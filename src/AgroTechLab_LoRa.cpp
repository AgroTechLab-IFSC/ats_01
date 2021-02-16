/**
 * @file AgroTechLab_LoRa.cpp
 * @author Robson Costa (robson.costa@ifsc.edu.br)
 * @brief AgroTechLab LoRa library.
 * @version 1.0.0
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
#include <AgroTechLab_LoRa.h>

/**
 * @fn LoRa::LoRa(LoRaConfig_t lora_config)
 * @brief Constructor of LoRa class.
 */
//LoRa::LoRa() { }

/**
 * @fn LoRa::initModem()
 * @brief Initialize LoRa modem.
 * @param[in] lora_config - struct with LoRa configuration (see \ref LoRaConfig_t).
 * @retval true - successful initialization.
 * @retval false - initialization fail.
 */
bool LoRa::initModem(LoRaConfig_t loraConfig) {

    String at_cmd;

    // Configure UART communication between MCU and LoRa module LoRa modem
    if (loraConfig.debug) {
        Serial.print("\nInitiating UART port between MCU device and LoRa modem... ");
        Serial.flush();
    }
    
    // Initiate Serial1
    // Serial1.begin(9600);

    // Wait for serial port to connect
    // while (!Serial1) {;}
    
    if (loraConfig.debug) {
        Serial.print("[OK]");
        Serial.flush();
    }

    // Test UART communication
    if (loraConfig.debug) {
        Serial.print("\nTesting UART communciation between MCU and LoRa modem... ");
        Serial.flush();
    }
    // Serial1.println("AT");
    // loraReturn = Serial1.readString();
    if (strcmp((char*)loraReturn.c_str(), "+AT: OK\r\n") != 0) {
        if (loraConfig.debug) {
            Serial.print("[ERROR]\n\t");
            Serial.print(loraReturn);
            Serial.flush();
        }
        return false;
    } else {
        if (loraConfig.debug) {
            Serial.print("[OK]");
            Serial.flush();
        }    
    }

    // Get LoRa modem firmware version
    if (loraConfig.debug) {
        Serial.print("\nGetting LoRa modem firmware version...");
        Serial.flush();
    }
    loraReturn = "";
    // Serial1.println("AT+VER");
    // loraReturn = Serial1.readString();
    if (loraConfig.debug) {
        Serial.print("\n\t");
        Serial.print(loraReturn);
        Serial.flush();
    }    

    // Set LoRa base band
    if (loraConfig.debug) {
        Serial.print("\nSetting LoRa base band... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+DR=";
    at_cmd.concat(loraBand_toString(loraConfig.band));
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    if (loraConfig.debug) {
        Serial.print("\n\t");
        Serial.print(loraReturn);
        Serial.flush();         
    }

    // Set LoRa class
    if (loraConfig.debug) {
        Serial.print("\nSetting LoRa class... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+CLASS=";
    at_cmd.concat(loraOpClass_toString(loraConfig.op_class));
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    if (loraConfig.debug) {
        Serial.print("\n\t");
        Serial.print(loraReturn);
        Serial.flush();        
    }

    // Set LoRa transmission power
    if (loraConfig.debug) {
        Serial.print("\nSetting LoRa transmission power... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+POWER=";
    at_cmd.concat(loraTxPower_toString(loraConfig.tx_power));
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    if (loraConfig.debug) {
        Serial.print("\n\t");
        Serial.print(loraReturn);
        Serial.flush();        
    }

    // Set LoRa uplink datarate
    if (loraConfig.debug) {
        Serial.print("\nSetting LoRa uplink datarate... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+DR=";
    at_cmd.concat(loraDR_toString(loraConfig.uplink_dr));
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    if (loraConfig.debug) {
        Serial.print("\n\t");
        Serial.print(loraReturn);
        Serial.flush();        
    }

    // Set LoRa channel 0 configuration
    if (loraConfig.debug) {
        Serial.print("\nSetting LoRa channel 0 configuration... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+CH=0,";
    at_cmd.concat(loraConfig.chan0_freq);
    at_cmd.concat(",");
    at_cmd.concat(loraDR_toString(loraConfig.chan0_dr));
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    if (loraConfig.debug) {
        Serial.print("\n\t");
        Serial.print(loraReturn);
        Serial.flush();        
    }

    // Set LoRa channel 1 configuration
    if (loraConfig.debug) {
        Serial.print("\nSetting LoRa channel 1 configuration... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+CH=1,";
    at_cmd.concat(loraConfig.chan1_freq);
    at_cmd.concat(",");
    at_cmd.concat(loraDR_toString(loraConfig.chan1_dr));
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    if (loraConfig.debug) {
        Serial.print("\n\t");
        Serial.print(loraReturn);
        Serial.flush();        
    }

    // Set LoRa RX window 2
    if (loraConfig.debug) {
        Serial.print("\nSetting LoRa RX window 2... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+RXWIN2=";
    at_cmd.concat(loraConfig.rxwin2_freq);
    at_cmd.concat(",");
    at_cmd.concat(loraDR_toString(loraConfig.rxwin2_dr));
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    if (loraConfig.debug) {
        Serial.print("\n\t");
        Serial.print(loraReturn);
        Serial.flush();        
    }

    // Set LoRa ADR (Automatic Datarate)
    if (loraConfig.debug) {
        Serial.print("\nSetting LoRa ADR... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+ADR=";
    at_cmd.concat(loraBool_toString(loraConfig.adr));
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    if (loraConfig.debug) {
        Serial.print("\n\t");
        Serial.print(loraReturn);
        Serial.flush();        
    }

    // Set LoRa DevEUI
    if (loraConfig.debug) {
        Serial.print("\nSetting LoRa DevEUI... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+ID=DevEui,\"";
    at_cmd.concat(loraConfig.dev_eui);
    at_cmd.concat("\"");
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    if (loraConfig.debug) {
        Serial.print("\n\t");
        Serial.print(loraReturn);
        Serial.flush();        
    }

    // Set LoRa AppEUI
    if (loraConfig.debug) {
        Serial.print("\nSetting LoRa AppEUI... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+ID=AppEui,\"";
    at_cmd.concat(loraConfig.app_eui);
    at_cmd.concat("\"");
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    if (loraConfig.debug) {
        Serial.print("\n\t");
        Serial.print(loraReturn);
        Serial.flush();        
    }

    // // Set LoRa unconfirmed message repeats time
    // if (loraConfig.debug) {
    //     Serial.print("\nSetting LoRa unconfirmed message repeats time... ");
    //     Serial.flush();
    // }
    // loraReturn = "";
    // at_cmd = "AT+REPT=";
    // at_cmd.concat(loraConfig.repeat);
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    // if (loraConfig.debug) {
    //     Serial.print("\n\t");
    //     Serial.print(loraReturn);
    //     Serial.flush();        
    // }

    // Set LoRa confirmed message retry times
    if (loraConfig.debug) {
        Serial.print("\nSetting LoRa confirmed message retry times... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+RETRY=";
    at_cmd.concat(loraConfig.retry);
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    if (loraConfig.debug) {
        Serial.print("\n\t");
        Serial.print(loraReturn);
        Serial.flush();        
    }

    // Set LoRa authentication mode
    if (loraConfig.debug) {
        Serial.print("\nSetting LoRa authentication mode... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+MODE=";
    at_cmd.concat(loraAuthMode_toString(loraConfig.auth_mode));
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    if (loraConfig.debug) {
        Serial.print("\n\t");
        Serial.print(loraReturn);
        Serial.flush();        
    }

    // Set another LoRa parameters based on authentication mode
    // Authentication LWABP
    if (loraAuthMode_toString(loraConfig.auth_mode).compareTo("LWABP") == 0) {
        
        // Set LoRa device address
        if (loraConfig.debug) {
            Serial.print("\nSetting LoRa device address... ");
            Serial.flush();
        }
        loraReturn = "";
        at_cmd = "AT+ID=DevAddr,\"";
        at_cmd.concat(loraConfig.dev_addr);
        at_cmd.concat("\"");
        // Serial1.println(at_cmd);
        // loraReturn = Serial1.readString();
        if (loraConfig.debug) {
            Serial.print("\n\t");
            Serial.print(loraReturn);
            Serial.flush();        
        }

        // Set LoRa network session key
        if (loraConfig.debug) {
            Serial.print("\nSetting LoRa network session key... ");
            Serial.flush();
        }
        loraReturn = "";
        at_cmd = "AT+KEY=NwkSKey,\"";
        at_cmd.concat(loraConfig.nwks_key);
        at_cmd.concat("\"");
        // Serial1.println(at_cmd);
        // loraReturn = Serial1.readString();
        if (loraConfig.debug) {
            Serial.print("\n\t");
            Serial.print(loraReturn);
            Serial.flush();        
        }

        // Set LoRa application session key
        if (loraConfig.debug) {
            Serial.print("\nSetting LoRa application session key... ");
            Serial.flush();
        }
        loraReturn = "";
        at_cmd = "AT+KEY=AppSKey,\"";
        at_cmd.concat(loraConfig.apps_key);
        at_cmd.concat("\"");
        // Serial1.println(at_cmd);
        // loraReturn = Serial1.readString();
        if (loraConfig.debug) {
            Serial.print("\n\t");
            Serial.print(loraReturn);
            Serial.flush();        
        }

    } else {
        // Authentication OTAA
        // Set LoRa application key
        if (loraConfig.debug) {
            Serial.print("\nSetting LoRa application key... ");
            Serial.flush();
        }
        loraReturn = "";
        at_cmd = "AT+KEY=AppKey,\"";
        at_cmd.concat(loraConfig.app_key);
        at_cmd.concat("\"");
        // Serial1.println(at_cmd);
        // loraReturn = Serial1.readString();
        if (loraConfig.debug) {
            Serial.print("\n\t");
            Serial.print(loraReturn);
            Serial.flush();        
        }

        // Join to the LoRa network
        if (loraConfig.debug) {
            Serial.print("\nJoining... ");
            Serial.flush();
        }
        loraReturn = "";
        at_cmd = "AT+Join";
        loraBusy = true;
        // Serial1.println(at_cmd);
        // loraReturn = Serial1.readString();
        do {
            // while (Serial1.available()) {
            //     loraReturn = Serial1.readString();
            //     if (loraConfig.debug) {
            //         Serial.print("\n");
            //         Serial.print(loraReturn);
            //         Serial.flush();        
            //     }
            //     char str[30];
            //     loraReturn.toCharArray(str, sizeof(str), 0);
            //     if (strstr(str, "Done")) {
            //         loraBusy = false;
            //     }
            // }  
        } while (loraBusy);

    }

    // Return success initialization
    return true;
}

/**
 * @fn loraBand_toString(LoRaBand_e loraBand)
 * @brief Convert LoRa band enum to String.
 * @param[in] lora_band - LoRa port used to send message.
 * @return String - LoRa band string.
 */ 
String LoRa::loraBand_toString(LoRaBand_e loraBand) {
    switch (loraBand) {
        case EU868:
            return "EU868";
        case US915:
            return "US915";
        case AU920:
            return "AU920";
        default:
            return "ERROR";
    }
}

/**
 * @fn loraOpClass_toString(LoRaOpClass_e loraOpClass)
 * @brief Convert LoRa operation class enum to String.
 * @param[in] lora_class - LoRa operation class enum.
 * @return String - LoRa class operation string.
 */ 
String LoRa::loraOpClass_toString(LoRaOpClass_e loraOpClass) {
    switch (loraOpClass) {
        case A:
            return "A";
        case C:
            return "C";
        default:
            return "ERROR";
    }
}

/**
 * @fn loraTxPower_toString(LoRaTxPower_e loraTxPower)
 * @brief Convert LoRa transmission power enum to String.
 * @param[in] loraTxPower - LoRa transmission power enum.
 * @return String - LoRa transmission power string.
 */ 
String LoRa::loraTxPower_toString(LoRaTxPower_e loraTxPower) {
    switch (loraTxPower) {
        case dBm30:
            return "30";
        case dBm28:
            return "28";
        case dBm26:
            return "26";
        case dBm24:
            return "24";
        case dBm22:
            return "22";
        case dBm20:
            return "20";
        case dBm18:
            return "18";
        case dBm16:
            return "16";
        case dBm14:
            return "14";
        case dBm12:
            return "12";
        case dBm10:
            return "10";
        default:
            return "ERROR";
    }
}


/**
 * @fn loraDR_toString(LoRaDR_e loraDR)
 * @brief Convert LoRa datarate enum to String.
 * @param[in] loraDR - LoRa datarate enum.
 * @return String - LoRa datarate string.
 */ 
String LoRa::loraDR_toString(LoRaDR_e loraDR) {
    switch (loraDR) {
        case DR0:
            return "DR0";
        case DR1:
            return "DR1";
        case DR2:
            return "DR2";
        case DR3:
            return "DR3";
        case DR4:
            return "DR4";
        case DR5:
            return "DR5";
        case DR6:
            return "DR6";
        case DR7:
            return "DR7";
        case DR8:
            return "DR8";
        case DR9:
            return "DR9";
        case DR10:
            return "DR10";
        case DR11:
            return "DR11";
        case DR12:
            return "DR12";
        case DR13:
            return "DR13";
        case DR14:
            return "DR14";
        case DR15:
            return "DR15";
        default:
            return "ERROR";
    }
}

/**
 * @fn loraBool_toString(LoRaBool_e loraBool)
 * @brief Convert LoRa boolean enum to String.
 * @param[in] loraBool - LoRa boolean enum.
 * @return String - LoRa boolean string.
 */ 
String LoRa::loraBool_toString(LoRaBool_e loraBool) {
    switch (loraBool) {
        case ON:
            return "ON";
        case OFF:
            return "OFF";
        default:
            return "ERROR";
    }
}

/**
 * @fn loraAuthMode_toString(LoRaAuthMode_e loraAuthMode)
 * @brief Convert LoRa authentication mode enum to String.
 * @param[in] loraAuthMode - LoRa authentication mode enum.
 * @return String - LoRa authentication mode string.
 */ 
String LoRa::loraAuthMode_toString(LoRaAuthMode_e loraAuthMode) {
    switch (loraAuthMode) {
        case LWABP:
            return "LWABP";
        case LWOTAA:
            return "LWOTAA";
        case LWTEST:
            return "LWTEST";
        default:
            return "ERROR";
    }
}

/**
 * @fn sendNoAckMsg(uint8_t port, char* msg_ptr, uint8_t msg_size)
 * @brief Send unconfirmed messages in a string format.
 * @param[in] port - LoRa port used to send message.
 * @param[in] msg_ptr - pointer to message.
 * @param[in] msg_size - message size.
 * @retval true - successful transmission.
 * @retval false - transmission fail.
 */ 
bool LoRa::sendNoAckMsg(LoRaConfig_t loraCfg, uint8_t port, String buf) {

    String at_cmd = "";

    // Set LoRa port
    if (loraCfg.debug) {
        Serial.print("\nSetting LoRa port... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+PORT=";
    at_cmd.concat(toAscii(port));
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    if (loraCfg.debug) {
        Serial.print("\n\t");
        Serial.print(loraReturn);
        Serial.flush();        
    }

    // Send LoRa message
    if (loraCfg.debug) {
        Serial.print("\nSending unconfirmed LoRa string message... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+MSG=\"";
    at_cmd.concat(buf);
    at_cmd.concat("\"");
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    if (loraCfg.debug) {
        Serial.print("\n\t");
        Serial.print(loraReturn);
        Serial.flush();        
    }

    return true;
}

/**
 * @fn sendAckMsg(uint8_t port, char* msg_ptr, uint8_t msg_size)
 * @brief Send confirmed messages in a string format.
 * @param[in] port - LoRa port used to send message.
 * @param[in] msg_ptr - pointer to message.
 * @param[in] msg_size - message size.
 * @retval true - successful transmission.
 * @retval false - transmission fail.
 */ 
bool LoRa::sendAckMsg(LoRaConfig_t loraCfg, uint8_t port, String buf) {

    String at_cmd = "";

    // Set LoRa port
    if (loraCfg.debug) {
        Serial.print("\nSetting LoRa port... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+PORT=";
    at_cmd.concat(toAscii(port));
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    if (loraCfg.debug) {
        Serial.print("\n\t");
        Serial.print(loraReturn);
        Serial.flush();        
    }

    // Send LoRa message
    if (loraCfg.debug) {
        Serial.print("\nSending confirmed LoRa string message... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+CMSG=\"";
    at_cmd.concat(buf);
    at_cmd.concat("\"");
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    if (loraCfg.debug) {
        Serial.print("\n");
        Serial.print(loraReturn);
        Serial.flush();        
    }

    return true;
}

/**
 * @fn sendNoAckMsgHex(uint8_t port, char* msg_ptr, uint8_t msg_size)
 * @brief Send unconfirmed messages in a hexadecimal format.
 * @param[in] port - LoRa port used to send message.
 * @param[in] msg_ptr - pointer to message.
 * @param[in] msg_size - message size.
 * @retval true - successful transmission.
 * @retval false - transmission fail.
 */ 
bool LoRa::sendNoAckMsgHex(LoRaConfig_t loraCfg, uint8_t port, String buf) {

    String at_cmd = "";

    // Set LoRa modem as busy
    loraBusy = true;

    // Set LoRa port
    if (loraCfg.debug) {
        Serial.print("\nSetting LoRa port... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+PORT=";
    at_cmd.concat(toAscii(port));
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    if (loraCfg.debug) {
        Serial.print("\n\t");
        Serial.print(loraReturn);
        Serial.flush();        
    }

    // Send LoRa message
    if (loraCfg.debug) {
        Serial.print("\nSending unconfirmed LoRa hexadecimal message... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+MSGHEX=\"";
    at_cmd.concat(buf);
    at_cmd.concat("\"");
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    do {
        // while (Serial1.available()) {
        //     loraReturn = Serial1.readString();
        //     if (loraCfg.debug) {
        //         Serial.print("\n");
        //         Serial.print(loraReturn);
        //         Serial.flush();        
        //     }
        //     char str[1024];
        //     loraReturn.toCharArray(str, sizeof(str), 0);
        //     if (strstr(str, "Done")) {
        //         loraBusy = false;
        //     }
        // }  
    } while (loraBusy);

    return true;
}

/**
 * @fn sendAckMsgHex(uint8_t port, char* msg_ptr, uint8_t msg_size)
 * @brief Send confirmed messages in a hexadecimal format.
 * @param[in] port - LoRa port used to send message.
 * @param[in] msg_ptr - pointer to message.
 * @param[in] msg_size - message size.
 * @retval true - successful transmission.
 * @retval false - transmission fail.
 */ 
bool LoRa::sendAckMsgHex(LoRaConfig_t loraCfg, uint8_t port, String buf) {

    String at_cmd = "";

    // Set LoRa modem as busy
    loraBusy = true;

    // Set LoRa port
    if (loraCfg.debug) {
        Serial.print("\nSetting LoRa port... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+PORT=";
    at_cmd.concat(toAscii(port));
    // Serial1.println(at_cmd);
    // loraReturn = Serial1.readString();
    if (loraCfg.debug) {
        Serial.print("\n\t");
        Serial.print(loraReturn);
        Serial.flush();        
    }

    // Send LoRa message
    if (loraCfg.debug) {
        Serial.print("\nSending confirmed LoRa hexadecimal message... ");
        Serial.flush();
    }
    loraReturn = "";
    at_cmd = "AT+CMSGHEX=\"";
    at_cmd.concat(buf);
    at_cmd.concat("\"");
    // Serial1.println(at_cmd);
    do {
        // while (Serial1.available()) {
        //     loraReturn = Serial1.readString();
        //     if (loraCfg.debug) {
        //         Serial.print("\n");
        //         Serial.print(loraReturn);
        //         Serial.flush();        
        //     }
        //     char str[1024];
        //     loraReturn.toCharArray(str, sizeof(str), 0);
        //     if (strstr(str, "Done")) {
        //         loraBusy = false;
        //     }
        // }  
    } while (loraBusy);

    return true;
}

/**
 * @fn loraSerialRx_callback()
 * @brief Callback to process data from LoRa modem.
 */
void LoRa::callback_RX() {
    // while (Serial1.available()) {    
    //     loraReturn = Serial1.readString();
    //     // if (loraConfig.debug) {
    //         Serial.print("\n");
    //         Serial.print(loraReturn);
    //         Serial.flush();
    //     // }
    // }
}