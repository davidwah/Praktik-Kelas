const int analogPin = 36;  //initializes/defines the output pin of the LM35 temperature sensor
                    //this sets the ground pin to LOW and the input voltage pin to high
int value;
void setup()
{
  Serial.begin(115200);
}

void loop() //main loop
{
//  value = analogRead(analogPin);
////  float mv = (value / 1024)*3300;/
//  float temp = ((value * (3300/1023)));
////  float celc = temp / 10;/
////  float farh = (celc*9)/5 + /32;
//
//  Serial.print("Temperature =  ");
//  Serial.print(temp);
//  Serial.print("*C");
//  Serial.println();
//  delay(500);


  
  int analogValue = analogRead(analogPin);
  float millivolts = (analogValue/1024.0) * 3300; //3300 is the voltage provided by NodeMCU
  float celsius = millivolts/10;
  Serial.print("in DegreeC=  ");
  Serial.println(celsius);
  delay(500);
//
//  float fahrenheit = ((celsius * 9)/5 + 32);
//  Serial.print("in Farenheit=   ");
//  Serial.println(fahrenheit);
//  delay(1000);
}
