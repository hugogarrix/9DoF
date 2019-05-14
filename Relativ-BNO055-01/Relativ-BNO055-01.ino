//
// Relativ-BNO055
//
// Version: 0.6
// Date: 14 May 2019
//
// You will need to install the following libraries into your Arduino IDE:
//    Adafruit BNO055
//    Adafruit Unified Sensor
//
// The Relativty 9DoF Tracker Sketch for the BNO055 breakout board is largely based on the
// Adafruit rawdata sketch. However, it has been modified to work with the Chinese clone 
// BNO055 boards that are widely available online. It should work with most Arduino boards
// but it has been tested predominantly with a Robotdyn Black Pill STM32 board. 
//
//           BNO055          STM32
//           ------          -----
//             VIN            3v3
//             GND            GND
//            SCL/Rx           B6
//            SDA/Tx           B7
//
// WARNING: After you have flashed this sketch, you may need to disconnect then reconnect your
//          arduino a couple of times before it will run. No, I don't know why this happens either.
//
// When you are first testing that everything works, set SerialDebug true below. Once you have tested
// it all & are happy, set SerialDebug false, reflash it, and it will be ready to use in your headset


#include <Wire.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>



// Debug: set to true to get very verbose Serial output & to slow down the data stream
//#define SerialDebug true
#define SerialDebug false


// Debug: Slow down the data stream, so you can actually see the data
#define BNO055_SAMPLERATE_DELAY_MS (100)


// I2C is usually 0x28 or 0x29
Adafruit_BNO055 bno = Adafruit_BNO055(55,0x29);


void setup(void)
{
  
  Serial.begin(115200);

  // Check that the sensor initialised correctly
  if(!bno.begin())
  {
    // but if it dodn't, print this error message...
    Serial.print("No BNO055 detected... Is your I2C address correct?");
    while(1);
  }

  // Wait a second for everything to settle
  delay(1000);

  // Are you using an external clock crystal (if you didn't physically solder one onto the board, you aren't!)
  bno.setExtCrystalUse(false);

  // Debug: Print header blurb
  if(SerialDebug) {
  Serial.println("Calibration status values: 0=uncalibrated, 3=fully calibrated");
  }
}


void loop(void)
{
  
  // Quaternion data
  imu::Quaternion quat = bno.getQuat();

  if(SerialDebug) {

    Serial.print(" QUATERNIONS  qX: ");
    Serial.print(quat.x(), 4);
    Serial.print(" qY: ");
    Serial.print(quat.y(), 4);
    Serial.print(" qZ: ");
    Serial.print(quat.z(), 4);
    Serial.print(" qW: ");
    Serial.print(quat.w(), 4);
    Serial.print("\t\t");

  }

  else {

    Serial.print(quat.x(), 4);
    Serial.print(",");
    Serial.print(quat.y(), 4);
    Serial.print(",");
    Serial.print(quat.z(), 4);
    Serial.print(",");
    Serial.println(quat.w(), 4);

  }
    
  
  if(SerialDebug) {
    // Debug: Display calibration status for each sensor.
    uint8_t system, gyro, accel, mag = 0;
    bno.getCalibration(&system, &gyro, &accel, &mag);
    Serial.print("CALIBRATION: Sys=");
    Serial.print(system, DEC);
    Serial.print(" Gyro=");
    Serial.print(gyro, DEC);
    Serial.print(" Accel=");
    Serial.print(accel, DEC);
    Serial.print(" Mag=");
    Serial.println(mag, DEC);
  }

  if(SerialDebug) {
    // Debug: Slow it all down so you can see the data change
    delay(BNO055_SAMPLERATE_DELAY_MS);
  }
}
