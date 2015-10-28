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



#include "widgetimageselector.h"
#include "ui_widgetimageselector.h"

//http://stackoverflow.com/questions/8995829/how-to-resize-columns-in-qtreewidget-to-the-minimum-space-required
//http://stackoverflow.com/questions/9943866/what-is-the-method-to-set-the-text-for-a-qtreewidgets-header


/*
http://stackoverflow.com/questions/16633555/how-to-convert-qstring-to-int
http://www.qtforum.org/article/33749/convert-string-to-int-and-int-to-string.html
The following will convert QString to int :---
QString num="123";
int n = num.toInt();

This will convert Int to QString :----
int num = 123;
QString str= QString::number(num);

*/

/*
http://stackoverflow.com/questions/11996756/qtreewidget-select-first-item
qt qtreewidget select top level item programmatically

ui->WidgetImageSelectorTreeWidget->setCurrentItem(ui->WidgetImageSelectorTreeWidget->topLevelItem(6));
*/

/*

qtreeview & Model :----

qtreeview model add column
http://stackoverflow.com/questions/8305033/qtreeview-multiple-column-possible
qstandarditem set icon
http://qt.developpez.com/doc/4.7/qstandarditem/#qstandarditem-3

*/



WidgetImageSelector::WidgetImageSelector( QString &imageData ,QWidget *parent) :
    QDialog(parent),
    imageDataRef(imageData),
    ui(new Ui::WidgetImageSelector)
{
    ui->setupUi(this);

    int selectTopItem;

    //Set columns count
    ui->WidgetImageSelectorTreeWidget->setColumnCount(3);
    if(QTreeWidgetItem* header = ui->WidgetImageSelectorTreeWidget->headerItem()) {
      header->setText(0, SET_COLUMN_ZERO_HEADER_TEXT);
      header->setText(1, SET_COLUMN_ONE_HEADER_TEXT);
      header->setText(2, SET_COLUMN_TWO_HEADER_TEXT);
    }
    /*Resize columns to content
    for(int i = 0; i < 3; i++){
        ui->WidgetImageSelectorTreeWidget->resizeColumnToContents(i);
    }*/
    AddRoot();

    // Select the image
    if(imageData != NULL)
    {
        selectTopItem = imageData.toInt() - 1u;
    }
    else
    {
        selectTopItem = 94 - 1u;
    }

    // Select the top level Item
    ui->WidgetImageSelectorTreeWidget->setCurrentItem(ui->WidgetImageSelectorTreeWidget->topLevelItem(selectTopItem));
}

WidgetImageSelector::~WidgetImageSelector()
{
    delete ui;
}


void WidgetImageSelector::AddRoot()
{
    QList<QTreeWidgetItem *> items;
    QTreeWidgetItem *newItem;
    QString imageOn;
    QString imageOff;
    QString imageText = "94";
    //QMessageBox *msgBox 	= new QMessageBox();

    QSize t2(10, 12);
    t2.scale(60, 60, Qt::KeepAspectRatio);

   //for (int i = 1; i < 96; ++i)
    for (int i = 1; i <= TOTAL_BUTTON_TYPES; ++i)
    {
        switch ( i ) {
            case 1:
                imageOn = ":/Images/Images/button/pressong.png";
                imageOff = ":/Images/Images/button/pressoffg.png";
                //imageOn = ":/Images/Images/button/BULB04_LED.png";
                //imageOff = ":/Images/Images/button/webmichl_light_bulb.png";
                imageText  = "1";
                break;

            case 2:

            /*msgBox->setText("ok clicked image");
            msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
            msgBox->exec();*/

                imageOn = ":/Images/Images/button/pressono.png";
                imageOff = ":/Images/Images/button/pressoffo.png";
                //imageOn = ":/Images/Images/button/alex-th.png";
                //imageOff = ":/Images/Images/button/Birne.png";
                imageText  = "2";
                break;

            case 3:
                imageOn = ":/Images/Images/button/jbb1o.png";
                imageOff = ":/Images/Images/button/jbb1.png";
                //imageOn = ":/Images/Images/button/light-bulb-icon.jpg";
                //imageOff = ":/Images/Images/button/glossy-light-bulb.jpg";
                imageText  = "3";
                break;

           case 4:
                imageOn = ":/Images/Images/button/jbb2o.png";
                imageOff = ":/Images/Images/button/jbb2.png";
                imageText  = "4";
                break;

            case 5:
                imageOn = ":/Images/Images/button/jbgo.png";
                imageOff = ":/Images/Images/button/jbg.png";
                imageText  = "5";
                break;

            case 6:
                imageOn = ":/Images/Images/button/jboo.png";
                imageOff = ":/Images/Images/button/jbo.png";
                imageText  = "6";
                break;

            case 7:
                imageOn = ":/Images/Images/button/jbro.png";
                imageOff = ":/Images/Images/button/jbr.png";
                imageText  = "7";
                break;

            case 8:
                imageOn = ":/Images/Images/button/jbwo.png";
                imageOff = ":/Images/Images/button/jbw.png";
                imageText  = "8";
                break;

            case 9:
                imageOn = ":/Images/Images/button/jbyo.png";
                imageOff = ":/Images/Images/button/jby.png";
                imageText  = "9";
                break;

            case 10:
                imageOn = ":/Images/Images/button/jellyon.png";
                imageOff = ":/Images/Images/button/jellyoff.png";
                imageText  = "10";
                break;

            case 11:
                imageOn = ":/Images/Images/button/dualpushgreymirror.png";
                imageOff = ":/Images/Images/button/dualpushgrey.png";
                imageText  = "11";
                break;

            case 12:
                imageOn = ":/Images/Images/button/klunk.png";
                imageOff = ":/Images/Images/button/klunkmirror.png";
                imageText  = "12";
                break;

            case 13:
                imageOn = ":/Images/Images/button/klunk2.png";
                imageOff = ":/Images/Images/button/klunk2mirror.png";
                imageText  = "13";
                break;

            case 14:
                imageOn = ":/Images/Images/button/klunk4.png";
                imageOff = ":/Images/Images/button/klunk4mirror.png";
                imageText  = "14";
                break;

            case 15:
                imageOn = ":/Images/Images/button/polyblue.png";
                imageOff = ":/Images/Images/button/polywhiteH.png";
                imageText  = "15";
                break;

            case 16:
                imageOn = ":/Images/Images/button/polyredV.png";
                imageOff = ":/Images/Images/button/polywhiteV.png";
                imageText  = "16";
                break;

            case 17:
                imageOn = ":/Images/Images/button/pressonS.png";
                imageOff = ":/Images/Images/button/pressoffS.png";
                imageText  = "17";
                break;

            case 18:
                imageOn = ":/Images/Images/button/pressonSb.png";
                imageOff = ":/Images/Images/button/pressoffSb.png";
                imageText  = "18";
                break;

            case 19:
                imageOn = ":/Images/Images/button/pressonSg.png";
                imageOff = ":/Images/Images/button/pressoffSg.png";
                imageText  = "19";
                break;

            case 20:
                imageOn = ":/Images/Images/button/pressonSy.png";
                imageOff = ":/Images/Images/button/pressoffSy.png";
                imageText  = "20";
                break;

            case 21:
                imageOn = ":/Images/Images/button/pushout.png";
                imageOff = ":/Images/Images/button/pushin.png";
                imageText  = "22";
                break;

            case 22:
                imageOn = ":/Images/Images/button/pushoutw.png";
                imageOff = ":/Images/Images/button/pushinw.png";
                imageText  = "22";
                break;

            case 23:
                imageOn = ":/Images/Images/button/rockerblack.png";
                imageOff = ":/Images/Images/button/rockerblackleft.png";
                imageText  = "23";
                break;

            case 24:
                imageOn = ":/Images/Images/button/rockerblue.png";
                imageOff = ":/Images/Images/button/rockerblueleft.png";
                imageText  = "24";
                break;

            case 25:
                imageOn = ":/Images/Images/button/rockergrey.png";
                imageOff = ":/Images/Images/button/rockergreyleft.png";
                imageText  = "25";
                break;

            case 26:
                imageOn = ":/Images/Images/button/rockerred.png";
                imageOff = ":/Images/Images/button/rockerredleft.png";
                imageText  = "26";
                break;

            case 27:
                imageOn = ":/Images/Images/button/rockersmoothd.png";
                imageOff = ":/Images/Images/button/rockersmooth.png";
                imageText  = "27";
                break;


            case 28:
                imageOn = ":/Images/Images/button/rockersmoothBBd.png";
                imageOff = ":/Images/Images/button/rockersmoothBB.png";
                imageText  = "28";
                break;

            case 29:
                imageOn = ":/Images/Images/button/rockersmoothBBLd.png";
                imageOff = ":/Images/Images/button/rockersmoothBBL.png";
                imageText  = "29";
                break;

            case 30:
                imageOn = ":/Images/Images/button/rockersmoothBCd.png";
                imageOff = ":/Images/Images/button/rockersmoothBC.png";
                imageText  = "30";
                break;

            case 31:
                imageOn = ":/Images/Images/button/rockersmoothBGd.png";
                imageOff = ":/Images/Images/button/rockersmoothBG.png";
                imageText  = "31";
                break;

            case 32:
                imageOn = ":/Images/Images/button/rockersmoothBGRd.png";
                imageOff = ":/Images/Images/button/rockersmoothBGR.png";
                imageText  = "32";
                break;

            case 33:
                imageOn = ":/Images/Images/button/rockersmoothBWd.png";
                imageOff = ":/Images/Images/button/rockersmoothBW.png";
                imageText  = "33";
                break;

            case 34:
                imageOn = ":/Images/Images/button/rockersmoothBWRd.png";
                imageOff = ":/Images/Images/button/rockersmoothBWR.png";
                imageText  = "34";
                break;

            case 35:
                imageOn = ":/Images/Images/button/rockerwhite.png";
                imageOff = ":/Images/Images/button/rockerwhiteleft.png";
                imageText  = "35";
                break;

            case 36:
                imageOn = ":/Images/Images/button/sidbon.png";
                imageOff = ":/Images/Images/button/sidb.png";
                imageText  = "36";
                break;

            case 37:
                imageOn = ":/Images/Images/button/sidbongreen.png";
                imageOff = ":/Images/Images/button/sidb.png";
                imageText  = "37";
                break;

            case 38:
                imageOn = ":/Images/Images/button/sidbonblue.png";
                imageOff = ":/Images/Images/button/sidb.png";
                imageText  = "38";
                break;

            case 39:
                imageOn = ":/Images/Images/button/solinaOn.png";
                imageOff = ":/Images/Images/button/solinaOff.png";
                imageText  = "39";
                break;

            case 40:
                imageOn = ":/Images/Images/button/led-orange-round-button-in.png";
                imageOff = ":/Images/Images/button/led-orange-round-button-out.png";
                imageText  = "40";
                break;

            case 41:
                imageOn = ":/Images/Images/button/led_circle_red.png";
                imageOff = ":/Images/Images/button/led_circle_grey.png";
                imageText  = "41";
                break;

            case 42:
                imageOn = ":/Images/Images/button/led_circle_yellow_.png";
                imageOff = ":/Images/Images/button/led_circle_grey.png";
                imageText  = "42";
                break;

            case 43:
                imageOn = ":/Images/Images/button/led-green.png";
                imageOff = ":/Images/Images/button/led_circle_grey.png";
                imageText  = "43";
                break;

            case 44:
                imageOn = ":/Images/Images/button/led-green-button2.png";
                imageOff = ":/Images/Images/button/led_circle_grey.png";
                imageText  = "44";
                break;

            case 45:
                imageOn = ":/Images/Images/button/led_circle_green.png";
                imageOff = ":/Images/Images/button/led_circle_grey.png";
                imageText  = "45";
                break;

            case 46:
                imageOn = ":/Images/Images/button/led_circle_orange.png";
                imageOff = ":/Images/Images/button/led_circle_grey.png";
                imageText  = "46";
                break;

            case 47:
                imageOn = ":/Images/Images/button/led_circle_purple.png";
                imageOff = ":/Images/Images/button/led_circle_grey.png";
                imageText  = "47";
                break;

            case 48:
                imageOn = ":/Images/Images/button/led_circle_blue.png";
                imageOff = ":/Images/Images/button/led_circle_grey.png";
                imageText  = "48";
                break;

            case 49:
                imageOn = ":/Images/Images/button/led-red-on.png";
                imageOff = ":/Images/Images/button/led-red-off.png";
                imageText  = "49";
                break;

            case 50:
                imageOn = ":/Images/Images/button/led-green.png";
                imageOff = ":/Images/Images/button/led_circle_green.png";
                imageText  = "50";
                break;

            case 51:
                imageOn = ":/Images/Images/button/led_circle_green.png";
                imageOff = ":/Images/Images/button/led-red-off.png";
                imageText  = "51";
                break;

            case 52:
                imageOn = ":/Images/Images/button/poweron.png";
                imageOff = ":/Images/Images/button/poweroff.png";
                imageText  = "52";
                break;

            case 53:
                imageOn = ":/Images/Images/button/push-button-light-blue.png";
                imageOff = ":/Images/Images/button/push-button-glossy-red.png";
                imageText  = "53";
                break;

            case 54:
                imageOn = ":/Images/Images/button/push-button-yellow-glossy.png";
                imageOff = ":/Images/Images/button/push-button-glossy-red.png";
                imageText  = "54";
                break;

            case 55:
                imageOn = ":/Images/Images/button/push-button-light-blue.png";
                imageOff = ":/Images/Images/button/push-button-yellow-glossy.png";
                imageText  = "55";
                break;

            case 56:
                imageOn = ":/Images/Images/button/light_switch_on.png";
                imageOff = ":/Images/Images/button/light_switch_off.png";
                imageText  = "56";
                break;

            case 57:
                imageOn = ":/Images/Images/button/sw2.png";
                imageOff = ":/Images/Images/button/sw1.png";
                imageText  = "57";
                break;

            case 58:
                imageOn = ":/Images/Images/button/sw3.png";
                imageOff = ":/Images/Images/button/sw5.png";
                imageText  = "58";
                break;

            case 59:
                imageOn = ":/Images/Images/button/switch3.png";
                imageOff = ":/Images/Images/button/switch1.png";
                imageText  = "59";
                break;

            case 60:
                imageOn = ":/Images/Images/button/touchy.png";
                imageOff = ":/Images/Images/button/touchoy.png";
                imageText  = "60";
                break;

            case 61:
                imageOn = ":/Images/Images/button/touchw.png";
                imageOff = ":/Images/Images/button/touchow.png";
                imageText  = "61";
                break;

            case 62:
                imageOn = ":/Images/Images/button/toucho.png";
                imageOff = ":/Images/Images/button/touchoo.png";
                imageText  = "62";
                break;

            case 63:
                imageOn = ":/Images/Images/button/btn_led_rectangular_vh_black.png";
                imageOff = ":/Images/Images/button/btn_led_rectangular_v_black.png";
                imageText  = "63";
                break;

            case 64:
                imageOn = ":/Images/Images/button/btn-led_rounded_vh_black.png";
                imageOff = ":/Images/Images/button/btn-led_rounded_v_black.png";
                imageText  = "64";
                break;

            case 65:
                imageOn = ":/Images/Images/button/btn-led_rounded_vh_grey.png";
                imageOff = ":/Images/Images/button/btn-led_rounded_v_grey.png";
                imageText  = "65";
                break;

            case 66:
                imageOn = ":/Images/Images/button/btn_pressdown_on.png";
                imageOff = ":/Images/Images/button/btn_pressdown_off.png";
                imageText  = "66";
                break;

            case 67:
                imageOn = ":/Images/Images/button/btn_pressdown2_on.png";
                imageOff = ":/Images/Images/button/btn_pressdown2_off.png";
                imageText  = "67";
                break;

            case 68:
                imageOn = ":/Images/Images/button/red-rectangle-blank-button-on.png";
                imageOff = ":/Images/Images/button/red-rectangle-blank-button2-off.png";
                imageText  = "68";
                break;

            case 69:
                imageOn = ":/Images/Images/button/run-push-button-on.png";
                imageOff = ":/Images/Images/button/run-push-button-off.png";
                imageText  = "69";
                break;

            case 70:
                imageOn = ":/Images/Images/button/btn-silver-on.png";
                imageOff = ":/Images/Images/button/btn-silver-off.png";
                imageText  = "70";
                break;

            case 71:
                imageOn = ":/Images/Images/button/stop.png";
                imageOff = ":/Images/Images/button/start.png";
                imageText  = "71";
                break;

            case 72:
                imageOn = ":/Images/Images/button/switch-knob-on.png";
                imageOff = ":/Images/Images/button/switch-knob-off.png";
                imageText  = "72";
                break;

            case 73:
                imageOn = ":/Images/Images/button/SwtchON1.png";
                imageOff = ":/Images/Images/button/SwtchOF1.png";
                imageText  = "73";
                break;

            case 74:
                imageOn = ":/Images/Images/button/system-shut-down-on.png";
                imageOff = ":/Images/Images/button/system-shut-down-off.png";
                imageText  = "74";
                break;

            case 75:
                imageOn = ":/Images/Images/button/brami_Square_Black_Crystal_Button.on.png";
                imageOff = ":/Images/Images/button/brami_Square_Black_Crystal_Button.off.png";
                imageText  = "75";
                break;

            case 76:
                imageOn = ":/Images/Images/button/btncpgreen-on.png";
                imageOff = ":/Images/Images/button/btncpgreen-off.png";
                imageText  = "76";
                break;

            case 77:
                imageOn = ":/Images/Images/button/btncpmag-on.png";
                imageOff = ":/Images/Images/button/btncpmag-off.png";
                imageText  = "77";
                break;

            case 78:
                imageOn = ":/Images/Images/button/button-for-numbers-on.png";
                imageOff = ":/Images/Images/button/button-for-numbers-off.png";
                imageText  = "78";
                break;

            case 79:
                imageOn = ":/Images/Images/button/button-green-on.png";
                imageOff = ":/Images/Images/button/button-green-off.png";
                imageText  = "79";
                break;

            case 80:
                imageOn = ":/Images/Images/button/button-on.png";
                imageOff = ":/Images/Images/button/button-off.png";
                imageText  = "80";
                break;

            case 81:
                imageOn = ":/Images/Images/button/button-power-on.png";
                imageOff = ":/Images/Images/button/button-power-off.png";
                imageText  = "81";
                break;

            case 82:
                imageOn = ":/Images/Images/button/btn-grey-rounded-on.png";
                imageOff = ":/Images/Images/button/btn-grey-rounded-off.png";
                imageText  = "82";
                break;

            case 83:
                imageOn = ":/Images/Images/button/btn-grey-on.png";
                imageOff = ":/Images/Images/button/btn-grey-off.png";
                imageText  = "83";
                break;

            case 84:
                imageOn = ":/Images/Images/button/interruptor-on.png";
                imageOff = ":/Images/Images/button/interruptor-off.png";
                imageText  = "84";
                break;

            case 85:
                imageOn = ":/Images/Images/button/knife_switch_on.png";
                imageOff = ":/Images/Images/button/knife_switch_off.png";
                imageText  = "85";
                break;

            case 86:
                imageOn = ":/Images/Images/button/on-button.png";
                imageOff = ":/Images/Images/button/off-button.png";
                imageText  = "86";
                break;

            case 87:
                imageOn = ":/Images/Images/button/btn-modern-on.png";
                imageOff = ":/Images/Images/button/btn-modern-off.png";
                imageText  = "87";
                break;

            case 88:
                imageOn = ":/Images/Images/button/btn-oldstyle-on.png";
                imageOff = ":/Images/Images/button/btn-oldstyle-off.png";
                imageText  = "88";
                break;

            case 89:
                imageOn = ":/Images/Images/button/orange-button-on.png";
                imageOff = ":/Images/Images/button/orange-button-off.png";
                imageText  = "89";
                break;

            case 90:
                imageOn = ":/Images/Images/light/lightbulb1_on.png";
                imageOff = ":/Images/Images/light/lightbulb1_off.png";
                imageText  = "90";
                break;

            case 91:
                imageOn = ":/Images/Images/light/light_red.gif";
                imageOff = ":/Images/Images/light/light_green.gif";
                imageText  = "91";
                break;

            case 92:
                imageOn = ":/Images/Images/lightbulb/semi-matte-light-bulb-lit-th.png";
                imageOff = ":/Images/Images/lightbulb/semi-matte-light-bulb-unlit-th.png";
                imageText  = "92";
                break;

            case 93:
                imageOn = ":/Images/Images/lightbulb/lightbulb-th.png";
                imageOff = ":/Images/Images/lightbulb/lightbulb-white-th.png";
                imageText  = "93";
                break;

            case 94:
                imageOn = ":/Images/Images/lightbulb/glossy-light-bulb.jpg";
                imageOff = ":/Images/Images/lightbulb/light-bulb-icon.jpg";
                imageText  = "94";
                break;

            case 95:
                imageOn = ":/Images/Images/doors_windows/Open_Door.png";
                imageOff = ":/Images/Images/doors_windows/closed_door.png";
                imageText  = "95";
                break;

            case 96:
                imageOn = ":/Images/Images/doors_windows/open_window.png";
                imageOff = ":/Images/Images/doors_windows/closed_window.png";
                imageText  = "96";
                break;

            default:
                imageOn = ":/Images/Images/button/presson.png";
                imageOff = ":/Images/Images/button/pressoff.png";
                imageText  = "default";
                break;
        }

        newItem = new  QTreeWidgetItem(ui->WidgetImageSelectorTreeWidget);
        newItem->setIcon(0, QIcon(imageOn));
        newItem->setIcon(1, QIcon(imageOff));
        newItem->setText(2, imageText);
        items.append(newItem);
        //ui->WidgetImageSelectorTreeWidget->insertTopLevelItem(i,newItem);
    }
    ui->WidgetImageSelectorTreeWidget->insertTopLevelItems(0,items);
    ui->WidgetImageSelectorTreeWidget->setIconSize(t2/*QSize(80,48)*/);
    //ui->WidgetImageSelectorTreeWidget->expandAll();

    //imageData = "test";
}

void WidgetImageSelector::on_WidgetImageSelectorPushButtonOk_clicked()
{
    int currentNum = ui->WidgetImageSelectorTreeWidget->currentIndex().row() + 1u;

    imageDataRef = QString::number(currentNum);
    //imageDataRef = "test_ok";
    /*QString str= QString::number(ui->WidgetImageSelectorTreeWidget->currentIndex().row());

    QMessageBox *msgBox 	= new QMessageBox();
    //msgBox->setText("ok clicked image");
    msgBox->setText(str);
    msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
    msgBox->exec();*/

    //Emit a close handler
    emit close();
}
