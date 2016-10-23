
/*LED Display Version 2.0 Last modified on 16/12/2015
 * 
 */
/*Pin configuration is as follows
 * D0 - 13 
 * D1 - A0
 * D2 - A1
 * D3 - A2
 * D4 - A3
 * D5 - A4
 * D6 - A5
 */
String len;
//void serialEvent();
String msg=" ";
String message;
boolean stringComplete = false; 
int pins[17]={13,A0,A1,A2,A3,A4,A5,2,3,4,5,6,7,8,9,10,11}; // Declaring Pins
int led=12;

// Initializing the hex code for characters
char font_5x7[95][6] = {
    {0x00,0x00,0x00,0x00,0x00}, //
    {0x00,0x00,0x7d,0x00,0x00}, // !
    {0x00,0x70,0x00,0x70,0x00}, // "
    {0x14,0x7f,0x14,0x7f,0x14}, // #
    {0x12,0x2a,0x6b,0x2a,0x24}, // $
    {0x32,0x34,0x08,0x16,0x26}, // %
    {0x36,0x49,0x4d,0x52,0x25}, // &
    {0x00,0x00,0x70,0x00,0x00}, // '
    {0x00,0x3e,0x41,0x00,0x00}, // (
    {0x00,0x00,0x41,0x3e,0x00}, // )
    {0x2a,0x1c,0x08,0x1c,0x2a}, // *
    {0x08,0x08,0x3e,0x08,0x08}, // +
    {0x00,0x01,0x06,0x04,0x00}, // ,
    {0x08,0x08,0x08,0x08,0x00}, // -
    {0x00,0x00,0x03,0x03,0x00}, // .
    {0x02,0x04,0x08,0x10,0x20}, // /
    {0x3e,0x41,0x41,0x3e,0x00}, // 0
    {0x11,0x21,0x7f,0x01,0x01}, // 1
    {0x21,0x43,0x45,0x49,0x31}, // 2
    {0x22,0x49,0x49,0x49,0x36}, // 3
    {0x0c,0x14,0x24,0x7f,0x04}, // 4
    {0x72,0x51,0x51,0x51,0x4e}, // 5
    {0x3e,0x49,0x49,0x49,0x26}, // 6
    {0x60,0x40,0x43,0x4c,0x70}, // 7
    {0x36,0x49,0x49,0x49,0x36}, // 8
    {0x32,0x49,0x49,0x49,0x3e}, // 9
    {0x00,0x36,0x36,0x00,0x00}, // :
    {0x01,0x36,0x34,0x00,0x00}, // ;
    {0x08,0x14,0x22,0x41,0x00}, // <
    {0x14,0x14,0x14,0x14,0x00}, // =
    {0x00,0x41,0x22,0x14,0x08}, // >
    {0x30,0x40,0x45,0x48,0x30}, // ?
    {0x3e,0x41,0x59,0x55,0x3c}, // @
    {0x3f,0X44,0x44,0x44,0x3f}, // A
    {0x7f,0x49,0x49,0x49,0x36}, // B
    {0x3e,0x41,0x41,0x41,0x22}, // C
    {0x41,0x7f,0x41,0x41,0x3e}, // D
    {0x7f,0x49,0x49,0x49,0x41}, // E
    {0x7f,0x48,0x48,0x48,0x40}, // F
    {0x3e,0x41,0x45,0x45,0x26}, // G
    {0x7f,0x08,0x08,0x08,0x7f}, // H
    {0x41,0x41,0x7f,0x41,0x41}, // I
    {0x42,0x41,0x41,0x7e,0x40}, // J
    {0x7f,0x08,0x14,0x22,0x41}, // K
    {0x7f,0x01,0x01,0x01,0x01}, // L
    {0x7f,0x20,0x18,0x20,0x7f}, // M
    {0x7f,0x20,0x18,0x06,0x7f}, // N
    {0x3e,0x41,0x41,0x41,0x3e}, // O
    {0x7f,0x48,0x48,0x48,0x30}, // P
    {0x3c,0x42,0x46,0x42,0x3d}, // Q
    {0x7f,0x48,0x4c,0x4a,0x31}, // R
    {0x32,0x49,0x49,0x49,0x26}, // S
    {0x40,0x40,0x7f,0x40,0x40}, // T
    {0x7e,0x01,0x01,0x01,0x7e}, // U
    {0x7c,0x02,0x01,0x02,0x7c}, // V
    {0x7e,0x01,0x06,0x01,0x7e}, // W
    {0x41,0x22,0x1c,0x22,0x41}, // X
    {0x70,0x08,0x0F,0x08,0x70}, // Y
    {0x43,0x45,0x49,0x51,0x61}, // Z
    {0x00,0x7f,0x41,0x00,0x00}, // [
    {0x20,0x10,0x08,0x04,0x02}, // "\"
    {0x00,0x00,0x41,0x7f,0x00}, // ]
    {0x00,0x20,0x40,0x20,0x00}, // ^
    {0x01,0x01,0x01,0x01,0x01}, // _
    {0x00,0x40,0x20,0x00,0x00}, // `
    {0x0c,0x12,0x14,0x0e,0x01}, // a
    {0x7e,0x11,0x11,0x0e,0x00}, // b
    {0x0e,0x11,0x11,0x11,0x00}, // c
    {0x0e,0x11,0x11,0x7e,0x00}, // d
    {0x0e,0x15,0x15,0x0d,0x00}, // e
    {0x08,0x3f,0x48,0x20,0x00}, // f
    {0x12,0x29,0x29,0x1e,0x00}, // g
    {0x7f,0x08,0x08,0x07,0x00}, // h
    {0x00,0x11,0x5f,0x01,0x00}, // i
    {0x00,0x12,0x11,0x5e,0x00}, // j
    {0x7f,0x04,0x0a,0x11,0x00}, // s
    {0x00,0x41,0x7f,0x01,0x00}, // l
    {0x3f,0x10,0x0f,0x10,0x0f}, // m
    {0x20,0x1f,0x10,0x10,0x0f}, // n
    {0x0e,0x11,0x11,0x0e,0x00}, // o
    {0x1f,0x14,0x14,0x08,0x00}, // p
    {0x08,0x14,0x14,0x1f,0x02}, // q
    {0x1f,0x08,0x10,0x00,0x00}, // r
    {0x09,0x15,0x15,0x12,0x00}, // s
    {0x10,0x7e,0x11,0x02,0x00}, // t
    {0x1e,0x01,0x01,0x1e,0x01}, // u
    {0x1e,0x01,0x1e,0x00,0x00}, // v
    {0x1e,0x01,0x06,0x01,0x1e},// w
    {0x11,0x0a,0x04,0x0a,0x11}, // x
    {0x19,0x05,0x06,0x18,0x00}, // y
    {0x13,0x15,0x19,0x11,0x00}, // z
    {0x00,0x08,0x36,0x41,0x00}, // {
    {0x00,0x00,0x7f,0x00,0x00}, // |
    {0x00,0x41,0x36,0x08,0x00}, // }
    {0x08,0x10,0x08,0x10,0x00}, // ~
};
//------------------------------------------------------------------------
char getChar(){                                                           //when this function is called it gets a character from the serial
  while(Serial.available() == false);                                     // it waits until the serial is available
  return Serial.read();                                                   //it returns the character which is read from the serial
}
void setup(){                                                                             // Open serial communications and wait for port to open:
  Serial.begin(9600);                                                     //serial communication for the microcontroller and system
  pinMode(led,OUTPUT);                                                    //led to see the if the message is received
  for (int i=0;i<17;i++)                                                  //for each pin in the array
   pinMode(pins[i],OUTPUT);                                               //pins for led display and system clocks
   msg.reserve(200);                                                      //limiting the size of the msg string to 200 
   for(int j=0;j<180;j++){                                                //for loop for all the leds off
      for(int i=0;i<7;i++){                                               //each column consists of 7 leds
        digitalWrite(pins[i],HIGH);                                       //to make all th led pins low
      }
      clockrate();                                                        //call for the clock to shift the regester
   }
}
void loop(){  
     if(Serial.available()){                                              //enters if the serial is open/available
      len="";                                                             //make the string empty to same the new incoming message
      for(int j=0;j<180;j++){                                             //for loop for all the leds off
      for(int i=0;i<7;i++){                                               //each column consists of 7 leds
        digitalWrite(pins[i],HIGH);                                       //to make all th led pins low when we receive a new message
      }
      clockrate();                                                        //call for the clock to shift the regester
   }
      
      for(int i=0; i<200; i++)                                            //taking the data character by character
       {
          char c = getChar();                                             //stores the character in c
          if(c == '\n')  {                                                //if the string goes to new line it will terminate
               break;                                                     // Terminate string.
             }
          len += c;                                                       //cocatinating the character to the string
       }
     Serial.write('\n');
    msg=len;                                                              //sending the string to msg which is used for the display
    digitalWrite(led, HIGH);                                              //led becomes high 
    delay(100);                                                           // delay is required for the lrd blink to be vissible
    digitalWrite(led, LOW);                                               //led becomes low
    display5x7();                                                         //call for the led display function
     }
    Serial.print("Received: ");
    Serial.println(msg);                                                  //print the message on the system
}

//---------------------------------------------------------------------
// Function to write the message to LED
void display5x7()   {
                                                                          //Check length of message and display each character
   for(int i=0;i<msg.length()-2;i++)  {
    if(i == 16)
    break;
    int length;
                                                                          // ASCII value of character - 32 is equivalent hex code in array
    int index=(int)msg[i]-32;
    for(int x=0;x<5;x++){
                                                                          //Copy equivalent hex values of each character and convert to binary
     String abc= String(font_5x7[index][x],BIN) ;
     char buf[10]={};
     String final = "";
     length = abc.length();
                                                                          // Add zeros after binary conversion to adjust values to display
     if (abc.length()<7)  {
       while(7-length!=0){
        final+="0";
        length++;
       }
     }
       final+=abc;
                                                                          //Convert string to char array
     final.toCharArray(buf,8);
                                                                          // Convert the value to string and write it to output pins

     for(int i = 0; i<7;i++) {
      if ((int)buf[i]-48==0)
       digitalWrite(pins[i],HIGH);
      else if ((int)buf[i]-48==1)
       digitalWrite(pins[i],LOW);
     }                                                                    // Give a clock cycle after every input to shift the display
         clockrate();
     }

 for(int j=0;j<1;j++){
     for(int i = 0; i<7;i++) {
  
       digitalWrite(pins[i],HIGH);
     }
     clockrate();
     }

     
    }
    //delay(2000);
    int spaces = ((16 - msg.length())*6);
     for(int j=0; j<spaces; j++)
     {
       for(int i= 0;i<7;i++)
         { 
           digitalWrite(pins[i],HIGH);           //to give spaces after the name which is printed
         }
         clockrate();
       }
     }
    
  

//------------------------------------------------------------------
//Function for clockrate
void clockrate(){
  
  {
    for(int j=7;j<17;j++)
 digitalWrite(pins[j],HIGH);
  delay(20);
  for(int j=7;j<17;j++)
 digitalWrite(pins[j],LOW);

 delay(20);
 
  } 
}
