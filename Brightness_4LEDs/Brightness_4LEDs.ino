#define LED1_PIN 6
#define LED2_PIN 3
#define LED3_PIN 5
#define LED4_PIN 9
#define POT_PIN A0

int pot;
int brightness;

void setup() {
  // put your setup code here, to run once:
  pinMode(POT_PIN, INPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot = analogRead(POT_PIN);
  brightness = map(pot, 0, 1023, 0, 255);

  if (brightness >= 0.00 * 255)
    analogWrite(LED1_PIN, brightness);

  if (brightness >= 0.25 * 255)
    analogWrite(LED2_PIN, map(brightness, 255*0.25, 255, 0, 255));
  else
    analogWrite(LED2_PIN, 0);

  if (brightness >= 0.50 * 255)
    analogWrite(LED3_PIN, map(brightness, 255*0.50, 255, 0, 255));
  else
    analogWrite(LED3_PIN, 0);

  if (brightness >= 0.75 * 255)
    analogWrite(LED4_PIN, map(brightness, 255*0.75, 255, 0, 255));
  else
    analogWrite(LED4_PIN, 0);
}
