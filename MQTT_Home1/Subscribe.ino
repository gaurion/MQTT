
//Function to list all the topics that the Device needs to subscribe to
void subscribeTopic()
{
  client.subscribe(subTopic);
}


//Function to read the messgaes from subscribed Topics
void callback(char* topic, byte* payload, unsigned int length) {

  debug_callback(topic, payload, length);

  //Cases for Controlling Devices
  if (strcmp(topic, "myhome/room1/in/light1") == 0)           // Light 1 Control
  {
    //Serial.println("Light1");
    if ((char)payload[0] == '1') {
      digitalWrite(led1, LOW);
      delay(100);
    }
    else {
      digitalWrite(led1, HIGH);
    }
  }
  if (strcmp(topic, "myhome/room1/in/light2") == 0)           //  Light 2 control
  {
    //Serial.println("Light2");
    if ((char)payload[0] == '1') {
      digitalWrite(led2, HIGH);
      delay(100);
    }
    else {
      digitalWrite(led2, LOW);
    }
  }
  if (strcmp(topic, "myhome/room1/in/light3") == 0)            //  Light 3 control
  {
    //Serial.println("Light3");
    if ((char)payload[0] == '1') {
      digitalWrite(led3, HIGH);
      delay(100);
    }
    else {
      digitalWrite(led3, LOW);
    }
  }
  /*
     LED3 is used instead of a fan for the purpose of testing
     It would work fine with a fan as well!
  */
  if (strcmp(topic, "myhome/room1/in/fan1") == 0)                //  Fan 1 control
  {
    Serial.println("Fan1");
    Serial.println((((int)((char)payload[0])) - 48));
    if ((char)payload[0] >= '0' && (char)payload[0] <= '5') {
      Serial.print("Fan 1 Speed = ");
      Serial.println((int)((char)payload[0]));
      analogWrite(led3, 51 * (((int)((char)payload[0])) - 48));
      delay(100);
    }
    else {
      digitalWrite(led3, LOW);
    }
  }
  else
  {
    ;
  }


}
