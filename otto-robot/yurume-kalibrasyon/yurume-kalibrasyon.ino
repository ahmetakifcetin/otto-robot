#include <Otto.h>
#include <EEPROM.h>
#include <Oscillator.h>

#define echo 9        // Ultrasonik mesafe sensörü echo pini
#define trig 8        // Ultrasonik mesafe sensörü trig pini
Otto Otto;

int trims[] = {140, 100, 122, 30}; //Servo motor kalibrasyon ayarları (Değiştirirseniz robot düzgün çalışmaz)
/*
TRIMS (DUZEN)
{sağ bacak[140],sol bacak[100],sağ ayak[122],sol ayak[30]}
bu değerleri kalibrasyonu 180 derece olacak şekilde giriniz!
*/
int servoPins[] = {2, 3, 4, 5};

void setup() {
  Otto.init(servoPins[0], servoPins[1], servoPins[2], servoPins[3], true, 13);
  Serial.begin(9600);
  Otto.home();
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Otto.sing(S_connection);
}

void loop() {
  // Engelden kaçınma kontrolü
  long duration, distance;
  digitalWrite(trig, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;

  if (distance < 20) { // Engelden yakın bir mesafede ise
    Otto.playGesture(OttoAngry);
    Otto.home();
    delay(1000); // Kısa bir süre bekleyin
  } else { // Engelden uzak bir mesafede ise
    Otto.walk(2, 1000, 1); // Yürüme işlemi
    Otto.playGesture(OttoHappy);
    Otto.moonwalker(2, 1000, 1, 2); 
    Otto.playGesture(OttoSuperHappy);
 }
}
