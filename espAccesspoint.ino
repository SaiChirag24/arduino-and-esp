
#include <WiFi.h>

void setup()
{
Serial.begin(115200);

  delay(2000);
  Serial.println("START");
  WiFi.softAP("ESP-32","password");
  Serial.println("IP address");
  Serial.println((WiFi.softAPIP()));

}


void loop()
{

    Serial.println("number of devices connected");
    Serial.println((WiFi.softAPgetStationNum()));
    delay(1000);

}