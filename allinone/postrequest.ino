// this method makes a HTTP connection to the server


void httpRequest()
{
  //String PostData = "{\"EC\":" + String(EC25) + "," + "\"PH\":" + String(pHValue) + "," + "\"WTEMP\":" + String(Temperature) + "}";
  String PostData = "EC=" + String(EC25) + "&PH=" + String(phelp) + "&WTEMP=" + String(Temperature);

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
