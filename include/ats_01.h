/**
 * @file ats_01.h
 * @author Robson Costa (robson.costa@ifsc.edu.br)
 * @brief AgroTechStation 01 general library.
 * @version 0.1.0
 * @since 2021-02-15 
 * @date 2021-02-16
 * 
 * @copyright Copyright (c) 2021 - Robson Costa\n
 * Licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Unported License (the <em>"License"</em>). 
 * You may not use this file except in compliance with the License. You may obtain a copy of the License at 
 * \url{https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode}. Unless required by applicable law or agreed to in writing,  
 * software distributed under the License is distributed on an <em>"as is" basis, without warranties or 
 * conditions of any kind</em>, either express or implied. See the License for the specific language governing 
 * permissions and limitations under the License.
 */
#ifndef __ATS_01_H__
#define __ATS_01_H__

#include <DHT_U.h>
#include <Adafruit_Sensor.h>
#include <BH1750.h>
#include <SoftwareSerial.h>
#include "AgroTechLab_LoRa.h"

/**
 * \def DEV_TYPE 
 * MCU device board.
 */
#define DEV_TYPE                        "Arduino Pro Mini Atmega328p 5V 16MHz"

/**
 * \def DEV_CONN 
 * Communication device board.
 */ 
#define DEV_CONN                        "LoRa - RHF0M003"

/**
 * \def DEV_FW_VERSION 
 * Firmware version.
 */
#define DEV_FW_VERSION                  "0.1.0"

/**
 * \def DEV_SENSOR_LIST 
 * List of sensors enabled in the station.
 */
#define DEV_SENSOR_LIST                 "DHT22, GY30, UVM30A"

/**
 * \def DEV_ACTUATOR_LIST 
 * List of actuators enabled in the station.
 */
#define DEV_ACTUATOR_LIST               "none"

/**
 * \def SERIAL_DEBUG 
 * Enable/disable derial debug.
 */
#define SERIAL_DEBUG                    true

/**
 * \def LED_BUILTIN_ENABLED 
 * Enable/disable LED built-in.
 */
#define LED_BUILTIN_ENABLED             true

#if (SERIAL_DEBUG == true)
    /**
    * \def SERIAL_BAUDRATE 
    * Define the serial baudrate.
    */
    #define SERIAL_BAUDRATE             115200

    /**
    * \def SERIAL_RX_PIN 
    * Define the serial RX pin.
    */
    #define SERIAL_RX_PIN               4

    /**
    * \def SERIAL_TX_PIN 
    * Define the serial TX pin.
    */
    #define SERIAL_TX_PIN               5
#endif

/**
 * \def LORA_RX_PIN 
 * Define the LoRa module RX pin.
 */
#define LORA_RX_PIN                   6

/**
 * \def LORA_TX_PIN 
 * Define the LoRa module TX pin.
 */
#define LORA_TX_PIN                   7

/**
 * \def DHT_TYPE 
 * DHT sensor type.
 */
#define DHT_TYPE                        DHT22

/**
 * \def DHT_PIN 
 * DHT22 sensor device pin.
 */
#define DHT_PIN                         9

/**
 * \def UVM30A_PIN 
 * UVM30A sensor pin.
 */
#define UVM30A_PIN                      A0

/**
 * \def VOLTAGE_SENSOR_PIN 
 * Voltage sensor pin.
 */
#define VOLTAGE_SENSOR_PIN              A1


/*********************************************
 *               DATA STRUCTS
 ********************************************/
/**
 * \def STATION_SENSORS_T 
 * Struct with sensor data.
 */
struct STATION_SENSORS_T {
    float air_temperature = 0.0f;
    float air_humidity = 0.0f;    
    uint16_t light = 0;    
    uint8_t uv_index = 0;
    float battery_voltage = 0.0f;    
};

/*********************************************
 *            FUNCTION PROTOTYPES
 ********************************************/
#if (SERIAL_DEBUG == true)
    void printInitInfo();
#endif
float getAirTemperatureInC();
float getAirHumidity();
uint16_t getLightInLux();
uint8_t getUVIndex();
float getBatteryVoltage();

/*********************************************
 *             SYSTEM VARIABLES
 ********************************************/
STATION_SENSORS_T sensorsData;                          /**< Global variable with sensor values. */
DHT_Unified dht(DHT_PIN, DHT_TYPE);                     /**< Global variable to access DHT sensor (DHT22). */
BH1750 lightSensor;                                     /**< Global variable to access light sensor (GY30). */
sensor_t dht_sensor;                                    /**< Global variable to access DHT sensor internal values. */
sensors_event_t dht_sensor_event;                       /**< Global variable to access DHT sensor internal events. */
LoRa lora;                                              /**< Global variable to access LoRaWAN module. */
LoRaConfig_t loraCfg;                                   /**< Global variable with LoRa configurations. */
SoftwareSerial loraSerial(LORA_RX_PIN, LORA_TX_PIN);    /**< Software Serial for LoRa module communication. */
#if (SERIAL_DEBUG == true)
    SoftwareSerial debugSerial(SERIAL_RX_PIN, SERIAL_TX_PIN);   /**< Software Serial for DEBUG. */
#endif

/*********************************************
 *             SYSTEM CONSTANTS
 ********************************************/
const float voltageSensor_R1 = 6800.0;     /**< Voltage sensor resistor 1. */
const float voltageSensor_R2 = 4700.0;     /**< Voltage sensor resistor 2. */
const uint16_t uvIndexValue [12] = { 50, 227, 318, 408, 503, 606, 696, 795, 881, 976, 1079, 1170};
// const unsigned long system_period = 1000;   /**< System run period (in ms). */
// const unsigned long sampling_period = 2 * 60 * system_period;   /**< Sampling period (in ms). */
// const unsigned long error_reset_period = 60 * system_period;   /**< Error reset period (in ms). */

/*********************************************
 *             LORA VARIABLES
 ********************************************/
const char* chan0_freq = "917.2";                           /**< Channel 0 frequency operation. */
const char* chan1_freq = "917.9";                           /**< Channel 1 frequency operation. */
const char* rxwin2_freq = "923.3";                          /**< Receive window 2 frequency operation. */
const char* repeat = "2";                                   /**< Repeat times for unconfirmed messages. */
const char* retry = "3";                                    /**< Retry times for confirmed messages. */

/*********************************************
 *             TTN VARIABLES
 ********************************************/
const char* dev_eui = "00B07C58D5CC67B0";                   /**< Device EUI for TTN network. */
const char* app_eui = "70B3D57ED0025F6D";                   /**< Application EUI for TTN network. */
const char* app_key = "342B90970C79EA3D162DD6DB4FD130CA";   /**< Application Key for TTN network. */
const char* apps_key = "AD9FA1750D8C3106A64B49D2B0AE283E";  /**< Application Session Key for TTN network. */
const char* nwks_key = "97DF737CF57133D49E62595BD6526136";  /**< Network Session Key for TTN network. */ 
const char* dev_addr = "260318EA";                          /**< Device address for TTN network. */

#endif // __ATS_01_H__