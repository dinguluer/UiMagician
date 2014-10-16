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


#ifndef WIDGETWEBSOCKETPACKETSENSOR_H
#define WIDGETWEBSOCKETPACKETSENSOR_H

#include <QtGui>
#include <QDialog>
#include "../../uiMagicianConfiguration.h"

namespace Ui {
class WidgetWebsocketPacketSensor;
}

class WidgetWebsocketPacketSensor : public QDialog
{
    Q_OBJECT
    
public:
    explicit WidgetWebsocketPacketSensor(T_widgetwebsocketPacketsensor &sensorPacket, QWidget *parent = 0);
    ~WidgetWebsocketPacketSensor();
    
    T_widgetwebsocketPacketsensor &sensorPacket_modify;

    //Copy Sensor packet to Dialog
    void CopySensorPacket();

    //Routines to get value of class & types
    vscpClassTypeObject ClassTypeObject;


private:
    Ui::WidgetWebsocketPacketSensor *ui;

    QList<QString> listClass;
    QList<QString> listType;
    QList<QString> listAction;
    QList<QString> listPriority;
    QList<QString> listCodingIndex;

    void setListValue();

private slots :
    void currentItemChanged_slot();
    void on_OkSensorPushButton_clicked();
    void on_CancelSensorPushButton_clicked();
};

#endif // WIDGETWEBSOCKETPACKETSENSOR_H
