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
 * \li \subpage ds18b20_page - soil temperature
 * \li \subpage hd38_page - soil moisture
 * <br> 
 * | Device  | Op. Voltage | Interface | Default Current                          | Response Time | Op. Temp.      |
 * | :----:  | :----:      | :----:    | :----:                                   | :----:        | :----:         |
 * | DHT-22  | 3V -- 5V    | UART      | 2.5 mA <run_mode> / 0.15 mA <sleep_mode> | 2 sec.        | -40°C -- 85°C  |
 * | GY-302  | 3V -- 5V    | I2C       | 0.18 mA                                  | 180 ms        | -40°C -- 85°C  |
 * | UVM-30A | 3V -- 5V    | Analog    | 0.06 mA                                  | < 0.5 sec.    | -25°C -- 85°C  |
 * | DS18B20 | 3V -- 5V    | 1-Wire    | --                                       | < 750 ms      | -55°C -- 125°C |
 * | HD-38   | 3V -- 12V   | Analog    | < 20 mA                                  | --            | --             |
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
 * RHF0M003 LoRaWAN® Module is a low cost, low power and ultra-small size module, embedded with Semtech’s LoRa® propriety chip SX127x and 
 * ST’s ultra-low power MCU STM32L07x. RHF0M003 LoraWAN® module is targeted application at wireless sensor network，AMR, wearable devices 
 * and others IoT devices powered by battery which need low power consumption to extend the battery life.
 *  
 * Key features are listed below:
 * - Low Power Consumption: 1.4uA Sleep Current In WOR Mode;
 * - Ultra Small Size: 14mm X 20mm
 * - 18 Pins SMT Package;
 * - Operating Frequency Band Option;
 * - High Performance，Suitable For Long Range;
 * - User-Friendly Interface LPUART / USART / I2C / USB 2×ADC 10×GPIOs;
 * - Support Global LoRaWAN® Protocol;
 * 
 * Documentation:\n
 * - [Design guide v2.0](../datasheets/RHF0M003_design_guide_v2.0.pdf)
 * - [Datasheet v1.2](../datasheets/RHF0M003_datasheet_v1.2.pdf)
 * - [Product brief v2.1](../datasheets/RHF0M003_product_brief_v2.1.pdf)
 * - [AT Command Specification v1.2](../datasheets/RHF0M003_at_command_spec_v1.2.pdf)
 * 
 * ![RHF0M003 pinout 1](../rhf0m003_pinout1.png)
 * ![RHF0M003 pinout 2](../rhf0m003_pinout2.png)
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
 * \page ds18b20_page DS18B20
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
 * \page hd38_page HD-38
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
    debugSerial.begin(SERIAL_BAUDRATE);
    while (!debugSerial) {;}
    printInitInfo();
  #endif

  // Setup and initialize DHT22 sensor
  pinMode(DHT_PIN, INPUT);  
  #if (SERIAL_DEBUG == true)
    debugSerial.print(F("\n\tInitializing DHT sensor... "));
    debugSerial.flush();
  #endif
  dht.begin();
  #if (SERIAL_DEBUG == true)
    debugSerial.print(F("[OK]"));
    debugSerial.flush();
  #endif

  // Initialize light sensor
  if (SERIAL_DEBUG) {
    debugSerial.print(F("\n\tInitializing light sensor... "));
    debugSerial.flush();
  }
  // lightSensor.begin();
  if (SERIAL_DEBUG) {
    debugSerial.print(F("[OK]"));
    debugSerial.flush();
  }

  // Setup LoRa module configuration
  loraCfg.band = AU920;
  loraCfg.op_class = A;
  loraCfg.tx_power = dBm14;
  loraCfg.uplink_dr = DR0;
  loraCfg.chan0_freq = chan0_freq;
  loraCfg.chan0_dr = DR0;
  loraCfg.chan1_freq = chan1_freq;
  loraCfg.chan1_dr = DR0;
  loraCfg.rxwin2_freq = rxwin2_freq;
  loraCfg.rxwin2_dr = DR8;
  loraCfg.adr = OFF;
  loraCfg.auth_mode = LWABP;
//  loraCfg.auth_mode = LWOTAA;
  loraCfg.dev_eui = dev_eui;
  loraCfg.app_eui = app_eui;
  loraCfg.repeat = repeat;
  loraCfg.retry = retry;
  loraCfg.dev_addr = dev_addr;
  loraCfg.app_key = app_key;
  loraCfg.apps_key = apps_key;
  loraCfg.nwks_key = nwks_key;
  loraCfg.debug = SERIAL_DEBUG;

  // Initiate LoRa modem
  // if (lora.initModem(loraCfg) == false) {
  //   // Put station in ERROR mode
  //   // Power on RGB LED during setup process
  //   rgb_led.on(Color(255,0,0));
  //   delay(error_reset_period);
  //   setup();
  // }

  // Power off builtin LED after setup process
  digitalWrite(LED_BUILTIN, LOW);
}

/**
 * @fn loop
 * @brief Loop function executed cyclically based on the value of \ref system_period.
 */
void loop() {
  #if (SERIAL_DEBUG == true)
    debugSerial.print(F("\nReading sensors...."));
    
    // Get time at start of process
    unsigned long start_time = millis();
  #endif  

  // Power on builtin LED during reading process
  digitalWrite(LED_BUILTIN, HIGH);

  // // Get air temperature
  sensorsData.air_temperature = getAirTemperatureInC();

  // // Get air humidity
  sensorsData.air_humidity = getAirHumidity();

  // // Get light in LUX
  sensorsData.light = getLightInLux();

  // // Get UV index
  sensorsData.uv_index = getUVIndex();

  // // Get battery voltage
  sensorsData.battery_voltage = getBatteryVoltage();  

  // Power off builtin LED after reading process
  digitalWrite(LED_BUILTIN, LOW);

  #if (SERIAL_DEBUG == true)
    // Get time at end of process
    unsigned long end_time = millis();

    debugSerial.print(F("\nProcess time (in ms): "));
    debugSerial.print(end_time - start_time);
  #endif  

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
  debugSerial.print(F("\n##########################################\n"));
  debugSerial.print(F("#                ATS-01                  #\n"));
  debugSerial.print(F("#   AgroTech Station 01 (Tiny version)   #\n"));
  debugSerial.print(F("#        AgroTechLab (IFSC/Lages)        #\n"));  
  debugSerial.print(F("##########################################\n"));
  debugSerial.print(F("Starting ATS-01..."));
  debugSerial.print(F("\n\tMCU device board......: "));
  debugSerial.print(DEV_TYPE);
  debugSerial.print(F("\n\tCommunication device..: "));
  debugSerial.print(DEV_CONN);
  debugSerial.print(F("\n\tFirmware version......: "));
  debugSerial.print(DEV_FW_VERSION);
  debugSerial.print(F("\n\tSensor list...........: "));
  debugSerial.print(DEV_SENSOR_LIST);
  debugSerial.print(F("\n\tActuator list.........: "));
  debugSerial.print(DEV_ACTUATOR_LIST);
  debugSerial.flush();
}
#endif

/**
 * @fn    getBatteryVoltage
 * @brief Get battery voltage level.
 * @return battery voltage.
 */
float getBatteryVoltage() {
  int analogValue = 0;
  float vout;
  float battery_voltage;

  // Read analog value using ADC 10 bits
  analogValue = analogRead(VOLTAGE_SENSOR_PIN);

  // Convert ADC value to voltage using factor 1:5
  vout = (analogValue * 5.0) / 1024;

  // Use tension division to get real voltage value
  battery_voltage = vout / (voltageSensor_R2/(voltageSensor_R1+voltageSensor_R2));
  
  #if (SERIAL_DEBUG == true)
    debugSerial.print(F("\n\tBattery voltage (in V): "));
    debugSerial.print(battery_voltage);
    debugSerial.flush();
  #endif

  return battery_voltage;
}

/**
 * @fn    getUVIndex
 * @brief Get UV index from UVM30A sensor.
 * @return UV index.
 */
uint8_t getUVIndex() {
  // Get UV sensor value and compute in milivolts
  //int uv_value = (analogRead(UVM30A_PORT) * (5.0 / 1023.0)) * 1000;
  uint16_t uv_value = analogRead(UVM30A_PIN);
  uint8_t uv_index = UINT8_MAX;
  if (isnan(uv_value)) {
    #if (SERIAL_DEBUG == true)
      debugSerial.print(F("\n\tError reading UV radiation index!!!"));
      debugSerial.flush();
    #endif
  } else {
    if (uv_value > 1170) {
      uv_index = 12;
    } else {
      for (int i = 0; i < 12; i++) {
        if (uv_value <= uvIndexValue[i]) {
          uv_index = i;
          break;
        }
      }
    }
    #if (SERIAL_DEBUG == true)
      debugSerial.print(F("\n\tUV radiation (in UV index): "));
      debugSerial.print(uv_value);
      debugSerial.print(" => ");
      debugSerial.print(uv_index);
      debugSerial.flush();
    #endif    
  }
  return uv_index;
}

/**
 * @fn    getLightInLux
 * @brief Get light intensity (in LUX) from GY30 or GY302 sensor.
 * @return light intensity (in LUX).
 */
uint16_t getLightInLux() {
  uint16_t lux = lightSensor.readLightLevel();    
  if ((isnan(lux)) || (lux < 0.0f) || (lux > 65535) ) {
    lux = UINT16_MAX;
    if (SERIAL_DEBUG == true) {
      debugSerial.print(F("\n\tError reading light level!!!"));
      debugSerial.flush();
    }  
  } else {    
    if (SERIAL_DEBUG == true) {
      debugSerial.print(F("\n\tLuminosity (in LUX): "));  
      debugSerial.print(lux);        
      debugSerial.flush();
    }
  }
  return lux;
}

/**
 * @fn    float getAirTemperatureInC
 * @brief Get air temperature (in Celsius) from DHT22 sensor.
 * @return air temperature (in Celsius).
 */
float getAirTemperatureInC() {  
  dht.temperature().getSensor(&dht_sensor);
  dht.temperature().getEvent(&dht_sensor_event);
  float air_temperature = 0.0f;

  if ((isnan(dht_sensor_event.temperature) || (dht_sensor_event.temperature < -40.0f) ||
      (dht_sensor_event.temperature > 80.0f))) {
      air_temperature = __FLT_MAX__;
    #if (SERIAL_DEBUG == true)
      debugSerial.print(F("\n\tError reading air temperature!!!"));
      debugSerial.flush();
    #endif  
  } else {
    air_temperature = dht_sensor_event.temperature;
    #if (SERIAL_DEBUG == true)
        debugSerial.print(F("\n\tAir temperature (in oC): "));
        debugSerial.print(air_temperature);        
        debugSerial.flush();
    #endif
  }
  return air_temperature;
}

/**
 * @fn    getAirHumidity
 * @brief Get air umidity (in %) from DHT22 sensor.
 * @return air umidity (in %).
 */
float getAirHumidity() {
  
  dht.humidity().getSensor(&dht_sensor);
  dht.humidity().getEvent(&dht_sensor_event);
  float air_umidity = 0.0f;
  
  if ((isnan(dht_sensor_event.relative_humidity)) || (dht_sensor_event.relative_humidity < 0.0f) ||
    (dht_sensor_event.relative_humidity > 100.0f)) {
    air_umidity = __FLT_MAX__;      
    #if (SERIAL_DEBUG == true)
      debugSerial.print(F("\n\tError reading air humidity!!!"));
      debugSerial.flush();
    #endif  
  } else {
    air_umidity = dht_sensor_event.relative_humidity;
    #if (SERIAL_DEBUG == true)
      debugSerial.print(F("\n\tAir humidity (in %): "));
      debugSerial.print(air_umidity);      
      debugSerial.flush();
    #endif
  }

  return air_umidity;
}