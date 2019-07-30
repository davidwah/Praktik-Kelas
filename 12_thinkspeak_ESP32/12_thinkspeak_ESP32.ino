//#ifdef __cplusplus
//extern "C" {
//#endif
//uint8_t temprature_sens_read();
//#ifdef __cplusplus
//}
//#endif
//uint8_t temprature_sens_read();
#include <WiFi.h>
#include <PubSubClient.h>


String apiKey = "W7ZAEX8K7MM41KW5";     //  Enter your Write API key from ThingSpeak
const char *ssid =  "Ashish";     // replace with your wifi ssid and password
const char *pass =  "12345678";
const char* server = "api.thingspeak.com";
WiFiClient client;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(10);
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
     Serial.print(".");
  }​​​​​​
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop() {
  // put your main code here, to run repeatedly:

  int h = 0;
  float t = 0;
  h = hallRead();
  t = ((temperature_sensor()-32)/1.8);

  String postStr = apiKey;
  postStr +="&field1=";
  postStr += String(h);
  postStr += "&field2=";
  postStr += String(t);
  postStr += "\r\n\r\n";


  client.print("POST /update HTTP/1.1\n");
  client.print("Host: api.thingspeak.com\n");
  client.print("Connection: close\n");
  client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
  client.print("Content-Type: application/x-www-form-urlencoded\n");
  client.print("Content-Length: ");
  client.print(postStr.length()); 
  client.print("\n\n");
  client.print(postStr);
  Serial.print("Hall: ");
  Serial.println(h);
  Serial.print("Temperature:");
  Serial.print(t);
  Serial.println(" C");
}
