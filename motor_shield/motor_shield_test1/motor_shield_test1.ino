#include <AFMotor.h>

#include <Servo.h> 



// DC hobby servo

Servo servo1;

// Stepper motor on M3+M4 48 steps per revolution

AF_Stepper stepper(20, 2);





void setup() {

  Serial.begin(9600);           // set up Serial library at 9600 bps

  Serial.println("Motor party!");

  

  // turn on servo

  servo1.attach(9);

   

  // turn on motor #2
//stepper.setSpeed(200);
  //motor.setSpeed(200);

  //motor.run(RELEASE);

}




int i;




// Test the DC motor, stepper and servo ALL AT ONCE!

void loop() {

  for (i=0; i<255; i++) {

    servo1.write(i);

   
    stepper.step(1, FORWARD, INTERLEAVE);

    delay(3);

 }
}


