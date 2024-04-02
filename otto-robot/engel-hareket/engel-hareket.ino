#include <Otto.h>
#include <Oscillator.h>

#define LeftLeg 2       // Sol bacak pin
#define RightLeg 3      // Sağ bacak pin
#define LeftFoot 4      // Sol ayak pin
#define RightFoot 5     // Sağ ayak pin
#define echoPin 9       // Mesafe sensörü echo pini
#define trigPin 8       // Mesafe sensörü trig pini
#define BuzzerPin 13    // Buzzer pin
#define DistanceThreshold 20  // Ses çıkarmak için belirlenecek mesafe eşiği (ayarlanabilir)

Otto Otto; 

void setup() {
   Serial.begin(9600);
   Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, false, BuzzerPin);    
   Otto.home();

   pinMode(trigPin, OUTPUT);  // Trig pini çıkış olarak ayarla
   pinMode(echoPin, INPUT);   // Echo pini giriş olarak ayarla
}

void loop() {
   // Mesafe ölçümü yap
   long duration, distance;
   digitalWrite(trigPin, LOW);  
   delayMicroseconds(2); 
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10); 
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   distance = (duration / 2) / 29.1;  // Mesafe hesaplama formülü

   // Mesafeyi seri monitöre yazdır
   Serial.print("Mesafe: ");
   Serial.print(distance);
   Serial.println(" cm");

   // Mesafe eşik değerinden daha kısa bir mesafe algılandığında
   if (distance < DistanceThreshold) {
       // Otto kızgın ses çıkarsın
       Otto.playGesture(OttoAngry);
       delay(500);  // Ses çalma süresi
   } 
}
