#include <IRremote.h>

IRsend irsend(3);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 3; i++)
  {
    irsend.sendPanasonic(0xBD3D0080, 32);
    delay(40);
  }
  delay(5000);
}
