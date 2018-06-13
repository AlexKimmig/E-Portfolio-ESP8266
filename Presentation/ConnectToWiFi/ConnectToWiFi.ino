#include <ESP8266WiFi.h>

char ssid[] = "myNetwork";    //  your network SSID (name) 
char pass[] = "myPassword";   // your network password
int status = WL_IDLE_STATUS;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  Serial.println("Attempting to connect to WPA network...");

  status = WiFi.begin(ssid, pass);
  if ( status != WL_CONNECTED) { 
    Serial.println("Couldn't get a wifi connection");
    while(true);
  } 
  else {
    Serial.print("Connected to wifi. My address:");
  }
}

void loop() {

}

