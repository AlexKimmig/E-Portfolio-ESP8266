#include <ArduinoJson.h>
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);

  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Waiting for ESP");
}

void loop() {
  if (Serial1.available()) {
    String espSerialMessage;
    espSerialMessage = ESPSerialReadString(500);

    if (espSerialMessage.startsWith("WEATHER:")) {
      Serial.println("Parsing weather");
      String weatherJSON = espSerialMessage.substring(8);
      parseWeather(weatherJSON);
    } else {
      Serial.println("Unknown");
    }
  }
  delay(100);
}

String ESPSerialReadString(int delayDuration) {
  String string = Serial1.readString();
  Serial.println(string);
  delay(500);
  return string;
}
