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


#ifndef XMLVERIFYWIDGET_H
#define XMLVERIFYWIDGET_H

#include <QtGui>
#include <QDialog>
#include <QStandardItemModel>
#include <QtXml>
#include "xmlverifymmodel.h"
#include "../uiMagicianConfiguration.h"

#define TEST_CASE_RESULT_COLUMN 0
#define TEST_CASE_NAME_COLUMN   1
#define TEST_CASE_FAIL          "Fail"
#define TEST_CASE_PASS          "Pass"
#define XML_REVIEW_COLUMN_ZERO  "Result"
#define XML_REVIEW_COLUMN_ONE   "Room Name"
#define XML_REVIEW_COLUMN_TWO   "Floor Name"
#define XML_REVIEW_COLUMN_THREE "House Name"


namespace Ui {
class xmlVerifyWidget;
}

class xmlVerifyWidget : public QDialog
{
    Q_OBJECT
    
public:
    explicit xmlVerifyWidget(QDomElement &xmlRootVerify, QWidget *parent = 0);
    ~xmlVerifyWidget();
    
    //Create model for the xml
    void createModelForTheXml(int rows);

    //update model with test case name & result
    void updateDialogResults();

    //Pointer to QStandardItemModel to be used inside - Test Case Tableview
    xmlverifymmodel *VerifyModel;

    //Node list
    QDomNodeList list;

private:
    Ui::xmlVerifyWidget *ui;
};

#endif // XMLVERIFYWIDGET_H
