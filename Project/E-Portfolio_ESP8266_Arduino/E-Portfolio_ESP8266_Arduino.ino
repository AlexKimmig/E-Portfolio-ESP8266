#include <ArduinoJson.h>
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  //Serial 1 is for recieving data from the ESP
  Serial1.begin(9600);

  //Serial is to communicate to the Serial monitor via. USB
  Serial.begin(9600);

  //Initializing size of the LCD
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Waiting for ESP");
}

void loop() {
  if (Serial1.available()) {  //When recieving a message from the ESP
    String espSerialMessage;
    espSerialMessage = ESPSerialReadString(500);  //It catches it

    if (espSerialMessage.startsWith("WEATHER:")) {  //Checking if the message begins with the keyword "WEATHER:"
      Serial.println("Parsing weather");
      String weatherJSON = espSerialMessage.substring(8); //Cutting out the "WEATHER:" part so we only have to JSON
      parseWeather(weatherJSON);  //Parsing the JSON
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
