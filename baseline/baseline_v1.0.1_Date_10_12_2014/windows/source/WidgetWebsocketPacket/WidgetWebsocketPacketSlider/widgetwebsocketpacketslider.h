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


#ifndef WIDGETWEBSOCKETPACKETSLIDER_H
#define WIDGETWEBSOCKETPACKETSLIDER_H

#include <QtGui>
#include <QDialog>
#include "../../uiMagicianConfiguration.h"

#define VARIABLE_TAB_INDEX  3

namespace Ui {
class WidgetWebsocketPacketSlider;
}

class WidgetWebsocketPacketSlider : public QDialog
{
    Q_OBJECT
    
public:
    explicit WidgetWebsocketPacketSlider(T_widgetWebsocketPacketSlider &sliderPacket, QWidget *parent = 0);
    ~WidgetWebsocketPacketSlider();

    T_widgetWebsocketPacketSlider &sliderPacket_modify;

    //Copy slider packet to Dialog
    void CopySliderPacket();

    //Routines to get value of class & types
    vscpClassTypeObject ClassTypeObject;

private slots:
    void on_OkSliderPushButton_clicked();

    void on_CancelSliderPushButton_clicked();

    void on_sliderTxClassListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_sliderRxClassListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_WidgetWebsocketPacketSliderTabWidget_currentChanged(int index);

private:
    Ui::WidgetWebsocketPacketSlider *ui;

    QList<QString> listClass;
    QList<QString> listType;
    QList<QString> listAction;
    QList<QString> listPriority;

    void setListValue();
};

#endif // WIDGETWEBSOCKETPACKETSLIDER_H
