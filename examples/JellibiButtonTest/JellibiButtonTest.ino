#import <JellibiButton.h> 

JellibiButton _buttonUP;
JellibiButton _buttonDown;
JellibiButton _buttonRight;
JellibiButton _buttonLeft;

void setup()
{
    Serial.begin(115200);
    _buttonUP.Init(A0, true);
    _buttonDown.Init(A1, true);
    _buttonRight.Init(2);
    _buttonLeft.Init(4);
}
void loop()
{
    if (_buttonUP.Check()) {
      Serial.print("UP\n");
    }
    if (_buttonDown.Check()) {
      serial.Print("Down\n");
    }
    if (_buttonRight.Check()) {
        Serial.print("Right\n");
    }
}
