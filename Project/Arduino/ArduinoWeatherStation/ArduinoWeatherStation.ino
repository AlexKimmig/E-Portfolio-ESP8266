void setup() {
  Serial.begin(57600);
  Serial1.begin(57600);

}

void loop() {
  // put your main code here, to run repeatedly:

}

ESPPrintLn(String message){
  Serial.println("@ESP: " + message);
  Serial1.println(message);
  delay(100);
}

