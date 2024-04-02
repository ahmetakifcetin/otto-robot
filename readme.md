

# Otto DIY Robot Arduino Kütüphanesi

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
![version](https://img.shields.io/badge/version-13.0-blue)

Bu depo, Arduino uyumlu kartlar için ana Otto DIY robot kütüphanelerini içerir. [Otto DIY robot](https://www.ottodiy.com/)

:star: Bana GitHub'da yıldız verin, bu bana yardımcı olur!

## Kurulum:

1. [Otto-Library.zip Kütüphanesini İndirin](https://github.com/OttoDIY/OttoDIYLib/archive/master.zip)
2. Arduino IDE'yi açın ve Sketch > Include Library > Add .ZIP Library'ye gidin. Açılır listede en üstte, "Add .ZIP Library" seçeneğini seçin.
3. İndirdiğiniz .zip dosyasının konumuna gidin ve açın.
4. Ana pencerede, alt kısımda bir mesaj görürsünüz, bu mesajın yüklendiğini belirtir.
5. Doğru bir şekilde yüklendiğini doğrulamak için, Sketch > Include Library menüsüne gidin. Artık kütüphaneyi açılır menünün en altında görmelisiniz.


Bu, Otto örnek kodlarını kullanmaya hazır demektir! Ayrıntılar için File > Examples > OttoDIYLib'e bakın veya kütüphaneleri başka nasıl yükleyebileceğinizi görmek için bu linke gidin.

[Kütüphane hakkında daha fazla bilgi edinmek için bu adresi ziyaret edin.](https://www.arduino.cc/en/Guide/Libraries)

Hızlı kurulum için bu kütüphaneyi Arduino Yöneticisinde `Otto DIYLib` olarak bulabilirsiniz (uyumsuz kütüphaneleri kullanmayın).

## Uyumlu Donanım Kartları

- Arduino Nano
- Arduino Uno
- Arduino Micro
- Arduino Mega
- Arduino Mini
- Arduino Leonardo
- Arduino Nano Every
- ESP8266
- ESP32

## Yapı

4 motorlu bacakları olan Otto gibi herhangi bir ikiayaklı robot için temel kütüphaneler.

* `Otto.h` ve `Otto.cpp` tüm ana işlevleri içerir
* `Otto_gestures.h` tüm jest işlevlerini içerir
* `Otto_mouths.h` tüm ağız işlevlerini içerir
* `Otto_sounds.h` tüm ses işlevlerini içerir
* `Otto_matrix.h` tüm matrix işlevlerini içerir
* `Oscillator.h` servo motorların "düzgün" hareketi için ana algoritmadır
* `SerialCommand.c` Yazılım seri iletişim için Bluetooth iletişimi içindir

### Kütüphane Ekleme

```cpp
#include <Otto.h>
Otto Otto;
```

### Pin Tanımları

Bu, örneklerde AVR Arduino kartları için servo motorlar ve buzzer için varsayılan sinyal bağlantılarıdır, ayrıca pin numarasını değiştirirseniz farklı pinlere bağlayabilirsiniz.

```cpp
#define LeftLeg 2 // Sol bacak pin
#define RightLeg 3 // Sag bacak pin
#define LeftFoot 4 // Sol ayak pin
#define RightFoot 5 // sag ayak pin
#define Buzzer 13 //buzzer pin
#define echo 9 //hc-sr signaş pin
#define trig 8 //hc-sr signal pin
```

### Başlatma

Programı başlattığınızda, servo motor kalibrasyonunu kullanarak 'init' fonksiyonunun çağrılması gerekir.<br/>'home' fonksiyonu ile başlangıçta servo motorları ev konumlarına yerleştirmek en iyisidir. 

```cpp
void setup() {
   Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer);
   Otto.home();
}
```
`home()` fonksiyonu, servoları merkez pozisyonuna hareket ettirir, Otto nötr pozisyonda durur.

## Ön Tanımlı Fonksiyonlar:
Kütüphanede birçok önceden yapılandırılmış hareket bulunmaktadır:

### Hareketler:
Bu, 4 servo motorun kullanımını içeren ve osilasyon kütüphanesinin sinerjik olarak bir araya geldiği ve düzgün hareketlerle birleştiği eylemlerdir. pratensis `()` içindeki değerleri değiştirerek hareketin hızını, yönünü ve büyüklüğünü değiştirebilirsiniz.

#### Yürüme fonksiyonu

```cpp
Otto.walk(steps, time, dir);
```
- `steps`o hareketin kaç kez tekrarlanacağıdır, ek kodlama veya ek satırlar eklemeye gerek yoktur.
- `time` (aşağıda `T` olarak belirtilmiştir) milisaniye cinsinden hareketin süresidir. Daha yüksek bir zaman değeri, hareketin daha yavaş olmasını sağlar, 500 ila 3000 arasında değerleri deneyin.
- `dir` yönü belirler: `1` ileri veya `-1` geri 

##### Örnek:
```cpp
Otto.walk(2, 1000, 1);
```
Bu örnekte `2` adım, `1000` "ZAMAN" milisaniye ve ileri yürüme yapacaktır.

For example changing T value: Slow=2000 Normal=1000 Fast= 500

```cpp
Otto.turn(steps, T, dir);
```
(adım sayısı, T, sola veya -1 sağa)

```cpp
Otto.bend (steps, T, dir);
```

(adım sayısı, T, 1 sol eğim veya -1 sağ eğim)

```cpp
Otto.shakeLeg (steps, T, dir);
```
(adım sayısı, T, 1 sol eğim veya -1 sağ eğim)

```cpp
Otto.jump(steps, T);
```
(adım sayısı yukarı, T) burada bir dir parametresi yoktur, Otto gerçekten zıplamaz ;P


### Danslar:

Hareketler gibi ama daha eğlenceli! dansı daha ilginç hale getirmek için yeni bir parametre olan `h` "hareketlerin yüksekliği veya büyüklüğü" ayarlayabilirsiniz.


```cpp
Otto.moonwalker(steps, T, h, dir);
```
(adım sayısı, T, h, 1 sola veya -1 sağa)

`h`: 15 ile 40 arasında değiştirebilirsiniz


##### Örnek:
```cpp
Otto.moonwalker(3, 1000, 25,1);
```
(adım sayısı, T, h, 1 sola veya -1 sağa)

`h`: 20 ile 50 arasında değiştirebilirsiniz

```cpp
Otto.crusaito(steps, T, h, dir);
```
(adım sayısı, T, h, 1 sola veya -1 sağa)

`h`: 15 ile 40 arasında değiştirebilirsiniz

```cpp
Otto.flapping(steps, T, h, dir);
```
(adım sayısı, T, h, 1 öne veya -1 arkaya)

`h`:  10 ile 30 arasında değiştirebilirsiniz

```cpp
Otto.swing(steps, T, h);
```
`h`: 0 ile 50 arasında değiştirebilirsiniz


```cpp
Otto.tiptoeSwing(steps, T, h);
```
`h`: 0 ile 50 arasında değiştirebilirsiniz

```cpp
Otto.jitter(steps, T, h);
```
`h`: 5 ile 25 arasında değiştirebilirsiniz

```cpp
Otto.updown(steps, T, h);  
```
`h`: 0 ile 90 arasında değiştirebilirsiniz

```cpp
Otto.ascendingTurn(steps, T, h);
```
`h`: 5 ile 15 arasında değiştirebilirsiniz


### Sesler:

```
Otto.sing(songName);
```
Yalnızca () içinde ne olduğunu değiştirerek, sesleri kolayca 19 farklı taneyle değiştirebiliriz.Kopyalayıp yapıştırarak yeni bir satıra yapıştırarak sesleri istediğiniz kadar yapabilirsiniz.
##### Sing Fonksiyonu():
- S_connection
- S_disconnection
- S_buttonPushed
- S_mode1
- S_mode2
- S_mode3
- S_surprise
- S_OhOoh
- S_OhOoh2
- S_cuddly
- S_sleeping
- S_happy
- S_superHappy
- S_happy_short
- S_sad
- S_confused
- S_fart1
- S_fart2
- S_fart3

Otto, 'sing' işleviyle birçok ses çıkarabilir:
```cpp
Otto._tone(10, 3, 1);
```
(notFrekansı, notSüresi, sessizSüre)

```cpp
Otto.bendTones (100, 200, 1.04, 10, 10);
```
(başlangıçFrekansı, sonFrekans, oran, notSüresi, sessizSüre)

### Jestler:
Son olarak, favorimiz, Bu, önceki iki işlevin bir kombinasyonu olan şarkı + yürüyüşü öğrendiğimiz.<br>
Amacı, aynı anda sesleri ve hareketleri birleştirerek duyguları ifade etmektir ve eğer LED matrisiniz varsa, onları robot ağzında gösterebilirsiniz!

```cpp
Otto.playGesture(gesture);
```
- `Otto.playGesture(OttoHappy);`
- `Otto.playGesture(OttoSuperHappy);`
- `Otto.playGesture(OttoSad);`
- `Otto.playGesture(OttoVictory);`
- `Otto.playGesture(OttoAngry);`
- `Otto.playGesture(OttoSleeping);`
- `Otto.playGesture(OttoFretful);`
- `Otto.playGesture(OttoLove);`
- `Otto.playGesture(OttoConfused);`
- `Otto.playGesture(OttoFart);`
- `Otto.playGesture(OttoWave);`
- `Otto.playGesture(OttoMagic);`
- `Otto.playGesture(OttoFail);`

Gördüğünüz gibi, çok basit, ama yaptığı şey oldukça ileri düzeydedir.

## Lisans

OttoDIYLib, GPL Açık Kaynak lisansı şartlarına tabidir ve ücretsiz olarak sunulmaktadır.

<a href="https://discord.gg/felicio"><img src="https://images.squarespace-cdn.com/content/v1/5cd3e3917046805e4d6700e3/1560193788834-KYURUXVSZAIE4XX1ZB2F/ke17ZwdGBToddI8pDm48kK6MRMHcYvpidTm-7i2qDf_lfiSMXz2YNBs8ylwAJx2qLijIv1YpVq4N1RMuCCrb3iJz4vYg48fcPCuGX417dnbl3kVMtgxDPVlhqW83Mmu6GipAUbdvsXjVksOX7D692AoyyEsAbPHhHcQMU6bWQFI/join_discord_button_small.png" width="25%"></a>

Tüm katkıda bulunanlarımıza büyük teşekkürler.
@otto

## Nasıl Katkıda Bulunulur:
Bu yazılıma katkıda bulunmak sıcak bir şekilde karşılanır. Bu projeye katkıda bulunabileceğiniz 3 yol vardır:

1. Bir sorun bulup test edin ve ardından bir sorun yayınlayın.
2. Sorunları veya diğer hataları çözmemize yardımcı olun.
3. Kodu iyileştirin.
Bunu [temel olarak çatalla](https://help.github.com/tr/articles/fork-a-repo),, değişiklikleri taahhüt ederek ve [çekme istekleri](https://help.github.com/tr/articles/about-pull-requests) ile yapabilirsiniz. Lütfen bir değişiklik günlüğü ve iletişim bilgilerinizi dosya başlığına ekleyin.

Katkılarınız için şimdiden teşekkürler. 