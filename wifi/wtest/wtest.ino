/*
 WiFiEsp example: WebClientRepeating

 This sketch connects to a web server and makes an HTTP request
 using an Arduino ESP8266 module.
 It repeats the HTTP call each 10 seconds.

 For more details see: http://yaab-arduino.blogspot.com/p/wifiesp.html
*/

#include "WiFiEsp.h"
#include "secret.h"
// Emulate Serial1 on pins 6/7 if not present
#ifndef HAVE_HWSERIAL1
#include "SoftwareSerial.h"
SoftwareSerial Serial1(19, 18); // RX, TX
#endif

//char ssid[] = "*****";     // your network SSID (name)
//char pass[] = "*****";  // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status

char server[] = "sven-holter.de";

unsigned long lastConnectionTime = 0;         // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 10000L; // delay between updates, in milliseconds

// Initialize the Ethernet client object
WiFiEspClient client;

int value = 1;
//String PostData = "EC%3D1%26PH%3D2%26WTEMP%3D4";
String PostData = "EC=1&PH=2&WTEMP=4";
//String PostData = "{\"EC\":" + String(value) + "," + "\"PH\":" + String(value) + "," + "\"WTEMP\":" + String(value) + "}";

void setup()
{
  // initialize serial for debugging
  Serial.begin(115200);
  // initialize serial for ESP module
  Serial1.begin(115200);
  // initialize ESP module
  WiFi.init(&Serial1);

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
  }

  Serial.println("You're connected to the network");
  
  printWifiStatus();
}

void loop()
{
  // if there's incoming data from the net connection send it out the serial port
  // this is for debugging purposes only
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }

  //if (!client.connected()) {
  //  Serial.println();
  //  Serial.println("Disconnecting from server...");
  //  client.stop();
  //}
  
  // if 10 seconds have passed since your last connection,
  // then connect again and send data
  if (millis() - lastConnectionTime > postingInterval) {
    httpRequest();
  }
}

// this method makes a HTTP connection to the server
void httpRequest()
{
  Serial.println();
    
  // close any connection before send a new request
  // this will free the socket on the WiFi shield
  client.stop();

  // if there's a successful connection
  if (client.connectSSL(server, 443)) {
    Serial.println("Connecting...");

    String PostHeader = "POST /sensordata.php HTTP/1.1\r\n";
    PostHeader += "Host: sven-holter.de\r\n";
    PostHeader += auth;
    PostHeader += "Connection: keep-alive\r\n";
    //PostHeader += "Content-Type: application/json; charset=utf-8\r\n";
    PostHeader += "Content-Type: application/x-www-form-urlencoded\r\n";
    PostHeader += "Content-Length: " + String(PostData.length()) + "\r\n\r\n";
    PostHeader += PostData;
    Serial.println(PostHeader);
    client.println(PostHeader);

    
    // note the time that the connection was made
    lastConnectionTime = millis();
  }
  else {
    Serial.println("Connection failed");
  }
}


void printWifiStatus()
{
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
