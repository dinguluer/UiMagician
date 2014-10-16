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
