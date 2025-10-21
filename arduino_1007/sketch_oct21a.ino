// ------------------------------------
// 共陰極七段顯示器 + 74LS138 掃描顯示
// 自動從 00:00:00 開始計時
// ------------------------------------

int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8};  // a~g 共用線
int decoderPins[3] = {9, 10, 11};            // 74LS138 A0~A2 控制
unsigned long lastUpdate = 0;                // 計時用
int second = 57, minute = 59, hour = 23;        // 時分秒

// 共陰極段碼（HIGH=亮）
byte digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

void setup() {
  for (int i=0; i<7; i++) pinMode(segmentPins[i], OUTPUT);
  for (int i=0; i<3; i++) pinMode(decoderPins[i], OUTPUT);
}

void showDigit(int num) {
  for (int i=0; i<7; i++) {
    digitalWrite(segmentPins[i], digits[num][i]);
  }
}

void selectDisplay(int n) {
  digitalWrite(decoderPins[0], n & 1);
  digitalWrite(decoderPins[1], (n >> 1) & 1);
  digitalWrite(decoderPins[2], (n >> 2) & 1);
}

void displayTime() {
  int d[6];
  d[0] = hour / 10;
  d[1] = hour % 10;
  d[2] = minute / 10;
  d[3] = minute % 10;
  d[4] = second / 10;
  d[5] = second % 10;

  for (int i = 0; i < 6; i++) {
    showDigit(d[i]);
    selectDisplay(i);
    delay(2);
  }
}

void updateTime() {
  if (millis() - lastUpdate >= 1000) {
    lastUpdate = millis();
    second++;
    if (second >= 60) {
      second = 0;
      minute++;
      if (minute >= 60) {
        minute = 0;
        hour++;
        if (hour >= 24) hour = 0;
      }
    }
  }
}

void loop() {
  updateTime();
  displayTime();
}
