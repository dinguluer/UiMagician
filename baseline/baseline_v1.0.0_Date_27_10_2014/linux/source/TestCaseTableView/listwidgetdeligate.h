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

#ifndef LISTWIDGETDELIGATE_H
#define LISTWIDGETDELIGATE_H


/*---------------------------------------------------------------------------
** Includes
*/
#include <QtGui>
#include <QItemDelegate>
#include <QListWidgetItem>

/*---------------------------------------------------------------------------
** This is the list widget delegate class. It is used as an delegate
** inside model cell.
*/
class listWidgetDeligate : public QItemDelegate
{

    QList<QString> &listWidgetList;
    Q_OBJECT
public:
    explicit listWidgetDeligate(QList<QString> &listWidgetListtemp ,QObject *parent = 0);

    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void	setEditorData ( QWidget * editor, const QModelIndex & index ) const;
    void	setModelData ( QWidget * editor, QAbstractItemModel * model, const QModelIndex & index ) const;
    void	updateEditorGeometry ( QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex & index ) const;

signals:
    
public slots:
    void onListWidgetItemDoubleClicked(QListWidgetItem * item);
};

#endif // LISTWIDGETDELIGATE_H
