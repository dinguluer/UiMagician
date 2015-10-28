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



#include "widgetwebsocketpacketslider.h"
#include "ui_widgetwebsocketpacketslider.h"

WidgetWebsocketPacketSlider::WidgetWebsocketPacketSlider(T_widgetWebsocketPacketSlider &sliderPacket, QWidget *parent) :
    QDialog(parent),
    sliderPacket_modify(sliderPacket),
    ui(new Ui::WidgetWebsocketPacketSlider)
{
    ui->setupUi(this);

    setListValue();

    //ui->sensorUrlLineEdit->setValidator(new QRegExpValidator( QRegExp("[w]{1,1}[s]{1,1}[s]{1,1}\\:\\/\\/[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\:[0-9]{1,4}" ), this ));
    ui->sliderUrlLineEdit->setValidator(new QRegExpValidator( QRegExp("[w]{1,1}[s]{1,2}\\:\\/\\/[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\:[0-9]{1,4}" ), this ));
    //ui->sliderMinLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    //ui->sliderMaxLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));

    //class
    // Add list item here
    for(int i=0; i< listClass.size() ; i++)
    {
        ui->sliderTxClassListWidget->addItem(listClass.at(i));
    }
    ui->sliderTxClassListWidget->setCurrentRow(0);
    //type
    // Add list item here
    for(int i=0; i< listType.size() ; i++)
    {
        ui->sliderTxTypeListWidget->addItem(listType.at(i));
    }
    ui->sliderTxTypeListWidget->setCurrentRow(0);
    //data
    /*ui->sliderTxGuidLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}"), this ));
    //ui->sliderTxIndexLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->sliderTxIndexLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    //ui->sliderTxZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->sliderTxZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    //ui->sliderTxSubZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->sliderTxSubZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    ui->sliderTxHeadLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->sliderTxObidLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,8}"), this ));
   */

    //class
    // Add list item here
    for(int i=0; i< listClass.size() ; i++)
    {
        ui->sliderRxClassListWidget->addItem(listClass.at(i));
    }
    ui->sliderRxClassListWidget->setCurrentRow(0);
    //type
    // Add list item here
    for(int i=0; i< listType.size() ; i++)
    {
        ui->sliderRxTypeListWidget->addItem(listType.at(i));
    }
    ui->sliderRxTypeListWidget->setCurrentRow(0);
    //data
    /*ui->sliderRxGuidLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}"), this ));
    //ui->sliderRxIndexLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->sliderRxIndexLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    //ui->sliderRxZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->sliderRxZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    //ui->sliderRxSubZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->sliderRxSubZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    ui->sliderRxHeadLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->sliderRxObidLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,8}"), this ));

    ui->sliderVariableAllowedFromLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9\\-\\:\\s]{1,19}"), this ));
    ui->sliderVariableAllowedToLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9\\-\\:\\s]{1,19}"), this ));
    ui->sliderVariableAllowedTimeLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9\\-\\:\\s]{1,19}"), this ));

    //groupId validator
    ui->sliderVariableGroupIdLineEdit->setValidator(new QRegExpValidator( QRegExp("[a-zA-Z0-9_]*"), this ));

    //set the list for Action - sliderVariableActionListWidget
    for(int i=0; i< listAction.size() ; i++)
    {
        ui->sliderVariableActionListWidget->addItem(listAction.at(i));
    }
    // set the list for priority
    for(int i=0; i< listPriority.size() ; i++)
    {
        ui->sliderVariablePriorityListWidget->addItem(listPriority.at(i));
    }

    ui->sliderVariableActionParametersLineEdit->setReadOnly(true);
    ui->sliderTxTimeStampLineEdit->setReadOnly(true);
    ui->sliderTxDataLineEdit->setReadOnly(true);
    ui->sliderRxTimeStampLineEdit->setReadOnly(true);
    ui->sliderRxDataLineEdit->setReadOnly(true);

    //domain should be fixed
    ui->sliderDomainLineEdit->setReadOnly(true);
   */

    //Copy slider packet to Dialog
    CopySliderPacket();

    //clear the qstring
    sliderVariableActionParameters.clear();
    sliderVariableActionParameters = "";
}

//Copy slider packet to Dialog
void WidgetWebsocketPacketSlider::CopySliderPacket()
{
    //QString action;
    QString tempString;
    QString rxClass;
    QString rxTypeValue;
    //QString parameterStringValue;
    QListWidgetItem dummyCurrentItem;
    QListWidgetItem dummyPreviousItem;
    int classIndex = 0;
    int typeIndex = 0;
    //int actionval;
    //int maxVal;
    //int minVal;
    //websocket
    //-->ui->sliderIdValueLabel->setText(sliderPacket_modify.id);
    //-->ui->sliderLocalTxtIdValueLabel->setText(sliderPacket_modify.idLocalTxt);
    //-->ui->sliderRemoteTxtIdValueLabel->setText(sliderPacket_modify.idRemoteTxt);
    ui->sliderUrlLineEdit->setText(sliderPacket_modify.url);
    ui->sliderMaxLineEdit->setText(sliderPacket_modify.maxValue);
    ui->sliderMinLineEdit->setText(sliderPacket_modify.minValue);
    ui->sliderUsernameLineEdit->setText(sliderPacket_modify.userName);
    ui->sliderPasswordLineEdit->setText(sliderPacket_modify.passWord);
    //domain should be fixed for this release
    ui->sliderDomainLineEdit->setText("mydomain.com");
    // set the remote node parameters
    ui->sliderGuidLineEdit->setText(sliderPacket_modify.rxEvent.guid);
    if(sliderPacket_modify.rxEvent.type_value == VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED_VALUE)
    {
        ui->sliderIndexLineEdit->setText(sliderPacket_modify.rxEvent.index);
    }
    else
    {
        ui->sliderIndexLineEdit->clear();
    }
    ui->sliderZoneLineEdit->setText(sliderPacket_modify.rxEvent.zone);
    ui->sliderSubZoneLineEdit->setText(sliderPacket_modify.rxEvent.subzone);

    //Tx event
    tempString = sliderPacket_modify.txEvent.class_value;
    if(tempString == VSCP_CLASS1_INFORMATION_VALUE)
    {
        classIndex = 0; //information
        tempString = sliderPacket_modify.txEvent.type_value;
        typeIndex = ClassTypeObject.getInformationTypeListIndex(tempString);
    }
    else if(tempString == VSCP_CLASS1_CONTROL_VALUE)
    {
        classIndex = 1; //control
        tempString = sliderPacket_modify.txEvent.type_value;
        typeIndex = ClassTypeObject.getControlTypeListIndex(tempString);
    }
    else
    {
        // Do nothing
    }
    ui->sliderTxClassListWidget->setCurrentRow(classIndex);
       // set the value of the type list
        on_sliderTxClassListWidget_currentItemChanged(&dummyCurrentItem, &dummyPreviousItem);
    ui->sliderTxTypeListWidget->setCurrentRow(typeIndex);
    /*ui->sliderTxGuidLineEdit->setText(sliderPacket_modify.txEvent.guid);
    // clear Tx line edit
    if(sliderPacket_modify.txEvent.type_value == VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL_VALUE)
    {
        ui->sliderTxIndexLineEdit->setText(sliderPacket_modify.txEvent.index);
    }
    else
    {
        ui->sliderTxIndexLineEdit->clear();
    }
    ui->sliderTxZoneLineEdit->setText(sliderPacket_modify.txEvent.zone);
    ui->sliderTxSubZoneLineEdit->setText(sliderPacket_modify.txEvent.subzone);
    ui->sliderTxHeadLineEdit->setText(sliderPacket_modify.txEvent.head);
    ui->sliderTxObidLineEdit->setText(sliderPacket_modify.txEvent.obid);
    ui->sliderTxTimeStampLineEdit->setText(sliderPacket_modify.txEvent.timeStamp);
    ui->sliderTxDataLineEdit->setText(sliderPacket_modify.txEvent.data);
*/
    //Rx event
    tempString = sliderPacket_modify.rxEvent.class_value;
    rxClass = tempString;
    if(tempString == VSCP_CLASS1_INFORMATION_VALUE)
    {
        classIndex = 0; //information
        tempString = sliderPacket_modify.rxEvent.type_value;
        rxTypeValue = tempString;
        typeIndex = ClassTypeObject.getInformationTypeListIndex(tempString);
    }
    else if(tempString == VSCP_CLASS1_CONTROL_VALUE)
    {
        classIndex = 1; //information
        tempString = sliderPacket_modify.rxEvent.type_value;
        typeIndex = ClassTypeObject.getControlTypeListIndex(tempString);        
    }
    else
    {
        // Do nothing
    }
    ui->sliderRxClassListWidget->setCurrentRow(classIndex);
        // set the value of the type list
         on_sliderRxClassListWidget_currentItemChanged(&dummyCurrentItem, &dummyPreviousItem);
    ui->sliderRxTypeListWidget->setCurrentRow(typeIndex);
    /*ui->sliderRxGuidLineEdit->setText(sliderPacket_modify.rxEvent.guid);

    // clear Rx line edit
    if(sliderPacket_modify.rxEvent.type_value == VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED_VALUE)
    {
        ui->sliderRxIndexLineEdit->setText(sliderPacket_modify.rxEvent.index);
    }
    else
    {
        ui->sliderRxIndexLineEdit->clear();
    }
    ui->sliderRxZoneLineEdit->setText(sliderPacket_modify.rxEvent.zone);
    ui->sliderRxSubZoneLineEdit->setText(sliderPacket_modify.rxEvent.subzone);
    ui->sliderRxHeadLineEdit->setText(sliderPacket_modify.rxEvent.head);
    ui->sliderRxObidLineEdit->setText(sliderPacket_modify.rxEvent.obid);
    ui->sliderRxTimeStampLineEdit->setText(sliderPacket_modify.rxEvent.timeStamp);
    ui->sliderRxDataLineEdit->setText(sliderPacket_modify.rxEvent.data);

    //Variable
    ui->sliderVariableNameValueLabel->setText(sliderPacket_modify.packetSliderVariable.name);
    ui->sliderVariableAllowedFromLineEdit->setText(sliderPacket_modify.packetSliderVariable.allowedFrom);
    ui->sliderVariableAllowedToLineEdit->setText(sliderPacket_modify.packetSliderVariable.allowedTo);
    ui->sliderVariableAllowedTimeLineEdit->setText(sliderPacket_modify.packetSliderVariable.allowedTime);
    if(sliderPacket_modify.packetSliderVariable.allowedDays.mon == "true")
    {
        ui->sliderVariableAllowedDaysMondaycheckBox->setChecked(true);
    }
    else
    {
        ui->sliderVariableAllowedDaysMondaycheckBox->setChecked(false);
    }

    if(sliderPacket_modify.packetSliderVariable.allowedDays.tue == "true")
    {
        ui->sliderVariableAllowedDaysTuesdaycheckBox->setChecked(true);
    }
    else
    {
        ui->sliderVariableAllowedDaysTuesdaycheckBox->setChecked(false);
    }

    if(sliderPacket_modify.packetSliderVariable.allowedDays.wed == "true")
    {
        ui->sliderVariableAllowedDaysWednesdaycheckBox->setChecked(true);
    }
    else
    {
        ui->sliderVariableAllowedDaysWednesdaycheckBox->setChecked(false);
    }

    if(sliderPacket_modify.packetSliderVariable.allowedDays.thur == "true")
    {
        ui->sliderVariableAllowedDaysThursdaycheckBox->setChecked(true);
    }
    else
    {
        ui->sliderVariableAllowedDaysThursdaycheckBox->setChecked(false);
    }

    if(sliderPacket_modify.packetSliderVariable.allowedDays.fri == "true")
    {
        ui->sliderVariableAllowedDaysFridaycheckBox->setChecked(true);
    }
    else
    {
        ui->sliderVariableAllowedDaysFridaycheckBox->setChecked(false);
    }

    if(sliderPacket_modify.packetSliderVariable.allowedDays.sat == "true")
    {
        ui->sliderVariableAllowedDaysSaturdaycheckBox->setChecked(true);
    }
    else
    {
        ui->sliderVariableAllowedDaysSaturdaycheckBox->setChecked(false);
    }

    if(sliderPacket_modify.packetSliderVariable.allowedDays.sun == "true")
    {
        ui->sliderVariableAllowedDaysSundaycheckBox->setChecked(true);
    }
    else
    {
        ui->sliderVariableAllowedDaysSundaycheckBox->setChecked(false);
    }
    action = sliderPacket_modify.packetSliderVariable.action;
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
    ui->sliderVariableActionListWidget->setCurrentRow(actionval);
    //ui->sliderVariableActionParametersLineEdit->setText(sliderPacket_modify.packetSliderVariable.actionParameters);
        //parameterStringValue = sliderPacket_modify.packetSliderVariable.name + ",3,true,\"0x60,0,%event.data[0]\"";

        maxVal = sliderPacket_modify.maxValue.toInt();
        minVal = sliderPacket_modify.minValue.toInt();
        //if((maxVal > 255)|| (minVal < 0))
        if((rxClass == VSCP_CLASS1_INFORMATION_VALUE) && (rxTypeValue == VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED_VALUE))
        {
            parameterStringValue = sliderPacket_modify.packetSliderVariable.name + ";9;true;%event.data";
        }
        else
        {
            parameterStringValue = sliderPacket_modify.packetSliderVariable.name + ";3;true;%event.data[0]";
        }
        ui->sliderVariableActionParametersLineEdit->setText(parameterStringValue);
    ui->sliderVariableCommentsLineEdit->setText(sliderPacket_modify.packetSliderVariable.comments);
    if(sliderPacket_modify.packetSliderVariable.control.EnableRow == "true")
    {
        ui->sliderVariableControlEnableRowcheckBox->setChecked(true);
    }
    else
    {
        ui->sliderVariableControlEnableRowcheckBox->setChecked(false);
    }

    if(sliderPacket_modify.packetSliderVariable.control.checkIndex == "true")
    {
        ui->sliderVariableControlCheckIndexcheckBox->setChecked(true);
    }
    else
    {
        ui->sliderVariableControlCheckIndexcheckBox->setChecked(false);
    }

    if(sliderPacket_modify.packetSliderVariable.control.checkzone == "true")
    {
        ui->sliderVariableControlCheckZonecheckBox->setChecked(true);
    }
    else
    {
        ui->sliderVariableControlCheckZonecheckBox->setChecked(false);
    }

    if(sliderPacket_modify.packetSliderVariable.control.checkSubzone == "true")
    {
        ui->sliderVariableControlCheckSubzonecheckBox->setChecked(true);
    }
    else
    {
        ui->sliderVariableControlCheckSubzonecheckBox->setChecked(false);
    }

    if(sliderPacket_modify.packetSliderVariable.control.endScan == "true")
    {
        ui->sliderVariableControlEndScancheckBox->setChecked(true);
    }
    else
    {
        ui->sliderVariableControlEndScancheckBox->setChecked(false);
    }

    ui->sliderVariableGroupIdLineEdit->setText(sliderPacket_modify.packetSliderVariable.groupId);
    // todo --> ui->sliderVariableClassLineEdit->setText(sliderPacket_modify.packetSliderVariable.class_value);
    // todo --> ui->sliderVariableTypeLineEdit->setText(sliderPacket_modify.packetSliderVariable.type_value);
    ui->sliderVariableGuidLineEdit->setText(sliderPacket_modify.packetSliderVariable.guid);
    ui->sliderVariablePriorityListWidget->setCurrentRow(sliderPacket_modify.packetSliderVariable.priority.toInt());
    ui->sliderVariableIndexLineEdit->setText(sliderPacket_modify.packetSliderVariable.index);
    ui->sliderVariableZoneLineEdit->setText(sliderPacket_modify.packetSliderVariable.zone);
    ui->sliderVariableSubzoneLineEdit->setText(sliderPacket_modify.packetSliderVariable.subzone);
   */

}

void WidgetWebsocketPacketSlider::setListValue()
{
    listClass << VSCP_CLASS1_INFORMATION << VSCP_CLASS1_CONTROL ;

    /*listType   << VSCP_TYPE_INFORMATION_GENERAL << VSCP_TYPE_INFORMATION_BUTTON << VSCP_TYPE_INFORMATION_MOUSE
              << VSCP_TYPE_INFORMATION_ON << VSCP_TYPE_INFORMATION_OFF << VSCP_TYPE_INFORMATION_ALIVE
              << VSCP_TYPE_INFORMATION_TERMINATING << VSCP_TYPE_INFORMATION_OPENED << VSCP_TYPE_INFORMATION_CLOSED
              << VSCP_TYPE_INFORMATION_NODE_HEARTBEAT << VSCP_TYPE_INFORMATION_BELOW_LIMIT << VSCP_TYPE_INFORMATION_ABOVE_LIMIT
              << VSCP_TYPE_INFORMATION_PULSE << VSCP_TYPE_INFORMATION_ERROR << VSCP_TYPE_INFORMATION_RESUMED
              << VSCP_TYPE_INFORMATION_PAUSED << VSCP_TYPE_INFORMATION_SLEEP << VSCP_TYPE_INFORMATION_GOOD_MORNING
              << VSCP_TYPE_INFORMATION_GOOD_DAY  << VSCP_TYPE_INFORMATION_GOOD_AFTERNOON
              << VSCP_TYPE_INFORMATION_GOOD_EVENING << VSCP_TYPE_INFORMATION_GOOD_NIGHT
              << VSCP_TYPE_INFORMATION_SEE_YOU_SOON << VSCP_TYPE_INFORMATION_GOODBYE << VSCP_TYPE_INFORMATION_STOP
              << VSCP_TYPE_INFORMATION_START << VSCP_TYPE_INFORMATION_RESET_COMPLETED << VSCP_TYPE_INFORMATION_INTERRUPTED
              << VSCP_TYPE_INFORMATION_PREPARING_TO_SLEEP << VSCP_TYPE_INFORMATION_WOKEN_UP << VSCP_TYPE_INFORMATION_DUSK
              << VSCP_TYPE_INFORMATION_DAWN << VSCP_TYPE_INFORMATION_ACTIVE << VSCP_TYPE_INFORMATION_INACTIVE << VSCP_TYPE_INFORMATION_BUSY
              << VSCP_TYPE_INFORMATION_IDLE << VSCP_TYPE_INFORMATION_STREAM_DATA << VSCP_TYPE_INFORMATION_TOKEN_ACTIVITY
              << VSCP_TYPE_INFORMATION_STREAM_DATA_WITH_ZONE << VSCP_TYPE_INFORMATION_CONFIRM << VSCP_TYPE_INFORMATION_LEVEL_CHANGED
              << VSCP_TYPE_INFORMATION_WARNING << VSCP_TYPE_INFORMATION_STATE << VSCP_TYPE_INFORMATION_ACTION_TRIGGER
              << VSCP_TYPE_INFORMATION_SUNRISE << VSCP_TYPE_INFORMATION_SUNSET << VSCP_TYPE_INFORMATION_START_OF_RECORD
              << VSCP_TYPE_INFORMATION_END_OF_RECORD << VSCP_TYPE_INFORMATION_PRESET_ACTIVE << VSCP_TYPE_INFORMATION_DETECT
              << VSCP_TYPE_INFORMATION_OVERFLOW << VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED
                 ;*/

    listType   << VSCP_TYPE_INFORMATION_LEVEL_CHANGED << VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED
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

void WidgetWebsocketPacketSlider::on_sliderTxClassListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{

    if(ui->sliderTxClassListWidget->currentItem()->text() == VSCP_CLASS1_INFORMATION)
    {
        ui->sliderTxTypeListWidget->clear();
        listType.clear();
        /*listType   << VSCP_TYPE_INFORMATION_GENERAL << VSCP_TYPE_INFORMATION_BUTTON << VSCP_TYPE_INFORMATION_MOUSE
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
                     ;*/

        listType   << VSCP_TYPE_INFORMATION_LEVEL_CHANGED << VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED
                     ;
        // Add item
        for(int i=0; i< listType.size() ; i++)
        {
            ui->sliderTxTypeListWidget->addItem(listType.at(i));
        }
        ui->sliderTxTypeListWidget->setCurrentRow(0);

    }
    else if(ui->sliderTxClassListWidget->currentItem()->text() == VSCP_CLASS1_CONTROL)
    {
        ui->sliderTxTypeListWidget->clear();
        listType.clear();
        /*listType   << VSCP_TYPE_CONTROL_GENERAL << VSCP_TYPE_CONTROL_MUTE << VSCP_TYPE_CONTROL_ALL_LAMPS
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
                     ;*/

        listType   << VSCP_TYPE_CONTROL_DIM_LAMPS << VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL
                     ;
        // Add item
        for(int i=0; i< listType.size() ; i++)
        {
            ui->sliderTxTypeListWidget->addItem(listType.at(i));
        }
        ui->sliderTxTypeListWidget->setCurrentRow(0);

    }
    else{
        // do nothing
    }

}

void WidgetWebsocketPacketSlider::on_sliderRxClassListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{

    if(ui->sliderRxClassListWidget->currentItem()->text() == VSCP_CLASS1_INFORMATION)
    {
        ui->sliderRxTypeListWidget->clear();
        listType.clear();
        /*listType   << VSCP_TYPE_INFORMATION_GENERAL << VSCP_TYPE_INFORMATION_BUTTON << VSCP_TYPE_INFORMATION_MOUSE
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
                     ;*/

        listType   << VSCP_TYPE_INFORMATION_LEVEL_CHANGED << VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED
                     ;
        // Add item
        for(int i=0; i< listType.size() ; i++)
        {
            ui->sliderRxTypeListWidget->addItem(listType.at(i));
        }
        ui->sliderRxTypeListWidget->setCurrentRow(0);

    }
    else if(ui->sliderRxClassListWidget->currentItem()->text() == VSCP_CLASS1_CONTROL)
    {
        ui->sliderRxTypeListWidget->clear();
        listType.clear();
        /*listType   << VSCP_TYPE_CONTROL_GENERAL << VSCP_TYPE_CONTROL_MUTE << VSCP_TYPE_CONTROL_ALL_LAMPS
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
                     ;*/

        listType   << VSCP_TYPE_CONTROL_DIM_LAMPS << VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL
                     ;
        // Add item
        for(int i=0; i< listType.size() ; i++)
        {
            ui->sliderRxTypeListWidget->addItem(listType.at(i));
        }
        ui->sliderRxTypeListWidget->setCurrentRow(0);

    }
    else{
        // do nothing
    }

}

void WidgetWebsocketPacketSlider::on_OkSliderPushButton_clicked()
{
    QString action;
    QString tempStringClass;
    QString tempStringType;
    //websocket
    //-->sliderPacket_modify.id = ui->sliderIdValueLabel->text();
    //-->sliderPacket_modify.idLocalTxt = ui->sliderLocalTxtIdValueLabel->text();
    //-->sliderPacket_modify.idRemoteTxt = ui->sliderRemoteTxtIdValueLabel->text();
    sliderPacket_modify.url = ui->sliderUrlLineEdit->text();
    sliderPacket_modify.maxValue = ui->sliderMaxLineEdit->text();
    sliderPacket_modify.minValue = ui->sliderMinLineEdit->text();
    sliderPacket_modify.userName = ui->sliderUsernameLineEdit->text();
    sliderPacket_modify.passWord = ui->sliderPasswordLineEdit->text();
    sliderPacket_modify.domain = ui->sliderDomainLineEdit->text();
    //Tx event
    //ui->sliderTxClassListWidget->setCurrentRow(sliderPacket_modify.txEvent.class_value.toInt());
    if( ui->sliderTxClassListWidget->currentItem()->text() == VSCP_CLASS1_INFORMATION)
    {
        tempStringClass = VSCP_CLASS1_INFORMATION_VALUE;
        tempStringType = ui->sliderTxTypeListWidget->currentItem()->text();
        ClassTypeObject.getInformationTypeValue(tempStringType);
    }
    else if ( ui->sliderTxClassListWidget->currentItem()->text() == VSCP_CLASS1_CONTROL)
    {
        tempStringClass = VSCP_CLASS1_CONTROL_VALUE;
        tempStringType = ui->sliderTxTypeListWidget->currentItem()->text();
        ClassTypeObject.getControlTypeValue(tempStringType);
    }
    else
    {
        // Do nothing
    }
    //sliderPacket_modify.txEvent.class_value = QString:tempStringType:number( ui->sliderTxClassListWidget->currentRow());
    sliderPacket_modify.txEvent.class_value = tempStringClass;
    //ui->sliderTxTypeListWidget->setCurrentRow(sliderPacket_modify.txEvent.type_value.toInt());
    sliderPacket_modify.txEvent.type_value = tempStringType;
    sliderPacket_modify.txEvent.guid = ui->sliderGuidLineEdit->text();
    sliderPacket_modify.txEvent.zone = ui->sliderZoneLineEdit->text();
    sliderPacket_modify.txEvent.subzone = ui->sliderSubZoneLineEdit->text();
    if(sliderPacket_modify.txEvent.type_value == VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL_VALUE)
    {
        sliderPacket_modify.txEvent.index = ui->sliderIndexLineEdit->text();
    }

    else
    {
        sliderPacket_modify.txEvent.index = "";
    }
    sliderPacket_modify.txEvent.head = "";
    sliderPacket_modify.txEvent.obid = "";
    sliderPacket_modify.txEvent.timeStamp = "";
    sliderPacket_modify.txEvent.data = "";

    //Rx event
    //ui->sliderRxClassListWidget->setCurrentRow(sliderPacket_modify.rxEvent.class_value.toInt());
    if( ui->sliderRxClassListWidget->currentItem()->text() == VSCP_CLASS1_INFORMATION)
    {
        tempStringClass = VSCP_CLASS1_INFORMATION_VALUE;
        tempStringType = ui->sliderRxTypeListWidget->currentItem()->text();
        ClassTypeObject.getInformationTypeValue(tempStringType);
    }
    else if ( ui->sliderRxClassListWidget->currentItem()->text() == VSCP_CLASS1_CONTROL)
    {
        tempStringClass = VSCP_CLASS1_CONTROL_VALUE;
        tempStringType = ui->sliderRxTypeListWidget->currentItem()->text();
        ClassTypeObject.getControlTypeValue(tempStringType);
    }
    else
    {
        // Do nothing
    }
    //sliderPacket_modify.rxEvent.class_value = QString:tempStringType:number( ui->sliderRxClassListWidget->currentRow());
    sliderPacket_modify.rxEvent.class_value = tempStringClass;
    //ui->sliderRxTypeListWidget->setCurrentRow(sliderPacket_modify.rxEvent.type_value.toInt());
    sliderPacket_modify.rxEvent.type_value = tempStringType;
    sliderPacket_modify.rxEvent.guid = ui->sliderGuidLineEdit->text();
    //sliderPacket_modify.rxEvent.index = ui->sliderRxIndexLineEdit->text();
    sliderPacket_modify.rxEvent.zone = ui->sliderZoneLineEdit->text();
    sliderPacket_modify.rxEvent.subzone = ui->sliderSubZoneLineEdit->text();
    // clear Rx line edit
    if(sliderPacket_modify.rxEvent.type_value == VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED_VALUE)
    {
      sliderPacket_modify.rxEvent.index = ui->sliderIndexLineEdit->text();
    }
    else
    {
        sliderPacket_modify.rxEvent.index = "";
    }
    sliderPacket_modify.rxEvent.head = "";
    sliderPacket_modify.rxEvent.obid = "";
    sliderPacket_modify.rxEvent.timeStamp = "";
    sliderPacket_modify.rxEvent.data = "";


    //Variable
    //sliderPacket_modify.packetSliderVariable.name = ui->sliderVariableNameValueLabel->text();
    sliderPacket_modify.packetSliderVariable.allowedFrom = "";
    sliderPacket_modify.packetSliderVariable.allowedTo = "";
    sliderPacket_modify.packetSliderVariable.allowedTime = "";
    sliderPacket_modify.packetSliderVariable.allowedDays.mon = "true";
    sliderPacket_modify.packetSliderVariable.allowedDays.tue = "true";
    sliderPacket_modify.packetSliderVariable.allowedDays.wed = "true";
    sliderPacket_modify.packetSliderVariable.allowedDays.thur = "true";
    sliderPacket_modify.packetSliderVariable.allowedDays.fri = "true";
    sliderPacket_modify.packetSliderVariable.allowedDays.sat = "true";
    sliderPacket_modify.packetSliderVariable.allowedDays.sun = "true";
    /*if(ui->sliderVariableAllowedDaysMondaycheckBox->isChecked())
    {
        sliderPacket_modify.packetSliderVariable.allowedDays.mon = "true";
    }
    else
    {
        sliderPacket_modify.packetSliderVariable.allowedDays.mon = "false";
    }

    if(ui->sliderVariableAllowedDaysTuesdaycheckBox->isChecked())
    {
        sliderPacket_modify.packetSliderVariable.allowedDays.tue = "true";
    }
    else
    {
        sliderPacket_modify.packetSliderVariable.allowedDays.tue = "false";
    }

    if(ui->sliderVariableAllowedDaysWednesdaycheckBox->isChecked())
    {
        sliderPacket_modify.packetSliderVariable.allowedDays.wed = "true";
    }
    else
    {
        sliderPacket_modify.packetSliderVariable.allowedDays.wed = "false";
    }

    if(ui->sliderVariableAllowedDaysThursdaycheckBox->isChecked())
    {
        sliderPacket_modify.packetSliderVariable.allowedDays.thur = "true";
    }
    else
    {
        sliderPacket_modify.packetSliderVariable.allowedDays.thur = "false";
    }

    if(ui->sliderVariableAllowedDaysFridaycheckBox->isChecked())
    {
        sliderPacket_modify.packetSliderVariable.allowedDays.fri = "true";
    }
    else
    {
        sliderPacket_modify.packetSliderVariable.allowedDays.fri = "false";
    }

    if(ui->sliderVariableAllowedDaysSaturdaycheckBox->isChecked())
    {
        sliderPacket_modify.packetSliderVariable.allowedDays.sat = "true";
    }
    else
    {
        sliderPacket_modify.packetSliderVariable.allowedDays.sat = "false";
    }

    if(ui->sliderVariableAllowedDaysSundaycheckBox->isChecked())
    {
        sliderPacket_modify.packetSliderVariable.allowedDays.sun = "true";
    }
    else
    {
        sliderPacket_modify.packetSliderVariable.allowedDays.sun = "false";
    }*/
    //action = ui->sliderVariableActionListWidget->currentItem()->text();
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
    //ui->sliderVariableActionListWidget->setCurrentRow(sliderPacket_modify.packetSliderVariable.action.toInt());
    sliderPacket_modify.packetSliderVariable.action = action;
    //sliderPacket_modify.packetSliderVariable.actionParameters = ui->sliderVariableActionParametersLineEdit->text();
    if(sliderVariableActionParameters != "")
    {
        sliderPacket_modify.packetSliderVariable.actionParameters = sliderVariableActionParameters;
    }
    //sliderPacket_modify.packetSliderVariable.comments = ui->sliderVariableCommentsLineEdit->text();
    sliderPacket_modify.packetSliderVariable.control.EnableRow = "true";
    sliderPacket_modify.packetSliderVariable.control.checkIndex = "true";
    sliderPacket_modify.packetSliderVariable.control.checkzone = "true";
    sliderPacket_modify.packetSliderVariable.control.checkSubzone = "true";
    sliderPacket_modify.packetSliderVariable.control.endScan = "false";
    /*if(ui->sliderVariableControlEnableRowcheckBox->isChecked())
    {
        sliderPacket_modify.packetSliderVariable.control.EnableRow = "true";
    }
    else
    {
        sliderPacket_modify.packetSliderVariable.control.EnableRow = "false";
    }

    if(ui->sliderVariableControlCheckIndexcheckBox->isChecked())
    {
        sliderPacket_modify.packetSliderVariable.control.checkIndex = "true";
    }
    else
    {
        sliderPacket_modify.packetSliderVariable.control.checkIndex = "false";;
    }

    if(ui->sliderVariableControlCheckZonecheckBox->isChecked())
    {
        sliderPacket_modify.packetSliderVariable.control.checkzone = "true";
    }
    else
    {
        sliderPacket_modify.packetSliderVariable.control.checkzone = "false";
    }

    if(ui->sliderVariableControlCheckSubzonecheckBox->isChecked())
    {
        sliderPacket_modify.packetSliderVariable.control.checkSubzone = "true";
    }
    else
    {
        sliderPacket_modify.packetSliderVariable.control.checkSubzone = "false";
    }

    if(ui->sliderVariableControlEndScancheckBox->isChecked())
    {
        sliderPacket_modify.packetSliderVariable.control.endScan = "true";
    }
    else
    {
        sliderPacket_modify.packetSliderVariable.control.endScan = "false";
    }*/

    //sliderPacket_modify.packetSliderVariable.groupId = ui->sliderVariableGroupIdLineEdit->text();
    sliderPacket_modify.packetSliderVariable.groupId = "";
    // todo --> sliderPacket_modify.packetSliderVariable.class_value = ui->sliderVariableClassLineEdit->text();
    sliderPacket_modify.packetSliderVariable.class_value = sliderPacket_modify.rxEvent.class_value;
    // todo --> sliderPacket_modify.packetSliderVariable.type_value = ui->sliderVariableTypeLineEdit->text();
    sliderPacket_modify.packetSliderVariable.type_value = sliderPacket_modify.rxEvent.type_value;
    sliderPacket_modify.packetSliderVariable.guid = ui->sliderGuidLineEdit->text();
    //ui->sliderVariablePriorityListWidget->setCurrentRow(sliderPacket_modify.packetSliderVariable.priority.toInt());
    //sliderPacket_modify.packetSliderVariable.priority = QString::number( ui->sliderVariablePriorityListWidget->currentRow());
    sliderPacket_modify.packetSliderVariable.priority =  "0";
    sliderPacket_modify.packetSliderVariable.index = ui->sliderIndexLineEdit->text();
    sliderPacket_modify.packetSliderVariable.zone = ui->sliderZoneLineEdit->text();
    sliderPacket_modify.packetSliderVariable.subzone = ui->sliderSubZoneLineEdit->text();


    //Emit a close handler
    emit close();
}

void WidgetWebsocketPacketSlider::on_CancelSliderPushButton_clicked()
{
    //Emit a close handler
    emit close();
}

void WidgetWebsocketPacketSlider::on_WidgetWebsocketPacketSliderTabWidget_currentChanged(int index)
{
    QString parameterStringValue;

    //QMessageBox::information(this, "name", "1");

    if((ui->sliderRxTypeListWidget->currentItem()->text() == VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED) || (ui->sliderTxTypeListWidget->currentItem()->text()  == VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL))
    {
        parameterStringValue = sliderPacket_modify.packetSliderVariable.name + ";9;true;%event.data";

        // set read only - false
        ui->sliderIndexLineEdit->setReadOnly(false);
        ui->sliderIndexLineEdit->setReadOnly(false);
    }
    else
    {
        parameterStringValue = sliderPacket_modify.packetSliderVariable.name + ";3;true;%event.data[0]";

        // clear Tx & rx line edit
        ui->sliderIndexLineEdit->clear();
        ui->sliderIndexLineEdit->clear();
        // set read only - true
        ui->sliderIndexLineEdit->setReadOnly(true);
        ui->sliderIndexLineEdit->setReadOnly(true);
    }
    //ui->sliderVariableActionParametersLineEdit->setText(parameterStringValue);
    sliderVariableActionParameters = parameterStringValue;

        //QMessageBox::information(this, "name", "2");
}

WidgetWebsocketPacketSlider::~WidgetWebsocketPacketSlider()
{
    delete ui;
}

