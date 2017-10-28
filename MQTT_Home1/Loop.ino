
//Loop to constantly publish messgages
void loop() {
  if (!client.connected())
  {
    reconnect();
  }
  client.loop();
  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;

    //Send sensor 1 Readings
      snprintf (msg, 75, "temp = #%ld", sensor1);
      client.publish(sens1, msg);

    //Send Sensor 2 Readings
      snprintf (msg, 75, "temp = #%ld", sensor2);
      client.publish(sens2, msg);
  }
  //debug_publish();
}
