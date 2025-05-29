#include <MQTTController.h>

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

void StartMQQTConnection();
void StartWifiConnection();
void ConnectMQQTBroker();
void SubscribeTopics();

MqttController::MqttController() {
}

void MqttController::start() {
  StartWifiConnection();
  ConnectMQQTBroker();
  SubscribeTopics();
}

void MqttController::sendMessage(char * topic, int value) {
  mqttClient.beginMessage(topic);
  mqttClient.print(value);
  mqttClient.endMessage();
}

void MqttController::sendMessage(char * topic, String value){
  mqttClient.beginMessage(topic);
  mqttClient.print(value);
  mqttClient.endMessage();
}


void MqttController::poll () {
  mqttClient.poll();
}

void StartWifiConnection() {
  WiFi.mode(WIFI_STA);
  Serial.println("Connecting to: ");
  Serial.print(WIFI_SSID);
  Serial.println();
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    // failed, retry
    Serial.print(".");
    delay(100);
  }
  
  Serial.println("Connected to Network.");
  Serial.println("");
}

void ConnectMQQTBroker() {
  if (!mqttClient.connect((char*)MQTT_SERVER_HOST, MQTT_SERVER_PORT)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while(1);
  }
  Serial.println("You're connected to the MQTT broker!");
  Serial.println();
}

void SubscribeTopics() {
  mqttClient.subscribe(MQTT_TOPIC_BATTERY);
  mqttClient.subscribe(MQTT_TOPIC_SPEED);
  mqttClient.subscribe(MQTT_TOPIC_INCLINATION);
  mqttClient.subscribe(MQTT_TOPIC_TRIPS);
  mqttClient.subscribe(MQTT_TOPIC_MOVEMENT);
  mqttClient.subscribe(MQTT_TOPIC_ACTION);
  mqttClient.subscribe(MQTT_TOPIC_PING);
}

String MqttController::messageTopic() {
  return mqttClient.messageTopic();
}

char* MqttController::getIncomingMessage(int messageSize) {
  char* message = (char*) malloc(sizeof(char) * messageSize);
  int currentChar = 0;
  char c;
  Serial.println("Reading Message: ");

  while (currentChar <= messageSize) {
    c = (char) mqttClient.read();
    if(c == ';')
      break;
    else {
      message[currentChar] = c;
      currentChar ++;
    }
  }
  message[messageSize - 1] = 0;

  return message;
}

void MqttController::setCallBack(void (*callBack)(int)) {
  mqttClient.onMessage(callBack);
}



