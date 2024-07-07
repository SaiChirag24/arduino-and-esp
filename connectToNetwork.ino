
#include <WiFi.h>

void setup()
{
Serial.begin(115200);

  WiFi.disconnect();
  delay(3000);
  Serial.println("----starting---");
  WiFi.begin("NR JIO-FI 2G","16nr1969");
  while ((!(WiFi.status() == WL_CONNECTED))){
    Serial.print("");
    delay(1000);

  }
  Serial.println("connected");
  Serial.println("IP address is");
  Serial.println((WiFi.localIP()));

}


void loop()
{


}