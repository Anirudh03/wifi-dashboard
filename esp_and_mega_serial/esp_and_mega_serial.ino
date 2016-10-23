/*Mega Serial Version 1.0 Last modified on 19/12/2015
 * 
 */
 
/*
 *esp and mega serial communication and 6 serial ports
 */
 #include <SoftwareSerial.h>
 SoftwareSerial wifiSerial(10, 11);                               // RX, TX
 SoftwareSerial HardwareSerial1(19, 18);                          // RX, TX
 SoftwareSerial HardwareSerial2(17, 16);                          // RX, TX
 SoftwareSerial HardwareSerial3(15, 14);                          // RX, TX
 SoftwareSerial Serial4(2, 3);                                    // RX, TX
 SoftwareSerial Serial5(4, 5);                                    // RX, TX
 SoftwareSerial Serial6(6, 7);                                    // RX, TX
String inputString = "";                                          // a string to hold incoming data
boolean stringComplete = false;                                   // whether the string is complete
int flag = 0;                                                     //to see the number of line
void setup(){
  // initialize serial:
  Serial.begin(9600);                                             //serial for debuggung
  wifiSerial.begin(9600);                                         //serial to communicate with wifi
  HardwareSerial1.begin(9600);                                    //6 serials to send names to the led boards
  HardwareSerial2.begin(9600);  
  HardwareSerial3.begin(9600);
  Serial4.begin(9600);
  Serial5.begin(9600);
  Serial6.begin(9600);      
  inputString.reserve(200);                                      // reserve 200 bytes for the inputString:
}

void loop() {
  serialEvent();                                                 //call the function
  delay(1000);
  if (stringComplete) {                                          //if the string is complete i.e stringcomplete is true
   if(flag == 1){                                                //if connected
       Serial.println();                                         //send a empty string
       }
   }
  if(flag > 1){                                                  //after connected
  int number=0;                                                  //initialize the number of name to 0
  String s =inputString;                                         //giving the input string to seperate
  String name1,name2,name3,name4,name5,name6;                    //strings to save the names of the students
  String temp="";                                                //temporary variable to store the data
 for(int i=0;i<s.length();i++){                
  if(s[i]!=',') temp+=s[i];                                      //if the incomming character is not a "," then take it into temp
   if(s[i]==',' || i== s.length()-1){                            //if the incomming character is a "," or the last character of the string then 
    number++;                                                    //increase the number and check the number
    switch(number){                                              //sending the names to the respective serial
      case 1: 
            name1=temp;
            temp="";
            HardwareSerial1.println(name1);
            break;
      case 2:
            name2=temp;
            temp="";
            HardwareSerial2.println(name2);
            break;
      case 3:
            name3=temp;
            temp="";
            HardwareSerial3.println(name3);
            break;
      case 4:
            name4=temp;
            temp="";
            Serial4.println(name4);
            break;
      case 5:
            name5=temp;
            temp="";
            Serial5.println(name5);
            break;
      case 6:
            name6=temp;
            temp="";
            Serial6.println(name6);
            break;
    }
   }
   Serial.println(inputString);                                        //printing for debugging
  }
  inputString = "";                                                    //reseting the input string to empty
  stringComplete = false;                                              //making stringcomplete to false
 }
}
 /*
  *SerialEvent occurs whenever a new data comes in the
  *hardware serial RX.  This routine is run between each
  *time loop() runs, so using delay inside loop can delay
  *response.  Multiple bytes of data may be available.
  */
void serialEvent() {
  while (wifiSerial.available()) {
    char inChar = (char)wifiSerial.read();                            // get the new byte:
    if (inChar != '\n') {                                             // add it to the inputString:
      inputString += inChar;                                          // not concatinating new line character at the end of the string
    }    
    else {
      flag++;                                                         // if the incoming character is a newline, set a flag
      stringComplete = true;                                          // so the main loop can do something about it:
    }
  }
}
