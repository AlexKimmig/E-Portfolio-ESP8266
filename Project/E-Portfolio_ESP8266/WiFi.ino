boolean testWiFi(char ssid[],char pass[]) {
  //Check connection
  int ctr = 0;
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1500);
    ctr++;
    if (ctr == 10) {
      WiFi.disconnect();
      return false;
    }
  }
  Serial.println();
  return true;
}
