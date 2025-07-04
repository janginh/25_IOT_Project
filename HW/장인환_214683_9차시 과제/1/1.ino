#include <Servo.h>
Servo myServo;
int motorPin = 12;
int pushPin = 7;
int angle = 90;
int state =0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(motorPin);
  pinMode(pushPin, INPUT);
  Serial.begin(9600);
  Serial.println("Enter the push button.");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pushPin)==HIGH){
    if(state == 0){
      angle += 1;
      if(angle >=180) state = 1;
      myServo.write(angle);
      delay(10);
      Serial.println(angle);
    }
    else{
      angle -=1;
      if(angle<=0) state =0;
      myServo.write(angle);
      delay(10);
      Serial.println(angle);
    }
  }
}
