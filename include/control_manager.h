#ifndef CONTROL_MANAGER_H
#define CONTROL_MANAGER_H

void control_init();
void control_update();
void control_set_servo_from_mqtt(int angle);
void control_set_led_from_mqtt(bool state);

#endif