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
   Otto.walk(2, 1000, 1); // 2 adım, 1000 ms, ileri yönde
   
   delay(3000); // Hareket arasında 3 saniye bekleme

   // Duyguları ifade eden jestlerin oynatılması
   Otto.playGesture(OttoHappy);    // Mutlu
   delay(3000);

   Otto.playGesture(OttoSad);      // Üzgün
   delay(3000);

   Otto.playGesture(OttoAngry);    // Kızgın
   delay(3000);

   Otto.playGesture(OttoConfused); // Şaşkın
   delay(3000);
}
