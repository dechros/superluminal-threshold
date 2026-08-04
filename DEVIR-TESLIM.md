# Devir teslim notu

Başka bir oturum ya da başka bir bilgisayar burayı devraldığında **önce bunu
okusun**. Tarih: 2026-08-04, ikinci güncelleme.

---

## 1. Bu proje ne yapıyor

Tek bir soru: **kütleli bir parçacığı öte taraftan dolandırıp zamanda geriye
göndermek.**

Parçacık ışık hızı eşiğinin ötesine geçer, orada tek uzay ekseninde mesafe kat
eder, geri döner. Öte tarafta kat edilen mesafe, bu tarafta **saatte yer
değiştirmedir**, ve katsayı birdir, bir hıza bölünmez. Yeterince uzağa
gidildiğinde dönüş, girişten öncedir.

`article/article.md` (Türkçe) iddiayı taşır, `src/` altındaki C++26 kütüphanesi
her iddiayı hesaplar. İkisi **birbirini aynalamak zorundadır**.

---

## 2. En önemli uyarı: konu dağıldı, toparlanacak

**Kullanıcının son talimatı budur ve bir sonraki oturumun ilk işidir.**

Makale $5119$ satıra ulaştı ve büyük kısmı çekirdeğe hizmet etmiyor. Sicil
tutma, hakem cevapları, itiraz kayıtları, yöntem beyanları çekirdeği bastırdı.
Kullanıcının kendi ifadesiyle: *makalenin çekirdeği geçmişe geleceğe gitmek, ve
makale şişirildi.*

Yapılacak sadeleştirmenin ölçütü şudur ve başka hiçbir ölçüt kullanılmamalıdır:

> Bir bölüm, bir parçacığın geçip, gidip, dönüp **farklı bir anda** bulunmasına
> doğrudan hizmet ediyor mu?

Etmiyorsa çıkar. "Doğru ama" savunması geçerli değildir; daha önce iki kez bu
savunmayla bölümler tutuldu ve makale şişti.

Aynısı kod için de geçerlidir. `src/` altında $90$'a yakın başlık var; hepsi
çalışıyor ve hepsi geçiyor, ama hepsi gidiş dönüşe hizmet etmiyor.

**Daha önce iki tur ayıklama denendi ve beş madde ölçüldüğünde yanlış çıktı.
Ayrı kayıt dosyaları kaldırıldı; kalıcı olan tek şey aşağıdaki liste, ve yeni
bir tur bunu okumadan başlamamalıdır.**

| Yanlış çıkan öneri | Ölçüm ne dedi |
|---|---|
| Bölüm 21–27 "aynı üç şeyi dört kez sayan meta" | Meta değil, sonuç taşıyor: 22 beş okumayı, 23 tablonun yeniden sayımını, 27 ödünç ile özgünün kaydını |
| Sözlük üç kez kuruluyor | Bir kez kurulu; 18.1 zaten "burada tekrarlanmaz" deyip 9.1'e atıf yapıyor. 17.9–17.12 tekrar değil, **bağımsız doğrulama** |
| Bölüm 16 atılabilir | 19.9'da öte tarafın üç gözlenebilirinden biri olarak kullanılıyor |
| Bölüm 2.2 iki satıra inebilir | Ölçüldüğünde $29$ satır. Kesmeye değmez |
| Bölüm 4.1 "aynı itirafın üçüncü türetimi" | Eklem koşulu seçimini işliyor, başka konu |

Dersi tek cümlede: **"şişmiş" izlenimi ölçülmeden kesilmez.** Beş maddenin
beşi de okununca ya sonuç çıktı ya da tahmin edilenden kısa çıktı.

---

## 3. Gidiş dönüş simülasyonu: bitti

`src/sim/PacketSimulation` yazıldı ve **tek geçiş** için çalışıyor. Sonucu
sağlam: dalga paketi sayısal olarak yürütüldüğünde gecikme $1{,}4635$ ölçülüyor,
kapalı biçim $1{,}4629$ diyor, kalınlık $4$'ten $16$'ya çıkarken değişmiyor.
Yani doyum, kendisine hiç söylenmemiş bir yol tarafından gözleniyor.

Ayrıca faz yolunun görmediği bir şey buldu: saydamsız rejimde geçirgenliğin
**modülü** frekansla dik yükseliyor, bölge paketi hızlı yanına doğru **yeniden
ağırlıklandırıyor**, ve bu kayma kalınlıkla büyüyor ($-0{,}0902$, $-0{,}1726$,
$-0{,}3369$). Gecikme değil, ama gerçek.

**Gidiş dönüş de artık koşuyor, ve sonucu şudur:**

| Öte tarafta kat edilen | Paketin tepe yaptığı an |
|------------------------|--------------------------|
| $1{,}0000$ | $+0{,}4635$ |
| $2{,}9257$ | $-1{,}4622$ |
| $6{,}0000$ | $-4{,}5365$ |

Eşik, bir formül okunarak değil, dönüş anı sıfırı geçene kadar mesafe
ikiye bölünerek bulunmuştur: $1{,}4635$, kapalı biçimin dediği $1{,}4629$'a
karşı.

Yani **evet, simülasyon parçacığı geçmişe götürdü.** Mesafe altı iken paket,
kalkışından $4{,}5365$ **önce** tepe yapmaktadır. Öteki aile seçildiğinde aynı
yolculuk daha geç inmektedir, yani dal bağımlılığı da yeniden üretilmiştir. Bu,
bir formül değerlendirilerek değil, bir paket zamanda ileri yürütülerek
bulunmuştur.

**Dikkat, buradaki tek tuzak:** `TwoCrossings::amplitude` zaten **iki** geçişi
tarif eder, dolayısıyla taşıdığı gecikme gidiş dönüşünkidir. İlk yazımda onu bir
de ikiyle çarptım ve eşik kontrolü düştü. Bu, bu çalışmanın **üçüncü** kez aynı
ikilik çarpan hatasını yapması olurdu; kontrol şimdi bunu yakalayacak biçimde
yazılıdır.

**Hız sorunu kapandı, ve maliyet tahmin edilen yerde değildi.** Ölçüldü:
simülasyon kapalıyken koşu $1{,}6$ saniye, açıkken $117$. Yani bütün maliyet bu
bölümdeydi. Sebebi bisection değildi; toplamın **frekans tarafının her zaman
adımında baştan kurulmasıydı**, oysa zamana bağlı olan tek çarpan
$\exp(-i\omega t)$. Frekans tarafı bir kez kurulup faza çarpılınca koşu $41$
saniyeye indi ve **hiçbir sayı oynamadı**.

**Katı kayma özdeşliği uygulandı ve bir kontrol olarak yazıldı:**

Toplamdaki iki faz çarpanı birleşir:

```
exp(i·sign·ω·s) · exp(-i·ω·t)  =  exp(-i·ω·(t - sign·s))
```

Yani öte taraftaki yer değiştirme, zaman ekseninin **katı bir kaymasıdır**.
Tepe konumu `t_tepe(s) = t_tepe(0) + sign·s` olur, **tam olarak**. Dolayısıyla
gidiş dönüş için tepeyi her mesafede yeniden aramaya gerek yoktur: bir kez
$s=0$'da bulunur, sonra kaydırılır. Bisection da gereksizdir, eşik doğrudan
$t_{tepe}(0)$ olarak çıkar.

Zarf, kaydırılmış zamanda ve yer değiştirmesiz kaydırılmış argümanda
karşılaştırılmakta ve üç mesafede, iki dalda birden, $10^{-12}$ mertebesinde
eşit çıkmaktadır. Hızlı yol ayrıca eski aramayla iki mesafede
karşılaştırılmıştır; aradaki $8 	imes 10^{-6}$, yavaş aramanın **ızgara
adımıdır**, kaymanın kusuru değildir, ve kontrol bunu böyle yazıp gevşek
toleransı sessizce değil gerekçesiyle taşımaktadır.

Eşik artık bisection ile değil, **durgun tepeden** okunuyor: moment tam olarak
işaretli yer değiştirmenin o tepeyi götürdüğü yerde sıfırlanır. Hâlâ bir
formülden değil yürütülmüş bir paketten geliyor: $1{,}4635$, kapalı biçimin
dediği $1{,}4629$'a karşı.

**Şu anki durum:** **$1580$ kontrolün tamamı geçiyor**, koşu $41$ saniye.

---

## 4. Bu repoda çalışmanın kuralları

Bunlar tercih değil, kullanıcının koyduğu kurallardır.

- `article/article.md` **yalnızca Türkçe**. Hiçbir yerde **uzun tire yok**;
  denetlenir, `grep -c "—" article/article.md` sıfır vermelidir.
- Hiçbir yerde araç atfı yok. Commit mesajlarında da yok.
- C++ içinde **hiçbir makale ya da kaynak atfı yok**, yorumlarda da konsol
  çıktısında da.
- `.cpp` dosyalarında **yorum yok**. Başlıklardaki doküman yorumları kalır ve
  ayrıntılıdır.
- Her doğrulama `src/` ve `main.cpp` içinde olur. **Python ile doğrulama
  yapılmaz**; geçici teşhis için kullanılabilir, repoya girmez.
- Derleme daima `make` ile. Commit sonrası daima `push`.
- Sohbette LaTeX yok, günlük Türkçe konuşulur. Makalede ve kodda bilimsel dil.

---

## 5. Kodun yapısı

`main.cpp` bütün bölümleri sırayla koşar. Her bölüm `Section` arayüzünü uygular:
`title()` ve `run(Report&)`. `Report::check(metin, koşul)` bir kontrol yazar.

**Çekirdeğe en yakın dosyalar**, bir sadeleştirmede korunacaklar:

| Dosya | Ne yapar |
|---|---|
| `transform/InvolutionD` | Geçişi yapan matris |
| `scan/PermutationScan` | $384$ adayı $8$'e indiren tarama |
| `scan/CrossingBranches` | Sekizin dörde dört ayrılması, ve seçimin geometrik olmaması |
| `intermediate/TwoCrossings` | İki geçişin genliği ve fazı, gecikmenin kaynağı |
| `intermediate/ThresholdOptimum` | Gereken mesafenin küçültülmesi |
| `particle/ReturnFormula` | Dönüş olayının kapalı biçimi |
| `particle/ReturnEvent` | Dönüş olayının dört koordinatı |
| `particle/WorkedRoundTrip` | Tek bir parçacığın uçtan uca yolculuğu |
| `particle/Feasibility` | Deneyle arada duran engeller, türlerine göre |
| `sim/PacketSimulation` | Sayısal deney, formülden bağımsız |

---

## 6. Bilinmesi gereken sonuçlar

**İşaret bir seçimdir.** Sekiz aday cebirsel olarak ayırt edilemez, dördü
ileriye dördü geriye gönderir, ve iki aileyi ayıran dönüşüm her iki metriğin de
izometrisidir. Kullanılan matris **ileri gönderen** ailededir. Bu, bir hakemin
sorduğu ölümcül sorudur ve özetin ikinci paragrafında durur. Bir alt bölüme geri
kaymasına izin verilmemelidir.

**Bedel sabit değildir.** Gereken öte taraf mesafesi enerjiyle sınırsız düşer:
toplam dokuzda $2{,}4845$, elli binde $0{,}0316$. Ve bu genlikten hiçbir şey
götürmez.

**Ama enerji hızı satın almaz.** Doyum derinliği sabitken dönen ağırlık her
enerjide $4{,}77 \times 10^{-10}$. Enerjinin satın aldığı şey mesafedir, hız
değildir. Bir olay için $1{,}5 \times 10^{36}$ deneme gerekir.

**Gidiş dönüş ile tek geçiş karıştırılmamalıdır.** Bu hata bu çalışmaya **iki
kez** ikilik çarpana mal olmuştur. Bir gecikmeyi ya da mesafeyi ışıkla
karşılaştıran her yerde iki tarafın da gidiş dönüş olduğu denetlenmelidir.

---

## 7. Bekçiler, sizi yakalayacaklar

Bunlar süs değildir, bu turda üç kez gerçek hata yakaladılar.

- **Varsayım sicili** metni tarar; bir bölüm varsayım ileri sürüyor ve sicilde
  satırı yoksa kontrol düşer.
- **Üretim sicili** yeniden üretildiği iddia edilen ama kütüphane adı taşımayan
  her kalemi reddeder.
- **Uzun tire kuralı** denetlenir.

Ayrıca kodun kendisi bu turda iki kez metni çürüttü: yayılımlı rejim satırı ve
"sayımda ayrışır" ifadesi. **Bir cümleye güvenmeden önce kontrolü yazın.**

---

## 8. Nerede ne yazılı

| Dosya | İçerik |
|---|---|
| `article/article.md` | Makalenin kendisi, $5119$ satır |
| `DEVIR-TESLIM.md` | Bu dosya. Ayıklama ve hakem kayıtları buraya taşınıp silindi |

**Kodun raporu çürüttüğü yer, kayda geçmesi için.** Bölüm 0.1'in tablosunda
altıncı bir satır vardı: yayılımlı rejimde eşiğin kalınlıkla büyüdüğü. Kod bunu
sınadı ve çürüttü. Kapalı biçim, iç mod sönümlü değilken bir gecikme
vermemektedir; o sınırda değişen şey bedelin büyüklüğü değil, **hesabın
uygulanıp uygulanmadığıdır**. Satır kaldırıldı. Bir cümleye güvenmeden önce
kontrolü yazma kuralının en somut örneği budur.

**Hakem raporundan sırada kalan üç madde:** sicillerin birleştirilmesi,
tarihsel değinilerin dipnota alınması, ve ek bir sayısal karşılaştırma.

Makalede **Bölüm 0** çekirdek hesabı taşır ve tek başına yeterlidir; bir okur
makalenin geri kalanına bakmadan bütün sayıları yeniden üretebilir. **Bölüm
0.1** bir gidiş dönüşün bütün ihtimallerini verir. **Bölüm 20** zinciri ve tek
bir parçacığın on bir adımlık dökümünü taşır. Bir sadeleştirmede bu üçü
korunmalıdır.

---

## 9. Bir sonraki oturum için sıra

1. Bu dosyayı oku, özellikle ikinci bölümdeki **yanlış çıkmış beş öneri**
   tablosunu.
2. Makaleyi çekirdeğe indir. Ölçüt ikinci bölümde. Kesmeden önce **ölç**;
   beş maddenin beşi de ölçülmediği için yanlış çıktı.
3. Kodu da aynı ölçütle indir. `src/` altında $79$ başlık var.
4. Her adımda `make`, çalıştır, `commit`, `push`.

Gidiş dönüş simülasyonu **bitti**, üçüncü bölümde. Yeniden açılmasına gerek
yok.
