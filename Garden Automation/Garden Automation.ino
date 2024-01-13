#include "time.h"
#include <ESP8266WiFi.h>

const char* ssid     = "";        // your network SSID (name)
const char* password = "";       // your network password

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 0;
const int   daylightOffset_sec = 3600;

void setup()
{
  Serial.begin(115200);
  delay(10);
 
  Serial.print("\n\nConnecting to ");
  Serial.println(ssid);
 
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
 
 configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
 
  Serial.println("\nWaiting for time");
  unsigned timeout = 5000;
  unsigned start = millis();
  while (!time(nullptr))
  {
    Serial.print(".");
    delay(1000);
  }
  delay(1000);
 
  Serial.println("Time...");
}

void loop()
{
  time_t current = time(nullptr);
  Serial.print(ctime(&current));
  delay(500);
}
