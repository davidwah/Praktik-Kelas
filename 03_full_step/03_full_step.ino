int buttonState = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(15, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(17, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(17);
 if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(15,HIGH);digitalWrite(2,LOW);digitalWrite(0,LOW);digitalWrite(4,LOW); delay(100);
    digitalWrite(15,LOW);digitalWrite(2,HIGH);digitalWrite(0,LOW);digitalWrite(4,LOW); delay(100);
    digitalWrite(15,LOW);digitalWrite(2,LOW);digitalWrite(0,HIGH);digitalWrite(4,LOW); delay(100);
    digitalWrite(15,LOW);digitalWrite(2,LOW);digitalWrite(0,LOW);digitalWrite(4,HIGH); delay(100);

  } else {
    // turn LED off:
    digitalWrite(15,LOW);digitalWrite(2,LOW);digitalWrite(0,LOW);digitalWrite(4,HIGH); delay(100);
    digitalWrite(15,LOW);digitalWrite(2,LOW);digitalWrite(0,HIGH);digitalWrite(4,LOW); delay(100);
    digitalWrite(15,LOW);digitalWrite(2,HIGH);digitalWrite(0,LOW);digitalWrite(4,LOW); delay(100);
    digitalWrite(15,HIGH);digitalWrite(2,LOW);digitalWrite(0,LOW);digitalWrite(4,LOW); delay(100);

  }
}
