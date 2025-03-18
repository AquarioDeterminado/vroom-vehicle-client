#define S0PIN GPIO32
#define S1PIN GPIO33
#define S2PIN GPIO32
#define S3PIN GPIO25
#define OUTPIN GPIO26
#define LEDPIN GPIO27







void setup() {
  // put your setup code here, to run once:
  Serialbegin(9600);

  //Set UP Wifi connection
}

void loop() {
  // put your main code here, to run repeatedly:
  String instruction = Serial.readStringUntil('\n');
  instruction.trim();

  char* pointer = (char*) instruction.c_str();
  
  char* inst = strtok(pointer, " ");

  if (strcmp(inst, "slay") == 0)
    Serial.write("boots");
}
