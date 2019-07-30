const int ledPin1 = 2;
//const int Pot = 34;

int potValue = 0;

const int freq = 5000;
const int ledChannel = 0;
const int resolution = 12;

void setup() {
  Serial.begin(115200);
  delay(1000);
  // put your setup code here, to run once:
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(ledPin1, ledChannel);
}

void loop() {

  //channel 1
  uint16_t dutycycle =  analogRead(A0);
  ledcWrite(ledChannel, dutycycle);
  Serial.println(dutycycle);
  delay(15);
  
}
