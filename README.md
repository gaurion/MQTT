# MQTT
Implementing IOT using MQTT

#MQTT_Home1
Used NodeMCU 1.0 (Esp 8266) as a client to connect it to MQTT broker.
Each client has its own Topic Level Separator enabling unique identification to each device.

Segregation is done on the following basis:
Topic => myhome/<ROOM>/<Sensor/Command>/<Pin>
  
  This way each Input operation for a device is separated from the output it generates.
