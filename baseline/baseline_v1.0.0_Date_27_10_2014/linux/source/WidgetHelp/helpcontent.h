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


#ifndef HELPCONTENT_H
#define HELPCONTENT_H

//#include <QDialog>
#include <QtGui>
#include <QtXml>
#include <QTreeWidgetItem>

namespace Ui {
class helpContent;
}

class helpContent : public QDialog
{
    Q_OBJECT
    
public:
    explicit helpContent(QWidget *parent = 0);
    ~helpContent();

    //Xml file name
    QFile   xmlFile;

    // Signal that tree is loaded -- onchange event handler do not perform
    // on first selection change in constructor
    bool b_flagTreeLoaded;
    // List of all Nodes from Help XML
    QDomNodeList list;

    // Add top node to
    QTreeWidgetItem* AddRoot(QString itemText);
    
private slots:
    void on_helpTreeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

private:
    Ui::helpContent *ui;
};

#endif // HELPCONTENT_H
