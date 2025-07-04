// 핀 설정
const int tempSensorPin = A0;  // 아날로그 온도 센서 (예: TMP36)
const int ledPin = 13;         // 내장 LED

void setup() {
  // 시리얼 통신 시작
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  String str1 = "hello Arduino";
  String str2 = String('a');
  String str3 = String("hello ");  // 고침!

  Serial.println("code start");
  Serial.println(str1);
  Serial.println(str2);
  Serial.println(str3);
  str1 += " World";
  Serial.println(str1); //hello Arduino World
  str1.toUpperCase();
  Serial.println(str1);
  str1.toLowerCase();
  Serial.println(str1);
  Serial.println();

  int firstPosition = str1.indexOf('o');
  int lastPosition = str1.lastIndexOf('o');
  Serial.println(firstPosition);
  Serial.println(lastPosition);
  Serial.println();

  str1.setCharAt(lastPosition, '1');
  Serial.println(str1);
   
  int Length = str1.length();
  Serial.println("\nLength : ");
  Serial.println(Length);
  Serial.println();

  int a = 66;
  char c='A';
  Serial.println(a); //66
  Serial.println(char(a));  //B
  Serial.println(c); //A
  Serial.println(int(c));



  Serial.println();
  delay(1000);  // 추가!
}
