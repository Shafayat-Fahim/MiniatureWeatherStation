#include <Wire.h>
#include <Adafruit_AHTX0.h>
#include <DFRobot_ENS160.h>

// ENS160 I2C Address: 0x53 (default)
#define ENS160_I2C_ADDR  0x53

// Create sensor objects
Adafruit_AHTX0 aht;
DFRobot_ENS160_I2C ens160(&Wire, ENS160_I2C_ADDR);

// Analog pin for anemometer
const int anemometerPin = A0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // Initialize I2C bus
  Wire.begin();

  // Initialize AHT21
  if (!aht.begin()) {
    Serial.println("AHT21 not found. Check connections.");
  } else {
    Serial.println("AHT21 initialized.");
  }

  // Initialize ENS160
  if (ens160.begin() != 0) {
    Serial.println("ENS160 not found. Check connections and address.");
  } else {
    ens160.setPWRMode(ENS160_STANDARD_MODE);
  }
}

void loop() {
  // 🌡️ Get temperature & humidity from AHT21
  sensors_event_t humidity, temperature;
  aht.getEvent(&humidity, &temperature);
  float tempC = temperature.temperature;
  float hum = humidity.relative_humidity;

  // Send temp & humidity to ENS160
  ens160.setTempAndHum(tempC, hum);

  // 🌫️ Get ENS160 values
  uint16_t eco2 = ens160.getECO2();
  uint16_t tvoc = ens160.getTVOC();

  int raw = analogRead(anemometerPin);
  float voltage = raw * (5.0 / 1023.0); // use 3.3 if on 3.3V board
  float windSpeed = voltage * 10; // adjust this formula based on datasheet

  String data = String(tempC) + "," + String(hum) + "," + String(eco2) + "," + String(tvoc) + "," + windSpeed;
  Serial.println(data);
  delay(1000); // wait 1 second
}
