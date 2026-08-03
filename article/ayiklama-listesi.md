# Ayıklama listesi

Bu bir öneri listesidir. Hiçbir şey silinmemiştir. Ölçüt, makalenin kendi ilan
ettiği kapsamdır: **öte taraftaki yönelimi dönüş olayının dört koordinatına
bağlayan eşleme**, ve o eşlemenin girdileri, kısıtları, sonuçları. Bir bölüm bu
eşlemenin hiçbir halkasına dokunmuyorsa, ne kadar doğru olursa olsun kapsam
dışıdır.

Makale şu an **5508 satır**, 30 numaralı bölüm ve ekler dahil.

---

## A. Kapsam dışı: gidiş dönüşe hiç değmeyen bölümler

Toplam **466 satır**. Bunlar yanlış değildir; yalnızca başka bir makalenin
konusudur.

### A1. Bölüm 28, "Orada gözlem", 275 satır, 14 alt bölüm

Öte tarafta kuantum alan kuramı kurulmaya çalışılıyor: Cauchy yüzeyi yok,
Feynman propagatörü tanımsız, kararlı vakum yok, Wick dönüşü, Öklid
propagatörü, parçacık kavramının tanımsızlığı, Casimir etkisi.

**Neden kapsam dışı.** Zincirin hiçbir halkası bir vakum tanımına, bir
propagatöre ya da bir parçacık sayısına dayanmıyor. Dönüş anı fazdan okunuyor,
faz da saçılma probleminden geliyor. 28'in tamamı silinse zincirde tek bir sayı
değişmez.

**Ne yapmalı.** Bulgularının tek paragrafa inmesi yeterli: "öte tarafta olağan
bir alan kuramı kurulamaz, bu çalışma da kurmaz, ihtiyaç da duymaz." Kod tarafı
(`quantum/`) dursun; oradaki hesaplar bir gün lazım olabilir.

**Tek istisna.** 28.5 ile 28.7, lapse konturu ve Wick dönüşü, geçiş
hesabındaki dallanma seçimini besliyor. O ikisi 14. bölüme taşınmalı,
atılmamalı.

### A2. Bölüm 29, "İki bölge arasında sinyal", 191 satır, 7 alt bölüm

Kütlesiz olmanın işe yaramaması, yer çekimi kanalı, korelasyonun sinyal
olmaması, etkileşim.

**Neden kapsam dışı.** Soru "bir parçacığı yollayıp geri almak" idi,
"iki bölge arasında haberleşmek" değil. Sinyal sorusu bambaşka bir kısıt
kümesine tabi ve makalenin iddiasını ne güçlendiriyor ne zayıflatıyor.

**Ne yapmalı.** Madde 9 (yer çekiminin bağlanması ve sinyal taşıması) kapsam
maddelerinden çıkarılmalı, ya da bölüm ayrı bir yazıya alınmalı. İkisinden
birini seçmek gerekir; şu an madde listesinde duruyor ama zincirde yeri yok.

---

## B. Tekrar: aynı şeyi ikinci kez kuran yerler

### B1. Bölüm 17 ile Bölüm 19 arasındaki örtüşme

17 "Yönelim sözlüğü", 346 satır, 12 alt bölüm. 19 "Çekirdek eşleme", 321 satır.
İkisi de aynı sözlüğü kuruyor ve aynı soruyu cevaplıyor.

Örtüşen alt bölümler:

- **17.2 Sözlük** ile **18.1 Sözlüğün burada kullanılan biçimi** ile 19'un
  tanım kümesi: sözlük üç kez yazılıyor.
- **17.8 Öte tarafta hareket ne demektir** ile **9.1 Dört eksende hareketin
  tanımı**: aynı tanım.
- **17.9, 17.10, 17.11, 17.12**: çıkış anı ve çıkış yüzünün içerideki hareketi
  ne kadar gördüğü. 19.7'nin kapalı formülü bunların hepsini tek ifadede
  veriyor. Formül yazıldıktan sonra bu dördü, formülün okunuşundan ibaret.

**Ne yapmalı.** 17 sözlüğü **bir kez** kursun, 19 formülü versin, 17.9 ile
17.12 arası formülün altına üç cümlelik bir okunuş notuna insin. Tahmini
kazanç 150 satır.

### B2. Beş ayrı yerde itiraz ve denetim

21, 22, 23, 24, 25, 26, 27, 30 toplam **1374 satır**, makalenin dörtte biri.

- **21** Sylvester engeli, 59 satır.
- **22** dönüş anına yöneltilen sorular, 321 satır.
- **23** yönelim tablosuna yöneltilen sorular, 95 satır.
- **24** itirazlar ve cevaplar, 195 satır, içinde tam sicil.
- **25** yöntem ve doğrulama, 191 satır, üç denetim.
- **26** açık kalanlar ve simülasyon yolu, 115 satır.
- **27** literatürün bıraktığı sorular ve duruş, 288 satır.
- **30** anlaşmazlıkların iki türü, 110 satır.

**Sorun.** Aynı üç şey dört kez anlatılıyor: neyin ödünç alındığı, neyin açık
kaldığı, neyin geri çekildiği. 24.7'deki sicil, 27.2'deki geri çekilenler ve
27.4'teki açık kalanlar büyük ölçüde aynı kalemleri sayıyor.

**Ne yapmalı.** Tek bir "İtirazlar, siciller ve denetim" bölümü. İçinde bir
itiraz sicili, bir üretim sicili, bir varsayım sicili, bir de açık sorular
listesi. Dördü de kodun ürettiği tablolar olduğu için metin zaten ince olabilir.
Tahmini kazanç 500 ila 700 satır, hiçbir bilgi kaybetmeden.

### B3. Bölüm 30, "Anlaşmazlıkların iki türü"

110 satır, tamamen yöntem üzerine: rakip modellerin tek bir nesnenin
izdüşümleri olduğu, madalyonun iki yüzü, yönteme direnen çelişkiler.

**Neden ayıklanmalı.** Bu bir okuma yöntemi beyanıdır, bir sonuç değildir.
Yeri giriş, hem de bir paragraf olarak. Sonda 110 satır kaplaması, makalenin
kendi yöntemini savunmakla bitmesi anlamına geliyor.

---

## C. Zayıf bağlı: kalabilir ama küçülmeli

### C1. Bölüm 16, "Bilgi farkı", 51 satır

Göreli entropi, yolculuğun paketi keskinleştirmesi. Zincirin hiçbir halkasına
girmiyor, ama dönüş olayının bir özelliği. Üç paragrafa insin.

### C2. Bölüm 11, "Orada madde, enerji ve öngörü", 163 satır

11.1 determinizm kaybı, 11.2 eşiğin mod filtresi olması. İkincisi zincirde:
neyin geçtiğini belirliyor. Birincisi bir yan gözlem. 11.1 kısalsın.

### C3. Bölüm 8, 426 satır, 9 alt bölüm

Makalenin ikinci en uzun bölümü. Zamanın oku, tek yönlülük, ayrımın etiketi,
denklemin yön tercihi. Bunların büyük kısmı **felsefi bir tartışmanın** karşı
tarafına verilmiş cevap. Zincirde gereken tek şey 8.6 zaman yönelimi ile 8.7
yolculuğun tanımı.

8.3, 8.4, 8.4.1 ve 8.5 birlikte yaklaşık 150 satır ve hepsi tek bir sonuca
çıkıyor: yönelim metrikte var, zorunluluk hiçbir metrikte yok. Bu tek bir alt
bölümde söylenebilir.

---

## D. Kalması gerekenler, tartışmasız

Zincirin halkaları ve bedelleri:

- **2** geçişi yapan yapı, tarama ve sözlük katsayısı.
- **3** ara bölgenin tipleri ve kalınlıkları, oran koşulu ve 3.7.1.
- **4, 5, 6, 7** eşik, eklem koşulu, sonlu kalınlık, yırtık.
- **9** öte tarafta hareket ve dispersiyon.
- **10** dalga ile parçacık okuması, çift izlek.
- **12, 13** ikinci geçiş ve dönüş anı.
- **14, 15** mod içeriği ve korunan yükler.
- **18** koordinat sözlüğü.
- **19** çekirdek eşleme ve kapalı formül, 19.8 ve 19.9 dahil.
- **20** zincirin tek yerde yazılması ve uçtan uca örnek.

---

## Toplam

| Öbek | Satır | Öneri |
|------|-------|-------|
| A, kapsam dışı | 466 | çıkar, iki alt bölümü taşı |
| B1, sözlük tekrarı | ~150 | birleştir |
| B2, itiraz ve denetim | ~600 | tek bölümde topla |
| B3, yöntem beyanı | 110 | girişe bir paragraf |
| C, küçültme | ~250 | kısalt |

Yaklaşık **1580 satır**, makalenin yüzde yirmi dokuzu. Geriye kalan yaklaşık
3900 satır, tamamı zincirin kendisi ve bedelleri.

**Hiçbir kesme yapılmadan önce iki şey doğrulanmalı.** Çıkarılan her bölüme
metnin başka yerlerinden atıf var mı, ve çıkarılan her bölümün varsayım
sicilinde satırı var mı. İkisi de kod tarafındaki denetimlerle taranabilir;
kesme kararı verildiğinde önce o iki tarama çalıştırılmalıdır.
