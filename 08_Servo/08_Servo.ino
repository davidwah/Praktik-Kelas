//#include <UnoWiFiDevEd.h>

#include <ESP32Servo.h>

//#include <Servo.h>

static const int servoPin = 13;
static const int potPin = 36;

Servo myservo;
//int pos = 0;  

void setup() {
  Serial.begin(115200);
  myservo.attach(servoPin);  // attaches the servo on pin 13 to the servo object
  
}

void loop() {
  int servoPosition = map(analogRead(potPin), 0, 4096, 0, 180);
  myservo.write(servoPosition);
  Serial.println(servoPosition);
  delay(20);

}
