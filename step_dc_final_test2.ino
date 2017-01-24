#include <Servo.h>



int speedPin = 6;



Servo myservo;

int servoPin = 9;

int min_value = 544;

int max_value = 2400;



int motor1APin = 4;

int motor2APin = 5;

int speed_value_motor1;



void setup() {

  Serial.begin(9600);

  pinMode(speedPin, OUTPUT);

  pinMode(motor1APin, OUTPUT);

  pinMode(motor2APin, OUTPUT);

  myservo.attach(servoPin, min_value, max_value);

  myservo.write(90);

  }





void loop(){



// if( Serial.available() ){

//  char direction = Serial.read();
//  Serial.println(direction);
//  switch (direction) {

//    case 'E' :stop
      digitalWrite(motor2APin, LOW); 

//    case 'F' : go straight foward
      digitalWrite(motor2APin, HIGH);
      myservo.write(90);
      delay(100); 

//    case 'R' : turn right
      digitalWrite(motor2APin, HIGH);
      myservo.write(125);
      delay(100);

//    case 'L' : turn left
      digitalWrite(motor2APin, HIGH);
      myservo.write(55);
      delay(100); 

 digitalWrite(motor1APin, LOW);

 speed_value_motor1 = 127;

 analogWrite(speedPin, speed_value_motor1);

 }

