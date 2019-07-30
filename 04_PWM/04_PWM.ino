const int ledPin = 2;

const int freq = 2000;
const int ledChannel = 0;
const int resolution = 8;

void setup() {
  // put your setup code here, to run once:
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(ledPin, ledChannel);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }

  for(int dutyCycle = 255; dutyCycle <= 0; dutyCycle++) {
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }
}
