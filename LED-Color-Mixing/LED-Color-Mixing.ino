const int arrayLength = 3;

const int outputPins[3] = {11, 9, 10};
const int sensorPins[3] = {A0, A1, A2};
int sensorValues[3] = {0, 0, 0};

void setup()
{
    Serial.begin(9600);
    setupPinsInArray(outputPins, 3, OUTPUT);
    setupPinsInArray(sensorPins, 3, INPUT);
}

void loop()
{
    readSensorValues();
    Serial.print("Red: ");
    Serial.print(sensorValues[0]);
    Serial.print(" Green: ");
    Serial.print(sensorValues[1]);
    Serial.print(" Blue: ");
    Serial.print(sensorValues[2]);
    Serial.println();
    outputLight();
}

void outputLight()
{
    for (int i = 0; i < arrayLength; i++)
    {
        analogWrite(outputPins[i], sensorValues[i]);
    }
}

void readSensorValues()
{
    for (int i = 0; i < arrayLength; i++)
    {
        sensorValues[i] = analogRead(sensorPins[i]) / 4;
        delay(5);
    }
}

void setupPinsInArray(const int array[], int length, int mode)
{
    for (int i = 0; i < length; i++)
    {
        pinMode(array[i], mode);
    }
}