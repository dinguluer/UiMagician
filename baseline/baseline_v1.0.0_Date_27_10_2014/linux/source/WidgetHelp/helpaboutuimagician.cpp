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

#include "uiMagicianConfiguration.h"
#include "helpaboutuimagician.h"
#include "ui_helpaboutuimagician.h"

helpAboutUiMagician::helpAboutUiMagician(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpAboutUiMagician)
{
    ui->setupUi(this);

    QString uimagicianText;
    uint16_t inputWidth = 256;  //16
    uint16_t inputHeight = 144;  //9

    //QPixmap pixmap(":/Images/Images/designer.png");

    QImage image(":/Images/Images/designer.png");
    QImage small = image.scaled(inputWidth, inputHeight,Qt::KeepAspectRatio);

    uimagicianText = "<b> UI Magician 1.0.0 </b>";
    ui->helpImageTextVscpVersion->setText(uimagicianText);
    ui->helpImageTextVscpVersion->setWordWrap(true);
    uimagicianText = " Author : Dinesh Guleria ";
    ui->helpImageTextAuthor->setText(uimagicianText);
    ui->helpImageTextAuthor->setWordWrap(true);
    uimagicianText = " Copyright 2012-2014. VSCP Project  ";
    ui->helpImageTextCopyright->setText(uimagicianText);
    ui->helpImageTextCopyright->setWordWrap(true);

    ui->helpImageLabel->setPixmap(QPixmap::fromImage(small));


}

helpAboutUiMagician::~helpAboutUiMagician()
{
    delete ui;
}

void helpAboutUiMagician::on_closePushButton_clicked()
{
    //Emit a close handler
    emit close();
}
