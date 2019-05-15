#include <JellibiButton.h> 

JellibiButton _buttonUP;
JellibiButton _buttonDown;
JellibiButton _buttonRight;
JellibiButton _buttonLeft;

void setup()
{
    Serial.begin(115200);
    _buttonUP.Init(A0, true);
    _buttonDown.Init(A1, true);
    _buttonRight.Init(4);
    _buttonLeft.Init(2);
}
void loop()
{
    if (_buttonUP.Check()) {
      Serial.print("UP\n");
    }
    if (_buttonDown.Check()) {
      Serial.print("Down\n");
    }
    if (_buttonRight.Check()) {
      Serial.print("Right\n");
    }
    if (_buttonLeft.Check()) {
      Serial.print("Left\n");
    }
}
