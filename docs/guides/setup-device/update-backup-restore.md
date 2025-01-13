---
title: Update, Backup & Restore
sidebar_position: 5
---

# Update, Backup & Restore
This page provides options to update your PandaLED board, back up your settings, and restore them when needed.


## Update Order
When updating the firmware or filesystem, follow this sequence:

1. Update the filesystem first, then update the firmware.
2. If no filesystem update is required, update only the firmware.
3. For downgrades, update the filesystem first.


## Update Files
Update files are available [here](https://github.com/derDeno/PandaLED/releases). 
Download the firmware and filesystem (fs) binary files, and upload them according to the [update order](#update-order).

### Firmware
- The firmware binary updates the core functionality of the PandaLED board.
- This is the code that drives the device's operations.


### Filesystem
- The filesystem binary contains the WebUI and related files.


## Backup
- Generates a _.pandaled_ file containing all your settings.
- Useful for resetting the device or transferring settings to a new board.
- The backup file is essentially a JSON file.


## Restore
- Upload a backup file to restore settings.
- The PandaLED will reboot after restoration.
- If the backup specifies a different Wi-Fi network, the device will attempt to connect to that network.