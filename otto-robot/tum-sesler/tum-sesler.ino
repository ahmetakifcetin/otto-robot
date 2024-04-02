#include <Otto.h>
#include <Oscillator.h>
#define LeftLeg 2    // Sol bacak pin
#define RightLeg 3   // Sağ bacak pin
#define LeftFoot 4   // Sol ayak pin
#define RightFoot 5  // Sağ ayak pin
#define echo 9 //echo
#define trig 8 //trig
#define Buzzer 13    // Buzzer pin

Otto Otto;

void setup() {
  init(LeftLeg, RightLeg, LeftFoot, RightFoot, false, Buzzer);
  Otto.home();
}

void loop() {
  Otto.sing(S_connection);
  delay(1000);
  Otto.sing(S_disconnection);
  delay(1000);
  Otto.sing(S_buttonPushed);
  delay(1000);
  Otto.sing(S_mode1);
  delay(1000);
  Otto.sing(S_mode2);
  delay(1000);
  Otto.sing(S_mode3);
  delay(1000);
  Otto.sing(S_surprise);
  delay(1000);
  Otto.sing(S_OhOoh);
  delay(1000);
  Otto.sing(S_OhOoh2);
  delay(1000);
  Otto.sing(S_cuddly);
  delay(1000);
  Otto.sing(S_sleeping);
  delay(1000);
  Otto.sing(S_happy);
  delay(1000);
  Otto.sing(S_superHappy);
  delay(1000);
  Otto.sing(S_happy_short);
  delay(1000);
  Otto.sing(S_sad);
  delay(1000);
  Otto.sing(S_confused);
  delay(1000);
  Otto.sing(S_fart1);
  delay(1000);
  Otto.sing(S_fart2);
  delay(1000);
  Otto.sing(S_fart3);
  delay(1000);
}