#
# For the web installer we need one merged binary file that contains the firmware
#


import re

Import("env")


version = "0"
with open("src/config.h", "r", encoding="utf-8") as f:
    content = f.read()
    match = re.search(r'#define\s+VERSION\s+"(.*?)"', content)
    if match:
        version = match.group(1)
        
print("XXX - Firmware version:", version)


FIRMWARE_BIN = "$BUILD_DIR/${PROGNAME}.bin"
MERGED_BIN = "$BUILD_DIR/${PROGNAME}_" + version + ".bin"
BOARD_CONFIG = env.BoardConfig()


# Set offsets and extra images
env.Replace(
    ESP32_APP_OFFSET="0x10000",
    FLASH_EXTRA_IMAGES=[
        "0x1000 .pio/build/esp32dev/bootloader.bin",
        "0x8000 .pio/build/esp32dev/partitions.bin",
        "0x670000 .pio/build/esp32dev/littlefs.bin"
    ]    
)


def merge_bin(source, target, env):
    print("Merging firmware and other images into one binary...")

    flash_images = env.Flatten(env.get("FLASH_EXTRA_IMAGES", [])) + ["$ESP32_APP_OFFSET", FIRMWARE_BIN]

    # Run esptool to merge images into a single binary
    env.Execute(
        " ".join(
            [
                "$PYTHONEXE",
                "$OBJCOPY", # esptool.py
                "--chip",
                BOARD_CONFIG.get("build.mcu", "esp32"),
                "merge_bin",
                "--fill-flash-size",
                BOARD_CONFIG.get("upload.flash_size", "8MB"),
                "-o",
                MERGED_BIN,
            ]
            + flash_images
        )
    )


# Add a post action that runs esptoolpy to merge available flash images
env.AddPostAction(FIRMWARE_BIN, merge_bin)


# Patch the upload command to flash the merged binary at address 0x0
env.Replace(
    UPLOADERFLAGS=[
        f for f in env.get("UPLOADERFLAGS") if f not in env.Flatten(env.get("FLASH_EXTRA_IMAGES"))
    ] + ["0x0", MERGED_BIN],
    UPLOADCMD='"$PYTHONEXE" "$UPLOADER" $UPLOADERFLAGS',
)