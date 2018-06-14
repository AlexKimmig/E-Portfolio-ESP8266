boolean testWiFi(char ssid[],char pass[]) {
  //Check connection
  int ctr = 0;

  //Configuring WiFi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    //Trying connection for 10 times
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
