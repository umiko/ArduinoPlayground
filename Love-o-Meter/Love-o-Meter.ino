#include <string.h>

const int sensorPin = A0;
float baseline = 0.0;
float voltage = 0.0;
float temperature = 0.0;
int sensorValue = 0;

void setup()
{
    Serial.begin(9600);
    resetLEDs();

    sensorValue = analogRead(sensorPin);
    voltage = getVoltage(sensorValue);
    temperature = getTemperature(voltage);
    baseline = temperature;
}

void loop()
{
    //resetLEDs();

    sensorValue = analogRead(sensorPin);
    voltage = getVoltage(sensorValue);
    temperature = getTemperature(voltage);

    Serial.print("Sensor Value: ");
    Serial.print(sensorValue);
    Serial.print(" Voltage: ");
    Serial.print(voltage);
    Serial.print(" Temp: ");
    Serial.print(temperature);
    Serial.print(" Baseline: ");
    Serial.println(baseline);
    measureLove(temperature);

    delay(500);
}

float getVoltage(int sensorValue)
{
    return (sensorValue / 1024.0) * 5.0;
}

float getTemperature(float voltage)
{
    return (voltage - 0.5) * 100.0;
}

void resetLEDs()
{
    for (short pinNumber = 2; pinNumber < 5; pinNumber++)
    {
        pinMode(pinNumber, OUTPUT);
        digitalWrite(pinNumber, LOW);
    }
}

void measureLove(float temperature)
{
    for (short pinNumber = 2; pinNumber < 5; pinNumber++)
    {
        if (temperature > baseline + pinNumber)
        {
            digitalWrite(pinNumber, HIGH);
        }
        else
        {
            digitalWrite(pinNumber, LOW);
        }
    }
}