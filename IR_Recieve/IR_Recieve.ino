#include <IRremote.h>

#define IR_PIN 3
#define LED_PIN 13

IRrecv IR(IR_PIN);

void setup() {
  IR.enableIRIn();
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (IR.decode())
  {
    Serial.println(IR.decodedIRData.decodedRawData, HEX);
    if (IR.decodedIRData.decodedRawData == 0xAB54FF00)
      digitalWrite(LED_PIN, HIGH);
    else if (IR.decodedIRData.decodedRawData == 0xE916FF00)
      digitalWrite(LED_PIN, LOW);
    IR.resume();
  }
}
