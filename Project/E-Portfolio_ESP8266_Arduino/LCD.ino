void displayLCD(String messageRow1, String messageRow2) {
  lcd.clear();
  lcd.setCursor(0, 0); // top left
  lcd.print(messageRow1);
  lcd.setCursor(0, 1); // top left
  lcd.print(messageRow2);
}

void displayLCD(String message) {
  String row1 = message, row2 = "";
  if (message.length() > 16) {
    row1 = message.substring(0, 16);
    row2 = message.substring(16);
  }
  lcd.clear();
  lcd.setCursor(0, 0); // top left
  lcd.print(row1);
  lcd.setCursor(0, 1); // top left
  lcd.print(row2);
  message = "";
}
