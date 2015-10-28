

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


#include <QtGui>
#include "textviewdeligate.h"

textViewDeligate::textViewDeligate(QObject *parent) :
    QItemDelegate(parent)
{
}


QWidget* textViewDeligate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    QTextEdit *tableEdit = new QTextEdit(parent);
    return tableEdit;
}

void textViewDeligate::setEditorData ( QWidget * editor, const QModelIndex & index ) const
{

    QString value = index.model()->data(index,Qt::EditRole).toString();

    QTextEdit *tableEditCopy = static_cast<QTextEdit*>(editor);
    tableEditCopy->setPlainText(value);
}

void	textViewDeligate::setModelData ( QWidget * editor, QAbstractItemModel * model, const QModelIndex & index ) const
{
    QTextEdit *tableEditCopy = static_cast<QTextEdit*>(editor);
    QString str = tableEditCopy->toPlainText();

    model->setData(index, str, Qt::EditRole);

}

void	textViewDeligate::updateEditorGeometry ( QWidget *editor, const QStyleOptionViewItem & option, const QModelIndex & index ) const
{

}
