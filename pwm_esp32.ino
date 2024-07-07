int freq=5000;
int ledchannel1=0;
int resolution =8;
int ledchannel2=1;
void setup() {
  ledcSetup(ledchannel1,freq,resolution);
  ledcSetup(ledchannel2,freq,resolution);
  ledcAttachPin(2,ledchannel1);
  ledcAttachPin(4,ledchannel2);


}

void loop() {
  for(int i=0;i<=255;i++){
    ledcWrite(ledchannel1,i);
    delay(5);
  }
  for(int i=255;i>=0;i--){
    ledcWrite(ledchannel1,i);
    delay(5);}
    
  for(int j=0;j<=255;j++){
    ledcWrite(ledchannel2,j);
    delay(5);
  }
  for(int j=255;j>=0;j--){
    ledcWrite(ledchannel2,j);
    delay(5);}

  }


