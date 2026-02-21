#ifndef CONFIG_H
#define CONFIG_H

#define WIFI_SSID "AG NETWORK"
#define WIFI_PASS "ga00ga01"

#define MQTT_SERVER "broker.hivemq.com"
#define MQTT_PORT 1883

#define TOPIC_LED_STATUS "gaance/esp32/led/status"
#define TOPIC_LED_COMMAND "gaance/esp32/led/cmd"

#define TOPIC_SERVO_STATUS "gaance/esp32/servo/status"
#define TOPIC_SERVO_COMMAND "gaance/esp32/servo/cmd"

#endif