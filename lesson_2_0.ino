// Tutorial How to 4-Digit Display Interface With Arduino UNO
// https://www.instructables.com/Tutorial-How-to-4-Digit-Display-Interface-With-Ard/

#include <Arduino.h>
#include <TM1637Display.h>
#define CLK 8
#define DIO 9
TM1637Display display(CLK, DIO);

void setup() {
  for(int i = 3; i <= 5; i++) {
    pinMode(i, OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {
  int a = analogRead(A1);
  Serial.println(a);
  
  int b = map(a, 0, 1000, 2, 5);
  b = constrain(b, 2, 5);

  showLights(b);
  showPercent(a);
  resetLights(b);
}

void showLights(int b) {
    for(int i = 3; i <= b; i++) {
    digitalWrite(i, HIGH);
  }
  delay(20);
}

void resetLights(int b) {
    for(int i = 3; i <= b; i++) {
    digitalWrite(i, LOW);
  }
}

void showPercent(int a) {
  int percent = map(a, 0, 1000, 0, 100);
  percent = constrain(percent, 0, 100);
  display.setBrightness(0x0f);
  display.showNumberDec(percent, false);
}
