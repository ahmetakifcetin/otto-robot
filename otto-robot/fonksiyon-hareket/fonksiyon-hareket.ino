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
  hareket1();
}

void hareket1() {
  // İleri yürüme hareketi
  for (int i = 0; i < 4; i++) {
    Otto.walk(1, 500, 1); // 1 adım, 500 ms süre, ileri yönde
    Otto.sing(S_buttonPushed); // Ses çal
  }
  Otto.walk(2, 1000, 1); // 2 adım, 1000 ms süre, ileri yönde
  
  // Sağa dönme hareketi
  Otto.turn(1, 1000, 1); // 1 adım, 1000 ms süre, sağa dönme
  
  // Geri yürüme hareketi
  Otto.walk(2, 1000, -1); // 2 adım, 1000 ms süre, geriye yönde
  
  // Sola dönme hareketi
  Otto.turn(1, 1000, -1); // 1 adım, 1000 ms süre, sola dönme
}