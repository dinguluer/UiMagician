/**
 * @brief           VSCP Level I/II class definition file
 * @file            vscp_class.h
 * @author          Ake Hedman, Grodans Paradis AB, www.vscp.org
 *
 * @section description Description
 **********************************
 * This module contains the definitions for the 
 * available VSCP class id's
 *********************************************************************/

/* ******************************************************************************
 * VSCP (Very Simple Control Protocol) 
 * http://www.vscp.org
 *
 * Copyright (C) 1995-2014 Ake Hedman, 
 * Grodans Paradis AB, &lt;akhe@grodansparadis.com&gt;
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
 * ******************************************************************************w
 */

#ifndef VSCP_CLASS_H
#define VSCP_CLASS_H

// ******** String of class ********
#define VSCP_CLASS1_PROTOCOL                            "CLASS1_PROTOCOL"
#define VSCP_CLASS1_ALARM                               "CLASS1_ALARM"
#define VSCP_CLASS1_SECURITY                            "CLASS1_SECURITY"
#define VSCP_CLASS1_MEASUREMENT                         "CLASS1_MEASUREMENT"
#define VSCP_CLASS1_DATA                                "CLASS1_DATA"
#define VSCP_CLASS1_INFORMATION                         "CLASS1_INFORMATION"
#define VSCP_CLASS1_CONTROL                             "CLASS1_CONTROL"
#define VSCP_CLASS1_MULTIMEDIA                          "CLASS1_MULTIMEDIA"
#define VSCP_CLASS1_AOL                                 "CLASS1_AOL"
#define VSCP_CLASS1_MEASUREMENT64						"CLASS1_MEASUREMENT64"
#define VSCP_CLASS1_MEASUREZONE							"CLASS1_MEASUREZONE"
#define VSCP_CLASS1_MEASUREMENT32						"CLASS1_MEASUREMENT32"
#define VSCP_CLASS1_SETVALUEZONE						"CLASS1_SETVALUEZONE"
#define VSCP_CLASS1_PHONE                               "CLASS1_PHONE"
#define VSCP_CLASS1_LIN                                 "CLASS1_LIN"
#define VSCP_CLASS1_DISPLAY                             "CLASS1_DISPLAY"
#define VSCP_CLASS1_RC5                                 "CLASS1_RC5"
#define VSCP_CLASS1_ONEWIRE                             "CLASS1_ONEWIRE"
#define VSCP_CLASS1_X10                                 "CLASS1_X10"
#define VSCP_CLASS1_LON                                 "CLASS1_LON"
#define VSCP_CLASS1_EIB                                 "CLASS1_EIB"
#define VSCP_CLASS1_SNAP                                "CLASS1_SNAP"
#define VSCP_CLASS1_MUMIN                               "CLASS1_MUMIN"
#define VSCP_CLASS1_LOG                                 "CLASS1_LOG"
#define VSCP_CLASS1_LAB                                 "CLASS1_LAB"
#define VSCP_CLASS1_LOCAL                               "CLASS1_LOCAL"

// Level I classes on Level II

#define VSCP_CLASS2_LEVEL1_PROTOCOL                      "CLASS2_LEVEL1_PROTOCOL"
#define VSCP_CLASS2_LEVEL1_ALARM                         "CLASS2_LEVEL1_ALARM"
#define VSCP_CLASS2_LEVEL1_SECURITY                      "CLASS2_LEVEL1_SECURITY"
#define VSCP_CLASS2_LEVEL1_MEASUREMENT                   "CLASS2_LEVEL1_MEASUREMENT"
#define VSCP_CLASS2_LEVEL1_DATA                          "CLASS2_LEVEL1_DATA"
#define VSCP_CLASS2_LEVEL1_INFORMATION                   "CLASS2_LEVEL1_INFORMATION"
#define VSCP_CLASS2_LEVEL1_CONTROL                       "CLASS2_LEVEL1_CONTROL"
#define VSCP_CLASS2_LEVEL1_MULTIMEDIA                    "CLASS2_LEVEL1_MULTIMEDIA"
#define VSCP_CLASS2_LEVEL1_AOL                           "CLASS2_LEVEL1_AOL"
#define VSCP_CLASS2_MEASUREMENT64						 "CLASS2_MEASUREMENT64"
#define VSCP_CLASS2_MEASUREZONE							 "CLASS2_MEASUREZONE"
#define VSCP_CLASS2_MEASUREMENT32						 "CLASS2_MEASUREMENT32"
#define VSCP_CLASS2_SETVALUEZONE						 "CLASS2_SETVALUEZONE"
#define VSCP_CLASS2_LEVEL1_PHONE                         "CLASS2_LEVEL1_PHONE"
#define VSCP_CLASS2_LEVEL1_LIN                           "CLASS2_LEVEL1_LIN"
#define VSCP_CLASS2_LEVEL1_RC5                           "CLASS2_LEVEL1_RC5"
#define VSCP_CLASS2_LEVEL1_ONEWIRE                       "CLASS2_LEVEL1_ONEWIRE"
#define VSCP_CLASS2_LEVEL1_X10                           "CLASS2_LEVEL1_X10"
#define VSCP_CLASS2_LEVEL1_LON                           "CLASS2_LEVEL1_LON"
#define VSCP_CLASS2_LEVEL1_EIB                           "CLASS2_LEVEL1_EIB"
#define VSCP_CLASS2_LEVEL1_SNAP                          "CLASS2_LEVEL1_SNAP"
#define VSCP_CLASS2_LEVEL1_MUMIN                         "CLASS2_LEVEL1_MUMIN"
#define VSCP_CLASS2_LEVEL1_LOG                           "CLASS2_LEVEL1_LOG"
#define VSCP_CLASS2_LEVEL1_LAB                           "CLASS2_LEVEL1_LAB"
#define VSCP_CLASS2_LEVEL1_LOCAL                         "CLASS2_LEVEL1_LOCAL"

// Level II classes
#define VSCP_CLASS2_PROTOCOL                             "CLASS2_PROTOCOL"
#define VSCP_CLASS2_CONTROL                              "CLASS2_CONTROL"
#define VSCP_CLASS2_INFORMATION                          "CLASS2_INFORMATION"
#define VSCP_CLASS2_TEXT2SPEECH                          "CLASS2_TEXT2SPEECH"
#define VSCP_CLASS2_CUSTOM                               "CLASS2_CUSTOM"
#define VSCP_CLASS2_DISPLAY                              "CLASS2_DISPLAY"
#define VSCP_CLASS2_MEASUREMENT_STR                      "CLASS2_MEASUREMENT_STR"
#define VSCP_CLASS2_VSCPD                                "CLASS2_VSCPD"



// ******** Value of class ********
#define VSCP_CLASS1_PROTOCOL_VALUE                            "0"
#define VSCP_CLASS1_ALARM_VALUE                               "1"
#define VSCP_CLASS1_SECURITY_VALUE                            "2"
#define VSCP_CLASS1_MEASUREMENT_VALUE                         "10"
#define VSCP_CLASS1_DATA_VALUE                                "15"
#define VSCP_CLASS1_INFORMATION_VALUE                         "20"
#define VSCP_CLASS1_CONTROL_VALUE                             "30"
#define VSCP_CLASS1_MULTIMEDIA_VALUE                          "40"
#define VSCP_CLASS1_AOL_VALUE                                 "50"
#define VSCP_CLASS1_MEASUREMENT64_VALUE			   			  "60"
#define VSCP_CLASS1_MEASUREZONE_VALUE						  "65"
#define VSCP_CLASS1_MEASUREMENT32_VALUE						  "70"
#define VSCP_CLASS1_SETVALUEZONE_VALUE						  "85"
#define VSCP_CLASS1_PHONE_VALUE                               "100"
#define VSCP_CLASS1_LIN_VALUE                                 "101"
#define VSCP_CLASS1_DISPLAY_VALUE                             "102"
#define VSCP_CLASS1_RC5_VALUE                                 "110"
#define VSCP_CLASS1_ONEWIRE_VALUE                             "200"
#define VSCP_CLASS1_X10_VALUE                                 "201"
#define VSCP_CLASS1_LON_VALUE                                 "202"
#define VSCP_CLASS1_EIB_VALUE                                 "203"
#define VSCP_CLASS1_SNAP_VALUE                                "204"
#define VSCP_CLASS1_MUMIN_VALUE                               "205"
#define VSCP_CLASS1_LOG_VALUE                                 "509"
#define VSCP_CLASS1_LAB_VALUE                                 "510"
#define VSCP_CLASS1_LOCAL_VALUE                               "511"

// Level I classes on Level II

#define VSCP_CLASS2_LEVEL1_PROTOCOL_VALUE                      "512"
#define VSCP_CLASS2_LEVEL1_ALARM_VALUE                         "513"
#define VSCP_CLASS2_LEVEL1_SECURITY_VALUE                      "514"
#define VSCP_CLASS2_LEVEL1_MEASUREMENT_VALUE                   "522"
#define VSCP_CLASS2_LEVEL1_DATA_VALUE                          "527"
#define VSCP_CLASS2_LEVEL1_INFORMATION_VALUE                   "532"
#define VSCP_CLASS2_LEVEL1_CONTROL_VALUE                       "542"
#define VSCP_CLASS2_LEVEL1_MULTIMEDIA_VALUE                    "552"
#define VSCP_CLASS2_LEVEL1_AOL_VALUE                           "562"
#define VSCP_CLASS2_MEASUREMENT64_VALUE						   "572"
#define VSCP_CLASS2_MEASUREZONE_VALUE						   "577"
#define VSCP_CLASS2_MEASUREMENT32_VALUE						   "582"
#define VSCP_CLASS2_SETVALUEZONE_VALUE						   "597"
#define VSCP_CLASS2_LEVEL1_PHONE_VALUE                         "612"
#define VSCP_CLASS2_LEVEL1_LIN_VALUE                           "613"
#define VSCP_CLASS2_LEVEL1_RC5_VALUE                           "622"
#define VSCP_CLASS2_LEVEL1_ONEWIRE_VALUE                       "712"
#define VSCP_CLASS2_LEVEL1_X10_VALUE                           "713"
#define VSCP_CLASS2_LEVEL1_LON_VALUE                           "714"
#define VSCP_CLASS2_LEVEL1_EIB_VALUE                           "715"
#define VSCP_CLASS2_LEVEL1_SNAP_VALUE                          "716"
#define VSCP_CLASS2_LEVEL1_MUMIN_VALUE                         "717"
#define VSCP_CLASS2_LEVEL1_LOG_VALUE                           "1021"
#define VSCP_CLASS2_LEVEL1_LAB_VALUE                           "1022"
#define VSCP_CLASS2_LEVEL1_LOCAL_VALUE                         "1023"

// Level II classes
#define VSCP_CLASS2_PROTOCOL_VALUE                             "1024"
#define VSCP_CLASS2_CONTROL_VALUE                              "1025"
#define VSCP_CLASS2_INFORMATION_VALUE                          "1026"
#define VSCP_CLASS2_TEXT2SPEECH_VALUE                          "1028"
#define VSCP_CLASS2_CUSTOM_VALUE                               "1029"
#define VSCP_CLASS2_DISPLAY_VALUE                              "1030"
#define VSCP_CLASS2_MEASUREMENT_STR_VALUE                      "1040"
#define VSCP_CLASS2_VSCPD_VALUE                                "65535"

#endif
