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


/*
    Licence:
    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version
    2 of the License, or (at your option) any later version.

    This file is part of the UiMagician Project (https://sites.google.com/site/uimagician/)

    This file is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this file see the file COPYING.  If not, write to
    the Free Software Foundation, 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.

    As a special exception, if other files instantiate templates or use macros
    or inline functions from this file, or you compile this file and link it
    with other works to produce a work based on this file, this file does not
    by itself cause the resulting work to be covered by the GNU General Public
    License. However the source code for this file must still be made available
    in accordance with section (3) of the GNU General Public License.

    This exception does not invalidate any other reasons why a work based on
    this file might be covered by the GNU General Public License.

    Alternative licenses for UiMagician may be arranged by contacting :--
    Tool Author : Dinesh Guleria
    din.gulu.er@gmail.com  https://sites.google.com/site/uimagician/
    Group : https://groups.google.com/forum/#!forum/uimagician
    Mailinglist : uimagician@googlegroups.com
*/


/*---------------------------------------------------------------------------
** Includes
*/
#include <QtGui>
#include "../mainwindow.h"
#include "ui_mainwindow.h"


// copy data from the test case buffer list to the textedit
// pass refrence to the list when calling this function
void MainWindow::copyBufferRoomDevicesToTheTextEdit(QList<T_testStepDetails> &testCaseStepslist )
{
    T_testStepDetails testStepMessageBuffer;
    QStandardItem *item;
    // create new test step itterator
    QListIterator<T_testStepDetails> testCaseStepslistIterator(testCaseStepslist);
    QString testStepPacket;

    //Iterrate through the test steps
    for(int row =0; testCaseStepslistIterator.hasNext() ; row++)
    {
        //Get the next node
        testStepMessageBuffer = testCaseStepslistIterator.next();

        // add row to the tree view
        if(row >= MODEL_INITIAL_ROWS)
        {
            //This add row at the end
            model->insertRow(model->rowCount());
        }

        for(int column =0; column < MODEL_INITIAL_COLUMNS; column++ )
        {
            //Copy from textview cell to the buffer
            switch (column)
            {
            case DEVICE_DESCRIPTION_DEVICE_NAME:
                // copy value to the QStandardItem
                item = new QStandardItem(QString(testStepMessageBuffer.u8_deviceName ));
                break;

            case DEVICE_DESCRIPTION_DEVICE_TYPE:
                // copy value to the QStandardItem
                item = new QStandardItem(QString(testStepMessageBuffer.u8_deviceType ));
                break;

            case DEVICE_DESCRIPTION_DEVICE_SUB_TYPE:
                // copy value to the QStandardItem
                item = new QStandardItem(QString(testStepMessageBuffer.u8_deviceSubType ));
                break;

            case DEVICE_DESCRIPTION_DEVICE_PACKET:
                //Create string of packet
                CreateStringForTestStepPacket(testCaseStepCanPacket_rx, row, testStepPacket);
                // copy value to the QStandardItem
                //item = new QStandardItem(QString(testStepMessageBuffer.u8_expectedResponse ));
                item = new QStandardItem(QString(testStepPacket));
                break;

            case DEVICE_DESCRIPTION_DEVICE_IMAGE:
                //Create string of packet
                //CreateStringForTestStepPacket(testCaseStepCanPacket_tx, row, testStepPacket);
                // copy value to the QStandardItem
                item = new QStandardItem(QString(testStepMessageBuffer.u8_deviceImage ));
                            //item = new QStandardItem(QString("default"));
                break;

            case DEVICE_DESCRIPTION_DEVICE_INFO:
                // copy value to the QStandardItem
                item = new QStandardItem(QString(testStepMessageBuffer.u8_deviceInfo ));
                break;

            /*case TEST_CASE_PASS_FAIL:
                // copy value to the QStandardItem
                item = new QStandardItem(QString(testStepMessageBuffer.u8_passFail ));
                break;

            case TEST_CASE_COMMENT:
                // copy value to the QStandardItem
                item = new QStandardItem(QString(testStepMessageBuffer.u8_comment ));
                break;*/

            default:         // Do nothing
                break;
            }

            // Append to the model - new test case
            model->setItem(row, column, item);
            if(testStepPacket == UNDEFINED_PACKET_STRING)
            {
                model->setData( model->index(row,column),Qt::red,Qt::ForegroundRole);
                //QMessageBox::information(this, "undoRoom", testStepPacket);
            }
            else
            {
                model->setData( model->index(row,column),Qt::black,Qt::ForegroundRole);
                //QMessageBox::information(this, "else", testStepPacket);
            }
        }
    }

    //Select the first row
    ui->testCaseTableView->selectRow(0);

    //Set the current row
    currentDeviceRow = 0;
}

// copy data from the textedit to the test case buffer list
// pass refrence to the list when calling this function
void MainWindow::copyTextEditToTheTestCasesBuffer(QList<T_testStepDetails> &testCaseStepslist)
{
    QVariant listData;
    QString strTemp;
    T_testStepDetails testStepMessageBuffer;

    // Read current testcase from - treeview
    for(int row =0; row < model->rowCount() ; row++)
    {
       for(int column =0; column < MODEL_INITIAL_COLUMNS; column++ )
       {
           //read string from model cell
           listData = model->data( model->index(row,column) );
           strTemp = listData.toString();

           //Copy from textview cell to the buffer
           switch (column)
           {
           case DEVICE_DESCRIPTION_DEVICE_NAME:
               // copy value to the pointer
               testStepMessageBuffer.u8_deviceName = strTemp;
               break;

           case DEVICE_DESCRIPTION_DEVICE_TYPE:
               // copy value to the pointer
               testStepMessageBuffer.u8_deviceType = strTemp;
             break;

           case DEVICE_DESCRIPTION_DEVICE_SUB_TYPE:
               // copy value to the pointer
               testStepMessageBuffer.u8_deviceSubType = strTemp;
             break;

           case DEVICE_DESCRIPTION_DEVICE_PACKET:
               strTemp = QLatin1String("");
               // copy value to the pointer
               testStepMessageBuffer.u8_devicePacket = strTemp;
             break;

           case DEVICE_DESCRIPTION_DEVICE_IMAGE:
               //strTemp = QLatin1String("");
               // copy value to the pointer
               testStepMessageBuffer.u8_deviceImage = strTemp;
             break;

           case DEVICE_DESCRIPTION_DEVICE_INFO:
               //strTemp = QLatin1String("");
               // copy value to the pointer
               testStepMessageBuffer.u8_deviceInfo = strTemp;
             break;

           /*case TEST_CASE_PASS_FAIL:
               strTemp = QLatin1String("");
               // copy value to the pointer
               testStepMessageBuffer.u8_passFail = strTemp;
             break;

           case TEST_CASE_COMMENT:
               // copy value to the pointer
               testStepMessageBuffer.u8_comment = strTemp;
             break;*/

           default:         // Do nothing
               break;
           }
       }
       // Append to the list
       testCaseStepslist.append(testStepMessageBuffer);
    }
}


//Create default view of the table
void MainWindow::createDefaultTableView()
{
    QVariant variant(PACKET_INITIAL_STRING);
    int row;

    /*int row = 0;
    int totalRows;
    int totalRowsToDelete;

    //Take total row count of the model
    totalRows = model->rowCount();

    //Delete some extra rows if it is there
    if (totalRows >= MODEL_INITIAL_ROWS)
    {
        totalRowsToDelete =  totalRows - MODEL_INITIAL_ROWS;
        //totalRowsToDelete++;

        for (row = 0; row <= totalRowsToDelete; row++) {
            model->removeRow(row);
        }
    }*/

    //Clear table view
    clearDefaultTableView();

    //Clear the other field of the form
    //ui->testCaseLineEdit->setText("");
    //ui->testCaseDescriptionLineEdit->setText("");
    //ui->selectedCellLineEdit->setText("");
    ui->roomLineEdit->setText("");
    ui->floorLineEdit->setText("");
    //ui->houseLineEdit->setText("");
    //ui->houseLineEdit->setText(DEFAULT_HOUSE_NAME);  // -- todo single floor house
    ui->houseLineEdit->setText("");

    // Increase height of the first row
    row = 0;
    model->setData(model->index(row,DEVICE_DESCRIPTION_DEVICE_PACKET_COLUMN),variant);

}


//Copy xml node value to room name &  description
void MainWindow::copyXmlNodeToRoomNameAndDescription()
{
    //ui->testCaseLineEdit->setText(testCaseNameText);
    //ui->testCaseDescriptionLineEdit->setText(testCaseDescriptionText);
    ui->roomLineEdit->setText(roomNameText);
    ui->floorLineEdit->setText(floorNameText);
    ui->houseLineEdit->setText(houseNameText);
}


//Clear default view of the table
void MainWindow::clearDefaultTableView()
{
    QVariant variant;
    variant.toString() = "";

    while(model->rowCount() > 1)
        model->removeRow(0);


    //Clear content of the model
    for (int row = 0; row < MODEL_INITIAL_ROWS; ++row) {
        for (int column = 0; column < MODEL_INITIAL_COLUMNS; ++column) {
            model->setData(model->index(row,column),variant);
        }
    }
}
