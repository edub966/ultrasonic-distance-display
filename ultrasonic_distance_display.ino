#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 10
#define ECHO_PIN 9

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Distance:");
}

void loop() {
  float distance = getDistance();

  lcd.setCursor(0, 1);
  lcd.print("                "); // clear the line
  lcd.setCursor(0, 1);

  if (distance > 500){
    lcd.print("OUT OF RANGE");
  }
  else{
    lcd.print(distance, 1);       
    lcd.print(" cm");

    if (distance <= 75){
      lcd.print(" NEAR");
    }
    else if (distance > 75 && distance <= 200){
      lcd.print(" MID");
    }
    else {
      lcd.print(" FAR");
    }
  }
  delay(200);

}

float getDistance() {
  // Send a 10 microsecond pulse to trigger
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read how long the echo takes to come back
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Convert to cm: sound travels 343m/s, divide by 2 for round trip
  float distance = (duration * 0.0343) / 2;

  return distance;
}