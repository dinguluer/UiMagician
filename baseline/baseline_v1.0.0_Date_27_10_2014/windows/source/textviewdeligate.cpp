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
