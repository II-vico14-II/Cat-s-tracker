#include <SoftwareSerial.h>
#include <TinyGPS++.h>

SoftwareSerial serial_connection(4,3);
TinyGPSPlus gps;

void setup()
{
  Serial.begin(9600);
  serial_connection.begin(9600);
  Serial.println("GPS Start");
  
}

void loop()
{
  while(serial_connection.available())
  {
    gps.encode(serial_connection.read());
  }
  if(gps.location.isUpdated())
  {
    Serial.println("Satellite Count:");
    Serial.println(gps.satellites.value());
    Serial.println("Latitude :");
    Serial.println(gps.location.lat(), 6);
    Serial.println(gps.location.lng(), 6);
    Serial.println("Speed MPH :");
    Serial.println(gps.speed.mph());
    Serial.println("Altitute : ");
    Serial.println(gps.altitude.feet());
     

    delay(10000);
    
    
    
    
  }
  
}
