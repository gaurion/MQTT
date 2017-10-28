/*
   This is a MQTT Protocol based code that has been implemented to control
   Home Automation using levels to segregate rooms, sensors and actuators.
   This protocol helps to handle independent rooms using 'Topic Level Seperators'
   The broker has been set up using 'Mosquitto' and the clients are NodeMCU 1.0 which are controlling each room
   Code By - Gauravjit Borah
*/


//MQTT Topics//
//Publishing from Device
const char* debug = "myhome/room1/outTopic";
const char* sens1 = "myhome/room1/out/1"; //Sensor1
const char* sens2 = "myhome/room1/out/2"; //Sensor2
//Subscribing from Broker
const char* subTopic = "myhome/room1/in/#";

//Input Pins to read Commands
#define led1  16
#define led2  13
#define led3  5

//Output Pins to send Sensor Readings
#define sensor1 analogRead(A0)
#define sensor2 analogRead(10)

//Network Details
const int port = 1885;

//Libraries
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
const char* ssid = "Self Service";      //The Wifi SSID
const char* password = "Srm$8749";      //Wifi Password - Leave blank if open
const char* mqtt_server = "10.190.9.54";  //IP Address of the MQTT Broker


//Device Nameing in the network
WiFiClient espClient1;
PubSubClient client(espClient1);
const char* clientName = "ESP8266Client1";

//Message Buffers
long lastMsg = 0;
char msg[50];

//Functions Declared for Scope Resolution
void setup_devices();
void subscribeTopic();
void setup_wifi();
void reconnect();
void callback(char* topic, byte* payload, unsigned int length);
void debug_callback(char* topic, byte* payload, unsigned int length);
void debug_publish();
