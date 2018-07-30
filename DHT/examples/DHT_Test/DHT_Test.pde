
//**************************************************************//
//  Name    : DHT Test                              
//  Author  : Robert Jaenisch 
//  Date    : 10 Feb, 2015    
//  Modified:                                 
//  Version : 1.0
//  URL     : http://deskfactory.de
//  Notes   : Programmcode zum Auslesen eines DHT Sensors. Der Urspruenglche Code von Rob Tillaart wurde   //
//            ins Deutsch übersetzt und die Ausgabe zu besseren Lesbarkeit angepasst.                     //
//            Verweis auf den Original Code:                                                              //                          

//    FILE: dht_test.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.07
// PURPOSE: DHT Temperature & Humidity Sensor library for Arduino
//     URL: http://arduino.cc/playground/Main/DHTLib
//
// Released to the public domain
//
//****************************************************************


// Laden der DHT Sensor Bibliothek
#include <DHT.h>

dht DHT;

// Definieren der Datenanbindung für den passenden DHT Sensor.
// In unseren Beispiel nutzen wir einen DHT11 und somit den Arduino Uno Pin 4.
#define DHT11_PIN 4 
#define DHT21_PIN 5
#define DHT22_PIN 6

int chk;

void setup()
{
  Serial.begin(9600);
  Serial.println("DHT TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT_LIB_VERSION);
  Serial.println();
}

void loop()
{
  // Daten für den DHT22 Sensor Lesen
  /*
    Serial.print("Type: DHT22, \t");
    chk = DHT.read22(DHT22_PIN);
    switch (chk)
    {
      case DHTLIB_OK:  
      Serial.print("Status: OK,\t"); 
      break;
      case DHTLIB_ERROR_CHECKSUM: 
      Serial.print("Status: Checksum error,\t"); 
      break;
      case DHTLIB_ERROR_TIMEOUT: 
      Serial.print("Status: Time out error,\t"); 
      break;
      default: 
      Serial.print("Status: unbekannter Fehler,\t"); 
      break;
    }
     // Ausgabe der Daten über die serielle Schnittstelle
    Serial.print("relative Luftfeuchtigkeit (%): ");
    Serial.print(DHT.humidity, 1);
    Serial.print(",\tTemperatur (C)");
    Serial.println(DHT.temperature, 1);
  
    delay(1000);
  */

    // Daten für den DHT21 lesen
    /*
    Serial.print("Type: DHT21, \t");
    chk = DHT.read21(DHT21_PIN);
    switch (chk)
    {
      case DHTLIB_OK:  
      Serial.print("Status: OK,\t"); 
      break;
      case DHTLIB_ERROR_CHECKSUM: 
      Serial.print("Status: Checksum error,\t"); 
      break;
      case DHTLIB_ERROR_TIMEOUT: 
      Serial.print("Status: Time out error,\t"); 
      break;
      default: 
      Serial.print("Status: unbekannter Fehler,\t"); 
      break;
    }
     // Ausgabe der Daten über die serielle Schnittstelle
    Serial.print("relative Luftfeuchtigkeit (%): ");
    Serial.print(DHT.humidity, 1);
    Serial.print(",\tTemperatur (C)");
    Serial.println(DHT.temperature, 1);
  
    delay(1000);
  */
  
  // Daten für den DHT11 Sensor lesen
  Serial.print("Type: DHT11, \t");
  chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
    Serial.print("Status: OK,\t"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    Serial.print("Status: Checksum error,\t"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.print("Status: Time out error,\t"); 
    break;
    default: 
    Serial.print("Status: unbekannter Fehler,\t"); 
    break;
  }
 // Ausgabe der Daten über die serielle Schnittstelle
    Serial.print("relative Luftfeuchtigkeit (%): ");
    Serial.print(DHT.humidity, 1);
    Serial.print(",\tTemperatur (C)");
    Serial.println(DHT.temperature, 1);

  delay(1000);
}
//
// ENDE DER DATEI
//