
/*
http://tortoiseforlabms.googlecode.com/svn-history/r4/trunk/Labms_v1/Labms_v1/
http://tortoiseforlabms.googlecode.com/svn-history/r4/trunk/Labms_v1/Labms_v1/excel.cpp
http://tortoiseforlabms.googlecode.com/svn-history/r4/trunk/Labms_v1/Labms_v1/excel.h
http://www.cprogramdev.com/29318/
http://dataviewer.googlecode.com/svn/trunk/DataViewer/dvXlsWriter.cpp
https://github.com/kravitz/kfais/blob/master/sources/reports.cpp

Font size & format :---
http://www.progtown.com/topic796198-qt-on-with-by-operation-with-qaxobject.html

*/

#include "excel.h"
#include <QAbstractItemModel>

//#if defined(Q_OS_WIN32)
MyExcel::MyExcel(QString strXlsFile, QObject *parent)
{
    excelApplication = 0;
    excelWorkBooks = 0;
    excelWorkBook = 0;
    excelSheets = 0;
    excelSheet = 0;
    fileName = strXlsFile;
    columnName = " A";

    try {
        excelApplication = new QAxObject("Excel.Application", parent);
        if (excelApplication) {
            excelWorkBooks = excelApplication->querySubObject("Workbooks");
            if (excelWorkBooks) {
                QFile file(strXlsFile);

                if (file.exists()){
                    //no need to open existing file we will always - create new file
                    //file name will depend upon -- time of creation
                    //excelWorkBook = excelWorkBooks->querySubObject("Open(const QString&)", strXlsFile);
                }else{
                    //Create new excel file
                    //Add work book - to excel
                    excelWorkBooks->dynamicCall("Add");

                    //Extract workbook pointer
                    excelWorkBook = excelApplication->querySubObject("ActiveWorkBook");
                    if (excelWorkBook){
                        //Extract excel sheet
                        excelSheets = excelWorkBook->querySubObject("WorkSheets");
                    }
                    else{
                        QMessageBox::information(0, "", "QAxObject workbook fail!");
                    }
                }
            } else{
                QMessageBox::information(0, "", "Excel WorkBooks creation fails! ");
            }
        } else{
            QMessageBox::information(0, "", "Excel Application creation fails! ");
        }
    } catch (...) {}
}

/*Excel::Excel()
{

}*/

MyExcel::~MyExcel()
{
    closeAll();

}

QAxObject *MyExcel::setFileName(const QString& strXlsFile)
{
    fileName = strXlsFile;
    if (excelWorkBooks) {
        delete excelWorkBooks;
        excelWorkBooks = excelApplication->querySubObject("Workbooks");
    }

    if (excelWorkBooks) {
        QFile file(fileName);
        if (file.exists())
            excelWorkBook = excelWorkBooks->querySubObject("Open(const QString&)", fileName);
        else {
            excelWorkBook = excelWorkBooks->querySubObject("Add()");
        }

        if (excelWorkBook)
            excelSheets = excelWorkBook->querySubObject("Sheets");
        else
            QMessageBox::information(0, "", "QAxObject workbook fail!");
    }
    return excelWorkBook;
}

void MyExcel::closeAll()
{
    if (excelApplication) {
        try {
            excelApplication->dynamicCall(" Quit()");
            delete excelSheet;
            delete excelSheets;
            delete excelWorkBook;
            delete excelWorkBooks;
            delete excelApplication;
            excelApplication = 0;
            excelWorkBooks = 0;
            excelWorkBook = 0;
            excelSheets = 0;
            excelSheet = 0;
        } catch (...) {}
    }
}

QAxObject *MyExcel::getWorkBooks()
{
    return excelWorkBooks;
}

QAxObject *MyExcel::getWorkBook()
{
    return excelWorkBook;

}

QAxObject *MyExcel::getWorkSheets()
{
    return excelSheets;
}

QAxObject *MyExcel::getWorkSheet()
{
    return excelSheet;

}
bool MyExcel::lockUpdate()
{
    try {
        if (!excelApplication)
            return false;
        excelApplication->dynamicCall(" SetScreenUpdating(bool)", false);
    } catch (...) {}

    return true;
}

bool MyExcel::unlockUpdate()
{
    try {
        if (!excelApplication)
            return false;
        excelApplication->dynamicCall(" SetScreenUpdating(bool)", true);
    } catch (...) {}
    return true;
}

QAxObject *MyExcel::selectSheet(const QString& strSheetName)
{

    try {
        if (!excelSheets)
            return 0;
        excelSheet = excelSheets->querySubObject("Item(const QVariant&)", strSheetName);

        if (!excelSheet)
            return 0;
        return excelSheet;
    } catch (...) {
        return 0;
    }
}

bool MyExcel::deletesheet(const QString& strSheetName)
{
    try {
        if (!excelSheets)
            return false;
        excelSheet = excelSheets->querySubObject("Item(const QVariant&)", strSheetName);

        if (!excelSheet)
            return false;
        excelSheet->dynamicCall("delete");
        return true;
    } catch (...) {
        return 0;
    }
}

bool MyExcel::deleteSheetExclude(const QString& strSheetName)
{
    try {
        if (!excelSheets)
            return false;
        int nCount = excelSheets->property("Count").toInt();
        QStringList sltSheetName;
        for (int i = 1; i < nCount + 1 ; i++) {
            excelSheet = excelSheets->querySubObject("Item(int index)", i);
            if (!excelSheet) {
                continue;
            }
            sltSheetName << excelSheet->property("Name").toString();
        }

        for (int j = 0; j < sltSheetName.count(); j++) {
            if (sltSheetName[j] == strSheetName) {
                continue;
            }
            excelSheet = excelSheets->querySubObject("Item(const QVariant&)", sltSheetName[j]);
            if (!excelSheet) {
                continue;
            }
            excelSheet->dynamicCall("delete");
        }
        return true;
    } catch (...) {
        return 0;
    }
}

QAxObject *MyExcel::selectSheet(int nSheetIndex)
{

    try {
        if (!excelSheets)
            return 0;
        excelSheet = excelSheets->querySubObject("Item(int index)", nSheetIndex);

        if (!excelSheet)
            return 0;
        return excelSheet;
    } catch (...) {
        return 0;
    }
}

bool MyExcel::setHeader(QStringList headerList)
{
    try {
        int len = headerList.count();
        if (len == 0) {
            return false;
        }

        for (int i = 1; i <= len; i++) {
            setValue(1, i, headerList.at(i - 1));
        }

        return true;
    } catch (...) {
        return false;
    }
}

bool MyExcel::insertRow(const QString& cell)
{
    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Range(const QVariant&)", QVariant(cell));
        if (!range)
            return false;

        range = range->querySubObject("EntireRow");
        if (!range) {
            return false;
        }
        range->dynamicCall("Insert");
        return true;
    } catch (...) {
        return false;
    }
}

bool MyExcel::deleteRow(const QString& cell)
{
    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Range(const QVariant&)", QVariant(cell));
        if (!range)
            return false;

        range = range->querySubObject("EntireRow");
        if (!range) {
            return false;
        }
        range->dynamicCall("Delete");
        return true;
    } catch (...) {
        return false;
    }
}

bool MyExcel::setValue(const QString& cell, const QString& strValue, int nType)
{
    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Range(const QVariant&)", QVariant(cell));
        if (!range)
            return false;

        range->dynamicCall("SetValue(const QVariant&)", QVariant(strValue));   //
        return true;
    } catch (...) {
        return false;
    }
}

bool MyExcel::setValue(int row, int col, const QString& strValue)
{
    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Cells(int,int)", row, col);
        if (!range)
            return false;

        range->dynamicCall("SetValue(const QVariant&)", QVariant(strValue));   //
        return true;
    } catch (...) {
        return false;
    }
}

bool MyExcel::setValue(int row, int col, const QString& strValue, int nType)
{
    try {
        char sCell[18];
        memset(sCell, 0, 18);
        if (col <= 26)
            sprintf(sCell, " %c", 'A' + col - 1);
        else
            sprintf(sCell, "%c%c", 'A' + col / 26 - 1, 'A' + col % 26 - 1);

        QString cell = sCell;
        columnName = columnName.toUpper() > cell.toUpper() ? columnName : cell;
        cell = cell.trimmed() + QString::number(row);
        cell = cell + ":" + cell;

        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Cells(int,int)", row, col);
        if (!range)
            return false;

        if (row == 1) {
            range->dynamicCall("SetHorizontalAlignment(const QVariant&)", QVariant(-4108));
            range->dynamicCall("SetNumberFormatLocal(const QVariant&)", QVariant("@"));
        } else
            if (nType == 7 || nType == 8 || nType == 9 || nType == 11 || nType == 12 || nType == 10) //SA_dtString
                range->dynamicCall("SetNumberFormatLocal(const QVariant&)", QVariant("@"));
        if (!strValue.isNull() && !strValue.isEmpty())
            range->dynamicCall("SetValue(const QVariant&)", QVariant(strValue));

        delete range;
        return true;
    } catch (...) {
        return false;
    }
}

bool MyExcel::setCalce(const QString& cell, const QString& szCal)
{
    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Range(const QVariant&)", QVariant(cell));
        if (!range)
            return false;

        return range->setProperty("FormulaR1C1", szCal);
    } catch (...) {
        return false;
    }
}

bool MyExcel::setFormula(const QString& cell, const QString& szCal)
{
    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Range(const QVariant&)", QVariant(cell));
        if (!range)
            return false;

        return range->setProperty("Formula", szCal);
    } catch (...) {
        return false;
    }
}

bool MyExcel::setFontBold(const QString& cell, bool blBold)
{
    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Range(const QVariant&)", QVariant(cell));
        if (!range)
            return false;

        range = range->querySubObject("Font");
        if (!range) {
            return false;
        }

        return range->setProperty("Bold", blBold);
    } catch (...) {
        return false;
    }
}
bool MyExcel::setFontBold(int row, int col,  bool blBold)
{
    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Cells(int,int)", row, col);
        if (!range)
            return false;

        range = range->querySubObject("Font");
        if (!range) {
            return false;
        }

        //range->setProperty("Size", 10);
        //range->setProperty("Name", "Arial");
        //range->setProperty("SetName(const QString&)", "Arial");

        return range->setProperty("Bold", blBold);

    } catch (...) {
        return false;
    }
}
bool MyExcel::setFontType(int row, int col,  QString type)
{

//    QAxObject *range_1;
     //excelWorkBook->dynamicCall("SetStandardFont(QString)", type);
//     excelSheet->setProperty("StandardFont", type);


    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Cells(int,int)", row, col);
        if (!range)
            return false;

        range = range->querySubObject("Font");
        if (!range) {
            return false;
        }

        return range->setProperty("Name", type);

    } catch (...) {
        return false;
    }
}

bool MyExcel::setFontSize(int row, int col,  int size)
{
    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Cells(int,int)", row, col);
        if (!range)
            return false;

        range = range->querySubObject("Font");
        if (!range) {
            return false;
        }

        return range->setProperty("Size", size);

    } catch (...) {
        return false;
    }
}

bool MyExcel::setFontBorder(int row, int col,  int type)
{
    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Cells(int,int)", row, col);
        if (!range)
            return false;

        //range = range->querySubObject("Font");
        if (!range) {
            return false;
        }

        QAxObject *border_T = range->querySubObject("Borders(xlEdgeTop)");
        border_T->setProperty("LineStyle",1);
        border_T->setProperty("Weight",type);

        QAxObject *border_B = range->querySubObject("Borders(xlEdgeBottom)");
        border_B->setProperty("LineStyle",1);
        border_B->setProperty("Weight",type); // ???????

        QAxObject *border_L = range->querySubObject("Borders(xlEdgeLeft)");
        border_L->setProperty("LineStyle",1);
        border_L->setProperty("Weight",type);

        QAxObject *border_R = range->querySubObject("Borders(xlEdgeRight)");
        border_R->setProperty("LineStyle",1);
        return border_R->setProperty("Weight",type);


    } catch (...) {
        return false;
    }
}

bool MyExcel::setFontBorder(const QString& cell, int type)
{
    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Range(const QVariant&)", QVariant(cell));
        if (!range)
            return false;

        //range = range->querySubObject("Font");
        if (!range) {
            return false;
        }

        QAxObject *border_T = range->querySubObject("Borders(xlEdgeTop)");
        border_T->setProperty("LineStyle",1);
        border_T->setProperty("Weight",type);

        QAxObject *border_B = range->querySubObject("Borders(xlEdgeBottom)");
        border_B->setProperty("LineStyle",1);
        border_B->setProperty("Weight",type); // ???????

        QAxObject *border_L = range->querySubObject("Borders(xlEdgeLeft)");
        border_L->setProperty("LineStyle",1);
        border_L->setProperty("Weight",type);

        QAxObject *border_R = range->querySubObject("Borders(xlEdgeRight)");
        border_R->setProperty("LineStyle",1);
        return border_R->setProperty("Weight",type);


    } catch (...) {
        return false;
    }
}

bool MyExcel::setSheetDefault()
{

    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Range(const QVariant&)", QVariant(SHEET_DEFAUT_SIZE_CAN));
        if (!range)
            return false;

        range = range->querySubObject("Font");
        if (!range) {
            return false;
        }

        range->setProperty("Name", DEFAULT_FONT_NAME);
        return range->setProperty("Size", DEFAULT_FONT_SIZE);

    } catch (...) {
        return false;
    }
}


bool MyExcel::setMergeCells(const QString& cell)
{
    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Range(const QVariant&)", QVariant(cell));
        if (!range)
            return false;

        //range->setProperty("HorizontalAlignment", 0xFFFFEFF4);
             //range->setProperty("HorizontalAlignment", -4108);  // allign text to the center
        //range->setProperty("VerticalAlignment", 0xFFFFEFF4);
             //range->setProperty("VerticalAlignment", -4108);  // allign text to the center
        //range->setProperty("WrapText", false);
          range->setProperty("WrapText", true);
        range->setProperty("Orientation", 0);
        range->setProperty("AddIndent", false);
        range->setProperty("IndentLevel", 0);
        //range->setProperty("ShrinkToFit", false);
          range->setProperty("ShrinkToFit", true);
        range->setProperty("ReadingOrder", 0xFFFFEC76);
        range->setProperty("MergeCells", true);
        return true;
    } catch (...) {
        return false;
    }
}


bool MyExcel::setMergeCells(QString startColumn ,QString endColumn , int row, int horizontalAllign, int verticalAllign)
{
    QString cellRange = startColumn + QString::number(row) + ":" + endColumn + QString::number(row);

    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Range(const QVariant&)", QVariant(cellRange));
        if (!range)
            return false;

        if(horizontalAllign == H_LEFT_ALLIGN){
            range->setProperty("HorizontalAlignment", -4131);  // allign text to the left
        }
        else if(horizontalAllign == H_CENTER_ALLIGN){
            range->setProperty("HorizontalAlignment", -4108);  // allign text to the center
        }
        else if(horizontalAllign == H_RIGHT_ALLIGN){
            range->setProperty("HorizontalAlignment", -4152);  // allign text to the right
        }else{}

        if(verticalAllign == V_TOP_ALLIGN){
            range->setProperty("VerticalAlignment", -4160);  // allign text to the top
        }
        else if(verticalAllign == V_CENTER_ALLIGN){
            range->setProperty("HorizontalAlignment", -4108);  // allign text to the center
        }
        else if(verticalAllign == V_BOTTOM_ALLIGN){
            range->setProperty("HorizontalAlignment", -4107);  // allign text to the bottom
        }else{}

             //range->setProperty("VerticalAlignment", -4108);  // allign text to the center
        //range->setProperty("WrapText", false);
          range->setProperty("WrapText", true);
        range->setProperty("Orientation", 0);
        range->setProperty("AddIndent", false);
        range->setProperty("IndentLevel", 0);
        //range->setProperty("ShrinkToFit", false);
          range->setProperty("ShrinkToFit", true);
        range->setProperty("ReadingOrder", 0xFFFFEC76);
        range->setProperty("MergeCells", true);
        return true;
    } catch (...) {
        return false;
    }
}

bool MyExcel::wrapText(int row, int col, bool value)
{

    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Cells(int,int)", row, col);
        if (!range)
            return false;

        range->setProperty("WrapText", value);

    } catch (...) {
        return false;
    }

    return true;
}

bool MyExcel::setColour(int row, int col, int value)
{

    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Cells(int,int)", row, col);
        if (!range)
            return false;

        QAxObject* Interior = range->querySubObject("Interior");
        Interior->setProperty("ColorIndex",value);

    } catch (...) {
        return false;
    }

    return true;
}

bool MyExcel::VerticalAlignmentTop(int row, int col)
{

    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Cells(int,int)", row, col);
        if (!range)
            return false;

        range->setProperty("VerticalAlignment", -4160);  // allign text to the top

    } catch (...) {
        return false;
    }

    return true;
}

bool MyExcel::VerticalAlignmentCenter(int row, int col)
{

    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Cells(int,int)", row, col);
        if (!range)
            return false;

        range->setProperty("VerticalAlignment", -4108);  // allign text to the center

    } catch (...) {
        return false;
    }

    return true;
}

bool MyExcel::VerticalAlignmentBottom(int row, int col)
{

    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Cells(int,int)", row, col);
        if (!range)
            return false;

        range->setProperty("VerticalAlignment", -4107);  // allign text to the bottom

    } catch (...) {
        return false;
    }

    return true;
}

bool MyExcel::HorizontalAlignmentLeft(int row, int col)
{

    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Cells(int,int)", row, col);
        if (!range)
            return false;

        range->setProperty("HorizontalAlignment", -4131);  // allign text to the left

    } catch (...) {
        return false;
    }

    return true;
}

bool MyExcel::HorizontalAlignmentCenter(int row, int col)
{

    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Cells(int,int)", row, col);
        if (!range)
            return false;

        range->setProperty("HorizontalAlignment", -4108);  // allign text to the center

    } catch (...) {
        return false;
    }

    return true;
}

bool MyExcel::HorizontalAlignmentRight(int row, int col)
{

    try {
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject("Cells(int,int)", row, col);
        if (!range)
            return false;

        range->setProperty("HorizontalAlignment", -4152);  // allign text to the right

    } catch (...) {
        return false;
    }

    return true;
}

QVariant MyExcel::value(int row, int col)
{
    QVariant vValue;
    try {
        if (!excelSheet)
            return QVariant();
        QAxObject *range = excelSheet->querySubObject("Cells(int,int)", row, col);
        if (!range)
            return QVariant();

        vValue = range->property("Value2");
        delete range;

    } catch (...) {}
    return vValue;
}

QString MyExcel::maxColumn()
{
    return columnName.trimmed();
}

bool MyExcel::save()
{
    try {
        if (!excelWorkBook)
            return false;

        excelWorkBook->dynamicCall("SaveAs(const QString&)", fileName);

        return true;
    } catch (...) {
        return false;
    }
}

bool MyExcel::save(const QString& szFileName)
{
    try {
        if (!excelWorkBook)
            return false;

        excelWorkBook->dynamicCall("SaveAs(const QString&)", szFileName);
        //excelWorkBook->dynamicCall("Save()");

        return true;
    } catch (...) {
        return false;
    }
}

bool MyExcel::saveExcelformatxls()
{
    QList<QVariant> lstParam;

    try {
        if (!excelWorkBook)
            return false;

        //Set parameter for xls - MS-2003 format
        lstParam.append(fileName); // set file name
        lstParam.append(-4143);
        lstParam.append("");
        lstParam.append("");
        lstParam.append(false);
        lstParam.append(false);
        lstParam.append(1);
        lstParam.append(2);
        lstParam.append(false);
        lstParam.append(false);
        lstParam.append(false);
        lstParam.append(false);

        //Save new xls
        excelWorkBook->dynamicCall("SaveAs(QVariant, QVariant, QVariant, QVariant, QVariant, QVariant, QVariant, QVariant, QVariant, QVariant, QVariant, QVariant)", lstParam);

        return true;
    } catch (...) {
        return false;
    }
}


bool MyExcel::showExcel(bool bShow)
{
    try {
        if (!excelApplication)
            return false;
        excelApplication->setProperty("DisplayAlerts", bShow);
        excelApplication->dynamicCall("SetVisible(bool)", bShow);
        return true;
    } catch (...) {
        return false;
    }
}
void MyExcel::autoColumnWidth(const QString& strColumns)
{
    try {
        if (!excelSheet) {
            return;
        }
        QAxObject *columns;
        if (strColumns.isEmpty())
            columns = excelSheet->querySubObject("Columns(const QString &)", "a:z");
        else
            columns = excelSheet->querySubObject("Columns(const QString &)", strColumns);
        if (!columns) {
            QMessageBox::information(0, strColumns, "cells fail");
            return;
        }

        columns->dynamicCall("AutoFit()");
    } catch (...) {}
    return;
}

void MyExcel::setAutoFitRow(int row)
{
    QString rowsName;
    rowsName.append(QString::number(row));
    rowsName.append(":");
    rowsName.append(QString::number(row));

    QAxObject * rows = excelSheet->querySubObject("Rows(const QString &)", rowsName);
    rows->dynamicCall("AutoFit()");
}

void MyExcel::setRowHeight(int row, int height)
{
    QString rowsName;
    rowsName.append(QString::number(row));
    rowsName.append(":");
    rowsName.append(QString::number(row));

    QAxObject * r = excelSheet->querySubObject("Rows(const QString &)", rowsName);
    r->setProperty("RowHeight", height);

    //r->setProperty("WrapText", true);
}

bool MyExcel::writeRow(int row, QVariantList &list)
{
    try {
        char sCell[18];
        memset(sCell, 0, 18);
        int col = list.count();
        if (col <= 26)
            sprintf(sCell, " %c", 'A' + col - 1);
        else
            sprintf(sCell, "%c%c", 'A' + col / 26 - 1, 'A' + col % 26 - 1);

        QString cell = sCell;
        columnName = columnName.toUpper() > cell.toUpper() ? columnName : cell;
        cell = cell.trimmed() + QString::number(row);
        QString srange = "Range(\"A" + QString::number(row) + "\",\"" + cell + "\")";
        if (!excelSheet)
            return false;
        QAxObject *range = excelSheet->querySubObject(srange.toLocal8Bit());
        if (!range)
            return false;

        range->dynamicCall("SetValue2(const QVariantList&)", QVariant(list));
        delete range;

        return true;
    } catch (...) {
        return false;
    }
}

void MyExcel::setStringColumn(int col, int rows)
{
    try {
        char sCell[18];
        memset(sCell, 0, 18);
        if (col <= 26)
            sprintf(sCell, " %c", 'A' + col - 1);
        else
            sprintf(sCell, "%c%c", 'A' + col / 26 - 1, 'A' + col % 26 - 1);

        QString cell = sCell;
        cell = cell.trimmed();
        QString srange = "Range(\"" + cell + "1\",\"" + cell + QString::number(rows + 1) + "\")";
        QAxObject *range = excelSheet->querySubObject(srange.toLocal8Bit());
        if (range) {
            range->dynamicCall("SetNumberFormatLocal(const QVariant&)", QVariant("@"));
            delete range;
        }
    } catch (...) {}

}

int MyExcel::sheetCount()
{
    try {
        if (!excelSheets)
            return 0;
        return excelSheets->property("Count").toInt();
    } catch (...) {}
    return 0;
}

QString MyExcel::sheetName(int index)
{
    try {
        if (!excelSheets)
            return QString();
        QAxObject *s = excelSheets->querySubObject("Item(int index)", index);
        if (s) {
            return s->property("Name").toString();

        }
    } catch (...) {}
    return QString();
}

void MyExcel::getRowsCols(int *rows, int *cols)
{
    try {
        if (excelSheet) {
            QAxObject *ur = excelSheet->querySubObject("UsedRange()");
            if (ur) {
                QAxObject *cs = ur->querySubObject("columns()");
                if (cs) {
                    *cols = cs->property("Count").toInt();
                }

                QAxObject *rs = ur->querySubObject("Rows()");
                if (rs) {
                    *rows = rs->property("Count").toInt();
                }
            }
        }
    } catch (...) {

    }
}

QVariantList MyExcel::getAll(int *rows, int *cols)
{
    QVariant result;
    char sCell[18];
    try {
        getRowsCols(rows, cols);

        memset(sCell, 0, 18);
        if (*cols <= 26)
            sprintf(sCell, "%c", 'A' + *cols - 1);
        else
            sprintf(sCell, "%c%c", 'A' + *cols / 26 - 1, 'A' + *cols % 26 - 1);

        QString cell = sCell;

        cell = cell.trimmed() + QString::number(*rows);
        QString srange = "Range(\"A1\",\"" + cell + "\")";
        if (excelSheet) {
            QAxObject *range = excelSheet->querySubObject(srange.toLocal8Bit());
            if (range) {
                result =  range->property("Value");
                delete range;
            }
        }
    } catch (...) {}
    QVariantList list = qVariantValue<QVariantList>(result);

    return list;
}

QVariantList MyExcel::selectAll()
{
    QVariantList result;

    //	To select all rang implemention

    return result;
}

bool MyExcel::clearAllContents()
{
    //	To clear all contents.
    return true;
}

void MyExcel::tableViewToExcel(QTableView* table, QString excelFileName){

    QAbstractItemModel* model = table->model();
    QStringList headsdataStr;
    for (int i = 0; i < model->columnCount(); i++){
        headsdataStr.append (model->headerData (i, Qt::Horizontal).toString());
    }


    setFileName(excelFileName);
    selectSheet(1);
    setHeader(headsdataStr);

//    setValue(2, 2, "sss");
    int row = model->rowCount ();
    int column = model->columnCount ();

     for (int i = 0; i <= row; i++){
         for (int j = 0; j < column; j++){
             setValue (i+2, j+1, model->data(model->index(i, j)).toString());
         }
     }

    save ();
}

//#endif
