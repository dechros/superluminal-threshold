#pragma once

// ============================================================================
//  SylvesterObstruction — model.md §26 (temel elestiri: imza gercekten
//  cevrilebilir mi?)
// ----------------------------------------------------------------------------
//
//  §26.1 LAKE'IN ITIRAZI
//  Lake, arXiv:2410.07017 (2025), Dragan ve ark.'nin (1+3) calismasina dogrudan
//  itiraz ediyor:
//    1. Superboost operatorleri, standart olmayan gosterimle yazilmis siradan
//       Lorentz boostlaridir.
//    2. Superflip, birim operator arti keyfi bir yeniden etiketlemedir.
//    3. 24 permutasyondan 6'si cizgi elemanini korur (etiket degisimi), 18'i
//       degistirir.
//    4. Bu 18'i elestirisi: boost yonu n ne olursa olsun belirli bir eksen
//       (or. z) her zaman takas edilir; bu koordinat-bagimli, dolayisiyla
//       fiziksel olmayan ongoruler verir.
//
//  BU MODELIN D'SI, LAKE'IN LISTELEDIGI ILK MATRISTIR — yani elestiri dogrudan
//  D'yi hedef alir.
//
//  §26.3 SYLVESTER ATALET YASASI — BELIRLEYICI SONUC
//
//    > REEL HICBIR M ICIN  M^T eta M = -eta  OLAMAZ.
//
//  Gerekce: kongruan matrisler ayni imzaya sahiptir (Sylvester). eta'nin imzasi
//  (1,3), -eta'ninki (3,1). Sayisal tarama da yapildi; hata sifira yaklasmiyor.
//
//  BU MODELIN D'SI NE SAGLIYORDU:
//      D^T eta' D = -eta        (sol tarafta eta', sagda eta)
//      D^T eta  D = -eta        SAGLANMIYOR
//
//  Yani "imza degisimi" iki FARKLI metrik arasinda bir iliskidir; eta''nun elle
//  konmasi, Lake'in itiraz ettigi yeniden etiketlemedir.
//
//  §26.4 CATAL
//      |                | Yon-kovaryant | Gercek imza cevirme        |
//      | Zaopo Lambda_inf(n) | evet     | hayir                      |
//      | Bu modelin D'si     | hayir    | hayir (eta' elle konur)    |
//      | +-i Lambda          | evet     | EVET — ama reel degil      |
//  Ikisini birden veren reel donusum yoktur; Sylvester bunu yasaklar.
//  Lake'in kendi notu: +-i Lambda uygulamak, metrigi sabit tutup m -> +-im
//  yapmakla esdegerdir — yani Feinberg'in sanal kutlesi.
//
//  §26.5 BU MODELIN DURUSU
//  Bu calismada REEL KUTLE KORUNMAKTADIR. Bunun bedeli acikca kabul edilir:
//  donusum duzeyinde gercek bir imza cevrilmesi elde edilmez; D iki farkli
//  metrik arasinda bir eslemedir.
//
//  Buna karsilik modelin §9, §16, §21, §23'teki sonuclari bu elestiriden
//  etkilenmez, cunku onlar DONUSUM DUZEYINDE DEGIL, METRIK DUZEYINDE
//  kurulmustur — iki bolge ayri metriklerle tanimlanir ve aralarindaki iliski
//  eklem kosullariyla ele alinir. Bu, §25.2'deki kozmoloji literaturunun
//  yontemidir ve Sylvester engeline takilmaz: orada imza, bir donusumle degil,
//  metrigin kendisinin degismesiyle degisir.
//
//    > SONUC OLARAK MODELIN SAGLAM CEKIRDEGI, DRAGAN-TIPI DONUSUM KOLU DEGIL,
//    > IMZA-DEGISIMI EKLEM KOSULLARI KOLUDUR.
//  Ileride yeniden cerceveleme yapilacaksa baslangic noktasi bu olmalidir.
// ============================================================================

#include "core/Section.h"

namespace slm
{

    class SylvesterObstruction : public Section
    {
    public:
        // 20.000 rastgele reel 4x4 matris uzerinde  M^T eta M + eta  hatasinin
        // ulasabildigi en kucuk deger. Sifira yaklasmaz.
        static double randomSearchBestResidual(int trials = 20000, unsigned seed = 20250801u);

        std::string number() const override { return "§26"; }
        std::string title() const override
        {
            return "Temel elestiri: Lake, Sylvester atalet yasasi ve modelin durusu";
        }
        void run(Report &report) const override;
    };

} // namespace slm
