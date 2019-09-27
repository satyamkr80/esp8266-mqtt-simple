#include <ESP8266WiFi.h>
#include<PubSubClient.h>

const char *ssid = "WiFi_SSID"; // cannot be longer than 32 characters!
const char *pass = "WiFi_PSWD";
const char *mqtt_server = "Mqtt_broker_address";
const int mqtt_port = 1883;
const char *mqttuser = "";
const char *mqttpass = "";

void callback(String topic,byte* payload,unsigned int length1);
void reconnect();

WiFiClient espclient;
PubSubClient client(mqtt_server,1883,callback,espclient);




void setup() {
Serial.begin(115200);
WiFi.begin(ssid, pass);
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
Serial.println("Connecting to WiFi..");
}
Serial.println("Connected to the WiFi network");
client.setServer(mqtt_server, mqtt_port);
client.setCallback(callback);
  
}



void loop() 
{
if(!client.connected()){
reconnect();
}
client.loop();

}





void callback(String topic,byte* payload,unsigned int length1){ 
Serial.print("message arrived[");
Serial.print(topic);
Serial.println("]");
String msg;
for(int i=0;i<length1;i++){
Serial.print((char)payload[i]);
msg += (char)payload[i]; 
//Serial.println(msgg);
}
if (msg=="abc")
{
 // condition as per message
}
else{
  // condition as per message
}

}

void reconnect(){
while (!client.connected()) {
Serial.println("Connecting to MQTT…");
if (client.connect("ESP8266Clientghjgjhgj", mqttuser, mqttpass)) {
Serial.println("connected"); 
client.subscribe("lockstatus");
} else {
Serial.print("failed with state ");
Serial.print(client.state());
delay(2000);
}
}
}
