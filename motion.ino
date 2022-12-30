// Датчик движения инфракрасный (PIR Sensor) HC-SR501
// https://www.mini-tech.com.ua/datchik-dvizheniya-infrakrasniy-pir-sensor-hc-sr501

// Светодиодный RGB LED модуль с общим катодом (ОК)
// https://www.mini-tech.com.ua/rgb-led-modul-obshiy-katod

void setup() {
  for(int i = 2; i <= 4; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(8, INPUT);
}

void loop() {
  int val = digitalRead(8);
  if (val) {
    showLights();
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
