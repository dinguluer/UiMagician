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
#include "textviewdeligate.h"
#include "../uiMagicianConfiguration.h"

/*----------------------------------------------------------------------------
** Function    : textViewDeligate
** Description : Constructor for textViewDeligate
** Precondition:  None
** Postcondition: None
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
textViewDeligate::textViewDeligate(QObject *parent) :
    QItemDelegate(parent)
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
QWidget* textViewDeligate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    QTextEdit *tableEdit = new QTextEdit(parent);
    return tableEdit;


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
void textViewDeligate::setEditorData ( QWidget * editor, const QModelIndex & index ) const
{

    QString value = index.model()->data(index,Qt::EditRole).toString();

    QTextEdit *tableEditCopy = static_cast<QTextEdit*>(editor);
    tableEditCopy->setPlainText(value);
}

/*----------------------------------------------------------------------------
** Function    : setModelData
** Description : This function will copy data from editor to the cell of model
** Precondition:  None
** Postcondition: Test Case Tree is created
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
void textViewDeligate::setModelData ( QWidget * editor, QAbstractItemModel * model, const QModelIndex & index ) const
{
    QTextEdit *tableEditCopy = static_cast<QTextEdit*>(editor);
    QString str = tableEditCopy->toPlainText();

    model->setData(index, str, Qt::EditRole);

}

/*----------------------------------------------------------------------------
** Function    : updateEditorGeometry
** Description : This function will set the geometry of the editor.
** Precondition:  None
** Postcondition: Test Case Tree is created
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
void textViewDeligate::updateEditorGeometry ( QWidget *editor, const QStyleOptionViewItem & option, const QModelIndex & index ) const
{
    // fit inside editor cell
    // editor->setGeometry(option.rect);

    //editor->setGeometry(option.rect.x(),option.rect.y(),editor->sizeHint().width(),100);
    editor->setGeometry(option.rect.x(),option.rect.y(),editor->sizeHint().width(),editor->sizeHint().height());
}
