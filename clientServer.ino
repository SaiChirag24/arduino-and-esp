#include <WiFi.h>

WiFiClient client;

String myurl = "/";
void setup()
{
Serial.begin(115200);

  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
  WiFi.begin("NR JIO-FI 2G","16nr1969");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");

  }
  Serial.println("Connected");
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP()));

}


void loop()
{

    if (client.connect("192.168.1.10", 80)) {
      myurl += "data1";
      client.print(String("GET ") + myurl + " HTTP/1.1\r\n" +
                "Host: " + "192.168.1.10" + "\r\n" +
               "Connection: close\r\n\r\n");
      myurl="/";

    }
    delay(5000);
    if (client.connect("192.168.1.10", 80)) {
      myurl += "data2";
      client.print(String("GET ") + myurl + " HTTP/1.1\r\n" +
                "Host: " + "192.168.1.10" + "\r\n" +
               "Connection: close\r\n\r\n");
      myurl="/";

    }
    delay(5000);
    if (client.connect("192.168.1.10", 80)) {
      myurl += "data3";
      client.print(String("GET ") + myurl + " HTTP/1.1\r\n" +
                "Host: " + "192.168.1.10" + "\r\n" +
               "Connection: close\r\n\r\n");
      myurl="/";

    }

}