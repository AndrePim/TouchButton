// Сенсорная кнопка (Touch Button)

#include <Arduino.h>

#define ctsPin 2 // Пин для сенсорной кнопки
int ledPin = 13; // Пин для светодиода

void setup() {
  Serial.begin(9600);      // Инициализация последовательного соединения и задание скорости передачи данных в бит/с(бод)
  pinMode(ledPin, OUTPUT); // Установка режима работы пина светодиода на выход 
  pinMode(ctsPin, INPUT);  // Установка режима работы пина сенсорной кнопки на вход
}

void loop() {
  int ctsValue = digitalRead(ctsPin); // Считывание значения с сенсорной кнопки и запись её в переменную ctsValue     
  if (ctsValue == HIGH) {             // Если значение переменной ctsValue равно HIGH, то загорится светодиод на 13 пине (Встроенный) и появиться надпись "TOUCHED" 
    digitalWrite(ledPin, HIGH);       // Загорается светодиод 
    Serial.println("TOUCHED");        // Появление надписи "TOUCHED"
  }
  else { 
    digitalWrite(ledPin, LOW);        // Светодиод не горит
    Serial.println("Not touched");    // Появление надписи "Not touched"
  }
  delay(500); // Обновление показаний происходит через 500мс
}
