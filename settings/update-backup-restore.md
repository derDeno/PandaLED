---
title: Update, Backup & Restore
parent: Settings
nav_order: 5
---

# Update, Backup & Restore

On this page you have the option to update your board using over the air using a firmware file found under releases, download a backup file of your settings and also to restore these settings.
<br><br>

## Update order
If there is an update to the firmware and filesystem, it is important to update the filesystem first and then the firmware. If there is no filesystem update, just update the firmware.
If you are downgrading, the filesystem needs to be updated first too.


## Update files
The update files can be found [here](https://github.com/derDeno/PandaLED/releases). Donwload the firmware and fs binary files and upload the according to the update order.


### Firmware
The firmware binary updates the firmware it self. This is the code which makes the PandaLED work.


### Filesystem
This is mainly the WebUI files.


## Backup
This generates a <i>.pandaled</i> which contains all your settings. You can use this to backup your settings if you plan to reset the device or upload it to a new board.
This is basically a json file.


## Restore
Here you can upload a backup file. The PandaLED will reboot afterwards and may connect to another WiFi if set so in the backup.