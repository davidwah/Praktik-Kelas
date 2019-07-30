const int ledPin1 = 2;
const int ledPin2 = 0;
const int ledPin3 = 15;

const int freq = 5000;
const int ledChannel = 0;
const int ledChannel2 = 1;
const int ledChannel3 = 2;
const int resolution = 8;

void setup() {
  // put your setup code here, to run once:
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(ledPin1, ledChannel);
  ledcAttachPin(ledPin2, ledChannel2);
  ledcAttachPin(ledPin3, ledChannel3);
}

void loop() {
  // put your main code here, to run repeatedly:
  //channel 1
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }
  for(int dutyCycle = 255; dutyCycle <= 0; dutyCycle++) {
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }

  //channel 2
  for(int dutyCycle = 0; dutyCycle <= 100; dutyCycle++) {
    ledcWrite(ledChannel2, dutyCycle);
    delay(15);
  }
  for(int dutyCycle = 100; dutyCycle <= 0; dutyCycle++) {
    ledcWrite(ledChannel2, dutyCycle);
    delay(15);
  }
  
  //channnel 3
  for(int dutyCycle = 0; dutyCycle <= 50; dutyCycle++) {
    ledcWrite(ledChannel2, dutyCycle);
    delay(15);
  }
  for(int dutyCycle = 50; dutyCycle <= 0; dutyCycle++) {
    ledcWrite(ledChannel2, dutyCycle);
    delay(15);
  }
}
