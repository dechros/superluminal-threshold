# İkinci bölgedeki mesafenin birinci bölgede zaman farkına dönüşmesi

## Özet

Bu çalışma, kütleli bir parçacığı zamanda başka bir ana taşımanın bir yolunu
sınamaktadır. Sınanan kurgu iki bölge tanımlar. **Bölge I** parçacığın yola
çıktığı sıradan bölgedir; Bölge I'de dört eksenin biri zaman, üçü mekân
eksenidir ve ışık hızı bir üst sınır olarak durur. **Bölge II** ise bunun tam
tersini taşır: Bölge II'de üç eksen zaman, bir eksen mekân eksenidir. Bu yüzden
parçacık Bölge II'de yalnızca o tek mekân ekseni boyunca ilerleyebilmekte,
zamanda ise üç ayrı yön bulmaktadır. Eksenlerin bu şekilde yer değiştirmesine
literatür *imza değişimi* demektedir. İki bölgeyi ayıran yüzey ise bu çalışmada
**eşik** adını almaktadır.

Kurgu üç adımdan oluşmaktadır: parçacık eşiği geçer, Bölge II'de $s$ kadar
mesafe alır ve aynı eşikten Bölge I'e döner. Çalışmanın sorduğu soru şudur: bu dönüş
Bölge I'in saatinde hangi ana denk düşmektedir.

Hesabın verdiği cevap şudur. Parçacığın döndüğü an ile parçacık hiç yola
çıkmasaydı bulunacağı an arasında bir fark oluşur, ve bu fark **saat farkı**
adını alır. Farkın büyüklüğü, doğal birimlerde ($c = 1$) tam olarak $s$ kadar
çıkar; SI birimlerinde ise $s/c$ olur, yani bir metrelik yolculuk $3{,}34$
nanosaniye verir, bir yıllık bir yolculuk ise $9{,}46 \times 10^{15}$ metrelik
bir mesafeye karşılık gelen bir zaman kazandırır. Sonucun taşıdığı bilgi bu
bölmede değil, bölenin **ne olduğundadır**: araya parçacığın hızı, geçişin
hızı ya da bir ölçek çarpanı girmez, yalnızca $c$ girer. Hesaptan çıkan katsayı
tam olarak bire eşittir.

Yolculuğun yönü de iki türlü olabilmektedir. Eşikten geçişi yazan matris sekiz tanedir. Bu sekiz matrisin dördü dönüşü
kalkıştan daha geç bir ana, dördü ise daha erken bir ana taşımaktadır.

Ne var ki bu sonuç bir koşula bağlı kalır. Sekiz matristen hangisinin işlediğini
geometri seçmez. Dolayısıyla çalışmanın kanıtladığı önerme yalnızca
şu olur: böyle bir geçiş gerçekleşirse, dönüş anı hesaplanmış bir sayıya eşit çıkar.
Geçişin gerçekten kurulabildiği ise kanıtlanmamıştır, çünkü Bölge II'nin içi
doğrudan ölçüme kapalıdır: Bölge I'de yalnızca dönüş anı okunabilmekte, ve bu
nicelik bir geçişin olduğunu bildirmekte ama içeride izlenen yolu
bildirmemektedir.

## 1. Giriş

Bir cismi zamanda geriye taşıyan çözümler genel görelilikte bilinmektedir:
dönen bir evren [27], sonsuz uzunlukta dönen bir silindir [28] ve geçilebilir
bir solucan deliği [29] bunların arasındadır. Ne var ki bunlar ya evren
ölçeğinde bir geometri ya da alışılmadık bir madde dağılımı gerektirdiğinden
laboratuvara inmemektedir; ayrıca kuantum etkilerinin böyle çözümleri
engelleyip engellemediği de açık bir sorudur [30]. Bu çalışma başka bir yol sınar ve onun
aritmetiğini kurar. Sınanan yolun sorusu şudur: parçacık Bölge II'de bir mesafe
alıp geri döndüğünde, Bölge I'de duran bir gözlemcinin saatinde hangi anda
görünür.

İki bölgenin tanımını Özet vermişti. **Bölge I**'de bir eksen zaman ve üç eksen
mekân eksenidir, **Bölge II**'de ise bunun tersi geçerlidir. İkisini ayıran
sonlu kalınlıktaki katman **eşik** adını alır. Bu tanıma bir madde daha eklenir.
Bölge II'de üç zaman ekseni bulunduğundan, o bölgede bir cismin durumu tek bir
hız sayısıyla değil, üç zaman uzayındaki bir **yönelimle** verilir (Bölüm 8).
Yönelim ile tek uzay eksenindeki ilerleme, parçacığın Bölge II'de taşıdığı
bilginin tamamıdır.

### 1.1 Kurulan dönüşüm

Çalışmanın cevapladığı soru şudur: parçacık geri döndüğünde Bölge I'in dört
koordinatı hangi değerleri alır. Sorunun ağırlığı da uzay koordinatlarında
değil, zaman koordinatındadır, çünkü aranan şey dönüşün nerede değil **ne
zaman** gerçekleştiğidir.

Bölge II'nin koordinatları $(t_1, t_2, t_3, r)$ ile, Bölge I'inkiler
$(ct, x, y, z)$ ile gösterilmektedir. İki dörtlüyü birbirine bağlayan dönüşüm
$M(V)$ matrisidir (Bölüm 4):

$$M(V)\,(t_1,\, t_2,\, t_3,\, r)^{\mathsf{T}} \;=\;
(ct,\, x,\, y,\, z)^{\mathsf{T}}_{\text{dönüş olayı}},
\qquad M(V) = D \cdot B(c^2/V), \qquad V > c$$

Buradaki $V$, dönüşümün etiketidir: iki bölge arasındaki bağıntıyı $c$'yi aşan
bir $V$ değeri parametrelendirir, ve $B(c^2/V)$ ışık hızının altında kalan
sıradan bir boosttur. $D$ ise imza değişimini tek başına yapan, hiçbir
parametreye bağlı olmayan sabit matristir. Aşağıdaki ana sonuç $V$'den
bağımsızdır, çünkü sonucu taşıyan çarpan $D$'dir; $V$ yalnızca hangi ailenin
kullanıldığını gösterir (Bölüm 4).

**Ana sonuç.** Parçacık Bölge II'nin tek uzay ekseninde $s$ kadar ilerlediğinde
dönüş olayının $t$ bileşeni $s$ kadar değişmektedir. İki nicelik arasındaki
katsayı bire eşit olduğundan araya bir hız ya da bir ölçek çarpanı girmez. Bu
değişim yalnızca $t$ bileşeninde görülür, çünkü $s$'nin dönüş olayındaki $x$,
$y$ ve $z$ bileşenlerine katkısı sıfırdır. Dönüşüm doğrusal olduğundan arka
arkaya yapılan yolculukların katkıları da toplanmaktadır. Bütün bunlara karşın
$t$ bileşenindeki değişimin işaretini, yani dönüşün kalkıştan önce mi sonra mı
gerçekleştiğini, geometri tek başına belirlememektedir.

Bu çalışma zamanda yolculuğu baştan kabul etmez, yukarıdaki dönüşümden
okumaktadır: dönüş anının, parçacık hiç eşiğe girmeseydi bulunacağı andan
farklı olup olmadığı hesapla belirlenir. Parçacığın Bölge II'de $s$ kadar
mesafe almasının kendisini hangi dinamiğin ürettiği, yani $s$'nin zamanla nasıl
büyüdüğü, bu çalışmanın kapsamı dışındadır; kurulan şey yalnızca $s$ ile dönüş
anı arasındaki bağıntıdır.

### 1.2 Sonucun koşulu

Bölüm 1.1'in yazdığı $M(V)$ matrisi tek bir matris değildir. Aynı eşitliği
sağlayan sekiz farklı $M(V)$ bulunmuştur, ve bu sekizinin hangisinin işlediğini
geometri seçmez, çünkü onları birbirine bağlayan dönüşümler her iki bölgenin
metriğini de bozmadan bırakmaktadır. Sekiz matrisin dördü Bölge II'deki bir
ilerlemeyi Bölge I'in saatinde daha geç bir ana taşır, kalan dördü ise daha
erken bir ana. Bu çalışma, geriye taşıyan dörtlüden birini seçmiştir, ve bu seçim hesaptan
çıkmamıştır (Bölüm 4.1).

Parçacık Bölge II'de tek bir yönde ilerler. Bu ilerlemenin Bölge I'in saatinde
hangi zaman yönüne düştüğünü ise parçacığın kendisi değil, seçilen $M(V)$
matrisi belirlemektedir. Dönüş kalkıştan önceye düşecekse, geriye taşıyan bir
$M(V)$ şarttır. Parçacığın Bölge II'de ne kadar mesafe alacağı ise $s$'yi
üreten dinamiğe bağlıdır, ve o dinamik bu çalışmanın kapsamı dışındadır.

Dolayısıyla çalışmanın kanıtladığı önerme şu olur: **böyle bir geçiş gerçekleşirse**,
dönüş anı hesaplanmış bir sayıya eşit çıkar. Böyle bir geçişin gerçekleştiğini
gösteren doğrudan bir deney ise henüz yoktur.

Literatür konunun birçok parçasını kurar. [4], [5], [6] ve [7] imza değişimini
tutarlı bir sınır değer problemi olarak yazar; [14], [15], [16] ve [17] alan
denklemlerini imza değiştiren bir uzayzamanda çözer; [13] imza değişimini
benzeşik bir ortamda üretir; [22] ve [23] doymuş tünelleme gecikmesini ölçer.
Ne var ki bu sonuçların hiçbiri kütleli bir parçacığın gerçek bir eşikten
geçtiğini göstermez, çünkü benzeşik bir sistem geometrinin denklemini taklit
eder, taşınan maddeyi değil.

Geçişin kurulmasının önünde bir engel de şudur: Bölge II'nin içi doğrudan
ölçüme kapalı kalmıştır. Bölge I'de okunabilen nicelik dönüş anıdır. Bu
nicelik bir geçişin olduğunu bildirir, ancak parçacığın Bölge II'de izlediği
yolu bildirmez (Bölüm 13).

### 1.3 İddianın büyüklüğü

Yukarıdaki sonuç dört parçadan kurulur, ancak bunlardan yalnızca dördüncüsü
yenidir. İlkini literatür 1962 ile 1970 arasında göstermiştir ([25], [19], [26]): ışıktan
hızlı hareket geçmişe varmayı mümkün kılar. İkincisini de yine literatür
bilmektedir ([1], [3]), yani Bölge II'nin bir uzay ve üç zaman ekseni
taşıdığını, parçacıkların da yalnızca o tek uzay ekseninde ilerleyebildiğini.
Üçüncüsü, bir uzay ekseninin bu geçiş altında zaman eksenine dönüşmesidir, ve o
da bilinen bir sonuçtur ([1], [3]).
Geriye kalan dördüncü adımı ise aşağıdaki cümle taşır:

> Işık hızını geçen kütleli madde, Bölge II'nin tek mekân boyutunda hareket edip
> subluminal bölgeye döndüğünde **farklı bir zaman konumunda** bulunur.

Literatürde bulunmayan şey tam olarak budur: Bölge II'deki yer değiştirmeyi bir
saat farkına çeviren ve dönüşte hangi ana varıldığını sayıyla veren bir
hesap. İlk üç parçanın her biri yukarıda kaynağıyla anılmıştır, dördüncüsünün
ise anılacak bir kaynağı yoktur.

### 1.4 Sonucu taşıyan adımlar

Sonuca beş adımda varılmıştır. Adımların tamamı, her birinin hangi bölümde
kurulduğuyla birlikte Bölüm 14'te sıralanır.

### 1.5 Gösterilmeyenler

Beş adım bir aritmetik kurar, ve o aritmetik kendi içinde eksiksiz işler. Ancak
aynı aritmetik, böyle bir geçişin fiziksel olarak kurulabildiğini göstermez.
Kurulmasının önüne iki ayrı engel çıkar.

**Birincisi bir açık sorudur.** Saat farkının işaretini seçebilmek, sekiz matris
arasından birini evrensel olarak sabitleyen bir kuralın bulunmamasına dayanır,
oysa böyle bir kuralın yokluğu kanıtlanmamıştır.

**İkincisi gözlemdedir.** Bölge II'de durup ileriyi kestirmeye çalışan bir
gözlemci başarısız olur, çünkü eşikteki başlangıç değeri problemi iyi
konumlanmaz (Bölüm 7.3). Bölge II'nin içi de Bölge I'den doğrudan ölçüme
kapalıdır (Bölüm 13).

### 1.6 Model

Model iki bölge değil üç bölge kullanır. Bölge I ile Bölge II'nin arasındaki
geçiş, kalınlıksız bir yüzey olarak alınmaz; kendi kalınlığı ve kendi imzası olan
üçüncü bir bölge olarak durur.

Çalışma parçacığı ayrıca iki okumayla birden taşır. Hesaplar dalga paketi üzerinden
yürür, anlatım ise noktasal bir cisim dilini kullanır. İki okumayı birbirine
çeviren sözlüğün, paket yeterince dar tutulduğunda tam olarak işlediği
gösterilmiştir.

### 1.7 Yolculuk

Parçacığın Bölge II'de yapabilecekleri iki etikete indirgenmiştir: ara bölgenin
hangi yüzünden çıktığı ve enerji vektörünün ne kadar döndüğü. İkisinin tanımını
Bölüm 7.5, Bölge I'deki karşılıklarını ise Bölüm 8.1 verir.

Bu iki etiketten çıkan sonuç şudur: Bölge I'in saatinde fark üreten tek hareket,
tek uzay ekseni boyunca alınan yoldur. Üç zaman ekseni içinde kalan hareketler
saate hiçbir şey taşımaz.

Dönüş anını ise parçacığın yanında taşıdığı bir saat vermez; içeride zaman
yönelimi bulunmadığından geçirilen bir süre tanımsız kalır (Bölüm 7).

### 1.8 Geri döndüğünde

Parçacık geri döndüğünde enerjisi, sürati ve kütlesi tam olarak korunur;
korunmayan tek şey gittiği yön olur. Bunun nedeni şudur: Bölge II'de hiçbir
fiziksel iz bırakmayan bir ayar dönmesi, Bölge I'de parçacığın yön değiştirmesi
olarak görünür, ve bu yön değişikliği hiçbir enerji harcamaz. Üstelik sapma
açıları her değeri de alamaz, sonlu bir kümeden gelir. İki özellik birleşince
çalışmanın deneyle ayırt edilebilecek öngörüsü ortaya çıkar: çarptığı hedefin
geri tepmediği ve açıları ayrık değerlerde kalan bir esnek sapma.

Dönüşümün kendisi ise tek yönlüdür: Bölge II'deki yönelim dönüş olayının
koordinatlarına ancak bir kısmıyla ulaşır, sürekli bir küme ayrık bir tayfa
düşer (Bölüm 11.8).

### 1.9 Modelin maddeleri

Aşağıdaki maddelerin hepsi tek bir dönüşüme aittir: Bölge II'deki yönelimi dönüş
olayının dört koordinatına bağlayan dönüşüme. Her madde bu dönüşümün ya bir
girdisini, ya bir kısıtını, ya da bir sonucunu kaydeder.

1. Model üç bölge kullanır: Bölge I, ara bölge ve Bölge II.
2. Ara bölgenin **neyden yapıldığı** ile **ne kadar kalın olduğu** birbirinden
 bağımsız iki soru sayılır. Kalınlık sıfıra inince tipin bir önemi kalmaz,
 ara bölge hiç yokken de kalınlığın bir önemi kalmaz.
3. Parçacık hem dalga paketi hem noktasal cisim olarak okunur; ikinci okuma
 paket yeterince dar tutulduğunda tam olarak geçerli kalır.
4. Bölge II'de ileriyi kestirme problemi kendi içinde iyi konumlanmaz, ancak
 eşikten erişilebilen alt kümesi bu sorundan etkilenmez.
5. Gidiş dönüş boyunca enerji, sürat ve kütle korunur; yön korunmaz.
6. Bölge II'deki bir ayar dönmesi Bölge I'de bir sapma olarak görünür, hiçbir
 enerji harcamaz ve açıları ayrık değerler alır.
7. Bölge II'deki yönelim dönüş olayının koordinatlarına ancak bir kısmıyla
 ulaşır: sürekli bir küme, ayrık bir tayfa düşer.

### 1.10 Okuma haritası

Çalışma üç adım üzerine kurulmuştur, ve üçü de tek bir amaca hizmet eder: kütleli
bir parçacığı zamanda geriye taşımak. Aşağıdaki tablo her adımın hangi bölümlerde
kurulduğunu gösterir.

| Adım | Sorusu | Kurulduğu bölümler |
| ------ | ----------------------------------------------------- | ----------------------------------------------------------- |
| Geçiş | Kütleli bir parçacık eşiğin ötesine nasıl geçer | Bölüm 3, Bölüm 4, Bölüm 5 |
| Mesafe | Bölge II'de mekânda kat edilen mesafe ne anlama gelir | Bölüm 4.1.1, Bölüm 4.1.2, Bölüm 7, Bölüm 8.1 |
| Dönüş | Geri döndüğünde saatte nereye düşer | Bölüm 11, Bölüm 12, Bölüm 13, Bölüm 14 |

**İki giriş noktası vardır ve ikisi farklı işe yarar.** Bölüm 2 hesabı kısa bir
tablo hâlinde verir; sayıyı yeniden üretmek isteyen oradan başlar. Bölüm 14 ise
beş adımı sıralar ve her adımın
hangi bölümde kurulduğunu gösterir; sonucun nasıl kurulduğunu izlemek isteyen
oradan başlar. İki bölümün sayıları farklı yapılanmalara aittir, dolayısıyla
birbirinin yerine geçmez.

Geri kalan bölümler ise ana hattı ilerletmez. Her biri, üç adımdan birine
yöneltilebilecek belirli bir itirazı karşılar ve o itirazı kapatınca işi biter.
Bu yüzden yukarıdaki tablo ile aşağıdaki tablo hiçbir adresi paylaşmaz. Yine de
ana hatta yer alan bazı bölümlerin alt bölümleri aşağıda görünür, çünkü bir bölüm
sonucu taşırken onun bir alt bölümü yalnızca bir itiraza cevap veriyor olabilir.

| Bölüm | Konusu | Karşıladığı soru |
| ---------- | ---------------------------------------------------------- | ---------------------------------------------------------------------------- |
| 6 | Geometrinin izin verdiği geçiş | Böyle bir geçişe geometri izin veriyor mu |
| 9 | Dalga ve nokta cisim okumaları | Hesabı paketle yapıp anlatımı cisimle kurmak meşru mu |
| 7.3 | Yönlendirilebilirlik ile ilerleme zorunluluğunun ayrılması | Ayrım metrikte var, zorunluluk hiçbir metrikte yok |
| 8.2, 8.3 | Dispersiyon, grup hızı, kapalı form çözüm | Üç zamanlı bir bölgede hız kavramı ne oluyor |
| 15 | Yöntem ve üç denetim | Bu sayılar doğrulanmış mı ve doğrulama kendini kandırıyor olabilir mi |
| 16 | İtirazlar ve yanıtlar | Literatürden gelen itirazlar tek yerde toplanmış mı |
| 4.2 | Geniş formülasyonla karşılaştırma | Aynı grubu daha genel kuran bir çalışma varken bu kurulum gereksiz mi |
| 8.3 | Durgunluğun tek yörüngeye indirgenmesi | Bölge II'de duran bir cismin sonsuz çok durumu mu var |
| 10.5 | Yükün yeniden dağılması | Eşikte yük kayboluyor mu |

Bölüm 10, geçişin neyi değiştirmeden bıraktığını kayda geçiren bir dökümdür ve
ana hat ile itiraz bölümlerinin arasında durmaktadır. Sonucu üretmez, ancak
sonucun kendi içinde tutarlı kalmasını sağlar.

**"Eşik" kökü iki ayrı nesnede geçer.** Tek başına **eşik**, iki bölgeyi ayıran
sonlu kalınlıktaki katmandır. **Eşik mesafesi** $s^\ast$ ise Bölge
II'de alınan ve dönüşü tam kalkış anına getiren uzunluktur, ve metre taşır.
İkisinin hangisinin kastedildiği bağlamdan okunur.

**"Sözlük" sözcüğü üç ayrı nesneyi adlandırır.** Üçü aşağıda bir kez ayrılmıştır ve
çalışmanın geri kalanında bu ayrım tekrarlanmamaktadır.

| Nerede | Neyi eşler | Çekirdek için rolü |
| ---------- | -------------------------------------------------------------------------------------- | ------------------------------------------------ |
| Bölüm 8.1 | Bölge II'nin dört ekseni $\to$ Bölge I'in yuvaları ve bir birim adımın saatte ürettiği | **Çekirdeğin kendisi.** İspatı Bölüm 4.1.1'dedir |
| Bölüm 11.2 | Bölge II'deki yönelim $\to$ Bölge I'de gözlenen nicelikler | Çekirdeğin girdi tarafı |
| Bölüm 12.1 | Dört koordinatta hareket ile yönelim arasındaki ayrım | Girdinin hangi kısmının hareket olduğu |

Sayısal katsayı yalnızca birincisinde tanımlanır ve tek bir yerde ispatlanmıştır.
Diğer ikisi onu kullanır, yeniden kurmaz.

---

# Kısım I. Bölge I

## 2. Çekirdek hesap

Hesabı baştan sona tekrar etmek için gereken her şey bu bölümde toplanmıştır ve
bölüm, makalenin geri kalanı okunmadan uygulanabilir. Her satırın hangi bölümde
türetildiği yanında yazılıdır. Çalışmanın kalanı da o türetmeleri ve her birinin
hangi itirazı karşıladığını anlatmaktadır.

**Girdi.** Hesap, Bölge II'nin enerji vektörü $E = (E_1, E_2, E_3)$ ile başlar. Bu
vektör Bölge I'de parçacığın üç momentum bileşenine karşılık gelir (Bölüm 10.1).
Vektörün Bölge II'deki yönü fiziksel bir fark yaratmaz, yalnızca uzunluğu yaratır
(Bölüm 10.3). Geri kalan girdiler kütle parametresi $\mu$ ve hız $c$ olur.

**Adımlar.**

| Adım | Nicelik | Bu nicelik nedir | Nerede |
| ---- | ---------------------------------------------------------------------------------- | ------------------------------------------------------ | ------------------------ |
| 1 | $\omega = c\sqrt{E_1^2 + E_2^2 + E_3^2 + \mu}$ | Parçacığın frekansı | Bölüm 10.1 |
| 2 | $2\tau$ | Gidiş dönüşün toplam eşik bedeli, tek bir geçişin $\tau$'sundan | Kapsam dışı |
| 3 | $2\tau - s$ | Varış anı, kalkışa göre, geri taşıyan dalda | Bölüm 4.1.2, Bölüm 4.1.1 |
| 4 | $s^\ast = 2\tau$ | Eşik mesafesi: bunu aşan yolculuk kalkıştan önce döner | Bölüm 4.1.2 |

Üçüncü satırda $s$'nin önündeki katsayı **bire eşittir** ve araya bir hız
girmez. Çalışmanın asıl sonucu budur (Bölüm 4.1.1, Bölüm 4.1.2). O terimin
işaretini, hangi geçiş dönüşümünün gerçeklendiği belirler; parçacığın Bölge II'de
hangi yöne ilerlediği belirlemez (Bölüm 4.1.1).

Tek bir geçişin bedeli $\tau$'nun kendisi ise ayrı bir sorudur: onu üreten
mekanizma bu çalışmanın kapsamı dışındadır. Kurulan şey $\tau$'nun bir değeri
değil, $\tau$ ile $s$'nin dönüş anında nasıl birleştiğidir.

### 2.1 Gidiş dönüşün hâlleri

Yukarıdaki adımlar tek bir sonuç değil, bir sonuç kümesi üretmektedir.

Sonucu iki bağımsız seçim belirlemiştir. Birincisi **dal**, yani sekiz geçiş
dönüşümünden hangisinin gerçeklendiği: dördü parçacığı ileriye, dördü geriye
gönderir ve metrik ikisi arasında bir tercih yapmaz. İkincisi **mesafe**, yani
parçacığın Bölge II'de ne kadar yol aldığı.

Varış anı, kalkışa göre, her durumda

$$t_{\text{dönüş}} = 2\tau \;\pm\; s$$

biçimini alır. Bu ifadedeki işareti dal belirler, $s$'yi ise yolculuğun uzunluğu.

| Dal | Mesafe | Varış anı | Ne olur |
| --------- | ----------- | --------------- | ------------------------------------------------ |
| Geri | $s < 2\tau$ | $0 < 2\tau - s$ | Kalktıktan sonra döner |
| Geri | $s = 2\tau$ | $0$ | Tam kalktığı anda döner |
| Geri | $s > 2\tau$ | $2\tau - s < 0$ | **Kalkmadan önce döner** |
| İleri | herhangi | $2\tau + s > 0$ | Her zaman sonra döner, mesafe gecikmeyi büyütür |
| Her ikisi | $s = 0$ | $2\tau$ | Yolculuk yok, yalnızca iki geçişin bedeli |

**Tablonun kapsamadığı tek durum**, dalın yolculuk sırasında değişmesidir. Dal,
geçiş dönüşümünün bir özelliğidir ve yolculuk boyunca sabit kalır. Değişmesi
için parçacığın Bölge II'de bir etkileşime girmesi gerekirdi; böyle bir
etkileşim bu modelde kurulmamıştır.

---

## 3. İki bölge ve metrikleri

İki bölge eksen sayılarında birbirinin tersidir. Bölge I eşiğin bu yanında kalır
ve bir zaman ekseni ile üç uzay ekseni taşır; Bölge II ise ışık hızının ötesinde
durur ve üç zaman ekseni ile bir uzay ekseni taşır. Koordinatları ve metrikleri
aşağıdaki gibi yazılır.

$$\text{Bölge I koordinatları: } (ct, x, y, z), \qquad
 \text{Bölge II koordinatları: } (t_1, t_2, t_3, r)$$

$$\eta = \mathrm{diag}(+1,-1,-1,-1), \qquad \eta' = \mathrm{diag}(+1,+1,+1,-1)$$

$\eta'$ işaretlerine göre $t_1$, $t_2$ ve $t_3$ zaman eksenleri, $r$ ise tek
uzay eksenidir. İki bölgenin eksenleri birbirine **ters sırayla** karşılık
gelir: Bölge I'in dörtlüsü baştan sona okunurken Bölge II'nin dörtlüsü sondan
başa okunur. Karşılıklar şöyledir:

| Bölge I ekseni | Karakteri | Bölge II'deki karşılığı | Karakteri |
| -------------- | --------- | ----------------------- | --------- |
| $ct$ | zaman | $r$ | uzay |
| $x$ | uzay | $t_3$ | zaman |
| $y$ | uzay | $t_2$ | zaman |
| $z$ | uzay | $t_1$ | zaman |

Tablonun ilk satırı bu çalışmanın taşıdığı asıl iddiadır: Bölge I'in zaman
ekseni, Bölge II'de tek uzay eksenine karşılık gelmektedir. Bu yüzden parçacığın
Bölge II'de $r$ boyunca aldığı yol, Bölge I'e döndüğünde $ct$ ekseninde bir
fark olarak görülür.

Kütle parametresi $\mu = (mc/\hbar)^2$ ile yazılır.

---

## 4. Geçişi yapan yapı

Eşiği geçiren dönüşüme literatürde **superboost** adı verilir: sıradan bir
Lorentz boostu gibi iki çerçeveyi bağlar, ancak bağladığı çerçevelerden biri
ışık hızının ötesinde durduğundan metriğin imzasını da çevirir. Bu dönüşüm
birbirinden bağımsız iki parçanın çarpımına ayrılır:

$$M(V) = D \cdot B(c^2/V), \qquad V > c$$

- $D$, hiçbir parametreye bağlı olmayan sabit bir matristir ve imza değişimini
 tek başına yapar. İki kez uygulanınca başa döner.
- $B(c^2/V)$, sıradan bir subluminal Lorentz boostudur ve hız bilgisini taşıyan
 tek parça odur.

Çarpanda $V > c$ olduğundan $u = c^2/V$ değeri $c$'nin altında kalır, yani $B$
gerçekten subluminal bir boosttur. Bu ayrıştırma her $V$ değeri için geçerlidir,
çünkü

$$M(V)^T \eta' M(V) = -\eta$$

bağıntısı sağlanır ve imza değişiminin tamamı $D$'nin üzerinde kalır. $D$
matrisinin kendisi de şudur:

$$D = \begin{pmatrix} 0&0&0&1 \\ 0&0&1&0 \\ 0&1&0&0 \\ 1&0&0&0 \end{pmatrix}
\qquad\text{yani}\qquad (ct, x, y, z) \longmapsto (z, y, x, ct)$$

Doğrulanan özellikler:

| Özellik | Sonuç |
| --------------- | ---------------------------------------------------------- |
| İmza dönüşümü | $D^T \eta' D = -\eta$, yani $s'^2 = -s^2$ |
| Işık konisi | $s^2 = 0 \Rightarrow s'^2 = 0$, dört ayrı yönde doğrulandı |
| İnvolüsyon | $D^2 = I$, iki geçiş başa döndürür |
| Determinant | $+1$, parite bozulmaz |
| Grup | $\mathbb{Z}_2$ |
| $V$ bağımlılığı | Yok |

$D$, iki olay arasındaki aralığın **işaretini bütünüyle** ters çevirir. Metriğin
işaretinin böyle değişmesini ve bunun fiziksel sonuçlarını [10] ayrıca ele
almıştır; o çalışmada konu, göreliliğin farklı formülasyonlarında klasik bir imza
değişimi türü olarak incelenir ve kozmolojik sabitle ilişkilendirilir. Bu çalışmadaki
kullanım daha dardır: işaret çevrilmesi başlı başına bir konu olarak ele
alınmaz, yalnızca iki metrik arasındaki dönüşümün bir özelliği olarak ortaya
çıkar.

Tablonun ikinci satırındaki ışık konisi testi dört ışın üzerinde yapılmıştır:
$(1,1,0,0)$, $(1,0,1,0)$, $(1,0,0,1)$ ve
$(1, 1/\sqrt{3}, 1/\sqrt{3}, 1/\sqrt{3})$. Dördünde de $s'^2 = -s^2 = 0$ çıkar,
ve genel bir aralık için de $s'^2 = -s^2$ tam olarak sağlanmaktadır.

**Bu çarpanlama yenilik taşımaz.** Bir superboost'un, sonsuz hız limitindeki bir
çevirme ile dual hız $c^2/V$'ye ait sıradan bir boostun bileşkesi olduğunu [1]
belirtir, ve [2] bunu kendi eleştirisinin ikinci basamağı olarak kullanır.

Bu bölümün eklediği şey çarpanlamanın kendisi değil, onun üzerine kurulan üç
sonuçtur. Birincisi, model bu ayrıştırmayı baştan sona düzenleyici bir ilke
olarak kullanmaktadır. İkincisi, Bölüm 4.1'in tam taraması çevirme parçasının
seçilmiş değil **zorunlu** olduğunu göstermektedir. Üçüncüsü,
Bölüm 4.2 grup kapanmasındaki bozulmanın tamamının $B$ parçasından geldiğini
ortaya koyar.

### 4.1 Permütasyon taraması

$D$'nin bir seçim değil bir zorunluluk olduğunu göstermek için işaretli
permütasyon matrislerinin tamamı tek tek tarandı. Aday sayısı $4!$ permütasyon
ile $2^4$ işaret bileşiminin çarpımından çıkar, yani 384 matris denendi.

| Filtre | Kalan aday |
| ---------------------------------- | ---------- |
| Metrik testi $M^T \eta' M = -\eta$ | 96 |
| ve involüsyon ($M^2 = I$) | 12 |
| ve $\det = +1$ | 8 |

Elde kalan sekiz çözümün **tamamı** $ct$ eksenini tek bir uzay eksenine
göndermektedir. Yani "Bölge I'in zamanı Bölge II'nin uzayı olur" cümlesi bir
tercih değil, üç koşulun zorladığı tek sonuçtur.

**Sekiz çözüm arasındaki fark yalnızca eksenlerin nasıl etiketlendiği değildir.**
Sekizi, $ct$ yuvasına düşen **işarete** göre dörde dört ayrılır:

| Filtre | Aday | İleri ($+$) | Geri ($-$) |
| -------------- | ---- | ----------- | ---------- |
| Metrik testi | $96$ | $48$ | $48$ |
| ve involüsyon | $12$ | $6$ | $6$ |
| ve $\det = +1$ | $8$ | $4$ | $4$ |

Bölünme filtrenin **her** aşamasında yarı yarıya kalmaktadır, dolayısıyla üç
koşulu daha da sıkılaştırmak geri götüren dalı elemez. Dört geri dalın her biri
üç koşulu ayrı ayrı sağlar ve Bölge II'de atılan birim adımı Bölge I'in saatinde
$-1{,}0000$'a gönderir.

**İki aileyi birbirinden ne ayırır.** Yalnızca Bölge I'in zaman eksenini ters
çevirmek ayırmaz, çünkü bu işlem determinantı negatife düşürür ve grup
kapanmasını bozar, yani adayı kümenin dışına atar. Yalnızca Bölge II'nin ayırt
edilmiş eksenini çevirmek de aynı sebeple ayırmaz. Ayıran işlem **ikisini
birlikte çevirmektir**:

$$S = \mathrm{diag}(-1, +1, +1, -1)$$

$S$ sekiz çözümü yine sekiz çözüme gönderir ve bu sırada her birinin işaretini
ters çevirir. Determinantı bire eşittir ve **her iki metriği de bozmadan
bırakır**, yani bir geçişten istenen bütün koşulları sağlar. Ters çevirdiği
eksen çifti de tam olarak geçişin birbirine eşlediği çifttir: Bölge I'in zamanı
ile Bölge II'nin tek uzay yönü.

**Sonuç.** Yukarıda yazılan $D$ bu sekizden biridir ve parçacığı **ileri
gönderen** ailede yer alır. Çalışmanın sonucunu taşıyan hesaplar ise onun **geri
taşıyan** eşi olan $SD$ üzerinde tanımlıdır. $S$ sekizliyi kendi üzerine
gönderdiğinden $SD$ de sekizden biri olur ve üç koşulu eksiksiz sağlar. Hangi
ailenin kullanılacağını bu çalışma karara bağlamıştır; karar üç koşuldan çıkmaz.
İki aile arasında seçim yapan hiçbir nicelik bu çalışmada hesaplanmamıştır, ve
aileleri ayıran dönüşüm her iki metriği de bozmadan bıraktığından **seçimin
kaynağı geometri değildir**. Bölüm 7.4 aynı durumu başka bir yerde daha
göstermektedir: o çerçevede de metrik, ayrımın iki yakası arasında bir tercih
yapmamaktadır. Seçimi iki yerde de geometri dışında bir şey yapar.

### 4.1.1 Sözlük katsayısının ispatı

Çalışmanın merkezinde şu cümle durur: Bölge II'nin tek uzay ekseni, Bölge I'in
zaman eksenine karşılık gelir. Cümle bu hâliyle bırakılırsa "o eksende
ilerlemek zamanda yer değiştirmektir" ifadesi bir benzetmeden öteye geçmez.
Aşağıdaki iki sonuç ona sayı verir ve ikisi de sekiz geçişin **tamamı**
üzerinde ayrı ayrı denetlenmiştir.

**Katsayı tam olarak bire eşit çıkar.** Sekiz geçişin her birinde, zaman
koordinatını üreten satırın sıfırdan farklı **tek** bir girdisi bulunur; o girdi
Bölge II'nin ayırt edilmiş ekseni üzerinde durur ve büyüklüğü bire eşittir. Bu
yüzden o eksende alınan $s$ kadar yol, saatte **tam olarak** $s$ kadar fark
üretir ve hiçbir katsayıyla ölçeklenmez. Diğer üç eksenin aynı yuvaya katkısı ise
**tam olarak sıfır** çıkar, yani tümüyle o üç eksenin içinde kalan bir hareket
saati hiç oynatmaz. Sınanan değerler bunu doğrular:
$0{,}5 \to 0{,}5000$, $1 \to 1{,}0000$, $2 \to 2{,}0000$, $4 \to 4{,}0000$,
$7{,}25 \to 7{,}2500$.

**Yer değiştirmeler toplanır.** Dönüşüm doğrusal olduğundan, önce $s_1$ sonra
$s_2$ kadar gitmek ile $s_1 + s_2$ kadar birden gitmek saatte aynı farkı
vermektedir. Bu eşitlik sekiz geçişin ve dokuz bacak çiftinin tamamında, artığı
$10^{-12}$ altında kalacak biçimde sağlanmıştır. Aynı doğrusallıktan bir sonuç
daha çıkar: bir bacak ile onun tersi **tam olarak** sadeleşir, yani kapalı bir
Bölge II gezisi saati başladığı yere döndürür.

**İki işaret aynı miktarı taşır.** İleri ve geri aileden birer geçiş alınıp
ikisine de aynı mesafe verildiğinde, ürettikleri farklar eşit büyüklükte ama
ters işaretli çıkar. Öyleyse sözlük saatin **ne kadar** oynadığını sabitler,
**hangi yöne** oynadığını sabitlemez.

**Bu bölümün tek başına haklı çıkarmadığı adım.** Yukarıdaki sonuçların hepsi
Bölge II'de atılan adımlarla ilgilidir. Eşikten geçerken saçılma fazından okunan
gecikme ise bu adımlardan biri değildir. Dolayısıyla gecikmeyi Bölge II'deki yer
değiştirmeyle toplama işlemi bu sonuçtan çıkmaz, ayrı bir sonuç olarak kurulmalıdır.
Bölüm 4.1.2 o toplamı eşlenik değişkenler üzerinden türetmektedir. Ayrım bilerek
keskin tutulmuştur, çünkü bulanıklaştığında iki ayrı sonuçtan biri, yalnızca
yazılış biçimi yüzünden diğerinin doğal devamı gibi görünür.

### 4.1.2 Toplamanın tek fazdan türetimi

Koordinatlar için ispatlanan bir sözlük, eşlenik değişkenler için doğrudan
geçerli değildir. $x' = M x$ koordinat dönüşümü altında fazın $p_\mu x^\mu$
değişmezliği momentumları $p' = M^{-\mathsf{T}} p$ ile taşır ve genel bir $M$
için $M^{-\mathsf{T}} \neq M$'dir. Bu makalede kullanılan
$\mathrm{diag}(2,1,1,1)$ gibi bir ölçekleme bunu gösteren en kısa örnektir.
Dolayısıyla Bölüm 4.1.1'in katsayısı, momentum tarafında yeniden kurulmadan
kullanılamaz.

Sekiz aday için iki cebirsel olgu bunu kurar:

1. **İşaretli permütasyon matrisleri ortogonaldir**, yani $M^{\mathsf{T}} M = I$
 ve bu bağıntıdan $M^{-\mathsf{T}} = M$. Momentumlar koordinatlarla **aynı**
 matrisle taşınır.
2. **Aynı matrisler involüsyondur** ($M^2 = I$, Bölüm 4.1'in tarama
 koşullarından biri). Ortogonallikle birlikte bu $M = M^{-1} = M^{\mathsf{T}}$
 verir, yani $M$ **simetriktir**. O hâlde eşlenik değişkeni yöneten girdi,
 koordinatı yöneten girdinin devriğidir: iki katsayı yalnızca aynı büyüklükte
 değil, aynı **sayıdır**.

Bu iki olgu, taramanın zaten dayattığı koşulların sonucudur; toplanabilirlik
için yeni bir varsayım eklenmemiştir.

Asıl adım bundan sonra gelir. Bölge II'deki yer değiştirme, fazın dışında
tutulup sonradan eklenmez; doğrudan fazın **içine** yerleştirilmiştir. Saçılma
fazı $\varphi(\omega)$ taşıyan ve Bölge II'nin ayırt edilmiş ekseni boyunca $s$
kadar ilerleyen tek bir genliğin toplam fazı

$$\Phi(\omega) \;=\; \varphi(\omega) + \kappa(\omega)\, s,$$

ve [24]'ün kullandığı durağan faz koşulu çıkan paketin anını

$$t \;=\; \frac{\mathrm{d}\varphi}{\mathrm{d}\omega}
 \;+\; s\,\frac{\mathrm{d}\kappa}{\mathrm{d}\omega}$$

olarak verir. Böylece toplam, iki ayrı hesabın arasına elle konan bir varsayım
olmaktan çıkıp **tek** bir hesaptan okunan bir sonuca dönüşür. İkinci terimin
önündeki çarpan da bir seçim değil, hesaplanabilen bir türev olur.

Söz konusu türev de hesaplanmıştır. Eşlenik değişkeni üreten satırın sıfırdan
farklı tek bir girdisi bulunduğundan $\kappa$ yalnızca frekansla orantılı kalır,
ve bu eşitlikten

$$\left|\frac{\mathrm{d}\kappa}{\mathrm{d}\omega}\right| = 1$$

eşitliği sekiz geçişin tamamında **tam olarak** sağlanmaktadır. Bu makalede
kullanılan dönüşüm için değer $+1$ çıkar, ve işaret her dalda o dalın kendi zaman
işaretine eşit kalır. Yani koordinat sözlüğünün atadığı yön ile fazın ürettiği
yön aynı yöndür. Bu eşitlik bir kabul değildir, çünkü sekiz dalın hepsinde ayrı
ayrı hesaplanmıştır.

**Dispersiyon bağıntısı neden girmiyor.** Aynı katsayıya bir grup hızı
argümanıyla gitmek mümkün görünür, ama o yol kapalı kalır: $k/\sqrt{k^2+\mu}$
niceliği $\mu > 0$ için hiçbir sonlu $k$'de bire ulaşmaz. Hesaplanan değerler
$\mu = 1$ için $k = 1$'de $0{,}707106781$, $k = 10$'da $0{,}995037190$,
$k = 1000$'de $0{,}999999500$. Yukarıdaki birim katsayı bir hızın kütlesiz
limiti değildir; dönüşümün tam bir özelliğidir ve sonlu kütlede de geçerli kalır.
Ayrım önemlidir, çünkü bir asimptotik yaklaşım sonucu yalnızca yaklaşık kılardı.

### 4.1.3 Çerçeve değişimi

Sözlük lineer olduğundan, tek eksende kalan bir yolculuğun saatte ürettiği fark
yalnızca **net** yol miktarına bağlı kalır; gidilen yol ile eşit uzunlukta bir
dönüş tam olarak birbirini götürür (Bölüm 4.1.1). Yolculuğun iki bacağı arasında
**çerçeve** değişirse soru başkalaşır, çünkü katsayıyı bir matris verir ve o
matris çerçeve değişimiyle bileşke alır. Bölge II'nin metriğini bozmadan bırakan
iki tür çerçeve değişimi bulunur, ve ikisi birbirinden farklı davranır.

**Aynı işaretli eksenler arasındaki dönmeler hiçbir şey bırakmaz.** Üç aynı
işaretli ekseni birbirine döndüren bir dönme, ayırt edilmiş ekseni **yerinde
bırakır** ve dolayısıyla katsayıyı veren matris girdisine dokunmaz. Katsayı
incelenen bütün açılarda $1$ olarak kalır. Net yer değiştirmesi sıfır olan bir
rota, ne kadar dolambaçlı olursa olsun saati başladığı yere geri getirir, ve bu
sekiz geçişin hepsinde doğrulanmıştır. Yani **Bölge II'de dolaşmak tek başına
hiçbir şey kazandırmaz**. Bu olumsuz bir sonuçtur ve dolaşmanın kendiliğinden
zaman kazandıracağı beklentisini ortadan kaldırır.

**Ayırt edilmiş ekseni karıştıran hiperbolik dönme ise iz bırakır.** Ayırt
edilmiş ekseni aynı işaretli bir eksenle karıştıran dönüşüm de Bölge II'nin
metriğini bozmaz, ancak o ekseni yerinde bırakmaz: katsayıyı, dönüşümün
hızlılığının hiperbolik kosinüsüyle çarpar. İki bacağı böyle bir dönüşümle
ayrılan kapalı bir rota artık başladığı yere dönmez, geriye bir artık bırakır,
ve o artık hızlılık büyüdükçe sınırsız büyür. Katsayı hızlılığın
hiperbolik kosinüsüdür: $0{,}5$'te $1{,}127626$, $1$'de $1{,}543081$, $2$'de
$3{,}762196$. Hesaptan çıkan kalıntılar, $3$ birimlik gidiş dönüş için:
$-0{,}382878$, $-1{,}629242$, $-8{,}286587$. Kalıntının işareti negatiftir, yani
dönüş düz rotaya göre saati **geriye** taşır.

**Bu artığın ne olduğu ve neye mal olduğu.** Yukarıdaki hiperbolik kosinüs, Bölge
I'de sıradan bir Lorentz dönüşümünün bir zaman aralığına uyguladığı çarpanın
aynısıdır. Dolayısıyla artık, bilinen zaman genleşmesinin Bölge II'den görünen
hâli olur, yeni ve bağımsız bir etki değil. Hesap bunun karşılığını da verir:
sıfırdan farklı bir hızlılıkla bileşke alınan geçiş metrik bağıntısını korur,
yani kabul edilebilir ailenin dışına çıkmaz, ancak **iki kez uygulanınca başa
dönme özelliğini kaybeder**. Bölüm 4.1'in tarama koşullarından biri olan bu
özellik böyle bir bileşkede ortadan kalkar.

### 4.1.4 Yer değiştirmenin karşılığı

Bölge II'de yol almanın bir enerji karşılığı vardır. $\Delta$, dönüşün kalkıştan
ne kadar önce gerçekleştiğini, yani alınan yolun eşik mesafesini ne kadar
aştığını göstersin ($\Delta = s - s^\ast$, Bölüm 4.1.2'nin $2\tau - s$
özdeşliğinden).

**Düz bir yolun enerjisi.** Bölge II'nin geometrisi, ayırt edilmiş eksen boyunca
kaydırma altında değişmez. Bu yüzden o eksene eşlenik nicelik korunur ve düz bir
yolun uzunluğu hiç enerji istemez. Aynı işaretli eksenler arasındaki dönmeler de
enerji istemez. Ancak Bölüm 4.1.3'e göre bu iki işlemin hiçbiri saatte bir fark
üretmez.

**Çerçeve değiştirmenin enerjisi.** Saatte fark üreten tek işlem hiperbolik
dönmedir, ve o da parçacığın enerjisini kendi hızlılığının hiperbolik
kosinüsüyle çarpar. Hızlılık iki bağıntı arasından elenirse geriye hiçbir serbest
parametre içermeyen bir ilişki kalır:

$$\frac{\Delta E}{E} \;=\; \frac{\Delta}{s},$$

yani harcanan fazladan enerjinin oranı, kazanılan ek kaymanın yol uzunluğuna
bölünmesine eşit çıkar. İlişki kaymada **doğrusaldır**, üstel değil. Uzun bir
yol aynı kaymayı daha küçük bir enerji artışıyla verir: $10$ birimlik bir yolda
$2$ birim ek kayma enerjiyi yüzde $20$ artırır, $100$ birimlik bir yolda yüzde
$2$ artırır. $1000$ birimlik bir yolda enerjiyi yüzde $1$ artırmak $10$ birim ek
kayma getirir, enerjiyi ikiye katlamak ise $1000$ birim getirir.

### 4.2 Geniş formülasyonla karşılaştırma

Aynı problem [3]'te bağımsız ve çok daha geniş biçimde çözülmüştür. İki
formülasyon yan yana konursa:

| | Bu bölüm | [3] |
| ------------------ | ------------------------------ | ---------------------------------------------------------------------------------------------- |
| Ayrık parça | Tek involüsyon $D$, sabit | $\Lambda_{\inf}(\theta,\varphi)$, yöne bağlı aile |
| Üretilen grup | $\mathbb{Z}_2$ | Klein dörtlü grubu $\mathbb{Z}_2 \times \mathbb{Z}_2$ |
| Genişletilmiş grup | $\mathbb{Z}_2 \ltimes SO(1,3)$ | $\mathcal{L}_{\text{ext}}$ |
| Yön kovaryansı | Yok, $z$ ekseni sabit | Var, her yön eşdeğer bir genişletme verir |
| Değişen koordinat | Dört | İki, $t$ ve $n$ |
| Temsil kuramı | Yok | Genişletilmiş Poincaré grubunun bütün üniter indirgenemez temsilleri sınıflandırılmış |
| Dalga denklemleri | Yok | Casimir öz-değer probleminden türetilmiş, bilinen bütün denklemler artı yeni takyonik sınıflar |

Kapsam bakımından [3] bu bölümü içerir ve aşar. İki formülasyon **aynı grup
değildir**: $D$, [3]'ün genişletilmiş grubunda bulunmaz, çünkü içerdiği
$x \leftrightarrow y$ takasının üç boyuttaki determinantı $-1$'dir ve
dolayısıyla $SO(3)$ elemanı değildir.

Karşılaştırma şöyle yürür. $\theta = \varphi = 0$ ekseni için yön-bağımlı
involüsyon $t$ ile $z$'yi işaretli olarak takas eder. Aynı işlem
$\Lambda_{\inf}^2 = I$ bağıntısını da sağlar, yani o da bir involüsyondur, ama
yalnızca iki koordinata dokunur. $D$ ise dört koordinatı birden değiştirir.
Sonuç şudur: $D$, yön-bağımlı involüsyonun ürettiği genişletilmiş grup
$L_{\text{ext}}$ içinde yer almaz, ve iki yapı aynı ailenin iki üyesi değildir.

Bu bölüm tek bir şey ekler: grup kapanmasındaki bozulma hangi parçadan geliyor,
onu ayırır. Doğrulanan iki olgu şudur. $D^2 = I$ olduğundan
$\langle D \rangle = \mathbb{Z}_2$ kapalıdır. Buna karşılık $M(V)^2 \neq I$
çıkar, yani birleşik dönüşüm kapalı değildir; bu $V = 1{,}5c$, $2c$ ve $10c$
için ayrı ayrı gösterilmiştir. Sorun $D$'den değil $B$ katmanından gelmektedir,
ve ayrıştırıldığında iki parça da düzgündür: $D$ bir $\mathbb{Z}_2$ ayrık
simetrisi, $B$ ise $SO(1,3)$ içindedir. Elde edilen yapı
$\langle D \rangle \ltimes SO(1,3)$ biçiminde bir yarı-doğrudan çarpımdır, ve
kapanmanın bozulması $D B D^{-1}$ konjugasyonunun boost tipini korumamasından
çıkar. [3] sorunu bu biçimde ortaya koymaz, çünkü o çalışma baştan kapalı bir
grup kurmaktadır.

---

# Kısım II. Ara bölge

## 5. Ara bölgenin tipleri ve kalınlığı

Önceki iki bölüm Bölge I ile Bölge II'yi tarif etti. İkisinin arasında ne
olduğu ayrı bir sorudur, ve bu çalışma orayı kalınlıksız bir yüzey olarak değil
kendi başına bir **bölge** olarak ele almıştır. Bunun nedeni şudur: geçişin nasıl
olacağını iki uçtaki metrikler değil, aradaki bölgenin karakteri belirler.

Bu soru da kendi içinde birbirini belirlemeyen iki ayrı soruya bölünür:

- **Ara bölge neyden yapılmıştır?** Yani hangi imzayı taşır.
- **Ne kadar kalındır?** Sıfır kalınlıktan sınırsıza.

Bu çalışma tiplerden hiçbirini baştan seçmez. Hesap dört tip için ayrı ayrı
yürütülmüş, sonuçlar yan yana konmuştur. Hangi tipin gerçekleştiği modelin
içinden çıkmaz. Kalınlığın sonuca ne kattığı ise bu çalışmanın kapsamı
dışındadır; aşağıdaki hesap yalnızca tipe bağlı kalır.

### 5.1 Dört aday

**Ara bölge yok.** Bu ilk durumda iki bölge doğrudan birbirine değer ve aralarında
yalnızca bir yüzey kalır. O yüzeyde iki enine yön aynı anda karakter değiştirir,
yani metriğin rankı bir defada iki düşer.

**Kademeli yol** bu tek adımın alternatifini sunar: enine yönler aynı anda değil,
teker teker çevrilir. Yol $(1,3)$ imzasından $(2,2)$ imzasına, o imzadan da $(3,1)$
imzasına gider; her adımda yalnızca tek bir öz değer sıfırdan geçtiğinden rank da
yalnızca bir düşer. Aşağıdaki adaylardan ikincisi tam olarak bu yolun durağıdır.

**Kleinian, $(2,2)$.** Bu imzanın geometrisi ayrıca [35]'te ele alınmıştır. Bu ara bölge iki zaman ve iki uzay ekseni taşır, çünkü
enine yönlerden yalnızca biri karakter değiştirmiştir. Yukarıda anılan kademeli
yol da bu noktada durur.

**Öklid, $(4,0)$.** İmza değişimi literatürünün büyük bölümü [33] ve [34] ile
başlayan bu geçişi ele almaktadır. Bu adayda enine yönlerin hepsi karakter değiştirmiştir ve
bölgede hiç zaman yönü kalmamıştır.

**Dejenere katman.** Son aday, metriğin tersi bulunmayan bir tabakadır. Öteki üç
adaydan farklı olarak bu adayda bir imzadan söz edilemez, çünkü yayılımı yöneten
operatörün kendisi tanımsız kalır.

### 5.2 İçerideki modun davranışı

Enine dalga sayısının yönler arasında eşit paylaşıldığı durumda, ara bölge
içindeki normal dalga sayısının karesi

$$q_{\text{iç}}^2 = \frac{\omega^2}{c^2} - \left(1 + \frac{2n}{3}\right)k_T^2 - \mu$$

olur; bu ifadede $n$, imzası çevrilen yön sayısıdır. Öklid tipinde üç uzay
yönünün üçü de işaret değiştirdiğinden $n = 3$, Kleinian tipinde yalnızca biri
değiştiğinden $n = 1$ olur. İfade dışarıdaki
$\kappa^2 = \omega^2/c^2 - k_T^2 - \mu$ değerinden, çevrilen her yönün üçte iki
ağırlıkla düşülmesiyle çıkar.

**İç mod frekansa bağlıdır.** Bir ara bölgenin engel olup olmadığı yalnızca tipine
değil, gelen parçacığın frekansına da bağlıdır; sönme koşulu $q_{\text{iç}}^2<0$,
yani $\omega^2 < c^2\big[(1+\tfrac{2n}{3})k_T^2+\mu\big]$
koşuludur. Aşağıdaki sınıflandırma bu koşulun tiplere göre okunuşudur:

| Tip | $n$ | İç mod | Sönme koşulu |
| -------- | --- | --------- | ----------------------------------------- |
| Yok | $0$ | Yayılır | Yok; $q_{\text{iç}}^2=\kappa^2>0$ |
| Kleinian | $1$ | Yayılır | $\omega^2 < c^2(\tfrac{5}{3}k_T^2+\mu)$ |
| Öklid | $3$ | Söner | $\omega^2 < c^2(3k_T^2+\mu)$ |
| Dejenere | - | Yayılamaz | Her zaman |

Örneğin $\omega^2 = 2c^2(k_T^2+\mu)$ yüzeyinde, yani
$\mu = 1$, $k_T^2 = 4$ için $\kappa^2 = 5$ değerinde, Kleinian bölge
$q_{\text{iç}}^2 = +7/3$ ile yayılımlı, Öklid bölge
$q_{\text{iç}}^2 = -3$ ile söndürücü çıkar. Aynı ara bölge, frekansa göre iki
farklı davranış sergiler.

Kleinian bölgenin kendi başına bir engel **olmaması** dikkate değerdir: iki
zamanlı bir bölge, madde için otomatik olarak kapalı değildir.

---

## 6. Geometrinin izin verdiği geçiş

Eşik yüzeyinde sorulabilecek bir soru şudur: bir eğrinin teğeti yüzeyi geçerken
nedensel karakterini koruyor mu. Bu soruyu cevaplamak için iki metriğe bakmak
yeter, çünkü cevabı yalnızca aralarındaki farka bağlıdır:

$$v^T \eta' v - v^T \eta\, v = 2\,(v_1^2 + v_2^2) \;\geq\; 0$$

Sağ taraf bir kareler toplamı olduğundan fark hiçbir zaman negatif olamaz, ve
sonuç doğrudan çıkar:

> Bölge I'de zaman-benzeri olan **her** yön, Bölge II'de de zaman-benzeridir.

Bu kapsama tek yönlüdür, tersi doğru değildir: örneğin $(0,1,0,0)$ yönü Bölge
I'de uzay-benzeri, Bölge II'de ise zaman-benzeridir. Dolayısıyla Bölge II'nin
zaman-benzeri yönleri kesin olarak daha fazladır.

**Ayrımın önemi.** Eşikte bir eğriyi durduran nedensel bir engel **yoktur**;
teğeti karakterini koruyarak geçer. Bu, eğrinin teğetinin değil alanın bir
özelliği olan bir başka niceliğe ilişkin sonucun yerini almaz; ikisi ayrı
niceliklerdir.

Bu ayrım, Bölüm 7.4'te değinilen ilmek teoremiyle bu modelin uyumlu
kalabilmesinin nedenidir: o teorem geometrik eğriler hakkındadır, bu bölümün
sonucu da bir eğrinin nedensel karakteri hakkındadır.

---

# Kısım III. Karşı taraf

## 7. Bölge II'de zaman ve mekân

Bu bölüm üç soruyu sırayla cevaplar: Bölge II'de hangi nicelikler korunur, hangi
roller yer değiştirir, ve "yolculuk" sözcüğü o kurguda ne anlama gelir. Sonucu
taşıyan adım, o kurguda zamanın bir yönünün bulunmamasıdır.

### 7.1 Noether yükleri

Bölge II'nin Lagrangian'ı $L'$, dört koordinatın hiçbirine açıkça bağlı değildir.
Bu yüzden dört öteleme simetrisi taşır, ve her biri korunan bir yük verir:

- üç "enerji" bileşeni ($t_1, t_2, t_3$ ötelemeleri),
- tek "momentum" ($r$ ötelemesi).

Aynı Lagrangian üç zaman ekseni arasındaki $O(3)$ dönmeleri altında da değişmez
kalır. Bu simetriden üç korunan "zamansal açı momentumu" daha çıkar, ve bunlar Bölge
I'in uzaysal açı momentumunun aynasıdır.

### 7.2 Rollerin tersine dönmesi

Aşağıdaki tablo Bölüm 8.1'in sözlüğünün rol tarafıdır; koordinat karşılıkları
Bölüm 8.1'de, rollerin karşılaştırması ise bu bölümde durmaktadır.

| | Bölge I | Bölge II |
| ---------------------- | ---------------- | ----------------------------- |
| Serbest hareket | Uzayda, üç yönde | Üç zamanda serbestçe |
| Tek yönlü zorunluluk | Zamanda | Tek uzay ekseninde |
| $O(3)$ dönme simetrisi | Uzaysal | Zamansal |

### 7.3 Ayrım ve zorunluluk

Bölge II'de zamanın oku **yoktur**, çünkü ok ilgili boyutun **tek** olmasının
sonucudur. Üç boyutlu bir eksen kümesi uzay gibi davranır ve yön ayrımı ortadan
kalkar. Buna karşılık o kurguda bir **uzay ayrımı** doğar, çünkü tek olan eksen bu
kez uzay eksenidir.

Bu ifadenin iki kez daraltılması gerekir, ve bu iki daraltma çalışmanın
duruşunun tamamını verir.

**Birincisi.** Boyut sayısından çıkan şey **ayrımın varlığıdır**, ayrımın iki
yakasından hangisinin gelecek olduğu değil. Bir koridorun iki ucu olması, hangi
ucun ileri olduğunu vermez.

**İkincisi.** Ayrım metrikte durur, ama **etiket durmaz**, çünkü denklemler bir
yönü tercih etmez. Zamanda ileri giden her çözümün geriye giden bir eşi bulunur
ve ikisi de aynı denklemi sağlar. Bir yönün seçilmesi için denkleme fazladan bir
şey eklenmesi gerekirdi, ve böyle bir şey eklenmemiştir.

Bu hesaptan çıkan sonuç şudur: **bu çalışma zamanın zorunlu bir akışı olduğunu
varsaymaz.** Bölge I'de de varsaymaz, Bölge II'de de. Yönelim metriktedir,
zorunluluk hiçbir metrikte değildir; ok, denklemlerde bulunmadığı için başka bir
yere, duruma yazılmak zorundadır.

Bu ayrım bir iddia değil, bir hesaptır. Yönelebilirlik, bir birim vektörün yarım
tur döndürülmesinden çıkar; zorunluluk ise hesabın hiçbir adımına girmez. Bölge II'nin bu tartışmadaki yeri de dikkat çekicidir: Bölge II'de ayrımın kendisi
bulunmaz (Bölüm 7.4), dolayısıyla zamanın okunu duruma yazma imkânı da doğmaz.

**Kapsam dışı bırakılan.** Aynı sonuca varan felsefi tartışma ve literatürdeki
"zamansız" programların taraması bu alt bölümün dışındadır; sonucu
değiştirmezler.

### 7.4 Zaman yöneliminin yokluğu

Yukarıdaki ifade sezgisel kalır, ve bu alt bölüm onu kesinleştirmektedir. Bir
bölge tutarlı bir gelecek-geçmiş ayrımı ancak zaman-benzeri vektörler kümesi
**iki ayrı bileşene** düştüğünde taşır; yalnızca o durumda bileşenlerden birine
"gelecek", diğerine "geçmiş" denebilir. Bu koşulun
karşılığı da tek bir pozitif yön bulunmasıdır.

**Bölge I.** $v = (1,0,0,0)$ ve $-v = (-1,0,0,0)$ vektörlerinin ikisi de
zaman-benzeridir. Birini diğerine götüren $(x^0, x^1)$ düzlemindeki dönme

$$v(\theta) = (\cos\theta,\, \sin\theta,\, 0,\, 0), \qquad
 v(\theta)^T \eta\, v(\theta) = \cos 2\theta$$

verir; bu ifade $\theta = \pi/4$'te sıfırlanır ve sonra negatife geçer. Dönme
zaman-benzeri kümeden çıkar. Dolayısıyla iki uç aynı bileşende değildir ve
gelecek ile geçmiş iyi tanımlıdır.

**Bölge II.** Aynı dönme, $\eta' = \mathrm{diag}(+1,+1,+1,-1)$ ile

$$v(\theta)^T \eta'\, v(\theta) = \cos^2\theta + \sin^2\theta = 1$$

verir; aralık **hiç** değişmez ve daima pozitiftir. $\theta = \pi$'de
$v(\pi) = -v(0)$ olur. Yani bir zaman-benzeri vektör, zaman-benzeri kümeden hiç
çıkmadan kendi negatifine sürekli olarak taşınmıştır. Böyle bir taşıma varken
ikili bir etiketleme yapılamaz: gelecek ile geçmiş ayrımı **yoktur**.

**Ara bölge.** Bölüm 5.1'deki kademeli yolun geçtiği $(2,2)$ imzasında da durum
aynıdır; iki pozitif yön bulunması yeterlidir. Dolayısıyla yönelim, kademeli
yolun daha **ilk adımında** kaybolur, ikinci adımı beklemez.

| Bölge | Zaman yönü sayısı | Zaman-benzeri küme | Gelecek/geçmiş |
| ------------------ | ----------------- | ------------------ | -------------- |
| Bölge I, $(1,3)$ | 1 | İki bileşen | Var |
| Ara bölge, $(2,2)$ | 2 | Bağlantılı | Yok |
| Bölge II, $(3,1)$ | 3 | Bağlantılı | Yok |

Ok, entropiden değil, zaman yönü **sayısından** çıkar: bir yön varsa ok vardır,
birden çoksa yoktur.

**Literatürdeki karşılığı.** [9], imza değiştiren bir manifoldun geçiş
hiperyüzeyinde, her noktadan geçen ve zaman yönünü tersine çeviren kapalı
sözde-zaman-benzeri ilmekler bulunduğunu ispatlar. Vardıkları sonuç kelimesi
kelimesine bu çalışmadakiyle aynıdır: gelecek ve geçmiş yönlü vektörler arasında
tutarlı bir ayrım yapılamaz.

Yollar farklıdır. [9] sonucu geçiş hiperyüzeyinin geometrisinden, Lorentzian
bölgede global hiperboliklik varsayarak elde eder; bu çalışmada ise yalnızca zaman
yönlerinin sayısından, hiperyüzey hakkında hiçbir varsayım yapmadan çıkar.

İki çekince var. Birincisi, [9]'un hipotezlerini bu modelin geçişi
**sağlamaz**. O kurguda bir taraf Riemann imzalıdır ve dejenerelik transvers radikal
tipindedir; bu çalışmanın doğrudan geçişinde ise rank iki düşer. Ortak olan
sonuçtur, ispat değildir. Buna karşılık Bölüm 5.1'in kademeli yolu her adımda
rank-1 dejenereliğe sahiptir, yani [8] ve [9]'un geometrik çerçevesine bu özellikten
bakıldığından daha yakındır.

İkincisi, [9]'un ilmekleri alışıldık anlamda kapalı zaman-benzeri eğriler
**değildir**: kesişim noktalarında hareket yönünün aynı olması gerekmez. Bu
nedenle sonuç, maddenin zamanda geriye gitmesi biçiminde okunamaz. [9] kendi
fiziksel yorumunu da verir: hiperyüzey yakınındaki bir gözlemciye böyle bir
ilmek, iki ayrı noktada bir parçacık-karşıparçacık çiftinin yaratılması gibi
görünebilir.

Bölüm 6 bunun neden bir çelişki olmadığını verir: iki metrik arasındaki fark
bir kareler toplamıdır, dolayısıyla Bölge I'de zaman-benzeri olan her yön
Bölge II'de de zaman-benzeridir. Yani eşikte bir eğriyi durduran nedensel
engel yoktur, ve [9]'un yüzeyden geçen ilmekleri bu çerçeveyle çelişmez.

**Bir itiraz.** [12], iki zamanlı dinamikte olasılık korunumu bir kez
dayatılınca fazladan zaman ekseninin ne kadar görünür kaldığını ölçmektedir. Klasik
$1+2$ boyutta Newton'un ikinci yasası tam olarak integre edilebilir ve her
başlangıç koşulu için **etkin tek zamanlı** bir evrim verir. Kuantum tarafta ise
düzey aralıkları, toplam süre ve $\hbar$ içeren genelleştirilmiş bir belirsizlik
bağıntısı çıkar. Bu, üç zamanlı Bölge II'nin dışarıdan bakıldığında tek zamanlı
görünebileceği anlamına gelir.

[12] bu çalışmanın formülasyonundan bir noktada ayrılır: o formülasyonda evrim üniter ve olasılık
koruyan bir yapı ister. Yukarıdaki hesap ise Bölge II'de o talebin dayandığı
yapıyı bulmamaktadır. Yine de bu itiraz açık bir soru olarak durur; model onu
kendi lehine kapatmamıştır.

### 7.5 Yolculuğun tanımı

Parçacığın Bölge II'de yapabilecekleri iki bağımsız etiketle tükenir.

**Hangi yüzden çıktığı.** Ara bölgenin iki yüzü vardır ve parçacık girdiği
yüzden geri dönebilir, karşı yüzden çıkabilir, ya da hiç çıkmayabilir.

**Enerji vektörünün ne kadar döndüğü.** Bölüm 10.3'te gösterildiği gibi
yönelimin kendisi Bölge II'de ayar fazlalığıdır; fiziksel olan tek şey giriş ile
çıkış arasındaki **bağıl** dönmedir. Üç sınıf ayırt edilir: dönme yok, kısmi
dönme ve tam ters çevirme.

İki etiket birlikte üç çarpı üç, yani dokuz hücrelik bir tablo verir. Bölüm 11
bu hücrelerin her birinin Bölge I'de nasıl göründüğünü tek tek hesaplamıştır.

## 8. Bölge II'de hareket ve yönelim

İmza değişimini yapan $D$ matrisinde hız hiç geçmez. Bu bir eksiklik değildir.
Aşağıdaki türetim, hız kavramının bu hesapta zaten gerekmediğini göstermektedir.

Bölge I'de bile hız temel bir büyüklük değildir, dispersiyon bağıntısından
türetilir:

$$\omega(k) = c\sqrt{k^2 + \mu}, \qquad
 v_{\text{faz}} = \frac{\omega}{k}, \qquad
 v_{\text{grup}} = \frac{d\omega}{dk}, \qquad
 v_{\text{faz}} \cdot v_{\text{grup}} = c^2$$

Bölge II'de de aynı türev alınabilir, ancak orada zamanın üç bileşeni
bulunduğundan türev bir sayı değil, üç bileşenli bir gradyan verir:

$$\frac{\partial \kappa}{\partial (t_1, t_2, t_3)} \;=\;
\left(\frac{\partial \kappa}{\partial t_1},\;
 \frac{\partial \kappa}{\partial t_2},\;
 \frac{\partial \kappa}{\partial t_3}\right)$$

**Sonuç:** Hız Bölge II'de bir sayı olmaktan çıkar ve bir yönelime dönüşür. "Ne
kadar hızlı" sorusunun yerini "hangi yönelimde" sorusu alır. Hız bilgisini
taşıyan tek yer $M(V)$ çarpanındaki $B$ boostudur, yani üç zamanlı uzaydaki
yönelim.

Hızın kendisi de geçiş altında $v' = c^2/v$ kuralıyla dönüşür; aynı kural
takyon kuramında da çıkar [36]. Bu kuralın sabit
noktası ışık hızıdır, ve kural subluminal ile superluminal bölgeleri birbirine
eşler.

### 8.1 Dört eksende hareketin tanımı

Yukarıdaki sonuç üç zaman ekseni hakkındadır ve dördüncü ekseni kapsamaz. Bu alt
bölüm dördünü birden tanımlar, çünkü çalışmanın sonucunu taşıyan eksen tam da
dördüncüsüdür.

Bölge II'nin dört yuvasının her biri için üç şey hesaplanır: kendi bölgesindeki
karakteri, involüsyon altında Bölge I'in hangi yuvasına düştüğü ve o yuvada bir
birim adımın Bölge I saatinde ne ürettiği.

| Bölge II'deki yuva | Bölge II'deki karakteri | Düştüğü yuva, Bölge I | O yuvanın karakteri | Bir birim adımın saatte karşılığı |
| ---------------- | --------------- | -------------------- | ------------------- | --------------------------------- |
| $0$ | zaman | $3$ | uzay | **tam olarak $0$** |
| $1$ | zaman | $2$ | uzay | **tam olarak $0$** |
| $2$ | zaman | $1$ | uzay | **tam olarak $0$** |
| $3$ | uzay | $0$ | zaman | **tam olarak $1$** |

Tablo iki sonucu birden verir. Dört yuvanın dördü de eşikte karakter değiştirir,
yani hiçbiri türünü korumaz. Buna karşılık **hareket serbestliği yuva yuva
aynı kalır**: parçacık Bölge II'nin üç zamanında serbestçe hareket eder, ve o üç
zamanın taşıdığı Bölge I uzay yönlerinde de aynı serbestliği bulur. Aynı biçimde,
Bölge II'nin tek uzay ekseninde yön seçemez, ve onun taşıdığı Bölge I zamanında da
seçemez.

**Üç zaman ekseninde hareket.** Bu eksenlerde hareket serbesttir, ama iki nedenle
sonucu taşıyamaz. Birincisi, tümüyle bu üç eksenin içinde kalan bir yer
değiştirme Bölge I saatinde **tam olarak sıfır** üretir; üç eksenin her birinde
birim adım tek tek denenmiş ve üçünün de izdüşümü sıfır çıkmıştır. İkincisi, bu
üç eksen arasındaki $O(3)$ simetrisi bir ayar fazlalığıdır, yani enerji
vektörünün yönü Bölge II'de fiziksel değildir ve yalnızca uzunluğu fizikseldir. Aynı
nedenle kapalı bir gezinti de hiçbir iz bırakmaz, çünkü bu eksenler arasındaki
dönmeler ayırt edilmiş ekseni yerinde bırakır ve sözlüğün katsayısına dokunmaz.

Bu yüzden yukarıdaki "hız yönelime dönüşür" sonucu bu üç eksene aittir: payda üç
boyutlu olduğu için türev skaler değil gradyandır ve "ne kadar hızlı" sorusu
"hangi yönelimde" sorusuna dönüşür.

**Tek uzay ekseninde hareket.** Dördüncü eksende durum başkadır. O eksen tek
olduğundan türev bir vektör değil **skaler** çıkar, dolayısıyla hız Bölge II'de
yönelime dönüşmez: sıradan anlamda bir yayılma hızı tanımlıdır ve bir üst sınırı
vardır. Hesaplanan büyüklük

$$\left|\frac{\mathrm{d}q}{\mathrm{d}\kappa}\right| = \frac{c\,\kappa}{\sqrt{\kappa^2+\mu}}$$

sınanan bütün dalga sayılarında $c$'nin altındadır ve $\kappa \to \infty$
limitinde $c$'ye gider. Yani **Bölge II'nin de bir hız sınırı vardır** ve o
sınır bu tarafın sınırıyla aynı sayıdır. Durgun bir cisim için
$q(0) = mc^2/\hbar \neq 0$'dır, yani o eksende duran bir cismin bile sıfırdan
farklı bir eşlenik niceliği vardır.

Çalışmanın sonucunu taşıyan eksen de budur. Parçacık bu eksende $s$ kadar
ilerlerse Bölge I'in saati tam $s$ kadar kayar, çünkü katsayı bire eşittir ve
diğer üç eksenin aynı yuvaya katkısı tam olarak sıfır kalır. Bunun ispatını
Bölüm 4.1.1 verir; işaretin nereden geldiğini ve o eksende geri dönülememesinin
bu sonuçla nasıl bir arada durduğunu ise Bölüm 1.2 yazar.

**Dört eksenin özeti.** Parçacık üç eksende serbestçe hareket eder, ama o üç
eksen saate hiçbir şey taşımaz. Kalan tek eksende hareket serbest değildir, ama
saate taşınan her şey bu dengesizlikten gelir. Yolculuğun tamamı bu dengesizlik üzerine
kuruludur.

### 8.2 Dispersiyon ve grup hızı

Düzlem dalga koşulu:

$$k_1^2 + k_2^2 + k_3^2 - \frac{q^2}{c^2} + \mu = 0
 \quad\Longrightarrow\quad q = \pm\, c\sqrt{k^2 + \mu}$$

$q$ her zaman reeldir: $r$ ekseninde salınım vardır, sönümlenme yoktur.

Durgun cisim ($k = 0$) için $q = mc^2/\hbar \neq 0$. Yani Bölge II'de duran bir cisim
bile $r$ ekseninde ilerler, Bölge I'deki "duran cisim zamanda ilerler"
ifadesinin tam aynasıdır.

Grup hızı:

$$\frac{dq}{dk} = \frac{c\,\hbar k}{\sqrt{c^2m^2 + \hbar^2k^2}}
 \qquad (\text{vektör, } k \text{ doğrultusunda})$$

$|dq/dk| < c$ ve $k \to \infty$ limitinde $c$'ye yaklaşır. Karşı tarafta da bir
hız sınırı vardır; yalnızca hangi eksende olduğu değişmiştir. Sınır davranışı
her iki tarafta aynıdır: $\kappa \to 0$'da sıfır, $\kappa \to \infty$'da $c$.

### 8.3 Durgunluğun tek yörüngeye indirgenmesi

Bölge II'de durgun bir cismin dört-momentumu $p' = (mc\,\mathbf{s},\, 0)$
biçimindedir, ve ilk bakışta her $\mathbf{s}$ seçimi ayrı bir dünya çizgisi
demeti veriyormuş gibi görünür. Hesap bunun böyle olmadığını gösterir:

- Kütle kabuğu koşulu $s_1^2 + s_2^2 + s_3^2 = 1$ verir, yani
 $\mathbf{s} \in S^2$.
- $\eta' = \mathrm{diag}(+1,+1,+1,-1)$ içinde ilk üç slot **aynı** işaretlidir;
 bu üç slotu koruyan grup $O(3)$'tür.
- $O(3)$ hem metriği korur hem de durgunluğu bozmaz (doğrulandı).
- $O(3)$, $S^2$ üzerinde geçişli (transitif) etki eder: herhangi bir
 $\mathbf{s}$'yi herhangi bir $\mathbf{s}'$ye götüren bir dönme her zaman
 vardır.

**Sonuç:** Bütün $\mathbf{s}$ seçimleri aynı yörünge üzerinde durur. Yani ortada
sonsuz sayıda fiziksel durum yoktur; **tek bir durumu yazmanın sonsuz yolu**
vardır, ve bu da bir ayar fazlalığıdır.

$$\text{Stabilizatör} = O(2), \qquad \text{Yörünge uzayı} = O(3)/O(2) = S^2$$

**Öncelik.** Fazladan bir zaman boyutunun ayar simetrisiyle elenmesini mekanizma
olarak ilk kuran [40] olmuştur, ve mekanizmanın olgun hâlini [11] vermiştir. O çalışmada $Sp(2,\mathbb{R})$ ayar simetrisi altında
tek zamanlı sistemler, aynı iki zamanlı sistemin farklı ayar sabitlemeleri olarak
ortaya çıkar, ve aynı mekanizma alan teorisine, etkileşimlere ve ayar arka
planlarına kadar götürülmüştür. Yukarıdaki $O(3)$ fazlalığı da aynı türdendir,
yalnızca çok daha dardır. Bu bölümün katkısı mekanizmanın kendisi değil, onun bu
modeldeki durgunluk sorusuna uygulanmasıdır.

# Kısım IV. Üç bölgede madde

## 9. Parçacığın iki okuması

Bu çalışmanın ele aldığı olay şudur: kütleli bir parçacık eşiği geçer, Bölge II'de bir süre kalır ve geri döner. Öyleyse "parçacık" sözcüğü küçük bir
ayrıntı değil, bütün hesabın dayanağıdır, ve ne anlama geldiği baştan
sabitlenmelidir.

Bunu yapmak zorunludur, çünkü Bölge II'de parçacık kavramı olağan anlamıyla
bulunmaz. O kavram üç yapıya dayanır [38], [41]: pozitif ile negatif frekansın
birbirinden ayrılması, alttan sınırlı bir Hamiltonyen ve Poincaré grubunun
üniter bir temsili. Bölüm 7 bu üçünün de Bölge II'de bulunmadığını
göstermektedir. Bu yüzden Bölge I'de doğal görünen bir tanımı Bölge II'ye
taşımak serbest değildir.

Benimsenen çözüm, tek bir tanım aramak yerine **iki okumayı birlikte
yürütmektir**. Bu, yalnızca bu bölümün değil, çalışmanın tamamının yöntemidir:
parçacık hakkında bir sonuç veren her bölüm, o sonucu iki kez yazar.

**Dalga okuması.** Bu okumada parçacık, kütleli reel skaler alanın dar bir mod
demetidir. Enine dalga sayısı üzerinde Gauss ağırlıklı bir paket alınır,

$$A(k) = \exp\!\left[-\frac{(k - k_0)^2}{2\sigma^2}\right]$$

ve fiziksel yoğunluk bu genliğin karesidir. Yoğunluğun genişliği bu nedenle
genliğinkinden $\sqrt{2}$ kat dardır; aşağıdaki bütün nicelikler yoğunluk
üzerinden tanımlanmıştır.

**Parçacık okuması.** İkinci okumada parçacık, konumu, momentumu ve bir yörüngesi
olan bir cisimdir. Sorulan sorular "nereye gitti", "ne zaman döndü", "hangi
yönelimi kazandı" biçimini alır, ve cevapları tek tek sayılardır.

İki okuma birbirinin basitleştirilmiş hâli değildir; ikisi de kendi içinde
eksiksizdir, ve bu çalışma ikisini yan yana yürütmektedir. Uyuştukları yerde çalışma
uyuşmanın nedenini de yazar. Ayrıldıkları yerde ise ayrılmayı **gizlemez, sonuç
olarak kaydeder**, çünkü bu modelde ikisinin ayrıldığı yerler tam olarak Bölge II'nin kendine özgü davrandığı yerlerdir.

İkisini birbirine bağlayan şey aşağıda kurulan sözlüktür, ve o sözlüğün nerede
geçerli kaldığı hesaplanabilir bir sorudur.

### 9.1 Sözlük

| Nokta cisim dili | Dalga paketi karşılığı |
| -------------------------------- | ----------------------------------------- |
| Konum | Yoğunluğun birinci momenti |
| Momentum | Ortalama dalga sayısı $\langle k \rangle$ |
| Parçacığın var olması | Paketin toplam ağırlığı |
| Parçacığın tekliği | Paketin dar olması, $\sigma \ll k_0$ |
| Parçacığın aynı parçacık kalması | Momentlerin geçiş boyunca korunması |

Bu bölümün asıl sonucunu son satır taşır.

### 9.2 Nokta cisim koşulu

Bir paketin ağırlık merkezi, eşikten geçerken kayabilir, ve bu kayma paket
genişliğiyle **doğru orantılı** gitmektedir: genişlik yarıya indiğinde kayma da
yarıya iner, ve bu ardışık genişliklerde sayısal olarak doğrulanmıştır.

Orantının sonucu şudur: kaymanın bir alt sınırı yoktur. Yeterince dar bir paket
seçilirse merkez kayması istenildiği kadar küçük tutulabilir.

> Nokta cisim dili yaklaşık bir kolaylık değil, dar paket limitinde **tam**
> geçerli kalır. Geçen cisim, giden cismin aynısıdır; yalnızca paket dar tutulduğu
> sürece.

Gidiş dönüş anlatısının tamamı bu sonuca dayanır. Paket dar tutulmadığında
"parçacık gitti ve geri döndü" cümlesi anlamını yitirir, çünkü dönen şey gidenden
farklı bir mod dağılımı olur.

### 9.3 Dar paketin iki kaybı

Dar paket limiti merkezi korur, ama her şeyi korumaz. İki kayıp kalır.

Birincisi, geçen ağırlığın oranı hiçbir zaman bire ulaşmaz. Dar bir pakette de
bu oran birden küçük kalır, yani dönen paketin toplam ağırlığı gidenin altındadır.
Bu bir konum ya da momentum kaybı değildir; kaybolan şey doğrudan parçacığın
Bölge II'de bulunma ağırlığıdır.

İkincisi, paketin genişliği de sabit kalmaz; dar limitte kendi büyüklüğünün binde
biri mertebesinde değişebilir. Yani genişlik merkez kadar temiz korunmaz, ama
merkeze göre ikinci mertebeden küçük kalır.

### 9.4 Bu tanımın sınırları

Üç çekince vardır.

Paket bu hesapta tek bir enine dalga sayısı değişkeni üzerinde durur. Gerçek
bir üç boyutlu paket için aynı hesap üç değişkende yapılmalıdır; sonucun
niteliksel olarak değişmesi beklenmez, ancak gösterilmemiştir.

Hesap doğrusaldır ve alanın kendisiyle etkileşimi yoktur. Etkileşen bir alanda
paketin geçiş sırasında dağılması ayrı bir olgudur.

Nokta cisim okuması yalnızca Bölge I'de tanımlıdır. Bölge II'de "konum" kavramı
tek uzay ekseni olan $r$ üzerine daralır ve üç zaman yönü boyunca hiçbir
karşılığı kalmaz.
Bölge II'de hareketin ne anlama geldiğini bu nedenle Bölüm 8 karşılar. Konumun
kendisi ise Bölge II'de de tanımlı değildir; Bölüm 13 bunu reddeder.

Sorunun bir katmanı daha vardır. Üç boyutlu bir elektron bulutunun bu tek
eksende neye karşılık geldiği, bu çalışmanın sormadığı bir sorudur. Bağıl
koordinatın üç zaman bir uzay imzasındaki dinamiği literatürde de kurulmuş
değildir. Bu çalışma o dinamiği icat etmemiştir; soru açık kalmıştır.

---

# Kısım V. Gidiş dönüşün sonucu

Bu kısım geçişin ayrı bir sorusunu ele alır: taşınan durumun hangi nicelikleri
değişmeden çıktığı.

---

## 10. Korunan nicelikler

Önceki bölüm geçişin neyi değiştirdiğini saydı. Bu bölüm ters soruyu sorar:
geçiş neye **dokunamaz**.

$D$ bir involüsyondur, dolayısıyla iki kez uygulandığında dört-momentumun dört
bileşeni de başlangıç değerine döner (Bölüm 10.2). Aşağıdaki alt bölümler bunun
ne anlama geldiğini açar: bir gidiş dönüşte enerji, momentumun büyüklüğü ve
kütle tam olarak korunur; değişen tek şey yöndür.

### 10.1 Enerji vektörünün karşılığı

Bölge II'nin üç enerji bileşeni soyut bir nesne değildir; Bölge I'de tanınan bir
şeyin başka adıdır. $D$ dört-momentuma uygulandığında

$$(E/c,\; p_x,\; p_y,\; p_z) \longmapsto (p_z,\; p_y,\; p_x,\; E/c)$$

olur. Yani:

> Bölge II'nin **enerji vektörü** Bölge I'in **üç-momentumudur**; Bölge II'nin tek
> **momentumu** ise Bölge I'in **enerjisidir**.

Bu, iki niceliğin sayısal olarak eşit olması değil, aynı nesne olmasıdır. Enerji
vektörünün uzunluğu Bölge I'in momentumunun büyüklüğüne tam olarak eşittir ve bu
doğrulanmıştır.

### 10.2 Dönüşümün kayıpsızlığı

$D$ bir involüsyon olduğundan, iki kez uygulandığında dört-momentumun dört
bileşeni de **tam olarak** başlangıç değerine döner ve sayısal artık sıfır kalır.

Bu sonucun önemi şudur: modelin bildirdiği bütün kayıplar dönüşümden değil,
iki bölgenin birleştiği **yüzeyden** gelmektedir. Cebir hiçbir şey kaybetmez,
karşılığını eklem koşulları belirler.

### 10.3 Bölge II'de uzunluğun fizikselliği

Bölüm 8'de gösterildiği gibi üç zaman ekseni arasında bir $O(3)$ simetrisi
bulunmaktadır. Bu simetri bir ayar fazlalığı olduğundan enerji vektörünün **yönü**
Bölge II'de fiziksel değildir, ve fiziksel olan tek nicelik uzunluğu olarak kalır.

Üç ayrı dönme açısı da aynı sonucu vermiştir: dönme, enerji vektörünün
uzunluğunu, Bölge II'nin momentumunu ve değişmezi değiştirmez.

### 10.4 Dönmenin bıraktığı iz

Söz konusu dönme Bölge II'de fiziksel bir fark yaratmasa da, Bölge I'de iz
bırakmaktadır. Parçacık Bölge II'de bir $O(3)$ dönmesi geçirip geri döndüğünde
şu tablo ortaya çıkar:

| Nicelik | Sonuç |
| --------------------------------- | ------------------ |
| Bölge I'in enerjisi | Tam olarak korunur |
| Bölge I'in momentumunun büyüklüğü | Tam olarak korunur |
| Kütle | Tam olarak korunur |
| Bölge I'in momentumunun **yönü** | **Değişir** |

Son satırdaki sapmanın büyüklüğü de hesaplanmıştır:

| Bölge II'deki dönme açısı | Bölge I'de sapma (radyan) |
| ------------------------- | ------------------------- |
| $0{,}3$ | $0{,}289$ |
| $1{,}0$ | $0{,}961$ |
| $2{,}5$ | $2{,}308$ |

> Bölge II'de **hiçbir fiziksel içeriği olmayan** bir ayar dönmesi, bu tarafta
> **gözlenebilir bir sapma** olarak görünür. Parçacık aynı enerjiyle, aynı
> süratle, aynı kütleyle, ama farklı bir yöne bakarak geri döner.

Bu madde, Bölüm 11'de kurulan sözlüğün en somut maddesidir, ve gidiş dönüşün
hiçbir enerji harcamadan yapabildiği tek şeyi adlandırır: yön değiştirmek.

**Çekince.** Yukarıdaki sonuç dönüşüm düzeyinde kalır ve yüzeyin mod
süzgecinden bağımsızdır. Parçacığın Bölge II'de gerçekten bir $O(3)$ dönmesi
geçirip geçirmediği bu hesabın konusu değildir. Hesabın verdiği tek şey şudur:
geçirirse Bölge I'de ne görünür.

**Kalan çekince.** Bu döküm doğrusal ve durağan bir saçılma kurgusuna dayanır.

### 10.5 Yükün yeniden dağılması

Yüklü bir durum için döküme bir kalem daha girmektedir. Yük yoğunluğu dört akımın
zaman bileşenidir, ve geçiş yakın tarafın zaman eksenini Bölge II'nin bir uzay
ekseni üzerine taşır. Dolayısıyla yakın tarafta yoğunluk olarak okunan nicelik
Bölge II'de bir **akım bileşenine** dönüşür, akımlardan biri de yoğunluğa. Sayıyla
söylemek gerekirse, yakın tarafta $(3{,}0,\, 0,\, 0,\, 0{,}5)$ yazılan dört akım
Bölge II'de $(0{,}5,\, 0,\, 0,\, 3{,}0)$ olarak görünür.

Bu yeniden dağılım bir kayıp değildir. Geçiş dört akımı bütün hâlinde taşımakta
ve bileşenlerinden hiçbirini kaybetmemektedir; değişen tek şey, yoğunluk ile akım
arasındaki bölünmedir. Dört akımın değişmez karesi de geçişin dayattığı genel
işarete kadar korunur. Yine de bu nedenle "Bölge II'de ne kadar yük var" sorusu,
yakın tarafta sorulan soruyla aynı soru sayılmaz.

---

# Kısım VI. Çekirdek dönüşüm

Bu kısım dönüşümün girdi tarafını, yani Bölge II'deki yönelimin ne anlama
geldiğini tanımlar; sonra girdiyi dönüş olayının dört koordinatına bağlar; ve
yedi adımı tek yerde yazar.

## 11. Yönelim sözlüğü

Bu bölüm Bölüm 7.5'in dokuz hücresini tek tek bu tarafa çevirir, sonra o
dokuzun gerçekte kaç tane olduğunu yeniden sayar.

### 11.1 Her hücrede korunan nicelikler

Dokuz hücrenin **tamamında** Bölge I'in enerjisi ve sürati tam olarak
korunmaktadır, ve sayısal artık sıfır çıkar. Öyleyse hücreleri birbirinden ayıran
tek nicelik, Bölge I'de momentumun yönüdür:

| Bağıl dönme | Bölge I'de sapma (radyan) |
| ----------- | ------------------------- |
| Yok | $0$ |
| Kısmi | $0{,}961$ |
| Tam ters | $2{,}601$ |

### 11.2 Sözlük

| Bölge II'de olan | Bu tarafta görünen | Sıradan bir olaydan ayırt edilebilir mi |
| ---------------------------------- | ---------------------- | --------------------------------------- |
| Giriş yüzünden döner, dönme yok | Yansıma | Hayır |
| Giriş yüzünden döner, kısmi dönme | Esnek geri saçılma | Hayır |
| Giriş yüzünden döner, ters çevirme | Tam geri saçılma | Hayır |
| Karşı yüzden çıkar, dönme yok | Gecikmeli geçiş | Hayır |
| Karşı yüzden çıkar, kısmi dönme | **Bedelsiz sapma** | **Evet** |
| Karşı yüzden çıkar, ters çevirme | **Bedelsiz tam sapma** | **Evet** |
| Hiç çıkmaz, dönme yok | Soğurulma | Hayır |
| Hiç çıkmaz, kısmi dönme | Soğurulma | Hayır |
| Hiç çıkmaz, ters çevirme | Soğurulma | Hayır |

### 11.3 Çıkış yüzünü belirleyen nicelik

Bölüm 7.5'in iki etiketinden biri çıkış yüzüydü, ve o bölümde bağımsız bir etiket
gibi ele alınmıştı. Oysa bağımsız değildir.

**Kurulum.** Ara bölgeyi geçmek, Bölge II'nin tek uzay ekseni boyunca hareket
etmek demektir. Parçacığın hangi yüzden çıktığını da o eksendeki dalga sayısının
**işareti** belirlemektedir.

**Kütle kabuğu büyüklüğü sabitler, işareti serbest bırakır.** Dispersiyon
bağıntısı $q$ ile $-q$ arasında ayrım yapmaz, ve üç ayrı dalga sayısında her iki
dalın da bağıntıyı sıfır artıkla sağladığı denetlenmiştir.

**Yönelim de büyüklüğü belirler, dalı belirlemez.** Enerji vektörünün yönünü
uzunluğunu değiştirmeden çevirmek geçiş dalga sayısına dokunmaz; bu üç ayrı
uzunlukta doğrulanmıştır.

**Bölge II'nin dalı seçecek bir aracı yoktur.** Bir dalı seçmek, dışarı giden
dalga koşulu koymak demektir; o koşul bir zaman yönelimi gerektirir, ve Bölge
II'de zaman yönelimi bulunmaz (Bölüm 7).

**Geriye kalan tek belirleyici Bölge I'in enerjisidir.** Bölüm 10.1 Bölge II'nin
tek momentumunun Bölge I'in enerjisi olduğunu göstermişti, ve geçiş dalga sayısı
tam olarak o yuvada durur. Dolayısıyla:

> "Hangi yüzden çıktı" sorusu ile "enerjisinin işareti ne" sorusu **aynı
> sorudur**.

Karşı yüzden dönüş, başka bir yerden gelmiş gibi değil, **negatif enerjiyle**
gelmiş gibi görünür.

Bu sonuç Bölüm 11.2'nin tablosunu iki yerden değiştirmektedir. Birincisi, çıkış
yüzü ile yönelim bağımsız etiketler değildir; ikisi de aynı vektörün
parçalarıdır. İkincisi, "hiç çıkmaz" satırının yanına üçüncü bir okuma girer:
negatif enerjili bir varış, sıradan bir gözlemciye parçacık yerine
karşıparçacık gibi görünebilir, ve bu da literatürdeki çift yaratımı okumasıyla
aynı yere düşer.

İkinci okumanın adı ve önceliği de vardır. **Yeniden yorumlama ilkesi** tam
olarak şunu vermektedir: negatif enerjiyle zamanda geriye giden bir çözüm,
pozitif enerjiyle ileri giden bir karşıparçacıktan ayırt edilemez. İlke takyonlar
bağlamında [25]'te formüle edilmiş, [19] ise onu alan kuramına taşımıştır.
Bu bölümün hesabı o ilkeyi kurmaz, yalnızca doğrular. Tek katkısı şudur: ayırt
edilemezlik **hangi nicelikten** çıkıyor, onu gösterir. Söz konusu işaret, çıkış
yüzünü belirleyen vektörün aynı bileşenidir. Dolayısıyla "hangi yüz" ile
"hangi işaret" bağımsız iki soru sayılmaz. Ayırt edilemezliğin nerede kırıldığını [37]
derlemektedir, ve o soru bu çalışmanın kapsamı dışında kalmaktadır.

**Çekince.** Bu bölümde hesaplanan şey, dispersiyon bağıntısının iki dalı da
kabul ettiği ve yönelim yönünün geçiş dalga sayısını değiştirmediğidir. "Bölge II dal seçemez" ifadesi bir hesap değil, zaman yöneliminin yokluğundan çıkan
bir muhakemedir; dayanağını Bölüm 7 hesaplamıştır.

### 11.4 Dönmenin nicelenmesi

İki yüz arasındaki bağıl dönme hakkında iki saf beklenti kurulabilir, ve ikisi
de bir varsayıma dayanır. **Ayar okuması** iki yüzü simetrik sayar ve dönmeyi
özdeşliğe indirger, sapma öngörmez. **Bilgisizlik okuması** ise Bölge II'de
hiçbir yönü ayrıcalıklı saymaz ve sapmanın küre üzerinde düzgün dağıldığını
varsayar. Oysa modelin içinde, hiçbir varsayım gerektirmeyen üçüncü bir cevap
zaten durmaktadır.

**Yapı.** Bölüm 4.1'de bütün filtreleri geçen sekiz matris kalmıştı, ve
aralarındaki tek fark uzay eksenlerinin etiketlenmesiydi. Ara bölgenin **her yüzü
bu sekizden birini gerçekler**. İki yüz aynı matrisi gerçeklerse gidiş dönüşün
bileşkesi özdeşlik olur; farklı matrisleri gerçeklerse bileşke belirli bir dönme
verir.

Dolayısıyla dönme ne serbest bir parametredir ne de düzgün dağılmıştır. Değerini,
sekiz matrisin bileşkelerinin oluşturduğu **sonlu bir kümeden** alır.

**Hesap.** Altmış dört eşleşmenin 32'si Bölge I'in enerjisini korumakta, ve
bunların 24'ü momentumu döndürmektedir. Gelen momentum $(1,2,3)$ için ortaya
çıkan sapma tayfı şudur:

$$\theta \in \{0{,}\ 0{,}873{,}\ 1{,}281\}$$

Tayf üç ayrı değerden oluşur, sürekli bir aralıktan değil.

**Sonuç.**

| Okuma | Durumu |
| ----------------------------------- | ------------------------------------- |
| Ayar okuması, sapma yok | Özel hâl: iki yüz eşleştiğinde çıkar |
| Bilgisizlik okuması, düzgün dağılım | **Dışlanır**: süreklilik mevcut değil |
| Nicelenmiş dönme | Modelin kendi yapısından çıkar |

Ayar okuması bir rakip değil, tayfın sıfır elemanıdır. Bilgisizlik okuması ise
elenir, çünkü sürekli bir sapma dağılımı bu yapıda bulunmaz.

> Model, gelişigüzel bir sapma değil, **belirli açılarda** sapma öngörür. Bu,
> iki okumanın ikisinden de keskin bir iddiadır ve sınanması da daha kolaydır:
> sapma açılarının dağılımı sürekli değil, ayrık çıkmalıdır.

**Bu mekanizma türünün öncülü.** Ayrık sapmanın sürekli geri tepen bir hedef
olmadan çıkması bu çalışmanın icadı değildir; fizikte bir yüzyıllık öncülü
vardır. [18] X-ışınlarının kristalden yansımasını, girişim yasalarına hiç
başvurmadan, momentumun **kuantumlar hâlinde** aktarılması varsayımıyla türetir
ve [42]'nin yasasını bu yolla elde eder. Ayrıklığı üreten şey kristalde örgünün
periyodikliği, bu kurguda ise çıkış yüzlerinin sonlu kümesidir; ikisinde de ayrıklık
saçıcının sürekli olmayan bir simetri yapısından gelir, dalga girişiminden
gelmez.

**Çekince.** Tayftaki açılar evrensel değildir; gelen parçacığın hangi
doğrultuda geldiğine bağlıdır. Eksen boyunca gelen bir parçacık için farklı bir
tayf çıkar. Evrensel olan, tayfın **sonlu** olmasıdır, çünkü bileşkeler sonlu
bir grup oluşturur.

İkinci çekince: hangi yüzün hangi matrisi gerçeklediğini belirleyen mekanizma bu
çalışmada kurulmamıştır. Tayfın kendisi hesaplanmıştır, tayf üzerindeki olasılık
dağılımı hesaplanmamıştır.

### 11.5 İşaret sorusunun yeniden okunması

Aşağıdaki tartışma bu sözlüğün bir parçasıdır ve sonucu tersine dönmüştür. Eski
formülasyonda iki bölgedeki okların bağıl işareti prensip olarak ölçülemezdi,
çünkü eşik geçirgen değildi. Eşik geçirgen olduğuna göre o gerekçe düşmüştür ve
bağıl işaret ilke olarak ölçülebilir kalır.

Ayrımın kendisi de sınanmıştır. $D$ ile $-D$ arasındaki fark denendiğinde her iki
işaretin de $\det = +1$ ve $M^2 = I$ koşullarını sağladığı çıkmıştır, yani bu
koşullar ikisini birbirinden ayıramaz. Buna karşılık Bölüm 7'nin bulgusu işaretin
anlamını netleştirmektedir:

1. Her iki bölgede birer ok seçimi vardır (Bölge I'de zaman, Bölge II'de uzay).
2. $D$ Bölge I'in ok eksenini Bölge II'nin ok eksenine gönderir, seçimler
 bağımsız değildir, biri diğerini belirler.
3. Fiziksel olarak anlamlı olan tek büyüklük **bağıl işarettir**: iki okun
 hizalanması. Tek başına hiçbiri anlamlı değildir.
4. Eşik geçirgen olduğuna göre iki bölge arasında bir kanal vardır; bağıl işaret
 bu nedenle prensip olarak ölçülebilir kalır. Ölçümü yapacak nicelik Bölüm
 11.3'te belirlenmiştir: parçacığın hangi yüzden döndüğü, yani enerjisinin
 işareti.

**Sonuç:** İşaret belirsizliği denklemlerin düzeyinde yapısaldır, ölçümün
düzeyinde değil. Bölge I tarafta da zamanın oku denklemlerden türetilmez,
Newton, Maxwell ve Schrödinger denklemlerinin hepsi $T$-simetriktir [32]; ok
başlangıç koşulundan gelir.

### 11.6 Bölge II'de hareketin tanımı

Çıkış yüzü Bölüm 11.3'te Bölge I'in enerjisinin işareti olarak belirlendi, ve
bu belirleme parçacığın ara bölgede **ne yaptığına** bağlanmamıştı. Bu bölüm o
bağlantıyı kurar.

Bölge II'nin dört ekseninin karakterini Bölüm 8.1 vermişti. O bölümdeki tabloya göre
bir durum iki parçadan oluşur: üç zaman uzayındaki bir enerji vektörü ve tek uzay
ekseni boyunca bir dalga sayısı. Parçacığın yapabileceği şey de yalnızca ikiye
iner:

1. **Geçiş yönünde yer değiştirme.** Tek uzay ekseni boyunca ilerlemek. Ara
 bölgeyi kat etmek budur.
2. **Enerji vektörünün dönmesi.** Üç zaman düzleminden birinde bir açı süpürmek.
 Dönme vektörün uzunluğunu korur ve bu denetlenmiştir.

Birinci hareket bir yolculuktur, ikincisi bir yönelimdir. Sorulacak soru şudur:
çıkış yüzü bu iki hareketten hangisini görür.

### 11.7 Çıkış yüzünün körlüğü

Enerji vektörü üç zaman düzleminden herhangi birinde, herhangi bir açıyla
döndürülse de geçiş dalga sayısı değişmez. Bunun nedeni açıktır: kütle kabuğu o
dalga sayısının büyüklüğünü yalnızca vektörün **uzunluğundan** belirler, dönme
ise uzunluğa dokunmaz.

Üç düzlemin her birinde yirmi dört açı ve üç farklı vektör uzunluğu tarandığında,
geçiş dalga sayısındaki en büyük değişim $10^{-9}$'un altında kalmıştır.
Dolayısıyla çıkış yüzü, parçacığın Bölge II'de izlediği yola hiçbir bağımlılık taşımaz. Yüz, ara
bölgenin
içinde değil, yüzeylerde belirlenmektedir.

### 11.8 İçerideki yolun izi

İçeride süpürülen açı süreklidir. Dönme açısı serbest bir parametre olduğundan,
birbirine ne kadar yakın iki değer seçilirse seçilsin iki farklı yol doğmaktadır;
örneğin çeyrek turluk bir dönme $1{,}1102$ radyan süpürmektedir. Buna karşılık
Bölge I'e ulaşan sapma, Bölüm 11.4'ün nicelenmiş tayfının bir elemanıdır, ve
momentum $(1,2,3)$ için o tayf yalnızca **üç** değer taşır.

Sürekli bir küme bu adımda üç elemanlı bir kümeye düşmektedir. Bu düşüş, Bölüm
1.9'un yedinci maddesinin somut karşılığıdır: Bölge II'deki yönelim, dönüş
olayının koordinatlarına ancak bir kısmıyla ulaşır. Kaybolan şey, parçacığın Bölge II'de izlediği yolun kendisidir. Geriye yalnızca o yolun iki ucu arasındaki
bileşke dönmenin nicelenmiş izi kalır.

**Bağlantının özeti.**

| Gözlenebilir | Neye bağlı | Nerede belirlenir |
| ------------ | ------------------------------------------------------ | --------------------- |
| Çıkış yüzü | Hiçbir içeri hareketini | Yüzeylerde |
| Sapma | Yolun yalnızca bileşkesini, nicelenmiş olarak | Yüzeylerde |

---

## 12. Koordinat sözlüğü

Sorulan soru şudur: parçacık Bölge II'de dört koordinattan birinde hareket eder
ya da yönelirse, bunun Bölge I'deki karşılığı ne olur. Bu bölüm o sözlüğü kurar,
Bölüm 13 ise sözlüğü kullanarak dönüş olayını hesaplamaktadır.

### 12.1 Sözlüğün bu bölümde kullanılan biçimi

Dört yuvanın karakterini, hangi yuvaya indiğini ve bir birim adımın Bölge I'in
saatinde ne ürettiğini Bölüm 8.1 tablo hâlinde vermişti, ve bu bölüm o tabloyu
tekrarlamaz. Sözlükten yalnızca iki sonuç gerekmektedir. Birincisi, dört yuvanın
dördü de eşikte karakter değiştirir. İkincisi, buna karşın hareket serbestliği
yuva yuva aynı kalmaktadır. Parçacık Bölge II'nin üç zamanında ve o üç zamanın
taşıdığı Bölge I uzay yönlerinde serbestçe hareket etmektedir. Buna karşılık Bölge II'nin tek uzay ekseninde ve onun taşıdığı Bölge I zamanında yön seçemez.

Sözlüğün en sıkı ifadesi de bu iki sonuçtan çıkar: tek yönlü koordinat iki bölgede **ayna
yerlerde** durmaktadır. Bölge I'in zamanı ile Bölge II'nin tek uzay ekseni aynı
koordinattır, ve ikisinde de yön seçilemez.

"Tek yönlü" ifadesinin içinde iki ayrı iddia gizlidir, yani yönlendirilebilirlik
ile ilerleme zorunluluğu. Bölüm 7.3 bu ikisini birbirinden ayırmakta ve yalnızca
birincisinin hesaplandığını göstermektedir.

Bu ifadenin Bölüm 1.2'nin sonucuyla nasıl bir arada durduğu da o bölümde yazılıdır.
Yön seçilemez, çünkü cisim o eksende geri dönemez. Dönüş anının işareti ise
cismin ilerleme yönünden değil, hangi geçiş dönüşümünün kullanıldığından gelir.
İki ifade farklı niceliklerden söz eder ve birbiriyle çelişmez.

### 12.2 Yönelimin gözlenemezliği

Üç zaman ekseni arasındaki $O(3)$ simetrisi bir ayar fazlalığıdır, ve bunun
sonucu şudur: Bölge II'de enerji vektörünün **yönü** fiziksel değildir, yalnızca
**uzunluğu** fizikseldir. Vektör döndürülebilir, ancak o dönmenin Bölge II'de
gözlenebilir bir karşılığı bulunmamaktadır.

Vektörün uzunluğunu ise kütle kabuğu sabitlemektedir. Uzunluk parçacığın enerjisi
ve kütlesiyle belirlenir, ve üç zaman düzleminden herhangi birinde döndürmek onu
değiştirmez; artık $10^{-16}$ mertebesinde kalır.

> Parçacık Bölge II'de **yönünü seçebilir, uzunluğunu seçemez.**

### 12.3 Üç zamandaki hareketin etkisi

Çekirdek sorunun en can alıcı yeri bu sorudur.

**Doğrudan yol kapalı kalır.** Bunu Bölüm 8.1'in tablosu vermektedir: üç zamanın
her birinde bir birim adımın Bölge I'in saatindeki karşılığı tam olarak sıfırdır,
tek uzay ekseninde ise tam olarak birdir. Yani "Bölge II'de zamanda ilerledim, Bölge I'de
zamanda kaydım" cümlesini involüsyonun kendisi **desteklemez**, çünkü involüsyon
o hareketi Bölge I'in uzayına gönderir.

> Bölge I'in zaman ekseninde bir konumu işaret eden şey, Bölge II'nin üç
> zamanındaki bir hareket değil, tek uzay ekseninde alınan mesafedir.

---

## 13. Bölge I'de ölçülebilenler

Bu çalışmanın aradığı ölçüm Bölge II'nin içinde değil, Bölge I'de durmaktadır.
Deney parçacığı gönderir, parçacık geri döner, ve Bölge I'in saati dönüş anını
verir; iddia da bu tek okumaya dayanmıştır. Bu bölümün sorusu bu yüzden
"içerisi görülebilir mi" değil, **dönüşte Bölge I'de ne okunabildiğidir**.
Bölge II'nin içi ise doğrudan ölçüme kapalı kalmıştır, ve bölümün geri kalanı
bu kapalılığın nereden geldiğini kurar.

**Konumlandırma reddedilir.** Uzaysal türden bir dörtlü momentum, öz durumları
nedenselliğe saygı gösteren bir konum işlemcisini kabul etmemektedir [38], [39]. Dolayısıyla
parçacığın Bölge II'de nerede olduğunu söyleyen bir durum bulunmaz, ve bu çalışma
da böyle bir durum sağlamamaktadır. Yazılan cümle bir hesap değil, bir kayıttır.

Bu sonuç iddiayı düşürmez, çünkü iddia zaten Bölge I'de okunan dönüş anına
dayanmaktadır. Düşen şey **tanı gücüdür**: bir geçişin olduğu ve dönüşün hangi
ana düştüğü ölçülebilir, ancak parçacığın Bölge II'de izlediği yol
ölçülemez.

---

## 14. Sonucun beş adımı

Önceki bölümler sonuca giden adımları ayrı ayrı kurdu. Bu bölüm adımları tek bir
yerde birleştirir ve her birinin hangi bölümde kurulduğunu göstermektedir. Yeni
bir hesap içermez.

**Beş adım.**

1. **İmza değişimini yapan dönüşüm zorunludur.** $384$ işaretli permütasyon
 matrisi taranır; metrik bağıntısı $96$'ya, involüsyon $12$'ye, birim
 determinant $8$'e indirir. Hiçbir aday baştan seçilmez (Bölüm 4.1).
2. **Ayakta kalan sekizin hepsi Bölge I'in zamanını Bölge II'nin tek uzay
 eksenine gönderir.** Ortak eksen taramanın sonucudur, kurgunun girdisi
 değildir (Bölüm 4.1).
3. **Sözlüğün katsayısı tam olarak birdir.** Zaman koordinatını üreten satırın
 tek bir sıfırdan farklı girdisi vardır, o girdi ayırt edilmiş eksendedir ve
 büyüklüğü birdir. Bölge II'nin diğer üç ekseninin bu yuvaya katkısı tam olarak
 sıfırdır (Bölüm 4.1.1).
4. **Eşlenik değişkenler için de birdir.** İşaretli permütasyon ortogonaldir,
 dolayısıyla momentumlar koordinatlarla aynı matrisle taşınır; aynı matris
 involüsyon olduğundan simetriktir, dolayısıyla eşlenik katsayı koordinat
 katsayısının aynı sayısıdır. $|\mathrm{d}\kappa/\mathrm{d}\omega| = 1$ sekiz
 geçişin tamamında tamdır ve dispersiyon bağıntısına bağlı değildir (Bölüm
 4.1.2).
5. **Gecikme ile yer değiştirme toplanır.** Yer değiştirme fazın içine
 konduğunda varış anı tek bir durağan faz koşulundan okunur; toplama iki
 hesabın arasına yerleştirilen bir varsayım değil, bir sonuçtur (Bölüm 4.1.2).

> Bu beş adımın verdiği kapalı ifade şudur: dönüş anı Bölge I'in saatinde
> $2\tau - s$ konumuna düşer; burada $s$ Bölge II'de alınan mesafe, $\tau$ ise
> tek bir geçişin bedelidir ve katsayısı tam olarak bir çıkar. Bu bölümün
> kurduğu şey bu toplamın kendisidir; $\tau$'yu hangi mekanizmanın ne kadar
> büyük verdiği ayrı bir sorudur.

**İddianın sınırı.** Bölüm 1.5'te kaydedilen engeller geçerliliğini korur.
İşaretin seçilebilirliği açık bir soru olarak durmaktadır (Bölüm 7.4). Beş
adımın kendisi bu boşluklardan bağımsız olarak doğrudur.

---

# Kısım VII. Yöntem ve deney

Bu kısım çalışmanın nasıl doğrulandığını ve hangi düzenekle sınanabileceğini
yazar.

Kısım iki bölümden oluşur. Birincisi yöntemi kurmaktadır: her sayısal ve cebirsel
iddia bir doğrulamaya karşılık gelir, makale ile kod birbirine isimle değil çalışma
zamanında bağlanır, ve doğrulama kendini de denetler. İkincisi ise neyin
gösterilmediğini yazar, ve çekirdek ölçümün düzeneğini şart şart belirtir.

## 15. Yöntem ve doğrulama

Bu çalışmadaki her sayısal ve cebirsel iddia, C++ ile kurulmuş bir doğrulamaya
karşılık gelir. Doğrulamalar genel amaçlı kütüphaneler hâlinde durmakta, ve
üzerlerinde bir test takımı çalışmaktadır.

**Makale ile kod birbirine atıf yapmaz.** Makale hiçbir dosya ya da sınıf adı anmaz;
kod da hiçbir bölüm ya da kaynak numarası anmaz. Gerekçe bakımdır: birbirine
isimle bağlanan iki çalışmadan biri yeniden düzenlendiğinde diğerindeki atıflar
sessizce çürür ve çürüdükleri fark edilmez. Bunun yerine bağ, aşağıdaki
denetimlerde olduğu gibi **çalışma zamanında kurulur**: doğrulama makale dosyasını okur ve
aradığını o dosyada bulamazsa koşuyu düşürür.

**Sayısal güvenilirlik.** Modelin matrislerinin büyük kısmı tamsayı girdi taşır
($0, +1, -1$), ve bu girdiler ikilik tabanda tam temsil edildiğinden permütasyon,
involüsyon ve determinant testleri cebirsel hesapla birebir aynı sonucu
vermektedir. Buna karşılık boost, dönme, faz türevi ve mod toplamı hesaplarında
irrasyonel ya da yakınsak nicelikler doğar; oralarda açıkça belirtilen bir
tolerans kullanılmıştır.

**Doğrulama disiplini.** Hiçbir kontrol, sonucunu hesaplamadan bildiremez. Bu
kurala uymayan kontrolleri bir tarama tek tek bulmuş, ve her birinin yerine ya
gerçek bir hesap koymuş ya da onu tümüyle atmıştır. Atılanlar fiziksel değil,
yorum niteliğindeydi.

Elle yapılan iki hesap, parite argümanı ve boyut sayımı, cebirsel kontrolde
**yanlış çıktı** ve düzeltildi. Modelin bugünkü hâli bu düzeltmeleri içerir.

### 15.1 Üç denetim

Aşağıdaki üç denetim makale dosyasını okumakta, ve dosyayı bulamazsa koşuyu
düşürmektedir. Bu son davranış zorunludur: girdisi yokken sessizce geçen bir
kontrol, hiçbir şey yapmadığı hâlde başarı bildirir.

**Sayıların makaleye ulaşması.** Birinci denetim, test takımı çıktısında üç ile altı
ondalık basamakla basılmış her sayıyı toplamakta ve makalede aramaktadır. Ham
çıktısı bir eksik listesi değil, incelenecek adaylar listesidir, çünkü makale
virgül ve $10^{-12}$ yazarken çıktı nokta ve $e$-gösterimi kullanır. Dört tur
boyunca makaleye ulaşmayan sonuçlar tek tek ortaya çıktı ve hepsi çalışmaya girdi;
geriye kalanların tamamı girdi ya da ara değerdir.

**Kaynakça kapsaması.** İkinci denetim iki yönü birden aramaktadır. Çalışmadaki her
atıf numarasının listede bir karşılığı, listedeki her künyenin de çalışmada en az
bir atfı bulunmalıdır. İki yön de gereklidir, çünkü liste iki ayrı biçimde
çürümektedir. Numaralar
kayarsa bir atıf listenin sonunu aşar; bir pasaj çıkarılırsa künye sahipsiz kalır.
Denetimin ağırlığı da şundan gelir: bir bölüm silindiğinde dosyada ondan sonra
gelen her şey onunla birlikte gider, ve kaynakça dosyanın son öğesidir. Bu
çalışmada tam olarak bu oldu, ve hiçbir sayısal denetim onu görmedi; çünkü bir
atıf numarası hiçbir hesabın ürettiği bir sayı değildir. Künyenin kimliğini de
basılı rakam değil listedeki sırası taşır.

**Varsayım sicili.** Üçüncü denetim, varsayım ileri süren her pasajı bulmakta ve
her birinin aşağıdaki sicilde bir hükümle yer almasını şart koşmaktadır. Sicilin
kapsamadığı bir pasaj koşuyu düşürür. Sicilin kendisi kodda değil makalede durur:
doğrulamanın içinde tek bir bölüm numarası geçmez, hem hüküm sözlüğünü hem sicili
bu bölümden okur.

Üç denetim de bozularak sınanmıştır. Çalışmaya karşılıksız bir atıf eklendi, kaynakça
listesi silindi, bir künyeye giden tek atıf başka yere çevrildi, ve sicilde yeri
olmayan bir varsayım cümlesi eklendi. Koşu her seferinde düşmüş, bozma geri
alındığında yeniden geçmiştir.

### 15.2 Hüküm sözlüğü ve sicil

**Hüküm sözlüğü.** Kullanılabilecek hükümler bunlardır ve doğrulama sicilde
bunların dışında bir hüküm bulursa koşuyu düşürür.

| Hüküm | Anlamı |
| ---------------------------- | --------------------------------------------------------------- |
| türetildi | Sonradan başka bir şeyden çıkar |
| iki yönlü hesaplandı | Hesap iki seçeneğin ikisini de verir, seçim hiçbir şey taşımaz |
| geçersiz kılındı | Sonraki bir sonuç ona olan ihtiyacı ortadan kaldırmıştır |
| başka kurguya ait | Karşılaştırılan bir formülasyona aittir, bu çalışmaya değil |
| ilan edilmiş sınırlama | Korunmuştur ve sonucu çalışmada yazılıdır |
| varsayım değil, söz ediliyor | Varsayım yapmak yerine varsayımlardan söz eden pasaj |

Yalnızca inanılan bir varsayım için hüküm yoktur; denetimin varlık nedeni budur.
Son satır, taramanın bir kelimeden niyet okuyamamasının sonucudur ve gereklidir:
varsayımı eleştiren bir cümle ile varsayan bir cümle aynı kelimeyi taşımaktadır.

**Sicil.**

| Bölüm | Ne varsayılıyor | Hüküm | Nerede kapandı |
| ----- | -------------------------------------------------------------------------- | ---------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------- |
| 4.1.2 | Faz gecikmesi ile Bölge II yer değiştirmesinin toplanabilmesi | türetildi | Aynı bölüm, tek bir durağan faz koşulundan |
| 7.4 | Global hiperbolikliğin sağlanması | başka kurguya ait | Karşılaştırılan formülasyonun ihtiyacıdır; bu çalışmanın sonucu yalnızca zaman yönlerinin sayısından çıkar |
| 11.4 | Yok; pasaj kendi kurduğu iki saf beklentiyi kaldırmak için anar | varsayım değil, söz ediliyor | Onları kaldıran bölümün kendisi |
| 15.1 | Yok; pasaj üç denetimin ne aradığını anlatır | varsayım değil, söz ediliyor | Denetimlerin kendisi, ki bu bölüm onları belgeler |
| 15.2 | Yok; pasaj bu sicili ve taradığı kelimeleri anlatır | varsayım değil, söz ediliyor | Sicilin kendisi, ki bu bölüm onu belgeler |
| 7.3 | Denklem düzeyinde ve durum düzeyinde tek yönlülüğün aynı iddia olması | başka kurguya ait | İki okuma o bölümde ayrılır ve yalnızca ikincisi savunulur |

Sicil $6$ kalem taşır. Kalemler üç türden birine girer: türetilmiş olanlar,
karşılaştırılan bir formülasyona ait olanlar, ve hiç varsayım yapmayan pasajlar.

Bir bozma denetimin kendisini de sınar: makaleye sicilde yeri olmayan bir varsayım
cümlesi eklendiğinde koşu iki kontrolle birden düşmüş, cümle geri alındığında
tekrar geçmiştir.

---

## 16. İtirazlar ve yanıtlar

Bu bölüm çekirdek zincire yöneltilebilecek itirazları tek yerde toplamaktadır.
Zincir beş halkadan oluşur: **geçiş**, **çevrim**, **doyum**, **işaret** ve
**ölçülebilirlik**. Aşağıdaki her madde bu halkalardan birini hedef alır, ve
her maddenin sonunda bu çalışmanın verebildiği yanıt durur. Yanıt veremediği
maddeler de aynı biçimde yazılmıştır.

### 16.1 İmza değişimi bir işaret uzlaşımı olabilir

**İtiraz.** $\eta = \mathrm{diag}(+1,-1,-1,-1)$ ile
$\eta' = \mathrm{diag}(+1,+1,+1,-1)$, eksenler ters sırayla okunduğunda
birbirinin negatifidir. Metriğin genel işareti ise tensör düzeyinde bir
uzlaşımdır. Dolayısıyla Bölge II, Bölge I'in ters işaretle yazılmış hâli
olabilir, ve $D$ fiziksel bir dönüşüm değil bir yeniden adlandırma olabilir. Bu
okumada Bölüm 4.1.1'in katsayı sonucu bir hesap değil bir tanımdır, çünkü
işaretli bir permütasyon matrisinin sıfırdan farklı girdisi zaten $\pm 1$ olmak
zorundadır. İtirazı [2] kurmaktadır.

**Vurduğu halka.** Geçiş ve çevrim, ikisi birden.

**Yanıt.** İtiraz sayıya dökülebilir bir ölçüt taşımaktadır, ve bu çalışma o
ölçütü hesaplamaktadır. Köşegen bir metrik için ölçüt artı işaretlerinin
sayısıdır: iki metrik, artı sayıları ya eşitse ya da birbirinin tümleyeni ise
aynı geometriyi ters uzlaşımla yazar. Hesap üç satır vermektedir.

| Metrik | Artı sayısı | Tümleyeni | Uzlaşım değişimi mi |
| ------------------- | ----------- | --------- | ------------------- |
| Bölge I, $(1,3)$ | $1$ | $3$ | ölçüt bu satıra göre |
| Bölge II, $(3,1)$ | $3$ | $1$ | **evet** |
| Ara bölge, $(2,2)$ | $2$ | $2$ | **hayır** |

İkinci satır itirazı doğrulamaktadır: Bölge I ile Bölge II arasındaki doğrudan
takas bir uzlaşım değişimidir, ve bu çalışma onu geçersiz kılan bir hesap
taşımamaktadır. Üçüncü satır ise yanıtı vermektedir. Geçiş bu modelde doğrudan
kurulmamış, araya kendi imzası olan üçüncü bir bölge konmuştur (Bölüm 5).
$(2,2)$ imzası kendi tümleyenine eşit olduğundan $(1,3)$'ün ters uzlaşımı
değildir, ve $(1,3)$'ten $(2,2)$'ye geçiş bir yeniden adlandırma sayılmaz.
Bölüm 5.1 bu yolun her adımında yalnızca tek bir öz-değerin sıfırlandığını
göstermektedir.

Yanıtın sınırı da açıktır. Hesap, kademeli yolun bir uzlaşım değişimi
olmadığını verir; $D$'nin uçtan uca tek adımda uygulanışı için aynı şeyi
vermez. Zincir ancak ara bölgeden geçen okumada ayakta kalır, ve doğrudan
okumada itiraz **açık kalmaktadır**. Bu, zincirin en zayıf halkasıdır.

### 16.2 İmza değişimi sınırsız parçacık üretebilir

**İtiraz.** İmza değiştiren bir arka planda tanımlı bir kuantum alanı, geçiş
sırasında sınırsız sayıda parçacık ve sınırsız toplam enerji üretebilir. O
zaman geçişin bedeli küçük bir olasılık değil, eşiği ayakta bırakmayan bir geri
tepkidir.

**Vurduğu halka.** Geçiş.

**Yanıt.** Bu çalışmada böyle bir hesap **yoktur**. [14] ile [15] tam olarak bu
soruya bakan bir çerçeve sunar, ve o çerçevede karışım yalnızca Öklidyen
bölgenin toplam konformal genişliğine bağlı çıkmaktadır. Bu çalışma tek
parçacığın geçişini konu alır ve geri tepkiyi hesaba katmaz. İtiraz
**karşılanmamıştır**.

### 16.3 Doyan gecikme bir kat etme süresi olmayabilir

**İtiraz.** Doymuş grup gecikmesi, engelde depolanan alanın boşalma süresidir,
ve alan iki uçtan birden boşalır. Bir ömür süresi ise bir hızla
ilişkilendirilemez, bir yayılma terimiyle de toplanamaz. O zaman $2\tau - s$
ifadesi iki farklı türden süreyi çıkarmaktadır, ve sıfırlandığı nokta fiziksel
bir olay işaretlemez. İtirazı [23] kurmaktadır.

**Vurduğu halka.** Doyum ve çevrim.

**Yanıt.** Bu çalışma toplamı elle kurmamış, tek bir genliğin durağan faz
koşulundan türetmiştir (Bölüm 4.1.2). Türetim itirazın hedefi olan **yorumu**
ise kurtarmamaktadır: durağan faz koşulu çıkan paketin tepesinin hangi anda
göründüğünü verir, o tepenin bir kat etme süresi taşıdığını vermez. İtiraz
**kısmen karşılanmıştır**: toplamın cebri sağlamdır, süre yorumu değildir.

### 16.4 Erken varan cismin sinyal sayılması

**İtiraz.** Bu çalışma nedensellik itirazını, bir sinyal iddiası taşımadığını
söyleyerek karşılamaktadır. Oysa çekirdek iddia bir dalga
tepesinin değil, kütleli bir parçacığın kalkıştan önce geri dönmesidir.
Kimliğini taşıyan bir cismin erken varması ise tanımı gereği bir sinyaldir, ve
[31] ile [26]'nın saydığı nedensel maliyeti doğurur.

**Vurduğu halka.** İşaret.

**Yanıt.** İtiraz bir ikilem kurmaktadır, ve ikilem gerçektir. Cisim okuması
alınırsa nedensel çelişki doğar. Faz okuması alınırsa geriye çıkan paketin
tepesinin öne düşmesi kalır, o da bilinen bir olgudur. Bu çalışma iki okumayı
birlikte yürütmekte (Bölüm 9) ve dönüş anını faz okumasından almaktadır. İki
okumanın hangi koşulda birbirine çevrildiğini Bölüm 9.2 ile 11.4
vermektedir: paket yeterince dar tutulduğunda çevrim tam işler, ancak dar paket
kendi kaybını getirir. Dolayısıyla ikilem **kapatılmamıştır**. Kaydedilen şey
şudur: faz okumasıyla hesaplanan dönüş anı bir sinyal iddiası taşımaz, ve cisim
okumasına geçmek için gereken dar paket sınırı Bölüm 9.3'te sayılıdır.

### 16.5 Çok zamanlı bölgede başlangıç verisinin serbestliği

**İtiraz.** Birden çok zaman ekseni taşıyan bir bölgede başlangıç değeri
problemi ancak yerel olmayan bir kısıt altında tek çözüm verir. O kısıt, Bölge
II'nin verisini eşikte serbest bırakmaz. Bu durumda $s$, dışarıdan seçilebilen
bir sayı olmaktan çıkar.

**Vurduğu halka.** Çevrim ve işaret.

**Yanıt.** Bu çalışma iyi konumlanma sorununu kaydetmekte (Bölüm 1.5, beşinci
engel), ve eşikten erişilen alt kümenin sönümlü olduğunu göstererek
**kararlılık** tarafını karşılamaktadır. İtirazın **teklik** tarafı ise
karşılanmamıştır. $s$'nin bu modelde belirlenmediği zaten kayıtlıdır; itiraz o
boşluğu daraltmakta, yani $s$'yi yalnızca belirsiz değil, eşikteki veriye bağlı
bir nicelik hâline getirmektedir.

### 16.6 Nedensel çevrim kurulan yüzeyde vakum gerilimi ıraksayabilir

**İtiraz.** Kapalı nedensel çevrimlerin kurulabilir hâle geldiği yüzeyde
düzenlenmiş gerilim-enerji tensörü ıraksar, ve geri tepki geometriyi yok eder.
Eşik mesafesi tam olarak böyle bir yüzeydir. İtirazı [30] kurmaktadır.

**Vurduğu halka.** İşaret.

**Yanıt.** Bu itiraz hesabı çürütmemekte, hesabın çıktısının kendini iptal
ettiğini söylemektedir, ve bu çalışma karşılık verecek bir hesap
taşımamaktadır. Bölüm 1 [30]'u yalnızca literatürdeki başka çözümler için
anmakta, kendi eşik mesafesine uygulamamaktadır. İtiraz **karşılanmamıştır**.

### 16.7 Yeniden yorumlama dönüş anını ayırt edici olmaktan çıkarabilir

**İtiraz.** Zamanda geriye giden negatif enerjili bir kol, ileri giden bir
karşıparçacık olarak yeniden yorumlanabilir ([25], [19]). O zaman dönüşün
kalkıştan önce olduğu cümlesi, hedefte daha sonra bir karşıparçacık çıktığı
cümlesinden ayırt edilemez.

**Vurduğu halka.** İşaret ve ölçülebilirlik.

**Yanıt.** İtiraz sayıya dökülebilir bir soru sormaktadır: enerji vektörü ile
ilerleme işaretinin ikisi birden çevrildiğinde dönüş olayının dört koordinatı
değişir mi. Hesap şunu vermektedir.

| Gözlenen nicelik | İki senaryoda | Ayırt eder mi |
| ----------------------- | ------------------------- | ------------- |
| Dönüş anı | Aynı | **hayır** |
| Çıkış yüzü | $2{,}0000$ ile $0{,}0000$ | **evet** |
| Enine yer değiştirmeler | Ters işaretli | **evet** |

İtirazın haklı olduğu kısım birinci satırdır: dönüş anı tek başına iki
senaryoyu ayırmaz, ve bu nicelik çekirdek iddiayı taşıyan niceliktir. Buna
karşılık ikinci ve üçüncü satırlar ayırmaktadır. Parçacığın hangi yüzden
çıktığı ile enine yer değiştirmelerinin işareti birlikte okunduğunda iki
senaryo ayrılmaktadır, ve ikisi de Bölge I'de okunabilir niceliklerdir. İtiraz
bu nedenle **kısmen karşılanmıştır**: dönüş anı tek başına yeterli değildir,
üç niceliğin birlikte okunması yeterlidir.

### 16.8 Alınan mesafenin gözlenebilirliği

**İtiraz.** Uzaysal türden bir dörtlü momentum, nedenselliğe saygı gösteren bir
konum işlemcisi kabul etmemektedir ([38], [39]). O zaman Bölge II'de alınan
mesafe diye ölçülebilir bir nicelik yoktur, ve $s$ bir koordinat etiketidir.

**Vurduğu halka.** Çevrim, girdi tarafı.

**Yanıt.** Bu çalışma sonucu Bölüm 13'te kabul etmektedir. Kabulün sonucu
çekirdek eşitliğe de taşınmalıdır: $\Delta t = s/c$ eşitliğinin sol tarafı
Bölge I'de ölçülür, sağ tarafı ölçülmez. Dolayısıyla eşitlik doğrudan
sınanamaz, ve sınanabilen tek şey sol taraftır.

### 16.9 Fermiyon taşınırsa spin yapısı sorunu

**İtiraz.** Çekirdek amaç bir proton taşımaksa, taşınan nesne fermiyondur. İmza
değiştiren ve Kleinyen manifoldlarda spin yapısının varlığı ise topolojik
engellere takılabilir ([20], [21]).

**Vurduğu halka.** Geçiş, yalnızca taşınan nesnenin türü için.

**Yanıt.** Bu çalışmanın bütün hesapları skaler alan üzerinde yürümektedir, ve
kütle yalnızca $\mu = (mc/\hbar)^2$ parametresi olarak girmektedir. Bölüm 4'ün
taraması da yalnızca vektör temsilinde yapılmıştır; $D$'nin spinor
temsilindeki karşılığı bu bölüm doğrudan kurmakta ve sınamaktadır.

Bu bölüm her üç imza için standart Dirac matrisleriyle bir gamma kümesi
kurmakta, ve Clifford bağıntısı $\{\gamma^\mu, \gamma^\nu\} = 2\eta^{\mu\nu}$'yı
her üçünde ayrı ayrı doğrulamaktadır. Sonra her kümeyi kendi karmaşık
eşleniğine bağlayan bir matrisi on altı elemanlı Clifford tabanında
aramaktadır. Böyle bir matrisin varlığı ve karesinin verdiği işaret, temsili
iki sınıftan birine koyar: **gerçel** sınıf Majorana koşulunu tek başına
taşır, **simplektik** sınıf onu yalnızca çift sayıda kopyayla taşır.
Sınıflandırmadaki serbest işareti bilinen bir olgu sabitler: Bölge I'in olağan
üç eksi bir artı imzası gerçel çıkar.

Bu sabitlemeyle Bölge I ile Kleinian ara bölge aynı sınıfa düşmekte, Bölge II
ise yalnızca simplektik sınıfta kalmaktadır. Yani Bölge I'in kurduğu bir
Majorana koşulunun Bölge II'de karşılığı yoktur.

Bu hesabın sınırı da nettir: temsilin gerçeklik sınıfını verir, çatı demetinin
eşikte dejenere olan bir metrik üzerinden spin yapısı taşıyıp taşımadığını
vermez; o soru [20] ile [21]'in konusu olarak kalır. İtiraz bu nedenle **kısmen
karşılanmıştır**: taşınan nesne bir Dirac fermiyonuysa bu hesaptan bir engel
çıkmaz, Bölge I'deki hâliyle bir Majorana fermiyonuysa engel doğrudan çıkar.

### 16.10 Ayakta kalan ve düşen

Yukarıdaki maddeler karşısında ayakta kalan kısım hesaptır: sekiz aday matrisin
taranması, katsayının tam olarak bir çıkması, yer değiştirmelerin toplanması,
ve momentumun koordinatlarla aynı matrisle taşınması. Hiçbir itiraz bu
adımların cebrini vurmamaktadır.

Düşen kısım ise aritmetiğin fiziksel yorumudur, ve dört ayrı yerden
düşmektedir. Bölüm 16.1 geçerliyse $D$ bir dönüşüm değil bir adlandırmadır.
Bölüm 16.3 geçerliyse $\tau$ ile $s$ toplanamaz. Bölüm 16.2 geçerliyse geçişin
bedeli küçük bir olasılık değildir. Bölüm 16.4'ün ikilemi kapatılmadıkça, elde
ya nedensel bir çelişki ya da bilinen bir tepe kayması kalmaktadır. Dördü
birbirinden bağımsızdır, ve dördü de zincirin ayrı bir halkasını kesmektedir.

İki itiraz ise hesapla daraltılmıştır, ve daraltma biçimi kayda değer.
Bölüm 16.1'in ölçütü sayıya döküldüğünde itiraz doğrudan okumada ayakta
kalmakta, ara bölgeden geçen okumada düşmektedir; yani zincir yalnızca üç
bölgeli hâliyle savunulabilir. Bölüm 16.7'nin hesabı ise dönüş anının tek başına
ayırt edici olmadığını doğrulamakta, ancak çıkış yüzü ile enine yer
değiştirmelerin ayırdığını göstermektedir. İkisinde de itirazın haklı olduğu
kısım ile kalan kısım artık düzyazıyla değil sayıyla ayrılmaktadır.

---

## Kaynakça

**Superluminal gözlemciler ve (1,3)/(3,1) çerçevesi**

1. A. Dragan, K. Dębski, S. Charzyński, K. Turzyński, A. Ekert. *Relativity of
   superluminal observers in 1+3 spacetime*. Class. Quantum Grav. **40** (2023)
   025013. arXiv:2209.01836
2. M. J. Lake. *The (1+3)-dimensional 'quantum principle of relativity' is
   Einstein's principle of relativity*. Eur. Phys. J. C **85** (2025) 92.
   arXiv:2410.07017
3. M. Zaopo. *Group representations of Lorentz transformations extended to
   superluminal observers*. arXiv:2510.25385
4. S. A. Hayward. *Junction conditions for signature change*.
   arXiv:gr-qc/9303034
5. F. Embacher. *Actions for signature change*. Phys. Rev. D **51** (1995) 6764.
   arXiv:gr-qc/9501004
6. T. Dray. *Einstein's equations in the presence of signature change*. J. Math.
   Phys. **37** (1996) 5627. arXiv:gr-qc/9610064
7. T. Dray, G. Ellis, C. Hellaby, C. Manogue. *Gravity and signature change*.
   Gen. Rel. Grav. **29** (1997) 591. arXiv:gr-qc/9610063
8. W. Hasse, N. E. Rieger. *A transformation theorem for transverse
   signature-type changing semi-Riemannian manifolds*. Diff. Geom. Appl.
   **103** (2026) 102370. arXiv:2407.09699
9. N. E. Rieger, W. Hasse. *Pseudo-timelike loops in signature changing
   semi-Riemannian manifolds with a transverse radical*. Results in Physics
   **78** (2025) 108478. arXiv:2409.02403
10. B. Alexandre, S. Gielen, J. Magueijo. *Overall signature of the metric and
    the cosmological constant*. arXiv:2306.11502
11. I. Bars. *Two-time physics in field theory*. Phys. Rev. D **62** (2000)
    046007. arXiv:hep-th/0003100
12. E. Piceno, A. Rosado, E. Sadurní. *Fundamental constraints on two-time
    physics*. Eur. Phys. J. Plus **131** (2016) 352. arXiv:1512.05345
13. D. Figueiredo, F. A. Gomes, S. Fumeron, B. Berche, F. Moraes. *Modeling Kleinian
    cosmology with electronic metamaterials*. Phys. Rev. D **94** (2016) 044039.
    arXiv:1608.03812
14. T. Dray, C. A. Manogue, R. W. Tucker. *Particle production from signature
    change*. Gen. Rel. Grav. **23** (1991) 967.
15. T. Dray, C. A. Manogue, R. W. Tucker. *The scalar field equation in the
    presence of signature change*. Phys. Rev. D **48** (1993) 2587.
    arXiv:gr-qc/9303002
16. J. D. Romano. *Scalar and spinor fields in signature-changing spacetimes*.
    Phys. Rev. D **47** (1993) 4328.
17. T. Dray, C. A. Manogue, R. W. Tucker. *Boundary conditions for the scalar
    field in the presence of signature change*. Class. Quantum Grav. **12**
    (1995) 2767. arXiv:gr-qc/9501034
18. W. Duane. *The transfer in quanta of radiation momentum to matter*. Proc.
    Natl. Acad. Sci. USA **9** (1923) 158.
19. G. Feinberg. *Possibility of faster-than-light particles*. Phys. Rev.
    **159** (1967) 1089.
20. L. J. Alty. *Kleinian signature change*. Class. Quantum Grav. **11** (1994)
    2523.
21. L. J. Alty, A. Chamblin. *Spin structures on Kleinian manifolds*. Class.
    Quantum Grav. **11** (1994) 2411.

**Tünelleme süresi ve doymuş gecikme**

22. T. E. Hartman. *Tunneling of a wave packet*. J. Appl. Phys. **33** (1962)
    3427.
23. H. G. Winful. *Tunneling time, the Hartman effect, and superluminality: a
    proposed resolution of an old paradox*. Phys. Rep. **436** (2006) 1.
24. E. P. Wigner. *Lower limit for the energy derivative of the scattering
    phase shift*. Phys. Rev. **98** (1955) 145.

**Takyonlar ve nedensellik**

25. O. M. P. Bilaniuk, V. K. Deshpande, E. C. G. Sudarshan. *"Meta" relativity*.
    Am. J. Phys. **30** (1962) 718.
26. G. A. Benford, D. L. Book, W. A. Newcomb. *The tachyonic antitelephone*.
    Phys. Rev. D **2** (1970) 263.

**Zamanda geriye yolculuğa izin veren çözümler**

27. K. Gödel. *An example of a new type of cosmological solution of Einstein's
    field equations of gravitation*. Rev. Mod. Phys. **21** (1949) 447.
28. F. J. Tipler. *Rotating cylinders and the possibility of global causality
    violation*. Phys. Rev. D **9** (1974) 2203.
29. M. S. Morris, K. S. Thorne, U. Yurtsever. *Wormholes, time machines, and
    the weak energy condition*. Phys. Rev. Lett. **61** (1988) 1446.
30. S. W. Hawking. *Chronology protection conjecture*. Phys. Rev. D **46**
    (1992) 603.
31. R. C. Tolman. *The Theory of the Relativity of Motion*. University of
    California Press, 1917, 71. bölümünde.

**İnce kabuk, eklem koşulu ve enerji koşulları**

32. S. W. Hawking, G. F. R. Ellis. *The Large Scale Structure of Space-Time*.
    Cambridge University Press, 1973.

**İmza değişiminin kurucu çalışmaları**

33. J. B. Hartle, S. W. Hawking. *Wave function of the Universe*. Phys. Rev. D
    **28** (1983) 2960.
34. G. F. R. Ellis, A. Sumeruk, D. Coule, C. Hellaby. *Change of signature in
    classical relativity*. Class. Quantum Grav. **9** (1992) 1535.
35. J. Barrett, G. W. Gibbons, M. J. Perry, C. N. Pope, P. Ruback. *Kleinian
    geometry and the $N = 2$ superstring*. Int. J. Mod. Phys. A **9** (1994)
    1457. arXiv:hep-th/9302073

**Takyonlar, yerelleştirme ve yeniden yorumlama**

36. E. Recami, R. Mignani. *Classical theory of tachyons*. Riv. Nuovo Cim. **4**
    (1974) 209.
37. E. Recami. *Classical tachyons and possible applications*. Riv. Nuovo Cim.
    **9** (1986) 1.
38. T. D. Newton, E. P. Wigner. *Localized states for elementary systems*. Rev.
    Mod. Phys. **21** (1949) 400.
39. G. C. Hegerfeldt. *Remark on causality and particle localization*. Phys.
    Rev. D **10** (1974) 3320.
40. I. Bars, C. Kounnas. *Theories with two times*. Phys. Lett. B **402** (1997)
    25. arXiv:hep-th/9703060

**Karşılıklılık, parçacık üretimi ve ölçek**

41. N. D. Birrell, P. C. W. Davies. *Quantum Fields in Curved Space*. Cambridge
    University Press, 1982.
42. W. L. Bragg. *The diffraction of short electromagnetic waves by a crystal*.
    Proc. Camb. Phil. Soc. **17** (1913) 43.
