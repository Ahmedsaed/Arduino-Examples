#define LEDG_PIN 2
#define LEDF_PIN 3
#define LEDA_PIN 4
#define LEDB_PIN 5
#define LEDE_PIN 10
#define LEDD_PIN 11
#define LEDC_PIN 12
#define LEDDP_PIN 13

#define DELAY 500

int numbers[] = {
 //ABCDEFGP
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11100110, // 9
};

int characters[] = {
 //ABCDEFGP
  B11101110, // a
  B00111110, // b
  B10011100, // c
  B01111010, // d
  B10011110, // e
  B10001110, // f
  B11110110, // g
  B00101110, // h
  B00001100, // i
  B01110000, // j
  B00101010, // k
  B00011100, // l
  B10101010, // m
  B00101010, // n
  B11111100, // o
  B11001110, // p
  B11100110, // q
  B00001010, // r
  B10110110, // s
  B00011110, // t
  B01111100, // u
  B00111000, // v
  B01000110, // w
  B01101110, // x
  B01110110, // y
  B11011010, // z
};

void display(int bytes)
{
  if (bytes & B10000000)
    digitalWrite(LEDA_PIN, HIGH);
  if (bytes & B01000000)
    digitalWrite(LEDB_PIN, HIGH);
  if (bytes & B00100000)
    digitalWrite(LEDC_PIN, HIGH);
  if (bytes & B00010000)
    digitalWrite(LEDD_PIN, HIGH);
  if (bytes & B00001000)
    digitalWrite(LEDE_PIN, HIGH);
  if (bytes & B00000100)
    digitalWrite(LEDF_PIN, HIGH);
  if (bytes & B00000010)
    digitalWrite(LEDG_PIN, HIGH);
  if (bytes & B00000001)
    digitalWrite(LEDDP_PIN, HIGH);
}

void clear()
{
    digitalWrite(LEDA_PIN, LOW);
    digitalWrite(LEDB_PIN, LOW);
    digitalWrite(LEDC_PIN, LOW);
    digitalWrite(LEDD_PIN, LOW);
    digitalWrite(LEDE_PIN, LOW);
    digitalWrite(LEDF_PIN, LOW);
    digitalWrite(LEDG_PIN, LOW);
    digitalWrite(LEDDP_PIN, LOW);
}

void display_alpha_num_char(char c)
{
  if (isAlpha(c))
    display(characters[toupper(c) - 'A']);
  else
    display(numbers[c - '0']);
  delay(DELAY);
  clear();
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDA_PIN, OUTPUT);
  pinMode(LEDB_PIN, OUTPUT);
  pinMode(LEDC_PIN, OUTPUT);
  pinMode(LEDD_PIN, OUTPUT);
  pinMode(LEDE_PIN, OUTPUT);
  pinMode(LEDF_PIN, OUTPUT);
  pinMode(LEDG_PIN, OUTPUT);
  pinMode(LEDDP_PIN, OUTPUT);

  clear();

  for (int i = 0; i <= 9; i++)
    display_alpha_num_char('0' + i);

  delay(500);

  for (int i = 0; i < 26; i++)
    display_alpha_num_char('a' + i);

  delay(500);

  char *s = "Arduino is amazing";
  for (int i = 0; s[i] != '\0'; i++)
    display_alpha_num_char(s[i]);
}

void loop() {
  // put your main code here, to run repeatedly:
}
