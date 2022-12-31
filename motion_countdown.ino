// Датчик движения инфракрасный (PIR Sensor) HC-SR501
// https://www.mini-tech.com.ua/datchik-dvizheniya-infrakrasniy-pir-sensor-hc-sr501

// Светодиодный RGB LED модуль с общим катодом (ОК)
// https://www.mini-tech.com.ua/rgb-led-modul-obshiy-katod

// Tutorial How to 4-Digit Display Interface With Arduino UNO
// https://www.instructables.com/Tutorial-How-to-4-Digit-Display-Interface-With-Ard/

#include <Arduino.h>
#include <TM1637Display.h>
#define CLK 10
#define DIO 9
TM1637Display display(CLK, DIO);

int repeat = 10;
int count = 0;

void setup() {
  for(int i = 2; i <= 4; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(8, INPUT);
}

void loop() {
  int val = digitalRead(8);
  if (val) {
    count = repeat;
  }

  display.setBrightness(0x0f);
  display.showNumberDec(count, false);

  if (count > 0) {
    showLights();
    count--;
  }
}

void showLights() {
  for(int i = 2; i <= 4; i++) {
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
    delay(200);
  }
}
