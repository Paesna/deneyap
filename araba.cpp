// Deneyap Kart IDE'de 3 Tekerlekli Mobil Robot Yapımı.cpp

#define motorR1 D1
#define motorR2 D4
#define motorRE D0
#define motorL1 D6
#define motorL2 D5
#define motorLE D7
int hiz = 150;

void setup() {
  pinMode(motorR1, OUTPUT);
  pinMode(motorR2, OUTPUT);
  pinMode(motorL1, OUTPUT);
  pinMode(motorL2, OUTPUT);
  pinMode(motorRE, OUTPUT);
  pinMode(motorLE, OUTPUT);
}

void loop() {
  ileri();
  delay(2000);
  dur();
  delay(2000);
  geri();
  delay(1500);
  dur();
  delay(2000);
  sag();
  delay(1000);
  dur();
  delay(1000);
  ileri();
  delay(2500);
  dur();
  delay(1000);
  sol();
  delay(1000);
  dur();
  delay(1000);
}

void ileri() {
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorRE, hiz);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  digitalWrite(motorLE, hiz);
}

void sol() {
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorRE, hiz);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH);
  digitalWrite(motorLE, 0);
}

void sag() {
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
  digitalWrite(motorRE, 0);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  digitalWrite(motorLE, hiz);
}

void dur() {
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorRE, 0);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  digitalWrite(motorLE, 0);
}

void geri() {
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
  digitalWrite(motorRE, hiz);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH);
  digitalWrite(motorLE, hiz);
}