---
title: Device Settings
sidebar_position: 1
---

# Device Settings
On this page, you can configure various settings for your device.

:::info
Don't forget to save your changes!
:::


## WLED
- **Activation**: Enable this option to configure WLED settings.
- **Number of LEDs**: Set the number of WLED LEDs to use.
- **LED Color Order**: Default is set to GRB, which is compatible with most WLED strips.


## Analog LED
- **Activation**: Enable this option to configure the analog LED output.
- **Output Handling**: Choose between:
    - **LED Strip**: For standard "dumb" LED strips.
    - **Individual Pin Control**: For controlling each output pin independently.


## Onboard Switch
- **Activation**: Enable this option to define the onboard switch behavior.
- **Functionality**:
    - Fire an event (handled under mappings as "Onboard switch pressed").
    - Use it as a reboot button.


## Logging
- **Activation**: Enable this option to log events to a log file.
- **Details**: Refer to the [Debugging Guide](../debugging) for more information


## Reset Device
- **Function**: Resets the device to factory settings.

:::danger
This will delete all changes made by you.
:::


## Screenshot
![](/img/device-settings.png)