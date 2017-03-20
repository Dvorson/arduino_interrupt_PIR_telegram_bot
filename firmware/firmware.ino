int ledPin = 13;
int PIRInterrupt = 0;
volatile int state = LOW;

void setup()
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(3, OUTPUT); // порт как выход
  digitalWrite(3, HIGH);
  attachInterrupt(PIRInterrupt, blink, CHANGE); // привязываем 0-е прерывание к функции blink().
}

void loop()
{
  digitalWrite(ledPin, state);          // выводим state  
}

void blink()
{
  state = !state;                    // меняем значение на противоположное
  Serial.println(state);
}
