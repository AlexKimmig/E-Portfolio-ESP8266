boolean parseWeather(String weatherJSON) {
  // Memory pool for JSON object tree.
  Serial.print("Parsing "); Serial.println(weatherJSON);

  StaticJsonBuffer<1024> jsonBuffer;

  // Root of the object tree.
  JsonObject& root = jsonBuffer.parseObject(weatherJSON);

  // Test if parsing succeeds.
  if (!root.success()) {
    Serial.println("parseObject() failed");
    Serial.println();
    return false;
  }

  // Fetch values.
  const char* city = root["name"];
  int temp = root["main"]["temp"];
  const char* weather = root["weather"][0]["main"];


  // Print values.
  Serial.print("City:             ");             Serial.println(city);
  Serial.print("Temp:             ");             Serial.println(temp);
  Serial.print("Weather:          ");          Serial.println(weather);


  //  displayLCD(String(city) + ": " + temp + "°C", weather);

  //    displayLCD("Waiting on ESP");

  lcd.clear();
  lcd.setCursor(0, 0); // top left
  lcd.print(String(city) + ": " + temp + "C"); // + ": " + String(temp) + "C"
  lcd.setCursor(0, 1); // bottom left
  lcd.print(weather);

  return true;
}

