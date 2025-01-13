---
title: What To Connect
sidebar_position: 2
---

# What Can I Connect to the PandaLED

The PandaLED PCB offers two primary outputs, along with GPIO pins for added flexibility. 
Below is an overview of the available connections and their specifications.


## WLED

The WLED output port is a 3-pin connector designed exclusively for use with 5V LED strips, such as the WS2812b.

- Port Type: 3-pin
- Voltage: 5V using USB-C or using the DC connector with 12V or 24V.
- Supported LEDs: WS2812b (5V)
- Pin Layout: Printed on the bottom side of the PCB


## Generic / Analog

The Analog output port is a 6-pin connector capable of delivering either 12V or 24V, depending on the connected power source. This port is inactive if the board is powered solely via USB-C.

- Port Type: 6-pin
- Voltage: 12V or 24V only. Powering using USB-C will not work.
- Usage: Designed for RGB CCT LED strips but can be repurposed for other devices due to PWM control or on/off switching capabilities
- Pin Layout: Printed on the bottom side of the PCB

:::danger
Never use USB-C and DC at the same time. Only one power source at a time is supported. Otherwise you will damage the PCB!
:::


## GPIO

![](/img/gpio%20pins.png)

The PCB includes a range of GPIO pins, enabling you to expand the board's functionality with additional features or extension boards. 
The GPIO pin layout is as follows (viewed from the top):

<table>
    <tr>
        <td>3.3V</td>
        <td>EN</td>
        <td>TX</td>
        <td>RX</td>
        <td>IO 0</td>
        <td>IO 33</td>
        <td>Ground</td>
        <td>5V</td>
    </tr>
    <tr>
        <td>Ground</td>
        <td>VP</td>
        <td>VN</td>
        <td>IO 34</td>
        <td>IO 35</td>
        <td>IO 32</td>
        <td>Ground</td>
        <td>VCC (12V/24V)</td>
    </tr>
</table>
<br/>

This table is also printed on the bottom of the PCB.


:::info
- Ensure proper voltage compatibility when connecting devices.
- Refer to the PCB's printed labels for accurate connections.
:::
