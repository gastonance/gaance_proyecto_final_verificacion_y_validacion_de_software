#include <unity.h>
#include "led.h"

void test_led_state() {
    led_set(true);
    TEST_ASSERT_TRUE(led_get());
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_led_state);
    UNITY_END();
}

void loop() {}