extern "C"
{uint8_t temperature_sens_read();}
uint8_t temperature_sens_read();
void setup() {
  Serial.begin(115200);// put your setup code here, to run once:

}

void loop() {
  Serial.print("temperature in degrees");
  Serial.print((temperature_sens_read()-32)/1.8);
  Serial.println("'C");
  delay(5000);// put your main code here, to run repeatedly:

}
