#include "Joystick.h"

byte buttonPins[3] = {9, 14, 16};


Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_MULTI_AXIS,
  3, 0, 2,              // Button Count, Hat Switch Count, Throttle Count
  false, false, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false,                  // rudder 
  false, false, false);  // No accelerator, brake, or steering

  int thrust_left = 0;
  int thrust_right = 0;

  int button0 = 0;
  int button1 = 0;
  int button2 = 0;

  
void setup() {
  // put your setup code here, to run once:
Joystick.begin();
pinMode(A1, INPUT_PULLUP);
pinMode(A2, INPUT_PULLUP);
pinMode(9, INPUT_PULLUP);
pinMode(14, INPUT_PULLUP);
pinMode(16, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
thrust_left = analogRead(A1);
Joystick.setThrottle(0, thrust_left);
//Serial.println(thrust_left);


thrust_right = analogRead(A2);
Joystick.setThrottle(1, thrust_right);
//Serial.println(thrust_right);

readButtonStates();

}


void readButtonStates()
{
    for (int i = 0; i < 3; i++)
    {
        int state = digitalRead(buttonPins[i]);
        Joystick.setButton(i, !state);
    }
}
