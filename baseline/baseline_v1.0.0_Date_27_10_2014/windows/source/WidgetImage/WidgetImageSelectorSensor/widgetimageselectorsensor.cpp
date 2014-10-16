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


#include "widgetimageselectorsensor.h"
#include "ui_widgetimageselectorsensor.h"

#include "../../uiMagicianConfiguration.h"

WidgetImageSelectorSensor::WidgetImageSelectorSensor( QString &imageData ,QWidget *parent) :
    QDialog(parent),
    imageDataRef(imageData),
    ui(new Ui::WidgetImageSelectorSensor)
{
    ui->setupUi(this);

    int selectTopItem;

    //Set columns count
    ui->WidgetImageSelectorSensorTreeWidget->setColumnCount(2);
    if(QTreeWidgetItem* header = ui->WidgetImageSelectorSensorTreeWidget->headerItem()) {
      header->setText(0, SET_COLUMN_ZERO_HEADER_TEXT_SENSOR);
      header->setText(1, SET_COLUMN_ONE_HEADER_TEXT_SENSOR);
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
        selectTopItem = 0u;
    }

    // Select the top level Item
    ui->WidgetImageSelectorSensorTreeWidget->setCurrentItem(ui->WidgetImageSelectorSensorTreeWidget->topLevelItem(selectTopItem));

}

WidgetImageSelectorSensor::~WidgetImageSelectorSensor()
{
    delete ui;
}

void WidgetImageSelectorSensor::AddRoot()
{
    QList<QTreeWidgetItem *> items;
    QTreeWidgetItem *newItem;
    QString imageSensor;
    QString imageText = "94";
    //QMessageBox *msgBox 	= new QMessageBox();

    QSize t2(10, 12);
    t2.scale(60, 60, Qt::KeepAspectRatio);

   //for (int i = 1; i < 96; ++i)
    for (int i = 0; i <= 57; ++i)
    {
        switch ( i ) {

            case 0:
               imageSensor = ":/Images/Images/measurement/length.jpg";
               imageText  = VSCP_TYPE_MEASUREMENT_GENERAL;
               break;

            case 1:
                imageSensor = ":/Images/Images/measurement/count.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_COUNT_I;
                break;

            case 2:
                imageSensor = ":/Images/Images/measurement/length.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_LENGTH;
                break;

            case 3:
                imageSensor = ":/Images/Images/measurement/mass.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_MASS;
                break;

           case 4:
                imageSensor = ":/Images/Images/measurement/time.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_TIME;
                break;

            case 5:
                imageSensor = ":/Images/Images/measurement/electric_current.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_ELECTRIC_CURRENT;
                break;

            case 6:
                imageSensor = ":/Images/Images/measurement/temprature.png";
                imageText  = VSCP_TYPE_MEASUREMENT_TEMPERATURE;
                break;

            case 7:
                imageSensor = ":/Images/Images/measurement/amount_of_substance.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_AMOUNT_OF_SUBSTANCE;
                break;

            case 8:
                imageSensor = ":/Images/Images/measurement/intensity_of_light.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_INTENSITY_OF_LIGHT;
                break;

            case 9:
                imageSensor = ":/Images/Images/measurement/frequency.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_FREQUENCY;
                break;

            case 10:
                imageSensor = ":/Images/Images/measurement/radioactivity.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_RADIOACTIVITY;
                break;

            case 11:
                imageSensor = ":/Images/Images/measurement/force.png";
                imageText  = VSCP_TYPE_MEASUREMENT_FORCE;
                break;

            case 12:
                imageSensor = ":/Images/Images/measurement/pressure.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_PRESSURE;
                break;

            case 13:
                imageSensor = ":/Images/Images/measurement/energy.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_ENERGY;
                break;

            case 14:
                imageSensor = ":/Images/Images/measurement/power.png";
                imageText  = VSCP_TYPE_MEASUREMENT_POWER;
                break;

            case 15:
                imageSensor = ":/Images/Images/measurement/electrical_charge.png";
                imageText  = VSCP_TYPE_MEASUREMENT_ELECTRICAL_CHARGE;
                break;

            case 16:
                imageSensor = ":/Images/Images/measurement/electrical_potential_voltage.png";
                imageText  = VSCP_TYPE_MEASUREMENT_ELECTRICAL_POTENTIAL;
                break;

            case 17:
                imageSensor = ":/Images/Images/measurement/electrical_capacitance.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_ELECTRICAL_CAPACITANCE;
                break;

            case 18:
                imageSensor = ":/Images/Images/measurement/electrical_resistance.png";
                imageText  = VSCP_TYPE_MEASUREMENT_ELECTRICAL_RESISTANCE;
                break;

            case 19:
                imageSensor = ":/Images/Images/measurement/electrical_conductance.png";
                imageText  = VSCP_TYPE_MEASUREMENT_ELECTRICAL_CONDUCTANCE;
                break;

            case 20:
                imageSensor = ":/Images/Images/measurement/electrical_magnetic_field.png";
                imageText  = VSCP_TYPE_MEASUREMENT_MAGNETIC_FIELD_STRENGTH;
                break;

            case 21:
                imageSensor = ":/Images/Images/measurement/electrical_magnetic_flux.png";
                imageText  = VSCP_TYPE_MEASUREMENT_MAGNETIC_FLUX;
                break;

            case 22:
                imageSensor = ":/Images/Images/measurement/electrical_magnetic_flux_density.png";
                imageText  = VSCP_TYPE_MEASUREMENT_MAGNETIC_FLUX_DENSITY;
                break;

            case 23:
                imageSensor = ":/Images/Images/measurement/electrical_inductance.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_INDUCTANCE;
                break;

            case 24:
                imageSensor = ":/Images/Images/measurement/flux.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_FLUX_OF_LIGHT;
                break;

            case 25:
                imageSensor = ":/Images/Images/measurement/illuminance.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_ILLUMINANCE;
                break;

            case 26:
                imageSensor = ":/Images/Images/measurement/dose.png";
                imageText  = VSCP_TYPE_MEASUREMENT_RADIATION_DOSE;
                break;

            case 27:
                imageSensor = ":/Images/Images/measurement/catalyst.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_CATALYTIC_ACITIVITY;
                break;

            case 28:
                imageSensor = ":/Images/Images/measurement/volume.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_VOLUME;
                break;

            case 29:
                imageSensor = ":/Images/Images/measurement/sound_intensity.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_SOUND_INTENSITY;
                break;

            case 30:
                imageSensor = ":/Images/Images/measurement/angle.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_ANGLE;
                break;

            case 31:
                imageSensor = ":/Images/Images/measurement/position.png";
                imageText  = VSCP_TYPE_MEASUREMENT_POSITION;
                break;

            case 32:
                imageSensor = ":/Images/Images/measurement/speed.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_SPEED;
                break;

            case 33:
                imageSensor = ":/Images/Images/measurement/acceleration.png";
                imageText  = VSCP_TYPE_MEASUREMENT_ACCELERATION;
                break;

            case 34:
                imageSensor = ":/Images/Images/measurement/tension.png";
                imageText  = VSCP_TYPE_MEASUREMENT_TENSION;
                break;

            case 35:
                imageSensor = ":/Images/Images/measurement/humidity.png";
                imageText  = VSCP_TYPE_MEASUREMENT_HUMIDITY;
                break;

            case 36:
                imageSensor = ":/Images/Images/measurement/flowmeter.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_FLOW;
                break;

            case 37:
                imageSensor = ":/Images/Images/measurement/thermal_resistance.png";
                imageText  = VSCP_TYPE_MEASUREMENT_THERMAL_RESISTANCE;
                break;

            case 38:
                imageSensor = ":/Images/Images/measurement/refractive_power.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_REFRACTIVE_POWER;
                break;

            case 39:
                imageSensor = ":/Images/Images/measurement/viscosity.png";
                imageText  = VSCP_TYPE_MEASUREMENT_DYNAMIC_VISCOSITY;
                break;

            case 40:
                imageSensor = ":/Images/Images/measurement/sound_impedance.png";
                imageText  = VSCP_TYPE_MEASUREMENT_SOUND_IMPEDANCE;
                break;

            case 41:
                imageSensor = ":/Images/Images/measurement/sound_resistance.png";
                imageText  = VSCP_TYPE_MEASUREMENT_SOUND_RESISTANCE;
                break;

            case 42:
                imageSensor = ":/Images/Images/measurement/Electric_elasticity.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_ELECTRIC_ELASTANCE;
                break;

            case 43:
                imageSensor = ":/Images/Images/measurement/luminous_energy.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_LUMINOUS_ENERGY;
                break;

            case 44:
                imageSensor = ":/Images/Images/measurement/luminance.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_LUMINANCE;
                break;

            case 45:
                imageSensor = ":/Images/Images/measurement/chemical_concentration.png";
                imageText  = VSCP_TYPE_MEASUREMENT_CHEMICAL_CONCENTRATION;
                break;

            case 46:
                imageSensor = ":/Images/Images/measurement/reserved.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_RESERVED;
                break;

            case 47:
                imageSensor = ":/Images/Images/measurement/dose.png";
                imageText  = VSCP_TYPE_MEASUREMENT_DOSE_EQVIVALENT;
                break;

            case 48:
                imageSensor = ":/Images/Images/measurement/reserved.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_RESERVED_48;
                break;

            case 49:
                imageSensor = ":/Images/Images/measurement/dewpoint.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_DEWPOINT;
                break;

            case 50:
                imageSensor = ":/Images/Images/measurement/relative_level.png";
                imageText  = VSCP_TYPE_MEASUREMENT_RELATIVE_LEVEL;
                break;

            case 51:
                imageSensor = ":/Images/Images/measurement/altitude.png";
                imageText  = VSCP_TYPE_MEASUREMENT_ALTITUDE;
                break;

            case 52:
                imageSensor = ":/Images/Images/measurement/area.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_AREA;
                break;

            case 53:
                imageSensor = ":/Images/Images/measurement/radiant_intensity.png";
                imageText  = VSCP_TYPE_MEASUREMENT_RADIANT_INTENSITY;
                break;

            case 54:
                imageSensor = ":/Images/Images/measurement/radiance.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_RADIANCE;
                break;

            case 55:
                imageSensor = ":/Images/Images/measurement/irradiance.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_IRRADIANCE;
                break;

            case 56:
                imageSensor = ":/Images/Images/measurement/spectral_radiance.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_SPECTRAL_RADIANCE;
                break;

            case 57:
                imageSensor = ":/Images/Images/measurement/spectral_irradiance.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_SPECTRAL_IRRADIANCE;
                break;

            default:
                imageSensor = ":/Images/Images/measurement/reserved.jpg";
                imageText  = VSCP_TYPE_MEASUREMENT_RESERVED;
                break;
        }

        newItem = new  QTreeWidgetItem(ui->WidgetImageSelectorSensorTreeWidget);
        newItem->setIcon(0, QIcon(imageSensor));
        newItem->setText(1, imageText);
        items.append(newItem);
        //ui->WidgetImageSelectorTreeWidget->insertTopLevelItem(i,newItem);
    }
    ui->WidgetImageSelectorSensorTreeWidget->insertTopLevelItems(0,items);
    ui->WidgetImageSelectorSensorTreeWidget->setIconSize(t2/*QSize(80,48)*/);
    //ui->WidgetImageSelectorTreeWidget->expandAll();

    //imageData = "test";
}

void WidgetImageSelectorSensor::on_WidgetImageSelectorSensorPushButtonOk_clicked()
{
    int currentNum = ui->WidgetImageSelectorSensorTreeWidget->currentIndex().row() + 1u;

    imageDataRef = QString::number(currentNum);

    //Emit a close handler
    emit close();
}
