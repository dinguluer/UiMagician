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

#ifndef MYEXCEL_H
#define MYEXCEL_H

//Includes
#include <QtGui>
#include <QAxObject>
#include <QTableView>
#include <QStringList>

//Defines
#define H_LEFT_ALLIGN   0
#define H_CENTER_ALLIGN 1
#define H_RIGHT_ALLIGN  2
#define V_TOP_ALLIGN    0
#define V_CENTER_ALLIGN 1
#define V_BOTTOM_ALLIGN 2
#define SHEET_DEFAUT_SIZE_CAN        "A1:Z750"
#define DEFAULT_FONT_NAME            "Arial"
#define DEFAULT_FONT_SIZE            10
#define TEST_SCRIPT_PROCEDURE_SIZE   9
#define TEST_SCRIPT_TC_DESCRIPTION_SIZE   8
#define TEST_SCRIPT_TC_TS_DESCRIPTION_SIZE   10

//http://msdn.microsoft.com/en-us/library/office/cc296089(v=office.12).aspx
#define GREY_COLOUR   15
#define GREEEN_COLOUR 4



// Border format -
//http://www.scribd.com/doc/60250872/Border-Constants
//Line style
#define XLCONTINOUS 1
#define XLDASH      -4115
#define XLDASHDOT   4
#define XLDASHDOTDOT   5
#define XLDOT    -4118
#define XLDOUBLE -4119
#define XLLINESTYLENONE -4142
#define XLSLANTDASHDOT 13
//weight
#define XLHAIRLINE 1
#define XLTHIN     2
#define XLMEDIUM   -4138
#define XLTHICK 4
//Border
#define XLDIAGONALDOWN 5
#define XLDIAGONALUP   6
#define XLEDGEBOTTOM   9
#define XLEDGELEFT     7
#define XLEDGERIGHT    10
#define XLEDGETOP      8
#define XLINSIDEHORIZONTAL 12
#define XLINSIDEVERTICAL   11

//class definition
class MyExcel : public QObject
{

public:
    MyExcel(QString strXlsFile = QString(), QObject *parent = 0);
    //MyExcel();
    ~MyExcel();
    QAxObject *getWorkBooks();
    QAxObject *getWorkBook();
    QAxObject *getWorkSheets();
    QAxObject *getWorkSheet();
    QAxObject *selectSheet(const QString& strSheetName);
    QAxObject *selectSheet(int nSheetIndex);
    QAxObject *setFileName(const QString& strFilename);
    bool deletesheet(const QString& strSheetName);
    bool deleteSheetExclude(const QString& strSheetName);
    bool lockUpdate();
    bool unlockUpdate();
    bool setHeader(QStringList headerList);
    bool insertRow(const QString& cell);
    bool deleteRow(const QString& cell);
    bool setValue(const QString& cell, const QString& strValue, int nType);
    bool setValue(int row, int col, const QString& strValue);
    bool setValue(int row, int col, const QString& strValue, int nType);
    bool setCalce(const QString& cell, const QString& szCal);
    bool setFormula(const QString& cell, const QString& szCal);
    bool setFontBold(const QString& cell, bool blBold);
    bool setFontBold(int row, int col,  bool blBold);
    bool setFontSize(int row, int col,  int size);
    bool setFontBorder(int row, int col,  int type);
    bool setFontBorder(const QString& cell, int type);
    bool setFontType(int row, int col,  QString type);
    bool setSheetDefault();
    bool setMergeCells(const QString& cell);
    bool setMergeCells(QString startColumn, QString endColumn, int row, int horizontalAllign=H_LEFT_ALLIGN, int verticalAllign=V_TOP_ALLIGN);
    bool wrapText(int row, int col, bool value);
    bool setColour(int row, int col, int value);
    bool VerticalAlignmentTop(int row, int col);
    bool VerticalAlignmentCenter(int row, int col);
    bool VerticalAlignmentBottom(int row, int col);
    bool HorizontalAlignmentLeft(int row, int col);
    bool HorizontalAlignmentCenter(int row, int col);
    bool HorizontalAlignmentRight(int row, int col);
    QVariant value(int row, int col);
    QVariantList getAll(int *rows, int *cols);
    QVariantList selectAll();
    bool clearAllContents();
    bool writeRow(int row,  QVariantList &list);
    void setStringColumn(int col, int rows);
    bool save();
    bool save(const QString& szFileName);
    bool saveExcelformatxls();
    bool showExcel(bool bShow);
    void closeAll();
    void autoColumnWidth(const QString& strColumns);
    void setAutoFitRow(int row);
    void setRowHeight(int row, int height);
    int sheetCount();
    QString sheetName(int index);
    void getRowsCols(int *rows, int *cols);
    QString maxColumn();

    void tableViewToExcel (QTableView* table, QString excelFileName);

//protected:
    QAxObject	*excelApplication;
    QAxObject	*excelWorkBooks;
    QAxObject	*excelWorkBook;
    QAxObject	*excelSheets;
    QAxObject	*excelSheet;
    QString		fileName;
    QString		columnName;


private:

};
//#if defined(Q_OS_WIN32)
//#endif

#endif
