---
title: What to connect
nav_order: 3
---

# What can I connect to the PandaLED

The PCB has two outputs. The first one is the 3 pin output which is only usable with a WLED strip (WS2812b).
<br><br>

## WLED
The WLED output port is the 3 pin one. It is only usable with a 5V LED strip (WS2812b).
Pin layout is printed on the bottom side.
<br><br>

## Generic / Analog
The Analog output port is the 6 pin one. It delivers 12V or 24V, depending on the connected power source. If the board is power only by USB-C, then this output is inactive. Pin layout is printed on the bottom side.

The pins are labeled for usage with a RGB CCT Led strip, but can be used for anything else, as these pins are pwm controlled or simple on / off switches, depending how they are set up.
<br><br>

## GPIO
The PCB features a number of GPIO pins to allow you to extend the board with new features or extension boards. 
The GPIO pin layout looks like the following when you look at it from the top:

| 3.3V   | EN | TX | RX    | IO 0  | IO 33 | Ground | 5V            |
|--------|----|----|-------|-------|-------|--------|---------------|
| Ground | VP | VN | IO 34 | IO 35 | IO 32 | Ground | VCC (12V/24V) |


![](../../assets/img/gpio%20pins.png)
