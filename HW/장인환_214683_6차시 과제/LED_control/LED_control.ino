int num = 0;

byte numbers[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1, 0},  // 2
  {1, 1, 1, 1, 0, 0, 1, 0},  // 3
  {0, 1, 1, 0, 0, 1, 1, 0},  // 4
  {1, 0, 1, 1, 0, 1, 1, 0},  // 5
  {1, 0, 1, 1, 1, 1, 1, 0},  // 6
  {1, 1, 1, 0, 0, 1, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1, 0},  // 8
  {1, 1, 1, 1, 0, 1, 1, 0}   // 9
};

int segPins[8] = {8, 7, 6, 5, 4, 3, 2, 9};  // 너 회로 순서 맞춰서

void displayNumbers(int n) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(segPins[i], numbers[n][i] ? HIGH : LOW);
  }
}

void setup() {
  pinMode(12, INPUT);  // 버튼
  for (int i = 0; i < 8; i++) {
    pinMode(segPins[i], OUTPUT);
  }
  digitalWrite(segPins[7], HIGH);  // dp 꺼두기
  randomSeed(analogRead(0));
}

void loop() {
  if (digitalRead(12) == HIGH) {
    delay(50);
    if (digitalRead(12) == HIGH) {
      num = random(1, 7);
      displayNumbers(num);
      while (digitalRead(12) == HIGH);
    }
  }
}
