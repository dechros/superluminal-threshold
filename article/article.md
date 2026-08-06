# Öte tarafta kat edilen mesafeyle zamanda geriye taşınma

## Öz

Kütleli bir parçacığı zamanda geriye taşımanın bir yolu aranmaktadır. Aranan yol
üç adım yürür: parçacık ışık hızı eşiğini geçer, öte tarafta mekânda bir mesafe
kat eder ve aynı eşikten geri döner. Bu metin de o mesafenin dönüşte hangi ana
denk düştüğünü hesaplamıştır.

Hesabın verdiği sonuç şudur: parçacık öte tarafta $s$ kadar yol alırsa, dönüşte
saat tam $s$ kadar kayar. Aradaki katsayı bire eşit çıktığından, mesafe bir hıza
bölünmeden doğrudan süreye dönüşür. Eşikten geçmenin kendisi de bir gecikme
yaratır, ancak o gecikme eşik kalınlaştıkça artmayı bırakır ve bir tavana oturur.
Saat kayması ise böyle bir tavan tanımaz, mesafeyle sınırsız büyür. Bu yüzden iki
nicelik belirli bir mesafede eşitlenir, ve o mesafeyi aşan her yolculuk parçacığı
yola çıktığı andan önce geri getirir.

Ne var ki bu sonuç bir koşula bağlı kalır. Eşikten geçişi sekiz ayrı matris
gerçekleştirebilir, ve hangisinin işlediğini geometri seçmez: dördü dönüşü ileri
bir ana, dördü geri bir ana taşır. Dolayısıyla kanıtlanan önerme yalnızca şu
olur: böyle bir geçiş gerçekleşirse, dönüş anı hesaplanmış bir sayıya oturur.
Geçişin gerçekten kurulabildiği ise kanıtlanmamıştır, çünkü önünde iki engel
durmaktadır. Birincisi, eşiği geçirgen kabul eden okuma geçiş yüzeyinde ince bir
madde tabakası doğurur ve o tabaka baskın enerji koşulunu çiğner. İkincisi,
iddiayı taşıyan aralıkta parçacık öte tarafta gözlenemez.

**Anahtar kelimeler:** imza değişimi, üstışık dönüşüm, zaman yolculuğu, eklem
koşulu, geçiş genliği, kütleli parçacık.

## 1. Giriş

Kütleli bir cismi zamanda geriye taşımanın bilinen bir yolu yoktur. Bu metin bir
yol önerir ve onun aritmetiğini kurar: parçacık ışık hızı eşiğini geçer, öte
tarafta mekânda mesafe kat eder ve geri döner. Metnin sorduğu soru, orada
harcanan mesafenin dönüşte saati ne kadar kaydırdığıdır.

Soruyu kurabilmek için metin iki bölgeyi birbirinden ayırmaktadır. **Bölge I**,
parçacığın yola çıktığı sıradan bölgedir; orada ışık hızı bir üst sınır olarak
durur ve zaman tek yönde işler. **Bölge II** ise eşiğin öte yanında kalır ve
orada metriğin imzası dönmüştür: tek bir mekân ekseni ile üç zaman ekseni
bulunur. Bu yüzden parçacık Bölge II'de yalnızca o tek mekân ekseni boyunca
ilerleyebilir. Metin boyunca "öte taraf" sözü de aynı bölgeyi, yani Bölge II'yi
adlandırmaktadır.

### 1.1 Kurulan eşleme

Metnin cevapladığı soru şudur: parçacık geri döndüğünde Bölge I'in dört
koordinatının neresine oturur. Buradaki "nerede", uzaydaki yerle sınırlı
kalmaz; asıl cevap zaman koordinatında çıkar. Metin bunun için tek bir eşleme
kurmuştur ve onu şöyle yazar:

$$(\text{öte taraftaki yönelim ve hareket}) \;\longmapsto\; (t, x, y, z)_{\text{dönüş olayı}}$$

**Ana sonuç.** Parçacık öte tarafın tek uzay ekseninde $s$ kadar ilerlerse, Bölge
I'in saati tam $s$ kadar kayar. Aradaki katsayı bire eşit olduğundan araya bir
hız ya da bir ölçek çarpanı girmez. Kayma yalnızca zaman koordinatında görünür,
çünkü dönüş olayının uzay koordinatlarına hiçbir şey sızmaz. Eşleme doğrusal
olduğu için arka arkaya yapılan yolculukların kaymaları da basitçe toplanır.
Bütün bunlara karşın geometri tek başına kaymanın işaretini, yani saatin ileri
mi geri mi gittiğini belirlemez.

İkinci sonucu, eşikten geçmenin kendi yarattığı gecikme verir. O gecikme eşik
kalınlaştıkça bir tavana oturur ve orada kalır, saat kayması ise mesafeyle
sınırsız büyür. Dolayısıyla ikisi belirli bir mesafede eşitlenir, ve o mesafeyi
aşan her $s$ parçacığı yola çıktığı andan önce geri getirir. Bu metin zamanda
yolculuğu baştan kabul etmez, yukarıdaki eşlemeden okumaktadır: dönüş anının,
parçacık hiç eşiğe girmeseydi bulunacağı andan farklı olup olmadığını hesap
söyler.

### 1.2 Sonucun koşulu

Eşikten geçişi sekiz ayrı matris gerçekleştirebilir. Hangisinin işlediğini
geometri seçmez, çünkü bu sekizi birbirine bağlayan dönüşümler her iki bölgenin
metriğini de bozmadan bırakır. Dört matris, öte taraftaki bir ilerlemeyi saatte
daha geç bir ana taşır; kalan dördü daha erken bir ana. Bu metin, geriye taşıyan
dörtlüden birini kullanmıştır. Bunu bir seçim olarak yapar, hesaptan çıkan bir
sonuç olarak değil (Bölüm 4.1).

Parçacık öte tarafta tek bir yönde yürür; o yürüyüşün Bölge I'de hangi zaman
yönüne düştüğünü matris belirler. Başka bir deyişle parçacık "geriye yürümez",
ileri yürür ve eşleme onu geriye taşır. Geçmişe varmak için iki şey birlikte
gerekir: geriye taşıyan bir matris ve gecikmeyi aşacak kadar büyük bir $s$.

Dolayısıyla metnin kanıtladığı önerme şu olur: **böyle bir geçiş gerçekleşirse**,
dönüş anı hesaplanmış bir sayıya oturur. Geçişin kurulabildiği ise
kanıtlanmamıştır, oysa zamanda yolculuktan söz edebilmek tam olarak onu
gerektirir. Kurulmasının önünde de iki engel durmaktadır. Birincisi, eşiği
geçirgen kabul eden okuma geçiş yüzeyinde bir madde tabakası doğurur ve o tabaka
baskın enerji koşulunu çiğner (Bölüm 5.6). İkincisi, iddiayı taşıyan aralıkta
parçacık öte tarafta gözlenemez (Bölüm 18.9).

### 1.3 İddianın büyüklüğü

Yukarıdaki sonuç dört parçadan kurulur, ancak bunlardan yalnızca dördüncüsü
yenidir. İlkini literatür 1962 ile 1970 arasında göstermiştir: ışıktan hızlı
hareket geçmişe varmayı mümkün kılar. İkincisini de yine literatür bilmektedir,
yani öte tarafın bir uzay ve üç zaman ekseni taşıdığını, parçacıkların da
yalnızca o tek uzay ekseninde ilerleyebildiğini. Üçüncüsü, bir uzay ekseninin bu
geçiş altında zaman eksenine dönüşmesidir, ve o da bilinen bir sonuç sayılır.
Geriye kalan dördüncü adımı ise aşağıdaki cümle taşır:

> Işık hızını geçen kütleli madde, oradaki tek mekân boyutunda hareket edip
> subluminal bölgeye döndüğünde **farklı bir zaman konumunda** bulunur.

Literatürde bulunmayan şey tam olarak budur: öte taraftaki yer değiştirmeyi bir
saat kaymasına çeviren ve dönüşte hangi ana varıldığını sayıyla veren bir
çalışma. İlk üç parçanın her biri yukarıda kaynağıyla anılmıştır, dördüncüsünün
ise anılacak bir kaynağı yoktur.

### 1.4 Sonucu taşıyan adımlar

Sonuca yedi adımda varılmıştır. Adımların tamamı, her birinin hangi bölümde
kurulduğuyla birlikte Bölüm 19'da sıralanır. Hesabı en kısa yoldan tekrar etmek
isteyen okuyucu orayı okursa yeter.

### 1.5 Bu adımların göstermedikleri

Yedi adım bir aritmetik kurar ve o aritmetik kendi içinde eksiksiz işler. Ancak
aynı aritmetik, böyle bir geçişin fiziksel olarak kurulabildiğini göstermez.
Kurulmasının önüne üç ayrı engel çıkar, ve üçü birbirinden farklı türdendir.

Birincisi bir büyüklük sorunudur. Eşiği geçebilen yapılanmalarda parçacığın geçme
olasılığını veren genlik, kalınlık $d = 8$'e çıktığında
$3{,}46 \times 10^{-12}$'ye kadar iner; yani geçiş mümkün kalır ama neredeyse hiç
gerçekleşmez. İkincisi ise bir açık sorudur. Saat kaymasının işaretini
seçebilmek, sekiz matris arasından birini evrensel olarak sabitleyen bir kuralın
bulunmamasına dayanır, oysa böyle bir kuralın yokluğu kanıtlanmamıştır.
Üçüncüsü, eşiği geçirgen kabul eden okuma ile geçiş yüzeyindeki madde
tabakasının bir arada duramamasıdır. Bu son engel bu modele özgü değildir, çünkü
kaynağını literatürün zaten taşıdığı güçlü ile zayıf eklem koşulu ayrımından
alır.

### 1.6 Model

Model iki bölge değil üç bölge kullanır. Bölge I ile Bölge II'nin arasındaki
geçiş, kalınlıksız bir yüzey olarak alınmaz; kendi kalınlığı ve kendi imzası olan
üçüncü bir bölge olarak durur. Bütün hesaplar bu ara bölgenin dört tipi ve beş
ayrı kalınlığı için ayrı ayrı yürütülmüştür.

Eşik geçirgen alınmıştır, yani parçacık oradan geçebilmektedir. Bu seçim, iki
bölgeyi birbirine bağlarken zayıf eklem koşulunu benimsemek anlamına gelir, ve
bedelini de açıkça öder. Ödenen bedel, geçiş yüzeyinde doğan bir madde
tabakasıdır; tabakanın gücü kalınlık arttıkça azalır, ama hiç sıfırlanmaz. Yüzey
zamansal olmadığından bu tabaka baskın enerji koşulunu çiğner, ve daha uygun bir
madde seçerek bundan kurtulmak mümkün olmaz. En ağır sonucu ise Bölüm 5.7 verir:
bu metrik ailesinde oran koşulunu geçebilen tek profil, güçlü koşulu sağlayan
profil çıkar, yani hiçbir şey geçirmeyen profil.

Metin parçacığı ayrıca iki okumayla birden taşır. Hesaplar dalga paketi üzerinden
yürür, anlatım ise noktasal bir cisim dilini kullanır. İki okumayı birbirine
çeviren sözlüğün, paket yeterince dar tutulduğunda tam olarak işlediği
gösterilmiştir.

### 1.7 Yolculuk

Parçacığın öte tarafta yapabilecekleri iki etikete indirgenmiştir: ara bölgenin
hangi yüzünden çıktığı ve enerji vektörünün ne kadar döndüğü. Vektörün yönü
serbest kalır, uzunluğu ise sabit durur; üç zaman ekseni arasındaki $O(3)$
dönmeleri fiziksel bir fark üretmez, yalnızca aynı durumu farklı biçimde yazar.

Bu iki etiketten hareketin saate ne taşıdığı da çıkar. Tümüyle üç zaman ekseninin
içinde kalan bir hareket Bölge I'in saatini hiç kaydırmaz, çünkü o eksenler
arasındaki dönmeler eşlemenin katsayısına dokunmaz. Aynı nedenle başladığı yere
dönen bir gezinti de hiçbir iz bırakmaz. Geriye saati oynatan tek şey kalır: tek
uzay ekseni boyunca alınan yol.

Dönüş anını ise parçacığın yanında taşıdığı bir saat vermez. O an, ara bölgeye
giriş ve çıkış genliklerinin ortak fazından okunur. Engel rejiminde bu faz
kalınlık arttıkça bir tavana oturur, ve kalınlığın bilgisi artık fazda değil,
frekans bileşenlerinin karışımında kalır.

### 1.8 Geri döndüğünde

Parçacık geri döndüğünde enerjisi, sürati ve kütlesi tam olarak korunur;
korunmayan tek şey gittiği yön olur. Bunun nedeni şudur: öte tarafta hiçbir
fiziksel iz bırakmayan bir ayar dönmesi, Bölge I'de parçacığın yön değiştirmesi
olarak görünür, ve bu yön değişikliği hiçbir enerji harcamaz. Üstelik sapma
açıları her değeri de alamaz, sonlu bir kümeden gelir. İki özellik birleşince
çalışmanın deneyle ayırt edilebilecek öngörüsü ortaya çıkar: çarptığı hedefin
geri tepmediği ve açıları ayrık değerlere oturan bir esnek sapma.

Eşlemenin kendisi ise tek yönlüdür. Tarama bütün girdileri tek tek denemiş ve
$312$ ayrı öte taraf durumunun yalnızca $158$ farklı dönüş olayına düştüğünü
göstermektedir. Buradaki sıkışma, boyut değişiminde kaybolan bilginin sayısal
ölçüsünü verir.

### 1.9 Gösterilmeyenler

Öte tarafta durup ileriyi kestirmeye çalışan bir gözlemci başarısız olur, çünkü
oradaki başlangıç değeri problemi iyi konumlanmaz. Ancak bu çöküş, eşikten
geçerek oraya giren hiçbir şeyi etkilemez: kütle kabuğu üzerindeki bir modun
büyüme katsayısı her durumda negatif çıkar, yani mod büyümek yerine sönümlenir.

İkinci sınır gecikmeyle ilgilidir. Gecikmenin kalınlıkla doyması, içeride bir
yayılma hızının ölçüldüğü anlamına gelmez, çünkü aynı rejimde grup hızı zaten
tanımsız kalır. Hesap bir şeyi daha göstermiştir: bu gecikme, ara bölgede
depolanan alanın orada ne kadar durduğundan bağımsız bir sayı değildir.

Üçüncü sınır ise gözlemdedir. İddiayı taşıyan aralıkta parçacık öte tarafta
doğrudan görünmez, ve geriye yalnızca üç sınır niceliği kalır. Üçü de tek bir
bilgi verir, yani bir geçişin olduğunu (Bölüm 18.9). Geçişin tayf üzerinde hangi
olasılıkla dağıldığı ise hesaplanmamıştır.

### 1.10 Modelin maddeleri

Aşağıdaki maddelerin hepsi tek bir eşlemeye aittir: öte taraftaki yönelimi dönüş
olayının dört koordinatına bağlayan eşlemeye. Her madde bu eşlemenin ya bir
girdisini, ya bir kısıtını, ya da bir sonucunu kaydeder.

1. Model üç bölge kullanır: Bölge I, ara bölge ve öte taraf.
2. Ara bölgenin **neyden yapıldığı** ile **ne kadar kalın olduğu** birbirinden
 bağımsız iki soru sayılır. Kalınlık sıfıra inince tipin bir önemi kalmaz,
 ara bölge hiç yokken de kalınlığın bir önemi kalmaz.
3. Eşik geçirgen kalır. Bu, zayıf eklem koşulunu seçmenin sonucudur ve bedelini
 bir madde tabakası olarak öder. Tabakanın gücü kalınlık arttıkça azalır ama
 hiç sıfırlanmaz, ve tabaka **baskın enerji koşulunu çiğner**.
4. Parçacık hem dalga paketi hem noktasal cisim olarak okunur; ikinci okuma
 paket yeterince dar tutulduğunda tam olarak geçerli kalır.
5. Öte tarafta ileriyi kestirme problemi kendi içinde iyi konumlanmaz, ancak
 eşikten erişilebilen alt kümesi bu sorundan etkilenmez.
6. Dönüş anını bir süre ölçümü değil, genliğin fazı verir. Engel rejiminde bu
 faz kalınlıkla bir tavana oturur.
7. Gidiş dönüş boyunca enerji, sürat ve kütle korunur; yön korunmaz.
8. Öte taraftaki bir ayar dönmesi Bölge I'de bir sapma olarak görünür, hiçbir
 enerji harcamaz ve açıları ayrık değerler alır.
9. Dönüş olayının dört koordinatı ayrı kaynaklardan gelir: zaman bileşenini faz
 verir, uzay bileşenlerini çıkış yüzü ile ayrık sapma açısı verir. Öte
 taraftaki yönelim bu koordinatların hepsine değil, yalnızca bir kısmına
 ulaşır.

### 1.11 Okuma haritası

Metin üç adım üzerine kurulmuştur, ve üçü de tek bir amaca hizmet eder: kütleli
bir parçacığı zamanda geriye taşımak. Aşağıdaki tablo her adımın hangi bölümlerde
kurulduğunu gösterir.

| Adım | Sorusu | Kurulduğu bölümler |
| ------ | ----------------------------------------------------- | ----------------------------------------------------------- |
| Geçiş | Kütleli bir parçacık eşiğin ötesine nasıl geçer | Bölüm 3, Bölüm 4, Bölüm 5, Bölüm 6, Bölüm 8, Bölüm 12 |
| Mesafe | Öte tarafta mekânda kat edilen mesafe ne anlama gelir | Bölüm 4.1.1, Bölüm 4.1.2, Bölüm 4.1.3, Bölüm 9, Bölüm 10.1 |
| Dönüş | Geri döndüğünde saatte nereye düşer | Bölüm 13, Bölüm 16, Bölüm 17, Bölüm 18, Bölüm 19 |

Bölüm 2 bu üç adımın tamamını tek bir hesap hâlinde, sayılarıyla birlikte önden
verir. Kalan bölümler o hesabın her bir adımını ayrı ayrı kurar.

**Simülasyon için gereken en kısa yol.** Yedi adımın tamamı Bölüm 19'da tek
yerde toplanmıştır ve her adımın hangi bölümde kurulduğu orada yazılıdır. Hesabı
tekrar etmek isteyen okuyucu için en kısa yol budur: önce Bölüm 19, sonra oradan
işaret edilen yedi adres.

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

Bölüm 14 ile Bölüm 15, eşiğin hangi modları geçirdiğini kayda geçiren iki
dökümdür ve ana hat ile itiraz bölümlerinin arasında durmaktadır. Sonucu
üretmezler, ancak sonucun kendi içinde tutarlı kalmasını onlar sağlar.

**"Sözlük" sözcüğü üç ayrı nesneyi adlandırır.** Üçü aşağıda bir kez ayrılmıştır ve
metnin geri kalanında bu ayrım tekrarlanmamaktadır.

| Nerede | Neyi eşler | Çekirdek için rolü |
| ---------- | -------------------------------------------------------------------------------------- | ------------------------------------------------ |
| Bölüm 10.1 | Öte tarafın dört ekseni $\to$ Bölge I'in yuvaları ve bir birim adımın saatte ürettiği | **Çekirdeğin kendisi.** İspatı Bölüm 4.1.1'dedir |
| Bölüm 16.2 | Öte taraftaki yönelim $\to$ Bölge I'de gözlenen nicelikler | Çekirdeğin girdi tarafı |
| Bölüm 17.1 | Dört koordinatta hareket ile yönelim arasındaki ayrım | Girdinin hangi kısmının hareket olduğu |

Sayısal katsayı yalnızca birincisinde tanımlanır ve tek bir yerde ispatlanmıştır.
Diğer ikisi onu kullanır, yeniden kurmaz.

---

# Kısım I. Bölge I

## 2. Çekirdek hesap

Hesabı baştan sona tekrar etmek için gereken her şey bu bölümde toplanmıştır ve
bölüm, makalenin geri kalanı okunmadan uygulanabilir. Her satırın hangi bölümde
türetildiği yanında yazılıdır. Metnin kalanı da o türetmeleri ve her birinin
hangi itirazı karşıladığını anlatmaktadır.

**Girdi.** Hesap, öte tarafın enerji vektörü $E = (E_1, E_2, E_3)$ ile başlar. Bu
vektör Bölge I'de parçacığın üç momentum bileşenine karşılık gelir (Bölüm 15.1).
Vektörün öte taraftaki yönü fiziksel bir fark yaratmaz, yalnızca uzunluğu yaratır
(Bölüm 15.3). Ara bölgenin tipi hesaba, imzası çevrilen yönlerin sayısı olan $n$
ile girer; Öklid tipi için $n = 3$. Geri kalan girdiler ara bölgenin kalınlığı
$d$, kütle parametresi $\mu$ ve hız $c$ olur.

**Adımlar.**

| Adım | Nicelik | Nerede |
| ---- | ---------------------------------------------------------------------------------- | ------------------------ |
| 1 | $\omega = c\sqrt{E_1^2 + E_2^2 + E_3^2 + \mu}$ | Bölüm 15.1 |
| 2 | $k_\perp^2 = E_2^2 + E_3^2$ | Bölüm 18.3 |
| 3 | $\kappa = \sqrt{\omega^2/c^2 - k_\perp^2 - \mu} = \lvert E_1 \rvert$ | Bölüm 18.7 |
| 4 | $\beta = \sqrt{\tfrac{2n}{3}k_\perp^2 - E_1^2}$, iç sönüm sabiti | Bölüm 18.7 |
| 5 | $q = i\beta$ söndürücü hâlde, reel yayılımlı hâlde | Bölüm 12.1 |
| 6 | $A(\omega) = \dfrac{4\kappa q}{(\kappa+q)^2 e^{-iqd} - (\kappa-q)^2 e^{iqd}}$ | Bölüm 12.1 |
| 7 | $\tau = \dfrac{\mathrm{d}}{\mathrm{d}\omega}\arg A(\omega)$, tek geçişin gecikmesi | Bölüm 13.2 |
| 8 | Gidiş dönüş gecikmesi $= 2\tau$ | Bölüm 12 |
| 9 | Varış anı $= 2\tau - s$, geri taşıyan dalda | Bölüm 4.1.2, Bölüm 4.1.3 |
| 10 | Eşik mesafesi $s^\ast = 2\tau$ | Bölüm 4.1.3 |
| 11 | Ödenen enerji oranı $\Delta E / E = \Delta / s$ | Bölüm 4.1.5 |

Dokuzuncu satırda $s$'nin önündeki katsayı **bire eşittir** ve araya bir hız
girmez. Çalışmanın asıl sonucu budur (Bölüm 4.1.1, Bölüm 4.1.2). O terimin
işaretini, hangi geçiş eşlemesinin gerçeklendiği belirler; parçacığın öte tarafta
hangi yöne yürüdüğü belirlemez (Bölüm 4.1.3).

**Denetim değerleri.** Yukarıdaki adımları uygulayan bir programın doğru
çalışıp çalışmadığı aşağıdaki yapılanmadan sınanabilir, çünkü bu yapılanma
metnin bütün çekirdek sayılarını üretmektedir.

$$c = \mu = 1, \qquad n = 3, \qquad d = 8$$
$$E = L(\sin\theta\cos\varphi,\; \sin\theta\sin\varphi,\; \cos\theta),
\qquad \theta = \pi/3,\; \varphi = 0{,}7,\; L = 3$$

| Nicelik | Değer |
| ------------------------------------------------- | ------------------------------------------ |
| $E$ | $(1{,}987118,\; 1{,}673727,\; 1{,}500000)$ |
| $\omega$ | $3{,}162278$ |
| $k_\perp^2$ | $5{,}051361$ |
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
olduğunu söyler, o şeyin ne kadar sık gerçekleşeceğini söylemez. Aynı
yapılanmada tek bir geçişin genliği $4{,}692932 \times 10^{-9}$, geçirgenliği
$2{,}202361 \times 10^{-17}$ çıkmaktadır. Bölüm 4.1.3 ile Bölüm 4.1.5'in
kalınlığa göre verdiği $3{,}46 \times 10^{-12}$ dizisi ise başka bir
yapılanmaya aittir, yani buradaki sayının kalınlıkla ölçeklenmiş hâli değildir.
Dönüş anı tek başına eksik kalır, çünkü o anın ne sıklıkta gerçekleşeceğini
yalnızca bu iki sayı verir.

### 2.1 Gidiş dönüşün hâlleri

Yukarıdaki adımlar tek bir sonuç değil, bir sonuç kümesi üretmektedir. Kümenin
tamamı aşağıda verilmiştir, çünkü yalnızca geriye götüren durumu göstermek öteki
durumları saklamak olurdu.

Sonucu iki bağımsız seçim belirlemiştir. Birincisi **dal**, yani sekiz geçiş
eşlemesinden hangisinin gerçeklendiği: dördü parçacığı ileriye, dördü geriye
gönderir ve metrik ikisi arasında bir tercih yapmaz. İkincisi **mesafe**, yani
parçacığın öte tarafta ne kadar yol aldığı. Bunların üstünde bir de ara bölgenin
rejimi durur: bölge söndürücüyse gecikme kalınlıkla bir tavana oturur,
yayılımlıysa oturmaz.

Varış anı, kalkışa göre, her durumda

$$t_{\text{dönüş}} = 2\tau \;\pm\; s$$

biçimini alır. Buradaki işareti dal belirler, $s$'yi ise yolculuğun uzunluğu.
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
Parçacık öte tarafta hiç yürümese bile iki geçişin kendisi bir süre yer:
Bölüm 19'un yapılanmasında $2{,}434322$ birim.

Dördüncü satır ise bir iddia değil, taranmış bir sonuç taşımaktadır. İleri dal
iki yüz birim mesafeye kadar tarandı, ve hiçbir mesafede parçacık kalkıştan
önceki bir ana varmadı. Buradan da aynı sonuç çıkar: varış anının işaretini
yolculuğun uzunluğu değil, hangi geçişin gerçeklendiği belirler.

**Ara bölgenin rejimi tabloya ayrı bir satır olarak girmez.** Tablonun tamamı,
ara bölgenin parçacığa engel olduğu duruma aittir. Bölge engel olmaktan çıkınca
eşik mesafesi büyümez, çünkü sönüm katsayısı sıfırlanır ve kapalı form hiç
gecikme vermez. Yayılımlı rejimde değişen şey sürelerin büyüklüğü değil, bu
hesabın orada geçerli olup olmadığıdır.

**Tablonun kapsamadığı tek durum**, dalın yolculuk sırasında değişmesidir. Dal,
geçiş eşlemesinin bir özelliğidir ve yolculuk boyunca sabit kalır. Değişmesi
için parçacığın öte tarafta bir etkileşime girmesi gerekirdi; böyle bir
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

Kütle parametresi $\mu = (mc/\hbar)^2$ ile yazılır.

---

## 4. Geçişi yapan yapı

Eşiği geçiren superboost dönüşümü, birbirinden bağımsız iki parçanın çarpımına
ayrılır:

$$M(V) = D \cdot B(c^2/V), \qquad V > c$$

- $D$, hiçbir parametreye bağlı olmayan sabit bir matristir ve imza değişimini
 tek başına yapar. İki kez uygulanınca başa döner.
- $B(c^2/V)$, sıradan bir subluminal Lorentz boostudur ve hız bilgisini taşıyan
 tek parça odur.

Burada $V > c$ olduğundan $u = c^2/V$ değeri $c$'nin altında kalır, yani $B$
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
almıştır; orada konu, göreliliğin farklı formülasyonlarında klasik bir imza
değişimi türü olarak incelenir ve kozmolojik sabitle ilişkilendirilir. Buradaki
kullanım daha dardır: işaret çevrilmesi başlı başına bir konu olarak ele
alınmaz, yalnızca iki metrik arasındaki eşlemenin bir özelliği olarak ortaya
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
üç koşulu ayrı ayrı sağlar ve öte tarafta atılan birim adımı Bölge I'in saatinde
$-1{,}0000$'a gönderir.

**İki aileyi birbirinden ne ayırır.** Yalnızca Bölge I'in zaman eksenini ters
çevirmek ayırmaz, çünkü bu işlem determinantı negatife düşürür ve grup
kapanmasını bozar, yani adayı kümenin dışına atar. Yalnızca öte tarafın ayırt
edilmiş eksenini çevirmek de aynı sebeple ayırmaz. Ayıran işlem **ikisini
birlikte çevirmektir**:

$$S = \mathrm{diag}(-1, +1, +1, -1)$$

$S$ sekiz çözümü yine sekiz çözüme gönderir ve bu sırada her birinin işaretini
ters çevirir. Determinantı bire eşittir ve **her iki metriği de bozmadan
bırakır**, yani bir geçişten istenen bütün koşulları sağlar. Ters çevirdiği
eksen çifti de tam olarak geçişin birbirine eşlediği çifttir: Bölge I'in zamanı
ile Bölge II'nin tek uzay yönü.

**Sonuç.** Yukarıda yazılan $D$ bu sekizden biridir ve parçacığı **ileri
gönderen** ailede yer alır. Metnin sonucunu taşıyan hesaplar ise onun **geri
taşıyan** eşi olan $SD$ üzerinde yürümektedir. $S$ sekizliyi kendi üzerine
gönderdiğinden $SD$ de sekizden biri olur ve üç koşulu eksiksiz sağlar. Hangi
ailenin kullanılacağını bu metin karara bağlamıştır; karar üç koşuldan çıkmaz.
İki aile arasında seçim yapan hiçbir nicelik burada hesaplanmamıştır, ve
aileleri ayıran dönüşüm her iki metriği de bozmadan bıraktığından **seçimin
kaynağı geometri değildir**. Bölüm 9.4 aynı durumu başka bir yerde daha
göstermektedir: orada da metrik, ayrımın iki yakası arasında bir tercih
yapmamaktadır. Seçimi iki yerde de geometri dışında bir şey yapar.

### 4.1.1 Sözlük katsayısının ispatı

Çalışmanın merkezinde şu cümle durur: öte tarafın tek uzay ekseni, Bölge I'in
zaman eksenine karşılık gelir. Cümle bu hâliyle bırakılırsa "o eksende
ilerlemek zamanda yer değiştirmektir" ifadesi bir benzetmeden öteye geçmez.
Aşağıdaki iki sonuç ona sayı verir ve ikisi de sekiz geçişin **tamamı**
üzerinde ayrı ayrı denetlenmiştir.

**Katsayı tam olarak bire eşit çıkar.** Sekiz geçişin her birinde, zaman
koordinatını üreten satırın sıfırdan farklı **tek** bir girdisi bulunur; o girdi
öte tarafın ayırt edilmiş ekseni üzerinde durur ve büyüklüğü bire eşittir. Bu
yüzden o eksende alınan $s$ kadar yol, saatte **tam olarak** $s$ kadar kayma
üretir ve hiçbir katsayıyla ölçeklenmez. Diğer üç eksenin aynı yuvaya katkısı ise
**tam olarak sıfır** çıkar, yani tümüyle o üç eksenin içinde kalan bir hareket
saati hiç oynatmaz. Sınanan değerler bunu doğrular:
$0{,}5 \to 0{,}5000$, $1 \to 1{,}0000$, $2 \to 2{,}0000$, $4 \to 4{,}0000$,
$7{,}25 \to 7{,}2500$.

**Yer değiştirmeler toplanır.** Eşleme doğrusal olduğundan, önce $s_1$ sonra
$s_2$ kadar gitmek ile $s_1 + s_2$ kadar birden gitmek saatte aynı kaymayı
vermektedir. Bu eşitlik sekiz geçişin ve dokuz bacak çiftinin tamamında, artığı
$10^{-12}$ altında kalacak biçimde sağlanmıştır. Aynı doğrusallıktan bir sonuç
daha çıkar: bir bacak ile onun tersi **tam olarak** sadeleşir, yani kapalı bir
öte taraf gezisi saati başladığı yere döndürür.

**İki işaret aynı miktarı taşır.** İleri ve geri aileden birer geçiş alınıp
ikisine de aynı mesafe verildiğinde, ürettikleri kaymalar eşit büyüklükte ama
ters işaretli çıkar. Öyleyse sözlük saatin **ne kadar** oynadığını sabitler,
**hangi yöne** oynadığını sabitlemez.

**Bu bölümün tek başına haklı çıkarmadığı adım.** Yukarıdaki sonuçların hepsi
öte tarafta atılan adımlarla ilgilidir. Eşikten geçerken saçılma fazından okunan
gecikme ise bu adımlardan biri değildir. Dolayısıyla gecikmeyi öte taraftaki yer
değiştirmeyle toplama işlemi buradan çıkmaz, ayrı bir sonuç olarak kurulmalıdır.
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
 ve buradan $M^{-\mathsf{T}} = M$. Momentumlar koordinatlarla **aynı**
 matrisle taşınır.
2. **Aynı matrisler involüsyondur** ($M^2 = I$, Bölüm 4.1'in tarama
 koşullarından biri). Ortogonallikle birlikte bu $M = M^{-1} = M^{\mathsf{T}}$
 verir, yani $M$ **simetriktir**. O hâlde eşlenik değişkeni yöneten girdi,
 koordinatı yöneten girdinin devriğidir: iki katsayı aynı **sayıdır**,
 yalnızca aynı büyüklükte değildir.

Bu iki olgu, taramanın zaten dayattığı koşulların sonucudur; toplanabilirlik
için yeni bir varsayım eklenmemiştir.

Asıl adım bundan sonra gelir. Öte taraftaki yer değiştirme, fazın dışında
tutulup sonradan eklenmez; doğrudan fazın **içine** yerleştirilmiştir. Saçılma
fazı $\varphi(\omega)$ taşıyan ve öte tarafın ayırt edilmiş ekseni boyunca $s$
kadar ilerleyen tek bir genliğin toplam fazı

$$\Phi(\omega) \;=\; \varphi(\omega) + \kappa(\omega)\, s,$$

ve durağan faz koşulu çıkan paketin anını

$$t \;=\; \frac{\mathrm{d}\varphi}{\mathrm{d}\omega}
 \;+\; s\,\frac{\mathrm{d}\kappa}{\mathrm{d}\omega}$$

olarak verir. Böylece toplam, iki ayrı hesabın arasına elle konan bir varsayım
olmaktan çıkıp **tek** bir hesaptan okunan bir sonuca dönüşür. İkinci terimin
önündeki çarpan da bir seçim değil, hesaplanabilen bir türev olur.

Söz konusu türev de hesaplanmıştır. Eşlenik değişkeni üreten satırın sıfırdan
farklı tek bir girdisi bulunduğundan $\kappa$ yalnızca frekansla orantılı kalır,
ve buradan

$$\left|\frac{\mathrm{d}\kappa}{\mathrm{d}\omega}\right| = 1$$

eşitliği sekiz geçişin tamamında **tam olarak** sağlanmaktadır. Bu makalede
kullanılan eşleme için değer $+1$ çıkar, ve işaret her dalda o dalın kendi zaman
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
limiti değildir; eşlemenin tam bir özelliğidir ve sonlu kütlede de geçerli kalır.
Ayrım önemlidir, çünkü bir asimptotik yaklaşım sonucu yalnızca yaklaşık kılardı.

### 4.1.3 Dönüş anının işareti

Bölüm 4.1.2 toplamı meşru kıldığına göre, iki terimin **yarışması** anlamlı bir
soru hâline gelir. Terimlerin kalınlığa bağımlılıkları farklıdır: bariyer
rejiminde faz gecikmesi kalınlıkla **doyar**, öte taraf yer değiştirmesi ise
doymaz ve $s$ ile sınırsız büyür. Doyan gecikme bu yüzden bir **eşik mesafesi**
tanımlar; öte tarafta bundan daha uzağa gidilirse ikinci terim birinciyi yener.

Öklidyen bir ara bölgede, $d = 8$ ve $c = \mu = 1$ için hesaplanan gecikme
$2{,}565988$ çıkmıştır. Eşik mesafesi de tam olarak bu sayıya eşittir, çünkü geri
taşıyan dalda varış anı orada sıfırlanır. Hesaplanan varış anları şöyledir:

| Öte taraf mesafesi | Varış anı | Girişe göre |
| ------------------ | ----------- | ----------- |
| $2$ | $+0{,}5660$ | sonra |
| $4$ | $-1{,}4340$ | **önce** |
| $8$ | $-5{,}4340$ | **önce** |

İleri taşıyan dalda ise incelenen hiçbir mesafede bu olmaz. Yayılımlı (Kleinyen)
rejimde de olmaz, çünkü orada gecikme doymaz: $d = 8$ için değeri $97{,}0543$'e
çıkar, yani incelenen mesafelerin çok ötesinde kalır ve eşik mesafesine hiç
ulaşılamaz.

Bu sonucun gerçekleşme olasılığı ise küçük kalmaktadır. Eşik mesafesine
ulaşabilen yapılanmalar kalın bariyerlerdir, ve kalın bir bariyer neredeyse
hiçbir şey geçirmez: geçirgenlik $d = 2$ için $3{,}67 \times 10^{-3}$, $d = 4$
için $3{,}60 \times 10^{-6}$, $d = 8$ için $3{,}46 \times 10^{-12}$ çıkar. Yani
geçiş hem mümkün kalır hem de son derece seyrek gerçekleşir. Buradaki sonuç
neyin olabileceğini söyler, ne kadarının olacağını söylemez.

Buradaki toplama işlemi ayrıca bağımsız bir türetmeyle karşılaştırılmıştır.
Bölüm 4.1.2 varış anını tek bir genlikten okumakta, ve iki yol üç ayrı mesafede
karşılaştırıldığında her üçünde de aynı sayı çıkmıştır. Dolayısıyla bu
bölümdeki toplam, yerine geçebilecek türetmeyle uyumlu kalmıştır.

**Erken varmak ile öte tarafta geri yürümek aynı şey değildir.** Bu ayrımı burada
yapmak gerekir. Metnin başka bir yerinde, öte tarafın tek uzay ekseninin
**yönlendirilebildiği** hesaptan çıkmaktadır. Bir cisim o eksende geri dönemez:
ne kadar ilerleyeceğini seçebilir, hangi yöne ilerleyeceğini seçemez.
Yukarıdaki erken varış bu sonuçla çelişmez, çünkü varış anının işareti cismin
öte tarafta hangi yöne yürüdüğünden değil, **hangi geçiş eşlemesinin
kullanıldığından** doğar. Bölüm 4.1'in sekiz adayından dördü aynı yer
değiştirmeyi daha geç bir ana, dördü daha erken bir ana taşır, ve iki aileyi
birbirine bağlayan dönüşüm her iki metriği de bozmadan bırakır. Cisim öte
tarafta hep tek yönde yürür; o yürüyüşün Bölge I'de hangi zaman yönüne düştüğünü
eşleme belirlemektedir. Dolayısıyla bu kurguda "geri yürümek" diye bir işlem
bulunmaz, ve zaten gerekmez.

### 4.1.4 Çerçeve değişimi

Sözlük lineer olduğundan, tek eksende kalan bir yolculuğun saatte ürettiği kayma
yalnızca **net** yol miktarına bağlı kalır; gidilen yol ile eşit uzunlukta bir
dönüş tam olarak birbirini götürür (Bölüm 4.1.1). Yolculuğun iki bacağı arasında
**çerçeve** değişirse soru başkalaşır, çünkü katsayıyı bir matris verir ve o
matris çerçeve değişimiyle bileşke alır. Öte tarafın metriğini bozmadan bırakan
iki tür çerçeve değişimi bulunur, ve ikisi birbirinden farklı davranır.

**Aynı işaretli eksenler arasındaki dönmeler hiçbir şey bırakmaz.** Üç aynı
işaretli ekseni birbirine döndüren bir dönme, ayırt edilmiş ekseni **yerinde
bırakır** ve dolayısıyla katsayıyı veren matris girdisine dokunmaz. Katsayı
incelenen bütün açılarda $1$ olarak kalır. Net yer değiştirmesi sıfır olan bir
rota, ne kadar dolambaçlı olursa olsun saati başladığı yere geri getirir, ve bu
sekiz geçişin hepsinde doğrulanmıştır. Yani **öte tarafta dolaşmak tek başına
hiçbir şey kazandırmaz**. Bu olumsuz bir sonuçtur ve dolaşmanın kendiliğinden
zaman kazandıracağı beklentisini ortadan kaldırır.

**Ayırt edilmiş ekseni karıştıran hiperbolik dönme ise iz bırakır.** Ayırt
edilmiş ekseni aynı işaretli bir eksenle karıştıran dönüşüm de öte tarafın
metriğini bozmaz, ancak o ekseni yerinde bırakmaz: katsayıyı, dönüşümün
hızlılığının hiperbolik kosinüsüyle çarpar. İki bacağı böyle bir dönüşümle
ayrılan kapalı bir rota artık başladığı yere dönmez, geriye bir artık bırakır,
ve o artık hızlılık büyüdükçe sınırsız büyür. Katsayı hızlılığın
hiperbolik kosinüsüdür: $0{,}5$'te $1{,}127626$, $1$'de $1{,}543081$, $2$'de
$3{,}762196$. Buradan çıkan kalıntılar, $3$ birimlik gidiş dönüş için:
$-0{,}382878$, $-1{,}629242$, $-8{,}286587$. Kalıntının işareti negatiftir, yani
dönüş düz rotaya göre saati **geriye** taşır.

**Bu artığın ne olduğu ve neye mal olduğu.** Yukarıdaki hiperbolik kosinüs, Bölge
I'de sıradan bir Lorentz dönüşümünün bir zaman aralığına uyguladığı çarpanın
aynısıdır. Dolayısıyla artık, bilinen zaman genleşmesinin öte taraftan görünen
hâli olur, yeni ve bağımsız bir etki değil. Hesap bunun bedelini de verir:
sıfırdan farklı bir hızlılıkla bileşke alınan geçiş metrik bağıntısını korur,
yani kabul edilebilir ailenin dışına çıkmaz, ancak **iki kez uygulanınca başa
dönme özelliğini kaybeder**. Bölüm 4.1'in tarama koşullarından biri olan bu
özellik böyle bir bileşkede ortadan kalkar.

### 4.1.5 Yer değiştirmenin bedeli

Öte tarafta yol almanın iki ayrı karşılığı vardır ve ikisi birbirinden farklı
davranır: yolculuğun ne olasılıkla gerçekleşeceğini veren genlik ağırlığı, ve
yolculuk için harcanması gereken enerji.

**Genlik ağırlığı.** Parçacık kalkıştan $\Delta$ kadar önce dönecekse, öte
tarafta aldığı yol doymuş geçiş gecikmesini $\Delta$ kadar aşmalıdır.
Gecikmeyi yolun uzunluğu değil ara bölge sabitlediğinden, gereken yol istenen
kaymayla **birebir** büyür: $\Delta = 0$ için $2{,}565988$, $\Delta = 1000$ için
$1002{,}565988$ birim. Geçişin genlik ağırlığını ise yalnızca ara bölge belirler.
Ağırlık kalınlık $2$'de $3{,}67 \times 10^{-3}$, kalınlık $8$'de
$3{,}46 \times 10^{-12}$ çıkar, yani bölgeye gerçekten duyarlı bir niceliktir.
Buna karşın **yolun uzunluğu, ağırlığı veren ifadede hiç geçmez**. Dolayısıyla bu
modelde ne kadar uzun bir yolculuk yapılırsa yapılsın, ağırlık en kısa
yolculuktakiyle aynı kalır.

Bu durum bir serbestlik değildir. Öte tarafta alınan yol genliğe hiç girmiyorsa,
modelde bir **eksik** var demektir. Yolculuğun ağırlığa ne kattığını
hesaplayabilmek için genliğin önce yol uzunluğuna bağlı bir değişken kazanması
gerekir. Yukarıdaki sayılar bundan fazlasını söylemez.

**Düz bir yolun enerjisi.** Öte tarafın geometrisi, ayırt edilmiş eksen boyunca
kaydırma altında değişmez. Bu yüzden o eksene eşlenik nicelik korunur ve düz bir
yolun uzunluğu hiç enerji istemez. Aynı işaretli eksenler arasındaki dönmeler de
enerji istemez. Ancak Bölüm 4.1.4'e göre bu iki işlemin hiçbiri saatte bir kayma
üretmez.

**Çerçeve değiştirmenin enerjisi.** Saatte kayma üreten tek işlem hiperbolik
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
özelliği gibi ele alır ve orada sorulan soru gecikmenin **doyup doymadığıdır**;
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
bulunur. Metinde kullanılan yapılanma bu en iyi değerin **yüzde birkaçı**
içinde kalmaktadır, yani iki payı yeniden dengelemek kayda değer bir kazanç
getirmez.

**İkincisi: toplam enerjiyi yükseltmek güçlü bir etki yapar.** Payların en iyi
bölüşümünde parçacığın öte tarafta almak zorunda kaldığı yol, gidiş dönüş
boyunca şu değerlere iner:

| Toplam enerji | Gereken öte taraf mesafesi |
| ------------- | -------------------------- |
| $9$ | $2{,}434322$ |
| $50$ | $0{,}989546$ |
| $500$ | $0{,}310148$ |
| $5000$ | $0{,}097990$ |

Mesafe **sınırsız** küçülmektedir. Yani öte tarafta alınması gereken yol sabit
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
İkincisi, küçültülen niceliğin metnin başka yerlerde karşılaştırdığı nicelikle
aynı olup olmadığı. Referans yapılanma $1{,}462864$ vermektedir, yani
Bölüm 13.4'ün doymuş değerinin tam olarak aynısını. Bu ikinci denetim önemsiz
değildir: tek geçiş ile gidiş dönüşü birbirine karıştırmak bu çalışmada iki kez
ikilik bir çarpan hatasına yol açmıştır.

**Bunun metne kattığı.** Bölüm 4.1.5'in ağırlık tablosundaki sayı, yani $d = 8$
için $3{,}46 \times 10^{-12}$, tek bir kalınlıkta okunmuş bir değerdir ve bir üst
sınır değildir. Aynı doyum derinliğinde daha yüksek enerjiyle çalışılırsa hem
gereken mesafe hem gereken kalınlık düşer, genlik ise yerinde kalır. Dolayısıyla
"mümkün, ama ağırlığı $10^{-12}$" cümlesi bir yasak bildirmez; yalnızca hangi
çalışma noktasının seçildiğini bildirir.

**Üçünün birlikte değerlendirilmesi, bir sınırlama olarak.** Üç nicelikten
ikisi zayıf kalır: genlik ağırlığı yolun uzunluğunu hiç görmez, ve düz bir yol
enerji istemez. Üçüncüsü gerçek bir enerji artışı getirir, ancak tanıdık bir
niceliktir: sıradan bir Lorentz dönüşümünün bir zaman aralığına uyguladığı
çarpanın aynısı. Yani bu üçlünün içinde bu kurguya özgü hiçbir nicelik
bulunmamaktadır. Modelin hesaplayamadığı şey yolculuğun kendisinin katkısıdır,
ve bunun nedeni yapısaldır: genliği veren ifadedeki değişkenlerin hiçbiri
parçacığın öte tarafta ne kadar gittiğine bağlı değildir.

**Literatürdeki en yakın sonuç ve ondan farkı.** Engelin biçimi ile parçacığın
enerjisi ayarlanarak tünellemenin güçlendirilebildiği bilinmektedir; belirli
koşullarda geçirgenlik, saydam olmayan bir engelde bile üstel olarak küçük
kalmaz. Ancak o mekanizma **geçme olasılığını** artırır ve tek boyutlu olmayan
bir engel ister. Buradaki hesap ise geçirgenliği değil, **genlik sabit tutulurken
doymuş gecikmeyi** küçültmektedir, ve kullanılan engel tek boyutludur. Sönüm
katsayısı ile kalınlığın çarpımı sabit kaldığından genlik zaten yerinden
kıpırdamaz. İki sonuç ne aynı niceliği ne de aynı kurulumu ele aldığından,
buradaki hesap o mekanizmanın yeniden bulunması sayılmaz. Bu bölüm ona yalnızca
kendi yerini göstermek için değinmektedir.

### 4.1.7 Grup kapalılığının bozulduğu katman

Doğrulanan iki olgu:

- $D^2 = I$, dolayısıyla $\langle D \rangle = \mathbb{Z}_2$, **kapalı**.
- $M(V)^2 \neq I$, birleşik dönüşüm kapalı **değil**. ($V = 1{,}5c$, $2c$ ve
 $10c$ için ayrı ayrı gösterildi.)

Kapanma sorunu $D$'den değil, $B$ katmanından kaynaklanır. $D \cdot B$'yi tek
bir dönüşüm olarak ele almak kapanmayı bozar; ayrıştırıldığında iki parça da
düzgündür: $D$ bir $\mathbb{Z}_2$ ayrık simetrisi, $B$ ise $SO(1,3)$ içindedir.

Buradaki yapı $\langle D \rangle \ltimes SO(1,3)$ biçiminde bir yarı-doğrudan
çarpımdır. Kapanmanın bozulması, $D B D^{-1}$ konjugasyonunun boost tipini
korumamasından çıkar; yön-bağımlı genleşmeler bu konjugasyonun ürünüdür.

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
dolayısıyla $SO(3)$ elemanı değildir. Bölüm 16.7 bunu hesaplamıştır.

Bu bölüm tek bir şey ekler: grup kapanmasındaki bozulma hangi parçadan geliyor,
onu ayırır. $D$ kapalı bir grup üretir, $B$ üretmez. [3] sorunu bu
biçimde ortaya koymaz, çünkü o çalışma baştan kapalı bir grup kurmaktadır.

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
teker teker çevrilir. Yol $(1,3)$ imzasından $(2,2)$ imzasına, oradan da $(3,1)$
imzasına gider; her ayakta yalnızca tek bir öz değer sıfırdan geçtiğinden rank da
yalnızca bir düşer. Aşağıdaki adaylardan ikincisi tam olarak bu yolun durağıdır.

**Kleinian, $(2,2)$.** Bu ara bölge iki zaman ve iki uzay ekseni taşır, çünkü
enine yönlerden yalnızca biri karakter değiştirmiştir. Yukarıda anılan kademeli
yol da burada durur.

**Öklid, $(4,0)$.** Burada enine yönlerin hepsi karakter değiştirmiştir ve
bölgede hiç zaman yönü kalmamıştır. İmza değişimi literatürünün büyük bölümü tam
olarak bu geçişi ele almaktadır.

**Dejenere katman.** Son aday, metriğin tersi bulunmayan bir tabakadır. Öteki üç
adaydan farklı olarak burada bir imzadan söz edilemez, çünkü yayılımı yöneten
operatörün kendisi tanımsız kalır.

### 5.2 İçerideki modun davranışı

Enine dalga sayısının yönler arasında eşit paylaşıldığı durumda, ara bölge
içindeki normal dalga sayısının karesi

$$q_{\text{iç}}^2 = \frac{\omega^2}{c^2} - \left(1 + \frac{2n}{3}\right)k_T^2 - \mu$$

olur; burada $n$ karakter değiştiren enine yön sayısıdır. İfade dışarıdaki
$\kappa^2 = \omega^2/c^2 - k_T^2 - \mu$ değerinden, çevrilen her yönün üçte iki
ağırlıkla düşülmesiyle çıkar ve Bölüm 18.7'nin $\beta^2$ tanımıyla
$q_{\text{iç}}^2 = -\beta^2$ bağıntısıyla aynıdır.

**İç mod frekansa bakar.** Bir ara bölgenin engel olup olmadığı yalnızca tipine
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
$q_{\text{iç}}^2 = -3$ ile söndürücü çıkar. Frekans seçimi burada kayda geçer,
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
karışımını hesaplar; bu, saçılma dilinde tam olarak bir geçiş katsayısıdır.
Oradaki merkezi sonuç, karışımın **yalnızca Öklid bölgelerinin toplam konformal
genişliğine** bağlı olduğu, metriğin ayrıntılı biçimine bağlı olmadığıdır. [22]
aynı hesabı spin-$1/2$ için dener ve çözüm uzayında korunan bir iç çarpım
bulunmadığını gösterir.

İki sonuç birbirini yalanlamaz, aynı yapının iki farklı kesitidir:

| | [20], [21] | Buradaki tablo |
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

Buradaki tablonun ona eklediği şey **sonlu kalınlıktır**. [27] tek bir imza
değişimi yüzeyinden geçişi ele almaktadır. Buradaki hesapta ise ara bölgenin iki yüzü
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
sıfırlanmayan bir dış eğrilik gerilim tensöründe bir **madde tabakasına**
karşılık gelir. Kalınlık sıfıra giderken tabaka noktasal bir terime iner. Sonlu
kalınlıkta ise geçiş bölgesinin içine yayılmış bir gerilim olarak durur
(Bölüm 6.2). Zayıf koşulun bedeli budur: parçacığın geçmesine izin veren seçim,
aynı anda yüzeye bir madde tabakası koyar. Böyle bir tabakanın genel
formülasyonunu [17] vermiştir; o çalışma, imzanın değiştiği yüzeyin zamansal
olamaması da dahil olmak üzere konuyu tam olarak ele alır. Buradaki hesap onun
bu geometrideki sayısal karşılığını çıkarmaktadır.

Tabakanın gücü, imzanın döndüğü mesafeyle ters orantılı gitmektedir. Hesaplanan
değerler:

| Tip | $d = 0{,}1$ | $d = 1$ | $d = 4$ |
| -------- | ----------- | ------- | -------- |
| Kleinian | $10{,}0$ | $1{,}0$ | $0{,}25$ |
| Öklid | $30{,}0$ | $3{,}0$ | $0{,}75$ |

Kalınlık on kat arttığında katman gücü on kata iner. Sıfır kalınlık limitinde
katman sınırsız büyür.

**Buradan çıkan gerilim.** İki eğilim birbirine terstir:

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
enerji koşullarının orada zamansal duruma göre daraldığını gösterir. Aşağıdaki
hesabın hangi çerçevede okunması gerektiğini o sonuç belirlemektedir.

**Hesap.** Katmanın taşıdığı yüzey enerji yoğunluğu ve basıncı, geçiş profili
ailesinin her üyesi için ayrı ayrı değerlendirilmiştir ($d = 1$):

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

**Sonuç ve bunun modele maliyeti.** Zayıf eklem koşulunun bedeli, daha önce
yazıldığı gibi yalnızca "bir madde katmanı" değildir. Bedel, **baskın enerji
koşulunu ihlal eden** bir katmandır ve bu, daha iyi bir madde seçilerek
onarılamaz. Geriye kalan tek çıkış yolu, dönüm noktasında durağan profildir; o
da genel bir yapılanma değil, ince ayarlanmış bir özel durumdur.

### 5.7 Oran koşulu

Zayıf seçime karşı yöneltilmiş en güçlü itiraz felsefi değildir ve burada
felsefeyle değil, hesapla karşılanmaktadır. Alan denklemleri yüzey boyunca
yazıldığında, **normal türev çarpı delta bölü lapse** biçiminde bir terim doğar.
Lapse dönüm noktasında sıfıra gittiğinden bu terim sıfır bölü sıfır biçimini
alır, ve **ilan ederek sıfır sayılamaz**. Terim ancak pay paydadan daha hızlı
sıfırlanırsa düşer, ve bunu ayrı bir hesap göstermelidir. Gösterilirse terim düşer ve zayıf seçim
ayakta kalır; gösterilemezse terim kalır ve denklemler ancak normal türev
tümüyle sıfırlanarak, yani güçlü koşul benimsenerek tutarlı olur.

Böylece anlaşmazlık tek bir hesaplanabilir üstele inmektedir. Burada kullanılan metrik
ailesinde lapse, işaret değiştiren metrik bileşeninin karekökü gibi gider;
normal türev ise katman için zaten hesaplanmış dış eğriliktir. Oran, dönüm
noktasına doğru izlenmiştir:

| Profil | Oranın uzaklıkla üsteli | Sonuç |
| --------------- | ----------------------- | ------------------ |
| Doğrusal | $-0{,}500$ | terim ayakta kalır |
| Dönümde durağan | $+0{,}497$ | terim düşer |
| Tanh basamağı | $-0{,}500$ | terim ayakta kalır |

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
teğet bloğun normal türevinin lapse'a bölümüne bakar. Bağımsız iki ayardır ve
ikisi birden sağlanabilir. Literatürün ikisini bir arada, aralarında bir gerilim
olduğunu belirtmeden dayatmasının sebebi budur.

Dejenere bileşenin sıfırlanma mertebesi $a$, teğet eğimin sıfırlanma mertebesi
$b$ ile gösterilir. Burada $q$ harfi kullanılmaz, çünkü $q$ metnin geri kalanında
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

Bölüm 5.7'deki aile bu formülün $b = a - 1$ dilimidir, çünkü orada dış eğrilik
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

Bu, literatürün zaten taşıdığı güçlü ile zayıf ayrımıdır. Buradaki yol ona iyi
tanımlı bir Ricci tensörü yerine bir hız üzerinden yaklaşmaktadır. **Yeni bir
engel iddiası bulunmamaktadır.** Bölüm 5.7'nin sonucuna iliştirilmiş özgünlük
payı bu nedenle geri çekilmiştir. Ayakta kalan katkı engelin kendisi değil,
üstelin iki parametreli kapalı biçimidir.

Literatürde dejenere bileşenin sıfırlanma hızını tek bir parametreyle
sınıflandıran çalışmalar bulunmaktadır. Teğet bloğun mertebesini ikinci bir
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

İki bölgeyi birbirine bağlayan $\Sigma$ yüzeyi iki eklem koşulu taşır:

1. Alan sürekli: $\psi_I|_\Sigma = \psi_{II}|_\Sigma$
2. Konjuge momentum sürekli: $\pi_I|_\Sigma = \pi_{II}|_\Sigma$

Bu iki koşuldan ikincisi beklenmedik bir sonuç doğurur. Yüzeyin normali Bölge
I'de zaman-benzeri, Bölge II'de ise uzay-benzeri olduğundan $\pi_{II} = -\pi_I$
çıkar, ve ikinci koşul ancak

$$\pi|_\Sigma = 0$$

olursa sağlanabilir. Bu eşitliğe **düğüm koşulu** denir ve anlamı şudur: eşikte
akı sıfırlanır.

**Sonuç:** $\Sigma$ geçirgen değil, **yansıtıcıdır**. Kütleli madde eşikten
geçemez, tam yansır.

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
diye adlandırmanın retorik olduğunu söyler.

Yukarıdaki $\pi|_\Sigma = 0$ sonucu **güçlü** koşuldur. Aynı sonucu başka bir
yoldan [4] daha önce elde eder. Orada Klein-Gordon alanı imza değiştiren bir
arka planda ele alınır. Eklem koşulu, alan denklemlerindeki Dirac dağılımının
katsayısı olarak $\phi' \delta = 0$ biçiminde **türetilir**, yani denklemleri
anlamlı kılmak için varsayılmaz. Buradaki türetim
Lagrangian'dan gider ve aynı yere varır.

Lagrangian yolunun kendisi de öncesiz değildir. [21] kütlesiz skaler alanı iki
boyutta imza değiştiren bir metrik üzerinde ele alır. Eklem koşulunu iki ayrı
yoldan sabitler: uzaysal olarak homojen hâlde momentumun korunmasını istemek, ve
doğal bir Lagrangian'dan varyasyon almak. İkisi aynı yere varır ve elde edilen
çözümlerin dağılımsal dalga denklemini her yerde sağladığı gösterilmiştir. Buradaki
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

Bölge II'de iki genlik birden tutulur, çünkü orada zaman sıralaması olmadığı
için "dışarı giden dalga" koşulu **tanımlanamaz**.

İlk gözlem şudur: normal doğrultudaki indirgenmiş denklem iki tarafta da aynı
kalır,

$$\frac{d^2}{d\xi^2} + \kappa^2 = 0, \qquad \kappa^2 = c^2(k_T^2 + \mu)$$

yani dalga yüzeye geldiğinde ortam değişmiş gibi bir **basamakla karşılaşmaz**.
Geçirgenliği belirleyen tek şey, momentum eşleşmesinin işaretidir.

Eklem koşulları $1 + R = T_+ + T_-$ ve $1 - R = s\,(T_+ - T_-)$ olur; burada
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
Zayıf koşul geçişe izin verir, ancak ne kadarının geçtiğini söylemez. Bölge
II'de dışarı giden dalgayı seçecek bir koşul kurulamadığından $R$ serbest kalır.
Yani zayıf koşul "geçiş vardır" demekten çok, "bu problem iyi konumlanmamıştır"
demektedir, ve bu da yukarıdaki sonuçla tutarlı kalır.

Tablodaki dört durumdan üçü yansıtmaktadır. Bunların içinde en dikkate değeri
[9]'un öz-eşlenik genişlemelerden çıkardığı **Dirichlet** koşuludur: buradaki
Neumann koşulunun tersi olmasına rağmen aynı yere varır ve orada da Minkowski
bölgesi Kleinian bölgeden kopar. Öyleyse "eşikten akı geçmez" sonucu Neumann ile
Dirichlet arasındaki tercihe duyarlı **değildir**, ve duyarlı olduğu tek şey
güçlü ile zayıf arasındaki tercih olarak kalır.

Buna karşılık [9] bir uyarı da içerir: kuantum alanların varlığı bu duvarları
**kararsız** kılar, Kleinian bölge ya çöker ya sınırsız genişler. Burada bu
soruya girilmemiştir ve açık bırakılmaktadır.

### 6.2 Seçimin yerçekimi görünümü

Yukarıdaki tercih madde tarafında, konjuge momentum üzerinden yapılmıştı. Aynı
tercih geometri tarafında yeniden belirir ve orada geçiş yüzeyinin **dış
eğriliği** üzerine konan bir koşula dönüşür: güçlü koşul onun yüzeyde sıfırlanmasını, zayıf
koşul yalnızca sürekli olmasını ister [5]. [6]'nın genelleştirilmiş Lanczos
denklemine göre gerilim tensöründe dağılımsal bir terim, yani bir **yüzey
katmanı**, tam olarak dış eğrilik sürekli olduğunda yoktur.

Bunu somutlaştırmak için Bölüm 5.1'deki kademeli yolun ilk ayağı bir
koordinatın fonksiyonu yapılır:

$$g(\xi) = \mathrm{diag}\big(1,\, -\cos\lambda(\xi),\, -1,\, -1\big),
 \qquad \xi \in [-1, 1]$$

İmza, $\lambda$'nın $\pi/2$'yi geçtiği yerde değişir. Sabit $\xi$ yüzeylerinin
dış eğriliğinin tek önemsiz bileşeni

$$K = \tfrac{1}{2}\,\frac{d g_{11}}{d\xi}
 = \tfrac{1}{2}\,\lambda'(\xi)\,\sin\lambda(\xi)$$

olur ve geçiş noktasında $\sin\lambda = 1$ olduğundan orada $K = \lambda'/2$'ye
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
bakar ve sonuçları birbirini yalanlamaz. Burada geçiş sonlu bir aralığa yayılır
ve profil düzgündür; dış eğrilik süreklidir, dolayısıyla delta terimi yoktur.
Bölüm 5.4 ise geçişi kalınlığı $d$ olan bir katmana sıkıştırır ve gücün
$1/d$ ile gittiğini bulur; o güç, buradaki sürekli eğriliğin sıfır kalınlık
limitinde aldığı biçimdir. Dolayısıyla "katman" sözcüğü Bölüm 5.4 ile Bölüm
5.6'da dağılımsal bir terimi değil, geçiş bölgesinin sonlu kalınlıkta taşıdığı
etkin gerilimi adlandırır. Bölüm 5.6'nın enerji koşulu hükmü o etkin gerilime bakmaktadır ve sonlu
kalınlıkta da ayakta kalır. Sonlu kalınlıkta kaybolan tek şey, terimin noktasal
olmasıdır.

Bu, modelin yerçekimi tarafına atılmış ilk adımdır ve sınırlıdır: Einstein
denklemleri çözülmemiş, yalnızca eklem koşulunun geometrik karşılığı
hesaplanmıştır. [6] ve [8]'in uyarısı burada da geçerli kalır: imza değişiminde
kanonik bir alan denklemi kümesi yoktur. Hangi formülasyonun kullanıldığını
söylemek gerekir. Burada kullanılan [6]'nın formülasyonudur, yani dış eğriliğin
süreksizliğini gerilim tensörünün dağılımsal terimine bağlayan formülasyon.

Bu formülasyonun pratik aracı [7]'dedir. Öz-zaman koordinat olarak alındığında,
imza değişimi boyunca düzgün genelleştirilmiş ortonormal çatılar tanımlanabilir.
Bu da hem Einstein denklemlerinin varyasyonel türetimini hem dağılım teorisini
kullanılabilir kılar; ikisi de sabit imzadaki hâllerinin doğrudan genellemesi
olur. Modelin yerçekimi tarafına daha ileri götürülmesi istenirse başlangıç
noktası burasıdır.

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
I'de uzay-benzeri, Bölge II'de ise zaman-benzeri çıkar. Dolayısıyla Bölge II'nin
zaman-benzeri yönleri kesin olarak daha fazladır.

**Ayrımın önemi.** Eşikte bir eğriyi durduran nedensel bir engel **yoktur**;
teğeti karakterini koruyarak geçer. Bölüm 6.1'in yasakladığı şey akıdır ve akı
eğrinin teğetinin değil, alanın ve eklem koşulunun bir özelliğidir. Dolayısıyla
şu iki ifade birbiriyle çelişmez:

- Yüzeyden geçen geometrik eğriler vardır.
- Yüzeyden akı geçmez.

Bu ayrım, Bölüm 9.4'te değinilen ilmek teoremiyle bu modelin eşik sonucunun
aynı anda doğru olabilmesinin nedenidir: o teorem geometrik eğriler hakkındadır,
buradaki sonuç alan akısı hakkındadır.

## 8. Sonlu kalınlıkta dilimden geçiş

Bölüm 6.1 öte tarafı **sınırsız** kabul etmektedir. Sonlu kalınlıkta bir dilim ayrı
bir problemdir ve sonucu farklıdır.

Bu ayrımı [15] kurmuştur ve o çalışma bu bölümün öncülüdür. Orada
Klein-Gordon parçacıklarının Lorentzian imzadan Kleinian imzaya geçişi
incelenir, düzlemsel bir sınırda parçacık akısı için **ayna davranışı** bulunur,
ve ardından sonlu kalınlıkta bir çift eklem ele alınarak **tünelleme olasılığı**
gösterilmiştir. Dikkat çekici olan, oradaki geçişin $(-,+,+,+) \to (-,+,+,-)$
olması, yani Bölüm 5.1'deki kademeli yolun tam olarak birinci ayağıdır.

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

Bir ikinci koşul daha vardır: iç modun sönümlü olup olmadığını gelen alanın mod
içeriği belirler. İşaret değiştiren yön az dalga sayısı taşıyorsa iç mod
yayılmaya devam eder ve geçirgenlik bastırılmak yerine **salınır**, rezonansta
bire ulaşır. Yani engeli yaratan imza değişiminin kendisi değil, gelen alanın
hangi modlardan oluştuğudur.

Bu, Bölüm 6.1'in sonucunu geçersiz kılmaz ama kapsamını daraltır: eşiğin
yansıtıcı olması, öte tarafın sınırsız olduğu ve gelen modun uygun içerikte
olduğu durum için geçerli kalır.

### 8.1 Geçirgenliği belirleyen toplam

Yukarıdaki hesap sönüm katsayısını dilim boyunca sabit almaktadır. Gerçek bir
geçişte katsayı konuma bağlıdır ve o zaman şu sorulur: geçen şeyi profilin
**biçimi** mi belirler, yoksa yalnızca **integrali** mi?

Beş profil, integralleri eşit tutulacak biçimde karşılaştırılır: düz, üçgen,
yarım sinüs, plato ve çarpık. Biçim farkı gerçektir ve hesaba girer. Kenara yakın
bölgede biçimlendirilmiş bir profil, düz profilin dörtte birinden az sönüm
taşır; merkezde ise onu belirgin biçimde aşar. Bir uyarı da şudur: üçgen profil
ile düz profil bir iç noktada tam olarak kesişir, dolayısıyla yalnızca tek bir
noktaya bakan bir karşılaştırma aralarında hiçbir fark bulamazdı.

Buna karşın geçirgenlik üsteli, biçimden bağımsız olarak toplamın belirlediği
bir değere yakınsar:

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

## 9. Öte tarafta zaman ve mekân

Bu bölüm üç soruyu sırayla cevaplar: öte tarafta hangi nicelikler korunur, hangi
roller yer değiştirir, ve "yolculuk" sözcüğü orada ne anlama gelir. Sonucu
taşıyan adım, orada zamanın bir yönünün bulunmamasıdır.

### 9.1 Noether yükleri

$L'$ dört koordinatın hiçbirine açıkça bağlı değildir, dolayısıyla dört öteleme
simetrisi vardır:

- üç "enerji" bileşeni ($t_1, t_2, t_3$ ötelemeleri),
- tek "momentum" ($r$ ötelemesi).

$L'$ ayrıca üç zaman ekseninde $O(3)$ altında değişmezdir; buradan üç korunan
"zamansal açı momentumu" çıkar, Bölge I'in uzaysal açı momentumunun aynası.

### 9.2 Rollerin tersine dönmesi

Aşağıdaki tablo Bölüm 10.1'in sözlüğünün rol tarafıdır; koordinat karşılıkları
orada, rollerin karşılaştırması burada durmaktadır.

| | Bölge I | Bölge II |
| ---------------------- | ---------------- | ----------------------------- |
| Serbest hareket | Uzayda, üç yönde | Üç zamanda serbestçe |
| Tek yönlü zorunluluk | Zamanda | Tek uzay ekseninde |
| $O(3)$ dönme simetrisi | Uzaysal | Zamansal |
| Temel nesne | Yörünge (eğri) | Cephe (üç boyutlu hiperyüzey) |

### 9.3 Ayrım ve zorunluluk

Bölge II'de zamanın oku **yoktur**. Ok, ilgili boyutun **tek** olmasının
sonucudur; üç boyutlu olan eksen kümesi uzay gibi davranır ve yön ayrımı ortadan
kalkar. Buna karşılık orada bir **uzay ayrımı** vardır, çünkü tek eksen uzay
eksenidir.

Bu ifadenin iki kez daraltılması gerekir ve daraltma bu çalışmanın duruşunun
tamamıdır.

**Birincisi.** Boyut sayısından çıkan şey **ayrımın varlığıdır**, ayrımın iki
yakasından hangisinin gelecek olduğu değil. Bir koridorun iki ucu olması, hangi
ucun ileri olduğunu söylemez.

**İkincisi.** Ayrım metrikte durur; **etiket durmaz**. Denklemler bir yönü
tercih etmez. Zamanda ileri giden her çözümün geriye giden bir eşi vardır ve
ikisi de aynı denklemi sağlar. Bir yönün seçilmesi için denkleme bir şey
eklenmesi gerekirdi ve eklenmemiştir.

Buradan çıkan sonuç şudur: **bu metin zamanın zorunlu bir akışı olduğunu
varsaymaz.** Bölge I'de de varsaymaz, Bölge II'de de. Yönelim metriktedir,
zorunluluk hiçbir metrikte değildir; ok, denklemlerde bulunmadığı için başka bir
yere, duruma yazılmak zorundadır.

Bu ayrım bir iddia değil, bir hesaptır. Yönelebilirlik, bir birim vektörün yarım
tur döndürülmesinden çıkar; zorunluluk ise hesabın hiçbir adımına girmez. Öte
tarafın bu tartışmadaki yeri de dikkat çekicidir: orada ayrımın kendisi
bulunmaz (Bölüm 9.4), dolayısıyla zamanın okunu duruma yazma imkânı da doğmaz.

**Kapsam dışı bırakılan.** Aynı sonuca varan felsefi tartışma ve literatürdeki
"zamansız" programların taraması bu alt bölümün dışındadır; sonucu
değiştirmezler.

### 9.4 Zaman yöneliminin yokluğu

Yukarıdaki ifade sezgiseldir; burada kesinleştirilmiştir. Bir bölgede tutarlı bir
gelecek-geçmiş ayrımı için, zaman-benzeri vektörler kümesi **iki ayrı
bileşenden** oluşmalıdır. Ancak o zaman bileşenlerden birine "gelecek", diğerine
"geçmiş" denebilir. Bu koşula, tek bir pozitif yön bulunması karşılık gelir.

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
yolun daha **ilk ayağında** kaybolur, ikinci ayağı beklemez.

| Bölge | Zaman yönü sayısı | Zaman-benzeri küme | Gelecek/geçmiş |
| ------------------ | ----------------- | ------------------ | -------------- |
| Bölge I, $(1,3)$ | 1 | İki bileşen | Var |
| Ara bölge, $(2,2)$ | 2 | Bağlantılı | Yok |
| Bölge II, $(3,1)$ | 3 | Bağlantılı | Yok |

Ok, entropiden değil, zaman yönü **sayısından** çıkar; ve eşik değeri birdir.

**Literatürdeki karşılığı.** [11], imza değiştiren bir manifoldun geçiş
hiperyüzeyinde, her noktadan geçen ve zaman yönünü tersine çeviren kapalı
sözde-zaman-benzeri ilmekler bulunduğunu ispatlar. Vardıkları sonuç kelimesi
kelimesine buradakiyle aynıdır: gelecek ve geçmiş yönlü vektörler arasında
tutarlı bir ayrım yapılamaz.

Yollar farklıdır. [11] sonucu geçiş hiperyüzeyinin geometrisinden, Lorentzian
bölgede global hiperboliklik varsayarak elde eder; burada ise yalnızca zaman
yönlerinin sayısından, hiperyüzey hakkında hiçbir varsayım yapmadan çıkar.

İki çekince var. Birincisi, [11]'in hipotezlerini bu modelin geçişi
**sağlamaz**. Orada bir taraf Riemann imzalıdır ve dejenerelik transvers radikal
tipindedir; buradaki doğrudan geçişte ise rank iki düşer. Ortak olan
sonuçtur, ispat değildir. Buna karşılık Bölüm 5.1'in kademeli yolu her ayakta
rank-1 dejenereliğe sahiptir, yani [10] ve [11]'in geometrik çerçevesine buradan
bakıldığından daha yakındır.

İkincisi, [11]'in ilmekleri alışıldık anlamda kapalı zaman-benzeri eğriler
**değildir**: kesişim noktalarında hareket yönünün aynı olması gerekmez. Bu
nedenle sonuç, maddenin zamanda geriye gitmesi biçiminde okunamaz. [11] kendi
fiziksel yorumunu da verir: hiperyüzey yakınındaki bir gözlemciye böyle bir
ilmek, iki ayrı noktada bir parçacık-karşıparçacık çiftinin yaratılması gibi
görünebilir.

İlk bakışta bir çelişki görünür: Bölüm 6.1 eşiğin geçirgen olmadığını söylerken,
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

[14] buradaki formülasyondan bir noktada ayrılır: orada evrim üniter ve olasılık
koruyan bir yapı ister. Yukarıdaki hesap ise Bölge II'de o talebin dayandığı
yapıyı bulmamaktadır. Yine de bu itiraz açık bir soru olarak durur; model onu
kendi lehine kapatmamıştır.

### 9.5 Yolculuğun tanımı

Parçacığın öte tarafta yapabilecekleri iki bağımsız etiketle tükenir.

**Hangi yüzden çıktığı.** Ara bölgenin iki yüzü vardır ve parçacık girdiği
yüzden geri dönebilir, karşı yüzden çıkabilir, ya da hiç çıkmayabilir.

**Enerji vektörünün ne kadar döndüğü.** Bölüm 15.3'te gösterildiği gibi
yönelimin kendisi öte tarafta ayar fazlalığıdır; fiziksel olan tek şey giriş ile
çıkış arasındaki **bağıl** dönmedir. Üç sınıf ayırt edilir: dönme yok, kısmi
dönme ve tam ters çevirme.

İki etiket birlikte üç çarpı üç, yani dokuz hücrelik bir tablo verir. Bölüm 16
bu hücrelerin her birinin Bölge I'de nasıl göründüğünü tek tek hesaplamıştır.

## 10. Orada hareket ve yönelim

İmza değişimini yapan $D$ matrisinde hız hiç geçmez. Bu bir eksiklik değildir.
Aşağıdaki türetim, hız kavramının burada zaten gerekmediğini göstermektedir.

Bölge I'de hız zaten temel bir büyüklük olmayıp dispersiyondan çıkar:

$$\omega(k) = c\sqrt{k^2 + \mu}, \qquad
 v_{\text{faz}} = \frac{\omega}{k}, \qquad
 v_{\text{grup}} = \frac{d\omega}{dk}, \qquad
 v_{\text{faz}} \cdot v_{\text{grup}} = c^2$$

Öte tarafta aynı türev alınır, ancak payda vektördür, zaman üç boyutludur:

$$\frac{dq}{d\kappa} \;\longrightarrow\; \text{skaler/vektör} = \text{gradyan} = \text{VEKTÖR}$$

**Sonuç:** Hız orada bir sayı olmaktan çıkar ve bir yönelime dönüşür. "Ne kadar
hızlı" sorusunun yerini "hangi yönelimde" sorusu alır. Hız bilgisini taşıyan tek
yer $B$ boostudur, yani üç zamanlı uzaydaki yönelim.

Hız dönüşümü $v' = c^2/v$'dir; ışık hızı sabit noktadır ve subluminal ile
superluminal bölgeleri birbirine eşler.

### 10.1 Dört eksende hareketin tanımı

Yukarıdaki sonuç üç zaman ekseni hakkındadır ve dördüncü ekseni kapsamaz. Bu alt
bölüm dördünü birden tanımlar, çünkü çalışmanın sonucunu taşıyan eksen tam da
dördüncüsüdür.

Öte tarafın dört yuvasının her biri için üç şey hesaplanır: kendi bölgesindeki
karakteri, involüsyon altında Bölge I'in hangi yuvasına düştüğü ve o yuvada bir
birim adımın Bölge I saatinde ne ürettiği.

| Öte tarafta yuva | Orada karakteri | Düştüğü yuva, burada | O yuvanın karakteri | Bir birim adımın saatte karşılığı |
| ---------------- | --------------- | -------------------- | ------------------- | --------------------------------- |
| $0$ | zaman | $3$ | uzay | **tam olarak $0$** |
| $1$ | zaman | $2$ | uzay | **tam olarak $0$** |
| $2$ | zaman | $1$ | uzay | **tam olarak $0$** |
| $3$ | uzay | $0$ | zaman | **tam olarak $1$** |

Dört yuvanın dördü de eşikte karakter değiştirir; hiçbiri türünü korumaz. Buna
karşılık **hareket serbestliği yuva yuva korunur.** Öte tarafın üç zamanında
serbestçe hareket edilir ve o üç zamanın taşıdığı Bölge I uzay yönlerinde de.
Öte tarafın tek uzay ekseninde yön seçilemez ve onun taşıdığı Bölge I zamanında
da seçilemez.

**Üç zaman ekseninde hareket.** Serbesttir, ama iki nedenle sonucu taşıyamaz.
Birincisi, tümüyle bu üç eksenin içinde kalan bir yer değiştirme Bölge I
saatinde **tam olarak sıfır** üretir; üç eksenin her birinde birim adım tek tek
denenmiş, üçünün de izdüşümü sıfır çıkmıştır. İkincisi, bu üç eksen arasında bir
$O(3)$ simetrisi vardır ve bu bir ayar fazlalığıdır: enerji vektörünün yönü
orada fiziksel değildir, yalnızca uzunluğu fizikseldir. Kapalı bir gezinti de
hiçbir iz bırakmaz, çünkü bu eksenler arasındaki dönmeler ayırt edilmiş ekseni
sabit bırakır ve sözlüğün katsayısına dokunmaz.

Bu yüzden yukarıdaki "hız yönelime dönüşür" sonucu bu üç eksene aittir: payda üç
boyutlu olduğu için türev skaler değil gradyandır ve "ne kadar hızlı" sorusu
"hangi yönelimde" sorusuna dönüşür.

**Tek uzay ekseninde hareket.** Burada durum başkadır. O eksen tek olduğu için
türev **skalerdir**, yani
orada hız yönelime dönüşmez; sıradan anlamda bir yayılma hızı tanımlıdır ve bir
üst sınırı vardır. Hesaplanan büyüklük

$$\left|\frac{\mathrm{d}q}{\mathrm{d}\kappa}\right| = \frac{c\,\kappa}{\sqrt{\kappa^2+\mu}}$$

sınanan bütün dalga sayılarında $c$'nin altındadır ve $\kappa \to \infty$
limitinde $c$'ye gider. Yani **öte tarafın da bir hız sınırı vardır** ve o
sınır bu tarafın sınırıyla aynı sayıdır. Durgun bir cisim için
$q(0) = mc^2/\hbar \neq 0$'dır, yani o eksende duran bir cismin bile sıfırdan
farklı bir eşlenik niceliği vardır.

Sonucu taşıyan eksen budur. Bu eksende $s$ kadar yer değiştirmek, Bölge I
saatinde tam olarak $s$ kadar yer değiştirmektir; katsayı birdir ve diğer üç
eksenin bu yuvaya katkısı tam olarak sıfırdır. İspatı Bölüm 4.1.1'dedir,
işaretin nereden geldiği Bölüm 4.1.3'te ve o eksende geri dönülemiyor olmasının
bu sonuçla nasıl bir arada durduğu da orada yazılmıştır.

**Dört eksenin özeti.** Parçacık üç eksende serbestçe hareket eder, ama o üç
eksen saate hiçbir şey taşımaz. Kalan tek eksende hareket serbest değildir, ama
saate taşınan her şey oradan gelir. Yolculuğun tamamı bu dengesizlik üzerine
kuruludur.

### 10.2 Dispersiyon ve grup hızı

Düzlem dalga koşulu:

$$k_1^2 + k_2^2 + k_3^2 - \frac{q^2}{c^2} + \mu = 0
 \quad\Longrightarrow\quad q = \pm\, c\sqrt{k^2 + \mu}$$

$q$ her zaman reeldir: $r$ ekseninde salınım vardır, sönümlenme yoktur.

Durgun cisim ($k = 0$) için $q = mc^2/\hbar \neq 0$. Yani orada duran bir cisim
bile $r$ ekseninde ilerler, Bölge I'deki "duran cisim zamanda ilerler"
ifadesinin tam aynasıdır.

Grup hızı:

$$\frac{dq}{dk} = \frac{c\,\hbar k}{\sqrt{c^2m^2 + \hbar^2k^2}}
 \qquad (\text{vektör, } k \text{ doğrultusunda})$$

$|dq/dk| < c$ ve $k \to \infty$ limitinde $c$'ye yaklaşır. Karşı tarafta da bir
hız sınırı vardır; yalnızca hangi eksende olduğu değişmiştir. Sınır davranışı
her iki tarafta aynıdır: $\kappa \to 0$'da sıfır, $\kappa \to \infty$'da $c$.

### 10.3 Durgunluğun tek yörüngeye indirgenmesi

Durgun superluminal dört-momentum $p' = (mc\,\mathbf{s},\, 0)$ biçimindedir ve
her $\mathbf{s}$ seçimi ayrı bir dünya çizgisi demeti veriyormuş gibi görünür.

Hesap:

- Kütle kabuğu koşulu $s_1^2 + s_2^2 + s_3^2 = 1$ verir, yani
 $\mathbf{s} \in S^2$.
- $\eta' = \mathrm{diag}(+1,+1,+1,-1)$ içinde ilk üç slot **aynı** işaretlidir;
 bu üç slotu koruyan grup $O(3)$'tür.
- $O(3)$ hem metriği korur hem de durgunluğu bozmaz (doğrulandı).
- $O(3)$, $S^2$ üzerinde geçişli (transitif) etki eder: herhangi bir
 $\mathbf{s}$'yi herhangi bir $\mathbf{s}'$ye götüren bir dönme her zaman
 vardır.

**Sonuç:** Bütün $\mathbf{s}$ seçimleri aynı yörüngededir. Sonsuz sayıda
fiziksel durum yoktur; **tek bir durumu yazmanın sonsuz yolu** vardır. Bu bir
ayar (gauge) fazlalığıdır.

$$\text{Stabilizatör} = O(2), \qquad \text{Yörünge uzayı} = O(3)/O(2) = S^2$$

**Öncelik.** Fazladan zaman boyutunun bir ayar simetrisiyle elenmesi [13]'ün
kurduğu mekanizmadır. $Sp(2,\mathbb{R})$ ayar simetrisi altında tek zamanlı
sistemler, aynı iki zamanlı sistemin farklı ayar sabitlemeleri olarak ortaya
çıkar. Aynı mekanizma alan teorisine, etkileşimlere ve ayar arka planlarına
kadar götürülmüştür. Yukarıdaki $O(3)$ fazlalığı aynı türden ve çok daha dar bir
olgudur. Buradaki katkı mekanizma değil, mekanizmanın bu modeldeki durgunluk
sorusuna uygulanmasıdır.

# Kısım IV. Üç bölgede madde

## 11. Parçacığın iki okuması

Bu çalışmanın ele aldığı olay şudur: kütleli bir parçacık eşiği geçer, öte
tarafta bir süre kalır ve geri döner. Öyleyse "parçacık" sözcüğü küçük bir
ayrıntı değil, bütün hesabın dayanağıdır, ve ne anlama geldiği baştan
sabitlenmelidir.

Bunu yapmak zorunludur, çünkü Bölge II'de parçacık kavramı olağan anlamıyla
bulunmaz. O kavram üç yapıya dayanır: pozitif ile negatif frekansın
birbirinden ayrılması, alttan sınırlı bir Hamiltonyen ve Poincaré grubunun
üniter bir temsili. Bölüm 9 bu üçünün de öte tarafta bulunmadığını
göstermektedir. Bu yüzden Bölge I'de doğal görünen bir tanımı öte tarafa
taşımak serbest değildir.

Burada benimsenen çözüm, tek bir tanım aramak yerine **iki okumayı birlikte
yürütmektir**. Bu, yalnızca bu bölümün değil, metnin tamamının yöntemidir:
parçacık hakkında bir şey söyleyen her bölüm, söylediğini iki kez söyler.

**Dalga okuması.** Parçacık, kütleli reel skaler alanın dar bir mod demetidir.
Enine dalga sayısı üzerinde Gauss ağırlıklı bir paket alınır,

$$A(k) = \exp\!\left[-\frac{(k - k_0)^2}{2\sigma^2}\right]$$

ve fiziksel yoğunluk bu genliğin karesidir. Yoğunluğun genişliği bu nedenle
genliğinkinden $\sqrt{2}$ kat dardır; aşağıdaki bütün nicelikler yoğunluk
üzerinden tanımlanmıştır. Eşikten geçiş Bölüm 8'de mod diliyle kurulduğu için,
geçişle ilgili her nicelik bu okumada doğrudan hesaplanabilir.

**Parçacık okuması.** Parçacık, konumu, momentumu ve bir yörüngesi olan bir
cisimdir. Bu okumada sorular "nereye gitti", "ne zaman döndü", "hangi yönelimi
kazandı" biçimindedir ve cevapları tek tek sayılardır.

İki okuma birbirinin yalınlaştırılmış hâli değildir; ikisi de kendi içinde
eksiksizdir ve metin ikisini yan yana yürütmektedir. Uyuştukları yerde metin
uyuşmanın nedenini de yazar. Ayrıldıkları yerde ayrılma **gizlenmez, sonuç
olarak kaydedilir**; çünkü bu modelde ikisinin ayrıldığı yerler tam olarak öte tarafın
kendine özgü davrandığı yerlerdir.

Aralarındaki bağ, aşağıda kurulan sözlüktür ve bu sözlüğün nerede geçerli
olduğu hesaplanabilir bir sorudur.

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

Bölüm 8 geçirgenliğin moda bağlı olduğunu vermektedir. Bir paket birçok moddan
oluştuğuna göre, eşik paketin bazı bileşenlerini diğerlerinden daha çok geçirir.
Geçen şey, gelenin sönümlenmiş bir kopyası değil, **başka bir dağılımdır**.

Geçen ağırlık oranı, $\mu = 1$, dilim kalınlığı $d = 1$ ve paket merkezi
$k_0 = 2$ için şu değerleri alır:

| Paket genişliği $\sigma$ | Geçen ağırlık oranı |
| ------------------------ | ------------------- |
| $0{,}1$ | $0{,}638$ |
| $0{,}4$ | $0{,}634$ |
| $1{,}0$ | $0{,}618$ |

Geçen oran her durumda sıfır ile bir arasındadır: paket ne tamamen yansır ne
tamamen geçer.

Asıl etki oranda değil, dağılımın kaymasındadır. Ağırlık merkezinin kayması,
paketin kendi genişliği birimiyle şu değerleri alır:

| Paket genişliği $\sigma$ | Merkez kayması (genişlik birimiyle) |
| ------------------------ | ----------------------------------- |
| $1{,}0$ | $0{,}413$ |
| $0{,}5$ | $0{,}256$ |
| $0{,}25$ | $0{,}138$ |
| $0{,}125$ | $0{,}071$ |

Kayma daima pozitiftir, yani büyük dalga sayısına doğrudur; çünkü dilim orada
daha geçirgen kalır. Geniş bir paket için kayma kendi genişliğinin yarısına
yaklaşır, ki bu paketin kimliğini yitirmesi demektir.

### 11.3 Nokta cisim koşulu

Tablodaki kayma, paket genişliğiyle **doğru orantılıdır**: genişlik yarıya
indiğinde kayma da yarıya iner. Bu, sayısal olarak ardışık genişliklerde
doğrulanmıştır.

Orantının sonucu şudur: kaymanın bir alt sınırı yoktur. Yeterince dar bir paket
için merkez kayması istenildiği kadar küçüktür.

> Nokta cisim dili yaklaşık bir kolaylık değil, dar paket limitinde **tam**
> geçerli kalır. Geçen cisim, giden cismin aynısıdır; yalnızca paket dar tutulduğu
> sürece.

Gidiş dönüş anlatısının tamamı bu sonuca dayanır. Paket dar tutulmadığında
"parçacık gitti ve geri döndü" cümlesi anlamını yitirir, çünkü dönen şey gidenden
farklı bir mod dağılımı olur.

### 11.4 Dar paketin bedeli

Dar paket limiti merkezi korur, ama her şeyi korumaz. İki bedel kalır.

Birincisi, geçen ağırlığın oranı hiçbir zaman bire ulaşmaz. Dar bir pakette de
bu oran birden küçük kalır, yani dönen paketin toplam ağırlığı gidenin altındadır.
Bu bir konum ya da momentum kaybı değildir; kaybolan şey doğrudan parçacığın
orada bulunma ağırlığıdır, ve Bölüm 14'ün bilgi dökümü bunu ilk kalem olarak
sayar.

İkincisi, paketin genişliği de değişir, dar limitte kendi büyüklüğünün binde
biri mertebesinde. Merkez kadar temiz korunmaz, ancak merkeze göre ikinci
mertebeden küçüktür.

Bu iki bedel, Bölüm 14'te mod içeriği karşılaştırmasının ölçeceği niceliklerdir.

### 11.5 Bu tanımın sınırları

Üç çekince vardır.

Paket burada tek bir enine dalga sayısı değişkeni üzerinde durur. Gerçek
bir üç boyutlu paket için aynı hesap üç değişkende yapılmalıdır; sonucun
niteliksel olarak değişmesi beklenmez, ancak gösterilmemiştir.

Hesap doğrusaldır ve alanın kendisiyle etkileşimi yoktur. Etkileşen bir alanda
paketin geçiş sırasında dağılması ayrı bir olgudur.

Nokta cisim okuması yalnızca Bölge I'de tanımlıdır. Bölge II'de "konum" kavramı
tek uzay ekseni olan $r$ üzerine daralır ve üç zaman yönü boyunca hiçbir
karşılığı kalmaz.
Öte tarafta hareketin ne anlama geldiğini bu nedenle Bölüm 10 karşılar. Konumun
kendisi ise orada da tanımlı değildir; Bölüm 18.9 bunu reddeder.

### 11.6 Okumaların ölçümle kararı

Geçişin ne kadar sürdüğü sorusuna üç kurgu üç ayrı yanıt verir. Nokta cisim
kalınlığı bir hıza böler, dalga fazı frekansa göre türetir, genlik depolanan
normu gelen akıya böler. Üçü de adı konmuş niceliklerdir ve bu çalışmaya ait
değildir: fazın frekans türevi [31]'e, depolanan normun akıya oranı [32]'nin
ikamet süresine karşılık gelir ve tanımların hangisinin neyi ölçtüğü [33]'te
derlenmiştir. Sınanan yapılanmada bir katediş için sırasıyla $9{,}861$,
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
$\omega_{\min} = c\sqrt{k_\perp^2 + \mu}$ değerindedir. Bandın merkezi bunun
altına düştüğünde hiçbir bileşen algılayıcıya ulaşmaz.

Birinci sınır kütleye düşer. Merkez frekans sabit tutulduğunda kütle parametresi
en çok

$$\mu_{\max} = \frac{\omega_0^2}{c^2} - k_\perp^2$$

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
$0{,}25$'ten $3{,}00$'a çıkarıldığında gereken öte taraf mesafesi $2{,}815$'ten
$4{,}567$'ye yükselir. Kütle bir kazanç değil maliyet getirir. Doyum her kütlede
ayaktadır.

Genişliğin etkisi ikinci mertebedendir ve kapalı biçimde **hiç görünmez**, çünkü
kapalı biçim bandın merkezinde değerlendirilir ve genişliği taşımaz. Yayılan
paketin tepesi ölçüldüğünde genişliğin on altı katlık değişimi eşiği binde
$7{,}5$ oranında oynatır ve her adımda aynı yönde: geniş paket daha geç döner.
Ölçüm ile kapalı biçimin ayrıldığı tek yer burasıdır ve iki rotanın birlikte
koşturulmasının gerekçesi budur.

---

# Kısım V. Gidiş dönüşün sonucu

Bu kısım çekirdek eşlemenin **zaman** bileşenini kurmaktadır. Dönüş olayının Bölge
I'in zaman eksenindeki yeri burada belirlenir ve içeride taşınan bir saatten
değil, iki geçişin ortak genliğinin fazından okunmaktadır.

## 12. İkinci geçiş ve eşleşme

Gidiş tek bir yüzeyin problemidir; gidiş dönüş iki yüzeyin problemidir ve
farklıdır. İki yüzey arasındaki bölge, dalganın bir kez geçtiği bir engel değil,
içinde ileri geri yansımaların üst üste bindiği bir **boşluk** gibi davranır.

### 12.1 Geçiş genliği

Normal doğrultudaki dalga sayısı dışarıda $\kappa$, ara bölgede $q$ olmak üzere,
iki yüzeyin birlikte çözümü tek bir karmaşık genlik verir:

$$A = \frac{4\kappa q}
 {(\kappa+q)^2 e^{-i q d} - (\kappa-q)^2 e^{i q d}}$$

Bu ifade dört ara bölge tipini birden kapsamaktadır, çünkü $q$ karmaşık değer
alabilir. Ara bölge yayılımlı ise $q$ reeldir ve payda salınır. Söndürücü ise
$q$ sanaldır; üstel terimler reel hiperbolik fonksiyonlara döner ve genlik
bastırılmaktadır. İki durum ayrı formüller değil, aynı formülün iki dalıdır.

Ara bölge yokken $q = \kappa$ olur ve $A$ serbest yayılma fazına indirgenir; bu,
hesabın tutarlılık sınamasıdır ve sağlanmaktadır.

### 12.2 Genliğin taşıdığı iki bilgi

Genliğin **büyüklüğü** ne kadarının geçtiğini söyler ve Bölüm 5'in geçirgenlik
tablosunu vermektedir.

Genliğin **fazı** ise dönüş anını taşır ve asıl konu odur. Bir sonraki bölümün
tamamı bu fazın nasıl okunacağı üzerinedir.

### 12.3 Parçacığın eşikten geçirilme yolu

Eşikten geçiş bir kapının açılması değildir. Ara bölge söndürücü rejimde bir
engeldir ve engelin içinde normal dalga sayısı sanaldır. Dolayısıyla geçiş
tünellemedir: parçacık engeli aşmaz, genliği engelin içinde üstel olarak bastırılır
ve öte yüzde sıfırdan farklı bir değerle çıkar.

Bunun iki sonucu vardır. Geçiş **olasılıksaldır**; tek bir parçacık için
söylenebilecek olan, geçme şansının $|A|^2$ olduğudur. Geçiş ayrıca
**zorlanamaz**; genlik ancak engelin opaklığı, yani sönüm sabiti ile kalınlığın
çarpımı küçültülerek büyür.

Deney bu nedenle tek bir parçacığa dayanmaz. Düzenek çok sayıda parçacığı aynı
eşiğe fırlatır ve geri dönenleri sayar. Gereken fırlatma sayısı opaklığın
üstelidir ve Bölüm 21.2.3 onu sayılara bağlamaktadır.

### 12.4 Dönüşün kendiliğinden olmasının sebebi

Parçacığın geri gelmesi bir tercih ya da ikinci bir müdahale değildir. Sebebi öte
tarafın yapısındadır.

Bölge II üç zaman yönü taşır ve Bölüm 9'da gösterildiği üzere zaman yönelimi
orada tanımsız kalır. Yönelim olmadığı için "ileri doğru yayılmayı sürdürmek" diye
bir koşul da yoktur. Yakın tarafta bir ışıma koşulu dalganın yalnızca dışarı
gitmesini şart koşar, çünkü orada geleceği geçmişten ayıran bir ok bulunur. Öte
taraf böyle bir ok sunmadığından **kendi ışıma koşulunu vermez**.

Bunun saçılma problemindeki karşılığı doğrudandır: Bölge II iki genlik taşır, biri
yüzeyden uzaklaşan diğeri yüzeye doğru gelen. İkincisi elle konmuş bir kabul
değildir; tek yönlülüğü dayatacak bir yapı bulunmadığı için ortaya çıkar.

Dolayısıyla dönüş kendiliğindendir. Parçacık öte tarafta kalmayı seçemez, çünkü
kalmayı tanımlayacak bir zaman oku yoktur. Geri gelmesi, gitmesiyle aynı çözümün
parçasıdır ve iki yüzeyin ortak çözümü tek bir genlik verir.

**Çekince.** Bu, dönüşün kesin olduğu anlamına gelmez. Kesin olan, dönüş
genliğinin var olduğudur; büyüklüğü Bölüm 12.2'nin verdiği $|A|$ değeridir ve
söndürücü rejimde küçüktür.

## 13. Dönüş anı

Bu bölümün sorusu şudur: parçacık geri döndüğünde, hiç geçmemiş bir gözlemcinin
saatinde nereye oturur.

### 13.1 Saat taşımanın imkânsızlığı

İlk akla gelen yol, parçacığın kendi saatini okumaktır. Bu yol kapalı kalır. Ara
bölgede zaman yönelimi yoktur; Öklid durumunda zaman ekseni hiç yoktur. Bir süre
okunacak bir yapı bulunmadığı için "içeride şu kadar kaldı" ifadesi tanımsız kalır.

Dolayısıyla dönüş anı, taşınan bir süreden değil, başka bir yerden gelmek
zorundadır.

### 13.2 Fazın taşıdığı yer bilgisi

Bölüm 12'nin genliği karmaşıktır. Fazının frekansa göre türevi, dışarıda kalan
gözlemcinin ölçtüğü gecikmedir:

$$\tau = \frac{d}{d\omega}\,\arg A(\omega)$$

Bu ifade ara bölgenin içinde hiçbir saat gerektirmez. Yalnızca dışarıda, iki
yüzeyin de dışında tanımlı olan bir niceliğin, geçiş genliğinin, frekansa
duyarlılığını kullanır. Süreyi bilmeden yeri veren şey budur.

Tutarlılık sınaması: ara bölge yokken $\tau$ tam olarak serbest uçuş süresine
eşit çıkar ve bu üç ayrı kalınlıkta doğrulanmıştır.

### 13.3 Engel olmanın frekansa bağlılığı

Hesabın ilk sonucu beklenmedik biçimde basittir. Aynı ara bölge, yüksek
frekansta yayılımlı, düşük frekansta söndürücüdür. Öklid bölge için sınır,

$$\omega^2 < k_T^2\left(1 + \tfrac{2n}{3}\right) + \mu$$

koşuluyla verilir. Yani "ara bölge bir duvar mıdır" sorusunun tek bir cevabı
yoktur; cevabı gelen parçacığın frekansı belirler. Eşik bu nedenle bir duvar değil
bir **mod filtresidir** ve metnin başka yerleri bu adla ona geri döner.

### 13.4 Engel rejiminde gecikmenin doyumu

Ara bölge söndürücü olduğunda gecikme kalınlıkla artmayı bırakır:

| Kalınlık $d$ | Gecikme $\tau$ | Işığın alacağı süre |
| ------------ | -------------- | ------------------- |
| $1$ | $1{,}451$ | $1$ |
| $2$ | $1{,}463$ | $2$ |
| $4$ | $1{,}463$ | $4$ |
| $8$ | $1{,}463$ | $8$ |

Gecikme ikinci basamaktan sonra sabitlenir. Kalınlık sekiz kat arttığında dönüş
anı değişmez.

Bunun iki sonucu vardır ve ikisi de önemlidir.

**Birincisi, geçiş ışıktan hızlı görünür.** Sekiz birim kalınlıkta gecikme
ışığın alacağı sürenin beşte biri kadardır. Bu, bu modelde bir uyarımın ışıktan
hızlı **yayılması** anlamına gelmez; Bölüm 10.2 grup hızının daima $c$'nin
altında kaldığını hesaplamıştır. Anlamı, geçen paketin tepe noktasının beklenenden
erken çıkmasıdır.

**Doyumun kendisi bu çalışmanın bulgusu değildir.** Kalın bir engelde tünelleme
süresinin kalınlıktan bağımsızlaşacağını [29] durağan faz yöntemiyle 1962'de
hesaplamıştır; olgu literatürde o adla anılır. Mikrodalga ve fotonik ölçümler
onu doğrulamış, [30] ise doymuş süreyi bir kat etme süresi olarak değil,
engelde depolanan alanın boşalma süresi olarak okumuştur. Yukarıdaki tablo o
sonucun bu geometrideki karşılığıdır. Bu çalışmanın kendi katkısı doyumun
varlığı değil, doymuş gecikmenin ne kadar küçültülebileceğidir (Bölüm 4.1.6).

**Aynı soru iki engelli hâlde de sorulmuş, ancak kapatılamamıştır.** [41] iki ardışık
engel arasındaki açıklığın da gecikmeye girmemesini bekler ve [42] bunu optik
çift bariyerde beş ayrı açıklıkta ölçer. Sonuç tartışmalıdır. [43] ölçülen
niceliğin bir kat etme süresi değil kavite ömrü olduğunu savunur; [44] ile [45]
bağımsızlığın kendisini reddeder.

Bu metnin hiçbir sonucu o tartışmaya dayanmaz. Buradaki hesap tek bir bölgenin
kalınlığını konu alır ve öte tarafta kat edilen mesafe gecikmeye değil ona
karşı çalışan terime girer. Kayıt, aynı yöne bakan bir soruyu açık olarak
göstermek içindir.

**İkincisi ve bu modelin aleyhinedir, dönüş anı kalınlığı unutur.** Bir
birimlik ara bölgeyle sekiz birimlik ara bölge parçacığı Bölge I saatinde **aynı
ana** koyar. Dolayısıyla dönüş anına bakarak ara bölgenin ne kadar kalın olduğu
söylenemez.

### 13.5 Yayılımlı rejimde tersine dönme

İç mod yayıldığında doyum yoktur; gecikme kalınlıkla salınır. Kalınlık taranınca
gecikme $0{,}225$ ile $9{,}009$ arasında gidip gelir. Yayılımlı bir ara bölgede
dönüş anı kalınlığa **duyarlıdır**, ancak tek değerli değildir: aynı gecikmeyi
veren birden çok kalınlık vardır.

| Ara bölge | Dönüş anının kalınlığa bağlılığı |
| --------- | ----------------------------------- |
| Yok | Doğrusal, tek değerli |
| Yayılımlı | Salınımlı, çok değerli |
| Söndürücü | Doyuma ulaşır, kalınlıktan bağımsız |
| Dejenere | Tanımsız, geçiş yok |

### 13.6 Mesafe ile fiyatın farkı

Dönüş anı tek bir çıkarma işlemidir. Öte tarafta kat edilen mesafe $s$, tek
geçişin faz gecikmesi $\tau$ ile yazıldığında, kalkışa göre varış anı
$2\tau - s$ değerindedir. Bedel gidiş dönüşe aittir, dolayısıyla tek geçişin
iki katıdır; ikisini karıştırmak bu çalışmaya iki kez ikilik çarpana mal
olmuştur. Sınanan yapılanmada $\tau = 1{,}462864$, gidiş dönüşün bedeli
$2\tau = 2{,}925728$ olarak çıkar.

| Öte tarafta kat edilen mesafe | Varış anı | Konum |
| ----------------------------- | -------------- | ----------------- |
| $1{,}000000$ | $+1{,}925728$ | Kalkıştan sonra |
| $2{,}925728$ | $0{,}000000$ | Tam kalkış anında |
| $6{,}000000$ | $-3{,}074272$ | Kalkıştan önce |
| $25{,}000000$ | $-22{,}074272$ | Kalkıştan önce |

Yolcunun denetlediği tek nicelik $s$ değeridir. Bedel durumun ve bölgenin
özelliklerinden çıkar ve yolculuk sırasında değiştirilemez.

### 13.7 Sekiz koşul, iki başarısızlık

Geçmenin, orada hareket etmenin ve kalkıştan önce dönmenin koşulları sekiz
tanedir.

| Koşul | Başarısızlığın anlamı |
| --------------------------------------- | -------------------------------- |
| Bant merkezinin kesimi aşması | Algılayıcıya ulaşan bileşen yok |
| Bandın tamamının kesimi aşması | Algılayıcıya ulaşan bileşen yok |
| Kütlenin tavanın altında kalması | Algılayıcıya ulaşan bileşen yok |
| İç kısmın yayılımı engellemesi | Doyan gecikme uygulanmaz |
| Genliğin iki geçişten sağ çıkması | Ölçülebilir dönüş yok |
| Bir eklem koşulunun çıkışa izin vermesi | Yüzey tek yönlü dalgayı yasaklar |
| Ters çeviren dalın gerçekleşmesi | Varış öne değil arkaya kayar |
| Mesafenin bedeli aşması | Varış kalkıştan sonraya düşer |

Bu koşullar aynı biçimde başarısız olmaz ve ayrım sonucun okunuşunu belirlemektedir.
Yedisi başarısız olduğunda yolculuk ortadan kalkar ya da işareti döner. Yalnızca
son koşul, yani öte tarafta alınan mesafe, **daha fazla ödenerek** sağlanabilir.
Koşullar tek tek bozulduğunda şu çıkar: kütle parametresinin $8$ olması, bant
genişliğinin $0{,}5$ olması ve ters dalın seçilmesi birinci türden bir
başarısızlık verir; mesafenin $0{,}5$'te kalması ise ikinci türden bir
başarısızlık verir.

### 13.8 Sınırın ağırlığa düşmesi

Öte tarafta alınacak mesafeyi yukarıdan sınırlayan bir koşul yoktur, dolayısıyla
varış anı sınırsız geriye iner. Bununla birlikte düşen nicelik **ağırlıktır**:
sınanan yapılanmada gönderilen bandın yalnızca $7{,}8 \times 10^{-36}$ katı geri
dönmektedir. Daha geriye gitmenin sınırı bu yüzden varabilmeye değil,
**görülebilmeye** konmuştur. Sorunun ölçülebilir biçimi şudur: ne kadar geriye
gitmek istendiği değil, ne kadar zayıf bir sinyalin algılanabildiği.

---

## 14. Mod içeriğinin değişimi

Gidiş dönüş aynı ara bölgeyi iki kez geçmektedir. Mod süzgeci bu nedenle paketin
üzerine **iki kez** iner ve etkiler çarpılır, toplanmaz.

### 14.1 Geri dönen ağırlık

$\mu = 1$, $d = 1$, paket genişliği $0{,}3$ için:

| Ara bölge | Tek geçişte kalan | Gidiş dönüşte kalan |
| --------- | ----------------- | ------------------- |
| Kleinian | $0{,}870$ | $0{,}757$ |
| Öklid | $0{,}122$ | $0{,}018$ |
| Dejenere | $0$ | $0$ |

Dönüş ayağı, gidiş ayağının bedelini yeniden ödetir. Öklid bölgede gidiş dönüş
paketin yüzde ikisinden azını geri getirir.

### 14.2 Merkez kayması

Süzgeç iki kez uygulandığı için ağırlık merkezinin kayması da büyür:

| Paket genişliği | Gidiş dönüş kayması (genişlik birimiyle) |
| --------------- | ---------------------------------------- |
| $0{,}4$ | $1{,}092$ |
| $0{,}2$ | $0{,}578$ |
| $0{,}1$ | $0{,}292$ |
| $0{,}05$ | $0{,}146$ |

Genişliği $0{,}4$ olan bir paket kendi genişliğinden fazla kayar; böyle bir
paket için "aynı parçacık geri döndü" ifadesi savunulamaz.

Kayma yine genişlikle **doğru orantılıdır** ve alt sınırı yoktur. Dolayısıyla
Bölüm 11.3'ün sonucu gidiş dönüş için de geçerli kalır: yeterince dar bir paket
kendisi olarak geri döner. Bu, yolculuğun bir yolculuk olmasını, yani gidenle
gelenin aynı şey sayılabilmesini sağlayan koşuldur.

---

## 15. Korunan nicelikler

Önceki bölüm geçişin neyi değiştirdiğini saydı. Bu bölüm ters soruyu sorar:
geçiş neye **dokunamaz**.

Üç nicelik geçişten değişmeden çıkar ve üçü de hesapla denetlenmiştir.

**Frekans.** Eklem koşulları sabit frekansta dayatıldığı için, ara bölgenin
dayattığı dalga sayısı adımı frekanstan bağımsızdır. Üç ayrı frekansta adım aynı
çıkar.

**Enine dalga sayısı.** Yüzey kendi boyunca homojen olduğundan enine dalga
sayısı korunur; adımı yalnızca o belirler. Üç ayrı enine dalga sayısı bunu
doğrulamıştır.

**Kütle.** Kütle parametresi iki tarafa da aynı miktarda girer; geçiş dalga
operatörüne etki eder, kütleye değil.

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

### 15.1 Enerji vektörünün karşılığı

Bölge II'nin üç enerji bileşeni soyut bir nesne değildir; Bölge I'de tanınan bir
şeyin başka adıdır. $D$ dört-momentuma uygulandığında

$$(E/c,\; p_x,\; p_y,\; p_z) \longmapsto (p_z,\; p_y,\; p_x,\; E/c)$$

olur. Yani:

> Öte tarafın **enerji vektörü** Bölge I'in **üç-momentumudur**; öte tarafın tek
> **momentumu** ise Bölge I'in **enerjisidir**.

Bu, iki niceliğin sayısal olarak eşit olması değil, aynı nesne olmasıdır. Enerji
vektörünün uzunluğu Bölge I'in momentumunun büyüklüğüne tam olarak eşittir ve bu
doğrulanmıştır.

### 15.2 Dönüşümün kayıpsızlığı

$D$ bir involüsyondur, dolayısıyla iki kez uygulanınca dört-momentumun dört
bileşeni de **tam olarak** başlangıç değerine döner; sayısal artık sıfırdır.

Bunun önemi şudur: modelin bildirdiği bütün kayıplar dönüşümden değil, iki
bölgenin birleştiği **yüzeyden** gelmektedir. Cebir hiçbir şey kaybetmez; bedeli
eklem koşulları ödetir.

### 15.3 Öte tarafta uzunluğun fizikselliği

Bölüm 10'da gösterildiği gibi üç zaman ekseni arasında bir $O(3)$ simetrisi
vardır ve enerji vektörünün **yönü** orada fiziksel değildir, bir ayar
fazlalığıdır. Fiziksel olan tek şey uzunluğudur.

Üç ayrı dönme açısı aynı sonucu verir: dönme enerji vektörünün uzunluğunu, öte
tarafın momentumunu ve değişmezi değiştirmez.

### 15.4 Dönmenin bıraktığı iz

Parçacık öte tarafta bir $O(3)$ dönmesi geçirip geri döndüğünde:

| Nicelik | Sonuç |
| --------------------------------- | ------------------ |
| Bölge I'in enerjisi | Tam olarak korunur |
| Bölge I'in momentumunun büyüklüğü | Tam olarak korunur |
| Kütle | Tam olarak korunur |
| Bölge I'in momentumunun **yönü** | **Değişir** |

Hesaplanan sapmalar:

| Öte taraftaki dönme açısı | Bölge I'de sapma (radyan) |
| ------------------------- | ------------------------- |
| $0{,}3$ | $0{,}289$ |
| $1{,}0$ | $0{,}961$ |
| $2{,}5$ | $2{,}308$ |

> Öte tarafta **hiçbir fiziksel içeriği olmayan** bir ayar dönmesi, bu tarafta
> **gözlenebilir bir sapma** olarak görünür. Parçacık aynı enerjiyle, aynı
> süratle, aynı kütleyle, ama farklı bir yöne bakarak geri döner.

Bu, Bölüm 16'da kurulan sözlüğün en somut maddesidir ve gidiş dönüşün bedelsiz
yapabildiği tek şeydir: yön değiştirmek.

**Çekince.** Bu sonuç dönüşüm düzeyindedir ve arayüzün mod süzgecinden
bağımsızdır. Parçacık öte tarafta bir $O(3)$ dönmesi geçirir mi, yani orada ne
yapar: bu hesabın konusu o değil. Hesap şunu verir: geçirirse Bölge I'de ne
görünür.

**Kalan çekince.** Bu döküm doğrusal ve durağan bir saçılma kurgusuna dayanır.

### 15.5 Yükün yeniden dağılması

Yüklü bir durum için döküme bir kalem daha girer. Yük yoğunluğu dört akımın
zaman bileşenidir ve geçiş yakın tarafın zaman eksenini öte tarafın bir uzay
ekseni üzerine taşır. Dolayısıyla yakın tarafta yoğunluk olarak okunan nicelik
öte tarafta bir **akım bileşeni**, akımlardan biri ise yoğunluktur. Yakın
tarafta $(3{,}0,\, 0,\, 0,\, 0{,}5)$ olarak yazılan dört akım öte tarafta
$(0{,}5,\, 0,\, 0,\, 3{,}0)$ olarak görünür.

Geçiş dört akımı bütün hâlinde taşımakta ve bileşenlerinden hiçbirini
kaybetmemektedir; yalnızca yoğunluk ile akım arasındaki bölünme yeniden dağılır.
Dört akımın değişmez karesi geçişin dayattığı genel işarete kadar korunur. Bu nedenle öte tarafta ne
kadar yük bulunduğu sorusu, yakın tarafta sorulan soruyla aynı soru değildir.

### 15.6 Potansiyelin ayar aralığı

Yük, zamanlamayı kendi başına değiştirmez. Uygulanan potansiyel sıfır olduğunda
yükün beş katına çıkarılması gidiş dönüş okumasını oynatmaz ve kod bunu üç
okumanın hepsinde ayrı ayrı sınamıştır.

Yükün getirdiği şey bölge dışından işleyen bir ayardır. Minimal bağlaşım etkin
frekansı yük ile potansiyelin çarpımı kadar kaydırır, dolayısıyla gereken öte
taraf mesafesi dışarıdan oynatılır. Nötr bir durumda bu ayar yoktur, çünkü kayma
yükle birlikte sıfırlanır.

Bu ayarın bir alt sınırı vardır. Gereken mesafe frekansla tek düze gitmez: önce
düşer, en küçük değerine ulaşır, sonra yeniden yükselir. Sınanan yapılanmada bu
en küçük değer $2{,}920810$ olup $-0{,}0395$ potansiyelinde bulunur. Yani
potansiyelin sağladığı şey istenildiği kadar ucuz bir yolculuk değil, yalnızca
**en ucuz noktaya ayarlanma** imkânıdır, ve buradan gelen kazanç toplam bedelin
yüzde beşinin altında kalmaktadır.


---

# Kısım VI. Çekirdek eşleme

Bu kısım eşlemenin girdi tarafını, yani öte taraftaki yönelimin ne anlama
geldiğini tanımlar; sonra girdiyi dönüş olayının dört koordinatına bağlar; ve
yedi adımı tek yerde yazar.

## 16. Yönelim sözlüğü

Bu bölüm Bölüm 9.5'in dokuz hücresini tek tek bu tarafa çevirir, sonra o
dokuzun gerçekte kaç tane olduğunu yeniden sayar.

### 16.1 Her hücrede korunan nicelikler

Dokuz hücrenin **tamamında** Bölge I'in enerjisi ve sürati tam olarak korunur;
sayısal artık sıfırdır. Hücreleri birbirinden ayıran tek şey Bölge I'in
momentumunun yönüdür.

| Bağıl dönme | Bölge I'de sapma (radyan) |
| ----------- | ------------------------- |
| Yok | $0$ |
| Kısmi | $0{,}961$ |
| Tam ters | $2{,}601$ |

### 16.2 Sözlük

| Öte tarafta olan | Bu tarafta görünen | Sıradan bir olaydan ayırt edilebilir mi |
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

Bölüm 9.5'in iki etiketinden biri çıkış yüzüydü ve orada bağımsız bir etiket
gibi ele alınmıştı. Oysa bağımsız değildir.

**Kurulum.** Ara bölgeyi geçmek, öte tarafın tek uzay ekseni boyunca hareket
etmektir. Hangi yüzden çıkıldığı, o eksendeki dalga sayısının **işaretiyle**
belirlenmektedir.

**Kütle kabuğu büyüklüğü sabitler, işareti serbest bırakır.** Dispersiyon
bağıntısı $q$ ile $-q$ arasında ayrım yapmaz; üç ayrı dalga sayısında her iki
dalın da bağıntıyı sıfır artıkla sağladığı denetlenmiştir.

**Yönelim büyüklüğü belirler, dalı belirlemez.** Enerji vektörünün yönünü
uzunluğunu değiştirmeden çevirmek, geçiş dalga sayısını değiştirmez. Üç ayrı
uzunlukta doğrulanmıştır.

**Öte tarafın dal seçecek bir aracı yoktur.** Bir dalı seçmek, dışarı giden
dalga koşulu koymaktır; o koşul bir zaman yönelimi gerektirir ve öte tarafta
zaman yönelimi yoktur (Bölüm 9). Bu, Bölüm 6'da iki genliğin birden
tutulmasının nedeniyle aynı nedendir.

**Ve dal Bölge I'in enerjisidir.** Bölüm 15.1'de öte tarafın tek momentumunun
Bölge I'in enerjisi olduğu gösterilmişti. Geçiş dalga sayısı tam olarak o
slottur. Dolayısıyla:

> "Hangi yüzden çıktı" sorusu ile "enerjisinin işareti ne" sorusu **aynı
> sorudur**.

Karşı yüzden dönüş, başka bir yerden gelmiş gibi değil, **negatif enerjiyle**
gelmiş gibi görünür.

Bu, tabloyu iki yerden değiştirir. Çıkış yüzü ile yönelim bağımsız etiketler
değildir, ikisi de aynı vektörün parçalarıdır. Bir de "hiç çıkmaz" satırının
yanına üçüncü bir okuma girer: negatif enerjili bir varış, sıradan bir
gözlemciye parçacık yerine karşıparçacık gibi görünebilir, ki bu literatürdeki
çift yaratımı okumasıyla aynı yere düşer.

Bu okumanın adı ve önceliği vardır. **Yeniden yorumlama ilkesi** tam olarak
bunu söyler: negatif enerjiyle zamanda geriye giden bir çözüm, pozitif enerjiyle
ileri giden bir karşıparçacıktan ayırt edilemez. İlke takyonlar bağlamında
[35]'te formüle edilmiş, [26] onu alan kuramına taşımıştır. Yukarıdaki hesap o
ilkeyi doğrulamakta, kurmamaktadır. Buradaki hesap ayırt
edilemezliğin **hangi nicelikten** çıktığını göstermiştir. İşaret, çıkış yüzünü
belirleyen vektörün aynı bileşenidir. Dolayısıyla "hangi yüz" ile "hangi işaret"
bağımsız iki soru değildir. Ayırt edilemezliğin nerede kırıldığı bu çalışmanın
kapsamı dışındadır.

**Çekince.** Bu bölümde hesaplanan şey, dispersiyon bağıntısının iki dalı da
kabul ettiği ve yönelim yönünün geçiş dalga sayısını değiştirmediğidir. "Öte
taraf dal seçemez" ifadesi bir hesap değil, zaman yöneliminin yokluğundan çıkan
bir muhakemedir; dayanağını Bölüm 9 hesaplamıştır.

### 16.4 Hücrelerin dağılımı

Yukarıdaki tablo hangi sonucun ne göründüğünü söyler, hangisinin
gerçekleşeceğini söylemez. Bu bölüm o eksiği kapatır ve cevabın ikiye
ayrıldığını bulur.

**Çıkış yüzü belirlidir.** Akı korunumu geçen ve yansıyan ağırlıkları verir ve
geriye bir şey bırakmaz:

| Ara bölge | Karşı yüzden | Giriş yüzünden | Hiç çıkmaz |
| --------- | ------------ | -------------- | ---------- |
| Kleinian | $0{,}868$ | $0{,}132$ | $0$ |
| Öklid | $0{,}111$ | $0{,}889$ | $0$ |
| Dejenere | $0$ | $1$ | $0$ |

Kayıpsız bir bölge parçacığı yutmaz. Dolayısıyla dokuz hücrenin üçü, dönme hiç
hesaba katılmadan önce, sıfır olasılıklıdır.

**Dönme belirli değildir ve iki okuma taban tabana zıttır.**

*Ayar okuması.* Öte tarafta yönelimin fiziksel içeriği yoktur (Bölüm 15.3). O
hâlde iki yüz arasındaki bağıl dönme öte taraf tarafından değil, eklem koşulları
tarafından belirlenmektedir. Simetrik bir ara bölge için dönme özdeşliktir ve **sapma
yoktur**. Bu okumada model ayırt edici hiçbir şey öngörmez.

*Bilgisizlik okuması.* Öte tarafta hiçbir yön ayrıcalıklı değildir, dolayısıyla
çıkış yönelimi küre üzerinde düzgün dağılmıştır. Bu durumda sapma açısının
dağılımı $\tfrac{1}{2}\sin\theta$ olur; hesaplanan ortalama sapma tam olarak dik
açıdır ve sonuçların yarısı dik açıdan fazla sapar. Sapmasız dönüş küre üzerinde
tek bir nokta olduğundan olasılığı sıfırdır: **geçen her parçacık imzayı
taşır**.

| Okuma | İmzanın olasılığı, Kleinian | İmzanın olasılığı, Öklid |
| ----------- | --------------------------- | ------------------------ |
| Ayar | $0$ | $0$ |
| Bilgisizlik | $0{,}868$ | $0{,}111$ |

**İki okumanın ayrılmasının değeri.** İkisi olabilecek en uzak iki tahmini
vermektedir: biri imzayı geçirgenlik oranında öngörür, diğeri hiç öngörmez.
Aradaki fark bir yorum farkı değil, **ölçülebilir** bir farktır. Parçacığı
geçiren ve bedelsiz sapma arayan tek bir deney ikisini birbirinden ayırır.

Bu, çalışmanın ayırt edici öngörüsünün bulunduğu yerdir ve ulaşılamaz bir
yüzeye değil ara bölgenin kendisine bağlıdır.

**Çekince.** İki okumanın verdiği sıfır ve bir uçları hesaplanmış değil,
**varsayılmıştır**. Ayar okumasında dönmenin özdeşlik olması, ara bölgenin
simetrik olduğu varsayımına dayanır. Bilgisizlik okumasındaki düzgün dağılım ise
hiçbir yönün ayrıcalıklı olmadığı varsayımına. Hesaplanan şey, bu varsayımlar
verildiğinde ne çıktığıdır. Hangi okumanın doğru olduğunu belirlemek eklem
koşullarının asimetrik hâlinin çözülmesini gerektirir ve burada yapılmamıştır.

Ayrıca "hiç çıkmaz" satırının sıfır olması, geçişin kayıpsız olduğu varsayımına
dayanır. Bölüm 5.4'teki madde katmanı geçişi sönümlü kılarsa bu satır sıfır
olmaktan çıkar.

### 16.5 Dönmenin nicelenmesi

Önceki bölümün iki ucu da varsayımdı. Modelin içinde, varsayım gerektirmeyen
üçüncü bir cevap zaten duruyor.

**Yapı.** Bölüm 4.1'de bütün filtreleri geçen sekiz matris kalmıştı;
aralarındaki tek fark uzay eksenlerinin etiketlenmesiydi. Ara bölgenin **her
yüzü bunlardan birini gerçekler**. İki yüz aynı matrisi gerçeklerse gidiş dönüş
bileşkesi özdeşliktir. Farklı matrisleri gerçeklerse bileşke belirli bir
dönmedir.

Dolayısıyla dönme ne serbest bir parametredir ne de düzgün dağılmıştır; sekiz
matrisin bileşkelerinin oluşturduğu **sonlu bir kümeden** değer alır.

**Hesap.** Altmış dört eşleşmenin 32'si Bölge I'in enerjisini korur ve bunların
24'ü momentumu döndürür. Gelen momentum $(1,2,3)$ için ortaya çıkan sapma tayfı:

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
ve Bragg yasasını bu yolla elde eder. Ayrıklığı üreten şey orada örgünün
periyodikliği, burada çıkış yüzlerinin sonlu kümesidir; ikisinde de ayrıklık
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

$\pm D$ ayrımı test edildi: her iki işaret de $\det = +1$ ve $M^2 = I$
koşullarını sağlar, dolayısıyla bu koşullarla ayırt edilemezler. Ancak Bölüm
9'daki bulgu işaretin anlamını netleştirir:

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
Newton, Maxwell ve Schrödinger denklemlerinin hepsi $T$-simetriktir; ok
başlangıç koşulundan gelir.

### 16.7 $D$'nin yön-bağımlı involüsyonla karşılaştırması

$D$'yi yön-bağımlı bir involüsyonla karşılaştırmak, onun grup içindeki yerini
netleştirir. $\theta = \varphi = 0$ ekseni için yön-bağımlı involüsyon $t$ ile
$z$'yi işaretli olarak takas eder ve $\Lambda_{\inf}^2 = I$ sağlar; yani o da
bir involüsyondur, ancak yalnızca iki koordinatı değiştirir.

$D$ ise dört koordinatı birden değiştirir ve içinde bir $x \leftrightarrow y$
takası barındırır. Bu takasın üç boyuttaki determinantı $-1$'dir, dolayısıyla
bir $SO(3)$ elemanı değildir. Bunun doğrudan sonucu şudur:

> $D$, yön-bağımlı involüsyonun ürettiği genişletilmiş grup $L_{\text{ext}}$
> içinde **bulunmaz**.

Yani $D$ ile yön-bağımlı formlar aynı ailenin iki üyesi değildir; farklı
yapılardır.

### 16.8 Öte tarafta hareketin tanımı

Çıkış yüzü Bölüm 16.3'te Bölge I'in enerjisinin işareti olarak belirlendi, çıkış
anı ise Bölüm 13'te genliğin fazından okundu. İkisi de parçacığın ara bölgede
**ne yaptığına** bağlanmamıştı. Bu bölüm o bağlantıyı kurar; simülasyonun
canlandıracağı nicelik tam olarak budur.

Öte tarafın dört ekseninin karakterini Bölüm 10.1 vermiştir. Bir durum, üç
zaman uzayındaki bir enerji vektörü ile tek uzay ekseni boyunca bir dalga
sayısından oluşur. Parçacığın yapabileceği iki şey vardır ve yalnızca ikisi:

1. **Geçiş yönünde yer değiştirme.** Tek uzay ekseni boyunca ilerlemek. Ara
 bölgeyi kat etmek budur.
2. **Enerji vektörünün dönmesi.** Üç zaman düzleminden birinde bir açı süpürmek.
 Dönme vektörün uzunluğunu korur ve bu denetlenmiştir.

Birinci hareket bir yolculuktur, ikincisi bir yönelimdir. Sorulacak soru şudur:
iki gözlenebilir, yani çıkış yüzü ve çıkış anı, bu iki hareketten hangisini
görür.

### 16.9 Çıkış anı ve yolculuk süresi

Ara bölge yayılıma izin veriyorsa geçiş ekseni boyunca bir grup hızı tanımlıdır
ve kalınlığın bu hıza bölümü bir yol süresi vermektedir. Fazdan okunan çıkış anıyla
karşılaştırıldığında ikisi birebir tutar:

| Kalınlık $d$ | Yol süresi | Fazdan okunan an |
| ------------ | ---------- | ---------------- |
| $1$ | $1{,}0776$ | $1{,}0776$ |
| $2$ | $2{,}1553$ | $2{,}1553$ |
| $4$ | $4{,}3105$ | $4{,}3105$ |

Artık $10^{-12}$ mertebesindedir. Bu rejimde çıkış anı gerçekten bir yolculuk
süresidir ve parçacık dili tam anlamıyla meşrudur.

Engel rejiminde durum niteliksel olarak değişir. İçerideki mod sönümlüyse grup
hızı **yoktur**, dolayısıyla yol süresi tanımsız kalır. Buna karşılık faz hâlâ
belirli bir an verir:

| Kalınlık $d$ | Yol süresi | Fazdan okunan an |
| ------------ | ---------- | ---------------- |
| $2$ | tanımsız | $1{,}4629$ |
| $4$ | tanımsız | $1{,}4629$ |
| $8$ | tanımsız | $1{,}4629$ |

Bu, Bölüm 13.4'teki Hartman doyumunun hareket dilindeki karşılığıdır ve okunuşu
şudur: gecikmenin kalınlıkla artmaması **hızlı bir yolculuk** değil,
**yolculuğun yokluğudur**. Kat edilen bir mesafe yoktur; elde yalnızca faz
vardır.

Bu ayrımın modelin geneli açısından sonucu şudur: parçacık okuması ile dalga
okuması burada ayrışır. Dalga okuması her iki rejimde de tanımlıdır, parçacık
okuması yalnızca yayılımlı rejimde tanımlıdır. Ayrışmanın kendisi bir sonuçtur.

### 16.10 Çıkış yüzünün körlüğü

Enerji vektörünün üç zaman düzleminden herhangi birinde, herhangi bir açıyla
döndürülmesi geçiş dalga sayısını değiştirmez. Kütle kabuğu o dalga sayısının
büyüklüğünü vektörün yalnızca **uzunluğundan** belirler, dönme ise uzunluğu
korur.

Üç düzlemin her birinde yirmi dört açı ve üç farklı vektör uzunluğu tarandığında
geçiş dalga sayısındaki en büyük değişim $10^{-9}$'un altındadır. Dolayısıyla
çıkış yüzü, parçacığın orada izlediği yola tümüyle kördür. Yüz, ara bölgenin
içinde değil, yüzeylerde belirlenmektedir.

### 16.11 Çıkış anının gördüğü düzlemler

Çıkış anı ise dönmeye kör değildir, ancak seçicidir. Öte tarafın enerji vektörü,
geçiş altında Bölge I'in üç momentumudur; bileşenlerinden biri geçiş yönüne,
ikisi enine yönlere karşılık gelir. Bir dönme, ancak geçiş yönüyle enine yönler
arasında ağırlık taşırsa çıkış anını değiştirir.

| Dönme düzlemi | Çıkış anına etkisi |
| --------------------------------- | ------------------ |
| İki enine yuvanın gerdiği düzlem | Yok |
| Geçiş yuvasına dokunan iki düzlem | Var |

Enine düzlemdeki dönme enine bileşenlerin kare toplamını korur; artık $10^{-12}$
mertebesindedir. Diğer iki düzlemde dönme o toplamı değiştirir ve çıkış anı
kayar.

Bu, gözlemsel olarak anlamlı bir ayrımdır: parçacığın öte tarafta **hangi
düzlemde döndüğü** buradan çıkarılabilir, çıkış anına bakılarak. Buna karşılık
**hangi yüzden çıktığı** hiçbir düzleme bağlı değildir.

### 16.12 İçerideki yolun izi

İçeride süpürülen açı süreklidir; dönme açısı serbest bir parametredir ve
birbirine ne kadar yakın iki değer seçilirse seçilsin farklı iki yol elde
edilir. Örnek olarak, çeyrek turluk bir dönme $1{,}1102$ radyan süpürür. Buna
karşılık buraya ulaşan sapma, Bölüm 16.5'in nicelenmiş tayfının bir elemanıdır
ve momentum $(1,2,3)$ için o tayf **üç** değerlidir.

Sürekli bir küme burada üç elemanlı bir kümeye düşmektedir. Bu düşüş, Bölüm
1.10'un dokuzuncu maddesinin somut karşılığıdır: öte taraftaki yönelim, dönüş
olayının koordinatlarına ancak bir kısmıyla ulaşır. Kaybolan şey, parçacığın öte
tarafta izlediği yolun kendisidir. Geriye yalnızca o yolun iki ucu arasındaki
bileşke dönmenin nicelenmiş izi kalır.

**Bağlantının özeti.**

| Gözlenebilir | Neyi görür | Nerede belirlenir |
| ------------ | ------------------------------------------------------ | --------------------- |
| Çıkış yüzü | Hiçbir içeri hareketini | Yüzeylerde |
| Çıkış anı | Yayılım varsa yolculuğu; dönmeyi üç düzlemden ikisinde | İçeride ve yüzeylerde |
| Sapma | Yolun yalnızca bileşkesini, nicelenmiş olarak | Yüzeylerde |

---

## 17. Koordinat sözlüğü

Çekirdek soru şudur: öte tarafta dört koordinatın her birinde hareket etmenin ya
da yönelmenin Bölge I'deki karşılığı nedir. Bu bölüm o sözlüğü kurar; Bölüm 18
sözlüğü kullanarak dönüş olayını hesaplamaktadır.

### 17.1 Sözlüğün burada kullanılan biçimi

Dört yuvanın karakteri, hangi yuvaya indiği ve bir birim adımın Bölge I saatinde
ne ürettiğini Bölüm 10.1 tablo hâlinde verir ve bu bölüm onu tekrarlamaz. Bu
bölümün ihtiyaç duyduğu iki sonuç şudur: dört yuvanın dördü de eşikte karakter
değiştirir ve buna karşın hareket serbestliği yuva yuva korunmaktadır. Öte tarafın üç
zamanında serbestçe hareket edilir ve o üç zamanın taşıdığı Bölge I uzay
yönlerinde de. Öte tarafın tek uzay ekseninde yön seçilemez ve onun taşıdığı
Bölge I zamanında da seçilemez.

Tek yönlü koordinatın iki bölgede **ayna yerlerde** durması bu sözlüğün en sıkı
ifadesidir: Bölge I'in zamanı ile Bölge II'nin tek uzay ekseni aynı
koordinattır ve ikisinde de yön seçilemez.

"Tek yönlü" ifadesinin içindeki iki ayrı iddiayı, yani yönlendirilebilirlik ile
ilerleme zorunluluğunu, Bölüm 9.3 ayırır ve yalnızca birincisinin hesaplandığını
göstermektedir.

Bu ifadenin Bölüm 4.1.3'ün sonucuyla nasıl bir arada durduğu da orada yazılıdır.
Yön seçilemez, çünkü cisim o eksende geri dönemez. Dönüş anının işareti ise
cismin yürüyüş yönünden değil, hangi geçiş eşlemesinin kullanıldığından gelir.
İki ifade farklı niceliklerden söz eder ve birbiriyle çelişmez.

### 17.2 Yönelimin gözlenemezliği

Üç zaman arasında bir $O(3)$ simetrisi vardır ve bu bir ayar fazlalığıdır.
Sonucu şudur: öte tarafta enerji vektörünün **yönü** fiziksel değildir, yalnızca
**uzunluğu** fizikseldir. Vektör döndürülebilir, ama orada bu dönmenin
gözlenebilir bir karşılığı yoktur.

Yönelimin büyüklüğünü belirleyen şey kütle kabuğudur. Uzunluk, parçacığın
enerjisi ve kütlesiyle sabitlenir; üç zaman düzlemlerinden herhangi birinde
döndürmek uzunluğu değiştirmez, artık $10^{-16}$ mertebesindedir.

> Parçacık öte tarafta **yönünü seçebilir, uzunluğunu seçemez.**

### 17.3 Üç zamandaki hareketin etkisi

Çekirdek sorunun en can alıcı yeri budur ve cevabı iki katmanlıdır.

**Doğrudan yol kapalı kalır.** Bölüm 10.1'in tablosu bunu vermektedir: üç zamanın
her birinde bir birim adımın Bölge I saatindeki karşılığı tam olarak sıfırdır,
tek uzay ekseninde ise tam olarak birdir.

Yani "orada zamanda yürüdüm, burada zamanda kaydım" cümlesi involüsyonun kendisi
tarafından **desteklenmez**. Involüsyon o hareketi Bölge I'in uzayına gönderir.

**Dolaylı yol açıktır.** Aynı enerji vektörünün bileşenleri, iki yüzeydeki
eşleşmeye girer ve dönüş anı o eşleşmenin fazından okunmaktadır. Uzunluk sabit tutulup
yalnızca yön değiştirildiğinde dönüş anı değişir: yönelim küresi tarandığında
ulaşılan aralık, uzunluk $3$ için $62{,}4$ birimdir.

> Öte taraftaki yönelim, Bölge I'in zaman ekseninde **başka bir konumu işaret
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

**Birincisi, aralık uzunlukla daralır, genişlemez.** Daha hızlı bir parçacık
dönüş anı üzerinde daha **dar** bir seçim aralığına sahiptir. Bu, beklenenin
tersidir ve hesabın sonucudur.

**İkincisi, aralığın büyüklüğü yanıltıcıdır.** Aralığa hâkim olan katkı, yüzeye
teğet geçen yönelimlerden gelir; orada normal dalga sayısı sıfıra gider ve
gecikme ıraksar. Bu nedenle $62{,}4$ sayısı fiziksel bir manevra kabiliyeti
değil, bir limit davranışıdır. Teğetlikten uzakta da yönelim dönüş anını
değiştirmeye devam eder, dolayısıyla etki bir ıraksama artefaktı değildir; ancak
büyüklüğü bu sayının verdiği izlenimden küçüktür.

### 17.5 Yönelim izinin kaynağı

Bölüm 17.3 yönelimin dönüş anını değiştirdiğini saçılma yoluyla buldu. Bu alt
bölüm aynı soruyu bağımsız bir yoldan sorar ve **etkinin nerede doğduğunu**
belirlemektedir.

**Ölçüt.** Bir durum aynı anda birden çok zaman değişkeninde evriliyorsa, her
biri kendi üretecini taşır ve bu evrimler ancak zamanlar uzayındaki taşımanın
yoldan bağımsız olması hâlinde tutarlı kalır. Bu koşul, bileşenleri üreteçlerin
ikişerli komütatörleri olan bir eğriliğin sıfırlanmasını gerektirir. Ölçüt bu
çalışmaya ait değildir: çok zamanlı dalga fonksiyonları için [18] ve [19]'da
kurulmuştur; ikincisi onu genel etkileşim potansiyelleri için tutarlılığın tam
koşulu olarak verir. [18] ayrıca burada önemli olan ayrımı yapar: çok
zamanlı bir betimleme, birden çok zamansı boyut demek değildir. Burada
uygulanan, o ölçütün kendisidir. Eğrilik sıfırsa yol hiçbir bilgi taşımaz ve tek
zamana indirgeme belirsizlik içermez; sıfır değilse kapalı bir yol durumun
üzerinde bir holonomi bırakır ve zamanlar arasındaki yönelim gözlenebilir hâle
gelir.

**Serbest kuram düzdür.** Öte tarafın serbest alanı için üç üreteç, tek bir
enerji vektörünün bileşenleridir ve komüte ederler; üç eğrilik bileşeninin üçü
de tam olarak sıfırdır. Kapalı bir yolun holonomisi, yolun uzunluğu ne olursa
olsun kaybolur; bu, $1000$ birimlik yol için de denetlenmiştir.

> İçerideki yol, serbest evrim tarafından **kaydedilmez**. Dolayısıyla Bölüm
> 17.3'te bulunan yönelim bağımlılığının kaynağı ara bölgenin içi olamaz.

**Eğriliği yüzeyler getiriyor.** İki eşik yüzeyindeki eşleşme, geçiş
doğrultusunu enine doğrultulara karıştırır ve üreteçler bu karışım altında
komüte etmeyi bırakır. Eğrilik bağlaşım gücüyle doğru orantılıdır ve bağlaşım
sıfırlandığında tümüyle kaybolur, dolayısıyla etkinin **tamamı** yüzeylere
aittir.

**İki hesabın örtüşmesi.** Bu, bağımsız bir sınamadır ve durum durum tutar:

| Durum | Yüzey eğriliği | Saçılmanın dönüş anını oynatması |
| -------------------------------------------------------------------------------- | -------------- | -------------------------------- |
| Geçiş yuvasında ağırlığı olmayan vektör, diğer iki yuvanın düzleminde döndürülür | $0$ | $0$ |
| Genel bir vektör, geçiş yuvasına dokunan düzlemde döndürülür | $3{,}000$ | $1{,}6383$ |

Ayrıca eğrilik yalnızca geçiş yuvasına dokunan iki düzlemde sıfırdan farklıdır;
diğer iki yuvanın gerdiği düzlem, yüzeyler dâhil edildiğinde bile düzdür. Bu,
Bölüm 16.11'de fazdan bağımsız olarak bulunan seçimin **aynısıdır**: çıkış anı
üç zaman düzleminden ikisini görür, birini görmez. İki ayrı yoldan aynı iki
düzleme varılmıştır.

**Sonuç.** Yönelimin Bölge I'in zaman eksenindeki izi gerçektir, ancak ara
bölgenin içinde değil, **sınırında** doğar. Bunu iki hesaptan hiçbiri tek başına
söyleyemez: saçılma etkinin varlığını verir, eğrilik ölçütü yerini vermektedir.

---

## 18. Yönelimden dönüş olayına

Önceki bölümler eşlemenin parçalarını ayrı ayrı kurdu. Bu bölüm o parçaları tek
bir hesapta birleştirir ve eşlemenin tanım kümesini baştan sona tarar.

### 18.1 Tanım kümesi

Öte taraftaki bir durum iki veriden oluşur:

1. **Yönelim.** Üç zaman uzayındaki enerji vektörünün doğrultusu. Uzunluk kütle
 kabuğu tarafından sabitlendiğinden, doğrultu bir **iki-küre** üzerinde
 değişir.
2. **Dal.** Tek uzay ekseni boyunca dalga sayısının işareti. İki değer alır.

Dolayısıyla yönelim uzayı $S^2 \times \mathbb{Z}_2$'dir. Taramada bu uzay $312$
duruma ayrıklaştırılmıştır.

### 18.2 Değer kümesi

Dönüş olayı Bölge I'in bir noktasıdır ve giriş olayına göre dört koordinatı
vardır:

$$(t,\; x_{\perp},\; y,\; z)_{\text{dönüş}}$$

Burada $t$ geçen süre, $x_{\perp}$ geçiş doğrultusundaki yer değiştirme, $y$ ve
$z$ enine yer değiştirmelerdir. Her dördü de öte taraftaki durumdan hesaplanır:

| Koordinat | Nereden gelir |
| ----------- | --------------------------------------------------------------------- |
| $t$ | İki geçişin ortak genliğinin fazından; içeride saat taşınamadığı için |
| $x_{\perp}$ | Daldan: sıfır ya da kalınlık, yani hangi yüzden çıktığı |
| $y,\, z$ | Paket merkezinin kayması, yönelimin enine bileşenlerine dağıtılmış |

Taranan $312$ durumun tamamı sonlu ve belirli bir olaya gider; eşlemede tanımsız
nokta yoktur. Üç örnek durum, eşlemenin ne verdiğini somutlaştırır ($d = 2$,
uzunluk kütle kabuğundan):

| Kutup açısı | $t$ | $x_{\perp}$ | $(y,\, z)$ |
| ----------- | ----------- | ----------- | -------------------------- |
| $0{,}4$ | $23{,}8700$ | $2{,}0000$ | $(+0{,}0015,\; +0{,}0041)$ |
| $1{,}2$ | $9{,}9732$ | $2{,}0000$ | $(+0{,}0037,\; +0{,}0016)$ |
| $2{,}5$ | $15{,}5319$ | $2{,}0000$ | $(+0{,}0024,\; -0{,}0036)$ |

Geçiş doğrultusundaki yer değiştirme üçünde de aynıdır, çünkü yalnızca dalı
görür; geçen süre ile enine yer değiştirmeler ise yönelimle birlikte
değişmektedir.

### 18.3 Koordinatların gördüğü durum bileşenleri

Eşlemenin yapısı, koordinatların birbirinden bağımsız kaynaklara bağlanmasıdır:

| Koordinat | Yönelimi görür mü | Dalı görür mü |
| ----------- | ----------------- | ------------- |
| $t$ | Evet | **Hayır** |
| $x_{\perp}$ | **Hayır** | Evet |
| $y,\, z$ | Evet | Hayır |

Bu tablonun en önemli satırı ilkidir: **parçacığın ne zaman döndüğü ile nereden
döndüğü ayrı şeyler tarafından belirlenmektedir.** Zaman bileşeni dala tümüyle kör,
geçiş yer değiştirmesi ise yönelime tümüyle kördür.

### 18.4 Eşlemenin tanım kümesini sıkıştırması

$312$ durum $158$ farklı olaya gitmektedir. Eşleme birebir değildir; öte
taraftaki farklı durumlar burada aynı olaya varır. Bu sıkışma, boyut
değişiminde kaybolan bilginin niceliksel ölçüsüdür ve Bölüm 16.12'deki sapma
tayfının sürekliden ayrığa düşmesiyle aynı olgunun bir başka görünümüdür.

### 18.5 Işık sinyaliyle karşılaştırma

Çekirdek sorunun asıl hedefi zaman bileşenidir. Karşılaştırma ölçütü, aynı gidiş
dönüşü ışığın yapması için gereken süredir, yani $2d/c$.

Engel rejiminde ($\omega = 2{,}8$, Öklid ara bölge):

| Kalınlık $d$ | Işığın gerektirdiği | Parçacığın dönüş anı | Fark |
| ------------ | ------------------- | -------------------- | ------------ |
| $2$ | $4{,}00$ | $2{,}9258$ | $+1{,}0742$ |
| $4$ | $8{,}00$ | $2{,}9257$ | $+5{,}0743$ |
| $8$ | $16{,}00$ | $2{,}9257$ | $+13{,}0743$ |
| $16$ | $32{,}00$ | $2{,}9257$ | $+29{,}0743$ |

Buradaki iki sütun **aynı ayakta** ölçülmektedir ve bu bir düzeltmedir. Işık
süresi gidiş dönüştür, yani $2d/c$; dolayısıyla parçacığın geçen süresi de
bölgenin iki kez katedilmesidir, yani tek geçişin iki katıdır. Önceki bir
sürümde gidiş dönüş ışık süresi, **tek geçişlik** bir gecikmeyle
karşılaştırılıyordu ve bu, geçişi tam bir geçiş kadar kayırıyordu. Bölüm
18.7'nin kapalı biçimi hangisinin hangisi olduğunu kesinleştirir: tek bir engel
için doymuş faz süresi $2\omega/(c^2\kappa\beta)$'dır, yani $1{,}4629$ tek
geçiştir.

Dönüş anı kalınlıkla doyduğu, ışık süresi ise doymadığı için **fark sınırsız
büyür**; fark $2d - 2{,}9257$ olarak gider. Bölge ne kadar kalınlaştırılırsa,
dönüş olayı ışığın varabileceği andan o kadar öne düşer.

### 18.6 Farkın kapsamı ve sınırları

Çalışmanın kendi çekincesi burada durmaktadır.

**Olduğu şey.** Dönüş olayının zaman koordinatı, kesintisiz hiçbir ışık
sinyalinin ulaşamayacağı bir yerdedir. Çekirdek sorunun "zamanda yolculuk"
kısmı, bu koordinatın konumu olarak tanımlanmıştır ve hesap onu vermektedir.

**Olmadığı şey.** Bu, ışıktan hızlı bir **yayılma** değildir. Aynı rejimde
içeride grup hızı diye bir nicelik yoktur, çünkü mod sönümlüdür ve sönümlü
bir modda kat edilen bir mesafe bulunmaz. Ölçülen şey, dönen paketin
**tepe noktasının** nereye düştüğüdür.

**Ve bir sinyal taşımadığı.** Ayrım burada zorunludur, çünkü üstışık bir
sinyalin geçmişe ulaşmasının nedensel bedeli [36]'da sayılmıştır: böyle bir
düzenek ya negatif sonuç verir ya da çelişki üretir. Aşağıdaki hesap bir sinyal
iddiası taşımadığı için o ikilemin dışında durur. Bu nokta açık bırakılmamış,
hesaba dâhil edilmiştir: çalışma dalganın ön cephesini tepesinden ayrı
hesaplamaktadır. Cephe hızı frekans büyüdükçe ışık hızına iner ve ara bölge
cepheyi hiçbir kalınlıkta öne almaz. Tepenin öne alınması büyürken de onu
taşıyan genlik çökmektedir: $d = 32$ için $5{,}2 \times 10^{-32}$'ye iner. Yukarıdaki $+29{,}0743$,
bir mesajın ışığı geçtiği anlamına gelmez ve bu çalışma öyle bir iddiada
bulunmamaktadır.

**Ayrıca tek okuma da değildir.** Aynı genlikten türetilen beş okuma vardır ve
üçü geçişi ışığın üstüne, ikisi altına koyar; ayrım kalınlıkla değişmez.
Yukarıdaki tablo faz okumasına dayanır, çünkü sorulan soru dışarıdaki bir
dedektörde tepenin ne zaman göründüğüdür. Bu bir seçimdir ve seçimi kurmayan
bir ölçüt Bölüm 11.6'da onu doğrular: yayılan paketin tepesi ölçüldüğünde
tutan okuma fazdır.

### 18.7 Eşlemenin kapalı biçimi

Bölüm 18.1 ile Bölüm 18.6 arası eşlemeyi **tarayarak** vermiştir. Tarama bir cevap
değildir: bu durumların nereye döndüğünü söyler, eşlemenin **ne olduğunu**
söylemez. Bu bölüm onu formül olarak yazmıştır. Yapılan tarama literatürde bu
eşlemenin hiçbir biçimini bulmamıştır; aşağıdakini bu çalışma üretir.

**İki özdeşlik formülü kısaltıyor ve ikisi de yaklaşık değil tamdır.**

**Birinci özdeşlik.** Dış normal dalga sayısı, enerji vektörünün **birinci
bileşenidir**. Kütle kabuğu frekansı uzunluktan sabitler, enine dalga sayısı
öteki iki bileşenin uzunluğudur ve fark birinci bileşeni yalnız bırakır:

$$\kappa^2 = \frac{\omega^2}{c^2} - k_\perp^2 - \mu = (E_1^2 + E_2^2 + E_3^2 + \mu) - (E_2^2 + E_3^2) - \mu = E_1^2$$

$$\boxed{\;\kappa = |E_1|\;}$$

Yani modun yüzeyle nasıl karşılaştığına karar veren nicelik, yönelimin bir
fonksiyonu değil, **bir koordinatıdır**. Bu, tüm formülü kısaltan şeydir.

**İkinci özdeşlik.** İç sönüm sabiti aynı üç bileşenden, tek ek girdi olarak
çevrilen yön sayısı $n$ ile kurulur:

$$\beta^2 = \frac{2n}{3}\,(E_2^2 + E_3^2) - E_1^2$$

Dolayısıyla geçişin engel mi geçit mi olduğu, bileşenler arasında düz bir
eşitsizliktir. Öklid ara bölge için ($n = 3$):

$$\text{engel} \iff 2(E_2^2 + E_3^2) > E_1^2$$

**Geçen süre, kapalı biçimde.** Engel rejiminde, **tek geçiş** için:

$$\boxed{\; t(\mathbf{E}) \;=\; \frac{2\,\omega}{c^2\,\kappa\,\beta} \;=\; \frac{2\sqrt{E_1^2+E_2^2+E_3^2+\mu}}{|E_1|\;\sqrt{2(E_2^2+E_3^2)-E_1^2}} \;}$$

(son eşitlik $c = 1$ ve Öklid ara bölge içindir.)

Gidiş dönüş bölgeyi iki kez kateder, dolayısıyla dönüş olayının zaman koordinatı
bunun **iki katıdır**:

$$t_{\text{gidiş dönüş}}(\mathbf{E}) \;=\; \frac{4\,\omega}{c^2\,\kappa\,\beta}$$

Bölüm 18.5'in tablosu bu nicelikle kurulur; ışık süresi de gidiş dönüş olduğu
için ikisi aynı ayaktadır.

**İçinde kalınlık yoktur.** Doyum burada bir tabloda fark edilen bir şey değil,
bir **özdeşliktir**. Saçılma hesabıyla karşılaştırıldığında:

| $d$ | Saçılma hesabı | Kapalı biçim | Artık |
| ---- | -------------- | ------------ | ----------------------- |
| $4$ | $1{,}462864$ | $1{,}462864$ | $3{,}9 \times 10^{-8}$ |
| $8$ | $1{,}462864$ | $1{,}462864$ | $6{,}6 \times 10^{-11}$ |
| $16$ | $1{,}462864$ | $1{,}462864$ | $7{,}1 \times 10^{-11}$ |
| $32$ | $1{,}462864$ | $1{,}462864$ | $7{,}2 \times 10^{-11}$ |

**Sonlu kalınlık biçimi.** Doyum henüz kurulmamışken de geçerli olan tam biçim,
doyuran çarpanı açıkça taşır.
$u = 2\kappa\beta / [(\kappa^2-\beta^2)\tanh(\beta d)]$ olmak üzere:

$$\arg T = \frac{\pi}{2} - \arctan u, \qquad t = -\frac{1}{1+u^2}\,\frac{du}{d\omega}$$

$$\frac{d\kappa}{d\omega} = \frac{\omega}{c^2\kappa}, \qquad \frac{d\beta}{d\omega} = -\frac{\omega}{c^2\beta}$$

$\tanh(\beta d) \to 1$ limitinde $u \to 2\kappa\beta/(\kappa^2-\beta^2)$ olur,
kalınlık düşer ve yukarıdaki kapalı biçim geri gelir. Sonlu kalınlıkta da
saçılma hesabıyla örtüşür: $d = 1$ için $1{,}451403$, $d = 2$ için $1{,}462898$,
ikisi de her iki yoldan aynıdır.

**Dört koordinatın tamamı.** Öte taraftaki durum, üç zamandaki enerji vektörü
$\mathbf{E}$ ile tek uzay eksenindeki dal $\sigma = \pm 1$'dir. Dönüş olayı:

$$t = \frac{4\omega}{c^2\,|E_1|\,\beta}, \qquad
x_\perp = d\,\frac{1+\sigma}{2}, \qquad y = S(d)\,\frac{E_2}{|\mathbf{E}|},
\qquad z = S(d)\,\frac{E_3}{|\mathbf{E}|}$$

Burada $S(d)$ paket merkezinin kaymasıdır ve iki enine koordinatın **ortak**
çarpanıdır. Okunuşu:

> **Ne zaman** döndüğü yalnızca yönelime bakar, dala hiç bakmaz. **Nereden**
> çıktığı yalnızca dala bakar, yönelime hiç bakmaz. **Ne kadar saptığı** ise
> yönelimin enine bileşenlerine bakar ve iki sapma tek bir çarpanı paylaşır.

Taranan olayın her koordinatı bu formülle yeniden üretilmektedir. Dolayısıyla
tarama artık cevaba giden tek yol değil, **formülün üzerindeki bir denetimdir**.

### 18.8 Yönün buradan seçilebilirliği

Formül, öte taraftaki yer değiştirmeyi veri almaktadır. Yer değiştirmenin **işareti**
dönüş anını doğrudan belirlediğine göre, o işaretin buradan kurulup
kurulamayacağı ayrı ve meşru bir sorudur.

**İki soru birbirinden ayrıdır.** Birincisi hangi geçiş eşlemesinin
gerçekleştiğidir. Bu soru, Bölge I'in zaman yuvasıyla öte tarafın ayrıcalıklı
uzay eksenini **birlikte** ters çeviren dönüşüme bakar ve o dönüşüm ayrıca
incelenmiştir. Buradaki soru ise eşleme verilmişken **yolculuğun yönüdür** ve
yalnızca geçiş ekseninin ters çevrilmesine bakar. İşaret dizileri olarak
yazıldığında birincisi $(-1,-1,+1,+1)$, ikincisi $(+1,-1,+1,+1)$'dir; çarpımları
$(-1,+1,+1,+1)$, yani Bölge I zamanının saf ters çevrilmesidir. İki işlem farklı
grup öğeleridir ve biri hakkındaki bir teorem ötekini kapatmaz.

**Geçişi biçimlendirerek yön verilemez.** Literatürdeki karşılıklılık sonucu
şunu söyler: her iki uçta yön başına tek bir yayılan kanal varsa, uzaysal olarak
bakışımsız bir engelin geçirgenliği soldan ve sağdan giriş için aynıdır. Bu,
zamanda tersinirlik ile birimsellikten çıkar. Bu sonuç olduğu gibi benimsenmez; burada
kurulmuş profiller onu yeniden üretmiştir. Çarpık profil için geçirgenlik iki yönde
de $4{,}9096125448 \times 10^{-3}$ çıkar ve fark $7 \times 10^{-18}$
mertebesinde kalır. Profilin gerçekten bakışımsız olduğu ayrıca doğrulandı.
Dolayısıyla eşitliği profilde saklanan bir bakışım değil, teorem vermektedir.
Kurulmuş beş profilin hiçbiri iki yönde farklı geçirmez.

> Tek kanallı bir gönderimde yolculuğun yönü, parçacığın zaten taşıdığı
> işarettir. Engelin biçimi, kalınlığı ve bakışımsızlığı bu işareti
> **değiştirmez**.

**Karşılıklılığın açık bıraktığı tek yer, gelen durumun kendisidir.** Eşevreli
bir kanal çiftinin taşıdığı yön, kanallar arası bağıl fazın tekil bir
fonksiyonudur. Ağırlıkları $A$ ve $B$, bağıl fazı $\varphi$ olan bir çift için
yön göstergesi $2AB\sin\varphi$ olur. $\varphi$ işaret değiştirdiğinde
göstergenin işareti de değişir. Yani yanlılık engelde değil, gelen durumdadır.

Bu, dal taramasının öteki uçtan vardığı gereksinimle **aynı biçimdedir**: tam
olarak bir eksende tek olan bir nicelik. Orada eşleme seçimi için, burada
yolculuk yönü için çıkmaktadır.

İki ters çevirmenin ayrı tutulması özgün bir gözlem değildir. Saçılma kuramının
olağan sınıflandırmasında karşılıklılık, zamanda tersinme ve uzaysal evirme
**ayrı işlemlerdir** ve karşılıklılık yalnızca geçirgenlik genliklerini bağlar.
Burada yapılan, o sınıflandırmanın bu geçişe uygulanmasıdır.

**Burada bir sonuç iddiası bulunmamaktadır.** Öte taraf tek bir uzay ekseni
taşır ve yukarıdaki çift geçişten türemez; bu bölüm onu elle yazar. Böyle bir
kanal yapısını bu çalışma **sağlamamaktadır**. Dolayısıyla bu alt bölüm bir yön
verme yöntemi kurmaz; yön vermenin inşa edilmesi gereken **tek yerini** işaret
eder.

### 18.9 Parçacık öte taraftayken gözlenebilenler

Yer değiştirmenin buradan seçilemediği görüldükten sonra, en azından
gözlenebilir olup olmadığı sorulmalıdır.

**Konumlandırma reddedilir.** Uzaysal türden bir dörtlü momentum, öz durumları
nedenselliğe saygı gösteren bir konum işlemcisi kabul etmez; dolayısıyla
parçacığın öte tarafta nerede olduğunu söyleyen bir durum yoktur. Bu çalışma
böyle bir durum da sağlamamaktadır ve bunu hesaplamaz, kaydeder.

**Var olan yöntem parçacığa değil, sınıra bakar.** Eksik kütle yöntemi, giren ve
çıkan her şeyi ölçüp farkın değişmezini kurar; uzaysal türden bir taşıyıcı, bu
değişmezin negatif çıkmasıyla kendini belli eder. Öznesi yolcu değil,
bilançodur.

Ne var ki yöntem, etkileşimden ayrılan **gerçek bir kütle kabuğu momentumunu**
varsayar; ve bu çalışmadaki iç bölge her zaman böyle bir momentum taşımaz.
Öklidyen bir bölgede, enine kare toplamı 4 ve $c = \mu = 1$ iken, iç mod
$\omega = \sqrt{13} \approx 3{,}6056$ frekansının altında söner, üstünde
yayılır:

| $\omega$ | Geçiş dalga sayısının karesi | Kütle kabuğunda | Gidiş dönüş rejimi |
| -------- | ---------------------------- | --------------- | ------------------ |
| $1{,}5$ | $-10{,}75$ | hayır | evet |
| $2{,}8$ | $-5{,}16$ | hayır | evet |
| $6$ | $+23{,}00$ | evet | hayır |
| $12$ | $+131{,}00$ | evet | hayır |

**Denetlenen şey gerek koşul, yeter koşul değil.** Yöntemin gerçekten okuduğu
nicelik, dörtlü momentumun bir değişmezinin işaretidir. Yukarıdaki sütun ise tek
bir eksen boyunca dalga sayısının karesidir, yani **başka bir nesnedir**. Bu
çalışma o değişmezi hiçbir yerde hesaplamamakta, dolayısıyla bir kütle imzası da
iddia etmemektedir. Elde kalan sonuç rejim ayrımının kendisidir.

İki rejim birbirinin tümleyenidir. İki ayrı yoldan yazılmış iki yüklem hesapta
uyuşur: biri iç dalga sayısından gelir, öteki eşik eniyilemesinin kullandığı
engel testinden. Taranan dört bin frekansın hiçbiri, iç modu kütle kabuğuna
oturtup aynı anda gecikmenin doymasına izin vermemektedir. Bu tümleyenlik de
yeni bir olgu değildir: sönümlü modun kendisi geçiş süresine katkı vermez,
dolayısıyla gecikmenin doyması zaten iç bölgenin sönümlü olmasını gerektirir.
Burada yapılan, bilinen bu bağın bu bölgeye uygulanıp gözlemle karşı karşıya
getirilmesidir. Sonuç bu nedenle bir yöntem değil, bir **gerilimdir**:

> İç bölgede kütle kabuğunda bir mod bulunan rejimde varış **öne alınmaz**.
> Varışın öne alındığı rejimde ise gözlenecek bir kütle kabuğu modu **yoktur**.

**Geriye kalan.** İddiayı taşıyan sönümlü rejimde elde kalan gözlenebilirler,
bu çalışmanın zaten hesapladığı iki sınır niceliğidir: geçen ağırlık ve katman
şiddeti. İkisi de iki aileyi ayıran ters çevirme altında çifttir; dolayısıyla
bir geçişin **olduğunu** bildirirler, içeride ne olduğunu değil, parçacığın
hangi yöne gittiğini hiç değil.

Bu bir tavizdir. İddiayı taşıyan rejimde öte taraf yalnızca iki yüzündeki genlikler
üzerinden görünür; doğrudan hiç görünmez.

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
 büyüklüğü birdir. Öte tarafın diğer üç ekseninin bu yuvaya katkısı tam olarak
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
 Öklidyen ara bölge, $d = 8$, $c = \mu = 1$ için eşik $2{,}565988$'dir (Bölüm
 4.1.3).

**Yedi adımın tek bir parçacık üzerinde yürütülmesi.** Yukarıdaki adımlar ayrı
ayrı kuruludur; hepsini birden kapatan tek bir örnek ise şudur. Öklidyen bir ara bölge,
kalınlık $8$, $c = \mu = 1$, toplam enerjisi $9$ olan bir parçacık; enerji
vektörü $(1{,}732051,\ 1{,}732051,\ 1{,}732051)$, frekansı $3{,}162278$, dışarıdaki
dalga sayısı $1{,}732051$, içerideki sönüm katsayısı $3{,}000000$. Parçacık
bölgeyi engel olarak görmektedir, dolayısıyla gecikme doymuştur.

Gidiş dönüş bölgenin içinde $2{,}434322$ harcamaktadır. Öte tarafta kat edilen
mesafeye göre, kalkışına göre ölçülen dönüş anı:

| Öte tarafta kat edilen | Dönüş anı | Sonuç |
| ---------------------- | ------------- | -------------------------- |
| $1{,}000000$ | $+1{,}434322$ | kalktıktan **sonra** döner |
| $2{,}434322$ | $0{,}000000$ | tam kalktığı anda döner |
| $6{,}000000$ | $-3{,}565678$ | kalkmadan **önce** döner |

Üç yolculuk yalnızca öte tarafta ne kadar gidildiğinde ayrışmaktadır; parçacık,
bölge ve enerji aynıdır. Öteki dal seçildiğinde aynı yolculuk daha geç
inmektedir, dolayısıyla işaret yolculuğun bir özelliği değil, geçişin bir
seçimidir.

**Yolculuğun adım adım dökümü.** Yukarıdaki üçüncü satır, yani eşiği aşan
yolculuk, her ara niceliğiyle birlikte şudur. Her satır ilgili bölümün
hesabıdır; burada yeniden türetilmemekte, çağrılmaktadır.

| Adım | Nicelik | Değer |
| ---- | ----------------------------------------- | ------------------------------- |
| 1 | Enerji bölüşümü: normal, enine, toplam | $3{,}000000$, $6{,}000000$, $9$ |
| 2 | Kütle kabuğundan frekans | $3{,}162278$ |
| 3 | Dışarıdaki dalga sayısı, içerideki sönüm | $1{,}732051$, $3{,}000000$ |
| 4 | Opaklık: sönüm çarpı kalınlık | $24{,}0000$, doyum sağlanmış |
| 5 | Tek geçişin faz gecikmesi | $1{,}217161$ |
| 6 | İki geçiş, yani gidiş dönüş gecikmesi | $2{,}434322$ |
| 7 | Gereken öte taraf mesafesi | $2{,}434322$ |
| 8 | Kat edilen mesafe ve dal | $6{,}000000$, dal $-1$ |
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
sönümlüdür, grup hızı tanımsız kalır ve gecikmenin kalınlıkla artmaması hızlı bir
yolculuk değil yolculuğun yokluğudur; elde yalnızca faz vardır (Bölüm 16.9).
Yukarıdaki $2{,}434322$ bu nedenle bir yol süresi değil, iki geçişin faz
gecikmesidir ve tablonun hiçbir satırında kalınlık değişmemektedir.

**Öte tarafta** kat edilen mesafe ise bundan bağımsız bir niceliktir. Öte taraf
bir engel değildir; orada mod sönümlü değildir ve tek uzay ekseni boyunca
hareket olağan anlamıyla tanımlıdır (Bölüm 10.1, Bölüm 17.2). Tablonun değişen
sütunu budur.

Bu ayrım olmasa örnek kendi kendini çürütürdü: sönümlü bir bölgenin içinde
yolculuk diline başvurmak, Bölüm 16.9'un tam olarak reddettiği şeydir. Örnek
buna başvurmamaktadır; ara bölge yalnızca bir faz gecikmesi katmakta, mesafe ise
bütünüyle öte tarafta kat edilmektedir.

**Bedeli de aynı yerde yazılıdır.** Bu yolculukta parçacık
$1{,}83 \times 10^{-41}$ ağırlıkla dönmektedir. Ne var ki bu ağırlık bir yasak değildir: doyum derinliği
sabit tutulup enerji yükseltildiğinde gereken mesafe $2{,}4343$'ten $0{,}9895$,
$0{,}3101$ ve $0{,}0980$'a inerken tek geçişin genliği
$4{,}293312 \times 10^{-3}$, dolayısıyla gidiş dönüşün ağırlığı
$3{,}397579 \times 10^{-10}$ değerinde **kıpırdamamaktadır**. Ödenen şey enerji ve daha ince bir bölgedir.

**Sonucun ifadesini** Bölüm 1.1'in "Ana sonuç" paragrafı verir ve bu bölüm
onu tekrarlamaz. Bu bölüm o ifadeyi eklemez; yukarıdaki yedi adımın onu nasıl
ürettiğini ve aşağıdaki tek parçacığın onu nasıl gerçeklediğini göstermektedir.

**İddianın sınırı**, aynı şekilde Bölüm 1.5'te üç bedel olarak sayılmıştır: genliğin
küçüklüğü bir büyüklük sorunudur ve Bölüm 4.1.6 bunun seçilmiş bir çalışma
noktası olduğunu göstermektedir. İşaretin seçilebilirliği bir açık sorudur (Bölüm
9.4). Geçirgen okuma ile yüzey katmanı bir arada duramaz; bu, literatürün güçlü
ile zayıf ayrımıdır, modele özgü bir boşluk değil (Bölüm 5.7.1). Yedi
adımın kendisi bu boşluktan bağımsız olarak doğrudur; eksik olan, adımları bir
deneye bağlayan son adımdır.

> Bu çalışmanın söylediği şudur: böyle bir geçiş kurulabilirse, dönüş anının
> nereye düştüğü serbest bir yorum değil, hesaplanmış bir sayıdır.

---

# Kısım VII. Yöntem ve deney

Bu kısım çalışmanın nasıl doğrulandığını ve hangi düzenekle sınanabileceğini
yazar.

İki bölüm vardır. Birincisi yöntemi kurmaktadır. Her sayısal ve cebirsel iddia bir
doğrulamaya karşılık gelir, iki metin birbirine isimle değil çalışma zamanında
bağlanır ve doğrulama kendini de denetlemektedir. İkincisi neyin gösterilmediğini
yazar ve çekirdek ölçümün düzeneğini şart şart belirtir.

## 20. Yöntem ve doğrulama

Bu metindeki her sayısal ve cebirsel iddia, C++ ile kurulmuş bir doğrulamaya
karşılık gelir. Doğrulamalar genel amaçlı kütüphaneler hâlinde durur ve
üzerlerinde bir test takımı çalışır.

**İki metin birbirine atıf yapmaz.** Makale hiçbir dosya ya da sınıf adı anmaz;
kod da hiçbir bölüm ya da kaynak numarası anmaz. Gerekçe bakımdır: birbirine
isimle bağlanan iki metinden biri yeniden düzenlendiğinde diğerindeki atıflar
sessizce çürür ve çürüdükleri fark edilmez. Bunun yerine bağ, aşağıdaki
denetimlerde olduğu gibi **çalışma zamanında kurulur**: doğrulama metni okur ve
aradığını orada bulamazsa koşuyu düşürür.

**Sayısal güvenilirlik.** Modelin matrislerinin büyük kısmı tamsayı girdilidir
($0, +1, -1$) ve bu girdiler ikilik tabanda tam temsil edildiğinden permütasyon,
involüsyon ve determinant testleri cebirsel hesapla birebir aynı sonucu vermektedir.
Boost, dönme, faz türevi ve mod toplamı hesaplarında irrasyonel ya da yakınsak
nicelikler oluşur; oralarda açıkça belirtilen bir tolerans kullanılmıştır.

**Doğrulama disiplini.** Bir kontrolün sonucunu hesaplamadan bildirmesine izin
verilmez. Sonucunu iddia edip hiçbir şey hesaplamayan kontroller tespit edilip
ya gerçek bir hesapla değiştirilmiş ya da kaldırılmıştır; kaldırılanlar fiziksel
değil yorum niteliğindeydi.

Elle yapılan iki hesap, parite argümanı ve boyut sayımı, cebirsel kontrolde
**yanlış çıktı** ve düzeltildi. Modelin bugünkü hâli bu düzeltmeleri içerir.

### 20.1 Üç denetim

Üç denetim makalenin kendisini okur ve metni bulamazsa koşuyu düşürür; girdisi
yokken sessizce geçen bir kontrol, hiçbir şey yapmadığı için başarı bildirir.

**Sayıların metne ulaşması.** Süpürme, test takımı çıktısında üç ile altı
ondalık basamakla basılmış her sayıyı toplar ve makalede arar. Ham çıktısı bir
eksik listesi değil, incelenecek adaylar listesidir: metin virgül ve $10^{-12}$
yazarken çıktı nokta ve $e$-gösterimi kullanır. Dört tur, makaleye ulaşmayan
sonuçları tek tek ortaya çıkardı ve hepsi metne girdi; geriye kalanların tamamı
girdi ya da ara değerdir.

**Kaynakça kapsaması.** Metindeki her atıf numarasının listede bir karşılığı,
listedeki her künyeye metinden en az bir atıf aranır. İki yön ayrı ayrı
gereklidir, çünkü liste iki ayrı biçimde çürür: numaralar kayarsa bir atıf
listenin sonunu aşar, bir pasaj çıkarılırsa künye sahipsiz kalır. Denetimin
ağırlığı şuradan gelir: bir bölüm silindiğinde dosyada ondan sonra gelen her şey
onunla birlikte gider ve kaynakça dosyanın son öğesidir. Bu çalışmada tam
olarak bu oldu; hiçbir sayısal denetim görmedi, çünkü bir atıf numarası hiçbir
hesabın ürettiği bir sayı değildir. Künyenin kimliğini basılı rakam değil
listedeki sırası taşır.

**Varsayım sicili.** Doğrulama, varsayım ileri süren her pasajı bulur ve her
birinin aşağıdaki sicilde bir hüküm ile yer almasını şart koşar. Sicilin
kapsamadığı bir pasaj başarısızlıktır. Sicil kodda değil burada durur:
doğrulamanın içinde tek bir bölüm numarası yoktur, hem hüküm sözlüğünü hem
sicili bu bölümden okur.

Üç denetim de bozma ile sınanmıştır: karşılıksız bir atıf eklemek, kaynakça
listesini silmek, bir künyeye giden tek atfı çevirmek ve sicilde yeri olmayan
bir varsayım cümlesi eklemek. Koşu her seferinde düşmüş, bozma geri alındığında
tekrar geçmiştir.

### 20.2 Hüküm sözlüğü ve sicil

**Hüküm sözlüğü.** Kullanılabilecek hükümler bunlardır ve doğrulama sicilde
bunların dışında bir hüküm bulursa koşuyu düşürür.

| Hüküm | Anlamı |
| ---------------------------- | --------------------------------------------------------------- |
| türetildi | Sonradan başka bir şeyden çıkar |
| iki yönlü hesaplandı | Hesap iki seçeneğin ikisini de verir, seçim hiçbir şey taşımaz |
| geçersiz kılındı | Sonraki bir sonuç ona olan ihtiyacı ortadan kaldırmıştır |
| başka kurguya ait | Karşılaştırılan bir formülasyona aittir, bu metne değil |
| ilan edilmiş sınırlama | Korunmuştur ve sonucu metinde yazılıdır |
| varsayım değil, söz ediliyor | Varsayım yapmak yerine varsayımlardan söz eden pasaj |

Yalnızca inanılan bir varsayım için hüküm yoktur; denetimin varlık nedeni budur.
Son satır, taramanın bir kelimeden niyet okuyamamasının sonucudur ve gereklidir:
varsayımı eleştiren bir cümle ile varsayan bir cümle aynı kelimeyi taşımaktadır.

**Sicil.**

| Bölüm | Ne varsayılıyor | Hüküm | Nerede kapandı |
| ----- | -------------------------------------------------------------------------- | ---------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------- |
| 4.1.2 | Faz gecikmesi ile öte taraf yer değiştirmesinin toplanabilmesi | türetildi | Aynı bölüm, tek bir durağan faz koşulundan |
| 5.8 | Enine dalga sayısının yönler arasında eşit paylaşılması | ilan edilmiş sınırlama | Sonucu yazılı: açık hücre mod içeriğine bağlıdır ve mod filtresi bölümünde hesaplanır |
| 5.8 | Dejenere katmanın içerideki her modu tam olarak bloklaması | ilan edilmiş sınırlama | Katmanın bir modeli olarak konur, tam hesabın sıfır vermeyebileceği yazılıdır |
| 5.8 | Madde katmanının gücünün imza dönüşünün eğimini izlemesi | ilan edilmiş sınırlama | Dolaylı bir ölçü olarak konur, tam gerilim tensörünün hesaplanmadığı yazılıdır |
| 6.1 | Yansıyan bir bileşenin bulunabilmesi | türetildi | Aynı bölüm: akı korunumu başka çözüm bırakmaz |
| 19 | Dökümün yedi adımdan sapmaması, yani dönüş olayının kapalı formülden okunması | türetildi | Aynı bölüm: dört koordinatın hepsi Bölüm 18.7'nin formülünden gelir ve döküm onları yeniden hesaplamaz |
| 9.4 | Global hiperbolikliğin sağlanması | başka kurguya ait | Karşılaştırılan formülasyonun ihtiyacıdır; buradaki sonuç yalnızca zaman yönlerinin sayısından çıkar |
| 16.4 | Dönmenin bir okumada özdeşlik, ötekinde düzgün olması | geçersiz kılındı | Dönmeyi nicelendirerek iki uca da ihtiyaç bırakmayan bölüm |
| 16.4 | Geçişin kayıpsız olması, ki bir satırı sıfırlayan budur | ilan edilmiş sınırlama | Sonucu yazılı: madde katmanı o sıfırı kaldırır |
| 16.5 | Yok; pasaj önceki bölümün iki varsayımını kaldırmak için anar | varsayım değil, söz ediliyor | Onları kaldıran bölümün kendisi |
| 20.1 | Yok; pasaj üç denetimin ne aradığını anlatır | varsayım değil, söz ediliyor | Denetimlerin kendisi, ki bu bölüm onları belgeler |
| 20.2 | Yok; pasaj bu sicili ve taradığı kelimeleri anlatır | varsayım değil, söz ediliyor | Sicilin kendisi, ki bu bölüm onu belgeler |
| 21.2 | Öte tarafın sınırsız olması | ilan edilmiş sınırlama | Sonucu yazılı: sonlu kalınlıkta dilim üstel olarak bastırılmış ama sıfır olmayan bir genlik bırakır |
| 9.3 | Denklem düzeyinde ve durum düzeyinde tek yönlülüğün aynı iddia olması | başka kurguya ait | İki okuma orada ayrılır ve yalnızca ikincisi savunulur |
| 4.1.6 | Sabit tutulan derinlikte gecikmenin doymuş olması | türetildi | Aynı bölüm: dört enerjinin dördünde de sonlu kalınlık gecikmesi doymuş değerin yüzde biri içindedir |
| 4.1.6 | Minimize edilen niceliğin Bölüm 4.1.3'ün karşılaştırdığı nicelik olması | türetildi | Aynı bölüm: referans yapılanma $2{,}565988$ verir, yani o bölümün sayısının aynısı |
| 21.2.5 | Üretilen bir bölgenin ömrünün ışık geçiş süresi kadar olması | ilan edilmiş sınırlama | Sonucu yazılı: borç ömrün 0,82'sini alır, şart sağlanır ama payı yoktur |
| 21.2.6 | Bir çarpışmanın ulaştığı yoğunluğun durgun küre tanımıyla okunması | ilan edilmiş sınırlama | Sonucu yazılı: üç hacim tanımı 3,7 mertebe yayılır ve en cömerti bile eşiğin çok altında kalır |
| 21.2.6 | Yer çekiminin güçlendiği ölçeğin dört boyutlu Planck ölçeğinin yerini alması | ilan edilmiş sınırlama | Sonucu yazılı: ölçekleme bu varsayıma dayanır ve burada gerekçelendirilmediği aynı bölümde belirtilir |
| 18.9 | Eksik kütle yönteminin kütle kabuğunda gerçek bir momentum varsayması | iki yönlü hesaplandı | Aynı bölüm: iç mod $\sqrt{13}$ altında söner, üstünde yayılır; iki rejim birbirinin tümleyenidir ve hiçbir frekans ikisini birden vermez |

Sicil $20$ kalem taşır, tarama ise $14$ bölümde iddia bulmaktadır. Sicilin
taramadan geniş olmasının nedeni şudur: sonradan olumsuzlanan bir ifade taramaya
takılmaz, ama hükmü kayıtta kalır.

Bu metnin **kendi** taşıdığı varsayım sekiz satırdır, sekizi de "ilan edilmiş
sınırlama" hükmündedir ve sekizinin de sonucu metinde yazılıdır. Geri kalan
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

Açık maddeler tek bir liste olarak sayıldığında yanıltıcıdır, çünkü hepsi aynı
türden değildir. Belirleyici ayrım şudur: **daha iyi bir düzeneğin
kaldırabildiği** engel ile **hiçbir düzeneğin kaldıramadığı** engel. Küçük bir
genlik birincisidir; bir hızdır ve hızlar denemeyle satın alınır. Modelde
karşılığı olmayan bir seçim ise ikincisidir ve ona mühendislik sorunu demek
dürüst olmaz.

Dört engel vardır ve türleri şöyledir:

| Engel | Türü | Neyle kapanır |
| ------------------------------------------ | ------ | -------------------------------------------------------------- |
| Parçacığın döndüğü ağırlık | Hız | Yalnızca deneme sayısı |
| Dönen parçacığı yaratılmış çiftten ayırmak | Hız | Kalorimetre, iki durgun enerji çözünürlükte, çakışmada okunmuş |
| Sekiz geçişten hangisinin gerçeklendiği | Seçim | Tam olarak bir eksende tek olan bir nicelik |
| Böyle bir bölgenin yapılabilmesi | Varlık | Bu çalışmanın dışında; koşullu ifade buraya dayanır |

**Hızların fiyatı.** Bölüm 19'un yürüttüğü gidiş dönüşün ağırlığında tek bir
olay için $5{,}5 \times 10^{40}$ deneme gerekir. Enerji yükseltmek bunu
**değiştirmez**: doyum derinliği sabit tutulduğunda gidiş dönüşün ağırlığı,
toplam enerji dokuzdan elli bine çıkarken $3{,}397579 \times 10^{-10}$
değerinde kalır. Bu bir umut değil, hesaplanmış bir sonuçtur.

**Enerjinin satın aldığı şey mesafedir.** Aynı aralıkta öte tarafta kat edilmesi
gereken mesafe $2{,}4343$'ten $0{,}0980$'a inmektedir. Yani iki talep
birbiriyle takas edilmez: enerji yükseltmek yolculuğu kısaltırken ağırlıktan
hiçbir şey götürmez.

**Hiçbir hızın dokunmadığı engel.** Hangi geçiş gerçeklenir: bunu ne enerji ne
deneme belirler. Söz konusu olan, görülemeyecek kadar küçük bir nicelik değil;
metriğin yapmadığı bir seçim. İki aile bu çalışmada hesaplanan **hiçbir**
nicelikte ayrışmamaktadır; daha iyi bir düzenek aynı sayıları ölçer.

**Koşullu ifadenin dayandığı yer** dördüncü satırdır. Bu çalışmanın hiçbir
sonucu, imzası değişmiş bir bölgenin yapılabilip yapılamayacağına dair bir şey
söylemez. Sonucun bir öneri değil bir koşullu olarak yazılmasının nedeni budur.

> Dürüst özet şudur: iki engel **sayıdır**, biri **seçimdir**, biri de **öncülün
> kendisidir**.

### 21.2 Kapanan ve açık maddeler

| Konu | Durum |
| ------------------------- | ------------------------------------------------------------------------ |
| Üç zamanda zamanın oku | Kapandı (Bölüm 9.4), ok zaman yönü sayısından çıkar, eşik değeri birdir |
| Dönüşümdeki $\pm$ işareti | Kapanamaz olduğu gösterildi (Bölüm 16.6) |
| Grup yapısı | Kapandı (Bölüm 4.2), sorun $B$ katmanında |
| Superluminal durgunluk | Kapandı (Bölüm 10.2), ayar fazlalığı |
| Etkileşim / Maxwell | Kapsam dışı bırakıldı |
| Kuantumlama | Kapandı |
| Takyonların varlığı | Açık, deneysel soru |

Modele özgü olduğu düşünülen sonuçlar şunlardır: $D$'nin 384 aday arasından
zorunlu çıkması (Bölüm 4.1); öte taraftaki yönelimden dönüş olayına giden
eşlemenin kurulup taranmış olması (Bölüm 18).

Eskiden bu listede olan "eşikte tam yansımanın akı korunumunun tek çözümü
olması" maddesi **çıkarılmıştır**; eşik geçirgen okunduğundan beri o iddia
taşınmamaktadır.

**Bölüm 5.1'de kapanan nokta.** İki imza arasındaki sürekli yolun ne kadar
dejenere olmak zorunda olduğu sorusu cevaplandı. Her noktada yalnızca tek bir
öz-değerin sıfırlandığı bir yol vardır; bedeli, $(2,2)$ imzalı iki zamanlı bir
ara bölgeden geçmektir. Daha önce yazılan "geçiş sağlanmaz" sonucu geri
çekilmiştir.

**Bölüm 8'de daraltılan nokta.** Eşiğin yansıtıcı olması sınırsız bir öte taraf
varsayar. Sonlu kalınlıkta bir dilim, üstel olarak bastırılmış ama sıfır olmayan
bir geçirgenlik verir; ayrıca engelin ortaya çıkıp çıkmadığını gelen alanın mod
içeriği belirler.

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

Geçiş koşullarının deneysel karşılığı sayılara indirgenmiştir. Kütle tavanı
$\mu_{\max} = \omega_0^2/c^2 - k_\perp^2$ biçiminde yazılmıştır. Bant merkezi, taşınan
kütlenin durgun enerjisinden kurulan frekansı aşmak zorundadır.

| Nicelik | Değer |
| ------------------------------------------ | ---------------------------------- |
| Proton durgun enerjisi | $938{,}3$ MeV |
| Aşılması gereken bant merkezi | $1{,}4255 \times 10^{24}$ rad/s |
| Karşılık gelen kütle parametresi | $2{,}2609 \times 10^{31}$ m$^{-2}$ |
| Bir voltluk potansiyelin frekans kayması | $1{,}5193 \times 10^{15}$ rad/s |

Bu tablo iki şey söyler. Kütle tavanı sonradan kestirilecek bir ölçek değil,
yazılı bir laboratuvar şartıdır: bu frekansın altındaki bir bant protonu hiç
taşımaz. Potansiyelin sağladığı ayar ise giriş frekansının dokuz mertebe
altında kalır. Dolayısıyla dönüş kaba bir şartın üzerinde ince bir ayarla
yönlendirilir ve şart bu yolla dolanılmaz.

Ölçülmesi gereken nicelikler de bu tablodan çıkar: bant merkezi ve genişliği,
öte tarafta kat edilen mesafe ve dönen genliğin ağırlığı. İlk üçü düzeneğin
ayarlarıdır, dördüncüsü sonucun kendisidir ve Bölüm 13.8'de gösterildiği üzere
deneyin asıl güçlüğü oradadır.

### 21.2.2 Mesafenin süreye çevrimi

Öte tarafta kat edilen uzunluğu Bölge I'de kazanılan süreye çeviren çarpan ışık
hızıdır. Bir metrelik yolculuk $3{,}34$ nanosaniye kazandırır.

| Kazanılan süre | Gereken öte taraf mesafesi |
| ------------------ | ----------------------------------- |
| $1$ ns | $0{,}30$ m |
| $1$ ms | $3{,}00 \times 10^{5}$ m |
| $1$ s | $3{,}00 \times 10^{8}$ m |
| $1$ dakika | $1{,}80 \times 10^{10}$ m |
| $1$ yıl | $9{,}46 \times 10^{15}$ m, bir ışık yılı |

Sınanan sürücüde, yani $1{,}5 \times 10^{24}$ rad/s değerinde, gidiş dönüşün
borcu $5{,}4614 \times 10^{-24}$ s olarak çıkar. Bu borcu kapatan öte taraf
mesafesi $1{,}6373 \times 10^{-15}$ m değerindedir, yani protonun birkaç
yarıçapı kadardır.
Borç, ölçülmeye değer herhangi bir ilerlemenin yanında ihmal edilir; gereken
mesafe pratikte ilerleme ile ışık hızının çarpımıdır.

Bir yıl geriye taşınma, öte tarafta bir ışık yılı mesafe kat edilmesini
gerektirmektedir. Önerinin ölçeği en açık biçimde bu satırda görünür.

### 21.2.3 Zayıflayan nicelik

Geri dönen parçacığın hiçbir özelliği azalmaz. Kütlesi, yükü ve mod ızgarası
gidişteki değerlerini korur, çünkü geçiş mod genliklerini ölçekler ve mod
etiketlerini yerinden oynatmaz.

Zayıflayan nicelik **varış olasılığıdır**. İletim katsayısı bir olasılıktır,
parçacığın bir kesri değil. Dolayısıyla geri gelen bir proton eksiksiz bir
protondur ve küçük olan sayı onun gelme şansıdır.

| Opaklık | Varış olasılığı | Bir varış için fırlatma sayısı |
| ------- | -------------------------- | ------------------------------ |
| $5$ | $4{,}54 \times 10^{-5}$ | $2{,}20 \times 10^{4}$ |
| $20$ | $4{,}25 \times 10^{-18}$ | $2{,}35 \times 10^{17}$ |
| $40$ | $1{,}80 \times 10^{-35}$ | $5{,}54 \times 10^{34}$ |

### 21.2.4 Görünürlük ile doyum

Deneyin asıl engeli kütle duvarı değildir. Varışın milyarda birin üzerinde
kalması opaklığı $10{,}36$ ile sınırlar. Gecikmenin doyması ise aynı çarpımın
büyük olmasını ister ve yolculuğu satın alan nicelik o gecikmedir.

İki şart birbirini ters yöne çeker. Sonucun görülebileceği kadar ince bir engel,
gecikmenin doyması için yeterince opak kalmaz. Kütle duvarını aşan bir sürücü
bulunsa bile bu gerilim ayakta kalır, ve deneyin asıl güçlüğünü de o
oluşturmaktadır.

### 21.2.5 Yoğunluk koşulu

Bu çalışma öte bölgeyi verilmiş kabul eder ve yolculuğu oradan hesaplamaktadır. Bölgenin
hangi koşulda ortaya çıktığını ise literatürün bir kolu bir sayıya bağlar.
Döngü kuantum kozmolojisinin etkin dinamiğinde hiperyüzey deformasyon cebiri
yoğunluğa bağlı bir çarpan kazanır ve bu çarpan enerji yoğunluğu kritik
yoğunluğun yarısını geçtiğinde işaret değiştirir [37]. Aynı kuram yüksek
yoğunlukta geometriyi Öklid imzasına döndürür [38]. Aşağıdaki sayılar o kuramın
kendi sayılarıdır, bu çalışmanın türettikleri değil. Altında mod denklemi
hiperboliktir ve geometri Lorentz imzalıdır; üstünde denklem eliptiktir ve
geometri Öklid imzalıdır.

| Nicelik | Değer |
| ------------------ | ----------------------------------------- |
| Planck yoğunluğu | $5{,}15 \times 10^{96}$ kg/m$^3$ |
| Kritik yoğunluk | $2{,}11 \times 10^{96}$ kg/m$^3$ |
| Dönme eşiği | $1{,}06 \times 10^{96}$ kg/m$^3$ |

Maliyet burada iki parçaya ayrılmaktadır, çünkü ikisi birlikte anıldığında
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

İkisi aynı mertebededir. Dolayısıyla şart bugün sağlanır, ama payı yoktur:
bölgeyi biraz küçülten ya da borcu biraz büyüten her seçim onu ihlal eder.
Bu metin bir üretim yolu önermediği için şartı sekizin arasına yazmaz, ancak
üretimi konuşan her öneriye onu iliştirmek gerekir.

### 21.2.6 Eşiğin dayandığı iki çarpan

Kritik yoğunluk evrensel bir sabit değildir. İki çarpandan kurulur:

$$\rho_c = \frac{\sqrt{3}}{32\pi^2\gamma^3}\, M_*^4$$

Birinci çarpan serbest değildir. Kuantizasyon parametresi $\gamma$ bir entropi
sayımından gelir ve $0{,}2375$ değerini alır; buradan türetilen kesir $0{,}4094$
çıkar. Bu çarpanı ayarlanabilir saymak, aranan sonucu baştan kabul etmek olur.

İkinci çarpan ölçülmüş bir nicelik tarafından sabitlenmemiştir. Ek sıkışmış
boyutlar bulunuyorsa yer çekiminin güçlendiği ölçek dört boyutlu değerin çok
altına iner [39] ve eşik o ölçeğin **dördüncü kuvvetiyle** düşer. Bu ölçekleme,
o ölçeğin dört boyutlu Planck ölçeğinin yerini aldığı varsayımına dayanır ve
burada gerekçelendirilmemiştir. Kaldıraç büyüktür:
ölçeğin on altı mertebe düşmesi eşiği altmış dört mertebe düşürür.

| Yer çekiminin güçlendiği ölçek | Dönme eşiği | Kazanç |
| ------------------------------ | --------------------------------- | ------------- |
| $10^{19}$ GeV | $4{,}75 \times 10^{95}$ kg/m$^3$ | yok |
| $10^{6}$ GeV | $4{,}75 \times 10^{43}$ kg/m$^3$ | $52{,}3$ mertebe |
| $10^{4}$ GeV | $4{,}75 \times 10^{35}$ kg/m$^3$ | $60{,}3$ mertebe |
| $10^{3}$ GeV | $4{,}75 \times 10^{31}$ kg/m$^3$ | $64{,}3$ mertebe |

En yoğun kasıtlı yapılanma $9{,}28 \times 10^{21}$ kg/m$^3$ değerine ulaşır.
Eşiğin oraya inmesi, yer çekiminin $3{,}74$ GeV ölçeğinde güçlenmesini
gerektirirdi. Dışlanan ölçek tek bir sayı değildir; ek boyut sayısına bağlıdır
ve [40] onu iki boyut için $9{,}9$ TeV, altı boyut için $5{,}3$ TeV olarak
verir. En elverişli sınır alındığında bile kapatan ölçek $3{,}2$ mertebe
dışlanmış kalır ve koşul $13{,}5$ mertebe uzaktadır.

Bu hesabın kazandırdığı şudur: açık, çıplak bir imkânsızlık değil tek bir
parametre üzerindeki ölçülmüş bir mesafedir. Mesafe çarpışmanın enerjisiyle
değil, ek boyutların varlığıyla kapanır.

**Ulaşılan yoğunluk, seçilen hacim tanımına bağlıdır.** Yukarıdaki
$9{,}28 \times 10^{21}$ sayısı, çarpışma enerjisini durgun bir proton küresine
koyar. Bir çarpışma hazır bir hacimle gelmez ve üç ayrı hacim tanımı üç ayrı
cevap verir: durgun küre
$9{,}28 \times 10^{21}$, Lorentz büzülmüş geometrik örtüşme
$4{,}28 \times 10^{25}$, bir femtometrelik oluşum dilimi
$1{,}04 \times 10^{22}$ kg/m$^3$. Aradaki yayılım $3{,}7$ mertebedir ve ölçüm
değil tanım farkıdır: büzülmüş örtüşme henüz maddeye dönüşmemiş enerjiyi
sayar, durgun küre ise düzleşmeyi hiç saymaz.

Yayılım yukarıdaki hükmü değiştirmez, çünkü en cömert tanım bile eşiğin
çok altında kalır; değiştirdiği şey, mesafenin üç anlamlı basamakla yazılamaz
olmasıdır. Bu metin durgun küreyi kullanır ve seçimini burada kaydeder.

### 21.2.7 Çekirdek ölçümün düzeneği

Ölçülen nicelik tektir. Bir proton fırlatılır, eşiği geçer, öte tarafta tek
uzamsal eksen boyunca yer değiştirir, geri geçer ve **aynı saat üzerinde**
fırlatılışından önceki bir anda kaydedilir. Okunan şey iki olay arasındaki zaman
farkıdır; bu, iddiayı bir çıkarım değil bir ölçüm yapan özelliktir.

Bir şart, göründüğü kadar ağır değildir. Protonun bant merkezi kendi toplam
enerjisi bölü indirgenmiş Planck sabitidir ve durgun bir proton durgun
enerjisinden kurulan frekansta zaten oturur. Hiçbir kaynak o frekansı sağlamaz,
proton kendisi taşır.

**Enerji yine de gerekir, ama bant için değil.** Varışın hangi fırlatmaya ait
olduğunu bir etiket söyler ve etiket protonun ince bir folyodan geçmesini
gerektirir; folyo da onu saçar. Bir megaelektronvoltluk proton santimetre karesi
başına on mikrogramlık karbondan $1{,}38 \times 10^{-3}$ radyan genişleyerek
çıkar, yani demet hattının ulaştığı kolimasyonu bozar. İki yüz otuz
megaelektronvoltta aynı folyo onu $6{,}66 \times 10^{-6}$ radyan genişletir ve
etiket ile kolimasyon bir arada durur. Enerjinin satın aldığı şey bant değil,
**saçılma bütçesidir**; o enerjide bant merkezi $1{,}7749 \times 10^{24}$ rad/s
değerine çıkar.

**Fırlatma hızı da bedava değildir.** Bir varış için $4{,}85 \times 10^{8}$
fırlatma gerekir, ancak saniyede $4{,}85 \times 10^{8}$ fırlatmak fırlatmalar
arasına yalnızca $2{,}06$ nanosaniye koyar. Aranan işaret bir nanosaniyelik bir
geri kayma olduğuna göre, o kadar erken bir varış ile bir önceki protonun geç
varışı ayırt edilemez. Hız saniyede on milyona indirilir, aralık yüz nanosaniye
olur ve koşu $48{,}5$ saniye sürer.

| Şart | İstenen | Ulaşılan |
| ------------------------------- | ---------------------------------- | ---------------------------------- |
| Demetin durgunluk frekansını aşması | $1{,}4255 \times 10^{24}$ rad/s | $1{,}7749 \times 10^{24}$ rad/s |
| Enine momentumun toplama oranı | $10^{-1}$ | $5 \times 10^{-5}$ |
| Öte bölgenin yoğunluğu | $1{,}06 \times 10^{96}$ kg/m$^3$ | $9{,}28 \times 10^{21}$ kg/m$^3$ |
| Geçişin opaklığı | $10$ | $10$ |
| Öte taraftaki yer değiştirme | $0{,}2998$ m | $1$ m |
| Zamanlama çözünürlüğü | $2 \times 10^{-11}$ s | $1{,}8 \times 10^{-11}$ s |
| Saniyedeki fırlatma sayısı | $4{,}85 \times 10^{8}$ | $10^{7}$ |
| Varışın fırlatmaya bağlanması | bir etiket | bir etiket |

Bugünkü bir laboratuvar sekiz şarttan yedisini karşılar. Tablonun sağ sütununu
şartlar tek tek değil birlikte belirler: yukarıdaki iki çekişme, enerjiyi
yükseltip hızı düşüren tek bir çalışma noktasında birlikte çözülür. Okumayı
mümkün kılan sayı şudur: aranan ilerleme $10^{-9}$ s, zamanlama çözünürlüğü
$1{,}8 \times 10^{-11}$ s, yani elli beş çözünürlük genişliği ayrım. Ölçüm
sınırda durmaz ve deney $48{,}5$ saniye sürer.

Düzeneğin parçaları da olağandır:

- tedavi sınıfı bir proton siklotronu, iki yüz otuz megaelektronvolt;
- iki delikli bir sürüklenme kolimasyonu, açıyı istenen bandın altına indiren ve
  bedelini akımdan ödeyen;
- iki katmanlı ince bir sürüklenme algılayıcısı, fırlatmayı on iki pikosaniye
  içinde etiketleyen;
- tek bir zaman çevirici yonga ve tek bir osilatör, iki damgayı birlikte okuyan.

Son madde isteğe bağlı değildir. İki damga ayrı saatlerden okunursa, bir
nanosaniyelik bir saat kayması aranan işaretin tamamını taklit eder.

Sağlanmayan tek şart öte bölgenin yoğunluğudur. Düzeneğin geri kalanı olağandır:
bir proton demeti, bir kolimatör, hızlı bir zamanlama algılayıcısı ve bir
tetikleyici. Dolayısıyla deney tarif edilmiş olup gerçekleştirilebilir değildir,
ve ikisinin arasında duran şey bir liste değil tek bir şart üzerindeki tek bir
sayıdır.

### 21.3 Simülasyondan okuma

Bu çalışmadaki her gecikme **tek bir yoldan** gelmektedir: fazın frekans türevi.
Yol doğrudur, ama tek bir yol kendini denetleyemez. Bu alt bölüm ikinci yolu
kurmaktadır.

**Yöntem.** Bir dalga paketi frekanslar üzerinden toplanır; her frekans, iki
geçişin o frekansa uyguladığı genlikle ve gözlem noktasına kadarki serbest
yayılım fazıyla çarpılmıştır. Hesap sonucu zamanda ileri yürütmekte ve zarfın
**tepe yaptığı anı** varış saymaktadır.

Hesap hiçbir gecikme formülü kullanmamaktadır. Durağan faz koşulunu da
dayatmamakta, ortaya çıkmasını ya da çıkmamasını serbest bırakmaktadır.

**Bandın kesilmesi zorunludur.** Frekans $\sqrt{k_\perp^2 + \mu}$ değerinin, bu
yapılanmada $2{,}2361$'in altına düştüğünde dışarıdaki dalga sayısı sanaldır ve
o bileşen dedektöre **hiç ulaşmaz**. Bant orada kesilmektedir; kesilmezse toplam
anlamsız bir katkı taşır.

**Birinci sonuç: gecikme doğrulanmaktadır.**

| Kalınlık | Simülasyonun ölçtüğü | Kapalı biçim |
| -------- | -------------------- | ------------ |
| $4$ | $+1{,}4635$ | $+1{,}4629$ |
| $8$ | $+1{,}4635$ | $+1{,}4629$ |
| $16$ | $+1{,}4635$ | $+1{,}4629$ |

Kalan fark paketin sonlu genişliğinden gelir ve bant daraldıkça küçülür.
Frekans toplamı dört kat inceltildiğinde sayı kıpırdamaz; yani bildirilen şey
kesmenin bir özelliği değil.

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

Sebebi şudur: opak rejimde geçirgenliğin **modülü** frekansla dik biçimde
yükselir. Bölge paketi yalnızca geciktirmez, onu **hızlı yanına doğru yeniden
ağırlıklandırır**. Bu kayma kalınlıkla büyümekte, gecikme ise büyümemektedir.

Bu gerçek bir etkidir ve bir hata değildir; ancak bir **gecikme de değildir**.
Paket, farklı bir paket olarak varmaktadır. İkisinin toplamını tek sayı olarak
bildirmek, birini ötekine yazmak olurdu; bu nedenle tablo ikisini ayrı tutmaktadır.

**Simülasyonun üç kez düzelttiği yer.** Grup hızı ilk yazımda ters çevrilmişti
ve arama penceresi tepeyi hiç içermiyordu. Bant, dışarıdaki dalga sayısının
sanal olduğu bölgeye uzanıyordu. İlk seçilen paket genişliğinde ise yeniden
ağırlıklandırma gecikmeye baskın gelmekteydi; kalınlıkla **büyüyen bir öne
kayma** neredeyse gecikme diye kaydedilecekti. Üçü de simülasyonun kendisi
tarafından yakalanmıştır, ki bir simülasyonun varlık nedeni budur.

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