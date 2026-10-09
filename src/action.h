#ifndef ACTION_H
#define ACTION_H

/*
* Actions are used to perform different actions on the pins,
* such as turning on or off, blinking, or setting a specific color.
*/

#include <Arduino.h>

extern AppConfig appConfig;
extern CRGB *leds;

int wledBlinkTime = 0;
bool wledAnimationBreak = false;


/**
 * Pin Control action. Perform action defined by EventOutput
 * @param event     EventOutput type
 */
void actionPinControl(EventOutput event) {
    if (event.blink) {
        for (int i = 0; i < event.blinkCount; i++) {
            digitalWrite(event.pin, HIGH);
            delay(event.blinkDelay);
            digitalWrite(event.pin, LOW);
            delay(event.blinkDelay);
        }
    } else if (event.isOn && event.brightness > 0) {

        const int invertStart = millis();
        bool breakLoop = false;
        analogWrite(event.pin, event.brightness);

        if(event.invert && event.invertDelay > 0) {
            while (!breakLoop) {
                if (millis() - invertStart < event.invertDelay * 1000) {
                    break;
                }

                breakLoop = true;
                analogWrite(event.pin, 0);
            }
        }
    } else if (event.isOn) {

        const int invertStart = millis();
        bool breakLoop = false;
        digitalWrite(event.pin, HIGH);

        if(event.invert && event.invertDelay > 0) {
            while (!breakLoop) {
                if (millis() - invertStart < event.invertDelay * 1000) {
                    break;
                }

                breakLoop = true;
                digitalWrite(event.pin, LOW);
            }
        }
    } else {
        const int invertStart = millis();
        bool breakLoop = false;
        digitalWrite(event.pin, LOW);

        if(event.invert && event.invertDelay > 0) {
            while (!breakLoop) {
                if (millis() - invertStart < event.invertDelay * 1000) {
                    break;
                }

                breakLoop = true;
                digitalWrite(event.pin, HIGH);
            }
        }
    }
}


/**
 * WLED Control action. Perform action defined by EventOutput
 * @param event     EventOutput type
 */
void actionColorWled(EventOutput event) {
    wledAnimationBreak = true;
    delay(10);

    int lastR = leds[0].r;
    int lastG = leds[0].g;
    int lastB = leds[0].b;
    FastLED.clear(true);

    // check if brightness is set
    if(event.brightness > 0) {
        FastLED.setBrightness(event.brightness);
    }

    // load back last color if no color is set
    if(event.r == 0 && event.g == 0 && event.b == 0) {
        event.r = lastR;
        event.g = lastG;
        event.b = lastB;
    }
    
    fill_solid(leds, appConfig.count, CRGB(event.r, event.g, event.b));

    if (event.blink) {
        for (int i = 0; i < event.blinkCount; i++) {
            FastLED.show();
            delay(event.blinkDelay);
            FastLED.clear(true);
            delay(event.blinkDelay);
        }
    } else {
        int invertStart = millis();
        bool breakLoop = false;
        FastLED.show();

        if(event.invert && event.invertDelay > 0) {
            while (!breakLoop) {
                if (millis() - invertStart < event.invertDelay * 1000) {
                    break;
                }

                breakLoop = true;
                FastLED.clear(true);
            }
        }
    }

    /*
    for (int i = 0; i < appConfig.count; i++) {
        leds[i].r = event.r;
        leds[i].g = event.g;
        leds[i].b = event.b;
    }
    */
}


// Turn off WLED
void actionColorWledOff() {
    wledAnimationBreak = true;
    FastLED.clear(true);
}



/**
 * Color Control action. Perform action defined by EventOutput
 * @param event     EventOutput type
 */
void actionColorAnalog(EventOutput event) {

    // first check if to blink
    if (event.blink) {
        analogWrite(ANALOG_PIN_R, event.r);
        analogWrite(ANALOG_PIN_G, event.g);
        analogWrite(ANALOG_PIN_B, event.b);
        analogWrite(ANALOG_PIN_WW, 0);
        analogWrite(ANALOG_PIN_CW, 0);
        delay(event.blinkDelay * 1000);

        analogWrite(ANALOG_PIN_R, 0);
        analogWrite(ANALOG_PIN_G, 0);
        analogWrite(ANALOG_PIN_B, 0);
        analogWrite(ANALOG_PIN_WW, 0);
        analogWrite(ANALOG_PIN_CW, 0);
        delay(event.blinkDelay * 1000);

        // turn off after delay
        if (event.invert && event.invertDelay > 0) {
            delay(event.invertDelay * 1000);
            analogWrite(ANALOG_PIN_R, 0);
            analogWrite(ANALOG_PIN_G, 0);
            analogWrite(ANALOG_PIN_B, 0);
            analogWrite(ANALOG_PIN_WW, 0);
            analogWrite(ANALOG_PIN_CW, 0);
        }

    } else {
        analogWrite(ANALOG_PIN_R, event.r);
        analogWrite(ANALOG_PIN_G, event.g);
        analogWrite(ANALOG_PIN_B, event.b);
        analogWrite(ANALOG_PIN_WW, 0);
        analogWrite(ANALOG_PIN_CW, 0);

        if (event.invert && event.invertDelay > 0) {
            delay(event.invertDelay * 1000);
            analogWrite(ANALOG_PIN_R, 0);
            analogWrite(ANALOG_PIN_G, 0);
            analogWrite(ANALOG_PIN_B, 0);
            analogWrite(ANALOG_PIN_WW, 0);
            analogWrite(ANALOG_PIN_CW, 0);
        }
    }
}


/**
 * Turn off Analog Pins
 * @param pin       pin or 0 for all analog pins
 */
void actionAnalogOff(const uint8_t pin) {

    if(pin == 0) {
        analogWrite(ANALOG_PIN_R, 0);
        analogWrite(ANALOG_PIN_G, 0);
        analogWrite(ANALOG_PIN_B, 0);
        analogWrite(ANALOG_PIN_WW, 0);
        analogWrite(ANALOG_PIN_CW, 0);
        return;
    }

    analogWrite(pin, 0);
}




/**
 * WLED Rainbow action
 * @param brightness        brightness value 1-255
 * @param speed             how many hue steps to take 1-255
 */
void actionWledRainbow(int brightness = 255, int speed = 10) {
    FastLED.setBrightness(brightness);
    wledAnimationBreak = false;

    uint8_t hue = 0;
    while (!wledAnimationBreak) {
        //fill_rainbow(leds, appConfig.count, hue, speed);
        fill_rainbow_circular(leds, appConfig.count, hue);
        FastLED.show();

        hue += speed;
        delay(10);
    }

    wledAnimationBreak = true;
    FastLED.clear(true);
}

#endif