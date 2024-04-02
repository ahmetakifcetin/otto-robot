#include <Otto.h>
#include <Oscillator.h>

#define LeftLeg 2     // Sol bacak pin
#define RightLeg 3    // Sağ bacak pin
#define LeftFoot 4    // Sol ayak pin
#define RightFoot 5   // Sağ ayak pin
#define echo 9        // Ultrasonik mesafe sensörü echo pini
#define trig 8        // Ultrasonik mesafe sensörü trig pini
#define Buzzer 13     // Buzzer pin

#define DistanceThreshold 20  // Engelden kaç cm uzaklıkta durulması gerektiği (ayarlanabilir)

Otto Otto; 

void setup() {
   Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, false, Buzzer);    
   Otto.home();

   pinMode(trig, OUTPUT);  // Trig pinini çıkış olarak ayarla
   pinMode(echo, INPUT);   // Echo pinini giriş olarak ayarla
}

void loop() {
   // Engel tespiti için mesafe ölçümü yap
   long duration, distance;
   digitalWrite(trig, LOW);  
   delayMicroseconds(2); 
   digitalWrite(trig, HIGH);
   delayMicroseconds(10); 
   digitalWrite(trig, LOW);
   duration = pulseIn(echo, HIGH);
   distance = (duration / 2) / 29.1;  // Mesafe hesaplama formülü

   // Engelden belirlenen mesafenin daha yakınında mıyız kontrol et
   if (distance < DistanceThreshold) {
       // Engelden daha yakınız, kızgın ses çal
       Otto.playGesture(OttoAngry);
       delay(500);  // Ses çalma süresi
   } else {
       // Engelden yeterince uzaktayız, dans etmeye devam et
       Otto.walk(2, 1000, 1); // 2 adım, 1000 ms, ileri yönde
   }
}
