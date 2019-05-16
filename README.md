# 9DoF
A collection of Arduino Sketches and Documents for the Relativty 9DoF Tracker Alpha Code Testers

The 9DoF_Tracker is a sketch based on the MPU-9250 sensor chip. 
Early version...

I have updated the 9DoF_Tracker sketch to 9DoF_Tracker2 which appears stable. Please test it.

The Relativ-BNO055-01 sketch is a 9DoF tracker based on the BNO055 sensor. You will need to install the Adafruit Unified Sensor Library and the Adafruit BNO055 Library to get it working. It uses the small, blue, rectangular, GY-BNO055 breakout boards that are widely available online. It was developed and tested using an STM32 but should work on other Arduino boards.

The Relativ-BNO055-01 sketch is pretty much ready to test in your headset right now, if you have a BNO055 board
The 9DoF_Tracker2 sketch should be headset ready too, if you have a 9250 board (or a 9255 board, if you follow the instructions)