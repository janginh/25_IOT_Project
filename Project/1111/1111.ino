#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD 주소, 문자 수

// 사용자 정의 문자 (1칸 = 5x8 도트)
byte gaugeFull[8] = { B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 };
byte gaugeEmpty[8] = { B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };

int value1;

void setup() {
  lcd.init();
  lcd.backlight();

  // 사용자 문자 등록
  lcd.createChar(0, gaugeEmpty);  // 문자 번호 0
  lcd.createChar(1, gaugeFull);   // 문자 번호 1

  randomSeed(analogRead(0));
}

void loop() {
  value1 = random(0, 10001);  // 0~10000

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("TITLE1");

  lcd.setCursor(8, 0);
  lcd.print("Val:");
  lcd.print(value1);

  // 게이지 출력
  lcd.setCursor(0, 1);
  lcd.print("[");
  
  // 전체 10칸으로 가정
  int filledBars = map(value1, 0, 10000, 0, 10);
  for (int i = 0; i < 10; i++) {
    if (i < filledBars)
      lcd.write(byte(1));  // 꽉 찬 바
    else
      lcd.write(byte(0));  // 빈 바
  }

  lcd.print("]");

  delay(1000);
}
