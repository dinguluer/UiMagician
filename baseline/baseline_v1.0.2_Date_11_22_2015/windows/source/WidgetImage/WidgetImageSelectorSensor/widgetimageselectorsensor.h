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


#ifndef WIDGETIMAGESELECTORSENSOR_H
#define WIDGETIMAGESELECTORSENSOR_H

#include <QDialog>

#define SET_COLUMN_ZERO_HEADER_TEXT_SENSOR "Sensor   Image              "
#define SET_COLUMN_ONE_HEADER_TEXT_SENSOR  "Image Text"

namespace Ui {
class WidgetImageSelectorSensor;
}

class WidgetImageSelectorSensor : public QDialog
{
    Q_OBJECT
    
public:
    explicit WidgetImageSelectorSensor( QString &imageData ,QWidget *parent = 0);
    ~WidgetImageSelectorSensor();

    void AddRoot();

    QString &imageDataRef;

private slots:

    void on_WidgetImageSelectorSensorPushButtonOk_clicked();
    
private:
    Ui::WidgetImageSelectorSensor *ui;
};

#endif // WIDGETIMAGESELECTORSENSOR_H
