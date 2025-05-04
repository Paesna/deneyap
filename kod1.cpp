#include <HCSR04.h>  // HC-SR04 mesafe sensörü için gerekli kütüphane

#define trigPin D0   // TRIG pini D0 olarak tanımlanıyor
#define echoPin D1   // ECHO pini D1 olarak tanımlanıyor

int LED_Dizisi[] = {D4, D5, D6, D7, D12, D13, D14, D15};  // LED'lerin bağlı olduğu pinler
long sure;     // Sinyalin gidip gelme süresi (mikrosaniye cinsinden)
long mesafe;   // Ölçülen mesafe (santimetre cinsinden)

// Ultrasonik mesafe sensör nesnesi tanımlanıyor
UltraSonicDistanceSensor mesafeSensoru(trigPin, echoPin);  

void setup() {
  // LED pinlerinin çıkış olarak ayarlanması
  for(int i = 0; i < 8; i++) {
    pinMode(LED_Dizisi[i], OUTPUT);
  }

  Serial.begin(115200);  // Seri haberleşme başlatılıyor (115200 baud)
}

void loop() {
  mesafe = mesafeSensoru.measureDistanceCm();  // Sensörden mesafe ölçümü alınıyor

  if(mesafe <= 5) {
    digitalWrite(LED_Dizisi[0], HIGH);  // En yakın mesafe → sadece ilk LED yanar
    delay(50);
    digitalWrite(LED_Dizisi[0], LOW);
  }
  else if(mesafe <= 10 && mesafe > 5) {
    for(int i = 0; i < 2; i++) {        // 2 LED yanıp söner
      digitalWrite(LED_Dizisi[i], HIGH);
      delay(50);
      digitalWrite(LED_Dizisi[i], LOW);
    }
  }
  else if(mesafe <= 15 && mesafe > 10) {
    for(int i = 0; i < 3; i++) {        // 3 LED yanıp söner
      digitalWrite(LED_Dizisi[i], HIGH);
      delay(50);
      digitalWrite(LED_Dizisi[i], LOW);
    }
  }
  else if(mesafe <= 20 && mesafe > 15) {
    for(int i = 0; i < 4; i++) {        // 4 LED yanıp söner
      digitalWrite(LED_Dizisi[i], HIGH);
      delay(50);
      digitalWrite(LED_Dizisi[i], LOW);
    }
  }
  else if(mesafe <= 25 && mesafe > 20) {
    for(int i = 0; i < 5; i++) {        // 5 LED yanıp söner
      digitalWrite(LED_Dizisi[i], HIGH);
      delay(50);
      digitalWrite(LED_Dizisi[i], LOW);
    }
  }
  else if(mesafe <= 30 && mesafe > 25) {
    for(int i = 0; i < 6; i++) {        // 6 LED yanıp söner
      digitalWrite(LED_Dizisi[i], HIGH);
      delay(50);
      digitalWrite(LED_Dizisi[i], LOW);
    }
  }
  else if(mesafe <= 35 && mesafe > 30) {
    for(int i = 0; i < 7; i++) {        // 7 LED yanıp söner
      digitalWrite(LED_Dizisi[i], HIGH);
      delay(50);
      digitalWrite(LED_Dizisi[i], LOW);
    }
  }
  else if(mesafe <= 40 && mesafe > 35) {
    for(int i = 0; i < 8; i++) {        // 8 LED yanıp söner
      digitalWrite(LED_Dizisi[i], HIGH);
      delay(50);
      digitalWrite(LED_Dizisi[i], LOW);
    }
  }

  // Seri porttan ölçülen mesafe yazdırılıyor
  Serial.print("Mesafe: ");
  Serial.println(mesafe);
}