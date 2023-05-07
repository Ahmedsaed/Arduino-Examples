#define LED_PIN LED_BUILTIN

const int duration = 150;

const char *morseTable[] = {
  ".-",   // A
  "-...", // B
  "-.-.", // C
  "-..",  // D
  ".",    // E
  "..-.", // F
  "--.",  // G
  "....", // H
  "..",   // I
  ".---", // J
  "-.-",  // K
  ".-..", // L
  "--",   // M
  "-.",   // N
  "---",  // O
  ".--.", // P
  "--.-", // Q
  ".-.",  // R
  "...",  // S
  "-",    // T
  "..-",  // U
  "...-", // V
  ".--",  // W
  "-..-", // X
  "-.--", // Y
  "--.."  // Z
};

const int morseTableLen = sizeof(morseTable) / sizeof(morseTableLen);

int char_to_morse_code(char c)
{
  int i;

  i = toupper(c) - 'A';

  if (i < 0 || i >= 26)
    return (-1);
  
  return (i);
}

void blink(int duration)
{
  digitalWrite(LED_PIN, HIGH);
  delay(duration);
  digitalWrite(LED_PIN, LOW);
  delay(duration);
}

void convert_to_morse_code(char *s)
{
  char *morseCode, c;
  int morseCodeIndex, i, j;

  for (j = 0; j < strlen(s); j++)
  {
    morseCodeIndex = char_to_morse_code(s[j]);
    if (morseCodeIndex == -1)
      continue;

    morseCode = morseTable[morseCodeIndex];

    for (i = 0; (c = morseCode[i]) != '\0'; i++)
    {
      if (c == '.')
        blink(duration);
      else if (c == '-')
        blink(duration * 3);
      
      delay(duration);
    }

    delay(duration * 2);
  }
}

void setup() {
  // put your setup code here, to run once:
  char *s = "Hallo World";
  
  pinMode(LED_PIN, OUTPUT);
  
  delay(1000);

  convert_to_morse_code(s);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
