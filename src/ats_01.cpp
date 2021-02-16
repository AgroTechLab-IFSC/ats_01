/**
 * @mainpage
 * The ATS-01 (<i>AgroTechStation 01</i>) is a tiny agricultural station that can be connected to AgroTech4All infrastructure.\n
 * <a href="https://agrotechlab.lages.ifsc.edu.br/agrotech4all.html">AgroTech4All</a> is a solution developed by 
 * <a href="https://agrotechlab.lages.ifsc.edu.br/">AgroTechLab</a> from <a href="https://www.ifsc.edu.br/web/campus-lages">IFSC (Instituto 
 * Federal de Santa Catarina)</a> at Lages/SC - Brazil. It allows remote monitoring of the microclimate existing in the plantations periodically
 * sending to a server agricultural data collected by sensors installed into field stations. These stations send their data to a gateway 
 * using the LoRa&trade; communication protocol. The gateway forwards this data (through the Internet) AgroTech4All server.\n
 * 
 * This documentation details the hardware and firmware used in this stations.\n
 * It is based on \subpage promini_page MCU board and is equipped with the following devices:\n
 * \li \subpage rhf0m003_page - LoRaWAN module
 * \li \subpage dht22_page - air temperature and air humidity sensor
 * \li \subpage gy302_page - lighting level sensor module
 * \li \subpage uvm30a_page - ultraviolet (UV) radiation index module
 */

/**
 * \page promini_page Arduino Pro Mini
 * The Arduino Pro Mini is a microcontroller board based on the ATmega328p. It has 14 digital input/output pins (of which 6 can be used
 * as PWM outputs), 6 analog inputs, an on-board resonator, a reset button, and holes for mounting pin headers. A six pin header can be
 * connected to an FTDI cable or Sparkfun breakout board to provide USB power and communication to the board. The Arduino Pro Mini is
 * intended for semi-permanent installation in objects or exhibitions. The board comes without pre-mounted headers, allowing the use
 * of various types of connectors or direct soldering of wires. The pin layout is compatible with the Arduino Mini. There are two
 * version of the Pro Mini. One runs at 3.3V and 8 MHz, the other at 5V and 16 MHz. 
 * 
 * ATmega328p key features are listed below, details can be found into [datasheet](../datasheets/ATmega328p.pdf):
 * - ATmega328p
 *  - RISC 8-bit MCU;
 *  - 8 MHz maximum frequency (3.3V versions) and 16 MHz maximum frequency (5V versions); 
 * - Memories
 *  - 32 KBytes of flash memory of which 2 KBytes are used by bootloader;
 *  - 2 KBytes of SRAM;
 * - Power supply
 *  - Circuit operating voltage 3.3V or 5V (depending on model)
 *  - Board power supply 3.35V - 12V (3.3V model) or 5 - 12V (5V model)
 * - Digitial I/O pins
 *  - 14 digital I/O pins;
 *  - 6 PWMs pins;
 *  - 40 mA D/C current per I/O pin;
 * - 6 analog input pins;
 * - 2 external interrupts;
 * - Up to 3 communication interfaces
 *  - 1 I2C interface;
 *  - 1 UART;
 *  - 1 SPI;
 * 
 * ![Arduino Pro Mini board pinout](../arduino_promini_pinout.jpg)
 */

/**
 * \page rhf0m003_page RHF0M003
 * This UV Sensor is used for detecting the intensity of incident ultraviolet (UV) radiation. 
 * This form of electromagnetic radiation has shorter wavelengths than visible radiation. 
 * This module is based on the sensor UVM-30A, which has a wide spectral range of 200nm–370nm. 
 * The module outputs electrical signal which varies with the UV intensity.
 *  
 * Key features are listed below, hardware details can be found into [datasheet](../UVM30A_datasheet.pdf):
 * - Power supply 5V;
 * - Analogic interface;
 * 
 * UV index table:\n
 * Tension (mV) | Analog | UV Index
 * :----:|:----:| :----:
 * < 50 | < 10 | 0
 * 227 | 46 | 1
 * 318 | 65 | 2
 * 408 | 83 | 3
 * 503 | 103 | 4
 * 606 | 124 | 5
 * 696 | 142 | 6
 * 795 | 162 | 7
 * 881 | 180 | 8
 * 976 | 200 | 9
 * 1079 | 221 | 10
 * 1170+ | 240+ | 11+
 * 
 * ![UVM-30A schematic connection](../uvm30a.png)
 */ 

/**
 * \page dht22_page DHT22
 * This UV Sensor is used for detecting the intensity of incident ultraviolet (UV) radiation. 
 * This form of electromagnetic radiation has shorter wavelengths than visible radiation. 
 * This module is based on the sensor UVM-30A, which has a wide spectral range of 200nm–370nm. 
 * The module outputs electrical signal which varies with the UV intensity.
 *  
 * Key features are listed below, hardware details can be found into [datasheet](../UVM30A_datasheet.pdf):
 * - Power supply 5V;
 * - Analogic interface;
 * 
 * UV index table:\n
 * Tension (mV) | Analog | UV Index
 * :----:|:----:| :----:
 * < 50 | < 10 | 0
 * 227 | 46 | 1
 * 318 | 65 | 2
 * 408 | 83 | 3
 * 503 | 103 | 4
 * 606 | 124 | 5
 * 696 | 142 | 6
 * 795 | 162 | 7
 * 881 | 180 | 8
 * 976 | 200 | 9
 * 1079 | 221 | 10
 * 1170+ | 240+ | 11+
 * 
 * ![DHT22 pinout](../dht22_pinout.jpg)
 */ 

/**
 * \page gy302_page GY30/GY302
 * GY30 and GY302 modules are based on BH1750FVI that is an digital Ambient Light Sensor IC for I²C bus interface. This IC is most suitable
 * to obtain the ambient light data for adjusting LCD and Keypad backlight power of mobile phones. It is possible to detect wide range
 * at high resolution (1 .. 65535 lux).
 *  
 * Key features are listed below, BH1750FVI details can be found into [datasheet](../datasheets/BH1750FVI.pdf):
 * - Power supply 3.3V - 5V;
 * - I2C interface;
 * - 16 bits ADC;
 * - 1 - 65535 lux;
 * - Spectral responsibility is approximately human eye response;
 * - 50Hz/60Hz light noise reject-function;
 * 
 * ![GY30 pinout](../gy30_pinout.jpg)
 * ![GY302 pinout](../gy302_pinout.jpg)
 */ 

/**
 * \page uvm30a_page UVM-30A
 * This UV Sensor is used for detecting the intensity of incident ultraviolet (UV) radiation. 
 * This form of electromagnetic radiation has shorter wavelengths than visible radiation. 
 * This module is based on the sensor UVM-30A, which has a wide spectral range of 200nm–370nm. 
 * The module outputs electrical signal which varies with the UV intensity.
 *  
 * Key features are listed below, hardware details can be found into [datasheet](../datasheets/UVM30A.pdf):
 * - Power supply 5V;
 * - Analogic interface;
 * 
 * UV index table:\n
 * Tension (mV) | Analog | UV Index
 * :----:|:----:| :----:
 * < 50 | < 10 | 0
 * 227 | 46 | 1
 * 318 | 65 | 2
 * 408 | 83 | 3
 * 503 | 103 | 4
 * 606 | 124 | 5
 * 696 | 142 | 6
 * 795 | 162 | 7
 * 881 | 180 | 8
 * 976 | 200 | 9
 * 1079 | 221 | 10
 * 1170+ | 240+ | 11+
 * 
 * ![UVM-30A pinout](../uvm30_pinout.png)
 */ 

/** 
 * @file ats_01.cpp
 * @author Robson Costa (robson.costa@ifsc.edu.br)
 * @brief Project main file.
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
#include <Arduino.h>
#include "ats_01.h"

/**
 * @fn setup
 * @brief Configure all parameters before call loop function.
 */
void setup() {
  // If LED BUILTIN enabled, configure and power on
  #if (LED_BUILTIN_ENABLED == true)
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
  #endif

  // If SERIAL_DEBUG enabled, configure serial port for debug
  #if (SERIAL_DEBUG == true)
    Serial.begin(SERIAL_BAUDRATE);
    while (!Serial) {;}
    printInitInfo();
  #endif

  // Setup and initialize DHT22 sensor
  pinMode(DHT_PORT, INPUT);  
  if (SERIAL_DEBUG) {
    Serial.print("\n\tInitializing DHT sensor... ");
    Serial.flush();
  }
  dht.begin();
  if (SERIAL_DEBUG) {
    Serial.print("[OK]");
    Serial.flush();
  }

  // // Initialize light sensor
  // if (SERIAL_DEBUG) {
  //   Serial.print("\n\tInitializing light sensor... ");
  //   Serial.flush();
  // }
  // lightSensor.begin();
  // if (SERIAL_DEBUG) {
  //   Serial.print("[OK]");
  //   Serial.flush();
  // }

  // Power off builtin LED after setup process
  digitalWrite(LED_BUILTIN, LOW);
}

/**
 * @fn loop
 * @brief Loop function executed cyclically based on the value of \ref system_period.
 */
void loop() {
  // Power on builtin LED during reading process
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.print("\nReading sensors....");
  dht.temperature().getSensor(&dht_sensor);
  dht.temperature().getEvent(&dht_sensor_event);
  if ((isnan(dht_sensor_event.temperature) || (dht_sensor_event.temperature < -40.0f) ||
      (dht_sensor_event.temperature > 80.0f))) {
      sensorsValues.air_temperature = __FLT_MAX__;
    if (SERIAL_DEBUG == true) {
      Serial.print("\n\tError reading air temperature!!!");
      Serial.flush();
    }  
  } else {
    sensorsValues.air_temperature = dht_sensor_event.temperature;
    if (SERIAL_DEBUG == true) {
        Serial.print("\n\tAir temperature (in oC): ");
        Serial.print(sensorsValues.air_temperature);        
        Serial.flush();
    }
  }

  dht.humidity().getSensor(&dht_sensor);
  dht.humidity().getEvent(&dht_sensor_event);
  if ((isnan(dht_sensor_event.relative_humidity)) || (dht_sensor_event.relative_humidity < 0.0f) ||
    (dht_sensor_event.relative_humidity > 100.0f)) {
    sensorsValues.air_humidity = __FLT_MAX__;      
    if (SERIAL_DEBUG == true) {
      Serial.print("\n\tError reading air humidity!!!");
      Serial.flush();
    }  
  } else {
    sensorsValues.air_humidity = dht_sensor_event.relative_humidity;
    if (SERIAL_DEBUG == true) {
      Serial.print("\n\tAir humidity (in %): ");
      Serial.print(sensorsValues.air_humidity);      
      Serial.flush();
    }
  }

  // uint16_t lux = lightSensor.readLightLevel();    
  // if ((isnan(lux)) || (lux < 0.0f) || (lux > 65535) ) {
  //   sensorsValues.light = UINT16_MAX;
  //   if (SERIAL_DEBUG == true) {
  //     Serial.print("\n\tError reading light level!!!");
  //     Serial.flush();
  //   }  
  // } else {
  //   sensorsValues.light = lux;
  //   if (SERIAL_DEBUG == true) {
  //     Serial.print("\n\tLuminosity (in LUX): ");  
  //     Serial.print(sensorsValues.light);        
  //     Serial.flush();
  //   }
  // }
  
  // Get UV sensor value and compute in milivolts
  //int uv_value = (analogRead(UVM30A_PORT) * (5.0 / 1023.0)) * 1000;
  uint16_t uv_value = analogRead(UVM30A_PORT);
  if (isnan(uv_value)) {
    if (SERIAL_DEBUG == true) {
      Serial.print("\n\tError reading UV radiation index!!!");
      Serial.flush();
    }  
  } else {
    if (uv_value > 1170) {
      sensorsValues.uv_index = 12;
    } else {
      for (int i = 0; i < 12; i++) {
        if (uv_value <= uvIndexValue[i]) {
          sensorsValues.uv_index = i;
          break;
        }
      }
    }
    if (SERIAL_DEBUG == true) {
      Serial.print("\n\tUV radiation (in UV index): ");
      Serial.print(uv_value);
      Serial.print(" => ");
      Serial.print(sensorsValues.uv_index);
      Serial.flush();
    }
  } 

  // Power off builtin LED after reading process
  digitalWrite(LED_BUILTIN, LOW);

  // Sleep 5 seconds
  delay(5000);
}

#if (SERIAL_DEBUG == true)
/**
 * @fn    printInitInfo()
 * @brief Print weather station initial information.
 * 
 */
void printInitInfo() {
  Serial.print("\n##########################################\n");
  Serial.print("#                ATS-01                  #\n");
  Serial.print("#   AgroTech Station 01 (Tiny version)   #\n");
  Serial.print("#        AgroTechLab (IFSC/Lages)        #\n");  
  Serial.print("##########################################\n");
  Serial.print("Starting ATS-01...");
  Serial.print("\n\tMCU device board......: ");
  Serial.print(DEV_TYPE);
  Serial.print("\n\tCommunication device..: ");
  Serial.print(DEV_CONN);
  Serial.print("\n\tFirmware version......: ");
  Serial.print(DEV_FW_VERSION);
  Serial.print("\n\tSensor list...........: ");
  Serial.print(DEV_SENSOR_LIST);
  Serial.print("\n\tActuator list.........: ");
  Serial.print(DEV_ACTUATOR_LIST);
  Serial.flush();
}
#endif