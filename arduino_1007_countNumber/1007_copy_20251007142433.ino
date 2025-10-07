// 七段顯示器段腳位 (a~g)
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

// 共陰極控制腳位 (個位、十位、百位)
int digitPins[3] = {9, 10, 11};

// 共陰極七段顯示碼：HIGH 亮、LOW 滅
int digits[10][7] = {
  {1,1,1,1,1,1,0},  // 0
  {0,1,1,0,0,0,0},  // 1
  {1,1,0,1,1,0,1},  // 2
  {1,1,1,1,0,0,1},  // 3
  {0,1,1,0,0,1,1},  // 4
  {1,0,1,1,0,1,1},  // 5
  {1,0,1,1,1,1,1},  // 6
  {1,1,1,0,0,0,0},  // 7
  {1,1,1,1,1,1,1},  // 8
  {1,1,1,1,0,1,1}   // 9
};

int number = 0; // 顯示的數字 0~999

void setup() {
  // 設定七段腳位
  for (int i = 2; i <= 8; i++) {
    pinMode(i, OUTPUT);
  }

  // 設定位數腳位
  for (int i = 0; i < 3; i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], HIGH); // 初始化關閉
  }
}

void loop() {
  int ones  = number % 10;           // 個位
  int tens  = (number / 10) % 10;    // 十位
  int hundreds = (number / 100) % 10;// 百位

  unsigned long t_start = millis(); // 記錄秒數起點
  while (millis() - t_start < 1000) { // 持續 1 秒掃描
    showDigit(ones, 0);     // 個位
    showDigit(tens, 1);     // 十位
    showDigit(hundreds, 2); // 百位
  }

  // 1 秒結束，數字 +1
  number++;
  if (number > 999) number = 0;
}

void showDigit(int num, int pos) {
  // 設定段腳位
  for (int seg = 0; seg < 7; seg++) {
    digitalWrite(2 + seg, digits[num][seg] ? HIGH : LOW);
  }

  // 啟用對應位數
  digitalWrite(digitPins[pos], LOW);  // 開啟共陰極
  delay(5);                             // 顯示短時間
  digitalWrite(digitPins[pos], HIGH); // 關閉共陰極
}
