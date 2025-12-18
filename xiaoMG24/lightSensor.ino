//Serial print light sensor values
#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;

void setup() {
  Serial.begin(115200);
  Wire.begin();           // SDA=D4, SCL=D5 on XIAO MG24
  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println("BH1750 OK");
  } else {
    Serial.println("BH1750 fail");
  }
}

void loop() {
  float lux = lightMeter.readLightLevel();   // returns lux as float
  if (lux >= 0) {
    // Send only the value as CSV (e.g., 123.45\n)
    Serial.println(lux, 2);
  }
  delay(2000);
}
