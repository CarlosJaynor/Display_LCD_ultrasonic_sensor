#include <LiquidCrystal.h>

//Variables display LCD
int rs = 12;
int e  = 11;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;

//variables Ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() {
  //definicion del display 16x2
  lcd.begin(16, 2);

  //inicializacion del sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

//funcion bucle
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;  // Calcular la distancia en cm

  lcd.clear();  // Limpiar el display
  lcd.setCursor(0, 0);  // Establecer la posición del cursor
  lcd.print("Distancia: ");
  lcd.print(distance);
  lcd.print(" cm");

  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);  // Esperar medio segundo antes de medir de nuevo
}
