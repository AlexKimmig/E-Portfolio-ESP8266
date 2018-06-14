#include <ESP8266WiFi.h>

char ssid2[] = "ssid"; //  your network SSID (name)
char pass2[] = "password";    // your network password (use for WPA, or use as key for WEP)

// URLs
const char URL_OPEN_WEATHER_API[] = "api.openweathermap.org";
const char URL_CURRENT_WEATHER[] = "/data/2.5/weather?id=2892794&units=metric&APPID=8b0cf6148353f8a2f51e348222ca6bb1";

void setup() {
  delay(10000);
  Serial.begin(9600);
  
  //Connecting to WiFi
  testWiFi(ssid2, pass2);
}

void loop() {
  //Getting weather JSON from API and sending it to the arduino
  String serialMsg = "WEATHER:";
  serialMsg += requestCurrentWeather();
  Serial.println(serialMsg);

  delay(1200000);
}
