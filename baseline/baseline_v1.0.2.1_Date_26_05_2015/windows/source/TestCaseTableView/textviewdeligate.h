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

#ifndef TEXTVIEWDELIGATE_H
#define TEXTVIEWDELIGATE_H


/*---------------------------------------------------------------------------
** Includes
*/
#include <QItemDelegate>


/*---------------------------------------------------------------------------
** This is the text view delegate class. It is used as an delegate
** inside model cell.
*/
class textViewDeligate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit textViewDeligate(QObject *parent = 0);

    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void	setEditorData ( QWidget * editor, const QModelIndex & index ) const;
    void	setModelData ( QWidget * editor, QAbstractItemModel * model, const QModelIndex & index ) const;
    void	updateEditorGeometry ( QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex & index ) const;

signals:
    
public slots:
    
};

#endif // TEXTVIEWDELIGATE_H
