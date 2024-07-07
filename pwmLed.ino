
int i;
void setup()
{
  ledcSetup(0,5000,8);
  ledcAttachPin(15,0);

}


void loop()
{

    for (i = 0; i <= 255; i++) {
      ledcWrite(0, i);
      delay(2000);
    }
    

}
