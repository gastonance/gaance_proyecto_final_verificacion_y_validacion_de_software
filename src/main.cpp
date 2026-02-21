#include <WiFi.h>
#include <PubSubClient.h>
#include "config.h"
#include "led.h"
#include "servo.h"

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {

    String message;
    for (int i = 0; i < length; i++)
        message += (char)payload[i];

    if (String(topic) == TOPIC_LED_COMMAND) {
        led_set(message == "ON");
    }

    if (String(topic) == TOPIC_SERVO_COMMAND) {
        servo_set_angle(message.toInt());
    }
}

void reconnect() {
    while (!client.connected()) {
        if (client.connect("ESP32Client")) {
            client.subscribe(TOPIC_LED_COMMAND);
            client.subscribe(TOPIC_SERVO_COMMAND);
        }
    }
}

void setup() {
    Serial.begin(115200);

    led_init(2);
    servo_init(18);

    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED);

    client.setServer(MQTT_SERVER, MQTT_PORT);
    client.setCallback(callback);
}

void loop() {

    if (!client.connected())
        reconnect();

    client.loop();

    client.publish(TOPIC_LED_STATUS, led_get() ? "ON" : "OFF");

    char buffer[4];
    itoa(servo_get_angle(), buffer, 10);
    client.publish(TOPIC_SERVO_STATUS, buffer);

    delay(1000);
}