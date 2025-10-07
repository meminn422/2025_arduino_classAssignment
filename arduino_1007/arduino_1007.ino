
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int common = 9;

int digits[10][7] = {
  // a, b, c, d, e, f, g
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
void setup() {
  for (int i = 2; i <= 8; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(common, OUTPUT);

  digitalWrite(common, LOW);
}

void loop() {
  for (int num = 0; num < 10; num++) {
    displayNumber(num);
    delay(1000); // 每秒換數字
  }
}

void displayNumber(int num) {
  for (int seg = 0; seg < 7; seg++) {
    digitalWrite(2 + seg, digits[num][seg] ? HIGH : LOW);
  }
}



