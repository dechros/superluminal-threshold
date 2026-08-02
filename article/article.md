# Superluminal geçişte imza değişimi: ayrık involüsyon modeli

> Bu metin, modelin kendi sonuçlarını literatürdeki konumuyla birlikte verir.
> Köşeli parantez içindeki numaralar sondaki kaynakçaya gönderir. Bir sonucun
> daha önce elde edilmiş olduğu durumlarda bu açıkça belirtilir.

## Özet

Işık hızının aşıldığı bir geçişte uzay ile zamanın rol değiştirdiği, yani
metriğin imzasının 1+3'ten 3+1'e döndüğü bir çerçeve ele alınıyor. Bu geçişi
yapan dönüşüm iki bağımsız çarpana ayrılıyor:

$$M(V) = D \cdot B(c^2/V)$$

Burada $D$ sabit ve parametresiz bir involüsyondur, imza değişimini tek başına
yapan parça. $B(c^2/V)$ ise sıradan bir subluminal Lorentz boostudur ve hız
bilgisini taşıyan parçadır. Bu ayrım, aşağıdaki bütün sonuçların dayanağıdır:
grup yapısının kapanması, enerji ile momentumun takası, öte tarafta öngörünün
denklem tipinden ötürü çökmesi, superluminal durgunluğun bir ayar fazlalığı
olduğunun gösterilmesi, ve eşik yüzeyinin akı geçirmemesi.

Çalışma kendi sınırını da içerir: Sylvester atalet yasası, reel bir dönüşümün bir
metriğin imzasını doğrudan çevirmesini yasaklar. Dolayısıyla $D$, tek bir metriğin
imzasını çeviren bir operatör değil, iki farklı metrik arasında bir eşlemedir. Bu
sınır Bölüm 17'de açıkça ele alınıyor.

Öncelik konusunda baştan açık olmak gerekir. Superluminal çerçevelerin 1+3
boyuttaki kuruluşu [2]'ye, çarpanlamanın kendisi yine [2]'ye aittir; imza
değişiminde eklem koşulları literatürü [5], [6], [7] ile 1990'ların başına
dayanır. Bu çalışmanın iddiası yeni bir parça bulmak değil, bu iki literatürü
birleştirmek ve birleşimin sonuçlarını sonuna kadar takip etmektir. Hangi
sonucun kime ait olduğu ilgili bölümlerde tek tek belirtilmiştir.

## Modelin yedi maddesi

1. $c$ aşılırsa uzay ve zaman rol değiştirir; bu değişim anidir ve hızdan bağımsızdır.
2. Bunu yapan tek dönüşüm $D$'dir; involüsyondur, pariteyi korur, ışık hızını korur.
3. Ötede hız bir skaler değil, bir yönelimdir.
4. Enerji ve momentum takas olur.
5. Hız dönüşümü $v' = c^2/v$.
6. Ötede öngörü çöker, denklem tipinin doğrudan sonucu olarak.
7. Eşik geçirgen değil, yansıtıcıdır (güçlü eklem koşulu altında; bkz. Bölüm 9.1).

## Gösterim ve konvansiyonlar

Bölge I bizim tarafımızdır: bir zaman, üç uzay. Bölge II ışık hızının ötesidir:
üç zaman, bir uzay.

$$\text{Bölge I koordinatları: } (ct, x, y, z), \qquad
  \text{Bölge II koordinatları: } (t_1, t_2, t_3, r)$$

$$\eta = \mathrm{diag}(+1,-1,-1,-1), \qquad \eta' = \mathrm{diag}(+1,+1,+1,-1)$$

Kütle parametresi $\mu = (mc/\hbar)^2$ ile yazılır.

---

## 1. Çarpanlama

Superboost dönüşümü iki bağımsız parçanın çarpımıdır:

$$M(V) = D \cdot B(c^2/V), \qquad V > c$$

- $D$, sabit, parametresiz involüsyon; imza değişimini tek başına yapar.
- $B(c^2/V)$, sıradan subluminal Lorentz boostu; $V$ bilgisini taşır.

**Bu çarpanlama yeni değildir.** Bir superboost'un, sonsuz hız limitindeki bir
çevirme ile dual hız $c^2/V$'ye ait sıradan bir boostun bileşkesi olduğu [2]'de
belirtilmiştir ve [3] bunu kendi eleştirisinin ikinci basamağı olarak kullanır.
Burada eklenen şey çarpanlamanın kendisi değil, üç noktadır: çarpanlamanın
modelin düzenleyici ilkesi olarak sonuna kadar kullanılması, çevirme parçasının
Bölüm 2.1'deki tam tarama ile **zorunlu** olduğunun gösterilmesi, ve grup
kapanmasındaki bozulmanın Bölüm 3'te yalnızca $B$ katmanına yıkılması.

$V > c$ olduğundan $u = c^2/V < c$'dir, yani $B$ gerçekten subluminaldir. Her $V$
değeri için

$$M(V)^T \eta' M(V) = -\eta$$

sağlanır: çarpanlama geçerlidir ve imza değişimi bütünüyle $D$'nin üzerindedir.

---

## 2. $D$ matrisi

$$D = \begin{pmatrix} 0&0&0&1 \\ 0&0&1&0 \\ 0&1&0&0 \\ 1&0&0&0 \end{pmatrix}
\qquad\text{yani}\qquad (ct, x, y, z) \longmapsto (z, y, x, ct)$$

Doğrulanan özellikler:

| Özellik | Sonuç |
|---------|-------|
| İmza dönüşümü | $D^T \eta' D = -\eta$, yani $s'^2 = -s^2$ |
| Işık konisi | $s^2 = 0 \Rightarrow s'^2 = 0$, dört ayrı yönde doğrulandı |
| İnvolüsyon | $D^2 = I$, iki geçiş başa döndürür |
| Determinant | $+1$, parite bozulmaz |
| Grup | $\mathbb{Z}_2$ |
| $V$ bağımlılığı | Yok |

$D$'nin yaptığı şey, aralığın **genel işaretinin** çevrilmesidir. Metriğin genel
işaretinin değişmesi ve bunun fiziksel sonuçları [40]'ta ayrıca ele alınmıştır;
orada bu, göreliliğin farklı formülasyonlarında klasik bir imza değişimi türü
olarak incelenir ve kozmolojik sabitle ilişkilendirilir. Buradaki kullanım ondan
dardır: genel işaret çevrilmesi tek başına ele alınmaz, iki metrik arasındaki
eşlemenin bir özelliği olarak ortaya çıkar.

Işık konisi testi $(1,1,0,0)$, $(1,0,1,0)$, $(1,0,0,1)$ ve
$(1, 1/\sqrt{3}, 1/\sqrt{3}, 1/\sqrt{3})$ ışınları üzerinde yapılır; her birinde
$s'^2 = -s^2 = 0$ çıkar. Genel bir aralık için de $s'^2 = -s^2$ tam olarak sağlanır.

### 2.1 384 işaretli permütasyon matrisinin taranması

$D$'nin bir seçim değil zorunluluk olduğunu göstermek için bütün işaretli
permütasyon matrisleri tarandı: $4!$ permütasyon çarpı $2^4$ işaret, toplam 384 aday.

| Filtre | Kalan aday |
|--------|-----------|
| Metrik testi $M^T \eta' M = -\eta$ | 96 |
| ve involüsyon ($M^2 = I$) | 12 |
| ve $\det = +1$ | 8 |

Kalan sekiz çözümün **tamamında** $ct$ tek bir uzay eksenine gider. "Bizim
zamanımız onların uzayı olur" sonucu bir seçim değil, zorunluluktur. Sekiz çözüm
arasındaki tek fark uzay eksenlerinin etiketlenmesidir; dönme ile birbirlerine
geçtikleri için ayrı fiziksel içerik taşımazlar.

---

## 3. Grup kapanması

Doğrulanan iki olgu:

- $D^2 = I$, dolayısıyla $\langle D \rangle = \mathbb{Z}_2$, **kapalı**.
- $M(V)^2 \neq I$, birleşik dönüşüm kapalı **değil**. ($V = 1{,}5c$, $2c$ ve $10c$
  için ayrı ayrı gösterildi.)

Kapanma sorunu $D$'den değil, $B$ katmanından kaynaklanır. $D \cdot B$'yi tek bir
dönüşüm olarak ele almak kapanmayı bozar; ayrıştırıldığında iki parça da düzgündür:
$D$ bir $\mathbb{Z}_2$ ayrık simetrisi, $B$ ise $SO(1,3)$ içindedir.

Buradaki yapı $\langle D \rangle \ltimes SO(1,3)$ biçiminde bir yarı-doğrudan
çarpımdır. Kapanmanın bozulması, $D B D^{-1}$ konjugasyonunun boost tipini
korumamasından çıkar; yön-bağımlı genleşmeler bu konjugasyonun ürünüdür.

### 3.1 Daha geniş kuruluşla karşılaştırma

Aynı problem [4]'te bağımsız ve çok daha geniş biçimde çözülmüştür. İki kuruluş
yan yana konursa:

| | Bu bölüm | [4] |
|---|---|---|
| Ayrık parça | Tek involüsyon $D$, sabit | $\Lambda_{\inf}(\theta,\varphi)$, yöne bağlı aile |
| Üretilen grup | $\mathbb{Z}_2$ | Klein dörtlü grubu $\mathbb{Z}_2 \times \mathbb{Z}_2$ |
| Genişletilmiş grup | $\mathbb{Z}_2 \ltimes SO(1,3)$ | $\mathcal{L}_{\text{ext}}$, birim bileşeni $O(3,1)$ ile aynı |
| Yön kovaryansı | Yok, $z$ ekseni sabit | Var, her yön eşdeğer bir genişletme verir |
| Determinant | $+1$ | $-1$ |
| Değişen koordinat | Dört | İki, $t$ ve $n$ |
| Temsil kuramı | Yok | Genişletilmiş Poincaré grubunun bütün üniter indirgenemez temsilleri sınıflandırılmış |
| Dalga denklemleri | Yok | Casimir öz-değer probleminden türetilmiş, bilinen bütün denklemler artı yeni takyonik sınıflar |

Kapsam bakımından [4] bu bölümü içerir ve aşar. İki kuruluş **aynı grup
değildir**: $D$, [4]'ün genişletilmiş grubunda bulunmaz, çünkü içerdiği
$x \leftrightarrow y$ takasının üç boyuttaki determinantı $-1$'dir ve dolayısıyla
$SO(3)$ elemanı değildir. Bu, Bölüm 12.1'de hesaplanmıştır.

Bu bölümün taşıdığı tek fark, kapanma bozulmasının hangi katmandan geldiğinin
ayrıştırılmasıdır: $D$ kapalıdır, $B$ değildir. [4]'te sorun bu biçimde
ortaya konmaz, çünkü orada zaten kapalı bir grup inşa edilmiştir.

---

## 4. Enerji ve momentum

$D$ dört-momentuma uygulandığında:

$$(E/c,\; p_x,\; p_y,\; p_z) \longmapsto (p_z,\; p_y,\; p_x,\; E/c)$$

Öte tarafta enerji üç bileşenli, momentum tek bileşenlidir. Değişmez de
koordinatlardaki davranışla tutarlı biçimde işaret çevirir:

$$\frac{E^2}{c^2} - p^2 \;\longmapsto\; -\left(\frac{E^2}{c^2} - p^2\right)$$

Kütle kabuğu koşulu buna göre dönüşür:

$$E^2 = p^2c^2 + m^2c^4 \;\longmapsto\; E'^2 = p'^2c^2 - m^2c^4$$

**Korunum.** Genel bir $2 \to 2$ çarpışmada bizim tarafta korunum sağlanıyorsa öte
tarafta da otomatik sağlanır; fark tam olarak sıfırdır. Bunun nedeni $D$'nin
doğrusal olmasıdır: toplamların görüntüsü, görüntülerin toplamına eşittir.

**Karışık çarpışma.** Duran bir subluminal cisim ile sonsuz hızlı bir takyon
çarpıştığında cisim momentum kazanır, enerjisi değişmez. Başlangıç durumu
$(E_1, p_1) = (mc^2, 0)$ ve $(E_2, p_2) = (0, Mc)$ alınır; çarpışma sonrasında
takyon yine sonsuz hızlıdır ($E_4 = 0$) ve momentumu $M'c$ olur.

**Sonsuz hız limiti.** $V \to \infty$ iken $E \to 0$ ve $p \to mc$.

**Enerji pozitifliği üzerine not.** Bizim tarafta enerji tek bir sayıdır ve işareti
bellidir. Öte tarafta "enerji" üç bileşenli bir vektördür; tek bir pozitif enerji
koşulu yazılamaz, ancak büyüklüğü

$$|E'| = \sqrt{E_1^2 + E_2^2 + E_3^2} \;\geq\; 0$$

kullanılabilir. Bu gözlem, Bölüm 14'teki "kararlı vakum yok" sonucunun klasik
habercisidir. Aynı sorun, superluminal boost sonrası parçacıkların negatif enerji
kazanması biçiminde [32]'de ele alınmış ve kuantum referans çerçeveleri
genişletilerek çözülmüştür; oradaki çözüm ile buradaki vektör-enerji okuması
birbirine alternatiftir.

---

## 5. Hız kavramı ve dispersiyon

$D$'de $V$ geçmez. Bu bir eksiklik değildir; hız kavramının kendisi türetilerek
gösterilir ki gerekli değildir.

Bizim tarafta hız zaten temel bir büyüklük olmayıp dispersiyondan çıkar:

$$\omega(k) = c\sqrt{k^2 + \mu}, \qquad
  v_{\text{faz}} = \frac{\omega}{k}, \qquad
  v_{\text{grup}} = \frac{d\omega}{dk}, \qquad
  v_{\text{faz}} \cdot v_{\text{grup}} = c^2$$

Öte tarafta aynı türev alınır, ancak payda vektördür, zaman üç boyutludur:

$$\frac{dq}{d\kappa} \;\longrightarrow\; \text{skaler/vektör} = \text{gradyan} = \text{VEKTÖR}$$

**Sonuç:** Hız skaler olmaktan çıkıp yönelime dönüşür. "Ne kadar hızlı" sorusu
"hangi yönelimde" sorusuna dönüşür. $V$ bilgisi $B$ boostunda, yani üç-zaman
uzayındaki yönelimde yaşar.

Hız dönüşümü $v' = c^2/v$'dir; ışık hızı sabit noktadır ve subluminal ile
superluminal bölgeleri birbirine eşler.

### 5.1 Karşı tarafta dispersiyon ve grup hızı

Düzlem dalga koşulu:

$$k_1^2 + k_2^2 + k_3^2 - \frac{q^2}{c^2} + \mu = 0
  \quad\Longrightarrow\quad q = \pm\, c\sqrt{k^2 + \mu}$$

$q$ her zaman reeldir: $r$ ekseninde salınım vardır, sönümlenme yoktur.

Durgun cisim ($k = 0$) için $q = mc^2/\hbar \neq 0$. Yani orada duran bir cisim bile
$r$ ekseninde ilerler, bizim taraftaki "duran cisim zamanda ilerler" ifadesinin
tam aynasıdır.

Grup hızı:

$$\frac{dq}{dk} = \frac{c\,\hbar k}{\sqrt{c^2m^2 + \hbar^2k^2}}
  \qquad (\text{vektör, } k \text{ doğrultusunda})$$

$|dq/dk| < c$ ve $k \to \infty$ limitinde $c$'ye yaklaşır. Karşı tarafta da bir hız
sınırı vardır; yalnızca hangi eksende olduğu değişmiştir. Sınır davranışı her iki
tarafta aynıdır: $\kappa \to 0$'da sıfır, $\kappa \to \infty$'da $c$.

---

## 6. Lagrangian, alan denklemi ve determinizm kaybı

Bizim taraf (Klein-Gordon):

$$L = \tfrac{1}{2}\left[\frac{(\partial_t \phi)^2}{c^2} - (\nabla \phi)^2 - \mu \phi^2\right]$$

Euler-Lagrange:

$$\frac{1}{c^2}\partial_t^2 \phi - \nabla^2 \phi + \mu \phi = 0$$

$D$ uygulanmış hali:

$$L' = \tfrac{1}{2}\left[(\partial_{t_1}\psi)^2 + (\partial_{t_2}\psi)^2
      + (\partial_{t_3}\psi)^2 - \frac{(\partial_r \psi)^2}{c^2} + \mu \psi^2\right]$$

Euler-Lagrange:

$$\left(\partial_{t_1}^2 + \partial_{t_2}^2 + \partial_{t_3}^2\right)\psi
  - \frac{1}{c^2}\partial_r^2 \psi - \mu \psi = 0$$

İki denklem $D$ ile birbirine geçer; Klein-Gordon operatörü işaret çevirerek
dönüşür: $\Box \to -\Box'$.

### 6.1 Determinizm kaybı denklem tipinden çıkar

| | Bölge I | Bölge II |
|---|---------|----------|
| İmza | 1 zaman + 3 uzay | 3 zaman + 1 uzay |
| Başlangıç değer problemi | İyi konumlanmış | Hadamard anlamında kötü konumlanmış |
| Sonuç | Determinist | Öngörü çöker |

Sayısal gösterim: bir modu Bölge I'de $e^{i k \cdot x} f(t)$ biçiminde alırsak

$$\partial_t^2 f = -c^2(k^2 + \mu)\, f$$

elde edilir; katsayı **her zaman negatiftir**, dolayısıyla çözüm salınımlıdır ve
büyüme sınırlıdır. Bölge II'de aynı modu $e^{i(k_2 t_2 + k_3 t_3 + q r)} f(t_1)$
biçiminde alırsak

$$\partial_{t_1}^2 f = \left(k_2^2 + k_3^2 - \frac{q^2}{c^2} + \mu\right) f$$

elde edilir; bu katsayı **pozitif olabilir** ve $k_2, k_3 \to \infty$ iken sınırsız
büyür. Çözüm $\exp\!\big(\sqrt{\text{katsayı}}\; t_1\big)$ tipinde patlar. Başlangıç
verisindeki keyfi küçük bir bozulma, keyfi büyük bir çözüm değişimi verir: problem
Hadamard anlamında kötü konumlanmıştır.

Bu sonuç bir yorum değil, denklem tipinin doğrudan sonucudur.

**Öncelik ve yöntem.** Bu sonucun kesin hâli [7]'ye aittir ve yöntemi
buradakinden farklıdır. Orada iki boyutlu bir imza-değişen uzay-zamanda sınır
koşulları Schrödinger Hamiltonyeninin öz-eşlenik genişlemelerinden çıkarılır,
alanın sürekli olması ve koşulların eklem koşulu biçiminde olması talebi tek bir
küme seçer, Klein-Gordon başlangıç değer problemi bu kümede kötü konumlanmış
bulunur, ve değişim yüzeyinden uzakta düzgün ve tıkız destekli başlangıç verisi
için çözümün $L^2$ normunun **sonlu zamanda ıraksadığı** ispatlanır. Yukarıdaki
mod hesabı aynı sonuca çok daha basit bir yoldan varır ve bir ispat değil,
bağımsız bir doğrulamadır.

---

## 7. Karşı tarafta dinamik ve zamanın oku

### 7.1 Noether yükleri

$L'$ dört koordinatın hiçbirine açıkça bağlı değildir, dolayısıyla dört öteleme
simetrisi vardır:

- üç "enerji" bileşeni ($t_1, t_2, t_3$ ötelemeleri),
- tek "momentum" ($r$ ötelemesi).

$L'$ ayrıca üç zaman ekseninde $O(3)$ altında değişmezdir; buradan üç korunan
"zamansal açı momentumu" çıkar, bizim uzaysal açı momentumumuzun aynası.

### 7.2 Roller tam tersine dönmüştür

| | Bölge I (bizim) | Bölge II |
|---|-----------------|----------|
| Serbest hareket | Uzayda, üç yönde | Üç zamanda serbestçe |
| Tek yönlü zorunluluk | Zamanda | Tek uzay ekseninde |
| $O(3)$ dönme simetrisi | Uzaysal | Zamansal |
| Temel nesne | Yörünge (eğri) | Cephe (üç boyutlu hiperyüzey) |

### 7.3 Zamanın oku sorusu

Bölge II'de zamanın oku **yoktur**. Ok, ilgili boyutun **tek** olmasının sonucudur.
Üç boyutlu olan eksen kümesi uzay gibi davranır ve yön ayrımı ortadan kalkar.
Buna karşılık Bölge II'de bir **uzay oku** vardır, çünkü orada $r$ tek eksendir.

Ok entropiden değil, boyut sayısından çıkar.

### 7.4 Zaman yönelimi: neden öte tarafta gelecek ve geçmiş yok

Yukarıdaki ifade sezgiseldir; burada kesinleştirilir. Bir bölgede tutarlı bir
gelecek-geçmiş ayrımı yapılabilmesi için, zaman-benzeri vektörler kümesinin
**iki ayrı bileşene** ayrılması gerekir. Ancak o zaman bileşenlerden birine
"gelecek", diğerine "geçmiş" denebilir. Bu, tek bir pozitif yön bulunmasının
tam karşılığıdır.

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

**Ara bölge.** Bölüm 13.5'teki kademeli yolun geçtiği $(2,2)$ imzasında da
durum aynıdır; iki pozitif yön bulunması yeterlidir. Dolayısıyla yönelim,
kademeli yolun daha **ilk ayağında** kaybolur, ikinci ayağı beklemez.

| Bölge | Zaman yönü sayısı | Zaman-benzeri küme | Gelecek/geçmiş |
|-------|-------------------|--------------------|----------------|
| Bölge I, $(1,3)$ | 1 | İki bileşen | Var |
| Ara bölge, $(2,2)$ | 2 | Bağlantılı | Yok |
| Bölge II, $(3,1)$ | 3 | Bağlantılı | Yok |

Ok, entropiden değil, zaman yönü **sayısından** çıkar; ve eşik değeri birdir.

**Literatürdeki karşılığı.** [16], imza değiştiren bir manifoldun geçiş
hiperyüzeyinde, her noktadan geçen ve zaman yönünü tersine çeviren kapalı
sözde-zaman-benzeri ilmekler bulunduğunu ispatlar. Vardıkları sonuç kelimesi
kelimesine buradakiyle aynıdır: gelecek ve geçmiş yönlü vektörler arasında
tutarlı bir ayrım yapılamaz.

Yollar farklıdır. [16] sonucu geçiş hiperyüzeyinin geometrisinden, Lorentzian
bölgede global hiperboliklik varsayarak elde eder; burada ise yalnızca zaman
yönlerinin sayısından, hiperyüzey hakkında hiçbir varsayım yapmadan çıkar.

İki çekince belirtilmelidir. Birincisi, [16]'nın hipotezleri bu modelin geçişi
tarafından **sağlanmaz**: orada bir taraf Riemann imzalıdır ve dejenerelik
transvers radikal tipindedir, buradaki doğrudan geçişte ise rank iki düşer
(Bölüm 13.5). Ortak olan sonuçtur, ispat değildir. Buna karşılık Bölüm 13.5'in
kademeli yolu her ayakta rank-1 dejenereliğe sahiptir, yani [15] ve [16]'nın
geometrik çerçevesine buradan bakıldığından daha yakındır.

İkincisi, [16]'nın ilmekleri alışıldık anlamda kapalı zaman-benzeri eğriler
**değildir**: kesişim noktalarında hareket yönünün aynı olması gerekmez. Bu
nedenle sonuç, maddenin zamanda geriye gitmesi biçiminde okunamaz. [16] kendi
fiziksel yorumunu da verir: hiperyüzey yakınındaki bir gözlemciye böyle bir
ilmek, iki ayrı noktada bir parçacık-karşıparçacık çiftinin yaratılması gibi
görünebilir.

Görünüşte bir gerilim vardır: Bölüm 9.1 eşiğin geçirgen olmadığını söylerken,
[16] yüzeyden geçen ilmeklerden söz eder. Gerilim görünüştedir ve Bölüm 9.3'te
çözülmüştür: iki metrik arasındaki fark bir kareler toplamı olduğundan, Bölge
I'de zaman-benzeri olan her yön Bölge II'de de zaman-benzeridir, yani eşikte bir
eğriyi durduran nedensel engel yoktur. Yasaklanan şey akıdır. Geometrik eğriler
ile alan akısı farklı nesnelerdir ve iki sonuç aynı anda doğru olabilir.

**Bir itiraz.** [21], iki zamanlı dinamikte olasılık korunumu dayatıldığında
fazladan zaman ekseninin gözlenebilirliğinin sınırlandığını gösterir: klasik
$1+2$ boyutta Newton'un ikinci yasası tam olarak integre edilebilir ve her
başlangıç koşulu için **etkin tek zamanlı** bir evrim verir; kuantum tarafta ise
düzey aralıkları, toplam süre ve $\hbar$ içeren genelleştirilmiş bir belirsizlik
bağıntısı çıkar. Bu, üç zamanlı Bölge II'nin dışarıdan bakıldığında tek zamanlı
görünebileceği anlamına gelir. Buradaki kuruluş ile arasındaki fark, [21]'in
evrimin üniter ve olasılık koruyan olmasını istemesidir; Bölüm 14'te gösterildiği
gibi Bölge II'de bu talebin dayandığı yapı zaten mevcut değildir. Yine de bu
itiraz açık bir sorudur ve modelin lehine kapatılmış sayılmamalıdır.

---

## 8. Superluminal durgunluk

Durgun superluminal dört-momentum $p' = (mc\,\mathbf{s},\, 0)$ biçimindedir ve her
$\mathbf{s}$ seçimi ayrı bir dünya çizgisi demeti veriyormuş gibi görünür.

Hesap:

- Kütle kabuğu koşulu $s_1^2 + s_2^2 + s_3^2 = 1$ verir, yani $\mathbf{s} \in S^2$.
- $\eta' = \mathrm{diag}(+1,+1,+1,-1)$ içinde ilk üç slot **aynı** işaretlidir;
  onları koruyan grup $O(3)$'tür.
- $O(3)$ hem metriği korur hem de durgunluğu bozmaz (doğrulandı).
- $O(3)$, $S^2$ üzerinde geçişli (transitif) etki eder: herhangi bir $\mathbf{s}$'yi
  herhangi bir $\mathbf{s}'$ye götüren bir dönme her zaman vardır.

**Sonuç:** Bütün $\mathbf{s}$ seçimleri aynı yörüngededir. Sonsuz sayıda fiziksel
durum yoktur; **tek bir durumu yazmanın sonsuz yolu** vardır. Bu bir ayar (gauge)
fazlalığıdır.

$$\text{Stabilizatör} = O(2), \qquad \text{Yörünge uzayı} = O(3)/O(2) = S^2$$

**Öncelik.** Fazladan zaman boyutunun bir ayar simetrisiyle elenmesi [20]'nin
kurduğu mekanizmadır: $Sp(2,\mathbb{R})$ ayar simetrisi altında tek-zamanlı
sistemler aynı iki-zamanlı sistemin farklı ayar sabitlemeleri olarak ortaya
çıkar, ve bu alan teorisine, etkileşimlere ve ayar arka planlarına kadar
götürülmüştür. Yukarıdaki $O(3)$ fazlalığı aynı türden ve çok daha dar bir
olgudur. Buradaki katkı mekanizma değil, mekanizmanın bu modeldeki durgunluk
sorusuna uygulanmasıdır.

---

## 9. Eşik yüzeyi: $V = c$

İki bölge arasındaki $\Sigma$ yüzeyi için eklem koşulları:

1. Alan sürekli: $\psi_I|_\Sigma = \psi_{II}|_\Sigma$
2. Konjuge momentum sürekli: $\pi_I|_\Sigma = \pi_{II}|_\Sigma$

Normal yön Bölge I'de zaman-benzeri, Bölge II'de uzay-benzeridir. Bu yüzden
$\pi_{II} = -\pi_I$ olur. İkinci koşul ancak

$$\pi|_\Sigma = 0$$

ise sağlanabilir. Bu bir **düğüm koşuludur**: eşikte akı sıfırdır.

**Sonuç:** $\Sigma$ geçirgen değil, **yansıtıcıdır**. Kütleli madde eşikten geçemez,
tam yansır.

**İstisna.** $\mu = 0$ (kütlesiz) durumunda koşul kendiliğinden sağlanır, ama
kütlesiz alan zaten $c$'dedir, geçmesi gerekmez.

Bu sonuç modele elle konmamıştır; kendi Lagrangian'ından çıkmıştır.

Dispersiyon tarafındaki karşılığı: $v_{\text{faz}} = v_{\text{grup}} = c$ ancak
$\mu = 0$ için sağlanır. Kütleli alan için $v_{\text{faz}} > c$ ama
$v_{\text{grup}} < c$'dir; eşik aşılmaz, **teğet** geçilir.

### 9.1 Hangi eklem koşulu seçildi, ve seçim ne kadar belirleyici

Yukarıdaki iki koşulun birlikte dayatılması masum bir adım değildir. İmza
değişimi literatüründe bu tam olarak tartışmalı noktadır: dış eğriliğin yüzeyde
yalnızca **sürekli** mi olması gerektiği (*zayıf* imza değişimi), yoksa
**sıfırlanması** mı (*güçlü*). [6] sekiz aday eylem yazıp her birinin hangi
koşulu verdiğini inceler ve ikisini de savunulabilir bulur. [9] daha ileri gider:
imza değişiminde kanonik Einstein denklemleri diye bir şey yoktur, seçim
yapılmak zorundadır; [11] aynı noktayı yineleyip herhangi bir seçimi "asıl"
denklemler diye adlandırmanın retorik olduğunu söyler.

Yukarıdaki $\pi|_\Sigma = 0$ sonucu **güçlü** koşuldur. Aynı sonuç, aynı yöntemle,
[5]'te daha önce elde edilmiştir: orada Klein-Gordon alanı imza değiştiren bir
arka planda ele alınır ve eklem koşulu, alan denklemlerindeki Dirac dağılımının
katsayısı olarak $\phi' \delta = 0$ biçiminde **türetilir**, yani denklemleri
anlamlı kılmak için varsayılmaz. Buradaki türetim Lagrangian'dan gider ve aynı
yere varır.

Seçimin ne kadar belirleyici olduğunu ölçmek için $\Sigma$ üzerinde bir mod
saçılması kurulur. Normal koordinat $\xi$, Bölge I $\xi<0$, Bölge II $\xi>0$:

$$\phi = e^{i\kappa\xi} + R\,e^{-i\kappa\xi}, \qquad
  \psi = T_+ e^{i\kappa\xi} + T_- e^{-i\kappa\xi}$$

Bölge II'de iki genlik birden tutulur, çünkü orada zaman sıralaması olmadığı için
"dışarı giden dalga" koşulu **tanımlanamaz** (Bölüm 14.2).

İlk gözlem: normal doğrultudaki indirgenmiş denklem iki tarafta da aynıdır,

$$\frac{d^2}{d\xi^2} + \kappa^2 = 0, \qquad \kappa^2 = c^2(k_T^2 + \mu)$$

yani yüzeyde bir **empedans basamağı yoktur**. Geçirgenliği belirleyen tek şey
momentum eşleşmesinin işaretidir.

Eklem koşulları $1 + R = T_+ + T_-$ ve $1 - R = s\,(T_+ - T_-)$ olur; burada
güçlü koşul için $s = -1$, zayıf koşul için $s = +1$. Akılar
$F_I = 1 - |R|^2$ ve $F_{II} = |T_+|^2 - |T_-|^2$ ile verilir. Sonuçlar:

| Koşul | Dışarı-giden çözüm | Akı korunumu | Sonuç |
|-------|--------------------|--------------|-------|
| Güçlü, $s=-1$ | Yok, sistem aşırı belirlenmiş | Ancak $\|R\| = 1$ ise | **Tam yansıma, zorunlu** |
| Zayıf, $s=+1$ | Var, $R = 0$ | Her $R$ için | Geçirgen, ama miktar **belirsiz** |
| Dirichlet duvar | Bölge II ayrık | $R = -1$ | Tam yansıma |
| Neumann duvar | Bölge II ayrık | $R = +1$ | Tam yansıma |

Güçlü koşulda $T_+ = R$ ve $T_- = 1$ çıkar, dolayısıyla $F_{II} = |R|^2 - 1 = -F_I$
olur. İki akının eşit olması ancak $1 - |R|^2 = 0$ ile mümkündür. Yani **tam
yansıma ek bir varsayım değil, akı korunumunun tek çözümüdür.** Bölüm 9'un sonucu
bu haliyle bir seçimin sonucu olmaktan çıkıp, o seçim verildiğinde bir zorunluluk
hâline gelir.

Zayıf koşulda ise $T_+ = 1$, $T_- = R$ olur ve akı **her** $R$ için korunur.
Zayıf koşul geçişe izin verir ama ne kadar geçtiğini söylemez; Bölge II bir
radyasyon koşulu sağlayamadığı için $R$ serbest kalır. Bu, zayıf koşulun "geçiş
var" demekten çok "bu problem iyi konumlanmamış" demek olduğu anlamına gelir ve
Bölüm 6'daki sonuçla tutarlıdır.

Dört durumdan üçü yansıtıcıdır. Özellikle [8]'in öz-eşlenik genişlemelerden
çıkardığı **Dirichlet** koşulu, buradaki Neumann koşulunun tersi olmasına rağmen
aynı yere varır: orada da Minkowski bölgesi Kleinian bölgeden kopar. Dolayısıyla
"eşikten akı geçmez" sonucu, Neumann ile Dirichlet arasındaki tercihe duyarlı
**değildir**. Duyarlı olduğu tek şey güçlü ile zayıf arasındaki tercihtir.

Buna karşılık [8] bir uyarı da içerir: kuantum alanların varlığı bu duvarları
**kararsız** kılar, Kleinian bölge ya çöker ya sınırsız genişler. Burada bu
soruya girilmemiştir ve açık bırakılmaktadır.

### 9.4 Sonlu kalınlıkta bir dilim bir şeyler geçirir

Bölüm 9.1 öte tarafı **sınırsız** kabul eder. Sonlu kalınlıkta bir dilim ayrı
bir problemdir ve sonucu farklıdır.

Bu ayrım [41]'de kurulmuştur ve o çalışma bu bölümün öncülüdür. Orada
Klein-Gordon parçacıklarının Lorentzian imzadan Kleinian imzaya geçişi
incelenir, düzlemsel bir sınırda parçacık akısı için **ayna davranışı** bulunur,
ve ardından sonlu kalınlıkta bir çift eklem ele alınarak **tünelleme
olasılığı** gösterilir. Dikkat çekici olan, oradaki geçişin
$(-,+,+,+) \to (-,+,+,-)$ olması, yani Bölüm 13.5'teki kademeli yolun tam
olarak birinci ayağıdır.

Aynı hesap bu modelin değişkenleriyle yapıldığında şu çıkar. Dilimin dışında
normal doğrultudaki dalga sayısı karesi daima pozitiftir; içeride ise işaret
değiştiren yön yeterince dalga sayısı taşıdığında negatife döner, yani iç mod
**yayılmaz, söner**. Bu durumda geçirgenlik

$$T(d) = \left[1 + \frac{(\kappa^2+q^2)^2}{4\kappa^2 q^2}\,
        \sinh^2(q d)\right]^{-1}$$

olur. Hesaplanan değerler:

| Kalınlık $d$ | $T$ |
|--------------|-----|
| $0{,}5$ | $5{,}50 \times 10^{-1}$ |
| $1$ | $1{,}48 \times 10^{-1}$ |
| $2$ | $6{,}70 \times 10^{-3}$ |
| $4$ | $1{,}20 \times 10^{-5}$ |
| $8$ | $3{,}87 \times 10^{-11}$ |

**Sonuç ve Bölüm 9.1'in yeniden okunması.** Geçirgenlik hiçbir sonlu kalınlıkta
sıfır değildir, ancak kalınlıkla üstel olarak bastırılır. Dolayısıyla Bölüm
9.1'in tam yansıması ayrı bir ifade değil, bu ifadenin **kalın dilim limitidir**.
Sıfır kalınlıkta her şey geçer, kalın dilimde hiçbir şey geçmez.

Bir ikinci koşul daha vardır: iç modun sönümlü olması, gelen alanın mod
içeriğine bağlıdır. İşaret değiştiren yön az dalga sayısı taşıyorsa iç mod
yayılmaya devam eder ve geçirgenlik bastırılmak yerine **salınır**, rezonansta
bire ulaşır. Yani engeli yaratan imza değişiminin kendisi değil, gelen alanın
hangi modlardan oluştuğudur.

Bu, Bölüm 9.1'in sonucunu geçersiz kılmaz ama kapsamını daraltır: eşiğin
yansıtıcı olması, öte tarafın sınırsız olduğu ve gelen modun uygun içerikte
olduğu durum için geçerlidir.

[41] ayrıca bu geometrinin bir **analog gerçeklemesini** verir: anizotropik bir
yarı iletken ile elektronik bir metamalzeme arasındaki eklemde elektron
yayılımı, aynı denklemi sağlar. Bu, modelin sınanabilirliği açısından Bölüm
16.4'te belirtilen çıkmaza bir alternatif sunar: $v = c$ yüzeyi hazırlanamaz,
ancak aynı denklemi sağlayan bir malzeme ekleminde ayna davranışı ve tünelleme
ölçülebilir. Bunun bu modelin bir sınaması sayılıp sayılamayacağı ayrı bir
sorudur ve burada karara bağlanmamıştır.

### 9.2 Aynı seçimin yerçekimi tarafındaki görünümü

Yukarıdaki tercih madde tarafında, konjuge momentum üzerinden yapıldı. Aynı
tercih geometri tarafında geçiş yüzeyinin **dış eğriliği** üzerinde bir koşul
olarak yeniden ortaya çıkar: güçlü koşul onun yüzeyde sıfırlanmasını, zayıf
koşul yalnızca sürekli olmasını ister [6]. [9]'un genelleştirilmiş Lanczos
denklemine göre gerilim tensöründe dağılımsal bir terim, yani bir **yüzey
katmanı**, tam olarak dış eğrilik sürekli olduğunda yoktur.

Bunu somutlaştırmak için Bölüm 13.5'in ilk ayağı bir koordinatın fonksiyonu
yapılır:

$$g(\xi) = \mathrm{diag}\big(1,\, -\cos\lambda(\xi),\, -1,\, -1\big),
  \qquad \xi \in [-1, 1]$$

İmza, $\lambda$'nın $\pi/2$'yi geçtiği yerde değişir. Sabit $\xi$ yüzeylerinin
dış eğriliğinin tek önemsiz bileşeni

$$K = \tfrac{1}{2}\,\frac{d g_{11}}{d\xi}
    = \tfrac{1}{2}\,\lambda'(\xi)\,\sin\lambda(\xi)$$

olur ve geçiş noktasında $\sin\lambda = 1$ olduğundan orada
$K = \lambda'/2$'ye indirgenir. Üç profil karşılaştırılmıştır:

| Profil | Geçişte $K$ | Güçlü koşul | Zayıf koşul |
|--------|-------------|-------------|-------------|
| Doğrusal, $\lambda = \pi(\xi+1)/2$ | $0{,}785$ | Sağlanmıyor | Sağlanıyor |
| $\tanh$ basamağı | $2{,}368$ | Sağlanmıyor | Sağlanıyor |
| $\lambda = \pi/2 + (\pi/2)\sin^3(\pi\xi/2)$ | $0$ | **Sağlanıyor** | Sağlanıyor |

**Sonuç.** Güçlü koşul, ulaşılan metrik hakkında değil, ona **nasıl
yaklaşıldığı** hakkında bir kısıttır: geçiş profilinin tam o noktada durağan
olmasını ister. Doğrusal ya da $\tanh$ tipi bir geçiş bunu sağlamaz;
$\tanh$ en kötüsüdür, çünkü en dik olduğu yer tam geçiş noktasıdır.

Üç profilin hiçbirinde yüzey katmanı doğmaz, çünkü dış eğrilik her üçünde de
süreklidir. Yani Bölüm 9.1'deki ayrım, gerilim tensöründe dağılımsal bir terim
olup olmaması meselesi değildir; profilin geçişe teğet gelip gelmediği
meselesidir.

Bu, modelin yerçekimi tarafına atılmış ilk adımdır ve sınırlıdır: Einstein
denklemleri çözülmemiş, yalnızca eklem koşulunun geometrik karşılığı
hesaplanmıştır. [9] ve [11]'in uyarısı burada da geçerlidir, imza değişiminde
kanonik bir alan denklemi kümesi yoktur ve hangi kuruluşun kullanıldığı
belirtilmek zorundadır; burada kullanılan, dış eğriliğin süreksizliğini gerilim
tensörünün dağılımsal terimine bağlayan [9] kuruluşudur.

Bu kuruluşun pratik aracı [10]'da verilmiştir: öz-zaman koordinat olarak
alındığında imza değişimi boyunca düzgün genelleştirilmiş ortonormal çatılar
tanımlanabilir, ve bu hem Einstein denklemlerinin varyasyonel türetimini hem
dağılım teorisini sabit imzadaki hâllerinin doğrudan genellemesi olarak
kullanılabilir kılar. Modelin yerçekimi tarafına daha ileri götürülmesi
istenirse başlangıç noktası burasıdır.

### 9.3 Geometrinin izin verdiği geçişi alan yasaklıyor

Bölüm 9.1'in sonucu akı hakkındadır. Bundan ayrı ve daha zayıf bir soru vardır:
bir eğrinin teğeti, yüzeyi geçerken nedensel karakterini koruyor mu. Bu yalnızca
iki metriğe bakan bir sorudur.

İki metrik arasındaki fark hesaplanır:

$$v^T \eta' v - v^T \eta\, v = 2\,(v_1^2 + v_2^2) \;\geq\; 0$$

Fark daima negatif değildir. Sonuç doğrudan çıkar:

> Bölge I'de zaman-benzeri olan **her** yön, Bölge II'de de zaman-benzeridir.

Kapsama tek yönlüdür, tersi doğru değildir: örneğin $(0,1,0,0)$ Bölge I'de
uzay-benzeri, Bölge II'de zaman-benzeridir. Bölge II'nin zaman-benzeri yönleri
kesin olarak daha fazladır.

**Ayrımın önemi.** Eşikte bir eğriyi durduran nedensel bir engel **yoktur**;
teğeti karakterini koruyarak geçer. Bölüm 9.1'in yasakladığı şey akıdır, ve akı
eğrinin teğetinin değil, alanın ve eklem koşulunun bir özelliğidir. Dolayısıyla
şu iki ifade birbiriyle çelişmez:

- Yüzeyden geçen geometrik eğriler vardır.
- Yüzeyden akı geçmez.

Bu ayrım, Bölüm 7.4'te değinilen ilmek teoremiyle bu modelin eşik sonucunun aynı
anda doğru olabilmesinin nedenidir: o teorem geometrik eğriler hakkındadır, buradaki
sonuç alan akısı hakkındadır.

---

## 10. Küresel simetrik çözüm

Genel hareket denklemi küresel simetriye indirgendiğinde

$$r'' + \frac{2}{t} r' - \frac{2}{c^2 t}\,(r')^3 = 0$$

elde edilir.

İndirgeme adımları. Genel denklem

$$\left[\left(\frac{1}{c^2}(\nabla_{t'} r')^2 - 1\right)\delta_{ij}
  - \frac{1}{c^2}\frac{\partial r'}{\partial t'_i}\frac{\partial r'}{\partial t'_j}\right]
  \frac{\partial^2 r'}{\partial t'_i \partial t'_j} = 0$$

biçimindedir. Küresel simetride $\nabla_{t'} r' = r'(t)\,\hat{t}$ olduğundan
$(\nabla r')^2 = r'^2$ olur; ikinci türev operatörü radyal $r''$ ile iki teğetsel
$r'/t$ terimine ayrışır. Sonuç

$$A\left(r'' + \frac{2r'}{t}\right) - \frac{r'^2}{c^2} r'' = 0,
  \qquad A = \frac{r'^2}{c^2} - 1$$

olur ve $r''$ katsayısı $-1$ olduğundan yukarıdaki denklem çıkar.

### 10.1 Kapalı form çözüm

$$p = \frac{dr}{dt} = \pm\,\frac{c\,a}{\sqrt{a^2 - t^4}}$$

Bu ifadenin denklemi sağladığı doğrulanmıştır; eliptik fonksiyona gerek yoktur.

**Denge noktaları.** $p' = 0$ koşulu $p\,(p^2 - c^2) = 0$ verir, yani
$p \in \{0, +c, -c\}$, sabit çözüm ve ışık hızında genişleyen kabuk.

**Davranış.** $t = 0$'da $p = c$; $t \to \sqrt{a}$ iken $p \to \infty$.

**Alınan toplam yol sonludur:**

$$r = \int_0^{\sqrt{a}} p\, dt
    = \frac{\sqrt{\pi}\,\sqrt{a}\,c\,\Gamma(1/4)}{4\,\Gamma(3/4)}
    \approx 1{,}311\, c \sqrt{a}$$

İntegral sayısal olarak da hesaplanır. Uçtaki tekillik iki değişken dönüşümüyle
tamamen kaldırılır:

$$t = \sqrt{a}\,u \;\Rightarrow\; c\sqrt{a}\int_0^1 \frac{du}{\sqrt{1-u^4}},
\qquad
u = \sin\theta \;\Rightarrow\; c\sqrt{a}\int_0^{\pi/2} \frac{d\theta}{\sqrt{1+\sin^2\theta}}$$

**Fiziksel okuma.** Bu bir nokta parçacık yörüngesi değil, **küresel bir cephedir**.
Işık hızıyla başlar, hızlanarak genişler, sonlu sürede ve sonlu yarıçapta sonsuz
hıza ulaşır; ötesinde tanımsızdır.

---

## 11. Elektromanyetizma

$D$ Maxwell teorisine uygulandığında bütün sonuçlar tek bir matris çarpımından
çıkar.

**Potansiyel ve akım:**

$$A^\mu = (\phi/c,\, \mathbf{A}) \;\longmapsto\; A'^\mu = (A_z,\, A_y,\, A_x,\, \phi/c)$$
$$j^\mu = (\rho c,\, \mathbf{j}) \;\longmapsto\; j'^\mu = (j_z,\, j_y,\, j_x,\, \rho c)$$

Elektrik potansiyeli öte tarafta bir uzaysal bileşene dönüşür; yük yoğunluğu ile
akım yoğunluğu takas olur.

**Etkileşim terimi:**

$$A' \cdot j' = -\,A \cdot j$$

**Alan tensörü:** $F' = D^T F D$ altında elektrik ve manyetik bileşenler yer
değiştirir.

**Kritik sonuç, değişmez korunur:**

$$F_{\mu\nu}F^{\mu\nu} = F'_{\mu\nu}F'^{\mu\nu}$$

Tam eşitlik. Maxwell Lagrangian'ının kinetik terimi $D$ altında **değişmezdir**;
yalnızca kaynak terimi işaret çevirir:

$$L = -\frac{1}{4\mu_0}F_{\mu\nu}F^{\mu\nu} - A_\mu j^\mu
\qquad\longmapsto\qquad
L' = -\frac{1}{4\mu_0}F'_{\mu\nu}F'^{\mu\nu} + A'_\mu j'^\mu$$

**Dalga denklemi ve korunum:**

$$\Box A^\nu = \mu_0 j^\nu \;\longmapsto\; -\Box' A'^\nu = \mu_0 j'^\nu$$
$$\partial_\mu j^\mu = 0 \;\longmapsto\; \partial'_\mu j'^\mu = 0 \quad(\text{otomatik})$$

Korunumun doğrusallıkla taşındığı somut olarak da gösterilir: iki akımın toplamının
görüntüsü, görüntülerinin toplamına eşittir.

**Öncelik.** Superluminal uzay-zamanda elektromanyetizma [27]'de kurulmuştur.
Orada Maxwell denklemleri ve tek foton dalga denklemi, sıradan denklemlerin
superluminal dönüşümüyle ve kompleks nicelik kullanılmadan elde edilir; dahası
dönüşmüş denklemler **çözülür** ve sonsuz ışık konisi ile ona dik iki yapraklı
hiperboloit arasında kalan bölgede X biçimli çözümler bulunur. Bu bölümdeki
sonuçlar o çalışmanın kapsamı içindedir ve burada bağımsız olarak, tek bir
kongruans işleminden yeniden üretilmiştir. Özgünlük iddiası taşımaz; korunmasının
nedeni, modelin elektromanyetizmayı bozmadığının kendi araçlarıyla
gösterilebilmesidir.

---

## 12. İşaret seçimi

$\pm D$ ayrımı test edildi: her iki işaret de $\det = +1$ ve $M^2 = I$ koşullarını
sağlar, dolayısıyla bu koşullarla ayırt edilemezler. Ancak Bölüm 7'deki bulgu
işaretin anlamını netleştirir:

1. Her iki bölgede birer ok seçimi vardır (bizde zaman, ötede uzay).
2. $D$ bizim ok eksenimizi onların ok eksenine gönderir, seçimler bağımsız
   değildir, biri diğerini belirler.
3. Fiziksel olarak anlamlı olan tek büyüklük **bağıl işarettir**: iki okun
   hizalanması. Tek başına hiçbiri anlamlı değildir.
4. $\Sigma$ geçirgen olmadığı için iki bölge haberleşemez; dolayısıyla bağıl işaret
   **prensip olarak ölçülemez**.

**Sonuç:** İşaret belirsizliği bir eksiklik değil, yapısal bir özelliktir. Bizim
tarafta da zamanın oku denklemlerden türetilmez, Newton, Maxwell ve Schrödinger
denklemlerinin hepsi $T$-simetriktir; ok başlangıç koşulundan gelir.

### 12.1 $D$'nin yapısı: yön-bağımlı bir involüsyonla karşılaştırma

$D$'yi yön-bağımlı bir involüsyonla karşılaştırmak, onun grup içindeki yerini
netleştirir. $\theta = \varphi = 0$ ekseni için yön-bağımlı involüsyon $t$ ile $z$'yi
işaretli olarak takas eder ve $\Lambda_{\inf}^2 = I$ sağlar; yani o da bir
involüsyondur, ancak yalnızca iki koordinatı değiştirir.

$D$ ise dört koordinatı birden değiştirir ve içinde bir $x \leftrightarrow y$ takası
barındırır. Bu takasın üç boyuttaki determinantı $-1$'dir, dolayısıyla bir $SO(3)$
elemanı değildir. Bunun doğrudan sonucu şudur:

> $D$, yön-bağımlı involüsyonun ürettiği genişletilmiş grup $L_{\text{ext}}$ içinde
> **bulunmaz**.

Yani $D$ ile yön-bağımlı formlar aynı ailenin iki üyesi değildir; farklı yapılardır.
Bölüm 18'de yön-bağımlı adayların neden $D$'nin yerini alamadığı ayrıca gösterilir.

---

## 13. Kara delik ufkuyla karşılaştırma

Schwarzschild metriğinde ufkun içinde $dt^2$ ve $dr^2$ terimlerinin işaretleri yer
değiştirir: $r$ zaman-benzeri, $t$ uzay-benzeri olur. Merkeze düşmek kaçınılmaz hale
gelir, dışarıda geleceğe ilerlemenin kaçınılmaz olması gibi. Benzerlik buraya
kadardır.

### 13.1 Kaç koordinat dönüyor

Ufuk için ($f = 1 - r_s/r$):

- $r > r_s$: $dt$ zaman-benzeri, $dr$ uzay-benzeri
- $r < r_s$: $dt$ uzay-benzeri, $dr$ zaman-benzeri
- Açı koordinatları değişmez
- İmza: $(+,-,-,-) \to (-,+,-,-)$, yani **hâlâ** 1 zaman + 3 uzay

$\Sigma$ için dört koordinat birden döner: $(1,3) \to (3,1)$.

### 13.2 Geçirgenlik farkının kaynağı

| | Ufuk | $\Sigma$ |
|---|------|----------|
| İmza sınıfı | $(1,3) \to (1,3)$, değişmiyor | $(1,3) \to (3,1)$, değişiyor |
| Lorentz yapısı | Korunuyor | Değişiyor |
| Normal vektör tipi | Sürekli dönüyor | Sıçrayarak değişiyor |
| Konjuge momentum | Sürekli; sıfır olmak zorunda değil | İşaret çevirmek zorunda, dolayısıyla $\pi = 0$ |
| Sonuç | **Geçirgen** | **Yansıtıcı** |

### 13.3 Sürekli köprü kurulabilir mi

Denendi. $(1,3)$'ten $(3,1)$'e sürekli bir interpolasyon, örneğin

$$g(\lambda) = \mathrm{diag}(1,\, -\cos\lambda,\, -\cos\lambda,\, -\cos\lambda),
\qquad \det g = -\cos^3\lambda$$

$\lambda = \pi/2$'de $\det g = 0$ verir: **dejenere metrik**. Orada metriğin tersi
yoktur ve alan denklemi tanımsızdır. Bu genel bir sonuçtur, iki imza sınıfı
arasında dejenere olmayan sürekli bir yol yoktur.

**Bu argümanın iki kusuru vardır ve Bölüm 13.5'te düzeltilmiştir.** Birincisi,
yukarıdaki yol hedefine varmaz: $\lambda = \pi$'de $\mathrm{diag}(1,1,1,1)$
verir, yani Öklid imzası $(4,0)$'a ulaşır, $(3,1)$'e değil. Dolayısıyla
kozmolojideki geçişi tarif eder, buradakini değil. İkincisi, determinant
üzerinden yürüyen gerekçe geçersizdir: $\det \eta = \det \eta' = -1$ olduğundan
determinant iki uç arasında işaret değiştirmek zorunda değildir.

Bölüm 13.5 doğru yolu kurar ve sonuç yukarıdakinden farklı çıkar.

### 13.4 Sonuç

Bu karşılaştırmanın diğer tarafı literatürde ayrıntılı işlenmiştir. [12] bir
Schwarzschild kara deliğinin yeniden doğuşunu çift imza değişimi olarak modeller;
[13] ufuk boyunca imza değiştiren bir Schwarzschild metriğini Hadamard partie
finie ile düzenleyip **vakum Einstein denklemlerinin çözümü olduğunu ispatlar** ve
tekilliğin bu yolla önlendiğini gösterir; [14] ise ufka varış öz-zamanının sonlu
kaldığını göstererek [13]'ün modelinin gözden geçirilmesi gerektiğini belirtir ve
dejenereliğin geometrik içeriğini verir: metriğin dejenere olması nedensel
konileri bir doğruya, dual metriğin dejenere olması bir hiperdüzleme çökertir.
Bu koni-çökmesi resmi, aşağıdaki 13.3'teki argümanın geometrik karşılığıdır.

Kara delik ufku bu modelin "kısmi" hâli değildir; farklı sınıfta bir olaydır. Ufuk
imza sınıfını korur, bu yüzden geçirgendir. $\Sigma$ imza sınıfını değiştirir.
Aralarında sürekli köprü kurmak dejenere bir nokta gerektirir; ancak bu noktanın
ne kadar kötü olduğu Bölüm 13.5'te hesaplanmıştır ve sanıldığı kadar kötü
değildir.

### 13.5 İki imza arasında sürekli yol ne kadar dejenere olmak zorunda

Soru şudur: $(1,3)$'ten $(3,1)$'e giden sürekli bir yol boyunca aynı noktada kaç
öz-değerin birden sıfırlanması gerekir. Dejenereliğin kendisi kaçınılmazdır,
çünkü pozitif öz-değer sayısının birden üçe çıkması gerekir ve her değişim sıfırdan
geçer; ancak bu sayının **kaç tane birden** sıfırlandığını söylemez.

**Doğrudan yol.** İki bileşen birlikte çevrilirse

$$g(\lambda) = \mathrm{diag}(1,\, -\cos\lambda,\, -\cos\lambda,\, -1)$$

elde edilir. $\lambda = 0$'da $(1,3)$, $\lambda = \pi$'de $(3,1)$ verir, yani
hedefe varır. $\lambda = \pi/2$'de **iki öz-değer birden** sıfırlanır: rank iki
düşer. Bütün yol boyunca en kötü nokta budur.

**Kademeli yol.** Bileşenler teker teker çevrilirse iki ayaklı bir yol çıkar:

$$g_1(\lambda) = \mathrm{diag}(1,\, -\cos\lambda,\, -1,\, -1)
  \;:\; (1,3) \longrightarrow (2,2)$$
$$g_2(\lambda) = \mathrm{diag}(1,\, 1,\, -\cos\lambda,\, -1)
  \;:\; (2,2) \longrightarrow (3,1)$$

Her iki ayakta da rank yalnızca **bir** düşer.

| Yol | Varış | En kötü rank düşüşü |
|-----|-------|---------------------|
| $\mathrm{diag}(1,-\cos\lambda,-\cos\lambda,-\cos\lambda)$, Bölüm 13.3 | $(4,0)$, hedef değil | 3 |
| Doğrudan, iki bileşen birlikte | $(3,1)$ | 2 |
| Kademeli, $(2,2)$ üzerinden | $(3,1)$ | **1** |

**Sonuç.** Dejenerelik kaçınılmazdır, ama rank-2 dejenerelik **kaçınılmaz
değildir.** $(1,3)$'ten $(3,1)$'e, her noktada yalnızca tek bir öz-değerin
sıfırlandığı sürekli bir yol vardır.

Bunun önemi şuradadır: literatürün dejenere yüzeyle çalışan araçları tam olarak
rank-1 dejenerelik için kuruludur. [15] ve [16]'nın "transvers radikal" dediği
yapı budur, ve [35]'in kink modeli, [37]'nin Colombeau kuruluşu, [13]'ün Hadamard
düzenlemesi bu sınıfta çalışır. Dolayısıyla bu modelin geçişi, o araçların
erişemeyeceği bir yerde **değildir**.

Bedeli vardır: kademeli yol $(2,2)$ imzasından, yani iki zamanlı bir bölgeden
geçer. Bu, Bölüm 14'teki sıralama sorunlarının orada da geçerli olacağı anlamına
gelir, ancak üç zaman yerine iki zamanla ve yalnızca ara bölgede. Bu ara bölgenin
fiziksel olarak var sayılıp sayılamayacağı burada karara bağlanmamıştır.

Bölüm 13.3'ün "iki imza sınıfı arasında dejenere olmayan sürekli bir yol yoktur"
ifadesi doğrudur ve Sylvester'ın sonucudur. Ondan çıkarılan "dolayısıyla geçiş
sağlanmaz" ifadesi ise **doğru değildir** ve geri çekilmektedir.

---

## 14. Kanonik kuantumlama: üç bağımsız engel

Bölge II'de kanonik yapı çalışmaz. Üç ayrı engel vardır ve üçü de aynı köke bağlıdır.

### 14.1 Cauchy yüzeyi yok

Bölge II'de konjuge momentum üç bileşenlidir:

$$\pi_i = \frac{\partial L'}{\partial(\partial_{t_i}\psi)} = \partial_{t_i}\psi,
  \qquad i = 1,2,3$$

Eşanlı komutasyon için uzay-benzeri bir başlangıç yüzeyi gerekir. $t_1 = $ sabit
alındığında geriye $(t_2, t_3, r)$ kalır; $t_2$ ve $t_3$ zaman-benzeri olduğundan bu
yüzey uzay-benzeri **değildir**. Standart bağıntı

$$[\psi(r),\, \pi_i(r')] = i\hbar\,\delta(r - r')$$

indis sayımı bakımından tutarsızdır: solda üç indis, sağda tek boyutlu delta.
Tutarlılık ancak tek konjuge momentum ve üç boyutlu uzay dilimi ile sağlanır; bu da
yalnızca Bölge I'de olur.

### 14.2 Feynman propagatörü tanımsız

Propagatördeki $i\varepsilon$ reçetesi zaman sıralamasını kodlar. Üç zamanda tek bir
sıralama olmadığı için kontur seçilemez.

### 14.3 Kararlı vakum yok

Öteleme simetrilerinden üç enerji bileşeni çıkar (Bölüm 7), dolayısıyla Hamiltonyen
bir **vektördür**. "Alttan sınırlı olma" ve "en düşük enerji" kavramları tanımsızdır.

### 14.4 Değerlendirme

Üç engel de tek bir köke bağlıdır: **üç zaman, dolayısıyla sıralama yok.**

Bu, Bölüm 6'daki determinizm kaybının kuantum düzeyindeki karşılığıdır ve Bölüm
9'daki "eşik geçirgen değil" sonucuyla uyumludur, iki bölge kuantum düzeyinde de
birleştirilemez. Model böylece üç bağımsız yoldan aynı sonuca varır: **Bölge II
kendi içinde tutarlıdır, ancak Bölge I ile birleştirilemez.**

**Bu engellerin aşıldığı iddiası ve akıbeti.** [22], burada sayılanlarla aynı
karakterdeki üç engelin, yani alttan sınırsız spektrumun, çerçeveye bağlı
kararsız vakumun ve kovaryant olmayan komütasyon bağıntılarının, Lorentz grubunun
fazla küçük bir Hilbert uzayında temsil edilmesinden kaynaklandığını ve uzayın
$\mathcal{F} \otimes \mathcal{F}^\star$ biçiminde ikiye katlanmasıyla
kalktığını öne sürer. [23] bu yapının kuantum bir teori **olmadığını** gösterir:
ikiye katlanmış uzayda alan her noktada komüte eder, dolayısıyla kanonik
komütasyon bağıntıları sağlanmaz ve geriye kuantum dinamiği olmayan klasik bir
teori kalır; ayrıca Feynman reçetesi üniterliği bozar. [24] aynı sonucu sanal
takyonlar için de kurar. Dolayısıyla bu bölümdeki engeller, bilinen tek onarım
girişimi karşısında ayakta kalmaktadır.

Kurtarılabilen yapı yol integralidir:

$$Z = \int \mathcal{D}[\psi]\; e^{\,i S'[\psi]/\hbar},
  \qquad S' = \int L'\, d^3t\, dr$$

Cauchy yüzeyi gerektirmediği için tanımlıdır.

---

## 15. Yol integrali ve Öklid yapısı

### 15.1 Wick dönüşü zorunlu bir seçim veriyor

| Seçenek | Öklid çekirdeği | Sonuç |
|---------|-----------------|-------|
| Üç zamanı birden döndür | $\mu - k_1^2 - k_2^2 - k_3^2 - q^2/c^2$ | Iraksar |
| Tek uzay eksenini döndür | $\mu + k_1^2 + k_2^2 + k_3^2 + q^2/c^2$ | **Yakınsar** |
| Bileşke yön |, | Tanımsız |

Yalnızca ikinci seçenek çalışır. Seçim keyfi değil, zorunludur. (Bileşke yön,
$O(3)$-değişmez olmadığı için tanımsızdır.)

### 15.2 Yorum: "tek olan ekseni döndür"

Bölge I'de zaman tek boyutludur ve Wick dönüşü **zamanı** döndürür. Bölge II'de uzay
tek boyutludur ve Wick dönüşü **uzayı** döndürür. Bu, $D$'nin zaman eksenini uzay
eksenine göndermesiyle tam tutarlıdır.

### 15.3 Öklid propagatörü

$$G_E(k,q) = \frac{1}{k_1^2 + k_2^2 + k_3^2 + \dfrac{q^2}{c^2} + \mu}$$

Payda reel argümanlar için daima $\geq \mu > 0$'dır, dolayısıyla **kutup yoktur**.
Tekillik olmadığı için $i\varepsilon$ reçetesine ihtiyaç duyulmaz ve zaman sıralaması
gerekmez. Kanonik yapıda çözülemeyen sıralama problemi (Bölüm 14.2) yol integralinde
ortadan kalkar.

Konum uzayında:

$$G_E(x) \sim \frac{m}{4\pi^2 x} K_1(m x)$$

Bu, Bölge I'inkiyle **aynı** fonksiyondur.

$m = 0$ durumunda payda yalnızca $k = q = 0$'da sıfırlanır, Bölge I'dekiyle aynı
tip kızılötesi tekillik, yeni bir sorun değil.

### 15.4 Ana bulgu: iki bölge ortak bir Öklid teorisinin analitik devamlarıdır

Öklid bölgesine geçildiğinde her iki bölgenin imzası $(+,+,+,+)$ olur ve
propagatörler aynıdır. **Öklid bölgesinde iki taraf ayırt edilemez.** Fark yalnızca
Lorentz bölgesine geri dönerken hangi eksenin döndürüldüğünde ortaya çıkar.

> $D$, imzayı değiştiren bir dönüşüm değildir; ortak Öklid teorisinden hangi eksende
> çıkılacağını seçen operatördür.

Burada Wick dönüşü elle yapılan bir seçimdir.

### 15.5 Kalan açık

Vakum problemi (Bölüm 14.3) Öklid bölgesinde çözülür, pozitif tanımlı çekirdek iyi
tanımlı bir ölçüm verir. Ancak Lorentz bölgesine analitik devam yapıldığında
Hamiltonyenin vektör olması sorunu geri gelir. Yani Bölge II'de **hesap
yapılabilir, ama sonuçların parçacık yorumu tanımsızdır.** Korelasyon fonksiyonları
hesaplanabilir; "kaç parçacık var" sorusu cevaplanamaz.

### 15.6 Türetilmiş bir geçişle karşılaştırma

Bu modelde geçiş **varsayılır**: ışık hızında olur, anidir, hızdan bağımsızdır.
[17] ve [18]'de ise geçiş **türetilir**. Holonomi düzeltmeleri etkin kısıt
cebirini bir çarpanla deforme eder,

$$\Omega(\rho) = 1 - \frac{2\rho}{\rho_c}$$

ve imza bu çarpanın işaretini izler: $\Omega > 0$ iken Lorentzian, $\Omega < 0$
iken Öklid. Dolayısıyla geçiş, teorinin kendi dinamiğinden çıkan belirli bir
yerde, $\rho = \rho_c/2$ yoğunluğunda gerçekleşir.

Hesaplanan sonuçlar:

- $\Omega$, tam olarak kritik yoğunluğun yarısında sıfırlanır.
- $\rho < \rho_c/2$ için Lorentzian, $\rho > \rho_c/2$ için Öklid.
- $\Omega$ yoğunlukta doğrusaldır ve eğimi her yerde sonludur, yani imza
  **sürekli** döner, sıçramaz.

| | Bu model | [17], [18] |
|---|---|---|
| Geçişin statüsü | Varsayılır | Dinamikten türetilir |
| Konumu belirleyen | Hız, $v = c$ | Yoğunluk, $\rho = \rho_c/2$ |
| Geçişin biçimi | Ani, ayrık | Sürekli, deformasyon çarpanıyla |
| Dönen koordinat sayısı | Dört | Bir |
| Varılan imza | $(3,1)$, üç zaman | $(4,0)$, Öklid |
| Bağlı olduğu teori | Yok | Döngü kuantum kozmolojisi |

Yöntem olarak türetilmiş olan üstündür ve burada tercih edilen kuruluş değildir.
Ancak son iki satır belirleyicidir: **iki geçiş aynı olay değildir.** Orada tek
bir koordinat döner ve Öklid imzasına varılır; burada dört koordinat döner ve üç
zamanlı bir imzaya varılır. Dolayısıyla [17] ve [18], bu modelin geçişi için bir
türetim **sağlamaz**; sağladığı şey, bir imza geçişinin varsayılmak yerine
türetilebileceğinin örneğidir.

Bu modelin geçişinin de benzer biçimde türetilebilmesi açık bir sorudur ve
Bölüm 21'de öyle listelenmiştir.

İki bölge ayrı yapılar değil, tek bir yapının iki dalıdır.

---

## 16. Vakum yorumu ve Casimir imzası

### 16.1 Parçacık kavramı neden tanımsız

Parçacık kavramı üç yapıya dayanır:

1. Pozitif/negatif frekans ayrımı, tek zaman ekseni gerektirir.
2. Hamiltonyenin alttan sınırlı olması, sıralama gerektirir.
3. Poincaré grubunun üniter temsili, tek zamanlı grup yapısı gerektirir.

Bölge II'de üçü de yoktur.

### 16.2 Ama teori boş değil

Korelasyon fonksiyonları $\langle \psi(x)\psi(y)\rangle$ Öklid bölgesinde tanımlıdır
ve analitik devamla Lorentz bölgesine taşınabilir.

> Bölge II bir parçacık teorisi değil, bir **korelasyon teorisidir**. "Kaç parçacık
> var" sorusu cevapsızdır; "ne kadar korelasyon var" sorusu cevaplanabilir.

Bu, Bölüm 7'deki "yörünge yok, cephe var" sonucunun kuantum karşılığıdır.

**Açık kalan zorluk.** [19], altta yatan klasik teori ne olursa olsun, imza
değiştiren bir arka planda kuantum alanının ciddi sorunlar ürettiğini savunur;
başlıcası, naif olarak sonsuz sayıda parçacık üretilmesidir, ki bunu bir
potansiyel bariyerinin yarısına kadar tünellemeye benzetip WKB tahminleri
verirler. Yukarıdaki "parçacık değil korelasyon" okuması bu sorunu ortadan
kaldırmaz; sorunun sorulamaz hâle geldiği bir çerçeve önerir. Bu ikisi arasındaki
fark önemlidir ve burada bir çözüm iddia edilmemektedir.

### 16.3 Casimir etkisi

$\Sigma$ üzerindeki $\pi = 0$ koşulu (Bölüm 9) kuantumda **Neumann** sınır koşuluna
karşılık gelir.

**Tek yüzey.** Casimir etkisi doğmaz, ikinci duvar yoktur. Yalnızca yüzey yakınında
vakum enerji yoğunluğunda $\langle T_{00}(z)\rangle \sim \hbar c / z^4$ tipi bir
kayma olur; renormalizasyon gerektirir.

**İki yüzey arasında.** $L$ aralıklı iki $\Sigma$ yüzeyi arasında, kütlesiz tek
reel skaler alan için:

$$\frac{E}{A} = -\frac{\pi^2 \hbar c}{1440\, L^3}$$

Katsayının seçimi önemlidir. $-\pi^2\hbar c/(720 L^3)$ değeri iki polarizasyonlu
elektromanyetik alana aittir; burada ele alınan $\psi$ tek bileşenli bir skaler
olduğu için değer bunun yarısıdır. Ayrıca aynı katsayı hem Dirichlet-Dirichlet
hem Neumann-Neumann için geçerlidir, dolayısıyla bu sayı Bölüm 9'daki eklem
koşulu tartışmasından **bağımsızdır**. Yalnızca karışık Dirichlet-Neumann
durumunda işaret döner ve kuvvet itici olur.

Bu ifade kütlesiz limit içindir. Kütleli alan için, $mL \gg 1$ bölgesinde Casimir
enerjisi $e^{-2mL}$ ile üstel olarak bastırılır; dolayısıyla yukarıdaki sonuç
$mL \ll 1$ idealizasyonudur.

Ölçek yasası doğrulanır: $L$ iki katına çıkınca enerji sekizde bire düşer.

**Bir çelişki.** [25] takyonik bir alan için Casimir enerjisini mutlak
eşzamanlama şemasında Abel-Plana formülüyle hesaplar ve yukarıdakinden nitel
olarak farklı bir sonuç bulur: enerji ve kuvvet tekdüze değildir, defalarca
işaret değiştirir, uzaklığın türevlenebilir bir fonksiyonu değildir ve kuvvette
sonsuza giden sıçramalar vardır. Buradaki hesap ise pürüzsüz ve daima çekicidir.
Fark, ele alınan alanın farklı olmasından gelir: [25]'in alanı negatif kütle
kareli, yani takyonik bir alandır; burada Bölge II alanı **reel kütlelidir** ve
tuhaflık kütlede değil imzadadır. İki hesabın aynı fiziksel duruma ait olmadığı,
dolayısıyla çelişmedikleri kanısındayız; ancak bu ayrımın kendisi sınanmamıştır.

### 16.4 İki eşik yüzeyinin ayırt edeceği şey

Bölüm 19.5, tek bir duvarda hangi öz-eşlenik koşul seçilirse seçilsin tam
yansıma olduğunu gösterdi. Tek yüzey hiçbir şeyi ayırt etmez. **İki** yüzey eder.

İki duvar arasındaki mod spektrumu, duvarların aynı koşulu mu yoksa karşıt
koşulları mı taşıdığına bağlıdır. Aynı koşul durumunda modlar $n\pi/L$,
karşıt koşul durumunda $(n+\tfrac{1}{2})\pi/L$ olur. İki toplamı bağlayan
özdeşlik

$$\sum_{n\geq 0}\Big(n+\tfrac{1}{2}\Big)^{-s} = (2^{s}-1)\sum_{n\geq 1} n^{-s}$$

sayısal olarak yakınsadığı bölgede doğrulanmış, ardından Casimir enerjisinin
ihtiyaç duyduğu $s = -3$ değerine sürdürülmüştür. Orada çarpan

$$2^{-3} - 1 = -\tfrac{7}{8}$$

olur. Sonuç:

| Yapılandırma | $E/A$ | Kuvvet |
|--------------|-------|--------|
| İki duvar **aynı** koşulu taşıyor | $-\dfrac{\pi^2\hbar c}{1440\,L^3}$ | Çekici |
| Duvarlar **karşıt** koşulları taşıyor | $+\dfrac{7}{8}\cdot\dfrac{\pi^2\hbar c}{1440\,L^3}$ | İtici |

**Bu modelin öngörüsü.** Eşik koşulu iki $\Sigma$ yüzeyinde de aynıdır,
dolayısıyla model **çekici** bir kuvvet öngörür. Kuvvetin **işareti** ayırt
edicidir, yalnızca büyüklüğü değil; ve büyüklük $L^{-3}$ ölçeklenmesini taşır.

Bu, çalışmanın ayırt edici tek öngörüsüdür. Koşulludur ve koşulu ağırdır:
$v = c$ değerinde iki yüzey gerekir, ki bugün hiçbir deney bunu hazırlayamaz.
Öngörünün varlığı ile sınanabilirliği ayrı şeylerdir ve burada yalnızca birincisi
sağlanmaktadır.

**Karşılaştırma.** Literatürde imza değişiminin sınanabilir hâle getirildiği iki
örnek vardır ve ikisi de burada izlenmeyen bir yol tutar. [36], pürüzsüz bir
Öklid-Lorentz geçişinin sonlu bir hızlanan genişleme aralığı **sürdüğünü**
gösterir; yani geçişi etkiyebileceği bir yere, erken evrene koyar ve gözlenen bir
niceliğe, enflasyon gözlemlerine bağlar. [17] benzer biçimde skaler ve tensör güç
spektrumlarına düzeltmeler türetir. [34] ise fazladan bir zaman boyutunu Bell
tipi bir deney önerisine bağlar.

Ortak yöntem şudur: geçişi kozmolojik ya da laboratuvar bağlamına yerleştirip
zaten ölçtüğümüz bir şeye etkisini hesaplamak. Bu çalışmada geçiş $v = c$
yüzeyine sabitlenmiştir ve o yüzey hiçbir gözlemin içinde bulunmadığı için aynı
yol izlenememiştir. Modelin sınanabilir hâle gelmesi, geçişin nerede
gerçekleşebileceği sorusunun yeniden açılmasına bağlıdır; bu Bölüm 21'de açık
olarak kaydedilmiştir.

**Değerlendirme.** $\Sigma$, $v = c$ yüzeyidir ve laboratuvarda erişilebilir
değildir. Dolayısıyla bu, prensipte var olan ama pratikte ölçülemeyen bir imzadır.

---

## 17. Sylvester engeli ve modelin duruşu

Bu bölüm modelin kendi sınırını belirler.

Aynı sınıra dışarıdan da işaret edilmiştir. [3], burada kullanılan türden bir
çevirmenin birim operatör artı keyfi bir yeniden etiketleme olduğunu, 24
permütasyondan altısının çizgi elemanını koruduğunu ve kalan on sekizinin boost
yönü ne olursa olsun belirli bir ekseni takas ettiğini, dolayısıyla koordinat
bağımlı olduğunu savunur; buradaki $D$ o listenin ilk matrisidir. Bu bölümdeki
sonuç, itirazın cebirsel çekirdeğini kabul eder. [28] ise aynı kopukluğu başka
bir yönden dile getirir: iki dalı birbirine bağlayan tutarlı bir formalizm
yoktur. Bu çalışma bu tespiti bir eksiklik değil, Bölüm 9.1'de nicelleştirilen
bir sonuç olarak okur.

### 17.1 Belirleyici sonuç

> Reel hiçbir $M$ için $M^T \eta\, M = -\eta$ olamaz.

Gerekçe: kongruan matrisler aynı imzaya sahiptir (Sylvester atalet yasası).
$\eta$'nın imzası $(1,3)$, $-\eta$'nınki $(3,1)$'dir. Sayısal tarama da yapıldı -
20.000 rastgele reel $4\times4$ matris üzerinde $M^T \eta M + \eta$ hatasının
ulaşabildiği en küçük değer sıfıra yaklaşmaz.

### 17.2 Bu modelin $D$'si ne sağlıyor

$$D^T \eta'\, D = -\eta \qquad \text{(sağlanıyor)}$$
$$D^T \eta\; D = -\eta \qquad \text{(sağlanmıyor)}$$

Yani "imza değişimi" iki **farklı** metrik arasındaki bir ilişkidir. $\eta'$ elle
konur; bu, dönüşüm düzeyinde gerçek bir imza çevirmesi olmadığı anlamına gelir.

### 17.3 Çatal

| | Yön-kovaryant | Gerçek imza çevirme |
|---|---------------|---------------------|
| Yön-bağımlı involüsyonlar | Evet | Hayır |
| Bu modelin $D$'si | Hayır | Hayır ($\eta'$ elle konur) |
| $\pm i \Lambda$ | Evet | Evet, ama reel değil |

İkisini birden veren reel dönüşüm yoktur; Sylvester bunu yasaklar. $\pm i\Lambda$
uygulamak, metriği sabit tutup $m \to \pm im$ yapmakla eşdeğerdir, yani sanal kütle.

### 17.4 Modelin duruşu

Bu çalışmada **reel kütle korunmaktadır**. Bunun bedeli açıkça kabul edilir: dönüşüm
düzeyinde gerçek bir imza çevrilmesi elde edilmez; $D$ iki farklı metrik arasında
bir eşlemedir.

Buna karşılık Bölüm 7, 9, 13 ve 15'teki sonuçlar bu sınırdan etkilenmez, çünkü onlar
dönüşüm düzeyinde değil **metrik düzeyinde** kurulmuştur: iki bölge ayrı metriklerle
tanımlanır ve aralarındaki ilişki eklem koşullarıyla ele alınır. Orada imza, bir
dönüşümle değil, metriğin kendisinin değişmesiyle değişir ve Sylvester engeline
takılmaz.

> Modelin sağlam çekirdeği dönüşüm kolu değil, imza-değişimi eklem koşulları koludur.
> İleride yeniden çerçeveleme yapılacaksa başlangıç noktası bu olmalıdır.

---

## 18. Yön-bağımlı $D$ denemesi

$D$'nin belirli bir ekseni sabit tutması, koordinat-bağımlı olduğu yönünde bir
itiraza açıktır. Bunu gidermek için $D$'nin yön-bağımlı hale getirilmesi denendi.
$n$ boost yönü birim vektörü ve $P = n n^T$ olmak üzere:

| Aday | $M^2 = I$ | $\det$ | $\eta$-çevirme |
|------|-----------|--------|----------------|
| $\begin{pmatrix} 0 & -n^T \\ -n & I-P\end{pmatrix}$ | Evet | $-1$ | Hayır |
| $\begin{pmatrix} 0 & n^T \\ n & I-P\end{pmatrix}$ | Evet | $-1$ | Hayır |
| $\begin{pmatrix} 0 & n^T \\ n & P-I\end{pmatrix}$ | Evet | $-1$ | Hayır |

Üç form da her $n$ yönü için involüsyondur; bu cebirsel olarak da görülür, çünkü
$n^T n = 1$, $(I-P)n = 0$ ve hem $(I-P)^2$ hem $(P-I)^2$ ile $P$'nin toplamı $I$
verir. Dolayısıyla involüsyon olmak bu adayları ayırt eden bir özellik değildir;
ayırt edici olan hiçbirinin imzayı çevirmemesidir. Buna karşılık Householder tipi
$\begin{pmatrix} 0 & n^T \\ n & I-2P\end{pmatrix}$ formu involüsyon bile değildir ve
o da imzayı çevirmez.

Sonuç: bu formlar aralığı yalnızca $t$ ile $n$'nin gerdiği iki boyutlu alt uzayda
çevirir; $n$'ye dik yönlerde çevirmez. Üç ayrı olay üzerinde doğrulandı:

- $t$ ve $n$'nin gerdiği düzlemde kalan bir olay,
- $n$'ye dik yönde kalan bir olay ($I - P$ bloğu orada birim gibi davranır),
- genel bir olay: aralık ne korunur ne çevrilir.

Yani yön-kovaryant formlar aralığı **korur** ($s'^2 = s^2$), işaret çevirmez. İşaret
çevirme ancak metrik bileşenlerinin yeniden sıralanmasıyla elde edilir, bu da
Bölüm 17'deki sonucun bir başka görünümüdür.

---

## 19. Modele yöneltilebilecek itirazlar ve bunlara cevaplar

Aşağıdaki maddeler, literatürde bu modelin çekirdeğini hedefleyen ya da hedefleme
potansiyeli taşıyan argümanlardır. Her madde önce itirazı olabildiğince güçlü
hâliyle aktarır, ardından bu çalışmanın cevabını verir. Cevabın bulunmadığı
durumlarda bu açıkça yazılmıştır.

Sayısal ya da yapısal bir iddia taşıyan maddeler, tartışılmakla kalmayıp
**hesaplanmıştır**; ilgili doğrulamalar 19.1, 19.2 ve 19.3 alt bölümlerinde
verilmiştir. Yalnızca kavramsal olan maddeler, örneğin işlemsel içeriğin
bulunmaması, bir hesaba dönüştürülemediği için metinde bırakılmıştır.

**1. "Superboost sıradan bir Lorentz boostudur, çevirme ise yalnızca yeniden
etiketlemedir."** [3]. Cebirsel çekirdek kabul edilmektedir: Bölüm 17'de
gösterildiği gibi $D$ tek bir metriğin imzasını çevirmez, iki metrik arasında bir
eşlemedir ve $\eta'$ elle konur. Buna karşılık itiraz, dönüşüm düzeyinde
kurulmuş sonuçları hedefler. Bölüm 9, 9.1, 13 ve 15'teki sonuçlar metrik
düzeyinde kurulmuştur: iki bölge ayrı metriklerle tanımlanır ve aralarındaki
ilişki eklem koşullarıyla ele alınır. Bir yeniden etiketlemenin akı korunumundan
$|R| = 1$ türetmesi beklenmez. Dolayısıyla itiraz, modelin dönüşüm kolunu keser,
eklem koşulları kolunu kesmez.

**2. "İki dal ayrıktır, bunları bağlayan tutarlı bir formalizm yoktur, dolayısıyla
program eksiktir."** [28]. Tespit doğrudur ve burada da elde edilmektedir. Ayrım
şuradadır: [28] bunu tamamlanması gereken bir eksiklik sayar, bu çalışma ise
Bölüm 9.1'de nicelleştirilen bir sonuç sayar. Ayrıklık bir boşluk değil,
güçlü eklem koşulunun öngörüsüdür.

**3. "Superluminal gözlemciler kuantum süperpozisyonlarını açıklamaz."** [30], ve
benzer biçimde [29]. Bu itirazlar [1]'in kuantum kuramını görelilikten türetme
iddiasını hedefler. Bu çalışma o iddiayı taşımaz ve gerektirmez; burada kurulan
şey bir kinematik ile onun alan denklemleridir. İtiraz kabul edilmekte, ancak
modelin bir parçasını etkilememektedir.

**4. "Koordinat haritası yazmak fizik teorisi kurmak değildir; süperpozisyon
kâğıt üzerinde çizilen yollarla değil, kapalı bir girişim döngüsüyle
tanımlanır."** [33]. Bu itiraz kabul edilmektedir ve bu metin için geçerlidir.
[33]'ün üç katmanlı ayrımı kullanılırsa, buradaki çalışma kinematik katmanında ve
kısmen dinamik katmanındadır; işlemsel katmanda hiçbir şey sunmamaktadır. Bölüm
21'de bu bir açık nokta olarak listelenmiştir.

**5. "Sıralamayı korumayan superluminal dönüşüm kabul eden her çerçeve, sonlu
bilgiden, zaman-simetrik bilgi içeriğinden, geçmişin bellek tutmasından ya da
zamanın nedensel sıralamayı belirlemesinden birini bırakmak zorundadır."** [31].
Bu bir no-go teoremidir ve buradaki çerçeveyi de bağlar. Bölüm 6'daki determinizm
kaybı denklem tipinden çıkar ve teoremin dördüncü seçeneğine, yani zamanın
nedensel sıralamayı belirlemesinden vazgeçmeye karşılık gelir; Bölüm 7'de Bölge
II'nin zaman oku taşımadığı zaten türetilmiştir. Dolayısıyla model teoremin
gerektirdiği bedeli ödemektedir. Ancak teoremin bir başka sonucu, bu tür
indeterminizmin sonlu bilgiden kaynaklanamayacağıdır; bu, modelin ontolojisi
hakkında burada karşılanmamış bir talep koyar.

**6. "Takyonik alan kuramındaki engeller Hilbert uzayı ikiye katlanarak
kalkar."** [22]. Bu, Bölüm 14'ün üç engelini doğrudan hedefleyen tek onarım
girişimidir. [23] bu yapının kuantum bir teori olmadığını göstermiştir: alan her
noktada komüte eder, kanonik komütasyon bağıntıları sağlanmaz, Feynman reçetesi
üniterliği bozar. [24] aynı sonucu sanal takyonlar için kurar. Bölüm 14'ün
engelleri bu nedenle ayakta kalmaktadır. Aynı sonuçların daha geniş okunuşu ise
modelin aleyhinedir: superluminal nesnelerin kovaryant bir kuantum alan kuramı
bilinmemektedir, ve bu Bölge II için de geçerlidir.

**7. "İmza değiştiren arka planda kuantum alanı naif olarak sonsuz sayıda
parçacık üretir."** [19]. Bölüm 16.2'deki "parçacık değil korelasyon" okuması
bunu çözmez, sorunun sorulamaz hâle geldiği bir çerçeve önerir. Bu bir cevap
değildir ve öyle sunulmamaktadır.

**8. "Olasılık korunumu dayatıldığında fazladan zaman ekseni gözlenemez hâle
gelir, klasik durumda evrim etkin olarak tek zamanlıdır."** [21]. Bölüm 7.3'te
tartışılmıştır. Kısmi bir cevap vardır: [21] üniter ve olasılık koruyan bir evrim
varsayar, Bölüm 14 ise Bölge II'de bu yapının kurulamadığını gösterir. Ancak bu,
itirazı karşılamaktan çok konuyu Bölüm 14'e havale etmektedir.

**9. "Nedenselliği korumak için tercihli bir çerçeve zorunludur."** [39], ve
[26]'da somut bir kuruluş: uygun bir eşzamanlama seçimiyle takyonik alan tutarlı
biçimde kuantumlanır, mutlak nedensellik ve tam Lorentz simetrisi korunur, bedel
olarak görelilik ilkesi bırakılır. Bu, modele gerçek bir alternatiftir ve daha
olgundur. Aradaki fark ödenen bedeldir: [26] tercihli çerçeveyi kabul eder,
buradaki model reel kütleyi ve görelilik ilkesini korur, karşılığında geçirgen
olmayan bir eşik alır. Hangi bedelin daha kabul edilebilir olduğu burada
kararlaştırılmamıştır.

### 19.1 Çizgi elemanını koruyan permütasyonların sayımı

[3]'ün sayımı kendi araçlarımızla doğrulanmıştır: dört koordinatın 24
permütasyonundan **6**'sı Bölge I çizgi elemanını korur, **18**'i değiştirir, ve
koruyanlar tam olarak zaman slotunu yerinde bırakanlardır. Sayım doğrudur ve
kabul edilmektedir. $D$ bu on sekizin içindedir.

Ayrım şuradadır: $D$ tek bir metriği korumaz, iki metrik arasındaki
$D^T \eta' D = -\eta$ bağıntısını sağlar. İki taraf aritmetikte anlaşır,
hangi bağıntının fiziksel olduğunda ayrılır.

### 19.2 İkiye katlanmış uzayda komütatörün yok olması

[22]'nin önerdiği onarım sayısal olarak sınanmıştır. Takyonik eşik üzerindeki
modlar toplanarak tek bir sektörün komütatör fonksiyonu hesaplanır ve her
ayrımda sıfırdan farklı çıkar; yıldızlı sektör ters işaretle eklendiğinde toplam
**tam olarak** sıfırlanır. Her ayrımda komüte eden bir alan kanonik komütasyon
bağıntılarını taşımaz. Onarım, engelleri kuantum dinamiğini kaldırarak
kaldırmaktadır. Bölüm 14'ün üç engeli ayaktadır.

### 19.3 Vakum Cherenkov sınırı

Superluminal yayılımı sınırlayan çift ışıma mekanizması [38], $\delta = v^2/c^2 - 1$
parametresi pozitif olduğunda işler; superluminal bir parçacık
$\nu \to \nu + e^+ + e^-$ süreciyle enerji kaybeder ve bu kaybın gözlenmemesi
superluminaliteye sıkı bir üst sınır koyar. Bu modelde hiçbir uyarım $\delta > 0$ ile
yayılmaz; grup hızı her zaman $c$'nin altında ya da ona eşittir. Dolayısıyla
sınır bu modeli yalnızca boş biçimde kısıtlar. Bu bir üstünlük değil, öngörü
yoksunluğunun bir başka görünümüdür.

### 19.4 Fazladan zamanın tek zamana çökmesi

[21]'in itirazı serbest hareket için doğrudur ve doğrulanmıştır: iki zamanlı
serbest hareket, hız bileşenlerinin belirlediği **tek bir bileşime** bağlıdır,
ikinci zaman bağımsız bir dinamik içerik taşımaz. Bu, sınanan bütün hız ve zaman
değerlerinde tam olarak sağlanır.

İtirazın karşılamadığı nokta şudur: Bölüm 7'deki iddia tek bir yörünge hakkında
değil, Lagrangian'ın simetrisi hakkındadır. Üç zaman ekseninde $O(3)$ değişmezliği
ve ondan çıkan üç korunan yük, tek bir serbest yörüngenin tek bileşime bağlı
olmasıyla ortadan kalkmaz. Yine de itiraz kısmen isabetlidir ve tam olarak
karşılanmamıştır.

### 19.5 Duvarda hangi sınır koşulu seçilirse seçilsin

[8]'in Dirichlet koşulu ile burada kullanılan Neumann koşulu arasındaki tercih
sınanmıştır. Duvarda öz-eşlenikliği sağlayan koşullar tek parametreli bir Robin
ailesi oluşturur,

$$\cos(a)\,\psi + \sin(a)\,\psi' = 0$$

ve $a = 0$ Dirichlet, $a = \pi/2$ Neumann koşuludur. Bu ailenin **her** üyesi
için, sınanan bütün dalga sayılarında

$$|R| = 1$$

çıkar. Yani tam yansıma, hangi öz-eşlenik genişlemenin seçildiğine **duyarlı
değildir**. Seçimin değiştirdiği tek şey yansıyan dalganın fazıdır; gözlenebilir
bir fark aranacaksa orada aranmalıdır.

Bu, Bölüm 9.1'deki sonucun üçüncü bağımsız desteğidir: akı korunumu tam yansımayı
zorluyordu, Dirichlet ve Neumann aynı yere çıkıyordu, ve şimdi aradaki bütün
koşullar da aynı yere çıkmaktadır.

### 19.6 Kapatılamayan itiraz

**"Dejenere yüzeyden geçilemeyeceği gösterilmemiştir."** İtiraz haklıydı ve
Bölüm 13.5'te karşılanmıştır. Dejenerelik kaçınılmazdır, ancak rank-2 dejenerelik
değildir: $(2,2)$ üzerinden giden kademeli bir yolda her noktada yalnızca tek bir
öz-değer sıfırlanır, ki bu tam olarak [15], [16], [35], [37] ve [13]'ün
araçlarının çalıştığı sınıftır. Bölüm 13.3'ün karşıt sonucu geri çekilmiştir.
Geriye kalan soru geçişin mümkün olup olmadığı değil, $(2,2)$ ara bölgesinin
fiziksel olarak kabul edilip edilemeyeceğidir.

---

## 20. Yöntem

Bütün doğrulamalar önce sembolik cebirle yapıldı:

- matris özellikleri: metrik testi, involüsyon, determinant, grup mertebesi,
- 384 permütasyon taraması,
- dört-momentum dönüşümü ve genel $2 \to 2$ korunum,
- Euler-Lagrange türetmeleri,
- $O(3)$ stabilizatör hesabı,
- dispersiyon ve limit hesapları.

Elle yapılan iki hesap, parite argümanı ve boyut sayımı, sembolik kontrolde
**yanlış çıktı** ve düzeltildi. Modelin bugünkü hâli bu düzeltmeleri içerir.

Aynı doğrulamalar daha sonra C++ ile sayısal/cebirsel olarak yeniden kuruldu.
Modelin matrislerinin büyük kısmı tamsayı girdilidir ($0, +1, -1$) ve bu girdiler
ikilik tabanda tam temsil edildiğinden permütasyon, involüsyon ve determinant
testleri sembolik hesapla birebir aynı sonucu verir. Yalnızca boost ve dönme
matrislerinde irrasyonel girdiler oluşur; oralarda bir tolerans kullanılır.

---

## 21. Kapanan ve açık kalan noktalar

| Konu | Durum |
|------|-------|
| Üç zamanda zamanın oku | Kapandı (Bölüm 7 ve 7.4), ok zaman yönü sayısından çıkar, eşik değeri birdir |
| Dönüşümdeki $\pm$ işareti | Kapanamaz olduğu gösterildi (Bölüm 12) |
| Grup yapısı | Kapandı (Bölüm 3), sorun $B$ katmanında |
| Küresel simetrik çözüm | Kapandı (Bölüm 10), kapalı form ve yorumu |
| Superluminal durgunluk | Kapandı (Bölüm 8), ayar fazlalığı |
| Etkileşim / Maxwell | Kapandı (Bölüm 11) |
| Kuantumlama | Kapandı (Bölüm 14, 15, 16) |
| Takyonların varlığı | Açık, deneysel soru |

Modele özgü olduğu düşünülen sonuçlar: eşikte tam yansımanın akı korunumunun tek
çözümü olması (Bölüm 9.1), $D$'nin 384 aday arasından zorunlu çıkması (Bölüm 2.1),
Wick dönüşünde "tek olan ekseni döndür" kuralı ve iki bölgenin ortak bir Öklid
teorisinin analitik devamları olması (Bölüm 15), ve iki literatürün birleştirilmesi.

**Bölüm 13.5'te kapanan nokta.** İki imza arasındaki sürekli yolun ne kadar
dejenere olmak zorunda olduğu sorusu cevaplanmıştır: her noktada yalnızca tek bir
öz-değerin sıfırlandığı bir yol vardır, bedeli $(2,2)$ imzalı iki zamanlı bir ara
bölgeden geçmektir. Bölüm 13.3'ün "geçiş sağlanmaz" sonucu geri çekilmiştir.

**Bölüm 9.4'te daraltılan nokta.** Eşiğin yansıtıcı olması sınırsız bir öte taraf
varsayar. Sonlu kalınlıkta bir dilim, üstel olarak bastırılmış ama sıfır olmayan
bir geçirgenlik verir; ayrıca engelin varlığı gelen alanın mod içeriğine bağlıdır.

**Açık kalanlar.**

| Soru | Nerede |
|------|--------|
| Güçlü ile zayıf eklem koşulu arasındaki tercihin gerekçesi | Bölüm 9.1 |
| $(2,2)$ ara bölgesinin fiziksel olarak savunulabilirliği | Bölüm 13.5 |
| Üç zamanın olasılık korunumu altında tek zamana çökmesi | Bölüm 7.3 |
| İmza değiştiren arka planda parçacık üretimi | Bölüm 16.2 |
| Eşik duvarlarının kuantum kararlılığı | Bölüm 9.1 |
| Geçişin varsayılmak yerine türetilebilmesi | Bölüm 15.6 |
| Yerçekiminin eklem koşulunun ötesine götürülmesi | Bölüm 9.2 |
| Ayırt edici öngörünün hazırlanabilir bir düzenek gerektirmesi | Bölüm 16.4 |

Bu listenin uzunluğu bir kusur olarak değil, çalışmanın bulunduğu aşamanın
kaydı olarak verilmektedir.

---

## Kaynakça

1. A. Dragan, A. Ekert. *Quantum principle of relativity*. New J. Phys. **22** (2020) 033038. arXiv:1910.02780
2. A. Dragan, K. Dębski, S. Charzyński, K. Turzyński, A. Ekert. *Relativity of superluminal observers in 1+3 spacetime*. Class. Quantum Grav. **40** (2023) 025013. arXiv:2209.01836
3. M. J. Lake. *The (1+3)-dimensional 'quantum principle of relativity' is Einstein's principle of relativity*. Eur. Phys. J. C **85** (2025) 92. arXiv:2410.07017
4. M. Zaopo. *Group representations of Lorentz transformations extended to superluminal observers*. arXiv:2510.25385
5. S. A. Hayward. *Junction conditions for signature change*. Class. Quantum Grav. **9** (1992) 1851. arXiv:gr-qc/9303034
6. F. Embacher. *Actions for signature change*. Phys. Rev. D **51** (1995) 6764. arXiv:gr-qc/9501004
7. L. J. Alty, C. J. Fewster. *Initial value problems and signature change*. Class. Quantum Grav. **13** (1996) 1129. arXiv:gr-qc/9501026
8. I. L. Egusquiza. *Self-adjoint extensions and signature change*. Class. Quantum Grav. **12** (1995) L89. arXiv:gr-qc/9503015
9. T. Dray. *Einstein's equations in the presence of signature change*. J. Math. Phys. **37** (1996) 5627. arXiv:gr-qc/9610064
10. T. Dray, G. Ellis, C. Hellaby, C. Manogue. *Gravity and signature change*. Gen. Rel. Grav. **29** (1997) 591. arXiv:gr-qc/9610063
11. T. Dray, G. Ellis, C. Hellaby. *Note on signature change and Colombeau theory*. Gen. Rel. Grav. **33** (2001) 1041. arXiv:gr-qc/0012047
12. C. Hellaby, A. Sumeruk, G. F. R. Ellis. *Classical signature change in the black hole topology*. Int. J. Mod. Phys. D **6** (1997) 211. arXiv:gr-qc/9907042
13. S. Capozziello, S. De Bianchi, E. Battista. *Avoiding singularities in Lorentzian-Euclidean black holes: the role of atemporality*. arXiv:2404.17267
14. R. Bartolo, E. Caponio, A. V. Germinario, M. Sánchez. *Lorentzian-Euclidean black holes and Lorentzian to Riemannian metric transitions*. Phys. Rev. D **111** (2025) 104058. arXiv:2502.14108
15. W. Hasse, N. E. Rieger. *A transformation theorem for transverse signature-type changing semi-Riemannian manifolds*. Diff. Geom. Appl. **103** (2026) 102370. arXiv:2407.09699
16. N. E. Rieger, W. Hasse. *Pseudo-timelike loops in signature changing semi-Riemannian manifolds with a transverse radical*. Results in Physics **78** (2025) 108478. arXiv:2409.02403
17. J. Mielczarek. *Signature change in loop quantum cosmology*. arXiv:1207.4657
18. M. Bojowald, S. Brahma. *Loop quantum gravity, signature change, and the no-boundary proposal*. Phys. Rev. D **102** (2020) 106023. arXiv:2011.02884
19. A. White, S. Weinfurtner, M. Visser. *Signature change events: a challenge for quantum gravity?*. Class. Quantum Grav. **27** (2010) 045007. arXiv:0812.3744
20. I. Bars. *Two-time physics in field theory*. Phys. Rev. D **62** (2000) 046007. arXiv:hep-th/0003100
21. E. Piceno, A. Rosado, E. Sadurní. *Fundamental constraints on two-time physics*. Eur. Phys. J. Plus **131** (2016) 352. arXiv:1512.05345
22. J. Paczos, K. Dębski, S. Cedrowski, S. Charzyński, K. Turzyński, A. Dragan, A. Ekert. *Covariant quantum field theory of tachyons*. Phys. Rev. D **109** (2024). arXiv:2308.00450
23. K. Jodłowski. *Covariant quantum field theory of tachyons is unphysical*. Phys. Rev. D **110** (2024) 115042. arXiv:2406.14225
24. K. Jodłowski. *Is a covariant virtual tachyon viable?*. Phys. Rev. D **113** (2026) 065016. arXiv:2602.20474
25. M. Ostrowski. *Casimir effect for tachyonic fields*. Found. Phys. Lett. **18** (2005) 227. arXiv:hep-th/0307051
26. J. Rembieliński. *Quantization of the tachyonic field and the preferred frame*. arXiv:hep-ph/9509219
27. L. Nanni. *Electromagnetic field theory in superluminal spacetime*. Indian J. Phys. (2023). arXiv:2305.12505
28. R. Horodecki. *Comment on 'Quantum principle of relativity'*. New J. Phys. **25** (2023) 128001. arXiv:2301.07802
29. F. Del Santo, S. Horvat. *Comment on 'Quantum principle of relativity'*. arXiv:2203.03661
30. A. Grudka, J. Stempin, J. Wójcik, A. Wójcik. *Superluminal observers do not explain quantum superpositions*. Phys. Lett. A **487** (2023) 129127. arXiv:2306.03961
31. A. Sen, F. Del Santo. *Superluminal transformations and indeterminism*. arXiv:2601.15263
32. A. Sen, M. Salzger, Ł. Rudnicki. *Superluminal quantum reference frames*. arXiv:2506.11787
33. M. Sienicki, K. Sienicki. *From kinematics to interference: operational requirements for the quantum principle of relativity*. arXiv:2512.05164
34. M. Pettini. *Quantum entanglement without nonlocal causation in (3,2)-dimensional spacetime*. Phys. Rev. Research **7** (2025) 013261. arXiv:2311.17070
35. S. Bondarenko, V. De La Hoz-Coronell. *Time kink: modeling change of metric signature*. arXiv:2204.07828
36. R. Singh, S. Bondarenko. *Inflation from covariant signature change: a geometric mechanism*. Phys. Rev. D **114** (2026) 024076. arXiv:2607.01274
37. R. Mansouri, K. Nozari. *Signature change, inflation, and the cosmological constant*. arXiv:gr-qc/9806109
38. F. L. Villante, F. Vissani. *On the generality of the Cohen and Glashow constraints on the neutrino velocity*. arXiv:1110.4591
39. V. F. Perepelitsa. *Looking for a theory of faster-than-light particles*. arXiv:1407.3245
40. B. Alexandre, S. Gielen, J. Magueijo. *Overall signature of the metric and the cosmological constant*. arXiv:2306.11502
41. F. Figueiredo, F. Moraes, S. Fumeron, B. Berche. *Modeling Kleinian cosmology with electronic metamaterials*. Phys. Rev. D **94** (2016) 044039. arXiv:1608.03812
