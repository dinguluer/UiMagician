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


#include <QtGui>
#include "generateapp.h"
#include "ui_generateapp.h"
#include "../common/timer/SleepTimerDelay.h"

#define VSCP_COPY_RIGHT_SINGLE_FLOOR "Copyright © 2014 VSCP Single Floor Layout"
#define VSCP_COPY_RIGHT_MULTI_FLOOR  "Copyright © 2014 VSCP Multi Floor Layout"

GenerateApp::GenerateApp(QString xmlFileName, QDomElement &xmlRoot, QWidget *parent) :
    QDialog(parent),
    xmlRootRef(xmlRoot),
    ui(new Ui::GenerateApp)
{
    ui->setupUi(this);

    // Set the xml file name
    xmlFileNameRef = xmlFileName;

    //QMessageBox::information(this, "name", xmlFileNameRef);

    //Load root nodes
    list = xmlRootRef.childNodes();

    // house floors
    houseFloor = SINGLE_FLOOR_HOUSE;
    xmlType = SINGLE_HOUSE;

    sensorCount = 0u;
    switchCount = 0u;
    variableSwitchCount = 0u;
    variableSliderCount = 0u;
    sensorTotal = 0u;
    switchTotal = 0u;
    variableSwitchTotal = 0u;
    variableSliderTotal = 0u;

    groupsTotal = 0u;
    lightsGroupTotal = 0u;
    accessoriesGroupTotal = 0u;
    blindDoorWindowGroupTotal = 0u;
    sensorGroupTotal = 0u;
    temperatureControllerGroupTotal = 0u;

    flagLightsGroup = 0;
    flagAccessoriesGroup = 0;
    flagBlindDoorWindowGroup = 0;
    flagsensorGroup = 0;
    flagTemperatureControllerGroup = 0;

    codingIndexSensor = "";

    sensorFlag = 0u;
    switchFlag = 0u;
    variableSwitchFlag = 0u;
    variableSliderFlag = 0u;

    firstLoopFlag = 0u;

    sensorIndex = "";
    sensorZone = "";
    sensorSubzone = "";
    //set the check box by default
    ui->htmlAppCheckBox->setChecked(true);
    // Progress bar set value
    ui->appGenerationProgressBar->setValue(25);

}

//reInitialise global variables
void GenerateApp::reInitializeGlobalVariables()
{

    sensorCount = 0u;
    switchCount = 0u;
    variableSwitchCount = 0u;
    variableSliderCount = 0u;

    sensorTotal = 0u;
    switchTotal = 0u;
    variableSwitchTotal = 0u;
    variableSliderTotal = 0u;

    flagLightsGroup = 0;
    flagAccessoriesGroup = 0;
    flagBlindDoorWindowGroup = 0;
    flagsensorGroup = 0;
    flagTemperatureControllerGroup = 0;

    codingIndexSensor = "";

    sensorFlag = 0u;
    switchFlag = 0u;
    variableSwitchFlag = 0u;
    variableSliderFlag = 0u;

    firstLoopFlag = 0u;

    sensorIndex = "";
    sensorZone = "";
    sensorSubzone = "";
}

//get sensor Image URL
void GenerateApp::getSensorDeviceImage(uint16_t deviceImageNumber , QString &sensorImageSrc)
{
    //Reduce by one -- so that index matches for sensor
    // image selector pop-up widget -- index starts from 1
    deviceImageNumber -= 1u;

    switch ( deviceImageNumber ) {

        case 0:
           sensorImageSrc = "../lib/widgets/measurement/length.jpg";
           break;

        case 1:
            sensorImageSrc = "../lib/widgets/measurement/count.jpg";
            break;

        case 2:
            sensorImageSrc = "../lib/widgets/measurement/length.jpg";
            break;

        case 3:
            sensorImageSrc = "../lib/widgets/measurement/mass.jpg";
            break;

       case 4:
            sensorImageSrc = "../lib/widgets/measurement/time.jpg";
            break;

        case 5:
            sensorImageSrc = "../lib/widgets/measurement/electric_current.jpg";
            break;

        case 6:
            sensorImageSrc = "../lib/widgets/measurement/temprature.png";
            break;

        case 7:
            sensorImageSrc = "../lib/widgets/measurement/amount_of_substance.jpg";
            break;

        case 8:
            sensorImageSrc = "../lib/widgets/measurement/intensity_of_light.jpg";
            break;

        case 9:
            sensorImageSrc = "../lib/widgets/measurement/frequency.jpg";
            break;

        case 10:
            sensorImageSrc = "../lib/widgets/measurement/radioactivity.jpg";
            break;

        case 11:
            sensorImageSrc = "../lib/widgets/measurement/force.png";
            break;

        case 12:
            sensorImageSrc = "../lib/widgets/measurement/pressure.jpg";
            break;

        case 13:
            sensorImageSrc = "../lib/widgets/measurement/energy.jpg";
            break;

        case 14:
            sensorImageSrc = "../lib/widgets/measurement/power.png";
            break;

        case 15:
            sensorImageSrc = "../lib/widgets/measurement/electrical_charge.png";
            break;

        case 16:
            sensorImageSrc = "../lib/widgets/measurement/electrical_potential_voltage.png";
            break;

        case 17:
            sensorImageSrc = "../lib/widgets/measurement/electrical_capacitance.jpg";
            break;

        case 18:
            sensorImageSrc = "../lib/widgets/measurement/electrical_resistance.png";
            break;

        case 19:
            sensorImageSrc = "../lib/widgets/measurement/electrical_conductance.png";
            break;

        case 20:
            sensorImageSrc = "../lib/widgets/measurement/electrical_magnetic_field.png";
            break;

        case 21:
            sensorImageSrc = "../lib/widgets/measurement/electrical_magnetic_flux.png";
            break;

        case 22:
            sensorImageSrc = "../lib/widgets/measurement/electrical_magnetic_flux_density.png";
            break;

        case 23:
            sensorImageSrc = "../lib/widgets/measurement/electrical_inductance.jpg";
            break;

        case 24:
            sensorImageSrc = "../lib/widgets/measurement/flux.jpg";
            break;

        case 25:
            sensorImageSrc = "../lib/widgets/measurement/illuminance.jpg";
            break;

        case 26:
            sensorImageSrc = "../lib/widgets/measurement/dose.png";
            break;

        case 27:
            sensorImageSrc = "../lib/widgets/measurement/catalyst.jpg";
            break;

        case 28:
            sensorImageSrc = "../lib/widgets/measurement/volume.jpg";
            break;

        case 29:
            sensorImageSrc = "../lib/widgets/measurement/sound_intensity.jpg";

            break;

        case 30:
            sensorImageSrc = "../lib/widgets/measurement/angle.jpg";
            break;

        case 31:
            sensorImageSrc = "../lib/widgets/measurement/position.png";
            break;

        case 32:
            sensorImageSrc = "../lib/widgets/measurement/speed.jpg";
            break;

        case 33:
            sensorImageSrc = "../lib/widgets/measurement/acceleration.png";
            break;

        case 34:
            sensorImageSrc = "../lib/widgets/measurement/tension.png";
            break;

        case 35:
            sensorImageSrc = "../lib/widgets/measurement/humidity.png";
            break;

        case 36:
            sensorImageSrc = "../lib/widgets/measurement/flowmeter.jpg";
            break;

        case 37:
            sensorImageSrc = "../lib/widgets/measurement/thermal_resistance.png";
            break;

        case 38:
            sensorImageSrc = "../lib/widgets/measurement/refractive_power.jpg";
            break;

        case 39:
            sensorImageSrc = "../lib/widgets/measurement/viscosity.png";
            break;

        case 40:
            sensorImageSrc = "../lib/widgets/measurement/sound_impedance.png";
            break;

        case 41:
            sensorImageSrc = "../lib/widgets/measurement/sound_resistance.png";
            break;

        case 42:
            sensorImageSrc = "../lib/widgets/measurement/Electric_elasticity.jpg";
            break;

        case 43:
            sensorImageSrc = "../lib/widgets/measurement/luminous_energy.jpg";
            break;

        case 44:
            sensorImageSrc = "../lib/widgets/measurement/luminance.jpg";
            break;

        case 45:
            sensorImageSrc = "../lib/widgets/measurement/chemical_concentration.png";
            break;

        case 46:
            sensorImageSrc = "../lib/widgets/measurement/reserved.jpg";
            break;

        case 47:
            sensorImageSrc = "../lib/widgets/measurement/dose.png";
            break;

        case 48:
            sensorImageSrc = "../lib/widgets/measurement/reserved.jpg";
            break;

        case 49:
            sensorImageSrc = "../lib/widgets/measurement/dewpoint.jpg";
            break;

        case 50:
            sensorImageSrc = "../lib/widgets/measurement/relative_level.png";
            break;

        case 51:
            sensorImageSrc = "../lib/widgets/measurement/altitude.png";
            break;

        case 52:
            sensorImageSrc = "../lib/widgets/measurement/area.jpg";
            break;

        case 53:
            sensorImageSrc = "../lib/widgets/measurement/radiant_intensity.png";
            break;

        case 54:
            sensorImageSrc = "../lib/widgets/measurement/radiance.jpg";
            break;

        case 55:
            sensorImageSrc = "../lib/widgets/measurement/irradiance.jpg";
            break;

        case 56:
            sensorImageSrc = "../lib/widgets/measurement/spectral_radiance.jpg";
            break;

        case 57:
            sensorImageSrc = "../lib/widgets/measurement/spectral_irradiance.jpg";
            break;

        default:
           sensorImageSrc  = "../lib/widgets/measurement/reserved.jpg";
            break;
    }

}

//get switch Image URL
void GenerateApp::getSwitchDeviceImage(uint16_t deviceImageNumber , QString &imageOn, QString &imageOff)
{

    switch ( deviceImageNumber ) {
        case 1:
            imageOn = "../lib/widgets/button/pressong.png";
            imageOff = "../lib/widgets/button/pressoffg.png";
            break;

        case 2:
            imageOn = "../lib/widgets/button/pressono.png";
            imageOff = "../lib/widgets/button/pressoffo.png";
            break;

        case 3:
            imageOn = "../lib/widgets/button/jbb1o.png";
            break;

       case 4:
            imageOn = "../lib/widgets/button/jbb2o.png";
            imageOff = "../lib/widgets/button/jbb2.png";
            break;

        case 5:
            imageOn = "../lib/widgets/button/jbgo.png";
            imageOff = "../lib/widgets/button/jbg.png";
            break;

        case 6:
            imageOn = "../lib/widgets/button/jboo.png";
            imageOff = "../lib/widgets/button/jbo.png";
            break;

        case 7:
            imageOn = "../lib/widgets/button/jbro.png";
            imageOff = "../lib/widgets/button/jbr.png";
            break;

        case 8:
            imageOn = "../lib/widgets/button/jbwo.png";
            imageOff = "../lib/widgets/button/jbw.png";
            break;

        case 9:
            imageOn = "../lib/widgets/button/jbyo.png";
            imageOff = "../lib/widgets/button/jby.png";
            break;

        case 10:
            imageOn = "../lib/widgets/button/jellyon.png";
            imageOff = "../lib/widgets/button/jellyoff.png";
            break;

        case 11:
            imageOn = "../lib/widgets/button/dualpushgreymirror.png";
            imageOff = "../lib/widgets/button/dualpushgrey.png";
            break;

        case 12:
            imageOn = "../lib/widgets/button/klunk.png";
            imageOff = "../lib/widgets/button/klunkmirror.png";
            break;

        case 13:
            imageOn = "../lib/widgets/button/klunk2.png";
            imageOff = "../lib/widgets/button/klunk2mirror.png";
            break;

        case 14:
            imageOn = "../lib/widgets/button/klunk4.png";
            imageOff = "../lib/widgets/button/klunk4mirror.png";
            break;

        case 15:
            imageOn = "../lib/widgets/button/polyblue.png";
            imageOff = "../lib/widgets/button/polywhiteH.png";
            break;

        case 16:
            imageOn = "../lib/widgets/button/polyredV.png";
            imageOff = "../lib/widgets/button/polywhiteV.png";
            break;

        case 17:
            imageOn = "../lib/widgets/button/pressonS.png";
            imageOff = "../lib/widgets/button/pressoffS.png";
            break;

        case 18:
            imageOn = "../lib/widgets/button/pressonSb.png";
            imageOff = "../lib/widgets/button/pressoffSb.png";
            break;

        case 19:
            imageOn = "../lib/widgets/button/pressonSg.png";
            imageOff = "../lib/widgets/button/pressoffSg.png";
            break;

        case 20:
            imageOn = "../lib/widgets/button/pressonSy.png";
            imageOff = "../lib/widgets/button/pressoffSy.png";
            break;

        case 21:
            imageOn = "../lib/widgets/button/pushout.png";
            imageOff = "../lib/widgets/button/pushin.png";
            break;

        case 22:
            imageOn = "../lib/widgets/button/pushoutw.png";
            imageOff = "../lib/widgets/button/pushinw.png";
            break;

        case 23:
            imageOn = "../lib/widgets/button/rockerblack.png";
            imageOff = "../lib/widgets/button/rockerblackleft.png";
            break;

        case 24:
            imageOn = "../lib/widgets/button/rockerblue.png";
            imageOff = "../lib/widgets/button/rockerblueleft.png";
            break;

        case 25:
            imageOn = "../lib/widgets/button/rockergrey.png";
            imageOff = "../lib/widgets/button/rockergreyleft.png";
            break;

        case 26:
            imageOn = "../lib/widgets/button/rockerred.png";
            imageOff = "../lib/widgets/button/rockerredleft.png";
            break;

        case 27:
            imageOn = "../lib/widgets/button/rockersmoothd.png";
            imageOff = "../lib/widgets/button/rockersmooth.png";
            break;


        case 28:
            imageOn = "../lib/widgets/button/rockersmoothBBd.png";
            imageOff = "../lib/widgets/button/rockersmoothBB.png";
            break;

        case 29:
            imageOn = "../lib/widgets/button/rockersmoothBBLd.png";
            imageOff = "../lib/widgets/button/rockersmoothBBL.png";
            break;

        case 30:
            imageOn = "../lib/widgets/button/rockersmoothBCd.png";
            imageOff = "../lib/widgets/button/rockersmoothBC.png";
            break;

        case 31:
            imageOn = "../lib/widgets/button/rockersmoothBGd.png";
            imageOff = "../lib/widgets/button/rockersmoothBG.png";
            break;

        case 32:
            imageOn = "../lib/widgets/button/rockersmoothBGRd.png";
            imageOff = "../lib/widgets/button/rockersmoothBGR.png";
            break;

        case 33:
            imageOn = "../lib/widgets/button/rockersmoothBWd.png";
            imageOff = "../lib/widgets/button/rockersmoothBW.png";
            break;

        case 34:
            imageOn = "../lib/widgets/button/rockersmoothBWRd.png";
            imageOff = "../lib/widgets/button/rockersmoothBWR.png";
            break;

        case 35:
            imageOn = "../lib/widgets/button/rockerwhite.png";
            imageOff = "../lib/widgets/button/rockerwhiteleft.png";
            break;

        case 36:
            imageOn = "../lib/widgets/button/sidbon.png";
            imageOff = "../lib/widgets/button/sidb.png";
            break;

        case 37:
            imageOn = "../lib/widgets/button/sidbongreen.png";
            imageOff = "../lib/widgets/button/sidb.png";
            break;

        case 38:
            imageOn = "../lib/widgets/button/sidbonblue.png";
            imageOff = "../lib/widgets/button/sidb.png";
            break;

        case 39:
            imageOn = "../lib/widgets/button/solinaOn.png";
            imageOff = "../lib/widgets/button/solinaOff.png";
            break;

        case 40:
            imageOn = "../lib/widgets/button/led-orange-round-button-in.png";
            imageOff = "../lib/widgets/button/led-orange-round-button-out.png";
            break;

        case 41:
            imageOn = "../lib/widgets/button/led_circle_red.png";
            imageOff = "../lib/widgets/button/led_circle_grey.png";
            break;

        case 42:
            imageOn = "../lib/widgets/button/led_circle_yellow_.png";
            imageOff = "../lib/widgets/button/led_circle_grey.png";
            break;

        case 43:
            imageOn = "../lib/widgets/button/led-green.png";
            imageOff = "../lib/widgets/button/led_circle_grey.png";
            break;

        case 44:
            imageOn = "../lib/widgets/button/led-green-button2.png";
            imageOff = "../lib/widgets/button/led_circle_grey.png";
            break;

        case 45:
            imageOn = "../lib/widgets/button/led_circle_green.png";
            imageOff = "../lib/widgets/button/led_circle_grey.png";
            break;

        case 46:
            imageOn = "../lib/widgets/button/led_circle_orange.png";
            imageOff = "../lib/widgets/button/led_circle_grey.png";

            break;

        case 47:
            imageOn = "../lib/widgets/button/led_circle_purple.png";
            imageOff = "../lib/widgets/button/led_circle_grey.png";
            break;

        case 48:
            imageOn = "../lib/widgets/button/led_circle_blue.png";
            imageOff = "../lib/widgets/button/led_circle_grey.png";

            break;

        case 49:
            imageOn = "../lib/widgets/button/led-red-on.png";
            imageOff = "../lib/widgets/button/led-red-off.png";
            break;

        case 50:
            imageOn = "../lib/widgets/button/led-green.png";
            imageOff = "../lib/widgets/button/led_circle_green.png";
            break;

        case 51:
            imageOn = "../lib/widgets/button/led_circle_green.png";
            imageOff = "../lib/widgets/button/led-red-off.png";
            break;

        case 52:
            imageOn = "../lib/widgets/button/poweron.png";
            imageOff = "../lib/widgets/button/poweroff.png";
            break;

        case 53:
            imageOn = "../lib/widgets/button/push-button-light-blue.png";
            imageOff = "../lib/widgets/button/push-button-glossy-red.png";
            break;

        case 54:
            imageOn = "../lib/widgets/button/push-button-yellow-glossy.png";
            imageOff = "../lib/widgets/button/push-button-glossy-red.png";
            break;

        case 55:
            imageOn = "../lib/widgets/button/push-button-light-blue.png";
            imageOff = "../lib/widgets/button/push-button-yellow-glossy.png";
            break;

        case 56:
            imageOn = "../lib/widgets/button/light_switch_on.png";
            imageOff = "../lib/widgets/button/light_switch_off.png";
            break;

        case 57:
            imageOn = "../lib/widgets/button/sw2.png";
            imageOff = "../lib/widgets/button/sw1.png";
            break;

        case 58:
            imageOn = "../lib/widgets/button/sw3.png";
            imageOff = "../lib/widgets/button/sw5.png";
            break;

        case 59:
            imageOn = "../lib/widgets/button/switch3.png";
            imageOff = "../lib/widgets/button/switch1.png";
            break;

        case 60:
            imageOn = "../lib/widgets/button/touchy.png";
            imageOff = "../lib/widgets/button/touchoy.png";
            break;

        case 61:
            imageOn = "../lib/widgets/button/touchw.png";
            imageOff = "../lib/widgets/button/touchow.png";
            break;

        case 62:
            imageOn = "../lib/widgets/button/toucho.png";
            imageOff = "../lib/widgets/button/touchoo.png";
            break;

        case 63:
            imageOn = "../lib/widgets/button/btn_led_rectangular_vh_black.png";
            imageOff = "../lib/widgets/button/btn_led_rectangular_v_black.png";
            break;

        case 64:
            imageOn = "../lib/widgets/button/btn-led_rounded_vh_black.png";
            imageOff = "../lib/widgets/button/btn-led_rounded_v_black.png";
            break;

        case 65:
            imageOn = "../lib/widgets/button/btn-led_rounded_vh_grey.png";
            imageOff = "../lib/widgets/button/btn-led_rounded_v_grey.png";
            break;

        case 66:
            imageOn = "../lib/widgets/button/btn_pressdown_on.png";
            imageOff = "../lib/widgets/button/btn_pressdown_off.png";
            break;

        case 67:
            imageOn = "../lib/widgets/button/btn_pressdown2_on.png";
            imageOff = "../lib/widgets/button/btn_pressdown2_off.png";
            break;

        case 68:
            imageOn = "../lib/widgets/button/red-rectangle-blank-button-on.png";
            imageOff = "../lib/widgets/button/red-rectangle-blank-button2-off.png";
            break;

        case 69:
            imageOn = "../lib/widgets/button/run-push-button-on.png";
            imageOff = "../lib/widgets/button/run-push-button-off.png";
            break;

        case 70:
            imageOn = "../lib/widgets/button/btn-silver-on.png";
            imageOff = "../lib/widgets/button/btn-silver-off.png";
            break;

        case 71:
            imageOn = "../lib/widgets/button/stop.png";
            imageOff = "../lib/widgets/button/start.png";
            break;

        case 72:
            imageOn = "../lib/widgets/button/switch-knob-on.png";
            imageOff = "../lib/widgets/button/switch-knob-off.png";
            break;

        case 73:
            imageOn = "../lib/widgets/button/SwtchON1.png";
            imageOff = "../lib/widgets/button/SwtchOF1.png";
            break;

        case 74:
            imageOn = "../lib/widgets/button/system-shut-down-on.png";
            imageOff = "../lib/widgets/button/system-shut-down-off.png";
            break;

        case 75:
            imageOn = "../lib/widgets/button/brami_Square_Black_Crystal_Button.on.png";
            imageOff = "../lib/widgets/button/brami_Square_Black_Crystal_Button.off.png";
            break;

        case 76:
            imageOn = "../lib/widgets/button/btncpgreen-on.png";
            imageOff = "../lib/widgets/button/btncpgreen-off.png";
            break;

        case 77:
            imageOn = "../lib/widgets/button/btncpmag-on.png";
            imageOff = "../lib/widgets/button/btncpmag-off.png";
            break;

        case 78:
            imageOn = "../lib/widgets/button/button-for-numbers-on.png";
            imageOff = "../lib/widgets/button/button-for-numbers-off.png";
            break;

        case 79:
            imageOn = "../lib/widgets/button/button-green-on.png";
            imageOff = "../lib/widgets/button/button-green-off.png";
            break;

        case 80:
            imageOn = "../lib/widgets/button/button-on.png";
            imageOff = "../lib/widgets/button/button-off.png";
            break;

        case 81:
            imageOn = "../lib/widgets/button/button-power-on.png";
            imageOff = "../lib/widgets/button/button-power-off.png";
            break;

        case 82:
            imageOn = "../lib/widgets/button/btn-grey-rounded-on.png";
            imageOff = "../lib/widgets/button/btn-grey-rounded-off.png";
            break;

        case 83:
            imageOn = "../lib/widgets/button/btn-grey-on.png";
            imageOff = "../lib/widgets/button/btn-grey-off.png";
            break;

        case 84:
            imageOn = "../lib/widgets/button/interruptor-on.png";
            imageOff = "../lib/widgets/button/interruptor-off.png";
            break;

        case 85:
            imageOn = "../lib/widgets/button/knife_switch_on.png";
            imageOff = "../lib/widgets/button/knife_switch_off.png";
            break;

        case 86:
            imageOn = "../lib/widgets/button/on-button.png";
            imageOff = "../lib/widgets/button/off-button.png";
            break;

        case 87:
            imageOn = "../lib/widgets/button/btn-modern-on.png";
            imageOff = "../lib/widgets/button/btn-modern-off.png";
            break;

        case 88:
            imageOn = "../lib/widgets/button/btn-oldstyle-on.png";
            imageOff = "../lib/widgets/button/btn-oldstyle-off.png";
            break;

        case 89:
            imageOn = "../lib/widgets/button/orange-button-on.png";
            imageOff = "../lib/widgets/button/orange-button-off.png";
            break;

        case 90:
            imageOn = "../lib/widgets/light/lightbulb1_on.png";
            imageOff = "../lib/widgets/light/lightbulb1_off.png";
            break;

        case 91:
            imageOn = "../lib/widgets/light/light_red.gif";
            imageOff = "../lib/widgets/light/light_green.gif";
            break;

        case 92:
            imageOn = "../lib/widgets/lightbulb/semi-matte-light-bulb-lit-th.png";
            imageOff = "../lib/widgets/lightbulb/semi-matte-light-bulb-unlit-th.png";
            break;

        case 93:
            imageOn = "../lib/widgets/lightbulb/lightbulb-th.png";
            imageOff = "../lib/widgets/lightbulb/lightbulb-white-th.png";
            break;

        case 94:
            imageOn = "../lib/widgets/lightbulb/glossy-light-bulb.jpg";
            imageOff = "../lib/widgets/lightbulb/light-bulb-icon.jpg";
            break;

        default:
            imageOn = "../lib/widgets/button/presson.png";
            imageOff = "../lib/widgets/button/pressoff.png";
            break;
    }
}

//get slider Image URL
void GenerateApp::getSliderDeviceImage(uint16_t deviceImageNumber , QString &imageSlider)
{
    // Index starting from 2 because -- in file -- widgetimageselectorvariableswitch.h
    // #define FIRST_SLIDER_IMAGE                     "2"
    switch ( deviceImageNumber ) {
    case 2:
        imageSlider = "../lib/widgets/button_variable/sliderDefault.png";
        break;

    default:
        imageSlider = "../lib/widgets/button_variable/sliderDefault.png";
        break;
    }
}

//get switch variable button Image URL
void GenerateApp::getSwitchVariableButtonDeviceImage(uint16_t deviceImageNumber ,QString &switchButtonUpImageSrc, QString &switchButtonDownImageSrc)
{    
    switch ( deviceImageNumber ) {
    case 1:
        switchButtonUpImageSrc = "../lib/widgets/button_variable/up.jpg";
        switchButtonDownImageSrc = "../lib/widgets/button_variable/down.jpg";
        break;

    default:
        switchButtonUpImageSrc = "../lib/widgets/button_variable/up.jpg";
        switchButtonDownImageSrc = "../lib/widgets/button_variable/down.jpg";
        break;

    }
}

//Append value to variables & dm xml files
void GenerateApp::prepareVariablesDmXmlFile(QDomNode &tempNodeChild , QString PacketType)
{
    QDomElement NodeElementTemp;
    QString tempString;

    // Make the node element
    NodeElementTemp = xmlVariablesDomDocument.createElement("variable");
    if(PacketType == PACKET_SWITCH_TEXT)
    {
        NodeElementTemp.setAttribute("type","bool");
    }
    else if(PacketType == PACKET_SENSOR_TEXT)
    {
        NodeElementTemp.setAttribute("type","data");
    }
    else if(PacketType == PACKET_VARIABLE_SWITCH_TEXT)
    {
        NodeElementTemp.setAttribute("type","integer");
    }
    else if(PacketType == PACKET_SLIDER_TEXT)
    {
        if((txEventClassSlider==VSCP_CLASS1_CONTROL_VALUE)&&(txEventTypeSlider==VSCP_TYPE_CONTROL_DIM_LAMPS_VALUE))
        {
            NodeElementTemp.setAttribute("type","integer");
        }
        else
        {
            NodeElementTemp.setAttribute("type","data");
        }
    }
    else
    {
        // Do nothing
    }

        //get the variable name
        tempString = tempNodeChild.toElement().attribute(VARIABLE_NAME);
        //Create name node
        nodeChildName = "name";
        NodeElementChild = xmlVariablesDomDocument.createElement(nodeChildName);
        textNode = htmlDomDocument.createTextNode(tempString);
        NodeElementChild.appendChild(textNode);
        NodeElementTemp.appendChild(NodeElementChild);

        //QMessageBox::information(this, "uiMagician", tempString);

        //Create value node
        if(PacketType == PACKET_SWITCH_TEXT)
        {
            tempString = "false";
        }
        else if(PacketType == PACKET_SENSOR_TEXT)
        {
            tempString = "0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00";
            //tempString = "0x00;0x00;0x00;0x00;0x00;0x00;0x00;0x00";
        }
        else if(PacketType == PACKET_VARIABLE_SWITCH_TEXT)
        {
            tempString = "0x00";
        }
        else if(PacketType == PACKET_SLIDER_TEXT)
        {
            if((txEventClassSlider==VSCP_CLASS1_CONTROL_VALUE)&&(txEventTypeSlider==VSCP_TYPE_CONTROL_DIM_LAMPS_VALUE))
            {
                tempString = "0x00";
            }
            else
            {
                tempString = "0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00";
                //tempString = "0x00;0x00;0x00;0x00;0x00;0x00;0x00;0x00";
                //tempString = "0x00";
            }
        }
        else
        {
            // Do nothing
        }
        nodeChildName = "value";
        NodeElementChild = xmlVariablesDomDocument.createElement(nodeChildName);
        textNode = htmlDomDocument.createTextNode(tempString);
        NodeElementChild.appendChild(textNode);
        NodeElementTemp.appendChild(NodeElementChild);

        //Create note node
        if(PacketType == PACKET_SWITCH_TEXT)
        {
            tempString = "A boolean Switch variable";
        }
        else if(PacketType == PACKET_SENSOR_TEXT)
        {
            tempString = "This is an sensor Measurement Data variable";
        }
        else if(PacketType == PACKET_SLIDER_TEXT)
        {
            if((txEventClassSlider==VSCP_CLASS1_CONTROL_VALUE)&&(txEventTypeSlider==VSCP_TYPE_CONTROL_DIM_LAMPS_VALUE))
            {
                tempString = "This is an slider variable";
            }
            else
            {
                //tempString = "A integer slider/variable button value variable";
                tempString = "This is an slider variable";
            }

        }
        else if(PacketType == PACKET_VARIABLE_SWITCH_TEXT)
        {
            //tempString = "This is an slider Data string variable";
            tempString = "This is an slider/variable button variable";
        }
        else
        {
            // Do nothing
        }
        nodeChildName = "note";
        NodeElementChild = xmlVariablesDomDocument.createElement(nodeChildName);
        textNode = htmlDomDocument.createTextNode(tempString);
        NodeElementChild.appendChild(textNode);
        NodeElementTemp.appendChild(NodeElementChild);

    // Append node to dom document
    xmlVariablesRoot.appendChild(NodeElementTemp);

    //QMessageBox::information(this, "uiMagician", QString::number(xmlVariablesRoot.childNodes().size()));

    NodeElementTemp.clear();

    //Create dm.xml node
    if(PacketType == PACKET_SWITCH_TEXT)
    {

        //get the variable name
        tempString = tempNodeChild.toElement().attribute(VARIABLE_GROUPID);
        if(tempString == "")
        {
            tempString = "switches";
        }
        // Make the node element
        NodeElementTemp = xmlDmDomDocument.createElement("row");
        NodeElementTemp.setAttribute("enable","true");
        NodeElementTemp.setAttribute("groupid",tempString);

        // variable ON event entry
            // Mask node
            tempString = "";
            //Create name node
            nodeChildName = "mask";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            //get the priority name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_PRIORITY);
            if(tempString == "")
            {
                tempString = "0";
            }
            NodeElementChild.setAttribute("priority",tempString);
            //get the class name
            tempString = "65535";
            NodeElementChild.setAttribute("class",tempString);
            //get the type name
            tempString = "65535";
            NodeElementChild.setAttribute("type",tempString);
            //get the GUID name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_GUID);
            if(tempString == "")
            {
                tempString = "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00";
            }
            else
            {
                tempString = "FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF";
            }
            NodeElementChild.setAttribute("GUID",tempString);
            NodeElementTemp.appendChild(NodeElementChild);


            // Filter node
            tempString = "";
            //Create name node
            nodeChildName = "filter";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            //get the priority name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_PRIORITY);
            if(tempString == "")
            {
                tempString = "0";
            }
            NodeElementChild.setAttribute("priority",tempString);
            //get the class name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_SWITCH_CLASS_ON);
            if(tempString == "")
            {
                tempString = "30";
            }
            NodeElementChild.setAttribute("class",tempString);
            //get the type name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_SWITCH_TYPE_ON);
            if(tempString == "")
            {
                tempString = "5";
            }
            NodeElementChild.setAttribute("type",tempString);
            //get the GUID name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_GUID);
            if(tempString == "")
            {
                tempString = "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00";
            }
            NodeElementChild.setAttribute("GUID",tempString);
            NodeElementTemp.appendChild(NodeElementChild);

            // control node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_CONTROL);
            //Create name node
            nodeChildName = "control";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // action node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ACTION);
            //Create name node
            nodeChildName = "action";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // param node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ACTION_PARAMETERS_SET);
            //Create name node
            nodeChildName = "param";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // comment node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_COMMENTS);
            //Create name node
            nodeChildName = "comment";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_from node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_FROM);
            if(tempString == "")
            {
                tempString = "1970-01-01 00:00:00";
            }
            //Create name node
            nodeChildName = "allowed_from";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_to node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_TO);
            if(tempString == "")
            {
                tempString = "2099-01-01 00:00:00";
            }
            //Create name node
            nodeChildName = "allowed_to";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_weekdays node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_DAYS);
            if(tempString == "")
            {
                tempString = "mtwtfss";
            }
            //Create name node
            nodeChildName = "allowed_weekdays";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_time node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_TIME);
            if(tempString == "")
            {
                tempString = "*-*-* *:*:*";
            }
            //Create name node
            nodeChildName = "allowed_time";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // index node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_INDEX);
            if(tempString == "")
            {
                tempString = "0";
            }
            //Create name node
            nodeChildName = "index";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // zone node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ZONE);
            if(tempString == "")
            {
                tempString = "0";
            }
            //Create name node
            nodeChildName = "zone";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // subzone node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_SUBZONE);
            if(tempString == "")
            {
                tempString = "0";
            }
            //Create name node
            nodeChildName = "subzone";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // Append node to dom document
            xmlDmRoot.appendChild(NodeElementTemp);


       //variable OFF event entry
            NodeElementTemp.clear();
            //get the variable name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_GROUPID);
            if(tempString == "")
            {
                tempString = "switches";
            }
            // Make the node element
            NodeElementTemp = xmlDmDomDocument.createElement("row");
            NodeElementTemp.setAttribute("enable","true");
            NodeElementTemp.setAttribute("groupid",tempString);

            // Mask node
            tempString = "";
            //Create name node
            nodeChildName = "mask";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            //get the priority name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_PRIORITY);
            if(tempString == "")
            {
                tempString = "0";
            }
            NodeElementChild.setAttribute("priority",tempString);
            //get the class name
            tempString = "65535";
            NodeElementChild.setAttribute("class",tempString);
            //get the type name
            tempString = "65535";
            NodeElementChild.setAttribute("type",tempString);
            //get the GUID name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_GUID);
            if(tempString == "")
            {
                tempString = "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00";
            }
            else
            {
                tempString = "FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF";
            }
            NodeElementChild.setAttribute("GUID",tempString);
            NodeElementTemp.appendChild(NodeElementChild);


            // Filter node
            tempString = "";
            //Create name node
            nodeChildName = "filter";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            //get the priority name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_PRIORITY);
            if(tempString == "")
            {
                tempString = "0";
            }
            NodeElementChild.setAttribute("priority",tempString);
            //get the class name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_SWITCH_CLASS_OFF);
            if(tempString == "")
            {
                tempString = "30";
            }
            NodeElementChild.setAttribute("class",tempString);
            //get the type name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_SWITCH_TYPE_OFF);
            if(tempString == "")
            {
                tempString = "5";
            }
            NodeElementChild.setAttribute("type",tempString);
            //get the GUID name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_GUID);
            if(tempString == "")
            {
                tempString = "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00";
            }
            NodeElementChild.setAttribute("GUID",tempString);
            NodeElementTemp.appendChild(NodeElementChild);

            // control node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_CONTROL);
            //Create name node
            nodeChildName = "control";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // action node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ACTION);
            //Create name node
            nodeChildName = "action";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // param node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ACTION_PARAMETERS_RESET);
            //Create name node
            nodeChildName = "param";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // comment node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_COMMENTS);
            //Create name node
            nodeChildName = "comment";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_from node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_FROM);
            if(tempString == "")
            {
                tempString = "1970-01-01 00:00:00";
            }
            //Create name node
            nodeChildName = "allowed_from";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_to node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_TO);
            if(tempString == "")
            {
                tempString = "2099-01-01 00:00:00";
            }
            //Create name node
            nodeChildName = "allowed_to";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_weekdays node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_DAYS);
            if(tempString == "")
            {
                tempString = "mtwtfss";
            }
            //Create name node
            nodeChildName = "allowed_weekdays";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_time node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_TIME);
            if(tempString == "")
            {
                tempString = "*-*-* *:*:*";
            }
            //Create name node
            nodeChildName = "allowed_time";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // index node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_INDEX);
            if(tempString == "")
            {
                tempString = "0";
            }
            //Create name node
            nodeChildName = "index";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // zone node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ZONE);
            if(tempString == "")
            {
                tempString = "0";
            }
            //Create name node
            nodeChildName = "zone";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // subzone node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_SUBZONE);
            if(tempString == "")
            {
                tempString = "0";
            }
            //Create name node
            nodeChildName = "subzone";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // Append node to dom document
            xmlDmRoot.appendChild(NodeElementTemp);

    }
    else if(PacketType == PACKET_SENSOR_TEXT)
    {
        // sensor event entry

        //get the variable name
        tempString = tempNodeChild.toElement().attribute(VARIABLE_GROUPID);
        if(tempString == "")
        {
            tempString = "sensors";
        }
        // Make the node element
        NodeElementTemp = xmlDmDomDocument.createElement("row");
        NodeElementTemp.setAttribute("enable","true");
        NodeElementTemp.setAttribute("groupid",tempString);

        // variable ON event entry
            // Mask node
            tempString = "";
            //Create name node
            nodeChildName = "mask";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            //get the priority name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_PRIORITY);
            if(tempString == "")
            {
                tempString = "0";
            }
            NodeElementChild.setAttribute("priority",tempString);
            //get the class name
            tempString = "65535";
            NodeElementChild.setAttribute("class",tempString);
            //get the type name
            tempString = "65535";
            NodeElementChild.setAttribute("type",tempString);
            //get the GUID name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_GUID);
            if(tempString == "")
            {
                tempString = "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00";
            }
            else
            {
                tempString = "FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF";
            }
            NodeElementChild.setAttribute("GUID",tempString);
            NodeElementTemp.appendChild(NodeElementChild);


            // Filter node
            tempString = "";
            //Create name node
            nodeChildName = "filter";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            //get the priority name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_PRIORITY);
            if(tempString == "")
            {
                tempString = "0";
            }
            NodeElementChild.setAttribute("priority",tempString);
            //get the class name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_CLASS);
            if(tempString == "")
            {
                tempString = "30";
            }
            NodeElementChild.setAttribute("class",tempString);
            //get the type name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_TYPE);
            if(tempString == "")
            {
                tempString = "5";
            }
            NodeElementChild.setAttribute("type",tempString);
            //get the GUID name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_GUID);
            if(tempString == "")
            {
                tempString = "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00";
            }
            NodeElementChild.setAttribute("GUID",tempString);
            NodeElementTemp.appendChild(NodeElementChild);

            // control node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_CONTROL);
            //Create name node
            nodeChildName = "control";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // action node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ACTION);
            //Create name node
            nodeChildName = "action";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // param node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ACTION_PARAMETERS);
            //Create name node
            nodeChildName = "param";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // comment node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_COMMENTS);
            //Create name node
            nodeChildName = "comment";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_from node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_FROM);
            if(tempString == "")
            {
                tempString = "1970-01-01 00:00:00";
            }
            //Create name node
            nodeChildName = "allowed_from";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_to node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_TO);
            if(tempString == "")
            {
                tempString = "2099-01-01 00:00:00";
            }
            //Create name node
            nodeChildName = "allowed_to";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_weekdays node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_DAYS);
            if(tempString == "")
            {
                tempString = "mtwtfss";
            }
            //Create name node
            nodeChildName = "allowed_weekdays";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_time node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_TIME);
            if(tempString == "")
            {
                tempString = "*-*-* *:*:*";
            }
            //Create name node
            nodeChildName = "allowed_time";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            if(txEventClassSensor==VSCP_CLASS1_MEASUREZONE_VALUE)
            {
                // index node
                tempString = tempNodeChild.toElement().attribute(VARIABLE_INDEX);
                if(tempString == "")
                {
                    tempString = "0";
                }
                sensorIndex = tempString;
                //Create name node
                nodeChildName = "index";
                NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
                textNode = htmlDomDocument.createTextNode(tempString);
                NodeElementChild.appendChild(textNode);
                NodeElementTemp.appendChild(NodeElementChild);

                // zone node
                tempString = tempNodeChild.toElement().attribute(VARIABLE_ZONE);
                if(tempString == "")
                {
                    tempString = "0";
                }
                sensorZone = tempString;
                //Create name node
                nodeChildName = "zone";
                NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
                textNode = htmlDomDocument.createTextNode(tempString);
                NodeElementChild.appendChild(textNode);
                NodeElementTemp.appendChild(NodeElementChild);

                // subzone node
                tempString = tempNodeChild.toElement().attribute(VARIABLE_SUBZONE);
                if(tempString == "")
                {
                    tempString = "0";
                }
                sensorSubzone = tempString;
                //Create name node
                nodeChildName = "subzone";
                NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
                textNode = htmlDomDocument.createTextNode(tempString);
                NodeElementChild.appendChild(textNode);
                NodeElementTemp.appendChild(NodeElementChild);
            }
            else
            {
                // codingIndex sensor node
                /*tempString = codingIndexSensor;
                if(tempString == "")
                {
                    tempString = "0";
                }*/
                //sensorIndex = tempString;
                sensorIndex = "";
                //Create name node
                nodeChildName = "index";
                NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
                NodeElementChild.setAttribute(SENSOR_ENABLE_MESUREMENT_CODING_INDEX,"true");
                textNode = htmlDomDocument.createTextNode(tempString);
                NodeElementChild.appendChild(textNode);
                NodeElementTemp.appendChild(NodeElementChild);
            }

            // Append node to dom document
            xmlDmRoot.appendChild(NodeElementTemp);

    }
    else if(PacketType == PACKET_SLIDER_TEXT)
    {
        // sensor event entry

        //get the variable name
        tempString = tempNodeChild.toElement().attribute(VARIABLE_GROUPID);
        if(tempString == "")
        {
            tempString = "slider";
        }
        // Make the node element
        NodeElementTemp = xmlDmDomDocument.createElement("row");
        NodeElementTemp.setAttribute("enable","true");
        NodeElementTemp.setAttribute("groupid",tempString);

        // variable ON event entry
            // Mask node
            tempString = "";
            //Create name node
            nodeChildName = "mask";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            //get the priority name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_PRIORITY);
            if(tempString == "")
            {
                tempString = "0";
            }
            NodeElementChild.setAttribute("priority",tempString);
            //get the class name
            tempString = "65535";
            NodeElementChild.setAttribute("class",tempString);
            //get the type name
            tempString = "65535";
            NodeElementChild.setAttribute("type",tempString);
            //get the GUID name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_GUID);
            if(tempString == "")
            {
                tempString = "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00";
            }
            else
            {
                tempString = "FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF";
            }
            NodeElementChild.setAttribute("GUID",tempString);
            NodeElementTemp.appendChild(NodeElementChild);


            // Filter node
            tempString = "";
            //Create name node
            nodeChildName = "filter";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            //get the priority name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_PRIORITY);
            if(tempString == "")
            {
                tempString = "0";
            }
            NodeElementChild.setAttribute("priority",tempString);
            //get the class name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_CLASS);
            if(tempString == "")
            {
                tempString = "30";
            }
            NodeElementChild.setAttribute("class",tempString);
            //get the type name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_TYPE);
            if(tempString == "")
            {
                tempString = "5";
            }
            NodeElementChild.setAttribute("type",tempString);
            //get the GUID name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_GUID);
            if(tempString == "")
            {
                tempString = "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00";
            }
            NodeElementChild.setAttribute("GUID",tempString);
            NodeElementTemp.appendChild(NodeElementChild);

            // control node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_CONTROL);
            //Create name node
            nodeChildName = "control";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // action node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ACTION);
            //Create name node
            nodeChildName = "action";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // param node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ACTION_PARAMETERS);
            //Create name node
            nodeChildName = "param";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // comment node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_COMMENTS);
            //Create name node
            nodeChildName = "comment";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_from node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_FROM);
            if(tempString == "")
            {
                tempString = "1970-01-01 00:00:00";
            }
            //Create name node
            nodeChildName = "allowed_from";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_to node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_TO);
            if(tempString == "")
            {
                tempString = "2099-01-01 00:00:00";
            }
            //Create name node
            nodeChildName = "allowed_to";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_weekdays node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_DAYS);
            if(tempString == "")
            {
                tempString = "mtwtfss";
            }
            //Create name node
            nodeChildName = "allowed_weekdays";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_time node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_TIME);
            if(tempString == "")
            {
                tempString = "*-*-* *:*:*";
            }
            //Create name node
            nodeChildName = "allowed_time";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            if((txEventClassSlider==VSCP_CLASS1_CONTROL_VALUE)&&(txEventTypeSlider==VSCP_TYPE_CONTROL_DIM_LAMPS_VALUE))
            {
                //Do not create Index Node
            }
            else
            {
                // index node -->
                // create it for both VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL & VSCP_TYPE_CONTROL_DIM_LAMPS
                // Javascript code will take care of index for both Types

                tempString = tempNodeChild.toElement().attribute(VARIABLE_INDEX);
                if(tempString == "")
                {
                    tempString = "0";
                }
                //sensorIndex = tempString;
                //Create name node
                nodeChildName = "index";
                NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
                textNode = htmlDomDocument.createTextNode(tempString);
                NodeElementChild.appendChild(textNode);
                NodeElementTemp.appendChild(NodeElementChild);

            }

            // zone node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ZONE);
            if(tempString == "")
            {
                tempString = "0";
            }
            //sensorZone = tempString;
            //Create name node
            nodeChildName = "zone";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // subzone node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_SUBZONE);
            if(tempString == "")
            {
                tempString = "0";
            }
            //sensorSubzone = tempString;
            //Create name node
            nodeChildName = "subzone";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // Append node to dom document
            xmlDmRoot.appendChild(NodeElementTemp);

    }
    else if(PacketType == PACKET_VARIABLE_SWITCH_TEXT)
    {
        // sensor event entry

        //get the variable name
        tempString = tempNodeChild.toElement().attribute(VARIABLE_GROUPID);
        if(tempString == "")
        {
            tempString = "variableSwitch";
        }
        // Make the node element
        NodeElementTemp = xmlDmDomDocument.createElement("row");
        NodeElementTemp.setAttribute("enable","true");
        NodeElementTemp.setAttribute("groupid",tempString);

        // variable ON event entry
            // Mask node
            tempString = "";
            //Create name node
            nodeChildName = "mask";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            //get the priority name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_PRIORITY);
            if(tempString == "")
            {
                tempString = "0";
            }
            NodeElementChild.setAttribute("priority",tempString);
            //get the class name
            tempString = "65535";
            NodeElementChild.setAttribute("class",tempString);
            //get the type name
            tempString = "65535";
            NodeElementChild.setAttribute("type",tempString);
            //get the GUID name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_GUID);
            if(tempString == "")
            {
                tempString = "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00";
            }
            else
            {
                tempString = "FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF:FF";
            }
            NodeElementChild.setAttribute("GUID",tempString);
            NodeElementTemp.appendChild(NodeElementChild);


            // Filter node
            tempString = "";
            //Create name node
            nodeChildName = "filter";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            //get the priority name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_PRIORITY);
            if(tempString == "")
            {
                tempString = "0";
            }
            NodeElementChild.setAttribute("priority",tempString);
            //get the class name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_CLASS);
            if(tempString == "")
            {
                tempString = "30";
            }
            NodeElementChild.setAttribute("class",tempString);
            //get the type name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_TYPE);
            if(tempString == "")
            {
                tempString = "5";
            }
            NodeElementChild.setAttribute("type",tempString);
            //get the GUID name
            tempString = tempNodeChild.toElement().attribute(VARIABLE_GUID);
            if(tempString == "")
            {
                tempString = "00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00";
            }
            NodeElementChild.setAttribute("GUID",tempString);
            NodeElementTemp.appendChild(NodeElementChild);

            // control node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_CONTROL);
            //Create name node
            nodeChildName = "control";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // action node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ACTION);
            //Create name node
            nodeChildName = "action";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // param node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ACTION_PARAMETERS);
            //Create name node
            nodeChildName = "param";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // comment node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_COMMENTS);
            //Create name node
            nodeChildName = "comment";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_from node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_FROM);
            if(tempString == "")
            {
                tempString = "1970-01-01 00:00:00";
            }
            //Create name node
            nodeChildName = "allowed_from";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_to node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_TO);
            if(tempString == "")
            {
                tempString = "2099-01-01 00:00:00";
            }
            //Create name node
            nodeChildName = "allowed_to";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_weekdays node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_DAYS);
            if(tempString == "")
            {
                tempString = "mtwtfss";
            }
            //Create name node
            nodeChildName = "allowed_weekdays";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // allowed_time node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ALLOWED_TIME);
            if(tempString == "")
            {
                tempString = "*-*-* *:*:*";
            }
            //Create name node
            nodeChildName = "allowed_time";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            /*
            // index node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_INDEX);
            if(tempString == "")
            {
                tempString = "0";
            }
            sensorIndex = tempString;
            //Create name node
            nodeChildName = "index";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);*/

            // zone node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_ZONE);
            if(tempString == "")
            {
                tempString = "0";
            }
            //sensorZone = tempString;
            //Create name node
            nodeChildName = "zone";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // subzone node
            tempString = tempNodeChild.toElement().attribute(VARIABLE_SUBZONE);
            if(tempString == "")
            {
                tempString = "0";
            }
            //sensorSubzone = tempString;
            //Create name node
            nodeChildName = "subzone";
            NodeElementChild = xmlDmDomDocument.createElement(nodeChildName);
            textNode = htmlDomDocument.createTextNode(tempString);
            NodeElementChild.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChild);

            // Append node to dom document
            xmlDmRoot.appendChild(NodeElementTemp);

    }
    else
    {
        // Do nothing
    }

}

//prepare the Packet format for each device socket
void GenerateApp::prepareSocketConf(QDomNode &tempNodeDevicePacket, QString DeviceId, QString DeviceLocalTxtId, QString VariableButtonOneId, QString VariableButtonTwoId, QString deviceImage, QString houseName)
{
    QDomNodeList listPacketDetails;
    QDomNode tempNodeChild;
    QString PacketType;
    QString tempString;
    QString bLocal;
    QString bNoState;

    //array name
    QString FloorsSwitchSocketCfgFileStringName;
    QString FloorsSensorSocketCfgFileStringName;
    QString FloorsVariableSliderSocketCfgFileStringName;
    QString FloorsVariableSwitchSocketCfgFileStringName;

    // Create list nodes of - Every DEVICE
    listPacketDetails = tempNodeDevicePacket.childNodes();

    // Get the packet type
    PacketType = tempNodeDevicePacket.toElement().tagName();

    if(firstLoopFlag == 0)
    {
        FloorsSwitchSocketCfgFileString.clear();
        //Create switch array head
        if((houseFloor == MULTI_FLOOR_HOUSE) && (switchCount == 0))
        {
            FloorsSwitchSocketCfgFileStringName = houseName + "_" + "Multi_Floor_Device_Array";
            FloorsSwitchSocketCfgFileString = "var " + FloorsSwitchSocketCfgFileStringName + " = [";
            houseFloorsSwitchSocketCfgFileString += FloorsSwitchSocketCfgFileStringName;
        }
        else if((houseFloor == SINGLE_FLOOR_HOUSE) && (switchCount == 0))
        {
            FloorsSwitchSocketCfgFileStringName = houseName + "_" + "Single_Floor_Device_Array";
            FloorsSwitchSocketCfgFileString = "var " + FloorsSwitchSocketCfgFileStringName + " = [";
            houseFloorsSwitchSocketCfgFileString += FloorsSwitchSocketCfgFileStringName;
        }
        else
        {
            //Do nothing
        }

        // --> could be an error
        FloorsSensorSocketCfgFileString.clear();
        //Create sensor array head
        if((houseFloor == MULTI_FLOOR_HOUSE) && (sensorCount == 0))
        {
            FloorsSensorSocketCfgFileStringName = houseName + "_" + "Multi_Floor_Sensor_Device_Array";
            FloorsSensorSocketCfgFileString = "var " + FloorsSensorSocketCfgFileStringName + " = [";
            houseFloorsSensorSocketCfgFileString += FloorsSensorSocketCfgFileStringName;
        }
        else if((houseFloor == SINGLE_FLOOR_HOUSE) && (sensorCount == 0))
        {
            FloorsSensorSocketCfgFileStringName = houseName + "_" + "Single_Floor_Sensor_Device_Array";
            FloorsSensorSocketCfgFileString = "var " + FloorsSensorSocketCfgFileStringName + " = [";
            houseFloorsSensorSocketCfgFileString += FloorsSensorSocketCfgFileStringName;
        }
        else
        {
            //Do nothing
        }

        // --> could be an error
        FloorsVariableSliderSocketCfgFileString.clear();
        //Create variable slider array head
        if((houseFloor == MULTI_FLOOR_HOUSE) && (variableSliderCount == 0))
        {
            FloorsVariableSliderSocketCfgFileStringName = houseName + "_" + "Multi_Floor_Variable_Slider_Device_Array";
            FloorsVariableSliderSocketCfgFileString = "var " + FloorsVariableSliderSocketCfgFileStringName + " = [";
            houseFloorsVariableSliderSocketCfgFileString += FloorsVariableSliderSocketCfgFileStringName;
        }
        else if((houseFloor == SINGLE_FLOOR_HOUSE) && (variableSliderCount == 0))
        {
            FloorsVariableSliderSocketCfgFileStringName = houseName + "_" + "Single_Floor_Variable_Slider_Device_Array";
            FloorsVariableSliderSocketCfgFileString = "var " + FloorsVariableSliderSocketCfgFileStringName + " = [";
            houseFloorsVariableSliderSocketCfgFileString += FloorsVariableSliderSocketCfgFileStringName;
        }
        else
        {
            //Do nothing
        }


        // --> could be an error
        FloorsVariableSwitchSocketCfgFileString.clear();
        //Create variable Switch array head
        if((houseFloor == MULTI_FLOOR_HOUSE) && (variableSwitchCount == 0))
        {
            FloorsVariableSwitchSocketCfgFileStringName = houseName + "_" + "Multi_Floor_Variable_Switch_Device_Array";
            FloorsVariableSwitchSocketCfgFileString = "var " + FloorsVariableSwitchSocketCfgFileStringName + " = [";
            houseFloorsVariableSwitchSocketCfgFileString += FloorsVariableSwitchSocketCfgFileStringName;
        }
        else if((houseFloor == SINGLE_FLOOR_HOUSE) && (variableSwitchCount == 0))
        {
            FloorsVariableSwitchSocketCfgFileStringName = houseName + "_" + "Single_Floor_Variable_Switch_Device_Array";
            FloorsVariableSwitchSocketCfgFileString = "var " + FloorsVariableSwitchSocketCfgFileStringName + " = [";
            houseFloorsVariableSwitchSocketCfgFileString += FloorsVariableSwitchSocketCfgFileStringName;
        }
        else
        {
            //Do nothing
        }

        firstLoopFlag = 1u;
    }

    if((switchTotal == 0)&&(switchFlag == 0))
    {
        //Do not append -- ","
        FloorsSwitchSocketCfgFileString += "\n" ;
        FloorsSwitchSocketCfgFileString += "];" ;
        switchFlag = 1;
    }

    if((sensorTotal == 0)&&(sensorFlag == 0))
    {
        //Do not append -- ","
        FloorsSensorSocketCfgFileString += "\n" ;
        FloorsSensorSocketCfgFileString += "];" ;
        sensorFlag = 1;
    }

    if((variableSliderTotal == 0)&&(variableSliderFlag == 0))
    {
        //Do not append -- ","
        FloorsVariableSliderSocketCfgFileString += "\n" ;
        FloorsVariableSliderSocketCfgFileString += "];" ;
        variableSliderFlag = 1;
    }

    if((variableSwitchTotal == 0)&&(variableSwitchFlag == 0))
    {
        //Do not append -- ","
        FloorsVariableSwitchSocketCfgFileString += "\n" ;
        FloorsVariableSwitchSocketCfgFileString += "];" ;
        variableSwitchFlag = 1;
    }

    if(PacketType == PACKET_SWITCH_TEXT)
    {
        FloorsSwitchSocketCfgFileString += "\n"  "  { ";

        FloorsSwitchSocketCfgFileString += "floorName: '" + floorNameDevice + "', ";
        FloorsSwitchSocketCfgFileString += "roomName: '" + roomNameDevice + "', ";
        FloorsSwitchSocketCfgFileString += "deviceName: '" + deviceNameDevice + "', ";
        FloorsSwitchSocketCfgFileString += "\n";
        FloorsSwitchSocketCfgFileString += "    ";
        tempNodeChild = listPacketDetails.at(VSCP_PACKET_SWITCH_WEBSOCKET_CONFIGURE);

        //Websocket configuration
        FloorsSwitchSocketCfgFileString += "url: '" + tempNodeChild.toElement().attribute(SWITCH_URL) + "', ";
        FloorsSwitchSocketCfgFileString += "canvasName: '" + DeviceId + "', ";
        tempString = tempNodeChild.toElement().attribute(SWITCH_BLOCAL);
        if(tempString == "0")
        {
            bLocal  = "true";
        }
        else
        {
            bLocal  = "false";
        }
        FloorsSwitchSocketCfgFileString += "bLocal: '" + bLocal + "', ";
        FloorsSwitchSocketCfgFileString += "btnType: " + deviceImage + " , ";
        tempString = tempNodeChild.toElement().attribute(SWITCH_BNOSTATE);
        if(tempString == "0")
        {
            bNoState  = "true";
        }
        else
        {
            bNoState  = "false";
        }
        FloorsSwitchSocketCfgFileString += "bNoState: '" + bNoState + "', ";
        tempString =tempNodeChild.toElement().attribute(SWITCH_USERNAME);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "userName: '" + tempString + "', ";
        tempString =tempNodeChild.toElement().attribute(SWITCH_PASSWORD);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "password: '" + tempString + "', ";
        tempString =tempNodeChild.toElement().attribute(SWITCH_DOMAIN);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "domain: '"   + tempString + "', ";
        //Get the variables node from XML
        tempNodeChild = listPacketDetails.at(VSCP_PACKET_SWITCH_VARIABLE_CONFIGURE);
        tempString =tempNodeChild.toElement().attribute(VARIABLE_NAME);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "VariableName: '" + tempString + "' , ";
        FloorsSwitchSocketCfgFileString += "\n";
        FloorsSwitchSocketCfgFileString += "    ";
        //TX on event
        //Read switch tx on event
        tempNodeChild = listPacketDetails.at(VSCP_PACKET_SWITCH_TX_ON_EVENT);
        tempString =tempNodeChild.toElement().attribute(EVENT_CLASS);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "onTxEventvscpclass: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_TYPE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "onTxEventvscptype: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_DATA);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        else
        {
            tempString = "'" + tempString + "'";
        }
        FloorsSwitchSocketCfgFileString += "onTxEventdata: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_GUID);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        else
        {
            tempString = "'" + tempString + "'";
        }
        FloorsSwitchSocketCfgFileString += "onTxEventguid: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_INDEX);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "onTxEventindex: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_ZONE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "onTxEventzone: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_SUBZONE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "onTxEventsubzone: " + tempString + " , ";
        FloorsSwitchSocketCfgFileString += "\n";
        FloorsSwitchSocketCfgFileString += "    ";
        //TX off event
        //Read switch tx off event
        tempNodeChild = listPacketDetails.at(VSCP_PACKET_SWITCH_TX_OFF_EVENT);
        tempString =tempNodeChild.toElement().attribute(EVENT_CLASS);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "offTxEventvscpclass: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_TYPE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "offTxEventvscptype: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_DATA);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        else
        {
            tempString = "'" + tempString + "'";
        }
        FloorsSwitchSocketCfgFileString += "offTxEventdata: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_GUID);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        else
        {
            tempString = "'" + tempString + "'";
        }
        FloorsSwitchSocketCfgFileString += "offTxEventguid: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_INDEX);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "offTxEventindex: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_ZONE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "offTxEventzone: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_SUBZONE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "offTxEventsubzone: " + tempString + " , ";
        FloorsSwitchSocketCfgFileString += "\n";
        FloorsSwitchSocketCfgFileString += "    ";
        //RX on event
        //Read switch rx on event
        tempNodeChild = listPacketDetails.at(VSCP_PACKET_SWITCH_RX_ON_EVENT);
        tempString =tempNodeChild.toElement().attribute(EVENT_CLASS);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "onRxEventvscpclass: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_TYPE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "onRxEventvscptype: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_DATA);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        else
        {
            tempString = "'" + tempString + "'";
        }
        FloorsSwitchSocketCfgFileString += "onRxEventdata: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_GUID);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        else
        {
            tempString = "'" + tempString + "'";
        }
        FloorsSwitchSocketCfgFileString += "onRxEventguid: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_INDEX);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "onRxEventindex: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_ZONE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "onRxEventzone: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_SUBZONE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "onRxEventsubzone: " + tempString + " , ";
        FloorsSwitchSocketCfgFileString += "\n";
        FloorsSwitchSocketCfgFileString += "    ";
        //RX off event
        //Read switch rx off event
        tempNodeChild = listPacketDetails.at(VSCP_PACKET_SWITCH_RX_OFF_EVENT);
        tempString =tempNodeChild.toElement().attribute(EVENT_CLASS);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "offRxEventvscpclass: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_TYPE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "offRxEventvscptype: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_DATA);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        else
        {
            tempString = "'" + tempString + "'";
        }
        FloorsSwitchSocketCfgFileString += "offRxEventdata: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_GUID);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        else
        {
            tempString = "'" + tempString + "'";
        }
        FloorsSwitchSocketCfgFileString += "offRxEventguid: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_INDEX);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "offRxEventindex: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_ZONE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "offRxEventzone: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_SUBZONE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSwitchSocketCfgFileString += "offRxEventsubzone: " + tempString ;
        FloorsSwitchSocketCfgFileString += "\n";
        FloorsSwitchSocketCfgFileString += "  ";
        FloorsSwitchSocketCfgFileString += "}";

        //Increment the count
        switchCount++;

        if(switchCount < switchTotal)
        {
            FloorsSwitchSocketCfgFileString += "," ;
        }
        else
        {
            //Do not append -- ","
            FloorsSwitchSocketCfgFileString += "\n" ;
            FloorsSwitchSocketCfgFileString += "];" ;
        }

        FloorsSwitchSocketCfgFileString += "\n" ;

        //Get the variables node from XML
        tempNodeChild = listPacketDetails.at(VSCP_PACKET_SWITCH_VARIABLE_CONFIGURE);
        //Append value to variables & dm xml files
        prepareVariablesDmXmlFile(tempNodeChild,PacketType);

    }
    else if (PacketType == PACKET_SENSOR_TEXT)
    {
        //get sensor coding index
        //get Websocket configuration
        tempNodeChild = listPacketDetails.at(VSCP_PACKET_SENSOR_WEBSOCKET_CONFIGURE);
        codingIndexSensor=tempNodeChild.toElement().attribute(SENSOR_CODING_INDEX);
        if(codingIndexSensor == "")
        {
            codingIndexSensor ="0";
        }
        //Get the variables node from XML
        tempNodeChild = listPacketDetails.at(VSCP_PACKET_SENSOR_VARIABLE_CONFIGURE);
        //Append value to variables & dm xml files
        prepareVariablesDmXmlFile(tempNodeChild,PacketType);   // -------> todo

        FloorsSensorSocketCfgFileString += "\n"  "  { ";

        FloorsSensorSocketCfgFileString += "floorName: '" + floorNameDevice + "', ";
        FloorsSensorSocketCfgFileString += "roomName: '" + roomNameDevice + "', ";
        FloorsSensorSocketCfgFileString += "deviceName: '" + deviceNameDevice + "', ";
        FloorsSensorSocketCfgFileString += "\n";
        FloorsSensorSocketCfgFileString += "    ";

        tempNodeChild = listPacketDetails.at(VSCP_PACKET_SENSOR_WEBSOCKET_CONFIGURE);

        //Websocket configuration
        FloorsSensorSocketCfgFileString += "url: '" + tempNodeChild.toElement().attribute(SENSOR_URL) + "', ";
        FloorsSensorSocketCfgFileString += "id: '" + DeviceId + "', ";
        FloorsSensorSocketCfgFileString += "graphId: '" + VariableButtonOneId + "', ";
        FloorsSensorSocketCfgFileString += "graphUnitId: '" + VariableButtonTwoId + "', ";
        FloorsSensorSocketCfgFileString += "graphType: '" + DeviceLocalTxtId + "', ";
        tempString =tempNodeChild.toElement().attribute(SENSOR_CLASS);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        txEventClassSensor = tempString;
        FloorsSensorSocketCfgFileString += "vscpclass: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(SENSOR_TYPE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        txEventTypeSensor = tempString;
        FloorsSensorSocketCfgFileString += "vscptype: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(SENSOR_CODING_INDEX);
        if(tempString == "")
        {
            tempString ="undefined";
        }
         FloorsSensorSocketCfgFileString += "codingIndex: " + tempString + " , ";
         FloorsSensorSocketCfgFileString += "\n";
         FloorsSensorSocketCfgFileString += "    ";
        //sensor index
         if(sensorIndex == "")
         {
             sensorIndex = "undefined";
         }
         FloorsSensorSocketCfgFileString += "sensorIndex: " + sensorIndex + " , ";
        // sensor zone
         if(sensorZone == "")
         {
             sensorZone = "undefined";
         }
         FloorsSensorSocketCfgFileString += "sensorZone: " + sensorZone + " , ";
        // sensor subzone
         if(sensorSubzone == "")
         {
             sensorSubzone = "undefined";
         }
         FloorsSensorSocketCfgFileString += "sensorSubzone: " + sensorSubzone + " , ";
         FloorsSensorSocketCfgFileString += "\n";
         FloorsSensorSocketCfgFileString += "    ";
        tempString =tempNodeChild.toElement().attribute(SENSOR_DECIMALS);
        if(tempString == "")
        {
            tempString ="undefined";
        }
         FloorsSensorSocketCfgFileString += "decimals: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(SENSOR_FORMAT_STRING);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        else
        {
            tempString = "'" + tempString + "'" ;
        }
         FloorsSensorSocketCfgFileString += "formatstr: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(SENSOR_GUID);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        else
        {
            tempString = "'" + tempString + "'";
        }
         FloorsSensorSocketCfgFileString += "guid: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(SENSOR_CALLACK);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSensorSocketCfgFileString += "fncallback: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(SENSOR_USERNAME);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSensorSocketCfgFileString += "userName: '" + tempString + "', ";
        tempString =tempNodeChild.toElement().attribute(SENSOR_PASSWORD);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSensorSocketCfgFileString += "password: '" + tempString + "', ";
        tempString =tempNodeChild.toElement().attribute(SENSOR_DOMAIN);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsSensorSocketCfgFileString += "domain: '"   + tempString + "', ";


         //Get the variables node from XML
         tempNodeChild = listPacketDetails.at(VSCP_PACKET_SENSOR_VARIABLE_CONFIGURE);
         tempString =tempNodeChild.toElement().attribute(VARIABLE_NAME);
         if(tempString == "")
         {
             tempString ="undefined";
         }
         FloorsSensorSocketCfgFileString += "VariableName: '" + tempString + "'";

         FloorsSensorSocketCfgFileString += "\n";
         FloorsSensorSocketCfgFileString += "  ";
         FloorsSensorSocketCfgFileString += "}";

        //Increment the count
        sensorCount++;

        if(sensorCount < sensorTotal)
        {
            FloorsSensorSocketCfgFileString += "," ;
        }
        else
        {
            //Do not append -- ","
            FloorsSensorSocketCfgFileString += "\n" ;
            FloorsSensorSocketCfgFileString += "];" ;
        }

        FloorsSensorSocketCfgFileString += "\n" ;

/*
        //Get the variables node from XML
        tempNodeChild = listPacketDetails.at(VSCP_PACKET_SENSOR_VARIABLE_CONFIGURE);
        //Append value to variables & dm xml files
        prepareVariablesDmXmlFile(tempNodeChild,PacketType);
*/
    }
    else if (PacketType == PACKET_SLIDER_TEXT)
    {

        FloorsVariableSliderSocketCfgFileString += "\n"  "  { ";

        FloorsVariableSliderSocketCfgFileString += "floorName: '" + floorNameDevice + "', ";
        FloorsVariableSliderSocketCfgFileString += "roomName: '" + roomNameDevice + "', ";
        FloorsVariableSliderSocketCfgFileString += "deviceName: '" + deviceNameDevice + "', ";
        FloorsVariableSliderSocketCfgFileString += "\n";
        FloorsVariableSliderSocketCfgFileString += "    ";

        tempNodeChild = listPacketDetails.at(VSCP_PACKET_SLIDER_WEBSOCKET_CONFIGURE);

        //Websocket configuration
        FloorsVariableSliderSocketCfgFileString += "url: '" + tempNodeChild.toElement().attribute(SLIDER_URL) + "', ";
        FloorsVariableSliderSocketCfgFileString += "canvasName: '" + VariableButtonOneId + "', ";
        FloorsVariableSliderSocketCfgFileString += "canvasLocalTxtName: '" + DeviceLocalTxtId + "', ";
        FloorsVariableSliderSocketCfgFileString += "canvasRemoteTxtName: '" + DeviceId + "', ";
        FloorsVariableSliderSocketCfgFileString += "Max: " + tempNodeChild.toElement().attribute(SLIDER_MAX) + " , ";
        FloorsVariableSliderSocketCfgFileString += "Min: " + tempNodeChild.toElement().attribute(SLIDER_MIN) + " , ";
        tempString =tempNodeChild.toElement().attribute(SLIDER_USERNAME);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSliderSocketCfgFileString += "userName: '" + tempString + "', ";
        tempString =tempNodeChild.toElement().attribute(SLIDER_PASSWORD);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSliderSocketCfgFileString += "password: '" + tempString + "', ";
        tempString =tempNodeChild.toElement().attribute(SLIDER_DOMAIN);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSliderSocketCfgFileString += "domain: '"   + tempString + "', ";
        //Get the variables node from XML
        tempNodeChild = listPacketDetails.at(VSCP_PACKET_SLIDER_VARIABLE_CONFIGURE);
        tempString =tempNodeChild.toElement().attribute(VARIABLE_NAME);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSliderSocketCfgFileString += "VariableName: '" + tempString + "', ";

        FloorsVariableSliderSocketCfgFileString += "\n";
        FloorsVariableSliderSocketCfgFileString += "    ";

        //TX event
        //Read switch tx on event
        tempNodeChild = listPacketDetails.at(VSCP_PACKET_SLIDER_TX_EVENT);
        tempString =tempNodeChild.toElement().attribute(EVENT_CLASS);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        txEventClassSlider = tempString;
        FloorsVariableSliderSocketCfgFileString += "TxEventvscpclass: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_TYPE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        txEventTypeSlider = tempString;
        FloorsVariableSliderSocketCfgFileString += "TxEventvscptype: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_DATA);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        else
        {
            tempString = "'" + tempString + "'";
        }
        FloorsVariableSliderSocketCfgFileString += "TxEventdata: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_GUID);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        else
        {
            tempString = "'" + tempString + "'";
        }
        FloorsVariableSliderSocketCfgFileString += "TxEventguid: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_INDEX);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSliderSocketCfgFileString += "TxEventindex: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_ZONE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSliderSocketCfgFileString += "TxEventzone: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_SUBZONE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSliderSocketCfgFileString += "TxEventsubzone: " + tempString + " , ";
        FloorsVariableSliderSocketCfgFileString += "\n";
        FloorsVariableSliderSocketCfgFileString += "    ";

        //RX event
        //Read switch Rx on event
        tempNodeChild = listPacketDetails.at(VSCP_PACKET_SLIDER_RX_EVENT);
        tempString =tempNodeChild.toElement().attribute(EVENT_CLASS);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        rxClassTxt = tempString;
        FloorsVariableSliderSocketCfgFileString += "RxEventvscpclass: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_TYPE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        rxTypeTxt = tempString;
        FloorsVariableSliderSocketCfgFileString += "RxEventvscptype: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_DATA);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        else
        {
            tempString = "'" + tempString + "'";
        }
        FloorsVariableSliderSocketCfgFileString += "RxEventdata: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_GUID);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        else
        {
            tempString = "'" + tempString + "'";
        }
        FloorsVariableSliderSocketCfgFileString += "RxEventguid: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_INDEX);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSliderSocketCfgFileString += "RxEventindex: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_ZONE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSliderSocketCfgFileString += "RxEventzone: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_SUBZONE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSliderSocketCfgFileString += "RxEventsubzone: "  + tempString ;

        FloorsVariableSliderSocketCfgFileString += "\n";
        FloorsVariableSliderSocketCfgFileString += "  ";
        FloorsVariableSliderSocketCfgFileString += "}";

       //Increment the count
       variableSliderCount++;

       if(variableSliderCount < variableSliderTotal)
       {
           FloorsVariableSliderSocketCfgFileString += "," ;
       }
       else
       {
           //Do not append -- ","
           FloorsVariableSliderSocketCfgFileString += "\n" ;
           FloorsVariableSliderSocketCfgFileString += "];" ;
       }

       FloorsVariableSliderSocketCfgFileString += "\n" ;

       //Get the variables node from XML
       tempNodeChild = listPacketDetails.at(VSCP_PACKET_SLIDER_VARIABLE_CONFIGURE);
       //Append value to variables & dm xml files
       prepareVariablesDmXmlFile(tempNodeChild,PacketType);

       //Reinitialize the variables
       rxClassTxt = "";
       rxTypeTxt = "";

    }
    else if (PacketType == PACKET_VARIABLE_SWITCH_TEXT)
    {

        FloorsVariableSwitchSocketCfgFileString += "\n"  "  { ";

        FloorsVariableSwitchSocketCfgFileString += "floorName: '" + floorNameDevice + "', ";
        FloorsVariableSwitchSocketCfgFileString += "roomName: '" + roomNameDevice + "', ";
        FloorsVariableSwitchSocketCfgFileString += "deviceName: '" + deviceNameDevice + "', ";
        FloorsVariableSwitchSocketCfgFileString += "\n";
        FloorsVariableSwitchSocketCfgFileString += "    ";

        tempNodeChild = listPacketDetails.at(VSCP_VARIABLE_SWITCH_WEBSOCKET_CONFIGURE);

        //Websocket configuration
        FloorsVariableSwitchSocketCfgFileString += "url: '" + tempNodeChild.toElement().attribute(VARIABLE_SWITCH_URL) + "', ";
        FloorsVariableSwitchSocketCfgFileString += "canvasIncName: '" + VariableButtonOneId + "', ";
        FloorsVariableSwitchSocketCfgFileString += "canvasDecName: '" + VariableButtonTwoId + "', ";
        FloorsVariableSwitchSocketCfgFileString += "canvasLocalTxtName: '" + DeviceLocalTxtId + "', ";
        FloorsVariableSwitchSocketCfgFileString += "canvasRemoteTxtName: '" + DeviceId + "', ";
        FloorsVariableSwitchSocketCfgFileString += "Max: " + tempNodeChild.toElement().attribute(VARIABLE_SWITCH_MAX) + " , ";
        FloorsVariableSwitchSocketCfgFileString += "Min: " + tempNodeChild.toElement().attribute(VARIABLE_SWITCH_MIN) + " , ";
        tempString =tempNodeChild.toElement().attribute(VARIABLE_USERNAME);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSwitchSocketCfgFileString += "userName: '" + tempString + "', ";
        tempString =tempNodeChild.toElement().attribute(VARIABLE_PASSWORD);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSwitchSocketCfgFileString += "password: '" + tempString + "', ";
        tempString =tempNodeChild.toElement().attribute(VARIABLE_DOMAIN);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSwitchSocketCfgFileString += "domain: '"   + tempString + "', ";
        //Get the variables node from XML
        tempNodeChild = listPacketDetails.at(VSCP_PACKET_SLIDER_VARIABLE_CONFIGURE);
        tempString =tempNodeChild.toElement().attribute(VARIABLE_NAME);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSwitchSocketCfgFileString += "VariableName: '" + tempString + "', ";

        FloorsVariableSwitchSocketCfgFileString += "\n";
        FloorsVariableSwitchSocketCfgFileString += "    ";

        //TX event
        //Read switch tx on event
        tempNodeChild = listPacketDetails.at(VSCP_VARIABLE_SWITCH_TX_EVENT);
        tempString =tempNodeChild.toElement().attribute(EVENT_CLASS);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSwitchSocketCfgFileString += "TxEventvscpclass: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_TYPE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSwitchSocketCfgFileString += "TxEventvscptype: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_DATA);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        else
        {
            tempString = "'" + tempString + "'";
        }
        FloorsVariableSwitchSocketCfgFileString += "TxEventdata: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_GUID);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        else
        {
            tempString = "'" + tempString + "'";
        }
        FloorsVariableSwitchSocketCfgFileString += "TxEventguid: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_ZONE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSwitchSocketCfgFileString += "TxEventzone: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_SUBZONE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSwitchSocketCfgFileString += "TxEventsubzone: " + tempString + " , ";
        FloorsVariableSwitchSocketCfgFileString += "\n";
        FloorsVariableSwitchSocketCfgFileString += "    ";

        //RX event
        //Read switch Rx on event
        tempNodeChild = listPacketDetails.at(VSCP_PACKET_SLIDER_RX_EVENT);
        tempString =tempNodeChild.toElement().attribute(EVENT_CLASS);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        rxClassTxt = tempString;
        FloorsVariableSwitchSocketCfgFileString += "RxEventvscpclass: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_TYPE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        rxTypeTxt = tempString;
        FloorsVariableSwitchSocketCfgFileString += "RxEventvscptype: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_DATA);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        else
        {
            tempString = "'" + tempString + "'";
        }
        FloorsVariableSwitchSocketCfgFileString += "RxEventdata: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_GUID);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        else
        {
            tempString = "'" + tempString + "'";
        }
        FloorsVariableSwitchSocketCfgFileString += "RxEventguid: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_ZONE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSwitchSocketCfgFileString += "RxEventzone: " + tempString + " , ";
        tempString =tempNodeChild.toElement().attribute(EVENT_SUBZONE);
        if(tempString == "")
        {
            tempString ="undefined";
        }
        FloorsVariableSwitchSocketCfgFileString += "RxEventsubzone: "  + tempString ;

        FloorsVariableSwitchSocketCfgFileString += "\n";
        FloorsVariableSwitchSocketCfgFileString += "  ";
        FloorsVariableSwitchSocketCfgFileString += "}";

       //Increment the count
       variableSwitchCount++;

       if(variableSwitchCount < variableSwitchTotal)
       {
           FloorsVariableSwitchSocketCfgFileString += "," ;
       }
       else
       {
           //Do not append -- ","
           FloorsVariableSwitchSocketCfgFileString += "\n" ;
           FloorsVariableSwitchSocketCfgFileString += "];" ;
       }

       FloorsVariableSwitchSocketCfgFileString += "\n" ;

       //Get the variables node from XML
       tempNodeChild = listPacketDetails.at(VSCP_VARIABLE_SWITCH_VARIABLE_CONFIGURE);
       //Append value to variables & dm xml files
       prepareVariablesDmXmlFile(tempNodeChild,PacketType);

    }
    else
    {
        // Do nothing
    }


}

// Create the General header for HTML
void GenerateApp::createHtmlHead()
{
    //Extract absolute file name form - xml file path
    QFileInfo fileInfo(xmlFileNameRef);
    htmlFileDirectoryPath = fileInfo.absolutePath();
    htmlFilePath = htmlFileDirectoryPath + "/MyHome.html";

    /*msgBox 	= new QMessageBox();
    msgBox->setText(htmlFilePath.replace("/", "\\"));
    msgBox->setWindowFlags(Qt::WindowStaysOnTopHint);
    msgBox->show();*/

    //set the name of the file
    htmlFile.setFileName(htmlFilePath.replace("/", "\\"));

    // open read & write mode
    if (!htmlFile.open(QIODevice::ReadWrite|QIODevice::Truncate|QIODevice::Text))
    {
        // Fail to open file Message
        //QMessageBox::information(this, "uiMagician", "Fail to Open file");
        return;
        //return FAIL_TO_OPEN_FILE;
    }

    // Assign file to the stream
    htmlStream.setDevice(&htmlFile);

    // Make the root element
    htmlRoot = htmlDomDocument.createElement("html");
    htmlRoot.setAttribute("style","height: 100%;");

    // Add root to the document
    htmlDomDocument.appendChild(htmlRoot);

    nodeName = "head";
    NodeElement  = htmlDomDocument.createElement(nodeName);
       //Create meta node
       nodeChildName = "meta";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       NodeElementChild.setAttribute("content","text/html; charset=ISO-8859-1");
       NodeElementChild.setAttribute("http-equiv","content-type");
       NodeElement.appendChild(NodeElementChild);
       //Create Title
       nodeChildName = "title";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       stringTxtNode = "VSCP My House Ui ..";
       textNode = htmlDomDocument.createTextNode(stringTxtNode);
       NodeElementChild.appendChild(textNode);
       NodeElement.appendChild(NodeElementChild);
       //Create link node
       nodeChildName = "link";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       NodeElementChild.setAttribute("rel","stylesheet");
       NodeElementChild.setAttribute("type","text/css");
       if(houseFloor == MULTI_FLOOR_HOUSE)
       {
           stringAttributeTxt = "../css/multiFloorStyle.css";
       }
       else
       {
           stringAttributeTxt = "../css/singleFloorStyle.css";
       }
       NodeElementChild.setAttribute("href",stringAttributeTxt);
       NodeElement.appendChild(NodeElementChild);
       //Create link node
       nodeChildName = "link";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       NodeElementChild.setAttribute("rel","stylesheet");
       NodeElementChild.setAttribute("type","text/css");
       stringAttributeTxt = "../css/info.css";
       NodeElementChild.setAttribute("href",stringAttributeTxt);
       NodeElement.appendChild(NodeElementChild);
       //Create link node
       nodeChildName = "link";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       NodeElementChild.setAttribute("rel","stylesheet");
       NodeElementChild.setAttribute("type","text/css");
       stringAttributeTxt = "../css/epoch.min.css";
       NodeElementChild.setAttribute("href",stringAttributeTxt);
       NodeElement.appendChild(NodeElementChild);
       if(xmlType == MULTI_HOUSE)
       {
           //Create link node
           nodeChildName = "link";
           NodeElementChild = htmlDomDocument.createElement(nodeChildName);
           NodeElementChild.setAttribute("rel","stylesheet");
           NodeElementChild.setAttribute("type","text/css");
           stringAttributeTxt = "../css/side_menu.css";
           NodeElementChild.setAttribute("href",stringAttributeTxt);
           NodeElement.appendChild(NodeElementChild);
       }
       else
       {
           //Do nothing
       }
       //Create setting jquery script node
       nodeChildName = "script";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       NodeElementChild.setAttribute("type","text/javascript");
       NodeElementChild.setAttribute("src","../lib/jquery.min.js");
       stringTxtNode = "";
       textNode = htmlDomDocument.createTextNode(stringTxtNode);
       NodeElementChild.appendChild(textNode);
       NodeElement.appendChild(NodeElementChild);
       //Create setting jquery script node
       nodeChildName = "script";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       NodeElementChild.setAttribute("type","text/javascript");
       NodeElementChild.setAttribute("src","../lib/d3.min.js");
       stringTxtNode = "";
       textNode = htmlDomDocument.createTextNode(stringTxtNode);
       NodeElementChild.appendChild(textNode);
       NodeElement.appendChild(NodeElementChild);
       //Create setting jquery script node
       nodeChildName = "script";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       NodeElementChild.setAttribute("type","text/javascript");
       NodeElementChild.setAttribute("src","../lib/epoch.min.js");
       stringTxtNode = "";
       textNode = htmlDomDocument.createTextNode(stringTxtNode);
       NodeElementChild.appendChild(textNode);
       NodeElement.appendChild(NodeElementChild);
       //Create graphics script node
       nodeChildName = "script";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       NodeElementChild.setAttribute("type","text/javascript");
       NodeElementChild.setAttribute("src","../lib/wz_jsgraphics.js");
       stringTxtNode = "";
       textNode = htmlDomDocument.createTextNode(stringTxtNode);
       NodeElementChild.appendChild(textNode);
       NodeElement.appendChild(NodeElementChild);
       //Create vscpws script node
       nodeChildName = "script";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       NodeElementChild.setAttribute("type","text/javascript");
       NodeElementChild.setAttribute("src","../lib/md5.js");
       stringTxtNode = "";
       textNode = htmlDomDocument.createTextNode(stringTxtNode);
       NodeElementChild.appendChild(textNode);
       NodeElement.appendChild(NodeElementChild);
       //Create vscpws script node
       nodeChildName = "script";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       NodeElementChild.setAttribute("type","text/javascript");
       NodeElementChild.setAttribute("src","../lib/infoInit.js");
       stringTxtNode = "";
       textNode = htmlDomDocument.createTextNode(stringTxtNode);
       NodeElementChild.appendChild(textNode);
       NodeElement.appendChild(NodeElementChild);
       if(xmlType == MULTI_HOUSE)
       {
           //Create vscpws script node
           nodeChildName = "script";
           NodeElementChild = htmlDomDocument.createElement(nodeChildName);
           NodeElementChild.setAttribute("type","text/javascript");
           if(houseFloor == SINGLE_FLOOR_HOUSE)
           {
               NodeElementChild.setAttribute("src","../lib/side_menu_house_single.js");
           }
           else
           {
               NodeElementChild.setAttribute("src","../lib/side_menu_house.js");
           }
           stringTxtNode = "";
           textNode = htmlDomDocument.createTextNode(stringTxtNode);
           NodeElementChild.appendChild(textNode);
           NodeElement.appendChild(NodeElementChild);
       }
       else
       {
           //Do nothing
       }
       //Create vscpws script node
       nodeChildName = "script";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       NodeElementChild.setAttribute("type","text/javascript");
       NodeElementChild.setAttribute("src","../lib/vscpwslib.js");
       stringTxtNode = "";
       textNode = htmlDomDocument.createTextNode(stringTxtNode);
       NodeElementChild.appendChild(textNode);
       NodeElement.appendChild(NodeElementChild);
       //Create vscpws script node
       nodeChildName = "script";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       NodeElementChild.setAttribute("type","text/javascript");
       NodeElementChild.setAttribute("src","../lib/vscpStateButton_mod.js");
       stringTxtNode = "";
       textNode = htmlDomDocument.createTextNode(stringTxtNode);
       NodeElementChild.appendChild(textNode);
       NodeElement.appendChild(NodeElementChild);
       //Create vscpws script node
       nodeChildName = "script";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       NodeElementChild.setAttribute("type","text/javascript");
       NodeElementChild.setAttribute("src","../lib/vscpSimpleText_mod.js");
       stringTxtNode = "";
       textNode = htmlDomDocument.createTextNode(stringTxtNode);
       NodeElementChild.appendChild(textNode);
       NodeElement.appendChild(NodeElementChild);
       //Create vscpws script node
       nodeChildName = "script";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       NodeElementChild.setAttribute("type","text/javascript");
       NodeElementChild.setAttribute("src","../lib/vscpslider.js");
       stringTxtNode = "";
       textNode = htmlDomDocument.createTextNode(stringTxtNode);
       NodeElementChild.appendChild(textNode);
       NodeElement.appendChild(NodeElementChild);
       //Create vscpws script node
       nodeChildName = "script";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       NodeElementChild.setAttribute("type","text/javascript");
       NodeElementChild.setAttribute("src","../lib/vscpVariableButton.js");
       stringTxtNode = "";
       textNode = htmlDomDocument.createTextNode(stringTxtNode);
       NodeElementChild.appendChild(textNode);
       NodeElement.appendChild(NodeElementChild);
       //Create floor type script node
       nodeChildName = "script";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       NodeElementChild.setAttribute("type","text/javascript");
       if(houseFloor == MULTI_FLOOR_HOUSE)
       {
           stringAttributeTxt = "../lib/multiFloorsSocketCfg.js";
       }
       else
       {
           stringAttributeTxt = "../lib/singleFloorsSocketCfg.js";
       }
       NodeElementChild.setAttribute("src",stringAttributeTxt);
       stringTxtNode = "";
       textNode = htmlDomDocument.createTextNode(stringTxtNode);
       NodeElementChild.appendChild(textNode);
       NodeElement.appendChild(NodeElementChild);
       //Create floor type script node
       nodeChildName = "script";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       NodeElementChild.setAttribute("type","text/javascript");
       if(houseFloor == MULTI_FLOOR_HOUSE)
       {
           stringAttributeTxt = "../lib/multiFloorCfg.js";
       }
       else
       {
           stringAttributeTxt = "../lib/singleFloorCfg.js";
       }
       NodeElementChild.setAttribute("src",stringAttributeTxt);
       stringTxtNode = "";
       textNode = htmlDomDocument.createTextNode(stringTxtNode);
       NodeElementChild.appendChild(textNode);
       NodeElement.appendChild(NodeElementChild);
       //Create floor type script node
       nodeChildName = "script";
       NodeElementChild = htmlDomDocument.createElement(nodeChildName);
       NodeElementChild.setAttribute("type","text/javascript");
       if(houseFloor == MULTI_FLOOR_HOUSE)
       {
           stringAttributeTxt = "../lib/multiFloorScript.js";
       }
       else
       {
           stringAttributeTxt = "../lib/singleFloorScript.js";
       }
       NodeElementChild.setAttribute("src",stringAttributeTxt);
       stringTxtNode = "";
       textNode = htmlDomDocument.createTextNode(stringTxtNode);
       NodeElementChild.appendChild(textNode);
       NodeElement.appendChild(NodeElementChild);
    htmlRoot.appendChild(NodeElement);

}


// Create the floor DIV scrollableCenter
void GenerateApp::createFloorDivScrollableCenter(QDomElement &NodeElementMultiFloorDivScrollableCenter)
{
    QString scrollableCenterAreaWidgetArray;
    //QString scrollableMenuTxtArray;
    QString infoVariableArray;
    QString infoVariableString;
    QString infoClassArray;
    //QString infoClassString;

    QDomElement NodeElementTemp;
    QDomElement NodeElementChildTemp;
    QDomElement NodeElementSpan;
    QDomElement NodeElementHr;
    QString nodeNameTemp;
    QString nodeChildNameTemp;
    QString floorNameArea;

    T_packetFloorNodes floorNodes;

    QString floorName;
    QDomNodeList listRooms;

    QString deviceName;
    QString deviceInfo;
    QString deviceNameNonFormatted;
    QString deviceNameNonFormattedRemote;
    QDomNodeList listDeviceDetails;

    QString deviceType;
    QString deviceSubType;
    QString deviceImage;
    QString deviceImageSrc;
    uint16_t deviceImageNumber;    

    QString sliderMaxValue;
    QString sliderMinValue;

    QString sensorImageSrc;
    QString switchOnImageSrc;
    QString switchOffImageSrc;

    QString sliderImageSrc;

    QString switchButtonIncImageSrc;
    QString switchButtonDownImageSrc;

    QString nodeDataTextRoom;
    QDomNode tempNodeChild;
    QDomNode tempNodeSubChild;
    QDomNodeList listChild;

    QDomNodeList listDevices;

    QString textArea;
    QString textArea_main;
    QString TextDeviceImageId;
    QString TextDevicetxtId;
    QString TextDeviceLocalTxtId;
    QString TextImageOneId;
    QString TextImageTwoId;

    //QString sensorRemoteText;
    uint8_t index = 0u;

    bool sensorGraphCreate = 0;

    // house name
    QString houseName;

    //Central widget array of array
    QString scrollableCenterAreaWidgetArrayName;
    QString houseCenterAreaWidgetArray;

    nodeName = "div";
    NodeElementMultiFloorDivScrollableCenter  = htmlDomDocument.createElement(nodeName);
    NodeElementMultiFloorDivScrollableCenter.setAttribute("id","center");
    NodeElementMultiFloorDivScrollableCenter.setAttribute("class","scrollableCenter");

    infoVariableArray.clear();
    infoVariableArray =  "var infoVariableArray = [";
    infoVariableArray += "\n";

    infoVariableString.clear();


    infoClassArray.clear();
    infoClassArray =  "var infoClass = [";
    infoClassArray += "\n";

    //infoClassString.clear();

    //Central widget array of array
    houseCenterAreaWidgetArray.clear();
    houseCenterAreaWidgetArray =  "var house_central_Area_widgets_id = [";
    houseCenterAreaWidgetArray += "\n";

    //Create switch array head
    if(houseFloor == MULTI_FLOOR_HOUSE)
    {
        houseFloorsSwitchSocketCfgFileString += "\n";
        houseFloorsSwitchSocketCfgFileString = "var Multi_Floor_Device_Array = [";
        houseFloorsSwitchSocketCfgFileString += "\n";
        houseFloorsSensorSocketCfgFileString = "var Multi_Floor_Sensor_Device_Array = [";
        houseFloorsSensorSocketCfgFileString += "\n";
        houseFloorsVariableSliderSocketCfgFileString = "var Multi_Floor_Variable_Slider_Device_Array = [";
        houseFloorsVariableSliderSocketCfgFileString += "\n";
        houseFloorsVariableSwitchSocketCfgFileString = "var Multi_Floor_Variable_Switch_Device_Array = [";
        houseFloorsVariableSwitchSocketCfgFileString += "\n";
    }
    else if(houseFloor == SINGLE_FLOOR_HOUSE)
    {
        houseFloorsSwitchSocketCfgFileString += "\n";
        houseFloorsSwitchSocketCfgFileString = "var Single_Floor_Device_Array = [";
        houseFloorsSwitchSocketCfgFileString += "\n";
        houseFloorsSensorSocketCfgFileString = "var Single_Floor_Sensor_Device_Array = [";
        houseFloorsSensorSocketCfgFileString += "\n";
        houseFloorsVariableSliderSocketCfgFileString = "var Single_Floor_Variable_Slider_Device_Array = [";
        houseFloorsVariableSliderSocketCfgFileString += "\n";
        houseFloorsVariableSwitchSocketCfgFileString = "var Single_Floor_Variable_Switch_Device_Array = [";
        houseFloorsVariableSwitchSocketCfgFileString += "\n";

    }
    else
    {
        //Do nothing
    }

    // Itterate through houses
    for (int p = 0; p < houseNodesList.size(); ++p)
    {
        houseName = houseNodesList.at(p).houseName;

        //QMessageBox::information(this,"house name",houseName);

        scrollableCenterAreaWidgetArray.clear();
        scrollableCenterAreaWidgetArray = "var " + houseName + "_" + "central_Area_widgets_id = [";
        scrollableCenterAreaWidgetArrayName = houseName + "_" + "central_Area_widgets_id";
        scrollableCenterAreaWidgetArray += "\n";

        houseCenterAreaWidgetArray += scrollableCenterAreaWidgetArrayName;


        FloorsSwitchSocketCfgFileString.clear();
        FloorsVariableSliderSocketCfgFileString.clear();
        FloorsVariableSwitchSocketCfgFileString.clear();
        FloorsSensorSocketCfgFileString.clear();

        if((p+1) <  houseNodesList.size())
        {
            houseCenterAreaWidgetArray += ",";
            //scrollableHrArray += ",";
        }


        /*QMessageBox::information(this, "uiMagician", QString::number(sensorTotal) +
                                 QString::number(switchTotal)+
                                 QString::number(variableSliderTotal)+
                                 QString::number(variableSwitchTotal)
                                 );*/

        //reInitialise global variables
        reInitializeGlobalVariables();

        //Get the Total number of switch & sensors
        //get floor name in list
        //for (int i = 0; i < floorNodesList.size(); ++i)
        for (int i = 0; i < houseNodesList.at(p).floorNodeList.size(); ++i)
        {
            //floorNodes = floorNodesList.at(i);
            floorNodes = houseNodesList.at(p).floorNodeList.at(i);

            //Load root nodes
            listRooms = floorNodes.floorRooms.childNodes();

            //get floor name in list
            // calculate device total
            for (int j = 0; j < listRooms.size(); ++j)
            {
                //read the child node from room list
                tempNodeChild = listRooms.at(j);

                // Create list of child nodes of - Every room
                listDevices = tempNodeChild.childNodes();

                for (int k = DEVICE_INDEX; k < listDevices.size(); ++k)
                {
                    //read the Device child node from device list
                    tempNodeChild = listDevices.at(k);
                    // Create list nodes of - Every DEVICE
                    listDeviceDetails = tempNodeChild.childNodes();

                    //Get device type node
                    tempNodeChild = listDeviceDetails.at(DEVICE_TYPE_INDEX);
                    if (!tempNodeChild.isNull())
                    {
                        deviceType = tempNodeChild.toElement().text();
                    }
                    else
                    {
                        deviceType = "";
                    }

                    //Get device sub type node
                    tempNodeChild = listDeviceDetails.at(DEVICE_SUB_TYPE_INDEX);
                    if (!tempNodeChild.isNull())
                    {
                        deviceSubType = tempNodeChild.toElement().text();
                    }
                    else
                    {
                        deviceSubType = "";
                    }

                    // If device type is sensor
                    if(deviceType == DEVICE_SENSOR)
                    {
                        sensorTotal++;

                        //create sensor graph
                        sensorGraphCreate = 1;
                    }
                    else if (deviceSubType == SWITCH_SUB_TYPE_ONE)
                    {
                        switchTotal++;
                    }
                    else if (deviceSubType == SWITCH_SUB_TYPE_TWO)
                    {
                        variableSliderTotal++;
                    }
                    else if (deviceSubType == SWITCH_SUB_TYPE_THREE)
                    {
                        variableSwitchTotal++;
                    }
                    else
                    {
                        //Do nothing
                    }

                }
            }
        }

        /*QMessageBox::information(this, "uiMagician", QString::number(sensorTotal) +
                                 QString::number(switchTotal)+
                                 QString::number(variableSliderTotal)+
                                 QString::number(variableSwitchTotal)
                                 );*/

        /*QMessageBox::information(this, "size", QString::number(houseNodesList.at(p).floorNodeList.size())
                                 );*/

        //get floor name in list
        //for (int i = 0; i < floorNodesList.size(); ++i)
        for (int i = 0; i < houseNodesList.at(p).floorNodeList.size(); ++i)
        {

            //floorNodes = floorNodesList.at(i);
            floorNodes = houseNodesList.at(p).floorNodeList.at(i);;

            floorName = floorNodes.floorName;
            floorName.replace(" ", "");
            floorName.remove(QRegExp("[^a-zA-Z\\d\\s]"));

            //QMessageBox::information(this, "size", floorName );
            floorNameArea = houseName + "_" + floorName + "_Floor_Area";

            //prepare global floor name
            floorNameDevice = floorName;

            //Load root nodes
            listRooms = floorNodes.floorRooms.childNodes();

            //get floor name in list
            for (int j = 0; j < listRooms.size(); ++j)
            {
                //read the child node from room list
                tempNodeChild = listRooms.at(j);

                // Create list of child nodes of - Every room
                listDevices = tempNodeChild.childNodes();

                //Read Room name from node
                tempNodeChild = listDevices.at(ROOM_NAME_INDEX);
                if (!tempNodeChild.isNull())
                {
                    nodeDataTextRoom = tempNodeChild.toElement().text();
                }
                else
                {
                    nodeDataTextRoom = "";
                }

                //Edit room name
                nodeDataTextRoom.replace(" ", "");
                nodeDataTextRoom.remove(QRegExp("[^a-zA-Z\\d\\s]"));

                //prepare global room name
                roomNameDevice = nodeDataTextRoom;

                // Area name ID
                textArea_main = floorNameArea + "_" + nodeDataTextRoom;

                // k = 0 : RoomName
                // k = 1 : FloorName
                // k = 2 : HouseName
                // k = 3 : Devices starts from here
                // itterate every device
                for (int k = DEVICE_INDEX; k < listDevices.size(); ++k)
                {

                    //read the Device child node from device list
                    tempNodeChild = listDevices.at(k);
                    // Create list nodes of - Every DEVICE
                    listDeviceDetails = tempNodeChild.childNodes();

                    //Get device name node
                    tempNodeChild = listDeviceDetails.at(DEVICE_INFO_INDEX);
                    if (!tempNodeChild.isNull())
                    {
                        deviceInfo = tempNodeChild.toElement().text();
                    }
                    else
                    {
                        deviceInfo = "";
                    }

                    // Area name ID
                    //textArea = floorNameArea + "_" + nodeDataTextRoom;
                    if(deviceInfo == DEVICE_INFO_TYPE_ONE)
                    {

                        if(houseFloor == MULTI_FLOOR_HOUSE)
                        {
                            textArea = textArea_main + " group_Lights_" + houseName;
                            textArea += " group_Lights_" + houseName + "_Floor_" + floorName;
                        }
                        else
                        {
                            textArea = textArea_main + " group_Lights_" + houseName;
                        }
                    }
                    else if (deviceInfo == DEVICE_INFO_TYPE_TWO)
                    {                        
                        if(houseFloor == MULTI_FLOOR_HOUSE)
                        {
                            textArea = textArea_main + " group_Accessories_" + houseName;
                            textArea += " group_Accessories_" + houseName + "_Floor_" + floorName;
                        }
                        else
                        {
                            textArea = textArea_main + " group_Accessories_" + houseName;
                        }
                    }
                    else if (deviceInfo == DEVICE_INFO_TYPE_THREE)
                    {                        
                        if(houseFloor == MULTI_FLOOR_HOUSE)
                        {
                            textArea = textArea_main + " group_Blinds_Windows_" + houseName;
                            textArea += " group_Blinds_Windows_" + houseName + "_Floor_" + floorName;
                        }
                        else
                        {
                            textArea = textArea_main + " group_Blinds_Windows_" + houseName;
                        }
                    }
                    else if (deviceInfo == DEVICE_INFO_TYPE_FOUR)
                    {                        
                        if(houseFloor == MULTI_FLOOR_HOUSE)
                        {
                            textArea = textArea_main + " group_Sensors_" + houseName;
                            textArea += " group_Sensors_" + houseName + "_Floor_" + floorName;
                        }
                        else
                        {
                            textArea = textArea_main + " group_Sensors_" + houseName;
                        }
                    }
                    else if (deviceInfo == DEVICE_INFO_TYPE_FIVE)
                    {                        
                        if(houseFloor == MULTI_FLOOR_HOUSE)
                        {
                            textArea = textArea_main + " group_Temperature_control_" + houseName;
                            textArea += " group_Temperature_control_" + houseName + "_Floor_" + floorName;
                        }
                        else
                        {
                            textArea = textArea_main + " group_Temperature_control_" + houseName;
                        }
                    }
                    else
                    {

                    }
                    // create Device node
                    nodeNameTemp = "div";
                    NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);
                    textArea = houseName + "_group_class " + textArea;
                    NodeElementTemp.setAttribute("class",textArea);

                    //Get device name node
                    tempNodeChild = listDeviceDetails.at(DEVICE_NAME_INDEX);
                    if (!tempNodeChild.isNull())
                    {
                        deviceName = tempNodeChild.toElement().text();
                    }
                    else
                    {
                        deviceName = "";
                    }

                    //prepare global device name
                    deviceNameDevice = deviceName;

                    deviceNameNonFormatted = deviceName;
                    //Edit device name
                    deviceName.replace(" ", "");
                    deviceName.remove(QRegExp("[^a-zA-Z\\d\\s]"));

                    //Get device type node
                    tempNodeChild = listDeviceDetails.at(DEVICE_TYPE_INDEX);
                    if (!tempNodeChild.isNull())
                    {
                        deviceType = tempNodeChild.toElement().text();
                    }
                    else
                    {
                        deviceType = "";
                    }

                    //Get device type node
                    tempNodeChild = listDeviceDetails.at(DEVICE_SUB_TYPE_INDEX);
                    if (!tempNodeChild.isNull())
                    {
                        deviceSubType = tempNodeChild.toElement().text();
                    }
                    else
                    {
                        deviceSubType = "";
                    }

                    if(deviceSubType == SWITCH_SUB_TYPE_TWO)
                    {
                        // get the slider Websocket node
                        tempNodeChild = listDeviceDetails.at(DEVICE_PACKET_INDEX).childNodes().at(VSCP_PACKET_SLIDER_WEBSOCKET_CONFIGURE);
                        // get the slider min
                        sliderMinValue =tempNodeChild.toElement().attribute(SLIDER_MIN);
                        if(sliderMinValue == "")
                        {
                            sliderMinValue ="0";
                        }
                        // get the slider max
                        sliderMaxValue =tempNodeChild.toElement().attribute(SLIDER_MAX);
                        if(sliderMaxValue == "")
                        {
                            sliderMaxValue ="100";
                        }
                    }
                    else if(deviceSubType == SWITCH_SUB_TYPE_THREE)
                    {
                        // get the slider Websocket node
                        tempNodeChild = listDeviceDetails.at(DEVICE_PACKET_INDEX).childNodes().at(VSCP_PACKET_SLIDER_WEBSOCKET_CONFIGURE);
                        // get the slider min
                        sliderMinValue =tempNodeChild.toElement().attribute(VARIABLE_SWITCH_MIN);
                        if(sliderMinValue == "")
                        {
                            sliderMinValue ="0";
                        }
                        // get the slider max
                        sliderMaxValue =tempNodeChild.toElement().attribute(VARIABLE_SWITCH_MAX);
                        if(sliderMaxValue == "")
                        {
                            sliderMaxValue ="100";
                        }
                    }
                    else
                    {

                    }

                    // If device type is sensor
                    if(deviceType == DEVICE_SENSOR)
                    {
                        //deviceNameNonFormatted = "No Data From Sensor";
                        //deviceNameNonFormattedRemote = "No Data From Sensor";
                        deviceNameNonFormattedRemote = deviceNameNonFormatted;
                    }
                    else if(deviceSubType == SWITCH_SUB_TYPE_ONE) // If device type is switch
                    {
                        deviceNameNonFormattedRemote = deviceNameNonFormatted;
                    }
                    else if(deviceSubType == SWITCH_SUB_TYPE_TWO)
                    {
                        deviceNameNonFormattedRemote = deviceNameNonFormatted;
                    }
                    else if(deviceSubType == SWITCH_SUB_TYPE_THREE)
                    {
                        deviceNameNonFormattedRemote = deviceNameNonFormatted;
                    }
                    else
                    {
                        //Do nothing
                    }

                    //Device image ID
                    //TextDeviceImageId = textArea + "_Image_" + deviceName;
                    //Device text ID
                    //TextDevicetxtId = textArea + "_" + deviceName + "_Txt";

                    //Get device Image node
                    tempNodeChild = listDeviceDetails.at(DEVICE_IMAGE_INDEX);
                    if (!tempNodeChild.isNull())
                    {
                        deviceImage = tempNodeChild.toElement().text();
                    }
                    else
                    {
                        deviceImage = "";
                    }

                    //convert into number
                    deviceImageNumber = deviceImage.toUInt();

                    // Get the image URL
                    if(deviceType == DEVICE_SENSOR)
                    {
                        getSensorDeviceImage(deviceImageNumber ,sensorImageSrc);
                        deviceImageSrc = sensorImageSrc;
                    }
                    else
                    {
                        if(deviceSubType == SWITCH_SUB_TYPE_ONE)
                        {
                            getSwitchDeviceImage(deviceImageNumber ,switchOnImageSrc,switchOffImageSrc);
                            deviceImageSrc = switchOffImageSrc;
                        }
                        else if (deviceSubType == SWITCH_SUB_TYPE_TWO)
                        {
                            getSliderDeviceImage(deviceImageNumber,sliderImageSrc);
                        }
                        else if (deviceSubType == SWITCH_SUB_TYPE_THREE)
                        {
                            getSwitchVariableButtonDeviceImage(deviceImageNumber ,switchButtonIncImageSrc,switchButtonDownImageSrc);

                        }
                        else
                        {
                            // Do nothing
                        }
                    }

                    tempNodeChild = listDeviceDetails.at(DEVICE_PACKET_INDEX);
                    // If device type is sensor
                    if(deviceType == DEVICE_SENSOR)
                    {
                        // get the sensor Websocket node
                        tempNodeSubChild = listDeviceDetails.at(DEVICE_PACKET_INDEX).childNodes().at(VSCP_PACKET_SENSOR_WEBSOCKET_CONFIGURE);
                        // get the switch image ID
                        TextDeviceImageId =tempNodeSubChild.toElement().attribute(SENSOR_ID);
                        // get the sensor Remote Txt ID
                        TextDevicetxtId = tempNodeSubChild.toElement().attribute(SENSOR_REMOTE_TXT_ID);
                        // get graph ID
                        TextImageOneId = tempNodeSubChild.toElement().attribute(SENSOR_GRAPH_ID);
                        //get graph unit ID
                        TextImageTwoId = tempNodeSubChild.toElement().attribute(SENSOR_GRAPH_UNIT_ID);
                        // get graph type
                        TextDeviceLocalTxtId = tempNodeSubChild.toElement().attribute(SENSOR_GRAPH_TYPE);
                        //prepare the Packet format for each sensor device socket
                        //  --> both are dummy parameter here to satisfy function call
                        prepareSocketConf(tempNodeChild,TextDevicetxtId,TextDeviceLocalTxtId,TextImageOneId,TextImageTwoId,deviceImage, houseName);
                    }
                    else
                    {
                        if(deviceSubType == SWITCH_SUB_TYPE_ONE)
                        {
                            // get the switch Websocket node
                            tempNodeSubChild = listDeviceDetails.at(DEVICE_PACKET_INDEX).childNodes().at(VSCP_PACKET_SWITCH_WEBSOCKET_CONFIGURE);
                            // get the switch image ID
                            TextDeviceImageId =tempNodeSubChild.toElement().attribute(SWITCH_ID);
                            //prepare the Packet format for each switch device socket
                            // TextDeviceLocalTxtId & TextImageOneID & TextImageTwoId --> both are dummy parameter here to satisfy function call
                            prepareSocketConf(tempNodeChild,TextDeviceImageId,TextDeviceLocalTxtId,TextImageOneId,TextImageTwoId,deviceImage, houseName);
                        }
                        else if (deviceSubType == SWITCH_SUB_TYPE_TWO)  // slider
                        {
                            // get the slider Websocket node
                            tempNodeSubChild = listDeviceDetails.at(DEVICE_PACKET_INDEX).childNodes().at(VSCP_PACKET_SWITCH_WEBSOCKET_CONFIGURE);
                            // get the Slider image ID
                            TextDeviceImageId =tempNodeSubChild.toElement().attribute(SLIDER_ID);
                            // get the Slider Local Txt ID
                            TextDeviceLocalTxtId = tempNodeSubChild.toElement().attribute(SLIDER_LOCAL_TXT_ID);
                            // get the Slider Remote Txt ID
                            TextDevicetxtId = tempNodeSubChild.toElement().attribute(SLIDER_REMOTE_TXT_ID);
                            //prepare the Packet format for each switch device socket
                            // TextImageTwo  -->  are dummy parameter here to satisfy function call
                            prepareSocketConf(tempNodeChild,TextDevicetxtId,TextDeviceLocalTxtId,TextDeviceImageId,TextImageTwoId,deviceImage, houseName);
                        }
                        else if (deviceSubType == SWITCH_SUB_TYPE_THREE)  // variable button
                        {
                            // get the variable button Websocket node
                            tempNodeSubChild = listDeviceDetails.at(DEVICE_PACKET_INDEX).childNodes().at(VSCP_PACKET_SLIDER_WEBSOCKET_CONFIGURE);
                            // get the variable button Inc ID
                            TextImageOneId =tempNodeSubChild.toElement().attribute(VARIABLE_SWITCH_INC_ID);
                            // get the variable button Dec ID
                            TextImageTwoId =tempNodeSubChild.toElement().attribute(VARIABLE_SWITCH_DEC_ID);
                            // get the variable button Local Txt ID
                            TextDeviceLocalTxtId = tempNodeSubChild.toElement().attribute(VARIABLE_SWITCH_LOCAL_TXT_ID);
                            // get the variable button Remote Txt ID
                            TextDevicetxtId = tempNodeSubChild.toElement().attribute(VARIABLE_SWITCH_REMOTE_TXT_ID);

                            //prepare the Packet format for each sensor device socket
                            prepareSocketConf(tempNodeChild,TextDevicetxtId,TextDeviceLocalTxtId,TextImageOneId,TextImageTwoId,deviceImage, houseName);
                        }
                        else
                        {
                            // Do nothing
                        }
                    }

                    //Create input node
                    nodeChildNameTemp = "input";
                    NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
                    if(k == DEVICE_INDEX)
                    {
                        NodeElementChildTemp.setAttribute("class","image_menu_center_first");
                    }
                    else
                    {
                        NodeElementChildTemp.setAttribute("class","image_menu_center_second");
                    }

                    if(deviceType == DEVICE_SENSOR)
                    {
                        NodeElementChildTemp.setAttribute("id",TextDeviceImageId);
                        NodeElementChildTemp.setAttribute("type","image");
                        NodeElementChildTemp.setAttribute("src",deviceImageSrc);
                    }
                    else if(deviceSubType == SWITCH_SUB_TYPE_ONE)
                    {
                        NodeElementChildTemp.setAttribute("id",TextDeviceImageId);
                        NodeElementChildTemp.setAttribute("type","image");
                        NodeElementChildTemp.setAttribute("src",deviceImageSrc);
                    }
                    else if(deviceSubType == SWITCH_SUB_TYPE_TWO)
                    {
                        NodeElementChildTemp.setAttribute("id",TextDeviceImageId);
                        NodeElementChildTemp.setAttribute("type","range");
                        NodeElementChildTemp.setAttribute("min",sliderMinValue);
                        NodeElementChildTemp.setAttribute("max",sliderMaxValue);
                        NodeElementChildTemp.setAttribute("step","1");
                        NodeElementChildTemp.setAttribute("value","0");
                        //NodeElementChildTemp.setAttribute("src",sliderImageSrc);
                    }
                    else if (deviceSubType == SWITCH_SUB_TYPE_THREE)
                    {
                        NodeElementChildTemp.setAttribute("id",TextImageOneId);
                        NodeElementChildTemp.setAttribute("type","image");
                        NodeElementChildTemp.setAttribute("src",switchButtonIncImageSrc);

                    }
                    //NodeElementChildTemp.setAttribute("alt",TextDeviceImageId);
                    //Append image div to room div
                    NodeElementTemp.appendChild(NodeElementChildTemp);

                    if(deviceSubType == SWITCH_SUB_TYPE_TWO)
                    {
                        //Create span node
                        nodeChildNameTemp = "span";
                        NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
                        NodeElementChildTemp.setAttribute("type","text");
                        NodeElementChildTemp.setAttribute("class","spantxt_center");
                        NodeElementChildTemp.setAttribute("id",TextDeviceLocalTxtId + "_Fix");
                        stringTxtNode = deviceNameNonFormatted + " Value : ";
                        textNode = htmlDomDocument.createTextNode(stringTxtNode);
                        //Append txt node
                        NodeElementChildTemp.appendChild(textNode);

                        //Append paragraph div to room div
                        NodeElementTemp.appendChild(NodeElementChildTemp);

                        //Create span node
                        nodeChildNameTemp = "span";
                        NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
                        NodeElementChildTemp.setAttribute("type","text");
                        NodeElementChildTemp.setAttribute("class","spantxt_center");
                        NodeElementChildTemp.setAttribute("id",TextDeviceLocalTxtId);
                        stringTxtNode = "0";
                        textNode = htmlDomDocument.createTextNode(stringTxtNode);
                        //Append txt node
                        NodeElementChildTemp.appendChild(textNode);

                        //Append paragraph div to room div
                        NodeElementTemp.appendChild(NodeElementChildTemp);

                    }
                    else if(deviceSubType == SWITCH_SUB_TYPE_THREE)
                    {
                        //Create span node
                        nodeChildNameTemp = "span";
                        NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
                        NodeElementChildTemp.setAttribute("type","text");
                        NodeElementChildTemp.setAttribute("class","spantxt_button_center");
                        NodeElementChildTemp.setAttribute("id",TextDeviceLocalTxtId);
                        stringTxtNode = "0";
                        textNode = htmlDomDocument.createTextNode(stringTxtNode);
                        //Append txt node
                        NodeElementChildTemp.appendChild(textNode);

                        //Append paragraph div to room div
                        NodeElementTemp.appendChild(NodeElementChildTemp);


                        //Create input node
                        nodeChildNameTemp = "input";
                        NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
                        NodeElementChildTemp.setAttribute("id",TextImageTwoId);
                        if(k == DEVICE_INDEX)
                        {
                            NodeElementChildTemp.setAttribute("class","image_menu_center_first_sec");
                        }
                        else
                        {
                            NodeElementChildTemp.setAttribute("class","image_menu_center_second_sec");
                        }
                        NodeElementChildTemp.setAttribute("type","image");
                        NodeElementChildTemp.setAttribute("src",switchButtonDownImageSrc);


                        //Append image div to room div
                        NodeElementTemp.appendChild(NodeElementChildTemp);


                    }

                    //Create paragraph node
                    nodeChildNameTemp = "p";
                    NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
                    NodeElementChildTemp.setAttribute("class","imgtxt_center");

                    stringTxtClass = "spantxt_center";
                    if(houseFloor == MULTI_FLOOR_HOUSE)
                    {
                        stringTxtNode = floorName + " :" ;
                        stringTxtClass += " group_Txt_" + houseName;

                        //Create span node : for floor name
                        nodeChildNameTemp = "span";
                        NodeElementSpan = htmlDomDocument.createElement(nodeChildNameTemp);
                        NodeElementSpan.setAttribute("type","text");
                        NodeElementSpan.setAttribute("class",stringTxtClass);
                        //stringTxtNode = " Disconnected";
                        textNode = htmlDomDocument.createTextNode(stringTxtNode);
                        //Append txt node
                        NodeElementSpan.appendChild(textNode);
                        NodeElementChildTemp.appendChild(NodeElementSpan);

                    }


                    stringTxtNode =  nodeDataTextRoom + " : " ;
                    stringTxtClass = "spantxt_center";
                    if(deviceInfo == DEVICE_INFO_TYPE_ONE)
                    {
                        if(houseFloor == SINGLE_FLOOR_HOUSE)
                        {
                            stringTxtClass = stringTxtClass + " group_Light_Txt_" + houseName;
                        }
                        else
                        {
                            stringTxtClass += " group_Floor_Txt_" + houseName;
                        }
                    }
                    else if (deviceInfo == DEVICE_INFO_TYPE_TWO)
                    {
                        if(houseFloor == SINGLE_FLOOR_HOUSE)
                        {
                            stringTxtClass = stringTxtClass + " group_Accessories_Txt_" + houseName;
                        }
                        else
                        {
                            stringTxtClass += " group_Floor_Txt_" + houseName;
                        }

                    }
                    else if (deviceInfo == DEVICE_INFO_TYPE_THREE)
                    {
                        if(houseFloor == SINGLE_FLOOR_HOUSE)
                        {
                            stringTxtClass = stringTxtClass + " group_Blinds_Windows_Txt_" + houseName;
                        }
                        else
                        {
                            stringTxtClass += " group_Floor_Txt_" + houseName;
                        }
                    }
                    else if (deviceInfo == DEVICE_INFO_TYPE_FOUR)
                    {
                        if(houseFloor == SINGLE_FLOOR_HOUSE)
                        {
                            stringTxtClass = stringTxtClass + " group_Sensors_Txt_" + houseName;
                        }
                        else
                        {
                            stringTxtClass += " group_Floor_Txt_" + houseName;
                        }
                    }
                    else if (deviceInfo == DEVICE_INFO_TYPE_FIVE)
                    {
                        if(houseFloor == SINGLE_FLOOR_HOUSE)
                        {
                            stringTxtClass = stringTxtClass + " group_Temperature_control_Txt_" + houseName;
                        }
                        else
                        {
                            stringTxtClass += " group_Floor_Txt_" + houseName;
                        }
                    }
                    else
                    {

                    }
                    //Create span node
                    nodeChildNameTemp = "span";
                    NodeElementSpan = htmlDomDocument.createElement(nodeChildNameTemp);
                    NodeElementSpan.setAttribute("type","text");
                    NodeElementSpan.setAttribute("class",stringTxtClass);
                    //stringTxtNode = " Disconnected";
                    textNode = htmlDomDocument.createTextNode(stringTxtNode);
                    //Append txt node
                    NodeElementSpan.appendChild(textNode);
                    NodeElementChildTemp.appendChild(NodeElementSpan);

                    //roomTxtId = floorNameArea  + "_" + nodeDataTextRoom + "_txt";
                    //if(deviceSubType == SWITCH_SUB_TYPE_TWO)
                    //{
                    //NodeElementChildTemp.setAttribute("id",TextDevicetxtId);
                    //}

                    if(deviceSubType == SWITCH_SUB_TYPE_ONE)
                    {
                        stringTxtNode = deviceNameNonFormattedRemote;
                    }
                    else if((deviceType == DEVICE_SENSOR))
                    {
                        //stringTxtNode = deviceNameNonFormattedRemote;
                        deviceNameNonFormattedRemote += " : ";
                        stringTxtNode = deviceNameNonFormattedRemote;
                    }
                    else if ((deviceSubType == SWITCH_SUB_TYPE_TWO) || (deviceSubType == SWITCH_SUB_TYPE_THREE))
                    {
                        deviceNameNonFormattedRemote += " : "; //<span id=\"" + TextDevicetxtId + "\">" " Disconnected" "</span>";
                        stringTxtNode = deviceNameNonFormattedRemote;
                    }
                    else
                    {
                        // Do nothing
                    }
                    // Enter device text ID
                    /*if(deviceType == DEVICE_SENSOR)
              {
                  NodeElementChildTemp.setAttribute("id",TextDevicetxtId);
              }*/

                    //sensorRemoteText = stringTxtNode;

                    textNode = htmlDomDocument.createTextNode(stringTxtNode);
                    //Append txt node
                    NodeElementChildTemp.appendChild(textNode);
                    if ((deviceSubType == SWITCH_SUB_TYPE_TWO) || (deviceSubType == SWITCH_SUB_TYPE_THREE) || (deviceType == DEVICE_SENSOR))
                    {
                        //Create span node
                        nodeChildNameTemp = "span";
                        NodeElementSpan = htmlDomDocument.createElement(nodeChildNameTemp);
                        NodeElementSpan.setAttribute("type","text");
                        NodeElementSpan.setAttribute("class","spantxt_center");
                        NodeElementSpan.setAttribute("id",TextDevicetxtId);
                        if(deviceType == DEVICE_SENSOR)
                        {
                            stringTxtNode = "No Data From Sensor";
                        }
                        else
                        {
                            stringTxtNode = " Disconnected";
                        }
                        textNode = htmlDomDocument.createTextNode(stringTxtNode);
                        //Append txt node
                        NodeElementSpan.appendChild(textNode);
                        NodeElementChildTemp.appendChild(NodeElementSpan);

                    }
                    //Append paragraph div to room div
                    NodeElementTemp.appendChild(NodeElementChildTemp);

                    //Create hr node
                    nodeChildNameTemp = "hr";
                    NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
                    //Append horizontal line div to room div
                    NodeElementTemp.appendChild(NodeElementChildTemp);

                    // Append floor div to div scrollable
                    NodeElementMultiFloorDivScrollableCenter.appendChild(NodeElementTemp);

                    // If device type is sensor
                    if(deviceType == DEVICE_SENSOR)
                    {
                        // create Device node
                        nodeNameTemp = "div";
                        NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);
                        if(houseFloor == MULTI_FLOOR_HOUSE)
                        {
                            textArea = houseName + "_group_class " + "group_sensor_graph " "group_sensor_graph_" + houseName + " group_Sensors_Graph_" + houseName + "_Floor_" + floorName;
                        }
                        else
                        {
                            textArea = houseName + "_group_class " + "group_sensor_graph " "group_sensor_graph_" + houseName;
                        }
                        NodeElementTemp.setAttribute("class",textArea);

                        //Create Header node
                        nodeChildNameTemp = "h3";
                        NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
                        NodeElementChildTemp.setAttribute("class","imgtxt_Heading_graph");

                        if(houseFloor == MULTI_FLOOR_HOUSE)
                        {
                            //Create span node : for floor name
                            nodeChildNameTemp = "span";
                            NodeElementSpan = htmlDomDocument.createElement(nodeChildNameTemp);
                            NodeElementSpan.setAttribute("type","text");
                            NodeElementSpan.setAttribute("class","group_Txt_" + houseName);
                            stringTxtNode = floorName + " : ";
                            textNode = htmlDomDocument.createTextNode(stringTxtNode);
                            //Append txt node
                            NodeElementSpan.appendChild(textNode);
                            NodeElementChildTemp.appendChild(NodeElementSpan);
                        }

                        stringTxtNode = roomNameDevice + " : " + deviceNameDevice + " : ";
                        textNode = htmlDomDocument.createTextNode(stringTxtNode);
                        //Append txt node
                        NodeElementChildTemp.appendChild(textNode);

                        stringTxtNode = " Disconnected" ;

                        //Create span node : for room name
                        nodeChildNameTemp = "span";
                        NodeElementSpan = htmlDomDocument.createElement(nodeChildNameTemp);
                        NodeElementSpan.setAttribute("type","text");
                        NodeElementSpan.setAttribute("id",TextImageTwoId);
                        //stringTxtNode = " Disconnected";
                        textNode = htmlDomDocument.createTextNode(stringTxtNode);
                        //Append txt node
                        NodeElementSpan.appendChild(textNode);
                        NodeElementChildTemp.appendChild(NodeElementSpan);


                        NodeElementTemp.appendChild(NodeElementChildTemp);

                        //Create div node
                        nodeChildNameTemp = "div";
                        NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
                        NodeElementChildTemp.setAttribute("class","graph_sensor epoch category10");
                        NodeElementChildTemp.setAttribute("id",TextImageOneId);
                        stringTxtNode = "";
                        textNode = htmlDomDocument.createTextNode(stringTxtNode);
                        //Append txt node
                        NodeElementChildTemp.appendChild(textNode);
                        //Append horizontal line div to room div
                        NodeElementTemp.appendChild(NodeElementChildTemp);


                        //Create hr node
                        nodeChildNameTemp = "hr";
                        NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
                        //Append horizontal line div to room div
                        NodeElementTemp.appendChild(NodeElementChildTemp);

                        // Append floor div to div scrollable
                        NodeElementMultiFloorDivScrollableCenter.appendChild(NodeElementTemp);

                    }

                }

                scrollableCenterAreaWidgetArray += "\"" + textArea_main + "\"";

                //create sensor graph
                if(sensorGraphCreate == 1)
                {
                    textArea_main = "group_sensor_graph_" + houseName;
                    scrollableCenterAreaWidgetArray += ",";
                    scrollableCenterAreaWidgetArray += "\"" + textArea_main + "\"";
                    sensorGraphCreate = 0;
                }

                // check if it is last element to put in the array
                /*if(((j+1) == listRooms.size()) && ((i+1) == floorNodesList.size()))
          {
              //Append nothing - as last node

          }
          else
          {*/
                scrollableCenterAreaWidgetArray += ",";
                //}

                index++;
                if(index == 5u)
                {
                    scrollableCenterAreaWidgetArray += "\n";
                    index = 0u;
                }
            }

        }

        // Append Info div
        for (int k = 0; k < INFO_NODES_COUNT; ++k)
        {

            QString classTemp;
            QString idTemp;

            classTemp = "info_" + houseName + "_" + QString::number(k);

            textArea = "info_text_" + houseName + " " + classTemp;
            // create Info node
            nodeNameTemp = "div";
            NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);
            NodeElementTemp.setAttribute("class",textArea);

            nodeChildNameTemp = "div";
            NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
            NodeElementChildTemp.setAttribute("class","green_box arrow_left");
            idTemp = "info_class_" + houseName + "_" + QString::number(k);
            NodeElementChildTemp.setAttribute("id",idTemp);
            //Create span node : for message
            stringTxtNode = "" ;
            nodeChildNameTemp = "span";
            idTemp = "info_txt_" + houseName + "_" + QString::number(k);
            NodeElementSpan = htmlDomDocument.createElement(nodeChildNameTemp);
            NodeElementSpan.setAttribute("id",idTemp);
            //create text node
            textNode = htmlDomDocument.createTextNode(stringTxtNode);
            //Append txt node
            NodeElementSpan.appendChild(textNode);
            NodeElementChildTemp.appendChild(NodeElementSpan);
            NodeElementTemp.appendChild(NodeElementChildTemp);

            nodeChildNameTemp = "div";
            NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
            NodeElementChildTemp.setAttribute("class","time_left_box_class");
            idTemp = "info_time_" + houseName + "_" + QString::number(k);
            NodeElementChildTemp.setAttribute("id",idTemp);
            //create text node
            textNode = htmlDomDocument.createTextNode(stringTxtNode);
            //Append txt node
            NodeElementChildTemp.appendChild(textNode);
            NodeElementTemp.appendChild(NodeElementChildTemp);


            nodeChildNameTemp = "div";
            NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
            NodeElementChildTemp.setAttribute("class","padding_Info_text");
            //Create hr node
            nodeChildNameTemp = "hr";
            NodeElementHr = htmlDomDocument.createElement(nodeChildNameTemp);
            //Append horizontal line div to room div
            NodeElementChildTemp.appendChild(NodeElementHr);
            NodeElementTemp.appendChild(NodeElementChildTemp);


            // Append floor div to div scrollable
            NodeElementMultiFloorDivScrollableCenter.appendChild(NodeElementTemp);

        }

        QString info_var_name = "infoVariable" + houseName + "_VAR";
        QString info_var = "var " + info_var_name + ";";
        //Info variable string -- (variable creation)
        infoVariableString += "\n";
        infoVariableString += "\n";
        infoVariableString += info_var;
        infoVariableString += "\n";
        // info variable array
        infoVariableArray += info_var_name;

        if((p+1) <  houseNodesList.size())
        {
            infoVariableArray += ",";
            //scrollableHrArray += ",";
            houseFloorsSwitchSocketCfgFileString += ",";
            houseFloorsSensorSocketCfgFileString += ",";
            houseFloorsVariableSliderSocketCfgFileString += ",";
            houseFloorsVariableSwitchSocketCfgFileString += ",";
        }

        //Add Info Text class
        QString classInfo = "info_text_" + houseName;

        infoClassArray += "\"" + classInfo + "\"";
        if((p+1) <  houseNodesList.size())
        {
            infoClassArray += ",";
        }

        scrollableCenterAreaWidgetArray += "\"" + classInfo + "\"";

        //Append new line
        scrollableCenterAreaWidgetArray += "\n";
        //Terminate the array
        scrollableCenterAreaWidgetArray += "];";
        //Append new line
        scrollableCenterAreaWidgetArray += "\n";
        //Append new line
        scrollableCenterAreaWidgetArray += "\n";

        // append scrollableCenterAreaWidgetArray
        floorCfgFileString += scrollableCenterAreaWidgetArray;

        FloorsSocketCfgFileString += FloorsSwitchSocketCfgFileString ;
        FloorsSocketCfgFileString +=  "\n\n\n\n\n\n";
        FloorsSocketCfgFileString += FloorsVariableSliderSocketCfgFileString ;
        FloorsSocketCfgFileString +=  "\n\n\n\n\n\n";
        FloorsSocketCfgFileString += FloorsVariableSwitchSocketCfgFileString ;
        FloorsSocketCfgFileString +=  "\n\n\n\n\n\n";
        FloorsSocketCfgFileString += FloorsSensorSocketCfgFileString;

        // --> could be an error
        //floorCfgFileString += SingleFloorGroupImageClass;
        //floorCfgFileString += SingleFloorGroupTxtClass;
        //htmlRoot.appendChild(NodeElement);

    }


    //Append new line
    infoVariableArray += "\n";
    //Terminate the array
    infoVariableArray += "];";
    //Append new line
    infoVariableArray += "\n";
    //Append new line
    infoVariableArray += "\n";

    //Append new line
    infoVariableString += "\n";

    //Append new line
    infoClassArray += "\n";
    //Terminate the array
    infoClassArray += "];";
    //Append new line
    infoClassArray += "\n";
    //Append new line
    infoClassArray += "\n";

    //Append new line
    houseCenterAreaWidgetArray += "\n";
    //Terminate the array
    houseCenterAreaWidgetArray += "];";
    //Append new line
    houseCenterAreaWidgetArray += "\n";
    //Append new line
    houseCenterAreaWidgetArray += "\n";

    //Append new line
    houseFloorsSwitchSocketCfgFileString += "\n";
    //Terminate the array
    houseFloorsSwitchSocketCfgFileString += "];";
    //Append new line
    houseFloorsSwitchSocketCfgFileString += "\n";
    //Append new line
    houseFloorsSwitchSocketCfgFileString += "\n";

    //Append new line
    houseFloorsSensorSocketCfgFileString += "\n";
    //Terminate the array
    houseFloorsSensorSocketCfgFileString += "];";
    //Append new line
    houseFloorsSensorSocketCfgFileString += "\n";
    //Append new line
    houseFloorsSensorSocketCfgFileString += "\n";

    //Append new line
    houseFloorsVariableSliderSocketCfgFileString += "\n";
    //Terminate the array
    houseFloorsVariableSliderSocketCfgFileString += "];";
    //Append new line
    houseFloorsVariableSliderSocketCfgFileString += "\n";
    //Append new line
    houseFloorsVariableSliderSocketCfgFileString += "\n";

    //Append new line
    houseFloorsVariableSwitchSocketCfgFileString += "\n";
    //Terminate the array
    houseFloorsVariableSwitchSocketCfgFileString += "];";
    //Append new line
    houseFloorsVariableSwitchSocketCfgFileString += "\n";
    //Append new line
    houseFloorsVariableSwitchSocketCfgFileString += "\n";

    // Add Central widget array of array
    floorCfgFileString += houseCenterAreaWidgetArray;
    // Add info variables
    floorCfgFileString += infoVariableString;
    // Add info variables array
    floorCfgFileString += infoVariableArray;
    // Add info variables array
    floorCfgFileString += infoClassArray;

}


// close java script configure files
void GenerateApp::closeCfgfiles()
{
    // Write floorCfgFile content to the file
    (floorCfgFileStream) << floorCfgFileString ;
    // close the file
    floorCfgFile.flush();
    floorCfgFile.close();

    FloorsSocketCfgFileString += houseFloorsSwitchSocketCfgFileString ;
    FloorsSocketCfgFileString +=  "\n\n\n\n\n\n";
    FloorsSocketCfgFileString += houseFloorsVariableSliderSocketCfgFileString ;
    FloorsSocketCfgFileString +=  "\n\n\n\n\n\n";
    FloorsSocketCfgFileString += houseFloorsVariableSwitchSocketCfgFileString ;
    FloorsSocketCfgFileString +=  "\n\n\n\n\n\n";
    FloorsSocketCfgFileString += houseFloorsSensorSocketCfgFileString;
    // Write FloorsSocketCfg content to the file
    (FloorsSocketCfgFileStream) << FloorsSocketCfgFileString ;
    // close the file
    FloorsSocketCfgFile.flush();
    FloorsSocketCfgFile.close();

    // Write variables.xml content to the file
    (xmlVariablesStream) << xmlVariablesDomDocument.toString() ;
    // close the file
    xmlVariablesFile.flush();
    xmlVariablesFile.close();

    // Write variables.xml content to the file
    (xmlDmStream) << xmlDmDomDocument.toString() ;
    // close the file
    xmlDmFile.flush();
    xmlDmFile.close();
}

// close the HTML File
void GenerateApp::closeHtmlFile()
{
    // Write html to the file
    (htmlStream) << htmlDomDocument.toString();

    // close the file
    htmlFile.flush();
    htmlFile.close();
}

/*
//verify the xml is single floor or multiple floor
void GenerateApp::verifyHouseFloor()
{
    QDomNode tempNodeChild;
    QDomNodeList listChild;
    QString nodeDataTextFloor;
    QString nodeDataTextFloorPrev;
    QString floorName;
    bool floorFoundInList = false;

    // root have Test Case nodes
    if(list.count() != 0)
    {
        for(int i =0; i< list.count() ; i++)
        {
            //read the child node from list
            tempNodeChild = list.at(i);

            // Create list of child nodes of - test case
            listChild = tempNodeChild.childNodes();

            //Read floor name from node
            tempNodeChild = listChild.at(FLOOR_NAME_INDEX);
            if (!tempNodeChild.isNull())
            {
                nodeDataTextFloor = tempNodeChild.toElement().text();
            }
            else
            {
                nodeDataTextFloor = "";
            }

            if(i==0)
            {
                nodeDataTextFloorPrev = nodeDataTextFloor;

                //Append to the list floor
                floorList << nodeDataTextFloor;
            }
            else
            {
                if(nodeDataTextFloorPrev != nodeDataTextFloor)
                {
                    houseFloor = MULTI_FLOOR_HOUSE;

                    // break the loop & return back
                    //break;
                }

                floorFoundInList = false;

                //Serch if floor name is in list
                for (int j = 0; j < floorList.size(); ++j)
                {

                  floorName = floorList.at(j);

                  if(floorName == nodeDataTextFloor)
                  {
                      floorFoundInList = true;
                      //break the loop
                      break;
                  }
                  else
                  {
                      floorFoundInList = false;
                  }

                }

                //append floor name to list if - not found
                if(floorFoundInList == false)
                {
                    //Append to the list floor
                    floorList << nodeDataTextFloor;
                }
            }
        }
    }

}*/


//verify the xml is single floor or multiple floor
void GenerateApp::verifyHouseFloor(QList<T_packetHouse> &housePacketList,QDomNodeList &list )
{
    QString nodeDataTextHouse;
    QString nodeDataTextFloor;

    QDomNodeList listChild;
    //
    QDomNode tempNodeChild;
    bool found = false;

    QList<QString> listHouses;
    QList<QString> floorList;

    T_packetFloor floorPacketNode;
    T_packetHouse housePacketNode;


    // root have Test Case nodes
    if(list.count() != 0)
    {
        /* **** Get the name of houses **** */
        for(int i =0; i< list.count() ; i++)
        {
            //read the child node from list
            tempNodeChild = list.at(i);

            // Create list of child nodes of - test case
            listChild = tempNodeChild.childNodes();

            //Read floor name from node
            tempNodeChild = listChild.at(HOUSE_NAME_INDEX);
            if (!tempNodeChild.isNull())
            {
                nodeDataTextHouse = tempNodeChild.toElement().text();
            }
            else
            {
                nodeDataTextHouse = "";
            }

            // append house name to list
            if(listHouses.isEmpty())
            {
                listHouses.append(nodeDataTextHouse);
            }
            else
            {
                found = false;
                for (int j = 0; j < listHouses.size(); ++j)
                {
                    if (listHouses.at(j) == nodeDataTextHouse)
                    {
                        found = true;
                    }

                }

                if(found == false)
                {
                    listHouses.append(nodeDataTextHouse);
                }
            }

        }/* **** Get the name of houses **** */

        /* **** Get floor for every house **** */
        for(int i =0; i< listHouses.count() ; i++)
        {
            QString houseNamestr = listHouses.at(i);
            housePacketNode.houseName = houseNamestr;

            //Get the floor of houses
            for(int j =0; j< list.count() ; j++)
            {
                //read the child node from list
                tempNodeChild = list.at(j);

                // Create list of child nodes of - test case
                listChild = tempNodeChild.childNodes();

                //Read house name from node
                tempNodeChild = listChild.at(HOUSE_NAME_INDEX);
                if (!tempNodeChild.isNull())
                {
                    nodeDataTextHouse = tempNodeChild.toElement().text();
                }
                else
                {
                    nodeDataTextHouse = "";
                }

                // Check if the house name matches
                if(nodeDataTextHouse == houseNamestr)
                {
                    //Read floor name from node
                    tempNodeChild = listChild.at(FLOOR_NAME_INDEX);
                    if (!tempNodeChild.isNull())
                    {
                        nodeDataTextFloor = tempNodeChild.toElement().text();
                    }
                    else
                    {
                        nodeDataTextFloor = "";
                    }

                    // Append floor name to the floor list
                    if(floorList.isEmpty())
                    {
                        floorList.append(nodeDataTextFloor);
                    }
                    else
                    {
                        found = false;
                        for (int k = 0; k < floorList.size(); ++k)
                        {
                            if (floorList.at(k) == nodeDataTextFloor)
                            {
                                found = true;
                            }

                        }

                        if(found == false)
                        {
                            floorList.append(nodeDataTextFloor);
                        }
                    }

                }
                else
                {
                    //Do nothing
                }
            }

            /* **** prepare list of floor for each house  **** */
            for (int i = 0; i < floorList.size(); ++i)
            {
                QString floorNamestr;
                floorPacketNode.floorName = floorList.at(i);
                floorNamestr = floorPacketNode.floorName;

                // Get the floor name node & prepare index list for every floor
                for(uint16_t j =0; j< list.count() ; j++)
                {
                    //read the child node from list
                    tempNodeChild = list.at(j);

                    // Create list of child nodes of - test case
                    listChild = tempNodeChild.childNodes();

                    //Read house name from node
                    tempNodeChild = listChild.at(FLOOR_NAME_INDEX);
                    if (!tempNodeChild.isNull())
                    {
                        nodeDataTextFloor = tempNodeChild.toElement().text();
                    }
                    else
                    {
                        nodeDataTextFloor = "";
                    }

                    //Read house name from node
                    tempNodeChild = listChild.at(HOUSE_NAME_INDEX);
                    if (!tempNodeChild.isNull())
                    {
                        nodeDataTextHouse = tempNodeChild.toElement().text();
                    }
                    else
                    {
                        nodeDataTextHouse = "";
                    }
                    // Check if the floor name matches
                    if((nodeDataTextFloor == floorNamestr) && (nodeDataTextHouse==houseNamestr) )
                    {
                        floorPacketNode.floorIndexList.append(j);
                    }

                    // append index to floor packet node
                    //floorPacketNode.floorIndexList.append();
                }

                //append the floorpacketnode
                housePacketNode.houseFloorList.append(floorPacketNode);

                floorPacketNode.floorName = "";
                floorPacketNode.floorIndexList.clear();
            }/* **** prepare list of floor for each house  **** */

            // Append the T_packetHouse to the housePacketList
            housePacketList.append(housePacketNode);

            //clear all temp list
            floorList.clear();
            housePacketNode.houseName = "";
            housePacketNode.houseFloorList.clear();
            floorPacketNode.floorName = "";
            floorPacketNode.floorIndexList.clear();
        }/* **** Get floor for every house **** */
    }

    // check house type
    if(housePacketList.size() > 1)
    {
        xmlType = MULTI_HOUSE;
    }
    else
    {
        xmlType = SINGLE_HOUSE;
    }

    //check GUI type to be built -- i.e -- floor type
    for (int i = 0; i < housePacketList.size(); ++i)
    {
        if(housePacketList.at(i).houseFloorList.size() > 1)
        {
            houseFloor = MULTI_FLOOR_HOUSE;
        }
        //QMessageBox::information(this, "kk -> size", QString::number(housePacketList.at(i).houseFloorList.size()));
        //QMessageBox::information(this, "kk -> size", QString::number(housePacketList.at(i).houseFloorList.at(0).floorIndexList.size()));

    }
}

// Create div to select house
void GenerateApp::createHouseSelectDiv(QDomElement &NodeElementDivHouseSelect)
{
    QDomElement NodeElementTemp;
    QDomElement NodeElementChildTemp;
    QString nodeNameTemp;
    QString nodeChildNameTemp;

    QString OnClickText;

    QString houseNameImageId;
    QString houseName;

    QString houseImageIdArray;
    QString houseNameArray;
    QString houseGroupClassArray;


    nodeName = "div";
    NodeElementDivHouseSelect  = htmlDomDocument.createElement(nodeName);
    NodeElementDivHouseSelect.setAttribute("class","div_layer");

    //clear strings
    houseImageIdArray.clear();
    houseNameArray.clear();
    houseGroupClassArray.clear();
    // create array name
    houseImageIdArray     = "var house_image_id = [";
    houseNameArray        = "var house_name = [";
    houseGroupClassArray  = "var house_group_class = [";
    //Append new line
    houseImageIdArray += "\n";
    houseNameArray += "\n";
    houseGroupClassArray += "\n";


    //create ul node
    nodeNameTemp = "ul";
    NodeElementTemp  = htmlDomDocument.createElement(nodeNameTemp);

    //create li node
    for (int j = 0; j < houseNodesList.size(); ++j)
    {
        houseName = houseNodesList.at(j).houseName;


        //add floor image ID
        houseImageIdArray += "\"" + houseName + "_ID" "\""  ;
        // add HR line ID
        houseNameArray += "\"" + houseName + "\""  ;
        // add HR line ID
        houseGroupClassArray += "\"" + houseName + "_group_class" "\""  ;

        // check if it is last element to put in the array
        if((j+1) < houseNodesList.size())
        {
            houseImageIdArray += ",";
            houseNameArray += ",";
            houseGroupClassArray += ",";
        }

        //Create input node
        nodeChildNameTemp = "li";
        NodeElementChildTemp = htmlDomDocument.createElement(nodeChildNameTemp);
        houseNameImageId = houseName + "_ID";
        NodeElementChildTemp.setAttribute("id",houseNameImageId);
        //NodeElementChildTemp.setAttribute("alt",floorNameId);
        OnClickText = "selectId(" "this.id," +
                QString::number(j) + ","  +
                "'" + houseName + "',"
                "'" + houseName + "_group_class" "')"
                ;
        NodeElementChildTemp.setAttribute("onclick",OnClickText);
        stringTxtNode = houseName;
        textNode = htmlDomDocument.createTextNode(stringTxtNode);
        //Append txt node
        NodeElementChildTemp.appendChild(textNode);
        //Append house div to house select div layer
        NodeElementTemp.appendChild(NodeElementChildTemp);

    }

    //Append new line
    houseImageIdArray += "\n";
    //Terminate the array
    houseImageIdArray += "];";
    //Append new line
    houseImageIdArray += "\n";
    //Append new line
    houseImageIdArray += "\n";

    //Append new line
    houseNameArray += "\n";
    //Terminate the array
    houseNameArray += "];";
    //Append new line
    houseNameArray += "\n";
    //Append new line
    houseNameArray += "\n";


    //Append new line
    houseGroupClassArray += "\n";
    //Terminate the array
    houseGroupClassArray += "];";
    //Append new line
    houseGroupClassArray += "\n";
    //Append new line
    houseGroupClassArray += "\n";

    // append array to global string -- of cfg file
    floorCfgFileString = houseImageIdArray + houseNameArray + houseGroupClassArray;


    //append ul list
    NodeElementDivHouseSelect.appendChild(NodeElementTemp);
}

// Create the Html Body
void GenerateApp::createHtmlBody()
{
    QDomElement NodeElementChildTemp;
    QString onLoadCallback;

    nodeName = "body";
    NodeElement  = htmlDomDocument.createElement(nodeName);
    if(xmlType == MULTI_HOUSE)
    {
        onLoadCallback = "doc_onload(1)";
    }
    else
    {
        onLoadCallback = "doc_onload(0)";
    }
    NodeElement.setAttribute("onload",onLoadCallback);

       // create multi house select div
       if(xmlType == MULTI_HOUSE)
       {
          createHouseSelectDiv(NodeElementChildTemp);
          NodeElement.appendChild(NodeElementChildTemp);
       }

    //QMessageBox::information(this, "uiMagician", "One");
       // Create the DIV scrollable
       if(houseFloor == MULTI_FLOOR_HOUSE)
       {
           createMultiFloorDivScrollable(NodeElementChildTemp);
       }
       else
       {
           createSingleFloorDivScrollable(NodeElementChildTemp);
       }
       NodeElement.appendChild(NodeElementChildTemp);

     //QMessageBox::information(this, "uiMagician", "two__");
       // Create the DIV scrollableMenu
       if(houseFloor == MULTI_FLOOR_HOUSE)
       {
           //clear the node
           NodeElementChildTemp.clear();
           createMultiFloorDivScrollableMenu(NodeElementChildTemp);
           NodeElement.appendChild(NodeElementChildTemp);  // --> could be error todo
       }
       else
       {
           // Do nothing
       }
       //NodeElement.appendChild(NodeElementChildTemp); // --> could be error todo
       // Create the DIV scrollableCenter
       //clear the node
       NodeElementChildTemp.clear();

       // Create the DIV scrollableCenter
       createFloorDivScrollableCenter(NodeElementChildTemp);

       NodeElement.appendChild(NodeElementChildTemp);
       //Create div fotter
       //clear the node
       NodeElementChildTemp.clear();
       createDivFotter(NodeElementChildTemp);
       NodeElement.appendChild(NodeElementChildTemp);

    htmlRoot.appendChild(NodeElement);

}

// create the floor configure javascript files
void GenerateApp::createFloorCfgFiles()
{
    /* set the Html body configure file */
    if(houseFloor == MULTI_FLOOR_HOUSE)
    {
        floorCfgFilePath = htmlFileDirectoryPath + "/multiFloorCfg.js";
    }
    else
    {
        floorCfgFilePath = htmlFileDirectoryPath + "/singleFloorCfg.js";
    }
    //set the name of the file
    floorCfgFile.setFileName(floorCfgFilePath.replace("/", "\\"));
    // open read & write mode
    if (!floorCfgFile.open(QIODevice::ReadWrite|QIODevice::Truncate|QIODevice::Text))
    {
        // Fail to open file Message
        //QMessageBox::information(this, "uiMagician", "Fail to Open file");
        return;
        //return FAIL_TO_OPEN_FILE;
    }
    // Assign file to the stream
    floorCfgFileStream.setDevice(&floorCfgFile);




    /* set the Html socket configure file */
    if(houseFloor == MULTI_FLOOR_HOUSE)
    {
        FloorsSocketCfgFilePath = htmlFileDirectoryPath + "/multiFloorsSocketCfg.js";
    }
    else
    {
        FloorsSocketCfgFilePath = htmlFileDirectoryPath + "/singleFloorsSocketCfg.js";
    }
    //set the name of the file
    FloorsSocketCfgFile.setFileName(FloorsSocketCfgFilePath.replace("/", "\\"));
    // open read & write mode
    if (!FloorsSocketCfgFile.open(QIODevice::ReadWrite|QIODevice::Truncate|QIODevice::Text))
    {
        // Fail to open file Message
        //QMessageBox::information(this, "uiMagician", "Fail to Open file");
        return;
        //return FAIL_TO_OPEN_FILE;
    }
    // Assign file to the stream
    FloorsSocketCfgFileStream.setDevice(&FloorsSocketCfgFile);

    //create variables.xml file
    //set the name of the file
    xmlVariablesFilePath = htmlFileDirectoryPath + VARIABLES_FILE_NAME;
    xmlVariablesFile.setFileName(xmlVariablesFilePath.replace("/", "\\"));
    if(!xmlVariablesFile.open(QIODevice::ReadWrite|QIODevice::Truncate|QIODevice::Text))
    {
        // Fail to open file Message
        //QMessageBox::information(this, "uiMagician", "Fail to Open file - variables.xml");
        return;
        //return FAIL_TO_OPEN_FILE;
    }
    //QMessageBox::information(this, "uiMagician", xmlVariablesFilePath);
    xmlVariablesStream.setDevice(&xmlVariablesFile);
    xmlVariablesDomDocument.clear();
    //xmlVariablesDomDocument.setContent(&xmlVariablesFile);
    // Make the root element
    xmlVariablesRoot = xmlVariablesDomDocument.createElement(VARIABLES_ROOT_NAME);
    // Add root to the document
    xmlVariablesDomDocument.appendChild(xmlVariablesRoot);

    //create dm.xml file
    //set the name of the file
    xmlDmFilePath = htmlFileDirectoryPath + DM_FILE_NAME;
    xmlDmFile.setFileName(xmlDmFilePath.replace("/", "\\"));
    if(!xmlDmFile.open(QIODevice::ReadWrite|QIODevice::Truncate|QIODevice::Text))
    {
        // Fail to open file Message
        //QMessageBox::information(this, "uiMagician", "Fail to Open file - dm.xml");
        return;
        //return FAIL_TO_OPEN_FILE;
    }
    //QMessageBox::information(this, "uiMagician", xmlDmFilePath);
    xmlDmStream.setDevice(&xmlDmFile);
    xmlDmDomDocument.clear();
    //xmlDmDomDocument.setContent(&xmlDmFile);
    // Make the root element
    xmlDmRoot = xmlDmDomDocument.createElement(DM_ROOT_NAME);
    // Add root to the document
    xmlDmDomDocument.appendChild(xmlDmRoot);
}

//Create div fotter
void GenerateApp::createDivFotter(QDomElement &NodeElementChildTemp)
{
    nodeName = "div";
    NodeElementChildTemp  = htmlDomDocument.createElement(nodeName);
    NodeElementChildTemp.setAttribute("id","fotter");
    //NodeElement.
    if(houseFloor == MULTI_FLOOR_HOUSE)
    {
        stringTxtNode = VSCP_COPY_RIGHT_MULTI_FLOOR;
    }
    else
    {
        stringTxtNode = VSCP_COPY_RIGHT_SINGLE_FLOOR;
    }
    textNode = htmlDomDocument.createTextNode(stringTxtNode);
    NodeElementChildTemp.appendChild(textNode);

    //htmlRoot.appendChild(NodeElement);
}

// Create the HTML App
void GenerateApp::createHtmlApp()
{

    //check if single floor home
    verifyHouseFloor(housePacketList, list);

    //Create floor room list
    createFloorRoomList(housePacketList,xmlRootRef);

    // Create the General header for HTML
    createHtmlHead();
    // Create fllor configure file
    createFloorCfgFiles();
    // Create Html Body
    createHtmlBody();                     // --> todo
    // close java script configure files
    closeCfgfiles();
    //Close the HTML app
    closeHtmlFile();
}

//get total groups
//void GenerateApp::getTotalGroups(const QList<T_packetFloorNodes> &floorNodesList)
void GenerateApp::getTotalGroups(int index)
{
    QString deviceInfo;
    QDomNodeList listDevices;
    QDomNodeList listDeviceDetails;
    T_packetFloorNodes floorNodes;
    QDomNodeList listRooms;
    QDomNode tempNodeChild;

    // Initialise all the group total values
    houseNodesList[index].groupsTotal = 0;
    houseNodesList[index].lightsGroupTotal = 0;
    houseNodesList[index].accessoriesGroupTotal = 0;
    houseNodesList[index].blindDoorWindowGroupTotal = 0;
    houseNodesList[index].sensorGroupTotal = 0;
    houseNodesList[index].temperatureControllerGroupTotal = 0;

    //Get the Total number of groups
    for (int i = 0; i < houseNodesList.at(index).floorNodeList.size(); ++i)
    {
        floorNodes = houseNodesList.at(index).floorNodeList.at(i);

        //Load root nodes
        listRooms = floorNodes.floorRooms.childNodes();

        //QMessageBox::information(this, "uiMagician", QString::number(houseNodesList[index].blindDoorWindowGroupTotal));

        //get device group name in list
        for (int j = 0; j < listRooms.size(); ++j)
        {
            //read the child node from room list
            tempNodeChild = listRooms.at(j);

            // Create list of child nodes of - Every room
            listDevices = tempNodeChild.childNodes();

            for (int k = DEVICE_INDEX; k < listDevices.size(); ++k)
            {
                //read the Device child node from device list
                tempNodeChild = listDevices.at(k);
                // Create list nodes of - Every DEVICE
                listDeviceDetails = tempNodeChild.childNodes();

                //Get device Info node
                tempNodeChild = listDeviceDetails.at(DEVICE_INFO_INDEX);
                if (!tempNodeChild.isNull())
                {
                    deviceInfo = tempNodeChild.toElement().text();
                }
                else
                {
                    deviceInfo = "";
                }

                //QMessageBox::information(this, "uiMagician", "2");

                // If device type is light
                if(deviceInfo == DEVICE_INFO_TYPE_ONE)
                {
                    houseNodesList[index].lightsGroupTotal++;
                }
                else if (deviceInfo == DEVICE_INFO_TYPE_TWO)
                {
                    houseNodesList[index].accessoriesGroupTotal++;
                }
                else if (deviceInfo == DEVICE_INFO_TYPE_THREE)
                {
                    houseNodesList[index].blindDoorWindowGroupTotal++;
                }
                else if (deviceInfo == DEVICE_INFO_TYPE_FOUR)
                {
                    houseNodesList[index].sensorGroupTotal++;
                }
                else if (deviceInfo == DEVICE_INFO_TYPE_FIVE)
                {
                    houseNodesList[index].temperatureControllerGroupTotal++;
                }
                else
                {
                    //Do nothing
                }

                //QMessageBox::information(this, "uiMagician", "3");


            }
        }
    }

    //QMessageBox::information(this, "uiMagician", QString::number(houseNodesList[index].blindDoorWindowGroupTotal));

//QMessageBox::information(this, "uiMagician", "4");

    // Check which group to create
    if(houseNodesList[index].lightsGroupTotal>0)
    {
        houseNodesList[index].groupsTotal++;
        flagLightsGroup = 1;
    }
    if(houseNodesList[index].accessoriesGroupTotal>0)
    {
        houseNodesList[index].groupsTotal++;
        flagAccessoriesGroup = 1;
    }
    if(houseNodesList[index].blindDoorWindowGroupTotal>0)
    {
        houseNodesList[index].groupsTotal++;
        flagBlindDoorWindowGroup = 1;
    }
    if(houseNodesList[index].sensorGroupTotal>0)
    {
        houseNodesList[index].groupsTotal++;
        flagsensorGroup = 1;
    }
    if(houseNodesList[index].temperatureControllerGroupTotal>0)
    {
        houseNodesList[index].groupsTotal++;
        flagTemperatureControllerGroup = 1;
    }


}

void GenerateApp::on_okPushButton_clicked()
{

    // Create the HTML App - by default
    createHtmlApp();

    if(ui->mobileAppCheckBox->isChecked())
    {
        //Generate Mobile apps
    }

    // Update progress bar value
    ui->appGenerationProgressBar->setValue(100);

    // Add a delay
    SleepTimerDelay::sleep(1);

    // Close the Ui
    on_closePushButton_clicked();
}

void GenerateApp::on_htmlAppCheckBox_clicked()
{
    //set the check box by default
    ui->htmlAppCheckBox->setChecked(true);
}

void GenerateApp::on_closePushButton_clicked()
{
    emit close();

}

GenerateApp::~GenerateApp()
{
    delete ui;
}
