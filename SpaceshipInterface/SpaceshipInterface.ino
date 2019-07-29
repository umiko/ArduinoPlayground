int switchIsPressed = 0;
int ready = 0;

void setup()
{
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  if (!ready)
  {
    delay(1000);
    digitalWrite(5, HIGH);
    delay(1500);
    digitalWrite(4, HIGH);
    delay(2000);
    digitalWrite(3, HIGH);
    delay(3000);
    ready = 1;
  }
  switchIsPressed = digitalRead(2);
  if (switchIsPressed)
  {
    resetLEDs();
    ready = 0;
  }

  // put your main code here, to run repeatedly:
}

void resetLEDs()
{
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}
