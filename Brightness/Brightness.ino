#define LED_PIN 6
#define POT_PIN A0

int pot;
int brightness;

void setup() {
  // put your setup code here, to run once:
  pinMode(POT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot = analogRead(POT_PIN);
  brightness = map(pot, 0, 1023, 0, 255);

  analogWrite(LED_PIN, brightness);
}
