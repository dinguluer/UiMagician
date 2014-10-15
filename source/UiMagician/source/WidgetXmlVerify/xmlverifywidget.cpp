/*---------------------------------------------------------------------------
** Project Name: UiMagician
** #Archive:
** #Author: # Dinesh Guleria
** #Date: # 15-03-2013
** Copyright (C) 2012-2014 Dinesh Guleria, VSCP Developer
**----------------------------------------------------------------------------
** #Revision: 1 #
**----------------------------------------------------------------------------
** Target system: QT - 4.8.1
** Compiler:
**----------------------------------------------------------------------------
**               A U T H O R   I D E N T I T Y
**----------------------------------------------------------------------------
** Initials           Name                     Project
** --------           ---------------------    -------------------------------
** DINESH.GULERIA     Dinesh Guleria           UiMagician
**----------------------------------------------------------------------------
**               R E V I S I O N   H I S T O R Y
**----------------------------------------------------------------------------
** #Log:
** 1. Creation of the file.
** 2. Review the implementation to bring it to 100%.
**--------------------------------------------------------------------------*/


#include "xmlverifywidget.h"
#include "ui_xmlverifywidget.h"

xmlVerifyWidget::xmlVerifyWidget(QDomElement &xmlRootVerify, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::xmlVerifyWidget)
{
    int rows;
    ui->setupUi(this);

    //Load root nodes
    list = xmlRootVerify.childNodes();
    rows = list.count();
    // Create model dynamically
    createModelForTheXml(rows);


    //Connect signals & slots for test report
    connect(ui->xmlVerifyWidgetPushButtonOk,SIGNAL(clicked()), this, SLOT(close()));
}

xmlVerifyWidget::~xmlVerifyWidget()
{
    delete ui;
}


void xmlVerifyWidget::createModelForTheXml(int rows)
{

    // Create model dynamically
    VerifyModel = new xmlverifymmodel(rows, 4);
    // Set Title in the column
    VerifyModel->setHorizontalHeaderItem(0, new QStandardItem(tr(XML_REVIEW_COLUMN_ZERO)));
    VerifyModel->setHorizontalHeaderItem(1, new QStandardItem(tr(XML_REVIEW_COLUMN_ONE)));
    VerifyModel->setHorizontalHeaderItem(2, new QStandardItem(tr(XML_REVIEW_COLUMN_TWO)));
    VerifyModel->setHorizontalHeaderItem(3, new QStandardItem(tr(XML_REVIEW_COLUMN_THREE)));
    // Best Fit the model inside the Tableview
    ui->xmlVerifyWidgetTableView->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);  //---> original
    ui->xmlVerifyWidgetTableView->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    ui->xmlVerifyWidgetTableView->horizontalHeader()->setStretchLastSection(true);
    //Set model
    ui->xmlVerifyWidgetTableView->setModel(VerifyModel);

    //update model with test case name & result
    updateDialogResults();

}

//update model with test case name & result
void xmlVerifyWidget::updateDialogResults()
{
    QDomNode tempNodeChild;
    QDomNode firstNodeOfTheXml;
    QStandardItem *item;
    QDomNode firstChild;
    QDomNodeList listChild;
    QString nodeDataTextRoom;
    QString nodeDataTextFloor;
    QString nodeDataTextHouse;
    QString nodeDataDeviceType;
    QString nodeDataDeviceSubType;
    QString nodeTagname;
    bool statusFail;

    // root have Test Case nodes
    if(list.count() != 0)
    {
        for(int i =0; i< list.count() ; i++)
        {
            statusFail = FALSE;

            tempNodeChild = list.at(i);
            if(i == 0)
            {
                firstNodeOfTheXml = tempNodeChild;
            }
            // Create list of child nodes of - test case
            listChild = tempNodeChild.childNodes();

            //Read room name from node
            tempNodeChild = listChild.at(ROOM_NAME_NUMBER);
            if (!tempNodeChild.isNull()){
                nodeDataTextRoom = tempNodeChild.toElement().text();
                //Check if node is empty
                if(nodeDataTextRoom == ""){
                    statusFail = TRUE;
                }

            }
            else{
                nodeDataTextRoom = "";
                statusFail = TRUE;
            }

            //Read floor name from node
            tempNodeChild = listChild.at(FLOOR_NAME_NUMBER);
            if (!tempNodeChild.isNull()){
                nodeDataTextFloor = tempNodeChild.toElement().text();
                //Check if node is empty
                if(nodeDataTextFloor == ""){
                    statusFail = TRUE;
                }

            }
            else{
                nodeDataTextFloor = "";
                statusFail = TRUE;
            }

            //Read house name from node
            tempNodeChild = listChild.at(HOUSE_NAME_NUMBER);
            if (!tempNodeChild.isNull()){
                nodeDataTextHouse = tempNodeChild.toElement().text();
                //Check if node is empty
                if(nodeDataTextHouse == ""){
                    statusFail = TRUE;
                }

            }
            else{
                nodeDataTextHouse = "";
                statusFail = TRUE;
            }
            //Itterate test steps of the - test case node
            for(int device = DEVICE_NODE_NUMBER; device<listChild.count(); device++)
            {
                //Read test Description from node
                tempNodeChild = listChild.at(device);
                if (!tempNodeChild.isNull()){

                    //Read first child of the node
                    firstChild = tempNodeChild.firstChild();
                    if(!firstChild.isNull()){
                        for(int column =0; column < MODEL_INITIAL_COLUMNS; column++ ){

                            if(column != DEVICE_DESCRIPTION_DEVICE_PACKET_COLUMN)
                            {
                                if(firstChild.toElement().text() == ""){
                                    statusFail = TRUE;
                                }
                            }
                            else
                            {
                                if(firstChild.isNull())
                                {
                                    statusFail = TRUE;
                                    //QMessageBox::information(this, "Packet Node", "Packet Node is NULL");
                                }
                                else
                                {
                                    //Do nothing
                                }

                                nodeTagname = firstChild.toElement().tagName();
                                if((nodeTagname!=PACKET_SWITCH_TEXT)&&(nodeTagname!=PACKET_SENSOR_TEXT))
                                {
                                    statusFail = TRUE;
                                    //QMessageBox::information(this, "Packet Node", "Packet Node Tagname Incorrect" + nodeTagname);
                                }
                                else
                                {
                                    //Do nothing
                                }

                            }

                            if(column == DEVICE_TYPE_COLUMN)
                            {
                                nodeDataDeviceType = firstChild.toElement().text();
                            }
                            else if(column == DEVICE_SUB_TYPE_COLUMN)
                            {
                                nodeDataDeviceSubType = firstChild.toElement().text();
                            }
                            else
                            {
                                /* Do nothing*/
                            }
                            // Get the next child
                            firstChild = firstChild.nextSibling();
                        }


                        // Check if the device is switch type
                        if(nodeDataDeviceType == DEVICE_SWITCH)
                        {
                            if((nodeDataDeviceSubType == SWITCH_SUB_TYPE_ONE) || (nodeDataDeviceSubType == SWITCH_SUB_TYPE_TWO))
                            {
                                //Do nothing
                            }
                            else
                            {
                                statusFail = TRUE;
                            }

                        }
                        else if(nodeDataDeviceType == DEVICE_SENSOR) // check if device is sensor type
                        {
                            if(nodeDataDeviceSubType == SENSOR_SUB_TYPE_DEFAULT)
                            {
                                /*QMessageBox *msgBox 	= new QMessageBox();
                                                msgBox->setText(SENSOR_SUB_TYPE_DEFAULT);
                                                msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
                                                msgBox->exec();*/
                                //Do nothing
                            }
                            else
                            {
                                statusFail = TRUE;
                            }

                        }
                        else
                        {
                            statusFail = TRUE;
                        }
                        nodeDataDeviceType = "";
                        nodeDataDeviceSubType = "";
                    }
                }
                else{
                    // Do nothing
                }
            }


            //Append to model
            if(statusFail == TRUE){
                item = new QStandardItem(TEST_CASE_FAIL);
            }else{
                item = new QStandardItem(TEST_CASE_PASS);
            }
            VerifyModel->setItem(i, TEST_CASE_RESULT_COLUMN, item);

            //Append to model
            item = new QStandardItem(nodeDataTextRoom);
            VerifyModel->setItem(i, 1, item);            
            //Append to model
            item = new QStandardItem(nodeDataTextFloor);
            VerifyModel->setItem(i, 2, item);
            //Append to model
            item = new QStandardItem(nodeDataTextHouse);
            VerifyModel->setItem(i, 3, item);

            if(statusFail == TRUE){
                VerifyModel->setData(VerifyModel->index(i, 0), Qt::red, Qt::BackgroundRole);
                VerifyModel->setData(VerifyModel->index(i, 1), Qt::red, Qt::BackgroundRole);
                VerifyModel->setData(VerifyModel->index(i, 2), Qt::red, Qt::BackgroundRole);
                VerifyModel->setData(VerifyModel->index(i, 3), Qt::red, Qt::BackgroundRole);
            }else{
                //Do nothing
            }

        }
    }
}
