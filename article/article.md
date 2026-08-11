# Eşik hızının sürekli geçişi ve saatteki fark

## Özet

Bu çalışma, kütleli bir parçacığın ışık hızı eşiğini geçip geri dönmesini
tek bir süreç olarak kurar: parçacık ışığın altında başlar, eşiği sürekli
bir kuvvetle geçer, ikinci bölgede bir mesafe alır, aynı kuvvetle geri
döner, ve birinci bölgenin saatinde bıraktığı farkı taşır. Parçacık eşiği
yeni bir serbestlik derecesiyle, eşik açısıyla, aşar; bu açıyı sabit kütle
değil sabit bir kuvvet sürer, ve enerji hiçbir noktada sonsuza gitmez.
İkinci bölgede alınan bir metrelik yol, dönüşü kalkıştan
$3{,}34\times 10^{-9}$ saniye öne çekmektedir.

## 1. Giriş

Literatür, kütleli bir parçacığın ışık hızı eşiğini aşıp aşamayacağı
sorusunu uzun süredir tartışmaktadır, çünkü böyle bir aşma geçmişe ulaşmayı
mümkün kılar [1], [2], [3]. Bu çalışma soruyu bir süreç olarak ele alır ve
altı adımda kurar:

1. Parçacık ışık hızının altında, sıradan bir cisim olarak hareket eder.
2. Parçacık, ışık hızı eşiğini yeni bir serbestlik derecesiyle, sürekli bir
   kuvvetle geçer.
3. Geçiş tamamlandığında parçacık ikinci bölgede, ışık hızının üstünde
   bulunur.
4. Parçacık ikinci bölgede tek bir eksen boyunca, yine bir kuvvetle, bir
   mesafe alır.
5. Aynı türden bir kuvvet, bu kez tersine, parçacığı ışığın altına
   döndürür.
6. Bu çalışma, alınan mesafenin birinci bölgenin saatinde bıraktığı farkı
   hesaplamıştır.

Önceki bir çalışma, üçüncü, dördüncü ve altıncı adımların matematiğini
kurmuştur: eşiği geçiren $384$ işaretli permütasyon matrisinin taraması,
ikinci bölgedeki sabit kuvvetle sürülen hareket, ve alınan mesafeyi saat
farkına çeviren katsayının bire eşit çıkması bu adımları taşımaktadır. Bu
çalışmanın eklediği adımlar ikincisi ve beşincisidir: parçacığın eşiği,
süreç içinde ve tekillik taşımadan, nasıl geçtiği.

## 2. Birinci bölgede sıradan hareket

Süreç, birinci bölgedeki sıradan hareketle başlar. Bu çalışma, birinci
bölgenin koordinatlarını $(ct, x, y, z)$, metriğini
$\eta = \mathrm{diag}(+1,-1,-1,-1)$ ile yazar. Kütleli bir parçacığın
dispersiyon bağıntısı

$$\omega(k) = c\sqrt{k^2 + \mu}, \qquad \mu = \left(\frac{mc}{\hbar}\right)^2$$

biçimindedir; $\omega$ frekansı, $k$ dalga sayısını, $\mu$ kütle
parametresini taşır. Grup hızı $v_{\text{grup}} = d\omega/dk$, $k\to\infty$
limitinde $c$'ye yaklaşır ve hiçbir sonlu $k$'de onu aşmaz. Aşağıdaki
bölümler, bu sınırı aşan süreci kurar.

## 3. Işık hızı eşiği

### 3.1 Ara bölgenin dört adayı

Bu çalışma eşiğin kendisini kalınlıksız bir yüzey değil, kendi imzası olan
bir bölge olarak ele alır. Bu çalışma dört adayı tarar: hiç ara bölge olmaması, enine
yönlerin teker teker çevrildiği kademeli bir yol, dördünün birden çevrildiği
Öklidyen bir katman, ve metriğin tersinin bulunmadığı dejenere bir tabaka.
Kademeli yolun durağı, yalnızca bir enine yönün çevrildiği ara katmandır; bu
katmanda metriğin rankı bir defada değil, teker teker düşmüştür.

### 3.2 Eşik açısı ve tekillik

Birinci bölgenin metriği ile eşiğin ötesindeki metrik, tek bir açıyla,
$\theta$, birbirine bağlanır:

$$g_\mu(\theta) = \eta_\mu \cos(2\theta), \qquad \mu = 0,1,2,3$$

$\theta = 0$'da $g = \eta$, yani birinci bölgenin metriği çıkar. $\theta =
\pi/2$'de $g = -\eta$ çıkar: aynı işaret sayısını taşıyan, yalnızca
eksenlerin yeniden etiketlendiği bir metrik. $\theta = \pi/4$'te ise $g$'nin
dört bileşeni de birden sıfırlanır; metrik burada dejeneredir.

Bu nokta ile 3.1'in dejenere tabakası aynı adı taşır, ama aynı nesne
değildir. Tabaka mekânda bir kalınlık taşır ve dalga onun içinden geçer; bu
noktanın ise mekânda hiçbir kalınlığı yoktur, yalnızca açının aldığı tek bir
değerdir. Bu çalışma ikisini birbirinden türetmez, yalnızca ikisinin de
dejenere olduğunu kaydetmiştir.

Bu çalışma, sabit kütleli bir parçacık için gerekli momentümün karesini
$\cos(2\theta)(E^2/c^2 - \mu)$ olarak yazar. $E^2/c^2 - \mu \geq 0$ iken bu
ifade $\theta < \pi/4$ için sıfırdan büyük, $\theta > \pi/4$ için negatif
çıkar. Sınanan sekiz açı değerinin dördü bunu sıfırdan büyük, kalan dördü
negatif vermiştir. Kütlesi sabit tutulan bir parçacığın eşik açısı, dejenere
noktanın ötesinde hiçbir gerçek momentüm taşımaz. Metrik ailesinin kendisi bu
yüzden parçacığı eşikten geçirmez; geçiren şey ayrı bir mekanizmadır.

### 3.3 Sabit kuvvetle geçiş

Çok zamanlı fizikte bir parçacığa kuvvet ekleyen olgun bir program
$Sp(2,\mathbb{R})$ ayar simetrisidir [5]. Bu program kısıta eklenen terimi
belirli bir dereceye sıkıştırır ve keyfi bir potansiyele izin vermez. Bunun
yerine bu çalışma, kısıtlı Hamiltonyen mekaniğinin standart yolunu, ayar
simetrisi yerine varsayar: eşik açısının kendi kütle kabuğuna doğrudan bir
potansiyel eklemiştir.

$$\mu_\theta + 2F\theta - \frac{p_\theta^2}{c^2} = 0$$

$p_\theta$, $\theta$'ya eşlenik momentümü taşır; $F$ sabit bir kuvvettir.
Bu çalışma Hamilton denklemlerini kapalı formda çözer. Giriş momentümü
için $\theta=0$'daki negatif kökü alır, çünkü bu kök $\theta$'yı artan
yöne taşır. $F>0$ iken $p_\theta$ sabit hızla azalır, dolayısıyla
$\theta$'nın artış hızı hiç durmadan büyür ve hiçbir dönüş noktası yoktur.
Dejenere nokta $\theta=\pi/4$ bu denklemde özel bir ağırlık taşımaz, çünkü
sürücü terim $\theta$ ile çarpımsal değil doğrusaldır.

Herhangi bir hedef açı için, oraya ulaşılan yörünge parametresi kapalı
formda çıkar ve her zaman gerçel, sonlu ve pozitiftir. Sınama üç kütle
değerini, üç kuvvet değerini ve üç hedef açıyı, yani yirmi yedi birleşimi
kapsamaktadır, ve hiçbir birleşim hedefine ulaşmadan kalmaz. Aynı yörünge
$\pi/2$'den geriye doğru okunduğunda, yani $\pi/2$ ile açının farkı
alındığında, sıfıra düşen ikinci bir yörünge verir; ikinci yörünge
birincisiyle aynı yörünge parametresinde sıfıra ulaşmıştır.

**Kuvvetin kaynağı.** Bu çalışma $F$'yi türetmez, önesürür. İki zamanlı
fizik yazınının etkileşimli alan kuramları, aynı kısıta tam bu türden
doğrusal bir terim ekleyerek arka plan alanlarını tanımlamaktadır [6]. Bu
çalışma, kuvvetin bu tür bir arka plan alanından geldiğini varsayar; hangi
alan olduğu, alanın kendi denklemi ve kaynağı ayrı birer sorudur ve bu
çalışmanın kapsamı dışında kalır.

## 4. İkinci bölgeye geçiş

Eşik açısı $\pi/2$'ye ulaştığında parçacık ikinci bölgededir. İkinci
bölgenin koordinatları $(t_1, t_2, t_3, r)$, metriği
$\eta' = \mathrm{diag}(+1,+1,+1,-1)$'dir; $t_1$, $t_2$, $t_3$ zaman
eksenini, $r$ ise tek uzay eksenini taşımaktadır.

Bu çalışma, iki bölgeyi birbirine bağlayan ayrık dönüşümü, işaretli
permütasyon matrislerinin tamamını tarayarak bulmuştur; bu dönüşüm klasik
takyon kuramının superboost kavramıyla aynı ailededir [4]. Aday sayısı
$4!$ permütasyon ile $2^4$ işaret bileşiminin çarpımından çıkar, yani bu
çalışma $384$ matrisi denemiştir.

| Filtre | Kalan aday |
| ---------------------------------- | ---------- |
| Metrik bağıntısı $M^T\eta'M=-\eta$ | 96 |
| ve involüsyon ($M^2=I$) | 12 |
| ve $\det=+1$ | 8 |

Kalan sekiz matrisin tamamı birinci bölgenin zamanını ikinci bölgenin tek
uzay eksenine göndermektedir. Bu çalışma sekizini, ikinci bölgeye atılan bir
birim adımı birinci bölgenin saatinde hangi yöne taşıdıklarına göre dörde
dört ayırır: dördü daha geç bir ana, dördü daha erken bir ana gönderir. Bu
çalışmanın sonucunu taşıyan hesaplar, geriye taşıyan dörtlüden $SD$
matrisi üzerinde tanımlıdır; bu seçim üç filtreden çıkmaz, bu çalışma onu
ayrıca kararlaştırmıştır.

## 5. İkinci bölgede mekânda ilerleyiş

Bölge II'ye giren parçacık, orada tek gerçek mekân ekseni boyunca
ilerlemelidir.

### 5.1 Hız sınırı

İkinci bölgenin dispersiyon bağıntısı $q(\kappa)=c\sqrt{\kappa^2+\mu}$
biçimindedir; $q$ değeri $r$'ye eşlenik momentümü, $\kappa$ değeri ise
$t_1,t_2,t_3$'e eşlenik momentümlerin büyüklüğünü taşır. Buradan çıkan hız

$$\left|\frac{dq}{d\kappa}\right| = \frac{c\kappa}{\sqrt{\kappa^2+\mu}}$$

sınanan bütün $\kappa$ değerlerinde $c$'nin altında kalır ve
$\kappa\to\infty$'da $c$'ye yaklaşmaktadır. İkinci bölgenin de bir hız
sınırı vardır, ve o sınır birinci bölgeninkiyle aynı sayıdır.

### 5.2 Sabit kuvvetle sürülen $r$ hareketi

Bu çalışma serbest kısıtı $k_1^2+k_2^2+k_3^2-q^2/c^2+\mu=0$, $r$ ekseni
boyunca bir kuvvet ekleyerek genişletir:

$$k_1^2+k_2^2+k_3^2-\frac{q^2}{c^2}+\mu+2Fr=0$$

Giriş momentümü, serbest kısıtın $r=0$'daki negatif köküdür; bu kök $r$'yi
artan yöne taşır. $F>0$ iken $r$ hiçbir dönüş noktası olmadan artmaktadır.
Herhangi bir hedef mesafe $s$ için oraya ulaşan yörünge parametresi kapalı
formda çıkar ve her zaman gerçel, sonlu ve pozitiftir; sınama yirmi yedi
birleşimi kapsar ve hiçbiri hedefine ulaşmadan kalmaz.

## 6. Eşikten geri dönüş

Parçacık hedef mesafeye ulaştıktan sonra dönüş başlar. 3.3'ün kurduğu
türden bir kuvvet, bu kez tersine, açının değerini $\pi/2$'den sıfıra
indirir. Bu, ileri yöndeki kuvvetin kendiliğinden sönmesi değildir, çünkü
sabit kuvvet açının artış hızını sürekli büyütür, hiç yavaşlatmaz. İki
bacağı da sabit kuvvetle kurmak, 3.3'ün kapalı formunu yeniden kullanmak
için yapılan bir seçimdir. İşareti değişen tek bir kuvvet, bütün gidiş
dönüşü tek bir uygulamada da kurabilir; ama bu çalışma o genellemeyi
yapmaz.

İki bölgeyi bağlayan matris bir involüsyondur: $D^2=I$'dir, $S$'nin
kendisi de $S^2=I$ sağlar, dolayısıyla iki kez uygulanan geçiş
dört-momentümün dört bileşenini de başlangıç değerine döndürmektedir. Bu
involüsyon özelliği, parçacık geri döndüğünde enerjisini, momentümünün
büyüklüğünü ve kütlesini tam olarak korur. Korunmayan tek şey yöndür,
çünkü ikinci bölgedeki üç zaman ekseni arasında bir $O(3)$ dönmesi
birinci bölgede bir sapma olarak görünebilir.

## 7. Zamanda gidilen mesafe

Bu geri dönüşün asıl sonucu, saatte bıraktığı farktır. İkinci bölgenin tek
uzay ekseninde alınan $s$ kadar yol, birinci bölgenin saatinde tam olarak
$s$ kadar fark üretir. Katsayı sekiz geçişin tamamında bire eşit
çıkmıştır ve diğer üç eksenin aynı yuvaya katkısı sıfırdır. İşaret,
seçilen $SD$ matrisinin geriye taşıyan ailesinden gelir. Dönüş anı şu
değeri alır:

$$t_{\text{dönüş}} = 2\tau - s$$

$\tau$ değeri tek bir geçişin bedelini, $s$ değeri ise ikinci bölgede
alınan mesafeyi taşır.

Bir metrelik bir hedef, dönüşü $3{,}34\times 10^{-9}$ saniye öne çeken bir
farka karşılık gelmektedir; bu fark kütleden ve enerji vektöründen
bağımsızdır, çünkü katsayı geometriden çıkar. Bir yıllık bir öne çekme ise
bir ışık yılı, yani $9{,}46\times 10^{15}$ metrelik bir yol gerektirmiştir.

## 8. Yöntem ve deney

Bu sonucun nasıl sınandığı ayrı bir sorudur. Bu bölüm hangi varsayımların
çalışmaya girdiğini değil, bu çalışmanın doğrulamayı nasıl kurduğunu
anlatır. Bu çalışmadaki her sayısal ve cebirsel iddia, C++ ile kurulmuş
bir doğrulamaya karşılık gelir; doğrulamalar genel amaçlı kütüphaneler
hâlinde durur ve üzerlerinde bir test takımı çalışır. Makale hiçbir dosya
ya da sınıf adı anmaz, kod da hiçbir bölüm ya da kaynak numarası anmaz;
bağı ise çalışma zamanında, makale metnini okuyan ayrı bir denetim
kurmaktadır.

Doğrudan bir sınama tek bir orantıya dayanır: Bölge II'de alınan $s$ kadar
mesafe, dönüşü tam olarak $s$ kadar öne çekmektedir (Bölüm 7), ve bu oran
$s$'nin büyüklüğünden bağımsız sabit kalır. $s$ büyüdükçe zaman farkı da
istenildiği kadar büyür; ölçüm büyüklüğü bir engel taşımaz.

İkincil bir iz de vardır: parçacık ikinci bölgede bir $O(3)$ dönmesi
geçirip geri dönerse, birinci bölgede aynı enerjiyle, aynı süratle, ama
farklı bir yöne bakarak görünür (Bölüm 6). Bu iz kavramsal düzeyde kalır;
bu çalışma sapmanın büyüklüğünü veren bir hesap kurmamıştır.

**Hüküm sözlüğü.**

| Hüküm | Anlamı |
| ---------------------------- | ----------------------------------------- |
| ilan edilmiş sınırlama | Korunmuştur ve sonucu çalışmada yazılıdır |
| varsayım değil, söz ediliyor | Varsayım yapmak yerine varsayımlardan söz eden pasaj |

**Sicil.**

| Bölüm | Ne varsayılıyor | Hüküm | Nerede kapandı |
| ----- | ---------------------------------------------------------- | ---------------------------- | -------------------------------------------------- |
| 3.3 | Kısıtlı Hamiltonyen mekaniğinin ayar simetrisi yerine standart yolu, ve $F$'nin bir arka plan alanından geldiği | ilan edilmiş sınırlama | Bölüm 3.3'ün kendisi, sonucu metinde yazılıdır |
| 8 | Yok; pasaj hangi varsayımların değil, doğrulamanın nasıl kurulduğunun anlatılması | varsayım değil, söz ediliyor | Doğrulamanın kendisi, bu bölüm onu belgeler |

## Kaynakça

1. O. M. P. Bilaniuk, V. K. Deshpande, E. C. G. Sudarshan. *"Meta" relativity*.
   Am. J. Phys. **30** (1962) 718.
2. G. Feinberg. *Possibility of faster-than-light particles*. Phys. Rev.
   **159** (1967) 1089.
3. G. A. Benford, D. L. Book, W. A. Newcomb. *The tachyonic antitelephone*.
   Phys. Rev. D **2** (1970) 263.
4. E. Recami, R. Mignani. *Classical theory of tachyons*. Riv. Nuovo Cim. **4**
   (1974) 209.
5. I. Bars. *Two-time physics with gravitational and gauge field backgrounds*.
   Phys. Rev. D **62** (2000) 105018. arXiv:hep-th/0002140
6. I. Bars, Y.-C. Kuo. *Interacting two-time physics field theory with a BRST
   gauge invariant action*. arXiv:hep-th/0605267
