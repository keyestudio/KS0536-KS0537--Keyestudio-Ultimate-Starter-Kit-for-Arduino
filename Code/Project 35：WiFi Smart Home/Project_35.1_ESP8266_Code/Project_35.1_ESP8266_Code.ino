//**********************************************************************************
/*
Keyestudio 2021 starter learning kit
Project 35.1
ESP8266_Code
http//www.keyestudio.com 
*/
// generated by KidsBlock
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>

#ifndef STASSID
#define STASSID "ChinaNet-2.4G-0DF0"  // the name of user's wifi
#define STAPSK  "ChinaNet@233"        //the password of user's wifi
#endif
const char* ssid = STASSID;
const char* password = STAPSK;
WiFiServer server(80);
String unoData = "";
int ip_flag = 0;
int ultra_state = 1;
String ip_str;


void setup() {
  Serial.begin(9600); 
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("IP ADDRESS: ");
  Serial.println(WiFi.localIP());
  if (!MDNS.begin("esp8266")) {
    //Serial.println("Error setting up MDNS responder!");
    while (1) {
      delay(1000);
    }
  }
 // Serial.println("mDNS responder started");
  server.begin();
  //Serial.println("TCP server started");
  MDNS.addService("http", "tcp", 80);
  ip_flag = 1;
  

}

void loop() {
  if(ip_flag == 1)
  {
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
    //Serial.print('#');
    delay(100);
  }
    MDNS.update();
    WiFiClient client = server.available();
    if (!client) {
      return;
    }
    //Serial.println("");
    while (client.connected() && !client.available()) {
      delay(1);
    }
    String req = client.readStringUntil('\r');
    int addr_start = req.indexOf(' ');
    int addr_end = req.indexOf(' ', addr_start + 1);
    if (addr_start == -1 || addr_end == -1) {
      //Serial.print("Invalid request: ");
      //Serial.println(req);
      return;
    }
    req = req.substring(addr_start + 1, addr_end);
    client.flush();
    String s;
    if (req == "/") {
      IPAddress ip = WiFi.localIP();
      String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
      s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>Hello from ESP8266 at ";
      s += ipStr;
      s += "</html>\r\n\r\n";
      //Serial.println("Sending 200");
      Serial.println(WiFi.localIP());
      Serial.write('*');
      client.println(WiFi.localIP());
      ip_flag = 0;
    }
    else if(req == "/btn/0")
    {
      Serial.write('a');
      client.println("turn on the relay");
    }
    else if(req == "/btn/1")
    {
      Serial.write('b');
      client.println("turn off the relay");
    }
    else if(req == "/btn/2")
    {
      Serial.write('c');
      client.println("Bring the steering gear over 180 degrees");
    }
    else if(req == "/btn/3")
    {
      Serial.write('d');
      client.println("Bring the steering gear over 0 degrees");
    }
    else if(req == "/btn/4")
    {
      Serial.write('e');
      client.println("esp8266 already turn on the fans");
    }
    else if(req == "/btn/5")
    {
      Serial.write('f');
      client.println("esp8266 already turn off the fans");
    }
    else if(req == "/btn/6")
    {
      Serial.write('g');
      while(Serial.available() > 0)
      {
        unoData = Serial.readStringUntil('#');
        client.println(unoData);
      }
    }
    else if(req == "/btn/7")
    {
      Serial.write('h');
      client.println("turn off the ultrasonic");
    }
    else if(req == "/btn/8")
    {
      Serial.write('i');
      while(Serial.available() > 0)
      {
        unoData = Serial.readStringUntil('#');
        client.println(unoData);
        //client.flush();
      }
    }
    else if(req == "/btn/9")
    {
      Serial.write('j');
      client.println("turn off the temperature");
    }
    else if(req == "/btn/10")
    {
      Serial.write('k');
      while(Serial.available() > 0)
      {
        unoData = Serial.readStringUntil('#');
        client.println(unoData);
        //client.flush();
      }
    }
    else if(req == "/btn/11")
    {
      Serial.write('l');
      client.println("turn off the humidity");
    }
    else if(req == "/btn/12")
    {
      Serial.write('m');
      client.println(F("m"));
    }
    else if(req == "/btn/13")
    {
      Serial.write('n');
      client.println(F("n"));
    }
    else if(req == "/btn/14")
    {
      Serial.write('o');
      client.println(F("o"));
    }
    else if(req == "/btn/15")
    {
      Serial.write('p');
      client.println(F("p"));
    }
    else if(req == "/btn/16")
    {
      Serial.write('q');
      client.println(F("q"));
    }
    else if(req == "/btn/17")
    {
      Serial.write('r');
      client.println(F("r"));
    }
    else if(req == "/btn/18")
    {
      Serial.write('s');
      client.println(F("s"));
    }
    else if(req == "/btn/19")
    {
      Serial.write('t');
      client.println(F("t"));
    }
    else if(req == "/btn/20")
    {
      Serial.write('u');
      client.println(F("u"));
    }
    else if(req == "/btn/21")
    {
      Serial.write('v');
      client.println(F("v"));
    }
    else if(req == "/btn/22")
    {
      Serial.write('w');
      client.println(F("w"));
    }
    else if(req == "/btn/23")
    {
      Serial.write('x');
      client.println(F("x"));
    }
    else {
      //s = "HTTP/1.1 404 Not Found\r\n\r\n";
      //Serial.println("Sending 404");
    }

    client.print(F("IP : "));
    client.println(WiFi.localIP());
}
//**********************************************************************************  
