#include <SPI.h>
#include <LoRa.h>

#define ss 10 //5
#define rst 14
#define dio0 2

int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial);
  Serial.println("Lora Sender");

  LoRa.setPins(ss, rst, dio0);
  while (!LoRa.begin(433E6)) //433 diganti dengan 915 
  {
    Serial.println(".");
    delay(500);
  }
  LoRa.setSyncWord(0xF5);
  Serial.println("LoRa Initializing OK!");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Sending packet: ");
  Serial.println(counter);

  LoRa.beginPacket();
  LoRa.print("Haloo Senin !!");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;
  delay(10000);

}
