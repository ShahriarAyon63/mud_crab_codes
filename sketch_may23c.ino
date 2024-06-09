#include "LiquidCrystal.h"

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float temp;  // to include LM35 sensor
const int buzzerPin = 8;  // Define the pin for the buzzer

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);
  lcd.begin(16, 2);  // the codes written here are to run the program once
  lcd.setCursor(0, 0);
  lcd.print(" MADE BY   ");      
  lcd.setCursor(0, 1);
  delay(400);
  lcd.print(" ELECTRO MENTOR  ");
  delay(700);
  lcd.clear();  // Let system settle
  
  pinMode(buzzerPin, OUTPUT);  // Set the buzzer pin as an output
  digitalWrite(buzzerPin, LOW);  // Ensure the buzzer is off initially
}

void loop() {
  temp = analogRead(A0);  // Read the analog value from pin A0
  temp = temp * (1100.0 / 1024.0) / 10.0;  // Convert the analog value to temperature in Celsius

  lcd.setCursor(0, 0);  // Set cursor to the first row, first column
  lcd.print("TEMP: ");
  lcd.print(temp);
  lcd.print(" *C");

  // Check if temperature is outside the range of 28-32°C
  if (temp < 28 || temp > 32) {
    digitalWrite(buzzerPin, HIGH);  // Turn on the buzzer
  } else {
    digitalWrite(buzzerPin, LOW);  // Turn off the buzzer
  }

  delay(500);
  lcd.clear();  // Let system settle
}
