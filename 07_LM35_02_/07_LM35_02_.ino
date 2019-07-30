const int analogIn = 36;
 
int RawValue= 0;
double Voltage = 0;
double tempC = 0;
double tempF = 0;
 
void setup(){
Serial.begin(115200);
}
 
void loop(){
  RawValue = analogRead(analogIn);
  Voltage = (RawValue / 1023.0) * 3300; // 5000 to get millivots.
//  Voltage = (RawValue * (3300/1023));
  tempC = Voltage * 0.1;
//  tempF = (tempC * 1.8) + 32; // conver to F
  Serial.print("Raw Value = " ); // shows pre-scaled value
  Serial.print(RawValue);
  Serial.print("\n");
  Serial.print("milli volts = "); // shows the voltage measured
  Serial.print(Voltage,0); //
  Serial.print("\n");
  Serial.print("Temperature in C = ");
  Serial.print(tempC,1);
  Serial.print("\n");
//  Serial.print("\t Temperature in F = ");
//  Serial.println(tempF,1);
  delay(500);
}
