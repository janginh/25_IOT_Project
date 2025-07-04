int led = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i=0;
  while(i<10){
    i++;
    Serial.println(i);
    delay(1000);
  }

  /*
  int button =1;
  switch(button){
    case1:
      digitalWrite(led, HIGH);
    case2:
      digitalWrite(led, LOW);
      delay(1000);
      digitalWrite(led, HIGH);
      delay(1000);
      break;
    case3:
      digitalWrite(led, LOW);
      break;
    default:
      digitalWrite(led, LOW);
      break;
  }
*/

/*
  for(int i=1; i<=10; i++){
    Serial.println(i);
    delay(1000);
  }
*/
/*
  int button = 2;
  if(button ==1){
    digitalWrite(led, HIGH);
  }
  else if(button ==2){
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
  }
  else{
    digitalWrite(led, LOW);
  }
  */
    
  }

