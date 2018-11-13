void setup() {
  // initialize both serial ports:
  Serial1.begin(115200);
  Serial.begin(115200);

}

void loop()
{
  Serial1.println("AT+GMR"); //Status abfragen
  String s = Serial1.readString();
  Serial.println("STRING:");
  Serial.println(s);
 
  delay(5000);
}
