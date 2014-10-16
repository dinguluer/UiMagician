/**
 * @brief           VSCP Level I/II type definition file
 * @file            vscp_type.h
 * @author          Ake Hedman, Grodans Paradis AB, www.vscp.org
 *
 *
 * @section description Description
 **********************************
 * This module contains the code that implements that 
 *
 *********************************************************************/

/* ******************************************************************************
 * 	VSCP (Very Simple Control Protocol) 
 * 	http://www.vscp.org
 *
 *  Copyright (C) 1995-2014 Ake Hedman,
 #  Grodans Paradis AB, &lt;akhe@grodansparadis.com&gt;
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 * 
 *	This file is part of VSCP - Very Simple Control Protocol 	
 *	http://www.vscp.org
 *
 * ******************************************************************************
 */

#ifndef VSCP_TYPE_H
#define VSCP_TYPE_H

#define VSCP_TYPE_UNDEFINED				0

// VSCP Protocol Functionality
#define VSCP_TYPE_PROTOCOL_SEGCTRL_HEARTBEAT                1
#define VSCP_TYPE_PROTOCOL_NEW_NODE_ONLINE                  2
#define VSCP_TYPE_PROTOCOL_PROBE_ACK                        3
#define VSCP_TYPE_PROTOCOL_SET_NICKNAME                     6
#define VSCP_TYPE_PROTOCOL_NICKNAME_ACCEPTED                7
#define VSCP_TYPE_PROTOCOL_DROP_NICKNAME                    8
#define VSCP_TYPE_PROTOCOL_READ_REGISTER                    9
#define VSCP_TYPE_PROTOCOL_RW_RESPONSE                      10
#define VSCP_TYPE_PROTOCOL_WRITE_REGISTER                   11
#define VSCP_TYPE_PROTOCOL_ENTER_BOOT_LOADER                12
#define VSCP_TYPE_PROTOCOL_ACK_BOOT_LOADER                  13
#define VSCP_TYPE_PROTOCOL_NACK_BOOT_LOADER                 14
#define VSCP_TYPE_PROTOCOL_START_BLOCK                      15
#define VSCP_TYPE_PROTOCOL_BLOCK_DATA                       16
#define VSCP_TYPE_PROTOCOL_BLOCK_DATA_ACK                   17
#define VSCP_TYPE_PROTOCOL_BLOCK_DATA_NACK                  18
#define VSCP_TYPE_PROTOCOL_PROGRAM_BLOCK_DATA               19
#define VSCP_TYPE_PROTOCOL_PROGRAM_BLOCK_DATA_ACK           20
#define VSCP_TYPE_PROTOCOL_PROGRAM_BLOCK_DATA_NACK          21
#define VSCP_TYPE_PROTOCOL_ACTIVATE_NEW_IMAGE               22
#define VSCP_TYPE_PROTOCOL_RESET_DEVICE                     23
#define VSCP_TYPE_PROTOCOL_PAGE_READ                        24
#define VSCP_TYPE_PROTOCOL_PAGE_WRITE                       25
#define VSCP_TYPE_PROTOCOL_RW_PAGE_RESPONSE                 26
#define VSCP_TYPE_PROTOCOL_HIGH_END_SERVER_PROBE            27
#define VSCP_TYPE_PROTOCOL_HIGH_END_SERVER_RESPONSE         28
#define VSCP_TYPE_PROTOCOL_INCREMENT_REGISTER               29
#define VSCP_TYPE_PROTOCOL_DECREMENT_REGISTER               30
#define VSCP_TYPE_PROTOCOL_WHO_IS_THERE                     31
#define VSCP_TYPE_PROTOCOL_WHO_IS_THERE_RESPONSE            32
#define VSCP_TYPE_PROTOCOL_GET_MATRIX_INFO                  33
#define VSCP_TYPE_PROTOCOL_GET_MATRIX_INFO_RESPONSE         34
#define VSCP_TYPE_PROTOCOL_GET_EMBEDDED_MDF                 35
#define VSCP_TYPE_PROTOCOL_GET_EMBEDDED_MDF_RESPONSE        36
#define VSCP_TYPE_PROTOCOL_EXTENDED_PAGE_READ               37
#define VSCP_TYPE_PROTOCOL_EXTENDED_PAGE_WRITE              38
#define VSCP_TYPE_PROTOCOL_EXTENDED_PAGE_RESPONSE           39
#define VSCP_TYPE_PROTOCOL_GET_EVENT_INTEREST               40
#define VSCP_TYPE_PROTOCOL_GET_EVENT_INTEREST_RESPONSE      41
#define VSCP_TYPE_PROTOCOL_ACTIVATE_NEW_IMAGE_ACK           48
#define VSCP_TYPE_PROTOCOL_ACTIVATE_NEW_IMAGE_NACK          49
#define VSCP_TYPE_PROTOCOL_START_BLOCK_ACK                  50
#define VSCP_TYPE_PROTOCOL_START_BLOCK_NACK                 51

// Class 1 (0x01) -- ALARM
#define VSCP_TYPE_ALARM_GENERAL                             0
#define VSCP_TYPE_ALARM_WARNING                             1
#define VSCP_TYPE_ALARM_ALARM                               2
#define VSCP_TYPE_ALARM_SOUND                               3
#define VSCP_TYPE_ALARM_LIGHT                               4
#define VSCP_TYPE_ALARM_POWER                               5
#define VSCP_TYPE_ALARM_EMERGENCY_STOP                      6
#define VSCP_TYPE_ALARM_EMERGENCY_PAUSE                     7
#define VSCP_TYPE_ALARM_EMERGENCY_RESET                     8
#define VSCP_TYPE_ALARM_EMERGENCY_RESUME                    9

// Class 2 (0x02) -- SECURITY
#define VSCP_TYPE_SECURITY_GENERAL                          0
#define VSCP_TYPE_SECURITY_MOTION                           1
#define VSCP_TYPE_SECURITY_GLASS_BREAK                      2
#define VSCP_TYPE_SECURITY_BEAM_BREAK                       3
#define VSCP_TYPE_SECURITY_SENSOR_TAMPER                    4
#define VSCP_TYPE_SECURITY_SHOCK_SENSOR                     5
#define VSCP_TYPE_SECURITY_SMOKE_SENSOR                     6
#define VSCP_TYPE_SECURITY_HEAT_SENSOR                      7
#define VSCP_TYPE_SECURITY_PANIC_SWITCH                     8
#define VSCP_TYPE_SECURITY_DOOR_OPEN                        9
#define VSCP_TYPE_SECURITY_WINDOW_OPEN                      10
#define VSCP_TYPE_SECURITY_CO_SENSOR                        11
#define VSCP_TYPE_SECURITY_FROST_DETECTED                   12
#define VSCP_TYPE_SECURITY_FLAME_DETECTED                   13
#define VSCP_TYPE_SECURITY_OXYGEN_LOW                       14
#define VSCP_TYPE_SECURITY_WEIGHT_DETECTED                  15
#define VSCP_TYPE_SECURITY_WATER_DETECTED                   16
#define VSCP_TYPE_SECURITY_CONDENSATION_DETECTED            17
#define VSCP_TYPE_SECURITY_SOUND_DETECTED                   18
#define VSCP_TYPE_SECURITY_HARMFUL_SOUND_LEVEL              19

// Class 10 (0x0a) -- MEASUREMENT
#define VSCP_TYPE_MEASUREMENT_GENERAL                     "GENERAL"
#define VSCP_TYPE_MEASUREMENT_COUNT_I                     "COUNT"
#define VSCP_TYPE_MEASUREMENT_LENGTH                      "LENGTH"
#define VSCP_TYPE_MEASUREMENT_MASS                        "MASS"
#define VSCP_TYPE_MEASUREMENT_TIME                        "TIME"
#define VSCP_TYPE_MEASUREMENT_ELECTRIC_CURRENT            "ELECTRIC_CURRENT"
#define VSCP_TYPE_MEASUREMENT_TEMPERATURE                 "TEMPERATURE"
#define VSCP_TYPE_MEASUREMENT_AMOUNT_OF_SUBSTANCE         "AMOUNT_OF_SUBSTANCE"
#define VSCP_TYPE_MEASUREMENT_INTENSITY_OF_LIGHT          "INTENSITY_OF_LIGHT"
#define VSCP_TYPE_MEASUREMENT_FREQUENCY                   "FREQUENCY"
#define VSCP_TYPE_MEASUREMENT_RADIOACTIVITY               "RADIOACTIVITY"	// or other random event
#define VSCP_TYPE_MEASUREMENT_FORCE                       "FORCE"
#define VSCP_TYPE_MEASUREMENT_PRESSURE                    "PRESSURE"
#define VSCP_TYPE_MEASUREMENT_ENERGY                      "ENERGY"
#define VSCP_TYPE_MEASUREMENT_POWER                       "POWER"
#define VSCP_TYPE_MEASUREMENT_ELECTRICAL_CHARGE           "ELECTRICAL_CHARGE"
#define VSCP_TYPE_MEASUREMENT_ELECTRICAL_POTENTIAL        "ELECTRICAL_POTENTIAL"	// Voltage
#define VSCP_TYPE_MEASUREMENT_ELECTRICAL_CAPACITANCE      "ELECTRICAL_CAPACITANCE"
#define VSCP_TYPE_MEASUREMENT_ELECTRICAL_RESISTANCE       "ELECTRICAL_RESISTANCE"
#define VSCP_TYPE_MEASUREMENT_ELECTRICAL_CONDUCTANCE      "ELECTRICAL_CONDUCTANCE"
#define VSCP_TYPE_MEASUREMENT_MAGNETIC_FIELD_STRENGTH     "MAGNETIC_FIELD_STRENGTH"
#define VSCP_TYPE_MEASUREMENT_MAGNETIC_FLUX               "MAGNETIC_FLUX"
#define VSCP_TYPE_MEASUREMENT_MAGNETIC_FLUX_DENSITY       "MAGNETIC_FLUX_DENSITY"
#define VSCP_TYPE_MEASUREMENT_INDUCTANCE                  "INDUCTANCE"
#define VSCP_TYPE_MEASUREMENT_FLUX_OF_LIGHT               "FLUX_OF_LIGHT"
#define VSCP_TYPE_MEASUREMENT_ILLUMINANCE                 "ILLUMINANCE"
#define VSCP_TYPE_MEASUREMENT_RADIATION_DOSE              "RADIATION_DOSE"
#define VSCP_TYPE_MEASUREMENT_CATALYTIC_ACITIVITY         "CATALYTIC_ACITIVITY"
#define VSCP_TYPE_MEASUREMENT_VOLUME                      "VOLUME"
#define VSCP_TYPE_MEASUREMENT_SOUND_INTENSITY             "SOUND_INTENSITY"
#define VSCP_TYPE_MEASUREMENT_ANGLE                       "ANGLE"
#define VSCP_TYPE_MEASUREMENT_POSITION                    "POSITION"
#define VSCP_TYPE_MEASUREMENT_SPEED                       "SPEED"
#define VSCP_TYPE_MEASUREMENT_ACCELERATION                "ACCELERATION"
#define VSCP_TYPE_MEASUREMENT_TENSION                     "TENSION"
#define VSCP_TYPE_MEASUREMENT_HUMIDITY                    "HUMIDITY"	// Damp/moist (Hygrometer reading)
#define VSCP_TYPE_MEASUREMENT_FLOW                        "FLOW"
#define VSCP_TYPE_MEASUREMENT_THERMAL_RESISTANCE          "THERMAL_RESISTANCE"
#define VSCP_TYPE_MEASUREMENT_REFRACTIVE_POWER            "REFRACTIVE_POWER"
#define VSCP_TYPE_MEASUREMENT_DYNAMIC_VISCOSITY           "DYNAMIC_VISCOSITY"
#define VSCP_TYPE_MEASUREMENT_SOUND_IMPEDANCE             "SOUND_IMPEDANCE"
#define VSCP_TYPE_MEASUREMENT_SOUND_RESISTANCE            "SOUND_RESISTANCE"
#define VSCP_TYPE_MEASUREMENT_ELECTRIC_ELASTANCE          "ELECTRIC_ELASTANCE"
#define VSCP_TYPE_MEASUREMENT_LUMINOUS_ENERGY             "LUMINOUS_ENERGY"
#define VSCP_TYPE_MEASUREMENT_LUMINANCE                   "LUMINANCE"
#define VSCP_TYPE_MEASUREMENT_CHEMICAL_CONCENTRATION      "CHEMICAL_CONCENTRATION"
#define VSCP_TYPE_MEASUREMENT_RESERVED	                  "RESERVED"
#define VSCP_TYPE_MEASUREMENT_DOSE_EQVIVALENT             "DOSE_EQVIVALENT"
#define VSCP_TYPE_MEASUREMENT_RESERVED_48	              "RESERVED"
#define VSCP_TYPE_MEASUREMENT_DEWPOINT                    "DEWPOINT"
#define VSCP_TYPE_MEASUREMENT_RELATIVE_LEVEL              "RELATIVE_LEVEL"
#define VSCP_TYPE_MEASUREMENT_ALTITUDE                    "ALTITUDE"
#define VSCP_TYPE_MEASUREMENT_AREA                        "AREA"
#define VSCP_TYPE_MEASUREMENT_RADIANT_INTENSITY           "RADIANT_INTENSITY"
#define VSCP_TYPE_MEASUREMENT_RADIANCE                    "RADIANCE"
#define VSCP_TYPE_MEASUREMENT_IRRADIANCE                  "IRRADIANCE"
#define VSCP_TYPE_MEASUREMENT_SPECTRAL_RADIANCE           "SPECTRAL_RADIANCE"
#define VSCP_TYPE_MEASUREMENT_SPECTRAL_IRRADIANCE         "SPECTRAL_IRRADIANCE"
// Class 10 (0x0a) -- MEASUREMENT Values
#define VSCP_TYPE_MEASUREMENT_GENERAL_VALUE                     "0"
#define VSCP_TYPE_MEASUREMENT_COUNT_I_VALUE                       "1"
#define VSCP_TYPE_MEASUREMENT_LENGTH_VALUE                      "2"
#define VSCP_TYPE_MEASUREMENT_MASS_VALUE                        "3"
#define VSCP_TYPE_MEASUREMENT_TIME_VALUE                        "4"
#define VSCP_TYPE_MEASUREMENT_ELECTRIC_CURRENT_VALUE            "5"
#define VSCP_TYPE_MEASUREMENT_TEMPERATURE_VALUE                 "6"
#define VSCP_TYPE_MEASUREMENT_AMOUNT_OF_SUBSTANCE_VALUE         "7"
#define VSCP_TYPE_MEASUREMENT_INTENSITY_OF_LIGHT_VALUE          "8"
#define VSCP_TYPE_MEASUREMENT_FREQUENCY_VALUE                   "9"
#define VSCP_TYPE_MEASUREMENT_RADIOACTIVITY_VALUE               "10"	// or other random event
#define VSCP_TYPE_MEASUREMENT_FORCE_VALUE                       "11"
#define VSCP_TYPE_MEASUREMENT_PRESSURE_VALUE                    "12"
#define VSCP_TYPE_MEASUREMENT_ENERGY_VALUE                      "13"
#define VSCP_TYPE_MEASUREMENT_POWER_VALUE                       "14"
#define VSCP_TYPE_MEASUREMENT_ELECTRICAL_CHARGE_VALUE           "15"
#define VSCP_TYPE_MEASUREMENT_ELECTRICAL_POTENTIAL_VALUE        "16"	// Voltage
#define VSCP_TYPE_MEASUREMENT_ELECTRICAL_CAPACITANCE_VALUE      "17"
#define VSCP_TYPE_MEASUREMENT_ELECTRICAL_RESISTANCE_VALUE       "18"
#define VSCP_TYPE_MEASUREMENT_ELECTRICAL_CONDUCTANCE_VALUE      "19"
#define VSCP_TYPE_MEASUREMENT_MAGNETIC_FIELD_STRENGTH_VALUE     "20"
#define VSCP_TYPE_MEASUREMENT_MAGNETIC_FLUX_VALUE               "21"
#define VSCP_TYPE_MEASUREMENT_MAGNETIC_FLUX_DENSITY_VALUE       "22"
#define VSCP_TYPE_MEASUREMENT_INDUCTANCE_VALUE                  "23"
#define VSCP_TYPE_MEASUREMENT_FLUX_OF_LIGHT_VALUE               "24"
#define VSCP_TYPE_MEASUREMENT_ILLUMINANCE_VALUE                 "25"
#define VSCP_TYPE_MEASUREMENT_RADIATION_DOSE_VALUE              "26"
#define VSCP_TYPE_MEASUREMENT_CATALYTIC_ACITIVITY_VALUE         "27"
#define VSCP_TYPE_MEASUREMENT_VOLUME_VALUE                      "28"
#define VSCP_TYPE_MEASUREMENT_SOUND_INTENSITY_VALUE             "29"
#define VSCP_TYPE_MEASUREMENT_ANGLE_VALUE                       "30"
#define VSCP_TYPE_MEASUREMENT_POSITION_VALUE                    "31"
#define VSCP_TYPE_MEASUREMENT_SPEED_VALUE                       "32"
#define VSCP_TYPE_MEASUREMENT_ACCELERATION_VALUE                "33"
#define VSCP_TYPE_MEASUREMENT_TENSION_VALUE                     "34"
#define VSCP_TYPE_MEASUREMENT_HUMIDITY_VALUE                    "35"	// Damp/moist (Hygrometer reading)
#define VSCP_TYPE_MEASUREMENT_FLOW_VALUE                        "36"
#define VSCP_TYPE_MEASUREMENT_THERMAL_RESISTANCE_VALUE          "37"
#define VSCP_TYPE_MEASUREMENT_REFRACTIVE_POWER_VALUE            "38"
#define VSCP_TYPE_MEASUREMENT_DYNAMIC_VISCOSITY_VALUE           "39"
#define VSCP_TYPE_MEASUREMENT_SOUND_IMPEDANCE_VALUE             "40"
#define VSCP_TYPE_MEASUREMENT_SOUND_RESISTANCE_VALUE            "41"
#define VSCP_TYPE_MEASUREMENT_ELECTRIC_ELASTANCE_VALUE          "42"
#define VSCP_TYPE_MEASUREMENT_LUMINOUS_ENERGY_VALUE             "43"
#define VSCP_TYPE_MEASUREMENT_LUMINANCE_VALUE                   "44"
#define VSCP_TYPE_MEASUREMENT_CHEMICAL_CONCENTRATION_VALUE      "45"
#define VSCP_TYPE_MEASUREMENT_RESERVED_VALUE	                "46"
#define VSCP_TYPE_MEASUREMENT_DOSE_EQVIVALENT_VALUE             "47"
#define VSCP_TYPE_MEASUREMENT_RESERVED_48_VALUE                 "48"
#define VSCP_TYPE_MEASUREMENT_DEWPOINT_VALUE                    "49"
#define VSCP_TYPE_MEASUREMENT_RELATIVE_LEVEL_VALUE              "50"
#define VSCP_TYPE_MEASUREMENT_ALTITUDE_VALUE                    "51"
#define VSCP_TYPE_MEASUREMENT_AREA_VALUE                        "52"
#define VSCP_TYPE_MEASUREMENT_RADIANT_INTENSITY_VALUE           "53"
#define VSCP_TYPE_MEASUREMENT_RADIANCE_VALUE                    "54"
#define VSCP_TYPE_MEASUREMENT_IRRADIANCE_VALUE                  "55"
#define VSCP_TYPE_MEASUREMENT_SPECTRAL_RADIANCE_VALUE           "56"
#define VSCP_TYPE_MEASUREMENT_SPECTRAL_IRRADIANCE_VALUE         "57"


// Class 15 (0x0f) -- DATA
#define VSCP_TYPE_DATA_GENERAL                            0
#define VSCP_TYPE_DATA_IO                                 1
#define VSCP_TYPE_DATA_AD                                 2
#define VSCP_TYPE_DATA_DA                                 3
#define VSCP_TYPE_DATA_RELATIVE_STRENGTH                  4
#define VSCP_TYPE_DATA_SIGNAL_LEVEL                       5
#define VSCP_TYPE_DATA_SIGNAL_QUALITY                     6

// class 20 (0x14) -- INFORMATION
#define VSCP_TYPE_INFORMATION_GENERAL                     "GENERAL"
#define VSCP_TYPE_INFORMATION_BUTTON                      "BUTTON"
#define VSCP_TYPE_INFORMATION_MOUSE                       "MOUSE"
#define VSCP_TYPE_INFORMATION_ON                          "ON"
#define VSCP_TYPE_INFORMATION_OFF                         "OFF"
#define VSCP_TYPE_INFORMATION_ALIVE                       "ALIVE"
#define VSCP_TYPE_INFORMATION_TERMINATING                 "TERMINATING"
#define VSCP_TYPE_INFORMATION_OPENED                      "OPENED"
#define VSCP_TYPE_INFORMATION_CLOSED                      "CLOSED"
#define VSCP_TYPE_INFORMATION_NODE_HEARTBEAT              "NODE_HEARTBEAT"
#define VSCP_TYPE_INFORMATION_BELOW_LIMIT                 "BELOW_LIMIT"
#define VSCP_TYPE_INFORMATION_ABOVE_LIMIT                 "ABOVE_LIMIT"
#define VSCP_TYPE_INFORMATION_PULSE                       "PULSE"
#define VSCP_TYPE_INFORMATION_ERROR                       "ERROR"
#define VSCP_TYPE_INFORMATION_RESUMED                     "RESUMED"
#define VSCP_TYPE_INFORMATION_PAUSED                      "PAUSED"
#define VSCP_TYPE_INFORMATION_SLEEP                       "SLEEP"
#define VSCP_TYPE_INFORMATION_GOOD_MORNING                "GOOD_MORNING"
#define VSCP_TYPE_INFORMATION_GOOD_DAY                    "GOOD_DAY"
#define VSCP_TYPE_INFORMATION_GOOD_AFTERNOON              "GOOD_AFTERNOON"
#define VSCP_TYPE_INFORMATION_GOOD_EVENING                "GOOD_EVENING"
#define VSCP_TYPE_INFORMATION_GOOD_NIGHT                  "GOOD_NIGHT"
#define VSCP_TYPE_INFORMATION_SEE_YOU_SOON                "SEE_YOU_SOON"
#define VSCP_TYPE_INFORMATION_GOODBYE                     "GOODBYE"
#define VSCP_TYPE_INFORMATION_STOP                        "STOP"
#define VSCP_TYPE_INFORMATION_START                       "START"
#define VSCP_TYPE_INFORMATION_RESET_COMPLETED             "RESET_COMPLETED"
#define VSCP_TYPE_INFORMATION_INTERRUPTED                 "INTERRUPTED"
#define VSCP_TYPE_INFORMATION_PREPARING_TO_SLEEP          "PREPARING_TO_SLEEP"
#define VSCP_TYPE_INFORMATION_WOKEN_UP                    "WOKEN_UP"
#define VSCP_TYPE_INFORMATION_DUSK                        "DUSK"
#define VSCP_TYPE_INFORMATION_DAWN                        "DAWN"
#define VSCP_TYPE_INFORMATION_ACTIVE                      "ACTIVE"
#define VSCP_TYPE_INFORMATION_INACTIVE                    "INACTIVE"
#define VSCP_TYPE_INFORMATION_BUSY                        "BUSY"
#define VSCP_TYPE_INFORMATION_IDLE                        "IDLE"
#define VSCP_TYPE_INFORMATION_STREAM_DATA                 "STREAM_DATA"
#define VSCP_TYPE_INFORMATION_TOKEN_ACTIVITY              "TOKEN_ACTIVITY"
#define VSCP_TYPE_INFORMATION_STREAM_DATA_WITH_ZONE       "STREAM_DATA_WITH_ZONE"
#define VSCP_TYPE_INFORMATION_CONFIRM                     "CONFIRM"
#define VSCP_TYPE_INFORMATION_LEVEL_CHANGED               "LEVEL_CHANGED"
#define VSCP_TYPE_INFORMATION_WARNING                     "WARNING"
#define VSCP_TYPE_INFORMATION_STATE                       "STATE"
#define VSCP_TYPE_INFORMATION_ACTION_TRIGGER              "ACTION_TRIGGER"
#define VSCP_TYPE_INFORMATION_SUNRISE                     "SUNRISE"
#define VSCP_TYPE_INFORMATION_SUNSET                      "SUNSET"
#define VSCP_TYPE_INFORMATION_START_OF_RECORD             "START_OF_RECORD"
#define VSCP_TYPE_INFORMATION_END_OF_RECORD               "END_OF_RECORD"
#define VSCP_TYPE_INFORMATION_PRESET_ACTIVE               "PRESET_ACTIVE"
#define VSCP_TYPE_INFORMATION_DETECT                      "DETECT"
#define VSCP_TYPE_INFORMATION_OVERFLOW                    "OVERFLOW"
#define VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED           "BIG_LEVEL_CHANGED "
// class 20 (0x14) -- INFORMATION VALUE
#define VSCP_TYPE_INFORMATION_GENERAL_VALUE                     "0"
#define VSCP_TYPE_INFORMATION_BUTTON_VALUE                      "1"
#define VSCP_TYPE_INFORMATION_MOUSE_VALUE                       "2"
#define VSCP_TYPE_INFORMATION_ON_VALUE                          "3"
#define VSCP_TYPE_INFORMATION_OFF_VALUE                         "4"
#define VSCP_TYPE_INFORMATION_ALIVE_VALUE                       "5"
#define VSCP_TYPE_INFORMATION_TERMINATING_VALUE                 "6"
#define VSCP_TYPE_INFORMATION_OPENED_VALUE                      "7"
#define VSCP_TYPE_INFORMATION_CLOSED_VALUE                      "8"
#define VSCP_TYPE_INFORMATION_NODE_HEARTBEAT_VALUE              "9"
#define VSCP_TYPE_INFORMATION_BELOW_LIMIT_VALUE                 "10"
#define VSCP_TYPE_INFORMATION_ABOVE_LIMIT_VALUE                 "11"
#define VSCP_TYPE_INFORMATION_PULSE_VALUE                       "12"
#define VSCP_TYPE_INFORMATION_ERROR_VALUE                       "13"
#define VSCP_TYPE_INFORMATION_RESUMED_VALUE                     "14"
#define VSCP_TYPE_INFORMATION_PAUSED_VALUE                      "15"
#define VSCP_TYPE_INFORMATION_SLEEP_VALUE                       "16"
#define VSCP_TYPE_INFORMATION_GOOD_MORNING_VALUE                "17"
#define VSCP_TYPE_INFORMATION_GOOD_DAY_VALUE                    "18"
#define VSCP_TYPE_INFORMATION_GOOD_AFTERNOON_VALUE              "19"
#define VSCP_TYPE_INFORMATION_GOOD_EVENING_VALUE                "20"
#define VSCP_TYPE_INFORMATION_GOOD_NIGHT_VALUE                  "21"
#define VSCP_TYPE_INFORMATION_SEE_YOU_SOON_VALUE                "22"
#define VSCP_TYPE_INFORMATION_GOODBYE_VALUE                     "23"
#define VSCP_TYPE_INFORMATION_STOP_VALUE                        "24"
#define VSCP_TYPE_INFORMATION_START_VALUE                       "25"
#define VSCP_TYPE_INFORMATION_RESET_COMPLETED_VALUE             "26"
#define VSCP_TYPE_INFORMATION_INTERRUPTED_VALUE                 "27"
#define VSCP_TYPE_INFORMATION_PREPARING_TO_SLEEP_VALUE          "28"
#define VSCP_TYPE_INFORMATION_WOKEN_UP_VALUE                    "29"
#define VSCP_TYPE_INFORMATION_DUSK_VALUE                        "30"
#define VSCP_TYPE_INFORMATION_DAWN_VALUE                        "31"
#define VSCP_TYPE_INFORMATION_ACTIVE_VALUE                      "32"
#define VSCP_TYPE_INFORMATION_INACTIVE_VALUE                    "33"
#define VSCP_TYPE_INFORMATION_BUSY_VALUE                        "34"
#define VSCP_TYPE_INFORMATION_IDLE_VALUE                        "35"
#define VSCP_TYPE_INFORMATION_STREAM_DATA_VALUE                 "36"
#define VSCP_TYPE_INFORMATION_TOKEN_ACTIVITY_VALUE              "37"
#define VSCP_TYPE_INFORMATION_STREAM_DATA_WITH_ZONE_VALUE       "38"
#define VSCP_TYPE_INFORMATION_CONFIRM_VALUE                     "39"
#define VSCP_TYPE_INFORMATION_LEVEL_CHANGED_VALUE               "40"
#define VSCP_TYPE_INFORMATION_WARNING_VALUE                     "41"
#define VSCP_TYPE_INFORMATION_STATE_VALUE                       "42"
#define VSCP_TYPE_INFORMATION_ACTION_TRIGGER_VALUE              "43"
#define VSCP_TYPE_INFORMATION_SUNRISE_VALUE                     "44"
#define VSCP_TYPE_INFORMATION_SUNSET_VALUE                      "45"
#define VSCP_TYPE_INFORMATION_START_OF_RECORD_VALUE             "46"
#define VSCP_TYPE_INFORMATION_END_OF_RECORD_VALUE               "47"
#define VSCP_TYPE_INFORMATION_PRESET_ACTIVE_VALUE               "48"
#define VSCP_TYPE_INFORMATION_DETECT_VALUE                      "49"
#define VSCP_TYPE_INFORMATION_OVERFLOW_VALUE                    "50"
#define VSCP_TYPE_INFORMATION_BIG_LEVEL_CHANGED_VALUE           "51"
// class 30 (0x1E) -- CONTROL
#define VSCP_TYPE_CONTROL_GENERAL                         "GENERAL"
#define VSCP_TYPE_CONTROL_MUTE                            "MUTE"
#define VSCP_TYPE_CONTROL_ALL_LAMPS                       "ALL_LAMPS"
#define VSCP_TYPE_CONTROL_OPEN                            "OPEN"
#define VSCP_TYPE_CONTROL_CLOSE                           "CLOSE"
#define VSCP_TYPE_CONTROL_TURNON                          "TURNON"
#define VSCP_TYPE_CONTROL_TURNOFF                         "TURNOFF"
#define VSCP_TYPE_CONTROL_START                           "START"
#define VSCP_TYPE_CONTROL_STOP                            "STOP"
#define VSCP_TYPE_CONTROL_RESET                           "RESET"
#define VSCP_TYPE_CONTROL_INTERRUPT                       "INTERRUPT"
#define VSCP_TYPE_CONTROL_SLEEP                           "SLEEP"
#define VSCP_TYPE_CONTROL_WAKEUP                          "WAKEUP"
#define VSCP_TYPE_CONTROL_RESUME                          "RESUME"
#define VSCP_TYPE_CONTROL_PAUSE                           "PAUSE"
#define VSCP_TYPE_CONTROL_ACTIVATE                        "ACTIVATE"
#define VSCP_TYPE_CONTROL_DEACTIVATE                      "DEACTIVATE"
#define VSCP_TYPE_CONTROL_DIM_LAMPS                       "DIM_LAMPS"
#define VSCP_TYPE_CONTROL_CHANGE_CHANNEL                  "CHANGE_CHANNEL"
#define VSCP_TYPE_CONTROL_CHANGE_LEVEL                    "CHANGE_LEVEL"
#define VSCP_TYPE_CONTROL_RELATIVE_CHANGE_LEVEL           "RELATIVE_CHANGE_LEVEL"
#define VSCP_TYPE_CONTROL_MEASUREMENT_REQUEST             "MEASUREMENT_REQUEST"
#define VSCP_TYPE_CONTROL_STREAM_DATA                     "STREAM_DATA"
#define VSCP_TYPE_CONTROL_SYNC                            "SYNC"
#define VSCP_TYPE_CONTROL_ZONED_STREAM_DATA               "ZONED_STREAM_DATA"
#define VSCP_TYPE_CONTROL_SET_PRESET                      "SET_PRESET"
#define VSCP_TYPE_CONTROL_TOGGLE_STATE                    "TOGGLE_STATE"
#define VSCP_TYPE_CONTROL_TIMED_PULE_ON                   "TIMED_PULE_ON"
#define VSCP_TYPE_CONTROL_TIMED_PULSE_OFF                 "TIMED_PULSE_OFF"
#define VSCP_TYPE_CONTROL_SET_COUNTRY_LANGUAGE	          "SET_COUNTRY_LANGUAGE"
#define VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL                "BIG_CHANGE_LEVEL"
// class 30 (0x1E) -- CONTROL VALUE
#define VSCP_TYPE_CONTROL_GENERAL_VALUE                         "0"
#define VSCP_TYPE_CONTROL_MUTE_VALUE                            "1"
#define VSCP_TYPE_CONTROL_ALL_LAMPS_VALUE                       "2"
#define VSCP_TYPE_CONTROL_OPEN_VALUE                            "3"
#define VSCP_TYPE_CONTROL_CLOSE_VALUE                           "4"
#define VSCP_TYPE_CONTROL_TURNON_VALUE                          "5"
#define VSCP_TYPE_CONTROL_TURNOFF_VALUE                         "6"
#define VSCP_TYPE_CONTROL_START_VALUE                           "7"
#define VSCP_TYPE_CONTROL_STOP_VALUE                            "8"
#define VSCP_TYPE_CONTROL_RESET_VALUE                           "9"
#define VSCP_TYPE_CONTROL_INTERRUPT_VALUE                       "10"
#define VSCP_TYPE_CONTROL_SLEEP_VALUE                           "11"
#define VSCP_TYPE_CONTROL_WAKEUP_VALUE                          "12"
#define VSCP_TYPE_CONTROL_RESUME_VALUE                          "13"
#define VSCP_TYPE_CONTROL_PAUSE_VALUE                           "14"
#define VSCP_TYPE_CONTROL_ACTIVATE_VALUE                        "15"
#define VSCP_TYPE_CONTROL_DEACTIVATE_VALUE                      "16"
#define VSCP_TYPE_CONTROL_DIM_LAMPS_VALUE                       "20"
#define VSCP_TYPE_CONTROL_CHANGE_CHANNEL_VALUE                  "21"
#define VSCP_TYPE_CONTROL_CHANGE_LEVEL_VALUE                    "22"
#define VSCP_TYPE_CONTROL_RELATIVE_CHANGE_LEVEL_VALUE           "23"
#define VSCP_TYPE_CONTROL_MEASUREMENT_REQUEST_VALUE             "24"
#define VSCP_TYPE_CONTROL_STREAM_DATA_VALUE                     "25"
#define VSCP_TYPE_CONTROL_SYNC_VALUE                            "26"
#define VSCP_TYPE_CONTROL_ZONED_STREAM_DATA_VALUE               "27"
#define VSCP_TYPE_CONTROL_SET_PRESET_VALUE                      "28"
#define VSCP_TYPE_CONTROL_TOGGLE_STATE_VALUE                    "29"
#define VSCP_TYPE_CONTROL_TIMED_PULE_ON_VALUE                   "30"
#define VSCP_TYPE_CONTROL_TIMED_PULSE_OFF_VALUE                 "31"
#define VSCP_TYPE_CONTROL_SET_COUNTRY_LANGUAGE_VALUE            "32"
#define VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL_VALUE                "33"


// class 40 (0x28) -- MULTIMEDIA
#define VSCP_TYPE_MULTIMEDIA_GENERAL                      0
#define VSCP_TYPE_MULTIMEDIA_PLAYBACK                     1
#define VSCP_TYPE_MULTIMEDIA_NAVIGATOR_KEY_ENG            2
#define VSCP_TYPE_MULTIMEDIA_ADJUST_CONTRAST              3
#define VSCP_TYPE_MULTIMEDIA_ADJUST_FOCUS                 4
#define VSCP_TYPE_MULTIMEDIA_ADJUST_TINT                  5
#define VSCP_TYPE_MULTIMEDIA_ADJUST_COLOUR_BALANCE        6
#define VSCP_TYPE_MULTIMEDIA_ADJUST_BRIGHTNESS            7
#define VSCP_TYPE_MULTIMEDIA_ADJUST_HUE                   8
#define VSCP_TYPE_MULTIMEDIA_ADJUST_BASS                  9
#define VSCP_TYPE_MULTIMEDIA_ADJUST_TREBLE                10
#define VSCP_TYPE_MULTIMEDIA_ADJUST_MASTER_VOLUME         11
#define VSCP_TYPE_MULTIMEDIA_ADJUST_FRONT_VOLUME          12
#define VSCP_TYPE_MULTIMEDIA_ADJUST_CENTRE_VOLUME         13
#define VSCP_TYPE_MULTIMEDIA_ADJUST_REAR_VOLUME           14
#define VSCP_TYPE_MULTIMEDIA_ADJUST_SIDE_VOLUME           15
#define VSCP_TYPE_MULTIMEDIA_ADJUST_SELECT_DISK           20
#define VSCP_TYPE_MULTIMEDIA_ADJUST_SELECT_TRACK          21
#define VSCP_TYPE_MULTIMEDIA_ADJUST_SELECT_ALBUM          22
#define VSCP_TYPE_MULTIMEDIA_ADJUST_SELECT_CHANNEL        23
#define VSCP_TYPE_MULTIMEDIA_ADJUST_SELECT_PAGE           24
#define VSCP_TYPE_MULTIMEDIA_ADJUST_SELECT_CHAPTER        25
#define VSCP_TYPE_MULTIMEDIA_ADJUST_SELECT_SCREEN_FORMAT  26
#define VSCP_TYPE_MULTIMEDIA_ADJUST_SELECT_INPUT_SOURCE   27
#define VSCP_TYPE_MULTIMEDIA_ADJUST_SELECT_OUTPUT         28
#define VSCP_TYPE_MULTIMEDIA_RECORD                       29
#define VSCP_TYPE_MULTIMEDIA_SET_RECORDING_VOLUME         30
#define VSCP_TYPE_MULTIMEDIA_TIVO_FUNCTION                40
#define VSCP_TYPE_MULTIMEDIA_GET_CURRENT_TITLE            50
#define VSCP_TYPE_MULTIMEDIA_SET_POSITION                 51
#define VSCP_TYPE_MULTIMEDIA_GET_MEDIA_INFO               52
#define VSCP_TYPE_MULTIMEDIA_REMOVE_ITEM                  53
#define VSCP_TYPE_MULTIMEDIA_REMOVE_ALL_ITEMS             54
#define VSCP_TYPE_MULTIMEDIA_SAVE_ALBUM                   55
#define VSCP_TYPE_MULTIMEDIA_CONTROL                      60
#define VSCP_TYPE_MULTIMEDIA_CONTROL_RESPONSE             61

// class 50 (0x32) -- AOL
#define VSCP_TYPE_AOL_GENERAL                             0
#define VSCP_TYPE_AOL_UNPLUGGED_POWER                     1 
#define VSCP_TYPE_AOL_UNPLUGGED_LAN                       2
#define VSCP_TYPE_AOL_CHASSIS_INTRUSION                   3
#define VSCP_TYPE_AOL_PROCESSOR_REMOVAL                   4
#define VSCP_TYPE_AOL_ENVIRONMENT_ERROR                   5
#define VSCP_TYPE_AOL_HIGH_TEMPERATURE                    6
#define VSCP_TYPE_AOL_FAN_SPEED                           7
#define VSCP_TYPE_AOL_VOLTAGE_FLUCTUATIONS                8
#define VSCP_TYPE_AOL_OS_ERROR                            9
#define VSCP_TYPE_AOL_POWER_ON_ERROR                      10
#define VSCP_TYPE_AOL_SYSTEM_HUNG                         11
#define VSCP_TYPE_AOL_COMPONENT_FAILURE                   12
#define VSCP_TYPE_AOL_REBOOT_UPON_FAILURE                 13
#define VSCP_TYPE_AOL_REPAIR_OPERATING_SYSTEM             14
#define VSCP_TYPE_AOL_UPDATE_BIOS_IMAGE                   15
#define VSCP_TYPE_AOL_UPDATE_DIAGNOSTIC_PROCEDURE         16

// class 60 (0x3C) -- CLASS1.MEASUREMENT64
// Types are the same as CLASS1.MEASUREMENT=10
#define VSCP_TYPE_MEASUREMENT64_GENERAL                     0
#define VSCP_TYPE_MEASUREMENT64_COUNT                       1
#define VSCP_TYPE_MEASUREMENT64_LENGTH                      2
#define VSCP_TYPE_MEASUREMENT64_MASS                        3
#define VSCP_TYPE_MEASUREMENT64_TIME                        4
#define VSCP_TYPE_MEASUREMENT64_ELECTRIC_CURRENT            5
#define VSCP_TYPE_MEASUREMENT64_TEMPERATURE                 6
#define VSCP_TYPE_MEASUREMENT64_AMOUNT_OF_SUBSTANCE         7
#define VSCP_TYPE_MEASUREMENT64_INTENSITY_OF_LIGHT          8
#define VSCP_TYPE_MEASUREMENT64_FREQUENCY                   9
#define VSCP_TYPE_MEASUREMENT64_RADIOACTIVITY               10	// or other random event
#define VSCP_TYPE_MEASUREMENT64_FORCE                       11
#define VSCP_TYPE_MEASUREMENT64_PRESSURE                    12
#define VSCP_TYPE_MEASUREMENT64_ENERGY                      13
#define VSCP_TYPE_MEASUREMENT64_POWER                       14
#define VSCP_TYPE_MEASUREMENT64_ELECTRICAL_CHARGE           15
#define VSCP_TYPE_MEASUREMENT64_ELECTRICAL_POTENTIAL        16	// Voltage
#define VSCP_TYPE_MEASUREMENT64_ELECTRICAL_CAPACITANCE      17
#define VSCP_TYPE_MEASUREMENT64_ELECTRICAL_RECISTANCE       18
#define VSCP_TYPE_MEASUREMENT64_ELECTRICAL_CONDUCTANCE      19
#define VSCP_TYPE_MEASUREMENT64_MAGNETIC_FIELD_STRENGTH     20
#define VSCP_TYPE_MEASUREMENT64_MAGNETIC_FLUX               21
#define VSCP_TYPE_MEASUREMENT64_MAGNETIC_FLUX_DENSITY       22
#define VSCP_TYPE_MEASUREMENT64_INDUCTANCE                  23
#define VSCP_TYPE_MEASUREMENT64_FLUX_OF_LIGHT               24
#define VSCP_TYPE_MEASUREMENT64_ILLUMINANCE                 25
#define VSCP_TYPE_MEASUREMENT64_RADIATION_DOSE              26
#define VSCP_TYPE_MEASUREMENT64_CATALYTIC_ACITIVITY         27
#define VSCP_TYPE_MEASUREMENT64_VOLUME                      28
#define VSCP_TYPE_MEASUREMENT64_SOUND_INTENSITY             29
#define VSCP_TYPE_MEASUREMENT64_ANGLE                       30
#define VSCP_TYPE_MEASUREMENT64_POSITION                    31
#define VSCP_TYPE_MEASUREMENT64_SPEED                       32
#define VSCP_TYPE_MEASUREMENT64_ACCELERATION                33
#define VSCP_TYPE_MEASUREMENT64_TENSION                     34
#define VSCP_TYPE_MEASUREMENT64_HUMIDITY                    35	// Damp/moist (Hygrometer reading)
#define VSCP_TYPE_MEASUREMENT64_FLOW                        36
#define VSCP_TYPE_MEASUREMENT64_THERMAL_RESISTANCE          37
#define VSCP_TYPE_MEASUREMENT64_REFRACTIVE_POWER            38
#define VSCP_TYPE_MEASUREMENT64_DYNAMIC_VISCOSITY           39
#define VSCP_TYPE_MEASUREMENT64_SOUND_IMPEDANCE             40
#define VSCP_TYPE_MEASUREMENT64_SOUND_RESISTANCE            41
#define VSCP_TYPE_MEASUREMENT64_ELECTRIC_ELASTANCE          42
#define VSCP_TYPE_MEASUREMENT64_LUMINOUS_ENERGY             43
#define VSCP_TYPE_MEASUREMENT64_LUMINANCE                   44
#define VSCP_TYPE_MEASUREMENT64_CHEMICAL_CONCENTRATION      45
#define VSCP_TYPE_MEASUREMENT64_RESERVED	            	46
#define VSCP_TYPE_MEASUREMENT64_DOSE_EQVIVALENT             47
#define VSCP_TYPE_MEASUREMENT64_DEWPOINT                    49
#define VSCP_TYPE_MEASUREMENT64_RELATIVE_LEVEL              50
#define VSCP_TYPE_MEASUREMENT64_ALTITUDE                    51
#define VSCP_TYPE_MEASUREMENT64_AREA                        52
#define VSCP_TYPE_MEASUREMENT64_RADIANT_INTENSITY           53
#define VSCP_TYPE_MEASUREMENT64_RADIANCE                    54
#define VSCP_TYPE_MEASUREMENT64_IRRADIANCE                  55
#define VSCP_TYPE_MEASUREMENT64_SPECTRAL_RADIANCE           56
#define VSCP_TYPE_MEASUREMENT64_SPECTRAL_IRRADIANCE         57

// class 65 (0x41) -- CLASS1.MEASUREZONE 
// Types are the same as CLASS1.MEASUREMENT=10
#define VSCP_TYPE_MEASUREZONE_GENERAL                     	0
#define VSCP_TYPE_MEASUREZONE_COUNT                       	1
#define VSCP_TYPE_MEASUREZONE_LENGTH                      	2
#define VSCP_TYPE_MEASUREZONE_MASS                        	3
#define VSCP_TYPE_MEASUREZONE_TIME                        	4
#define VSCP_TYPE_MEASUREZONE_ELECTRIC_CURRENT            	5
#define VSCP_TYPE_MEASUREZONE_TEMPERATURE                 	6
#define VSCP_TYPE_MEASUREZONE_AMOUNT_OF_SUBSTANCE         	7
#define VSCP_TYPE_MEASUREZONE_INTENSITY_OF_LIGHT          	8
#define VSCP_TYPE_MEASUREZONE_FREQUENCY                   	9
#define VSCP_TYPE_MEASUREZONE_RADIOACTIVITY               	10	// or other random event
#define VSCP_TYPE_MEASUREZONE_FORCE                       	11
#define VSCP_TYPE_MEASUREZONE_PRESSURE                    	12
#define VSCP_TYPE_MEASUREZONE_ENERGY                      	13
#define VSCP_TYPE_MEASUREZONE_POWER                       	14
#define VSCP_TYPE_MEASUREZONE_ELECTRICAL_CHARGE           	15
#define VSCP_TYPE_MEASUREZONE_ELECTRICAL_POTENTIAL        	16	// Voltage
#define VSCP_TYPE_MEASUREZONE_ELECTRICAL_CAPACITANCE      	17
#define VSCP_TYPE_MEASUREZONE_ELECTRICAL_RECISTANCE       	18
#define VSCP_TYPE_MEASUREZONE_ELECTRICAL_CONDUCTANCE      	19
#define VSCP_TYPE_MEASUREZONE_MAGNETIC_FIELD_STRENGTH     	20
#define VSCP_TYPE_MEASUREZONE_MAGNETIC_FLUX               	21
#define VSCP_TYPE_MEASUREZONE_MAGNETIC_FLUX_DENSITY       	22
#define VSCP_TYPE_MEASUREZONE_INDUCTANCE                  	23
#define VSCP_TYPE_MEASUREZONE_FLUX_OF_LIGHT               	24
#define VSCP_TYPE_MEASUREZONE_ILLUMINANCE                 	25
#define VSCP_TYPE_MEASUREZONE_RADIATION_DOSE              	26
#define VSCP_TYPE_MEASUREZONE_CATALYTIC_ACITIVITY         	27
#define VSCP_TYPE_MEASUREZONE_VOLUME                      	28
#define VSCP_TYPE_MEASUREZONE_SOUND_INTENSITY             	29
#define VSCP_TYPE_MEASUREZONE_ANGLE                       	30
#define VSCP_TYPE_MEASUREZONE_POSITION                    	31
#define VSCP_TYPE_MEASUREZONE_SPEED                       	32
#define VSCP_TYPE_MEASUREZONE_ACCELERATION                	33
#define VSCP_TYPE_MEASUREZONE_TENSION                     	34
#define VSCP_TYPE_MEASUREZONE_HUMIDITY                    	35	// Damp/moist (Hygrometer reading)
#define VSCP_TYPE_MEASUREZONE_FLOW                        	36
#define VSCP_TYPE_MEASUREZONE_THERMAL_RESISTANCE          	37
#define VSCP_TYPE_MEASUREZONE_REFRACTIVE_POWER            	38
#define VSCP_TYPE_MEASUREZONE_DYNAMIC_VISCOSITY           	39
#define VSCP_TYPE_MEASUREZONE_SOUND_IMPEDANCE             	40
#define VSCP_TYPE_MEASUREZONE_SOUND_RESISTANCE            	41
#define VSCP_TYPE_MEASUREZONE_ELECTRIC_ELASTANCE          	42
#define VSCP_TYPE_MEASUREZONE_LUMINOUS_ENERGY             	43
#define VSCP_TYPE_MEASUREZONE_LUMINANCE                   	44
#define VSCP_TYPE_MEASUREZONE_CHEMICAL_CONCENTRATION      	45
#define VSCP_TYPE_MEASUREZONE_RESERVED	               	  	46
#define VSCP_TYPE_MEASUREZONE_DOSE_EQVIVALENT             	47
#define VSCP_TYPE_MEASUREZONE_DEWPOINT                    	49
#define VSCP_TYPE_MEASUREZONE_RELATIVE_LEVEL              	50
#define VSCP_TYPE_MEASUREZONE_ALTITUDE                    	51
#define VSCP_TYPE_MEASUREZONE_AREA                        	52
#define VSCP_TYPE_MEASUREZONE_RADIANT_INTENSITY           	53
#define VSCP_TYPE_MEASUREZONE_RADIANCE                    	54
#define VSCP_TYPE_MEASUREZONE_IRRADIANCE                  	55
#define VSCP_TYPE_MEASUREZONE_SPECTRAL_RADIANCE           	56
#define VSCP_TYPE_MEASUREZONE_SPECTRAL_IRRADIANCE         	57

// class 70 (0x46) -- CLASS1.MEASUREMENT32
// Types are the same as CLASS1.MEASUREMENT=10
#define VSCP_TYPE_MEASUREMENT32_GENERAL                     0
#define VSCP_TYPE_MEASUREMENT32_COUNT                       1
#define VSCP_TYPE_MEASUREMENT32_LENGTH                      2
#define VSCP_TYPE_MEASUREMENT32_MASS                        3
#define VSCP_TYPE_MEASUREMENT32_TIME                        4
#define VSCP_TYPE_MEASUREMENT32_ELECTRIC_CURRENT            5
#define VSCP_TYPE_MEASUREMENT32_TEMPERATURE                 6
#define VSCP_TYPE_MEASUREMENT32_AMOUNT_OF_SUBSTANCE         7
#define VSCP_TYPE_MEASUREMENT32_INTENSITY_OF_LIGHT          8
#define VSCP_TYPE_MEASUREMENT32_FREQUENCY                   9
#define VSCP_TYPE_MEASUREMENT32_RADIOACTIVITY               10	// or other random event
#define VSCP_TYPE_MEASUREMENT32_FORCE                       11
#define VSCP_TYPE_MEASUREMENT32_PRESSURE                    12
#define VSCP_TYPE_MEASUREMENT32_ENERGY                      13
#define VSCP_TYPE_MEASUREMENT32_POWER                       14
#define VSCP_TYPE_MEASUREMENT32_ELECTRICAL_CHARGE           15
#define VSCP_TYPE_MEASUREMENT32_ELECTRICAL_POTENTIAL        16	// Voltage
#define VSCP_TYPE_MEASUREMENT32_ELECTRICAL_CAPACITANCE      17
#define VSCP_TYPE_MEASUREMENT32_ELECTRICAL_RECISTANCE       18
#define VSCP_TYPE_MEASUREMENT32_ELECTRICAL_CONDUCTANCE      19
#define VSCP_TYPE_MEASUREMENT32_MAGNETIC_FIELD_STRENGTH     20
#define VSCP_TYPE_MEASUREMENT32_MAGNETIC_FLUX               21
#define VSCP_TYPE_MEASUREMENT32_MAGNETIC_FLUX_DENSITY       22
#define VSCP_TYPE_MEASUREMENT32_INDUCTANCE                  23
#define VSCP_TYPE_MEASUREMENT32_FLUX_OF_LIGHT               24
#define VSCP_TYPE_MEASUREMENT32_ILLUMINANCE                 25
#define VSCP_TYPE_MEASUREMENT32_RADIATION_DOSE              26
#define VSCP_TYPE_MEASUREMENT32_CATALYTIC_ACITIVITY         27
#define VSCP_TYPE_MEASUREMENT32_VOLUME                      28
#define VSCP_TYPE_MEASUREMENT32_SOUND_INTENSITY             29
#define VSCP_TYPE_MEASUREMENT32_ANGLE                       30
#define VSCP_TYPE_MEASUREMENT32_POSITION                    31
#define VSCP_TYPE_MEASUREMENT32_SPEED                       32
#define VSCP_TYPE_MEASUREMENT32_ACCELERATION                33
#define VSCP_TYPE_MEASUREMENT32_TENSION                     34
#define VSCP_TYPE_MEASUREMENT32_HUMIDITY                    35	// Damp/moist (Hygrometer reading)
#define VSCP_TYPE_MEASUREMENT32_FLOW                        36
#define VSCP_TYPE_MEASUREMENT32_THERMAL_RESISTANCE          37
#define VSCP_TYPE_MEASUREMENT32_REFRACTIVE_POWER            38
#define VSCP_TYPE_MEASUREMENT32_DYNAMIC_VISCOSITY           39
#define VSCP_TYPE_MEASUREMENT32_SOUND_IMPEDANCE             40
#define VSCP_TYPE_MEASUREMENT32_SOUND_RESISTANCE            41
#define VSCP_TYPE_MEASUREMENT32_ELECTRIC_ELASTANCE          42
#define VSCP_TYPE_MEASUREMENT32_LUMINOUS_ENERGY             43
#define VSCP_TYPE_MEASUREMENT32_LUMINANCE                   44
#define VSCP_TYPE_MEASUREMENT32_CHEMICAL_CONCENTRATION      45
#define VSCP_TYPE_MEASUREMENT32_RESERVED	            46
#define VSCP_TYPE_MEASUREMENT32_DOSE_EQVIVALENT             47
#define VSCP_TYPE_MEASUREMENT32_DEWPOINT                    49
#define VSCP_TYPE_MEASUREMENT32_RELATIVE_LEVEL              50
#define VSCP_TYPE_MEASUREMENT32_ALTITUDE                    51
#define VSCP_TYPE_MEASUREMENT32_AREA                        52
#define VSCP_TYPE_MEASUREMENT32_RADIANT_INTENSITY           53
#define VSCP_TYPE_MEASUREMENT32_RADIANCE                    54
#define VSCP_TYPE_MEASUREMENT32_IRRADIANCE                  55
#define VSCP_TYPE_MEASUREMENT32_SPECTRAL_RADIANCE           56
#define VSCP_TYPE_MEASUREMENT32_SPECTRAL_IRRADIANCE         57

// class 85 (0x55) -- CLASS1.SETVALUEZONE 
// Types are the same as CLASS1.MEASUREMENT=10
#define VSCP_TYPE_SETVALUEZONE_GENERAL                     	0
#define VSCP_TYPE_SETVALUEZONE_COUNT                       	1
#define VSCP_TYPE_SETVALUEZONE_LENGTH                      	2
#define VSCP_TYPE_SETVALUEZONE_MASS                        	3
#define VSCP_TYPE_SETVALUEZONE_TIME                        	4
#define VSCP_TYPE_SETVALUEZONE_ELECTRIC_CURRENT            	5
#define VSCP_TYPE_SETVALUEZONE_TEMPERATURE                 	6
#define VSCP_TYPE_SETVALUEZONE_AMOUNT_OF_SUBSTANCE         	7
#define VSCP_TYPE_SETVALUEZONE_INTENSITY_OF_LIGHT          	8
#define VSCP_TYPE_SETVALUEZONE_FREQUENCY                   	9
#define VSCP_TYPE_SETVALUEZONE_RADIOACTIVITY               	10	// or other random event
#define VSCP_TYPE_SETVALUEZONE_FORCE                       	11
#define VSCP_TYPE_SETVALUEZONE_PRESSURE                    	12
#define VSCP_TYPE_SETVALUEZONE_ENERGY                      	13
#define VSCP_TYPE_SETVALUEZONE_POWER                       	14
#define VSCP_TYPE_SETVALUEZONE_ELECTRICAL_CHARGE           	15
#define VSCP_TYPE_SETVALUEZONE_ELECTRICAL_POTENTIAL        	16	// Voltage
#define VSCP_TYPE_SETVALUEZONE_ELECTRICAL_CAPACITANCE      	17
#define VSCP_TYPE_SETVALUEZONE_ELECTRICAL_RECISTANCE       	18
#define VSCP_TYPE_SETVALUEZONE_ELECTRICAL_CONDUCTANCE      	19
#define VSCP_TYPE_SETVALUEZONE_MAGNETIC_FIELD_STRENGTH     	20
#define VSCP_TYPE_SETVALUEZONE_MAGNETIC_FLUX               	21
#define VSCP_TYPE_SETVALUEZONE_MAGNETIC_FLUX_DENSITY       	22
#define VSCP_TYPE_SETVALUEZONE_INDUCTANCE                  	23
#define VSCP_TYPE_SETVALUEZONE_FLUX_OF_LIGHT               	24
#define VSCP_TYPE_SETVALUEZONE_ILLUMINANCE                 	25
#define VSCP_TYPE_SETVALUEZONE_RADIATION_DOSE              	26
#define VSCP_TYPE_SETVALUEZONE_CATALYTIC_ACITIVITY         	27
#define VSCP_TYPE_SETVALUEZONE_VOLUME                      	28
#define VSCP_TYPE_SETVALUEZONE_SOUND_INTENSITY             	29
#define VSCP_TYPE_SETVALUEZONE_ANGLE                       	30
#define VSCP_TYPE_SETVALUEZONE_POSITION                    	31
#define VSCP_TYPE_SETVALUEZONE_SPEED                       	32
#define VSCP_TYPE_SETVALUEZONE_ACCELERATION                	33
#define VSCP_TYPE_SETVALUEZONE_TENSION                     	34
#define VSCP_TYPE_SETVALUEZONE_HUMIDITY                    	35	// Damp/moist (Hygrometer reading)
#define VSCP_TYPE_SETVALUEZONE_FLOW                        	36
#define VSCP_TYPE_SETVALUEZONE_THERMAL_RESISTANCE          	37
#define VSCP_TYPE_SETVALUEZONE_REFRACTIVE_POWER            	38
#define VSCP_TYPE_SETVALUEZONE_DYNAMIC_VISCOSITY           	39
#define VSCP_TYPE_SETVALUEZONE_SOUND_IMPEDANCE             	40
#define VSCP_TYPE_SETVALUEZONE_SOUND_RESISTANCE            	41
#define VSCP_TYPE_SETVALUEZONE_ELECTRIC_ELASTANCE          	42
#define VSCP_TYPE_SETVALUEZONE_LUMINOUS_ENERGY             	43
#define VSCP_TYPE_SETVALUEZONE_LUMINANCE                   	44
#define VSCP_TYPE_SETVALUEZONE_CHEMICAL_CONCENTRATION      	45
#define VSCP_TYPE_SETVALUEZONE_RESERVED	               	  	46
#define VSCP_TYPE_SETVALUEZONE_DOSE_EQVIVALENT             	47
#define VSCP_TYPE_SETVALUEZONE_DEWPOINT                    	49
#define VSCP_TYPE_SETVALUEZONE_RELATIVE_LEVEL              	50
#define VSCP_TYPE_SETVALUEZONE_ALTITUDE                    	51
#define VSCP_TYPE_SETVALUEZONE_AREA                        	52
#define VSCP_TYPE_SETVALUEZONE_RADIANT_INTENSITY           	53
#define VSCP_TYPE_SETVALUEZONE_RADIANCE                    	54
#define VSCP_TYPE_SETVALUEZONE_IRRADIANCE                  	55
#define VSCP_TYPE_SETVALUEZONE_SPECTRAL_RADIANCE           	56
#define VSCP_TYPE_SETVALUEZONE_SPECTRAL_IRRADIANCE         	57

// class 100 (0x64) -- PHONE
#define VSCP_TYPE_PHONE_GENERAL                           0
#define VSCP_TYPE_PHONE_INCOMING_CALL                     1
#define VSCP_TYPE_PHONE_OUTGOING_CALL                     2
#define VSCP_TYPE_PHONE_RING                              3
#define VSCP_TYPE_PHONE_ANSWERE                           4
#define VSCP_TYPE_PHONE_HANGUP                            5
#define VSCP_TYPE_PHONE_GIVEUP                            6
#define VSCP_TYPE_PHONE_TRANSFER                          7
#define VSCP_TYPE_PHONE_DATABASE_INFO                     8

// class 102 (0x66) -- DISPLAY
#define VSCP_TYPE_DISPLAY_GENERAL                         0
#define VSCP_TYPE_DISPLAY_CLEAR_DISPLAY                   1
#define VSCP_TYPE_DISPLAY_POSITION_CURSOR                 2
#define VSCP_TYPE_DISPLAY_WRITE_DISPLAY                   3
#define VSCP_TYPE_DISPLAY_WRITE_DISPLAY_BUFFER            4
#define VSCP_TYPE_DISPLAY_SHOW_DISPLAY_BUFFER             5
#define VSCP_TYPE_DISPLAY_SET_DISPLAY_BUFFER_PARAM        6
#define VSCP_TYPE_DISPLAY_SHOW_TEXT                       32
#define VSCP_TYPE_DISPLAY_SHOW_LED                        48
#define VSCP_TYPE_DISPLAY_SHOW_LED_COLOR                  49

// class 110 (0x6E) -- REMOTE
#define VSCP_TYPE_REMOTE_GENERAL                          0
#define VSCP_TYPE_REMOTE_RC5                              1
#define VSCP_TYPE_REMOTE_SONY12                           2
#define VSCP_TYPE_REMOTE_LIRC                             32
#define VSCP_TYPE_REMOTE_VSCP                             48

// class 200 (0xC8) -- 1-WIRE
#define VSCP_TYPE_1WIRE_GENERAL                           0
#define VSCP_TYPE_1WIRE_NEW_ID                            1
#define VSCP_TYPE_1WIRE_CONVERT                           2
#define VSCP_TYPE_1WIRE_READ_ROM                          3
#define VSCP_TYPE_1WIRE_MATCH_ROM                         4
#define VSCP_TYPE_1WIRE_SKIP_ROM                          5
#define VSCP_TYPE_1WIRE_SEARCH_ROM                        6
#define VSCP_TYPE_1WIRE_CONDITIONAL_SEARCH_ROM            7
#define VSCP_TYPE_1WIRE_PROGRAM                           8
#define VSCP_TYPE_1WIRE_OVERDRIVE_SKIP_ROM                9
#define VSCP_TYPE_1WIRE_OVERDRIVE_MATCH_ROM               10
#define VSCP_TYPE_1WIRE_OVERDRIVE_READ_MEMORY             11
#define VSCP_TYPE_1WIRE_OVERDRIVE_WRITE_MEMORY            12

// class 201 (0xC9) -- X10
#define VSCP_TYPE_X10_GENERAL                             0
#define VSCP_TYPE_X10_STANDARD_MESSAGE_RECEIVE            1
#define VSCP_TYPE_X10_EXTENDED_MESSAGE_RECEIVE            2
#define VSCP_TYPE_X10_STANDARD_MESSAGE_SEND               3
#define VSCP_TYPE_X10_EXTENDED_MESSAGE_SEND               4
#define VSCP_TYPE_X10_SIMPLE_MESSAGE                      5


// class 202 (0xCA) -- LON
#define VSCP_TYPE_LON_GENERAL                             0

// class 203 (0xCB) -- KNX/EIB
#define VSCP_TYPE_EIB_GENERAL                             0

// class 204 (0xCC) -- SNAP
#define VSCP_TYPE_SNAP_GENERAL                            0

// class 205 (0xCD) -- CBUS
#define VSCP_TYPE_CBUS_GENERAL                            0

// class 206 (0xCE) -- GPS
#define VSCP_TYPE_GPS_GENERAL                             0
#define VSCP_TYPE_GPS_POSITION                            1
#define VSCP_TYPE_GPS_SATELLITES                          2

// class 212 (0xD4) -- WIRELESS
#define VSCP_TYPE_WIRELESS_GENERAL                        0
#define VSCP_TYPE_WIRELESS_GSM_CELL                       1

// class 509 (0x1FD) -- LOG
#define VSCP_TYPE_LOG_GENERAL                             0
#define VSCP_TYPE_LOG_MESSAGE                             1
#define VSCP_TYPE_LOG_START                               2
#define VSCP_TYPE_LOG_STOP                                3
#define VSCP_TYPE_LOG_LEVEL                               4

// class 510 (0x1FE) -- LABORATORY
#define VSCP_TYPE_LABORATORY_GENERAL                      0

// class 511 (0x1FF) -- LOCAL
#define VSCP_TYPE_LOCAL_GENERAL                           0

///////////////////////////////////////////////////////////////////////////////
//				Level II
///////////////////////////////////////////////////////////////////////////////

// Level II Protocol functionality Class=1024 (0x400)
#define VSCP2_TYPE_PROTOCOL_GENERAL                       0
#define VSCP2_TYPE_PROTOCOL_READ_REGISTER                 1
#define VSCP2_TYPE_PROTOCOL_WRITE_REGISTER                2
#define VSCP2_TYPE_PROTOCOL_READ_WRITE_RESPONSE           3

// Level II Control functionality Class=1025 (0x401)
#define VSCP2_TYPE_CONTROL_GENERAL                        0

// Level II Information functionality Class=1026 (0x402)
#define VSCP2_TYPE_INFORMATION_GENERAL                    0
#define VSCP2_TYPE_INFORMATION_TOKEN_ACTIVITY             1

// Level II Text to speech functionality Class=1028 (0x404)
#define VSCP2_TYPE_TEXT2SPEECH_GENERAL                    0
#define VSCP2_TYPE_TEXT2SPEECH_TALK                       1

// Level II Custom functionality Class=1029 (0x405)
#define VSCP2_TYPE_CUSTOM_GENERAL                         0

// Level II Display functionality Class=1030 (0x406)
#define VSCP2_TYPE_DISPLAY_GENERAL                        0

// Level II Measurement String Class=1040 (0x410)
#define VSCP2_TYPE_MEASUREMENT_STR_GENERAL                0
#define VSCP_TYPE_MEASUREMENT_COUNT                       1
#define VSCP_TYPE_MEASUREMENT_COUNT_LENGTH                      2
#define VSCP_TYPE_MEASUREMENT_COUNT_MASS                        3
#define VSCP_TYPE_MEASUREMENT_COUNT_TIME                        4
#define VSCP_TYPE_MEASUREMENT_COUNT_ELECTRIC_CURRENT            5
#define VSCP_TYPE_MEASUREMENT_COUNT_TEMPERATURE                 6
#define VSCP_TYPE_MEASUREMENT_COUNT_AMOUNT_OF_SUBSTANCE         7
#define VSCP_TYPE_MEASUREMENT_COUNT_INTENSITY_OF_LIGHT          8
#define VSCP_TYPE_MEASUREMENT_COUNT_FREQUENCY                   9
#define VSCP_TYPE_MEASUREMENT_COUNT_RADIOACTIVITY               10	// or other random event
#define VSCP_TYPE_MEASUREMENT_COUNT_FORCE                       11
#define VSCP_TYPE_MEASUREMENT_COUNT_PRESSURE                    12
#define VSCP_TYPE_MEASUREMENT_COUNT_ENERGY                      13
#define VSCP_TYPE_MEASUREMENT_COUNT_POWER                       14
#define VSCP_TYPE_MEASUREMENT_COUNT_ELECTRICAL_CHARGE           15
#define VSCP_TYPE_MEASUREMENT_COUNT_ELECTRICAL_POTENTIAL        16	// Voltage
#define VSCP_TYPE_MEASUREMENT_COUNT_ELECTRICAL_CAPACITANCE      17
#define VSCP_TYPE_MEASUREMENT_COUNT_ELECTRICAL_RECISTANCE       18
#define VSCP_TYPE_MEASUREMENT_COUNT_ELECTRICAL_CONDUCTANCE      19
#define VSCP_TYPE_MEASUREMENT_COUNT_MAGNETIC_FIELD_STRENGTH     20
#define VSCP_TYPE_MEASUREMENT_COUNT_MAGNETIC_FLUX               21
#define VSCP_TYPE_MEASUREMENT_COUNT_MAGNETIC_FLUX_DENSITY       22
#define VSCP_TYPE_MEASUREMENT_COUNT_INDUCTANCE                  23
#define VSCP_TYPE_MEASUREMENT_COUNT_FLUX_OF_LIGHT               24
#define VSCP_TYPE_MEASUREMENT_COUNT_ILLUMINANCE                 25
#define VSCP_TYPE_MEASUREMENT_COUNT_RADIATION_DOSE              26
#define VSCP_TYPE_MEASUREMENT_COUNT_CATALYTIC_ACITIVITY         27
#define VSCP_TYPE_MEASUREMENT_COUNT_VOLUME                      28
#define VSCP_TYPE_MEASUREMENT_COUNT_SOUND_INTENSITY             29
#define VSCP_TYPE_MEASUREMENT_COUNT_ANGLE                       30
#define VSCP_TYPE_MEASUREMENT_COUNT_POSITION                    31
#define VSCP_TYPE_MEASUREMENT_COUNT_SPEED                       32
#define VSCP_TYPE_MEASUREMENT_COUNT_ACCELERATION                33
#define VSCP_TYPE_MEASUREMENT_COUNT_TENSION                     34
#define VSCP_TYPE_MEASUREMENT_COUNT_HUMIDITY                    35	// Damp/moist (Hygrometer reading)
#define VSCP_TYPE_MEASUREMENT_COUNT_FLOW                        36
#define VSCP_TYPE_MEASUREMENT_COUNT_THERMAL_RESISTANCE          37
#define VSCP_TYPE_MEASUREMENT_COUNT_REFRACTIVE_POWER            38
#define VSCP_TYPE_MEASUREMENT_COUNT_DYNAMIC_VISCOSITY           39
#define VSCP_TYPE_MEASUREMENT_COUNT_SOUND_IMPEDANCE             40
#define VSCP_TYPE_MEASUREMENT_COUNT_SOUND_RESISTANCE            41
#define VSCP_TYPE_MEASUREMENT_COUNT_ELECTRIC_ELASTANCE          42
#define VSCP_TYPE_MEASUREMENT_COUNT_LUMINOUS_ENERGY             43
#define VSCP_TYPE_MEASUREMENT_COUNT_LUMINANCE                   44
#define VSCP_TYPE_MEASUREMENT_COUNT_CHEMICAL_CONCENTRATION      45
#define VSCP_TYPE_MEASUREMENT_COUNT_RESERVED	                46
#define VSCP_TYPE_MEASUREMENT_COUNT_DOSE_EQVIVALENT             47
#define VSCP_TYPE_MEASUREMENT_COUNT_DEWPOINT                    49
#define VSCP_TYPE_MEASUREMENT_COUNT_RELATIVE_LEVEL              50
#define VSCP_TYPE_MEASUREMENT_COUNT_ALTITUDE                    51
#define VSCP_TYPE_MEASUREMENT_COUNT_AREA                        52
#define VSCP_TYPE_MEASUREMENT_COUNT_RADIANT_INTENSITY           53
#define VSCP_TYPE_MEASUREMENT_COUNT_RADIANCE                    54
#define VSCP_TYPE_MEASUREMENT_COUNT_IRRADIANCE                  55
#define VSCP_TYPE_MEASUREMENT_COUNT_SPECTRAL_RADIANCE           56
#define VSCP_TYPE_MEASUREMENT_COUNT_SPECTRAL_IRRADIANCE         57

// Level II VSCPD daemon functionality Class=65535 (0xFFFF)
#define VSCP2_TYPE_VSCPD_GENERAL                          0
#define VSCP2_TYPE_VSCPD_LOOP                             1
#define VSCP2_TYPE_VSCPD_PAUSE                            3
#define VSCP2_TYPE_VSCPD_ACTIVATE                         4
#define VSCP2_TYPE_VSCPD_SECOND                           5
#define VSCP2_TYPE_VSCPD_MINUTE                           6
#define VSCP2_TYPE_VSCPD_HOUR                             7
#define VSCP2_TYPE_VSCPD_NOON                             8
#define VSCP2_TYPE_VSCPD_MIDNIGHT                         9
#define VSCP2_TYPE_VSCPD_WEEK                             11
#define VSCP2_TYPE_VSCPD_MONTH                            12
#define VSCP2_TYPE_VSCPD_QUARTER                          13
#define VSCP2_TYPE_VSCPD_YEAR                             14
#define VSCP2_TYPE_VSCPD_RANDOM_MINUTE                    15
#define VSCP2_TYPE_VSCPD_RANDOM_HOUR                      16
#define VSCP2_TYPE_VSCPD_RANDOM_DAY                       17
#define VSCP2_TYPE_VSCPD_RANDOM_WEEK                      18
#define VSCP2_TYPE_VSCPD_RANDOM_MONTH                     19
#define VSCP2_TYPE_VSCPD_RANDOM_YEAR                      20
#define VSCP2_TYPE_VSCPD_DUSK                             21
#define VSCP2_TYPE_VSCPD_DAWN                             22
#define VSCP2_TYPE_VSCPD_STARTING_UP                      23
#define VSCP2_TYPE_VSCPD_SHUTTING_DOWN                    24
#define VSCP2_TYPE_VSCPD_TIMER_STARTED                    25
#define VSCP2_TYPE_VSCPD_TIMER_PAUSED                     26
#define VSCP2_TYPE_VSCPD_TIMER_RESUMED                    27
#define VSCP2_TYPE_VSCPD_TIMER_STOPPED                    28
#define VSCP2_TYPE_VSCPD_TIMER_ELLAPSED                   29

#endif
