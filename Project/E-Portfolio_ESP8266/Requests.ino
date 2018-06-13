String requestCurrentWeather() {
  Serial.println("-----Requesting weather-----");
  WiFiClient client;

  Serial.printf("\n[Connecting to %s ...", URL_OPEN_WEATHER_API);
  if (client.connect(URL_OPEN_WEATHER_API, 80))
  {
    Serial.println("connected]");

    Serial.println("[Sending a request]");

    client.println(String("GET ") + URL_CURRENT_WEATHER + " HTTP/1.1");
    client.println(String("Host: ") + URL_OPEN_WEATHER_API);
    client.println("Connection: close");
    client.println();

    Serial.println("[Response:]");
    String response = "";
    while (client.connected())
    {
      if (client.available())
      {
        response = client.readString();

        int indexOfResponse = response.indexOf("{");
        response = response.substring(indexOfResponse);
      }
    }
    client.stop();
    return response;
  }
  else
  {
    client.stop();    Serial.println("connection failed!]");
    Serial.println();
    return "Couldn't connect to Server";
  }
}

