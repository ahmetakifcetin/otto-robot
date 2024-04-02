#include <Otto.h>
Otto Otto;
#include <EEPROM.h>

int v;
int ch;
int i;

  int positions[] = {90, 90, 90, 90};
  int8_t trims[4] = {0,0,0,0};

#define LeftLeg 2    // Sol bacak pin
#define RightLeg 3   // Sağ bacak pin
#define LeftFoot 4   // Sol ayak pin
#define RightFoot 5  // Sağ ayak pin
#define echo 9 //echo
#define trig 8 //trig
#define Buzzer 13    // Buzzer pin

void readChar(char ch) {
  switch (ch) {
  case '0'...'9':
    v = (v * 10 + ch) - 48;
    break;
   case 'a':
    trims[0] = v-90;
    setTrims();
    v = 0;
    break;
   case 'b':
    trims[1] = v-90;
    setTrims();
    v = 0;
    break;
   case 'c':
    trims[2] = v-90;
    setTrims();
    v = 0;
    break;
   case 'd':
    trims[3] = v-90;
    setTrims();
    v = 0;
    break;
   case 'w':
    for (int count=0 ; count<4 ; count++) {
      Otto.walk(1,1000,1); // FORWARD
    }
    break;
   case 's':
    for (i=0 ; i<=3 ; i=i+1) {
      EEPROM.write(i,trims[i]);
    }
    delay(500);
    Otto.sing(S_superHappy);
    Otto.crusaito(1, 1000, 25, -1);
    Otto.crusaito(1, 1000, 25, 1);
    Otto.sing(S_happy_short);
    break;
  }
}

void setTrims() {
  Otto.setTrims(trims[0],trims[1],trims[2],trims[3]);
   Otto._moveServos(10, positions);}


void setup() {
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer);
Otto.home();

  Serial.begin(9600);

/*

- Otto'yu kalibre etmek için, önce bu kodu Otto'ya yüklemeniz gerekecek. Yükleme tamamlandığında, Otto'ya bağlı olan USB bağlantısını çıkarın.

- Servo Kalibrasyonu Arayüzü

- Şimdi, Servo Kalibrasyon yazılımını ottodiy.com adresinden çalıştırmanız gerekecek. USB'nin çıkarıldığından emin olun. Windows platformunuza bağlı olarak, ilgili klasörde bulunan 32 veya 64 bit yürütülebilir dosyayı çalıştırmanız gerekecektir. Lütfen dosyayı klasöründe bırakın - program, veri dosyalarına erişimi olmadığında çalışmaz.

- Başlangıçta, arayüzün üstünde USB etiketi yanında kırmızı bir çarpı görmelisiniz. USB'yi Otto'ya takın ve programın USB bağlantısını algıladığını belirten yeşil bir onay işareti göreceksiniz (bu birkaç saniye sürebilir).
- USB'yi çıkarmayı unuttuysanız, programı kapatmanız, USB'yi çıkartmanız ve programı tekrar başlatmanız gerekecektir. Daha sonra USB'yi takın. Şimdi servo pozisyonlarını, bacakların ve ayakların doğru şekilde hizalandığından emin olmak için kalibre edebilirsiniz. Kaydıraç, açıda büyük değişikliklere izin verirken, +/- düğmeleri her servo pozisyonu için daha ince kontrol sağlar.

- Otto'daki servolar doğru şekilde hizalandığında, Otto'nun nasıl hareket ettiğini görmek için 'Walk Test' üzerine tıklayın. Daha ince ayarlar gerekiyorsa, şimdi yapılmalı ve yürüme testi tekrarlanmalıdır. USB kablosunun Otto'nun hareketini engellemediğinden emin olun.

- Her şeyin hizalandığından memnun olduğunuzda, 'Save' üzerine tıklayın. Bir onay işareti ve düzgün hizalanmış bir Otto arayüzünde görünecektir. Otto'nun mutlu bir ses çıkarması (eğer buzzer bağladıysanız) ve dans etmesi.

- TEBRİKLER!! Otto'nun servolarını başarıyla kalibre ettiniz. Pozisyonlar Otto'ya kaydedildi ve Nano veya servolardan herhangi birini değiştirmediğiniz sürece tekrar kalibre edilmesi gerekmez.

*/
  
  v = 0;

}

void loop() {
/*
- Otto'yu nasıl inşa edeceğinizle ilgili talimatları dikkatlice izlediniz ve tüm servoları (boynuzları takmadan önce 90 derecede) merkezi hale getirdiğinizden emin oldunuz. Şimdi Otto'nun nasıl hareket ettiğini ve dans ettiğini kontrol ettiğiniz çok heyecan verici bir anasınıfı kodu yüklüyorsunuz.

- (Ne oldu? Neden bacaklar ve ayaklar yerinden çıktı? Otto doğru görünmüyor ve düzgün hareket etmiyor.

- Hayal kırıklığına uğramayın ve endişelenmeyin! Bu tamamen normaldir ve her Otto montajında olur. Bu, servoların merkezi pozisyonlarını ayarlamak için basit bir kalibrasyon adı verilen bir süreçte gereklidir. Bu, sadece bir kez yapılması gereken bir işlemdir ve ardından Otto'nuzu her açtığınızda doğru pozisyonlar hatırlanacaktır.
*/

    if (Serial.available()) {
      readChar((Serial.read()));
    }

}