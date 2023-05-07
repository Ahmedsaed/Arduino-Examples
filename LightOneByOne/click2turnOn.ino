#define LED1_PIN 2
#define LED2_PIN 3
#define LED3_PIN 5
#define BTN_PIN 4

bool btn_state = HIGH;
bool last_state = btn_state;

void light(bool state)
{
  if (state == 0)
  {
    digitalWrite(LED1_PIN, HIGH);
    delay(300);
    digitalWrite(LED2_PIN, HIGH);
    delay(300);
    digitalWrite(LED3_PIN, HIGH);
    delay(300);
  }
  else
  {
    digitalWrite(LED3_PIN, LOW);
    delay(300);
    digitalWrite(LED2_PIN, LOW);
    delay(300);
    digitalWrite(LED1_PIN, LOW);
    delay(300);
  }

  last_state = state;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  btn_state = digitalRead(BTN_PIN);

  if (btn_state == LOW)
  {
    if (last_state != btn_state)
      light(btn_state);
  }
  else
  {
    if (last_state != btn_state)
      light(btn_state);
  }
}
