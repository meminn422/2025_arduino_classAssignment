int led1 = 2;
int led2 = 3;
int led3 = 4;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  delay(1000);  // 亮1秒

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  delay(500);

  digitalWrite(led1, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  
  digitalWrite(led2, HIGH);
  delay(300);
  digitalWrite(led2, LOW);

  digitalWrite(led3, HIGH);
  delay(300);
  digitalWrite(led3, LOW);

  delay(500);

  digitalWrite(led3, HIGH);
  delay(300);
  digitalWrite(led3, LOW);
  
  digitalWrite(led2, HIGH);
  delay(300);
  digitalWrite(led2, LOW);
  
  digitalWrite(led1, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  
  delay(500);
}
