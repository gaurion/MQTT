
//To check all the topics subscribed by the device
void debug_callback(char* topic, byte* payload, unsigned int length)
{
  //Display Arrival of Message
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

//To see whether the sensors are givinig valid data
void debug_publish()
{
  Serial.print("Sensor 1: ");
  Serial.print(sensor1);
  Serial.print(" Sensor 2: ");
  Serial.println(sensor2);
}

