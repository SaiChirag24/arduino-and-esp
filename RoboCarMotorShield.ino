//using Motor Shield
#include <WiFi.h>

String  ClientRequest;
WiFiServer server(80);

WiFiClient client;

String myresultat;

String ReadIncomingRequest(){
while(client.available()) {
ClientRequest = (client.readStringUntil('\r'));
 if ((ClientRequest.indexOf("HTTP/1.1")>0)&&(ClientRequest.indexOf("/favicon.ico")<0)){
myresultat = ClientRequest;
}
}
return myresultat;
}

void stop() {
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
}

void forward() {
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
}

void back() {
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
}

void right() {
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
}

void left() {
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
}

void setup()
{
ClientRequest = "";

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
  server.begin();

pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
}


void loop()
{

    client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    ClientRequest = (ReadIncomingRequest());
    ClientRequest.remove(0, 5);
    ClientRequest.remove(ClientRequest.length()-9,9);
    if (ClientRequest == "stop") {
      stop();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("STOP");
      client.println("</html>");
      delay(1);

    }
    if (ClientRequest == "forward") {
      forward();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("FORWARD");
      client.println("</html>");
      delay(1);

    }
    if (ClientRequest == "back") {
      back();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("BACK");
      client.println("</html>");
      delay(1);

    }
    if (ClientRequest == "right") {
      right();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("RIGHT");
      client.println("</html>");
      delay(1);

    }
    if (ClientRequest == "left") {
      left();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("LEFT");
      client.println("</html>");
      delay(1);

    }
    client.flush();

}
