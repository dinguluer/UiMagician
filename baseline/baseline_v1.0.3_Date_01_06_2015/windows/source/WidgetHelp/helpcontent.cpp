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



#include <QtGui>
#include "helpcontent.h"
#include "ui_helpcontent.h"

#define FILE_NAME              "HelpContent.xml"
#define INDEX_NAME             "IndexName"

#define TEXT_MACRO         "hello \n\n hw r u "

#define TEXT_MACRO_BOLD         "hello \n\n hw r u \n\n <b>  i am fine </b>  "


// Link
// http://stackoverflow.com/questions/24883992/string-with-newline-character-copy-to-qtextview
// https://svn.katastrophos.net/quasar/branches/view_restructuring/ui/aboutdialog.cpp
// http://bax.comlab.uni-rostock.de/~bj/software/yasa/developer/doc/html/output_8h-source.html
// bullet -- > http://www.echoecho.com/htmllists01.htm
// http://www.ascii.cl/htmlcodes.htm
// http://stackoverflow.com/questions/2641131/is-there-a-character-that-is-the-same-size-as-a-bullet-but-open
helpContent::helpContent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpContent)
{
    ui->setupUi(this);


    QString xmlFileName(FILE_NAME);
//    QFile   xmlFile;
    // xml dom document object
    QDomDocument xmlDomDocument;
    QDomNode nn;
    uint8_t temp=0;
    bool ret;

    QTreeWidgetItem *firstItem = NULL;
    QString rootDescription;
    QString rootElementText;
    QString exePath = QCoreApplication::applicationDirPath();
    QString helpFileCompletePath = exePath + QDir::separator() + FILE_NAME;
    //QSize treeWidgetSize(234,478);
    QTreeWidgetItem* headerItem = new QTreeWidgetItem();
    headerItem->setText(0,QString("Help Content"));

    //set the flag to
    b_flagTreeLoaded = FALSE;

    ui->helpTreeWidget->setMaximumWidth(300);
    //ui->helpTreeWidget->header()->resizeSection(0 /*column index*/, 234 /*width*/);


    ui->helpTreeWidget->setHeaderItem(headerItem);
    ui->helpTreeWidget->setVisible(true);

    ui->helpTreeWidget->header()->resizeSections(QHeaderView::ResizeToContents);
    ui->helpTreeWidget->header()->resizeMode(QHeaderView::ResizeToContents);
    ui->helpTreeWidget->header()->setStretchLastSection(true);

    //set the name of the XML Help file
    xmlFile.setFileName(helpFileCompletePath);
    ret = xmlFile.open(QIODevice::ReadOnly|QIODevice::Text);
    if(ret == false)
    {
        QMessageBox *msgBox 	= new QMessageBox();
        msgBox->setText("File Not Found !!");
        msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
        msgBox->exec();

        // terminate the constructor
        return;
    }
    else
    {
        /*QMessageBox *msgBox 	= new QMessageBox();
        msgBox->setText("File is Found !!");
        msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
        msgBox->exec();
        */
    }

    xmlDomDocument.clear();
    xmlDomDocument.setContent(&xmlFile);
    nn = xmlDomDocument.firstChild();
    list = nn.childNodes();

    /*QMessageBox *msgBox 	= new QMessageBox();

    msgBox->setText(nn.toElement().tagName());
    msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
    msgBox->exec();

    msgBox->setText(QString::number(list.count()));
    msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
    msgBox->exec();*/

    for(int i =0; i< list.count(); i++)
    {
        QDomNode e = list.at(i);

        // Add root item
        //rootDescription = e.toElement().attribute(INDEX_NAME).toStdString().c_str();
        rootDescription = e.toElement().attribute(INDEX_NAME);
        if(temp == 0 )
        {
            firstItem = AddRoot(rootDescription);
            rootElementText = e.toElement().text();
                 //rootElementText =  QString(" <ul><li> <u>hello \n\n hw r u </u> </li><ul>");
            //rootElementText = e.toElement().text().replace("\\n","\n");  ---------> working
            ui->helpTextEdit->clear();
            ui->helpTextEdit->setText(rootElementText);
            temp++;
        }
        else
        {
            AddRoot(rootDescription);
        }

    }

    //Set to read only
    ui->helpTextEdit->setReadOnly(true);

    //change the selection
    ui->helpTreeWidget->setCurrentItem(firstItem);

    //headerView()->resizeSection(0 /*column index*/, 234 /*width*/);
}

/*----------------------------------------------------------------------------
** Function    : AddRoot
** Description : Add root item to tree
** Precondition:  None
** Postcondition: Item is added to the tree
** Parameters  : None
** Return value: None
**--------------------------------------------------------------------------*/
QTreeWidgetItem* helpContent::AddRoot(QString itemText)
{
    QTreeWidgetItem *itemNode;

    itemNode = new QTreeWidgetItem(ui->helpTreeWidget);
    itemNode->setText(0,itemText);
    itemNode->setIcon(0,*(new QIcon(":/Images/Images/index_arrow_1.gif")));
    ui->helpTreeWidget->addTopLevelItem(itemNode);


    return itemNode;
}

helpContent::~helpContent()
{

    //close the
    xmlFile.close();
    delete ui;
}

void helpContent::on_helpTreeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    QString rootElementText;
    QDomNode e ;
    uint16_t i;

    if(b_flagTreeLoaded == TRUE)
    {
        //QMessageBox::information(this, "uiMagician", QString::number(ui->helpTreeWidget->currentIndex().row()));
        i = ui->helpTreeWidget->currentIndex().row();
        e = list.at(i);
        rootElementText = e.toElement().text();
        ui->helpTextEdit->clear();
        ui->helpTextEdit->setText(rootElementText);
    }
    else
    {
        b_flagTreeLoaded = TRUE;
    }
}
