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
nanosaniye verir (Bölüm 21.2.2). Sonucun taşıdığı bilgi bu bölmede değil,
bölenin **ne olduğundadır**: araya parçacığın hızı, geçişin hızı ya da bir ölçek
çarpanı girmez, yalnızca $c$ girer. Hesaptan çıkan katsayı tam olarak bire
eşittir.

Bu farkın karşısında bir gecikme durmaktadır. Eşik, kalınlıksız bir yüzey
olarak değil, sonlu kalınlıkta bir katman olarak ele alınmaktadır. Parçacık o
katmanı sonlu bir sürede geçer, ve bu süre **eşik gecikmesi** adını alır. Eşik
gecikmesi katman kalınlaştıkça artmayı bir noktada bırakıp sabit bir değerde
durmaktadır. Saat farkı ise böyle bir sınır tanımaz, $s$ ile birlikte sınırsız
büyür.

Yolculuğun yönü de iki türlü olabilmektedir. Eşikten geçişi yazan matris sekiz tanedir. Bu sekiz matrisin dördü dönüşü
kalkıştan daha geç bir ana, dördü ise daha erken bir ana taşımaktadır. İlk dörtlüde yolculuk her $s$ değeri için ileri
yönde bir yer değiştirme verir. İkinci dörtlüde ise eşik gecikmesi ters yönde çalışır. Dönüş kalkıştan önce
gerçekleşecekse $s$ değeri eşik gecikmesini aşmalıdır.

Ne var ki bu sonuç bir koşula bağlı kalır. Sekiz matristen hangisinin işlediğini
geometri seçmez. Dolayısıyla çalışmanın kanıtladığı önerme yalnızca
şu olur: böyle bir geçiş gerçekleşirse, dönüş anı hesaplanmış bir sayıya eşit çıkar.
Geçişin gerçekten kurulabildiği ise kanıtlanmamıştır, çünkü önünde iki engel
durmaktadır. Birincisi, eşiği geçirgen kabul eden okuma geçiş yüzeyinde ince bir
madde tabakası doğurur ve o tabaka baskın enerji koşulunu çiğner. İkincisi,
Bölge II'nin içi doğrudan ölçüme kapalıdır: Bölge I'de yalnızca dönüş anı ile
eşiğin iki yüzündeki genlikler okunabilmekte, bunlar da bir geçişin olduğunu
bildirmekte ama içeride izlenen yolu bildirmemektedir.

## 1. Giriş

Bir cismi zamanda geriye taşıyan çözümler genel görelilikte bilinmektedir:
dönen bir evren [46], sonsuz uzunlukta dönen bir silindir [47] ve geçilebilir
bir solucan deliği [48] bunların arasındadır. Ne var ki bunlar ya evren
ölçeğinde bir geometri ya da alışılmadık bir madde dağılımı gerektirdiğinden
laboratuvara inmemektedir; ayrıca kuantum etkilerinin böyle çözümleri
engelleyip engellemediği de açık bir sorudur [49]. Bu çalışma başka bir yol sınar ve onun
aritmetiğini kurar. Sınanan yolun sorusu şudur: parçacık Bölge II'de bir mesafe
alıp geri döndüğünde, Bölge I'de duran bir gözlemcinin saatinde hangi anda
görünür.

İki bölgenin tanımını Özet vermişti. **Bölge I**'de bir eksen zaman ve üç eksen
mekân eksenidir, **Bölge II**'de ise bunun tersi geçerlidir. İkisini ayıran
sonlu kalınlıktaki katman **eşik** adını alır. Bu tanıma bir madde daha eklenir.
Bölge II'de üç zaman ekseni bulunduğundan, o bölgede bir cismin durumu tek bir
hız sayısıyla değil, üç zaman uzayındaki bir **yönelimle** verilir (Bölüm 10).
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

Çalışmanın ikinci sonucu eşiğin kendisiyle ilgilidir. Parçacık eşik katmanını sonlu bir sürede
geçer, ve bu süre **eşik gecikmesi** adını alır. Eşik gecikmesi katman kalınlaştıkça belirli bir
değerde durup artmayı bırakır. Dönüş olayının $t$ bileşenindeki değişim ise
böyle bir sınır tanımaz, $s$ ile birlikte sınırsız büyür. Dolayısıyla bu iki
süre, yani eşik gecikmesi ile $t$ bileşenindeki değişim, belirli bir $s$
değerinde birbirine eşit olur; o değeri aşan her $s$ ise parçacığı yola çıktığı
andan önce geri getirir. Bu çalışma zamanda
yolculuğu baştan kabul etmez, yukarıdaki dönüşümden okumaktadır: dönüş anının,
parçacık hiç eşiğe girmeseydi bulunacağı andan farklı olup olmadığı hesapla
belirlenir.

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
matrisi belirlemektedir. Dönüşün kalkıştan önceye düşmesi için iki koşul
birlikte gerekir: geriye taşıyan bir $M(V)$ ve eşik gecikmesini aşacak kadar
büyük bir $s$.

Dolayısıyla çalışmanın kanıtladığı önerme şu olur: **böyle bir geçiş gerçekleşirse**,
dönüş anı hesaplanmış bir sayıya eşit çıkar. Böyle bir geçişin gerçekleştiğini
gösteren doğrudan bir deney ise henüz yoktur.

Literatür konunun birçok parçasını kurar. [4], [5], [6] ve [7] imza değişimini
tutarlı bir sınır değer problemi olarak yazar; [20], [21], [22] ve [23] alan
denklemlerini imza değiştiren bir uzayzamanda çözer; [15] imza değişimini
benzeşik bir ortamda üretir; [29] ve [30] doymuş tünelleme gecikmesini ölçer.
Ne var ki bu sonuçların hiçbiri kütleli bir parçacığın gerçek bir eşikten
geçtiğini göstermez, çünkü benzeşik bir sistem geometrinin denklemini taklit
eder, taşınan maddeyi değil.

Geçişin kurulmasının önünde de iki engel durmaktadır. Birincisi, eşiği
geçirgen kabul eden okuma geçiş yüzeyinde bir madde tabakası doğurur ve o tabaka
baskın enerji koşulunu çiğner (Bölüm 5.6). İkincisi, Bölge II'nin içi doğrudan
ölçüme kapalı kalmıştır. Bölge I'de okunabilen nicelikler dönüş anı ile eşiğin
iki yüzündeki genliklerdir. Bu nicelikler bir geçişin olduğunu bildirir, ancak
parçacığın Bölge II'de izlediği yolu bildirmez (Bölüm 18.9).

Geçişin gerçekleşmesi için gereken koşullar ise boş bırakılmamıştır. Hesap
sekiz koşul üretmiş, ve her birinin bozulduğunda neyin ortadan kalktığı ayrı
ayrı sayılmıştır (Bölüm 13.7). Yedi koşul sağlanabilir çıkmakta, sağlanamayan
tek koşul Bölge II'de gereken madde yoğunluğu olarak kalmaktadır; gereken değer
bilinen en yoğun ortamın çok üzerindedir (Bölüm 21). Dolayısıyla bu çalışma bir
koordinat dönüşümü kurmakla yetinmez, o dönüşümün fiziksel olarak
gerçekleşebilmesi için nelerin gerektiğini de sayıyla verir.

### 1.3 İddianın büyüklüğü

Yukarıdaki sonuç dört parçadan kurulur, ancak bunlardan yalnızca dördüncüsü
yenidir. İlkini literatür 1962 ile 1970 arasında göstermiştir ([35], [26], [36]): ışıktan
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

Sonuca yedi adımda varılmıştır. Adımların tamamı, her birinin hangi bölümde
kurulduğuyla birlikte Bölüm 19'da sıralanır.

### 1.5 Gösterilmeyenler

Yedi adım bir aritmetik kurar, ve o aritmetik kendi içinde eksiksiz işler. Ancak
aynı aritmetik, böyle bir geçişin fiziksel olarak kurulabildiğini göstermez.
Kurulmasının önüne beş ayrı engel çıkar.

**Birincisi bir büyüklük sorunudur.** Eşiği geçebilen yapılanmalarda geçirgenlik
$T$, yani parçacığın geçme olasılığı, kalınlık $d = 8$'e çıktığında
$3{,}46 \times 10^{-12}$'ye kadar iner. Yani geçiş mümkün kalır ama neredeyse
hiç gerçekleşmez.

**İkincisi bir açık sorudur.** Saat farkının işaretini seçebilmek, sekiz matris
arasından birini evrensel olarak sabitleyen bir kuralın bulunmamasına dayanır,
oysa böyle bir kuralın yokluğu kanıtlanmamıştır.

**Üçüncüsü bir çelişkidir.** Eşiği geçirgen kabul eden okuma ile geçiş
yüzeyindeki madde tabakası bir arada duramaz. Bu engel bu modele özgü değildir,
çünkü kaynağını literatürün zaten taşıdığı güçlü ile zayıf eklem koşulu
ayrımından alır.

**Dördüncüsü bir yanlış okuma tehlikesidir.** Gecikmenin kalınlıkla doyması,
içeride bir yayılma hızının ölçüldüğü anlamına gelmez, çünkü aynı rejimde grup
hızı zaten tanımsız kalır. Aynı gecikme, ara bölgede depolanan alanın katmanda
ne kadar durduğundan da bağımsız değildir.

**Beşincisi gözlemdedir.** İddiayı taşıyan aralıkta parçacık Bölge II'de
doğrudan görünmez, ve geriye yalnızca üç sınır niceliği kalır. Üçü de tek bir
bilgi verir, yani bir geçişin olduğunu (Bölüm 18.9). Bölge II'de durup ileriyi
kestirmeye çalışan bir gözlemci de başarısız olur, çünkü eşikteki başlangıç
değeri problemi iyi konumlanmaz. Ancak bu çöküş, eşikten geçerek Bölge II'ye
giren durumları etkilemez: iddiayı taşıyan engel rejiminde iç mod sönümlüdür,
yani $q = i\beta$ ile $\beta$ gerçeldir (Bölüm 5.2), ve sönümlü bir mod
büyüyerek çözümü bozamaz.

### 1.6 Model

Model iki bölge değil üç bölge kullanır. Bölge I ile Bölge II'nin arasındaki
geçiş, kalınlıksız bir yüzey olarak alınmaz; kendi kalınlığı ve kendi imzası olan
üçüncü bir bölge olarak durur. Bütün hesaplar bu ara bölgenin dört tipi ve beş
ayrı kalınlığı için ayrı ayrı yürütülmüştür.

Eşik geçirgen alınmıştır, yani parçacık eşikten geçebilmektedir. Bunun
karşılığında doğan madde tabakasını ve o tabakanın çiğnediği enerji koşulunu
Bölüm 1.5 üçüncü engel olarak saymıştı. Bölüm 5.7 sınanan üç profilde oran
koşulunu geçen tek profilin güçlü koşulu sağlayan, yani hiçbir şey geçirmeyen
profil olduğunu bulur. Bunun genel bir engel olmadığını ise Bölüm 5.7.1
göstermekte: oran koşulunu sağlayan yapılanmalar bulunur, ve aynı alt bölüm
engel iddiasını bu nedenle geri alır. Kalan katkı üstelin iki parametreli
kapalı biçimidir.

Çalışma parçacığı ayrıca iki okumayla birden taşır. Hesaplar dalga paketi üzerinden
yürür, anlatım ise noktasal bir cisim dilini kullanır. İki okumayı birbirine
çeviren sözlüğün, paket yeterince dar tutulduğunda tam olarak işlediği
gösterilmiştir.

### 1.7 Yolculuk

Parçacığın Bölge II'de yapabilecekleri iki etikete indirgenmiştir: ara bölgenin
hangi yüzünden çıktığı ve enerji vektörünün ne kadar döndüğü. İkisinin tanımını
Bölüm 9.5, Bölge I'deki karşılıklarını ise Bölüm 10.1 verir.

Bu iki etiketten çıkan sonuç şudur: Bölge I'in saatinde fark üreten tek hareket,
tek uzay ekseni boyunca alınan yoldur. Üç zaman ekseni içinde kalan hareketler
saate hiçbir şey taşımaz.

Dönüş anını ise parçacığın yanında taşıdığı bir saat vermez. O an, ara bölgeye
giriş ve çıkış genliklerinin ortak fazından okunur. Engel rejiminde bu faz
kalınlık arttıkça sabit bir değerde durur, ve kalınlığın bilgisi artık fazda değil,
frekans bileşenlerinin karışımında kalır.

### 1.8 Geri döndüğünde

Parçacık geri döndüğünde enerjisi, sürati ve kütlesi tam olarak korunur;
korunmayan tek şey gittiği yön olur. Bunun nedeni şudur: Bölge II'de hiçbir
fiziksel iz bırakmayan bir ayar dönmesi, Bölge I'de parçacığın yön değiştirmesi
olarak görünür, ve bu yön değişikliği hiçbir enerji harcamaz. Üstelik sapma
açıları her değeri de alamaz, sonlu bir kümeden gelir. İki özellik birleşince
çalışmanın deneyle ayırt edilebilecek öngörüsü ortaya çıkar: çarptığı hedefin
geri tepmediği ve açıları ayrık değerlerde kalan bir esnek sapma.

Dönüşümün kendisi ise tek yönlüdür. Tarama on üç kutup açısı ile on iki azimut
açısını iki ilerleme işaretiyle çarpar, ve böylece $312$ Bölge II durumu
sınanır. Bu $312$ durum yalnızca $158$ farklı dönüş olayına düşmektedir. İki
sayının oranı ızgaranın çözünürlüğüne bağlı olduğundan bir ölçü değildir; sabit
kalan şey, hangi koordinatın hangi girdiden bağımsız olduğudur (Bölüm 18.3).

### 1.9 Modelin maddeleri

Aşağıdaki maddelerin hepsi tek bir dönüşüme aittir: Bölge II'deki yönelimi dönüş
olayının dört koordinatına bağlayan dönüşüme. Her madde bu dönüşümün ya bir
girdisini, ya bir kısıtını, ya da bir sonucunu kaydeder.

1. Model üç bölge kullanır: Bölge I, ara bölge ve Bölge II.
2. Ara bölgenin **neyden yapıldığı** ile **ne kadar kalın olduğu** birbirinden
 bağımsız iki soru sayılır. Kalınlık sıfıra inince tipin bir önemi kalmaz,
 ara bölge hiç yokken de kalınlığın bir önemi kalmaz.
3. Eşik geçirgen kalır. Bu, zayıf eklem koşulunu seçmenin sonucudur ve bedelini
 bir madde tabakası olarak öder. Tabakanın gücü kalınlık arttıkça azalır ama
 hiç sıfırlanmaz, ve tabaka **baskın enerji koşulunu çiğner**.
4. Parçacık hem dalga paketi hem noktasal cisim olarak okunur; ikinci okuma
 paket yeterince dar tutulduğunda tam olarak geçerli kalır.
5. Bölge II'de ileriyi kestirme problemi kendi içinde iyi konumlanmaz, ancak
 eşikten erişilebilen alt kümesi bu sorundan etkilenmez.
6. Dönüş anını bir süre ölçümü değil, genliğin fazı verir. Engel rejiminde bu
 faz kalınlık arttıkça sabit bir değerde durur.
7. Gidiş dönüş boyunca enerji, sürat ve kütle korunur; yön korunmaz.
8. Bölge II'deki bir ayar dönmesi Bölge I'de bir sapma olarak görünür, hiçbir
 enerji harcamaz ve açıları ayrık değerler alır.
9. Dönüş olayının dört koordinatı ayrı kaynaklardan gelir: zaman bileşenini faz
 verir, uzay bileşenlerini çıkış yüzü ile ayrık sapma açısı verir. Bölge II'deki
 yönelim bu koordinatların hepsine değil, yalnızca bir kısmına
 ulaşır.

### 1.10 Okuma haritası

Çalışma üç adım üzerine kurulmuştur, ve üçü de tek bir amaca hizmet eder: kütleli
bir parçacığı zamanda geriye taşımak. Aşağıdaki tablo her adımın hangi bölümlerde
kurulduğunu gösterir.

| Adım | Sorusu | Kurulduğu bölümler |
| ------ | ----------------------------------------------------- | ----------------------------------------------------------- |
| Geçiş | Kütleli bir parçacık eşiğin ötesine nasıl geçer | Bölüm 3, Bölüm 4, Bölüm 5, Bölüm 6, Bölüm 8, Bölüm 12 |
| Mesafe | Bölge II'de mekânda kat edilen mesafe ne anlama gelir | Bölüm 4.1.1, Bölüm 4.1.2, Bölüm 4.1.3, Bölüm 9, Bölüm 10.1 |
| Dönüş | Geri döndüğünde saatte nereye düşer | Bölüm 13, Bölüm 16, Bölüm 17, Bölüm 18, Bölüm 19 |

**İki giriş noktası vardır ve ikisi farklı işe yarar.** Bölüm 2 hesabı on bir
satırlık bir tablo hâlinde, denetim sayılarıyla birlikte verir; sayıyı yeniden
üretmek isteyen oradan başlar. Bölüm 19 ise yedi adımı sıralar ve her adımın
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
| 5.6, 5.7 | Katmanın enerji koşulları ve oran koşulu | Geçirgen eşiğin doğurduğu madde katmanı fiziksel olarak kabul edilebilir mi |
| 7 | Geometrinin izin verdiği geçiş | Böyle bir geçişe geometri izin veriyor mu |
| 11 | Dalga ve nokta cisim okumaları | Hesabı paketle yapıp anlatımı cisimle kurmak meşru mu |
| 9.3 | Yönlendirilebilirlik ile ilerleme zorunluluğunun ayrılması | Ayrım metrikte var, zorunluluk hiçbir metrikte yok |
| 10.2, 10.5 | Dispersiyon, grup hızı, kapalı form çözüm | Üç zamanlı bir bölgede hız kavramı ne oluyor |
| 20 | Yöntem ve üç denetim | Bu sayılar doğrulanmış mı ve doğrulama kendini kandırıyor olabilir mi |
| 21 | Açık kalanlar | Neyin gösterilmediği yazılı mı |
| 22 | İtirazlar ve yanıtlar | Literatürden gelen itirazlar tek yerde toplanmış mı |
| 4.2 | Geniş formülasyonla karşılaştırma | Aynı grubu daha genel kuran bir çalışma varken bu kurulum gereksiz mi |
| 10.3 | Durgunluğun tek yörüngeye indirgenmesi | Bölge II'de duran bir cismin sonsuz çok durumu mu var |
| 15.5 | Yükün yeniden dağılması | Eşikte yük kayboluyor mu |
| 18.8 | Yönün Bölge I'den seçilebilirliği | Engeli biçimlendirerek işaret seçilebilir mi |

Bölüm 14 ile Bölüm 15, eşiğin hangi modları geçirdiğini kayda geçiren iki
dökümdür ve ana hat ile itiraz bölümlerinin arasında durmaktadır. Sonucu
üretmezler, ancak sonucun kendi içinde tutarlı kalmasını onlar sağlar.

**"Eşik" kökü üç ayrı nesnede geçer.** Tek başına **eşik**, iki bölgeyi ayıran
sonlu kalınlıktaki katmandır. **Eşik gecikmesi**, parçacığın o katmanı geçmesi
için gereken süredir ve saniye taşır. **Eşik mesafesi** $s^\ast$ ise Bölge
II'de alınan ve dönüşü tam kalkış anına getiren uzunluktur, ve metre taşır.
Üçünün birimi farklı olduğundan hangisinin kastedildiği bağlamdan da okunur.

**"Sözlük" sözcüğü üç ayrı nesneyi adlandırır.** Üçü aşağıda bir kez ayrılmıştır ve
çalışmanın geri kalanında bu ayrım tekrarlanmamaktadır.

| Nerede | Neyi eşler | Çekirdek için rolü |
| ---------- | -------------------------------------------------------------------------------------- | ------------------------------------------------ |
| Bölüm 10.1 | Bölge II'nin dört ekseni $\to$ Bölge I'in yuvaları ve bir birim adımın saatte ürettiği | **Çekirdeğin kendisi.** İspatı Bölüm 4.1.1'dedir |
| Bölüm 16.2 | Bölge II'deki yönelim $\to$ Bölge I'de gözlenen nicelikler | Çekirdeğin girdi tarafı |
| Bölüm 17.1 | Dört koordinatta hareket ile yönelim arasındaki ayrım | Girdinin hangi kısmının hareket olduğu |

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
vektör Bölge I'de parçacığın üç momentum bileşenine karşılık gelir (Bölüm 15.1).
Vektörün Bölge II'deki yönü fiziksel bir fark yaratmaz, yalnızca uzunluğu yaratır
(Bölüm 15.3). Ara bölgenin tipi hesaba, imzası çevrilen yönlerin sayısı olan $n$
ile girer; Öklid tipi için $n = 3$. Geri kalan girdiler ara bölgenin kalınlığı
$d$, kütle parametresi $\mu$ ve hız $c$ olur.

**Adımlar.**

| Adım | Nicelik | Bu nicelik nedir | Nerede |
| ---- | ---------------------------------------------------------------------------------- | ------------------------------------------------------ | ------------------------ |
| 1 | $\omega = c\sqrt{E_1^2 + E_2^2 + E_3^2 + \mu}$ | Parçacığın frekansı | Bölüm 15.1 |
| 2 | $k_T^2 = E_2^2 + E_3^2$ | Geçiş doğrultusuna dik dalga sayısının karesi | Bölüm 18.3 |
| 3 | $\kappa = \sqrt{\omega^2/c^2 - k_T^2 - \mu} = \lvert E_1 \rvert$ | Geçiş doğrultusundaki dalga sayısı, eşiğin dışında | Bölüm 18.7 |
| 4 | $\beta = \sqrt{\tfrac{2n}{3}k_T^2 - E_1^2}$ | Eşiğin içinde genliğin sönüm hızı | Bölüm 18.7 |
| 5 | $q = i\beta$ söndürücü hâlde, reel yayılımlı hâlde | Geçiş doğrultusundaki dalga sayısı, eşiğin içinde | Bölüm 12.1 |
| 6 | $A(\omega) = \dfrac{4\kappa q}{(\kappa+q)^2 e^{-iqd} - (\kappa-q)^2 e^{iqd}}$ | Eşiğin bir yüzünden girip diğerinden çıkma genliği | Bölüm 12.1 |
| 7 | $\tau = \dfrac{\mathrm{d}}{\mathrm{d}\omega}\arg A(\omega)$ | Tek geçişin süresi | Bölüm 13.2 |
| 8 | $2\tau$ | Gidiş dönüşün toplam eşik gecikmesi | Bölüm 12 |
| 9 | $2\tau - s$ | Varış anı, kalkışa göre, geri taşıyan dalda | Bölüm 4.1.2, Bölüm 4.1.3 |
| 10 | $s^\ast = 2\tau$ | Eşik mesafesi: bunu aşan yolculuk kalkıştan önce döner | Bölüm 4.1.3 |
| 11 | $\Delta E / E = \Delta / s$ | Kalkıştan $\Delta$ kadar önce dönmenin enerji oranı | Bölüm 4.1.5 |

**Üç yakın nicelik birbirinden ayrı durur.** Altıncı satırın verdiği
$A(\omega)$ bir **genliktir** ve karmaşık bir sayıdır. Onun karesi
$T = |A|^2$ **geçirgenliktir**, yani tek bir geçişin olasılığıdır. Bir paketin
gidiş dönüşten sağ çıkan kesrine ise **dönen ağırlık** denir (Bölüm 14.1);
ağırlık, paketin bütün frekans bileşenleri üzerinden alınmış bir toplam
olduğundan tek bir $T$ değerine eşit değildir.

Dokuzuncu satırda $s$'nin önündeki katsayı **bire eşittir** ve araya bir hız
girmez. Çalışmanın asıl sonucu budur (Bölüm 4.1.1, Bölüm 4.1.2). O terimin
işaretini, hangi geçiş dönüşümünün gerçeklendiği belirler; parçacığın Bölge II'de
hangi yöne ilerlediği belirlemez (Bölüm 4.1.3).

**Denetim değerleri.** Yukarıdaki adımları uygulayan bir programın doğru
çalışıp çalışmadığı aşağıdaki yapılanmadan sınanabilir, çünkü bu yapılanma
çalışmanın bütün çekirdek sayılarını üretmektedir.

$$c = \mu = 1, \qquad n = 3, \qquad d = 8$$
$$E = L(\sin\theta\cos\varphi,\; \sin\theta\sin\varphi,\; \cos\theta),
\qquad \theta = \pi/3,\; \varphi = 0{,}7,\; L = 3$$

| Nicelik | Değer |
| ------------------------------------------------- | ------------------------------------------ |
| $E$ | $(1{,}987118,\; 1{,}673727,\; 1{,}500000)$ |
| $\omega$ | $3{,}162278$ |
| $k_T^2$ | $5{,}051361$ |
| $\kappa$ | $1{,}987118$ |
| $\beta$ | $2{,}480742$ |
| $\tau$, fazın türevinden | $1{,}282994$ |
| $\tau$, kapalı formdan $2\omega/(c^2\kappa\beta)$ | $1{,}282994$ |
| Gidiş dönüş gecikmesi $2\tau$ | $2{,}565988$ |
| Eşik mesafesi $s^\ast$ | $2{,}565988$ |

Altıncı ile yedinci satırın aynı çıkması bir rastlantı değildir, çünkü iki sayı
iki ayrı yoldan gelir: biri genliğin frekansa göre sayısal türevinden, diğeri
kalınlığın hiç geçmediği kapalı formdan. Bu yüzden ikisi birbirinden bağımsız
hesaplanıp karşılaştırılabilir, ve ayrıldıkları noktada hatanın kaynağı
uygulamada bulunur, modelde değil.

**Geçişin ne sıklıkta olacağı da hesaba girer.** Yukarıdaki sayılar neyin mümkün
olduğunu verir, o şeyin ne kadar sık gerçekleşeceğini vermez. Aynı
yapılanmada tek bir geçişin genliği $4{,}692932 \times 10^{-9}$, geçirgenliği
$2{,}202361 \times 10^{-17}$ çıkmaktadır. Bölüm 4.1.3 ile Bölüm 4.1.5'in
kalınlığa göre verdiği $3{,}46 \times 10^{-12}$ dizisi ise başka bir
yapılanmaya aittir, yani bu bölümdeki sayının kalınlıkla ölçeklenmiş hâli değildir.
Dönüş anı tek başına eksik kalır, çünkü o anın ne sıklıkta gerçekleşeceğini
yalnızca bu iki sayı verir.

### 2.1 Gidiş dönüşün hâlleri

Yukarıdaki adımlar tek bir sonuç değil, bir sonuç kümesi üretmektedir. Kümenin
tamamı aşağıda verilmiştir, çünkü yalnızca geriye götüren durumu göstermek öteki
durumları saklamak olurdu.

Sonucu iki bağımsız seçim belirlemiştir. Birincisi **dal**, yani sekiz geçiş
dönüşümünden hangisinin gerçeklendiği: dördü parçacığı ileriye, dördü geriye
gönderir ve metrik ikisi arasında bir tercih yapmaz. İkincisi **mesafe**, yani
parçacığın Bölge II'de ne kadar yol aldığı. Bunların üstünde bir de ara bölgenin
rejimi durur: bölge söndürücüyse gecikme kalınlıkla sabit bir değerde durur,
yayılımlıysa durmaz.

Varış anı, kalkışa göre, her durumda

$$t_{\text{dönüş}} = 2\tau \;\pm\; s$$

biçimini alır. Bu ifadedeki işareti dal belirler, $s$'yi ise yolculuğun uzunluğu.
Formülden beş ayrı durum çıkar ve beşi de bu modelin içinde kalır. Aşağıdaki
sayılar Bölüm 19'un yürüttüğü gidiş dönüşe aittir, Bölüm 2'nin denetim
yapılanmasına değil. İki yapılanma farklı bir $2\tau$ verdiğinden tablo yalnızca
durumların listesini göstermektedir:

| Dal | Mesafe | Varış anı | Ne olur |
| --------- | ----------- | --------------- | ------------------------------------------------ |
| Geri | $s < 2\tau$ | $0 < 2\tau - s$ | Kalktıktan sonra döner, ama ışıktan erken |
| Geri | $s = 2\tau$ | $0$ | Tam kalktığı anda döner |
| Geri | $s > 2\tau$ | $2\tau - s < 0$ | **Kalkmadan önce döner** |
| İleri | herhangi | $2\tau + s > 0$ | Her zaman sonra döner, mesafe gecikmeyi büyütür |
| Her ikisi | $s = 0$ | $2\tau$ | Yolculuk yok, yalnızca iki geçişin faz gecikmesi |

Son satır, gecikmenin yolculuktan bağımsız bir tabanı olduğunu göstermektedir.
Parçacık Bölge II'de hiç ilerlemese bile iki geçişin kendisi bir süre yer:
Bölüm 19'un yapılanmasında $2{,}434322$ birim.

Dördüncü satır ise bir iddia değil, taranmış bir sonuç taşımaktadır. İleri dal
iki yüz birim mesafeye kadar tarandı, ve hiçbir mesafede parçacık kalkıştan
önceki bir ana varmadı. Aynı sonuç bu satırdan da çıkar: varış anının işaretini
yolculuğun uzunluğu değil, hangi geçişin gerçeklendiği belirler.

**Ara bölgenin rejimi tabloya ayrı bir satır olarak girmez.** Tablonun tamamı,
ara bölgenin parçacığa engel olduğu duruma aittir. Bölge engel olmaktan çıkınca
eşik mesafesi büyümez, çünkü sönüm katsayısı sıfırlanır ve kapalı form hiç
gecikme vermez. Yayılımlı rejimde değişen şey sürelerin büyüklüğü değil, bu
hesabın yayılımlı rejimde geçerli olup olmadığıdır.

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
işaretinin böyle değişmesini ve bunun fiziksel sonuçlarını [12] ayrıca ele
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
kaynağı geometri değildir**. Bölüm 9.4 aynı durumu başka bir yerde daha
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

ve [31]'in kullandığı durağan faz koşulu çıkan paketin anını

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

Aynı sonuca ikinci bir yoldan da varılır: Bölge I'in kütle kabuğu üzerinde
frekansa göre merkezî fark alınarak. Dört kütle değeri ($\mu = 0$, $0{,}25$, $1$,
$9$), üç frekans ve sekiz geçiş üzerinde sayısal türev, cebirsel değeri dokuz
basamağa kadar yeniden üretmektedir. Enine bileşenler frekansta bilerek **doğrusal
olmayan** bir bağımlılık taşır; bu yüzden sonuçta hiç görünmemeleri bir ihmal
değil, hesaplanmış bir olgudur.

**Dispersiyon bağıntısı neden girmiyor.** Aynı katsayıya bir grup hızı
argümanıyla gitmek mümkün görünür, ama o yol kapalı kalır: $k/\sqrt{k^2+\mu}$
niceliği $\mu > 0$ için hiçbir sonlu $k$'de bire ulaşmaz. Hesaplanan değerler
$\mu = 1$ için $k = 1$'de $0{,}707106781$, $k = 10$'da $0{,}995037190$,
$k = 1000$'de $0{,}999999500$. Yukarıdaki birim katsayı bir hızın kütlesiz
limiti değildir; dönüşümün tam bir özelliğidir ve sonlu kütlede de geçerli kalır.
Ayrım önemlidir, çünkü bir asimptotik yaklaşım sonucu yalnızca yaklaşık kılardı.

### 4.1.3 Dönüş anının işareti

Bölüm 4.1.2 toplamı meşru kıldığına göre, iki terimin **yarışması** anlamlı bir
soru hâline gelir. Terimlerin kalınlığa bağımlılıkları farklıdır: bariyer
rejiminde faz gecikmesi kalınlıkla **doyar**, Bölge II yer değiştirmesi ise
doymaz ve $s$ ile sınırsız büyür. Doyan gecikme bu yüzden bir **eşik mesafesi**
tanımlar; Bölge II'de bundan daha uzağa gidilirse ikinci terim birinciyi yener.

Öklidyen bir ara bölgede, $d = 8$ ve $c = \mu = 1$ için hesaplanan gecikme
$2{,}565988$ çıkmıştır. Eşik mesafesi de tam olarak bu sayıya eşittir, çünkü geri
taşıyan dalda varış anı o mesafede sıfırlanır. Hesaplanan varış anları şöyledir:

| Bölge II mesafesi | Varış anı | Girişe göre |
| ------------------ | ----------- | ----------- |
| $2$ | $+0{,}5660$ | sonra |
| $4$ | $-1{,}4340$ | **önce** |
| $8$ | $-5{,}4340$ | **önce** |

İleri taşıyan dalda ise incelenen hiçbir mesafede bu olmaz. Yayılımlı (Kleinyen)
rejimde de olmaz, çünkü yayılımlı rejimde gecikme doymaz: $d = 8$ için değeri $97{,}0543$'e
çıkar, yani incelenen mesafelerin çok ötesinde kalır ve eşik mesafesine hiç
ulaşılamaz.

Bu sonucun gerçekleşme olasılığı ise küçük kalmaktadır. Eşik mesafesine
ulaşabilen yapılanmalar kalın bariyerlerdir, ve kalın bir bariyer neredeyse
hiçbir şey geçirmez: geçirgenlik $d = 2$ için $3{,}67 \times 10^{-3}$, $d = 4$
için $3{,}60 \times 10^{-6}$, $d = 8$ için $3{,}46 \times 10^{-12}$ çıkar. Yani
geçiş hem mümkün kalır hem de son derece seyrek gerçekleşir. Bu bölümün sonucu
neyin olabileceğini verir, ne kadarının olacağını vermez.

Bu toplama işlemi ayrıca bağımsız bir türetmeyle karşılaştırılmıştır.
Bölüm 4.1.2 varış anını tek bir genlikten okumakta, ve iki yol üç ayrı mesafede
karşılaştırıldığında her üçünde de aynı sayı çıkmıştır. Dolayısıyla bu
bölümdeki toplam, yerine geçebilecek türetmeyle uyumlu kalmıştır.

**Erken varmak ile Bölge II'de ters yönde ilerlemek aynı şey değildir.** Bölge
II'nin tek uzay ekseni **yönlendirilmiş** çıkmaktadır, yani üzerinde ayırt
edilmiş bir yön taşır. Yönü eksenin kendisi verir. Bir cisim o eksende yalnızca
mesafeyi seçer, yönü seçemez.
Yukarıdaki erken varış bu sonuçla çelişmez, çünkü varış anının işaretini cismin
ilerleme yönü değil, kullanılan geçiş dönüşümü belirler (Bölüm 1.2). Dolayısıyla
bu kurguda "geri gitmek" diye bir işlem bulunmaz, ve zaten gerekmez.

### 4.1.4 Çerçeve değişimi

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

### 4.1.5 Yer değiştirmenin karşılığı

Bölge II'de yol almanın iki ayrı karşılığı vardır ve ikisi birbirinden farklı
davranır: yolculuğun ne olasılıkla gerçekleşeceğini veren genlik ağırlığı, ve
yolculuk için harcanması gereken enerji.

**Genlik ağırlığı.** Parçacık kalkıştan $\Delta$ kadar önce dönecekse, Bölge II'de aldığı yol doymuş geçiş gecikmesini $\Delta$ kadar aşmalıdır.
Gecikmeyi yolun uzunluğu değil ara bölge sabitlediğinden, gereken yol istenen
kaymayla **birebir** büyür: $\Delta = 0$ için $2{,}565988$, $\Delta = 1000$ için
$1002{,}565988$ birim. Geçişin geçirgenliğini ise yalnızca ara bölge belirler.
Geçirgenlik kalınlık $2$'de $3{,}67 \times 10^{-3}$, kalınlık $8$'de
$3{,}46 \times 10^{-12}$ çıkar, yani bölgeye gerçekten duyarlı bir niceliktir.
Buna karşın **yolun uzunluğu, geçirgenliği veren ifadede hiç geçmez**.
Dolayısıyla bu modelde ne kadar uzun bir yolculuk yapılırsa yapılsın,
geçirgenlik en kısa yolculuktakiyle aynı kalır.

Bu durum bir serbestlik değildir. Bölge II'de alınan yol genliğe hiç girmiyorsa,
modelde bir **eksik** var demektir. Yolculuğun geçirgenliğe ne kattığını
hesaplayabilmek için genliğin önce yol uzunluğuna bağlı bir değişken kazanması
gerekir. Yukarıdaki sayılar bundan fazlasını vermez.

**Düz bir yolun enerjisi.** Bölge II'nin geometrisi, ayırt edilmiş eksen boyunca
kaydırma altında değişmez. Bu yüzden o eksene eşlenik nicelik korunur ve düz bir
yolun uzunluğu hiç enerji istemez. Aynı işaretli eksenler arasındaki dönmeler de
enerji istemez. Ancak Bölüm 4.1.4'e göre bu iki işlemin hiçbiri saatte bir fark
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

### 4.1.6 Doymuş gecikmenin küçültülmesi

Yukarıdaki hesapların hepsi eşik mesafesini **verili** almaktadır. Oysa bu
mesafe verili değildir. Literatür doymuş gecikmeyi bariyerin değişmez bir
özelliği gibi ele alır, ve o çerçevede sorulan soru gecikmenin **doyup doymadığıdır**;
ne kadar **küçültülebileceğini** kimse sormamıştır. Bu modelde o gecikme,
parçacığın geçmişe varmak için aşması gereken mesafeyi belirler. Dolayısıyla
soru hem anlamlı hem de cevaplanabilir hâle gelir.

Kapalı form cevabı doğrudan vermektedir. Enerji vektörünün birinci bileşeninin
karesine **normal pay**, kalan iki bileşenin kareleri toplamına **enine pay**
denmektedir. Gecikme yalnızca bu iki sayıya ve kütleye bağlı kalır, kalınlık
formülde hiç geçmez. Öyleyse gecikme bu iki pay üzerinden küçültülebilir.
Küçültme iki ayrı yönde işler.

**Birincisi: sabit toplam enerjide bir iç optimum vardır ve etkisi zayıftır.**
Toplam $6{,}84$ için:

| Normal pay | Gecikme |
| ---------- | ------------ |
| $1$ | $1{,}713572$ |
| $2{,}28$ | $1{,}418053$ |
| $2{,}84$ | $1{,}462864$ |
| $4$ | $2{,}160247$ |

En küçük gecikme $1{,}418053$ çıkar ve normal payın $2{,}2800$ olduğu noktada
bulunur. Çalışmada kullanılan yapılanma bu en iyi değerin **yüzde birkaçı**
içinde kalmaktadır, yani iki payı yeniden dengelemek kayda değer bir kazanç
getirmez.

**İkincisi: toplam enerjiyi yükseltmek güçlü bir etki yapar.** Payların en iyi
bölüşümünde parçacığın Bölge II'de almak zorunda kaldığı yol, gidiş dönüş
boyunca şu değerlere iner:

| Toplam enerji | Gereken Bölge II mesafesi |
| ------------- | -------------------------- |
| $9$ | $2{,}434322$ |
| $50$ | $0{,}989546$ |
| $500$ | $0{,}310148$ |
| $5000$ | $0{,}097990$ |

Mesafe **sınırsız** küçülmektedir. Yani Bölge II'de alınması gereken yol sabit
bir zorunluluk değil, deneyi kuranın **seçtiği** bir büyüklüktür.

**Bu kısaltmanın neye mal olduğu.** Asıl soru budur, çünkü geçirgenlik kalınlıkla
üstel olarak çöker. Cevap şudur: genlik hiçbir şey kaybetmez. Gecikmenin doyması
için sönüm sabiti ile kalınlığın çarpımının büyük olması gerekir, ve genliği
belirleyen de tam olarak aynı çarpımdır. O çarpım sabit tutulduğunda genlik,
basılan bütün basamaklarda **değişmeden** kalır:

| Toplam enerji | Kalınlık | Genlik |
| ------------- | ------------ | --------------------------- |
| $6{,}84$ | $2{,}294157$ | $4{,}293312 \times 10^{-3}$ |
| $50$ | $0{,}848528$ | $4{,}293312 \times 10^{-3}$ |
| $500$ | $0{,}268328$ | $4{,}293312 \times 10^{-3}$ |
| $5000$ | $0{,}084853$ | $4{,}293312 \times 10^{-3}$ |

> Kısalan mesafenin bedelini genlik ödemez. Bedeli **daha yüksek enerji ve daha
> ince bir ara bölge** öder, ve bu ikisi birlikte hareket eder.

**İki nokta denetlendi ve doğrulanmadan geçilmedi.** Birincisi, sabit tutulan
derinlikte gecikmenin gerçekten doyup doymadığı. Dört enerjinin dördünde de
sonlu kalınlıktaki gecikme, doymuş değerin yüzde biri içinde kalmaktadır.
İkincisi, küçültülen niceliğin çalışmanın başka yerlerde karşılaştırdığı nicelikle
aynı olup olmadığı. Referans yapılanma $1{,}462864$ vermektedir, yani
Bölüm 13.4'ün doymuş değerinin tam olarak aynısını. Bu ikinci denetim önemsiz
değildir: tek geçiş ile gidiş dönüşü birbirine karıştırmak bu çalışmada iki kez
ikilik bir çarpan hatasına yol açmıştır.

**Bunun çalışmaya kattığı.** Bölüm 4.1.5'in geçirgenlik değeri, yani $d = 8$
için $3{,}46 \times 10^{-12}$, tek bir kalınlıkta okunmuş bir değerdir ve bir üst
sınır değildir. Aynı doyum derinliğinde daha yüksek enerjiyle çalışılırsa hem
gereken mesafe hem gereken kalınlık düşer, genlik ise yerinde kalır. Dolayısıyla
"mümkün, ama ağırlığı $10^{-12}$" cümlesi bir yasak bildirmez; yalnızca hangi
çalışma noktasının seçildiğini bildirir.

**Bir sınırlama olarak.** Yukarıdaki üç nicelikten ikisi zayıf kalmaktadır:
geçirgenlik yolun uzunluğunu hiç görmez, ve düz bir yol enerji istemez.
Üçüncüsü gerçek bir enerji artışı getirir, ancak sıradan bir Lorentz
dönüşümünün bir zaman aralığına uyguladığı çarpandan başkası değildir. Modelin
hesaplayamadığı şey yolculuğun kendi katkısıdır, ve nedeni yapısaldır: genliği
veren ifadedeki değişkenlerin hiçbiri parçacığın Bölge II'de ne kadar
gittiğine bağlı değildir.

**Literatürdeki en yakın sonuçtan farkı.** Engelin biçimini ve enerjiyi
ayarlayarak tünellemeyi güçlendiren mekanizmalar bilinmektedir, ancak onlar
**geçme olasılığını** artırır ve tek boyutlu olmayan bir engel ister. Bu
bölümün hesabı ise geçirgenliği değil, genlik sabit tutulurken **doymuş
gecikmeyi** küçültmektedir, ve kullanılan engel tek boyutludur. İki sonuç ne
aynı niceliği ne de aynı kurulumu ele almaktadır.

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

Bu çalışma tiplerden hiçbirini baştan seçmez. Hesap dört tip ve beş kalınlık
için ayrı ayrı yürütülmüş, sonuçlar yan yana konmuştur. Hangi tipin gerçekleştiği
modelin içinden çıkmaz. Modelin verdiği şey, her tipin hangi sonuçlara yol
açtığıdır.

### 5.1 Dört aday

**Ara bölge yok.** Bu ilk durumda iki bölge doğrudan birbirine değer ve aralarında
yalnızca bir yüzey kalır. O yüzeyde iki enine yön aynı anda karakter değiştirir,
yani metriğin rankı bir defada iki düşer.

**Kademeli yol** bu tek adımın alternatifini sunar: enine yönler aynı anda değil,
teker teker çevrilir. Yol $(1,3)$ imzasından $(2,2)$ imzasına, o imzadan da $(3,1)$
imzasına gider; her adımda yalnızca tek bir öz değer sıfırdan geçtiğinden rank da
yalnızca bir düşer. Aşağıdaki adaylardan ikincisi tam olarak bu yolun durağıdır.

**Kleinian, $(2,2)$.** Bu imzanın geometrisi ayrıca [60]'ta ele alınmıştır. Bu ara bölge iki zaman ve iki uzay ekseni taşır, çünkü
enine yönlerden yalnızca biri karakter değiştirmiştir. Yukarıda anılan kademeli
yol da bu noktada durur.

**Öklid, $(4,0)$.** İmza değişimi literatürünün büyük bölümü [58] ve [59] ile
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
ağırlıkla düşülmesiyle çıkar ve Bölüm 18.7'nin $\beta^2$ tanımıyla
$q_{\text{iç}}^2 = -\beta^2$ bağıntısıyla aynıdır.

**İç mod frekansa bağlıdır.** Bir ara bölgenin engel olup olmadığı yalnızca tipine
değil, gelen parçacığın frekansına da bağlıdır; sönme koşulu $q_{\text{iç}}^2<0$,
yani Bölüm 13.3'ün yazdığı $\omega^2 < c^2\big[(1+\tfrac{2n}{3})k_T^2+\mu\big]$
koşuludur. Aşağıdaki sınıflandırma bu koşulun tiplere göre okunuşudur:

| Tip | $n$ | İç mod | Sönme koşulu |
| -------- | --- | --------- | ----------------------------------------- |
| Yok | $0$ | Yayılır | Yok; $q_{\text{iç}}^2=\kappa^2>0$ |
| Kleinian | $1$ | Yayılır | $\omega^2 < c^2(\tfrac{5}{3}k_T^2+\mu)$ |
| Öklid | $3$ | Söner | $\omega^2 < c^2(3k_T^2+\mu)$ |
| Dejenere | - | Yayılamaz | Her zaman |

Bölüm 5.3'ün geçirgenlik tablosu $\omega^2 = 2c^2(k_T^2+\mu)$ yüzeyinde, yani
$\mu = 1$, $k_T^2 = 4$ için $\kappa^2 = 5$ değerinde hesaplanmıştır. O yüzeyde
Kleinian bölge $q_{\text{iç}}^2 = +7/3$ ile yayılımlı, Öklid bölge
$q_{\text{iç}}^2 = -3$ ile söndürücü çıkar. Frekans seçimi bu satırda kayda geçer,
çünkü tablonun iki satırı arasındaki niteliksel fark onunla birlikte durur.

Kleinian bölgenin kendi başına bir engel **olmaması** dikkate değerdir: iki
zamanlı bir bölge, madde için otomatik olarak kapalı değildir.

### 5.3 Geçirgenlik tablosu

$\mu = 1$, $k_T^2 = 4$ için dört tip ve beş kalınlıkta hesaplanan geçirgenlik:

| Tip | $d = 0$ | $d = 0{,}1$ | $d = 1$ | $d = 4$ | $d = 40$ |
| -------- | ------- | ----------- | --------- | -------------------- | --------------------- |
| Yok | $1$ | $1$ | $1$ | $1$ | $1$ |
| Kleinian | $1$ | $0{,}996$ | $0{,}868$ | $0{,}996$ | $0{,}871$ |
| Öklid | $1$ | $0{,}969$ | $0{,}111$ | $3{,}6\times10^{-6}$ | $2{,}5\times10^{-60}$ |
| Dejenere | $1$ | $0$ | $0$ | $0$ | $0$ |

Tablodan üç sonuç doğrudan okunmaktadır.

**Sıfır kalınlıkta tip önemsizdir.** İlk sütunda dört satırın dördü de bir verir,
yani kalınlığı olmayan bir ara bölge neyden yapıldığından bağımsız olarak her
şeyi geçirir. Öyleyse ara bölgenin tipi ancak bir kalınlığı varsa fizik taşır.

**Öklid bölge kalınlıkla üstel olarak kapanır.** Dört birim kalınlıkta
geçirgenlik milyonda üçe iner, kırk birimde ise altmış mertebe aşağı düşer. Bu
yüzden yeterince kalın bir Öklid bölge, dejenere katmandan ayırt edilemez hâle
gelir.

**Kleinian bölge hiçbir kalınlıkta kapanmaz, geçirgenliği salınır.** Geçirgenlik
kalınlık arttıkça tekdüze azalmaz, artıp azalır. İç mod bölgenin içinde
yayılabildiğinden bölge bir engel gibi değil, dalganın iki yüz arasında gidip
gelerek kendisiyle girişime girdiği bir **oda** gibi davranır. Kırk birim
kalınlıkta bile geçirgenlik yüzde seksen yedi civarında kalmaktadır.

**Literatürdeki karşılığı.** Bu tablonun üçüncü satırının bir öncülü vardır ve
karşılaştırma yapılmalıdır. [20] ve [21] kütlesiz skaler alanı iki boyutta imza
değiştiren bir metrik üzerinde taşır ve pozitif ile negatif frekansların
karışımını hesaplar. Bu karışım, saçılma dilinde bir geçiş katsayısıdır; eğri
uzayzaman kuramının dilinde ise [75] ile [76]'nın parçacık üretimidir.
O çalışmanın merkezi sonucu, karışımın **yalnızca Öklid bölgelerinin toplam konformal
genişliğine** bağlı olduğu, metriğin ayrıntılı biçimine bağlı olmadığıdır. [22]
aynı hesabı spin-$1/2$ için dener ve çözüm uzayında korunan bir iç çarpım
bulunmadığını gösterir.

İki sonuç birbiriyle çelişmez, aynı yapının iki farklı kesitidir:

| | [20], [21] | Bu çalışma |
| -------------------- | ------------------------------- | -------------------------------------------------- |
| Boyut | $1+1$ | $1+3$, enine momentum taşıyan |
| Kütle | Sıfır | $\mu \neq 0$ |
| Ara bölge tipi | Öklid | Dört tip birlikte |
| Kalınlık bağımlılığı | Yalnızca toplam genişliğe bağlı | Öklid satırında aynı; Kleinian satırında salınımlı |
| Ölçülen nicelik | Frekans karışımı | Tek modun geçirgenliği |

Öklid satırının kalınlıkla üstel kapanması, dolayısıyla bağımsız bir bulgu
değildir: profilin ayrıntısından bağımsız olarak yalnızca genişliğin sayması
[20]'nin sonucudur. Bölüm 8.1 bunu beş profille sınar ve toplamın üsteli
sabitlediğini, önçarpanı sabitlemediğini bulur.

Kleinian satırının da öncülü vardır ve bu satır bir kez fazla iddialı
yazıldıktan sonra bugünkü biçimini almıştır. [27] düz bir arka planda metriğin Lorentz
imzasından Kleinian imzaya geçtiği durumda düzlem dalgaların yayılmasını ele
alır. Geçiş süreksiz olduğunda tamsayı ve yarım tamsayı spinli madde farklı
davranır. Spin yapısı tarafı [28]'dedir. Dolayısıyla "Lorentz'den Kleinian'a
geçen dalga" sorusu 1994'te sorulmuştur.

Yukarıdaki tablonun ona eklediği şey **sonlu kalınlıktır**. [27] tek bir imza
değişimi yüzeyinden geçişi ele almaktadır. Bu bölümün hesabında ise ara bölgenin iki yüzü
ve aralarında bir kalınlığı var. Tablo o kalınlığın işlevini anlatır: Öklid
bölge kalınlık arttıkça kapanır, Kleinian bölge kapanmaz. Bunun nedeni, iki yüz
arasında yayılabilen bir iç modun ortaya çıkmasıdır: mod iki yüz arasında gidip
gelir ve kendisiyle girişime girer. Geçirgenlikteki salınım doğrudan kalınlığın
ürünüdür, ve tek yüzlü bir hesapta hiç görünmez.

Dolayısıyla bu tablonun kendine ait olan kısmı Kleinian imzanın kendisi değil,
**iki yüz arasındaki girişimdir**.

### 5.4 Eşiğin taşıdığı madde katmanı

Geçirgenlik sorunun yalnızca yarısını cevaplar. Kalan yarısını, geçişin yüzeyde
bıraktığı iz oluşturur.

Zayıf eklem koşulu seçildiğinde geçiş yüzeyinde dış eğrilik sıfırlanmaz, ve
sıfırlanmayan bir dış eğrilik bir **madde tabakasına** karşılık gelir. Bu
karşılığı [52] ile [53]'ün ince kabuk formalizmi kurmaktadır. Kalınlık sıfıra giderken tabaka noktasal bir terime iner. Sonlu
kalınlıkta ise geçiş bölgesinin içine yayılmış bir gerilim olarak durur
(Bölüm 6.2). Zayıf koşulun karşılığı budur: parçacığın geçmesine izin veren seçim,
aynı anda yüzeye bir madde tabakası koyar. Böyle bir tabakanın genel
formülasyonunu [17] vermiştir; o çalışma, imzanın değiştiği yüzeyin zamansal
olamaması da dahil olmak üzere konuyu tam olarak ele alır. Bu bölümün hesabı onun
bu geometrideki sayısal karşılığını çıkarmaktadır.

Tabakanın gücü, imzanın döndüğü mesafeyle ters orantılı gitmektedir. Hesaplanan
değerler:

| Tip | $d = 0{,}1$ | $d = 1$ | $d = 4$ |
| -------- | ----------- | ------- | -------- |
| Kleinian | $10{,}0$ | $1{,}0$ | $0{,}25$ |
| Öklid | $30{,}0$ | $3{,}0$ | $0{,}75$ |

Kalınlık on kat arttığında katman gücü on kata iner. Sıfır kalınlık limitinde
katman sınırsız büyür.

**İki eğilimin ürettiği gerilim.** İki eğilim birbirine terstir:

- Ara bölge inceldikçe geçiş kolaylaşır, ama madde katmanı sertleşir.
- Ara bölge kalınlaştıkça katman yumuşar, ama çoğu tip kapanır.

Onaltı hücrelik tabloda bu iki isteği aynı anda karşılayan tek hücre **kalın
Kleinian** bölgedir: geçirgenliği yüksek kalır ve katman gücü kalınlıkla düşer.
Bu bir seçim değil, tablonun kendisinden çıkan bir elemedir. Yine de bu çalışma
diğer üç tipi kapatmaz; sonraki bölümlerde gidiş dönüş hesabı dört tip için de
ayrı ayrı yürütülmüştür.

### 5.5 Katmandan kaçınma

Bölüm 6.2 üç geçiş profilini karşılaştırmıştır. Katmanın sıfırlanması, ancak
geçiş profilinin tam dönüm noktasında **durağan** olmasıyla mümkündür. Doğrusal
ya da $\tanh$ tipi bir profil bunu sağlamaz.

Dolayısıyla madde katmanı taşımayan bir geçiş vardır, ancak ince ayarlanmış bir
profil gerektirir. Sıradan bir profil için katman kaçınılmazdır. Modelin duruşu
şudur: katman genel durumda vardır, gücü kalınlıkla azalır ve yalnızca özel bir
profilde tümüyle kaybolur.

### 5.6 Katmanın enerji koşulları

Katmanın **var olması** ile **fiziksel olarak kabul edilebilir** olması ayrı iki
sorudur. İkincisi maddenin seçimiyle değil, yüzeyin nedensel karakteriyle
belirlenmektedir.

**Bağlayıcı olan, yüzeyin zamansal olmamasıdır.** İmzanın değiştiği bir yüzeyde
normal, karakterini değiştirir; dolayısıyla yüzey zamansal olamaz. Zamansal
kabuklar için kurulmuş sonuçlar bu yüzeye uygulanmaz. Zamansal olmayan yüzeyler
için geçerli kısıtlar ise çok daha sıkıdır. [16] bu sınıfı ayrı ele alır ve
enerji koşullarının o durumda zamansal duruma göre daraldığını gösterir. Aşağıdaki
hesabın hangi çerçevede okunması gerektiğini o sonuç belirlemektedir.

**Hesap.** Aşağıdaki sütunlarda anılan sıfır, zayıf ve baskın enerji koşulları
[54]'ün tanımlarıdır; koşulların bugünkü statüsünü [55] derlemektedir. Katmanın
taşıdığı yüzey enerji yoğunluğu ve basıncı, geçiş profili ailesinin her üyesi
için ayrı ayrı değerlendirilmiştir ($d = 1$):

| Profil | Yoğunluk | Basınç | Sıfır (null) | Zayıf | Baskın |
| ------------------------ | ---------- | ---------- | ------------ | ---------- | ---------- |
| Doğrusal | $-1{,}000$ | $+1{,}000$ | sağlar | sağlamaz | sağlamaz |
| Dönüm noktasında durağan | $0$ | $0$ | katman yok | katman yok | katman yok |
| $\tanh$ basamağı | $-1{,}000$ | $+1{,}000$ | sağlar | sağlamaz | sağlamaz |

Katman taşıyan hiçbir profil baskın enerji koşulunu sağlamaz. Kaçan tek profil,
hiç katman taşımayan durağan profildir; yani kaçış, koşulu sağlayarak değil,
kısıtlanacak bir şey bırakmayarak gerçekleşir.

**Kalınlık kurtarmıyor.** Ara bölge kalınlaştırıldığında katmanın gücü
kalınlığın tersiyle azalır, ancak yoğunluk negatif dalda kalmaya devam eder:

| Kalınlık $d$ | Yoğunluk | Baskın koşul |
| ------------ | ----------- | ------------ |
| $0{,}5$ | $-2{,}0000$ | sağlanmaz |
| $1$ | $-1{,}0000$ | sağlanmaz |
| $4$ | $-0{,}2500$ | sağlanmaz |
| $40$ | $-0{,}0250$ | sağlanmaz |

İhlal zayıflar, kaybolmaz.

**Sonuç ve bunun modele maliyeti.** Zayıf eklem koşulunun karşılığı, daha önce
yazıldığı gibi yalnızca "bir madde katmanı" değildir. Bedel, **baskın enerji
koşulunu ihlal eden** bir katmandır ve bu, daha iyi bir madde seçilerek
onarılamaz. Geriye kalan tek çıkış yolu, dönüm noktasında durağan profildir; o
da genel bir yapılanma değil, ince ayarlanmış bir özel durumdur.

### 5.7 Oran koşulu

Zayıf seçime karşı yöneltilmiş en güçlü itiraz felsefi değildir ve bu bölümde
felsefeyle değil, hesapla karşılanmaktadır. Alan denklemleri yüzey boyunca
yazıldığında, **normal türev çarpı delta bölü lapse** biçiminde bir terim doğar.
Lapse dönüm noktasında sıfıra gittiğinden bu terim sıfır bölü sıfır biçimini
alır, ve **ilan ederek sıfır sayılamaz**. Terim ancak pay paydadan daha hızlı
sıfırlanırsa düşer, ve bunu ayrı bir hesap göstermelidir. Hesap bunu
gösterirse terim düşer ve zayıf seçim geçerli kalır. Göstermezse terim kalır,
ve denklemler ancak normal türev tümüyle sıfırlanarak, yani güçlü koşul
benimsenerek tutarlı olur.

Böylece anlaşmazlık tek bir hesaplanabilir üstele inmektedir. Kullanılan metrik
ailesinde lapse, işaret değiştiren metrik bileşeninin karekökü gibi gider;
normal türev ise katman için zaten hesaplanmış dış eğriliktir. Oran, dönüm
noktasına doğru izlenmiştir:

| Profil | Oranın uzaklıkla üsteli | Sonuç |
| --------------- | ----------------------- | ------------------ |
| Doğrusal | $-0{,}500$ | terim sıfırlanmaz |
| Dönümde durağan | $+0{,}497$ | terim düşer |
| Tanh basamağı | $-0{,}500$ | terim sıfırlanmaz |

Üsteller iki ondalık mertebe boyunca kararlıdır; doğrusal profil için oran
$10^{-2}$ uzaklıkta $6{,}27$, $10^{-3}$ uzaklıkta $19{,}8$, $10^{-4}$ uzaklıkta
$62{,}7$'dir. Örnekleme bundan daha yakın alınamaz: sonlu fark kalıbının
genişliği ve dönümde durağan profilin çift duyarlıkta temsil edilebilirliği
oraya kadar izin verir, ötesi üstel değil yuvarlama gürültüsü verir. Genel
profiller **başarısız olur**. Yani itiraz, geçişin biçimi değiştirilerek
karşılanamaz; tıpkı enerji koşullarının karşılanamadığı gibi.

**Ve iki itiraz aynı profilde buluşur.** Oran koşulunu geçen tek profil, Bölüm
5.6'da enerji koşullarının tek kaçış yolu olarak bıraktığı profilin aynısıdır:
dönüm noktasında durağan olan, yani hiç katman taşımayan profil. Bu ailede, hem
katman taşıyan hem de oran koşulunu sağlayan bir profil **yoktur**.

**Ve hayatta kalan yapılanma, zayıf seçimin ince ayarlanmış bir örneği
değildir.** Dönümde durağan profilin dış eğriliği dönüm noktasında sıfırdır;
yani o profil **güçlü koşulu sağlar**. Öteki iki profil zayıf koşulu sağlayıp
güçlüyü sağlamaz, dolayısıyla aile iki seçimi gerçekten ayırmaktadır ve hayatta
kalanın kimliği parametrelendirmenin bir kazası değildir.

Ne var ki bu, bu ailede geçerli bir sonuçtur ve bir sonraki alt bölüm ailenin
kendisinin ne kadarını taşıdığını ölçmektedir.

### 5.7.1 Üstelin kapalı biçimi

Yukarıdaki üç sayı ölçümdür; kapalı bir biçimi vardır ve o biçim, engelin imza
değişiminin bir özelliği mi yoksa bu ailenin yazılış biçiminin bir özelliği mi
olduğunu belirlemektedir.

Literatürün genel olarak kullandığı reçetede iki koşul birlikte dayatılmıştır.
**Enine olma** koşulunu, dejenere bileşenin birinci mertebeden sıfırlanması
verir. Bu koşul iki şeyi sağlar: determinant birinci mertebeden sıfırlanır, ve
yüzey düzgün gömülü kalır. **Tümüyle jeodezik olma** ise dış eğriliğin
sıfırlanmasıdır ve dağılımsal kaynağı kaldıran koşul budur. Bu ikisi **farklı
bileşenleri** bağlar: enine olma dejenere bileşenin türevine, dış eğrilik ise
teğet bloğun normal türevinin lapse'a bölümünden çıkar. Bağımsız iki ayardır ve
ikisi birden sağlanabilir. Literatürün ikisini bir arada, aralarında bir gerilim
olduğunu belirtmeden dayatmasının sebebi budur.

Dejenere bileşenin sıfırlanma mertebesi $a$, teğet eğimin sıfırlanma mertebesi
$b$ ile gösterilir. Bu ifadede $q$ harfi kullanılmaz, çünkü $q$ çalışmanın geri kalanında
ara bölgedeki dalga sayısını taşır. Lapse $d^{a/2}$ gibi gider, dış eğrilik ise
$d^{b}$ gibi. Oran koşulunun sınadığı nicelik ise uzaklığın

$$b - \frac{a}{2}$$

kuvvetiyle davranmaktadır. Bu, dokuz $(a,b)$ çifti üzerinde ölçümle $10^{-9}$
duyarlıkla doğrulanmıştır.

| $a$ | $b$ | Ölçülen üstel | Kapalı biçim |
| --- | --- | ------------- | ------------ |
| 1 | 0 | $-0{,}5000$ | $-0{,}5000$ |
| 1 | 1 | $+0{,}5000$ | $+0{,}5000$ |
| 1 | 2 | $+1{,}5000$ | $+1{,}5000$ |
| 2 | 0 | $-1{,}0000$ | $-1{,}0000$ |
| 2 | 1 | $-0{,}0000$ | $0{,}0000$ |
| 2 | 2 | $+1{,}0000$ | $+1{,}0000$ |
| 3 | 0 | $-1{,}5000$ | $-1{,}5000$ |
| 3 | 1 | $-0{,}5000$ | $-0{,}5000$ |
| 3 | 2 | $+0{,}5000$ | $+0{,}5000$ |

Bölüm 5.7'deki aile bu formülün $b = a - 1$ dilimidir, çünkü o ailede dış eğrilik
teğet bloktan değil, **işaret değiştiren bileşenin kendisinden** gelir. Bu
dilimde üstel $a/2 - 1$ olur ve enine olma $a = 1$ demek olduğundan üstel
zorunlu olarak $-1/2$ çıkmaktadır. Aynı formül, o ailenin sayısal olarak ölçtüğü üç
üsteli de aynen vermektedir. Yani:

> Bölüm 5.7'nin engeli, imza değişiminin bir özelliği değil, o ailede dış
> eğriliğin hangi bileşenden okunduğundan çıkar. Genel reçetede enine, tümüyle
> jeodezik ve oran koşulunu sağlayan bir yapılanma **vardır**; üsteli
> $+1/2$'dir.

Dahası oran koşulu, tümüyle jeodezik olma koşuluna bir şey **eklemez**; onu bir
hız olarak yeniden ifade eder. Oranı tam olarak teğet eğimin dönüm noktasında
sıfırlanması sağlar, ki bu koşulun kendisine karşılık gelir.

**Ayakta kalan engel başkadır.** Bir yüzey tabakasının doğması için dış
eğriliğin dönüm noktasında sıfırdan farklı olması gerekir. Oran koşulu ise aynı
eğriliğin lapse'tan daha hızlı sıfırlanmasını ister. Sınanan oran dış eğriliğin
tam iki katı olduğundan, "tabaka taşımak" ile "oranı geçememek" **aynı nicelik
üzerinde yapılan aynı ölçüme** dönüşür. İkisinin bir arada bulunamaması bir
arama sonucu değil, doğrudan bu aritmetiğin sonucudur. Seksen bir mertebe çifti
taranmış ve ikisini birden sağlayan tek bir çift bile çıkmamıştır.

Bu, literatürün zaten taşıdığı güçlü ile zayıf ayrımıdır. Bu çalışmanın yolu ona iyi
tanımlı bir Ricci tensörü yerine bir hız üzerinden yaklaşmaktadır. **Yeni bir
engel iddiası bulunmamaktadır.** Bölüm 5.7'nin sonucuna iliştirilmiş özgünlük
payı bu nedenle geri çekilmiştir. Ayakta kalan katkı engelin kendisi değil,
üstelin iki parametreli kapalı biçimidir.

Dejenere bileşenin sıfırlanma hızını tek bir parametreyle sınıflandıran bir
çalışma [57]'de bulunmaktadır. Teğet bloğun mertebesini ikinci bir
parametre olarak taşıyan bir sınıflandırma ise yoktur; eğrilik ile lapse oranını
bu iki mertebenin bileşimi olarak veren bir çalışma da yoktur.

**Kapsamı.** Bu itiraz geçişin **geometrisini** bağlar, yani metrik ara
değerlemesinin dönüm noktasındaki davranışını. Mod geçirgenliği ise ayrı bir
eksende durur: ara bölgenin tipine bağlıdır, ara değerleme profiline değil. İki
eksen hesapta bağımsızdır. Bu bağımsızlığın fiziksel olarak savunulabilirliği
açık kalır ve Bölüm 21.2 onu açık olarak sayar. Geçirgen okumanın daha geniş bir
geçiş ailesindeki temsilcisi ise yukarıdaki kapalı biçimle bulunmuştur.

### 5.8 Çekinceler

Üç varsayım vardır.

Bölüm 5.3'ün geçirgenlik tablosu, enine dalga sayısının yönler arasında eşit
paylaşıldığını varsayar. Parçacık dalga sayısının çoğunu tam da karakter değiştiren yönde
taşıyorsa Kleinian bölge de kapanır. Kleinian bölgenin açık olması bu nedenle
mutlak değil, **mod içeriğine bağlıdır**. Bölüm 13.3'ün mod filtresi sonucu
aynı olgunun başka bir yüzüdür.

Dejenere katman, içeride hiçbir modun yayılamayacağı biçiminde modellenmiştir.
Gerçek bir dejenere metrik hesabı daha incedir ve tam sıfır vermeyebilir.

Madde tabakasının gücü doğrudan hesaplanmamış, imza dönüşünün dik eğimi
üzerinden dolaylı bir ölçüyle alınmıştır. Tam gerilim tensörü çıkarılmamıştır.

---

## 6. Eşik yüzeyi ve eklem koşulu

İki bölgeyi ayıran eşik yüzeyi aşağıda $\Sigma$ ile gösterilmektedir. Bir alanın
bu yüzeyden geçebilmesi için iki koşul gerekir, ve bu ikisine **eklem koşulu**
adı verilir:

1. Alan sürekli: $\psi_I|_\Sigma = \psi_{II}|_\Sigma$
2. Konjuge momentum sürekli: $\pi_I|_\Sigma = \pi_{II}|_\Sigma$

Bu iki koşuldan ikincisi beklenmedik bir sonuç doğurur. Yüzeyin normali Bölge
I'de zaman-benzeri, Bölge II'de ise uzay-benzeri olduğundan $\pi_{II} = -\pi_I$
çıkar, ve ikinci koşul ancak

$$\pi|_\Sigma = 0$$

olursa sağlanabilir. Bu eşitliğe **düğüm koşulu** adı verilir, ve anlamı şudur:
eşik yüzeyinde parçacık akısı sıfıra iner.

**Sonuç:** $\Sigma$ geçirgen değil, **yansıtıcıdır**. Kütleli madde eşikten
geçemez, tam yansır. Bu sonuç çalışmanın geri kalanıyla çelişir görünmektedir,
çünkü Bölüm 1 eşiği geçirgen almıştı. Çelişki görünüştedir ve Bölüm 6.1
çözmektedir: yukarıdaki hesap **güçlü** eklem koşulunu kullanır, oysa aynı
denklemler **zayıf** eklem koşuluyla da tutarlıdır ve zayıf koşul geçişe izin
verir. İki koşul arasındaki seçimi geometri yapmaz.

**İstisna.** Kütlesiz durumda, yani $\mu = 0$ için koşul kendiliğinden sağlanır.
Ancak kütlesiz alan zaten $c$ hızında gittiğinden onun geçmesi de gerekmez.

Bu sonuç modele elle konmamış, doğrudan kendi Lagrangian'ından çıkmıştır.

Aynı sonucun dispersiyon tarafındaki karşılığı şudur: faz hızı ile grup hızının
ikisi birden $c$'ye ancak $\mu = 0$ için eşitlenir. Kütleli bir alanda faz hızı
$c$'yi aşar, grup hızı ise $c$'nin altında kalır. Yani parçacık eşiği aşmaz,
ona yalnızca **teğet** geçer.

### 6.1 Seçimin belirleyiciliği

Yukarıdaki iki koşulun birlikte dayatılması masum bir adım değildir, çünkü imza
değişimi literatüründeki tartışmalı nokta tam olarak budur. Soru şudur: dış
eğrilik yüzeyde yalnızca **sürekli** mi kalmalı (*zayıf* imza değişimi), yoksa
**sıfırlanmalı** mı (*güçlü*). [5] sekiz aday eylem yazıp her birinin hangi
koşulu verdiğini incelemiş ve ikisini de savunulabilir bulmuştur. [6] daha ileri gider: imza
değişiminde kanonik Einstein denklemleri diye bir şey yoktur, seçim yapılmak
zorundadır; [8] aynı noktayı yineleyip herhangi bir seçimi "asıl" denklemler
diye adlandırmanın retorik kaldığını gösterir.

Yukarıdaki $\pi|_\Sigma = 0$ sonucu **güçlü** koşuldur. Aynı sonucu başka bir
yoldan [4] daha önce elde eder. O çalışmada Klein-Gordon alanı imza değiştiren bir
arka planda ele alınır. Eklem koşulu, alan denklemlerindeki Dirac dağılımının
katsayısı olarak $\phi' \delta = 0$ biçiminde **türetilir**, yani denklemleri
anlamlı kılmak için varsayılmaz. Bu bölümün türetimi
Lagrangian'dan gider ve aynı yere varır.

Lagrangian yolunun kendisi de öncesiz değildir. [21] kütlesiz skaler alanı iki
boyutta imza değiştiren bir metrik üzerinde ele alır. Eklem koşulunu iki ayrı
yoldan sabitler: uzaysal olarak homojen hâlde momentumun korunmasını istemek, ve
doğal bir Lagrangian'dan varyasyon almak. İkisi aynı yere varır ve elde edilen
çözümlerin dağılımsal dalga denklemini her yerde sağladığı gösterilmiştir. Bu çalışmadaki
türetim aynı ailenin dört boyutlu ve kütleli üyesidir; yeni olan koşulun kendisi
değil, hangi geçiş profillerinin onu sağlayabildiğidir (Bölüm 5.5).

Yine de bu çizgi tartışmalıdır: [24] koşulun verdiği çözüm sınıfını reddederken
[23] onu savunmaktadır. Aşağıdaki hesap tartışmanın hangi tarafında durulduğunu
değiştirmez; yalnızca seçimin ne kadar belirleyici olduğunu ölçer.

Ölçüm için $\Sigma$ üzerinde bir mod saçılması kurulmuştur. Normal koordinat
$\xi$ ile gösterilir; Bölge I $\xi<0$ tarafında, Bölge II ise $\xi>0$ tarafında
kalır:

$$\phi = e^{i\kappa\xi} + R\,e^{-i\kappa\xi}, \qquad
 \psi = T_+ e^{i\kappa\xi} + T_- e^{-i\kappa\xi}$$

Bölge II'de iki genlik birden tutulur, çünkü Bölge II'de zaman sıralaması olmadığı
için "dışarı giden dalga" koşulu **tanımlanamaz**.

İlk gözlem şudur: normal doğrultudaki indirgenmiş denklem iki tarafta da aynı
kalır,

$$\frac{d^2}{d\xi^2} + \kappa^2 = 0, \qquad \kappa^2 = c^2(k_T^2 + \mu)$$

yani dalga yüzeye geldiğinde ortam değişmiş gibi bir **basamakla karşılaşmaz**.
Geçirgenliği belirleyen tek şey, momentum eşleşmesinin işaretidir.

Eklem koşulları $1 + R = T_+ + T_-$ ve $1 - R = s\,(T_+ - T_-)$ olur; bu ifadede
güçlü koşul için $s = -1$, zayıf koşul için $s = +1$. Akılar $F_I = 1 - |R|^2$
ve $F_{II} = |T_+|^2 - |T_-|^2$ ile verilir. Sonuçlar:

| Koşul | Dışarı-giden çözüm | Akı korunumu | Sonuç |
| --------------- | ----------------------------- | --------------------- | --------------------------------- |
| Güçlü, $s=-1$ | Yok, sistem aşırı belirlenmiş | Ancak $\|R\| = 1$ ise | **Tam yansıma, zorunlu** |
| Zayıf, $s=+1$ | Var, $R = 0$ | Her $R$ için | Geçirgen, ama miktar **belirsiz** |
| Dirichlet duvar | Bölge II ayrık | $R = -1$ | Tam yansıma |
| Neumann duvar | Bölge II ayrık | $R = +1$ | Tam yansıma |

Tablonun ilk satırı şöyle çıkar. Güçlü koşulda $T_+ = R$ ve $T_- = 1$ olur,
dolayısıyla $F_{II} = |R|^2 - 1 = -F_I$ elde edilir. İki akı ancak
$1 - |R|^2 = 0$ olduğunda eşitlenebilir, yani **tam yansıma ek bir varsayım
değil, akı korunumunun tek çözümüdür.** Böylece Bölüm 6'nın sonucu bir seçimin
ürünü olmaktan çıkar ve o seçim verildiğinde bir zorunluluğa dönüşür.

Zayıf koşulda ise $T_+ = 1$, $T_- = R$ olur ve akı **her** $R$ için korunur.
Zayıf koşul geçişe izin verir, ancak ne kadarının geçtiğini vermez. Bölge
II'de dışarı giden dalgayı seçecek bir koşul kurulamadığından $R$ serbest kalır.
Yani zayıf koşul "geçiş vardır" demekten çok, "bu problem iyi konumlanmamıştır"
demektedir, ve bu da yukarıdaki sonuçla tutarlı kalır.

Tablodaki dört durumdan üçü yansıtmaktadır. Bunların içinde en dikkate değeri
[9]'un öz-eşlenik genişlemelerden çıkardığı **Dirichlet** koşuludur: bu çalışmadaki
Neumann koşulunun tersi olmasına rağmen aynı yere varır, ve o koşulda da Minkowski
bölgesi Kleinian bölgeden kopar. Öyleyse "eşikten akı geçmez" sonucu Neumann ile
Dirichlet arasındaki tercihe duyarlı **değildir**, ve duyarlı olduğu tek şey
güçlü ile zayıf arasındaki tercih olarak kalır.

Buna karşılık [9] bir uyarı da içerir: kuantum alanların varlığı bu duvarları
**kararsız** kılar, Kleinian bölge ya çöker ya sınırsız genişler. Bu bölümde
soruya girilmemiştir ve açık bırakılmaktadır.

### 6.2 Seçimin yerçekimi görünümü

Yukarıdaki tercih madde tarafında, konjuge momentum üzerinden yapılmıştı. Aynı
tercih geometri tarafında yeniden belirir, ve geometri tarafında geçiş yüzeyinin **dış
eğriliği** üzerine konan bir koşula dönüşür: güçlü koşul onun yüzeyde sıfırlanmasını, zayıf
koşul yalnızca sürekli olmasını ister [5]. [6]'nın genelleştirilmiş Lanczos
denklemine göre gerilim tensöründe dağılımsal bir terim, yani bir **yüzey
katmanı**, tam olarak dış eğrilik sürekli olduğunda yoktur.

Bunu somutlaştırmak için Bölüm 5.1'deki kademeli yolun ilk adımı bir
koordinatın fonksiyonu yapılır:

$$g(\xi) = \mathrm{diag}\big(1,\, -\cos\lambda(\xi),\, -1,\, -1\big),
 \qquad \xi \in [-1, 1]$$

İmza, $\lambda$'nın $\pi/2$'yi geçtiği yerde değişir. Sabit $\xi$ yüzeylerinin
dış eğriliğinin tek önemsiz bileşeni

$$K = \tfrac{1}{2}\,\frac{d g_{11}}{d\xi}
 = \tfrac{1}{2}\,\lambda'(\xi)\,\sin\lambda(\xi)$$

olur ve geçiş noktasında $\sin\lambda = 1$ olduğundan geçiş noktasında $K = \lambda'/2$'ye
indirgenmiştir. Üç profil şu değerleri verir:

| Profil | Geçişte $K$ | Güçlü koşul | Zayıf koşul |
| ------------------------------------------- | ----------- | -------------- | ----------- |
| Doğrusal, $\lambda = \pi(\xi+1)/2$ | $0{,}785$ | Sağlanmıyor | Sağlanıyor |
| $\tanh$ basamağı | $2{,}368$ | Sağlanmıyor | Sağlanıyor |
| $\lambda = \pi/2 + (\pi/2)\sin^3(\pi\xi/2)$ | $0$ | **Sağlanıyor** | Sağlanıyor |

**Sonuç.** Güçlü koşul varılan metriği kısıtlamaz, ona **nasıl yaklaşıldığını**
kısıtlar: geçiş profili tam dönüm noktasında durağan olmalıdır. Doğrusal ya da
$\tanh$ tipi bir geçiş bunu sağlamaz, ve $\tanh$ en kötüsü çıkar, çünkü en dik
olduğu yer tam geçiş noktasına denk gelir.

Buna karşılık üç profilin hiçbirinde noktasal bir yüzey tabakası doğmaz, çünkü
dış eğrilik her üçünde de süreklidir. Yani Bölüm 6.1'deki ayrım gerilim
tensöründe noktasal bir terim olup olmaması meselesi değildir; profilin geçişe
teğet gelip gelmediği meselesidir.

**Bölüm 5.4 ile bunun bağı.** İki hesap aynı geçişin iki idealleştirmesine
bakar, ve sonuçları birbiriyle çelişmez. Bu kurguda geçiş sonlu bir aralığa yayılır
ve profil düzgündür; dış eğrilik süreklidir, dolayısıyla delta terimi yoktur.
Bölüm 5.4 ise geçişi kalınlığı $d$ olan bir katmana sıkıştırır ve gücün
$1/d$ ile gittiğini bulur; o güç, bu bölümdeki sürekli eğriliğin sıfır kalınlık
limitinde aldığı biçimdir. Dolayısıyla "katman" sözcüğü Bölüm 5.4 ile Bölüm
5.6'da dağılımsal bir terimi değil, geçiş bölgesinin sonlu kalınlıkta taşıdığı
etkin gerilimi adlandırır. Bölüm 5.6'nın enerji koşulu hükmü o etkin gerilime bakmaktadır ve sonlu
kalınlıkta da sıfırlanmaz. Sonlu kalınlıkta kaybolan tek şey, terimin noktasal
olmasıdır.

Bu, modelin yerçekimi tarafına atılmış ilk adımdır ve sınırlıdır: Einstein
denklemleri çözülmemiş, yalnızca eklem koşulunun geometrik karşılığı
hesaplanmıştır. [6] ve [8]'in uyarısı bu kurgu için de geçerli kalır: imza değişiminde
kanonik bir alan denklemi kümesi yoktur. Hangi formülasyonun kullanıldığını
söylemek gerekir. Kullanılan formülasyon [6]'nınkidir, yani dış eğriliğin
süreksizliğini gerilim tensörünün dağılımsal terimine bağlayan formülasyon.

Bu formülasyonun pratik aracı [7]'dedir. Öz-zaman koordinat olarak alındığında,
imza değişimi boyunca düzgün genelleştirilmiş ortonormal çatılar tanımlanabilir.
Bu da hem Einstein denklemlerinin varyasyonel türetimini hem dağılım teorisini
kullanılabilir kılar; ikisi de sabit imzadaki hâllerinin doğrudan genellemesi
olur. Modelin yerçekimi tarafına daha ileri götürülmesi istenirse başlangıç
noktası bu satırdır.

## 7. Geometrinin izin verdiği geçiş

Bölüm 6.1'in sonucu akı hakkındaydı. Ondan ayrı ve daha zayıf bir soru daha
sorulabilir: bir eğrinin teğeti yüzeyi geçerken nedensel karakterini koruyor mu.
Bu soruyu cevaplamak için iki metriğe bakmak yeter, çünkü cevabı yalnızca
aralarındaki farka bağlıdır:

$$v^T \eta' v - v^T \eta\, v = 2\,(v_1^2 + v_2^2) \;\geq\; 0$$

Sağ taraf bir kareler toplamı olduğundan fark hiçbir zaman negatif olamaz, ve
sonuç doğrudan çıkar:

> Bölge I'de zaman-benzeri olan **her** yön, Bölge II'de de zaman-benzeridir.

Bu kapsama tek yönlüdür, tersi doğru değildir: örneğin $(0,1,0,0)$ yönü Bölge
I'de uzay-benzeri, Bölge II'de ise zaman-benzeridir. Dolayısıyla Bölge II'nin
zaman-benzeri yönleri kesin olarak daha fazladır.

**Ayrımın önemi.** Eşikte bir eğriyi durduran nedensel bir engel **yoktur**;
teğeti karakterini koruyarak geçer. Bölüm 6.1'in yasakladığı şey akıdır ve akı
eğrinin teğetinin değil, alanın ve eklem koşulunun bir özelliğidir. Dolayısıyla
şu iki ifade birbiriyle çelişmez:

- Yüzeyden geçen geometrik eğriler vardır.
- Yüzeyden akı geçmez.

Bu ayrım, Bölüm 9.4'te değinilen ilmek teoremiyle bu modelin eşik sonucunun
aynı anda doğru olabilmesinin nedenidir: o teorem geometrik eğriler hakkındadır,
bu bölümün sonucu alan akısı hakkındadır.

## 8. Sonlu kalınlıkta dilimden geçiş

Bölüm 6.1 Bölge II'yi **sınırsız** kabul etmektedir. Oysa sonlu kalınlıkta bir
dilim ayrı bir problemdir, ve sonucu da farklı çıkar.

Bu ayrımı ilk kuran [15] olmuştur ve o çalışma bu bölümün öncülüdür. O çalışmada
Klein-Gordon parçacıklarının Lorentzian imzadan Kleinian imzaya geçişi
incelenir, düzlemsel bir sınırda parçacık akısı için **ayna davranışı** bulunur,
ve ardından sonlu kalınlıkta bir çift eklem ele alınarak **tünelleme olasılığı**
gösterilmiştir. Dikkat çekici olan, o çalışmadaki geçişin $(-,+,+,+) \to (-,+,+,-)$
olması, yani Bölüm 5.1'deki kademeli yolun tam olarak birinci adımıdır.

Aynı hesap bu modelin değişkenleriyle yapıldığında şu çıkmaktadır. Dilimin dışında
normal doğrultudaki dalga sayısı karesi daima pozitiftir; içeride ise işaret
değiştiren yön yeterince dalga sayısı taşıdığında negatife döner, yani iç mod
**yayılmaz, söner**. Bu durumda geçirgenlik

$$T(d) = \left[1 + \frac{(\kappa^2+q^2)^2}{4\kappa^2 q^2}\,
 \sinh^2(q d)\right]^{-1}$$

olur. Öklid ara bölge için, yani enine dalga sayısının tamamı karakter değiştiren
yönde iken ($\mu = 1$, $k_T^2 = 4$, dolayısıyla $\kappa^2 = 5$ ve $q^2 = -3$),
hesaplanan değerler:

| Kalınlık $d$ | $T$ |
| ------------ | ------------------------ |
| $0{,}5$ | $4{,}95 \times 10^{-1}$ |
| $1$ | $1{,}11 \times 10^{-1}$ |
| $2$ | $3{,}67 \times 10^{-3}$ |
| $4$ | $3{,}60 \times 10^{-6}$ |
| $8$ | $3{,}46 \times 10^{-12}$ |

Bu satırlar Bölüm 5.3'ün Öklid satırıyla aynı engeli anlatır ve onunla tam
olarak örtüşür; iki bölüm aynı bölgeyi iki ayrı yoldan hesaplar.

**Sonuç ve Bölüm 6.1'in yeniden okunması.** Geçirgenlik hiçbir sonlu kalınlıkta
sıfır değildir, ancak kalınlıkla üstel olarak bastırılır. Dolayısıyla Bölüm
6.1'in tam yansıması ayrı bir ifade değil, bu ifadenin **kalın dilim
limitidir**. Sıfır kalınlıkta her şey geçer, kalın dilimde hiçbir şey geçmez.

Buna ikinci bir koşul daha eklenir, çünkü iç modun sönümlü olup olmadığını gelen
alanın mod içeriği belirler. İşaret değiştiren yön az dalga sayısı taşıyorsa iç
mod yayılmaya devam eder, ve geçirgenlik bastırılmak yerine **salınır**,
rezonansta bire kadar çıkar. Öyleyse engeli imza değişiminin kendisi
değil, gelen alanın mod içeriği yaratmaktadır.

İki koşul birlikte Bölüm 6.1'in sonucunu geçersiz kılmaz, yalnızca kapsamını
daraltır: eşiğin yansıtıcı olması, Bölge II'nin sınırsız olduğu ve gelen modun
uygun içerikte kaldığı durum için geçerlidir.

### 8.1 Geçirgenliği belirleyen toplam

Yukarıdaki hesap sönüm katsayısını dilim boyunca sabit almaktadır. Gerçek bir
geçişte katsayı konuma bağlıdır ve o zaman şu sorulur: geçen şeyi profilin
**biçimi** mi belirler, yoksa yalnızca **integrali** mi?

Soruyu cevaplamak için beş profil, integralleri eşit tutulacak biçimde
karşılaştırılmıştır: düz, üçgen, yarım sinüs, plato ve çarpık. Aralarındaki biçim
farkı gerçektir ve hesaba girer, çünkü kenara yakın bölgede biçimlendirilmiş bir
profil düz profilin dörtte birinden az sönüm taşırken merkezde onu belirgin
biçimde aşar. Bir uyarı da bu karşılaştırmadan doğar: üçgen profil ile düz profil bir iç
noktada tam olarak kesişir, dolayısıyla yalnızca tek bir noktaya bakan bir
karşılaştırma aralarında hiçbir fark bulamazdı.

Bütün bu biçim farkına karşın geçirgenliğin üsteli, biçimden bağımsız olarak
toplamın belirlediği bir değere yakınsamaktadır:

| Toplam | Üstelin bütün biçimlerde düştüğü aralık | Biçimler arası yayılım |
| ------ | --------------------------------------- | ---------------------- |
| $4$ | $[0{,}8268,\ 0{,}9336]$ | $0{,}1068$ |
| $8$ | $[0{,}9412,\ 0{,}9704]$ | $0{,}0292$ |
| $16$ | $[0{,}9806,\ 1{,}0038]$ | $0{,}0232$ |
| $32$ | $[0{,}9952,\ 1{,}0221]$ | $0{,}0270$ |

Yayılım toplam büyüdükçe daralmakta ve üstel beş profilde de birin yirmide biri
içinde kalmaktadır: düz $1{,}02172$, üçgen $1{,}00127$, yarım sinüs $1{,}00236$,
plato $1{,}00485$, çarpık $1{,}00383$.

**İfadenin tam biçimi, ondan güçlüsü değil.** Biçim tümüyle görünmez de değildir:
toplamları eşit olan iki profil $2{,}881 \times 10^{-7}$ ve
$1{,}807 \times 10^{-7}$ geçirmekte, yani farklı sayılar vermektedir. Toplamın
sabitlediği şey **üsteldir**, üstelin önündeki çarpan değil. Bu ayrım yerinde
durmalıdır, çünkü "geçen şeyi yalnızca toplam belirler" cümlesi olduğu gibi
alındığında yayımlanmış sonuçtan daha güçlü bir iddia hâline gelir.

Bu sonucun modeldeki yeri şudur: geçirgenliğin mertebesini ara bölgenin
**ayrıntılı profili** değil, yalnızca toplam sönüm belirlemektedir. Dolayısıyla Bölüm
5'in profil ailesi üzerinde yapılan tartışmalar geçirgenliğin mertebesini
değiştirmez; profilin bağladığı şey, Bölüm 5.6 ile Bölüm 5.7'de görüldüğü gibi,
katman ve oran koşuludur.

---

# Kısım III. Karşı taraf

## 9. Bölge II'de zaman ve mekân

Bu bölüm üç soruyu sırayla cevaplar: Bölge II'de hangi nicelikler korunur, hangi
roller yer değiştirir, ve "yolculuk" sözcüğü o kurguda ne anlama gelir. Sonucu
taşıyan adım, o kurguda zamanın bir yönünün bulunmamasıdır.

### 9.1 Noether yükleri

Bölge II'nin Lagrangian'ı $L'$, dört koordinatın hiçbirine açıkça bağlı değildir.
Bu yüzden dört öteleme simetrisi taşır, ve her biri korunan bir yük verir:

- üç "enerji" bileşeni ($t_1, t_2, t_3$ ötelemeleri),
- tek "momentum" ($r$ ötelemesi).

Aynı Lagrangian üç zaman ekseni arasındaki $O(3)$ dönmeleri altında da değişmez
kalır. Bu simetriden üç korunan "zamansal açı momentumu" daha çıkar, ve bunlar Bölge
I'in uzaysal açı momentumunun aynasıdır.

### 9.2 Rollerin tersine dönmesi

Aşağıdaki tablo Bölüm 10.1'in sözlüğünün rol tarafıdır; koordinat karşılıkları
Bölüm 10.1'de, rollerin karşılaştırması ise bu bölümde durmaktadır.

| | Bölge I | Bölge II |
| ---------------------- | ---------------- | ----------------------------- |
| Serbest hareket | Uzayda, üç yönde | Üç zamanda serbestçe |
| Tek yönlü zorunluluk | Zamanda | Tek uzay ekseninde |
| $O(3)$ dönme simetrisi | Uzaysal | Zamansal |

### 9.3 Ayrım ve zorunluluk

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
bulunmaz (Bölüm 9.4), dolayısıyla zamanın okunu duruma yazma imkânı da doğmaz.

**Kapsam dışı bırakılan.** Aynı sonuca varan felsefi tartışma ve literatürdeki
"zamansız" programların taraması bu alt bölümün dışındadır; sonucu
değiştirmezler.

### 9.4 Zaman yöneliminin yokluğu

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

**Literatürdeki karşılığı.** [11], imza değiştiren bir manifoldun geçiş
hiperyüzeyinde, her noktadan geçen ve zaman yönünü tersine çeviren kapalı
sözde-zaman-benzeri ilmekler bulunduğunu ispatlar. Vardıkları sonuç kelimesi
kelimesine bu çalışmadakiyle aynıdır: gelecek ve geçmiş yönlü vektörler arasında
tutarlı bir ayrım yapılamaz.

Yollar farklıdır. [11] sonucu geçiş hiperyüzeyinin geometrisinden, Lorentzian
bölgede global hiperboliklik varsayarak elde eder; bu çalışmada ise yalnızca zaman
yönlerinin sayısından, hiperyüzey hakkında hiçbir varsayım yapmadan çıkar.

İki çekince var. Birincisi, [11]'in hipotezlerini bu modelin geçişi
**sağlamaz**. O kurguda bir taraf Riemann imzalıdır ve dejenerelik transvers radikal
tipindedir; bu çalışmanın doğrudan geçişinde ise rank iki düşer. Ortak olan
sonuçtur, ispat değildir. Buna karşılık Bölüm 5.1'in kademeli yolu her adımda
rank-1 dejenereliğe sahiptir, yani [10] ve [11]'in geometrik çerçevesine bu özellikten
bakıldığından daha yakındır.

İkincisi, [11]'in ilmekleri alışıldık anlamda kapalı zaman-benzeri eğriler
**değildir**: kesişim noktalarında hareket yönünün aynı olması gerekmez. Bu
nedenle sonuç, maddenin zamanda geriye gitmesi biçiminde okunamaz. [11] kendi
fiziksel yorumunu da verir: hiperyüzey yakınındaki bir gözlemciye böyle bir
ilmek, iki ayrı noktada bir parçacık-karşıparçacık çiftinin yaratılması gibi
görünebilir.

İlk bakışta bir çelişki görünür: Bölüm 6.1 eşiğin geçirgen olmadığını verirken,
[11] yüzeyden geçen ilmeklerden söz etmektedir. Çelişki yalnızca görünüştedir ve
Bölüm 7 onu çözer. İki metrik arasındaki fark bir kareler toplamıdır, dolayısıyla Bölge I'de
zaman-benzeri olan her yön Bölge II'de de zaman-benzeridir. Yani eşikte bir
eğriyi durduran nedensel engel yoktur. Yasaklanan şey akıdır. Geometrik eğriler
ile alan akısı farklı nesnelerdir ve iki sonuç aynı anda doğru olabilir.

**Bir itiraz.** [14], iki zamanlı dinamikte olasılık korunumu bir kez
dayatılınca fazladan zaman ekseninin ne kadar görünür kaldığını ölçmektedir. Klasik
$1+2$ boyutta Newton'un ikinci yasası tam olarak integre edilebilir ve her
başlangıç koşulu için **etkin tek zamanlı** bir evrim verir. Kuantum tarafta ise
düzey aralıkları, toplam süre ve $\hbar$ içeren genelleştirilmiş bir belirsizlik
bağıntısı çıkar. Bu, üç zamanlı Bölge II'nin dışarıdan bakıldığında tek zamanlı
görünebileceği anlamına gelir.

[14] bu çalışmanın formülasyonundan bir noktada ayrılır: o formülasyonda evrim üniter ve olasılık
koruyan bir yapı ister. Yukarıdaki hesap ise Bölge II'de o talebin dayandığı
yapıyı bulmamaktadır. Yine de bu itiraz açık bir soru olarak durur; model onu
kendi lehine kapatmamıştır.

### 9.5 Yolculuğun tanımı

Parçacığın Bölge II'de yapabilecekleri iki bağımsız etiketle tükenir.

**Hangi yüzden çıktığı.** Ara bölgenin iki yüzü vardır ve parçacık girdiği
yüzden geri dönebilir, karşı yüzden çıkabilir, ya da hiç çıkmayabilir.

**Enerji vektörünün ne kadar döndüğü.** Bölüm 15.3'te gösterildiği gibi
yönelimin kendisi Bölge II'de ayar fazlalığıdır; fiziksel olan tek şey giriş ile
çıkış arasındaki **bağıl** dönmedir. Üç sınıf ayırt edilir: dönme yok, kısmi
dönme ve tam ters çevirme.

İki etiket birlikte üç çarpı üç, yani dokuz hücrelik bir tablo verir. Bölüm 16
bu hücrelerin her birinin Bölge I'de nasıl göründüğünü tek tek hesaplamıştır.

## 10. Bölge II'de hareket ve yönelim

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
takyon kuramında da çıkar [61]. Bu kuralın sabit
noktası ışık hızıdır, ve kural subluminal ile superluminal bölgeleri birbirine
eşler.

### 10.1 Dört eksende hareketin tanımı

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
bu sonuçla nasıl bir arada durduğunu ise Bölüm 4.1.3 yazar.

**Dört eksenin özeti.** Parçacık üç eksende serbestçe hareket eder, ama o üç
eksen saate hiçbir şey taşımaz. Kalan tek eksende hareket serbest değildir, ama
saate taşınan her şey bu dengesizlikten gelir. Yolculuğun tamamı bu dengesizlik üzerine
kuruludur.

### 10.2 Dispersiyon ve grup hızı

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

### 10.3 Durgunluğun tek yörüngeye indirgenmesi

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
olarak ilk kuran [66] olmuştur, ve mekanizmanın olgun hâlini [13] vermiştir. O çalışmada $Sp(2,\mathbb{R})$ ayar simetrisi altında
tek zamanlı sistemler, aynı iki zamanlı sistemin farklı ayar sabitlemeleri olarak
ortaya çıkar, ve aynı mekanizma alan teorisine, etkileşimlere ve ayar arka
planlarına kadar götürülmüştür. Yukarıdaki $O(3)$ fazlalığı da aynı türdendir,
yalnızca çok daha dardır. Bu bölümün katkısı mekanizmanın kendisi değil, onun bu
modeldeki durgunluk sorusuna uygulanmasıdır.

# Kısım IV. Üç bölgede madde

## 11. Parçacığın iki okuması

Bu çalışmanın ele aldığı olay şudur: kütleli bir parçacık eşiği geçer, Bölge II'de bir süre kalır ve geri döner. Öyleyse "parçacık" sözcüğü küçük bir
ayrıntı değil, bütün hesabın dayanağıdır, ve ne anlama geldiği baştan
sabitlenmelidir.

Bunu yapmak zorunludur, çünkü Bölge II'de parçacık kavramı olağan anlamıyla
bulunmaz. O kavram üç yapıya dayanır [63], [75]: pozitif ile negatif frekansın
birbirinden ayrılması, alttan sınırlı bir Hamiltonyen ve Poincaré grubunun
üniter bir temsili. Bölüm 9 bu üçünün de Bölge II'de bulunmadığını
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
üzerinden tanımlanmıştır. Eşikten geçiş Bölüm 8'de mod diliyle kurulduğu için,
geçişle ilgili her nicelik bu okumada doğrudan hesaplanabilir.

**Parçacık okuması.** İkinci okumada parçacık, konumu, momentumu ve bir yörüngesi
olan bir cisimdir. Sorulan sorular "nereye gitti", "ne zaman döndü", "hangi
yönelimi kazandı" biçimini alır, ve cevapları tek tek sayılardır.

İki okuma birbirinin basitleştirilmiş hâli değildir; ikisi de kendi içinde
eksiksizdir, ve bu çalışma ikisini yan yana yürütmektedir. Uyuştukları yerde çalışma
uyuşmanın nedenini de yazar. Ayrıldıkları yerde ise ayrılmayı **gizlemez, sonuç
olarak kaydeder**, çünkü bu modelde ikisinin ayrıldığı yerler tam olarak Bölge II'nin kendine özgü davrandığı yerlerdir.

İkisini birbirine bağlayan şey aşağıda kurulan sözlüktür, ve o sözlüğün nerede
geçerli kaldığı hesaplanabilir bir sorudur.

### 11.1 Sözlük

| Nokta cisim dili | Dalga paketi karşılığı |
| -------------------------------- | ----------------------------------------- |
| Konum | Yoğunluğun birinci momenti |
| Momentum | Ortalama dalga sayısı $\langle k \rangle$ |
| Parçacığın var olması | Paketin toplam ağırlığı |
| Parçacığın tekliği | Paketin dar olması, $\sigma \ll k_0$ |
| Parçacığın aynı parçacık kalması | Momentlerin geçiş boyunca korunması |

Bu bölümün asıl sonucunu son satır taşır.

### 11.2 Eşiğin paketi yeniden ağırlıklandırması

Bölüm 8 geçirgenliğin moda bağlı olduğunu vermişti. Bir paket birçok moddan
oluştuğuna göre, eşik o paketin bazı bileşenlerini ötekilerden daha çok geçirir.
Dolayısıyla karşı tarafa ulaşan şey, gelenin sönümlenmiş bir kopyası değil,
**başka bir dağılımdır**.

Geçen ağırlığın oranı, $\mu = 1$, dilim kalınlığı $d = 1$ ve paket merkezi
$k_0 = 2$ için şu değerleri almaktadır:

| Paket genişliği $\sigma$ | Geçen ağırlık oranı |
| ------------------------ | ------------------- |
| $0{,}1$ | $0{,}638$ |
| $0{,}4$ | $0{,}634$ |
| $1{,}0$ | $0{,}618$ |

Geçen oran her durumda sıfır ile bir arasında kalır, yani paket ne tamamen
yansır ne de tamamen geçer.

Asıl etki bu oranda değil, dağılımın kaymasında görünür. Ağırlık merkezinin
kayması, paketin kendi genişliği birim alınarak şu değerleri almaktadır:

| Paket genişliği $\sigma$ | Merkez kayması (genişlik birimiyle) |
| ------------------------ | ----------------------------------- |
| $1{,}0$ | $0{,}413$ |
| $0{,}5$ | $0{,}256$ |
| $0{,}25$ | $0{,}138$ |
| $0{,}125$ | $0{,}071$ |

Kayma daima pozitiftir, yani büyük dalga sayısına doğrudur; çünkü dilim yüksek dalga sayısında
daha geçirgen kalır. Geniş bir paket için kayma kendi genişliğinin yarısına
yaklaşır, ki bu paketin kimliğini yitirmesi demektir.

### 11.3 Nokta cisim koşulu

Yukarıdaki tabloda kayma, paket genişliğiyle **doğru orantılı** gitmektedir:
genişlik yarıya indiğinde kayma da yarıya iner, ve bu ardışık genişliklerde
sayısal olarak doğrulanmıştır.

Orantının sonucu şudur: kaymanın bir alt sınırı yoktur. Yeterince dar bir paket
seçilirse merkez kayması istenildiği kadar küçük tutulabilir.

> Nokta cisim dili yaklaşık bir kolaylık değil, dar paket limitinde **tam**
> geçerli kalır. Geçen cisim, giden cismin aynısıdır; yalnızca paket dar tutulduğu
> sürece.

Gidiş dönüş anlatısının tamamı bu sonuca dayanır. Paket dar tutulmadığında
"parçacık gitti ve geri döndü" cümlesi anlamını yitirir, çünkü dönen şey gidenden
farklı bir mod dağılımı olur.

### 11.4 Dar paketin iki kaybı

Dar paket limiti merkezi korur, ama her şeyi korumaz. İki kayıp kalır.

Birincisi, geçen ağırlığın oranı hiçbir zaman bire ulaşmaz. Dar bir pakette de
bu oran birden küçük kalır, yani dönen paketin toplam ağırlığı gidenin altındadır.
Bu bir konum ya da momentum kaybı değildir; kaybolan şey doğrudan parçacığın
Bölge II'de bulunma ağırlığıdır, ve Bölüm 14'ün bilgi dökümü bunu ilk kalem olarak
sayar.

İkincisi, paketin genişliği de sabit kalmaz; dar limitte kendi büyüklüğünün binde
biri mertebesinde değişir. Yani genişlik merkez kadar temiz korunmaz, ama merkeze
göre ikinci mertebeden küçük kalır.

Bölüm 14'ün mod içeriği karşılaştırması tam olarak bu iki niceliği ölçmektedir.

### 11.5 Bu tanımın sınırları

Üç çekince vardır.

Paket bu hesapta tek bir enine dalga sayısı değişkeni üzerinde durur. Gerçek
bir üç boyutlu paket için aynı hesap üç değişkende yapılmalıdır; sonucun
niteliksel olarak değişmesi beklenmez, ancak gösterilmemiştir.

Hesap doğrusaldır ve alanın kendisiyle etkileşimi yoktur. Etkileşen bir alanda
paketin geçiş sırasında dağılması ayrı bir olgudur.

Nokta cisim okuması yalnızca Bölge I'de tanımlıdır. Bölge II'de "konum" kavramı
tek uzay ekseni olan $r$ üzerine daralır ve üç zaman yönü boyunca hiçbir
karşılığı kalmaz.
Bölge II'de hareketin ne anlama geldiğini bu nedenle Bölüm 10 karşılar. Konumun
kendisi ise Bölge II'de de tanımlı değildir; Bölüm 18.9 bunu reddeder.

### 11.6 Okumaların ölçümle kararı

Geçişin ne kadar sürdüğü sorusuna üç kurgu üç ayrı yanıt verir. Nokta cisim
kalınlığı bir hıza böler, dalga fazı frekansa göre türetir, genlik depolanan
normu gelen akıya böler. Üçü de adı konmuş niceliklerdir ve bu çalışmaya ait
değildir: fazın frekans türevi [31]'e, depolanan normun akıya oranı ise
[67]'nin ikamet süresine karşılık gelir. Aynı süreyi bir saatin dönmesi
olarak okuyan kurgu [68] ile başlamış, Larmor saati biçimini [32]'de almıştır.
İkamet süresinin ilk tanımını [67] vermiştir.
Tanımların hangisinin neyi ölçtüğü [69] ve [33]'te derlenmiştir. Sınanan yapılanmada bir katediş için sırasıyla $9{,}861$,
$1{,}462864$ ve $0{,}519$ çıkar. Geçişin tek bir süresi yoktur.

Dönüş anını hangisinin doğru yerleştirdiği ölçümle karara bağlanmıştır. Yayılan
paketin tepesi, üç okumadan hiçbirine ait olmadığı için tarafsız bir ölçüt
sağlar. Üç okumadan yalnızca dalga okuması tutmaktadır; aradaki bağıl fark
$4{,}5 \times 10^{-4}$ düzeyinde kalır. Nokta cisim okuması altı katı aşan bir
bağıl sapmayla, genlik okuması ise yüzde altmış beşlik bir bağıl sapmayla
şaşar.

Dönen durumun zaman ekseni üzerindeki yeri bu nedenle **fazın** özelliğidir,
bölgede geçirilen sürenin değil. Diğer iki okuma yanlış değildir; biri ikamet
süresini, öteki yasak iç bölgenin geçilmesini ölçer.

**Bu ölçütün taraflı olabileceği kayda geçer.** Kullanılan ölçüt yayılan paketin
tepesidir, ve tepenin konumu durağan faz koşulundan çıktığı için ölçüt baştan
faz okumasına yatkındır. Bağımsız bir ölçüt seçilseydi sonuç değişebilirdi: ikamet süresi ultrasoğuk
atomlarda Larmor saatiyle doğrudan ölçülmüştür [34], ve o ölçümün konusu tepe
değil, parçacığın engelde geçirdiği süredir. Bu çalışma dönüş anını
yerleştiren okumayı seçmektedir, en fiziksel okumayı değil; ikisi aynı soru
değildir.

Ayrımın en keskin biçimi kalınlık bağımlılığıdır. Nokta cisim okuması kalınlıkla
büyür, dalga ve genlik okumaları durur. Kalınlıkla doyan bir okuma ile doymayan
bir okuma aynı kalınlığın geçiş süresi olamaz.

### 11.7 Kütle ve genişlik tavanları

Paketin bölgeyi geçebilmesi iki üst sınırla kısıtlanmıştır ve ikisi tek bir
koşulun iki görünümüdür. Dışarıda yayılabilen en düşük frekans
$\omega_{\min} = c\sqrt{k_T^2 + \mu}$ değerindedir. Bandın merkezi bunun
altına düştüğünde hiçbir bileşen algılayıcıya ulaşmaz.

Birinci sınır kütleye düşer. Merkez frekans sabit tutulduğunda kütle parametresi
en çok

$$\mu_{\max} = \frac{\omega_0^2}{c^2} - k_T^2$$

değerine kadar büyür; sınanan yapılanmada bu $3{,}84$ çıkar ve kalınlık ifadeye
girmez. İkinci sınır bandın genişliğine düşer. Toplamın kapsadığı genişlik sayısı
$N$ ile yazıldığında alt kenarın kesimi aşması

$$\sigma_{\max} = \frac{\omega_0 - \omega_{\min}}{N}$$

koşulunu verir ve aynı yapılanmada $0{,}1128$ çıkar. Birinci sınıra merkez
aşağı inerek, ikincisine alt kenar yayılarak varılmıştır.

Bu tavanların aşılması gecikmeyi küçültmez, **tanımsız bırakır**. Aradaki fark
sonucun okunuşunu değiştirir: tavanın üstünde kalan bir durum daha pahalı bir
yolculuk yapmaz, yolculuk yapmaz.

### 11.8 Ölçülen bağımlılıklar

Tavanların altında kalan bölgede iki bağımlılık ortaya çıkar. Kütle parametresi
$0{,}25$'ten $3{,}00$'a çıkarıldığında gereken Bölge II mesafesi $2{,}815$'ten
$4{,}567$'ye yükselir. Kütle bir kazanç değil maliyet getirir. Doyum her kütlede geçerlidir.

Genişliğin etkisi ikinci mertebedendir ve kapalı biçimde **hiç görünmez**, çünkü
kapalı biçim bandın merkezinde değerlendirilir ve genişliği taşımaz. Yayılan
paketin tepesi ölçüldüğünde genişliğin on altı katlık değişimi eşiği binde
$7{,}5$ oranında oynatır ve her adımda aynı yönde: geniş paket daha geç döner.
Ölçüm ile kapalı biçimin ayrıldığı tek yer bu satırdır ve iki rotanın birlikte
koşturulmasının gerekçesi budur.

---

# Kısım V. Gidiş dönüşün sonucu

Bu kısım çekirdek dönüşümün **zaman** bileşenini kurmaktadır. Dönüş olayının Bölge
I'in zaman eksenindeki yeri bu adımda belirlenir ve içeride taşınan bir saatten
değil, iki geçişin ortak genliğinin fazından okunmaktadır.

## 12. İkinci geçiş ve eşleşme

Gidiş tek bir yüzeyin problemidir, oysa gidiş dönüş iki yüzeyin problemidir ve
sonucu farklı çıkar. İki yüzey arasındaki bölge artık dalganın bir kez geçtiği
bir engel gibi değil, içinde ileri geri yansımaların üst üste bindiği bir
**boşluk** gibi davranır.

### 12.1 Geçiş genliği

Normal doğrultudaki dalga sayısı dışarıda $\kappa$, ara bölgede $q$ olmak üzere,
iki yüzeyin birlikte çözümü tek bir karmaşık genlik verir:

$$A = \frac{4\kappa q}
 {(\kappa+q)^2 e^{-i q d} - (\kappa-q)^2 e^{i q d}}$$

Bu tek ifade dört ara bölge tipini birden kapsar, çünkü $q$ karmaşık değer
alabilir. Ara bölge yayılımlıysa $q$ reel çıkmakta ve payda salınmaktadır; söndürücüyse
$q$ sanal olur, üstel terimler reel hiperbolik fonksiyonlara döner ve genlik
bastırılır. Yani iki durum ayrı formüller değil, aynı formülün iki dalıdır.

Ara bölge hiç yokken de $q = \kappa$ olur ve $A$ serbest yayılma fazına iner. Bu,
hesabın tutarlılık sınamasıdır ve sağlanmaktadır.

### 12.2 Genliğin taşıdığı iki bilgi

Genliğin **büyüklüğü** ne kadarının geçtiğini verir, ve Bölüm 5'in geçirgenlik
tablosunu vermektedir.

Genliğin **fazı** ise dönüş anını taşır ve asıl konu odur. Bir sonraki bölümün
tamamı bu fazın nasıl okunacağı üzerinedir.

### 12.3 Parçacığın eşikten geçirilme yolu

Eşikten geçiş, açılıp kapanan bir geçit değildir. Söndürücü rejimde ara bölge bir
engeldir ve engelin içinde normal dalga sayısı sanal değer alır. Dolayısıyla
geçişin adı tünellemedir: parçacık engeli aşmaz, genliği engelin içinde üstel
olarak bastırılır ve karşı yüzde sıfırdan farklı bir değerle çıkar.

Bu sonuçtan iki şey daha çıkar. Geçiş **olasılıksaldır**, yani tek bir parçacık için
söylenebilecek tek şey geçme şansının $|A|^2$ olduğudur. Geçiş ayrıca
**zorlanamaz**, çünkü genlik ancak engelin opaklığı, yani sönüm sabiti ile
kalınlığın çarpımı küçültülerek büyür.

İkinci sonuç deneyin biçimini de belirler. Düzenek tek bir parçacığa dayanamaz;
çok sayıda parçacığı aynı eşiğe fırlatır ve geri dönenleri sayar. Gereken
fırlatma sayısı opaklığın üsteliyle büyür, ve Bölüm 21.2.3 onu sayılara
bağlamaktadır.

### 12.4 Dönüşün kendiliğinden olmasının sebebi

Parçacığın geri gelmesi bir tercih ya da ikinci bir müdahale değildir; sebebi
doğrudan Bölge II'nin yapısında durur.

Bölge II üç zaman yönü taşır, ve Bölüm 9'da gösterildiği üzere zaman yönelimi
Bölge II'de tanımsız kalır. Yönelim bulunmadığından "ileri doğru yayılmayı sürdürmek"
diye bir koşul da kurulamaz. Yakın tarafta ışıma koşulu dalgayı yalnızca dışarı
gönderir, çünkü Bölge I'de geleceği geçmişten ayıran bir ok bulunur. Bölge II böyle bir ok sunmadığından **kendi ışıma koşulunu veremez**.

Aynı durumun saçılma problemindeki karşılığı doğrudandır: Bölge II iki genlik
birden taşır, biri yüzeyden uzaklaşan diğeri yüzeye doğru gelen. İkincisi elle
konmuş bir kabul değildir, tek yönlülüğü dayatacak bir yapı bulunmadığı için
kendiliğinden ortaya çıkar.

Dolayısıyla dönüşün kendisi de kendiliğindendir. Parçacık Bölge II'de kalmayı
seçemez, çünkü kalmayı tanımlayacak bir zaman oku yoktur. Geri gelmesi,
gitmesiyle aynı çözümün parçasıdır, ve iki yüzeyin ortak çözümü tek bir genlik
verir.

**Çekince.** Bu, dönüşün kesin olduğu anlamına gelmez. Kesin olan, dönüş
genliğinin var olduğudur; büyüklüğü Bölüm 12.2'nin verdiği $|A|$ değeridir ve
söndürücü rejimde küçüktür.

## 13. Dönüş anı

Bu bölümün sorusu şudur: parçacık geri döndüğünde, hiç geçmemiş bir gözlemcinin
saatinde hangi ana denk düşer.

### 13.1 Saat taşımanın imkânsızlığı

İlk akla gelen yol, parçacığın kendi saatini okumaktır, ancak bu yol kapalı
kalır. Ara bölgede zaman yönelimi bulunmaz, Öklid durumunda ise zaman ekseninin
kendisi hiç yoktur. Bir süreyi okuyacak yapı bulunmadığından "içeride şu kadar
kaldı" ifadesi de tanımsız kalır.

Öyleyse dönüş anı taşınan bir süreden gelemez, başka bir yerden gelmek zorundadır.

### 13.2 Fazın taşıdığı yer bilgisi

O yer Bölüm 12'nin genliğidir. Genlik karmaşık bir sayı olduğundan bir fazı
vardır, ve o fazın frekansa göre türevi dışarıda kalan gözlemcinin ölçtüğü
gecikmeyi verir:

$$\tau = \frac{d}{d\omega}\,\arg A(\omega)$$

Bu ifade ara bölgenin içinde hiçbir saat gerektirmez, çünkü yalnızca iki yüzeyin
de dışında tanımlı olan tek bir niceliği kullanır: geçiş genliğinin frekansa
duyarlılığını. Süreyi hiç bilmeden yeri veren şey budur.

İfade bir tutarlılık sınamasından da geçmiştir: ara bölge hiç yokken $\tau$ tam
olarak serbest uçuş süresine eşit çıkar, ve bu üç ayrı kalınlıkta
doğrulanmıştır.

### 13.3 Engel olmanın frekansa bağlılığı

Yukarıdaki ifadenin verdiği ilk sonuç beklenmedik biçimde basittir: aynı ara
bölge, yüksek frekansta yayılımlı, düşük frekansta ise söndürücü
davranmaktadır. Öklid bölge için sınırı

$$\omega^2 < c^2\left[\left(1 + \tfrac{2n}{3}\right)k_T^2 + \mu\right]$$

koşulu verir. Yani "ara bölge bir duvar mıdır" sorusunun tek bir cevabı yoktur;
cevabı gelen parçacığın frekansı belirler. Bu nedenle eşik bir duvar değil bir
**mod filtresidir**, ve çalışmanın başka yerleri ona bu adla geri döner.

### 13.4 Engel rejiminde gecikmenin doyumu

Ara bölge söndürücü olduğunda gecikme kalınlıkla artmayı bırakır:

| Kalınlık $d$ | Gecikme $\tau$ | Işığın alacağı süre |
| ------------ | -------------- | ------------------- |
| $1$ | $1{,}451$ | $1$ |
| $2$ | $1{,}463$ | $2$ |
| $4$ | $1{,}463$ | $4$ |
| $8$ | $1{,}463$ | $8$ |

Tabloda gecikme ikinci basamaktan sonra sabitlenmektedir, yani kalınlık sekiz kat
arttığında dönüş anı hiç değişmez. Bu bağımsızlıktan iki sonuç çıkar, ve ikisi de önemlidir.

**Birincisi, geçiş ışıktan hızlı görünür.** Sekiz birim kalınlıkta gecikme,
ışığın alacağı sürenin beşte biri kadar kalır. Yine de bu, bir uyarımın ışıktan
hızlı **yayılması** anlamına gelmez, çünkü Bölüm 10.2 grup hızının daima $c$'nin
altında kaldığını hesaplamıştır. Tek anlamı, geçen paketin tepe
noktasının beklenenden erken çıkmasıdır.

**Doyumun kendisi bu çalışmanın bulgusu değildir.** Kalın bir engelde tünelleme
süresinin kalınlıktan bağımsızlaşacağını [29] durağan faz yöntemiyle 1962'de
hesaplamıştır; olgu literatürde o adla anılır. Mikrodalga [71] ve fotonik [70]
ölçümler onu doğrulamış, [30] ise doymuş süreyi bir kat etme süresi olarak değil,
engelde depolanan alanın boşalma süresi olarak okumuştur. Yukarıdaki tablo o
sonucun bu geometrideki karşılığıdır. Bu çalışmanın kendi katkısı doyumun
varlığı değil, doymuş gecikmenin ne kadar küçültülebileceğidir (Bölüm 4.1.6).

**Aynı soru iki engelli hâlde de sorulmuş, ancak kapatılamamıştır.** [41] iki ardışık
engel arasındaki açıklığın da gecikmeye girmemesini bekler ve [42] bunu optik
çift bariyerde beş ayrı açıklıkta ölçer. Sonuç tartışmalıdır. [43] ölçülen
niceliğin bir kat etme süresi değil kavite ömrü olduğunu savunur; [44] ile [45]
bağımsızlığın kendisini reddeder.

Yine de bu çalışmanın hiçbir sonucu o tartışmaya dayanmaz. Bu bölümün hesabı tek bir
bölgenin kalınlığını konu alır, ve Bölge II'de kat edilen mesafe gecikmeye değil
ona karşı çalışan terime girer. Yukarıdaki kayıt yalnızca aynı yöne bakan bir
soruyu açık olarak göstermek için durmaktadır.

**İkinci sonuç ise bu modelin aleyhinedir: dönüş anı kalınlığı unutur.** Bir
birimlik bir ara bölge ile sekiz birimlik bir ara bölge, parçacığı Bölge I'in
saatinde **aynı ana** koyar. Dolayısıyla dönüş anına bakarak ara bölgenin ne
kadar kalın olduğu söylenemez.

### 13.5 Yayılımlı rejimde tersine dönme

İç mod yayılabildiğinde doyum ortadan kalkmakta ve gecikme kalınlıkla
salınmaktadır.
Kalınlık tarandığında gecikme $0{,}225$ ile $9{,}009$ arasında gidip gelmektedir.
Yani yayılımlı bir ara bölgede dönüş anı kalınlığa **duyarlıdır**, ancak tek
değerli değildir: aynı gecikmeyi veren birden çok kalınlık bulunur.

| Ara bölge | Dönüş anının kalınlığa bağlılığı |
| --------- | ----------------------------------- |
| Yok | Doğrusal, tek değerli |
| Yayılımlı | Salınımlı, çok değerli |
| Söndürücü | Doyuma ulaşır, kalınlıktan bağımsız |
| Dejenere | Tanımsız, geçiş yok |

### 13.6 Mesafe ile fiyatın farkı

Varış anının $2\tau - s$ olduğunu Bölüm 2.1 ile Bölüm 4.1.3 kurmuştu. Bu alt
bölüm o ifadeyi bir başka yapılanmada sayıya döker. $\tau$ tek bir geçişin
gecikmesi olduğundan gidiş dönüşün gecikmesi onun iki katıdır, ve ikisini
birbirine karıştırmak bu çalışmada iki kez ikilik çarpan hatasına yol açmıştır.
Sınanan yapılanmada $\tau = 1{,}462864$, gidiş dönüşün gecikmesi ise
$2\tau = 2{,}925728$ değerindedir.

| Bölge II'de kat edilen mesafe | Varış anı | Konum |
| ----------------------------- | -------------- | ----------------- |
| $1{,}000000$ | $+1{,}925728$ | Kalkıştan sonra |
| $2{,}925728$ | $0{,}000000$ | Tam kalkış anında |
| $6{,}000000$ | $-3{,}074272$ | Kalkıştan önce |
| $25{,}000000$ | $-22{,}074272$ | Kalkıştan önce |

**$s$ değerini ne belirler.** Bu soru bu çalışmada cevapsızdır, ve cevapsız
kaldığı burada kayda geçirilmektedir. Bölüm 12.4 parçacığın Bölge II'de kalmayı
seçemeyeceğini göstermişti, çünkü seçimi tanımlayacak bir zaman oku yoktur.
Dolayısıyla $s$, parçacığın yolculuk sırasında ayarladığı bir nicelik değildir.
Model içinde $s$, iki yüzeyin ortak çözümünde serbest kalan bir parametredir:
hesap her $s$ için varış anını verir, ancak hangi $s$ değerinin gerçekleşeceğini
vermez.

Bu boşluğun kapanması için gereken şey de bellidir. $s$'yi sabitleyen bir
mekanizma, ancak Bölge II'nin sınır koşullarını hazırlık aşamasında belirleyen
bir düzenekten çıkabilir. Bölüm 15.6'nın yük ile potansiyel çarpımı böyle bir
kolun ilk adayıdır, çünkü etkin frekansı kaydırarak gereken $s$ değerini
dışarıdan oynatmaktadır. Ne var ki o bağıntı $s$'yi belirlemez, yalnızca gereken
$s$'yi değiştirir; ikisi ayrı sorulardır ve ikincisi bu çalışmada açık kalır
(Bölüm 21.2.7).

Eşik gecikmesi ise buna karşılık serbest değildir: durumun ve ara bölgenin
özelliklerinden çıkar, ve yolculuk başladıktan sonra sabit kalır.

### 13.7 Sekiz koşul, iki başarısızlık

Buraya kadar kurulan hesap sekiz koşul üretmiştir. Parçacık eşiği geçecek, Bölge II'de
hareket edecek ve kalkıştan önce dönecekse, sekizi de sağlanmalıdır.

| Koşul | Başarısızlığın anlamı |
| --------------------------------------- | -------------------------------- |
| Bant merkezinin kesimi aşması | Algılayıcıya ulaşan bileşen yok |
| Bandın tamamının kesimi aşması | Algılayıcıya ulaşan bileşen yok |
| Kütlenin tavanın altında kalması | Algılayıcıya ulaşan bileşen yok |
| İç kısmın yayılımı engellemesi | Doyan gecikme uygulanmaz |
| Genliğin iki geçişten sağ çıkması | Ölçülebilir dönüş yok |
| Bir eklem koşulunun çıkışa izin vermesi | Yüzey tek yönlü dalgayı yasaklar |
| Ters çeviren dalın gerçekleşmesi | Varış öne değil arkaya kayar |
| Mesafenin eşik gecikmesini aşması | Varış kalkıştan sonraya düşer |

Bu sekiz koşul aynı biçimde bozulmamaktadır, ve aradaki ayrım sonucun okunuşunu
belirlemektedir. İlk yedisi bozulduğunda yolculuk ya tümüyle ortadan kalkar ya da
işareti döner. Yalnızca sonuncusu, yani Bölge II'de alınan mesafe, **daha fazla
ödenerek** sağlanabilmektedir. Koşullar tek tek bozulduğunda şu tablo çıkmıştır:
kütle parametresinin $8$ olması, bant genişliğinin $0{,}5$ olması ve ters dalın
seçilmesi birinci türden bir başarısızlık verir, mesafenin $0{,}5$'te kalması
ise ikinci türden bir başarısızlık verir.

### 13.8 Sınırın ağırlığa düşmesi

Bölge II'de alınacak mesafeyi yukarıdan sınırlayan bir koşul yoktur, dolayısıyla
varış anı sınırsız geriye iner. Bununla birlikte düşen nicelik **ağırlıktır**:
sınanan yapılanmada gönderilen bandın yalnızca $7{,}8 \times 10^{-36}$ katı geri
dönmektedir. Daha geriye gitmenin sınırı bu yüzden varabilmeye değil,
**görülebilmeye** konmuştur. Sorunun ölçülebilir biçimi şudur: ne kadar geriye
gitmek istendiği değil, ne kadar zayıf bir sinyalin algılanabildiği.

---

## 14. Mod içeriğinin değişimi

Bir gidiş dönüş aynı ara bölgeyi iki kez geçmektedir. Bu nedenle Bölüm 13.3'ün
mod süzgeci paketin üzerine **iki kez** iner, ve iki geçişin etkileri toplanmaz,
birbiriyle çarpılır.

### 14.1 Geri dönen ağırlık

Çarpımın sonucu, $\mu = 1$, $d = 1$ ve paket genişliği $0{,}3$ için şöyle
çıkmaktadır:

| Ara bölge | Tek geçişte kalan | Gidiş dönüşte kalan |
| --------- | ----------------- | ------------------- |
| Kleinian | $0{,}870$ | $0{,}757$ |
| Öklid | $0{,}122$ | $0{,}018$ |
| Dejenere | $0$ | $0$ |

Görüldüğü gibi dönüş geçişi, gidiş geçişinin kaybını bir kez daha tekrarlamaktadır.
Öklid bir bölgede gidiş dönüş, paketin yüzde ikisinden azını geri getirir.

### 14.2 Merkez kayması

Süzgeç iki kez uygulandığından ağırlık merkezinin kayması da büyümektedir:

| Paket genişliği | Gidiş dönüş kayması (genişlik birimiyle) |
| --------------- | ---------------------------------------- |
| $0{,}4$ | $1{,}092$ |
| $0{,}2$ | $0{,}578$ |
| $0{,}1$ | $0{,}292$ |
| $0{,}05$ | $0{,}146$ |

Tablonun ilk satırında genişliği $0{,}4$ olan bir paket kendi genişliğinden fazla
kaymaktadır; böyle bir paket için "aynı parçacık geri döndü" ifadesi savunulamaz.

Buna karşılık kayma yine genişlikle **doğru orantılıdır** ve bir alt sınırı
yoktur. Dolayısıyla Bölüm 11.3'ün sonucu gidiş dönüş için de geçerli kalmaktadır:
yeterince dar bir paket kendisi olarak geri döner. Yolculuğun bir yolculuk
sayılabilmesi, yani gidenle gelenin aynı şey olması, tam olarak bu koşula
bağlıdır.

---

## 15. Korunan nicelikler

Önceki bölüm geçişin neyi değiştirdiğini saydı. Bu bölüm ters soruyu sorar:
geçiş neye **dokunamaz**.

Üç nicelik geçişten değişmeden çıkar ve üçü de hesapla denetlenmiştir.

**Frekans.** Eklem koşulları sabit frekansta dayatıldığından, ara bölgenin
dayattığı dalga sayısı adımı frekanstan bağımsız kalmaktadır. Üç ayrı frekansta
adım aynı çıkmıştır.

**Enine dalga sayısı.** Yüzey kendi boyunca homojen olduğundan enine dalga sayısı
korunur, ve adımı yalnızca o belirler. Üç ayrı enine dalga sayısı bunu
doğrulamıştır.

**Kütle.** Kütle parametresi iki tarafa da aynı miktarda girmektedir, çünkü geçiş
dalga operatörüne etki eder, kütleye değil.

| Nicelik | Gidiş dönüşte |
| ------------------- | --------------------------- |
| Frekans | Değişmez |
| Enine dalga sayısı | Değişmez |
| Kütle | Değişmez |
| Normal dalga sayısı | Ara bölgede sanal olabilir |
| Genlik | Azalır |
| Mod dağılımı | Yeniden ağırlıklanır |
| Faz | Kayar ve dönüş anını taşır |

Sol sütun parçacığın kimliğini, sağ sütun başına gelenleri tarif etmektedir.
Kimlik korunmakta, geçmiş değişmektedir.

**Bu tabloya yöneltilebilecek itiraz.** [56], klasik bir imza değişiminde
**standart korunum yasalarının çöktüğünü** göstermektedir: geçiş yüzeyinde
enerji-momentum tensörünün olağan diverjans özdeşliği geçerliliğini
yitirmektedir. Yukarıdaki tablo bu sonuçla çelişmez, çünkü iki ifade farklı
nesneler hakkındadır. [56]'nın konusu **alanın enerji-momentum akısıdır**, yani
bir yüzey boyunca taşınan nicelik; yukarıdaki tablonun konusu ise **tek bir
modun etiketleridir**, yani frekans, enine dalga sayısı ve kütle parametresi.
Birincisinin korunmadığını bu çalışma da bulmaktadır: geçen genlik birden
küçüktür ve fark yüzeyde kalır (Bölüm 14.1). Korunan şey akı değil, geçen kısmın
kimliğidir. Enerji-momentum akısının imza değişiminde nasıl kitaplandığı ise bu
çalışmada hesaplanmamıştır, ve Bölüm 21.2 bunu açık madde olarak taşımaktadır.

### 15.1 Enerji vektörünün karşılığı

Bölge II'nin üç enerji bileşeni soyut bir nesne değildir; Bölge I'de tanınan bir
şeyin başka adıdır. $D$ dört-momentuma uygulandığında

$$(E/c,\; p_x,\; p_y,\; p_z) \longmapsto (p_z,\; p_y,\; p_x,\; E/c)$$

olur. Yani:

> Bölge II'nin **enerji vektörü** Bölge I'in **üç-momentumudur**; Bölge II'nin tek
> **momentumu** ise Bölge I'in **enerjisidir**.

Bu, iki niceliğin sayısal olarak eşit olması değil, aynı nesne olmasıdır. Enerji
vektörünün uzunluğu Bölge I'in momentumunun büyüklüğüne tam olarak eşittir ve bu
doğrulanmıştır.

### 15.2 Dönüşümün kayıpsızlığı

$D$ bir involüsyon olduğundan, iki kez uygulandığında dört-momentumun dört
bileşeni de **tam olarak** başlangıç değerine döner ve sayısal artık sıfır kalır.

Bu sonucun önemi şudur: modelin bildirdiği bütün kayıplar dönüşümden değil,
iki bölgenin birleştiği **yüzeyden** gelmektedir. Cebir hiçbir şey kaybetmez,
karşılığını eklem koşulları belirler.

### 15.3 Bölge II'de uzunluğun fizikselliği

Bölüm 10'da gösterildiği gibi üç zaman ekseni arasında bir $O(3)$ simetrisi
bulunmaktadır. Bu simetri bir ayar fazlalığı olduğundan enerji vektörünün **yönü**
Bölge II'de fiziksel değildir, ve fiziksel olan tek nicelik uzunluğu olarak kalır.

Üç ayrı dönme açısı da aynı sonucu vermiştir: dönme, enerji vektörünün
uzunluğunu, Bölge II'nin momentumunu ve değişmezi değiştirmez.

### 15.4 Dönmenin bıraktığı iz

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

Bu madde, Bölüm 16'da kurulan sözlüğün en somut maddesidir, ve gidiş dönüşün
hiçbir enerji harcamadan yapabildiği tek şeyi adlandırır: yön değiştirmek.

**Çekince.** Yukarıdaki sonuç dönüşüm düzeyinde kalır ve yüzeyin mod
süzgecinden bağımsızdır. Parçacığın Bölge II'de gerçekten bir $O(3)$ dönmesi
geçirip geçirmediği bu hesabın konusu değildir. Hesabın verdiği tek şey şudur:
geçirirse Bölge I'de ne görünür.

**Kalan çekince.** Bu döküm doğrusal ve durağan bir saçılma kurgusuna dayanır.

### 15.5 Yükün yeniden dağılması

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

### 15.6 Potansiyelin ayar aralığı

Yük, zamanlamayı kendi başına değiştirmemektedir. Uygulanan potansiyel sıfır
olduğunda yükü beş katına çıkarmak gidiş dönüş okumasını hiç oynatmaz, ve
doğrulama bunu üç okumanın hepsinde ayrı ayrı sınamıştır.

Yükün getirdiği şey, bölgenin dışından işleyen bir ayardır. Minimal bağlaşım
etkin frekansı yük ile potansiyelin çarpımı kadar kaydırdığından, gereken Bölge II mesafesi dışarıdan oynatılabilir. Nötr bir durumda böyle bir ayar
bulunmaz, çünkü kayma yükle birlikte sıfırlanır.

Bu ayarın bir alt sınırı vardır. Gereken mesafe frekansla tek düze gitmez: önce
düşer, en küçük değerine ulaşır, sonra yeniden yükselir. Sınanan yapılanmada bu
en küçük değer $2{,}920810$ olup $-0{,}0395$ potansiyelinde bulunur. Yani
potansiyelin sağladığı şey istenildiği kadar ucuz bir yolculuk değil, yalnızca
**en ucuz noktaya ayarlanma** imkânıdır, ve bu ayardan gelen kazanç toplam maliyetin
yüzde beşinin altında kalmaktadır.


---

# Kısım VI. Çekirdek dönüşüm

Bu kısım dönüşümün girdi tarafını, yani Bölge II'deki yönelimin ne anlama
geldiğini tanımlar; sonra girdiyi dönüş olayının dört koordinatına bağlar; ve
yedi adımı tek yerde yazar.

## 16. Yönelim sözlüğü

Bu bölüm Bölüm 9.5'in dokuz hücresini tek tek bu tarafa çevirir, sonra o
dokuzun gerçekte kaç tane olduğunu yeniden sayar.

### 16.1 Her hücrede korunan nicelikler

Dokuz hücrenin **tamamında** Bölge I'in enerjisi ve sürati tam olarak
korunmaktadır, ve sayısal artık sıfır çıkar. Öyleyse hücreleri birbirinden ayıran
tek nicelik, Bölge I'de momentumun yönüdür:

| Bağıl dönme | Bölge I'de sapma (radyan) |
| ----------- | ------------------------- |
| Yok | $0$ |
| Kısmi | $0{,}961$ |
| Tam ters | $2{,}601$ |

### 16.2 Sözlük

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

### 16.3 Çıkış yüzünü belirleyen nicelik

Bölüm 9.5'in iki etiketinden biri çıkış yüzüydü, ve o bölümde bağımsız bir etiket
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
dalga koşulu koymak demektir; o koşul bir zaman yönelimi gerektirir, ve Bölge II'de zaman yönelimi bulunmaz (Bölüm 9). Bölüm 6'da iki genliğin birden
tutulmasının nedeni de tam olarak budur.

**Geriye kalan tek belirleyici Bölge I'in enerjisidir.** Bölüm 15.1 Bölge II'nin
tek momentumunun Bölge I'in enerjisi olduğunu göstermişti, ve geçiş dalga sayısı
tam olarak o yuvada durur. Dolayısıyla:

> "Hangi yüzden çıktı" sorusu ile "enerjisinin işareti ne" sorusu **aynı
> sorudur**.

Karşı yüzden dönüş, başka bir yerden gelmiş gibi değil, **negatif enerjiyle**
gelmiş gibi görünür.

Bu sonuç Bölüm 16.2'nin tablosunu iki yerden değiştirmektedir. Birincisi, çıkış
yüzü ile yönelim bağımsız etiketler değildir; ikisi de aynı vektörün
parçalarıdır. İkincisi, "hiç çıkmaz" satırının yanına üçüncü bir okuma girer:
negatif enerjili bir varış, sıradan bir gözlemciye parçacık yerine
karşıparçacık gibi görünebilir, ve bu da literatürdeki çift yaratımı okumasıyla
aynı yere düşer.

İkinci okumanın adı ve önceliği de vardır. **Yeniden yorumlama ilkesi** tam
olarak şunu vermektedir: negatif enerjiyle zamanda geriye giden bir çözüm,
pozitif enerjiyle ileri giden bir karşıparçacıktan ayırt edilemez. İlke takyonlar
bağlamında [35]'te formüle edilmiş, [26] ise onu alan kuramına taşımıştır.
Bu bölümün hesabı o ilkeyi kurmaz, yalnızca doğrular. Tek katkısı şudur: ayırt
edilemezlik **hangi nicelikten** çıkıyor, onu gösterir. Söz konusu işaret, çıkış
yüzünü belirleyen vektörün aynı bileşenidir. Dolayısıyla "hangi yüz" ile
"hangi işaret" bağımsız iki soru sayılmaz. Ayırt edilemezliğin nerede kırıldığını [62]
derlemektedir, ve o soru bu çalışmanın kapsamı dışında kalmaktadır.

**Çekince.** Bu bölümde hesaplanan şey, dispersiyon bağıntısının iki dalı da
kabul ettiği ve yönelim yönünün geçiş dalga sayısını değiştirmediğidir. "Bölge II dal seçemez" ifadesi bir hesap değil, zaman yöneliminin yokluğundan çıkan
bir muhakemedir; dayanağını Bölüm 9 hesaplamıştır.

### 16.4 Hücrelerin dağılımı

Bölüm 16.2'nin tablosu hangi sonucun nasıl göründüğünü verir, ama hangisinin
gerçekleşeceğini vermez. Bu alt bölüm o eksiği kapatmakta, ve cevabın ikiye
ayrıldığını bulmaktadır.

**Çıkış yüzü belirlidir.** Akı korunumu geçen ve yansıyan ağırlıkları doğrudan
verir, ve geriye açıkta bir şey bırakmaz:

| Ara bölge | Karşı yüzden | Giriş yüzünden | Hiç çıkmaz |
| --------- | ------------ | -------------- | ---------- |
| Kleinian | $0{,}868$ | $0{,}132$ | $0$ |
| Öklid | $0{,}111$ | $0{,}889$ | $0$ |
| Dejenere | $0$ | $1$ | $0$ |

Son sütunun tamamı sıfırdır, çünkü kayıpsız bir bölge parçacığı yutmaz.
Dolayısıyla dokuz hücrenin üçü, daha dönme hesaba hiç katılmadan sıfır
olasılıklı çıkmaktadır.

**Dönme belirli değildir ve iki okuma taban tabana zıttır.**

*Ayar okuması.* Bölüm 15.3'e göre Bölge II'de yönelimin fiziksel bir içeriği
yoktur. Öyleyse iki yüz arasındaki bağıl dönmeyi Bölge II değil, eklem koşulları
belirlemektedir. Simetrik bir ara bölge için bu dönme özdeşliğe iner ve ortada
**hiç sapma kalmaz**. Yani bu okumada model ayırt edici hiçbir şey öngörmez.

*Bilgisizlik okuması.* İkinci okumada Bölge II'de hiçbir yön ayrıcalıklı
sayılmaz, dolayısıyla çıkış yönelimi küre üzerinde düzgün dağılır. Bu durumda
sapma açısının dağılımı $\tfrac{1}{2}\sin\theta$ olur, hesaplanan ortalama sapma
tam olarak dik açı çıkar, ve sonuçların yarısı dik açıdan fazla sapar. Sapmasız
dönüş küre üzerinde tek bir noktaya karşılık geldiğinden olasılığı sıfırdır, yani
**geçen her parçacık imzayı taşır**.

| Okuma | İmzanın olasılığı, Kleinian | İmzanın olasılığı, Öklid |
| ----------- | --------------------------- | ------------------------ |
| Ayar | $0$ | $0$ |
| Bilgisizlik | $0{,}868$ | $0{,}111$ |

**İki okumanın ayrılmasının değeri.** İkisi olabilecek en uzak iki tahmini
vermektedir: biri imzayı geçirgenlik oranında öngörür, diğeri hiç öngörmez.
Aradaki fark bir yorum farkı değil, **ölçülebilir** bir farktır. Parçacığı
geçiren ve enerjisiz sapma arayan tek bir deney ikisini birbirinden ayırır.

Ne var ki bu ayrım çalışmanın son sözü değildir. Bölüm 16.5 iki okumadan
ikincisini elemekte, ve yerine modelin kendi yapısından çıkan üçüncü bir cevap
koymaktadır. Çalışmanın ayırt edici öngörüsü de o üçüncü cevapta durur; aşağıdaki
iki uç ise onun sınandığı çerçeveyi kurar.

**Çekince.** İki okumanın verdiği sıfır ve bir uçlarını hesap değil, iki kabul
üretmektedir. Ayar okumasında dönme özdeşliğe iner, çünkü ara bölge simetrik
sayılır. Bilgisizlik okumasındaki düzgün dağılım ise hiçbir yönü ayrıcalıklı
saymayan ikinci bir kabulden gelir. Hesap yalnızca şunu verir: bu iki kabul
altında sonuç ne çıkar. Hangi okumanın doğru olduğunu ise ancak eklem
koşullarının asimetrik hâli verebilir, ve o hâl bu çalışmada çözülmemiştir.

Aynı biçimde "hiç çıkmaz" satırının sıfır kalması da geçişin kayıpsız olduğu
varsayımına dayanmaktadır. Bölüm 5.4'teki madde tabakası geçişi sönümlü kılarsa
o satır sıfır olmaktan çıkar.

### 16.5 Dönmenin nicelenmesi

Önceki alt bölümün iki ucu da varsayıma dayanıyordu. Oysa modelin içinde, hiçbir
varsayım gerektirmeyen üçüncü bir cevap zaten durmaktadır.

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
vardır. [25] X-ışınlarının kristalden yansımasını, girişim yasalarına hiç
başvurmadan, momentumun **kuantumlar hâlinde** aktarılması varsayımıyla türetir
ve [77]'nin yasasını bu yolla elde eder. Ayrıklığı üreten şey kristalde örgünün
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

### 16.6 İşaret sorusunun yeniden okunması

Aşağıdaki tartışma bu sözlüğün bir parçasıdır ve sonucu tersine dönmüştür. Eski
formülasyonda iki bölgedeki okların bağıl işareti prensip olarak ölçülemezdi,
çünkü eşik geçirgen değildi. Eşik geçirgen olduğuna göre o gerekçe düşmüştür ve
bağıl işaret ilke olarak ölçülebilir kalır.

Ayrımın kendisi de sınanmıştır. $D$ ile $-D$ arasındaki fark denendiğinde her iki
işaretin de $\det = +1$ ve $M^2 = I$ koşullarını sağladığı çıkmıştır, yani bu
koşullar ikisini birbirinden ayıramaz. Buna karşılık Bölüm 9'un bulgusu işaretin
anlamını netleştirmektedir:

1. Her iki bölgede birer ok seçimi vardır (Bölge I'de zaman, Bölge II'de uzay).
2. $D$ Bölge I'in ok eksenini Bölge II'nin ok eksenine gönderir, seçimler
 bağımsız değildir, biri diğerini belirler.
3. Fiziksel olarak anlamlı olan tek büyüklük **bağıl işarettir**: iki okun
 hizalanması. Tek başına hiçbiri anlamlı değildir.
4. Eşik geçirgen olduğuna göre iki bölge arasında bir kanal vardır; bağıl işaret
 bu nedenle prensip olarak ölçülebilir kalır. Ölçümü yapacak nicelik Bölüm
 16.3'te belirlenmiştir: parçacığın hangi yüzden döndüğü, yani enerjisinin
 işareti.

**Sonuç:** İşaret belirsizliği denklemlerin düzeyinde yapısaldır, ölçümün
düzeyinde değil. Bölge I tarafta da zamanın oku denklemlerden türetilmez,
Newton, Maxwell ve Schrödinger denklemlerinin hepsi $T$-simetriktir [54]; ok
başlangıç koşulundan gelir.

### 16.7 Bölge II'de hareketin tanımı

Çıkış yüzü Bölüm 16.3'te Bölge I'in enerjisinin işareti olarak belirlendi, çıkış
anı ise Bölüm 13'te genliğin fazından okundu. İkisi de parçacığın ara bölgede
**ne yaptığına** bağlanmamıştı. Bu bölüm o bağlantıyı kurar; simülasyonun
canlandıracağı nicelik tam olarak budur.

Bölge II'nin dört ekseninin karakterini Bölüm 10.1 vermişti. O bölümdeki tabloya göre
bir durum iki parçadan oluşur: üç zaman uzayındaki bir enerji vektörü ve tek uzay
ekseni boyunca bir dalga sayısı. Parçacığın yapabileceği şey de yalnızca ikiye
iner:

1. **Geçiş yönünde yer değiştirme.** Tek uzay ekseni boyunca ilerlemek. Ara
 bölgeyi kat etmek budur.
2. **Enerji vektörünün dönmesi.** Üç zaman düzleminden birinde bir açı süpürmek.
 Dönme vektörün uzunluğunu korur ve bu denetlenmiştir.

Birinci hareket bir yolculuktur, ikincisi bir yönelimdir. Sorulacak soru şudur:
iki gözlenebilir, yani çıkış yüzü ve çıkış anı, bu iki hareketten hangisini
görür.

### 16.8 Çıkış anı ve yolculuk süresi

Ara bölge yayılıma izin veriyorsa geçiş ekseni boyunca bir grup hızı tanımlıdır,
ve kalınlığın bu hıza bölümü bir yol süresi vermektedir. Bu süre fazdan okunan
çıkış anıyla karşılaştırıldığında ikisi birebir tutar:

| Kalınlık $d$ | Yol süresi | Fazdan okunan an |
| ------------ | ---------- | ---------------- |
| $1$ | $1{,}0776$ | $1{,}0776$ |
| $2$ | $2{,}1553$ | $2{,}1553$ |
| $4$ | $4{,}3105$ | $4{,}3105$ |

Aradaki artık $10^{-12}$ mertebesinde kalır. Yani bu rejimde çıkış anı gerçekten
bir yolculuk süresidir, ve parçacık dilini kullanmak tam anlamıyla meşrudur.

Engel rejiminde ise durum niteliksel olarak değişir. İçerideki mod sönümlüyse
grup hızı **yoktur**, dolayısıyla yol süresi de tanımsız kalır. Buna karşılık faz
yine belirli bir an vermeyi sürdürür:

| Kalınlık $d$ | Yol süresi | Fazdan okunan an |
| ------------ | ---------- | ---------------- |
| $2$ | tanımsız | $1{,}4629$ |
| $4$ | tanımsız | $1{,}4629$ |
| $8$ | tanımsız | $1{,}4629$ |

İkinci tablo, Bölüm 13.4'teki doyumun hareket dilindeki karşılığıdır, ve okunuşu
şudur: gecikmenin kalınlıkla artmaması **hızlı bir yolculuk** anlamına gelmez,
**yolculuğun hiç olmaması** anlamına gelir. Kat edilen bir mesafe yoktur, elde
yalnızca faz kalır.

Bu körlükten modelin geneli için bir sonuç daha çıkar: parçacık okuması ile dalga
okuması tam bu noktada ayrışmaktadır. Dalga okuması her iki rejimde de tanımlı
kalır, parçacık okuması ise yalnızca yayılımlı rejimde tanımlıdır. Ayrışmanın
kendisi de bir sonuçtur.

### 16.9 Çıkış yüzünün körlüğü

Enerji vektörü üç zaman düzleminden herhangi birinde, herhangi bir açıyla
döndürülse de geçiş dalga sayısı değişmez. Bunun nedeni açıktır: kütle kabuğu o
dalga sayısının büyüklüğünü yalnızca vektörün **uzunluğundan** belirler, dönme
ise uzunluğa dokunmaz.

Üç düzlemin her birinde yirmi dört açı ve üç farklı vektör uzunluğu tarandığında,
geçiş dalga sayısındaki en büyük değişim $10^{-9}$'un altında kalmıştır.
Dolayısıyla çıkış yüzü, parçacığın Bölge II'de izlediği yola hiçbir bağımlılık taşımaz. Yüz, ara
bölgenin
içinde değil, yüzeylerde belirlenmektedir.

### 16.10 Çıkış anının gördüğü düzlemler

Çıkış anı ise dönmeye kör değildir, ancak seçici davranır. Bölge II'nin enerji
vektörü geçiş altında Bölge I'in üç momentumuna karşılık gelir, ve
bileşenlerinden biri geçiş yönüne, ikisi ise enine yönlere düşmektedir. Bir dönme
çıkış anını ancak geçiş yönüyle enine yönler arasında ağırlık taşıdığında
değiştirmektedir:

| Dönme düzlemi | Çıkış anına etkisi |
| --------------------------------- | ------------------ |
| İki enine yuvanın gerdiği düzlem | Yok |
| Geçiş yuvasına dokunan iki düzlem | Var |

Tablonun ilk satırının nedeni şudur: enine düzlemdeki bir dönme enine
bileşenlerin kare toplamını korur, ve artık $10^{-12}$ mertebesinde kalır. Diğer
iki düzlemde ise dönme o toplamı değiştirmekte ve çıkış anı kaymaktadır.

Bu ayrım gözlem bakımından anlamlıdır: çıkış anına bakılarak parçacığın Bölge II'de **hangi düzlemde döndüğü** çıkarılabilir. Buna karşılık **hangi yüzden
çıktığı** hiçbir düzleme bağlı değildir.

### 16.11 İçerideki yolun izi

İçeride süpürülen açı süreklidir. Dönme açısı serbest bir parametre olduğundan,
birbirine ne kadar yakın iki değer seçilirse seçilsin iki farklı yol doğmaktadır;
örneğin çeyrek turluk bir dönme $1{,}1102$ radyan süpürmektedir. Buna karşılık
Bölge I'e ulaşan sapma, Bölüm 16.5'in nicelenmiş tayfının bir elemanıdır, ve
momentum $(1,2,3)$ için o tayf yalnızca **üç** değer taşır.

Sürekli bir küme bu adımda üç elemanlı bir kümeye düşmektedir. Bu düşüş, Bölüm
1.10'un dokuzuncu maddesinin somut karşılığıdır: Bölge II'deki yönelim, dönüş
olayının koordinatlarına ancak bir kısmıyla ulaşır. Kaybolan şey, parçacığın Bölge II'de izlediği yolun kendisidir. Geriye yalnızca o yolun iki ucu arasındaki
bileşke dönmenin nicelenmiş izi kalır.

**Bağlantının özeti.**

| Gözlenebilir | Neye bağlı | Nerede belirlenir |
| ------------ | ------------------------------------------------------ | --------------------- |
| Çıkış yüzü | Hiçbir içeri hareketini | Yüzeylerde |
| Çıkış anı | Yayılım varsa yolculuğu; dönmeyi üç düzlemden ikisinde | İçeride ve yüzeylerde |
| Sapma | Yolun yalnızca bileşkesini, nicelenmiş olarak | Yüzeylerde |

---

## 17. Koordinat sözlüğü

Sorulan soru şudur: parçacık Bölge II'de dört koordinattan birinde hareket eder
ya da yönelirse, bunun Bölge I'deki karşılığı ne olur. Bu bölüm o sözlüğü kurar,
Bölüm 18 ise sözlüğü kullanarak dönüş olayını hesaplamaktadır.

### 17.1 Sözlüğün bu bölümde kullanılan biçimi

Dört yuvanın karakterini, hangi yuvaya indiğini ve bir birim adımın Bölge I'in
saatinde ne ürettiğini Bölüm 10.1 tablo hâlinde vermişti, ve bu bölüm o tabloyu
tekrarlamaz. Sözlükten yalnızca iki sonuç gerekmektedir. Birincisi, dört yuvanın
dördü de eşikte karakter değiştirir. İkincisi, buna karşın hareket serbestliği
yuva yuva aynı kalmaktadır. Parçacık Bölge II'nin üç zamanında ve o üç zamanın
taşıdığı Bölge I uzay yönlerinde serbestçe hareket etmektedir. Buna karşılık Bölge II'nin tek uzay ekseninde ve onun taşıdığı Bölge I zamanında yön seçemez.

Sözlüğün en sıkı ifadesi de bu iki sonuçtan çıkar: tek yönlü koordinat iki bölgede **ayna
yerlerde** durmaktadır. Bölge I'in zamanı ile Bölge II'nin tek uzay ekseni aynı
koordinattır, ve ikisinde de yön seçilemez.

"Tek yönlü" ifadesinin içinde iki ayrı iddia gizlidir, yani yönlendirilebilirlik
ile ilerleme zorunluluğu. Bölüm 9.3 bu ikisini birbirinden ayırmakta ve yalnızca
birincisinin hesaplandığını göstermektedir.

Bu ifadenin Bölüm 4.1.3'ün sonucuyla nasıl bir arada durduğu da o bölümde yazılıdır.
Yön seçilemez, çünkü cisim o eksende geri dönemez. Dönüş anının işareti ise
cismin ilerleme yönünden değil, hangi geçiş dönüşümünün kullanıldığından gelir.
İki ifade farklı niceliklerden söz eder ve birbiriyle çelişmez.

### 17.2 Yönelimin gözlenemezliği

Üç zaman ekseni arasındaki $O(3)$ simetrisi bir ayar fazlalığıdır, ve bunun
sonucu şudur: Bölge II'de enerji vektörünün **yönü** fiziksel değildir, yalnızca
**uzunluğu** fizikseldir. Vektör döndürülebilir, ancak o dönmenin Bölge II'de
gözlenebilir bir karşılığı bulunmamaktadır.

Vektörün uzunluğunu ise kütle kabuğu sabitlemektedir. Uzunluk parçacığın enerjisi
ve kütlesiyle belirlenir, ve üç zaman düzleminden herhangi birinde döndürmek onu
değiştirmez; artık $10^{-16}$ mertebesinde kalır.

> Parçacık Bölge II'de **yönünü seçebilir, uzunluğunu seçemez.**

### 17.3 Üç zamandaki hareketin etkisi

Çekirdek sorunun en can alıcı yeri bu sorudur, ve cevabı iki parçadan oluşur.

**Doğrudan yol kapalı kalır.** Bunu Bölüm 10.1'in tablosu vermektedir: üç zamanın
her birinde bir birim adımın Bölge I'in saatindeki karşılığı tam olarak sıfırdır,
tek uzay ekseninde ise tam olarak birdir. Yani "Bölge II'de zamanda ilerledim, Bölge I'de
zamanda kaydım" cümlesini involüsyonun kendisi **desteklemez**, çünkü involüsyon
o hareketi Bölge I'in uzayına gönderir.

**Dolaylı yol ise açıktır.** Aynı enerji vektörünün bileşenleri iki yüzeydeki
eşleşmeye girmekte, ve dönüş anı o eşleşmenin fazından okunmaktadır. Uzunluk
sabit tutulup yalnızca yön değiştirildiğinde dönüş anı da değişir: yönelim küresi
tarandığında ulaşılan aralık, uzunluk $3$ için $62{,}4$ birim olmaktadır.

> Bölge II'deki yönelim, Bölge I'in zaman ekseninde **başka bir konumu işaret
> eder**. Ama bunu koordinat izdüşümüyle değil, eşleşmenin fazıyla yapar.

Bu ayrım korunmalıdır, çünkü iki farklı mekanizmadır ve biri diğerinin yerine
kullanılamaz.

### 17.4 Yönelimin komuta ettiği aralık

| Enerji vektörünün uzunluğu | Ulaşılan dönüş anı aralığı | Bölge I'in zamanını taşıyan eksen boyunca dönüş anı |
| -------------------------- | -------------------------- | --------------------------------------------------- |
| $2$ | $66{,}19$ | $2{,}2361$ |
| $3$ | $62{,}40$ | $2{,}1082$ |
| $5$ | $60{,}37$ | $2{,}0396$ |

İki çekince kayda geçirilmiştir.

**Birincisi, aralık uzunlukla daralmaktadır, genişlememektedir.** Yani daha hızlı
bir parçacığın dönüş anı üzerindeki seçim aralığı daha **dardır**. Bu, beklenenin
tersi bir sonuçtur ve doğrudan hesaptan çıkar.

**İkincisi, aralığın büyüklüğü yanıltıcıdır.** Aralığa hâkim olan katkı, yüzeye
teğet geçen yönelimlerden gelmektedir; teğet yönelimlerde normal dalga sayısı sıfıra gider ve
gecikme ıraksar. Bu nedenle $62{,}4$ sayısı fiziksel bir manevra kabiliyeti
değil, bir limit davranışıdır. Yine de teğetlikten uzakta da yönelim dönüş anını
değiştirmeyi sürdürür, dolayısıyla etki bir ıraksama yan ürünü sayılmaz; yalnızca
büyüklüğü bu sayının verdiği izlenimden küçük kalır.

### 17.5 Yönelim izinin kaynağı

Bölüm 17.3 yönelimin dönüş anını değiştirdiğini saçılma yoluyla buldu. Bu alt
bölüm aynı soruyu bağımsız bir yoldan sorar ve **etkinin nerede doğduğunu**
belirlemektedir.

**Ölçüt.** Bir durum aynı anda birden çok zaman değişkeninde evriliyorsa, her
değişken kendi üretecini taşır. Bu evrimler ancak zamanlar uzayındaki taşıma
yoldan bağımsız kaldığında tutarlı olur, ve o koşul da bileşenleri üreteçlerin
ikişerli komütatörleri olan bir eğriliğin sıfırlanmasını gerektirir. Ölçüt bu
çalışmaya ait değildir: çok zamanlı dalga fonksiyonları için [18] ve [19]'da
kurulmuş, ikincisi onu genel etkileşim potansiyelleri için tutarlılığın tam
koşulu olarak vermiştir. [18] ayrıca bu çalışma için önemli olan bir ayrımı yapar: çok
zamanlı bir betimleme, birden çok zamansı boyut demek değildir. Uygulanan
şey o ölçütün kendisidir, ve okunuşu şudur. Eğrilik sıfırsa yol hiçbir bilgi
taşımaz, tek zamana indirgeme de belirsizlik içermez. Sıfır değilse kapalı bir
yol durumun üzerinde bir holonomi bırakır, ve zamanlar arasındaki yönelim
gözlenebilir hâle gelir.

**Serbest kuram düzdür.** Bölge II'nin serbest alanında üç üreteç, tek bir enerji
vektörünün bileşenlerinden ibarettir ve birbiriyle komüte ederler. Bu yüzden üç
eğrilik bileşeninin üçü de tam olarak sıfır çıkmaktadır. Kapalı bir yolun
holonomisi de, yolun uzunluğu ne olursa olsun kaybolur; bu $1000$ birimlik bir
yol için ayrıca denetlenmiştir.

> İçerideki yol, serbest evrim tarafından **kaydedilmez**. Dolayısıyla Bölüm
> 17.3'te bulunan yönelim bağımlılığının kaynağı ara bölgenin içi olamaz.

**Eğriliği yüzeyler getirmektedir.** İki eşik yüzeyindeki eşleşme, geçiş
doğrultusunu enine doğrultulara karıştırır, ve üreteçler bu karışım altında
komüte etmeyi bırakır. Ortaya çıkan eğrilik bağlaşım gücüyle doğru orantılıdır ve
bağlaşım sıfırlandığında tümüyle kaybolur. Dolayısıyla etkinin **tamamı**
yüzeylere aittir.

**İki hesabın örtüşmesi.** Bu örtüşme bağımsız bir sınamadır, ve durum durum
tutmaktadır:

| Durum | Yüzey eğriliği | Saçılmanın dönüş anını oynatması |
| -------------------------------------------------------------------------------- | -------------- | -------------------------------- |
| Geçiş yuvasında ağırlığı olmayan vektör, diğer iki yuvanın düzleminde döndürülür | $0$ | $0$ |
| Genel bir vektör, geçiş yuvasına dokunan düzlemde döndürülür | $3{,}000$ | $1{,}6383$ |

Eğrilik ayrıca yalnızca geçiş yuvasına dokunan iki düzlemde sıfırdan farklı
çıkmaktadır; diğer iki yuvanın gerdiği düzlem, yüzeyler hesaba katıldığında bile
düz kalır. Seçilen bu iki düzlem, Bölüm 16.10'da fazdan bağımsız olarak bulunan
düzlemlerin **aynısıdır**: çıkış anı üç zaman düzleminden ikisine bağlıdır, birine
bağlı değildir. Yani iki ayrı yoldan aynı iki düzleme varılmıştır.

**Sonuç.** Yönelimin Bölge I'in zaman eksenindeki izi gerçektir, ancak ara
bölgenin içinde değil **sınırında** doğmaktadır. Bunu iki hesaptan hiçbiri tek
başına veremez: saçılma etkinin varlığını verir, eğrilik ölçütü ise yerini.

---

## 18. Yönelimden dönüş olayına

Önceki bölümler dönüşümün parçalarını ayrı ayrı kurmuştu. Bu bölüm o parçaları
tek bir hesapta birleştirmekte, ve dönüşümün tanım kümesini baştan sona
taramaktadır.

### 18.1 Tanım kümesi

Bölge II'deki bir durum iki veriden oluşur:

1. **Yönelim.** Üç zaman uzayındaki enerji vektörünün doğrultusu. Uzunluk kütle
 kabuğu tarafından sabitlendiğinden, doğrultu bir **iki-küre** üzerinde
 değişir.
2. **İlerleme işareti.** Tek uzay ekseni boyunca dalga sayısının işareti,
 $\sigma = \pm 1$. Bu işaret, sekiz geçiş matrisinden hangisinin işlediğini
 adlandıran **dal** ile aynı nicelik değildir: dal varış anının işaretini
 belirler, ilerleme işareti ise belirlemez. Hangi koordinatın hangisine
 bağlı olduğunu Bölüm 18.3 vermektedir.

İki veri birleşince dönüşümün tanım kümesi $S^2 \times \mathbb{Z}_2$ olmaktadır.
Tarama bu sürekli uzayı bir ızgarayla örnekler: kutup açısı on üç, azimut açısı
on iki değer alır, ve iki ilerleme işaretiyle birlikte $312$ durum çıkar. Izgara
sürekli kümenin yerini tutmaz, yalnızca onu örnekler.

### 18.2 Değer kümesi

Dönüş olayı Bölge I'in bir noktasıdır ve giriş olayına göre dört koordinatı
vardır:

$$(t,\; x_{\perp},\; y,\; z)_{\text{dönüş}}$$

Bu ifadede $t$ geçen süreyi, $x_{\perp}$ geçiş doğrultusundaki yer değiştirmeyi, $y$
ile $z$ ise enine yer değiştirmeleri göstermektedir. Dördü de Bölge II'deki
durumdan hesaplanır, ancak dördü farklı yerlerden gelir:

| Koordinat | Nereden gelir |
| ----------- | --------------------------------------------------------------------- |
| $t$ | İki geçişin ortak genliğinin fazından; içeride saat taşınamadığı için |
| $x_{\perp}$ | İlerleme işaretinden: sıfır ya da kalınlık, yani hangi yüzden çıktığı |
| $y,\, z$ | Paket merkezinin kayması, yönelimin enine bileşenlerine dağıtılmış |

Taranan $312$ durumun tamamı sonlu ve belirli bir olaya gitmektedir, yani
dönüşümde tanımsız nokta bulunmaz. Aşağıdaki üç örnek dönüşümün ne verdiğini
somutlaştırmaktadır ($d = 2$, uzunluk kütle kabuğundan):

| Kutup açısı | $t$ | $x_{\perp}$ | $(y,\, z)$ |
| ----------- | ----------- | ----------- | -------------------------- |
| $0{,}4$ | $23{,}8700$ | $2{,}0000$ | $(+0{,}0015,\; +0{,}0041)$ |
| $1{,}2$ | $9{,}9732$ | $2{,}0000$ | $(+0{,}0037,\; +0{,}0016)$ |
| $2{,}5$ | $15{,}5319$ | $2{,}0000$ | $(+0{,}0024,\; -0{,}0036)$ |

Geçiş doğrultusundaki yer değiştirme üçünde de aynıdır, çünkü yalnızca ilerleme
işaretine bağlıdır; geçen süre ile enine yer değiştirmeler ise yönelimle birlikte
değişmektedir.

### 18.3 Koordinatların gördüğü durum bileşenleri

Dönüşümün yapısı şöyle görülür: dört koordinat birbirinden bağımsız kaynaklara
bağlanmaktadır.

| Koordinat | Yönelime bağlı mı | İlerleme işaretine bağlı mı |
| ----------- | ----------------- | ------------- |
| $t$ | Evet | **Hayır** |
| $x_{\perp}$ | **Hayır** | Evet |
| $y,\, z$ | Evet | Hayır |

Tablonun en önemli satırı ilkidir, ve okunuşu şudur: **parçacığın ne zaman
döndüğünü ile nereden döndüğünü ayrı nicelikler belirlemektedir.** Zaman bileşeni
ilerleme işaretine hiç bağlı değildir, geçiş yönündeki yer değiştirme ise
yönelime hiç bağlı değildir.

### 18.4 Dönüşümün tanım kümesini sıkıştırması

Taranan $312$ durum yalnızca $158$ farklı olaya gitmektedir. Yani dönüşüm birebir
değildir: Bölge II'deki farklı durumlar Bölge I'de aynı olaya varır. Bu
sıkışma, boyut değişiminde kaybolan bilginin sayısal ölçüsüdür, ve Bölüm
16.5'te sapma tayfının sürekliden ayrığa düşmesiyle aynı olgunun başka bir
görünümüdür.

### 18.5 Işık sinyaliyle karşılaştırma

Çekirdek sorunun asıl hedefi dört koordinattan zaman bileşenidir. Onu
değerlendirmek için bir ölçüt gerekir, ve ölçüt aynı gidiş dönüşü ışığın yapması
için geçen süredir, yani $2d/c$.

Engel rejiminde ($\omega = 2{,}8$, Öklid ara bölge) karşılaştırma şöyle çıkar:

| Kalınlık $d$ | Işığın gerektirdiği | Parçacığın dönüş anı | Fark |
| ------------ | ------------------- | -------------------- | ------------ |
| $2$ | $4{,}00$ | $2{,}9258$ | $+1{,}0742$ |
| $4$ | $8{,}00$ | $2{,}9257$ | $+5{,}0743$ |
| $8$ | $16{,}00$ | $2{,}9257$ | $+13{,}0743$ |
| $16$ | $32{,}00$ | $2{,}9257$ | $+29{,}0743$ |

Tablodaki iki sütun **aynı geçişte** ölçülmektedir, ve bu bir düzeltmenin
sonucudur. Işık süresi bir gidiş dönüş süresi olduğundan, parçacığın süresi de
bölgenin iki kez kat edilmesine, yani tek geçişin iki katına karşılık gelmelidir.
Çalışmanın önceki bir sürümünde gidiş dönüş ışık süresi **tek geçişlik** bir
gecikmeyle karşılaştırılıyordu, ve bu geçişi tam bir geçiş kadar kayırıyordu.
Hangi sürenin hangisi olduğunu Bölüm 18.7'nin kapalı biçimi kesinleştirmektedir:
tek bir engel için doymuş faz süresi $2\omega/(c^2\kappa\beta)$'dır, yani
$1{,}4629$ değeri tek geçişe aittir.

Dönüş anı kalınlıkla doyduğundan, ışık süresi ise doymadığından **fark sınırsız
büyümektedir**; fark $2d - 2{,}9257$ biçiminde gider. Yani bölge ne kadar
kalınlaştırılırsa, dönüş olayı ışığın varabileceği andan o kadar öne düşer.

### 18.6 Farkın kapsamı ve sınırları

Yukarıdaki farkın ne olduğu ile ne olmadığı, çalışmanın kendi çekincesini
oluşturmaktadır.

**Olduğu şey.** Dönüş olayının zaman koordinatı, kesintisiz hiçbir ışık
sinyalinin ulaşamayacağı bir yere düşmektedir. Çekirdek sorunun "zamanda
yolculuk" kısmı da bu koordinatın konumu olarak tanımlanmıştır, ve hesap onu
vermektedir.

**Olmadığı şey.** Bu sonuç ışıktan hızlı bir **yayılma** değildir. Aynı rejimde
içeride grup hızı diye bir nicelik bulunmaz, çünkü mod sönümlüdür ve sönümlü bir
modda kat edilen bir mesafeden söz edilemez. Ölçülen tek şey, dönen paketin
**tepe noktasının** nereye düştüğüdür.

**Ve bir sinyal taşımadığı.** Ayrım bu noktada zorunludur, çünkü üstışık bir
sinyalin geçmişe ulaşmasının nedensel maliyetini [50] ile [36] saymaktadır:
böyle bir düzenek ya negatif sonuç verir ya da çelişki üretir. Hangi üstışık
türünün nedenselliği gerçekten çiğnediğini ise [51] ayırmaktadır. Aşağıdaki hesap bir sinyal
iddiası taşımadığı için o ikilemin dışında durur. Bu nokta açık bırakılmamış,
hesaba dâhil edilmiştir: hesap dalganın ön cephesini tepesinden ayrı
hesaplamaktadır. Cephe hızının frekans büyüdükçe ışık hızına inmesi [72] ile
[73]'ün klasik sonucudur, ve bu çalışma onu ödünç almak yerine kendi
dispersiyon bağıntısından yeniden üretmiştir: faz hızı $k = 10$ için
$1{,}004988$, $k = 100$ için $1{,}000050$ çıkmakta, ve sonsuz frekans sınırında
$c$'ye inmektedir. Ara bölge de cepheyi hiçbir
kalınlıkta öne almaz. Tepenin öne alınması büyürken de onu
taşıyan genlik çökmektedir: $d = 32$ için $5{,}2 \times 10^{-32}$'ye iner. Yukarıdaki $+29{,}0743$,
bir mesajın ışığı geçtiği anlamına gelmez ve bu çalışma öyle bir iddiada
bulunmamaktadır.

**Ayrıca tek okuma da değildir.** Aynı genlikten beş ayrı okuma türetilebilir:
faz okuması, ikamet süresi, dönme bileşeni, hizalanma okuması ve yarı klasik
okuma. Bunlardan dönme bileşeni ile ikamet süresi aynı niceliktir, dolayısıyla
geriye dört ayrı değer kalmıştır. Bölüm 11.6 bu listeden üçünü ele almıştı, ve
karşılıkları şöyledir: nokta cisim okuması yarı klasik okumadır, dalga okuması
faz okumasıdır, genlik okuması ise ikamet süresidir. Beş okumanın üçü
geçişi ışığın üstüne, ikisi altına koyar, ve aradaki ayrım kalınlıkla
değişmemektedir. Yukarıdaki tablo bunlardan faz okumasına
dayanmaktadır, çünkü sorulan soru dışarıdaki bir dedektörde tepenin ne zaman
göründüğüdür. Bu bir seçimdir, ancak seçimi kurmayan bağımsız bir ölçüt Bölüm
11.6'da onu doğrulamıştır: yayılan paketin tepesi ölçüldüğünde tutan okuma
fazdır.

### 18.7 Dönüşümün kapalı biçimi

Bölüm 18.1 ile Bölüm 18.6 arası dönüşümü **tarayarak** vermişti. Oysa tarama tam
bir cevap sayılmaz: taranan durumların nereye gittiğini verir, ama dönüşümün
**ne olduğunu** vermez. Bu alt bölüm onu formül olarak yazmaktadır. Literatür
taraması bu dönüşümün hiçbir biçimini bulamamıştır, dolayısıyla aşağıdaki formülü
bu çalışma üretir.

**Formülü iki özdeşlik kısaltmaktadır, ve ikisi de yaklaşık değil tamdır.**

**Birinci özdeşlik.** Dış normal dalga sayısı, enerji vektörünün **birinci
bileşenine** eşittir. Kütle kabuğu frekansı vektörün uzunluğundan sabitler, enine
dalga sayısı öteki iki bileşenin uzunluğunu verir, ve aradaki fark birinci
bileşeni yalnız bırakır:

$$\kappa^2 = \frac{\omega^2}{c^2} - k_T^2 - \mu = (E_1^2 + E_2^2 + E_3^2 + \mu) - (E_2^2 + E_3^2) - \mu = E_1^2$$

$$\boxed{\;\kappa = |E_1|\;}$$

Yani modun yüzeyle nasıl karşılaştığına karar veren nicelik, yönelimin bir
fonksiyonu değil doğrudan **bir koordinatıdır**. Formülü kısaltan şey de budur.

**İkinci özdeşlik.** İç sönüm sabiti de aynı üç bileşenden kurulmaktadır; tek ek
girdi, imzası çevrilen yön sayısı $n$ olur:

$$\beta^2 = \frac{2n}{3}\,(E_2^2 + E_3^2) - E_1^2$$

Dolayısıyla ara bölgenin engel mi yoksa geçit mi olduğu, bileşenler arasındaki
düz bir eşitsizliğe inmektedir. Öklid ara bölge için ($n = 3$) bu eşitsizlik
şudur:

$$\text{engel} \iff 2(E_2^2 + E_3^2) > E_1^2$$

**Geçen süre, kapalı biçimde.** Engel rejiminde, **tek geçiş** için:

$$\boxed{\; t(\mathbf{E}) \;=\; \frac{2\,\omega}{c^2\,\kappa\,\beta} \;=\; \frac{2\sqrt{E_1^2+E_2^2+E_3^2+\mu}}{|E_1|\;\sqrt{2(E_2^2+E_3^2)-E_1^2}} \;}$$

(son eşitlik $c = 1$ ve Öklid ara bölge içindir.)

Gidiş dönüş bölgeyi iki kez kateder, dolayısıyla dönüş olayının zaman koordinatı
bunun **iki katıdır**:

$$t_{\text{gidiş dönüş}}(\mathbf{E}) \;=\; \frac{4\,\omega}{c^2\,\kappa\,\beta}$$

Bölüm 18.5'in tablosu bu nicelikle kurulmuştur, ve ışık süresi de bir gidiş dönüş
süresi olduğundan ikisi aynı geçişe aittir.

**Formülün içinde kalınlık geçmez.** Yani doyum, bir tabloda sonradan fark edilen
bir olgu değil, doğrudan bir **özdeşliktir**. Saçılma hesabıyla
karşılaştırıldığında şu çıkar:

| $d$ | Saçılma hesabı | Kapalı biçim | Artık |
| ---- | -------------- | ------------ | ----------------------- |
| $4$ | $1{,}462864$ | $1{,}462864$ | $3{,}9 \times 10^{-8}$ |
| $8$ | $1{,}462864$ | $1{,}462864$ | $6{,}6 \times 10^{-11}$ |
| $16$ | $1{,}462864$ | $1{,}462864$ | $7{,}1 \times 10^{-11}$ |
| $32$ | $1{,}462864$ | $1{,}462864$ | $7{,}2 \times 10^{-11}$ |

**Sonlu kalınlık biçimi.** Doyum henüz kurulmamışken de geçerli olan tam biçim,
doyuma götüren çarpanı açıkça taşımaktadır. $u = 2\kappa\beta /
[(\kappa^2-\beta^2)\tanh(\beta d)]$ yazıldığında:

$$\arg T = \frac{\pi}{2} - \arctan u, \qquad t = -\frac{1}{1+u^2}\,\frac{du}{d\omega}$$

$$\frac{d\kappa}{d\omega} = \frac{\omega}{c^2\kappa}, \qquad \frac{d\beta}{d\omega} = -\frac{\omega}{c^2\beta}$$

$\tanh(\beta d) \to 1$ limitinde $u$ değeri $2\kappa\beta/(\kappa^2-\beta^2)$'ye
gitmekte, kalınlık formülden düşmekte ve yukarıdaki kapalı biçim geri
gelmektedir. Bu tam
biçim sonlu kalınlıkta da saçılma hesabıyla örtüşmektedir: $d = 1$ için
$1{,}451403$, $d = 2$ için $1{,}462898$ çıkar, ve iki yol da aynı sayıyı verir.

**Dört koordinatın tamamı.** Bölge II'deki bir durumu, üç zamandaki enerji
vektörü $\mathbf{E}$ ile tek uzay eksenindeki ilerleme işareti
$\sigma = \pm 1$ belirler.
Dönüş olayının dört koordinatı da bunlardan çıkar:

$$t = \frac{4\omega}{c^2\,|E_1|\,\beta}, \qquad
x_\perp = d\,\frac{1+\sigma}{2}, \qquad y = S(d)\,\frac{E_2}{|\mathbf{E}|},
\qquad z = S(d)\,\frac{E_3}{|\mathbf{E}|}$$

Bu ifadede $S(d)$ paket merkezinin kaymasıdır ve iki enine koordinatın **ortak**
çarpanıdır. Okunuşu:

> **Ne zaman** döndüğü yalnızca yönelime bağlıdır, ilerleme işaretine hiç bağlı
> değildir. **Nereden**
> çıktığı yalnızca dala bakar, yönelime hiç bakmaz. **Ne kadar saptığı** ise
> yönelimin enine bileşenlerine bakar ve iki sapma tek bir çarpanı paylaşır.

Taranan olayın her koordinatı bu formülle yeniden üretilmektedir. Dolayısıyla
tarama artık cevaba giden tek yol değil, **formülün üzerindeki bir denetimdir**.

### 18.8 Yönün Bölge I'den seçilebilirliği

Yukarıdaki formül Bölge II'deki yer değiştirmeyi veri olarak almaktadır. O yer
değiştirmenin **işareti** dönüş anını doğrudan belirlediğine göre, işaretin Bölge
I'den kurulup kurulamayacağı ayrı ve meşru bir soru hâline gelir.

**Karıştırılmaması gereken iki soru vardır.** Birincisi, hangi geçiş dönüşümünün
gerçekleştiğidir; bu soru Bölge I'in zaman yuvasıyla Bölge II'nin ayrıcalıklı uzay
eksenini **birlikte** ters çeviren dönüşüme bakar, ve o dönüşüm ayrıca
incelenmiştir. Bu bölümün sorusu ise dönüşüm verilmişken **yolculuğun yönüdür**, ve
yalnızca geçiş ekseninin ters çevrilmesine bakar. İşaret dizisi olarak
yazıldığında birincisi $(-1,-1,+1,+1)$, ikincisi $(+1,-1,+1,+1)$ olur; çarpımları
$(-1,+1,+1,+1)$, yani Bölge I zamanının saf ters çevrilmesidir. İkisi farklı grup
öğeleri olduğundan, biri hakkındaki bir teorem ötekini kapatmaz.

**Geçişi biçimlendirerek yön verilemez.** [74]'ün karşılıklılık sonucu
şunu söylemektedir. Her iki uçta yön başına tek bir yayılan kanal varsa, uzaysal
olarak bakışımsız bir engelin geçirgenliği soldan ve sağdan giriş için aynı
kalır. Bu sonuç, zamanda tersinirlik ile birimsellikten çıkmaktadır. Bu çalışma onu olduğu gibi
benimsemekle yetinmez, kendi kurduğu profillerle yeniden üretmiştir. Çarpık
profil için geçirgenlik iki yönde de $4{,}9096125448 \times 10^{-3}$ çıkmakta ve
aradaki fark $7 \times 10^{-18}$ mertebesinde kalmaktadır. Profilin gerçekten
bakışımsız olduğu da ayrıca doğrulanmıştır. Eşitlik tek bir kalınlığa da bağlı
değildir: beş kalınlık ile üç derinlikten kurulu on beş yapılanmanın hepsinde
iki yön arasındaki fark $10^{-15}$ altında kalmaktadır. Dolayısıyla eşitliği
profilde gizlenmiş bir bakışım değil doğrudan teorem vermektedir, ve kurulan
beş profilin hiçbiri iki yönde farklı geçirmez.

> Tek kanallı bir gönderimde yolculuğun yönü, parçacığın zaten taşıdığı
> işarettir. Engelin biçimi, kalınlığı ve bakışımsızlığı bu işareti
> **değiştirmez**.

**Karşılıklılığın açık bıraktığı tek yer, gelen durumun kendisidir.** Eşevreli
bir kanal çiftinin taşıdığı yön, kanallar arası bağıl fazın tek başına
belirlediği bir niceliktir. Ağırlıkları $A$ ve $B$, bağıl fazı $\varphi$ olan bir
çift için yön göstergesi $2AB\sin\varphi$ olur, ve $\varphi$ işaret değiştirdiğinde
göstergenin işareti de döner. Yani yanlılık engelde değil, gelen durumda
saklıdır.

Bu gereksinim, sekiz matris taramasının öteki uçtan vardığı gereksinimle **aynı
biçimdedir**: tam olarak bir eksende tek olan bir nicelik. O bölümde bu nicelik dönüşüm
seçimi için gerekiyordu, bu bölümde ise yolculuk yönü için gerekmektedir.

İki ters çevirmenin ayrı tutulması özgün bir gözlem değildir. Saçılma kuramının
olağan sınıflandırmasında [74] karşılıklılık, zamanda tersinme ve uzaysal evirme
**ayrı işlemlerdir** ve karşılıklılık yalnızca geçirgenlik genliklerini bağlar.
Yapılan iş, o sınıflandırmanın bu geçişe uygulanmasıdır.

**Yine de bu bölüm bir sonuç iddia etmemektedir.** Bölge II tek bir uzay ekseni
taşımaktadır, ve yukarıdaki kanal çifti o eksenden türemez; bu alt bölüm onu elle
yazmıştır. Böyle bir kanal yapısını bu çalışma **sağlamamaktadır**. Dolayısıyla
bu bölümün hesabı bir yön verme yöntemi kurmaz, yalnızca yön vermenin inşa edilmesi
gereken **tek yerini** işaret eder.

### 18.9 Bölge I'de ölçülebilenler

Bu çalışmanın aradığı ölçüm Bölge II'nin içinde değil, Bölge I'de durmaktadır.
Deney parçacığı gönderir, parçacık geri döner, ve Bölge I'in saati dönüş anını
verir; iddia da bu tek okumaya dayanmıştır. Bu bölümün sorusu bu yüzden
"içerisi görülebilir mi" değil, **dönüşte Bölge I'de ne okunabildiğidir**.

Bölge I üç nicelik verir: dönüş anının kendisi, eşiğin iki yüzü arasında geçen
ağırlık, ve katman şiddeti. İddiayı taşıyan sonuç birincisinden çıkmıştır.
Kalan ikisi ise geçişin gerçekleştiğini bildirir. Buna karşılık Bölge II'nin
içi doğrudan ölçüme kapalı kalmıştır, ve bölümün geri kalanı bu kapalılığın
nereden geldiğini kurar.

**Konumlandırma reddedilir.** Uzaysal türden bir dörtlü momentum, öz durumları
nedenselliğe saygı gösteren bir konum işlemcisini kabul etmemektedir [63], [64]. Dolayısıyla
parçacığın Bölge II'de nerede olduğunu söyleyen bir durum bulunmaz, ve bu çalışma
da böyle bir durum sağlamamaktadır. Yazılan cümle bir hesap değil, bir kayıttır.

**Var olan yöntem parçacığa değil, sınıra bakar.** [65]'in kullandığı eksik
kütle yöntemi giren ve
çıkan her şeyi ölçüp farkın değişmezini kurar, ve uzaysal türden bir taşıyıcı o
değişmezin negatif çıkmasıyla kendini belli eder. Yani yöntemin öznesi yolcu
değil, tutulan hesabın kendisidir.

Ne var ki bu yöntem, etkileşimden ayrılan **gerçek bir kütle kabuğu momentumunu**
varsaymaktadır, oysa bu kurgudaki iç bölge her zaman böyle bir momentum taşımaz.
Öklidyen bir bölgede, enine kare toplamı 4 ve $c = \mu = 1$ iken iç mod
$\omega = \sqrt{13} \approx 3{,}6056$ frekansının altında sönmekte, üstünde ise
yayılmaktadır:

| $\omega$ | Geçiş dalga sayısının karesi | Kütle kabuğunda | Gidiş dönüş rejimi |
| -------- | ---------------------------- | --------------- | ------------------ |
| $1{,}5$ | $-10{,}75$ | hayır | evet |
| $2{,}8$ | $-5{,}16$ | hayır | evet |
| $6$ | $+23{,}00$ | evet | hayır |
| $12$ | $+131{,}00$ | evet | hayır |

**Denetlenen şey gerek koşuldur, yeter koşul değil.** Yöntemin gerçekten okuduğu
nicelik, dörtlü momentumun bir değişmezinin işaretidir. Yukarıdaki sütun ise tek
bir eksen boyunca dalga sayısının karesini vermektedir, yani **başka bir
nesnedir**. Bu çalışma o değişmezi hiçbir yerde hesaplamamış, dolayısıyla bir
kütle imzası da iddia etmemiştir. Elde kalan tek sonuç, rejim ayrımının
kendisidir.

İki rejim birbirinin tümleyenidir. Bunu iki ayrı yoldan yazılmış iki yüklem
doğrular: biri iç dalga sayısından, öteki eşik eniyilemesinin kullandığı engel
testinden gelmektedir. Taranan dört bin frekansın hiçbiri, iç modu kütle
kabuğuna taşıyıp aynı anda gecikmenin doymasına izin vermemektedir. Bu
tümleyenlik de yeni bir olgu değildir, çünkü sönümlü mod geçiş süresine katkı
vermez ve gecikmenin doyması zaten iç bölgenin sönümlü olmasını gerektirir.
Yapılan tek şey, bilinen bu bağı bu bölgeye uygulayıp gözlemle karşı
karşıya getirmektir. Sonuç bu nedenle bir yöntem değil, bir **gerilim** olarak
çıkar:

> İç bölgede kütle kabuğunda bir mod bulunan rejimde varış **öne alınmaz**.
> Varışın öne alındığı rejimde ise gözlenecek bir kütle kabuğu modu **yoktur**.

**Geriye kalan.** İddiayı taşıyan sönümlü rejimde elde kalan gözlenebilirler,
bu çalışmanın zaten hesapladığı iki sınır niceliğidir: geçen ağırlık ve katman
şiddeti. İkisi de iki aileyi ayıran ters çevirme altında çift olduğundan, yalnızca
bir geçişin **olduğunu** bildirebilirler. İçeride ne olduğunu vermezler,
parçacığın hangi yöne gittiğini de vermezler.

Bu sonuç iddiayı düşürmez, çünkü iddia zaten Bölge I'de okunan dönüş anına
dayanmaktadır. Düşen şey **tanı gücüdür**: bir geçişin olduğu ve dönüşün hangi
ana düştüğü ölçülebilir, ancak parçacığın Bölge II'de izlediği yol
ölçülemez.

---

## 19. Sonuç ve yedi adım

Önceki bölümler sonuca giden adımları ayrı ayrı kurdu. Bu bölüm adımları tek bir
yerde birleştirir ve her birinin hangi bölümde kurulduğunu göstermektedir. Yeni
bir hesap içermez. Eklediği tek şey, iddianın **tam olarak ne kadar** olduğunun
tek cümlede sabitlenmesidir.

**Yedi adım.**

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
6. **Engel rejiminde gecikme kalınlığa doyar, yer değiştirme doymaz.** Doyum bir
 tabloda fark edilen bir olgu değil, kapalı biçimin bir özdeşliğidir: formülde
 kalınlık geçmez (Bölüm 18.7). Rejim kaydı zorunludur, çünkü yayılımlı bir ara
 bölgede gecikme doymaz, salınır (Bölüm 13.5).
7. **Dolayısıyla bir eşik mesafesi vardır ve ötesinde varış, girişten öncedir.**
 Eşik mesafesinin sayısal değeri enerji vektörünün yönelimine bağlıdır. Bölüm
 4.1.3'ün yönelimi, Öklidyen ara bölge, $d = 8$ ve $c = \mu = 1$ için
 $2{,}565988$ verir; aşağıdaki örnek başka bir yönelim kullandığından
 $2{,}434322$ verecektir. İki sayı aynı formülün iki farklı girdideki
 değeridir.

**Yedi adımın tek bir parçacık üzerinde yürütülmesi.** Yukarıdaki adımlar ayrı
ayrı kuruludur, ve hepsini birden kapatan tek bir örnek şudur. Ara bölge Öklidyen
ve kalınlığı $8$ alınır, $c = \mu = 1$ seçilir, parçacığın toplam enerjisi $9$
olur. Bu parçacığın enerji vektörü
$(1{,}732051,\ 1{,}732051,\ 1{,}732051)$, frekansı $3{,}162278$, dışarıdaki dalga
sayısı $1{,}732051$ ve içerideki sönüm katsayısı $3{,}000000$ değerindedir. Parçacık
bölgeyi engel olarak gördüğünden gecikme de doymuştur.

Gidiş dönüş bölgenin içinde $2{,}434322$ birim harcamaktadır. Kalkışa göre ölçülen
dönüş anı ise Bölge II'de kat edilen mesafeyle birlikte şöyle değişmektedir:

| Bölge II'de kat edilen | Dönüş anı | Sonuç |
| ---------------------- | ------------- | -------------------------- |
| $1{,}000000$ | $+1{,}434322$ | kalktıktan **sonra** döner |
| $2{,}434322$ | $0{,}000000$ | tam kalktığı anda döner |
| $6{,}000000$ | $-3{,}565678$ | kalkmadan **önce** döner |

Üç yolculuğun parçacığı, bölgesi ve enerjisi aynıdır; ayrıştıkları tek yer Bölge II'de ne kadar gidildiğidir. Öteki dal seçilseydi aynı yolculuk daha geç
inecekti, yani işaret yolculuğun bir özelliği değil geçişin bir seçimidir.

**Yolculuğun adım adım dökümü.** Tablonun üçüncü satırı, yani eşiği aşan yolculuk,
bütün ara nicelikleriyle birlikte aşağıda verilmiştir. Her satır ilgili bölümün
hesabıdır ve bu bölümde yeniden türetilmez, yalnızca çağrılır.

| Adım | Nicelik | Değer |
| ---- | ----------------------------------------- | ------------------------------- |
| 1 | Enerji bölüşümü: normal, enine, toplam | $3{,}000000$, $6{,}000000$, $9$ |
| 2 | Kütle kabuğundan frekans | $3{,}162278$ |
| 3 | Dışarıdaki dalga sayısı, içerideki sönüm | $1{,}732051$, $3{,}000000$ |
| 4 | Opaklık: sönüm çarpı kalınlık | $24{,}0000$, doyum sağlanmış |
| 5 | Tek geçişin faz gecikmesi | $1{,}217161$ |
| 6 | İki geçiş, yani gidiş dönüş gecikmesi | $2{,}434322$ |
| 7 | Gereken Bölge II mesafesi | $2{,}434322$ |
| 8 | Kat edilen mesafe ve ilerleme işareti | $6{,}000000$, $\sigma = -1$ |
| 9 | Dönüş olayı: geçen süre | $-3{,}565678$ |
| 9 | Dönüş olayı: geçiş yönünde yer değiştirme | $0{,}000000$ |
| 9 | Dönüş olayı: iki enine yer değiştirme | $+0{,}009483$, $+0{,}009483$ |
| 10 | Dönen ağırlık | $1{,}827983 \times 10^{-41}$ |
| 11 | Aynı gidiş dönüşü yapan ışık | $16{,}000000$ |
| 11 | Parçacığın ışığa karşı önceliği | $19{,}565678$ |

Dokuzuncu adımdaki dört sayı, dönüş olayının dört koordinatıdır ve **kapalı
formülden** gelmektedir (Bölüm 18.7). Bu döküm onları yeniden hesaplamaz,
doğrudan formülden okur, ve böylece yukarıdaki yedi adımdan sapması imkânsız
kalır.

On birinci adımda karşılaştırmanın **iki tarafı da gidiş dönüştür**. Işık
$2d/c = 16$ harcar, parçacık ise $-3{,}565678$ ile döner. Bu eşitlik
denetlenmiştir. Tek geçiş ile gidiş dönüşü birbirine karıştırmak bu çalışmada
iki kez ikilik çarpan hatasına yol açtı; bugün o eşitlik bir kabul değil, ayrı
bir denetimdir.

**Tablodaki mesafe nerede kat ediliyor.** Söz konusu iki ayrı yer vardır, ve
örneğin geçerliliği bu ikisinin birbirinden ayrı tutulmasına bağlıdır.

**Ara bölgenin içinde** kat edilen bir mesafe **yoktur**. İçerideki mod
sönümlüdür, grup hızı tanımsız kalmaktadır, ve gecikmenin kalınlıkla artmaması hızlı
bir yolculuğa değil yolculuğun hiç olmamasına karşılık gelir; elde yalnızca faz
kalır (Bölüm 16.8). Bu nedenle tablodaki $2{,}434322$ bir yol süresi değil, iki
geçişin faz gecikmesidir, ve tablonun hiçbir satırında kalınlık değişmemektedir.

**Bölge II'de** kat edilen mesafe ise bundan bağımsız bir niceliktir. Bölge II
bir engel değildir: o rejimde mod sönümlü kalmamakta ve tek uzay ekseni boyunca
hareket olağan anlamıyla tanımlı olmaktadır (Bölüm 10.1, Bölüm 17.2). Tablonun satırdan satıra
değişen sütunu da bu niceliktir.

Bu ayrım olmasaydı örnek kendi kendini çürütürdü, çünkü sönümlü bir bölgenin
içinde yolculuk diline başvurmak Bölüm 16.8'in tam olarak reddettiği şeydir.
Örnek buna başvurmaz: ara bölge yalnızca bir faz gecikmesi katmakta, mesafe ise
bütünüyle Bölge II'de kat edilmektedir.

**Bedeli de aynı yerde yazılıdır.** Bu yolculukta parçacık
$1{,}83 \times 10^{-41}$ ağırlıkla dönmektedir. Ne var ki bu ağırlık bir yasak
anlamına gelmez. Doyum derinliği sabit tutulup enerji yükseltildiğinde gereken
mesafe $2{,}4343$'ten sırasıyla $0{,}9895$, $0{,}3101$ ve $0{,}0980$'a
inmektedir. Buna karşılık tek geçişin genliği $4{,}293312 \times 10^{-3}$ ve gidiş dönüşün
ağırlığı $3{,}397579 \times 10^{-10}$ değerinde **kıpırdamadan** kalır. Ödenen
şey enerji ve daha ince bir bölgedir.

**Sonucun ifadesini** Bölüm 1.1'in "Ana sonuç" paragrafı vermiştir, ve bu bölüm
onu tekrarlamaz. Bu bölümün katkısı başkadır: yedi adımın o ifadeyi nasıl ürettiğini
ve yukarıdaki tek parçacığın onu nasıl gerçeklediğini göstermektir.

**İddianın sınırını** ise Bölüm 1.5 üç engel olarak saymıştı. Birincisi, genliğin
küçüklüğü bir büyüklük sorunudur, ve Bölüm 4.1.6 bunun seçilmiş bir çalışma
noktası olduğunu göstermektedir. İkincisi, işaretin seçilebilirliği açık bir soru
olarak durur (Bölüm 9.4). Üçüncüsü, geçirgen okuma ile yüzey tabakası bir arada
duramaz; bu da literatürün güçlü ile zayıf ayrımından gelir, modele özgü bir
boşluk değildir (Bölüm 5.7.1). Yedi adımın kendisi bu boşluklardan bağımsız
olarak doğrudur, ve eksik olan tek şey adımları bir deneye bağlayan son adımdır.

> Bu çalışmanın söylediği şudur: böyle bir geçiş kurulabilirse, dönüş anının
> nereye düştüğü serbest bir yorum değil, hesaplanmış bir sayıdır.

---

# Kısım VII. Yöntem ve deney

Bu kısım çalışmanın nasıl doğrulandığını ve hangi düzenekle sınanabileceğini
yazar.

Kısım iki bölümden oluşur. Birincisi yöntemi kurmaktadır: her sayısal ve cebirsel
iddia bir doğrulamaya karşılık gelir, makale ile kod birbirine isimle değil çalışma
zamanında bağlanır, ve doğrulama kendini de denetler. İkincisi ise neyin
gösterilmediğini yazar, ve çekirdek ölçümün düzeneğini şart şart belirtir.

## 20. Yöntem ve doğrulama

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

### 20.1 Üç denetim

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

### 20.2 Hüküm sözlüğü ve sicil

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
| 5.8 | Enine dalga sayısının yönler arasında eşit paylaşılması | ilan edilmiş sınırlama | Sonucu yazılı: açık hücre mod içeriğine bağlıdır ve mod filtresi bölümünde hesaplanır |
| 5.8 | Dejenere katmanın içerideki her modu tam olarak bloklaması | ilan edilmiş sınırlama | Katmanın bir modeli olarak konur, tam hesabın sıfır vermeyebileceği yazılıdır |
| 5.8 | Madde katmanının gücünün imza dönüşünün eğimini izlemesi | ilan edilmiş sınırlama | Dolaylı bir ölçü olarak konur, tam gerilim tensörünün hesaplanmadığı yazılıdır |
| 6.1 | Yansıyan bir bileşenin bulunabilmesi | türetildi | Aynı bölüm: akı korunumu başka çözüm bırakmaz |
| 19 | Dökümün yedi adımdan sapmaması, yani dönüş olayının kapalı formülden okunması | türetildi | Aynı bölüm: dört koordinatın hepsi Bölüm 18.7'nin formülünden gelir ve döküm onları yeniden hesaplamaz |
| 9.4 | Global hiperbolikliğin sağlanması | başka kurguya ait | Karşılaştırılan formülasyonun ihtiyacıdır; bu çalışmanın sonucu yalnızca zaman yönlerinin sayısından çıkar |
| 16.4 | Dönmenin bir okumada özdeşlik, ötekinde düzgün olması | geçersiz kılındı | Dönmeyi nicelendirerek iki uca da ihtiyaç bırakmayan bölüm |
| 16.4 | Geçişin kayıpsız olması, ki bir satırı sıfırlayan budur | ilan edilmiş sınırlama | Sonucu yazılı: madde katmanı o sıfırı kaldırır |
| 16.5 | Yok; pasaj önceki bölümün iki varsayımını kaldırmak için anar | varsayım değil, söz ediliyor | Onları kaldıran bölümün kendisi |
| 20.1 | Yok; pasaj üç denetimin ne aradığını anlatır | varsayım değil, söz ediliyor | Denetimlerin kendisi, ki bu bölüm onları belgeler |
| 20.2 | Yok; pasaj bu sicili ve taradığı kelimeleri anlatır | varsayım değil, söz ediliyor | Sicilin kendisi, ki bu bölüm onu belgeler |
| 21.2 | Bölge II'nin sınırsız olması | ilan edilmiş sınırlama | Sonucu yazılı: sonlu kalınlıkta dilim üstel olarak bastırılmış ama sıfır olmayan bir genlik bırakır |
| 9.3 | Denklem düzeyinde ve durum düzeyinde tek yönlülüğün aynı iddia olması | başka kurguya ait | İki okuma o bölümde ayrılır ve yalnızca ikincisi savunulur |
| 4.1.6 | Sabit tutulan derinlikte gecikmenin doymuş olması | türetildi | Aynı bölüm: dört enerjinin dördünde de sonlu kalınlık gecikmesi doymuş değerin yüzde biri içindedir |
| 4.1.6 | Minimize edilen niceliğin Bölüm 4.1.3'ün karşılaştırdığı nicelik olması | türetildi | Aynı bölüm: referans yapılanma $2{,}565988$ verir, yani o bölümün sayısının aynısı |
| 21.2.5 | Üretilen bir bölgenin ömrünün ışık geçiş süresi kadar olması | ilan edilmiş sınırlama | Sonucu yazılı: borç ömrün 0,82'sini alır, şart sağlanır ama payı yoktur |
| 21.2.6 | Bir çarpışmanın ulaştığı yoğunluğun durgun küre tanımıyla okunması | ilan edilmiş sınırlama | Sonucu yazılı: üç hacim tanımı 3,7 mertebe yayılır ve en cömerti bile eşiğin çok altında kalır |
| 21.2.6 | Yer çekiminin güçlendiği ölçeğin dört boyutlu Planck ölçeğinin yerini alması | ilan edilmiş sınırlama | Sonucu yazılı: ölçekleme bu varsayıma dayanır ve gerekçelendirilmediği aynı bölümde belirtilir |
| 18.9 | Eksik kütle yönteminin kütle kabuğunda gerçek bir momentum varsayması | iki yönlü hesaplandı | Aynı bölüm: iç mod $\sqrt{13}$ altında söner, üstünde yayılır; iki rejim birbirinin tümleyenidir ve hiçbir frekans ikisini birden vermez |

Sicil $20$ kalem taşır, tarama ise $14$ bölümde iddia bulmaktadır. Sicilin
taramadan geniş olmasının nedeni şudur: sonradan olumsuzlanan bir ifade taramaya
takılmaz, ama hükmü kayıtta kalır.

Bu çalışmanın **kendi** taşıdığı varsayım sekiz satırdır, sekizi de "ilan edilmiş
sınırlama" hükmündedir ve sekizinin de sonucu çalışmada yazılıdır. Geri kalan
kalemler beş türden birine girer: türetilmiş olanlar, iki yönü de hesaplananlar,
sonradan kaldırılanlar, karşılaştırılan bir formülasyona ait olanlar ve hiç
varsayım yapmayan pasajlar.

Bir bozma denetimin kendisini de sınar: makaleye sicilde yeri olmayan bir varsayım
cümlesi eklendiğinde koşu iki kontrolle birden düşmüş, cümle geri alındığında
tekrar geçmiştir.

---

## 21. Açık kalanlar

Bu bölüm yedi adımın neresinin eksik olduğunu sayar ve eksikleri türlerine göre
ayırır: hangisi bir sayı, hangisi bir seçim, hangisi öncülün kendisi. Son alt
bölüm adımları formülden değil sayısal deneyden okur.

### 21.1 Hesap ile deney arası

Açık maddeleri tek bir liste hâlinde saymak yanıltıcı olur, çünkü hepsi aynı
türden değildir. Belirleyici ayrım şudur: **daha iyi bir düzeneğin
kaldırabildiği** engel ile **hiçbir düzeneğin kaldıramadığı** engel. Küçük bir
genlik birincisine girer; o bir hızdır, ve hızlar denemeyle satın alınabilir.
Modelde karşılığı olmayan bir seçim ise ikincisine girer, ve ona mühendislik
sorunu demek dürüst olmaz.

Bu ölçüte göre dört engel ve üç tür çıkmaktadır:

| Engel | Türü | Neyle kapanır |
| ------------------------------------------ | ------ | -------------------------------------------------------------- |
| Parçacığın döndüğü ağırlık | Hız | Yalnızca deneme sayısı |
| Dönen parçacığı yaratılmış çiftten ayırmak | Hız | Kalorimetre, iki durgun enerji çözünürlükte, çakışmada okunmuş |
| Sekiz geçişten hangisinin gerçeklendiği | Seçim | Tam olarak bir eksende tek olan bir nicelik |
| Böyle bir bölgenin yapılabilmesi | Varlık | Bu çalışmanın dışında; koşullu ifade buraya dayanır |

**Hızların fiyatı.** Bölüm 19'un yürüttüğü gidiş dönüşün ağırlığında tek bir olay
için $5{,}5 \times 10^{40}$ deneme gerekmektedir. Enerji yükseltmek bu sayıyı
**değiştirmez**: doyum derinliği sabit tutulduğunda gidiş dönüşün ağırlığı,
toplam enerji dokuzdan elli bine çıkarken $3{,}397579 \times 10^{-10}$ değerinde
kalır. Bu bir tahmin değil, hesaplanmış bir sonuçtur.

**Enerjinin satın aldığı şey mesafedir.** Aynı enerji aralığında Bölge II'de kat
edilmesi gereken mesafe $2{,}4343$'ten $0{,}0980$'a inmektedir. Yani iki talep
birbiriyle takas edilemez: enerji yükseltmek yolculuğu kısaltırken ağırlıktan
hiçbir şey götürmez.

**Hiçbir hızın dokunamadığı engel.** Hangi geçişin gerçeklendiğini ne enerji ne
de deneme sayısı belirler. Söz konusu olan, görülemeyecek kadar küçük bir nicelik
değildir; metriğin yapmadığı bir seçimdir. İki aile bu çalışmada hesaplanan
**hiçbir** nicelikte ayrışmamaktadır, dolayısıyla daha iyi bir düzenek de aynı
sayıları ölçer.

**Koşullu ifadenin dayandığı yer** tablonun dördüncü satırıdır. Bu çalışmanın
hiçbir sonucu, imzası değişmiş bir bölgenin yapılıp yapılamayacağı hakkında bir
şey vermez. Sonucun bir öneri olarak değil bir koşullu ifade olarak
yazılmasının nedeni de budur.

> Dürüst özet şudur: iki engel **sayıdır**, biri **seçimdir**, biri de **öncülün
> kendisidir**.

### 21.2 Kapanan ve açık maddeler

| Konu | Durum |
| ------------------------- | ------------------------------------------------------------------------ |
| Üç zamanda zamanın oku | Kapandı (Bölüm 9.4), ok zaman yönü sayısından çıkar, bir yön varsa ok vardır |
| Dönüşümdeki $\pm$ işareti | Kapanamaz olduğu gösterildi (Bölüm 16.6) |
| Grup yapısı | Kapandı (Bölüm 4.2), sorun $B$ katmanında |
| Superluminal durgunluk | Kapandı (Bölüm 10.3), ayar fazlalığı |
| Etkileşim / Maxwell | Kapsam dışı bırakıldı |
| Kuantumlama | Kapandı |
| Takyonların varlığı | Açık, deneysel soru |

Modele özgü olduğu düşünülen sonuçlar şunlardır: $D$'nin 384 aday arasından
zorunlu çıkması (Bölüm 4.1); Bölge II'deki yönelimden dönüş olayına giden
dönüşümün kurulup taranmış olması (Bölüm 18).

Eskiden bu listede olan "eşikte tam yansımanın akı korunumunun tek çözümü
olması" maddesi **çıkarılmıştır**; eşik geçirgen okunduğundan beri o iddia
taşınmamaktadır.

**Bölüm 5.1'de kapanan nokta.** O bölüm şu soruyu cevaplamıştır: iki imza
arasındaki sürekli bir yol ne kadar dejenere olmak zorundadır. Her noktada
yalnızca tek bir öz-değerin sıfırlandığı bir yol bulunmaktadır, ve maliyeti $(2,2)$
imzalı iki zamanlı bir ara bölgeden geçmektir. Çalışmanın daha önceki "geçiş
sağlanmaz" sonucu bu nedenle geri çekilmiştir.

**Bölüm 8'de daraltılan nokta.** Eşiğin yansıtıcı olması, Bölge II'nin sınırsız
olduğu varsayımına dayanır. Sonlu kalınlıkta bir dilim ise üstel olarak
bastırılmış, ama sıfır olmayan bir geçirgenlik vermektedir. Buna ek olarak,
engelin ortaya çıkıp çıkmadığını gelen alanın mod içeriği belirler.

**Açık kalanlar.**

| Soru | Nerede |
| ------------------------------------------------------------- | -------------------------------------------------------------------------- |
| Güçlü ile zayıf eklem koşulu arasındaki tercihin gerekçesi | Bölüm 5.7 ve 4.1; oran koşulu hesaplanmış, sonuç zayıf seçimin aleyhinedir |
| Geçirgen okumanın daha geniş bir metrik ailesinde temsilcisi | Kapandı, Bölüm 5.7.1 |
| Geçiş süresinin beş okumasından hangisinin fiziksel olduğu | Dönüş anını yerleştiren okuma için kapandı, Bölüm 11.6; kalan okumaların neyi ölçtüğü açık |
| $(2,2)$ ara bölgesinin fiziksel olarak savunulabilirliği | Açık; Bölüm 5.3 onun madde geçirdiğini hesaplar, var olabilirliğini değil |
| Üç zamanın olasılık korunumu altında tek zamana çökmesi | Bölüm 9.3 |
| İmza değiştiren arka planda parçacık üretimi | Açık; Bölüm 5.3'te anılan frekans karışımı hesabı bu soruya bakar, bu çalışma bakmaz |
| Eşik duvarlarının kuantum kararlılığı | Bölüm 6.1 |
| Geçişin varsayılmak yerine türetilebilmesi | Kapsam dışı bırakıldı |
| Yerçekiminin eklem koşulunun ötesine götürülmesi | Bölüm 6.2 |
| Ayırt edici öngörünün hazırlanabilir bir düzenek gerektirmesi | Kapsam dışı bırakıldı |

### 21.2.1 Laboratuvar mertebeleri

Bu alt bölüm geçiş koşullarının deneysel karşılığını sayılara indirmektedir.
Kütle tavanı $\mu_{\max} = \omega_0^2/c^2 - k_T^2$ biçiminde yazılır, ve
bu koşuldan bir alt sınır doğar: bant merkezi, taşınan kütlenin durgun enerjisinden
kurulan frekansı aşmak zorundadır.

| Nicelik | Değer |
| ------------------------------------------ | ---------------------------------- |
| Proton durgun enerjisi | $938{,}3$ MeV |
| Aşılması gereken bant merkezi | $1{,}4255 \times 10^{24}$ rad/s |
| Karşılık gelen kütle parametresi | $2{,}2609 \times 10^{31}$ m$^{-2}$ |
| Bir voltluk potansiyelin frekans kayması | $1{,}5193 \times 10^{15}$ rad/s |

Tablodan iki sonuç çıkmaktadır. Birincisi, kütle tavanı sonradan kestirilecek bir
ölçek değil yazılı bir laboratuvar şartıdır: bu frekansın altındaki bir bant
protonu hiç taşımaz. İkincisi, potansiyelin sağladığı ayar giriş frekansının
dokuz mertebe altında kalır. Yani dönüş, kaba bir şartın üzerine binen ince bir
ayarla yönlendirilmekte, ve şartın kendisi bu yolla dolanılamamaktadır.

Ölçülmesi gereken nicelikler de aynı tablodan çıkar: bant merkezi ve genişliği,
Bölge II'de kat edilen mesafe, ve dönen genliğin ağırlığı. İlk üçü düzeneğin
ayarlarıdır; dördüncüsü sonucun kendisidir, ve Bölüm 13.8'de gösterildiği üzere
deneyin asıl güçlüğü de bu koşuldadır.

### 21.2.2 Mesafenin süreye çevrimi

Bölge II'de kat edilen uzunluğu Bölge I'de kazanılan süreye çeviren çarpan ışık
hızıdır. Bir metrelik yolculuk $3{,}34$ nanosaniye kazandırır.

| Kazanılan süre | Gereken Bölge II mesafesi |
| ------------------ | ----------------------------------- |
| $1$ ns | $0{,}30$ m |
| $1$ ms | $3{,}00 \times 10^{5}$ m |
| $1$ s | $3{,}00 \times 10^{8}$ m |
| $1$ dakika | $1{,}80 \times 10^{10}$ m |
| $1$ yıl | $9{,}46 \times 10^{15}$ m, bir ışık yılı |

Tabloya bir de geçişin kendi borcu eklenmelidir. Sınanan sürücüde, yani
$1{,}5 \times 10^{24}$ rad/s değerinde, gidiş dönüşün borcu
$5{,}4614 \times 10^{-24}$ s çıkmaktadır, ve bu borcu kapatan Bölge II mesafesi
$1{,}6373 \times 10^{-15}$ m, yani protonun birkaç yarıçapı kadardır. Görüldüğü
gibi borç, ölçülmeye değer herhangi bir ilerlemenin yanında ihmal edilir;
dolayısıyla gereken mesafe pratikte ilerleme ile ışık hızının çarpımına eşittir.

Tablonun son satırı önerinin ölçeğini en açık biçimde göstermektedir: bir yıl
geriye taşınmak, Bölge II'de bir ışık yılı yol almayı gerektirir.

### 21.2.3 Zayıflayan nicelik

Geri dönen parçacığın hiçbir özelliği azalmaz. Kütlesi, yükü ve mod ızgarası
gidişteki değerlerini korur, çünkü geçiş yalnızca mod genliklerini ölçekler ve
mod etiketlerini yerinden oynatmaz.

Zayıflayan tek nicelik **varış olasılığıdır**. İletim katsayısı bir olasılıktır,
parçacığın bir kesri değil. Dolayısıyla geri gelen bir proton eksiksiz bir
protondur, ve küçük olan sayı yalnızca onun gelme şansıdır.

| Opaklık | Varış olasılığı | Bir varış için fırlatma sayısı |
| ------- | -------------------------- | ------------------------------ |
| $5$ | $4{,}54 \times 10^{-5}$ | $2{,}20 \times 10^{4}$ |
| $20$ | $4{,}25 \times 10^{-18}$ | $2{,}35 \times 10^{17}$ |
| $40$ | $1{,}80 \times 10^{-35}$ | $5{,}54 \times 10^{34}$ |

### 21.2.4 Görünürlük ile doyum

Deneyin asıl engeli kütle duvarı değildir, iki şartın birbirine ters çekmesidir.
Varışın milyarda birin üzerinde kalması opaklığı $10{,}36$ ile sınırlamaktadır.
Buna karşılık gecikmenin doyması aynı çarpımın büyük olmasını ister, ve
yolculuğu satın alan nicelik de o gecikmedir.

İki şart birbirini ters yöne çeker. Sonucun görülebileceği kadar ince bir engel,
gecikmenin doyması için yeterince opak kalmaz. Kütle duvarını aşan bir sürücü
bulunsa bile bu gerilim ortadan kalkmaz, ve deneyin asıl güçlüğünü de o
oluşturmaktadır.

### 21.2.5 Yoğunluk koşulu

Bu çalışma Bölge II'yi verilmiş kabul etmekte ve yolculuğu o bölgeden
hesaplamaktadır. Bölgenin hangi koşulda ortaya çıktığını ise literatürün bir kolu
tek bir sayıya bağlamıştır. Döngü kuantum kozmolojisinin etkin dinamiğinde
hiperyüzey deformasyon cebiri yoğunluğa bağlı bir çarpan kazanır, ve bu çarpan
enerji yoğunluğu kritik yoğunluğun yarısını geçtiğinde işaret değiştirir [37].
Aynı kuram yüksek yoğunlukta geometriyi Öklid imzasına döndürmektedir [38].
Eşiğin altında mod denklemi hiperbolik, geometri Lorentz imzalıdır; üstünde
denklem eliptik, geometri Öklid imzalı olur. Aşağıdaki sayılar da o kuramın
kendi sayılarıdır, bu çalışmanın türettikleri değil.

| Nicelik | Değer |
| ------------------ | ----------------------------------------- |
| Planck yoğunluğu | $5{,}15 \times 10^{96}$ kg/m$^3$ |
| Kritik yoğunluk [79] | $2{,}11 \times 10^{96}$ kg/m$^3$ |
| Dönme eşiği | $1{,}06 \times 10^{96}$ kg/m$^3$ |

Maliyet bu hesapta iki parçaya ayrılmaktadır, çünkü ikisi birlikte anıldığında
yanlış okunur. Gereken **enerji büyük değildir**: aynı kuramın kabul ettiği en
küçük hacmi eşiğe getirmek $4{,}01 \times 10^{8}$ J ister, yani yaklaşık yüz
kilogram kimyasal patlayıcının açığa çıkardığı enerji kadardır. Asıl engel
**o enerjiyi o kadar küçük bir hacme sıkıştırmaktır**. Çekirdek maddesi eşikten
$78{,}7$, nötron yıldızı çekirdeği $78{,}0$, en yüksek enerjili çarpışma bir
proton yarıçapı içinde $74{,}1$ mertebe geridedir.

Koşul bir yoğunluk olduğundan yoğunlaştırmayla sağlanır, süreyle değil. Şartı
zamana yayarak biriktirme yolu bu nedenle kapalı kalır.

**Bölge yapılırsa dokuzuncu bir şart doğar.** Bölüm 13.7'nin sekiz şartı öte
bölgeyi **verilmiş** kabul eder ve bu meşrudur: geçiş hesabının hiçbir adımı
bölgenin nasıl üretildiğine bakmaz. Bir üretim yolu adlandırıldığı anda durum
değişir, çünkü üretilen bir bölge kalıcı değildir. Bir proton büyüklüğündeki
bölgenin ömrü, ışığın onu geçme süresi kadardır:
$5{,}6132 \times 10^{-24}$ s. Gidiş dönüşün borcu ise
$4{,}6155 \times 10^{-24}$ s, yani o ömrün $0{,}82$'si.

İki süre aynı mertebede kalmaktadır. Dolayısıyla şart bugün sağlanır, ama hiç
payı yoktur: bölgeyi biraz küçülten ya da borcu biraz büyüten her seçim onu
çiğner. Bu çalışma bir üretim yolu önermediğinden şartı sekizin arasına yazmaz,
ancak üretimi konuşan her öneriye onu iliştirmek gerekmektedir.

### 21.2.6 Eşiğin dayandığı iki çarpan

Yukarıdaki kritik yoğunluk evrensel bir sabit değildir, iki çarpandan
kurulmaktadır:

$$\rho_c = \frac{\sqrt{3}}{32\pi^2\gamma^3}\, M_*^4$$

Birinci çarpan serbest değildir. Kuantizasyon parametresi $\gamma$, [78]'in
entropi
sayımından gelmekte ve $0{,}2375$ değerini almaktadır; bu değerden türetilen kesir de
$0{,}4094$ çıkar. Bu çarpanı ayarlanabilir saymak, aranan sonucu baştan kabul
etmek anlamına gelir.

İkinci çarpanı ise ölçülmüş bir nicelik sabitlememektedir. [39] ile [82]'nin
kurduğu senaryoda ek sıkışmış boyutlar
bulunuyorsa yer çekiminin güçlendiği ölçek dört boyutlu değerin çok altına
inmekte [39], ve eşik o ölçeğin **dördüncü kuvvetiyle** düşmektedir. Bu
ölçekleme, söz konusu ölçeğin dört boyutlu Planck ölçeğinin yerini aldığı
varsayımına dayanır ve bu çalışmada gerekçelendirilmemiştir. Kaldıraç ise büyüktür:
ölçeğin on altı mertebe düşmesi eşiği altmış dört mertebe aşağı çeker.

| Yer çekiminin güçlendiği ölçek | Dönme eşiği | Kazanç |
| ------------------------------ | --------------------------------- | ------------- |
| $10^{19}$ GeV | $4{,}75 \times 10^{95}$ kg/m$^3$ | yok |
| $10^{6}$ GeV | $4{,}75 \times 10^{43}$ kg/m$^3$ | $52{,}3$ mertebe |
| $10^{4}$ GeV | $4{,}75 \times 10^{35}$ kg/m$^3$ | $60{,}3$ mertebe |
| $10^{3}$ GeV | $4{,}75 \times 10^{31}$ kg/m$^3$ | $64{,}3$ mertebe |

Bugün kasıtlı olarak kurulabilen en yoğun yapılanma, hacmi [80]'in ölçütüyle
alındığında
$9{,}28 \times 10^{21}$ kg/m$^3$ değerine ulaşmaktadır. Eşiğin oraya inmesi ise
yer çekiminin $3{,}74$ GeV ölçeğinde güçlenmesini gerektirirdi. Dışlanan ölçek
tek bir sayı değildir, ek boyut sayısına bağlıdır: [40] onu iki boyut için
$9{,}9$ TeV, altı boyut için $5{,}3$ TeV olarak vermektedir. En elverişli sınır
alındığında bile kapatan ölçek $3{,}2$ mertebe dışlanmış kalır, ve koşul
$13{,}5$ mertebe uzakta durur.

Bu hesabın kazandırdığı şey şudur: ortada çıplak bir imkânsızlık değil, tek bir
parametre üzerinde ölçülmüş bir mesafe bulunmaktadır. O mesafeyi de çarpışmanın
enerjisi değil, ek boyutların varlığı kapatır.

**Ulaşılan yoğunluk, seçilen hacim tanımına bağlıdır.** Yukarıdaki
$9{,}28 \times 10^{21}$ sayısı, çarpışma enerjisini durgun bir proton küresine
koyar. Bir çarpışma hazır bir hacimle gelmez ve üç ayrı hacim tanımı üç ayrı
cevap verir: durgun küre
$9{,}28 \times 10^{21}$, Lorentz büzülmüş geometrik örtüşme
$4{,}28 \times 10^{25}$, bir femtometrelik oluşum dilimi
$1{,}04 \times 10^{22}$ kg/m$^3$. Aradaki yayılım $3{,}7$ mertebedir ve ölçüm
değil tanım farkıdır: büzülmüş örtüşme henüz maddeye dönüşmemiş enerjiyi
sayar, durgun küre ise düzleşmeyi hiç saymaz.

Bu yayılım yukarıdaki hükmü değiştirmez, çünkü en cömert tanım bile eşiğin çok
altında kalmaktadır. Değiştirdiği tek şey, mesafenin üç anlamlı basamakla
yazılamaz olmasıdır. Çalışma durgun küre tanımını kullanmakta, ve seçimini bu bölümde
kayda geçirmektedir.

### 21.2.7 Çekirdek ölçümün düzeneği

Deneyin ölçtüğü nicelik tektir. Bir proton fırlatılır, eşiği geçer, Bölge II'de
tek uzay ekseni boyunca yer değiştirir, geri geçer, ve **aynı saat üzerinde**
fırlatılışından önceki bir anda kaydedilir. Okunan şey yalnızca iki olay
arasındaki zaman farkıdır, ve iddiayı bir çıkarım olmaktan çıkarıp bir ölçüme
çeviren de budur.

Şartlardan biri göründüğü kadar ağır değildir. Protonun bant merkezi, kendi
toplam enerjisinin indirgenmiş Planck sabitine bölümüne eşittir, ve durgun bir
proton zaten durgun enerjisinden kurulan frekansta bulunur. Yani o frekansı hiçbir
kaynağın sağlaması gerekmez, protonun kendisi taşır.

**Enerji yine de gerekir, ama bant için değil.** Varışın hangi fırlatmaya ait
olduğunu bir etiket söylemektedir, ve etiket protonun ince bir folyodan
geçmesini gerektirir; folyo da protonu saçar. [81]'in çoklu Coulomb saçılması
yaklaşımına göre bir megaelektronvoltluk bir proton,
santimetre karesi başına on mikrogramlık karbondan $1{,}38 \times 10^{-3}$ radyan
genişleyerek çıkar, yani demet hattının ulaştığı kolimasyonu bozar. Aynı folyo
iki yüz otuz megaelektronvoltta protonu yalnızca $6{,}66 \times 10^{-6}$ radyan
genişletmektedir, ve böylece etiket ile kolimasyon bir arada durabilir.
Dolayısıyla enerjinin satın aldığı şey bant değil, **saçılma bütçesidir**; o
enerjide bant merkezi de $1{,}7749 \times 10^{24}$ rad/s değerine çıkar.

**Fırlatma hızı da bedava değildir.** Tek bir varış için
$4{,}85 \times 10^{8}$ fırlatma gerekmektedir, ancak bunu saniyede yapmak
fırlatmalar arasına yalnızca $2{,}06$ nanosaniye koyar. Aranan işaret bir
nanosaniyelik bir geri kayma olduğuna göre, o kadar erken bir varış ile bir
önceki protonun geç varışı birbirinden ayırt edilemez. Bu yüzden hız saniyede on
milyona indirilir; aralık yüz nanosaniyeye çıkar, ve koşu $48{,}5$ saniye sürer.

| Şart | İstenen | Bu düzenekte |
| ------------------------------- | ---------------------------------- | ---------------------------------- |
| Demetin durgunluk frekansını aşması | $1{,}4255 \times 10^{24}$ rad/s | $1{,}7749 \times 10^{24}$ rad/s |
| Enine momentumun toplama oranı | $10^{-1}$ | $5 \times 10^{-5}$ |
| Bölge II'nin yoğunluğu | $1{,}06 \times 10^{96}$ kg/m$^3$ | $9{,}28 \times 10^{21}$ kg/m$^3$ |
| Geçişin opaklığı | $10$ | $10$ |
| Bölge II'deki yer değiştirme | $0{,}2998$ m | $1$ m, düzeneğin varsayımı |
| Zamanlama çözünürlüğü | $2 \times 10^{-11}$ s | $1{,}8 \times 10^{-11}$ s |
| Saniyedeki fırlatma sayısı | $4{,}85 \times 10^{8}$ | $10^{7}$ |
| Varışın fırlatmaya bağlanması | bir etiket | bir etiket |

Bugünkü bir laboratuvar bu sekiz şarttan yedisini karşılamaktadır. Sağ sütunun
yedi satırı bugünkü donanımın ölçülü yeteneğini verir. Sekizinci satır, yani
Bölge II'de kat edilen $1$ m, bir ölçüm değil bir gerekliliktir: düzenek ancak o
uzunlukta çalışır, ve o uzunluğa da yalnızca yoğunluk şartı altında erişir.
Tablonun sağ sütununu şartlar tek tek değil birlikte belirler: yukarıdaki iki çekişme, enerjiyi yükseltip hızı düşüren
tek bir çalışma noktasında birlikte çözülür.
Okumayı mümkün kılan sayı da şudur: aranan ilerleme $10^{-9}$ s, zamanlama
çözünürlüğü $1{,}8 \times 10^{-11}$ s, yani arada elli beş çözünürlük genişliği
bulunur. Ölçüm sınırda durmaz, ve deneyin tamamı $48{,}5$ saniye sürer.

Düzeneğin parçaları da olağandır ve hepsi raftan alınabilir:

- tedavi sınıfı bir proton siklotronu, iki yüz otuz megaelektronvolt;
- iki delikli bir sürüklenme kolimasyonu, açıyı istenen bandın altına indiren ve
  bedelini akımdan ödeyen;
- iki katmanlı ince bir sürüklenme algılayıcısı, fırlatmayı on iki pikosaniye
  içinde etiketleyen;
- tek bir zaman çevirici yonga ve tek bir osilatör, iki damgayı birlikte okuyan.

Son madde isteğe bağlı değildir. İki damga ayrı saatlerden okunursa, bir
nanosaniyelik bir saat farkı aranan işaretin tamamını taklit edebilir.

Geriye sağlanmayan tek şart kalmaktadır: Bölge II'nin yoğunluğu. Düzeneğin geri
kalanı bir proton demeti, bir kolimatör, hızlı bir zamanlama algılayıcısı ve bir
tetikleyiciden ibarettir. Dolayısıyla deney tarif edilmiştir ama
gerçekleştirilebilir değildir, ve ikisinin arasında duran şey uzun bir liste
değil, tek bir şart üzerindeki tek bir sayıdır.

### 21.2.8 Bağlı bir durum, hidrojen atomu

Bu çalışmanın bütün geçiş hesabı taşınan nesneyi tek bir kütleyle temsil eder,
ve o kütle hesaba yalnızca bir yerde girer: Bölüm 11.7'nin tavanı. Tavanın
ötesinde nesnenin ne olduğu bir daha okunmaz. Bu bölüm o tek girişi bir proton
yerine bir hidrojen atomuyla, yani bir elektronla bağlı bir protonla,
sınamıştır.

Hidrojen atomunun durgun kütlesini proton ile elektronun kütleleri
toplamından bağlanma enerjisinin kütle karşılığını çıkarmak verir:
$1{,}672622 \times 10^{-27}$ kg artı $9{,}109384 \times 10^{-31}$ kg eksi
$2{,}424141 \times 10^{-35}$ kg. Elektronun payı protona göre bağıl
$5{,}4462 \times 10^{-4}$, bağlanma enerjisininki ise $1{,}4493 \times
10^{-8}$'dir, yani dört basamak daha küçüktür. Atomun ağırlığını neredeyse
tamamen elektron taşır, bağlanma enerjisinin kendisi bu çalışmanın kullandığı
basamak sayısında hiç iz bırakmaz.

Aynı ölçütle protonun ve atomun tavanı karşılaştırılabilir. Protonun bant
tavanı $1{,}4255 \times 10^{24}$ rad/s'dir, Bölüm 21.2.1'in verdiği sayı;
atomun tavanı $1{,}4263 \times 10^{24}$ rad/s'e çıkar, artış elektronun
payına eşit mertebede kalır. Bölüm 21.2.2 ile 21.2.7'nin sınadığı sürücü,
$1{,}5 \times 10^{24}$ rad/s, ikisini de aşar.

Tavan aşıldıktan sonra geçişin geri kalanı sürücüye ve mesafeye bakar, taşınan
nesneye bakmaz: Bölüm 21.2.1'in kullandığı hesap kütleyi hiç girdi olarak
almaz. Bu yüzden aynı sürücüyle, aynı mesafeyle kurulan gidiş dönüş, hidrojen
atomu için de protonunkiyle **aynı** sayıları verir: borç $5{,}4614 \times
10^{-24}$ s, varış fırlatıştan $1{,}0007$ nanosaniye önce. Tavanı aşan her
nesne bu hesapta aynı yolculuğu yapar, çünkü hesap tavanın ötesinde nesnenin
ne olduğunu bir daha sormaz.

**Bu eşitliğin gösterdiği şey dardır.** Model taşınan nesneyi tavanın
ötesinde tek bir kütle olarak taşır, ve elektronla protonun bağıl konumunu
hiçbir yerde temsil etmez. Dolayısıyla dönen atomun elektronu hâlâ taşıyıp
taşımadığı, yani aynı moleküler bağla dönüp dönmediği, bu hesabın konusu
değildir; hesap o soruyu hiç sormaz.

Bölge II'de sorunun bir katmanı daha vardır. Bölüm 11.5 orada "konum"
kavramının tek uzay ekseni $r$'ye daraldığını, üç zaman yönü boyunca hiçbir
karşılığı kalmadığını yazar; Bölüm 18.9 de aynı daralmayı teyit etmiştir. Üç
boyutlu bir elektron bulutunun bu tek eksende neye karşılık geldiği bu
çalışmanın sormadığı bir sorudur, çünkü bağıl koordinatın üç zaman bir uzay
imzasındaki dinamiği literatürde de kurulmuş değildir. Bu çalışma o dinamiği
icat etmemiştir; soru açık kalmıştır.

### 21.2.9 Bağın kinematik sınaması

Literatür bu soruyu daha önce kurmamıştır. Dixon'ın genişletilmiş cisim
dinamiği [83] sıradan görelilikte vardır, ama imza değişimiyle hiç
birleştirilmemiştir. Çok zamanlı fizik yazını [66] bir bağlı durumun iç
yapısını hesaplamaz. Tegmark [84] ile Craig ve Weinstein [85], birden fazla
zaman ekseninin kararlı bir yapıyı desteklemediğini tartışır, ama bir bağlı
durumun tayfını çıkarmaz. Sıradan uzay-zamanda bile boyut düşürmek hidrojen
atomunu bozar: Loudon'ın tek boyutlu hidrojen atomu [86] sınırsız derin bir
taban durumu ve uyarılmış durumlarda yozlaşma verir. Hazır bir kuram yoktur,
bu yüzden bu bölüm kendi dar sınamasını kurar.

Bu bölüm kendi tanımını kurar. Aynı sürücüyü, aynı yönelim açılarını ve aynı
dalı paylaşan, yalnızca kütlesi farklı iki durumu Bölüm 18'in yönelim-dönüş
eşlemesinden geçirir, ve eşlemenin ikisine verdiği sonucu karşılaştırır. Aynı
dönüş olayını verdikleri durumu bağlı, farklı sonuç verdikleri durumu ayrık
adlandırır, ve farkın büyüklüğünü hesaplar.

Sürücü $\omega = 2{,}8$'dir, aynı yönelim açıları ve aynı dal her iki kütleye
de uygulanır. Kütle kabuğu her kütleye kendi enerji vektörü uzunluğunu verir:
protonun $\mu = 1$'i uzunluk $2{,}615339$'a, elektronun $\mu = 5{,}446170
\times 10^{-4}$'ü uzunluk $2{,}799903$'e karşılık gelir. Proton dönüş anını
$t = 2{,}860608$'de, elektron $t = 2{,}495908$'de bulur; fark $-0{,}364700$
birimdir. Enine varış noktaları da farklıdır: proton $(+0{,}011745,
+0{,}008657)$, elektron $(+0{,}042547, +0{,}031359)$, fark
$(+0{,}030802, +0{,}022703)$ birim. Makalenin geri kalanının kullandığı
sürücüde bu fark $6{,}8077 \times 10^{-25}$ s ve $1{,}7237 \times 10^{-17}$ m
ile $1{,}2705 \times 10^{-17}$ m'ye karşılık gelir.

**Sonuç.** Aynı yönelimle ve aynı dalla fırlatılan, yalnızca kütlesi farklı
iki durum, bu eşlemede **aynı** dönüş olayına gitmez. Ağır ve hafif kütle
farklı anda döner, farklı enine noktaya varır. Bağ, bu sınamanın tanımladığı
anlamda, çift dönüşte ayakta kalmaz.

**Bunun gösterdiği ve göstermediği.** Bu bir kinematik sınamadır, çözülmüş bir
iki cisim yörüngesi değildir. Protonla elektronu bir arada tutan kuvveti
hiçbir yerde temsil etmez, Bölge II'nin tek uzay ekseninde bir bağıl
koordinatın ne anlama geleceğini de kurmaz; ikisini literatür de
kurmamıştır (yukarıdaki tarama). Bu sınamanın verdiği şey dardır: bu
projenin kendi tek-parçacık eşlemesi, kütle farkına karşı katı değildir.

Bu tanımı üç ya da daha çok kütleye, gerçek bir 3D moleküle taşımanın
gerekçeli bir yolu yoktur. Her kütleye kendi molekül içi konumuna göre ayrı
bir yönelim vermek, konumu yönelime çeviren bir kural ister. Böyle bir kural
ne bu projede ne literatürde vardır: Bölüm 3'ün eksen karşılığı tek bir
parçacığın kendi hızını taşır, bir yapı içindeki konumu değil. Katı bir
öteleme tek yönelimi bütün kütlelere paylaştırır. O durumda aynı kütleli her
atom zaten aynı olaya gider, yalnızca farklı kütle ayrı kalır. Bu da
yukarıdaki proton-elektron bulgusunun bir tekrarından başka bir şey vermez.

### 21.3 Simülasyondan okuma

Bu çalışmadaki her gecikme **tek bir yoldan** gelmektedir: fazın frekansa göre
türevinden. Yol doğrudur, ancak tek bir yol kendini denetleyemez. Bu alt bölüm
ikinci bir yol kurmaktadır.

**Yöntem.** Bir dalga paketi frekanslar üzerinden toplanmaktadır. Her frekans,
iki geçişin o frekansa uyguladığı genlikle ve gözlem noktasına kadarki serbest
yayılım fazıyla çarpılır. Hesap sonucu zamanda ileri yürütmekte, ve zarfın **tepe
yaptığı anı** varış saymaktadır.

Bu hesap hiçbir gecikme formülü kullanmaz. Durağan faz koşulunu da dayatmaz,
ortaya çıkmasını ya da çıkmamasını serbest bırakır.

**Bandın kesilmesi zorunludur.** Frekans $\sqrt{k_T^2 + \mu}$ değerinin, bu
yapılanmada $2{,}2361$'in altına düştüğünde dışarıdaki dalga sayısı sanal olur ve
o bileşen dedektöre **hiç ulaşmaz**. Bu yüzden bant o frekansta kesilmektedir; kesilmezse
toplam anlamsız bir katkı taşır.

**Birinci sonuç: gecikme doğrulanmaktadır.**

| Kalınlık | Simülasyonun ölçtüğü | Kapalı biçim |
| -------- | -------------------- | ------------ |
| $4$ | $+1{,}4635$ | $+1{,}4629$ |
| $8$ | $+1{,}4635$ | $+1{,}4629$ |
| $16$ | $+1{,}4635$ | $+1{,}4629$ |

Kalan fark paketin sonlu genişliğinden gelmekte, ve bant daraldıkça
küçülmektedir. Frekans toplamı dört kat inceltildiğinde sayı hiç kıpırdamaz, yani
bildirilen değer kesmenin bir yan ürünü değildir.

> Doyum, kendisine hiç söylenmemiş bir yol tarafından **gözlenmektedir**.
> Kalınlık dörtten on altıya çıkarken gecikme değişmemektedir. Dolayısıyla
> kapalı biçim, bir fazı türetmenin yan ürünü değildir.

**İkinci sonuç: faz yolunun görmediği bir şey vardır.** Yukarıdaki ölçüm,
genliğin yalnızca **fazını** almaktadır. Genliğin tamamı hesaba girdiğinde
tepe fazladan kaymaktadır:

| Kalınlık | Genliğin tepeye eklediği kayma |
| -------- | ------------------------------ |
| $4$ | $-0{,}0902$ |
| $8$ | $-0{,}1726$ |
| $16$ | $-0{,}3369$ |

Bunun sebebi şudur: opak rejimde geçirgenliğin **modülü** frekansla dik biçimde
yükselmektedir. Yani bölge paketi yalnızca geciktirmez, onu **hızlı yanına doğru
yeniden ağırlıklandırır**. Bu kayma kalınlıkla büyürken, gecikme büyümez.

Ortaya çıkan etki gerçektir ve bir hesap hatası değildir; ancak bir **gecikme de
değildir**. Paket varır, ama farklı bir paket olarak varır. İkisinin toplamını
tek bir sayı olarak bildirmek birini ötekinin hanesine yazmak olurdu, ve tablo bu
nedenle ikisini ayrı tutmaktadır.

**Simülasyonun üç kez düzelttiği yer.** Grup hızı ilk yazımda ters çevrilmişti,
ve arama penceresi tepeyi hiç içermiyordu. İkinci hatada bant, dışarıdaki dalga
sayısının sanal olduğu bölgeye kadar uzanıyordu. Üçüncüsünde ise ilk seçilen
paket genişliğinde yeniden ağırlıklandırma gecikmeye baskın geliyordu, ve
kalınlıkla **büyüyen bir öne kayma** neredeyse gecikme diye kaydedilecekti. Üçünü
de simülasyonun kendisi yakalamıştır, ki bir simülasyonun varlık nedeni de
budur.

---

## 22. İtirazlar ve yanıtlar

Bu bölüm çekirdek zincire yöneltilebilecek itirazları tek yerde toplamaktadır.
Zincir beş halkadan oluşur: **geçiş**, **çevrim**, **doyum**, **işaret** ve
**ölçülebilirlik**. Aşağıdaki her madde bu halkalardan birini hedef alır, ve
her maddenin sonunda bu çalışmanın verebildiği yanıt durur. Yanıt veremediği
maddeler de aynı biçimde yazılmıştır.

### 22.1 İmza değişimi bir işaret uzlaşımı olabilir

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

### 22.2 İmza değişimi sınırsız parçacık üretebilir

**İtiraz.** İmza değiştiren bir arka planda tanımlı bir kuantum alanı, geçiş
sırasında sınırsız sayıda parçacık ve sınırsız toplam enerji üretebilir. O
zaman geçişin bedeli küçük bir olasılık değil, eşiği ayakta bırakmayan bir geri
tepkidir.

**Vurduğu halka.** Geçiş.

**Yanıt.** Bu çalışmada böyle bir hesap **yoktur**. Bölüm 5.3'ün andığı frekans
karışımı hesabı ([20], [21]) tam olarak bu soruya bakan çerçevedir, ve o
çerçevede karışım yalnızca Öklidyen bölgenin toplam konformal genişliğine bağlı
çıkmaktadır. Bu çalışmanın verdiği geçirgenlik sayıları tek parçacık
saçılmasına aittir, ve geri tepkiyi içermez. İtiraz **karşılanmamıştır**.

### 22.3 Doyan gecikme bir kat etme süresi olmayabilir

**İtiraz.** Doymuş grup gecikmesi, engelde depolanan alanın boşalma süresidir,
ve alan iki uçtan birden boşalır. Bir ömür süresi ise bir hızla
ilişkilendirilemez, bir yayılma terimiyle de toplanamaz. O zaman $2\tau - s$
ifadesi iki farklı türden süreyi çıkarmaktadır, ve sıfırlandığı nokta fiziksel
bir olay işaretlemez. İtirazı [30] kurmaktadır.

**Vurduğu halka.** Doyum ve çevrim.

**Yanıt.** Bu çalışma toplamı elle kurmamış, tek bir genliğin durağan faz
koşulundan türetmiştir (Bölüm 4.1.2), ve türetimi bağımsız bir yolla üç ayrı
mesafede sınamıştır. Türetim itirazın hedefi olan **yorumu** ise
kurtarmamaktadır: durağan faz koşulu çıkan paketin tepesinin hangi anda
göründüğünü verir, o tepenin bir kat etme süresi taşıdığını vermez. Ayrımı
Bölüm 1.5 dördüncü engel olarak kaydetmektedir. İtiraz **kısmen
karşılanmıştır**: toplamın cebri sağlamdır, süre yorumu değildir.

### 22.4 Erken varan cismin sinyal sayılması

**İtiraz.** Bu çalışma nedensellik itirazını, bir sinyal iddiası taşımadığını
söyleyerek karşılamaktadır (Bölüm 18.6). Oysa çekirdek iddia bir dalga
tepesinin değil, kütleli bir parçacığın kalkıştan önce geri dönmesidir.
Kimliğini taşıyan bir cismin erken varması ise tanımı gereği bir sinyaldir, ve
[50] ile [36]'nın saydığı nedensel maliyeti doğurur.

**Vurduğu halka.** İşaret.

**Yanıt.** İtiraz bir ikilem kurmaktadır, ve ikilem gerçektir. Cisim okuması
alınırsa nedensel çelişki doğar. Faz okuması alınırsa geriye çıkan paketin
tepesinin öne düşmesi kalır, o da bilinen bir olgudur. Bu çalışma iki okumayı
birlikte yürütmekte (Bölüm 11) ve dönüş anını faz okumasından almaktadır (Bölüm
13). İki okumanın hangi koşulda birbirine çevrildiğini Bölüm 11.3 ile 11.4
vermektedir: paket yeterince dar tutulduğunda çevrim tam işler, ancak dar paket
kendi kaybını getirir. Dolayısıyla ikilem **kapatılmamıştır**. Kaydedilen şey
şudur: faz okumasıyla hesaplanan dönüş anı bir sinyal iddiası taşımaz, ve cisim
okumasına geçmek için gereken dar paket sınırı Bölüm 11.4'te sayılıdır.

### 22.5 Çok zamanlı bölgede başlangıç verisinin serbestliği

**İtiraz.** Birden çok zaman ekseni taşıyan bir bölgede başlangıç değeri
problemi ancak yerel olmayan bir kısıt altında tek çözüm verir. O kısıt, Bölge
II'nin verisini eşikte serbest bırakmaz. Bu durumda $s$, dışarıdan seçilebilen
bir sayı olmaktan çıkar.

**Vurduğu halka.** Çevrim ve işaret.

**Yanıt.** Bu çalışma iyi konumlanma sorununu kaydetmekte (Bölüm 1.5, beşinci
engel), ve eşikten erişilen alt kümenin sönümlü olduğunu göstererek
**kararlılık** tarafını karşılamaktadır. İtirazın **teklik** tarafı ise
karşılanmamıştır. Bölüm 13.6 zaten $s$'nin bu modelde belirlenmediğini
yazmaktadır; itiraz o boşluğu daraltmakta, yani $s$'yi yalnızca belirsiz değil,
eşikteki veriye bağlı bir nicelik hâline getirmektedir.

### 22.6 Güçlü eklem koşulu bir tercih olmayabilir

**İtiraz.** İmza değişen bir yüzeyde iyi tanımlı bir Ricci tensörü, dış
eğriliğin sıfırlanmasını zaten dayatmaktadır ([57], [24]). O zaman zayıf koşul
bir seçenek değildir, ve eşik geçirgen olamaz.

**Vurduğu halka.** Geçiş.

**Yanıt.** Bu çalışma itirazı reddetmemekte, **kabul etmektedir**. Bölüm 5.7
sınanan üç profilde oran koşulunu geçen tek profilin hiçbir şey geçirmeyen
profil olduğunu bulmaktadır, ve Bölüm 5.7.1 seksen bir mertebe çiftinin
hiçbirinin iki koşulu birden sağlamadığını göstermektedir. Elde kalan tek
boşluk şudur: itirazın dayandığı alan denklemi biçimi kaçınılmaz değildir, ve
bunu [8] ayrıca belirtmektedir. Bu çalışma o boşluğu kullanmamaktadır.

### 22.7 Nedensel çevrim kurulan yüzeyde vakum gerilimi ıraksayabilir

**İtiraz.** Kapalı nedensel çevrimlerin kurulabilir hâle geldiği yüzeyde
düzenlenmiş gerilim-enerji tensörü ıraksar, ve geri tepki geometriyi yok eder.
Eşik mesafesi tam olarak böyle bir yüzeydir. İtirazı [49] kurmaktadır.

**Vurduğu halka.** İşaret.

**Yanıt.** Bu itiraz hesabı çürütmemekte, hesabın çıktısının kendini iptal
ettiğini söylemektedir, ve bu çalışma karşılık verecek bir hesap
taşımamaktadır. Bölüm 1 [49]'u yalnızca literatürdeki başka çözümler için
anmakta, kendi eşik mesafesine uygulamamaktadır. İtiraz **karşılanmamıştır**.

### 22.8 Yeniden yorumlama dönüş anını ayırt edici olmaktan çıkarabilir

**İtiraz.** Zamanda geriye giden negatif enerjili bir kol, ileri giden bir
karşıparçacık olarak yeniden yorumlanabilir ([35], [26]). O zaman dönüşün
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
senaryo ayrılmaktadır, ve ikisi de Bölüm 18.9'un saydığı okunabilir nicelikler
arasındadır. İtiraz bu nedenle **kısmen karşılanmıştır**: dönüş anı tek başına
yeterli değildir, üç niceliğin birlikte okunması yeterlidir.

### 22.9 Alınan mesafenin gözlenebilirliği

**İtiraz.** Uzaysal türden bir dörtlü momentum, nedenselliğe saygı gösteren bir
konum işlemcisi kabul etmemektedir ([63], [64]). O zaman Bölge II'de alınan
mesafe diye ölçülebilir bir nicelik yoktur, ve $s$ bir koordinat etiketidir.

**Vurduğu halka.** Çevrim, girdi tarafı.

**Yanıt.** Bu çalışma sonucu Bölüm 18.9'da kabul etmektedir. Kabulün sonucu
çekirdek eşitliğe de taşınmalıdır: $\Delta t = s/c$ eşitliğinin sol tarafı
Bölge I'de ölçülür, sağ tarafı ölçülmez. Dolayısıyla eşitlik doğrudan
sınanamaz, ve sınanabilen tek şey sol taraftır. Bölüm 21.2.7'nin düzeneği de
yalnızca sol tarafı okumaktadır.

### 22.10 Fermiyon taşınırsa spin yapısı sorunu

**İtiraz.** Çekirdek amaç bir proton taşımaksa, taşınan nesne fermiyondur. İmza
değiştiren ve Kleinyen manifoldlarda spin yapısının varlığı ise topolojik
engellere takılabilir ([27], [28]).

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
vermez; o soru [27] ile [28]'in konusu olarak kalır. İtiraz bu nedenle **kısmen
karşılanmıştır**: taşınan nesne bir Dirac fermiyonuysa bu hesaptan bir engel
çıkmaz, Bölge I'deki hâliyle bir Majorana fermiyonuysa engel doğrudan çıkar.

### 22.11 Karşılanmış sayılan iki itiraz

İki itirazı bu çalışma kapatmaktadır, ve tamlık için ikisi de burada durur.
Birincisi, genelleştirilmiş Hartman etkisinin reddedilmiş olmasıdır ([43],
[44], [45]); Bölüm 13.4 üç karşı kaynağı da anmakta ve bu çalışmanın hiçbir
sonucunun o tartışmaya dayanmadığını göstermektedir. İkincisi, geçiş süresinin
tek bir okuması bulunmamasıdır ([32], [34], [69]); Bölüm 18.6 beş okumayı
saymakta, faz okumasının seçildiğini bir seçim olarak kaydetmekte, ve seçimi
Bölüm 11.6'nın bağımsız ölçütüyle desteklemektedir.

### 22.12 Ayakta kalan ve düşen

Yukarıdaki maddeler karşısında ayakta kalan kısım hesaptır: sekiz aday matrisin
taranması, katsayının tam olarak bir çıkması, yer değiştirmelerin toplanması,
momentumun koordinatlarla aynı matrisle taşınması, ve doymuş gecikmenin bu
geometrideki kapalı biçimi. Hiçbir itiraz bu adımların cebrini vurmamaktadır.

Düşen kısım ise aritmetiğin fiziksel yorumudur, ve dört ayrı yerden
düşmektedir. Bölüm 22.1 geçerliyse $D$ bir dönüşüm değil bir adlandırmadır.
Bölüm 22.3 geçerliyse $\tau$ ile $s$ toplanamaz. Bölüm 22.2 geçerliyse geçişin
bedeli küçük bir olasılık değildir. Bölüm 22.4'ün ikilemi kapatılmadıkça, elde
ya nedensel bir çelişki ya da bilinen bir tepe kayması kalmaktadır. Dördü
birbirinden bağımsızdır, ve dördü de zincirin ayrı bir halkasını kesmektedir.

İki itiraz ise hesapla daraltılmıştır, ve daraltma biçimi kayda değer.
Bölüm 22.1'in ölçütü sayıya döküldüğünde itiraz doğrudan okumada ayakta
kalmakta, ara bölgeden geçen okumada düşmektedir; yani zincir yalnızca üç
bölgeli hâliyle savunulabilir. Bölüm 22.8'in hesabı ise dönüş anının tek başına
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
8. T. Dray, G. Ellis, C. Hellaby. *Note on signature change and Colombeau
   theory*. Gen. Rel. Grav. **33** (2001) 1041. arXiv:gr-qc/0012047
9. I. L. Egusquiza. *Self-adjoint extensions and signature change*. Class.
    Quantum Grav. **12** (1995) L89. arXiv:gr-qc/9503015
10. W. Hasse, N. E. Rieger. *A transformation theorem for transverse
    signature-type changing semi-Riemannian manifolds*. Diff. Geom. Appl.
    **103** (2026) 102370. arXiv:2407.09699
11. N. E. Rieger, W. Hasse. *Pseudo-timelike loops in signature changing
    semi-Riemannian manifolds with a transverse radical*. Results in Physics
    **78** (2025) 108478. arXiv:2409.02403
12. B. Alexandre, S. Gielen, J. Magueijo. *Overall signature of the metric and
    the cosmological constant*. arXiv:2306.11502
13. I. Bars. *Two-time physics in field theory*. Phys. Rev. D **62** (2000)
    046007. arXiv:hep-th/0003100
14. E. Piceno, A. Rosado, E. Sadurní. *Fundamental constraints on two-time
    physics*. Eur. Phys. J. Plus **131** (2016) 352. arXiv:1512.05345
15. D. Figueiredo, F. A. Gomes, S. Fumeron, B. Berche, F. Moraes. *Modeling Kleinian
    cosmology with electronic metamaterials*. Phys. Rev. D **94** (2016) 044039.
    arXiv:1608.03812
16. H. Maeda. *Energy conditions for non-timelike thin shells*. Class. Quantum
    Grav. **40** (2023) 195009. arXiv:2306.07326
17. M. Mars, J. M. M. Senovilla, R. Vera. *Lorentzian and signature changing
    branes*. Phys. Rev. D **76** (2007) 044029. arXiv:0705.3380
18. M. Lienert, S. Petrat, R. Tumulka. *Multi-time wave functions versus
    multiple timelike dimensions*. Found. Phys. **47** (2017) 1582.
    arXiv:1708.03376
19. D.-A. Deckert, L. Nickel. *Consistency of multi-time Dirac equations with
    general interaction potentials*. J. Math. Phys. **57** (2016) 072301.
    arXiv:1603.02538
20. T. Dray, C. A. Manogue, R. W. Tucker. *Particle production from signature
    change*. Gen. Rel. Grav. **23** (1991) 967.
21. T. Dray, C. A. Manogue, R. W. Tucker. *The scalar field equation in the
    presence of signature change*. Phys. Rev. D **48** (1993) 2587.
    arXiv:gr-qc/9303002
22. J. D. Romano. *Scalar and spinor fields in signature-changing spacetimes*.
    Phys. Rev. D **47** (1993) 4328.
23. T. Dray, C. A. Manogue, R. W. Tucker. *Boundary conditions for the scalar
    field in the presence of signature change*. Class. Quantum Grav. **12**
    (1995) 2767. arXiv:gr-qc/9501034
24. S. A. Hayward. *Comment on "Boundary conditions for the scalar field in the
    presence of signature change"*. arXiv:gr-qc/9502001
25. W. Duane. *The transfer in quanta of radiation momentum to matter*. Proc.
    Natl. Acad. Sci. USA **9** (1923) 158.
26. G. Feinberg. *Possibility of faster-than-light particles*. Phys. Rev.
    **159** (1967) 1089.
27. L. J. Alty. *Kleinian signature change*. Class. Quantum Grav. **11** (1994)
    2523.
28. L. J. Alty, A. Chamblin. *Spin structures on Kleinian manifolds*. Class.
    Quantum Grav. **11** (1994) 2411.

**Tünelleme süresi ve doymuş gecikme**

29. T. E. Hartman. *Tunneling of a wave packet*. J. Appl. Phys. **33** (1962)
    3427.
30. H. G. Winful. *Tunneling time, the Hartman effect, and superluminality: a
    proposed resolution of an old paradox*. Phys. Rep. **436** (2006) 1.
31. E. P. Wigner. *Lower limit for the energy derivative of the scattering
    phase shift*. Phys. Rev. **98** (1955) 145.
32. M. Büttiker. *Larmor precession and the traversal time for tunneling*.
    Phys. Rev. B **27** (1983) 6178.
33. R. Landauer, Th. Martin. *Barrier interaction time in tunneling*. Rev. Mod.
    Phys. **66** (1994) 217.
34. R. Ramos, D. Spierings, I. Racicot, A. M. Steinberg. *Measurement of the
    time spent by a tunnelling atom within the barrier region*. Nature **583**
    (2020) 529.

**Takyonlar ve nedensellik**

35. O. M. P. Bilaniuk, V. K. Deshpande, E. C. G. Sudarshan. *"Meta" relativity*.
    Am. J. Phys. **30** (1962) 718.
36. G. A. Benford, D. L. Book, W. A. Newcomb. *The tachyonic antitelephone*.
    Phys. Rev. D **2** (1970) 263.

**İmza değişiminin kozmolojik kaynağı ve yer çekimi ölçeği**

37. J. Mielczarek. *Signature change in loop quantum cosmology*. Springer Proc.
    Phys. **157** (2014) 555. arXiv:1207.4657
38. M. Bojowald, G. M. Paily. *Deformed general relativity and effective actions
    from loop quantum gravity*. Phys. Rev. D **86** (2012) 104018.
    arXiv:1112.1899
39. N. Arkani-Hamed, S. Dimopoulos, G. Dvali. *The hierarchy problem and new
    dimensions at a millimeter*. Phys. Lett. B **429** (1998) 263.
    arXiv:hep-ph/9803315
40. ATLAS Collaboration. *Search for new phenomena in events with an energetic
    jet and missing transverse momentum in $pp$ collisions at
    $\sqrt{s} = 13$ TeV*. Phys. Rev. D **103** (2021) 112006. arXiv:2102.10874

**İki engelli hâl ve ona yöneltilen itirazlar**

41. V. S. Olkhovsky, E. Recami, G. Salesi. *Superluminal tunneling through two
    successive barriers*. Europhys. Lett. **57** (2002) 879.
42. S. Longhi, P. Laporta, M. Belmonte, E. Recami. *Measurement of superluminal
    optical tunneling times in double-barrier photonic band gaps*. Phys. Rev. E
    **65** (2002) 046610.
43. H. G. Winful. *Apparent superluminality and the generalized Hartman effect
    in double-barrier tunneling*. Phys. Rev. E **72** (2005) 046608; erratum
    Phys. Rev. E **73** (2006) 039901.
44. H. P. Simanjuntak, P. Pereyra. *On the generalized Hartman effect
    presumption in semiconductors and photonic structures*. Nanoscale Res.
    Lett. **8** (2013) 145.
45. S. Kudaka, S. Matsumoto. *A mathematically rigorous approach raises
    questions concerning the generalized Hartman effect*. arXiv:1105.2159
**Zamanda geriye yolculuğa izin veren çözümler**

46. K. Gödel. *An example of a new type of cosmological solution of Einstein's
    field equations of gravitation*. Rev. Mod. Phys. **21** (1949) 447.
47. F. J. Tipler. *Rotating cylinders and the possibility of global causality
    violation*. Phys. Rev. D **9** (1974) 2203.
48. M. S. Morris, K. S. Thorne, U. Yurtsever. *Wormholes, time machines, and
    the weak energy condition*. Phys. Rev. Lett. **61** (1988) 1446.
49. S. W. Hawking. *Chronology protection conjecture*. Phys. Rev. D **46**
    (1992) 603.
50. R. C. Tolman. *The Theory of the Relativity of Motion*. University of
    California Press, 1917, §71.
51. S. Liberati, S. Sonego, M. Visser. *Faster-than-c signals, special
    relativity, and causality*. Ann. Phys. **298** (2002) 167.
    arXiv:gr-qc/0107091

**İnce kabuk, eklem koşulu ve enerji koşulları**

52. W. Israel. *Singular hypersurfaces and thin shells in general relativity*.
    Nuovo Cimento B **44** (1966) 1; erratum **48** (1967) 463.
53. C. Lanczos. *Flächenhafte Verteilung der Materie in der Einsteinschen
    Gravitationstheorie*. Ann. Phys. **74** (1924) 518.
54. S. W. Hawking, G. F. R. Ellis. *The Large Scale Structure of Space-Time*.
    Cambridge University Press, 1973.
55. E. Curiel. *A Primer on Energy Conditions*. Einstein Stud. **13** (2017) 43.
    arXiv:1405.0403
56. C. Hellaby, T. Dray. *Failure of standard conservation laws at a classical
    change of signature*. Phys. Rev. D **49** (1994) 5096. arXiv:gr-qc/9404001
57. M. Kossowski, M. Kriele. *Smooth and discontinuous signature type change in
    general relativity*. Class. Quantum Grav. **10** (1993) 2363.

**İmza değişiminin kurucu çalışmaları**

58. J. B. Hartle, S. W. Hawking. *Wave function of the Universe*. Phys. Rev. D
    **28** (1983) 2960.
59. G. F. R. Ellis, A. Sumeruk, D. Coule, C. Hellaby. *Change of signature in
    classical relativity*. Class. Quantum Grav. **9** (1992) 1535.
60. J. Barrett, G. W. Gibbons, M. J. Perry, C. N. Pope, P. Ruback. *Kleinian
    geometry and the $N = 2$ superstring*. Int. J. Mod. Phys. A **9** (1994)
    1457. arXiv:hep-th/9302073

**Takyonlar, yerelleştirme ve yeniden yorumlama**

61. E. Recami, R. Mignani. *Classical theory of tachyons*. Riv. Nuovo Cim. **4**
    (1974) 209.
62. E. Recami. *Classical tachyons and possible applications*. Riv. Nuovo Cim.
    **9** (1986) 1.
63. T. D. Newton, E. P. Wigner. *Localized states for elementary systems*. Rev.
    Mod. Phys. **21** (1949) 400.
64. G. C. Hegerfeldt. *Remark on causality and particle localization*. Phys.
    Rev. D **10** (1974) 3320.
65. C. Baltay, G. Feinberg, N. Yeh, R. Linsker. *Search for uncharged
    faster-than-light particles*. Phys. Rev. D **1** (1970) 759.
66. I. Bars, C. Kounnas. *Theories with two times*. Phys. Lett. B **402** (1997)
    25. arXiv:hep-th/9703060

**Geçiş süresinin tanımları ve ölçümleri**

67. F. T. Smith. *Lifetime matrix in collision theory*. Phys. Rev. **118**
    (1960) 349.
68. M. Büttiker, R. Landauer. *Traversal time for tunneling*. Phys. Rev. Lett.
    **49** (1982) 1739.
69. E. H. Hauge, J. A. Støvneng. *Tunneling times: a critical review*. Rev.
    Mod. Phys. **61** (1989) 917.
70. A. M. Steinberg, P. G. Kwiat, R. Y. Chiao. *Measurement of the
    single-photon tunneling time*. Phys. Rev. Lett. **71** (1993) 708.
71. A. Enders, G. Nimtz. *On superluminal barrier traversal*. J. Phys. I France
    **2** (1992) 1693.
72. A. Sommerfeld. *Über die Fortpflanzung des Lichtes in dispergierenden
    Medien*. Ann. Phys. **44** (1914) 177.
73. L. Brillouin. *Wave Propagation and Group Velocity*. Academic Press, 1960.

**Karşılıklılık, parçacık üretimi ve ölçek**

74. R. G. Newton. *Scattering Theory of Waves and Particles*. 2nd edition,
    Springer, 1982.
75. N. D. Birrell, P. C. W. Davies. *Quantum Fields in Curved Space*. Cambridge
    University Press, 1982.
76. L. Parker. *Quantized fields and particle creation in expanding universes
    I*. Phys. Rev. **183** (1969) 1057.
77. W. L. Bragg. *The diffraction of short electromagnetic waves by a crystal*.
    Proc. Camb. Phil. Soc. **17** (1913) 43.
78. A. Ashtekar, J. Baez, K. Krasnov. *Quantum geometry of isolated horizons
    and black hole entropy*. Adv. Theor. Math. Phys. **4** (2000) 1.
    arXiv:gr-qc/0005126
79. A. Ashtekar, T. Pawlowski, P. Singh. *Quantum nature of the big bang:
    improved dynamics*. Phys. Rev. D **74** (2006) 084003. arXiv:gr-qc/0607039
80. J. D. Bjorken. *Highly relativistic nucleus-nucleus collisions: the central
    rapidity region*. Phys. Rev. D **27** (1983) 140.
81. G. R. Lynch, O. I. Dahl. *Approximations to multiple Coulomb scattering*.
    Nucl. Instr. Meth. B **58** (1991) 6.
82. I. Antoniadis, N. Arkani-Hamed, S. Dimopoulos, G. Dvali. *New dimensions at
    a millimeter to a Fermi and superstrings at a TeV*. Phys. Lett. B **436**
    (1998) 257. arXiv:hep-ph/9804398

**Genişletilmiş cisimler ve çok zamanlı yapının sınırları**

83. W. G. Dixon. *Dynamics of extended bodies in general relativity I:
    Momentum and angular momentum*. Proc. R. Soc. Lond. A **314** (1970) 499.
84. M. Tegmark. *On the dimensionality of spacetime*. Class. Quantum Grav.
    **14** (1997) L69.
85. W. Craig, S. Weinstein. *On determinism and well-posedness in multiple
    time dimensions*. Proc. R. Soc. A **465** (2009) 3023. arXiv:0812.0210
86. R. Loudon. *One-dimensional hydrogen atom*. Am. J. Phys. **27** (1959)
    649.
