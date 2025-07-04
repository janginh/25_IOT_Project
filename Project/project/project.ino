#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2,3);   //bluetooth module Tx:Digital 2 Rx:Digital 3
LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD 주소, 문자 수

int trigPin = 13;    // trigPin을 13번에 저장
int echoPin = 12;    // echPin을 12번에 저장
int led = 11;        // led를 11번에 저장
int led2 = 10;       // led2를 10번에 저장
int led3 = 9;

// 사용자 정의 문자 (1칸 = 5x8 도트)
byte gaugeFull[8] = { B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 };
byte gaugeEmpty[8] = { B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };

void setup() 
{
  Serial.begin (9600);            //시리얼 통신을, 9600속도로 받습니다. ( 숫자 조정은 자유)
  BTSerial.begin(9600);

  pinMode(trigPin, OUTPUT);      //trigPic을 출력모드로
  pinMode(echoPin, INPUT);       //echoPin을 입력모드로
  pinMode(led, OUTPUT);          // led를 출력모드로
  pinMode(led2, OUTPUT);          // led2를 출력모드로
  pinMode(led3, OUTPUT);          // led3를 출력모드로

  lcd.init();
  lcd.backlight();

  // 사용자 문자 등록
  lcd.createChar(0, gaugeEmpty);  // 문자 번호 0
  lcd.createChar(1, gaugeFull);   // 문자 번호 1
}

void loop() 
{
  if(BTSerial.available()){
    Serial.write(BTSerial.read());
  }

  long duration, distance;           //시간과 거리를 설정합니다
  digitalWrite(trigPin, LOW);        // trigPin이 low 신호를 주면
  delayMicroseconds(2);              // 2 만큼 지연합니다
  digitalWrite(trigPin, HIGH);       // trigPin이 high 신호를 주면
  delayMicroseconds(10);             // 10 만큼 지연합니다
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);  // duration에 밑의 공식을 대입합니다
  distance = (duration/2) / 29.1;     // 초음파가 갔다가 돌아오기 때문에 2배의 값을 얻습니다 그렇기에 거리/2를 합니다.
  //Serial.println(distance);

  // 거리 전송 (Python용)
  
  
  // 거리에 따른 제어
  if (distance < 7)                   // 거리가 7보다 작아지면
  {
    digitalWrite(led,HIGH);           // 빨간 LED가  켜지고
    digitalWrite(led2,LOW);           // 노랑 LED가 꺼지고
    digitalWrite(led3,LOW);           // 초록 LED도 꺼집니다

    Serial.print("DIST:");
    Serial.print(distance);
    Serial.print(",WARN:");
    Serial.println((distance <= 2) ? 1 : 0);     // 2cm 이하일 경우 경고 (1)

    if (distance <=2){
      BTSerial.println("🚨 경고: 너무 가까움!");
      Serial.println("Bluetooth로 경고 전송됨!");
      delay(100);
    }
}
  else if (distance>=7 and distance <30){
    digitalWrite(led,LOW);          // 빨간 LED 꺼지고
    digitalWrite(led3,LOW);         // 초록 LED 꺼지고
    digitalWrite(led2,HIGH);        // 노랑 LED 켜집니다
  }
  else {                           //위 상황이 아닐경우
    digitalWrite(led,LOW);
    digitalWrite(led2,LOW);         //노랑 LED가 꺼지고
    digitalWrite(led3,HIGH);       //초록 LED가 켜집니다
  }
  if (distance >= 200 )            // 거리가 200cm가 넘어가면
  {
    Serial.println("Out of range.");  // 시리얼 모니터에 Out of range.라는 문구가 나옵니다
  }
  delay(500);


  // 게이지 출력
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TITLE1");
  lcd.setCursor(8, 0);
  lcd.print("Dis:");
  lcd.print(distance);
  lcd.setCursor(0, 1);
  lcd.print("[");

  int filledBars = map(distance, 0, 80, 10, 0);
  for (int i = 0; i < 10; i++) {
    if (i < filledBars)
      lcd.write(byte(1));  // 꽉 찬 바
    else
      lcd.write(byte(0));  // 빈 바
  }
  lcd.print("]");

}