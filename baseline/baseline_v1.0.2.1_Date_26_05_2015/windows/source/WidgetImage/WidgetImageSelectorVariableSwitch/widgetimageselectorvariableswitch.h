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


#ifndef WIDGETIMAGESELECTORVARIABLESWITCH_H
#define WIDGETIMAGESELECTORVARIABLESWITCH_H

#include <QtGui>
#include <QDialog>


#define SET_VARIABLE_SWITCH_COLUMN_ZERO_HEADER_TEXT "Image One              "
#define SET_VARIABLE_SWITCH_COLUMN_ONE_HEADER_TEXT  "Image Two              "
#define SET_VARIABLE_SWITCH_COLUMN_TWO_HEADER_TEXT  "Image Text"

#define TOTAL_VARIABLE_SWITCH_BUTTON_TYPES     1
#define FIRST_SLIDER_IMAGE                     "2"  // i.e ---> (VARIABLE_SWITCH_ + 1)


namespace Ui {
class WidgetImageSelectorVariableSwitch;
}

class WidgetImageSelectorVariableSwitch : public QDialog
{
    Q_OBJECT
    
public:
    explicit WidgetImageSelectorVariableSwitch( QString &imageData ,QWidget *parent = 0);
    ~WidgetImageSelectorVariableSwitch();

    void AddRoot();

    QString &imageDataRef;

private slots:
    void on_WidgetImageSelectorVariableSwitchPushButtonOk_clicked();

private:
    Ui::WidgetImageSelectorVariableSwitch *ui;
};

#endif // WIDGETIMAGESELECTORVARIABLESWITCH_H
