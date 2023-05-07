#define LED_PIN 2
#define BTN1_PIN 4
#define BTN2_PIN 7

bool light_state, s1_state, s2_state;

class Switch
{
public:
  Switch(int pin)
  {
    pinMode(pin, INPUT_PULLUP);
    m_switch_state = LOW;
    m_last_change = 0;
    m_pin = pin;
  }

  bool read()
  {
    if (digitalRead(m_pin) == LOW)
    {
      if (millis() - m_last_change > 5)
      {
        m_last_change = millis();
        m_switch_state = !m_switch_state;
        return (m_switch_state);
      }
      else
        m_last_change = millis();
    }

    return (m_switch_state);
  }

private:
  bool m_switch_state;
  long m_last_change;
  int m_pin;
};

Switch s1(BTN1_PIN), s2(BTN2_PIN);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  s1_state = s1.read();
  s2_state = s2.read();  

  digitalWrite(LED_PIN, s1_state ^ s2_state);
}
