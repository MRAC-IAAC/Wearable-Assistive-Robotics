#include <Wire.h>



void setup() {
 Wire.begin(8);                /* join i2c bus with address 8 */
 Wire.onReceive(receiveEvent); /* register receive event */
 Serial.begin(115200);           /* start serial for debug */

}

void loop() {
 delay(100);
}

void processCall(String command){
}


void receiveEvent(int howMany) {
  String data="";
 while (0 <Wire.available()) {
    char c = Wire.read();      /* receive byte as a character */
    data += c;
    
  }
    Serial.println(data);           /* print the request data */
    processCall(data);         /* to newline */
}
