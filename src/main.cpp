#include <Arduino.h>
#include <Stepper.h>

// change this to fit the number of steps per revolution
const int stepsPerRevolution = 2048; 
// Adjustable range of 28BYJ-48 stepper is 0~17 rpm 
const int rolePerMinute = 15;
// 
const int stoprevolution = 0;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() 
{
  myStepper.setSpeed(rolePerMinute);
  // initialize the serial port:
  Serial.begin(9600);
}


void loop() 
{
  char inputVariable = Serial.read();
  if( inputVariable == 's')
  {
    // step one revolution in one direction:
    Serial.println("clock_start");
    delay(500);
    myStepper.step(stepsPerRevolution);

    // stop revolution in clock direction:
    if( inputVariable == 'c')
    {
      myStepper.step(stoprevolution);
      delay(500);
      Serial.println("clock_over");
    }
    
  }
  
  if (inputVariable == 'a')
  {
    Serial.println("Counter_start");
    myStepper.step(-stepsPerRevolution);
    delay(100000);
    Serial.println("Counter_Over");
  }
    
}