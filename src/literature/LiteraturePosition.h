#pragma once

// ============================================================================
//  LiteraturePosition — model.md §17, §19, §24, §25 ve kaynakca
// ----------------------------------------------------------------------------
//
//  §17 ISARET SECIMI (acik A): KAPANAMAZ OLDUGUNUN GOSTERIMI
//  ---------------------------------------------------------
//  +-D ayrimi test edildi: her iki isaret de det = +1 ve M^2 = I kosullarini
//  sagliyor, ayirt edilemiyorlar. Ancak §16'daki bulgu, isaretin ANLAMINI
//  netlestiriyor:
//    1. Her iki bolgede birer ok secimi var (bizde zaman, otede uzay).
//    2. D bizim ok eksenimizi onlarin ok eksenine gonderiyor — secimler
//       bagimsiz degil, biri digerini belirliyor.
//    3. Fiziksel olarak anlamli olan tek buyukluk BAGIL ISARET: iki okun
//       hizalanmasi. Tek basina hicbiri anlamli degil.
//    4. Sigma gecirgen olmadigi icin iki bolge haberlesemiyor -> bagil isaret
//       PRENSIP OLARAK OLCULEMEZ.
//  SONUC: A bir eksiklik degil, YAPISAL BIR OZELLIK. Bizim tarafta da zamanin
//  oku denklemlerden turetilmez (Newton, Maxwell, Schrodinger hepsi
//  T-simetriktir); ok baslangic kosulundan gelir.
//
//
//  §11 ACIK KALANLAR (calisma notunun ara durumu)
//  ----------------------------------------------
//    A | D'nin genel isareti      | KAPANAMAZ oldugu gosterildi — bkz. §17
//    B | Makale (37) dogrulamasi  | Kapandi — bkz. §14
//    C | Etkilesim / Maxwell      | Kapandi — bkz. §15
//    D | Kuantumlama              | Kapandi — §20, §21, §22
//    E | Uc zamanda zamanin oku   | Kapandi — ok boyut sayisindan, bkz. §16
//
//
//  §19 GUNCEL DURUM
//  ----------------
//    #1 Uc zamanda zamanin oku  | Kapandi (§16) — ok boyut sayisindan
//    #2 +- isareti              | Kapanamaz oldugu gosterildi (§17)
//    #3 Grup yapisi             | Kapandi (§4) — sorun B katmaninda
//    #4 Kuresel simetrik cozum  | Kapandi (§14) — kapali form + yorum
//    #5 Superluminal durgunluk  | Kapandi (§8) — gauge fazlaligi
//    #6 Takyonlar var mi        | Acik (deneysel)
//  Modele ozgu ek sonuclar: carpanlama (§2), esigin yansitici olmasi (§9),
//  Maxwell'in bagimsiz yeniden uretimi (§15).
//
//
//  §24 2023 MAKALESIYLE KUANTUM DUZEYINDE KARSILASTIRMA
//  ---------------------------------------------------
//    Kuantumlama        | Dragan: yapilmiyor  | Bu model: kanonik yolun neden
//                       |                     | tikali oldugu gosterildi (§20.1)
//    Determinizm kaybi  | onceki calismaya    | denklem tipinden turetildi (§7)
//                       | dayandiriliyor      |
//    Propagator         | yok                 | Oklid propagatoru, tekilliksiz (§21.3)
//    Wick donusu        | ele alinmiyor       | zorunlu secim gosterildi (§21.1)
//    Iki bolgenin       | ayri cerceveler     | ortak Oklid teorisinin iki
//    iliskisi           |                     | analitik devami (§21.4)
//    Maxwell            | klasik alan         | ayni sonuclar tek matris
//                       |                     | carpimindan (§15)
//    Vakum / parcacik   | ele alinmiyor       | parcacik tanimsiz, korelasyon
//                       |                     | teorisi (§22)
//
//
//  §25 LITERATUR TARAMASI VE MODELIN KONUMU
//  ----------------------------------------
//  Modelin bilesenlerinin karsiliklari IKI AYRI LITERATURDE bulunuyor ve bu iki
//  literatur birbirine atif yapmiyor.
//
//  §25.1 SUPERLUMINAL DONUSUM / GRUP TEORISI KOLU
//    Zaopo, arXiv:2510.25385 (2025) — §2-4'un bagimsiz ve daha genis hali.
//    Involutif matrisler Lambda_inf(theta,phi) ile Lambda_inf^2 = I,
//    carpanlama Lambda_S(V) = Lambda_s(v) Lambda_inf, esleme V = c^2/v, ve
//    yari-dogrudan carpim L_ext = (SO(3,1)+^ |x Z_2) x Z_2.
//
//    Farklar (hesaplandi):
//      Degisen koordinat : Zaopo 2 (t ve n yonu)  | D: 4 (hepsi)
//      Yon bagimliligi   : var, Lambda(th,ph)     | yok, z sabit
//      det               : -1                     | +1
//      Parite            : bozuluyor, kullaniliyor| korunuyor
//      Grup              : Z_2 x Z_2              | Z_2
//
//    D, Zaopo'nun L_ext'inde BULUNMUYOR: D'nin icerdigi x<->y takasinin 3B
//    determinanti -1'dir, dolayisiyla SO(3) elemani degildir.
//
//    Daha eski kol: Mignani-Recami (1973), Chandola-Rajput (1989),
//    Marchildon-Antippa-Everett (1983, SL(4,R) engeli),
//    Bilaniuk-Deshpande-Sudarshan (1962), Feinberg (1967), Rembielinski.
//
//  §25.2 IMZA DEGISIMI / EKLEM KOSULLARI KOLU
//    Bu literatur kozmoloji ve kuantum kutlecekimi tarafinda ve §9, §23
//    sonuclarini BAGIMSIZ OLARAK DOGRULUYOR.
//      Bojowald, arXiv:2009.13565 — imza degisimi olan uzay-zamanda alanlar
//        karisik tipte PDE'lere uyar: Lorentz bolgesinde hiperbolik, Oklid
//        bolgesinde eliptik. Gecis yuzeyi determinist evrimle koprulenemez.
//        (Tricomi sinif landirmasi.) — §9'un karsiligi.
//      Kamleh, arXiv:gr-qc/0004057 — surekli lapse istenirse metrik sinirda
//        dejenere olur ve ters metrik tekillesir. — §23.3'un karsiligi.
//      PRD 100.064043 (2019) — uzaysal metrik ozdegerlerinin isaret degistirdigi
//        durum ve eklem kosullari. — (1,3)->(3,1) gecisinin dogrudan karsiligi.
//      Ayrica: Hayward (gr-qc/9907042), Ellis ve ark., Hartle-Hawking,
//        Hawking-Ellis kolu, arXiv:2607.01274.
//
//  §25.3 COKLU ZAMAN KOLU
//    Bars, hep-th/0003100 — iki-zaman fizigi; ekstra zaman boyutu ayar
//    simetrisiyle elimine edilir. §20'deki kanonik tikanmanin muadili.
//
//  §25.4 MODELIN OZGUN KALDIGI YERLER
//    - §9  esigin yansitici olmasi, superluminal baglamda turetilmis hali
//    - §21 Wick donusunun "tek olan ekseni dondur" kurali ve iki bolgenin
//          ortak Oklid teorisinin analitik devamlari olmasi
//    - §23 kara delik ufkuyla imza-sinifi karsilastirmasi
//    - §14 kuresel simetrik cozumun kapali formu ve yorumu
//
//    ASIL OZGUNLUK IDDIASI, PARCALARDA DEGIL BAGLANTIDADIR: Dragan'in
//    superluminal cercevesini, kozmolojideki imza-degisimi eklem kosullari
//    makineriyle birlestirmek. Bu birlestirmeyi yapan bir calismaya
//    rastlanmadi.
//
//
//  KAYNAKLAR
//  ---------
//    Dragan A, Debski K, Charzynski S, Turzynski K, Ekert A. Relativity of
//      superluminal observers in 1+3 spacetime. Class. Quantum Grav. 40 (2023)
//      025013
//    Dragan A, Ekert A. New J. Phys. 22 (2020) 033038
//    Marchildon L, Antippa A F, Everett A E. Phys. Rev. D 27 (1983) 1740
//    Bilaniuk O M P, Deshpande V K, Sudarshan E C G. Am. J. Phys. 30 (1962) 718
//    Feinberg G. Phys. Rev. 159 (1967) 1089
//    Recami E. Riv. Nuovo Cimento 9 (1986) 1
//    Rembielinski J. arXiv:hep-th/9612072
//    Zaopo M. Group Representations of Lorentz Transformations Extended to
//      Superluminal Observers. arXiv:2510.25385 (2025)
//    Lake M J. The (1+3)-dimensional 'quantum principle of relativity' is
//      Einstein's principle of relativity. arXiv:2410.07017 (2025)
//    Lake M J. Towards a group structure for superluminal velocity boosts.
//      arXiv:2409.01773 (2024)
//    Horodecki P. Comment on 'Quantum principle of relativity'.
//      arXiv:2301.07802 (2023); Dragan & Ekert, Reply, New J. Phys. 25 128002
//      (2023)
//    Bojowald M. Black-hole models in loop quantum gravity. arXiv:2009.13565
//    Kamleh W. Signature Changing Space-times and the New Generalised
//      Functions. arXiv:gr-qc/0004057
//    Hayward S A. Failure of Standard Conservation Laws at a Classical Change
//      of Signature. arXiv:gr-qc/9404001
//    Alternative route towards the change of metric signature.
//      Phys. Rev. D 100, 064043 (2019)
//    Bars I. Two-Time Physics in Field Theory. arXiv:hep-th/0003100
//    Mignani R, Recami E. Nuovo Cimento 14(1), 169 (1973)
//    Chandola H C, Rajput V S. Can. J. Phys. 67(7), 645 (1989)
//    Hartle J B, Hawking S W. Phys. Rev. D 28, 2960 (1983)
// ============================================================================

#include "core/Matrix4.h"
#include "core/Section.h"

namespace slm
{

    class LiteraturePosition : public Section
    {
    public:
        // Zaopo Lambda_inf(theta=0, phi=0): t <-> z (isaretli), x ve y sabit.
        static Matrix4 zaopoLambdaInfinity();

        // D, Zaopo'nun L_ext grubunda mi? (Hayir — x<->y takasi det = -1.)
        static bool isInZaopoGroup();

        // D'nin icerdigi x <-> y takasinin 3B determinanti.
        static double xySwapDeterminant3D();

        std::string number() const override { return "§17 / §24 / §25"; }
        std::string title() const override
        {
            return "Isaret secimi, makale karsilastirmasi ve literatur konumu";
        }
        void run(Report &report) const override;
    };

} // namespace slm
