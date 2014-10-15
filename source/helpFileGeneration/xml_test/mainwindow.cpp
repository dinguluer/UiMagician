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


#include <QtGui>
#include <QtXml>
#include <QtDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "configureHelp.h"

//#define ROOT_ELEMENT_DETAILS  "TestCases"  //--> IMP  --> no space character is allowed in names of node
#define HELP_ELEMENT_DETAILS  "HelpMenu"
//#define ROOM_NODE_PREFIX    "Room"         //--> IMP  --> no space character is allowed in names of node
#define INDEX_NODE_PREFIX    "Index"
#define ROOM_NAME_ONE       "RoomNameOne"     //--> IMP  --> no space character is allowed in names of node
#define ROOM_NAME           "RoomName"     //--> IMP  --> no space character is allowed in names of node



#define SENSOR_ID              "id"        //--> IMP  --> no space character is allowed in names of node
#define SENSOR_URL             "url"       //--> IMP  --> no space character is allowed in names of node

#define INDEX_NAME             "IndexName"

#define FILE_NAME              "HelpContent.xml"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString xmlFileName(FILE_NAME);
    QFile   xmlFile;
    QTextStream xmlStream;
    // xml dom document object
    QDomDocument xmlDomDocument;
    QDomElement xmlRoot;
    QDomElement NodeElement;

    QDomElement roomNameNode;
    QDomElement houseNameNode;
    QDomElement floorNameNode;

    QDomText textNode;
    QString string;


    //set the name of the file
    xmlFile.setFileName(xmlFileName);

    xmlFile.open(QIODevice::ReadWrite|QIODevice::Text);

    // Assign file to the stream
    xmlStream.setDevice(&xmlFile);

    // Make the root element
        xmlRoot = xmlDomDocument.createElement(HELP_ELEMENT_DETAILS);

        // Add it to the document
        xmlDomDocument.appendChild(xmlRoot);

        string = "About UiMagician";
        NodeElement  = xmlDomDocument.createElement(INDEX_NODE_PREFIX);
        NodeElement.setAttribute(INDEX_NAME,string);
        string = ABOUT_QT_GUI_TEXT;
        textNode = xmlDomDocument.createTextNode(string);
        NodeElement.appendChild(textNode);
        xmlRoot.appendChild(NodeElement);

        string = "User Guide";
        NodeElement  = xmlDomDocument.createElement(INDEX_NODE_PREFIX);
        NodeElement.setAttribute(INDEX_NAME,string);
        string = CREATE_HOW_TO_USE_TOOL_TEXT;
        textNode = xmlDomDocument.createTextNode(string);
        NodeElement.appendChild(textNode);
        xmlRoot.appendChild(NodeElement);

        string = "Create Button";
        NodeElement  = xmlDomDocument.createElement(INDEX_NODE_PREFIX);
        NodeElement.setAttribute(INDEX_NAME,string);
        string = CREATE_BUTTON_TEXT;
        textNode = xmlDomDocument.createTextNode(string);
        NodeElement.appendChild(textNode);
        xmlRoot.appendChild(NodeElement);

        string = "Create Variable Button";
        NodeElement  = xmlDomDocument.createElement(INDEX_NODE_PREFIX);
        NodeElement.setAttribute(INDEX_NAME,string);
        string = CREATE_VARIABLE_BUTTON_TEXT;
        textNode = xmlDomDocument.createTextNode(string);
        NodeElement.appendChild(textNode);
        xmlRoot.appendChild(NodeElement);

        string = "Create Variable Slider";
        NodeElement  = xmlDomDocument.createElement(INDEX_NODE_PREFIX);
        NodeElement.setAttribute(INDEX_NAME,string);
        string = CREATE_VARIABLE_SLIDER_TEXT;
        textNode = xmlDomDocument.createTextNode(string);
        NodeElement.appendChild(textNode);
        xmlRoot.appendChild(NodeElement);

        string = "Create Sensor";
        NodeElement  = xmlDomDocument.createElement(INDEX_NODE_PREFIX);
        NodeElement.setAttribute(INDEX_NAME,string);
        string = CREATE_SENSOR_TEXT;
        textNode = xmlDomDocument.createTextNode(string);
        NodeElement.appendChild(textNode);
        xmlRoot.appendChild(NodeElement);

        string = "Frequently Asked Questions";
        NodeElement  = xmlDomDocument.createElement(INDEX_NODE_PREFIX);
        NodeElement.setAttribute(INDEX_NAME,string);
        string = CREATE_FAQ_TEXT;
        textNode = xmlDomDocument.createTextNode(string);
        NodeElement.appendChild(textNode);
        xmlRoot.appendChild(NodeElement);

        /*
        NodeElement  = xmlDomDocument.createElement(ROOM_NODE_PREFIX);
        roomNameNode = xmlDomDocument.createElement(ROOM_NAME);
        textNode = xmlDomDocument.createTextNode("Drawing room");
        roomNameNode.appendChild(textNode);
        NodeElement.appendChild(roomNameNode);
        string = "hello hw";
        NodeElement.setAttribute(SENSOR_ID,string);
        string = "are you";
        NodeElement.setAttribute(SENSOR_URL,string);
        xmlRoot.appendChild(NodeElement);

        NodeElement  = xmlDomDocument.createElement(ROOM_NAME_ONE);
        roomNameNode = xmlDomDocument.createElement(ROOM_NAME);
        textNode = xmlDomDocument.createTextNode("Bed room");
        roomNameNode.appendChild(textNode);
        NodeElement.appendChild(roomNameNode);
        xmlRoot.appendChild(NodeElement);*/


        // Write xml to the file
        (xmlStream) << xmlDomDocument.toString();



        QMessageBox *msgBox 	= new QMessageBox();
        QDomNodeList list;
        QDomNode nn = xmlDomDocument.firstChild();

        msgBox->setText(nn.toElement().tagName());
        msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
        msgBox->exec();

        list = nn.childNodes();
         //while (!n.isNull()) {
        for(int i =0; i< list.count(); i++)
        {
                 QDomNode e = list.at(i);
                 //qDebug() << "Element name: " << e.tagName() << endl;
                 //msgBox->setText(e.toElement().tagName() + "  :  " + e.toElement().firstChild().toElement().tagName() + "  :  " + e.toElement().firstChild().toElement().text());
                 //msgBox->setText(e.toElement().tagName() );

                 msgBox->setText(e.toElement().attribute(INDEX_NAME));
                 msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
                 msgBox->exec();

                 msgBox->setText(e.toElement().text());
                 msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
                 msgBox->exec();
        }


        // close the file
        xmlFile.flush();
        xmlFile.close();


        /*
        QString str = "Hello world";
        QChar *data = str.data();
        while (!data->isNull()) {
            //qDebug() << data->toAscii();
            if(data->toAscii() == 'H')
            {
                msgBox->setText("H");
                msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
                msgBox->exec();
            }
            ++data;
        }*/

}

MainWindow::~MainWindow()
{
    delete ui;
}
