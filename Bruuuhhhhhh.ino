// kill me

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

SoftwareSerial serial_connection(10, 11); // RX is 10 and TX is 11
TinyGPSPlus gps; // GPS object thing
static const uint32_t GPSBaud = 9600;

void setup() {

Serial.begin(GPSBaud);
serial_connection.begin(9600);
Serial.println("GPS Starting...");

}

void loop() {

  while(serial_connection.available())
  {
    gps.encode(serial_connection.read());
  }
  if(gps.location.isUpdated())
  { 
    Serial.println("Satellites: ");
    Serial.println(gps.satellites.value());
    Serial.println("Latitude: ");
    Serial.println(gps.location.lat(), 6);
    Serial.println("Longitude: ");
    Serial.println(gps.location.lng(), 6);
    Serial.println("Speed (MPH): ");
    Serial.println(gps.speed.mph());
  }


delay(100);

}
