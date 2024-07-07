
void setup()
{
Serial.begin(115200);
pinMode(4, OUTPUT);
pinMode(15, OUTPUT);
pinMode(2, OUTPUT);

}


void loop()
{

    digitalWrite(4,HIGH);
    digitalWrite(15,LOW);
    digitalWrite(2,LOW);
    delay(3000);
    digitalWrite(4,LOW);
    digitalWrite(15,HIGH);
    digitalWrite(2,LOW);
    delay(3000);
    digitalWrite(4,LOW);
    digitalWrite(15,LOW);
    digitalWrite(2,HIGH);
    delay(3000);

}
