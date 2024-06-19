
String data = " ";
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    data=Serial.readString();
    if (data == "1"){
      Serial.write("Data: 1");}
    else{
      Serial.write("data Not 1");}
  }
}
