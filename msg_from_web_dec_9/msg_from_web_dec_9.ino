/*WEB Message Version 1.0 Last modified on 21/12/2015
 * 
 */
 
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "power";                                                                                   //wifi name
const char* password = "r&dkmit123";                                                                          //wifi password

String form =
  "<p>"
  "<center>"
  "<h1>WELCOME TO KMIT DASHBOARD</h1>"
  "<img src='http://imgur.com/37GLBXA.jpg'>"
  "<form action='msg'><p>ENTER COMMA SEPARATED MESSAGE <input type='text' name='msg' size=50 autofocus>"     //HTML code for the web page
  "<input type='Button' value='Submit'></form>"
  "</center>";
ESP8266WebServer server(80);                                                                                 // HTTP server will listen at port 80
void handle_msg() {
  
  server.send(200, "text/html", form);                                                                       // Send same page so they can send another msg

  // Display msg on LCD
  String msg = server.arg("msg");
  Serial.println(msg);
}


void setup(void) {
  Serial.begin(9600);
  delay(500);
  WiFi.begin(ssid, password);                                                                               // Connect to WiFi network
  Serial.println("");
  while (WiFi.status() != WL_CONNECTED) {                                                                   // Wait for connection
    delay(500);
    Serial.print(".");
  }
   Serial.println("");
   Serial.print("Connected to");
   Serial.print(ssid);
   Serial.print("IP address:");
   Serial.println(WiFi.localIP());                                                                          //sends the ip address of the module
  server.on("/", []() {
    server.send(200, "text/html", form);
  }); 
  server.on("/msg", handle_msg);                                                                            // And as regular external functions:
  server.begin(); // Start the server 
  Serial.println("HTTP server Started");
}
void loop(void)
{
  server.handleClient();
}

