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


#include "widgetwebsocketpacketsensor.h"
#include "ui_widgetwebsocketpacketsensor.h"

WidgetWebsocketPacketSensor::WidgetWebsocketPacketSensor(T_widgetwebsocketPacketsensor &sensorPacket, QWidget *parent) :
    QDialog(parent),
    sensorPacket_modify(sensorPacket),
    ui(new Ui::WidgetWebsocketPacketSensor)
{
    ui->setupUi(this);

    //ui->sensorUrlLineEdit->setValidator(new QRegExpValidator( QRegExp("[w]{1,1}[s]{1,1}[s]{1,1}\\:\\/\\/[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\:[0-9]{1,4}" ), this ));
    ui->sensorUrlLineEdit->setValidator(new QRegExpValidator( QRegExp("[w]{1,1}[s]{1,2}\\:\\/\\/[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\:[0-9]{1,4}" ), this ));

    setListValue();
    //class
    for(int i=0; i< listClass.size() ; i++)
    {
        ui->sensorClassListWidget->addItem(listClass.at(i));
        //ui->sensorClassListWidget->currentChanged();
    }
    ui->sensorClassListWidget->setCurrentRow(0);

    //type
    for(int i=0; i< listType.size() ; i++)
    {
        ui->sensorTypeListWidget->addItem(listType.at(i));
        //ui->sensorClassListWidget->currentChanged();
    }
    ui->sensorTypeListWidget->setCurrentRow(0);

    //set the list for Coding Index - sensorCodingIndexListWidget
    for(int i=0; i< listCodingIndex.size() ; i++)
    {
        ui->sensorCodingIndexListWidget->addItem(listCodingIndex.at(i));
    }
    ui->sensorCodingIndexListWidget->setCurrentRow(0);

    //data
    ui->sensorGuidLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}"), this ));
    ui->sensorDecimalsLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]"), this ));

    ui->sensorVariableAllowedFromLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9\\-\\:\\s]{1,19}"), this ));
    ui->sensorVariableAllowedToLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9\\-\\:\\s]{1,19}"), this ));
    ui->sensorVariableAllowedTimeLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9\\-\\:\\s]{1,19}"), this ));

    //groupId validator
    ui->sensorVariableGroupIdLineEdit->setValidator(new QRegExpValidator( QRegExp("[a-zA-Z0-9_]*"), this ));

    ui->sensorVariableIndexLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    ui->sensorVariableZoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));
    ui->sensorVariableSubzoneLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9]{1,3}"), this ));


    //set the list for Action - variableActionListWidget
    for(int i=0; i< listAction.size() ; i++)
    {
        ui->sensorVariableActionListWidget->addItem(listAction.at(i));
    }
    ui->sensorVariableActionListWidget->setCurrentRow(0);
    // set the list for priority
    for(int i=0; i< listPriority.size() ; i++)
    {
        ui->sensorVariablePriorityListWidget->addItem(listPriority.at(i));
    }
    ui->sensorVariablePriorityListWidget->setCurrentRow(0);
    ui->sensorVariableGuidLineEdit->setValidator(new QRegExpValidator( QRegExp("[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}\\:[0-9a-fxA-FX]{1,2}"), this ));

    // non editable
    ui->sensorVariableActionParametersLineEdit->setReadOnly(true);
    //ui->sensorVariableActionParametersLineEdit->setReadOnly(true);
    //domain should be fixed
    ui->sensorDomainLineEdit->setReadOnly(true);

    //Copy Sensor packet to Dialog
    CopySensorPacket();

    connect(ui->sensorClassListWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), this, SLOT(currentItemChanged_slot()));
}

void WidgetWebsocketPacketSensor::setListValue()
{
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
                     ; */

    //listClass << VSCP_CLASS1_INFORMATION << VSCP_CLASS1_CONTROL ;
    listClass << VSCP_CLASS1_MEASUREMENT << VSCP_CLASS1_MEASUREMENT64 << VSCP_CLASS1_MEASUREZONE;

    listType   << VSCP_TYPE_MEASUREMENT_GENERAL << VSCP_TYPE_MEASUREMENT_COUNT_I << VSCP_TYPE_MEASUREMENT_LENGTH
              << VSCP_TYPE_MEASUREMENT_MASS << VSCP_TYPE_MEASUREMENT_TIME << VSCP_TYPE_MEASUREMENT_ELECTRIC_CURRENT
              << VSCP_TYPE_MEASUREMENT_TEMPERATURE << VSCP_TYPE_MEASUREMENT_AMOUNT_OF_SUBSTANCE << VSCP_TYPE_MEASUREMENT_INTENSITY_OF_LIGHT
              << VSCP_TYPE_MEASUREMENT_FREQUENCY << VSCP_TYPE_MEASUREMENT_RADIOACTIVITY << VSCP_TYPE_MEASUREMENT_FORCE
              << VSCP_TYPE_MEASUREMENT_PRESSURE << VSCP_TYPE_MEASUREMENT_ENERGY << VSCP_TYPE_MEASUREMENT_POWER
              << VSCP_TYPE_MEASUREMENT_ELECTRICAL_CHARGE << VSCP_TYPE_MEASUREMENT_ELECTRICAL_POTENTIAL << VSCP_TYPE_MEASUREMENT_ELECTRICAL_CAPACITANCE
              << VSCP_TYPE_MEASUREMENT_ELECTRICAL_RESISTANCE << VSCP_TYPE_MEASUREMENT_ELECTRICAL_CONDUCTANCE << VSCP_TYPE_MEASUREMENT_MAGNETIC_FIELD_STRENGTH
              << VSCP_TYPE_MEASUREMENT_MAGNETIC_FLUX << VSCP_TYPE_MEASUREMENT_MAGNETIC_FLUX_DENSITY << VSCP_TYPE_MEASUREMENT_INDUCTANCE
              << VSCP_TYPE_MEASUREMENT_FLUX_OF_LIGHT << VSCP_TYPE_MEASUREMENT_ILLUMINANCE << VSCP_TYPE_MEASUREMENT_RADIATION_DOSE
              << VSCP_TYPE_MEASUREMENT_CATALYTIC_ACITIVITY << VSCP_TYPE_MEASUREMENT_VOLUME << VSCP_TYPE_MEASUREMENT_SOUND_INTENSITY
              << VSCP_TYPE_MEASUREMENT_ANGLE << VSCP_TYPE_MEASUREMENT_POSITION << VSCP_TYPE_MEASUREMENT_SPEED
              << VSCP_TYPE_MEASUREMENT_ACCELERATION << VSCP_TYPE_MEASUREMENT_TENSION << VSCP_TYPE_MEASUREMENT_HUMIDITY
              << VSCP_TYPE_MEASUREMENT_FLOW << VSCP_TYPE_MEASUREMENT_THERMAL_RESISTANCE << VSCP_TYPE_MEASUREMENT_REFRACTIVE_POWER
              << VSCP_TYPE_MEASUREMENT_DYNAMIC_VISCOSITY << VSCP_TYPE_MEASUREMENT_SOUND_IMPEDANCE << VSCP_TYPE_MEASUREMENT_SOUND_RESISTANCE
              << VSCP_TYPE_MEASUREMENT_ELECTRIC_ELASTANCE << VSCP_TYPE_MEASUREMENT_LUMINOUS_ENERGY << VSCP_TYPE_MEASUREMENT_LUMINANCE
              << VSCP_TYPE_MEASUREMENT_CHEMICAL_CONCENTRATION << VSCP_TYPE_MEASUREMENT_RESERVED << VSCP_TYPE_MEASUREMENT_DOSE_EQVIVALENT
              << VSCP_TYPE_MEASUREMENT_DEWPOINT << VSCP_TYPE_MEASUREMENT_RELATIVE_LEVEL << VSCP_TYPE_MEASUREMENT_ALTITUDE
              << VSCP_TYPE_MEASUREMENT_AREA << VSCP_TYPE_MEASUREMENT_RADIANT_INTENSITY << VSCP_TYPE_MEASUREMENT_RADIANCE
              << VSCP_TYPE_MEASUREMENT_IRRADIANCE << VSCP_TYPE_MEASUREMENT_SPECTRAL_RADIANCE << VSCP_TYPE_MEASUREMENT_SPECTRAL_IRRADIANCE
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

    listCodingIndex << SENSOR_CODING_INDEX_ZERO << SENSOR_CODING_INDEX_ONE << SENSOR_CODING_INDEX_TWO << SENSOR_CODING_INDEX_THREE
                    << SENSOR_CODING_INDEX_FOUR << SENSOR_CODING_INDEX_FIVE << SENSOR_CODING_INDEX_SIX << SENSOR_CODING_INDEX_SEVEN
                       ;

}

void WidgetWebsocketPacketSensor::currentItemChanged_slot()
{
   /*QMessageBox *msgBox 	= new QMessageBox();
   msgBox->setText("Item changed .... >>>> ");
    msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
    msgBox->exec();*/
    if(ui->sensorClassListWidget->currentItem()->text() == VSCP_CLASS1_INFORMATION)
    {
        ui->sensorTypeListWidget->clear();
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
            ui->sensorTypeListWidget->addItem(listType.at(i));
        }
        ui->sensorTypeListWidget->setCurrentRow(0);

    }
    else if(ui->sensorClassListWidget->currentItem()->text() == VSCP_CLASS1_CONTROL)
    {
        ui->sensorTypeListWidget->clear();
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
            ui->sensorTypeListWidget->addItem(listType.at(i));
        }
        ui->sensorTypeListWidget->setCurrentRow(0);

    }
    else{
        // do nothing
    }

}

//Copy Sensor packet to Dialog
void WidgetWebsocketPacketSensor::CopySensorPacket()
{
    QString action;
    QString parameterStringValue;
    int classIndex = 0;
    int typeIndex = 0;
    int actionval;

    //websocket
    ui->sensorIdValueLabel->setText(sensorPacket_modify.id);
    ui->sensorRemoteTxtIdValueLabel->setText(sensorPacket_modify.idRemoteTxt);
    ui->sensorUrlLineEdit->setText(sensorPacket_modify.url);
    ui->sensorUsernameLineEdit->setText(sensorPacket_modify.userName);
    ui->sensorPasswordLineEdit->setText(sensorPacket_modify.passWord);
    //domain should be fixed for this release
    ui->sensorDomainLineEdit->setText("mydomain.com");

    if(sensorPacket_modify.class_value == VSCP_CLASS1_MEASUREMENT_VALUE)
    {
        classIndex = 0; //i.e index of measurement class in list
    }
    else if(sensorPacket_modify.class_value == VSCP_CLASS1_MEASUREMENT64_VALUE)
    {
        classIndex = 1; //i.e index of measurement class in list
    }
    else if(sensorPacket_modify.class_value == VSCP_CLASS1_MEASUREZONE_VALUE)
    {
        classIndex = 2; //i.e index of measurement class in list
    }
    else
    {
        //do nothing
    }
    ui->sensorClassListWidget->setCurrentRow(classIndex);
    typeIndex = ClassTypeObject.getMeasurementTypeListIndex(sensorPacket_modify.type_value);
    ui->sensorTypeListWidget->setCurrentRow(typeIndex);
    ui->sensorCodingIndexListWidget->setCurrentRow(sensorPacket_modify.codingIndex.toInt());
    ui->sensorDecimalsLineEdit->setText(sensorPacket_modify.decimals);
    ui->sensorFormatStringLineEdit->setText(sensorPacket_modify.formatString);
    ui->sensorGuidLineEdit->setText(sensorPacket_modify.guid);
    ui->sensorCallBackLineEdit->setText(sensorPacket_modify.callback);

    //Variable
    ui->sensorVariableNameValueLabel->setText(sensorPacket_modify.packetSensorVariable.name);
    ui->sensorVariableAllowedFromLineEdit->setText(sensorPacket_modify.packetSensorVariable.allowedFrom);
    ui->sensorVariableAllowedToLineEdit->setText(sensorPacket_modify.packetSensorVariable.allowedTo);
    ui->sensorVariableAllowedTimeLineEdit->setText(sensorPacket_modify.packetSensorVariable.allowedTime);
    if(sensorPacket_modify.packetSensorVariable.allowedDays.mon == "true")
    {
        ui->sensorVariableAllowedDaysMondaycheckBox->setChecked(true);
    }
    else
    {
        ui->sensorVariableAllowedDaysMondaycheckBox->setChecked(false);
    }

    if(sensorPacket_modify.packetSensorVariable.allowedDays.tue == "true")
    {
        ui->sensorVariableAllowedDaysTuesdaycheckBox->setChecked(true);
    }
    else
    {
        ui->sensorVariableAllowedDaysTuesdaycheckBox->setChecked(false);
    }

    if(sensorPacket_modify.packetSensorVariable.allowedDays.wed == "true")
    {
        ui->sensorVariableAllowedDaysWednesdaycheckBox->setChecked(true);
    }
    else
    {
        ui->sensorVariableAllowedDaysWednesdaycheckBox->setChecked(false);
    }

    if(sensorPacket_modify.packetSensorVariable.allowedDays.thur == "true")
    {
        ui->sensorVariableAllowedDaysThursdaycheckBox->setChecked(true);
    }
    else
    {
        ui->sensorVariableAllowedDaysThursdaycheckBox->setChecked(false);
    }

    if(sensorPacket_modify.packetSensorVariable.allowedDays.fri == "true")
    {
        ui->sensorVariableAllowedDaysFridaycheckBox->setChecked(true);
    }
    else
    {
        ui->sensorVariableAllowedDaysFridaycheckBox->setChecked(false);
    }

    if(sensorPacket_modify.packetSensorVariable.allowedDays.sat == "true")
    {
        ui->sensorVariableAllowedDaysSaturdaycheckBox->setChecked(true);
    }
    else
    {
        ui->sensorVariableAllowedDaysSaturdaycheckBox->setChecked(false);
    }

    if(sensorPacket_modify.packetSensorVariable.allowedDays.sun == "true")
    {
        ui->sensorVariableAllowedDaysSundaycheckBox->setChecked(true);
    }
    else
    {
        ui->sensorVariableAllowedDaysSundaycheckBox->setChecked(false);
    }
    action = sensorPacket_modify.packetSensorVariable.action;
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
    ui->sensorVariableActionListWidget->setCurrentRow(actionval);
    //ui->sensorVariableActionParametersLineEdit->setText(sensorPacket_modify.packetSensorVariable.actionParameters);
        parameterStringValue = sensorPacket_modify.packetSensorVariable.name + ";9;true;%event.data";
        ui->sensorVariableActionParametersLineEdit->setText(parameterStringValue);
    ui->sensorVariableCommentsLineEdit->setText(sensorPacket_modify.packetSensorVariable.comments);
    if(sensorPacket_modify.packetSensorVariable.control.EnableRow == "true")
    {
        ui->sensorVariableControlEnableRowcheckBox->setChecked(true);
    }
    else
    {
        ui->sensorVariableControlEnableRowcheckBox->setChecked(false);
    }

    if(sensorPacket_modify.packetSensorVariable.control.checkIndex == "true")
    {
        ui->sensorVariableControlCheckIndexcheckBox->setChecked(true);
    }
    else
    {
        ui->sensorVariableControlCheckIndexcheckBox->setChecked(false);
    }

    if(sensorPacket_modify.packetSensorVariable.control.checkzone == "true")
    {
        ui->sensorVariableControlCheckZonecheckBox->setChecked(true);
    }
    else
    {
        ui->sensorVariableControlCheckZonecheckBox->setChecked(false);
    }

    if(sensorPacket_modify.packetSensorVariable.control.checkSubzone == "true")
    {
        ui->sensorVariableControlCheckSubzonecheckBox->setChecked(true);
    }
    else
    {
        ui->sensorVariableControlCheckSubzonecheckBox->setChecked(false);
    }

    if(sensorPacket_modify.packetSensorVariable.control.endScan == "true")
    {
        ui->sensorVariableControlEndScancheckBox->setChecked(true);
    }
    else
    {
        ui->sensorVariableControlEndScancheckBox->setChecked(false);
    }

    ui->sensorVariableGroupIdLineEdit->setText(sensorPacket_modify.packetSensorVariable.groupId);
    // todo --> ui->sensorVariableClassLineEdit->setText(sensorPacket_modify.packetSensorVariable.class_value);
    // todo --> ui->sensorVariableTypeLineEdit->setText(sensorPacket_modify.packetSensorVariable.type_value);
    ui->sensorVariableGuidLineEdit->setText(sensorPacket_modify.packetSensorVariable.guid);
    ui->sensorVariablePriorityListWidget->setCurrentRow(sensorPacket_modify.packetSensorVariable.priority.toInt());
    ui->sensorVariableIndexLineEdit->setText(sensorPacket_modify.packetSensorVariable.index);
    ui->sensorVariableZoneLineEdit->setText(sensorPacket_modify.packetSensorVariable.zone);
    ui->sensorVariableSubzoneLineEdit->setText(sensorPacket_modify.packetSensorVariable.subzone);


}

void WidgetWebsocketPacketSensor::on_OkSensorPushButton_clicked()
{
    QString action;
    QString typeValue;
    //websocket
    sensorPacket_modify.id  =  ui->sensorIdValueLabel->text();
    sensorPacket_modify.idRemoteTxt = ui->sensorRemoteTxtIdValueLabel->text();
    sensorPacket_modify.url = ui->sensorUrlLineEdit->text();

    sensorPacket_modify.userName = ui->sensorUsernameLineEdit->text();
    sensorPacket_modify.passWord = ui->sensorPasswordLineEdit->text();
    sensorPacket_modify.domain = ui->sensorDomainLineEdit->text();

    //ui->sensorClassListWidget->setCurrentRow(sensorPacket_modify.class_value.toInt());
    if(ui->sensorClassListWidget->currentItem()->text() == VSCP_CLASS1_MEASUREMENT)
    {
        sensorPacket_modify.class_value = VSCP_CLASS1_MEASUREMENT_VALUE;
    }
    else if(ui->sensorClassListWidget->currentItem()->text() == VSCP_CLASS1_MEASUREMENT64)
    {
        sensorPacket_modify.class_value = VSCP_CLASS1_MEASUREMENT64_VALUE;
    }
    else if(ui->sensorClassListWidget->currentItem()->text() == VSCP_CLASS1_MEASUREZONE)
    {
        sensorPacket_modify.class_value = VSCP_CLASS1_MEASUREZONE_VALUE;
    }
    else
    {
        //do nothing
    }
    //sensorPacket_modify.class_value = QString::number( ui->sensorClassListWidget->currentRow());
    //ui->sensorTypeListWidget->setCurrentRow(sensorPacket_modify.type_value.toInt());
    typeValue = ui->sensorTypeListWidget->currentItem()->text();
    ClassTypeObject.getMeasurementTypeValue(typeValue);
    sensorPacket_modify.type_value = typeValue;
    //ui->sensorCodingIndexListWidget->setCurrentRow(sensorPacket_modify.codingIndex.toInt());
    sensorPacket_modify.codingIndex = QString::number( ui->sensorCodingIndexListWidget->currentRow());
    sensorPacket_modify.decimals = ui->sensorDecimalsLineEdit->text();
    sensorPacket_modify.formatString = ui->sensorFormatStringLineEdit->text();
    sensorPacket_modify.guid = ui->sensorGuidLineEdit->text();
    sensorPacket_modify.callback = ui->sensorCallBackLineEdit->text();

    //Variable
    sensorPacket_modify.packetSensorVariable.name = ui->sensorVariableNameValueLabel->text();
    sensorPacket_modify.packetSensorVariable.allowedFrom = ui->sensorVariableAllowedFromLineEdit->text();
    sensorPacket_modify.packetSensorVariable.allowedTo = ui->sensorVariableAllowedToLineEdit->text();
    sensorPacket_modify.packetSensorVariable.allowedTime = ui->sensorVariableAllowedTimeLineEdit->text();
    if(ui->sensorVariableAllowedDaysMondaycheckBox->isChecked())
    {
        sensorPacket_modify.packetSensorVariable.allowedDays.mon = "true";
    }
    else
    {
        sensorPacket_modify.packetSensorVariable.allowedDays.mon = "false";
    }

    if(ui->sensorVariableAllowedDaysTuesdaycheckBox->isChecked())
    {
        sensorPacket_modify.packetSensorVariable.allowedDays.tue = "true";
    }
    else
    {
        sensorPacket_modify.packetSensorVariable.allowedDays.tue = "false";
    }

    if(ui->sensorVariableAllowedDaysWednesdaycheckBox->isChecked())
    {
        sensorPacket_modify.packetSensorVariable.allowedDays.wed = "true";
    }
    else
    {
        sensorPacket_modify.packetSensorVariable.allowedDays.wed = "false";
    }

    if(ui->sensorVariableAllowedDaysThursdaycheckBox->isChecked())
    {
        sensorPacket_modify.packetSensorVariable.allowedDays.thur = "true";
    }
    else
    {
        sensorPacket_modify.packetSensorVariable.allowedDays.thur = "false";
    }

    if(ui->sensorVariableAllowedDaysFridaycheckBox->isChecked())
    {
        sensorPacket_modify.packetSensorVariable.allowedDays.fri = "true";
    }
    else
    {
        sensorPacket_modify.packetSensorVariable.allowedDays.fri = "false";
    }

    if(ui->sensorVariableAllowedDaysSaturdaycheckBox->isChecked())
    {
        sensorPacket_modify.packetSensorVariable.allowedDays.sat = "true";
    }
    else
    {
        sensorPacket_modify.packetSensorVariable.allowedDays.sat = "false";
    }

    if(ui->sensorVariableAllowedDaysSundaycheckBox->isChecked())
    {
        sensorPacket_modify.packetSensorVariable.allowedDays.sun = "true";
    }
    else
    {
        sensorPacket_modify.packetSensorVariable.allowedDays.sun = "false";
    }
    action = ui->sensorVariableActionListWidget->currentItem()->text();
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
    //ui->sensorVariableActionListWidget->setCurrentRow(sensorPacket_modify.packetSensorVariable.action.toInt());
    sensorPacket_modify.packetSensorVariable.action = action;
    sensorPacket_modify.packetSensorVariable.actionParameters = ui->sensorVariableActionParametersLineEdit->text();
    sensorPacket_modify.packetSensorVariable.comments = ui->sensorVariableCommentsLineEdit->text();
    if(ui->sensorVariableControlEnableRowcheckBox->isChecked())
    {
        sensorPacket_modify.packetSensorVariable.control.EnableRow = "true";
    }
    else
    {
        sensorPacket_modify.packetSensorVariable.control.EnableRow = "false";
    }

    if(ui->sensorVariableControlCheckIndexcheckBox->isChecked())
    {
        sensorPacket_modify.packetSensorVariable.control.checkIndex = "true";
    }
    else
    {
        sensorPacket_modify.packetSensorVariable.control.checkIndex = "false";;
    }

    if(ui->sensorVariableControlCheckZonecheckBox->isChecked())
    {
        sensorPacket_modify.packetSensorVariable.control.checkzone = "true";
    }
    else
    {
        sensorPacket_modify.packetSensorVariable.control.checkzone = "false";
    }

    if(ui->sensorVariableControlCheckSubzonecheckBox->isChecked())
    {
        sensorPacket_modify.packetSensorVariable.control.checkSubzone = "true";
    }
    else
    {
        sensorPacket_modify.packetSensorVariable.control.checkSubzone = "false";
    }

    if(ui->sensorVariableControlEndScancheckBox->isChecked())
    {
        sensorPacket_modify.packetSensorVariable.control.endScan = "true";
    }
    else
    {
        sensorPacket_modify.packetSensorVariable.control.endScan = "false";
    }

    sensorPacket_modify.packetSensorVariable.groupId = ui->sensorVariableGroupIdLineEdit->text();
    // todo --> sensorPacket_modify.packetSensorVariable.class_value = ui->sensorVariableClassLineEdit->text();
    sensorPacket_modify.packetSensorVariable.class_value = sensorPacket_modify.class_value;
    // todo --> sensorPacket_modify.packetSensorVariable.type_value = ui->sensorVariableTypeLineEdit->text();
    sensorPacket_modify.packetSensorVariable.type_value = sensorPacket_modify.type_value;
    sensorPacket_modify.packetSensorVariable.guid = ui->sensorVariableGuidLineEdit->text();
    //ui->sensorVariablePriorityListWidget->setCurrentRow(sensorPacket_modify.packetSensorVariable.priority.toInt());
    sensorPacket_modify.packetSensorVariable.priority = QString::number( ui->sensorVariablePriorityListWidget->currentRow());
    sensorPacket_modify.packetSensorVariable.index = ui->sensorVariableIndexLineEdit->text();
    sensorPacket_modify.packetSensorVariable.zone = ui->sensorVariableZoneLineEdit->text();
    sensorPacket_modify.packetSensorVariable.subzone = ui->sensorVariableSubzoneLineEdit->text();

    //Emit a close handler
    emit close();

}

void WidgetWebsocketPacketSensor::on_CancelSensorPushButton_clicked()
{
    //Emit a close handler
    emit close();
}

WidgetWebsocketPacketSensor::~WidgetWebsocketPacketSensor()
{
    delete ui;
}

