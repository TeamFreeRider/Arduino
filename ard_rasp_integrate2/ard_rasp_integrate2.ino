#include <Servo.h>
                                                  
int enablePin = 11;
int enablePin2 = 5;
int in1Pin = 10;
int in2Pin = 9;
int servoPin = 6;
int speed = 255;
int flag = 0;
int already_going = 0;
boolean direction = false;

Servo servo;

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  delay(50);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  servo.attach(servoPin);
}

void loop() {

  if(Serial.avaliable()){
  
    char direction = Serial.read(); // received from dijkstra main algorithm
    
    Serial.println(direction);
    switch(direction){
      case 'H' ://halt
        digitalWrite(in1Pin, false);
        digitalWrite(in2Pin, false);
      case 'S' ://stop
        digitalWrite(in1Pin, false);
        digitalWrite(in2Pin, false);
      case 'L' ://left
        if(already_going == 0){
          already_going = 1;
          servo.write(60);
          delay(15);
          analogWrite(enablePin, 50);//왼 // 이전꺼 왼30, 오 95
          analogWrite(enablePin2, 113);//오
          digitalWrite(in1Pin, true);
          digitalWrite(in2Pin, true);
          delay(950);
        }
      case 'R' ://right
        if(already_going == 0){
           already_going = 1;
          servo.write(140);
          delay(15);
          analogWrite(enablePin, 57);//왼 // 이전꺼 왼30, 오 95
          analogWrite(enablePin2, 105);//오
          digitalWrite(in1Pin, true);
          digitalWrite(in2Pin, true);
          delay(1050);
        }
      case 'F' ://foward, linetracing code will work here
        if(Serial2.availbable()){
          char lanetrack = Serial2.read();
  
          Serial.println(lanetrack);
          switch(lanetrack){
            case 'f' : // foward
              servo.write(100); // forward
              analogWrite(enablePin, 40);
              analogWrite(enablePin2, 105);
              digitalWrite(in1Pin, true);
              digitalWrite(in2Pin, true);
            case 'l' : //left
              servo.write(형이 써주셈);
              analogWrite(enablePin, 40);
              analogWrite(enablePin2, 105);
              digitalWrite(in1Pin, true);
              digitalWrite(in2Pin, true);              
              
            case 'r' : //right
              servo.write(형이 써주셈);
              analogWrite(enablePin, 40);
              analogWrite(enablePin2, 105);
              digitalWrite(in1Pin, true);
              digitalWrite(in2Pin, true); 
          }
        }
    }
  }
}
