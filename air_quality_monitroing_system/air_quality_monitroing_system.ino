#include <string.h>

#define MODE_PIN 2

/*
  air_quality_sensors.ino:
  - updateReadings()
  - getTemp()
  - getHumidity()
*/

int screenIndex = 0;

void setup() {
  Serial.begin(9600);

  pinMode(MODE_PIN, INPUT_PULLUP);

  setupLCD();
  setupSensors();
}

void loop() {
  updateSensorReadings();
  SmokeWarning(getSmoke());
  displayScreen(screenIndex);
  debug();

  if (digitalRead(MODE_PIN) == LOW) {
    screenIndex = (screenIndex + 1) % 5;
    Serial.println("Screen: " + String(screenIndex));
    // delay(200);
    while (digitalRead(MODE_PIN) == LOW) {
      
    }
  }
  else {
    delay(1000);
  }
}

void debug() {
  Serial.println("-----------------------------------------");
  Serial.println("Temp: " + String(getTemp()));
  Serial.println("Humidity: " + String(getHumidity()));
  Serial.println("LPG: " + String(getLPG()));
  Serial.println("CO: " + String(getCO()));
  Serial.println("Smoke: " + String(getSmoke()));
}

void displayScreen(int index) {
  switch (index) {
    case 0:
      displayInfo("Temp: " + String(getTemp()));
      break;
    case 1:
      displayInfo("Humidity: " + String(getHumidity()));
      break;
    case 2:
      displayInfo("LPG: " + String(getLPG()));
      break;
    case 3:
      displayInfo("CO: " + String(getCO()));
      break;
    case 4:
      displayInfo("Smoke: " + String(getSmoke()));
      break;
  }
}

void SmokeWarning(float smokeLevel) {
  if (smokeLevel > 200) {
    displayInfo("Warning! Run run.");
    // buzzer code
    delay(5000);
  }
}