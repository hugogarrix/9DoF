/*
 * Relativty 9DoF Arduino MPU-9250 Tracker Code
 * © 2019 Relativty
 * Version 0.3
 * Date: 16/05/2019
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
        mpu.update();

        Serial.print(mpu.getQuaternion(3));Serial.print(",");
        Serial.print(mpu.getQuaternion(0));Serial.print(",");
        Serial.print(mpu.getQuaternion(1));Serial.print(",");
        Serial.println(mpu.getQuaternion(2));

        
    
}
