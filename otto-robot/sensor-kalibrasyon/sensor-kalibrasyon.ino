#define echoPin 9 // Mesafe sensörü echo pini
#define trigPin 8 // Mesafe sensörü trig pini

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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

  delay(1000); // 1 saniye bekle
}
