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


#ifndef WIDGETWEBSOCKETPACKETVARIABLESWITCH_H
#define WIDGETWEBSOCKETPACKETVARIABLESWITCH_H

#include <QtGui>
#include <QDialog>
#include "../../uiMagicianConfiguration.h"

namespace Ui {
class WidgetWebsocketPacketVariableSwitch;
}

class WidgetWebsocketPacketVariableSwitch : public QDialog
{
    Q_OBJECT
    
public:
    explicit WidgetWebsocketPacketVariableSwitch(T_widgetWebsocketPacketVariableSwitch &variableSwitchPacket, QWidget *parent = 0);
    ~WidgetWebsocketPacketVariableSwitch();

    T_widgetWebsocketPacketVariableSwitch &variableSwitchPacket_modify;

    //Copy slider packet to Dialog
    void CopyVariableSwitchPacket();

    //Routines to get value of class & types
    vscpClassTypeObject ClassTypeObject;

private slots:
    void on_OkvariableSwitchPushButton_clicked();

    void on_CancelvariableSwitchPushButton_clicked();

    void on_variableSwitchTxClassListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_variableSwitchRxClassListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::WidgetWebsocketPacketVariableSwitch *ui;

    QList<QString> listClass;
    QList<QString> listType;
    QList<QString> listAction;
    QList<QString> listPriority;

    void setListValue();
};

#endif // WIDGETWEBSOCKETPACKETVARIABLESWITCH_H
