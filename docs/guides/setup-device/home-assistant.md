---
title: Home Assistant
sidebar_position: 4
---

# Home Assistant
PandaLED supports Home Assistant over MQTT.

The following is exposed to MQTT:
- Device information like device name, firmware version, settings page link
- WLED as light bulb
- Depending on device configuration:
    - Analog RGB light bulb
    - Analog Pins
- GPIO Pins as switches
- Reboot button


## Configuration
First you need to enable and configure the Home Assistant connection.
You need the IP address and port of your MQTT broker and the username / password.


## Usage
PandaLED exposes it self using discovery functionality, therefore your PandaLED will be automatically discovered by Home Assistant and added to your setup.
If you don't see it, try restarting your Home Assistant.
<br/><br/>

You can use this functionality, to implement your own automations without creating mappings on the PandaLED it self or to just monitor your PandaLED.
The integration is build to support multiple PandaLEDs in your network.


## General
You can also use the MQTT integration to also control / monitor your PandaLED without Home Assistant if you want. 
Just be sure to communicate the same way Home Assistant would.


## Screenshot
![](/img/ha-settings.png)