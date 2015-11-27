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





/*

Get a QListWidgetItem's row :--
http://www.qtforum.org/article/36857/get-a-qlistwidgetitem-s-row.html
http://stackoverflow.com/questions/18596260/c-qlistwidget-select-first-item

listWidget->currentRow();


qlistwidget select row programatically :---
http://stackoverflow.com/questions/18596260/c-qlistwidget-select-first-item

qlistwidget  item value :--
http://stackoverflow.com/questions/15311241/qlistwidget-event-on-item-click

Double click item signal :--
itemDoubleClicked ( QListWidgetItem * item )

*/


/*---------------------------------------------------------------------------
** Includes
*/

#include <QtGui>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "listWidgetDeligate.h"
#include "listWidgetDerived.h"
#include "../uiMagicianConfiguration.h"

/*----------------------------------------------------------------------------
** Function    : listWidgetDeligate
** Description : Constructor for listWidgetDeligate
** Precondition:  None
** Postcondition: None
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
listWidgetDeligate::listWidgetDeligate(QList<QString> &listWidgetListtemp, QObject *parent) :
    QItemDelegate(parent), listWidgetList(listWidgetListtemp)
{

}

/*----------------------------------------------------------------------------
** Function    : createEditor
** Description : This function will create editor to be used inside a cell
** Precondition:  None
** Postcondition: Test Case Tree is created
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
QWidget* listWidgetDeligate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // listwidget pointer
    QListWidgetDerived *listWidget = new QListWidgetDerived(parent);

    //Connect double click signal to slot
    connect(listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
                this, SLOT(onListWidgetItemDoubleClicked(QListWidgetItem*)));


    // Add list item here
    for(int i=0; i< listWidgetList.size() ; i++)
    {
        //listWidget->addItem(QString::number(i) + " : Item" + listWidgetList);
        listWidget->addItem(listWidgetList.at(i));
    }

    return listWidget;


    /*if ((index.column() != TX_PACKET_COLUMN_DELIGATE)||(index.column() != RX_PACKET_COLUMN_DELIGATE)) {
        // change property to non editable
        //index.( index.flags() & ~Qt::ItemIsEditable);
        index.flags() = index.flags() & ~Qt::ItemIsEditable;

    } else {
        // Do nothing
    }*/

}

/*----------------------------------------------------------------------------
** Function    : setEditorData
** Description : This function will read data from model cell to editor
** Precondition:  None
** Postcondition: Test Case Tree is created
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
void listWidgetDeligate::setEditorData ( QWidget * editor, const QModelIndex & index ) const
{

    QString value = index.model()->data(index,Qt::EditRole).toString();

    //--- QTextEdit *tableEditCopy = static_cast<QTextEdit*>(editor);
    //--- tableEditCopy->setPlainText(value);
}

/*----------------------------------------------------------------------------
** Function    : setModelData
** Description : This function will copy data from editor to the cell of model
** Precondition:  None
** Postcondition: Test Case Tree is created
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
void listWidgetDeligate::setModelData ( QWidget * editor, QAbstractItemModel * model, const QModelIndex & index ) const
{
    QListWidgetDerived *listWidgetCopy = static_cast<QListWidgetDerived*>(editor);
    //--- QString str = tableEditCopy->toPlainText();

    QString str = listWidgetCopy->currentItem()->text();
    int i = listWidgetCopy->currentRow();
    //model->setData(index, str, Qt::EditRole);
    model->setData(index, listWidgetList.at(i), Qt::EditRole);

    //--- model->setData(index, str, Qt::EditRole);

}

/*----------------------------------------------------------------------------
** Function    : updateEditorGeometry
** Description : This function will set the geometry of the editor.
** Precondition:  None
** Postcondition: Test Case Tree is created
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
void listWidgetDeligate::updateEditorGeometry ( QWidget *editor, const QStyleOptionViewItem & option, const QModelIndex & index ) const
{
    // fit inside editor cell
    // editor->setGeometry(option.rect);

    //editor->setGeometry(option.rect.x(),option.rect.y(),editor->sizeHint().width(),100);


    editor->setGeometry(option.rect.x(),option.rect.y(),editor->sizeHint().width(),editor->sizeHint().height());
}

/*----------------------------------------------------------------------------
** Function    : onListWidgetItemDoubleClicked
** Description : This slot is called on the double click list item signal.
** Precondition:  None
** Postcondition: Test Case Tree is created
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
void listWidgetDeligate::onListWidgetItemDoubleClicked(QListWidgetItem * item)
{
    /*QMessageBox *msgBox 	= new QMessageBox();
    msgBox->setText(MESSAGE_SAVE_PRESSESD);
    msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
    msgBox->show();*/

    item->listWidget()->close();
    //emit closeEditor();
}
