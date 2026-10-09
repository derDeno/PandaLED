#include <Arduino.h>

extern AppConfig appConfig;
extern CRGB *leds;
extern EventQueue eventQueue;

bool maintenanceToggle = false;

/**
 * Printer event types
 */
typedef enum {
    EVENT_SW_CLICK,
    EVENT_PRINTER_IDLE,
    EVENT_PREHEAT_BED,
    EVENT_CLEANING_NOZZLE,
    EVENT_BED_LEVELING,
    EVENT_EXTRUSION_CALIBRATION,
    EVENT_PRINTING,
    EVENT_PRINT_FINISHED,
    EVENT_PRINT_FAILED,
    EVENT_DOOR_OPEN_IDLE,
    EVENT_DOOR_CLOSE_IDLE,
    EVENT_DOOR_OPEN_PRINT,
    EVENT_DOOR_CLOSE_PRINT,
    EVENT_DOOR_OPEN_FINISH,
    EVENT_DOOR_CLOSE_FINISH,
    EVENT_LIGHT_ON,
    EVENT_LIGHT_OFF,
    EVENT_PRINTER_STANDBY,
    EVENT_RAINBOW,
} EventPrinter;


/**
 * Convert pin name to pin number
 * @deprecated      This function is deprecated and will be removed in future versions
 * 
 * @param output    pin name
 * @return          pin number
 */
int outputToPin(const char* output) {
    if (strcmp(output, "analog-r") == 0) {
        return ANALOG_PIN_R;
    } else if (strcmp(output, "analog-g") == 0) {
        return ANALOG_PIN_G;
    } else if (strcmp(output, "analog-b") == 0) {
        return ANALOG_PIN_B;
    } else if (strcmp(output, "analog-ww") == 0) {
        return ANALOG_PIN_WW;
    } else if (strcmp(output, "analog-cw") == 0) {
        return ANALOG_PIN_CW;
    } else {
        // default
        return atoi(output);
    }
}



/**
 * Maintenance event. Toggle maintenance mode
 */
void eventMaintenance() {
    if (!maintenanceToggle) {
        if (appConfig.wled) {

            EventOutput event;
            event.type = WLED_CHANGE;
            event.isOn = true;
            event.r = 255;
            event.g = 255;
            event.b = 255;
            event.brightness = 255;

            eventQueue.push(event);

        } else if (appConfig.analog) {
            if (appConfig.mode == 1) {

                EventOutput event;
                event.type = ANALOG_CHANGE;
                event.isOn = true;
                event.r = 255;
                event.g = 255;
                event.b = 255;
                event.brightness = 255;

                eventQueue.push(event);
            }
        }

        maintenanceToggle = true;
    } else {
        if (appConfig.wled) {

            EventOutput event;
            event.type = WLED_CHANGE;
            event.isOn = false;

            eventQueue.push(event);

        } else if (appConfig.analog) {
            if (appConfig.mode == 1) {

                EventOutput event;
                event.type = ANALOG_CHANGE;
                event.isOn = false;

                eventQueue.push(event);
            }
        }

        maintenanceToggle = false;
    }
}


/**
 * Printer Event Bus.
 * Map printer events to output events and add them to the event queue
 * basically the most important part happens here. 
 * The custom user events are mapped against the printer events and the converted to output events.
 * 
 * @param eventPrinter     EventPrinter type
 */
void printerEventBus(EventPrinter eventPrinter) {
    EventOutput eOutput;
    
    switch (eventPrinter) {
        case EVENT_SW_CLICK: {
            logger("Event: SW Click");
            if (appConfig.sw) {
                if (appConfig.action == 1) {
                    eventMaintenance();
                } else if (appConfig.action == 2) {
                    ESP.restart();
                }
            }
        }
        break;
        case EVENT_PRINTER_IDLE: {
            logger("Event: Printer Idle");
        }
        break;
        case EVENT_PREHEAT_BED: {
            logger("Event: Preheat Bed");
            eOutput.type = WLED_CHANGE;
            eOutput.isOn = true;
            eOutput.brightness = 125;
            eOutput.r = 0;
            eOutput.g = 0;
            eOutput.b = 255;
        }
        break;
        case EVENT_CLEANING_NOZZLE: {
            logger("Event: Cleaning Nozzle");
            eOutput.type = WLED_CHANGE;
            eOutput.isOn = false;
        }
        break;
        case EVENT_BED_LEVELING: {
            logger("Event: Bed Leveling");
            eOutput.type = WLED_CHANGE;
            eOutput.isOn = false;
        }
        break;
        case EVENT_EXTRUSION_CALIBRATION: {
            logger("Event: Extrusion Calibration");
            eOutput.type = WLED_CHANGE;
            eOutput.isOn = false;
        }
        break;
        case EVENT_PRINTING: {
            logger("Event: Printing");
            eOutput.type = WLED_CHANGE;
            eOutput.isOn = true;
            eOutput.brightness = 50;
            eOutput.r = 255;
            eOutput.g = 255;
            eOutput.b = 255;
        }
        break;
        case EVENT_PRINT_FINISHED: {
            logger("Event: Print Finished");
            eOutput.type = WLED_CHANGE;
            eOutput.isOn = true;
            eOutput.brightness = 125;
            eOutput.r = 0;
            eOutput.g = 255;
            eOutput.b = 0;
        }
        break;
        case EVENT_PRINT_FAILED: {
            logger("Event: Print Failed");
            eOutput.type = WLED_CHANGE;
            eOutput.isOn = true;
            eOutput.brightness = 125;
            eOutput.r = 255;
            eOutput.g = 0;
            eOutput.b = 0;
        }
        break;
        case EVENT_DOOR_OPEN_IDLE: {
            logger("Event: Door Open Idle");
            eOutput.type = WLED_CHANGE;
            eOutput.isOn = true;
            eOutput.brightness = 255;
            eOutput.r = 255;
            eOutput.g = 255;
            eOutput.b = 255;
        }
        break;
        case EVENT_DOOR_CLOSE_IDLE: {
            logger("Event: Door Close Idle");
            eOutput.type = WLED_CHANGE;
            eOutput.isOn = true;
            eOutput.brightness = 50;
            eOutput.r = 255;
            eOutput.g = 255;
            eOutput.b = 255;
        }
        break;
        case EVENT_DOOR_OPEN_PRINT: {
            logger("Event: Door Open Print");
        }
        break;
        case EVENT_DOOR_CLOSE_PRINT: {
            logger("Event: Door Close Print");
        }
        break;
        case EVENT_DOOR_OPEN_FINISH: {
            logger("Event: Door Open Finish");
            eOutput.type = WLED_CHANGE;
            eOutput.isOn = true;
            eOutput.brightness = 255;
            eOutput.r = 255;
            eOutput.g = 255;
            eOutput.b = 255;
        }
        break;
        case EVENT_DOOR_CLOSE_FINISH: {
            logger("Event: Door Close Finish");
            eOutput.type = WLED_CHANGE;
            eOutput.isOn = false;
        }
        break;
        case EVENT_LIGHT_ON: {
            logger("Event: Light On");
            eOutput.type = WLED_CHANGE;
            eOutput.isOn = true;
            eOutput.brightness = 125;
            eOutput.r = 255;
            eOutput.g = 255;
            eOutput.b = 255;
        }
        break;
        case EVENT_LIGHT_OFF: {
            logger("Event: Light Off");
            eOutput.type = WLED_CHANGE;
            eOutput.isOn = false;
        }
        break;
        case EVENT_PRINTER_STANDBY: {
            logger("Event: Printer Standby");
            eOutput.type = WLED_CHANGE;
            eOutput.isOn = false;
        }
        break;
        case EVENT_RAINBOW: {
            logger("Event: Rainbow");
            actionWledRainbow(255, 10);
        }
        break;
    }

    eventQueue.push(eOutput);
}


// ToDo: implement MQTT push
void eventLoop() {
    EventOutput event;

    while(!eventQueue.isEmpty()) {
        if(eventQueue.pop(event)) {
            Serial.println("Event type: " + String(event.type));
            switch(event.type) {
                case WLED_CHANGE: {
                    if(event.isOn) {

                        if(event.color.length() > 0) {
                            const char* hexColor = event.color.c_str() + 1;
                            unsigned long colorValue = strtoul(hexColor, NULL, 16);
                            event.r = (colorValue >> 16) & 0xFF;
                            event.g = (colorValue >> 8) & 0xFF;
                            event.b = colorValue & 0xFF;

                            actionColorWled(event);
                        } else {
                            actionColorWled(event);
                        }

                        // publish to mqtt
                        JsonDocument state;
                        state["state"] = "ON";
                        state["brightness"] = FastLED.getBrightness();
                        state["color"]["r"] = leds[0].r;
                        state["color"]["g"] = leds[0].g;
                        state["color"]["b"] = leds[0].b;

                        String stateStr;
                        serializeJson(state, stateStr);
                        mqttHaPublish("/wled/state", stateStr.c_str(), true);

                    } else {
                        actionColorWledOff();
                        mqttHaPublish("/wled/state", "{\"state\":\"OFF\"}", true);
                    }
                }
                break;

                case ANALOG_CHANGE: {
                    if(event.isOn) {
                        if(event.color.length() > 0) {
                            const char* hexColor = event.color.c_str() + 1;
                            unsigned long colorValue = strtoul(hexColor, NULL, 16);
                            event.r = (colorValue >> 16) & 0xFF;
                            event.g = (colorValue >> 8) & 0xFF;
                            event.b = colorValue & 0xFF;

                            actionColorAnalog(event);
                        }else {
                            actionColorAnalog(event);
                        }

                        // publish to mqtt
                        JsonDocument state;
                        state["state"] = "ON";
                        state["brightness"] = event.brightness;
                        state["color"]["r"] = event.r;
                        state["color"]["g"] = event.g;
                        state["color"]["b"] = event.b;

                        String stateStr;
                        serializeJson(state, stateStr);
                        mqttHaPublish("/analog/state", stateStr.c_str(), true);

                    } else {
                        actionAnalogOff(0);
                        mqttHaPublish("/analog/state", "{\"state\":\"OFF\"}", true);
                    }
                }    
                break;

                case ANALOG_PIN_CHANGE: {
                    // handle analog pin event
                }
                break;

                case GPIO_CHANGE: {
                    actionPinControl(event);

                    // publish to mqtt
                    String topic = "/gpio/" + String(event.pin) + "/state";
                    if(event.isOn) {
                        mqttHaPublish(topic.c_str(), "ON", true);
                        Serial.println(topic);
                    } else {
                        mqttHaPublish(topic.c_str(), "OFF", true);
                    }
                }
                break;

                case WLED_RAINBOW: {
                    actionWledRainbow(event.brightness, 10);
                }
                break;
            }
        }
    }
}