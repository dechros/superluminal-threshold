# Superluminal geçişte imza değişimi: ayrık involüsyon modeli

> Not: Bu metin yalnızca bu çalışmanın kendi sonuçlarını içerir. Atıflar ve
> kaynakça sonradan eklenecektir.

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
olduğunun gösterilmesi, ve eşik yüzeyinin geçirgen değil yansıtıcı olması.

Çalışma kendi sınırını da içerir: Sylvester atalet yasası, reel bir dönüşümün bir
metriğin imzasını doğrudan çevirmesini yasaklar. Dolayısıyla $D$, tek bir metriğin
imzasını çeviren bir operatör değil, iki farklı metrik arasında bir eşlemedir. Bu
sınır Bölüm 17'de açıkça ele alınıyor.

## Modelin yedi maddesi

1. $c$ aşılırsa uzay ve zaman rol değiştirir; bu değişim anidir ve hızdan bağımsızdır.
2. Bunu yapan tek dönüşüm $D$'dir; involüsyondur, pariteyi korur, ışık hızını korur.
3. Ötede hız bir skaler değil, bir yönelimdir.
4. Enerji ve momentum takas olur.
5. Hız dönüşümü $v' = c^2/v$.
6. Ötede öngörü çöker, denklem tipinin doğrudan sonucu olarak.
7. Eşik geçirgen değil, yansıtıcıdır.

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

Yapı, $\langle D \rangle \ltimes SO(1,3)$ biçiminde bir yarı-doğrudan çarpımdır.
Kapanmanın bozulması, $D B D^{-1}$ konjugasyonunun boost tipini korumamasından
çıkar; yön-bağımlı genleşmeler bu konjugasyonun ürünüdür.

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
habercisidir.

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

**Değerlendirme.** Model elektromanyetizmayı bozmadan taşır. Bu, modelin en güçlü
doğrulamasıdır.

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

### 13.4 Sonuç

Kara delik ufku bu modelin "kısmi" hâli değildir; farklı sınıfta bir olaydır. Ufuk
imza sınıfını korur, bu yüzden geçirgendir. $\Sigma$ imza sınıfını değiştirir, bu
yüzden yansıtıcıdır. Aralarında sürekli köprü kurmak dejenere bir nokta gerektirir
ve orada da geçiş sağlanmaz; tıkanma yalnızca yer değiştirir.

Bu, Bölüm 9'daki yansıtıcılık sonucunun bağımsız bir doğrulamasıdır.

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

İki bölge ayrı yapılar değil, tek bir yapının iki dalıdır.

### 15.5 Kalan açık

Vakum problemi (Bölüm 14.3) Öklid bölgesinde çözülür, pozitif tanımlı çekirdek iyi
tanımlı bir ölçüm verir. Ancak Lorentz bölgesine analitik devam yapıldığında
Hamiltonyenin vektör olması sorunu geri gelir. Yani Bölge II'de **hesap
yapılabilir, ama sonuçların parçacık yorumu tanımsızdır.** Korelasyon fonksiyonları
hesaplanabilir; "kaç parçacık var" sorusu cevaplanamaz.

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

**Değerlendirme.** $\Sigma$, $v = c$ yüzeyidir ve laboratuvarda erişilebilir
değildir. Dolayısıyla bu, prensipte var olan ama pratikte ölçülemeyen bir imzadır.

---

## 17. Sylvester engeli ve modelin duruşu

Bu bölüm modelin kendi sınırını belirler.

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

## 19. Yöntem

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

## 20. Kapanan ve açık kalan noktalar

| Konu | Durum |
|------|-------|
| Üç zamanda zamanın oku | Kapandı (Bölüm 7), ok boyut sayısından çıkar |
| Dönüşümdeki $\pm$ işareti | Kapanamaz olduğu gösterildi (Bölüm 12) |
| Grup yapısı | Kapandı (Bölüm 3), sorun $B$ katmanında |
| Küresel simetrik çözüm | Kapandı (Bölüm 10), kapalı form ve yorumu |
| Superluminal durgunluk | Kapandı (Bölüm 8), ayar fazlalığı |
| Etkileşim / Maxwell | Kapandı (Bölüm 11) |
| Kuantumlama | Kapandı (Bölüm 14, 15, 16) |
| Takyonların varlığı | Açık, deneysel soru |

Modele özgü sonuçlar: çarpanlama (Bölüm 1), eşiğin yansıtıcı olması (Bölüm 9),
Maxwell'in bağımsız yeniden üretimi (Bölüm 11), Wick dönüşünün "tek olan ekseni
döndür" kuralı ve iki bölgenin ortak bir Öklid teorisinin analitik devamları olması
(Bölüm 15), kara delik ufkuyla imza-sınıfı karşılaştırması (Bölüm 13), ve küresel
simetrik çözümün kapalı formu (Bölüm 10).
