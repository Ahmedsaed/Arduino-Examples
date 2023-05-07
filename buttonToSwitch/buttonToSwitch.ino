#define LED_PIN 2
#define BTN_PIN 4

bool btn_state, light_state;
long last_change = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  btn_state = digitalRead(BTN_PIN);

  if (btn_state == LOW)
  {
    if (millis() - last_change > 50)
    {
      last_change = millis();
      light_state = !light_state;
    }
    else
      last_change = millis();
  }

  digitalWrite(LED_PIN, light_state);
}
