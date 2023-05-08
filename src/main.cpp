#include <Arduino.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <WiFiClientSecure.h>
#include "WiFi.h"

#include "./wifi/wifiInit.h"
#include "./aws/aws.h"
#include "secrets.h"


void setup()
{
  Serial.begin(9600);

  initializeWifi();
  connectAWS();
}

void loop()
{

  publishAWSMessage();
  client.loop();
  delay(10000);
}