#include <Servo.h>


//dc speed
int speedPin = 3;



Servo myservo;

int servoPin = 9;

int min_value = 544;

int max_value = 2400;


//dc pin
int motor1APin =6;

int motor2APin = 7;

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

/*
//stop
      digitalWrite(motor2APin, LOW); break;

//go straight
      digitalWrite(motor2APin, HIGH);
      myservo.write(90);
      delay(100);

//turn right
      digitalWrite(motor2APin, HIGH);
      myservo.write(125);
      delay(100);
*/
//turn left
      digitalWrite(motor2APin, HIGH);
      myservo.write(55);
      delay(100); 

 
 digitalWrite(motor1APin, LOW);

 speed_value_motor1 = 127;

 analogWrite(speedPin, speed_value_motor1);

 }

delay(100);
}
