/**
 * @file ats_01.h
 * @author Robson Costa (robson.costa@ifsc.edu.br)
 * @brief AgroTechStation 01 general library.
 * @version 1.0.0
 * @since 2021-02-15 
 * @date 2021-02-15
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

/**
 * \def DEV_TYPE 
 * MCU device board.
 */
#define DEV_TYPE                        "Arduino Pro Mini Atmega328p 5V 16MHz"

/**
 * \def DEV_CONN 
 * Communication device board.
 */ 
#define DEV_CONN                        "LoRa - RHF76-052AM"

/**
 * \def DEV_FW_VERSION 
 * Firmware version.
 */
#define DEV_FW_VERSION                  "1.0.0"

/**
 * \def DEV_SENSOR_LIST 
 * List of sensors enabled in the station.
 */
#define DEV_SENSOR_LIST                 "DHT22, BH1750"

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
#endif

/**
 * \def DHT_TYPE 
 * DHT sensor type.
 */
#define DHT_TYPE                        DHT22

/**
 * \def DHT_PORT 
 * DHT22 sensor device port.
 */
#define DHT_PORT                        9

/**
 * \def UVM30A_PORT 
 * UVM30A sensor port.
 */
// #define UVM30A_PORT                     A0

// /**
//  * \def I2C_PORT 
//  * I2C port.
//  */
// #define I2C_PORT                        7

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
    uint8_t soil_moisture = 0;
    float soil_temperature = 0.0f;
    float battery = 0.0f;    
};

/*********************************************
 *            FUNCTION PROTOTYPES
 ********************************************/
#if (SERIAL_DEBUG == true)
    void printInitInfo();
#endif

/*********************************************
 *             SYSTEM VARIABLES
 ********************************************/
DHT_Unified dht(DHT_PORT, DHT_TYPE);        /**< Global variable to access DHT sensor. */
STATION_SENSORS_T sensorsValues;            /**< Global variable with sensor values. */
BH1750 lightSensor;                         /**< Global variable to access light sensor (GY-30). */
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