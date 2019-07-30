#include <SPI.h>
#include <LoRa.h>

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

#define ss 5 //5
#define rst 14
#define dio0 2

const char* ssid = "POSKO INTERNET";
const char* password = "yuhusaja";

WebServer server(80);

String LoRaData;

int counter = 0;


//void handle_OnConnect() {
//  server.send(200, "text/html", SendHTML(loradata));
//}

//void handle_led1on() {
//  led1status = HIGH;
//  server.send(200, "text/html", SendHTML(led1status));
//  Serial.println("LED dinyalakan.");
//}

//void handle_led1off() {
////  led1status = LOW;
//  server.send(200, "text/html", SendHTML(led1status));
//  Serial.println("LED dimatikan.");
//}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial);
  delay(500);
  Serial.println("Lora Receiver");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }
////  server.on("/", handle_OnConnect);
//  server.on("/led1on", handle_led1on);
//  server.on("/led1off", handle_led1off);
//  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
  

  LoRa.setPins(ss, rst, dio0);
  while (!LoRa.begin(915E6)) //433 diganti dengan 915 
  {
    Serial.println(".");
    delay(500);
  }
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");
}

void loop() {
//  LoRaData = LoRa.readString();
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Recived packet: ");

    //Read packet data
    while (LoRa.available()) {
      String LoRaData = LoRa.readString();
      Serial.print(LoRaData);    
    }
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}

String SendHTML(uint8_t loradata) {
  String teks = "<!DOCTYPE html> <html>\n";
  teks += "<head><meta http-equiv=\"refresh\" content=\"6\"></head>";

  teks = teks + "<p> loradata = "+ LoRaData +"</p>";

  teks += "</html>";
  
  return teks;
}
