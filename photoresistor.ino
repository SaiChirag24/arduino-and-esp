void setup()
{
Serial.begin(115200);

}


void loop()
{

    Serial.println(analogRead(15));
    delay(1000);

}