#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <SocketIoClient.h>
const char *ssid = "*******"; //Enter your WIFI ssid
const char *password = "******"; //Enter your WIFI password
SocketIoClient Socket;
#define USE_SERIAL Serial


void setup() {
  // put your setup code here, to run once:
 pinMode(LED_BUILTIN, OUTPUT);
 delay(3000);
 Serial.begin(9600);
 Serial.println();
 Serial.print("Configuring access point...");
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected");
 Serial.println("IP address: ");
 Serial.println(WiFi.localIP());
 //menggunakan jaringan yang sama
 //Socket.begin("192.168.100.127",5000);
 
 //menggunakan jaringan yang sudah di tunnel
 Socket.begin("5356b04ef3ff.ngrok.io");
 
 
 //event dari backend
 Socket.on("triger", event);
 
}

void event(const char * payload, size_t length) {
  Serial.println(payload);
}

void loop() {
  // put your main code here, to run repeatedly:
 Socket.loop();
}
