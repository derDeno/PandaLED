#ifndef FS_HELPER_H
#define FS_HELPER_H

#include <LittleFS.h>
#include <soc/efuse_reg.h>

/**
 * Read the version from the filesystem
 * @param versionBuffer     Buffer to store the version
 * @param bufferSize        Size of the buffer
 */
void readFsVersion(char* versionBuffer, size_t bufferSize) {
    File versionFile = LittleFS.open("/version.txt", "r");
    if (!versionFile) {
        Serial.println("Failed to open version file");
        versionBuffer[0] = '\0';
        return;
    }

    // Read characters until newline or end of file
    size_t index = 0;
    while (index < bufferSize - 1 && versionFile.available()) {
        char c = versionFile.read();
        if (c == '\n' || c == '\r') {
            break;
        }
        versionBuffer[index++] = c;
    }

    versionBuffer[index] = '\0';
    versionFile.close();
}

/**
 * Initialize the filesystem
 */
void initFs() {
    if (!LittleFS.begin()) {
        Serial.println("LittleFS mount failed, formatting...");
        LittleFS.format();

    } else if (!LittleFS.exists("/version.txt")) {
        Serial.println("Version file missing");

    } else {
        Serial.println("Filesystem mounted.");
    }
}


/**
* Read serial and hardware information from efuse
* @param serial    Serial number
* @param revision  Revision number
*/
void getEfuseData(char* &serial, char* &revision) {
    const int dataLen = 17;
    int numRegs = (dataLen + 3) / 4;
    uint8_t efuseBytes[numRegs * 4] = {0};

    for(int i=0; i<numRegs; i++) {
        uint32_t regValue = REG_READ(EFUSE_BLK3_RDATA0_REG + (i * 4));
        efuseBytes[i * 4 + 0] = (uint8_t)(regValue & 0xFF);
        efuseBytes[i * 4 + 1] = (uint8_t)((regValue >> 8) & 0xFF);
        efuseBytes[i * 4 + 2] = (uint8_t)((regValue >> 16) & 0xFF);
        efuseBytes[i * 4 + 3] = (uint8_t)((regValue >> 24) & 0xFF);
    }

    char efuseString[dataLen + 1];
    memcpy(efuseString, efuseBytes, dataLen);
    efuseString[dataLen] = '\0';

    char* delimiter = strchr(efuseString, '|');
    if (delimiter != NULL) {
        *delimiter = '\0';  // Replace '|' with '\0' to terminate the serial number string.
        serial = efuseString;
        revision = delimiter + 1;

        Serial.printf("Serial: %s\n", serial);
        Serial.printf("Revision: %s\n", revision);

    }else {
        serial = "n/a";
        revision = "n/a";

        Serial.println("Failed to read serial and revision");
    }
}

#endif