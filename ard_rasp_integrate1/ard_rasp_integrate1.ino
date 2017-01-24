#include <Servo.h>
                                                  
int enablePin = 11;
int enablePin2 = 5;
int in1Pin = 10;
int in2Pin = 9;
int servoPin = 6;
int speed = 255;
int flag = 0;


Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  servo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
          if(Serial.available()){
          char lanetrack = Serial.read();
  
          Serial.println(lanetrack);
          switch(lanetrack){
            case 'f' : // foward
              servo.write(92); // forward
              analogWrite(enablePin, 40);
              analogWrite(enablePin2, 105);
              digitalWrite(in1Pin, true);
              digitalWrite(in2Pin, true);
              delay(100);
              break;
            case 'l' : //left
              servo.write(87);
              analogWrite(enablePin, 40);
              analogWrite(enablePin2, 105);
              digitalWrite(in1Pin, true);
              digitalWrite(in2Pin, true);    
              delay(100);
              break;          
              
            case 'r' : //right
              servo.write(97);
              analogWrite(enablePin, 40);
              analogWrite(enablePin2, 105);
              digitalWrite(in1Pin, true);
              digitalWrite(in2Pin, true); 
              delay(100);
              break;

             default : //stop
               digitalWrite(in1Pin,false);
               digitalWrite(in2Pin,false);
               delay(100);
               break;
          }
        }

}
