/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

int led_g=2;
int led_y=4;
int led_r=7;
int LED[]={led_g, led_y, led_r}; //{2,4,7}
int LED_delay[]={300,500,700,1000};

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.

  for(int i =0; i<3; i++){
    pinMode(LED[i], OUTPUT);
  }

  /*
  pinMode(led_g, OUTPUT);
  pinMode(led_y, OUTPUT);
  pinMode(led_r, OUTPUT);
   */
}

// the loop function runs over and over again forever
void loop() {

  /*
  digitalWrite(led_g, HIGH);
  digitalWrite(led_y, HIGH);
  digitalWrite(led_r, HIGH);
  delay(0);
  digitalWrite(led_g, LOW);
  digitalWrite(led_y, LOW);
  digitalWrite(led_r, LOW);
  delay(300);
  */

  for(int i=0; i<3; i++){
    digitalWrite(LED[i], HIGH);
    delay(LED_delay[i]);
    digitalWrite(LED[i], LOW);
    delay(LED_delay[i]);
  }

  /*  한개씩 켜지기 
  digitalWrite(led_g, HIGH);
  digitalWrite(led_y, LOW);
  digitalWrite(led_r, LOW);  // turn the LED on (HIGH is the voltage level)
  delay(1000);
  digitalWrite(led_g, LOW);
  digitalWrite(led_y, HIGH);
  digitalWrite(led_r, LOW);
  delay(1000);
                        // wait for a second
  digitalWrite(led_g, LOW);
  digitalWrite(led_y, LOW);
  digitalWrite(led_r, HIGH);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
  */
}
