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


#include "widgetWebsocketPacketVariableSwitch.h"
#include "ui_widgetwebsocketpacketvariableswitch.h"

WidgetWebsocketPacketVariableSwitch::WidgetWebsocketPacketVariableSwitch(T_widgetWebsocketPacketVariableSwitch &variableSwitchPacket, QWidget *parent) :
    QDialog(parent),
    variableSwitchPacket_modify(variableSwitchPacket),
    ui(new Ui::WidgetWebsocketPacketVariableSwitch)
{
    ui->setupUi(this);

    setListValue();

    //ui->sensorUrlLineEdit->setValidator(new QRegExpValidator( QRegExp("[w]{1,1}[s]{1,1}[s]{1,1}\\:\\/\\/[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\:[0-9]{1,4}" ), this ));
    ui->variableSwitchUrlLineEdit->setValidator(new QRegExpValidator( QRegExp("[w]{1,1}[s]{1,2}\\:\\/\\/[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\:[0-9]{1,4}" ), this ));
    ui->variableSwitchMinLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    ui->variableSwitchMaxLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));

    //class
    // Add list item here
    for(int i=0; i< listClass.size() ; i++)
    {
        ui->variableSwitchTxClassListWidget->addItem(listClass.at(i));
    }
    ui->variableSwitchTxClassListWidget->setCurrentRow(0);
    //type
    // Add list item here
    for(int i=0; i< listType.size() ; i++)
    {
        ui->variableSwitchTxTypeListWidget->addItem(listType.at(i));
    }
    ui->variableSwitchTxTypeListWidget->setCurrentRow(0);
    //data
    ui->variableSwitchTxGuidLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}"), this ));
    //ui->variableSwitchTxIndexLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    //ui->variableSwitchTxZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->variableSwitchTxZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    //ui->variableSwitchTxSubZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->variableSwitchTxSubZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    ui->variableSwitchTxHeadLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->variableSwitchTxObidLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,8}"), this ));


    //class
    // Add list item here
    for(int i=0; i< listClass.size() ; i++)
    {
        ui->variableSwitchRxClassListWidget->addItem(listClass.at(i));
    }
    ui->variableSwitchRxClassListWidget->setCurrentRow(0);
    //type
    // Add list item here
    for(int i=0; i< listType.size() ; i++)
    {
        ui->variableSwitchRxTypeListWidget->addItem(listType.at(i));
    }
    ui->variableSwitchRxTypeListWidget->setCurrentRow(0);
    //data
    ui->variableSwitchRxGuidLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}"), this ));
    //ui->variableSwitchRxIndexLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    //ui->variableSwitchRxZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->variableSwitchRxZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    //ui->variableSwitchRxSubZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->variableSwitchRxSubZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    ui->variableSwitchRxHeadLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}"), this ));
    ui->variableSwitchRxObidLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,8}"), this ));

    ui->variableSwitchVariableAllowedFromLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9\\-\\:\\s]{1,19}"), this ));
    ui->variableSwitchVariableAllowedToLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9\\-\\:\\s]{1,19}"), this ));
    ui->variableSwitchVariableAllowedTimeLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9\\-\\:\\s]{1,19}"), this ));

    //groupId validator
    ui->variableSwitchVariableGroupIdLineEdit->setValidator(new QRegExpValidator( QRegExp("[a-zA-Z0-9_]*"), this ));

    //set the list for Action - sliderVariableActionListWidget
    for(int i=0; i< listAction.size() ; i++)
    {
        ui->variableSwitchVariableActionListWidget->addItem(listAction.at(i));
    }
    // set the list for priority
    for(int i=0; i< listPriority.size() ; i++)
    {
        ui->variableSwitchVariablePriorityListWidget->addItem(listPriority.at(i));
    }

    ui->variableSwitchVariableActionParametersLineEdit->setReadOnly(true);
    ui->variableSwitchTxTimeStampLineEdit->setReadOnly(true);
    ui->variableSwitchTxDataLineEdit->setReadOnly(true);
    ui->variableSwitchRxTimeStampLineEdit->setReadOnly(true);
    ui->variableSwitchRxDataLineEdit->setReadOnly(true);
    //domain should be fixed
    ui->variableSwitchDomainLineEdit->setReadOnly(true);

    //Copy slider packet to Dialog
    CopyVariableSwitchPacket();

}

//Copy slider packet to Dialog
void WidgetWebsocketPacketVariableSwitch::CopyVariableSwitchPacket()
{
    QString action;
    QString tempString;
    QString parameterStringValue;
    QListWidgetItem dummyCurrentItem;
    QListWidgetItem dummyPreviousItem;
    int classIndex = 0;
    int typeIndex = 0;
    int actionval;
    //websocket
    ui->variableSwitchIncIdValueLabel->setText(variableSwitchPacket_modify.idIncImage);
    ui->variableSwitchDecIdValueLabel->setText(variableSwitchPacket_modify.idDecImage);
    ui->variableSwitchLocalTxtIdValueLabel->setText(variableSwitchPacket_modify.idLocalTxt);
    ui->variableSwitchRemoteTxtIdValueLabel->setText(variableSwitchPacket_modify.idRemoteTxt);
    ui->variableSwitchUrlLineEdit->setText(variableSwitchPacket_modify.url);
    ui->variableSwitchMaxLineEdit->setText(variableSwitchPacket_modify.maxValue);
    ui->variableSwitchMinLineEdit->setText(variableSwitchPacket_modify.minValue);
    ui->variableSwitchUsernameLineEdit->setText(variableSwitchPacket_modify.userName);
    ui->variableSwitchPasswordLineEdit->setText(variableSwitchPacket_modify.passWord);
    //domain should be fixed for this release
    ui->variableSwitchDomainLineEdit->setText("mydomain.com");

    //Tx event
    tempString = variableSwitchPacket_modify.txEvent.class_value;
    if(tempString == VSCP_CLASS1_INFORMATION_VALUE)
    {
        classIndex = 0; //information
        tempString = variableSwitchPacket_modify.txEvent.type_value;
        typeIndex = ClassTypeObject.getInformationTypeListIndex(tempString);
    }
    else if(tempString == VSCP_CLASS1_CONTROL_VALUE)
    {
        classIndex = 1; //control
        tempString = variableSwitchPacket_modify.txEvent.type_value;
        typeIndex = ClassTypeObject.getControlTypeListIndex(tempString);
    }
    else
    {
        // Do nothing
    }
    ui->variableSwitchTxClassListWidget->setCurrentRow(classIndex);
       // set the value of the type list
        on_variableSwitchTxClassListWidget_currentItemChanged(&dummyCurrentItem, &dummyPreviousItem);
    ui->variableSwitchTxTypeListWidget->setCurrentRow(typeIndex);
    ui->variableSwitchTxGuidLineEdit->setText(variableSwitchPacket_modify.txEvent.guid);
    ui->variableSwitchTxZoneLineEdit->setText(variableSwitchPacket_modify.txEvent.zone);
    ui->variableSwitchTxSubZoneLineEdit->setText(variableSwitchPacket_modify.txEvent.subzone);
    ui->variableSwitchTxHeadLineEdit->setText(variableSwitchPacket_modify.txEvent.head);
    ui->variableSwitchTxObidLineEdit->setText(variableSwitchPacket_modify.txEvent.obid);
    ui->variableSwitchTxTimeStampLineEdit->setText(variableSwitchPacket_modify.txEvent.timeStamp);
    ui->variableSwitchTxDataLineEdit->setText(variableSwitchPacket_modify.txEvent.data);

    //Rx event
    tempString = variableSwitchPacket_modify.rxEvent.class_value;
    if(tempString == VSCP_CLASS1_INFORMATION_VALUE)
    {
        classIndex = 0; //information
        tempString = variableSwitchPacket_modify.rxEvent.type_value;
        typeIndex = ClassTypeObject.getInformationTypeListIndex(tempString);
    }
    else if(tempString == VSCP_CLASS1_CONTROL_VALUE)
    {
        classIndex = 1; //information
        tempString = variableSwitchPacket_modify.rxEvent.type_value;
        typeIndex = ClassTypeObject.getControlTypeListIndex(tempString);        
    }
    else
    {
        // Do nothing
    }
    ui->variableSwitchRxClassListWidget->setCurrentRow(classIndex);
        // set the value of the type list
         on_variableSwitchRxClassListWidget_currentItemChanged(&dummyCurrentItem, &dummyPreviousItem);
    ui->variableSwitchRxTypeListWidget->setCurrentRow(typeIndex);
    ui->variableSwitchRxGuidLineEdit->setText(variableSwitchPacket_modify.rxEvent.guid);
    ui->variableSwitchRxZoneLineEdit->setText(variableSwitchPacket_modify.rxEvent.zone);
    ui->variableSwitchRxSubZoneLineEdit->setText(variableSwitchPacket_modify.rxEvent.subzone);
    ui->variableSwitchRxHeadLineEdit->setText(variableSwitchPacket_modify.rxEvent.head);
    ui->variableSwitchRxObidLineEdit->setText(variableSwitchPacket_modify.rxEvent.obid);
    ui->variableSwitchRxTimeStampLineEdit->setText(variableSwitchPacket_modify.rxEvent.timeStamp);
    ui->variableSwitchRxDataLineEdit->setText(variableSwitchPacket_modify.rxEvent.data);

    //Variable
    ui->variableSwitchVariableNameValueLabel->setText(variableSwitchPacket_modify.packetVariableSwitchVariable.name);
    ui->variableSwitchVariableAllowedFromLineEdit->setText(variableSwitchPacket_modify.packetVariableSwitchVariable.allowedFrom);
    ui->variableSwitchVariableAllowedToLineEdit->setText(variableSwitchPacket_modify.packetVariableSwitchVariable.allowedTo);
    ui->variableSwitchVariableAllowedTimeLineEdit->setText(variableSwitchPacket_modify.packetVariableSwitchVariable.allowedTime);
    if(variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.mon == "true")
    {
        ui->variableSwitchVariableAllowedDaysMondaycheckBox->setChecked(true);
    }
    else
    {
        ui->variableSwitchVariableAllowedDaysMondaycheckBox->setChecked(false);
    }

    if(variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.tue == "true")
    {
        ui->variableSwitchVariableAllowedDaysTuesdaycheckBox->setChecked(true);
    }
    else
    {
        ui->variableSwitchVariableAllowedDaysTuesdaycheckBox->setChecked(false);
    }

    if(variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.wed == "true")
    {
        ui->variableSwitchVariableAllowedDaysWednesdaycheckBox->setChecked(true);
    }
    else
    {
        ui->variableSwitchVariableAllowedDaysWednesdaycheckBox->setChecked(false);
    }

    if(variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.thur == "true")
    {
        ui->variableSwitchVariableAllowedDaysThursdaycheckBox->setChecked(true);
    }
    else
    {
        ui->variableSwitchVariableAllowedDaysThursdaycheckBox->setChecked(false);
    }

    if(variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.fri == "true")
    {
        ui->variableSwitchVariableAllowedDaysFridaycheckBox->setChecked(true);
    }
    else
    {
        ui->variableSwitchVariableAllowedDaysFridaycheckBox->setChecked(false);
    }

    if(variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.sat == "true")
    {
        ui->variableSwitchVariableAllowedDaysSaturdaycheckBox->setChecked(true);
    }
    else
    {
        ui->variableSwitchVariableAllowedDaysSaturdaycheckBox->setChecked(false);
    }

    if(variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.sun == "true")
    {
        ui->variableSwitchVariableAllowedDaysSundaycheckBox->setChecked(true);
    }
    else
    {
        ui->variableSwitchVariableAllowedDaysSundaycheckBox->setChecked(false);
    }
    action = variableSwitchPacket_modify.packetVariableSwitchVariable.action;
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
    ui->variableSwitchVariableActionListWidget->setCurrentRow(actionval);
    //ui->variableSwitchVariableActionParametersLineEdit->setText(variableSwitchPacket_modify.packetVariableSwitchVariable.actionParameters);
        //parameterStringValue = variableSwitchPacket_modify.packetVariableSwitchVariable.name + ",3,true,\"0x60,0,%event.data[0]\"";
        parameterStringValue = variableSwitchPacket_modify.packetVariableSwitchVariable.name + ";3;true;%event.data[0]";

        ui->variableSwitchVariableActionParametersLineEdit->setText(parameterStringValue);
    ui->variableSwitchVariableCommentsLineEdit->setText(variableSwitchPacket_modify.packetVariableSwitchVariable.comments);
    if(variableSwitchPacket_modify.packetVariableSwitchVariable.control.EnableRow == "true")
    {
        ui->variableSwitchVariableControlEnableRowcheckBox->setChecked(true);
    }
    else
    {
        ui->variableSwitchVariableControlEnableRowcheckBox->setChecked(false);
    }

    /*if(variableSwitchPacket_modify.packetVariableSwitchVariable.control.checkIndex == "true")
    {
        ui->variableSwitchVariableControlCheckIndexcheckBox->setChecked(true);
    }
    else
    {
        ui->variableSwitchVariableControlCheckIndexcheckBox->setChecked(false);
    }*/

    if(variableSwitchPacket_modify.packetVariableSwitchVariable.control.checkzone == "true")
    {
        ui->variableSwitchVariableControlCheckZonecheckBox->setChecked(true);
    }
    else
    {
        ui->variableSwitchVariableControlCheckZonecheckBox->setChecked(false);
    }

    if(variableSwitchPacket_modify.packetVariableSwitchVariable.control.checkSubzone == "true")
    {
        ui->variableSwitchVariableControlCheckSubzonecheckBox->setChecked(true);
    }
    else
    {
        ui->variableSwitchVariableControlCheckSubzonecheckBox->setChecked(false);
    }

    if(variableSwitchPacket_modify.packetVariableSwitchVariable.control.endScan == "true")
    {
        ui->variableSwitchVariableControlEndScancheckBox->setChecked(true);
    }
    else
    {
        ui->variableSwitchVariableControlEndScancheckBox->setChecked(false);
    }

    ui->variableSwitchVariableGroupIdLineEdit->setText(variableSwitchPacket_modify.packetVariableSwitchVariable.groupId);
    // todo --> ui->variableSwitchVariableClassLineEdit->setText(variableSwitchPacket_modify.packetVariableSwitchVariable.class_value);
    // todo --> ui->variableSwitchVariableTypeLineEdit->setText(variableSwitchPacket_modify.packetVariableSwitchVariable.type_value);
    ui->variableSwitchVariableGuidLineEdit->setText(variableSwitchPacket_modify.packetVariableSwitchVariable.guid);
    ui->variableSwitchVariablePriorityListWidget->setCurrentRow(variableSwitchPacket_modify.packetVariableSwitchVariable.priority.toInt());
    ui->variableSwitchVariableZoneLineEdit->setText(variableSwitchPacket_modify.packetVariableSwitchVariable.zone);
    ui->variableSwitchVariableSubzoneLineEdit->setText(variableSwitchPacket_modify.packetVariableSwitchVariable.subzone);


}

void WidgetWebsocketPacketVariableSwitch::setListValue()
{
    listClass << VSCP_CLASS1_INFORMATION << VSCP_CLASS1_CONTROL ;

    listType   << VSCP_TYPE_INFORMATION_GENERAL << VSCP_TYPE_INFORMATION_BUTTON << VSCP_TYPE_INFORMATION_MOUSE
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

void WidgetWebsocketPacketVariableSwitch::on_variableSwitchTxClassListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{

    if(ui->variableSwitchTxClassListWidget->currentItem()->text() == VSCP_CLASS1_INFORMATION)
    {
        ui->variableSwitchTxTypeListWidget->clear();
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
            ui->variableSwitchTxTypeListWidget->addItem(listType.at(i));
        }
        ui->variableSwitchTxTypeListWidget->setCurrentRow(0);

    }
    else if(ui->variableSwitchTxClassListWidget->currentItem()->text() == VSCP_CLASS1_CONTROL)
    {
        ui->variableSwitchTxTypeListWidget->clear();
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
            ui->variableSwitchTxTypeListWidget->addItem(listType.at(i));
        }
        ui->variableSwitchTxTypeListWidget->setCurrentRow(0);

    }
    else{
        // do nothing
    }

}

void WidgetWebsocketPacketVariableSwitch::on_variableSwitchRxClassListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{

    if(ui->variableSwitchRxClassListWidget->currentItem()->text() == VSCP_CLASS1_INFORMATION)
    {
        ui->variableSwitchRxTypeListWidget->clear();
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
            ui->variableSwitchRxTypeListWidget->addItem(listType.at(i));
        }
        ui->variableSwitchRxTypeListWidget->setCurrentRow(0);

    }
    else if(ui->variableSwitchRxClassListWidget->currentItem()->text() == VSCP_CLASS1_CONTROL)
    {
        ui->variableSwitchRxTypeListWidget->clear();
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
            ui->variableSwitchRxTypeListWidget->addItem(listType.at(i));
        }
        ui->variableSwitchRxTypeListWidget->setCurrentRow(0);

    }
    else{
        // do nothing
    }

}

void WidgetWebsocketPacketVariableSwitch::on_OkvariableSwitchPushButton_clicked()
{
    QString action;
    QString tempStringClass;
    QString tempStringType;
    //websocket
    variableSwitchPacket_modify.idIncImage = ui->variableSwitchIncIdValueLabel->text();
    variableSwitchPacket_modify.idDecImage = ui->variableSwitchDecIdValueLabel->text();
    variableSwitchPacket_modify.idLocalTxt = ui->variableSwitchLocalTxtIdValueLabel->text();
    variableSwitchPacket_modify.idRemoteTxt = ui->variableSwitchRemoteTxtIdValueLabel->text();
    variableSwitchPacket_modify.url = ui->variableSwitchUrlLineEdit->text();
    variableSwitchPacket_modify.maxValue = ui->variableSwitchMaxLineEdit->text();
    variableSwitchPacket_modify.minValue = ui->variableSwitchMinLineEdit->text();
    variableSwitchPacket_modify.userName = ui->variableSwitchUsernameLineEdit->text();
    variableSwitchPacket_modify.passWord = ui->variableSwitchPasswordLineEdit->text();
    variableSwitchPacket_modify.domain = ui->variableSwitchDomainLineEdit->text();

    //Tx event
    //ui->variableSwitchTxClassListWidget->setCurrentRow(variableSwitchPacket_modify.txEvent.class_value.toInt());
    if( ui->variableSwitchTxClassListWidget->currentItem()->text() == VSCP_CLASS1_INFORMATION)
    {
        tempStringClass = VSCP_CLASS1_INFORMATION_VALUE;
        tempStringType = ui->variableSwitchTxTypeListWidget->currentItem()->text();
        ClassTypeObject.getInformationTypeValue(tempStringType);
    }
    else if ( ui->variableSwitchTxClassListWidget->currentItem()->text() == VSCP_CLASS1_CONTROL)
    {
        tempStringClass = VSCP_CLASS1_CONTROL_VALUE;
        tempStringType = ui->variableSwitchTxTypeListWidget->currentItem()->text();
        ClassTypeObject.getControlTypeValue(tempStringType);
    }
    else
    {
        // Do nothing
    }
    //variableSwitchPacket_modify.txEvent.class_value = QString:tempStringType:number( ui->variableSwitchTxClassListWidget->currentRow());
    variableSwitchPacket_modify.txEvent.class_value = tempStringClass;
    //ui->variableSwitchTxTypeListWidget->setCurrentRow(variableSwitchPacket_modify.txEvent.type_value.toInt());
    variableSwitchPacket_modify.txEvent.type_value = tempStringType;
    variableSwitchPacket_modify.txEvent.guid = ui->variableSwitchTxGuidLineEdit->text();
    variableSwitchPacket_modify.txEvent.zone = ui->variableSwitchTxZoneLineEdit->text();
    variableSwitchPacket_modify.txEvent.subzone = ui->variableSwitchTxSubZoneLineEdit->text();
    variableSwitchPacket_modify.txEvent.head = ui->variableSwitchTxHeadLineEdit->text();
    variableSwitchPacket_modify.txEvent.obid = ui->variableSwitchTxObidLineEdit->text();
    variableSwitchPacket_modify.txEvent.timeStamp = ui->variableSwitchTxTimeStampLineEdit->text();
    variableSwitchPacket_modify.txEvent.data = ui->variableSwitchTxDataLineEdit->text();

    //Rx event
    //ui->variableSwitchRxClassListWidget->setCurrentRow(variableSwitchPacket_modify.rxEvent.class_value.toInt());
    if( ui->variableSwitchRxClassListWidget->currentItem()->text() == VSCP_CLASS1_INFORMATION)
    {
        tempStringClass = VSCP_CLASS1_INFORMATION_VALUE;
        tempStringType = ui->variableSwitchRxTypeListWidget->currentItem()->text();
        ClassTypeObject.getInformationTypeValue(tempStringType);
    }
    else if ( ui->variableSwitchRxClassListWidget->currentItem()->text() == VSCP_CLASS1_CONTROL)
    {
        tempStringClass = VSCP_CLASS1_CONTROL_VALUE;
        tempStringType = ui->variableSwitchRxTypeListWidget->currentItem()->text();
        ClassTypeObject.getControlTypeValue(tempStringType);
    }
    else
    {
        // Do nothing
    }
    //variableSwitchPacket_modify.rxEvent.class_value = QString:tempStringType:number( ui->variableSwitchRxClassListWidget->currentRow());
    variableSwitchPacket_modify.rxEvent.class_value = tempStringClass;
    //ui->variableSwitchRxTypeListWidget->setCurrentRow(variableSwitchPacket_modify.rxEvent.type_value.toInt());
    variableSwitchPacket_modify.rxEvent.type_value = tempStringType;
    variableSwitchPacket_modify.rxEvent.guid = ui->variableSwitchRxGuidLineEdit->text();
    variableSwitchPacket_modify.rxEvent.zone = ui->variableSwitchRxZoneLineEdit->text();
    variableSwitchPacket_modify.rxEvent.subzone = ui->variableSwitchRxSubZoneLineEdit->text();
    variableSwitchPacket_modify.rxEvent.head = ui->variableSwitchRxHeadLineEdit->text();
    variableSwitchPacket_modify.rxEvent.obid = ui->variableSwitchRxObidLineEdit->text();
    variableSwitchPacket_modify.rxEvent.timeStamp = ui->variableSwitchRxTimeStampLineEdit->text();
    variableSwitchPacket_modify.rxEvent.data = ui->variableSwitchRxDataLineEdit->text();


    //Variable
    variableSwitchPacket_modify.packetVariableSwitchVariable.name = ui->variableSwitchVariableNameValueLabel->text();
    variableSwitchPacket_modify.packetVariableSwitchVariable.allowedFrom = ui->variableSwitchVariableAllowedFromLineEdit->text();
    variableSwitchPacket_modify.packetVariableSwitchVariable.allowedTo = ui->variableSwitchVariableAllowedToLineEdit->text();
    variableSwitchPacket_modify.packetVariableSwitchVariable.allowedTime = ui->variableSwitchVariableAllowedTimeLineEdit->text();
    if(ui->variableSwitchVariableAllowedDaysMondaycheckBox->isChecked())
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.mon = "true";
    }
    else
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.mon = "false";
    }

    if(ui->variableSwitchVariableAllowedDaysTuesdaycheckBox->isChecked())
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.tue = "true";
    }
    else
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.tue = "false";
    }

    if(ui->variableSwitchVariableAllowedDaysWednesdaycheckBox->isChecked())
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.wed = "true";
    }
    else
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.wed = "false";
    }

    if(ui->variableSwitchVariableAllowedDaysThursdaycheckBox->isChecked())
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.thur = "true";
    }
    else
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.thur = "false";
    }

    if(ui->variableSwitchVariableAllowedDaysFridaycheckBox->isChecked())
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.fri = "true";
    }
    else
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.fri = "false";
    }

    if(ui->variableSwitchVariableAllowedDaysSaturdaycheckBox->isChecked())
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.sat = "true";
    }
    else
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.sat = "false";
    }

    if(ui->variableSwitchVariableAllowedDaysSundaycheckBox->isChecked())
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.sun = "true";
    }
    else
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.allowedDays.sun = "false";
    }
    action = ui->variableSwitchVariableActionListWidget->currentItem()->text();
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
    //ui->variableSwitchVariableActionListWidget->setCurrentRow(variableSwitchPacket_modify.packetVariableSwitchVariable.action.toInt());
    variableSwitchPacket_modify.packetVariableSwitchVariable.action = action;
    variableSwitchPacket_modify.packetVariableSwitchVariable.actionParameters = ui->variableSwitchVariableActionParametersLineEdit->text();
    variableSwitchPacket_modify.packetVariableSwitchVariable.comments = ui->variableSwitchVariableCommentsLineEdit->text();
    if(ui->variableSwitchVariableControlEnableRowcheckBox->isChecked())
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.control.EnableRow = "true";
    }
    else
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.control.EnableRow = "false";
    }

    /*if(ui->variableSwitchVariableControlCheckIndexcheckBox->isChecked())
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.control.checkIndex = "true";
    }
    else
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.control.checkIndex = "false";;
    }*/
    variableSwitchPacket_modify.packetVariableSwitchVariable.control.checkIndex = "false";;

    if(ui->variableSwitchVariableControlCheckZonecheckBox->isChecked())
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.control.checkzone = "true";
    }
    else
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.control.checkzone = "false";
    }

    if(ui->variableSwitchVariableControlCheckSubzonecheckBox->isChecked())
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.control.checkSubzone = "true";
    }
    else
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.control.checkSubzone = "false";
    }

    if(ui->variableSwitchVariableControlEndScancheckBox->isChecked())
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.control.endScan = "true";
    }
    else
    {
        variableSwitchPacket_modify.packetVariableSwitchVariable.control.endScan = "false";
    }

    variableSwitchPacket_modify.packetVariableSwitchVariable.groupId = ui->variableSwitchVariableGroupIdLineEdit->text();
    // todo --> variableSwitchPacket_modify.packetVariableSwitchVariable.class_value = ui->variableSwitchVariableClassLineEdit->text();
    variableSwitchPacket_modify.packetVariableSwitchVariable.class_value = variableSwitchPacket_modify.rxEvent.class_value;
    // todo --> variableSwitchPacket_modify.packetVariableSwitchVariable.type_value = ui->variableSwitchVariableTypeLineEdit->text();
    variableSwitchPacket_modify.packetVariableSwitchVariable.type_value = variableSwitchPacket_modify.rxEvent.type_value;
    variableSwitchPacket_modify.packetVariableSwitchVariable.guid = ui->variableSwitchVariableGuidLineEdit->text();
    //ui->variableSwitchVariablePriorityListWidget->setCurrentRow(variableSwitchPacket_modify.packetVariableSwitchVariable.priority.toInt());
    variableSwitchPacket_modify.packetVariableSwitchVariable.priority = QString::number( ui->variableSwitchVariablePriorityListWidget->currentRow());
    variableSwitchPacket_modify.packetVariableSwitchVariable.zone = ui->variableSwitchVariableZoneLineEdit->text();
    variableSwitchPacket_modify.packetVariableSwitchVariable.subzone = ui->variableSwitchVariableSubzoneLineEdit->text();


    //Emit a close handler
    emit close();
}

void WidgetWebsocketPacketVariableSwitch::on_CancelvariableSwitchPushButton_clicked()
{
    //Emit a close handler
    emit close();
}

WidgetWebsocketPacketVariableSwitch::~WidgetWebsocketPacketVariableSwitch()
{
    delete ui;
}
