/* This code has been modified by That's So Mo to be "suited" for the magic bell trick, it was initially created by Awais Naeem over at www.embedded-robotics.com
 * This code will configure ESP8266 in SoftAP mode and will act as a web server for atleast two connecting devices. It will then turn On/Off the magnet.
 */
 
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
 
/*Specifying the SSID and Password of the AP*/
 
const char* ssid = "TrudyNet7315"; //Access Point SSID
const char* password= "Test123456"; //Access Point Password
uint8_t max_connections=2;//Maximum Connection Limit for AP
int current_stations=0, new_stations=0;
 
//Specifying the Webserver instance to connect with HTTP Port: 80
ESP8266WebServer server(80);
 
//Specifying the Pins connected from magnet to LED4
uint8_t magnet_pin=D1;
 
//Specifying the boolean variables indicating the status of magnet to LED4
bool magnet_status=false;
 
void setup() {
  //Start the serial communication channel
  Serial.begin(115200);
  Serial.println();
 
  //Output mode for the LED Pins
  pinMode(magnet_pin,OUTPUT);
   
  //Setting the AP Mode with SSID, Password, and Max Connection Limit
  if(WiFi.softAP(ssid,password,1,false,max_connections)==true)
  {
    Serial.print("Access Point is Created with SSID: ");
    Serial.println(ssid);
    Serial.print("Max Connections Allowed: ");
    Serial.println(max_connections);
    Serial.print("Access Point IP: ");
    Serial.println(WiFi.softAPIP());
  }
  else
  {
    Serial.println("Unable to Create Access Point");
  }
 
  //Specifying the functions which will be executed upon corresponding GET request from the client
  server.on("/",handle_OnConnect);
  server.on("/magneton",handle_magneton);
  server.on("/magnetoff",handle_magnetoff);
  server.onNotFound(handle_NotFound);
   
  //Starting the Server
  server.begin();
  Serial.println("HTTP Server Started");
}
 
void loop() {
  //Assign the server to handle the clients
  server.handleClient();
     
  //Continuously check how many stations are connected to Soft AP and notify whenever a new station is connected or disconnected
  new_stations=WiFi.softAPgetStationNum();
   
  if(current_stations<new_stations)//Device is Connected
  {
    current_stations=new_stations;
    Serial.print("New Device Connected to SoftAP... Total Connections: ");
    Serial.println(current_stations);
  }
   
  if(current_stations>new_stations)//Device is Disconnected
  {
    current_stations=new_stations;
    Serial.print("Device disconnected from SoftAP... Total Connections: ");
    Serial.println(current_stations);
  }
 
  //Turn the LEDs ON/OFF as per their status set by the connected client
   
  //magnet
  if(magnet_status==false)
  {
    digitalWrite(magnet_pin,LOW);
  }
  else
  {
    digitalWrite(magnet_pin,HIGH);
    delay(1000);
    digitalWrite(magnet_pin,LOW);
    delay(500);        
  }
 
}
 
void handle_OnConnect()
{
  Serial.println("Client Connected");
  server.send(200, "text/html", HTML()); 
}
 
void handle_magneton()
{
  Serial.println("magnet ON");
  magnet_status=true;
  server.send(200, "text/html", HTML());
}
 
void handle_magnetoff()
{
  Serial.println("magnet OFF");
  magnet_status=false;
  server.send(200, "text/html", HTML());
}
  
void handle_NotFound()
{
  server.send(404, "text/plain", "Not found");
}
 
String HTML()
{
  String msg="<!DOCTYPE html> <html>\n";
  msg+="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  msg+="<title>Magnet Control</title>\n";
  msg+="<style>html{font-family:Helvetica; display:inline-block; margin:0px auto; text-align:center; background-color:#2B2934;}\n";
  msg+="body{margin-top: 50px;} h1{color: #000000; margin: 50px auto 30px;} h3{color:#000000; margin-bottom: 50px;}\n";
  msg+=".button{display:block; width:80px; background-color:#f48100; border:none; color:white; padding: 13px 30px; text-decoration:none; font-size:25px; margin: 0px auto 35px; cursor:pointer; border-radius:4px;}\n";
  msg+=".button-on{background-color:#26282d;}\n";
  msg+=".button-on:active{background-color:#26282d;}\n";
  msg+=".button-off{background-color:#000000;}\n";
  msg+=".button-off:active{background-color:#000000;}\n";
  msg+="</style>\n";
  msg+="</head>\n";
  msg+="<body>\n";
  msg+="<h1>The Bell Magic Trick Server</h1>\n";
  msg+="<h3>Using Access Point (AP) Mode</h3>\n";
   
  if(magnet_status==false)
  {
    msg+="<p>MAGNET Status: OFF</p><a class=\"button button-on\" href=\"/magneton\">ON</a>\n";    
  }
  else
  {
    msg+="<p>MAGNET Status: ON</p><a class=\"button button-off\" href=\"/magnetoff\">OFF</a>\n";
  }
   
  msg+="</body>\n";
  msg+="</html>\n";
  return msg;
}