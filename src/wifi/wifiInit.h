#ifndef WIFI_INIT
#define WIFI_INIT

#include <Arduino.h>
#include "WiFi.h"
#include "secrets.h"


const long maxWaitingTime = 20000;

void initializeWifi()
{
  Serial.begin(9600);
  delay(1000);

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
  Serial.println("");
  Serial.println("Connecting to WiFi network...");

  const unsigned long startTime = millis();

  while (WiFi.status() != WL_CONNECTED && millis() - startTime < maxWaitingTime)
  {
    Serial.print(".");
    delay(100);
  }

  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Connection timeout! The device could not establish WiFi connection!");
  }
  else
  {
    Serial.println("");
    Serial.println("WiFi connection established!");
    Serial.print("local ip: ");
    Serial.println(WiFi.localIP());
  }
}

#endif