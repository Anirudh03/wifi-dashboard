
/*Serial Version 1.0 Last modified on 21/12/2015
 * 
 */
 
 /* 
 When new serial data arrives, this sketch adds it to a String.
 When a newline is received, the loop prints the string and
 clears it.
 */
#include <SoftwareSerial.h>
SoftwareSerial dbgSerial(10, 11);                                     // RX, TX
String inputString = "";                                              // a string to hold incoming data
boolean stringComplete = false;                                       // whether the string is complete
int flag = 0;
void setup() {                                                        // initialize serial:
Serial.begin(9600);
dbgSerial.begin(9600);                                              
inputString.reserve(200);                                             // reserve 200 bytes for the inputString: 
}
void loop() {
  serialEvent();                                                      //call the function
  delay(1000);
  if (stringComplete) { 
   if(flag == 2){
      Serial.println("WELCOME TO KMIT");                              //displays welcome to kmit when connected
    }
   if(flag > 2){                                                      // displays the incoming message
    Serial.println(inputString);
    }
    inputString = "";                                                 //empty the string for next message
    stringComplete = false;                                           //make string complete false
  }
}
void serialEvent() {
  while (dbgSerial.available()) {
    char inChar = (char)dbgSerial.read();                             // get the new byte:
    if (inChar != '\n') {
      inputString += inChar;                                          // not concatinating new line character at the end of the string
    }   
    else {
      flag++;                                                         // if the incoming character is a newline, set a flag
      stringComplete = true;
    }
  }
}
