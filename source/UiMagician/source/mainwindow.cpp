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

/*---------------------------------------------------------------------------
** Includes
*/
#include <QtGui>
#include <QSplashScreen>
#include <QPixmap>
#include <QThread>
#include "mainwindow.h"
#include "ui_mainwindow.h"


/*----------------------------------------------------------------------------
** Function    : MainWindow
** Description : Constructor for MainWindow
** Precondition: None
** Postcondition: None
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Create List for device type
    deviceTypedeligateList << DEVICE_SWITCH << DEVICE_SENSOR ;

    // Create List for device sub type
    deviceSubTypedeligateList << SWITCH_SUB_TYPE_ONE << SWITCH_SUB_TYPE_TWO << SWITCH_SUB_TYPE_THREE
                              << SENSOR_SUB_TYPE_DEFAULT ;

    // Create List for device Info
    deviceInfodeligateList << DEVICE_INFO_TYPE_ONE << DEVICE_INFO_TYPE_TWO << DEVICE_INFO_TYPE_THREE
                              << DEVICE_INFO_TYPE_FOUR << DEVICE_INFO_TYPE_FIVE ;

    // This function is used to Create Test Cases & Test Steps view
    createTestEditView();
    // Best Fit the model inside the Tableview
    ui->testCaseTableView->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);  //---> original
    ui->testCaseTableView->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    ui->testCaseTableView->horizontalHeader()->setStretchLastSection(true);

    // Highlight entire row on clicking any cell
    ui->testCaseTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->testCaseTableView->setSelectionMode(QTableView::SingleSelection);

    //Set model & deligate
    ui->testCaseTableView->setModel(model);
    //ui->testCaseTableView->setItemDelegate(mydeligate);
    //Set the deligate per column
    ui->testCaseTableView->setItemDelegateForColumn(0, mydeligate);
    //ui->testCaseTableView->setItemDelegateForColumn(1, mydeligate);
    //ui->testCaseTableView->setItemDelegateForColumn(2, mydeligate);
    ui->testCaseTableView->setItemDelegateForColumn(1, deviceTypedeligate);
    //ui->testCaseTableView->setItemDelegateForColumn(2, deviceSubTypedeligate);
    ui->testCaseTableView->setItemDelegateForColumn(2, deviceSubTypedeligate);
    /*ui->testCaseTableView->setItemDelegateForColumn(TX_PACKET_COLUMN_DELIGATE, 0);
    ui->testCaseTableView->setItemDelegateForColumn(EXPECTED_PACKET_COLUMN_DELIGATE, 0);
    ui->testCaseTableView->setItemDelegateForColumn(RX_PACKET_COLUMN_DELIGATE, 0);
    ui->testCaseTableView->setItemDelegateForColumn(RESULT_PACKET_COLUMN_DELIGATE, 0);
    ui->testCaseTableView->setItemDelegateForColumn(7, mydeligate);*/
    ui->testCaseTableView->setItemDelegateForColumn(DEVICE_IMAGE_COLUMN_DELIGATE, 0);
    //ui->testCaseTableView->setItemDelegateForColumn(4, mydeligate);
    ui->testCaseTableView->setItemDelegateForColumn(4, deviceInfodeligate);
    ui->testCaseTableView->setItemDelegateForColumn(DEVICE_PACKET_COLUMN_DELIGATE, 0);

    //ui->statusBar->setStyleSheet("QStatusBar { border: 1px solid grey;}");
    setStyleSheet("QStatusBar{border-top: 1px outset grey;}");

   /* ui->statusBar->setStyleSheet("QStatusBar { border: 1px solid grey; \
                                                       border-radius: 3px}");
*/
    //ui->statusBar->showMessage("hello");
    //ui->statusBar->setStyleSheet("QStatusBar {   background: brown}");
    //create new object
    //xmlLibObject = new xmlLib();
    //This function will create layout for the left tree widget
    createTreeWidgetView();


    //set width of left tree widget
    //ui->treeWidgetLeft->setMaximumWidth(ui->treeWidgetLeft->width());
    ui->treeWidgetLeft->setMinimumWidth(LEFT_TREE_WIDGET_WIDTH);


    //Make this field as non editable
    ui->houseLineEdit->setEnabled(false);

    //ui->leftTreeDockWidget->set
    //Connect signals & slots for test report
    connect(ui->testReportSavePushButton,SIGNAL(clicked()), this, SLOT(on_actionSave_triggered()));
    connect(ui->testReportNewPushButton,SIGNAL(clicked()), this, SLOT(on_actionNew_triggered()));
    connect(ui->testReportOpenPushButton,SIGNAL(clicked()), this, SLOT(on_actionOpen_triggered()));
    connect(ui->testReportClosePushButton,SIGNAL(clicked()), this, SLOT(on_actionClose_Project_triggered()));

    //Initialise the variables
    initialiseVariables();

}

/*----------------------------------------------------------------------------
** Function    : ~MainWindow
** Description : Destructor for MainWindow
** Precondition: None
** Postcondition: None
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
MainWindow::~MainWindow()
{
    delete ui;
}

/*----------------------------------------------------------------------------
** Function    : on_actionSave_triggered
** Description : This Slot is used to save Test Report
** Precondition:  None
** Postcondition: None
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
void MainWindow::on_actionSave_triggered()
{
    QMessageBox* msgBox;
    // check if test report is already open or not
    if (b_xmlFileAlreadyOpen)
    {
        if(b_nodeIsNewAndNotSaved == FALSE)
        {
            /*msgBox 	= new QMessageBox();
            msgBox->setText(MESSAGE_SAVE_PRESSESD);
            msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
            msgBox->show();*/
            if((b_xmlFileAlreadyOpen == TRUE) && (b_newFileCreationSignal = TRUE))
            {
                xmlLibObject.xmlCloseFileNoFlush(xmlFile);
                //Now again open & truncate the file
                xmlLibObject.xmlOpenFileTruncate( xmlFileName, xmlFile, xmlStream);
                //close the file -- this will save totally new content to the file
                xmlLibObject.xmlCloseFile(xmlStream, xmlDomDocument, xmlFile);
                // create new xml file & text stream
                xmlLibObject.xmlOpenFile( xmlFileName, xmlFile, xmlStream);
                //Load the XML file
                xmlLibObject.xmlLoadFile(xmlDomDocument, xmlFile);
                //Get the root element
                xmlLibObject.xmlGetRoot(xmlRoot, xmlDomDocument);
            }

        }
        else{
            msgBox 	= new QMessageBox();
            msgBox->setText(SAVE_DELETE_NEW_EXISTING_NODE);
            msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
            msgBox->show();
        }
    }
    else {

        /*QMessageBox* msgBox 	= new QMessageBox();
        msgBox->setText(CREATE_OPEN_TEST_CASE);
        msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
        msgBox->show();*/
        QMessageBox::information(this, "uiMagician", CREATE_OPEN_HOUSE_CONFIGUATION_FILE);
    }
}

/*----------------------------------------------------------------------------
** Function    : on_testStepNewPushButton_clicked
** Description : This Slot is used to add new Test Step
** Precondition:  None
** Postcondition: None
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
void MainWindow::on_testStepNewPushButton_clicked()
{
    QMessageBox* msgBox;
    QVariant variant(PACKET_INITIAL_STRING);
    T_vscpDevicePacket testCaseStepCanMessage;
    int row;

    // check if test report is already open or not
    if (b_xmlFileAlreadyOpen)
    {
        // check if test case exist or not
        if (b_testCaseExists)
        {
            // This insert row below current selected row
            QModelIndex currentIndex = ui->testCaseTableView->selectionModel()->currentIndex();
            model->insertRow(currentIndex.row()+ 1u);

            row = currentIndex.row()+ 1u;
            //variant.String = ;
            model->setData(model->index(row,DEVICE_DESCRIPTION_DEVICE_PACKET_COLUMN),variant);

            //initialiseUndoRedoItems();

            //Set the current row
            currentDeviceRow = row;

            //Select the row
            ui->testCaseTableView->selectRow(currentDeviceRow);

            //means pressed undo - Then pressed new
            if(b_roomUndoPressed == TRUE)
            {
                b_roomUndoPressed = FALSE;
                b_roomRedoPressed = FALSE;

                /*
                   suppose th undo_orig_list have been updated to 4 elements -
                   now undo button is pressed & actual list is updated to orginal node read from XML --
                   i.e less than or greater than 4 elements
                   now a new button is pressed in this case we will have to update the undo_orig_list to the
                   actual elements in latest list.
                */

                //clear the undolist
                testCaseStepCanPacket_undo.clear();
                //update the undo list to latest -- bt itterate through the actual list
                for (uint16_t i = 0; i < testCaseStepCanPacket_rx.size(); ++i)
                {
                     //Read from list
                     testCaseStepCanMessage = testCaseStepCanPacket_rx.at(i);
                     testCaseStepCanPacket_undo.append(testCaseStepCanMessage);
                }


            }
        }
        else
        {
            msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Altert Message");
            msgBox->setText(NO_TEST_STEP_EXIST_POP_UP_MESSAGE);
            msgBox->exec();
        }
    }
    else {

        /*msgBox 	= new QMessageBox();
        msgBox->setText(CREATE_OPEN_TEST_CASE);
        msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
        msgBox->show();*/
        QMessageBox::information(this, "uiMagician", CREATE_OPEN_HOUSE_CONFIGUATION_FILE);
    }
}

/*----------------------------------------------------------------------------
** Function    : on_testStepDeletePushButton_clicked
** Description : This Slot is used to delete selected Test Step
                 Before deleting current row pop-up message is displayed
** Precondition:  None
** Postcondition: None
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
void MainWindow::on_testStepDeletePushButton_clicked()
{
    QModelIndex currentIndex = ui->testCaseTableView->selectionModel()->currentIndex();
    QString str = DELETE_CONFIRM_MESSAGE;
    QMessageBox* msgBox;
    QPushButton *yesButton;

    // check if test report is already open or not
    if (b_xmlFileAlreadyOpen)
    {
        // check if test case exist or not
        if (b_testCaseExists)
        {
            str.append(QString("%1").arg(currentIndex.row() + 1u));

            msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Confirmation");
            msgBox->setText(str);

            yesButton = msgBox->addButton(tr("Yes"), QMessageBox::ActionRole);
            msgBox->addButton(tr("No"), QMessageBox::ActionRole);
            msgBox->exec();

            //If user clicks 'Yes'  button
            if ((QPushButton*)msgBox->clickedButton() == yesButton)
            {
                model->removeRow(currentIndex.row());
            }
            else {
                //Do nothing
            }

            //clear the undo items & list
            if(!testCaseStepCanPacket_rx.isEmpty())
            {
                // Check actual list
                if(testCaseStepCanPacket_rx.size() > currentIndex.row())
                {
                    testCaseStepCanPacket_rx.removeAt(currentIndex.row());
                }
                else
                {
                    // Do nothing as - Packet is not added to the list
                }

                //Check if undolist is empty
                if(!testCaseStepCanPacket_undo.isEmpty())
                {
                    //check the undo list
                    if(testCaseStepCanPacket_undo.size() > currentIndex.row())
                    {
                        testCaseStepCanPacket_undo.removeAt(currentIndex.row());
                    }
                }
                else
                {
                    // Do nothing
                }

            }
            else
            {
                // Do nothing
            }
        }
        else
        {
            msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Altert Message");
            msgBox->setText(NO_TEST_STEP_EXIST_POP_UP_MESSAGE);
            msgBox->exec();
        }
    }
    else {

        /*QMessageBox* msgBox 	= new QMessageBox();
        msgBox->setText(CREATE_OPEN_TEST_CASE);
        msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
        msgBox->show();*/
        QMessageBox::information(this, "uiMagician", CREATE_OPEN_HOUSE_CONFIGUATION_FILE);
    }

}

/*----------------------------------------------------------------------------
** Function    : on_leftTreeDockWidget_topLevelChanged
** Description : This Slot is used to pop-up the left tree widget
** Precondition:  None
** Postcondition: None
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
void MainWindow::on_leftTreeDockWidget_topLevelChanged(bool topLevel)
{
    if(topLevel){
        ui->leftTreeDockWidget->setFloating(1);
        ui->leftTreeDockWidget->showMaximized();
    }
    else{
        //Dock Automatically
    }
}

void MainWindow::on_actionNew_triggered()
{
    QString str = NEW_FILE_CONFIRM_MESSAGE;
    QMessageBox* msgBox;
    QPushButton *yesButton;

    // If file is already open
    if (b_xmlFileAlreadyOpen )
    {
       // open pop-up mesage to indicate close existing file
        msgBox = new QMessageBox(this);
        msgBox->setWindowTitle("Confirmation");
        msgBox->setText(str);

        str.append(QString(xmlFileName));

        yesButton = msgBox->addButton(tr("Yes"), QMessageBox::ActionRole);
        msgBox->addButton(tr("No"), QMessageBox::ActionRole);
        msgBox->exec();

        //If user clicks 'Yes'  button
        if ((QPushButton*)msgBox->clickedButton() == yesButton)
        {
            //close file
            closeExistingFile(xmlFileName, xmlFile, xmlDomDocument);
            //Re-initialise all the variables
            initialiseVariables();
          // create new file
          openFile(xmlFileName, xmlFile, xmlDomDocument, xmlDomDocumentOrg, CREATE_NEW_FILE);

        }
        else {
            //Do nothing
        }
    }
    else
    {
       // if no file is open
        //Re-initialise all the variables
        initialiseVariables();
        // create new file
        openFile(xmlFileName, xmlFile, xmlDomDocument, xmlDomDocumentOrg, CREATE_NEW_FILE);
    }

    //Create a new room entry - by default
    on_testCaseNewPushButton_clicked();
}

void MainWindow::on_actionOpen_triggered()
{
    QString str = OPEN_FILE_CONFIRM_MESSAGE;
    QMessageBox* msgBox;
    QPushButton *yesButton;

    // If file is already open
    if (b_xmlFileAlreadyOpen )
    {
       // open pop-up mesage to indicate close existing file
        msgBox = new QMessageBox(this);
        msgBox->setWindowTitle("Confirmation");
        msgBox->setText(str);

        str.append(QString(xmlFileName));

        yesButton = msgBox->addButton(tr("Yes"), QMessageBox::ActionRole);
        msgBox->addButton(tr("No"), QMessageBox::ActionRole);
        msgBox->exec();

        //If user clicks 'Yes'  button
        if ((QPushButton*)msgBox->clickedButton() == yesButton)
        {
          //close file
          closeExistingFile(xmlFileName, xmlFile, xmlDomDocument);
          //Re-initialise all the variables
          initialiseVariables();
          // open new file
          openFile(xmlFileName, xmlFile, xmlDomDocument, xmlDomDocumentOrg, OPEN_EXISTING_FILE);
        }
        else{
            // do nothing
        }
    }
    else
    {
        // if no file is open
        //Re-initialise all the variables
        initialiseVariables();
        // open new file
        openFile(xmlFileName, xmlFile, xmlDomDocument, xmlDomDocumentOrg, OPEN_EXISTING_FILE);
    }
}

// slot - Delete the current node of the tree
void MainWindow::on_testCaseDeletePushButton_clicked()
{
    QMessageBox* msgBox_1;
    QPushButton *yesButton_1;

    // check if test report is already open or not
    if (b_xmlFileAlreadyOpen)
    {
        if(ui->treeWidgetLeft->currentIndex().row() != NO_TREE_TOP_ITEM_TO_DELETE)
        {
            //Indicate delete button is delete
            b_deleteButtonIsPressed = TRUE;
            // Show confirmation message
            msgBox_1 = new QMessageBox(this);
            msgBox_1->setWindowTitle("Confirmation");
            msgBox_1->setText("Are you sure to delete current node");
            //msgBox->setText(textRead.data());

            yesButton_1 = msgBox_1->addButton(tr("Yes"), QMessageBox::ActionRole);
            msgBox_1->addButton(tr("No"), QMessageBox::ActionRole);
            msgBox_1->exec();

            //If user clicks 'Yes'  button
            if ((QPushButton*)msgBox_1->clickedButton() == yesButton_1)
            {
                //delete current selected item from the tree widget
                RemoveTopLevelItem();
                // This will trigger the -- event -- left tree item changed --> there we will change name of the tree nodes

                if(b_nodeIsNewAndNotSaved == FALSE)
                {
                    //Update TextView & xml after delete Test Case Pressed
                    UpdateXmlAndTextViewAfterDelete();
                }
                else // New node created is deleted without saving
                {
                    if(ui->treeWidgetLeft->currentIndex().row() != NO_TREE_TOP_ITEM_TO_DELETE)
                    {
                        // Decrement the global variable -- for current node -- because it was incremented at new time
                        //currentXmlRootNodeNumber--;
                        currentXmlRootNodeNumber = ui->treeWidgetLeft->currentIndex().row();

                        //dont save present & Show previous node
                        UpdateTextViewForCurrentSelectedNode();
                    }
                    else
                    {
                        //Create default view of the table --> after deleting first -- new node
                        // means now nothing is there to display -- you have deleted first new node also
                        createDefaultTableView();

                        // No test case exist
                        b_testCaseExists = FALSE;
                    }
                    // Make new node flag as false
                    b_nodeIsNewAndNotSaved = FALSE;
                }
                //Indicate delete button is release --> after work is done
                b_deleteButtonIsPressed = FALSE;
            }
        }
        else
        {
            //File do not contains nodes
            b_fileDoesNotContainsNode = TRUE;

            msgBox_1 = new QMessageBox(this);
            msgBox_1->setWindowTitle("Altert Message");
            msgBox_1->setText(DELETE_POP_UP_MESSAGE);
            msgBox_1->exec();
        }

    }
    else {

        /*QMessageBox* msgBox 	= new QMessageBox();
        msgBox->setText(CREATE_OPEN_TEST_CASE);
        msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
        msgBox->show();*/
        QMessageBox::information(this, "uiMagician", CREATE_OPEN_HOUSE_CONFIGUATION_FILE);
    }
}

// slot - add node to the tree
void MainWindow::on_testCaseNewPushButton_clicked()
{
    QString str = TEST_CASE_PREFIX;
    QDomElement testCaseNode;
    QList<T_testStepDetails> testCaseStepslist;
    QDomNode currentSelectedTestCaseNode;
    QMessageBox* msgBox;
    int treeTotalTestCaseCount;

    T_packetDeviceLocation deviceLocation;

    deviceLocation.houseName = ui->houseLineEdit->text();
    deviceLocation.floorName = ui->floorLineEdit->text();
    deviceLocation.roomName  = ui->roomLineEdit->text();


    // check if test report is already open or not
    if (b_xmlFileAlreadyOpen)
    {
        // if there are no nodes in the xml file
        if(b_fileDoesNotContainsNode)
        {
            b_fileDoesNotContainsNode = FALSE;
        }
        else{/* Do nothing*/
        }

        if(b_nodeIsNewAndNotSaved == FALSE)
        {
            // New node created
            b_nodeIsNewAndNotSaved = TRUE;
            // Test case exist
            b_testCaseExists = TRUE;

            // Update value of current node from Text View to -- XML
            // first time when new is pressed dont go inside
            // If again new is pressed -- save -- previous New Node -- by apending it to the xml file
            if(currentXmlRootNodeNumber != NO_NODE_TO_DISPLAY)
            {
                //xmlCreateNode(testCaseNode, TEST_CASE_NODE_PREFIX);
                xmlLibObject.xmlCreateNode(xmlDomDocument, testCaseNode, ROOM_NODE_PREFIX);
                // Update xml by reading from the text view

                //Append Room name & description to the node
                xmlAppendRoomNameAndDescription(testCaseNode);

                //Copy rest of text view
                copyTextEditToTheTestCasesBuffer(testCaseStepslist);
                xmlAppendFullTestStepsToTestCase(testCaseStepslist,testCaseNode,deviceLocation);

                //xmlGetNodeByNumber(xmlRoot, currentXmlRootNodeNumber,currentSelectedTestCaseNode);
                xmlLibObject.xmlGetNodeByNumber(xmlRoot, currentXmlRootNodeNumber,currentSelectedTestCaseNode);
                //xmlUpdateNode(testCaseNode , currentSelectedTestCaseNode);
                xmlLibObject.xmlUpdateNode(xmlRoot, testCaseNode , currentSelectedTestCaseNode);

                //change the name of the current node in the tree
                ChangeNameOfcurrentNodeOfTree();

                // Clear the TX & Rx list
                clearTxRxList();

            }

            // Get top level root count of tree
            treeTotalTestCaseCount = ui->treeWidgetLeft->topLevelItemCount();
            //str.append(QString("%1").arg(treeTotalTestCaseCount + 1u));
            str = "";
            // Add the root item to tree
            AddRoot(""   , str);

            //Create default view of the table
            createDefaultTableView();

            // Update the global variable -- for current node
            currentXmlRootNodeNumber = treeTotalTestCaseCount;
        }
        else {
            msgBox 	= new QMessageBox();
            msgBox->setText(PRESENT_NODE_IS_NEW_NODE);
            msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
            msgBox->show();
        }
    }
    else{
        /*msgBox 	= new QMessageBox();
        msgBox->setText(CREATE_OPEN_TEST_CASE);
        msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
        msgBox->show();*/
        QMessageBox::information(this, "uiMagician", CREATE_OPEN_HOUSE_CONFIGUATION_FILE);
    }
}

// slot - test case save button
void MainWindow::on_testCaseSavePushButton_clicked()
{
    QString str = TEST_CASE_PREFIX;
    QMessageBox* msgBox;
    QDomElement testCaseNode;
    QList<T_testStepDetails> testCaseStepslist;
    QDomNode currentSelectedTestCaseNode;
    int treeTotalTestCaseCount;
    T_packetDeviceLocation deviceLocation;

    deviceLocation.houseName = ui->houseLineEdit->text();
    deviceLocation.floorName = ui->floorLineEdit->text();
    deviceLocation.roomName  = ui->roomLineEdit->text();
    // check if test report is already open or not
    if (b_xmlFileAlreadyOpen)
    {
        // Some item is there in the tree
        if(!b_fileDoesNotContainsNode)
        {
            // Read content from the tree view & save to node
            // Update value of current node from Text View to -- XML
            // first time when new is pressed dont go inside
            // If again new is pressed -- save -- previous New Node -- by apending it to the xml file
            if(currentXmlRootNodeNumber != NO_NODE_TO_DISPLAY)
            {
                //change the name of the current node in the tree
                ChangeNameOfcurrentNodeOfTree();
                // Total child of the root
                treeTotalTestCaseCount = xmlRoot.childNodes().count();
                // Create new test Node
               // xmlCreateNode(testCaseNode, TEST_CASE_NODE_PREFIX);
                xmlLibObject.xmlCreateNode(xmlDomDocument, testCaseNode, ROOM_NODE_PREFIX);
                //Append Room name & description to the node
                xmlAppendRoomNameAndDescription(testCaseNode);
                //Copy rest of text view
                copyTextEditToTheTestCasesBuffer(testCaseStepslist);
                xmlAppendFullTestStepsToTestCase(testCaseStepslist,testCaseNode,deviceLocation);

                // Update xml by reading from the text view
                // -1 --> as currentXmlRootNodeNumber --> starts from --> 0
                if(currentXmlRootNodeNumber <= (treeTotalTestCaseCount-1))
                {
                    //xmlGetNodeByNumber(xmlRoot, currentXmlRootNodeNumber,currentSelectedTestCaseNode);
                    xmlLibObject.xmlGetNodeByNumber(xmlRoot, currentXmlRootNodeNumber,currentSelectedTestCaseNode);
                    // Replace old node with new one
                    //xmlUpdateNode(testCaseNode , currentSelectedTestCaseNode);
                    xmlLibObject.xmlUpdateNode(xmlRoot, testCaseNode , currentSelectedTestCaseNode);
                    //xmlCloseFile();

                }
                else  //Append node in xml
                {
                    //xmlAppendNode(xmlRoot,testCaseNode);
                    xmlLibObject.xmlAppendNode(xmlRoot,testCaseNode);
                }

                // Set the signal
                b_currentNodeSavedOnce = TRUE;

                //New node is saved
                if(b_nodeIsNewAndNotSaved)
                {
                    b_nodeIsNewAndNotSaved = FALSE;
                }

                numberOfTimeSelectionChangedWhenNewNode = SELECTION_CHANGED_ONCE;
            }
        }
        else
        {
            // Pop up message - create new node
            msgBox 	= new QMessageBox();
            msgBox->setText(NO_NODE_EXIST_MESSAGE);
            msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
            msgBox->show();
        }
    }
    else {
        /*msgBox 	= new QMessageBox();
        msgBox->setText(CREATE_OPEN_TEST_CASE);
        msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
        msgBox->show();*/
        QMessageBox::information(this, "uiMagician", CREATE_OPEN_HOUSE_CONFIGUATION_FILE);
    }

}

// slot - tree item change button
void MainWindow::on_treeWidgetLeft_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    //QMessageBox* msgBox;

    //signal indicate node is changing
    b_nodeIsChanging = TRUE;

    if(!b_updateTreeViewSignal)
    {
        //Event triggered because of the -- clearing the tree
        if(!b_clearTreeViewSignal)
        {
            // check if test report is already open or not
            if(b_xmlFileAlreadyOpen)
            {
                if(b_deleteButtonIsPressed == FALSE)
                {
                    if ((b_nodeIsNewAndNotSaved == FALSE)||(numberOfTimeSelectionChangedWhenNewNode == SELECTION_CHANGED_TWICE))
                    {
                        //save to xml -- current test case
                        on_testCaseSavePushButton_clicked(); //Save the current node -- emit signal

                        //Clear all the undo redo list & items
                        initialiseUndoRedoItems();

                        //Create default view
                        createDefaultTableView();

                        //Update TextView for currently selected node
                        UpdateTextViewForCurrentSelectedNode();

                        numberOfTimeSelectionChangedWhenNewNode = SELECTION_CHANGED_ONCE;
                    }else{

                        if(numberOfTimeSelectionChangedWhenNewNode == SELECTION_CHANGED_ONCE){
                            numberOfTimeSelectionChangedWhenNewNode++;
                        }
                        else{  // selection changed --> second time after new node is created
                        }
                    }
                }
                else {
                    // Do nothing

                    //Clear all the undo redo list & items
                    initialiseUndoRedoItems();
                }

            }
            else {
                /*msgBox 	= new QMessageBox();
                msgBox->setText(CREATE_OPEN_TEST_CASE);
                msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
                msgBox->show();*/
                QMessageBox::information(this, "uiMagician", CREATE_OPEN_HOUSE_CONFIGUATION_FILE);
            }
        }
    }

    //signal indicate node is changing
    b_nodeIsChanging = FALSE;
}

void MainWindow::on_actionClose_Project_triggered()
{
    QMessageBox* msgBox;
    //QVariant variant(PACKET_INITIAL_STRING);
    //int row;

    // check if test report is already open or not
    if (b_xmlFileAlreadyOpen){

        if(b_nodeIsNewAndNotSaved == FALSE){

            //Close the existing file
            closeExistingFile(xmlFileName, xmlFile, xmlDomDocument);

            // clear the text view edit
            createDefaultTableView();

            // clear the tree view -- remove toplevel items
            clearAllTopLevelItems();

            //Re-initialise all the variables
            initialiseVariables();

            // Increase height of the first row
            //row = 0;
            //model->setData(model->index(row,DEVICE_DESCRIPTION_DEVICE_PACKET_COLUMN),variant);
        }
        else{
            msgBox 	= new QMessageBox();
            msgBox->setText(SAVE_DELETE_NEW_EXISTING_NODE);
            msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
            msgBox->show();
        }

    }
    else {

        /*msgBox 	= new QMessageBox();
        msgBox->setText(NOTHING_TO_CLOSE);
        msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
        msgBox->show();*/
        QMessageBox::information(this, "uiMagician", CREATE_OPEN_HOUSE_CONFIGUATION_FILE);
    }

}

void MainWindow::initialiseVariables()
{
    //Reset the signal
    //Re-initialise all the variables
    //xml file is not opened at present
    b_xmlFileAlreadyOpen = FALSE;
    // No node is there to be displayed
    currentXmlRootNodeNumber = NO_NODE_TO_DISPLAY;
    b_currentNodeSavedOnce = FALSE;
    b_nodeIsNewAndNotSaved = FALSE;
    b_deleteButtonIsPressed = FALSE;
    b_testCaseExists = FALSE;
    b_clearTreeViewSignal = FALSE;
    b_fileDoesNotContainsNode = FALSE;
    b_newFileCreationSignal = FALSE;
    b_verifyDialogIsOpened = FALSE;
    b_nodeIsChanging = FALSE;
    b_updateTreeViewSignal = FALSE;
    numberOfTimeSelectionChangedWhenNewNode = SELECTION_CHANGED_ONCE;

    b_packetDialogIsOpened = FALSE;
    b_verifyDialogIsOpened = FALSE;


    testCaseStepCanPacket_tx.clear();
    testCaseStepCanPacket_rx.clear();

    b_deviceUndoPressed = FALSE;
    b_deviceRedoPressed = FALSE;
    b_roomUndoPressed = FALSE;
    b_roomRedoPressed = FALSE;
    b_xmlUndoPressed = FALSE;
    b_xmlRedoPressed = FALSE;

    initialiseUndoRedoItems();

}

void MainWindow::initialiseUndoRedoItems()
{
    testCaseStepCanPacket_undo.clear();
    testCaseStepslist_undo.clear();

    testCaseStepCanPacket_undoRoom.clear();
    testCaseStepslist_undoRoom.clear();
    roomNameText_undo  = "";
    floorNameText_undo = "";
    houseNameText_undo = "";

    VscpPacketInitialise(testCaseStepCanPacket_redo);
    deviceDetailsInitialise(testCaseStepsDetails_redo);
    roomNameText_redo  = "";
    floorNameText_redo = "";
    houseNameText_redo = "";

    currentDeviceRow = 0;

}

void MainWindow::on_testReportVerifyPushButton_clicked()
{
    QMessageBox *msgBox;

    if(b_verifyDialogIsOpened == FALSE)
    {
        // check if test report is already open or not
        if (b_xmlFileAlreadyOpen)
        {
            // Some item is there in the tree
            if(!b_fileDoesNotContainsNode)
            {
                b_verifyDialogIsOpened = TRUE;
                xmlVerifyWidget mdialog(xmlRoot);
                mdialog.setModal(true);
                //mdialog.show();
                mdialog.exec();
                b_verifyDialogIsOpened = FALSE;
            }
            else
            {
                // Pop up message - create new node
                msgBox 	= new QMessageBox();
                msgBox->setText(NO_NODE_EXIST_MESSAGE);
                msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
                msgBox->show();
            }
        }
        else
        {
            /*msgBox 	= new QMessageBox();
            msgBox->setText(CREATE_OPEN_TEST_CASE);
            msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
            msgBox->show();*/
            QMessageBox::information(this, "uiMagician", CREATE_OPEN_HOUSE_CONFIGUATION_FILE);
        }
    }
    else
    {
        msgBox 	= new QMessageBox();
        msgBox->setText(TEST_CASE_VERIFY_MESSAGE);
        msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
        msgBox->show();
    }


}


void MainWindow::on_appGeneratePushButton_clicked()
{

    //QMessageBox *msgBox;

    // check if test report is already open or not
    if (b_xmlFileAlreadyOpen)
    {
        GenerateApp GenerateAppWidget(xmlFileName,xmlRoot);
        GenerateAppWidget.exec();
        // Report generated Message
        // QMessageBox::information(this, "uiMagician", "Report is Generated");
    }
    else
    {
        QMessageBox::information(this, "uiMagician", CREATE_OPEN_HOUSE_CONFIGUATION_FILE);
    }
}


//load to xml test case ro excel
void MainWindow::loadXmlTestCasetoexcel(MyExcel &excelTestReport)
{
    QDomNodeList list;
    QDomNode tempNodeChild;
    QDomNode firstChild;
    QDomNodeList listChild;
    QString nodeDataTextTcName;
    QString nodeDataTextTcDescription;
    QString houseNameString;
    QString nodeDataTextTcExcel;
    QString testCaseDataString;
    int testCaseExcelRow = TEST_CASE_ROW_VALUE;

    //read node list from root
    list = xmlRoot.childNodes();

    //append list to the excel

    // root have Test Case nodes
    if(list.count() != 0)
    {
        for(int i =0; i< list.count() ; i++)
        {
            tempNodeChild = list.at(i);

            // Create list of child nodes of - test case
            listChild = tempNodeChild.childNodes();

            //Read test case name from node
            tempNodeChild = listChild.at(ROOM_NAME_NUMBER);
            if (!tempNodeChild.isNull()){
                nodeDataTextTcName = tempNodeChild.toElement().text();
            }
            else{
                nodeDataTextTcName = "";
            }

            //Read test Description from node
            tempNodeChild = listChild.at(FLOOR_NAME_NUMBER);
            if (!tempNodeChild.isNull()){
                nodeDataTextTcDescription = tempNodeChild.toElement().text();
            }
            else{
                nodeDataTextTcDescription = "";
            }


            //Read test Description from node
            tempNodeChild = listChild.at(HOUSE_NAME_NUMBER);
            if (!tempNodeChild.isNull()){
                houseNameString = tempNodeChild.toElement().text();
            }
            else{
                houseNameString = "";
            }

            //Create Excel test case description
            nodeDataTextTcExcel = nodeDataTextTcName + " : " + nodeDataTextTcDescription + " : " + houseNameString;
            //Add to the Excel
            excelTestReport.setValue(testCaseExcelRow,1,nodeDataTextTcExcel);
            //Change text allignment
            excelTestReport.VerticalAlignmentCenter(testCaseExcelRow,1);
            excelTestReport.HorizontalAlignmentCenter(testCaseExcelRow,1);
            //Merge cells in fourth row
            excelTestReport.setMergeCells(MERGE_CELLS_START_COLUMN, MERGE_CELLS_END_COLUMN, testCaseExcelRow, H_CENTER_ALLIGN, V_CENTER_ALLIGN);
            excelTestReport.setFontBold(testCaseExcelRow,1,true);
            excelTestReport.setFontType(testCaseExcelRow,1,"Arial");
            excelTestReport.setFontSize(testCaseExcelRow,1,TEST_SCRIPT_TC_DESCRIPTION_SIZE);
            //set colour Green
            excelTestReport.setColour(testCaseExcelRow,1,GREEEN_COLOUR);
            excelTestReport.setFontBorder( "A4:I4", XLTHICK);

            //increment the Excel row
            testCaseExcelRow++;

            //Itterate test steps of the - test case node
            for(int testSteps = DEVICE_NODE_NUMBER; testSteps<listChild.count(); testSteps++)
            {
                //Read test Description from node
                tempNodeChild = listChild.at(testSteps);
                if (!tempNodeChild.isNull()){
                    //Read first child of the node
                    firstChild = tempNodeChild.firstChild();
                    if(!firstChild.isNull()){
                        for(int column =1; column <= MODEL_INITIAL_COLUMNS+1; column++ ){ //+1 to add for code sniphet

                            if(column != TEST_SCRIPT_CODE_SNIPPET_IX)
                            {
                                //Read text from the xml
                                testCaseDataString = firstChild.toElement().text();

                                //Add to the Excel
                                excelTestReport.setValue(testCaseExcelRow,column,testCaseDataString);
                                //Change text allignment
                                //excelTestReport.HorizontalAlignmentLeft(testCaseExcelRow,column);
                                //excelTestReport.VerticalAlignmentTop(testCaseExcelRow,column);
                                excelTestReport.setFontBold(testCaseExcelRow,column,true);
                                excelTestReport.setFontType(testCaseExcelRow,column,"Courier New");
                                excelTestReport.setFontSize(testCaseExcelRow,column,TEST_SCRIPT_TC_TS_DESCRIPTION_SIZE);

                                //Allign text
                                if(column <= 3)
                                {
                                    excelTestReport.HorizontalAlignmentLeft(testCaseExcelRow,column);
                                    excelTestReport.VerticalAlignmentTop(testCaseExcelRow,column);
                                    //wrap text
                                    excelTestReport.wrapText(testCaseExcelRow,column,true);

                                }else{
                                    excelTestReport.HorizontalAlignmentLeft(testCaseExcelRow,column);
                                    excelTestReport.VerticalAlignmentTop(testCaseExcelRow,column);
                                }




                                // Get the next child
                                firstChild = firstChild.nextSibling();

                            }else{
                                //set colour Grey
                                excelTestReport.setColour(testCaseExcelRow,column,GREY_COLOUR);
                            }

                            excelTestReport.setFontBorder( testCaseExcelRow, column,  XLTHICK);
                        }

                        //increment the Excel row
                        testCaseExcelRow++;
                    }
                }
                else{
                    // Do nothing
                }
            }//for
        }//for
    }//if
}

void MainWindow::on_testCaseTableView_doubleClicked(const QModelIndex &index)
{
    QVariant variant;
    QMessageBox *msgBox;
    //--T_testCaseStepCanPacket canPacket;
    T_vscpDevicePacket testCaseStepCanMessage;

    //T_widgetwebsocketPacketsensor Packetsensor;
    //T_widgetWebsocketPacketSwitch PacketSwitch;
    T_vscpDevicePacket vscpPacket;

    //QString Canstring;
    QString VscpPacketstring;
    uint8_t row;
    //uint8_t column;
    //bool mesaageInTxQueue = false;
    bool mesaageInRxQueue = false;
    uint8_t queueIndex = 0;

    QString imageData;
    QVariant deviceTypeVariant;
    QString deviceType;
    QString deviceSubType;
    QVariant deviceNameVariant;
    QString deviceName;
    QString houseNameStr;
    QString floorNameStr;
    QString roomNameStr;

    //if((index.column() == TX_PACKET_COLUMN_DELIGATE)||(index.column() == EXPECTED_PACKET_COLUMN_DELIGATE))
    if((index.column() == DEVICE_PACKET_COLUMN_DELIGATE)||(index.column() == DEVICE_IMAGE_COLUMN_DELIGATE))
    {
        //model->setData(index, variant);   // write new value

        // Initialise the CAN packet
        //--CanPacketInitialise(canPacket);


        //Initialise the VSCP packet
        vscpPacket.packetType = UNDEFINED_PACKET_TYPE;
        SwitchPacketInitialise(vscpPacket.vscpPacketSwitch);
        SensorPacketInitialise(vscpPacket.vscpPacketSensor);
        SliderPacketInitialise(vscpPacket.vscpPacketSlider);
        SliderPacketVariableSwitchInitialise(vscpPacket.vscpPacketVariableSwitch);

        if(b_packetDialogIsOpened == FALSE)
        {
            // check if test report is already open or not
            if (b_xmlFileAlreadyOpen)
            {
                /*//check the packet is - Tx or Rx type -- update desired list
                column = index.column();
                if(column == TX_PACKET_COLUMN_DELIGATE)
                {
                    if(!testCaseStepCanPacket_tx.isEmpty())
                    {
                        row = index.row();
                        //itterate through the list
                        for (uint16_t i = 0; i < testCaseStepCanPacket_tx.size(); ++i)
                        {
                             //Read from list without removing node
                             testCaseStepCanMessage = testCaseStepCanPacket_tx.at(i);
                             if(testCaseStepCanMessage.stepnumber == row)
                             {
                                 mesaageInTxQueue = true;
                                 queueIndex = i;
                                 canPacket = testCaseStepCanMessage;
                                 break;
                             }

                         }

                    }

                    //testCaseStepCanPacket_tx.append(canPacket);

                }
                else // RX_PACKET_COLUMN_DELIGATE
                {
                    if(!testCaseStepCanPacket_rx.isEmpty())
                    {
                        row = index.row();
                        //itterate through the list
                        for (uint16_t i = 0; i < testCaseStepCanPacket_rx.size(); ++i)
                        {
                             //Read from list without removing node
                             testCaseStepCanMessage = testCaseStepCanPacket_rx.at(i);
                             if(testCaseStepCanMessage.stepnumber == row)
                             {
                                 mesaageInRxQueue = true;
                                 queueIndex = i;
                                 canPacket = testCaseStepCanMessage;
                                 break;
                             }

                         }

                    }
                    //testCaseStepCanPacket_rx.append(canPacket);
                //}*/

                if(index.column() == DEVICE_PACKET_COLUMN_DELIGATE)
                {
                    // update desired list
                    if(!testCaseStepCanPacket_rx.isEmpty())
                    {
                        row = index.row();
                        //itterate through the list
                        for (uint16_t i = 0; i < testCaseStepCanPacket_rx.size(); ++i)
                        {
                             //Read from list without removing node
                             testCaseStepCanMessage = testCaseStepCanPacket_rx.at(i);
                             if(testCaseStepCanMessage.stepnumber == row)
                             {
                                 mesaageInRxQueue = true;
                                 queueIndex = i;
                                 //canPacket = testCaseStepCanMessage;
                                 vscpPacket = testCaseStepCanMessage;
                                 break;
                             }

                         }

                    }

                    b_packetDialogIsOpened = TRUE;

                    //read string from model cell
                    deviceTypeVariant = model->data( model->index(index.row(),DEVICE_TYPE_COLUMN) );
                    deviceType = deviceTypeVariant.toString();

                    //read string from model cell
                    deviceTypeVariant = model->data( model->index(index.row(),DEVICE_SUB_TYPE_COLUMN) );
                    deviceSubType = deviceTypeVariant.toString();


                    //read string from model cell
                    deviceNameVariant = model->data( model->index(index.row(),DEVICE_NAME_COLUMN) );
                    deviceName = deviceNameVariant.toString().simplified().replace(" ", "");
                    deviceName.remove(QRegExp("[^a-zA-Z\\d\\s]"));

                    houseNameStr = ui->houseLineEdit->text().simplified().replace(" ", "");
                    houseNameStr.remove(QRegExp("[^a-zA-Z\\d\\s]"));
                    floorNameStr = ui->floorLineEdit->text().simplified().replace(" ", "");
                    floorNameStr.remove(QRegExp("[^a-zA-Z\\d\\s]"));
                    roomNameStr  = ui->roomLineEdit->text().simplified().replace(" ", "");
                    roomNameStr.remove(QRegExp("[^a-zA-Z\\d\\s]"));

                    if(houseNameStr.isEmpty())
                    {
                        QMessageBox::information(this, "Field Missing", "Enter House Name");
                        b_packetDialogIsOpened = FALSE;
                        return;
                    }
                    else
                    {
                        //Do nothing
                    }

                    if(floorNameStr.isEmpty())
                    {
                        QMessageBox::information(this, "Field Missing", "Enter Floor Name");
                        b_packetDialogIsOpened = FALSE;
                        return;
                    }
                    else
                    {
                        //Do nothing
                    }

                    if(roomNameStr.isEmpty())
                    {
                        QMessageBox::information(this, "Field Missing", "Enter Device Name");
                        b_packetDialogIsOpened = FALSE;
                        return;
                    }
                    else
                    {
                        //Do nothing
                    }

                    if(deviceName.isEmpty())
                    {
                        QMessageBox::information(this, "Field Missing", "Enter Device Name");
                        b_packetDialogIsOpened = FALSE;
                        return;
                    }
                    else
                    {
                        //Do nothing
                    }


                    if(deviceType.isEmpty())
                    {
                        QMessageBox::information(this, "Field Missing", "Enter Device Type");
                        b_packetDialogIsOpened = FALSE;
                        return;
                    }
                    else
                    {
                        //Do nothing
                    }

                    if(deviceSubType.isEmpty())
                    {
                        QMessageBox::information(this, "Field Missing", "Enter Device Sub Type");
                        b_packetDialogIsOpened = FALSE;
                        return;
                    }
                    else
                    {
                        //Do nothing
                    }

                    if(deviceType == DEVICE_SENSOR)
                    {
                        //if((mesaageInRxQueue==false) || (vscpPacket.vscpPacketSensor.id == "") || (vscpPacket.vscpPacketSensor.packetSensorVariable.name == "") )
                        //{
                            //Set the device ID
                            vscpPacket.vscpPacketSensor.id = houseNameStr + floorNameStr + roomNameStr + deviceName + "_Image" + "_ID";
                            //Set the device ID
                            vscpPacket.vscpPacketSensor.graphId = houseNameStr + floorNameStr + roomNameStr + deviceName + "_chart_div";
                            //Set the device ID
                            vscpPacket.vscpPacketSensor.graphUnitId = houseNameStr + floorNameStr + roomNameStr + deviceName + "_chart_unit_div";
                            //Set the Remote Txt ID
                            vscpPacket.vscpPacketSensor.idRemoteTxt = houseNameStr + floorNameStr + roomNameStr + deviceName + "_Remote_Txt" + "_ID";
                            //set the variable name
                            vscpPacket.vscpPacketSensor.packetSensorVariable.name = houseNameStr + floorNameStr + roomNameStr + deviceName + "_VAR";
                        //}

                        //vscpPacket.vscpPacketSensor.packetSensorVariable.control.checkSubzone = "true";
                        WidgetWebsocketPacketSensor WebsocketPacketSensor(vscpPacket.vscpPacketSensor);
                        WebsocketPacketSensor.exec();

                        //set the packet type
                        vscpPacket.packetType = SENSOR_PACKET_TYPE;
                    }
                    else if(deviceType == DEVICE_SWITCH)
                    {
                        if(deviceSubType == SWITCH_SUB_TYPE_ONE)
                        {
                            //if((mesaageInRxQueue==false) || (vscpPacket.vscpPacketSwitch.id == "") || (vscpPacket.vscpPacketSwitch.packetSwitchVariable.name == "" ) )
                            //{
                            //Set the device ID
                            vscpPacket.vscpPacketSwitch.id = houseNameStr + floorNameStr + roomNameStr + deviceName  + "_Image" + "_ID";
                            //set the variable name
                            vscpPacket.vscpPacketSwitch.packetSwitchVariable.name = houseNameStr + floorNameStr + roomNameStr + deviceName + "_VAR";
                            //}

                            WidgetWebsocketPacketSwitch WebsocketPacketSwitch(vscpPacket.vscpPacketSwitch);
                            WebsocketPacketSwitch.exec();
                            //set the packet type
                            vscpPacket.packetType = SWITCH_PACKET_TYPE;
                        }
                        else if (deviceSubType == SWITCH_SUB_TYPE_TWO)
                        {

                            //Set the device ID
                            vscpPacket.vscpPacketSlider.id = houseNameStr + floorNameStr + roomNameStr + deviceName  + "_Image" + "_ID";
                            //Set the Local Txt ID
                            vscpPacket.vscpPacketSlider.idLocalTxt = houseNameStr + floorNameStr + roomNameStr + deviceName  + "_Local_Txt" + "_ID";
                            //Set the Remote Txt ID
                            vscpPacket.vscpPacketSlider.idRemoteTxt = houseNameStr + floorNameStr + roomNameStr + deviceName  + "_Remote_Txt" + "_ID";
                            //set the variable name
                            vscpPacket.vscpPacketSlider.packetSliderVariable.name = houseNameStr + floorNameStr + roomNameStr + deviceName + "_VAR";

                            WidgetWebsocketPacketSlider WebsocketPacketSlider(vscpPacket.vscpPacketSlider);
                            WebsocketPacketSlider.exec();
                            //set the packet type
                            vscpPacket.packetType = SLIDER_PACKET_TYPE;
                        }
                        else if (deviceSubType == SWITCH_SUB_TYPE_THREE)
                        {

                            //Set the device up image ID
                            vscpPacket.vscpPacketVariableSwitch.idIncImage = houseNameStr + floorNameStr + roomNameStr + deviceName  + "_Inc_Image" + "_ID";
                            //Set the device down image ID
                            vscpPacket.vscpPacketVariableSwitch.idDecImage = houseNameStr + floorNameStr + roomNameStr + deviceName  + "_Dec_Image" + "_ID";
                            //Set the Local Txt ID
                            vscpPacket.vscpPacketVariableSwitch.idLocalTxt = houseNameStr + floorNameStr + roomNameStr + deviceName  + "_Local_Txt" + "_ID";
                            //Set the Remote Txt ID
                            vscpPacket.vscpPacketVariableSwitch.idRemoteTxt = houseNameStr + floorNameStr + roomNameStr + deviceName  + "_Remote_Txt" + "_ID";
                            //set the variable name
                            vscpPacket.vscpPacketVariableSwitch.packetVariableSwitchVariable.name = houseNameStr + floorNameStr + roomNameStr + deviceName + "_VAR";

                            WidgetWebsocketPacketVariableSwitch WebsocketPacketVariableSwitch(vscpPacket.vscpPacketVariableSwitch);
                            WebsocketPacketVariableSwitch.exec();
                            //set the packet type
                            vscpPacket.packetType = VARIABLE_BUTTON_PACKET_TYPE;
                        }
                        else
                        {
                            //Do nothing
                        }
                    }
                    else
                    {
                        QMessageBox::information(this, "Device Packet", SELECT_RIGHT_DEVICE_TYPE);
                        b_packetDialogIsOpened = FALSE;
                        return;
                    }

                    /*CanSewsiPacket mdialog(canPacket);
                    mdialog.setModal(true);
                    //mdialog.show();
                    mdialog.exec();*/

                    b_packetDialogIsOpened = FALSE;

                    //copy packet to the -- string
                    //CanPacketCreateString( canPacket, Canstring);

                    //
                    VscpPacketCreateString(vscpPacket,VscpPacketstring);

                    //variant = QString(Canstring);
                    variant = QString(VscpPacketstring);
                    model->setData(index, variant);   // write new value

                    if(VscpPacketstring == UNDEFINED_PACKET_STRING)
                    {
                        model->setData( index,Qt::red,Qt::ForegroundRole);
                        //QMessageBox::information(this, "undoRoom", testStepPacket);
                    }
                    else
                    {
                        model->setData( index,Qt::black,Qt::ForegroundRole);
                        //QMessageBox::information(this, "else", testStepPacket);
                    }

                    //Update step number
                    variant = index.row();
                    //canPacket.stepnumber = variant.toInt();
                    vscpPacket.stepnumber = variant.toInt();

                    /*
                    //check the packet is - Tx or Rx type -- update desired list
                    variant = index.column();
                    if(variant.toInt() == TX_PACKET_COLUMN_DELIGATE)
                    {
                        if(mesaageInTxQueue)
                        {
                          testCaseStepCanPacket_tx.replace(queueIndex,canPacket);
                        }
                        else
                        {
                          testCaseStepCanPacket_tx.append(canPacket);
                        }

                    }
                    else // RX_PACKET_COLUMN_DELIGATE
                    {*/
                        if(mesaageInRxQueue)
                        {
                           //testCaseStepCanPacket_rx.replace(queueIndex,canPacket);
                            testCaseStepCanPacket_rx.replace(queueIndex,vscpPacket);
                        }
                        else
                        {
                            //testCaseStepCanPacket_rx.append(canPacket);
                            testCaseStepCanPacket_rx.append(vscpPacket);
                        }
                    //}
                }
                else      /* Get the image */
                {
                    /*QList<QTreeWidgetItem *> items;
                    QTreeWidget *treeWidget = new QTreeWidget(this);
                    QTreeWidgetItem *newItem = new  QTreeWidgetItem(treeWidget);
                    treeWidget->setColumnCount(3);


                    for (int i = 0; i < 10; ++i)
                    {
                        newItem->setText(0, "Something");
                        newItem->setIcon(1, QIcon(":/Images/Images/Folder-Add.ico"));

                        items.append(newItem);
                    }
                    treeWidget->expandAll();
                    treeWidget->insertTopLevelItems(0,items);
                    treeWidget->show();

                    return;*/
                    ////////////
                    b_packetDialogIsOpened = TRUE;

                    //read string from model cell
                    deviceTypeVariant = model->data( model->index(index.row(),DEVICE_TYPE_COLUMN) );
                    deviceType = deviceTypeVariant.toString();

                    //read string from model cell
                    deviceTypeVariant = model->data( model->index(index.row(),DEVICE_SUB_TYPE_COLUMN) );
                    deviceSubType = deviceTypeVariant.toString();

                    // Read image number from cell
                    variant = model->data(index);
                    imageData = variant.toString();

                    if(deviceType == DEVICE_SENSOR)
                    {
                       // To do
                        WidgetImageSelectorSensor mdialogImageSelectorSensor(imageData);
                        //mdialog.setModal(true);
                        //mdialog.show();
                        mdialogImageSelectorSensor.exec();
                    }
                    else if(deviceType == DEVICE_SWITCH)
                    {
                        if(deviceSubType == SWITCH_SUB_TYPE_ONE)
                        {
                            WidgetImageSelector mdialogImageSelector(imageData);
                            //mdialog.setModal(true);
                            //mdialog.show();
                            mdialogImageSelector.exec();
                        }
                        else if ((deviceSubType == SWITCH_SUB_TYPE_TWO)|| (deviceSubType == SWITCH_SUB_TYPE_THREE))
                        {
                            WidgetImageSelectorVariableSwitch mdialogImageSelector(imageData);
                            //mdialog.setModal(true);
                            //mdialog.show();
                            mdialogImageSelector.exec();
                            //Do nothing
                            //imageData = "Default";
                        }
                        else
                        {
                            //Do nothing
                        }
                    }
                    else
                    {
                        QMessageBox::information(this, "Device Packet", SELECT_RIGHT_DEVICE_TYPE);
                        b_packetDialogIsOpened = FALSE;
                        return;
                    }

                    /*variant = model->data(index);
                    imageData = variant.toString();
                    WidgetImageSelector mdialogImageSelector(imageData);
                    //mdialog.setModal(true);
                    //mdialog.show();
                    mdialogImageSelector.exec();*/
                    b_packetDialogIsOpened = FALSE;

                    //copy packet to the -- string
                    //CanPacketCreateString( canPacket, Canstring);

                    variant = QString(imageData);
                    model->setData(index, variant);   // write new value
                }

            }
            else
            {
                /*msgBox 	= new QMessageBox();
                msgBox->setText(CREATE_OPEN_TEST_CASE);
                msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
                msgBox->show();*/
                QMessageBox::information(this, "uiMagician", CREATE_OPEN_HOUSE_CONFIGUATION_FILE);
            }
        }
        else
        {
            msgBox 	= new QMessageBox();
            msgBox->setText("Message Editor Already Open");
            msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
            msgBox->show();
        }

    }
}


//copy packet to the -- string
void MainWindow::CanPacketCreateString(T_testCaseStepCanPacket &canPacket, QString &Canstring)
{
    Canstring  = "CAN ID : ";
    Canstring += canPacket.u16_CanId;
    Canstring += "\n";
    Canstring += "\n";

    Canstring += "DLC : ";
    Canstring += canPacket.u8_dlc;
    Canstring += "\n";
    Canstring += "\n";

    Canstring += "Packet : ";
    Canstring += canPacket.u8_byte0 + " " + canPacket.u8_byte1 + " " +  canPacket.u8_byte2 + " " +  canPacket.u8_byte3 + " " +
                 canPacket.u8_byte4 + " " + canPacket.u8_byte5 + " " +  canPacket.u8_byte6 + " " +  canPacket.u8_byte7;
    Canstring += "\n";
}

//copy vscp packet to the -- string
void MainWindow::VscpPacketCreateString(T_vscpDevicePacket &vscpPacket, QString &vscpPacketString){
    if(vscpPacket.packetType == SWITCH_PACKET_TYPE)
    {
       SwitchPacketCreateString(vscpPacket.vscpPacketSwitch,vscpPacketString);

    }
    else if (vscpPacket.packetType == SENSOR_PACKET_TYPE)
    {

        SensorPacketCreateString(vscpPacket.vscpPacketSensor,vscpPacketString);
    }
    else if (vscpPacket.packetType == SLIDER_PACKET_TYPE)
    {

        SliderPacketCreateString(vscpPacket.vscpPacketSlider,vscpPacketString);
    }
    else if (vscpPacket.packetType == VARIABLE_BUTTON_PACKET_TYPE)
    {

        VariableButtonPacketCreateString(vscpPacket.vscpPacketVariableSwitch,vscpPacketString);
    }
    else{
        // Do nothing
        vscpPacketString = "\n\n";
        vscpPacketString = UNDEFINED_PACKET_STRING;
        vscpPacketString = "\n\n";
    }
}

//copy vscp  Sensor packet to the -- string
void MainWindow::SensorPacketCreateString(T_widgetwebsocketPacketsensor &vscpSensorPacket, QString &VscpSensorPacketstring)
{
    /******* Websocket string *******/
    //VscpSensorPacketstring  = "WEBSOCKET CONFIGURE :--";
    VscpSensorPacketstring  = "WEBSOCKET CONFIGURE : DONE";

    VscpSensorPacketstring += "\n";
    VscpSensorPacketstring += "\n";

    /*VscpSensorPacketstring += "ID :";
    VscpSensorPacketstring += vscpSensorPacket.id;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "URL :";
    VscpSensorPacketstring += vscpSensorPacket.url;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "CLASS VALUE :";
    VscpSensorPacketstring += vscpSensorPacket.class_value;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "TYPE VALUE :";
    VscpSensorPacketstring += vscpSensorPacket.type_value;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "CODING INDEX :";
    VscpSensorPacketstring += vscpSensorPacket.codingIndex;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "DECIMALS :";
    VscpSensorPacketstring += vscpSensorPacket.decimals;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "FORMAT STRING :";
    VscpSensorPacketstring += vscpSensorPacket.formatString;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "GUID :";
    VscpSensorPacketstring += vscpSensorPacket.guid;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "CALLBACK :";
    VscpSensorPacketstring += vscpSensorPacket.callback;
    VscpSensorPacketstring += "\n";
    VscpSensorPacketstring += "\n";

    ******* Variable Configure string *******/
    //VscpSensorPacketstring += "VARIABLE CONFIGURE :--";
    VscpSensorPacketstring += "VARIABLE CONFIGURE : DONE";

    /*VscpSensorPacketstring += "NAME :";
    VscpSensorPacketstring += vscpSensorPacket.packetSensorVariable.name;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "GROUP ID :";
    VscpSensorPacketstring += vscpSensorPacket.packetSensorVariable.groupId;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "ALLOWED FROM :";
    VscpSensorPacketstring += vscpSensorPacket.packetSensorVariable.allowedFrom;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "ALLOWED TO :";
    VscpSensorPacketstring += vscpSensorPacket.packetSensorVariable.allowedTo;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "ALLOWED TIME :";
    VscpSensorPacketstring += vscpSensorPacket.packetSensorVariable.allowedTime;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "ALLOWED DAYS :";
    if(vscpSensorPacket.packetSensorVariable.allowedDays.mon == "true")
    {
        VscpSensorPacketstring += "mon";
    }

    if(vscpSensorPacket.packetSensorVariable.allowedDays.tue == "true")
    {
        VscpSensorPacketstring += ",tue";
    }

    if(vscpSensorPacket.packetSensorVariable.allowedDays.wed == "true")
    {
        VscpSensorPacketstring += ",wed";
    }

    if(vscpSensorPacket.packetSensorVariable.allowedDays.thur == "true")
    {
        VscpSensorPacketstring += ",thur";
    }

    if(vscpSensorPacket.packetSensorVariable.allowedDays.fri == "true")
    {
        VscpSensorPacketstring += ",fri";
    }

    if(vscpSensorPacket.packetSensorVariable.allowedDays.sat == "true")
    {
        VscpSensorPacketstring += ",sat";
    }

    if(vscpSensorPacket.packetSensorVariable.allowedDays.sun == "true")
    {
        VscpSensorPacketstring += ",sun";
    }

    VscpSensorPacketstring += "ACTION :";
    VscpSensorPacketstring += vscpSensorPacket.packetSensorVariable.action;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "ACTION PARAMETERS :";
    VscpSensorPacketstring += vscpSensorPacket.packetSensorVariable.actionParameters;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "CONTROL :";
    if(vscpSensorPacket.packetSensorVariable.control.EnableRow == "true")
    {
        VscpSensorPacketstring += "Enable Row";
    }

    if(vscpSensorPacket.packetSensorVariable.control.checkIndex == "true")
    {
        VscpSensorPacketstring += ",Check Index";
    }

    if(vscpSensorPacket.packetSensorVariable.control.checkzone == "true")
    {
        VscpSensorPacketstring += ",Check zone";
    }

    if(vscpSensorPacket.packetSensorVariable.control.endScan == "true")
    {
        VscpSensorPacketstring += ",End Scan";
    }

    if(vscpSensorPacket.packetSensorVariable.control.checkSubzone == "true")
    {
        VscpSensorPacketstring += ",Check Subzone";
    }

    VscpSensorPacketstring += "CLASS VALUE :";
    VscpSensorPacketstring += vscpSensorPacket.packetSensorVariable.class_value;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "TYPE VALUE :";
    VscpSensorPacketstring += vscpSensorPacket.packetSensorVariable.type_value;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "GUID :";
    VscpSensorPacketstring += vscpSensorPacket.packetSensorVariable.guid;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "PRIORITY :";
    VscpSensorPacketstring += vscpSensorPacket.packetSensorVariable.priority;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "INDEX :";
    VscpSensorPacketstring += vscpSensorPacket.packetSensorVariable.index;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "ZONE :";
    VscpSensorPacketstring += vscpSensorPacket.packetSensorVariable.zone;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "SUBZONE :";
    VscpSensorPacketstring += vscpSensorPacket.packetSensorVariable.subzone;
    VscpSensorPacketstring += "\n";

    VscpSensorPacketstring += "COMMENTS :";
    VscpSensorPacketstring += vscpSensorPacket.packetSensorVariable.comments;
    VscpSensorPacketstring += "\n";
    */

}

//copy vscp switch packet to the -- string
void MainWindow::SwitchPacketCreateString(T_widgetWebsocketPacketSwitch &vscpSwitchPacket, QString &VscpSwitchPacketstring)
{
    /******* Websocket string *******/
    //VscpSwitchPacketstring  = "WEBSOCKET CONFIGURE :--";
    VscpSwitchPacketstring  = "WEBSOCKET CONFIGURE: DONE";

    VscpSwitchPacketstring += "\n";
    VscpSwitchPacketstring += "\n";

    /*VscpSwitchPacketstring += "ID :";
    VscpSwitchPacketstring += vscpSwitchPacket.id;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "URL :";
    VscpSwitchPacketstring += vscpSwitchPacket.url;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "bLocal :";
    VscpSwitchPacketstring += vscpSwitchPacket.bLocal;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "bNoState :";
    VscpSwitchPacketstring += vscpSwitchPacket.bNoState;
    VscpSwitchPacketstring += "\n";

    *** Tx ON Event String ***/
    //VscpSwitchPacketstring  += "Tx ON Event :--";
    VscpSwitchPacketstring  += "Tx ON Event : DONE";
    VscpSwitchPacketstring += "\n";
    VscpSwitchPacketstring += "\n";

    /*VscpSwitchPacketstring += "CLASS VALUE :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOnEvent.class_value;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "TYPE VALUE :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOnEvent.type_value;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "GUID :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOnEvent.guid;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "INDEX :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOnEvent.index;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "ZONE :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOnEvent.zone;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "SUBZONE :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOnEvent.subzone;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "HEAD :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOnEvent.head;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "OBID :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOnEvent.obid;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "TIMESTAMP :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOnEvent.timeStamp;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "DATA :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOnEvent.data;
    VscpSwitchPacketstring += "\n";

    *** Tx OFF Event String ***/
    //VscpSwitchPacketstring  += "TX OFF Event :--";
    VscpSwitchPacketstring  += "Tx OFF Event : DONE";
    VscpSwitchPacketstring += "\n";
    VscpSwitchPacketstring += "\n";

    /*VscpSwitchPacketstring += "CLASS VALUE :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOffEvent.class_value;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "TYPE VALUE :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOffEvent.type_value;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "GUID :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOffEvent.guid;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "INDEX :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOffEvent.index;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "ZONE :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOffEvent.zone;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "SUBZONE :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOffEvent.subzone;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "HEAD :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOffEvent.head;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "OBID :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOffEvent.obid;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "TIMESTAMP :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOffEvent.timeStamp;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "DATA :";
    VscpSwitchPacketstring += vscpSwitchPacket.txOffEvent.data;
    VscpSwitchPacketstring += "\n";

    *** Rx ON Event String ***/
    //VscpSwitchPacketstring  += "RX ON Event :--";
    VscpSwitchPacketstring  += "Rx ON Event : DONE";
    VscpSwitchPacketstring += "\n";
    VscpSwitchPacketstring += "\n";

    /*VscpSwitchPacketstring += "CLASS VALUE :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOnEvent.class_value;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "TYPE VALUE :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOnEvent.type_value;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "GUID :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOnEvent.guid;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "INDEX :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOnEvent.index;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "ZONE :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOnEvent.zone;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "SUBZONE :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOnEvent.subzone;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "HEAD :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOnEvent.head;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "OBID :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOnEvent.obid;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "TIMESTAMP :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOnEvent.timeStamp;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "DATA :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOnEvent.data;
    VscpSwitchPacketstring += "\n";

    *** Rx OFF Event String ***/
    //VscpSwitchPacketstring  += "RX OFF Event :--";
    VscpSwitchPacketstring  += "Rx OFF Event : DONE";
    VscpSwitchPacketstring += "\n";
    VscpSwitchPacketstring += "\n";

    /*VscpSwitchPacketstring += "CLASS VALUE :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOffEvent.class_value;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "TYPE VALUE :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOffEvent.type_value;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "GUID :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOffEvent.guid;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "INDEX :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOffEvent.index;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "ZONE :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOffEvent.zone;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "SUBZONE :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOffEvent.subzone;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "HEAD :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOffEvent.head;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "OBID :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOffEvent.obid;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "TIMESTAMP :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOffEvent.timeStamp;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "DATA :";
    VscpSwitchPacketstring += vscpSwitchPacket.rxOffEvent.data;
    VscpSwitchPacketstring += "\n";

    ******* Variable Configure string *******/
    //VscpSwitchPacketstring += "VARIABLE CONFIGURE :--";
    VscpSwitchPacketstring  += "VARIABLE CONFIGURE : DONE";
    VscpSwitchPacketstring += "\n";
    VscpSwitchPacketstring += "\n";

    /*VscpSwitchPacketstring += "NAME :";
    VscpSwitchPacketstring += vscpSwitchPacket.packetSwitchVariable.name;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "GROUP ID :";
    VscpSwitchPacketstring += vscpSwitchPacket.packetSwitchVariable.groupId;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "ALLOWED FROM :";
    VscpSwitchPacketstring += vscpSwitchPacket.packetSwitchVariable.allowedFrom;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "ALLOWED TO :";
    VscpSwitchPacketstring += vscpSwitchPacket.packetSwitchVariable.allowedTo;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "ALLOWED TIME :";
    VscpSwitchPacketstring += vscpSwitchPacket.packetSwitchVariable.allowedTime;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "ALLOWED DAYS :";
    if(vscpSwitchPacket.packetSwitchVariable.allowedDays.mon == "true")
    {
        VscpSwitchPacketstring += "mon";
    }

    if(vscpSwitchPacket.packetSwitchVariable.allowedDays.tue == "true")
    {
        VscpSwitchPacketstring += ",tue";
    }

    if(vscpSwitchPacket.packetSwitchVariable.allowedDays.wed == "true")
    {
        VscpSwitchPacketstring += ",wed";
    }

    if(vscpSwitchPacket.packetSwitchVariable.allowedDays.thur == "true")
    {
        VscpSwitchPacketstring += ",thur";
    }

    if(vscpSwitchPacket.packetSwitchVariable.allowedDays.fri == "true")
    {
        VscpSwitchPacketstring += ",fri";
    }

    if(vscpSwitchPacket.packetSwitchVariable.allowedDays.sat == "true")
    {
        VscpSwitchPacketstring += ",sat";
    }

    if(vscpSwitchPacket.packetSwitchVariable.allowedDays.sun == "true")
    {
        VscpSwitchPacketstring += ",sun";
    }

    VscpSwitchPacketstring += "ACTION :";
    VscpSwitchPacketstring += vscpSwitchPacket.packetSwitchVariable.action;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "ACTION PARAMETERS :";
    VscpSwitchPacketstring += vscpSwitchPacket.packetSwitchVariable.actionParameters;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "CONTROL :";
    if(vscpSwitchPacket.packetSwitchVariable.control.EnableRow == "true")
    {
        VscpSwitchPacketstring += "Enable Row";
    }

    if(vscpSwitchPacket.packetSwitchVariable.control.checkIndex == "true")
    {
        VscpSwitchPacketstring += ",Check Index";
    }

    if(vscpSwitchPacket.packetSwitchVariable.control.checkzone == "true")
    {
        VscpSwitchPacketstring += ",Check zone";
    }

    if(vscpSwitchPacket.packetSwitchVariable.control.endScan == "true")
    {
        VscpSwitchPacketstring += ",End Scan";
    }

    if(vscpSwitchPacket.packetSwitchVariable.control.checkSubzone == "true")
    {
        VscpSwitchPacketstring += ",Check Subzone";
    }

    VscpSwitchPacketstring += "CLASS VALUE :";
    VscpSwitchPacketstring += vscpSwitchPacket.packetSwitchVariable.class_value;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "TYPE VALUE :";
    VscpSwitchPacketstring += vscpSwitchPacket.packetSwitchVariable.type_value;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "GUID :";
    VscpSwitchPacketstring += vscpSwitchPacket.packetSwitchVariable.guid;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "PRIORITY :";
    VscpSwitchPacketstring += vscpSwitchPacket.packetSwitchVariable.priority;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "INDEX :";
    VscpSwitchPacketstring += vscpSwitchPacket.packetSwitchVariable.index;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "ZONE :";
    VscpSwitchPacketstring += vscpSwitchPacket.packetSwitchVariable.zone;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "SUBZONE :";
    VscpSwitchPacketstring += vscpSwitchPacket.packetSwitchVariable.subzone;
    VscpSwitchPacketstring += "\n";

    VscpSwitchPacketstring += "COMMENTS :";
    VscpSwitchPacketstring += vscpSwitchPacket.packetSwitchVariable.comments;
    VscpSwitchPacketstring += "\n";*/


}

//copy vscp slider packet to the -- string
void MainWindow::SliderPacketCreateString(T_widgetWebsocketPacketSlider &vscpSliderPacket, QString &VscpSwitchPacketstring)
{
    /******* Websocket string *******/
    //VscpSwitchPacketstring  = "WEBSOCKET CONFIGURE :--";
    VscpSwitchPacketstring  = "WEBSOCKET CONFIGURE: DONE";

    VscpSwitchPacketstring += "\n";
    VscpSwitchPacketstring += "\n";


    /*** Tx Event String ***/
    //VscpSwitchPacketstring  += "Tx Event :--";
    VscpSwitchPacketstring  += "Tx Event : DONE";
    VscpSwitchPacketstring += "\n";
    VscpSwitchPacketstring += "\n";


    /*** Rx Event String ***/
    //VscpSwitchPacketstring  += "Rx Event :--";
    VscpSwitchPacketstring  += "Rx Event : DONE";
    VscpSwitchPacketstring += "\n";
    VscpSwitchPacketstring += "\n";

    /******* Variable Configure string *******/
    //VscpSwitchPacketstring += "VARIABLE CONFIGURE :--";
    VscpSwitchPacketstring  += "VARIABLE CONFIGURE : DONE";
    VscpSwitchPacketstring += "\n";
    VscpSwitchPacketstring += "\n";
}

//copy vscp variable button packet to the -- string
void MainWindow::VariableButtonPacketCreateString(T_widgetWebsocketPacketVariableSwitch &vscpVariableSwitchPacket, QString &VscpSwitchPacketstring)
{
    /******* Websocket string *******/
    //VscpSwitchPacketstring  = "WEBSOCKET CONFIGURE :--";
    VscpSwitchPacketstring  = "WEBSOCKET CONFIGURE: DONE";

    VscpSwitchPacketstring += "\n";
    VscpSwitchPacketstring += "\n";


    /*** Tx Event String ***/
    //VscpSwitchPacketstring  += "Tx Event :--";
    VscpSwitchPacketstring  += "Tx Event : DONE";
    VscpSwitchPacketstring += "\n";
    VscpSwitchPacketstring += "\n";


    /*** Rx Event String ***/
    //VscpSwitchPacketstring  += "Rx Event :--";
    VscpSwitchPacketstring  += "Rx Event : DONE";
    VscpSwitchPacketstring += "\n";
    VscpSwitchPacketstring += "\n";

    /******* Variable Configure string *******/
    //VscpSwitchPacketstring += "VARIABLE CONFIGURE :--";
    VscpSwitchPacketstring  += "VARIABLE CONFIGURE : DONE";
    VscpSwitchPacketstring += "\n";
    VscpSwitchPacketstring += "\n";
}

// Initialise the CAN packet
void MainWindow::CanPacketInitialise(T_testCaseStepCanPacket &canPacket)
{
    canPacket.stepnumber = 0;
    canPacket.u16_CanId = "";
    canPacket.u8_dlc    = "";
    canPacket.u8_byte0 = "";
    canPacket.u8_byte1 = "";
    canPacket.u8_byte2 = "";
    canPacket.u8_byte3 = "";
    canPacket.u8_byte4 = "";
    canPacket.u8_byte5 = "";
    canPacket.u8_byte6 = "";
    canPacket.u8_byte7 = "";
}

// Initialise the Device details packet
void MainWindow::deviceDetailsInitialise(T_testStepDetails &testCaseStepsDetails_redo)
{
    testCaseStepsDetails_redo.u8_deviceName = "";
    testCaseStepsDetails_redo.u8_deviceType = "";
    testCaseStepsDetails_redo.u8_deviceSubType = "";
    testCaseStepsDetails_redo.u8_devicePacket = "";
    testCaseStepsDetails_redo.u8_deviceImage = "";
    testCaseStepsDetails_redo.u8_deviceInfo = "";

}
// Initialise the vscp packet
void MainWindow::VscpPacketInitialise(T_vscpDevicePacket &vscpPacket)
{
    vscpPacket.stepnumber = 0;
    vscpPacket.packetType = UNDEFINED_PACKET_TYPE;

    SensorPacketInitialise(vscpPacket.vscpPacketSensor);
    SwitchPacketInitialise(vscpPacket.vscpPacketSwitch);
    SliderPacketInitialise(vscpPacket.vscpPacketSlider);
    SliderPacketVariableSwitchInitialise(vscpPacket.vscpPacketVariableSwitch);
}

// Initialise the Sensor packet
void MainWindow::SensorPacketInitialise(T_widgetwebsocketPacketsensor &packetSensor)
{
    packetSensor.id = "";
    packetSensor.graphId = "";
    packetSensor.graphUnitId = "";
    packetSensor.graphType = "";
    packetSensor.idRemoteTxt = "";
    packetSensor.url = "";
    packetSensor.class_value = "";
    packetSensor.type_value = "";
    packetSensor.codingIndex = "";
    packetSensor.decimals = "";
    packetSensor.formatString = "";
    packetSensor.guid = "";
    packetSensor.callback = "";
    vscpVariableInitialise(packetSensor.packetSensorVariable);

}

// Initialise the switch packet
void MainWindow::SwitchPacketInitialise(T_widgetWebsocketPacketSwitch &packetSwitch)
{
    packetSwitch.id = "";
    packetSwitch.url = "";
    packetSwitch.bLocal = "";
    packetSwitch.bNoState = "";
    vscpEventInitialise(packetSwitch.txOnEvent);
    vscpEventInitialise(packetSwitch.txOffEvent);
    vscpEventInitialise(packetSwitch.rxOnEvent);
    vscpEventInitialise(packetSwitch.txOnEvent);
    vscpSwitchVariableInitialise(packetSwitch.packetSwitchVariable);
}


void MainWindow::SliderPacketInitialise(T_widgetWebsocketPacketSlider &packetSlider)
{
    packetSlider.id = "";
    packetSlider.idLocalTxt = "";
    packetSlider.idRemoteTxt = "";
    packetSlider.url = "";
    packetSlider.maxValue = "";
    packetSlider.minValue = "";
    vscpSliderEventInitialise(packetSlider.txEvent);
    vscpSliderEventInitialise(packetSlider.rxEvent);
    vscpVariableInitialise(packetSlider.packetSliderVariable);
}

void MainWindow::SliderPacketVariableSwitchInitialise(T_widgetWebsocketPacketVariableSwitch &packetVariableSwitch)
{
    packetVariableSwitch.idIncImage = "";
    packetVariableSwitch.idDecImage = "";
    packetVariableSwitch.idLocalTxt = "";
    packetVariableSwitch.idRemoteTxt = "";
    packetVariableSwitch.url = "";
    packetVariableSwitch.maxValue = "";
    packetVariableSwitch.minValue = "";
    vscpSliderEventInitialise(packetVariableSwitch.txEvent);
    vscpSliderEventInitialise(packetVariableSwitch.rxEvent);
    vscpVariableInitialise(packetVariableSwitch.packetVariableSwitchVariable);
}


// Initialise the vscp Event packet
void MainWindow::vscpEventInitialise(T_event &packetEvent)
{
    packetEvent.class_value = "";
    packetEvent.type_value = "";
    packetEvent.guid = "";
    packetEvent.index = "";
    packetEvent.zone = "";
    packetEvent.subzone = "";
    packetEvent.head = "";
    packetEvent.obid = "";
    packetEvent.timeStamp = "";
    packetEvent.data = "";

}

// Initialise the vscp Slider Event packet
void MainWindow::vscpSliderEventInitialise(T_eventSlider &packetEvent)
{
    packetEvent.class_value = "";
    packetEvent.type_value = "";
    packetEvent.guid = "";
    packetEvent.index = "";
    packetEvent.zone = "";
    packetEvent.subzone = "";
    packetEvent.head = "";
    packetEvent.obid = "";
    packetEvent.timeStamp = "";
    packetEvent.data = "";

}

// Initialise the vscp variable initialise
void MainWindow::vscpVariableInitialise(T_variableConfigure &vscpVariable)
{
    vscpVariable.name = "";
    vscpVariable.groupId = "";
    vscpVariable.allowedFrom = "";
    vscpVariable.allowedTo = "";
    vscpVariable.allowedTime = "";
    vscpVariable.allowedDays.mon = "false";
    vscpVariable.allowedDays.tue = "false";
    vscpVariable.allowedDays.wed = "false";
    vscpVariable.allowedDays.thur = "false";
    vscpVariable.allowedDays.fri = "false";
    vscpVariable.allowedDays.sat = "false";
    vscpVariable.allowedDays.sun = "false";
    vscpVariable.action = "";
    vscpVariable.actionParameters = "";
    vscpVariable.control.EnableRow = "false";
    vscpVariable.control.checkIndex = "false";
    vscpVariable.control.checkzone = "false";
    vscpVariable.control.checkSubzone = "false";
    vscpVariable.control.endScan = "false";
    vscpVariable.class_value = "";
    vscpVariable.type_value = "";
    vscpVariable.guid = "";
    vscpVariable.priority = "";
    vscpVariable.index = "";
    vscpVariable.zone = "";
    vscpVariable.subzone = "";
    vscpVariable.comments = "";
}


// Initialise the vscp variable initialise
void MainWindow::vscpSwitchVariableInitialise(T_variableConfigureSwitch &vscpVariable)
{
    vscpVariable.name = "";
    vscpVariable.groupId = "";
    vscpVariable.allowedFrom = "";
    vscpVariable.allowedTo = "";
    vscpVariable.allowedTime = "";
    vscpVariable.allowedDays.mon = "false";
    vscpVariable.allowedDays.tue = "false";
    vscpVariable.allowedDays.wed = "false";
    vscpVariable.allowedDays.thur = "false";
    vscpVariable.allowedDays.fri = "false";
    vscpVariable.allowedDays.sat = "false";
    vscpVariable.allowedDays.sun = "false";
    vscpVariable.action = "";
    vscpVariable.actionParametersSet = "";
    vscpVariable.actionParametersReset = "";
    vscpVariable.control.EnableRow = "false";
    vscpVariable.control.checkIndex = "false";
    vscpVariable.control.checkzone = "false";
    vscpVariable.control.checkSubzone = "false";
    vscpVariable.control.endScan = "false";
    vscpVariable.class_value_on = "";
    vscpVariable.type_value_on = "";
    vscpVariable.class_value_off = "";
    vscpVariable.type_value_off = "";
    vscpVariable.guid = "";
    vscpVariable.priority = "";
    vscpVariable.index = "";
    vscpVariable.zone = "";
    vscpVariable.subzone = "";
    vscpVariable.comments = "";
}

// Clear the TX & Rx list
void MainWindow::clearTxRxList()
{
    //clear the Tx list
    while (!testCaseStepCanPacket_tx.isEmpty())
       testCaseStepCanPacket_tx.removeFirst();
    //clear the Rx list
    while (!testCaseStepCanPacket_rx.isEmpty())
       testCaseStepCanPacket_rx.removeFirst();
}

//Create string of packet
void MainWindow::CreateStringForTestStepPacket(QList<T_vscpDevicePacket> &testCaseStepCanPacketList, int row, QString &testStepPacket)
{
    //T_testCaseStepCanPacket canPacket;
    T_vscpDevicePacket vscpPacket;
    //T_testCaseStepCanPacket testCaseStepCanMessage;
    T_vscpDevicePacket testCaseStepCanMessage;
    bool messageInTxQueue = false;

    // Initialise the CAN packet
    //CanPacketInitialise(canPacket);
    VscpPacketInitialise(vscpPacket);

    // Check if list is empty
    if(!testCaseStepCanPacketList.isEmpty())
    {
        for (uint16_t i = 0; i < testCaseStepCanPacketList.size(); ++i)
        {
             //Read from list without removing node
             testCaseStepCanMessage = testCaseStepCanPacketList.at(i);
             if(testCaseStepCanMessage.stepnumber == row)
             {
                 messageInTxQueue = true;
                 //canPacket = testCaseStepCanMessage;
                 vscpPacket = testCaseStepCanMessage;
                 break;
             }

         }
    }

    // Create string out of the Packet
    //CanPacketCreateString(canPacket,testStepPacket);
    VscpPacketCreateString(vscpPacket,testStepPacket);

}

void MainWindow::on_deviceUndoPushButton_clicked()
{
    uint8_t row;
    //QVariant variant;
    QStandardItem *item;
    T_testStepDetails testStepDetailsPacket;
    QString vscpPacketString;
    QVariant deviceTypeVariant;
    T_vscpDevicePacket vscpPacket;

    //variant.toString() = "";
    // check if test report is already open or not
    if (b_xmlFileAlreadyOpen)
    {
        //Test if undolist is empty
        if(!testCaseStepCanPacket_undo.isEmpty())
        {
            row = ui->testCaseTableView->currentIndex().row();

            // size returns number of items in list
            // and row numbering starts from - 0
            if(testCaseStepCanPacket_undo.size() >= (uint8_t)(row + 1u))
            {
                // Set the redo items
                testCaseStepCanPacket_redo = testCaseStepCanPacket_rx.at(row);  // Read the vscp packet
                deviceTypeVariant = model->data(model->index(row,DEVICE_DESCRIPTION_DEVICE_NAME)) ;
                testCaseStepsDetails_redo.u8_deviceName  = deviceTypeVariant.toString();
                deviceTypeVariant = model->data(model->index(row,DEVICE_DESCRIPTION_DEVICE_TYPE)) ;
                testCaseStepsDetails_redo.u8_deviceType  = deviceTypeVariant.toString();
                deviceTypeVariant = model->data(model->index(row,DEVICE_DESCRIPTION_DEVICE_SUB_TYPE)) ;
                testCaseStepsDetails_redo.u8_deviceSubType  = deviceTypeVariant.toString();
                deviceTypeVariant = model->data(model->index(row,DEVICE_DESCRIPTION_DEVICE_IMAGE)) ;
                testCaseStepsDetails_redo.u8_deviceImage  = deviceTypeVariant.toString();
                deviceTypeVariant = model->data(model->index(row,DEVICE_DESCRIPTION_DEVICE_INFO)) ;
                testCaseStepsDetails_redo.u8_deviceInfo  = deviceTypeVariant.toString();
                //testCaseStepsDetails_redo.u8_devicePacket  = deviceTypeVariant.toString();


                //Replace the current list item
                vscpPacket = testCaseStepCanPacket_undo.at(row);
                testCaseStepCanPacket_rx.replace(row,vscpPacket);
                //Read from undo item list
                testStepDetailsPacket = testCaseStepslist_undo.at(row);
                //Set device name
                // copy value to the QStandardItem
                item = new QStandardItem(QString(testStepDetailsPacket.u8_deviceName ));
                model->setItem(row,DEVICE_DESCRIPTION_DEVICE_NAME,item);
                //Set device type
                // copy value to the QStandardItem
                item = new QStandardItem(QString(testStepDetailsPacket.u8_deviceType ));
                model->setItem(row,DEVICE_DESCRIPTION_DEVICE_TYPE,item);
                //Set device sub type
                // copy value to the QStandardItem
                item = new QStandardItem(QString(testStepDetailsPacket.u8_deviceSubType ));
                model->setItem(row,DEVICE_DESCRIPTION_DEVICE_SUB_TYPE,item);
                //Set device image
                // copy value to the QStandardItem
                item = new QStandardItem(QString(testStepDetailsPacket.u8_deviceImage ));
                model->setItem(row,DEVICE_DESCRIPTION_DEVICE_IMAGE,item);
                //Set device info
                // copy value to the QStandardItem
                item = new QStandardItem(QString(testStepDetailsPacket.u8_deviceInfo ));
                model->setItem(row,DEVICE_DESCRIPTION_DEVICE_INFO,item);
                //convert undo can packet into string
                VscpPacketCreateString(vscpPacket,vscpPacketString);
                //Set device packet
                // copy value to the QStandardItem
                item = new QStandardItem(QString(vscpPacketString ));
                model->setItem(row,DEVICE_DESCRIPTION_DEVICE_PACKET,item);

                //Select the first row
                ui->testCaseTableView->selectRow(row);

            }
            else
            {
                QMessageBox::information(this, "undoDevice", NEW_DEVICE_CREATED_NOTHING_TO_UNDO);
            }

            //QMessageBox::information(this, "undoDevice", "undo list is not empty");

        }
        else
        {
            QMessageBox::information(this, "undoDevice", NEW_DEVICE_CREATED_NOTHING_TO_UNDO);
        }
    }
    else {
        QMessageBox::information(this, "uiMagician", CREATE_OPEN_HOUSE_CONFIGUATION_FILE);
    }
}

void MainWindow::on_devicRedoPushButton_clicked()
{
    uint8_t row;
    //QVariant variant;
    QStandardItem *item;
    T_testStepDetails testStepDetailsPacket;
    QString vscpPacketString;
    //QVariant deviceTypeVariant;

    //variant.toString() = "";
    // check if test report is already open or not
    if (b_xmlFileAlreadyOpen)
    {
        //Test if undolist is empty
        if(!testCaseStepCanPacket_undo.isEmpty())
        {
            row = ui->testCaseTableView->currentIndex().row();

            // size returns number of items in list
            // and row numbering starts from - 0
            if(testCaseStepCanPacket_undo.size() >= (uint8_t)(row + 1u))
            {
                //Replace the current list item
                testCaseStepCanPacket_rx.replace(row,testCaseStepCanPacket_redo);
                //Read from Redo item list
                testStepDetailsPacket = testCaseStepsDetails_redo;
                //Set device name
                // copy value to the QStandardItem
                item = new QStandardItem(QString(testStepDetailsPacket.u8_deviceName ));
                model->setItem(row,DEVICE_DESCRIPTION_DEVICE_NAME,item);
                //Set device type
                // copy value to the QStandardItem
                item = new QStandardItem(QString(testStepDetailsPacket.u8_deviceType ));
                model->setItem(row,DEVICE_DESCRIPTION_DEVICE_TYPE,item);
                //Set device sub type
                // copy value to the QStandardItem
                item = new QStandardItem(QString(testStepDetailsPacket.u8_deviceSubType ));
                model->setItem(row,DEVICE_DESCRIPTION_DEVICE_SUB_TYPE,item);
                //Set device image
                // copy value to the QStandardItem
                item = new QStandardItem(QString(testStepDetailsPacket.u8_deviceImage ));
                model->setItem(row,DEVICE_DESCRIPTION_DEVICE_IMAGE,item);
                //Set device info
                // copy value to the QStandardItem
                item = new QStandardItem(QString(testStepDetailsPacket.u8_deviceInfo ));
                model->setItem(row,DEVICE_DESCRIPTION_DEVICE_INFO,item);
                //convert undo can packet into string
                VscpPacketCreateString(testCaseStepCanPacket_redo,vscpPacketString);
                //Set device packet
                // copy value to the QStandardItem
                item = new QStandardItem(QString(vscpPacketString ));
                model->setItem(row,DEVICE_DESCRIPTION_DEVICE_PACKET,item);

                //Select the first row
                ui->testCaseTableView->selectRow(row);
            }
            else
            {
                QMessageBox::information(this, "redoDevice", NEW_DEVICE_CREATED_NOTHING_TO_REDO);
            }

        }
        else
        {
            QMessageBox::information(this, "redoDevice", NEW_DEVICE_CREATED_NOTHING_TO_REDO);
        }
    }
    else {
        QMessageBox::information(this, "redoDevice", CREATE_OPEN_HOUSE_CONFIGUATION_FILE);
    }

}


void MainWindow::on_testCaseTableView_clicked(const QModelIndex &index)
{
    //QString tempstr ;
    T_vscpDevicePacket testCaseStepCanMessage;
    T_vscpDevicePacket vscpPacket;
    // Save the packet for device details
    T_testStepDetails testCaseStepsDetails_temp;
    QVariant deviceTypeVariant;
    QVariant undefinedPacketVariant(UNDEFINED_PACKET_STRING);

    // check if test report is already open or not
    if (b_xmlFileAlreadyOpen)
    {
        if (index.row() != currentDeviceRow)
        {
            if(!testCaseStepCanPacket_undo.isEmpty())
            {

                // --- error we are reading something -- if suppose clicked without entring the packet
                if(model->data(model->index(currentDeviceRow,DEVICE_DESCRIPTION_DEVICE_PACKET)).toString() == PACKET_INITIAL_STRING)
                {
                    vscpPacket.stepnumber = currentDeviceRow;
                    vscpPacket.packetType = UNDEFINED_PACKET_TYPE;
                    SensorPacketInitialise(vscpPacket.vscpPacketSensor);
                    SwitchPacketInitialise(vscpPacket.vscpPacketSwitch);
                    SliderPacketInitialise(vscpPacket.vscpPacketSlider);
                    SliderPacketVariableSwitchInitialise(vscpPacket.vscpPacketVariableSwitch);

                    //Apend the undefined packet
                    testCaseStepCanPacket_rx.append(vscpPacket);

                    //QMessageBox::information(this, "test", "test_1");

                    //update the model cell
                    model->setData(model->index(currentDeviceRow,DEVICE_DESCRIPTION_DEVICE_PACKET_COLUMN),undefinedPacketVariant);

                    model->setData( model->index(currentDeviceRow,DEVICE_DESCRIPTION_DEVICE_PACKET_COLUMN),Qt::red,Qt::ForegroundRole);
                    //QMessageBox::information(this, "changed", UNDEFINED_PACKET_STRING);


                }
                // --- error if nothing is their then -- enter a packet from your side inside --- testCaseStepCanPacket_rx

                // Check if new device have been added & click is on come other row
                if(testCaseStepCanPacket_undo.size() < testCaseStepCanPacket_rx.size())
                {
                    /* OK logic

                        //Read from list without removing node
                        testCaseStepCanMessage = testCaseStepCanPacket_rx.at(currentDeviceRow);
                        //append - new item to the end of the undo list
                        testCaseStepCanPacket_undo.append(testCaseStepCanMessage);
                    */

                    //clear the undolist
                    testCaseStepCanPacket_undo.clear();
                    //update the undo list to latest -- by itterate through the actual list
                    for (uint16_t i = 0; i < testCaseStepCanPacket_rx.size(); ++i)
                    {
                         //Read from list
                         testCaseStepCanMessage = testCaseStepCanPacket_rx.at(i);
                         testCaseStepCanPacket_undo.append(testCaseStepCanMessage);
                    }

                    testCaseStepslist_undo.clear();
                    for(int i=0; i<model->rowCount();i++)
                    {
                        // prepare the teststepdetails data
                        deviceTypeVariant = model->data(model->index(i,DEVICE_DESCRIPTION_DEVICE_NAME)) ;
                        testCaseStepsDetails_temp.u8_deviceName  = deviceTypeVariant.toString();
                        deviceTypeVariant = model->data(model->index(i,DEVICE_DESCRIPTION_DEVICE_TYPE)) ;
                        testCaseStepsDetails_temp.u8_deviceType  = deviceTypeVariant.toString();
                        deviceTypeVariant = model->data(model->index(i,DEVICE_DESCRIPTION_DEVICE_SUB_TYPE)) ;
                        testCaseStepsDetails_temp.u8_deviceSubType  = deviceTypeVariant.toString();
                        deviceTypeVariant = model->data(model->index(i,DEVICE_DESCRIPTION_DEVICE_IMAGE)) ;
                        testCaseStepsDetails_temp.u8_deviceImage  = deviceTypeVariant.toString();
                        deviceTypeVariant = model->data(model->index(i,DEVICE_DESCRIPTION_DEVICE_INFO)) ;
                        testCaseStepsDetails_temp.u8_deviceInfo  = deviceTypeVariant.toString();
                        //append - new item to the end of the undo list
                        testCaseStepslist_undo.append(testCaseStepsDetails_temp);
                    }

                }

            }
            else
            {
                //Undo list is empty - do nothing as new room is added
            }
        }
        else
        {
            //Same row clicked do nothing

        }

        VscpPacketInitialise(testCaseStepCanPacket_redo);
        deviceDetailsInitialise(testCaseStepsDetails_redo);
        //Set the current row
        currentDeviceRow = index.row();
    }
    else {
        QMessageBox::information(this, "uiMagician", CREATE_OPEN_HOUSE_CONFIGUATION_FILE);
    }
}

void MainWindow::on_roomUndoPushButton_clicked()
{
    T_vscpDevicePacket testCaseStepCanMessage;
    T_vscpDevicePacket vscpPacket;
    QVariant deviceTypeVariant;
    T_testStepDetails testCaseStepsDetails_temp;
    QVariant undefinedPacketVariant(UNDEFINED_PACKET_STRING);

    // check if test report is already open or not
    if (b_xmlFileAlreadyOpen)
    {
        if(!testCaseStepCanPacket_undoRoom.isEmpty())
        {

            //Again pressing undo button
            if(b_roomUndoPressed == TRUE )
            {
                QMessageBox::information(this, "undoRoom", NOTHING_TO_UNDO);
                return;
            }

            if(!testCaseStepCanPacket_undo.isEmpty())
            {
                // --- error if we pressed undo button -- without entring the packet -- enter packet in actual list fomyour side
                if(model->data(model->index(currentDeviceRow,DEVICE_DESCRIPTION_DEVICE_PACKET)).toString() == PACKET_INITIAL_STRING)
                {
                    vscpPacket.stepnumber = currentDeviceRow;

                    if(model->data(model->index(currentDeviceRow,DEVICE_DESCRIPTION_DEVICE_TYPE)).toString() == DEVICE_SWITCH)
                    {
                        vscpPacket.packetType = SWITCH_PACKET_TYPE;
                    }
                    else if(model->data(model->index(currentDeviceRow,DEVICE_DESCRIPTION_DEVICE_TYPE)).toString() == DEVICE_SENSOR)
                    {
                        vscpPacket.packetType = SENSOR_PACKET_TYPE;
                    }
                    else
                    {
                        vscpPacket.packetType = UNDEFINED_PACKET_TYPE;
                    }
                    SensorPacketInitialise(vscpPacket.vscpPacketSensor);
                    SwitchPacketInitialise(vscpPacket.vscpPacketSwitch);
                    SliderPacketInitialise(vscpPacket.vscpPacketSlider);
                    SliderPacketVariableSwitchInitialise(vscpPacket.vscpPacketVariableSwitch);
                    //Apend the undefined packet
                    testCaseStepCanPacket_rx.append(vscpPacket);

                    //QMessageBox::information(this, "enter packet count", QString::number(testCaseStepCanPacket_rx.size()));

                    //update the model cell
                    model->setData(model->index(currentDeviceRow,DEVICE_DESCRIPTION_DEVICE_PACKET_COLUMN),undefinedPacketVariant);

                }
                    // --- error if nothing is their then -- enter a packet from your side inside --- testCaseStepCanPacket_rx
                    /* OK logic

                        //Read from list without removing node
                        testCaseStepCanMessage = testCaseStepCanPacket_rx.at(currentDeviceRow);
                        //append - new item to the end of the undo list
                        testCaseStepCanPacket_undo.append(testCaseStepCanMessage);
                    */

                    //clear the undolist
                    testCaseStepCanPacket_undo.clear();
                    //update the undo list to latest -- by itterate through the actual list
                    for (uint16_t i = 0; i < testCaseStepCanPacket_rx.size(); ++i)
                    {
                         //Read from list
                         testCaseStepCanMessage = testCaseStepCanPacket_rx.at(i);
                         testCaseStepCanPacket_undo.append(testCaseStepCanMessage);
                    }

                    QMessageBox::information(this, "row count", QString::number(model->rowCount()));
                    QMessageBox::information(this, "packet count", QString::number(testCaseStepCanPacket_rx.size()));
                    //update the teststeplist to latest
                    testCaseStepslist_undo.clear();
                    //for(int i=0; 1<testCaseStepCanPacket_rx.size();i++)
                    for(int i=0; i<model->rowCount();i++)
                    {
                        // prepare the teststepdetails data
                        deviceTypeVariant = model->data(model->index(i,DEVICE_DESCRIPTION_DEVICE_NAME)) ;
                        testCaseStepsDetails_temp.u8_deviceName  = deviceTypeVariant.toString();
                        deviceTypeVariant = model->data(model->index(i,DEVICE_DESCRIPTION_DEVICE_TYPE)) ;
                        testCaseStepsDetails_temp.u8_deviceType  = deviceTypeVariant.toString();
                        deviceTypeVariant = model->data(model->index(i,DEVICE_DESCRIPTION_DEVICE_SUB_TYPE)) ;
                        testCaseStepsDetails_temp.u8_deviceSubType  = deviceTypeVariant.toString();
                        deviceTypeVariant = model->data(model->index(i,DEVICE_DESCRIPTION_DEVICE_IMAGE)) ;
                        testCaseStepsDetails_temp.u8_deviceImage  = deviceTypeVariant.toString();
                        deviceTypeVariant = model->data(model->index(i,DEVICE_DESCRIPTION_DEVICE_INFO)) ;
                        testCaseStepsDetails_temp.u8_deviceInfo  = deviceTypeVariant.toString();
                        //append - new item to the end of the undo list
                        testCaseStepslist_undo.append(testCaseStepsDetails_temp);
                    }

            }
            else
            {
                //Undo list is empty - do nothing as new room is added
                QMessageBox::information(this, "undoRoom", "Undo room - List is empty");
            }

            // Copy the Redo values
            roomNameText_redo = ui->roomLineEdit->text();
            floorNameText_redo = ui->floorLineEdit->text();
            houseNameText_redo = ui->houseLineEdit->text();

            //clear the existing list
            testCaseStepCanPacket_rx.clear();
            //change the existing list to original
            // index starting from 0 & size() starts from 1 --> thats why compare is > not >=
            for(int index =0; testCaseStepCanPacket_undoRoom.size() > index ; index++)
            {
                //QMessageBox::information(this, "undo Room Pop up  ", "enter");
                vscpPacket = testCaseStepCanPacket_undoRoom.at(index);
                testCaseStepCanPacket_rx.append(vscpPacket);
            }

            //Change the text view
            createDefaultTableView();

            // Paste the Redo values
            ui->roomLineEdit->setText(roomNameText_undo);
            ui->floorLineEdit->setText(floorNameText_undo);
            ui->houseLineEdit->setText(houseNameText_undo);
            copyBufferRoomDevicesToTheTextEdit(testCaseStepslist_undoRoom);


            if(b_roomRedoPressed == TRUE )
            {
                b_roomRedoPressed = FALSE;
            }

            b_roomUndoPressed = TRUE;

        }
        else
        {
            //Undo list is empty - do nothing as new room is added
            QMessageBox::information(this, "undoRoom", NEW_ROOM_CREATED_NOTHING_TO_UNDO);
        }
    }
    else {
        QMessageBox::information(this, "uiMagician", CREATE_OPEN_HOUSE_CONFIGUATION_FILE);
    }

    QMessageBox::information(this, "uiMagician", "exit -- ??");
}

void MainWindow::on_roomRedoPushButton_clicked()
{
    T_vscpDevicePacket vscpPacket;

    // check if test report is already open or not
    if (b_xmlFileAlreadyOpen)
    {
        if(!testCaseStepCanPacket_undoRoom.isEmpty())
        {
            //Again pressing redo button
            if(b_roomRedoPressed == TRUE )
            {
                QMessageBox::information(this, "redoRoom", NOTHING_TO_REDO);
                return;
            }

            //clear the existing list
            testCaseStepCanPacket_rx.clear();

            //change the existing list to original
            // index starting from 0 & size() starts from 1 --> thats why compare is > not >=
            for(int index =0; testCaseStepCanPacket_undo.size() > index ; index++)
            {
                vscpPacket = testCaseStepCanPacket_undo.at(index);
                testCaseStepCanPacket_rx.append(vscpPacket);
            }

            //Change the text view
            createDefaultTableView();

            // Paste the Redo values
            ui->roomLineEdit->setText(roomNameText_redo);
            ui->floorLineEdit->setText(floorNameText_redo);
            ui->houseLineEdit->setText(houseNameText_redo);
            copyBufferRoomDevicesToTheTextEdit(testCaseStepslist_undo);

            if(b_roomUndoPressed == TRUE )
            {
                b_roomUndoPressed = FALSE;
            }

            b_roomRedoPressed = TRUE;

        }
        else
        {
            //Undo list is empty - do nothing as new room is added
            QMessageBox::information(this, "redoRoom", NEW_ROOM_CREATED_NOTHING_TO_REDO);
        }
    }
    else {
        QMessageBox::information(this, "uiMagician", CREATE_OPEN_HOUSE_CONFIGUATION_FILE);
    }
}

void MainWindow::on_actionUndo_triggered()
{
    QMessageBox* msgBox;
    QPushButton *yesButton;
    QString str = XML_UNDO_CONFIRM_MESSAGE;
    // check if test report is already open or not
    if (b_xmlFileAlreadyOpen)
    {
        //New file creation signal
        if(b_newFileCreationSignal != TRUE)
        {
            //Again pressing undo button
            if(b_xmlUndoPressed == TRUE )
            {
                // ------> do not delete or uncomment these two lines --->here i disabled the effect of b_xmlUndoPressed
                //QMessageBox::information(this, "undoXml", NOTHING_TO_UNDO);
                //return;
            }

            msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Confirmation");
            msgBox->setText(str);

            yesButton = msgBox->addButton(tr("Yes"), QMessageBox::ActionRole);
            msgBox->addButton(tr("No"), QMessageBox::ActionRole);
            msgBox->exec();

            //If user clicks 'Yes'  button
            if ((QPushButton*)msgBox->clickedButton() == yesButton)
            {
                // save the current node
                on_testCaseSavePushButton_clicked();
                //clear the redo dom document
                xmlDomDocumentRedo.clear();
                //set the redo dom document
                xmlDomDocumentRedo = xmlDomDocument.cloneNode(true).toDocument();
                //clear the original document
                xmlDomDocument.clear();
                // set the actual dom document
                xmlDomDocument = xmlDomDocumentOrg.cloneNode(true).toDocument();

                //Re-initialise all the variables
                //initialiseVariables();

                xmlRoot.clear();
                xmlLibObject.xmlGetRoot(xmlRoot, xmlDomDocument);
                // copy data to the tree view
                // copy data to the text view
                loadXmltoTreeAndTextView();

                // Reset the redo button
                if(b_xmlRedoPressed == TRUE )
                {
                    b_xmlRedoPressed = FALSE;
                }
                b_xmlUndoPressed = TRUE;
            }
            else {
                //Do nothing
            }


        }
        else {
            QMessageBox::information(this, "uiMagician", NOTHING_TO_UNDO);
        }

    }
    else {
        QMessageBox::information(this, "uiMagician", CREATE_OPEN_HOUSE_CONFIGUATION_FILE);
    }

}

void MainWindow::on_actionRedo_triggered()
{
    QMessageBox* msgBox;
    QPushButton *yesButton;
    QString str = XML_REDO_CONFIRM_MESSAGE;

    // check if test report is already open or not
    if (b_xmlFileAlreadyOpen)
    {
        //New file creation signal
        if(b_newFileCreationSignal != TRUE)
        {
            //Again pressing Redo button
            if( (b_xmlRedoPressed == TRUE)  || (b_xmlUndoPressed == FALSE))
            {
                QMessageBox::information(this, "redoXml+", NOTHING_TO_REDO);
                return;
            }

            msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Confirmation");
            msgBox->setText(str);

            yesButton = msgBox->addButton(tr("Yes"), QMessageBox::ActionRole);
            msgBox->addButton(tr("No"), QMessageBox::ActionRole);
            msgBox->exec();

            //If user clicks 'Yes'  button
            if ((QPushButton*)msgBox->clickedButton() == yesButton)
            {
                //clear the current dom document
                xmlDomDocument.clear();
                //set the current dom document
                xmlDomDocument = xmlDomDocumentRedo.cloneNode(true).toDocument();

                //Re-initialise all the variables
                //initialiseVariables();

                xmlRoot.clear();
                xmlLibObject.xmlGetRoot(xmlRoot, xmlDomDocument);
                // copy data to the tree view
                // copy data to the text view
                loadXmltoTreeAndTextView();

                // Reset the undo button
                if(b_xmlUndoPressed == TRUE )
                {
                    b_xmlUndoPressed = FALSE;
                }
                b_xmlRedoPressed = TRUE;

            }
            else {
                //Do nothing
            }

        }
        else {
            QMessageBox::information(this, "uiMagician", NOTHING_TO_REDO);
        }
    }
    else {
        QMessageBox::information(this, "uiMagician", CREATE_OPEN_HOUSE_CONFIGUATION_FILE);
    }
}

void MainWindow::on_actionAbout_Ui_Magician_triggered()
{
    //Popup a dialog
    helpAboutUiMagician aboutUiMagician(this);
    aboutUiMagician.exec();
}

void MainWindow::on_actionContent_Help_F1_triggered()
{
    // A Macintosh style tree widget in help.
    helpContent helpContentDialog(this);
    helpContentDialog.exec();
}


// close main window & save existing file
void MainWindow::forceQuitMainWindow( bool closeVar)
{
    QMessageBox* msgBox;
    QPushButton *yesButton;
    QString str = "Save current changes";

    if (b_xmlFileAlreadyOpen){

        msgBox = new QMessageBox(this);
        msgBox->setWindowTitle("Confirmation");
        msgBox->setText(str);

        yesButton = msgBox->addButton(tr("Yes"), QMessageBox::ActionRole);
        msgBox->addButton(tr("No"), QMessageBox::ActionRole);
        msgBox->exec();

        //If user clicks 'Yes'  button
        if ((QPushButton*)msgBox->clickedButton() == yesButton)
        {
            // check if test report is already open or not
            if (b_xmlFileAlreadyOpen){

                if(b_nodeIsNewAndNotSaved == TRUE){
                    on_testCaseSavePushButton_clicked();
                }
                else{
                    //do nothing
                }

                //Close the existing file
                closeExistingFile(xmlFileName, xmlFile, xmlDomDocument);
                // clear the text view edit
                createDefaultTableView();
                // clear the tree view -- remove toplevel items
                clearAllTopLevelItems();
                //Re-initialise all the variables
                initialiseVariables();

            }
        }
        else {
            //Do nothing
        }

    }

    if(closeVar == 1)
    {
        //close app
        emit close();
    }
}


void MainWindow::on_actionExit_Ctrl_Q_triggered()
{
    bool closeVar = 1;
    forceQuitMainWindow(closeVar);
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    bool closeVar = 0;
    forceQuitMainWindow(closeVar);
    //qDebug() << "Alt + f4 was pressed, causing shutdown";
}
