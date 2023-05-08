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

private:
    XFS fs;
    AppState()
    {
        Serial.println("Reading file");
        LoadedData file = fs.load("/relays.json");
        Serial.println(file.data);
        DynamicJsonDocument doc(file.size);
        auto error = deserializeJson(doc, file.data);
        if (error)
        {
            Serial.println("Failed to read file, using default configuration");
        }
        Serial.println("Initing AppState Done");
        delete file.data;
    };
    AppState(AppState const &) = delete;
    void operator=(AppState const &) = delete;
};

#endif