#include <ESP8266WiFi.h>
#include <Servo.h>
#include "user_interface.h"
os_timer_t myTimer;
bool tickOccured;

Servo myservo, myservoc;
WiFiServer server(80); //Initialize the server on Port 80
const short int LED_PIN = 16;//GPIO16
int angle;
int endpoint;

int tmp;

int NOTEPOS_DN[] = {92,82,72,68,62,56,50,46}; //target positions of notes when moving downwards
int NOTEPOS_UP[] = {92,78,70,66,60,56,46,40}; //target positions of notes when moving upwards
int SONGLEN = 68;
//Do Re Mi
int SONG1[] = {1,1,1,2,3,3,3,1,3,3,3,1,3,3,3,3,2,2,2,3,4,4,3,2,4,4,4,4,4,4,4,4,3,3,3,4,5,5,5,3,5,5,3,3,5,5,5,5,4,4,4,5,6,6,5,4,6,6,6,6,6,6,6,6}; 
//The Ode to Joy
int SONG[]  = {3,3,4,5,5,4,3,2,1,1,2,3,3,2,2,2,3,3,4,5,5,4,3,2,1,1,2,3,2,1,1,1,2,2,3,1,2,4,3,1,2,4,3,2,1,2,2,2,3,3,4,5,5,4,3,2,1,1,2,3,2,1,1,1};

int currentNote;
int lastNote;
int newNote;
int stage;

bool started;

void timerCallback(void *pArg) {
      tickOccured = true;

      if (started == false)
        return;

      if (stage == 0){ //change ruler position
        stage = 1;
        newNote = SONG1[currentNote]-1;
        if (newNote > lastNote ){
          tmp = NOTEPOS_UP[newNote];
          myservo.write(tmp);
        } else if (newNote < lastNote){
          tmp = NOTEPOS_DN[newNote];
          myservo.write(tmp);
        }
        lastNote = newNote;
        currentNote = currentNote+1;
        if (currentNote > SONGLEN)
          currentNote = currentNote - SONGLEN;
        myservoc.write(85);
      } else if(stage == 1){ //leave some time for ruler to reach the right position
        stage = 2;     
      } else if(stage == 2){
        stage = 3;
      }else if (stage == 3){ //move the continuous servo for 200 ms
        myservoc.write(180);
        stage  = 0;
      }
}

void user_init(void) {
      os_timer_setfn(&myTimer, timerCallback, NULL);
      os_timer_arm(&myTimer, 200, true);
      currentNote = 0;
      lastNote = 0;
      newNote = 0;
      stage = 0;
}

void setup() {
  started = false;
  WiFi.mode(WIFI_AP); //Our ESP8266-12E is an AccessPoint
  WiFi.softAP("Arthur_ee183d", "12345678"); // Provide the (SSID, password); .
  server.begin(); // Start the HTTP Server
  myservo.attach(2);
  myservoc.attach(4);
  
  //Looking under the hood
  Serial.begin(115200);
  //while(!Serial){}
  IPAddress HTTPS_ServerIP= WiFi.softAPIP(); // Obtain the IP of the Server
  Serial.print("Server IP is: "); // Print the IP to the monitor window
  Serial.println(HTTPS_ServerIP);
  pinMode(LED_PIN, OUTPUT); //GPIO16 is an OUTPUT pin;
  digitalWrite(LED_PIN, LOW); //Initial state is ON
  angle = 85;
  endpoint = 0;
  myservo.write(85);
  myservoc.write(85);
  tickOccured = false;
  user_init();
}
void loop() {
   if (tickOccured == true)
  {
    //Serial.println("Tick Occurred");
    tickOccured = false;
   }
  
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  //Looking under the hood
  Serial.println("Somebody has connected :)");
  
  //Read what the browser has sent into a String class
  //and print the request to the monitor
  String request = client.readStringUntil('\r');
  //Looking under the hood
  Serial.println(request);
  
  // Handle the Request
  if (request.indexOf("/OFF") != -1){
    digitalWrite(LED_PIN, HIGH); }
  else if (request.indexOf("/ON") != -1){
    digitalWrite(LED_PIN, LOW);  }
  else if (request.indexOf("/START") != -1){
    currentNote = 0;
    started = true;}
  else if (request.indexOf("/STOP") != -1){
    started = false; }
  else if (request.indexOf("/value") != -1){
    endpoint = request.indexOf("HTTP");
    angle = request.substring(11,endpoint-1).toInt();
    Serial.println(angle);
    //myservo.write(angle);                     //move ruler to given position for tuning
  }
  
  // Prepare the HTML document to respond and add buttons:
  String s = "HTTP/1.1 200 OK\r\n";
  s += "Content-Type: text/html\r\n\r\n";
  s += "<!DOCTYPE HTML>\r\n<html>\r\n";
  s += "<style> .button { color: black; padding: 15px 32px; text-align: center; font-size: 20px;} </style>";
  s += "<style> .slider {  width: 300px;} </style>";
  s += "<br><input type=\"button\" name=\"b1\" value=\"LED On\"";
  s += " onclick=\"location.href='/ON'\">";
  s += "<br><br>";
  s += "<br><input type=\"button\" name=\"b1\" value=\"LED Off\"";
  s += " onclick=\"location.href='/OFF'\">";
  s += "<br><br>";
    s += "<br><input type=\"button\" name=\"b1\" value=\"Start\"";
  s += " onclick=\"location.href='/START'\">";
  s += "<br><br>";
    s += "<br><input type=\"button\" name=\"b1\" value=\"Stop\"";
  s += " onclick=\"location.href='/STOP'\">";
  s += "<br><br>";
  s += "<br><input type=\"range\" class=\"slider\" min=\"0\" max=\"180\" value=\"";  //a slider to get numerical input, used only for tuning
  s += String(angle);
  s += "\"step=\"2\" ";
  s += " onchange=\"location.href='/value='+this.value.toString()\">";
  s += "</html>\n";
  //Serve the HTML document to the browser.
  client.flush(); //clear previous info in the stream
  client.print(s); // Send the response to the client
  delay(1);
  Serial.println("Client disonnected"); //Looking under the hood
}
