#ifndef AWS
#define AWS

#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <WiFiClientSecure.h>
#include "secrets.h"

#define AWS_IOT_PUBLISH_TOPIC "esp32/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "esp32/sub"

WiFiClientSecure net = WiFiClientSecure();
PubSubClient awsClient(net);

void messageHandler(char *topic, byte *payload, unsigned int length)
{
    Serial.print("incoming: ");
    Serial.println(topic);

    StaticJsonDocument<200> doc;
    deserializeJson(doc, payload);
    const char *message = doc["message"];
    Serial.println(message);
}

void connectAWS()
{

    // Configure WiFiClientSecure to use the AWS IoT device credentials
    net.setCACert(AWS_CERT_CA);
    net.setCertificate(AWS_CERT_CRT);
    net.setPrivateKey(AWS_CERT_PRIVATE);

    // Connect to the MQTT broker on the AWS endpoint we defined earlier
    awsClient.setServer(AWS_IOT_ENDPOINT, 8883);

    // Create a message handler
    awsClient.setCallback(messageHandler);

    Serial.println("Connecting to AWS IOT");

    while (!awsClient.connect(THING_NAME))
    {
        Serial.print(".");
        delay(100);
    }

    if (!awsClient.connected())
    {
        Serial.println("AWS IoT Timeout!");
        return;
    }

    // Subscribe to a topic
    awsClient.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);

    Serial.println("AWS IoT Connected!");
}

void publishAWSMessage()
{
    StaticJsonDocument<200> doc;
    doc["humidity"] = 30;
    doc["temperature"] = 15;
    char jsonBuffer[512];
    serializeJson(doc, jsonBuffer); // print to client

    awsClient.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
}

#endif
