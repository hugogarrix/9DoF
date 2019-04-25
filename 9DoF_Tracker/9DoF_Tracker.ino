/*
 * Relativty 9DoF Arduino MPU-9250 Tracker Code
 * © 2019 Relativty
 * Version 0.1
 * Author: justin@relativty.net
 */


#include "MPU9250.h"

MPU9250 mpu;

void setup()
{
    Serial.begin(115200);

    Wire.begin();

    delay(2000);
    
    mpu.setup();
}

void loop()
{
    static uint32_t prev_ms = millis();
    if ((millis() - prev_ms) > 16)
    {
        mpu.update();

        Serial.print(mpu.getQuaternion(0));Serial.print(",");
        Serial.print(mpu.getQuaternion(1));Serial.print(",");
        Serial.print(mpu.getQuaternion(2));Serial.print(",");
        Serial.println(mpu.getQuaternion(3));

        prev_ms = millis();
    }
}
