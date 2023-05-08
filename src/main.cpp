#include <Arduino.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <WiFiClientSecure.h>
#include "WiFi.h"
#include "ArduinoJson.h"

#include "./appState/appState.h"
#include "./wifi/wifiInit.h"
#include "./aws/aws.h"
#include "secrets.h"

void setup()
{
  Serial.begin(9600);
  AppState::getInstance();
  // initializeWifi();
  // connectAWS();
  Serial.println("Setup done");
}

void loop()
{

  // publishAWSMessage();
  // awsClient.loop();
  delay(10000);
}