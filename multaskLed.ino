int i;
void Task1code( void * pvParameters ){
  for (i = 1; i <= 5; i++) {
    digitalWrite(2,HIGH);
    delay(3000);
    digitalWrite(2,LOW);
    delay(3000);
  }
  vTaskDelete(NULL);
}

TaskHandle_t firsttask;
TaskHandle_t secondTask;
int j;
void Task2code( void * pvParameters ){
  for (j = 1; j <= 5; j++) {
    digitalWrite(4,HIGH);
    delay(3000);
    digitalWrite(4,LOW);
    delay(3000);
  }
  vTaskDelete(NULL);
}

void setup()
{
pinMode(2, OUTPUT);
Serial.begin(9600);

  delay(3000);
  Serial.println("start");
  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
     Task1code,    //Task function.
     "firsttask", //name of task
     10000, //Stack size of task
     NULL, //parameter of the task
     1, //priority of the task
     &firsttask, //Task handle to keep track of created task
     0); //pin task to core 0
  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
     Task2code,    //Task function.
     "secondTask", //name of task
     10000, //Stack size of task
     NULL, //parameter of the task
     1, //priority of the task
     &secondTask, //Task handle to keep track of created task
     1); //pin task to core 1

pinMode(4, OUTPUT);
}


void loop()
{


}
