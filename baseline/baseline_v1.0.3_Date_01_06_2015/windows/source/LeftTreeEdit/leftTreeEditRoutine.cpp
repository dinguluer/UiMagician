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
#include "../mainwindow.h"
//#include "../../uiMagician-build-desktop-Qt_4_8_1_for_Desktop_-_MinGW__Qt_SDK__Release/ui_mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>


/*----------------------------------------------------------------------------
** Function    : createTreeWidgetView
** Description : This function will create layout for the left tree widget
** Precondition:  None
** Postcondition: Test Case Tree is created
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
void MainWindow::createTreeWidgetView()
{
    QTreeWidgetItem* headerItem = new QTreeWidgetItem();
    headerItem->setText(0,QString("Room         "));
    headerItem->setText(1,QString("Description    "));
    headerItem->setText(2,QString("Floor    "));  //--------------------------
    headerItem->setText(3,QString("House   "));  //--------------------------

    ui->treeWidgetLeft->setHeaderItem(headerItem);
    ui->treeWidgetLeft->setVisible(true);

    ui->treeWidgetLeft->header()->resizeSections(QHeaderView::ResizeToContents);
    ui->treeWidgetLeft->header()->resizeMode(QHeaderView::ResizeToContents);
    ui->treeWidgetLeft->header()->setStretchLastSection(true);
    //ui->testCaseTableView->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    //ui->testCaseTableView->horizontalHeader()->setStretchLastSection(true);

    /*for(int i = 0; i <= 3; i++)
    {
        ui->treeWidgetLeft->resizeColumnToContents(i);
    }*/
}

/*----------------------------------------------------------------------------
** Function    : AddRoot
** Description : Add root item to tree
** Precondition:  None
** Postcondition: Item is added to the tree
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
void MainWindow::AddRoot(QString name , QString description)
{
    QTreeWidgetItem *itemNode;

    itemNode = new QTreeWidgetItem(ui->treeWidgetLeft);
    itemNode->setText(0,name);
    itemNode->setText(1,description);
    itemNode->setIcon(0,*(new QIcon(":/Images/Images/room/room_selected.jpg")));
    //itemNode->setIcon(0,*(new QIcon(":/Images/Images/Folder-Add.ico")));
    ui->treeWidgetLeft->addTopLevelItem(itemNode);

    //change the selection
    ui->treeWidgetLeft->setCurrentItem(itemNode);

}

/*----------------------------------------------------------------------------
** Function    : AddRootNoSelectionChange
** Description : Add root item to tree
** Precondition:  None
** Postcondition: Item is added to the tree
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
void MainWindow::AddRootNoSelectionChange(QString name , QString roomName, QString floorname, QString houseName)
{
    QTreeWidgetItem *itemNode;

    itemNode = new QTreeWidgetItem(ui->treeWidgetLeft);
    itemNode->setText(0,name);
    itemNode->setText(1,roomName);
    itemNode->setText(2,floorname);
    itemNode->setText(3,houseName);
    //itemNode->setIcon(0,*(new QIcon(":/Images/Images/Folder-Add.ico")));
    itemNode->setIcon(0,*(new QIcon(":/Images/Images/room/room_selected.jpg")));
    ui->treeWidgetLeft->addTopLevelItem(itemNode);

}

/*----------------------------------------------------------------------------
** Function    : AddChild
** Description : Add child to the parent
** Precondition:  None
** Postcondition: Child is added to the tree QTreeWidgetItem
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
void MainWindow::AddChild(QTreeWidgetItem *parent , QString name , QString description)
{
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0,name);
    item->setText(1,description);
    item->setIcon(0,*(new QIcon(":/Images/Images/Gears.ico")));
    parent->addChild(item);

}


/*----------------------------------------------------------------------------
** Function    : RemoveTopLevelItem
** Description : Remove child to the main tree
** Precondition:  None
** Postcondition: None
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
void MainWindow::RemoveTopLevelItem()
{
    int rowNumber;

    rowNumber = ui->treeWidgetLeft->currentIndex().row();
    if(rowNumber != NO_TREE_TOP_ITEM_TO_DELETE)
    {
        ui->treeWidgetLeft->takeTopLevelItem(rowNumber);
        //After deleting -- current index will become -- same value
        // if it was 6 case --> then 7 will move to sixth position
        // when treee is empty --> ui->treeWidgetLeft->currentIndex().row() --> returns --> -1
        // for first node in tree --> ui->treeWidgetLeft->currentIndex().row() --> returns --> 0
    }
    else
    {
        QMessageBox* msgBox 	= new QMessageBox();
        msgBox->setText(NO_TEST_CASE_EXIST);
        msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
        msgBox->show();
    }

}

// clear the tree view -- remove toplevel items
void MainWindow::clearAllTopLevelItems()
{
    // Set the signal
    b_clearTreeViewSignal = TRUE;
    //disconnect(ui->testCaseTableView, SIGNAL(currentItemChanged() ), 0, 0);
    // clear the tree view -- remove all toplevel items
    ui->treeWidgetLeft->clear();

    //Reset the signal
    b_clearTreeViewSignal = FALSE;

}

//change the name of the current node in the tree
void MainWindow::ChangeNameOfcurrentNodeOfTree()
{
    QTreeWidgetItem *current;
    QString itemRoomName;
    QString itemFloorName;
    QString itemHouseName;
    bool flag = 0;
    //Change name of the node in tree -- once saved

    //get the current item
    if(b_nodeIsChanging)
    {
        if(currentXmlRootNodeNumber > NO_NODE_TO_DISPLAY)
        {
            //take item from location currentXmlRootNodeNumber
            current = ui->treeWidgetLeft->topLevelItem(currentXmlRootNodeNumber);

            flag = 1;
        }
    }else{
        //Take current item
        current = ui->treeWidgetLeft->currentItem();
        flag = 1;

    }

    if(flag == 1)
    {
        //get the text from the room name field
        itemRoomName = ui->roomLineEdit->text();
        // Some item is there in the test case field
        if(!itemRoomName.isEmpty()){
            current->setText(1, itemRoomName);  //(column_Number, text)
        }
        else{
            current->setText(1,"");  //(column_Number, text)
        }

        //get the text from the floor name field
        itemFloorName = ui->floorLineEdit->text();
        // Some item is there in the test case field
        if(!itemFloorName.isEmpty()){
            current->setText(2, itemFloorName);  //(column_Number, text)
        }
        else{
            current->setText(2,"");  //(column_Number, text)
        }

        //get the text from the house name field
        itemHouseName = ui->houseLineEdit->text();
        // Some item is there in the test case field
        if(!itemHouseName.isEmpty()){
            current->setText(3, itemHouseName);  //(column_Number, text)
        }
        else{
            current->setText(3,"");  //(column_Number, text)
        }
    }

}
