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



#include "widgetwebsocketpacketswitch.h"
#include "ui_widgetwebsocketpacketswitch.h"

WidgetWebsocketPacketSwitch::WidgetWebsocketPacketSwitch(T_widgetWebsocketPacketSwitch &switchPacket, QWidget *parent) :
    QDialog(parent),
    switchPacket_modify(switchPacket),
    ui(new Ui::WidgetWebsocketPacketSwitch)
{
    ui->setupUi(this);

    setListValue();

    //ui->sensorUrlLineEdit->setValidator(new QRegExpValidator( QRegExp("[w]{1,1}[s]{1,1}[s]{1,1}\\:\\/\\/[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\:[0-9]{1,4}" ), this ));
    ui->urlLineEdit->setValidator(new QRegExpValidator( QRegExp("[w]{1,1}[s]{1,2}\\:\\/\\/[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\:[0-9]{1,4}" ), this ));
    // Add list item here
    for(int i=0; i< listTrueFalse.size() ; i++)
    {
        ui->bLocalListWidget->addItem(listTrueFalse.at(i));
        ui->bNoStateListWidget->addItem(listTrueFalse.at(i));
    }

    /*
    //class
    // Add list item here
    for(int i=0; i< listClass.size() ; i++)
    {
        ui->txOnClassListWidget->addItem(listClass.at(i));
    }
    ui->txOnClassListWidget->setCurrentRow(0);
    //type
    // Add list item here
    for(int i=0; i< listType.size() ; i++)
    {
        ui->txOnTypeListWidget->addItem(listType.at(i));
    }
    ui->txOnTypeListWidget->setCurrentRow(0);
    //data
    ui->txOnGuidLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}"), this ));
    //ui->txOnIndexLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->txOnIndexLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    //ui->txOnZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->txOnZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    //ui->txOnSubZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->txOnSubZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    ui->txOnHeadLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->txOnObidLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,8}"), this ));
    //class
    // Add list item here
    for(int i=0; i< listClass.size() ; i++)
    {
        ui->txOffClassListWidget->addItem(listClass.at(i));
    }
    ui->txOffClassListWidget->setCurrentRow(0);
    //type
    // Add list item here
    for(int i=0; i< listType.size() ; i++)
    {
        ui->txOffTypeListWidget->addItem(listType.at(i));
    }
    ui->txOffTypeListWidget->setCurrentRow(0);
    //data
    ui->txOffGuidLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}"), this ));
    //ui->txOffIndexLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->txOffIndexLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    //ui->txOffZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->txOffZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    //ui->txOffSubZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->txOffSubZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    ui->txOffHeadLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->txOffObidLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,8}"), this ));
    //class
    // Add list item here
    for(int i=0; i< listClass.size() ; i++)
    {
        ui->rxOnClassListWidget->addItem(listClass.at(i));
    }
    ui->rxOnClassListWidget->setCurrentRow(0);
    //type
    // Add list item here
    for(int i=0; i< listType.size() ; i++)
    {
        ui->rxOnTypeListWidget->addItem(listType.at(i));
    }
    ui->rxOnTypeListWidget->setCurrentRow(0);
    //data
    ui->rxOnGuidLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}"), this ));
    //ui->rxOnIndexLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->rxOnIndexLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    //ui->rxOnZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->rxOnZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    //ui->rxOnSubZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->rxOnSubZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    ui->rxOnHeadLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->rxOnObidLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,8}"), this ));

    //class
    // Add list item here
    for(int i=0; i< listClass.size() ; i++)
    {
        ui->rxOffClassListWidget->addItem(listClass.at(i));
    }
    ui->rxOffClassListWidget->setCurrentRow(0);
    //type
    // Add list item here
    for(int i=0; i< listType.size() ; i++)
    {
        ui->rxOffTypeListWidget->addItem(listType.at(i));
    }
    ui->rxOffTypeListWidget->setCurrentRow(0);
    //data
    ui->rxOffGuidLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}"), this ));
    //ui->rxOffIndexLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->rxOffIndexLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    //ui->rxOffZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->rxOffZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    //ui->rxOffSubZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->rxOffSubZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    ui->rxOffHeadLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->rxOffObidLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,8}"), this ));

    ui->variableAllowedFromLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9\\-\\:\\s]{1,19}"), this ));
    ui->variableAllowedToLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9\\-\\:\\s]{1,19}"), this ));
    ui->variableAllowedTimeLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9\\-\\:\\s]{1,19}"), this ));

    //groupId validator
    ui->variableGroupIdLineEdit->setValidator(new QRegExpValidator( QRegExp("[a-zA-Z0-9_]*"), this ));

    //set the list for Action - variableActionListWidget
    for(int i=0; i< listAction.size() ; i++)
    {
        ui->variableActionListWidget->addItem(listAction.at(i));
    }
    // set the list for priority
    for(int i=0; i< listPriority.size() ; i++)
    {
        ui->variablePriorityListWidget->addItem(listPriority.at(i));
    }

    // Make data & timestamp cell non editable
    ui->txOnTimeStampLineEdit->setReadOnly(true);
    ui->variableActionParametersSetLineEdit->setReadOnly(true);
    ui->variableActionParametersResetLineEdit->setReadOnly(true);
    ui->txOnDataLineEdit->setReadOnly(true);
    ui->txOffTimeStampLineEdit->setReadOnly(true);
    ui->txOffDataLineEdit->setReadOnly(true);
    ui->rxOnTimeStampLineEdit->setReadOnly(true);
    ui->rxOnDataLineEdit->setReadOnly(true);
    ui->rxOffTimeStampLineEdit->setReadOnly(true);
    ui->rxOffDataLineEdit->setReadOnly(true);

    */
    //domain should be fixed
    ui->domainLineEdit->setReadOnly(true);
    // non editable
    //ui->variableActionParametersLineEdit->setReadOnly(true);

    //Copy switch packet to Dialog
    CopySwitchPacket();

    /*
    connect(ui->txOnClassListWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), this, SLOT(txOnClassListWidgetcurrentItemChanged_slot()));
    connect(ui->txOffClassListWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), this, SLOT(txOffClassListWidgetcurrentItemChanged_slot()));
    connect(ui->rxOnClassListWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), this, SLOT(rxOnClassListWidgetcurrentItemChanged_slot()));
    connect(ui->txOffClassListWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), this, SLOT(txOffClassListWidgetcurrentItemChanged_slot()));
*/
}


void WidgetWebsocketPacketSwitch::setListValue()
{
    listTrueFalse << "true" << "false";
    /*listClass     << VSCP_CLASS1_PROTOCOL << VSCP_CLASS1_ALARM << VSCP_CLASS1_SECURITY << VSCP_CLASS1_MEASUREMENT
                  << VSCP_CLASS1_DATA << VSCP_CLASS1_INFORMATION << VSCP_CLASS1_CONTROL << VSCP_CLASS1_MULTIMEDIA
                  << VSCP_CLASS1_AOL << VSCP_CLASS1_MEASUREMENT64 << VSCP_CLASS1_MEASUREZONE << VSCP_CLASS1_MEASUREMENT32
                  << VSCP_CLASS1_SETVALUEZONE << VSCP_CLASS1_PHONE << VSCP_CLASS1_LIN << VSCP_CLASS1_DISPLAY
                  << VSCP_CLASS1_RC5 << VSCP_CLASS1_ONEWIRE << VSCP_CLASS1_X10 << VSCP_CLASS1_LON
                  << VSCP_CLASS1_EIB << VSCP_CLASS1_SNAP << VSCP_CLASS1_MUMIN << VSCP_CLASS1_LOG
                  << VSCP_CLASS1_LAB << VSCP_CLASS1_LOCAL

                  << VSCP_CLASS2_LEVEL1_PROTOCOL << VSCP_CLASS2_LEVEL1_ALARM << VSCP_CLASS2_LEVEL1_SECURITY
                  << VSCP_CLASS2_LEVEL1_MEASUREMENT << VSCP_CLASS2_LEVEL1_DATA << VSCP_CLASS2_LEVEL1_INFORMATION
                  << VSCP_CLASS2_LEVEL1_CONTROL << VSCP_CLASS2_LEVEL1_MULTIMEDIA << VSCP_CLASS2_LEVEL1_AOL
                  << VSCP_CLASS2_MEASUREMENT64 << VSCP_CLASS2_MEASUREZONE << VSCP_CLASS2_MEASUREMENT32
                  << VSCP_CLASS2_SETVALUEZONE << VSCP_CLASS2_LEVEL1_PHONE << VSCP_CLASS2_LEVEL1_LIN
                  << VSCP_CLASS2_LEVEL1_RC5 << VSCP_CLASS2_LEVEL1_ONEWIRE << VSCP_CLASS2_LEVEL1_X10
                  << VSCP_CLASS2_LEVEL1_LON << VSCP_CLASS2_LEVEL1_EIB << VSCP_CLASS2_LEVEL1_SNAP
                  << VSCP_CLASS2_LEVEL1_MUMIN << VSCP_CLASS2_LEVEL1_LOG << VSCP_CLASS2_LEVEL1_LAB
                  << VSCP_CLASS2_LEVEL1_LOCAL

                  << VSCP_CLASS2_PROTOCOL << VSCP_CLASS2_CONTROL << VSCP_CLASS2_INFORMATION
                  << VSCP_CLASS2_TEXT2SPEECH << VSCP_CLASS2_CUSTOM << VSCP_CLASS2_DISPLAY
                  << VSCP_CLASS2_MEASUREMENT_STR << VSCP_CLASS2_VSCPD
                     ;*/

    listClass << VSCP_CLASS1_INFORMATION << VSCP_CLASS1_CONTROL ;

    listType   << VSCP_TYPE_INFORMATION_GENERAL << VSCP_TYPE_INFORMATION_BUTTON << VSCP_TYPE_INFORMATION_MOUSE
              << VSCP_TYPE_INFORMATION_ON << VSCP_TYPE_INFORMATION_OFF << VSCP_TYPE_INFORMATION_ALIVE
              << VSCP_TYPE_INFORMATION_TERMINATING << VSCP_TYPE_INFORMATION_OPENED << VSCP_TYPE_INFORMATION_CLOSED
              << VSCP_TYPE_INFORMATION_NODE_HEARTBEAT << VSCP_TYPE_INFORMATION_BELOW_LIMIT << VSCP_TYPE_INFORMATION_ABOVE_LIMIT
              << VSCP_TYPE_INFORMATION_PULSE << VSCP_TYPE_INFORMATION_ERROR << VSCP_TYPE_INFORMATION_RESUMED
              << VSCP_TYPE_INFORMATION_PAUSED << VSCP_TYPE_INFORMATION_SLEEP << VSCP_TYPE_INFORMATION_GOOD_MORNING
              << VSCP_TYPE_INFORMATION_GOOD_DAY << VSCP_TYPE_INFORMATION_GOOD_AFTERNOON
              << VSCP_TYPE_INFORMATION_GOOD_EVENING << VSCP_TYPE_INFORMATION_GOOD_NIGHT
              << VSCP_TYPE_INFORMATION_SEE_YOU_SOON << VSCP_TYPE_INFORMATION_GOODBYE << VSCP_TYPE_INFORMATION_STOP
              << VSCP_TYPE_INFORMATION_START << VSCP_TYPE_INFORMATION_RESET_COMPLETED << VSCP_TYPE_INFORMATION_INTERRUPTED
              << VSCP_TYPE_INFORMATION_PREPARING_TO_SLEEP << VSCP_TYPE_INFORMATION_WOKEN_UP << VSCP_TYPE_INFORMATION_DUSK
              << VSCP_TYPE_INFORMATION_DAWN  << VSCP_TYPE_INFORMATION_ACTIVE  << VSCP_TYPE_INFORMATION_INACTIVE << VSCP_TYPE_INFORMATION_BUSY
              << VSCP_TYPE_INFORMATION_IDLE << VSCP_TYPE_INFORMATION_STREAM_DATA << VSCP_TYPE_INFORMATION_TOKEN_ACTIVITY
              << VSCP_TYPE_INFORMATION_STREAM_DATA_WITH_ZONE << VSCP_TYPE_INFORMATION_CONFIRM << VSCP_TYPE_INFORMATION_LEVEL_CHANGED
              << VSCP_TYPE_INFORMATION_WARNING << VSCP_TYPE_INFORMATION_STATE << VSCP_TYPE_INFORMATION_ACTION_TRIGGER
              << VSCP_TYPE_INFORMATION_SUNRISE << VSCP_TYPE_INFORMATION_SUNSET << VSCP_TYPE_INFORMATION_START_OF_RECORD
              << VSCP_TYPE_INFORMATION_END_OF_RECORD << VSCP_TYPE_INFORMATION_PRESET_ACTIVE << VSCP_TYPE_INFORMATION_DETECT
              << VSCP_TYPE_INFORMATION_OVERFLOW << VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED
                 ;

    listPriority << VSCP_PRIORITY7 << VSCP_PRIORITY6 << VSCP_PRIORITY5 << VSCP_PRIORITY4 << VSCP_PRIORITY3
                 << VSCP_PRIORITY2 << VSCP_PRIORITY1 << VSCP_PRIORITY0 ;

    listAction << VSCP_DAEMON_ACTION_CODE_NOOP << VSCP_DAEMON_ACTION_CODE_EXECUTE << VSCP_DAEMON_ACTION_INTERNAL_PROCEDURE_EXECUTE
               << VSCP_DAEMON_ACTION_CODE_EXECUTE_METHOD << VSCP_DAEMON_ACTION_CODE_SEND_EVENT
               << VSCP_DAEMON_ACTION_CODE_SEND_EVENT_CONDITIONAL << VSCP_DAEMON_ACTION_CODE_SEND_EVENTS_FROM_FILE << VSCP_DAEMON_ACTION_CODE_SEND_TO_REMOTE
               << VSCP_DAEMON_ACTION_CODE_STORE_VARIABLE << VSCP_DAEMON_ACTION_CODE_STORE_ARRAY << VSCP_DAEMON_ACTION_CODE_ADD_VARIABLE
               << VSCP_DAEMON_ACTION_CODE_SUBTRACT_VARIABLE << VSCP_DAEMON_ACTION_CODE_MULTIPLY_VARIABLE << VSCP_DAEMON_ACTION_CODE_DIVIDE_VARIABLE
               << VSCP_DAEMON_ACTION_CODE_START_TIMER << VSCP_DAEMON_ACTION_CODE_PAUSE_TIMER << VSCP_DAEMON_ACTION_CODE_STOP_TIMER
               << VSCP_DAEMON_ACTION_CODE_RESUME_TIMER << VSCP_DAEMON_ACTION_CODE_WRITE_FILE << VSCP_DAEMON_ACTION_CODE_GET_PUT_POST_URL
                  ;
}


/*
void WidgetWebsocketPacketSwitch::txOnClassListWidgetcurrentItemChanged_slot()
{
   / *QMessageBox *msgBox 	= new QMessageBox();
   msgBox->setText("Item changed .... >>>> ");
    msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
    msgBox->exec();* /
    if(ui->txOnClassListWidget->currentItem()->text() == VSCP_CLASS1_INFORMATION)
    {
        ui->txOnTypeListWidget->clear();
        listType.clear();
        listType   << VSCP_TYPE_INFORMATION_GENERAL << VSCP_TYPE_INFORMATION_BUTTON << VSCP_TYPE_INFORMATION_MOUSE
                  << VSCP_TYPE_INFORMATION_ON << VSCP_TYPE_INFORMATION_OFF << VSCP_TYPE_INFORMATION_ALIVE
                  << VSCP_TYPE_INFORMATION_TERMINATING << VSCP_TYPE_INFORMATION_OPENED << VSCP_TYPE_INFORMATION_CLOSED
                  << VSCP_TYPE_INFORMATION_NODE_HEARTBEAT << VSCP_TYPE_INFORMATION_BELOW_LIMIT << VSCP_TYPE_INFORMATION_ABOVE_LIMIT
                  << VSCP_TYPE_INFORMATION_PULSE << VSCP_TYPE_INFORMATION_ERROR << VSCP_TYPE_INFORMATION_RESUMED
                  << VSCP_TYPE_INFORMATION_PAUSED << VSCP_TYPE_INFORMATION_SLEEP << VSCP_TYPE_INFORMATION_GOOD_MORNING
                  << VSCP_TYPE_INFORMATION_GOOD_DAY << VSCP_TYPE_INFORMATION_GOOD_AFTERNOON
                  << VSCP_TYPE_INFORMATION_GOOD_EVENING << VSCP_TYPE_INFORMATION_GOOD_NIGHT
                  << VSCP_TYPE_INFORMATION_SEE_YOU_SOON << VSCP_TYPE_INFORMATION_GOODBYE << VSCP_TYPE_INFORMATION_STOP
                  << VSCP_TYPE_INFORMATION_START << VSCP_TYPE_INFORMATION_RESET_COMPLETED << VSCP_TYPE_INFORMATION_INTERRUPTED
                  << VSCP_TYPE_INFORMATION_PREPARING_TO_SLEEP << VSCP_TYPE_INFORMATION_WOKEN_UP << VSCP_TYPE_INFORMATION_DUSK
                  << VSCP_TYPE_INFORMATION_DAWN  << VSCP_TYPE_INFORMATION_ACTIVE << VSCP_TYPE_INFORMATION_INACTIVE << VSCP_TYPE_INFORMATION_BUSY
                  << VSCP_TYPE_INFORMATION_IDLE << VSCP_TYPE_INFORMATION_STREAM_DATA << VSCP_TYPE_INFORMATION_TOKEN_ACTIVITY
                  << VSCP_TYPE_INFORMATION_STREAM_DATA_WITH_ZONE << VSCP_TYPE_INFORMATION_CONFIRM << VSCP_TYPE_INFORMATION_LEVEL_CHANGED
                  << VSCP_TYPE_INFORMATION_WARNING << VSCP_TYPE_INFORMATION_STATE << VSCP_TYPE_INFORMATION_ACTION_TRIGGER
                  << VSCP_TYPE_INFORMATION_SUNRISE << VSCP_TYPE_INFORMATION_SUNSET << VSCP_TYPE_INFORMATION_START_OF_RECORD
                  << VSCP_TYPE_INFORMATION_END_OF_RECORD << VSCP_TYPE_INFORMATION_PRESET_ACTIVE << VSCP_TYPE_INFORMATION_DETECT
                  << VSCP_TYPE_INFORMATION_OVERFLOW << VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED
                     ;
        // Add item
        for(int i=0; i< listType.size() ; i++)
        {
            ui->txOnTypeListWidget->addItem(listType.at(i));
        }
        ui->txOnTypeListWidget->setCurrentRow(0);

    }
    else if(ui->txOnClassListWidget->currentItem()->text() == VSCP_CLASS1_CONTROL)
    {
        ui->txOnTypeListWidget->clear();
        listType.clear();
        listType   << VSCP_TYPE_CONTROL_GENERAL << VSCP_TYPE_CONTROL_MUTE << VSCP_TYPE_CONTROL_ALL_LAMPS
                  << VSCP_TYPE_CONTROL_OPEN << VSCP_TYPE_CONTROL_CLOSE << VSCP_TYPE_CONTROL_TURNON
                  << VSCP_TYPE_CONTROL_TURNOFF << VSCP_TYPE_CONTROL_START << VSCP_TYPE_CONTROL_STOP
                  << VSCP_TYPE_CONTROL_RESET << VSCP_TYPE_CONTROL_INTERRUPT << VSCP_TYPE_CONTROL_SLEEP
                  << VSCP_TYPE_CONTROL_WAKEUP << VSCP_TYPE_CONTROL_RESUME << VSCP_TYPE_CONTROL_PAUSE
                  << VSCP_TYPE_CONTROL_ACTIVATE << VSCP_TYPE_CONTROL_DEACTIVATE << VSCP_TYPE_CONTROL_DIM_LAMPS
                  << VSCP_TYPE_CONTROL_CHANGE_CHANNEL << VSCP_TYPE_CONTROL_CHANGE_LEVEL << VSCP_TYPE_CONTROL_RELATIVE_CHANGE_LEVEL
                  << VSCP_TYPE_CONTROL_MEASUREMENT_REQUEST << VSCP_TYPE_CONTROL_STREAM_DATA << VSCP_TYPE_CONTROL_SYNC
                  << VSCP_TYPE_CONTROL_ZONED_STREAM_DATA << VSCP_TYPE_CONTROL_SET_PRESET << VSCP_TYPE_CONTROL_TOGGLE_STATE
                  << VSCP_TYPE_CONTROL_TIMED_PULE_ON << VSCP_TYPE_CONTROL_TIMED_PULSE_OFF << VSCP_TYPE_CONTROL_SET_COUNTRY_LANGUAGE
                  << VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL
                     ;
        // Add item
        for(int i=0; i< listType.size() ; i++)
        {
            ui->txOnTypeListWidget->addItem(listType.at(i));
        }
        ui->txOnTypeListWidget->setCurrentRow(0);

    }
    else{
        // do nothing
    }

}

void WidgetWebsocketPacketSwitch::txOffClassListWidgetcurrentItemChanged_slot()
{
    / *QMessageBox *msgBox 	= new QMessageBox();
    msgBox->setText("Item changed .... >>>> ");
     msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
     msgBox->exec();* /
     if(ui->txOffClassListWidget->currentItem()->text() == VSCP_CLASS1_INFORMATION)
     {
         ui->txOffTypeListWidget->clear();
         listType.clear();
         listType   << VSCP_TYPE_INFORMATION_GENERAL << VSCP_TYPE_INFORMATION_BUTTON << VSCP_TYPE_INFORMATION_MOUSE
                   << VSCP_TYPE_INFORMATION_ON << VSCP_TYPE_INFORMATION_OFF << VSCP_TYPE_INFORMATION_ALIVE
                   << VSCP_TYPE_INFORMATION_TERMINATING << VSCP_TYPE_INFORMATION_OPENED << VSCP_TYPE_INFORMATION_CLOSED
                   << VSCP_TYPE_INFORMATION_NODE_HEARTBEAT << VSCP_TYPE_INFORMATION_BELOW_LIMIT << VSCP_TYPE_INFORMATION_ABOVE_LIMIT
                   << VSCP_TYPE_INFORMATION_PULSE << VSCP_TYPE_INFORMATION_ERROR << VSCP_TYPE_INFORMATION_RESUMED
                   << VSCP_TYPE_INFORMATION_PAUSED << VSCP_TYPE_INFORMATION_SLEEP << VSCP_TYPE_INFORMATION_GOOD_MORNING
                   << VSCP_TYPE_INFORMATION_GOOD_DAY << VSCP_TYPE_INFORMATION_GOOD_AFTERNOON
                   << VSCP_TYPE_INFORMATION_GOOD_EVENING << VSCP_TYPE_INFORMATION_GOOD_NIGHT
                   << VSCP_TYPE_INFORMATION_SEE_YOU_SOON << VSCP_TYPE_INFORMATION_GOODBYE << VSCP_TYPE_INFORMATION_STOP
                   << VSCP_TYPE_INFORMATION_START << VSCP_TYPE_INFORMATION_RESET_COMPLETED << VSCP_TYPE_INFORMATION_INTERRUPTED
                   << VSCP_TYPE_INFORMATION_PREPARING_TO_SLEEP << VSCP_TYPE_INFORMATION_WOKEN_UP << VSCP_TYPE_INFORMATION_DUSK
                   << VSCP_TYPE_INFORMATION_DAWN << VSCP_TYPE_INFORMATION_ACTIVE  << VSCP_TYPE_INFORMATION_INACTIVE << VSCP_TYPE_INFORMATION_BUSY
                   << VSCP_TYPE_INFORMATION_IDLE << VSCP_TYPE_INFORMATION_STREAM_DATA << VSCP_TYPE_INFORMATION_TOKEN_ACTIVITY
                   << VSCP_TYPE_INFORMATION_STREAM_DATA_WITH_ZONE << VSCP_TYPE_INFORMATION_CONFIRM << VSCP_TYPE_INFORMATION_LEVEL_CHANGED
                   << VSCP_TYPE_INFORMATION_WARNING << VSCP_TYPE_INFORMATION_STATE << VSCP_TYPE_INFORMATION_ACTION_TRIGGER
                   << VSCP_TYPE_INFORMATION_SUNRISE << VSCP_TYPE_INFORMATION_SUNSET << VSCP_TYPE_INFORMATION_START_OF_RECORD
                   << VSCP_TYPE_INFORMATION_END_OF_RECORD << VSCP_TYPE_INFORMATION_PRESET_ACTIVE << VSCP_TYPE_INFORMATION_DETECT
                   << VSCP_TYPE_INFORMATION_OVERFLOW << VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED
                      ;
         // Add item
         for(int i=0; i< listType.size() ; i++)
         {
             ui->txOffTypeListWidget->addItem(listType.at(i));
         }
         ui->txOffTypeListWidget->setCurrentRow(0);

     }
     else if(ui->txOffClassListWidget->currentItem()->text() == VSCP_CLASS1_CONTROL)
     {
         ui->txOffTypeListWidget->clear();
         listType.clear();
         listType   << VSCP_TYPE_CONTROL_GENERAL << VSCP_TYPE_CONTROL_MUTE << VSCP_TYPE_CONTROL_ALL_LAMPS
                   << VSCP_TYPE_CONTROL_OPEN << VSCP_TYPE_CONTROL_CLOSE << VSCP_TYPE_CONTROL_TURNON
                   << VSCP_TYPE_CONTROL_TURNOFF << VSCP_TYPE_CONTROL_START << VSCP_TYPE_CONTROL_STOP
                   << VSCP_TYPE_CONTROL_RESET << VSCP_TYPE_CONTROL_INTERRUPT << VSCP_TYPE_CONTROL_SLEEP
                   << VSCP_TYPE_CONTROL_WAKEUP << VSCP_TYPE_CONTROL_RESUME << VSCP_TYPE_CONTROL_PAUSE
                   << VSCP_TYPE_CONTROL_ACTIVATE << VSCP_TYPE_CONTROL_DEACTIVATE << VSCP_TYPE_CONTROL_DIM_LAMPS
                   << VSCP_TYPE_CONTROL_CHANGE_CHANNEL << VSCP_TYPE_CONTROL_CHANGE_LEVEL << VSCP_TYPE_CONTROL_RELATIVE_CHANGE_LEVEL
                   << VSCP_TYPE_CONTROL_MEASUREMENT_REQUEST << VSCP_TYPE_CONTROL_STREAM_DATA << VSCP_TYPE_CONTROL_SYNC
                   << VSCP_TYPE_CONTROL_ZONED_STREAM_DATA << VSCP_TYPE_CONTROL_SET_PRESET << VSCP_TYPE_CONTROL_TOGGLE_STATE
                   << VSCP_TYPE_CONTROL_TIMED_PULE_ON << VSCP_TYPE_CONTROL_TIMED_PULSE_OFF << VSCP_TYPE_CONTROL_SET_COUNTRY_LANGUAGE
                   << VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL
                      ;
         // Add item
         for(int i=0; i< listType.size() ; i++)
         {
             ui->txOffTypeListWidget->addItem(listType.at(i));
         }
         ui->txOffTypeListWidget->setCurrentRow(0);

     }
     else{
         // do nothing
     }

}

void WidgetWebsocketPacketSwitch::rxOnClassListWidgetcurrentItemChanged_slot()
{
    / *QMessageBox *msgBox 	= new QMessageBox();
    msgBox->setText("Item changed .... >>>> ");
     msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
     msgBox->exec();* /
     if(ui->rxOnClassListWidget->currentItem()->text() == VSCP_CLASS1_INFORMATION)
     {
         ui->rxOnTypeListWidget->clear();
         listType.clear();
         listType   << VSCP_TYPE_INFORMATION_GENERAL << VSCP_TYPE_INFORMATION_BUTTON << VSCP_TYPE_INFORMATION_MOUSE
                   << VSCP_TYPE_INFORMATION_ON << VSCP_TYPE_INFORMATION_OFF << VSCP_TYPE_INFORMATION_ALIVE
                   << VSCP_TYPE_INFORMATION_TERMINATING << VSCP_TYPE_INFORMATION_OPENED << VSCP_TYPE_INFORMATION_CLOSED
                   << VSCP_TYPE_INFORMATION_NODE_HEARTBEAT << VSCP_TYPE_INFORMATION_BELOW_LIMIT << VSCP_TYPE_INFORMATION_ABOVE_LIMIT
                   << VSCP_TYPE_INFORMATION_PULSE << VSCP_TYPE_INFORMATION_ERROR << VSCP_TYPE_INFORMATION_RESUMED
                   << VSCP_TYPE_INFORMATION_PAUSED << VSCP_TYPE_INFORMATION_SLEEP << VSCP_TYPE_INFORMATION_GOOD_MORNING
                   << VSCP_TYPE_INFORMATION_GOOD_DAY << VSCP_TYPE_INFORMATION_GOOD_AFTERNOON
                   << VSCP_TYPE_INFORMATION_GOOD_EVENING << VSCP_TYPE_INFORMATION_GOOD_NIGHT
                   << VSCP_TYPE_INFORMATION_SEE_YOU_SOON << VSCP_TYPE_INFORMATION_GOODBYE << VSCP_TYPE_INFORMATION_STOP
                   << VSCP_TYPE_INFORMATION_START << VSCP_TYPE_INFORMATION_RESET_COMPLETED << VSCP_TYPE_INFORMATION_INTERRUPTED
                   << VSCP_TYPE_INFORMATION_PREPARING_TO_SLEEP << VSCP_TYPE_INFORMATION_WOKEN_UP << VSCP_TYPE_INFORMATION_DUSK
                   << VSCP_TYPE_INFORMATION_DAWN  << VSCP_TYPE_INFORMATION_ACTIVE  << VSCP_TYPE_INFORMATION_INACTIVE << VSCP_TYPE_INFORMATION_BUSY
                   << VSCP_TYPE_INFORMATION_IDLE << VSCP_TYPE_INFORMATION_STREAM_DATA << VSCP_TYPE_INFORMATION_TOKEN_ACTIVITY
                   << VSCP_TYPE_INFORMATION_STREAM_DATA_WITH_ZONE << VSCP_TYPE_INFORMATION_CONFIRM << VSCP_TYPE_INFORMATION_LEVEL_CHANGED
                   << VSCP_TYPE_INFORMATION_WARNING << VSCP_TYPE_INFORMATION_STATE << VSCP_TYPE_INFORMATION_ACTION_TRIGGER
                   << VSCP_TYPE_INFORMATION_SUNRISE << VSCP_TYPE_INFORMATION_SUNSET << VSCP_TYPE_INFORMATION_START_OF_RECORD
                   << VSCP_TYPE_INFORMATION_END_OF_RECORD << VSCP_TYPE_INFORMATION_PRESET_ACTIVE << VSCP_TYPE_INFORMATION_DETECT
                   << VSCP_TYPE_INFORMATION_OVERFLOW << VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED
                      ;
         // Add item
         for(int i=0; i< listType.size() ; i++)
         {
             ui->rxOnTypeListWidget->addItem(listType.at(i));
         }
         ui->rxOnTypeListWidget->setCurrentRow(0);

     }
     else if(ui->rxOnClassListWidget->currentItem()->text() == VSCP_CLASS1_CONTROL)
     {
         ui->rxOnTypeListWidget->clear();
         listType.clear();
         listType   << VSCP_TYPE_CONTROL_GENERAL << VSCP_TYPE_CONTROL_MUTE << VSCP_TYPE_CONTROL_ALL_LAMPS
                   << VSCP_TYPE_CONTROL_OPEN << VSCP_TYPE_CONTROL_CLOSE << VSCP_TYPE_CONTROL_TURNON
                   << VSCP_TYPE_CONTROL_TURNOFF << VSCP_TYPE_CONTROL_START << VSCP_TYPE_CONTROL_STOP
                   << VSCP_TYPE_CONTROL_RESET << VSCP_TYPE_CONTROL_INTERRUPT << VSCP_TYPE_CONTROL_SLEEP
                   << VSCP_TYPE_CONTROL_WAKEUP << VSCP_TYPE_CONTROL_RESUME << VSCP_TYPE_CONTROL_PAUSE
                   << VSCP_TYPE_CONTROL_ACTIVATE << VSCP_TYPE_CONTROL_DEACTIVATE << VSCP_TYPE_CONTROL_DIM_LAMPS
                   << VSCP_TYPE_CONTROL_CHANGE_CHANNEL << VSCP_TYPE_CONTROL_CHANGE_LEVEL << VSCP_TYPE_CONTROL_RELATIVE_CHANGE_LEVEL
                   << VSCP_TYPE_CONTROL_MEASUREMENT_REQUEST << VSCP_TYPE_CONTROL_STREAM_DATA << VSCP_TYPE_CONTROL_SYNC
                   << VSCP_TYPE_CONTROL_ZONED_STREAM_DATA << VSCP_TYPE_CONTROL_SET_PRESET << VSCP_TYPE_CONTROL_TOGGLE_STATE
                   << VSCP_TYPE_CONTROL_TIMED_PULE_ON << VSCP_TYPE_CONTROL_TIMED_PULSE_OFF << VSCP_TYPE_CONTROL_SET_COUNTRY_LANGUAGE
                   << VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL
                      ;
         // Add item
         for(int i=0; i< listType.size() ; i++)
         {
             ui->rxOnTypeListWidget->addItem(listType.at(i));
         }
         ui->rxOnTypeListWidget->setCurrentRow(0);

     }
     else{
         // do nothing
     }

}

void WidgetWebsocketPacketSwitch::rxOffClassListWidgetcurrentItemChanged_slot()
{
    / *QMessageBox *msgBox 	= new QMessageBox();
    msgBox->setText("Item changed .... >>>> ");
     msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
     msgBox->exec();* /
     if(ui->rxOffClassListWidget->currentItem()->text() == VSCP_CLASS1_INFORMATION)
     {
         ui->rxOffTypeListWidget->clear();
         listType.clear();
         listType   << VSCP_TYPE_INFORMATION_GENERAL << VSCP_TYPE_INFORMATION_BUTTON << VSCP_TYPE_INFORMATION_MOUSE
                   << VSCP_TYPE_INFORMATION_ON << VSCP_TYPE_INFORMATION_OFF << VSCP_TYPE_INFORMATION_ALIVE
                   << VSCP_TYPE_INFORMATION_TERMINATING << VSCP_TYPE_INFORMATION_OPENED << VSCP_TYPE_INFORMATION_CLOSED
                   << VSCP_TYPE_INFORMATION_NODE_HEARTBEAT << VSCP_TYPE_INFORMATION_BELOW_LIMIT << VSCP_TYPE_INFORMATION_ABOVE_LIMIT
                   << VSCP_TYPE_INFORMATION_PULSE << VSCP_TYPE_INFORMATION_ERROR << VSCP_TYPE_INFORMATION_RESUMED
                   << VSCP_TYPE_INFORMATION_PAUSED << VSCP_TYPE_INFORMATION_SLEEP << VSCP_TYPE_INFORMATION_GOOD_MORNING
                   << VSCP_TYPE_INFORMATION_GOOD_DAY << VSCP_TYPE_INFORMATION_GOOD_AFTERNOON
                   << VSCP_TYPE_INFORMATION_GOOD_EVENING << VSCP_TYPE_INFORMATION_GOOD_NIGHT
                   << VSCP_TYPE_INFORMATION_SEE_YOU_SOON << VSCP_TYPE_INFORMATION_GOODBYE << VSCP_TYPE_INFORMATION_STOP
                   << VSCP_TYPE_INFORMATION_START << VSCP_TYPE_INFORMATION_RESET_COMPLETED << VSCP_TYPE_INFORMATION_INTERRUPTED
                   << VSCP_TYPE_INFORMATION_PREPARING_TO_SLEEP << VSCP_TYPE_INFORMATION_WOKEN_UP << VSCP_TYPE_INFORMATION_DUSK
                   << VSCP_TYPE_INFORMATION_DAWN  << VSCP_TYPE_INFORMATION_ACTIVE << VSCP_TYPE_INFORMATION_INACTIVE << VSCP_TYPE_INFORMATION_BUSY
                   << VSCP_TYPE_INFORMATION_IDLE << VSCP_TYPE_INFORMATION_STREAM_DATA << VSCP_TYPE_INFORMATION_TOKEN_ACTIVITY
                   << VSCP_TYPE_INFORMATION_STREAM_DATA_WITH_ZONE << VSCP_TYPE_INFORMATION_CONFIRM << VSCP_TYPE_INFORMATION_LEVEL_CHANGED
                   << VSCP_TYPE_INFORMATION_WARNING << VSCP_TYPE_INFORMATION_STATE << VSCP_TYPE_INFORMATION_ACTION_TRIGGER
                   << VSCP_TYPE_INFORMATION_SUNRISE << VSCP_TYPE_INFORMATION_SUNSET << VSCP_TYPE_INFORMATION_START_OF_RECORD
                   << VSCP_TYPE_INFORMATION_END_OF_RECORD << VSCP_TYPE_INFORMATION_PRESET_ACTIVE << VSCP_TYPE_INFORMATION_DETECT
                   << VSCP_TYPE_INFORMATION_OVERFLOW << VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED
                      ;
         // Add item
         for(int i=0; i< listType.size() ; i++)
         {
             ui->rxOffTypeListWidget->addItem(listType.at(i));
         }
         ui->rxOffTypeListWidget->setCurrentRow(0);

     }
     else if(ui->rxOffClassListWidget->currentItem()->text() == VSCP_CLASS1_CONTROL)
     {
         ui->rxOffTypeListWidget->clear();
         listType.clear();
         listType   << VSCP_TYPE_CONTROL_GENERAL << VSCP_TYPE_CONTROL_MUTE << VSCP_TYPE_CONTROL_ALL_LAMPS
                   << VSCP_TYPE_CONTROL_OPEN << VSCP_TYPE_CONTROL_CLOSE << VSCP_TYPE_CONTROL_TURNON
                   << VSCP_TYPE_CONTROL_TURNOFF << VSCP_TYPE_CONTROL_START << VSCP_TYPE_CONTROL_STOP
                   << VSCP_TYPE_CONTROL_RESET << VSCP_TYPE_CONTROL_INTERRUPT << VSCP_TYPE_CONTROL_SLEEP
                   << VSCP_TYPE_CONTROL_WAKEUP << VSCP_TYPE_CONTROL_RESUME << VSCP_TYPE_CONTROL_PAUSE
                   << VSCP_TYPE_CONTROL_ACTIVATE << VSCP_TYPE_CONTROL_DEACTIVATE << VSCP_TYPE_CONTROL_DIM_LAMPS
                   << VSCP_TYPE_CONTROL_CHANGE_CHANNEL << VSCP_TYPE_CONTROL_CHANGE_LEVEL << VSCP_TYPE_CONTROL_RELATIVE_CHANGE_LEVEL
                   << VSCP_TYPE_CONTROL_MEASUREMENT_REQUEST << VSCP_TYPE_CONTROL_STREAM_DATA << VSCP_TYPE_CONTROL_SYNC
                   << VSCP_TYPE_CONTROL_ZONED_STREAM_DATA << VSCP_TYPE_CONTROL_SET_PRESET << VSCP_TYPE_CONTROL_TOGGLE_STATE
                   << VSCP_TYPE_CONTROL_TIMED_PULE_ON << VSCP_TYPE_CONTROL_TIMED_PULSE_OFF << VSCP_TYPE_CONTROL_SET_COUNTRY_LANGUAGE
                   << VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL
                      ;
         // Add item
         for(int i=0; i< listType.size() ; i++)
         {
             ui->rxOffTypeListWidget->addItem(listType.at(i));
         }
         ui->rxOffTypeListWidget->setCurrentRow(0);

     }
     else{
         // do nothing
     }

}
*/
//Copy switch packet to Dialog
void WidgetWebsocketPacketSwitch::CopySwitchPacket()
{
    //QString action;
    //QString tempString;
    //QString parameterStringValue;
    //int classIndex = 0;
    //int typeIndex = 0;
    //int actionval;
    //websocket
    //ui->idValueLabel->setText(switchPacket_modify.id);
    ui->urlLineEdit->setText(switchPacket_modify.url);
    ui->bLocalListWidget->setCurrentRow(switchPacket_modify.bLocal.toInt());
    ui->bNoStateListWidget->setCurrentRow(switchPacket_modify.bNoState.toInt());
    ui->usernameLineEdit->setText(switchPacket_modify.userName);
    ui->passwordLineEdit->setText(switchPacket_modify.passWord);
    //domain should be fixed for this release
    ui->domainLineEdit->setText("mydomain.com");
    //set for the -- remote node
    ui->guidLineEdit->setText(switchPacket_modify.rxOnEvent.guid);
    ui->indexLineEdit->setText(switchPacket_modify.rxOnEvent.index);
    ui->zoneLineEdit->setText(switchPacket_modify.rxOnEvent.zone);
    ui->subZoneLineEdit->setText(switchPacket_modify.rxOnEvent.subzone);

    /*
    //Tx ON event
    tempString = switchPacket_modify.txOnEvent.class_value;
    if(tempString == VSCP_CLASS1_INFORMATION_VALUE)
    {
        classIndex = 0; //information
        tempString = switchPacket_modify.txOnEvent.type_value;
        typeIndex = ClassTypeObject.getInformationTypeListIndex(tempString);
    }
    else if(tempString == VSCP_CLASS1_CONTROL_VALUE)
    {
        classIndex = 1; //control
        tempString = switchPacket_modify.txOnEvent.type_value;
        typeIndex = ClassTypeObject.getControlTypeListIndex(tempString);
    }
    else
    {
        // Do nothing
    }
    ui->txOnClassListWidget->setCurrentRow(classIndex);
       // set the value of the type list
        txOnClassListWidgetcurrentItemChanged_slot();
    ui->txOnTypeListWidget->setCurrentRow(typeIndex);
    ui->txOnGuidLineEdit->setText(switchPacket_modify.txOnEvent.guid);
    ui->txOnIndexLineEdit->setText(switchPacket_modify.txOnEvent.index);
    ui->txOnZoneLineEdit->setText(switchPacket_modify.txOnEvent.zone);
    ui->txOnSubZoneLineEdit->setText(switchPacket_modify.txOnEvent.subzone);
    ui->txOnHeadLineEdit->setText(switchPacket_modify.txOnEvent.head);
    ui->txOnObidLineEdit->setText(switchPacket_modify.txOnEvent.obid);
    ui->txOnTimeStampLineEdit->setText(switchPacket_modify.txOnEvent.timeStamp);
    ui->txOnDataLineEdit->setText(switchPacket_modify.txOnEvent.data);

    //Tx Off event
    tempString = switchPacket_modify.txOffEvent.class_value;
    if(tempString == VSCP_CLASS1_INFORMATION_VALUE)
    {
        classIndex = 0; //information
        tempString = switchPacket_modify.txOffEvent.type_value;
        typeIndex = ClassTypeObject.getInformationTypeListIndex(tempString);
    }
    else if(tempString == VSCP_CLASS1_CONTROL_VALUE)
    {
        classIndex = 1; //information
        tempString = switchPacket_modify.txOffEvent.type_value;
        typeIndex = ClassTypeObject.getControlTypeListIndex(tempString);
    }
    else
    {
        // Do nothing
    }
    ui->txOffClassListWidget->setCurrentRow(classIndex);
        // set the value of the type list
    txOffClassListWidgetcurrentItemChanged_slot();
    ui->txOffTypeListWidget->setCurrentRow(typeIndex);
    ui->txOffGuidLineEdit->setText(switchPacket_modify.txOffEvent.guid);
    ui->txOffIndexLineEdit->setText(switchPacket_modify.txOffEvent.index);
    ui->txOffZoneLineEdit->setText(switchPacket_modify.txOffEvent.zone);
    ui->txOffSubZoneLineEdit->setText(switchPacket_modify.txOffEvent.subzone);
    ui->txOffHeadLineEdit->setText(switchPacket_modify.txOffEvent.head);
    ui->txOffObidLineEdit->setText(switchPacket_modify.txOffEvent.obid);
    ui->txOffTimeStampLineEdit->setText(switchPacket_modify.txOffEvent.timeStamp);
    ui->txOffDataLineEdit->setText(switchPacket_modify.txOffEvent.data);

    //Rx ON event
    tempString = switchPacket_modify.rxOnEvent.class_value;
    if(tempString == VSCP_CLASS1_INFORMATION_VALUE)
    {
        classIndex = 0; //information
        tempString = switchPacket_modify.rxOnEvent.type_value;
        typeIndex = ClassTypeObject.getInformationTypeListIndex(tempString);
    }
    else if(tempString == VSCP_CLASS1_CONTROL_VALUE)
    {
        classIndex = 1; //information
        tempString = switchPacket_modify.rxOnEvent.type_value;
        typeIndex = ClassTypeObject.getControlTypeListIndex(tempString);
    }
    else
    {
        // Do nothing
    }
    ui->rxOnClassListWidget->setCurrentRow(classIndex);
        // set the value of the type list
        rxOnClassListWidgetcurrentItemChanged_slot();
    ui->rxOnTypeListWidget->setCurrentRow(typeIndex);
    ui->rxOnGuidLineEdit->setText(switchPacket_modify.rxOnEvent.guid);
    ui->rxOnIndexLineEdit->setText(switchPacket_modify.rxOnEvent.index);
    ui->rxOnZoneLineEdit->setText(switchPacket_modify.rxOnEvent.zone);
    ui->rxOnSubZoneLineEdit->setText(switchPacket_modify.rxOnEvent.subzone);
    ui->rxOnHeadLineEdit->setText(switchPacket_modify.rxOnEvent.head);
    ui->rxOnObidLineEdit->setText(switchPacket_modify.rxOnEvent.obid);
    ui->rxOnTimeStampLineEdit->setText(switchPacket_modify.rxOnEvent.timeStamp);
    ui->rxOnDataLineEdit->setText(switchPacket_modify.rxOnEvent.data);

    //Rx Off event
    tempString = switchPacket_modify.rxOffEvent.class_value;
    if(tempString == VSCP_CLASS1_INFORMATION_VALUE)
    {
        classIndex = 0; //information
        tempString = switchPacket_modify.rxOffEvent.type_value;
        typeIndex = ClassTypeObject.getInformationTypeListIndex(tempString);
    }
    else if(tempString == VSCP_CLASS1_CONTROL_VALUE)
    {
        classIndex = 1; //information
        tempString = switchPacket_modify.rxOffEvent.type_value;
        typeIndex = ClassTypeObject.getControlTypeListIndex(tempString);
    }
    else
    {
        // Do nothing
    }
    ui->rxOffClassListWidget->setCurrentRow(classIndex);
        // set the value of the type list
        rxOffClassListWidgetcurrentItemChanged_slot();
    ui->rxOffTypeListWidget->setCurrentRow(typeIndex);
    ui->rxOffGuidLineEdit->setText(switchPacket_modify.rxOffEvent.guid);
    ui->rxOffIndexLineEdit->setText(switchPacket_modify.rxOffEvent.index);
    ui->rxOffZoneLineEdit->setText(switchPacket_modify.rxOffEvent.zone);
    ui->rxOffSubZoneLineEdit->setText(switchPacket_modify.rxOffEvent.subzone);
    ui->rxOffHeadLineEdit->setText(switchPacket_modify.rxOffEvent.head);
    ui->rxOffObidLineEdit->setText(switchPacket_modify.rxOffEvent.obid);
    ui->rxOffTimeStampLineEdit->setText(switchPacket_modify.rxOffEvent.timeStamp);
    ui->rxOffDataLineEdit->setText(switchPacket_modify.rxOffEvent.data);

    // Variable configure
    ui->variableNameValueLabel->setText(switchPacket_modify.packetSwitchVariable.name);
    ui->variableAllowedFromLineEdit->setText(switchPacket_modify.packetSwitchVariable.allowedFrom);
    ui->variableAllowedToLineEdit->setText(switchPacket_modify.packetSwitchVariable.allowedTo);
    ui->variableAllowedTimeLineEdit->setText(switchPacket_modify.packetSwitchVariable.allowedTime);
    if(switchPacket_modify.packetSwitchVariable.allowedDays.mon == "true")
    {
        ui->variableAllowedDaysMondaycheckBox->setChecked(true);
    }
    else
    {
        ui->variableAllowedDaysMondaycheckBox->setChecked(false);
    }

    if(switchPacket_modify.packetSwitchVariable.allowedDays.tue == "true")
    {
        ui->variableAllowedDaysTuesdaycheckBox->setChecked(true);
    }
    else
    {
        ui->variableAllowedDaysTuesdaycheckBox->setChecked(false);
    }

    if(switchPacket_modify.packetSwitchVariable.allowedDays.wed == "true")
    {
        ui->variableAllowedDaysWednesdaycheckBox->setChecked(true);
    }
    else
    {
        ui->variableAllowedDaysWednesdaycheckBox->setChecked(false);
    }

    if(switchPacket_modify.packetSwitchVariable.allowedDays.thur == "true")
    {
        ui->variableAllowedDaysThursdaycheckBox->setChecked(true);
    }
    else
    {
        ui->variableAllowedDaysThursdaycheckBox->setChecked(false);
    }

    if(switchPacket_modify.packetSwitchVariable.allowedDays.fri == "true")
    {
        ui->variableAllowedDaysFridaycheckBox->setChecked(true);
    }
    else
    {
        ui->variableAllowedDaysFridaycheckBox->setChecked(false);
    }

    if(switchPacket_modify.packetSwitchVariable.allowedDays.sat == "true")
    {
        ui->variableAllowedDaysSaturdaycheckBox->setChecked(true);
    }
    else
    {
        ui->variableAllowedDaysSaturdaycheckBox->setChecked(false);
    }

    if(switchPacket_modify.packetSwitchVariable.allowedDays.sun == "true")
    {
        ui->variableAllowedDaysSundaycheckBox->setChecked(true);
    }
    else
    {
        ui->variableAllowedDaysSundaycheckBox->setChecked(false);
    }
    action = switchPacket_modify.packetSwitchVariable.action;

    if(action == VSCP_DAEMON_ACTION_CODE_NOOP_VALUE)
    {
        actionval = 0;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_EXECUTE_VALUE)
    {
        actionval = 1;
    }
    else if (action == VSCP_DAEMON_ACTION_INTERNAL_PROCEDURE_EXECUTE_VALUE)
    {
        actionval = 2;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_EXECUTE_METHOD_VALUE)
    {
        actionval = 3;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_SEND_EVENT_VALUE)
    {
        actionval = 4;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_SEND_EVENT_CONDITIONAL_VALUE)
    {
        actionval = 5;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_SEND_EVENTS_FROM_FILE_VALUE)
    {
        actionval = 6;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_SEND_TO_REMOTE_VALUE)
    {
        actionval = 7;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_STORE_VARIABLE_VALUE)
    {
        actionval = 8;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_STORE_ARRAY_VALUE)
    {
        actionval = 9;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_ADD_VARIABLE_VALUE)
    {
        actionval = 10;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_SUBTRACT_VARIABLE_VALUE)
    {
        actionval = 11;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_MULTIPLY_VARIABLE_VALUE)
    {
        actionval = 12;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_DIVIDE_VARIABLE_VALUE)
    {
        actionval = 13;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_START_TIMER_VALUE)
    {
        actionval = 14;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_PAUSE_TIMER_VALUE)
    {
        actionval = 15;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_STOP_TIMER_VALUE)
    {
        actionval = 16;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_RESUME_TIMER_VALUE)
    {
        actionval = 17;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_WRITE_FILE_VALUE)
    {
        actionval = 18;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_GET_PUT_POST_URL_VALUE)
    {
        actionval = 19;
    }
    else
    {
        actionval = 0;
    }
    ui->variableActionListWidget->setCurrentRow(actionval);
    //ui->variableActionParametersLineEdit->setText(switchPacket_modify.packetSwitchVariable.actionParameters);
          parameterStringValue = switchPacket_modify.packetSwitchVariable.name + ";2;true;true";
          ui->variableActionParametersSetLineEdit->setText(parameterStringValue);
          parameterStringValue = switchPacket_modify.packetSwitchVariable.name + ";2;true;false";
          ui->variableActionParametersResetLineEdit->setText(parameterStringValue);
    ui->variableCommentsLineEdit->setText(switchPacket_modify.packetSwitchVariable.comments);

    if(switchPacket_modify.packetSwitchVariable.control.EnableRow == "true")
    {
        ui->variableControlEnableRowcheckBox->setChecked(true);

    }
    else
    {
        ui->variableControlEnableRowcheckBox->setChecked(false);
    }

    if(switchPacket_modify.packetSwitchVariable.control.checkIndex == "true")
    {
        ui->variableControlCheckIndexcheckBox->setChecked(true);
    }
    else
    {
        ui->variableControlCheckIndexcheckBox->setChecked(false);
    }

    if(switchPacket_modify.packetSwitchVariable.control.checkzone == "true")
    {
        ui->variableControlCheckZonecheckBox->setChecked(true);
    }
    else
    {
        ui->variableControlCheckZonecheckBox->setChecked(false);
    }

    if(switchPacket_modify.packetSwitchVariable.control.checkSubzone == "true")
    {
        ui->variableControlCheckSubzonecheckBox->setChecked(true);
    }
    else
    {
        ui->variableControlCheckSubzonecheckBox->setChecked(false);
    }

    if(switchPacket_modify.packetSwitchVariable.control.endScan == "true")
    {
        ui->variableControlEndScancheckBox->setChecked(true);
    }
    else
    {
        ui->variableControlEndScancheckBox->setChecked(false);
    }

    ui->variableGroupIdLineEdit->setText(switchPacket_modify.packetSwitchVariable.groupId);
    // todo --> ui->variableClassLineEdit->setText(switchPacket_modify.packetSwitchVariable.class_value);
    // todo --> ui->variableTypeLineEdit->setText(switchPacket_modify.packetSwitchVariable.type_value);
    ui->variableGuidLineEdit->setText(switchPacket_modify.packetSwitchVariable.guid);

    ui->variablePriorityListWidget->setCurrentRow(switchPacket_modify.packetSwitchVariable.priority.toInt());
    ui->variableIndexLineEdit->setText(switchPacket_modify.packetSwitchVariable.index);
    ui->variableZoneLineEdit->setText(switchPacket_modify.packetSwitchVariable.zone);
    ui->variableSubzoneLineEdit->setText(switchPacket_modify.packetSwitchVariable.subzone);
    */

}


void WidgetWebsocketPacketSwitch::on_OkPushButton_clicked()
{
    QString action;
    QString tempStringClass;
    QString tempStringType;
    QString masterGuid;
    QString masterIndex;
    QString masterZone;
    QString masterSubzone;
    //websocket
    //switchPacket_modify.id = ui->idValueLabel->text();
    switchPacket_modify.url = ui->urlLineEdit->text();
    //ui->bLocalListWidget->setCurrentRow(switchPacket_modify.bLocal.toInt());
    switchPacket_modify.bLocal = QString::number( ui->bLocalListWidget->currentRow());
    //ui->bNoStateListWidget->setCurrentRow(switchPacket_modify.bNoState.toInt());
    switchPacket_modify.bNoState = QString::number( ui->bNoStateListWidget->currentRow());
    switchPacket_modify.userName = ui->usernameLineEdit->text();
    switchPacket_modify.passWord = ui->passwordLineEdit->text();
    switchPacket_modify.domain = ui->domainLineEdit->text();
    masterGuid = ui->guidLineEdit->text();
    masterIndex = ui->indexLineEdit->text();
    masterZone = ui->zoneLineEdit->text();
    masterSubzone = ui->subZoneLineEdit->text();

    //Tx ON event
    //ui->txOnClassListWidget->setCurrentRow(switchPacket_modify.txOnEvent.class_value.toInt());
    /*if( ui->txOnClassListWidget->currentItem()->text() == VSCP_CLASS1_INFORMATION)
    {
        tempStringClass = VSCP_CLASS1_INFORMATION_VALUE;
        tempStringType = ui->txOnTypeListWidget->currentItem()->text();
        ClassTypeObject.getInformationTypeValue(tempStringType);
    }
    else if ( ui->txOnClassListWidget->currentItem()->text() == VSCP_CLASS1_CONTROL)
    {
        tempStringClass = VSCP_CLASS1_CONTROL_VALUE;
        tempStringType = ui->txOnTypeListWidget->currentItem()->text();
        ClassTypeObject.getControlTypeValue(tempStringType);
    }
    else
    {
        // Do nothing
    }*/
    tempStringClass = VSCP_CLASS1_CONTROL_VALUE;
    tempStringType = VSCP_TYPE_CONTROL_TURNON;
    ClassTypeObject.getControlTypeValue(tempStringType);
    //switchPacket_modify.txOnEvent.class_value = QString:tempStringType:number( ui->txOnClassListWidget->currentRow());
    switchPacket_modify.txOnEvent.class_value = tempStringClass;
    //ui->txOnTypeListWidget->setCurrentRow(switchPacket_modify.txOnEvent.type_value.toInt());
    switchPacket_modify.txOnEvent.type_value = tempStringType;
    switchPacket_modify.txOnEvent.guid = masterGuid;  // --> for tx -- you can set it to ""  --> to take current demon guid
    switchPacket_modify.txOnEvent.index = masterIndex;
    switchPacket_modify.txOnEvent.zone = masterZone;
    switchPacket_modify.txOnEvent.subzone = masterSubzone;
    switchPacket_modify.txOnEvent.head = "";
    switchPacket_modify.txOnEvent.obid = "";
    switchPacket_modify.txOnEvent.timeStamp = "";
    switchPacket_modify.txOnEvent.data = "";

    //Tx Off event
    //ui->txOffClassListWidget->setCurrentRow(switchPacket_modify.txOffEvent.class_value.toInt());
    //ui->txOnClassListWidget->setCurrentRow(switchPacket_modify.txOnEvent.class_value.toInt());
    /*if( ui->txOffClassListWidget->currentItem()->text() == VSCP_CLASS1_INFORMATION)
    {
        tempStringClass = VSCP_CLASS1_INFORMATION_VALUE;
        tempStringType = ui->txOffTypeListWidget->currentItem()->text();
        ClassTypeObject.getInformationTypeValue(tempStringType);
    }
    else if ( ui->txOffClassListWidget->currentItem()->text() == VSCP_CLASS1_CONTROL)
    {
        tempStringClass = VSCP_CLASS1_CONTROL_VALUE;
        tempStringType = ui->txOffTypeListWidget->currentItem()->text();
        ClassTypeObject.getControlTypeValue(tempStringType);
    }
    else
    {
        // Do nothing
    }*/
    tempStringClass = VSCP_CLASS1_CONTROL_VALUE;
    tempStringType = VSCP_TYPE_CONTROL_TURNOFF;
    ClassTypeObject.getControlTypeValue(tempStringType);
    switchPacket_modify.txOffEvent.class_value = tempStringClass;
    //ui->txOffTypeListWidget->setCurrentRow(switchPacket_modify.txOffEvent.type_value.toInt());
    switchPacket_modify.txOffEvent.type_value = tempStringType;
    switchPacket_modify.txOffEvent.guid = masterGuid;// --> for tx -- you can set it to ""  --> to take current demon guid
    switchPacket_modify.txOffEvent.index = masterIndex;
    switchPacket_modify.txOffEvent.zone = masterZone;
    switchPacket_modify.txOffEvent.subzone = masterSubzone;
    switchPacket_modify.txOffEvent.head = "";
    switchPacket_modify.txOffEvent.obid = "";
    switchPacket_modify.txOffEvent.timeStamp = "";
    switchPacket_modify.txOffEvent.data = "";

    //Rx ON event
    //ui->rxOnClassListWidget->setCurrentRow(switchPacket_modify.rxOnEvent.class_value.toInt());
    /*if( ui->rxOnClassListWidget->currentItem()->text() == VSCP_CLASS1_INFORMATION)
    {
        tempStringClass = VSCP_CLASS1_INFORMATION_VALUE;
        tempStringType = ui->rxOnTypeListWidget->currentItem()->text();
        ClassTypeObject.getInformationTypeValue(tempStringType);
    }
    else if ( ui->rxOnClassListWidget->currentItem()->text() == VSCP_CLASS1_CONTROL)
    {
        tempStringClass = VSCP_CLASS1_CONTROL_VALUE;
        tempStringType = ui->rxOnTypeListWidget->currentItem()->text();
        ClassTypeObject.getControlTypeValue(tempStringType);
    }
    else
    {
        // Do nothing
    }*/
    tempStringClass = VSCP_CLASS1_INFORMATION_VALUE;
    tempStringType = VSCP_TYPE_INFORMATION_ON;
    ClassTypeObject.getInformationTypeValue(tempStringType);
    switchPacket_modify.rxOnEvent.class_value = tempStringClass;
        // enter value in variable class on event
        switchPacket_modify.packetSwitchVariable.class_value_on =  tempStringClass;
    //ui->rxOnTypeListWidget->setCurrentRow(switchPacket_modify.rxOnEvent.type_value.toInt());
    switchPacket_modify.rxOnEvent.type_value = tempStringType;
        // enter value in variable class on event
        switchPacket_modify.packetSwitchVariable.type_value_on =  tempStringType;
    switchPacket_modify.rxOnEvent.guid = masterGuid;
    switchPacket_modify.rxOnEvent.index = masterIndex;
    switchPacket_modify.rxOnEvent.zone = masterZone;
    switchPacket_modify.rxOnEvent.subzone = masterSubzone;
    switchPacket_modify.rxOnEvent.head = "";
    switchPacket_modify.rxOnEvent.obid = "";
    switchPacket_modify.rxOnEvent.timeStamp = "";
    switchPacket_modify.rxOnEvent.data = "";

    //Rx Off event
    /*if( ui->rxOffClassListWidget->currentItem()->text() == VSCP_CLASS1_INFORMATION)
    {
        tempStringClass = VSCP_CLASS1_INFORMATION_VALUE;
        tempStringType = ui->rxOffTypeListWidget->currentItem()->text();
        ClassTypeObject.getInformationTypeValue(tempStringType);
    }
    else if ( ui->rxOffClassListWidget->currentItem()->text() == VSCP_CLASS1_CONTROL)
    {
        tempStringClass = VSCP_CLASS1_CONTROL_VALUE;
        tempStringType = ui->rxOffTypeListWidget->currentItem()->text();
        ClassTypeObject.getControlTypeValue(tempStringType);
    }
    else
    {
        // Do nothing
    }*/
    tempStringClass = VSCP_CLASS1_INFORMATION_VALUE;
    tempStringType = VSCP_TYPE_INFORMATION_OFF;
    ClassTypeObject.getInformationTypeValue(tempStringType);
    //ui->rxOffClassListWidget->setCurrentRow(switchPacket_modify.rxOffEvent.class_value.toInt());
    switchPacket_modify.rxOffEvent.class_value = tempStringClass;
        // enter value in variable class off event
        switchPacket_modify.packetSwitchVariable.class_value_off =  tempStringClass;
    //ui->rxOffTypeListWidget->setCurrentRow(switchPacket_modify.rxOffEvent.type_value.toInt());
    switchPacket_modify.rxOffEvent.type_value = tempStringType;
        // enter value in variable class off event
        switchPacket_modify.packetSwitchVariable.type_value_off =  tempStringType;
    switchPacket_modify.rxOffEvent.guid = masterGuid;
    switchPacket_modify.rxOffEvent.index = masterIndex;
    switchPacket_modify.rxOffEvent.zone = masterZone;
    switchPacket_modify.rxOffEvent.subzone = masterSubzone;
    switchPacket_modify.rxOffEvent.head = "";
    switchPacket_modify.rxOffEvent.obid = "";
    switchPacket_modify.rxOffEvent.timeStamp = "";
    switchPacket_modify.rxOffEvent.data = "";

    // Variable configure
    //-->switchPacket_modify.packetSwitchVariable.name = ui->variableNameValueLabel->text();
    switchPacket_modify.packetSwitchVariable.allowedFrom = "";
    switchPacket_modify.packetSwitchVariable.allowedTo = "";
    switchPacket_modify.packetSwitchVariable.allowedTime = "";
    switchPacket_modify.packetSwitchVariable.allowedDays.mon = "true";
    switchPacket_modify.packetSwitchVariable.allowedDays.tue = "true";
    switchPacket_modify.packetSwitchVariable.allowedDays.wed = "true";
    switchPacket_modify.packetSwitchVariable.allowedDays.thur = "true";
    switchPacket_modify.packetSwitchVariable.allowedDays.fri = "true";
    switchPacket_modify.packetSwitchVariable.allowedDays.sat = "true";
    switchPacket_modify.packetSwitchVariable.allowedDays.sun = "true";
    /*if(ui->variableAllowedDaysMondaycheckBox->isChecked())
    {
        switchPacket_modify.packetSwitchVariable.allowedDays.mon = "true";
    }
    else
    {
        switchPacket_modify.packetSwitchVariable.allowedDays.mon = "false";
    }

    if(ui->variableAllowedDaysTuesdaycheckBox->isChecked())
    {
        switchPacket_modify.packetSwitchVariable.allowedDays.tue = "true";
    }
    else
    {
        switchPacket_modify.packetSwitchVariable.allowedDays.tue = "false";
    }

    if(ui->variableAllowedDaysWednesdaycheckBox->isChecked())
    {
        switchPacket_modify.packetSwitchVariable.allowedDays.wed = "true";
    }
    else
    {
        switchPacket_modify.packetSwitchVariable.allowedDays.wed = "false";
    }

    if(ui->variableAllowedDaysThursdaycheckBox->isChecked())
    {
        switchPacket_modify.packetSwitchVariable.allowedDays.thur = "true";
    }
    else
    {
        switchPacket_modify.packetSwitchVariable.allowedDays.thur = "false";
    }

    if(ui->variableAllowedDaysFridaycheckBox->isChecked())
    {
        switchPacket_modify.packetSwitchVariable.allowedDays.fri = "true";
    }
    else
    {
        switchPacket_modify.packetSwitchVariable.allowedDays.fri = "false";
    }

    if(ui->variableAllowedDaysSaturdaycheckBox->isChecked())
    {
        switchPacket_modify.packetSwitchVariable.allowedDays.sat = "true";
    }
    else
    {
        switchPacket_modify.packetSwitchVariable.allowedDays.sat = "false";
    }

    if(ui->variableAllowedDaysSundaycheckBox->isChecked())
    {
        switchPacket_modify.packetSwitchVariable.allowedDays.sun = "true";
    }
    else
    {
        switchPacket_modify.packetSwitchVariable.allowedDays.sun = "false";
    }*/
    //action = ui->variableActionListWidget->currentItem()->text();
    action = VSCP_DAEMON_ACTION_CODE_STORE_VARIABLE;
    if(action == VSCP_DAEMON_ACTION_CODE_NOOP)
    {
        action = VSCP_DAEMON_ACTION_CODE_NOOP_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_EXECUTE)
    {
        action = VSCP_DAEMON_ACTION_CODE_EXECUTE_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_INTERNAL_PROCEDURE_EXECUTE)
    {
        action = VSCP_DAEMON_ACTION_INTERNAL_PROCEDURE_EXECUTE_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_EXECUTE_METHOD)
    {
        action = VSCP_DAEMON_ACTION_CODE_EXECUTE_METHOD_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_SEND_EVENT)
    {
        action = VSCP_DAEMON_ACTION_CODE_SEND_EVENT_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_SEND_EVENT_CONDITIONAL)
    {
        action = VSCP_DAEMON_ACTION_CODE_SEND_EVENT_CONDITIONAL_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_SEND_EVENTS_FROM_FILE)
    {
        action = VSCP_DAEMON_ACTION_CODE_SEND_EVENTS_FROM_FILE_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_SEND_TO_REMOTE)
    {
        action = VSCP_DAEMON_ACTION_CODE_SEND_TO_REMOTE_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_STORE_VARIABLE)
    {
        action = VSCP_DAEMON_ACTION_CODE_STORE_VARIABLE_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_STORE_ARRAY)
    {
        action = VSCP_DAEMON_ACTION_CODE_STORE_ARRAY_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_ADD_VARIABLE)
    {
        action = VSCP_DAEMON_ACTION_CODE_ADD_VARIABLE_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_SUBTRACT_VARIABLE)
    {
        action = VSCP_DAEMON_ACTION_CODE_SUBTRACT_VARIABLE_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_MULTIPLY_VARIABLE)
    {
        action = VSCP_DAEMON_ACTION_CODE_MULTIPLY_VARIABLE_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_DIVIDE_VARIABLE)
    {
        action = VSCP_DAEMON_ACTION_CODE_DIVIDE_VARIABLE_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_START_TIMER)
    {
        action = VSCP_DAEMON_ACTION_CODE_START_TIMER_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_PAUSE_TIMER)
    {
        action = VSCP_DAEMON_ACTION_CODE_PAUSE_TIMER_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_STOP_TIMER)
    {
        action = VSCP_DAEMON_ACTION_CODE_STOP_TIMER_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_RESUME_TIMER)
    {
        action = VSCP_DAEMON_ACTION_CODE_RESUME_TIMER_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_WRITE_FILE)
    {
        action = VSCP_DAEMON_ACTION_CODE_WRITE_FILE_VALUE;
    }
    else if (action == VSCP_DAEMON_ACTION_CODE_GET_PUT_POST_URL)
    {
        action = VSCP_DAEMON_ACTION_CODE_GET_PUT_POST_URL_VALUE;
    }
    else
    {
        action = VSCP_DAEMON_ACTION_CODE_NOOP_VALUE;
    }
    //ui->variableActionListWidget->setCurrentRow(switchPacket_modify.packetSwitchVariable.action.toInt());
    switchPacket_modify.packetSwitchVariable.action = action;
    //-->switchPacket_modify.packetSwitchVariable.actionParametersSet = ui->variableActionParametersSetLineEdit->text();
    //-->switchPacket_modify.packetSwitchVariable.actionParametersReset = ui->variableActionParametersResetLineEdit->text();
    //-->switchPacket_modify.packetSwitchVariable.comments = ui->variableCommentsLineEdit->text();
    switchPacket_modify.packetSwitchVariable.control.EnableRow = "true";
    switchPacket_modify.packetSwitchVariable.control.checkIndex = "true";
    switchPacket_modify.packetSwitchVariable.control.checkzone = "true";
    switchPacket_modify.packetSwitchVariable.control.checkSubzone = "true";
    switchPacket_modify.packetSwitchVariable.control.endScan = "false";
    /*if(ui->variableControlEnableRowcheckBox->isChecked())
    {
        switchPacket_modify.packetSwitchVariable.control.EnableRow = "true";
    }
    else
    {
        switchPacket_modify.packetSwitchVariable.control.EnableRow = "false";
    }

    if(ui->variableControlCheckIndexcheckBox->isChecked())
    {
        switchPacket_modify.packetSwitchVariable.control.checkIndex = "true";
    }
    else
    {
        switchPacket_modify.packetSwitchVariable.control.checkIndex = "false";;
    }

    if(ui->variableControlCheckZonecheckBox->isChecked())
    {
        switchPacket_modify.packetSwitchVariable.control.checkzone = "true";
    }
    else
    {
        switchPacket_modify.packetSwitchVariable.control.checkzone = "false";
    }

    if(ui->variableControlCheckSubzonecheckBox->isChecked())
    {
        switchPacket_modify.packetSwitchVariable.control.checkSubzone = "true";
    }
    else
    {
        switchPacket_modify.packetSwitchVariable.control.checkSubzone = "false";
    }

    if(ui->variableControlEndScancheckBox->isChecked())
    {
        switchPacket_modify.packetSwitchVariable.control.endScan = "true";
    }
    else
    {
        switchPacket_modify.packetSwitchVariable.control.endScan = "false";
    }*/

    switchPacket_modify.packetSwitchVariable.groupId = "";
    // todo --> switchPacket_modify.packetSwitchVariable.class_value = ui->variableClassLineEdit->text();
    // todo --> switchPacket_modify.packetSwitchVariable.type_value = ui->variableTypeLineEdit->text();
    switchPacket_modify.packetSwitchVariable.guid = masterGuid;
    //ui->variablePriorityListWidget->setCurrentRow(switchPacket_modify.packetSwitchVariable.priority.toInt());
    //switchPacket_modify.packetSwitchVariable.priority = QString::number( ui->variablePriorityListWidget->currentRow());
    switchPacket_modify.packetSwitchVariable.priority = "0";
    switchPacket_modify.packetSwitchVariable.index = masterIndex;
    switchPacket_modify.packetSwitchVariable.zone = masterZone;
    switchPacket_modify.packetSwitchVariable.subzone = masterSubzone;

    //Emit a close handler
    emit close();
}

WidgetWebsocketPacketSwitch::~WidgetWebsocketPacketSwitch()
{
    delete ui;
}

void WidgetWebsocketPacketSwitch::on_CancelPushButton_clicked()
{
    //Emit a close handler
    emit close();
}
