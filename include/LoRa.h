/**
 * @file lora.h
 * @author Robson Costa (robson.costa@ifsc.edu.br)
 * @brief LoRa operation library.
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
#ifndef __LORA_H__
#define __LORA_H__

#include <Arduino.h>

/**
 * @enum LoRaBand_e
 * @brief LoRa band operation.
 * @var EU868
 * European band operation.
 * @var US915
 * America band operation.
 * @var AU920
 * Australia band operation.
 */
enum LoRaBand_e {
    EU868,
    US915,
    AU920
};

/**
 * @enum LoRaOpClass_e
 * @brief LoRa operation class.
 * @var A
 * LoRa class "A".
 * @var C
 * LoRa class "C".
 */
enum LoRaOpClass_e {
    A,
    C
};

/**
 * @enum LoRaTxPower_e
 * @brief LoRa transmission power (in dBm).
 * @var A
 * LoRa class "A".
 * @var C
 * LoRa class "C".
 */
enum LoRaTxPower_e {
    dBm30,
    dBm28,
    dBm26,
    dBm24,
    dBm22,
    dBm20,
    dBm18,
    dBm16,
    dBm14,
    dBm12,
    dBm10
};

/**
 * @enum LoRaDR_e
 * @brief LoRa data rate.
 * @var DR0
 * [EU868/EU434] - LoRa SF12/125KHz.\n
 * [US915/AU920] - LoRa SF10/125KHz.
 * @var DR1
 * [EU868/EU434] - LoRa SF11/125KHz.\n
 * [US915/AU920] - LoRa SF9/125KHz.
 * @var DR2
 * [EU868/EU434] - LoRa SF10/125KHz.\n
 * [US915/AU920] - LoRa SF8/125KHz.
 * @var DR3
 * [EU868/EU434] - LoRa SF9/125KHz.\n
 * [US915/AU920] - LoRa SF7/125KHz.
 * @var DR4
 * [EU868/EU434] - LoRa SF8/125KHz.\n
 * [US915/AU920] - LoRa SF8/500KHz.
 * @var DR5
 * [EU868/EU434] - LoRa SF7/125KHz.\n
 * [US915/AU920] - RFU.
 * @var DR6
 * [EU868/EU434] - LoRa SF7/250KHz.\n
 * [US915/AU920] - RFU.
 * @var DR7
 * [EU868/EU434] - FSK 50Kbps.\n
 * [US915/AU920] - RFU.
 * @var DR8
 * [EU868/EU434] - RFU.\n
 * [US915/AU920] - LoRa SF12/500KHz.
 * @var DR9
 * [EU868/EU434] - RFU.\n
 * [US915/AU920] - LoRa SF11/500KHz.
 * @var DR10
 * [EU868/EU434] - RFU.\n
 * [US915/AU920] - LoRa SF10/500KHz.
 * @var DR11
 * [EU868/EU434] - RFU.\n
 * [US915/AU920] - LoRa SF9/500KHz.
 * @var DR12
 * [EU868/EU434] - RFU.\n
 * [US915/AU920] - LoRa SF8/500KHz.
 * @var DR13
 * [EU868/EU434] - RFU.\n
 * [US915/AU920] - LoRa SF7/500KHz.
 * @var DR14
 * [EU868/EU434] - RFU.\n
 * [US915/AU920] - RFU.
 * @var DR15
 * [EU868/EU434] - RFU.\n
 * [US915/AU920] - RFU.
 */
enum LoRaDR_e {
    DR0,
    DR1,
    DR2,
    DR3,
    DR4,
    DR5,
    DR6,
    DR7,
    DR8,
    DR9,
    DR10,
    DR11,
    DR12,
    DR13,
    DR14,
    DR15
};

/**
 * @enum LoRaBool_e
 * @brief LoRa boolean.
 * @var ON
 * parameter is ON.
 * @var OFF
 * parameter is OFF.
 */
enum LoRaBool_e {
    ON,
    OFF
};

/**
 * @enum LoRaAuthMode_e
 * @brief LoRa authentication mode.
 * @var LWABP
 * Authentication by Personalisation.
 * @var LWOTAA
 * Over the Air Authentication.
 * @var LWTEST
 * Test mode.
 */
enum LoRaAuthMode_e {
    LWABP,
    LWOTAA,
    LWTEST
};

/**
 * @struct LoRaConfig_t
 * @brief LoRa configuration struct.
 */
struct LoRaConfig_t {
    LoRaBand_e band;            /**< LoRa band. */
    LoRaOpClass_e op_class;     /**< LoRa operation class. */
    LoRaTxPower_e tx_power;     /**< LoRa transmission power. */
    LoRaDR_e uplink_dr;         /**< LoRa uplink datarate. */
    LoRaBool_e adr;             /**< LoRa ADR (Automatic Data Rate). */
    LoRaAuthMode_e auth_mode;   /**< LoRa authentication mode. */
    String dev_eui;             /**< LoRa DevEUI. */
    String app_eui;             /**< LoRa AppEUI. */
    String repeat;              /**< LoRa unconfirmed message repeat time. */
    String retry;               /**< LoRa confirmed message retry times. */
    String dev_addr;            /**< LoRa device address. */
    String app_key;             /**< LoRa application key. */
    String apps_key;            /**< LoRa application session key. */
    String nwks_key;            /**< LoRa network session key. */
    String rxwin2_freq;         /**< LoRa receive window 2 frequency. */
    LoRaDR_e rxwin2_dr;         /**< LoRa receive window 2 datarate. */
    String chan0_freq;          /**< LoRa channel 0 frequency. */
    LoRaDR_e chan0_dr;          /**< LoRa channel 0 datarate. */
    String chan1_freq;          /**< LoRa channel 1 frequency. */
    LoRaDR_e chan1_dr;          /**< LoRa channel 1 datarate. */
    bool debug;                 /**< Enable/disable LoRa debug. */
};

class LoRa {
    private:
        String loraReturn = "";
        bool loraBusy = false;
        String loraBand_toString(LoRaBand_e loraBand);
        String loraOpClass_toString(LoRaOpClass_e loraOpClass);
        String loraTxPower_toString(LoRaTxPower_e loraTxPower);
        String loraDR_toString(LoRaDR_e loraDR);
        String loraBool_toString(LoRaBool_e loraBool);
        String loraAuthMode_toString(LoRaAuthMode_e loraAuthMode);

    public:
        bool initModem(LoRaConfig_t loraConfig);
        bool sendNoAckMsg(LoRaConfig_t loraCfg, uint8_t port, String buf);
        bool sendAckMsg(LoRaConfig_t loraCfg, uint8_t port, String buf);
        bool sendNoAckMsgHex(LoRaConfig_t loraCfg, uint8_t port, String buf);
        bool sendAckMsgHex(LoRaConfig_t loraCfg, uint8_t port, String buf);
        void callback_RX();
};
#endif // __LORA_H_