#include <Wire.h>
#include <Mouse.h>

const int INPUT_RANGE = 250;
const int OUTPUT_RANGE = 12;
const int responseDelay = 5;
const int OUTPUT_THRESHOLD = OUTPUT_RANGE / 4;
const int OUTPUT_CENTER = OUTPUT_RANGE / 2;

void setup()
{
    Serial.begin(9600);
    Wire.begin();
    Mouse.begin();
}
 
void loop()
{
    Wire.requestFrom(0x52, 2);
    int xIn = Wire.read();
    int yIn = Wire.read();

    int xOut = transformInput(xIn);
    int yOut = transformInput(yIn);

    // don't be confused by the mapping of x and y, this is due to the positioning of the joystick on the table
    Mouse.move(-yOut, -xOut, 0);
}

int transformInput(int input) {
  int output = map(input, 0, INPUT_RANGE, 0, OUTPUT_RANGE);

  int result = output - OUTPUT_CENTER;
  if (abs(result) < OUTPUT_THRESHOLD) {
    result = 0;
  }

  return result;
}
