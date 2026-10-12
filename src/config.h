/*
* AppConfig holds all relevant config values for the application.
*/

#include <Arduino.h>
#include <FastLED.h>

// System Defenition
#define HW1_6
// #define HW1_6
#define VERSION "0.1.55"

// Pins Defenition
#ifdef HW1_5
#define WLED_PIN 18
#define ANALOG_PIN_R 17
#define ANALOG_PIN_G 16
#define ANALOG_PIN_B 4
#define ANALOG_PIN_WW 15
#define ANALOG_PIN_CW 2
#define SW_PIN 5
#endif

#ifdef HW1_6
#define WLED_PIN 13
#define ANALOG_PIN_R 17
#define ANALOG_PIN_G 16
#define ANALOG_PIN_B 4
#define ANALOG_PIN_WW 15
#define ANALOG_PIN_CW 2
#define SW_PIN 14
#endif

#ifdef HW1_7
#define WLED_PIN 13
#define ANALOG_PIN_R 17
#define ANALOG_PIN_G 16
#define ANALOG_PIN_B 4
#define ANALOG_PIN_WW 15
#define ANALOG_PIN_CW 2
#define SW_PIN 0
#endif


// Default Pref values
#define PREF_WLED true
#define PREF_COUNT 79
#define PREF_ORDER "grb"
#define PREF_ANALOG false
#define PREF_MODE 1
#define PREF_SW true
#define PREF_ACTION 1
#define PREF_LOGGING false
#define PREF_RTID true
#define PREF_RTSB 600


/**
 * Application Configuration
 */
struct AppConfig {

    // system config
    char versionFs[13];     // version of the filesystem
    String serialNumber;      // serial number
    String hwRev;             // hardware revision


    // device config
    char name[65];          // device name
    bool wled;              // wled active
    uint8_t count;          // number of leds
    char order[4];          // led order
    bool analog;            // analog led active
    uint8_t mode;           // 1 = strip, 2 = individual
    bool sw;                // switch active
    uint8_t action;         // 1 = maintenance, 2 = reboot, 3 = disco
    bool logging;           // logging active


    // printer config
    bool printerSet;        // Was printer already set up
    bool isX1;              // Printer type. true = X1, false = P1
    char ip[16];            // printer ip
    char ac[9];             // access code
    char sn[16];            // serial number
    bool rtid;              // return to idle after door opened while print finished
    int rtsb;               // return to standby time in seconds


    // WiFi config
    bool wifiSet;           // Is WiFi config present
    char ssid[33];          // WiFi ssid
    char pass[64];          // WiFi password


    // Home Assistant config
    bool haSet;             // Is HA config present
    char haIp[16];          // HA mqtt ip
    uint16_t haPort;        // HA mqtt port
    char haUser[33];        // HA mqtt user
    char haPass[64];        // HA mqtt password

};