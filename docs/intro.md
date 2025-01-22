---
title: PandaLED Docs
slug: /
sidebar_position: 1
---

<h1 align="center">PandaLED Docs</h1>

<div align="center">
    <img width="200" src={require('/img/logo.png').default} />
</div>

<div align="center">
    ESP32 based controller for Bambu Lab Printer (P1/X1) to controll LEDs or other devices.

    ![GitHub Release](https://img.shields.io/github/v/release/derDeno/BLWLED?style=for-the-badge&label=PandaLED&color=blueviolet)
    <br/>

    [![license](https://img.shields.io/badge/license-CC--BY--NC--SA--4.0-blue)](https://github.com/derDeno/PandaLED/blob/HEAD/LICENSE)
    ![GitHub Issues or Pull Requests](https://img.shields.io/github/issues/derDeno/PandaLED)
    [![prettier](https://img.shields.io/badge/code_style-prettier-ff69b4.svg)](https://github.com/prettier/prettier)
    [![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](https://github.com/derDeno/PandaLED/blob/HEAD/CONTRIBUTING.md#pull-requests)
    <br />

</div>

# Introduction
If you want to go straight to the web installer, just press the button below. 
Otherwise, follow the getting started guide found in the sidebar.

<br/>
<Button label="Web Installer" size="lg" link="https://derdeno.github.io/PandaLED/web-installer.html" />
<br/><br/>
* * *

![](/img/pcb.png)

## What is PandaLED?
PandaLED is a control board designed for P1 and X1 Bambu Lab printers. It allows you to connect WLED, classic (analog) LED strips, or any device operating on 12V or 24V with a maximum current of 3A.

The board controls connected devices based on events. A complete list of available events is provided on the Mappings page. Using the WebUI, you can define mappings, which provide a simple yet powerful way to associate events with outputs.

**Example:**
You can map a "finished print" event to the WLED output to turn the LEDs green and have them turn off automatically after 10 minutes.


## What makes this project special?
The standout feature of PandaLED is its mapping tool, which provides an intuitive way to connect events with devices. This eliminates the need for firmware modifications or coding skills.

Additionally, the exposed GPIO pins enable further customization, allowing you to connect additional devices or design custom expansion boards to enhance functionality.


## Where can I get this board?
Currently, the board is in its final development phase and is not yet available for purchase. However, a preorder option is planned for the near future.

To stay updated, consider joining our [Discord community](https://discord.gg/8VhnsCXKun).

The entire project is open-source, giving you the freedom to modify it as you like.



## How can I support this project?
![](/img/jlcpcb.png)

This project is currently sponsored by JLCPCB but welcomes additional support from the community. 

If you're interested in supporting this project, you can:

- Reach out on Discord [here](https://discord.gg/8VhnsCXKun).
- Contribute to the codebase on [GitHub](https://github.com/derDeno/PandaLED/blob/HEAD/CONTRIBUTING.md#pull-requests).

Your contributions and support are greatly appreciated!