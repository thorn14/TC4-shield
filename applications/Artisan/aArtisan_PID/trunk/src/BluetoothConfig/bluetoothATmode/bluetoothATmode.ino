#include <SoftwareSerial.h>
SoftwareSerial BTSerial(4, 5); // RX, TX
String response = "";
void setup() {
// Serial connection to host PC:
Serial.begin(9600);
Serial.println("Type AT commands!");
// Serial connection to BT module:
BTSerial.begin(9600);
// You might have to adjust the baud rate!
}
void loop() {
// Check if BT module has sent data, and pass it to host PC:
if (BTSerial.available()) {
delay(10);
while(BTSerial.available()) {
response += (char)BTSerial.read();
}
Serial.println(response);
response = "";
}
// Vice versa: Check if host PC has sent data, and pass it to BT module:
if (Serial.available()){
delay(10);
BTSerial.write(Serial.read());
}
}