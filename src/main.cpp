#include <Arduino.h>
#define ANALOG_PIN 4
#define ADC_BITS 4095.0
#define MCU_VOLTAGE 3.3


void setup() {
  Serial.begin(115200);
  pinMode(ANALOG_PIN, INPUT);
}

void loop() {
  int analogValue = analogRead(ANALOG_PIN);
  float measuredMilivolts = analogReadMilliVolts(ANALOG_PIN);
  float volts = analogValue / ADC_BITS * MCU_VOLTAGE;

  Serial.println("---------");
  Serial.print("Raw analog value: ");
  Serial.println(analogValue);
  Serial.print("Measured voltage with formula: ");
  Serial.println(volts);
  Serial.print("Milivolts from MCU function: ");
  Serial.println(measuredMilivolts);
  Serial.print("Error: ");
  Serial.print(fabs((1 - fabs(volts * 1000 / measuredMilivolts)) * 100));
  Serial.println("%");
  Serial.println("---------");
  delay(100);
}

