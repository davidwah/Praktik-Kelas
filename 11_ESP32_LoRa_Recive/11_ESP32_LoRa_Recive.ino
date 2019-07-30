#include <SPI.h>
#include <LoRa.h>

#define ss 5 //5
#define rst 14
#define dio0 2

int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial);
  delay(500);
  Serial.println("Lora Receiver");
  

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
