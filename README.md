# esp8266-mqtt-simple

<b> For last will check , modify this line as </b>

if (client.connect("ESP8266Clientghjgjhgj", mqttuser, mqttpass, "last", 0, 0, "offline" )) {

<b> And add a new publish command on same topic  </b>

client.publish("last","online");
