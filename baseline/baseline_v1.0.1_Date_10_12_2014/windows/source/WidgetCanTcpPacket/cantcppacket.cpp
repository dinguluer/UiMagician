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

#include "canTcppacket.h"
#include "ui_canTcppacket.h"

CanTcpPacket::CanTcpPacket(T_testCaseStepCanPacket &canPacket, QWidget *parent) :
    QDialog(parent),
    canPacket_modify(canPacket),
    ui(new Ui::CanTcpPacket)
{
    ui->setupUi(this);

    //By default set the Hex -- CAN Packet TAB
    //set the hex checkbox - by default
    ui->HexcheckBox->setChecked(true);
    ui->DecimalcheckBox->setChecked(false);

    // Can-ID is 3 byte long
    ui->CanIdlineEdit->setValidator(new QRegExpValidator( QRegExp("[0-8a-fxA-FX]{1,3}"), this ));
    //ui->CanIdlineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9\\-\\:\\s]{1,19}"), this ));
    // DLC is 1 byte long
    ui->DlclineEdit->setValidator(new QRegExpValidator( QRegExp("[0-8xX]{1,1}"), this ));
    // Set the byte field is 2 byte long
    ui->Byte0lineEdit->setValidator(new QRegExpValidator( QRegExp("[0-8a-fxA-FX]{1,2}"), this ));
    ui->Byte1lineEdit->setValidator(new QRegExpValidator( QRegExp("[0-8a-fxA-FX]{1,2}"), this ));
    ui->Byte2lineEdit->setValidator(new QRegExpValidator( QRegExp("[0-8a-fxA-FX]{1,2}"), this ));
    ui->Byte3lineEdit->setValidator(new QRegExpValidator( QRegExp("[0-8a-fxA-FX]{1,2}"), this ));
    ui->Byte4lineEdit->setValidator(new QRegExpValidator( QRegExp("[0-8a-fxA-FX]{1,2}"), this ));
    ui->Byte5lineEdit->setValidator(new QRegExpValidator( QRegExp("[0-8a-fxA-FX]{1,2}"), this ));
    ui->Byte6lineEdit->setValidator(new QRegExpValidator( QRegExp("[0-8a-fxA-FX]{1,2}"), this ));
    ui->Byte7lineEdit->setValidator(new QRegExpValidator( QRegExp("[0-8a-fxA-FX]{1,2}"), this ));

    CopyCanPacket();

}

CanTcpPacket::~CanTcpPacket()
{
    delete ui;
}

void CanTcpPacket::on_DecimalcheckBox_clicked()
{
    //At present by default Hex state is enabled
    ui->DecimalcheckBox->setChecked( false );
}

void CanTcpPacket::on_HexcheckBox_clicked()
{
    //At present by default Hex state is enabled
    ui->HexcheckBox->setChecked( true );
}

void CanTcpPacket::on_OkPushButton_clicked()
{
    canPacket_modify.u16_CanId = ui->CanIdlineEdit->text();
    canPacket_modify.u8_dlc    = ui->DlclineEdit->text();
    canPacket_modify.u8_byte0  = ui->Byte0lineEdit->text();
    canPacket_modify.u8_byte1  = ui->Byte1lineEdit->text();
    canPacket_modify.u8_byte2  = ui->Byte2lineEdit->text();
    canPacket_modify.u8_byte3  = ui->Byte3lineEdit->text();
    canPacket_modify.u8_byte4  = ui->Byte4lineEdit->text();
    canPacket_modify.u8_byte5  = ui->Byte5lineEdit->text();
    canPacket_modify.u8_byte6  = ui->Byte6lineEdit->text();
    canPacket_modify.u8_byte7  = ui->Byte7lineEdit->text();

    /*QMessageBox *msgBox 	= new QMessageBox();
    msgBox->setText(canPacket_modify.u8_dlc);
    msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
    msgBox->exec();*/

    //Emit a close handler
    emit close();
}

//Copy CAN packet to Dialog
void CanTcpPacket::CopyCanPacket()
{
    ui->CanIdlineEdit->setText(canPacket_modify.u16_CanId);
    ui->DlclineEdit->setText(canPacket_modify.u8_dlc);
    ui->Byte0lineEdit->setText(canPacket_modify.u8_byte0);
    ui->Byte1lineEdit->setText(canPacket_modify.u8_byte1);
    ui->Byte2lineEdit->setText(canPacket_modify.u8_byte2);
    ui->Byte3lineEdit->setText(canPacket_modify.u8_byte3);
    ui->Byte4lineEdit->setText(canPacket_modify.u8_byte4);
    ui->Byte5lineEdit->setText(canPacket_modify.u8_byte5);
    ui->Byte6lineEdit->setText(canPacket_modify.u8_byte6);
    ui->Byte7lineEdit->setText(canPacket_modify.u8_byte7);

}
