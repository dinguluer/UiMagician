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

#ifndef CANTCPPACKET_H
#define CANTCPPACKET_H

#include <QtGui>
#include <QDialog>
#include "uiMagicianConfiguration.h"

namespace Ui {
class CanTcpPacket;
}

class CanTcpPacket : public QDialog
{
    Q_OBJECT
    
public:
    explicit CanTcpPacket(T_testCaseStepCanPacket &canPacket, QWidget *parent = 0);
    ~CanTcpPacket();

    T_testCaseStepCanPacket &canPacket_modify;

    //Copy CAN packet to Dialog
    void CopyCanPacket();
    
private slots:
    void on_DecimalcheckBox_clicked();

    void on_HexcheckBox_clicked();

    void on_OkPushButton_clicked();

private:
    Ui::CanTcpPacket *ui;
};

#endif // CANTCPPACKET_H
