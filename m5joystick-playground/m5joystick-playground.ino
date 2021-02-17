#include <Wire.h>

void setup()
{
    Serial.begin(9600);
    Serial.print("Wire begin \n");
    Wire.begin();
    delay(200);
}
 
void loop()
{
    Serial.print("Hello\n");
    int sensorValue1, sensorValue2;
    Wire.requestFrom(0x52, 2);
    while (Wire.available())
    {
      sensorValue1 = Wire.read();
      sensorValue2 = Wire.read();
 
      Serial.print("The X and Y coordinate is:");
      Serial.print(sensorValue1, DEC);
      Serial.print(",");
      Serial.println(sensorValue2, DEC);
      Serial.println(" ");
      delay(200);
     
    }
}
