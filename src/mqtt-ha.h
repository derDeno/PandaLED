#ifndef MQTT_HA_H
#define MQTT_HA_H

/*
* Managig MQTT communication with Home Assistant
*/
#include <WiFiClient.h>

extern AppConfig appConfig;
extern EventQueue eventQueue;

WiFiClient wifiClientHa;
PubSubClient mqttClientHa;
bool configSent = false;


void mqttHaPublish(const char* topic, const char* payload, bool retain = true) {

    if(!appConfig.haSet) {
        return;
    }
    
    const String mqttBase = String("pandaled/") + appConfig.name;
    mqttClientHa.publish((mqttBase + topic).c_str(), payload, retain);
}


void mqttHaInitState() {
    mqttHaPublish("/status", "online", false);

    if(appConfig.wled) {
        mqttHaPublish("/wled/state", "{\"state\": \"OFF\"}", true);
    }

    if(appConfig.analog) {
        mqttHaPublish("/analog/state", "{\"state\": \"OFF\"}", true);
    }

    mqttHaPublish("/gpio/5/state", "OFF", true);
    mqttHaPublish("/gpio/18/state", "OFF", true);
    mqttHaPublish("/gpio/19/state", "OFF", true);
    mqttHaPublish("/gpio/21/state", "OFF", true);
    mqttHaPublish("/gpio/22/state", "OFF", true);
    mqttHaPublish("/gpio/23/state", "OFF", true);

    delay(1000);
}


void mqttHaConfig() {
    const String mqttBase = String("pandaled/") + String(appConfig.name);
    const String availability_topic = String("pandaled/") + appConfig.name + String("/status");

    // device config
    JsonDocument device;
    device["name"] = appConfig.name;
    device["ids"][0] = appConfig.name;
    device["mdl"] = "PandaLED Controller";
    device["mf"] = "DNO";
    device["sw"] = VERSION;
    device["cu"] = "http://" + WiFi.localIP().toString() + "/settings";
    device["sn"] = appConfig.serialNumber;
    device["hw"] = appConfig.hwRev;

    // minimal device config for less data transfer
    JsonDocument deviceMinimal;
    deviceMinimal["name"] = appConfig.name;
    deviceMinimal["ids"][0] = appConfig.name;


    // button reboot
    // topic: homeassistant/button/pandaled/reboot/config
    JsonDocument reboot;
    reboot["name"] = "Reboot";
    reboot["uniq_id"] = appConfig.name + String("_reboot");
    reboot["cmd_t"] = mqttBase + "/reboot/set";
    reboot["ent_cat"] = "config";
    reboot["dev_cla"] = "restart";
    reboot["dev"] = device;


    // wled
    // topic: homeassistant/light/pandaled/wled/config
    JsonDocument wled;
    wled["name"] = "WLED Light";
    wled["uniq_id"] = appConfig.name + String("_wled");
    wled["stat_t"] = mqttBase + "/wled/state";
    wled["cmd_t"] = mqttBase + "/wled/switch";
    wled["avty_t"] = availability_topic;
    wled["schema"] = "json";
    wled["brightness"] = true;
    wled["bri_scl"] = 255;
    wled["rgb"] = true;
    wled["effect"] = false;
    wled["dev"] = deviceMinimal;


    // analog rgbcct
    // topic: homeassistant/light/pandaled/analog/config
    JsonDocument analogRgb;
    analogRgb["name"] = "Analog RGBCCT Light";
    analogRgb["uniq_id"] = appConfig.name + String("_analog");
    analogRgb["stat_t"] = mqttBase + "/analog/state";
    analogRgb["cmd_t"] = mqttBase + "/analog/switch";
    analogRgb["avty_t"] = availability_topic;
    analogRgb["schema"] = "json";
    analogRgb["brightness"] = true;
    analogRgb["bri_scl"] = 255;
    analogRgb["rgb"] = true;
    analogRgb["effect"] = false;
    analogRgb["dev"] = deviceMinimal;


    // analog pins


    /**
    * GPIO Header Pins
    */

    // gpio pin 5
    // topic: homeassistant/switch/pandaled/gpio5/config
    JsonDocument gpio5;
    gpio5["name"] = "GPIO 5";
    gpio5["uniq_id"] = appConfig.name + String("_gpio5");
    gpio5["stat_t"] = mqttBase + "/gpio/5/state";
    gpio5["cmd_t"] = mqttBase + "/gpio/5/set";
    gpio5["avty_t"] = availability_topic;
    gpio5["pl_on"] = "ON";
    gpio5["pl_off"] = "OFF";
    gpio5["dev"] = deviceMinimal;

    // gpio pin 18
    // topic: homeassistant/switch/pandaled/gpio18/config
    JsonDocument gpio18;
    gpio18["name"] = "GPIO 18";
    gpio18["uniq_id"] = appConfig.name + String("_gpio18");
    gpio18["stat_t"] = mqttBase + "/gpio/18/state";
    gpio18["cmd_t"] = mqttBase + "/gpio/18/set";
    gpio18["avty_t"] = availability_topic;
    gpio18["pl_on"] = "ON";
    gpio18["pl_off"] = "OFF";
    gpio18["dev"] = deviceMinimal;

    // gpio pin 19
    // topic: homeassistant/switch/pandaled/gpio19/config
    JsonDocument gpio19;
    gpio19["name"] = "GPIO 19";
    gpio19["uniq_id"] = appConfig.name + String("_gpio19");
    gpio19["stat_t"] = mqttBase + "/gpio/19/state";
    gpio19["cmd_t"] = mqttBase + "/gpio/19/set";
    gpio19["avty_t"] = availability_topic;
    gpio19["pl_on"] = "ON";
    gpio19["pl_off"] = "OFF";
    gpio19["dev"] = deviceMinimal;

    // gpio pin 21
    // topic: homeassistant/switch/pandaled/gpio21/config
    JsonDocument gpio21;
    gpio21["name"] = "GPIO 21";
    gpio21["uniq_id"] = appConfig.name + String("_gpio21");
    gpio21["stat_t"] = mqttBase + "/gpio/21/state";
    gpio21["cmd_t"] = mqttBase + "/gpio/21/set";
    gpio21["avty_t"] = availability_topic;
    gpio21["pl_on"] = "ON";
    gpio21["pl_off"] = "OFF";
    gpio21["dev"] = deviceMinimal;

    // gpio pin 22
    // topic: homeassistant/switch/pandaled/gpio22/config
    JsonDocument gpio22;
    gpio22["name"] = "GPIO 22";
    gpio22["uniq_id"] = appConfig.name + String("_gpio22");
    gpio22["stat_t"] = mqttBase + "/gpio/22/state";
    gpio22["cmd_t"] = mqttBase + "/gpio/22/set";
    gpio22["avty_t"] = availability_topic;
    gpio22["pl_on"] = "ON";
    gpio22["pl_off"] = "OFF";
    gpio22["dev"] = deviceMinimal;

    // gpio pin 23
    // topic: homeassistant/switch/pandaled/gpio23/config
    JsonDocument gpio23;
    gpio23["name"] = "GPIO 23";
    gpio23["uniq_id"] = appConfig.name + String("_gpio23");
    gpio23["stat_t"] = mqttBase + "/gpio/23/state";
    gpio23["cmd_t"] = mqttBase + "/gpio/23/set";
    gpio23["avty_t"] = availability_topic;
    gpio23["pl_on"] = "ON";
    gpio23["pl_off"] = "OFF";
    gpio23["dev"] = deviceMinimal;
    

    // serialize
    String rebootConfig, wledConfig, analogRgbConfig, gpio5Config, gpio18Config, gpio19Config, gpio21Config, gpio22Config, gpio23Config;
    serializeJson(reboot, rebootConfig);
    serializeJson(wled, wledConfig);
    serializeJson(analogRgb, analogRgbConfig);
    serializeJson(gpio5, gpio5Config);
    serializeJson(gpio18, gpio18Config);
    serializeJson(gpio19, gpio19Config);
    serializeJson(gpio21, gpio21Config);
    serializeJson(gpio22, gpio22Config);
    serializeJson(gpio23, gpio23Config);

    // publish
    mqttClientHa.publish((String("homeassistant/button/") + appConfig.name + String("/reboot/config")).c_str(), rebootConfig.c_str());
    
    if(appConfig.wled) {
        mqttClientHa.publish((String("homeassistant/light/") + appConfig.name + String("/wled/config")).c_str(), wledConfig.c_str());
    }

    if(appConfig.analog) {
        mqttClientHa.publish((String("homeassistant/light/") + appConfig.name + String("/analog/config")).c_str(), analogRgbConfig.c_str());
    }

    mqttClientHa.publish((String("homeassistant/switch/") + appConfig.name + String("/gpio5/config")).c_str(), gpio5Config.c_str());
    mqttClientHa.publish((String("homeassistant/switch/") + appConfig.name + String("/gpio18/config")).c_str(), gpio18Config.c_str());
    mqttClientHa.publish((String("homeassistant/switch/") + appConfig.name + String("/gpio19/config")).c_str(), gpio19Config.c_str());
    mqttClientHa.publish((String("homeassistant/switch/") + appConfig.name + String("/gpio21/config")).c_str(), gpio21Config.c_str());
    mqttClientHa.publish((String("homeassistant/switch/") + appConfig.name + String("/gpio22/config")).c_str(), gpio22Config.c_str());
    mqttClientHa.publish((String("homeassistant/switch/") + appConfig.name + String("/gpio23/config")).c_str(), gpio23Config.c_str());

    mqttHaInitState();
}


void mqttHaListen(char* topic, byte* payload, unsigned int length) {
    const String mqttBase = String("pandaled/") + String(appConfig.name);

    // reboot
    if(strcmp(topic, (mqttBase + "/reboot/set").c_str()) == 0) {
        logger("MQTT:   Rebooting triggered");
        delay(10);
        ESP.restart();
        return;
    }

    // wled
    if(strcmp(topic, (mqttBase + "/wled/switch").c_str()) == 0) {
        JsonDocument message;
        DeserializationError error = deserializeJson(message, payload, length);
        
        if(error) {
            logger("E:  Failed to parse mqtt message");
            return;
        }

        // check if message is on or off
        if(message["state"] == "ON") {
            logger("MQTT:   WLED turned on");

            int r = message["color"]["r"].is<int>() ? message["color"]["r"] : 0;
            int g = message["color"]["g"].is<int>() ? message["color"]["g"] : 0;
            int b = message["color"]["b"].is<int>() ? message["color"]["b"] : 0;
            int brightness = message["brightness"].is<int>() ? message["brightness"] : 0;

            EventOutput event;
            event.type = WLED_CHANGE;
            event.isOn = true;
            event.r = r;
            event.g = g;
            event.b = b;
            event.brightness = brightness;
            eventQueue.push(event);

        } else {
            logger("MQTT:   WLED turned off");
            EventOutput event;
            event.type = WLED_CHANGE;
            event.isOn = false;
            eventQueue.push(event);
        }

        return;
    }

    // analog
    if(strcmp(topic, (mqttBase + "/analog/switch").c_str()) == 0) {
        JsonDocument message;
        DeserializationError error = deserializeJson(message, payload, length);
        
        if(error) {
            logger("E:  Failed to parse mqtt message");
            return;
        }

        // check if message is on or off
        if(message["state"] == "ON") {
            logger("MQTT:   Analog turned on");

            int r = message["color"]["r"];
            int g = message["color"]["g"];
            int b = message["color"]["b"];
            int brightness = message["brightness"].is<int>() ? message["brightness"] : 255;

            EventOutput event;
            event.type = ANALOG_CHANGE;
            event.isOn = true;
            event.r = r;
            event.g = g;
            event.b = b;
            event.brightness = brightness;
            eventQueue.push(event);
            
        } else {
            logger("MQTT:   Analog turned off");
            EventOutput event;
            event.type = ANALOG_CHANGE;
            event.isOn = false;
            eventQueue.push(event);
        }

        return;
    }


    // gpio pins
    if(strcmp(topic, (mqttBase + "/gpio/5/set").c_str()) == 0) {
        String payloadStr;
        for (size_t i = 0; i < length; i++) {
            payloadStr += static_cast<char>(payload[i]);
        }

        Serial.println(payloadStr);

        if(payloadStr == "ON") {
            logger("MQTT:   GPIO 5 turned on");
            EventOutput event;
            event.type = GPIO_CHANGE;
            event.pin = 5;
            event.isOn = true;
            eventQueue.push(event);
        } else {
            logger("MQTT:   GPIO 5 turned off");
            EventOutput event;
            event.type = GPIO_CHANGE;
            event.pin = 5;
            event.isOn = false;
            eventQueue.push(event);
        }

        return;
    }

    if(strcmp(topic, (mqttBase + "/gpio/18/set").c_str()) == 0) {
        String payloadStr;
        for (size_t i = 0; i < length; i++) {
            payloadStr += static_cast<char>(payload[i]);
        }

        if(payloadStr == "ON") {
            logger("MQTT:   GPIO 18 turned on");
            EventOutput event;
            event.type = GPIO_CHANGE;
            event.pin = 18;
            event.isOn = true;
            eventQueue.push(event);
        } else {
            logger("MQTT:   GPIO 18 turned off");
            EventOutput event;
            event.type = GPIO_CHANGE;
            event.pin = 18;
            event.isOn = false;
            eventQueue.push(event);
        }

        return;
    }

    if(strcmp(topic, (mqttBase + "/gpio/19/set").c_str()) == 0) {
        String payloadStr;
        for (size_t i = 0; i < length; i++) {
            payloadStr += static_cast<char>(payload[i]);
        }

        if(payloadStr == "ON") {
            logger("MQTT:   GPIO 19 turned on");
            EventOutput event;
            event.type = GPIO_CHANGE;
            event.pin = 19;
            event.isOn = true;
            eventQueue.push(event);
        } else {
            logger("MQTT:   GPIO 19 turned off");
            EventOutput event;
            event.type = GPIO_CHANGE;
            event.pin = 19;
            event.isOn = false;
            eventQueue.push(event);
        }

        return;
    }

    if(strcmp(topic, (mqttBase + "/gpio/21/set").c_str()) == 0) {
        String payloadStr;
        for (size_t i = 0; i < length; i++) {
            payloadStr += static_cast<char>(payload[i]);
        }

        if(payloadStr == "ON") {
            logger("MQTT:   GPIO 21 turned on");
            EventOutput event;
            event.type = GPIO_CHANGE;
            event.pin = 21;
            event.isOn = true;
            eventQueue.push(event);
        } else {
            logger("MQTT:   GPIO 21 turned off");
            EventOutput event;
            event.type = GPIO_CHANGE;
            event.pin = 21;
            event.isOn = false;
            eventQueue.push(event);
        }

        return;
    }

    if(strcmp(topic, (mqttBase + "/gpio/22/set").c_str()) == 0) {
        String payloadStr;
        for (size_t i = 0; i < length; i++) {
            payloadStr += static_cast<char>(payload[i]);
        }

        if(payloadStr == "ON") {
            logger("MQTT:   GPIO 22 turned on");
            EventOutput event;
            event.type = GPIO_CHANGE;
            event.pin = 22;
            event.isOn = true;
            eventQueue.push(event);
        } else {
            logger("MQTT:   GPIO 22 turned off");
            EventOutput event;
            event.type = GPIO_CHANGE;
            event.pin = 22;
            event.isOn = false;
            eventQueue.push(event);
        }

        return;
    }

    if(strcmp(topic, (mqttBase + "/gpio/23/set").c_str()) == 0) {

        String payloadStr;
        for (size_t i = 0; i < length; i++) {
            payloadStr += static_cast<char>(payload[i]);
        }

        if(payloadStr == "ON") {
            logger("MQTT:   GPIO 23 turned on");
            EventOutput event;
            event.type = GPIO_CHANGE;
            event.pin = 23;
            event.isOn = true;
            eventQueue.push(event);;
        } else {
            logger("MQTT:   GPIO 23 turned off");
            EventOutput event;
            event.type = GPIO_CHANGE;
            event.pin = 23;
            event.isOn = false;
            eventQueue.push(event);
        }

        return;
    }
}


int mqttHaReconnect() {
    
    // check if wifi is connected
    if (WiFi.status() != WL_CONNECTED) {
        return 0;
    }

    // if mqtt connected, disconnect first
    if(mqttClientHa.connected()) {
        mqttClientHa.disconnect();
    }

    int retries = 0;
    while (!mqttClientHa.connected() && retries < 5) {

        if (mqttClientHa.connect(appConfig.name, appConfig.haUser, appConfig.haPass, (String("pandaled/") + appConfig.name + "/status").c_str(), 1, true, "offline")) {
            logger("MQTT connected to Home Assistant");

            // send config
            if(!configSent) {
                mqttHaConfig();
                configSent = true;
                Serial.println("Config sent");
            }

            // subscribe to topics
            const String topic = String("pandaled/") + appConfig.name + String("/#");
            mqttClientHa.subscribe(topic.c_str());

            return 1;

        } else {
            logger("E:  HA MQTT failed with state " + String(mqttClientHa.state()));
            delay(2000);
            retries++;
        }
    }

    logger("E:  Failed to connect to HA MQTT after 5 retries");
    return 0;
}


bool mqttHaSetup() {

    if (!appConfig.haSet) {
        logger("E:  Home Assistant not configured!");
        return false;
    }

    mqttClientHa.setClient(wifiClientHa);
    mqttClientHa.setBufferSize(12000);
    mqttClientHa.setServer(appConfig.haIp, appConfig.haPort);
    mqttClientHa.setCallback(mqttHaListen);
    mqttClientHa.setSocketTimeout(20);

    return true;
}


void mqttHaLoop() {

    if(!appConfig.haSet) {
        return;
    }

    if (!mqttClientHa.connected()) {
        mqttHaReconnect();
    }

    mqttClientHa.loop();
}

#endif