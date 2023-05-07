// DPDT Switch

#define SWITCH_PIN 4
#define LED_PIN 2

bool switch_state, last_state;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  switch_state = digitalRead(SWITCH_PIN);

  if (switch_state != last_state)
  {
    digitalWrite(LED_PIN, switch_state);
    last_state = switch_state;
  }

}
