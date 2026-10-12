#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <FastLED.h>
#include <Preferences.h>
#include <WiFi.h>
#include <time.h>

#include "_dev.h"
#include "fs-helper.h"
#include "config.h"
#include "log.h"
#include "event-queue.h"
#include "wifi-helper.h"
#include "led-helper.h"
#include "action.h"
#include "mqtt-ha.h"
#include "events.h"
#include "mqtt-helper.h"
#include "webserver.h"


AppConfig appConfig;
AsyncWebServer server(80);
AsyncEventSource events("/api/events");
Preferences pref;
CRGB* leds;
EventQueue eventQueue;

int swState = HIGH;
int lastSwState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned const long debounceDelay = 1000;

bool blockWifi = false;

void initConfig() {
    
    // FS Version
    char versionBuffer[13];
    readFsVersion(versionBuffer, sizeof(versionBuffer));
    strcpy(appConfig.versionFs, versionBuffer);

    // efuse data
    char* serialNumber;
    char* hwRev;
    getEfuseData(serialNumber, hwRev);
    appConfig.serialNumber = serialNumber;
    appConfig.hwRev = hwRev;

    pref.begin("deviceSettings");

    // set the board name (aka hostname) using 2 mac bytes
    uint8_t mac[4];
    esp_read_mac(mac, ESP_MAC_WIFI_STA);
    char boardName[15];
    snprintf(boardName, sizeof(boardName), "PandaLED-%02X%02X", mac[4], mac[5]);

    if (pref.getString("name", "").length() == 0) {
        pref.putString("name", boardName);
    }

    strcpy(appConfig.name, pref.getString("name", boardName).c_str());
    appConfig.wled = pref.getBool("wled", PREF_WLED);
    appConfig.count = pref.getInt("count", PREF_COUNT);
    strcpy(appConfig.order, pref.getString("order", PREF_ORDER).c_str());
    appConfig.analog = pref.getBool("analog", PREF_ANALOG);
    appConfig.mode = pref.getInt("mode", PREF_MODE);
    appConfig.sw = pref.getBool("sw", PREF_SW);
    appConfig.action = pref.getInt("action", PREF_ACTION);
    appConfig.logging = pref.getBool("logging", PREF_LOGGING);
    pref.end();

    pref.begin("printerSettings", true);
    appConfig.isX1 = pref.getBool("isX1", true);
    strcpy(appConfig.ip, pref.getString("ip", PREF_IP).c_str());
    strcpy(appConfig.ac, pref.getString("ac", PREF_AC).c_str());
    strcpy(appConfig.sn, pref.getString("sn", PREF_SN).c_str());
    appConfig.rtid = pref.getBool("rtid", PREF_RTID);
    appConfig.rtsb = pref.getInt("rtsb", PREF_RTSB);
    pref.end();

    pref.begin("haSettings", true);
    appConfig.haSet = pref.getBool("activate", true);
    strcpy(appConfig.haIp, pref.getString("ip", PREF_HA_IP).c_str());
    appConfig.haPort = pref.getInt("port", 1883);
    strcpy(appConfig.haUser, pref.getString("user", PREF_HA_USER).c_str());
    strcpy(appConfig.haPass, pref.getString("pass", PREF_HA_PASS).c_str());
    pref.end();

    pref.begin("wifi", true);
    appConfig.wifiSet = pref.getBool("set", true);
    strcpy(appConfig.ssid, pref.getString("ssid", PREF_SSID).c_str());
    strcpy(appConfig.pass, pref.getString("pass", PREF_PASS).c_str());
    pref.end();

    appConfig.printerSet = (strlen(appConfig.ip) > 0 && strlen(appConfig.ac) > 0 && strlen(appConfig.sn) > 0) ? true : false;
}

void setup() {
    Serial.begin(115200);
    delay(500);

    // Initialize LittleFS
    initFs();

    // Initialize application config
    initConfig();

    // Initialize WLED strip
    if(appConfig.wled) {
        setupWled();
    }

    // Initialize analog strip
    if(appConfig.analog) {
        setupAnalogLed();
    }

    if (!appConfig.wifiSet) {
        logger("WiFi not setup yet, starting AP Mode");
        setupWifiAp();
    } else {
        setupWifi();
    }

    // Pins def
    pinMode(SW_PIN, INPUT_PULLUP);
    pinMode(ANALOG_PIN_R, OUTPUT);
    pinMode(ANALOG_PIN_G, OUTPUT);
    pinMode(ANALOG_PIN_B, OUTPUT);
    pinMode(ANALOG_PIN_CW, OUTPUT);
    pinMode(ANALOG_PIN_WW, OUTPUT);
    pinMode(WLED_PIN, OUTPUT);

    // Setup server sent events
    events.onConnect([](AsyncEventSourceClient* client) {
        client->send("hello!", NULL, millis(), 1000);
        logger("Server Events: Client connected");
    });

    // Start server
    routing(server);
    server.addHandler(&events);
    server.begin();
    logger("HTTP server:  ok");
    logger(String(appConfig.name) + " is ready!");

    startupAnimation();

    // start mqtt for Home Assistant
    if (appConfig.haSet) {
        if (mqttHaSetup()) {
            mqttHaReconnect();
        }
    }

    // start mqtt for printer
    if (appConfig.printerSet) {
        if (mqttSetup()) {
            mqttReconnect();
        }
    }
    
}

void loop() {
    // react to switch press
    int reading = digitalRead(5);
    if (reading != lastSwState) {
        lastDebounceTime = millis();

        if (reading == LOW) {
            printerEventBus(EVENT_SW_CLICK);
        }
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
        lastDebounceTime = millis();
    }
    lastSwState = reading;

    // all the loops
    if (!blockWifi) {
        wifiLoop();
        mqttLoop();
        mqttHaLoop();
        eventLoop();
    }
}
