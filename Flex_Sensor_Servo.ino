/* This is a simple code showing how to interface a flex sensor (I made one at home) with a servo motor and control the position*/

#include <Servo.h>

Servo servo1; 
const int flexpin = 0; //define pin connected to servo signal

void setup()  
{
  Serial.begin(9600);  //baud rate
  servo1.attach(9); //initialize servo
}


void loop()
{
  int flexposition;  //variable for flex sensor positional values
  int servoposition;  //variable for servo motor positional values
  flexposition = analogRead(flexpin); 
  servoposition = map(flexposition, 6, 50, 0, 90); 
  servoposition = constrain(servoposition, 0, 90);  
  servo1.write(servoposition);  
  Serial.print("sensor: "); 
  Serial.print(flexposition); 
  Serial.print(" servo: "); 
  Serial.println(servoposition);  
  delay(1000); 
}
