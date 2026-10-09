/*
* EventQueue class
* This class is a simple wrapper around std::queue to store events.
*/

#include <queue>

/*
* EventOutputType enum
*/
typedef enum {
    WLED_CHANGE,
    ANALOG_CHANGE,
    ANALOG_PIN_CHANGE,
    GPIO_CHANGE,
    WLED_RAINBOW,
} EventOutputType;


/*
* EventOutput struct
*/
struct EventOutput {
    EventOutputType type;
    
    String color = "";           // hex color

    // analog
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    uint8_t ww = 0;
    uint8_t cw = 0;

    // gpio
    uint8_t pin = 0;

    // general
    bool isOn = true;           // output state (on/off)
    uint8_t brightness = 0;        // pwm if not wled
    bool invert = false;        // should output be inverted
    int invertDelay = 0;        // delay before inverting output
    bool blink = false;         // should output blink
    int blinkDelay = 0;         // delay between blinks
    int blinkCount = 0;         // number of blinks (0 = infinite)

};


class EventQueue {
public:
    void push(const EventOutput& event) {
        queue.push(event);
    }

    bool pop(EventOutput& event) {
        if (queue.empty()) {
            return false;
        }

        event = queue.front();
        queue.pop();
        return true;
    }

    bool isEmpty() const {
        return queue.empty();
    }

private:
    std::queue<EventOutput> queue;
};
