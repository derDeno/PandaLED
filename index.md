---
title: Home
nav_order: 1
---

# Welcome to the PandaLED Docs
{: .fs-9 }

If you want to go straight to the web installer, just press the button below. 
Otherwise follow the getting started guide.
{: .fs-6 .fw-300 }

[Web installer](https://derdeno.github.io/PandaLED/web-installer.html){: .btn .btn-primary .fs-5 .mb-4 .mb-md-0 .mr-2 }
[Getting started](https://derdeno.github.io/PandaLED/getting-started/){: .btn .fs-5 .mb-4 .mb-md-0 }

---

{: .note }
This documentation is for the current PandaLED rev. 1.5 board.


## What is PandaLED?
PandaLED is a control board for P1 and X1 Bambulab printers.
It allows you to connect WLED, classic (analog) LED strips or anything else which uses 12V or 24V and not more then 3A.

The board will control the connected devices depending on so called _events_. A full list of all available events can be found on the Mappings page.
Using the WebUI you can define mappings, which is a simple but powerful way to map events to outputs.

For example you can map a finished print event to the WLED output to turn the LEDs green and turn the off after 10 minutes.


## What makes this project special?
The biggest feature is the mapping tool. It provides you a very simple way to connect events with devices.
You don't need to change anything in the firmware or any coding skills.

Furthermore the exposed GPIO pins allow you to connect more things to the board or design a custom expansion board to expand the functionalities.


## Where can I get this board?
Currently the board is in its final development phase and therefore not purchasable.
But I plan to provide a way to preorder the board in the near future.
If you don't want to miss any updates, please join our [Discord](https://discord.gg/8VhnsCXKun)

The whole project is open source, so you can modify it how ever you like.


## How can I support this project?
![](../assets/img/jlcpcb.png)

This project is currently sponsored by JLCPCB, but can also be supported by anyone else.
If you want to support this project, please reach out to me on Discord [here](https://discord.gg/8VhnsCXKun) or help improving the code here on [GitHub](https://github.com/derDeno/PandaLED).