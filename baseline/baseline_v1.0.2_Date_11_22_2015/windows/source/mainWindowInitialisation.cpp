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
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uiMagicianConfiguration.h"
#include "../common/timer/SleepTimerDelay.h"
#include "TestCaseTableView/textviewdeligate.h"
#include "TestCaseTableView/listwidgetdeligate.h"

#include <QtGui>

/*----------------------------------------------------------------------------
** Function    : showSplashScreen
** Description : This function shows Show splash - on starting
** Precondition:  None
** Postcondition: Splash Screen is shown onto the screen
** Parameters  : refrence to QApplication &a
                 refrence to MainWindow& w
** Return value: None
**--------------------------------------------------------------------------*/
void MainWindow::showSplashScreen(QApplication& a, MainWindow& w)
{
    //QPixmap pixmap(":/Images/Images/designer.png");
    QPixmap pixmap(":/Images/Images/vscp_bumblebee.png");
    QSplashScreen splash(pixmap);
    splash.show();

    splash.showMessage(QObject::tr(" uiMagician .. \n Author : Dinesh Guleria"),
                        Qt::AlignLeft | Qt::AlignTop, Qt::black);  //This line represents the alignment of text, color and position
    // Add a delay
    SleepTimerDelay::sleep(1);
    // Clear the splash mesage
    splash.clearMessage();
    //Display Another message
    splash.showMessage(QObject::tr("Initiating your program now..."),
                        Qt::AlignRight | Qt::AlignBottom, Qt::black);  //This line represents the alignment of text, color and position
    //This is used to accept a click on the screen so that user can cancel the screen
    a.processEvents();
    // Add a delay
    SleepTimerDelay::sleep(1);
    //Splash finished
    splash.finish(&w);

}


/*----------------------------------------------------------------------------
** Function    : createTestEditView
** Description : This function is used to Create Test Cases & Test Steps view
** Precondition:  None
** Postcondition: Test Case editor is created in the table view
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
void MainWindow::createTestEditView()
{
    QVariant variant(PACKET_INITIAL_STRING);
    // Create model dynamically
    model= new MyStandardItemModel(MODEL_INITIAL_ROWS, MODEL_INITIAL_COLUMNS);
    model->setData(model->index(DEVICE_INITIAL_ROW_NUMBER,DEVICE_DESCRIPTION_DEVICE_PACKET_COLUMN),variant);

    mydeligate = new textViewDeligate(this);
    //deviceTypedeligateList = "qlist_type";
    deviceTypedeligate = new listWidgetDeligate(deviceTypedeligateList, this) ;
    //deviceSubTypedeligateList = "qlist_subtype";
    deviceSubTypedeligate = new listWidgetDeligate(deviceSubTypedeligateList, this) ;
    //deviceInfodeligate = "qlist_subtype";
    deviceInfodeligate = new listWidgetDeligate(deviceInfodeligateList, this) ;

    // Set Title in the column
    model->setHorizontalHeaderItem(0, new QStandardItem(tr(COLUMN_ZERO_TEXT)));
    model->setHorizontalHeaderItem(1, new QStandardItem(tr(COLUMN_ONE_TEXT)));
    model->setHorizontalHeaderItem(2, new QStandardItem(tr(COLUMN_TWO_TEXT)));
    model->setHorizontalHeaderItem(3, new QStandardItem(tr(COLUMN_THREE_TEXT)));
    model->setHorizontalHeaderItem(4, new QStandardItem(tr(COLUMN_FOUR_TEXT)));
    model->setHorizontalHeaderItem(5, new QStandardItem(tr(COLUMN_FIVE_TEXT)));
    //model->setHorizontalHeaderItem(6, new QStandardItem(tr(COLUMN_SIX_TEXT)));
    //model->setHorizontalHeaderItem(7, new QStandardItem(tr(COLUMN_SEVEN_TEXT)));

}

// If file is already open
void MainWindow::closeExistingFile(QString &xmlFileName, QFile &xmlFile, QDomDocument &xmlDomDocument)
{
    //Check for some node is there in the tree
    if(ui->treeWidgetLeft->topLevelItemCount()> NO_NODE_TO_SAVE)
    {
        // save xml doc
        on_testCaseSavePushButton_clicked();
    }

    // close xml file
    //xmlCloseFile();
    //xmlLibObject.xmlCloseFile(xmlStream, xmlDomDocument, xmlFile);

    xmlLibObject.xmlCloseFileNoFlush(xmlFile);
    //Now again open & truncate the file
    xmlLibObject.xmlOpenFileTruncate( xmlFileName, xmlFile, xmlStream);
    //close the file -- this will save totally new content to the file
    xmlLibObject.xmlCloseFile(xmlStream, xmlDomDocument, xmlFile);

}


// save existing file
void MainWindow::saveExistingFile()
{
    // save xml doc
    on_testCaseSavePushButton_clicked();

    // Write xml to the file
    (xmlStream) << xmlDomDocument.toString();
    // flush the file
    xmlFile.flush();

}

// open already existing file
void MainWindow::openExistingFile(QString &xmlFileName, QFile &xmlFile, QDomDocument &xmlDomDocument, QDomDocument &xmlDomDocumentOrg, bool createFile)
{

    QString filename = xmlFileName;

    // Check if cancel button is pressed in the QFileDialog
    if(filename != "")
    {
        //copy file name to globalobject
        xmlFileName = filename;
        // create new xml file & text stream
        //xmlOpenFile();
        // Add a delay
        xmlLibObject.xmlOpenFile( xmlFileName, xmlFile, xmlStream);

        if(createFile == OPEN_EXISTING_FILE){

            //Load the XML file
            //xmlLoadFile();
            xmlLibObject.xmlLoadFile(xmlDomDocument, xmlFile);

            //close file
            //xmlCloseFile();
            //xmlLibObject.xmlCloseFile(xmlStream, xmlDomDocument, xmlFile);

            //Now again open & truncate the file
            //xmlOpenFileTruncate();
            //xmlLibObject.xmlOpenFileTruncate( xmlFileName, xmlFile, xmlStream);

            //Get the root element
            //xmlGetRoot();
            xmlLibObject.xmlGetRoot(xmlRoot, xmlDomDocument);
            // copy data to the tree view
            // copy data to the text view
            loadXmltoTreeAndTextView();

            //Its not new file
            b_newFileCreationSignal = FALSE;

            //create backup for original xml.
            xmlDomDocumentOrg.clear();
            xmlDomDocumentOrg = xmlDomDocument.cloneNode(true).toDocument();
        }
        else{

            //Do nothing
        }

        // xml file is already open
        b_xmlFileAlreadyOpen = TRUE;

    }
    else {
        // Do nothing cancel presses
    }


}

// if no file is open
void MainWindow::openFile(QString &xmlFileName, QFile &xmlFile, QDomDocument &xmlDomDocument, QDomDocument &xmlDomDocumentOrg, bool createFile)
{

    QString filename;

    // open file diaglog
    if(createFile == OPEN_EXISTING_FILE){
        // Open diaglog to -- open existing file
        filename = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                   "",
                                                   tr("Files (*.xml)"));

    }
    else{
        // Open diaglog to -- create new file
        filename = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                   "",
                                                   tr("Files (*.xml)"));
    }

    // Check if cancel button is pressed in the QFileDialog
    if(filename != "")
    {
        //copy file name to globalobject
        xmlFileName = filename;
        // create new xml file & text stream
        //xmlOpenFile();
        // Add a delay
        xmlLibObject.xmlOpenFile( xmlFileName, xmlFile, xmlStream);

        if(createFile == OPEN_EXISTING_FILE){

            //Load the XML file
            //xmlLoadFile();
            xmlLibObject.xmlLoadFile(xmlDomDocument, xmlFile);

            //close file
            //xmlCloseFile();
            //xmlLibObject.xmlCloseFile(xmlStream, xmlDomDocument, xmlFile);

            //Now again open & truncate the file
            //xmlOpenFileTruncate();
            //xmlLibObject.xmlOpenFileTruncate( xmlFileName, xmlFile, xmlStream);

            //Get the root element
            //xmlGetRoot();
            xmlLibObject.xmlGetRoot(xmlRoot, xmlDomDocument);
            // copy data to the tree view
            // copy data to the text view
            loadXmltoTreeAndTextView();

            //Its not new file
            b_newFileCreationSignal = FALSE;

            //create backup for original xml.
            xmlDomDocumentOrg.clear();
            xmlDomDocumentOrg = xmlDomDocument.cloneNode(true).toDocument();
        }
        else{
            //Add root node
             //xmlAddRoot();            
            xmlLibObject.xmlAddRoot(xmlRoot, xmlDomDocument);

            // File contains new node
            b_fileDoesNotContainsNode = TRUE;

            //New file creation signal
            b_newFileCreationSignal = TRUE;

            //New file created
            xmlDomDocumentOrg.clear();
        }

        // xml file is already open
        b_xmlFileAlreadyOpen = TRUE;

    }
    else {
        // Do nothing cancel presses
    }


}

