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


#include "vscpClassTypeObject.h"
#include <QMessageBox>

vscpClassTypeObject::vscpClassTypeObject()
{
    //Do nothing
}

void vscpClassTypeObject::getInformationTypeValue(QString &tempType)
{
    if(tempType == VSCP_TYPE_INFORMATION_GENERAL)
    {
        tempType = VSCP_TYPE_INFORMATION_GENERAL_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_BUTTON)
    {
        tempType = VSCP_TYPE_INFORMATION_BUTTON_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_MOUSE)
    {
        tempType = VSCP_TYPE_INFORMATION_MOUSE_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_ON)
    {
        tempType = VSCP_TYPE_INFORMATION_ON_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_OFF)
    {
        tempType = VSCP_TYPE_INFORMATION_OFF_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_ALIVE)
    {
        tempType = VSCP_TYPE_INFORMATION_ALIVE_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_TERMINATING)
    {
        tempType = VSCP_TYPE_INFORMATION_TERMINATING_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_OPENED)
    {
        tempType = VSCP_TYPE_INFORMATION_OPENED_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_CLOSED)
    {
        tempType = VSCP_TYPE_INFORMATION_CLOSED_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_NODE_HEARTBEAT)
    {
        tempType = VSCP_TYPE_INFORMATION_NODE_HEARTBEAT_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_BELOW_LIMIT)
    {
        tempType = VSCP_TYPE_INFORMATION_BELOW_LIMIT_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_ABOVE_LIMIT)
    {
        tempType = VSCP_TYPE_INFORMATION_ABOVE_LIMIT_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_PULSE)
    {
        tempType = VSCP_TYPE_INFORMATION_PULSE_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_ERROR)
    {
        tempType = VSCP_TYPE_INFORMATION_ERROR_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_RESUMED)
    {
        tempType = VSCP_TYPE_INFORMATION_RESUMED_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_PAUSED)
    {
        tempType = VSCP_TYPE_INFORMATION_PAUSED_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_PAUSED)
    {
        tempType = VSCP_TYPE_INFORMATION_PAUSED_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_SLEEP)
    {
        tempType = VSCP_TYPE_INFORMATION_SLEEP_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_GOOD_MORNING)
    {
        tempType = VSCP_TYPE_INFORMATION_GOOD_MORNING_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_GOOD_DAY)
    {
        tempType = VSCP_TYPE_INFORMATION_GOOD_DAY_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_GOOD_AFTERNOON)
    {
        tempType = VSCP_TYPE_INFORMATION_GOOD_AFTERNOON_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_GOOD_EVENING)
    {
        tempType = VSCP_TYPE_INFORMATION_GOOD_EVENING_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_GOOD_NIGHT)
    {
        tempType = VSCP_TYPE_INFORMATION_GOOD_NIGHT_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_SEE_YOU_SOON)
    {
        tempType = VSCP_TYPE_INFORMATION_SEE_YOU_SOON_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_GOODBYE)
    {
        tempType = VSCP_TYPE_INFORMATION_GOODBYE_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_STOP)
    {
        tempType = VSCP_TYPE_INFORMATION_STOP_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_START)
    {
        tempType = VSCP_TYPE_INFORMATION_START_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_RESET_COMPLETED)
    {
        tempType = VSCP_TYPE_INFORMATION_RESET_COMPLETED_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_INTERRUPTED)
    {
        tempType = VSCP_TYPE_INFORMATION_INTERRUPTED_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_PREPARING_TO_SLEEP)
    {
        tempType = VSCP_TYPE_INFORMATION_PREPARING_TO_SLEEP_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_WOKEN_UP)
    {
        tempType = VSCP_TYPE_INFORMATION_WOKEN_UP_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_DUSK)
    {
        tempType = VSCP_TYPE_INFORMATION_DUSK_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_DAWN)
    {
        tempType = VSCP_TYPE_INFORMATION_DAWN_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_ACTIVE)
    {
        tempType = VSCP_TYPE_INFORMATION_ACTIVE_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_INACTIVE)
    {
        tempType = VSCP_TYPE_INFORMATION_INACTIVE_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_BUSY)
    {
        tempType = VSCP_TYPE_INFORMATION_BUSY_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_IDLE)
    {
        tempType = VSCP_TYPE_INFORMATION_IDLE_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_STREAM_DATA)
    {
        tempType = VSCP_TYPE_INFORMATION_STREAM_DATA_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_TOKEN_ACTIVITY)
    {
        tempType = VSCP_TYPE_INFORMATION_TOKEN_ACTIVITY_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_STREAM_DATA_WITH_ZONE)
    {
        tempType = VSCP_TYPE_INFORMATION_STREAM_DATA_WITH_ZONE_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_CONFIRM)
    {
        tempType = VSCP_TYPE_INFORMATION_CONFIRM_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_LEVEL_CHANGED)
    {
        tempType = VSCP_TYPE_INFORMATION_LEVEL_CHANGED_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_WARNING)
    {
        tempType = VSCP_TYPE_INFORMATION_WARNING_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_STATE)
    {
        tempType = VSCP_TYPE_INFORMATION_STATE_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_ACTION_TRIGGER)
    {
        tempType = VSCP_TYPE_INFORMATION_ACTION_TRIGGER_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_SUNRISE)
    {
        tempType = VSCP_TYPE_INFORMATION_SUNRISE_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_SUNSET)
    {
        tempType = VSCP_TYPE_INFORMATION_SUNSET_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_START_OF_RECORD)
    {
        tempType = VSCP_TYPE_INFORMATION_START_OF_RECORD_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_END_OF_RECORD)
    {
        tempType = VSCP_TYPE_INFORMATION_END_OF_RECORD_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_PRESET_ACTIVE)
    {
        tempType = VSCP_TYPE_INFORMATION_PRESET_ACTIVE_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_DETECT)
    {
        tempType = VSCP_TYPE_INFORMATION_DETECT_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_OVERFLOW)
    {
        tempType = VSCP_TYPE_INFORMATION_OVERFLOW_VALUE;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED)
    {
        tempType = VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED_VALUE;
    }
    else
    {
        tempType = VSCP_TYPE_INFORMATION_GENERAL_VALUE;
    }

}

void vscpClassTypeObject::getControlTypeValue(QString &tempType)
{

    if(tempType == VSCP_TYPE_CONTROL_GENERAL)
    {
        tempType = VSCP_TYPE_CONTROL_GENERAL_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_MUTE)
    {
        tempType = VSCP_TYPE_CONTROL_MUTE_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_ALL_LAMPS)
    {
        tempType = VSCP_TYPE_CONTROL_ALL_LAMPS_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_OPEN)
    {
        tempType = VSCP_TYPE_CONTROL_OPEN_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_CLOSE)
    {
        tempType = VSCP_TYPE_CONTROL_CLOSE_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_TURNON)
    {
        tempType = VSCP_TYPE_CONTROL_TURNON_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_TURNOFF)
    {
        tempType = VSCP_TYPE_CONTROL_TURNOFF_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_START)
    {
        tempType = VSCP_TYPE_CONTROL_START_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_STOP)
    {
        tempType = VSCP_TYPE_CONTROL_STOP_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_RESET)
    {
        tempType = VSCP_TYPE_CONTROL_RESET_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_INTERRUPT)
    {
        tempType = VSCP_TYPE_CONTROL_INTERRUPT_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_SLEEP)
    {
        tempType = VSCP_TYPE_CONTROL_SLEEP_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_WAKEUP)
    {
        tempType = VSCP_TYPE_CONTROL_WAKEUP_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_RESUME)
    {
        tempType = VSCP_TYPE_CONTROL_RESUME_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_PAUSE)
    {
        tempType = VSCP_TYPE_CONTROL_PAUSE_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_ACTIVATE)
    {
        tempType = VSCP_TYPE_CONTROL_ACTIVATE_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_DEACTIVATE)
    {
        tempType = VSCP_TYPE_CONTROL_DEACTIVATE_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_DIM_LAMPS)
    {
        tempType = VSCP_TYPE_CONTROL_DIM_LAMPS_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_CHANGE_CHANNEL)
    {
        tempType = VSCP_TYPE_CONTROL_CHANGE_CHANNEL_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_CHANGE_LEVEL)
    {
        tempType = VSCP_TYPE_CONTROL_CHANGE_LEVEL_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_RELATIVE_CHANGE_LEVEL)
    {
        tempType = VSCP_TYPE_CONTROL_RELATIVE_CHANGE_LEVEL_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_MEASUREMENT_REQUEST)
    {
        tempType = VSCP_TYPE_CONTROL_MEASUREMENT_REQUEST_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_STREAM_DATA)
    {
        tempType = VSCP_TYPE_CONTROL_STREAM_DATA_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_SYNC)
    {
        tempType = VSCP_TYPE_CONTROL_SYNC_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_ZONED_STREAM_DATA)
    {
        tempType = VSCP_TYPE_CONTROL_ZONED_STREAM_DATA_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_SET_PRESET)
    {
        tempType = VSCP_TYPE_CONTROL_SET_PRESET_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_TOGGLE_STATE)
    {
        tempType = VSCP_TYPE_CONTROL_TOGGLE_STATE_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_TIMED_PULE_ON)
    {
        tempType = VSCP_TYPE_CONTROL_TIMED_PULE_ON_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_TIMED_PULSE_OFF)
    {
        tempType = VSCP_TYPE_CONTROL_TIMED_PULSE_OFF_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_SET_COUNTRY_LANGUAGE)
    {
        tempType = VSCP_TYPE_CONTROL_SET_COUNTRY_LANGUAGE_VALUE;
    }
    else if(tempType == VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL)
    {
        tempType = VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL_VALUE;
    }
    else
    {
        tempType = VSCP_TYPE_CONTROL_GENERAL_VALUE;
    }

}

// get list index for Information
int vscpClassTypeObject::getInformationTypeListIndex(QString &tempType)
{
    int indexValue = 0;

    if(tempType == VSCP_TYPE_INFORMATION_GENERAL_VALUE)
    {
        indexValue = 0;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_BUTTON_VALUE)
    {
        indexValue = 1;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_MOUSE_VALUE)
    {
        indexValue = 2;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_ON_VALUE)
    {
        indexValue = 3;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_OFF_VALUE)
    {
        indexValue = 4;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_ALIVE_VALUE)
    {
        indexValue = 5;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_TERMINATING_VALUE)
    {
        indexValue = 6;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_OPENED_VALUE)
    {
        indexValue = 7;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_CLOSED_VALUE)
    {
        indexValue = 8;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_NODE_HEARTBEAT_VALUE)
    {
        indexValue = 9;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_BELOW_LIMIT_VALUE)
    {
        indexValue = 10;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_ABOVE_LIMIT_VALUE)
    {
        indexValue = 11;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_PULSE_VALUE)
    {
        indexValue = 12;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_ERROR_VALUE)
    {
        indexValue = 13;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_RESUMED_VALUE)
    {
        indexValue = 14;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_PAUSED_VALUE)
    {
        indexValue = 15;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_SLEEP_VALUE)
    {
        indexValue = 16;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_GOOD_MORNING_VALUE)
    {
        indexValue = 17;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_GOOD_DAY_VALUE)
    {
        indexValue = 18;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_GOOD_AFTERNOON_VALUE)
    {
        indexValue = 19;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_GOOD_EVENING_VALUE)
    {
        indexValue = 20;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_GOOD_NIGHT_VALUE)
    {
        indexValue = 21;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_SEE_YOU_SOON_VALUE)
    {
        indexValue = 22;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_GOODBYE_VALUE)
    {
        indexValue = 23;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_STOP_VALUE)
    {
        indexValue = 24;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_START_VALUE)
    {
        indexValue = 25;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_RESET_COMPLETED_VALUE)
    {
        indexValue = 26;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_INTERRUPTED_VALUE)
    {
        indexValue = 27;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_PREPARING_TO_SLEEP_VALUE)
    {
        indexValue = 28;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_WOKEN_UP_VALUE)
    {
        indexValue = 29;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_DUSK_VALUE)
    {
        indexValue = 30;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_DAWN_VALUE)
    {
        indexValue = 31;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_ACTIVE_VALUE)
    {
        indexValue = 32;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_INACTIVE_VALUE)
    {
        indexValue = 33;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_BUSY_VALUE)
    {
        indexValue = 34;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_IDLE_VALUE)
    {
        indexValue = 35;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_STREAM_DATA_VALUE)
    {
        indexValue = 36;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_TOKEN_ACTIVITY_VALUE)
    {
        indexValue = 37;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_STREAM_DATA_WITH_ZONE_VALUE)
    {
        indexValue = 38;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_CONFIRM_VALUE)
    {
        indexValue = 39;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_LEVEL_CHANGED_VALUE)
    {
        indexValue = 40;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_WARNING_VALUE)
    {
        indexValue = 41;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_STATE_VALUE)
    {
        indexValue = 42;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_ACTION_TRIGGER_VALUE)
    {
        indexValue = 43;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_SUNRISE_VALUE)
    {
        indexValue = 44;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_SUNSET_VALUE)
    {
        indexValue = 45;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_START_OF_RECORD_VALUE)
    {
        indexValue = 46;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_END_OF_RECORD_VALUE)
    {
        indexValue = 47;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_PRESET_ACTIVE_VALUE)
    {
        indexValue = 48;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_DETECT_VALUE)
    {
        indexValue = 49;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_OVERFLOW_VALUE)
    {
        indexValue = 50;
    }
    else if(tempType == VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED_VALUE)
    {
        indexValue = 51;
    }
    else
    {
        indexValue = 0;
    }

    return indexValue;
}

// get list index for Control
int vscpClassTypeObject::getControlTypeListIndex(QString &tempType)
{
    int indexValue = 0;

    if(tempType == VSCP_TYPE_CONTROL_GENERAL_VALUE)
    {
        indexValue = 0;
    }
    else if(tempType == VSCP_TYPE_CONTROL_MUTE_VALUE)
    {
        indexValue = 1;
    }
    else if(tempType == VSCP_TYPE_CONTROL_ALL_LAMPS_VALUE)
    {
        indexValue = 2;
    }
    else if(tempType == VSCP_TYPE_CONTROL_OPEN_VALUE)
    {
        indexValue = 3;
    }
    else if(tempType == VSCP_TYPE_CONTROL_CLOSE_VALUE)
    {
        indexValue = 4;
    }
    else if(tempType == VSCP_TYPE_CONTROL_TURNON_VALUE)
    {
        indexValue = 5;
    }
    else if(tempType == VSCP_TYPE_CONTROL_TURNOFF_VALUE)
    {
        indexValue = 6;
    }
    else if(tempType == VSCP_TYPE_CONTROL_START_VALUE)
    {
        indexValue = 7;
    }
    else if(tempType == VSCP_TYPE_CONTROL_STOP_VALUE)
    {
        indexValue = 8;
    }
    else if(tempType == VSCP_TYPE_CONTROL_RESET_VALUE)
    {
        indexValue = 9;
    }
    else if(tempType == VSCP_TYPE_CONTROL_INTERRUPT_VALUE)
    {
        indexValue = 10;
    }
    else if(tempType == VSCP_TYPE_CONTROL_SLEEP_VALUE)
    {
        indexValue = 11;
    }
    else if(tempType == VSCP_TYPE_CONTROL_WAKEUP_VALUE)
    {
        indexValue = 12;
    }
    else if(tempType == VSCP_TYPE_CONTROL_RESUME_VALUE)
    {
        indexValue = 13;
    }
    else if(tempType == VSCP_TYPE_CONTROL_PAUSE_VALUE)
    {
        indexValue = 14;
    }
    else if(tempType == VSCP_TYPE_CONTROL_ACTIVATE_VALUE)
    {
        indexValue = 15;
    }
    else if(tempType == VSCP_TYPE_CONTROL_DEACTIVATE_VALUE)
    {
        indexValue = 16;
    }
    else if(tempType == VSCP_TYPE_CONTROL_DIM_LAMPS_VALUE)
    {
        indexValue = 17;
    }
    else if(tempType == VSCP_TYPE_CONTROL_CHANGE_CHANNEL_VALUE)
    {
        indexValue = 18;
    }
    else if(tempType == VSCP_TYPE_CONTROL_CHANGE_LEVEL_VALUE)
    {
        indexValue = 19;
    }
    else if(tempType == VSCP_TYPE_CONTROL_RELATIVE_CHANGE_LEVEL_VALUE)
    {
        indexValue = 20;
    }
    else if(tempType == VSCP_TYPE_CONTROL_MEASUREMENT_REQUEST_VALUE)
    {
        indexValue = 21;
    }
    else if(tempType == VSCP_TYPE_CONTROL_STREAM_DATA_VALUE)
    {
        indexValue = 22;
    }
    else if(tempType == VSCP_TYPE_CONTROL_SYNC_VALUE)
    {
        indexValue = 23;
    }
    else if(tempType == VSCP_TYPE_CONTROL_ZONED_STREAM_DATA_VALUE)
    {
        indexValue = 24;
    }
    else if(tempType == VSCP_TYPE_CONTROL_SET_PRESET_VALUE)
    {
        indexValue = 25;
    }
    else if(tempType == VSCP_TYPE_CONTROL_TOGGLE_STATE_VALUE)
    {
        indexValue = 26;
    }
    else if(tempType == VSCP_TYPE_CONTROL_TIMED_PULE_ON_VALUE)
    {
        indexValue = 27;
    }
    else if(tempType == VSCP_TYPE_CONTROL_TIMED_PULSE_OFF_VALUE)
    {
        indexValue = 28;
    }
    else if(tempType == VSCP_TYPE_CONTROL_SET_COUNTRY_LANGUAGE_VALUE)
    {
        indexValue = 29;
    }
    else if(tempType == VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL_VALUE)
    {
        indexValue = 30;
    }
    else
    {
        indexValue = 0;
    }


    return indexValue;
}


// get type for Measurement
void vscpClassTypeObject::getMeasurementTypeValue(QString &tempType)
{

    if(tempType == VSCP_TYPE_MEASUREMENT_GENERAL)
    {
        tempType = VSCP_TYPE_MEASUREMENT_GENERAL_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_COUNT_I)
    {
        tempType = VSCP_TYPE_MEASUREMENT_COUNT_I_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_LENGTH)
    {
        tempType = VSCP_TYPE_MEASUREMENT_LENGTH_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_MASS)
    {
        tempType = VSCP_TYPE_MEASUREMENT_MASS_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_TIME)
    {
        tempType = VSCP_TYPE_MEASUREMENT_TIME_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ELECTRIC_CURRENT)
    {
        tempType = VSCP_TYPE_MEASUREMENT_ELECTRIC_CURRENT_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_TEMPERATURE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_TEMPERATURE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_AMOUNT_OF_SUBSTANCE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_AMOUNT_OF_SUBSTANCE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_INTENSITY_OF_LIGHT)
    {
        tempType = VSCP_TYPE_MEASUREMENT_INTENSITY_OF_LIGHT_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_FREQUENCY)
    {
        tempType = VSCP_TYPE_MEASUREMENT_FREQUENCY_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_RADIOACTIVITY)
    {
        tempType = VSCP_TYPE_MEASUREMENT_RADIOACTIVITY_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_FORCE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_FORCE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_PRESSURE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_PRESSURE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ENERGY)
    {
        tempType = VSCP_TYPE_MEASUREMENT_ENERGY_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_POWER)
    {
        tempType = VSCP_TYPE_MEASUREMENT_POWER_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ELECTRICAL_CHARGE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_ELECTRICAL_CHARGE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ELECTRICAL_POTENTIAL)
    {
        tempType = VSCP_TYPE_MEASUREMENT_ELECTRICAL_POTENTIAL_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ELECTRICAL_CAPACITANCE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_ELECTRICAL_CAPACITANCE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ELECTRICAL_RESISTANCE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_ELECTRICAL_RESISTANCE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ELECTRICAL_CONDUCTANCE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_ELECTRICAL_CONDUCTANCE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_MAGNETIC_FIELD_STRENGTH)
    {
        tempType = VSCP_TYPE_MEASUREMENT_MAGNETIC_FIELD_STRENGTH_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_MAGNETIC_FLUX)
    {
        tempType = VSCP_TYPE_MEASUREMENT_MAGNETIC_FLUX_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_MAGNETIC_FLUX_DENSITY)
    {
        tempType = VSCP_TYPE_MEASUREMENT_MAGNETIC_FLUX_DENSITY_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_INDUCTANCE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_INDUCTANCE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_FLUX_OF_LIGHT)
    {
        tempType = VSCP_TYPE_MEASUREMENT_FLUX_OF_LIGHT_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ILLUMINANCE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_ILLUMINANCE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_RADIATION_DOSE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_RADIATION_DOSE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_CATALYTIC_ACITIVITY)
    {
        tempType = VSCP_TYPE_MEASUREMENT_CATALYTIC_ACITIVITY_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_VOLUME)
    {
        tempType = VSCP_TYPE_MEASUREMENT_VOLUME_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_SOUND_INTENSITY)
    {
        tempType = VSCP_TYPE_MEASUREMENT_SOUND_INTENSITY_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ANGLE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_ANGLE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_POSITION)
    {
        tempType = VSCP_TYPE_MEASUREMENT_POSITION_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_SPEED)
    {
        tempType = VSCP_TYPE_MEASUREMENT_SPEED_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ACCELERATION)
    {
        tempType = VSCP_TYPE_MEASUREMENT_ACCELERATION_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_TENSION)
    {
        tempType = VSCP_TYPE_MEASUREMENT_TENSION_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_HUMIDITY)
    {
        tempType = VSCP_TYPE_MEASUREMENT_HUMIDITY_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_FLOW)
    {
        tempType = VSCP_TYPE_MEASUREMENT_FLOW_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_THERMAL_RESISTANCE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_THERMAL_RESISTANCE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_REFRACTIVE_POWER)
    {
        tempType = VSCP_TYPE_MEASUREMENT_REFRACTIVE_POWER_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_DYNAMIC_VISCOSITY)
    {
        tempType = VSCP_TYPE_MEASUREMENT_DYNAMIC_VISCOSITY_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_SOUND_IMPEDANCE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_SOUND_IMPEDANCE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_SOUND_RESISTANCE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_SOUND_RESISTANCE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ELECTRIC_ELASTANCE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_ELECTRIC_ELASTANCE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_LUMINOUS_ENERGY)
    {
        tempType = VSCP_TYPE_MEASUREMENT_LUMINOUS_ENERGY_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_LUMINANCE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_LUMINANCE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_CHEMICAL_CONCENTRATION)
    {
        tempType = VSCP_TYPE_MEASUREMENT_CHEMICAL_CONCENTRATION_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_RESERVED)
    {
        tempType = VSCP_TYPE_MEASUREMENT_RESERVED_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_DOSE_EQVIVALENT)
    {
        tempType = VSCP_TYPE_MEASUREMENT_DOSE_EQVIVALENT_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_DEWPOINT)
    {
        tempType = VSCP_TYPE_MEASUREMENT_DEWPOINT_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_RELATIVE_LEVEL)
    {
        tempType = VSCP_TYPE_MEASUREMENT_RELATIVE_LEVEL_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ALTITUDE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_ALTITUDE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_AREA)
    {
        tempType = VSCP_TYPE_MEASUREMENT_AREA_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_RADIANT_INTENSITY)
    {
        tempType = VSCP_TYPE_MEASUREMENT_RADIANT_INTENSITY_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_RADIANCE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_RADIANCE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_IRRADIANCE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_IRRADIANCE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_SPECTRAL_RADIANCE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_SPECTRAL_RADIANCE_VALUE;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_SPECTRAL_IRRADIANCE)
    {
        tempType = VSCP_TYPE_MEASUREMENT_SPECTRAL_IRRADIANCE_VALUE;
    }
    else
    {
        tempType = VSCP_TYPE_MEASUREMENT_GENERAL_VALUE;
    }

}

// get list index for Information
int vscpClassTypeObject::getMeasurementTypeListIndex(QString &tempType)
{
    int indexValue = 0;

    if(tempType == VSCP_TYPE_MEASUREMENT_GENERAL_VALUE)
    {
        indexValue = 0;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_COUNT_I_VALUE)
    {
        indexValue = 1;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_LENGTH_VALUE)
    {
        indexValue = 2;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_MASS_VALUE)
    {
        indexValue = 3;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_TIME_VALUE)
    {
        indexValue = 4;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ELECTRIC_CURRENT_VALUE)
    {
        indexValue = 5;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_TEMPERATURE_VALUE)
    {
        indexValue = 6;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_AMOUNT_OF_SUBSTANCE_VALUE)
    {
        indexValue = 7;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_INTENSITY_OF_LIGHT_VALUE)
    {
        indexValue = 8;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_FREQUENCY_VALUE)
    {
        indexValue = 9;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_RADIOACTIVITY_VALUE)
    {
        indexValue = 10;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_FORCE_VALUE)
    {
        indexValue = 11;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_PRESSURE_VALUE)
    {
        indexValue = 12;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ENERGY_VALUE)
    {
        indexValue = 13;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_POWER_VALUE)
    {
        indexValue = 14;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ELECTRICAL_CHARGE_VALUE)
    {
        indexValue = 15;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ELECTRICAL_POTENTIAL_VALUE)
    {
        indexValue = 16;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ELECTRICAL_CAPACITANCE_VALUE)
    {
        indexValue = 17;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ELECTRICAL_RESISTANCE_VALUE)
    {
        indexValue = 18;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ELECTRICAL_CONDUCTANCE_VALUE)
    {
        indexValue = 19;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_MAGNETIC_FIELD_STRENGTH_VALUE)
    {
        indexValue = 20;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_MAGNETIC_FLUX_VALUE)
    {
        indexValue = 21;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_MAGNETIC_FLUX_DENSITY_VALUE)
    {
        indexValue = 22;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_INDUCTANCE_VALUE)
    {
        indexValue = 23;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_FLUX_OF_LIGHT_VALUE)
    {
        indexValue = 24;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ILLUMINANCE_VALUE)
    {
        indexValue = 25;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_RADIATION_DOSE_VALUE)
    {
        indexValue = 26;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_CATALYTIC_ACITIVITY_VALUE)
    {
        indexValue = 27;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_VOLUME_VALUE)
    {
        indexValue = 28;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_SOUND_INTENSITY_VALUE)
    {
        indexValue = 29;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ANGLE_VALUE)
    {
        indexValue = 30;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_POSITION_VALUE)
    {
        indexValue = 31;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_SPEED_VALUE)
    {
        indexValue = 32;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ACCELERATION_VALUE)
    {
        indexValue = 33;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_TENSION_VALUE)
    {
        indexValue = 34;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_HUMIDITY_VALUE)
    {
        indexValue = 35;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_FLOW_VALUE)
    {
        indexValue = 36;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_THERMAL_RESISTANCE_VALUE)
    {
        indexValue = 37;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_REFRACTIVE_POWER_VALUE)
    {
        indexValue = 38;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_DYNAMIC_VISCOSITY_VALUE)
    {
        indexValue = 39;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_SOUND_IMPEDANCE_VALUE)
    {
        indexValue = 40;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_SOUND_RESISTANCE_VALUE)
    {
        indexValue = 41;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ELECTRIC_ELASTANCE_VALUE)
    {
        indexValue = 42;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_LUMINOUS_ENERGY_VALUE)
    {
        indexValue = 43;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_LUMINANCE_VALUE)
    {
        indexValue = 44;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_CHEMICAL_CONCENTRATION_VALUE)
    {
        indexValue = 46;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_RESERVED_VALUE)
    {
        indexValue = 47;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_DOSE_EQVIVALENT_VALUE)
    {
        indexValue = 48;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_DEWPOINT_VALUE)
    {
        indexValue = 49;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_RELATIVE_LEVEL_VALUE)
    {
        indexValue = 50;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_ALTITUDE_VALUE)
    {
        indexValue = 51;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_AREA_VALUE)
    {
        indexValue = 52;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_RADIANT_INTENSITY_VALUE)
    {
        indexValue = 53;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_RADIANCE_VALUE)
    {
        indexValue = 54;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_IRRADIANCE_VALUE)
    {
        indexValue = 55;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_SPECTRAL_RADIANCE_VALUE)
    {
        indexValue = 56;
    }
    else if(tempType == VSCP_TYPE_MEASUREMENT_SPECTRAL_IRRADIANCE_VALUE)
    {
        indexValue = 57;
    }
    else
    {
        indexValue = 0;
    }

    return indexValue;
}

vscpClassTypeObject::~vscpClassTypeObject()
{
    //Do nothing
}

