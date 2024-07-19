#include <Arduino.h>

int sensorValue = 0;
float inputVoltage = 0.0;
float batteryVoltage = 0.0;
const float R1 = 150000.0;  // R1 (150kΩ)
const float R2 = 90000.0;   // R2 (90kΩ)
const float maxVoltage = 8.4;
const float ratedVoltage = 7.4;
const float minVoltage = 6.8;
// Linear Regression variables 
const float m = 1.124;  
const float b = 0.174;

void setup() {
  Serial.begin(115200);
}

void loop() {
  sensorValue = analogRead(A0);

  //analog value (0-1023) to corresponding voltage (0-3.3V)
  inputVoltage = sensorValue * (3.3 / 1023.0);

  //LInear regression
  inputVoltage = m * inputVoltage + b;
  
  // reading voltage to real voltage
  batteryVoltage = inputVoltage * (R1 + R2) / R2;
  
  // battery level
  float batteryLevel = (batteryVoltage - minVoltage) / (maxVoltage - minVoltage) * 100;
  if (batteryLevel > 100) batteryLevel = 100;
  if (batteryLevel < 0) batteryLevel = 0;


  //OUTPUT
  Serial.print("Input Voltage (A0): ");
  Serial.print(inputVoltage);
  Serial.print("V -> Battery Voltage: ");
  Serial.print(batteryVoltage);
  Serial.print("V -> Battery Level: ");
  Serial.print(batteryLevel);
  Serial.println("%");

  delay(1000);
}

//i'm rajesh
