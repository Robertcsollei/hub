#ifndef APP_STATE
#define APP_STATE

#include <ArduinoJson.h>
#include <SPIFFS.h>

#include "relaySchema.h"
#include "../xfs/loadedData.h"
#include "../xfs/xfs.h"

class AppState
{
public:
    static AppState &getInstance()
    {
        static AppState instance;
        return instance;
    }
    
    RelaySchema relays;
    char ssid[25];
    char password[25];
    char port[25];

private:
    XFS fs;
    AppState()
    {
        Serial.println("Initializing App State...");
        LoadedData file = fs.load("/relays.json");
        DynamicJsonDocument doc(file.size);
        auto error = deserializeJson(doc, file.data);
        if (error)
        {
            Serial.println("Failed to read file, using default configuration");
        }
        Serial.println("App State Initialized!");
        // TODO fill relays with the incoming data from relays.json
        delete file.data;
    };
    AppState(AppState const &) = delete;
    void operator=(AppState const &) = delete;
};

#endif