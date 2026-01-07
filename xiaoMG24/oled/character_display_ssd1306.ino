//Uses SSD1306 library by vlodymyr kumpan
   // library file needs edits on cpp file: https://docs.google.com/document/d/1DgA_IxW4ZyAJf7BHWbWGh3gFYRJy0vEe/edit#heading=h.wzlawsxa1qej 
#include <SSD1306.h>
#include <Wire.h>

SSD1306 display;
// use this for 128x32 displays
// SSD1306 display(SSD1306_HEIGHT_32);

void setup() {
  Serial.begin(9600);
  Wire.begin();

  display.init();
  display.clear();

  display.print('!');
  display.print(F("\"#$%&'()*+,-./"));
  display.setCaret(10, 10);
  display.setScale(2);
  display.print(F("0123456789"));
  display.setCaret(40, 28);
  display.setScale(1);
  display.print(F(":;<=>?@"));
  display.setCaret(0, 40);
  display.print(F("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
  display.print(F("[\\]^_`"));
  display.print(F("abcdefghijklmnopqrstuvwxyz"));
  display.print(F("{|}~"));

  display.update();
}

void loop() {
}
