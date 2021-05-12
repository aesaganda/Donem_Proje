#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
// #include <unistd.h>
#define musteriSayisi 100

//static FILE *fopen(char *musteriKayitlari,char *a); //dosya acildi.

short satir, kolon;

// KullanÄ±lan deÄŸiÅŸkenler
int kartNo[100];
float karttakiPara[100];
float kasadakiPara = 1000; // test amaÃ§lÄ± 1000 deÄŸeri
float toplamTutar = 0.0;
unsigned int toplamSiparis[100];
unsigned int siparisMiktari[100];
unsigned int siparis = 0;

// Ä°ÅŸlev fonksiyonlarÄ±
float siparisDetaylari(float *fiyatToplam, float tekFiyat);

// Ekleme ve GÃ¼ncelleme FonksiyonlarÄ±
void yemek_ekle(int veri, char yemekAdi[25], int miktar, float fiyat);
void fiyat_guncelle();
void musteriEkleme();
void musteriKayitlariniGoruntule();

// Silme ve Sayma FonksiyonlarÄ±
void yemek_sil(int siparisKodu);
void yemek_say();

// MenÃ¼ fonksiyonlarÄ±
void yemek_listesi(int n);
void admin_menu();
void siparis_menu();
void ana_menu();
void musteriGirisi();
void uygulamayiKapat();
void gecersizGiris();
int secimFonksiyonu();

// Alt menÃ¼ fonksiyonlarÄ±
void kebap();
void doner();
void pizza();
void pide();
void hamburger();
void tatli();
void icecekler();

// TasarÄ±m fonksiyonlarÄ±
void tamEkran();
void cls();
void echo(char print[]);
void satir_bas(int line);
void tab_bas(int tab);
void bosluk_bas(int space);
void cerceve();
void karsilama();
void ilerleme();
void menuRenk();

// Structlarin tanÄ±mÄ±
struct musteriAdresi
{
    char *sehir;
    char *ilce;
    char *semt;
    char *sokak;
    char *daireNo;
};

struct krediKartiBilgileri
{
    char *kartNumarasi;
    char *gecerlilikTarihi; // tarih ay/yÄ±l seklinde
    char *kartSahibiAdi;
    char *guvenlikKodu;
};

struct musteriBilgileri
{
    char *musteriIsmi;
    char *musteriSoyismi;
    char *musteriEMail;
    int musteriSifre;
    int musteriId;
    float musteriHesapbakiyesi;
    struct musteriAdresi adres;
    struct krediKartiBilgileri krediKarti;
};

struct iceceklerBilgi
{
    char adi[20];
    int stokAdedi;
    float fiyati;
};

struct kebaplarBilgi
{
    char adi[20];
    int malzemeAdedi;
    float fiyati;
};

struct donerlerBilgi
{
    char adi[20];
    int malzemeAdedi;
    float fiyati;
};

struct hamburgerlerBilgi
{
    char adi[20];
    int malzemeAdedi;
    float fiyati;
};

struct pizzalarBilgi
{
    char adi[20];
    int malzemeAdedi;
    float fiyati;
};

struct pidelerBilgi
{
    char adi[20];
    int malzemeAdedi;
    float fiyati;
};

struct tatlilarBilgi
{
    char adi[20];
    int malzemeAdedi;
    float fiyati;
};

struct Test
{
    char yemekAdi[50];
    int miktar;
    float fiyat;
    int veri;
    struct Test *sonraki;
};

//Structlar - fonksiyon // Yemek Secimi
void kebapSecimVeFiyatlandirma(struct kebaplarBilgi *pKebap, int n);

void kebapBilgisiGuncelleme(struct kebaplarBilgi *pKebap);

void donerSecimVeFiyatlandirma(struct donerlerBilgi *pDoner, int n);

void hamburgerSecimVeFiyatlandirma(struct hamburgerlerBilgi *pHamburger, int n);

void pizzaSecimVeFiyatlandirma(struct pizzalarBilgi *pPizza, int n);

void pideSecimVeFiyatlandirma(struct pidelerBilgi *pPide, int n);

void tatliSecimVeFiyatlandirma(struct tatlilarBilgi *pTatli, int n);

void icecekSecimVeFiyatlandirma(struct iceceklerBilgi *pIcecek, int n);

// test tipinde deÄŸiÅŸken oluÅŸturulmasÄ±
typedef struct Test test;

test *bas, *liste;

int main()
{
    tamEkran(); // Konsol ekranini tam ekran seklinde donusturme
    struct musteriBilgileri musteri[musteriSayisi];
    struct musteriBilgileri *musteriler;
    system("title Marmara Kebap House");
    //system("mode con: cols=100 lines=40");
    bas = NULL;

    //yemek_ekle(1, "Adana Kebap  ", 10, 35);

    // ilerleme();
    cls();
    //  karsilama();
    cls();
    ana_menu();
}

void cls()
{
    system("cls");
}

void echo(char print[])
{
    printf("%s", print);
}

void satir_bas(int satir)
{
    int i;
    for (i = 0; i < satir; i++)
    {
        putchar('\n');
    }
}

void tab_bas(int tab)
{
    int i;
    for (i = 0; i < tab; i++)
    {
        putchar('\t');
    }
}

void bosluk_bas(int bosluk)
{
    int i;
    for (i = 0; i < bosluk; i++)
    {
        putchar(' ');
    }
}

void menuRenk()
{
    system("color 3E");
    printf("\n\t\t");
    system("color 3E");
    cls();
    bosluk_bas(1);
    tab_bas(4);
    printf("\n\t\t");
    echo("==>  [0]. Ust Menu\n\n");
    bosluk_bas(2);
    Sleep(35);
}

void yemek_ekle(int veri, char yemekAdi[25], int miktar, float fiyat)
{
    test *gecici;

    gecici = (test *)malloc(sizeof(test));

    gecici->veri = veri;
    gecici->fiyat = fiyat;

    strcpy(gecici->yemekAdi, yemekAdi);
    gecici->miktar = miktar;
    gecici->sonraki = bas;
    bas = gecici;
    liste = bas;
}

void ana_menu()
{
    cls();
    int i, n = 0;
    char anaMenuListesi[4][30] = {"Musteri Girisi", "Admin Paneli", "Yeni Musteri Ekleme Paneli", "Cikis"};
    satir_bas(10);
    for (i = 0; i < 4; i++)
    {
        satir_bas(2);
        tab_bas(9);
        printf("==>  [%d]. %s\n\n", i + 1, anaMenuListesi[i]);
        Sleep(100);
    }
    satir_bas(1);

    int anaSecim = secimFonksiyonu();
    switch (anaSecim)
    {
    case 1:
        musteriGirisi();
        break;

    case 2:
        admin_menu();
        break;

    case 3:
        musteriEkleme();
        break;

    case 4:
        uygulamayiKapat();

    default:
        gecersizGiris();
        break;
    }
}

void admin_menu()
{
    menuRenk();
    echo("\n\nSifrenizi girin: ");
    int adminSecim = secimFonksiyonu();

    if (adminSecim == 0)
    {
        ana_menu();
    }

    else if (adminSecim != 12345)
    {
        cls();
        bosluk_bas(5);
        tab_bas(4);
        echo("Giris yaparken hatali tuslama yaptiniz...\n\n");
        Sleep(1000);
        ana_menu();
    }

    else if (adminSecim == 12345)
    {
        test *gecici;

        gecici = liste;

        cls();
        satir_bas(10);
        tab_bas(9);
        echo("Basariyla giris yaptiniz...\n\n");
        Sleep(1000);

    admin:
        cls();
        bosluk_bas(5);

        int i;
        char adminMenuListesi[6][40] = {"Ana Menuye Don", "Gunluk Butce", "Yemek Ekle", "Yemek Sil", "Kayitli Kullanicilar", "Yemekleri Listele"};
        satir_bas(6);
        for (i = 0; i < 6; i++)
        {
            satir_bas(2);
            tab_bas(9);
            printf("==>  [%d]. %s\n\n", i, adminMenuListesi[i]);
            Sleep(100);
        }

        int adminSecim = secimFonksiyonu();
        switch (adminSecim)
        {
        case 0:
            ana_menu();
            break;

        case 1:
            cls();
            satir_bas(8);
            cerceve();
            satir_bas(2);
            tab_bas(8);
            printf("Kasaya giren toplam para : %0.2f \n", kasadakiPara); //fonksiyon olusturulabilir.
            satir_bas(2);
            cerceve();
            getchar();
            Sleep(3000);
            goto admin;
            break;

        case 2:
            cls();
            char yemek[50];
            bosluk_bas(2);
            tab_bas(4);

            printf(" Yemek adini girin: ");
            scanf("%s", &yemek);
            goto admin;
            break;

        case 3:
            cls();
            printf(" Yemek silmek icin kodunu girin: ");
            getchar();
            goto admin;
            break;

        case 4:
            cls();
            musteriKayitlariniGoruntule();
            goto admin;
            break;

        case 5:
            cls();
            int n;
            yemek_listesi(n);
            getchar();
            Sleep(3000);
            goto admin;
            break;

        default:
            cls();
            puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
            goto admin;
            break;
        }
    }
}

void musteriGirisi()
{
    cls();

    int sifre;
    int idNumarasi;
    struct musteriBilgileri *musteriler;

    int n = 0;
    menuRenk();
    int i = 0;
    //echo("\n==>[0] Ana menu :");
    echo("\t\t Size ozel ID kodunuzu giriniz:");
    scanf("%d", &idNumarasi);
    echo("\t\tkullanici Sifrenizi girin: ");
    scanf("%d", &sifre);

    while (i != EOF)
    {
        if (musteriler[i].musteriId == idNumarasi && musteriler[i].musteriSifre == sifre)
        {
            printf("id kodunuz ve sifreniz dogrudur.Giris Basarili...\n");
            Sleep(1000);
            yemek_listesi(n);
        }
        else
        {
            printf("id kodunuz veya sifreniz hatalidir...\n");
            Sleep(1000);
            ana_menu();
        }
        i++;
    }
}

void yemek_listesi(int n)
{
    int i;

    char yemekListesi[7][15] = {"Kebaplar", "Donerler", "Hamburgerler", "Pizzalar", "Pideler", "Tatlilar", "Icecekler"};

    menuRenk();
    for (i = 0; i < 7; i++)
    {
        bosluk_bas(1);
        tab_bas(9);
        Sleep(100);
        printf("==>  [%d]. %s\n\n", i + 1, yemekListesi[i]);
    }
    Sleep(100);

    int listeSecim = secimFonksiyonu();

    switch (listeSecim)
    {
    case 0:
        ana_menu();
        break;

    case 1:
        kebap(n);
        break;

    case 2:
        doner(n);
        break;

    case 3:
        hamburger(n);
        break;

    case 4:
        pizza(n);
        break;

    case 5:
        pide(n);
        break;

    case 6:
        tatli(n);
        break;

    case 7:
        icecekler(n);
        break;

    default:
        gecersizGiris();
        break;
    }
}

void icecekler(int n)
{
    int i, icecekCesitSayisi = 7;
    struct iceceklerBilgi icecek[icecekCesitSayisi], *pIcecek;
    pIcecek = icecek;

    strcpy(icecek[0].adi, "Kola");
    icecek[0].stokAdedi = 125;
    icecek[0].fiyati = 4.0;

    strcpy(icecek[1].adi, "Fanta");
    icecek[1].stokAdedi = 125;
    icecek[1].fiyati = 4.0;

    strcpy(icecek[2].adi, "Ayran");
    icecek[2].stokAdedi = 125;
    icecek[2].fiyati = 3.0;

    strcpy(icecek[3].adi, "Salgam");
    icecek[3].stokAdedi = 125;
    icecek[3].fiyati = 3.5;

    strcpy(icecek[4].adi, "Soda");
    icecek[4].stokAdedi = 125;
    icecek[4].fiyati = 2.0;

    strcpy(icecek[5].adi, "Turk Kahvesi");
    icecek[5].stokAdedi = 125;
    icecek[5].fiyati = 5.0;

    strcpy(icecek[6].adi, "Su");
    icecek[6].stokAdedi = 125;
    icecek[6].fiyati = 2.0;

    menuRenk();
    cerceve();
    satir_bas(3);
    for (i = 1; i <= icecekCesitSayisi; i++)
    {
        bosluk_bas(3);
        tab_bas(6);

        printf("==================>  [%d].%10s: %5.2f%25s", i, icecek[i - 1].adi, icecek[i - 1].fiyati, "<==================\n\n");
        Sleep(100);
    }
    cerceve();

    if (n)
    {
        echo("\n\nadmin yemek guncelleme fonksiyonu");
        //admin yemek guncelleme fonksiyonu
    }
    else
    {
        icecekSecimVeFiyatlandirma(pIcecek, n);
    }
}

void icecekSecimVeFiyatlandirma(struct iceceklerBilgi *pIcecek, int n)
{
    echo("\n");

    int icecek_secim = secimFonksiyonu();
    switch (icecek_secim)
    {
    case 0:
        echo("Icecek istemediginizden emin misiniz? Evet 1 / Hayir 0 \n");
        int tercih = secimFonksiyonu();
        if (tercih)
        {
            printf("Aldiklariniz %.2f TL tutmustur.\n", toplamTutar);
            echo("Siparisiniz hazirlaniyor.Anasayfaya yonlendiriliyorsunuz...");
            Sleep(1100);
            kasadakiPara += toplamTutar;
            //! toplamTutar sifirlanmadan once dosyaya aktarilmali
            toplamTutar = 0;
            ana_menu();
        }
        else
        {
            icecekler(n);
        }
        break;

    case 1:
        siparisDetaylari(&toplamTutar, pIcecek[0].fiyati);
        kasadakiPara += toplamTutar; //Kasadaki ana para admin panelinden gorulebilir haldedir.
        //TODO: toplamTutar sifirlanmadan once dosyaya aktarilmali
        toplamTutar = 0;
        break;

    case 2:
        siparisDetaylari(&toplamTutar, pIcecek[1].fiyati);
        kasadakiPara += toplamTutar;
        //TODO: toplamTutar sifirlanmadan once dosyaya aktarilmali
        toplamTutar = 0;
        break;

    case 3:
        siparisDetaylari(&toplamTutar, pIcecek[2].fiyati);
        kasadakiPara += toplamTutar;
        //TODO: toplamTutar sifirlanmadan once dosyaya aktarilmali
        toplamTutar = 0;
        break;

    case 4:
        siparisDetaylari(&toplamTutar, pIcecek[3].fiyati);
        kasadakiPara += toplamTutar;
        //TODO: toplamTutar sifirlanmadan once dosyaya aktarilmali
        toplamTutar = 0;
        break;

    case 5:
        siparisDetaylari(&toplamTutar, pIcecek[4].fiyati);
        kasadakiPara += toplamTutar;
        //TODO: toplamTutar sifirlanmadan once dosyaya aktarilmali
        toplamTutar = 0;
        break;

    case 6:
        siparisDetaylari(&toplamTutar, pIcecek[5].fiyati);
        kasadakiPara += toplamTutar;
        //TODO: toplamTutar sifirlanmadan once dosyaya aktarilmali
        toplamTutar = 0;
        break;

    case 7:
        siparisDetaylari(&toplamTutar, pIcecek[6].fiyati);
        kasadakiPara += toplamTutar;
        //TODO: toplamTutar sifirlanmadan once dosyaya aktarilmali
        toplamTutar = 0;
        break;
    default:
        cls();
        icecekler(n);
        break;
    }
    Sleep(1000);
    ana_menu();
}

void kebap(int n)
{
    int i, kebapCesitSayisi = 3;
    struct kebaplarBilgi kebap[kebapCesitSayisi], *pKebap;
    pKebap = kebap;

    strcpy(kebap[0].adi, "Adana");
    kebap[0].malzemeAdedi = 105;
    kebap[0].fiyati = 20.0;

    strcpy(kebap[1].adi, "Urfa");
    kebap[1].malzemeAdedi = 105;
    kebap[1].fiyati = 20.0;

    strcpy(kebap[2].adi, "Alinazik");
    kebap[2].malzemeAdedi = 105;
    kebap[2].fiyati = 25.0;

    menuRenk();
    cerceve();
    satir_bas(3);

    for (i = 1; i <= kebapCesitSayisi; i++)
    {

        bosluk_bas(3);
        tab_bas(6);

        printf("=========================>  [%d].%10s: %5.2f%25s  ", i, kebap[i - 1].adi, kebap[i - 1].fiyati, "<=========================\n\n");
        Sleep(100);
    }
    cerceve();

    if (n)
    {
        kebapBilgisiGuncelleme(pKebap);
        //TODO: admin yemek guncelleme fonksiyonu gelistirilmeli
    }
    else
    {
        kebapSecimVeFiyatlandirma(pKebap, n);
    }
}

void kebapBilgisiGuncelleme(struct kebaplarBilgi *pKebap)
{
    int kebapGuncelleme;
    echo("\n\nGuncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    kebapGuncelleme = secimFonksiyonu();

    switch (kebapGuncelleme)
    {
    case 0:
        ana_menu();
        break;

    case 1:
        printf("\n%s yemeginin yeni ismini giriniz: ", pKebap[0].adi);
        scanf("%s", &pKebap[0].adi);
        printf("\n Yemeginin yeni ismi: %s ", pKebap[0].adi);
        break;
        /*
    case 2:

        break;

    case 3:

        break;
*/
    default:
        cls();
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }
    echo("\n Basariyla kaydedilmistir.");
    getch();
    ana_menu();
}

void kebapSecimVeFiyatlandirma(struct kebaplarBilgi *pKebap, int n)
{

    echo("\n");
    int kebap_secim = secimFonksiyonu();

    switch (kebap_secim)
    {
    case 0:
        ana_menu();
        break;

    case 1:
        siparisDetaylari(&toplamTutar, pKebap[0].fiyati);
        tatli(n);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, pKebap[1].fiyati);
        tatli(n);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, pKebap[2].fiyati);
        tatli(n);
        break;

    default:
        cls();
        gecersizGiris();
        break;
    }
}

void doner(int n)
{
    int i, donerCesitSayisi = 3;
    struct donerlerBilgi doner[donerCesitSayisi], *pDoner;
    pDoner = doner;

    strcpy(doner[0].adi, "Porsiyon Et Doner");
    doner[0].malzemeAdedi = 100;
    doner[0].fiyati = 27.0;

    strcpy(doner[1].adi, "Pilavustu Et Doner");
    doner[1].malzemeAdedi = 100;
    doner[1].fiyati = 28.0;

    strcpy(doner[2].adi, "Iskender Doner");
    doner[2].malzemeAdedi = 100;
    doner[2].fiyati = 29.0;

    menuRenk();
    cerceve();
    satir_bas(3);

    for (i = 1; i <= donerCesitSayisi; i++)
    {
        bosluk_bas(3);
        tab_bas(6);

        printf("==================>  [%d].%20s: %5.2f%25s  ", i, doner[i - 1].adi, doner[i - 1].fiyati, "<==================\n\n");
        Sleep(100);
    }

    cerceve();

    if (n)
    {
        echo("\n\nadmin yemek guncelleme fonksiyonu");
        //admin yemek guncelleme fonksiyonu
    }
    else
    {
        donerSecimVeFiyatlandirma(pDoner, n);
    }
}

void donerSecimVeFiyatlandirma(struct donerlerBilgi *pDoner, int n)
{
    echo("\n");
    int doner_secim = secimFonksiyonu();

    switch (doner_secim)
    {
    case 0:
        ana_menu();
        break;

    case 1:
        siparisDetaylari(&toplamTutar, pDoner[0].fiyati);
        tatli(n);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, pDoner[1].fiyati);
        tatli(n);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, pDoner[2].fiyati);
        tatli(n);
        break;
    default:
        gecersizGiris();
        break;
    }
}

void hamburger(int n)
{
    int i, hamburgerCesitSayisi = 10;
    struct hamburgerlerBilgi hamburger[hamburgerCesitSayisi], *pHamburger;
    pHamburger = hamburger;

    strcpy(hamburger[0].adi, "Steak Hamburger");
    hamburger[0].malzemeAdedi = 100;
    hamburger[0].fiyati = 10.0;

    strcpy(hamburger[1].adi, "Whopper Hamburger");
    hamburger[1].malzemeAdedi = 100;
    hamburger[1].fiyati = 12.0;

    strcpy(hamburger[2].adi, "Big King Hamburger");
    hamburger[2].malzemeAdedi = 100;
    hamburger[2].fiyati = 15.0;

    strcpy(hamburger[3].adi, "Ekonomik Hamburger");
    hamburger[3].malzemeAdedi = 100;
    hamburger[3].fiyati = 8.0;

    strcpy(hamburger[4].adi, "Marmara Hause Hamburger");
    hamburger[4].malzemeAdedi = 100;
    hamburger[4].fiyati = 15.0;

    strcpy(hamburger[5].adi, "Cheeseburger Hamburger");
    hamburger[5].malzemeAdedi = 100;
    hamburger[5].fiyati = 20.0;

    strcpy(hamburger[6].adi, "King Chicken Hamburger");
    hamburger[6].malzemeAdedi = 100;
    hamburger[6].fiyati = 12.0;

    strcpy(hamburger[7].adi, "Klasik Hamburger");
    hamburger[7].malzemeAdedi = 100;
    hamburger[7].fiyati = 10.0;

    strcpy(hamburger[8].adi, "Gurme Hamburger");
    hamburger[8].malzemeAdedi = 100;
    hamburger[8].fiyati = 20.0;

    strcpy(hamburger[9].adi, "Fish Royale Hamburger");
    hamburger[9].malzemeAdedi = 100;
    hamburger[9].fiyati = 14.0;

    menuRenk();
    cerceve();
    satir_bas(3);

    for (i = 1; i <= hamburgerCesitSayisi; i++)
    {
        bosluk_bas(3);
        tab_bas(6);

        printf("==============>  [%d].%28s: %5.2f %25s", i, hamburger[i - 1].adi, hamburger[i - 1].fiyati, "<==============\n\n");
        Sleep(100);
    }

    cerceve();

    if (n)
    {
        echo("\n\nadmin yemek guncelleme fonksiyonu");
        //admin yemek guncelleme fonksiyonu
    }
    else
    {
        hamburgerSecimVeFiyatlandirma(pHamburger, n);
    }
}

void hamburgerSecimVeFiyatlandirma(struct hamburgerlerBilgi *pHamburger, int n)
{
    echo("\n");
    int hamburger_secim = secimFonksiyonu();

    switch (hamburger_secim)
    {
    case 0:
        ana_menu();
        break;

    case 1:
        siparisDetaylari(&toplamTutar, pHamburger[0].fiyati);
        tatli(n);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, pHamburger[1].fiyati);
        tatli(n);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, pHamburger[2].fiyati);
        tatli(n);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, pHamburger[3].fiyati);
        tatli(n);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, pHamburger[4].fiyati);
        tatli(n);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, pHamburger[5].fiyati);
        tatli(n);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, pHamburger[6].fiyati);
        tatli(n);
        break;

    case 8:
        siparisDetaylari(&toplamTutar, pHamburger[7].fiyati);
        tatli(n);
        break;

    case 9:
        siparisDetaylari(&toplamTutar, pHamburger[8].fiyati);
        tatli(n);
        break;

    case 10:
        siparisDetaylari(&toplamTutar, pHamburger[9].fiyati);
        tatli(n);
        break;
    default:
        gecersizGiris();
        break;
    }
}

void pizza(int n)
{
    int i, j, pizzaCesitSayisi = 7;
    struct pizzalarBilgi pizza[pizzaCesitSayisi], *pPizza;
    pPizza = pizza;

    strcpy(pizza[0].adi, "Sucuklu Pizza");
    pizza[0].fiyati = 12.0;
    pizza[0].malzemeAdedi = 105;

    strcpy(pizza[1].adi, "Peynirli Pizza");
    pizza[1].fiyati = 24.0;
    pizza[1].malzemeAdedi = 105;

    strcpy(pizza[2].adi, "Bolbol Pizza");
    pizza[2].fiyati = 32.0;
    pizza[2].malzemeAdedi = 105;

    strcpy(pizza[3].adi, "Meksika Pizza");
    pizza[3].fiyati = 30.0;
    pizza[3].malzemeAdedi = 105;

    strcpy(pizza[4].adi, "Mozarella Pizza");
    pizza[4].fiyati = 35.0;
    pizza[4].malzemeAdedi = 105;

    strcpy(pizza[5].adi, "NewYork Pizza");
    pizza[5].fiyati = 34.0;
    pizza[5].malzemeAdedi = 105;

    strcpy(pizza[6].adi, "MarmaraPizza Pizza");
    pizza[6].fiyati = 17.0;
    pizza[6].malzemeAdedi = 105;

    menuRenk();
    cerceve();
    satir_bas(3);

    for (i = 1; i <= pizzaCesitSayisi; i++)
    {
        bosluk_bas(3);
        tab_bas(6);

        printf("=======================>  [%d].%20s: %5.2f%25s", i, pizza[i - 1].adi, pizza[i - 1].fiyati, "<=======================\n\n");
        Sleep(100);
    }

    cerceve();

    if (n)
    {
        echo("\n\nadmin yemek guncelleme fonksiyonu");
        //admin yemek guncelleme fonksiyonu
    }
    else
    {
        pizzaSecimVeFiyatlandirma(pPizza, n);
    }
}

void pizzaSecimVeFiyatlandirma(struct pizzalarBilgi *pPizza, int n)
{
    echo("\n");
    int pizza_secim = secimFonksiyonu();

    switch (pizza_secim)
    {
    case 0:
        ana_menu();
        break;

    case 1:
        siparisDetaylari(&toplamTutar, pPizza[0].fiyati);
        tatli(n);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, pPizza[1].fiyati);
        tatli(n);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, pPizza[2].fiyati);
        tatli(n);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, pPizza[3].fiyati);
        tatli(n);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, pPizza[4].fiyati);
        tatli(n);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, pPizza[5].fiyati);
        tatli(n);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, pPizza[6].fiyati);
        tatli(n);
        break;
    default:
        gecersizGiris();
        break;
    }
}

void pide(int n)
{
    int i, pideCesitSayisi = 7;
    struct pidelerBilgi pide[pideCesitSayisi], *pPide;
    pPide = pide;

    strcpy(pide[0].adi, "Kiymali Pide");
    pide[0].malzemeAdedi = 100;
    pide[0].fiyati = 12.0;

    strcpy(pide[1].adi, "Kavurmali Pide");
    pide[1].malzemeAdedi = 100;
    pide[1].fiyati = 15.0;

    strcpy(pide[2].adi, "Kusbasi Pide");
    pide[2].malzemeAdedi = 100;
    pide[2].fiyati = 15.0;

    strcpy(pide[3].adi, "Sucuklu Yumurtali Pide");
    pide[3].malzemeAdedi = 100;
    pide[3].fiyati = 15.0;

    strcpy(pide[4].adi, "Peynirli Pide");
    pide[4].malzemeAdedi = 100;
    pide[4].fiyati = 14.0;

    strcpy(pide[5].adi, "Mevlana Pide");
    pide[5].malzemeAdedi = 100;
    pide[5].fiyati = 18.0;

    strcpy(pide[6].adi, "Bicak Arasi Pide");
    pide[6].malzemeAdedi = 100;
    pide[6].fiyati = 19.0;

    menuRenk();
    cerceve();
    satir_bas(3);

    for (i = 1; i <= pideCesitSayisi; i++)
    {
        bosluk_bas(3);
        tab_bas(6);

        printf("==================>  [%d].%25s: %5.2f%25s", i, pide[i - 1].adi, pide[i - 1].fiyati, "<==================\n\n");
        Sleep(100);
    }

    cerceve();

    if (n)
    {
        echo("\n\nadmin yemek guncelleme fonksiyonu");
        //admin yemek guncelleme fonksiyonu
    }
    else
    {
        pideSecimVeFiyatlandirma(pPide, n);
    }
}

void pideSecimVeFiyatlandirma(struct pidelerBilgi *pPide, int n)
{
    echo("\n");
    int pide_secim = secimFonksiyonu();

    switch (pide_secim)
    {
    case 0:
        ana_menu();
        break;

    case 1:
        siparisDetaylari(&toplamTutar, pPide[0].fiyati);
        tatli(n);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, pPide[1].fiyati);
        tatli(n);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, pPide[2].fiyati);
        tatli(n);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, pPide[3].fiyati);
        tatli(n);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, pPide[4].fiyati);
        tatli(n);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, pPide[5].fiyati);
        tatli(n);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, pPide[6].fiyati);
        tatli(n);
        break;
    default:
        gecersizGiris();
        break;
    }
}

void tatli(int n)
{
    int i, tatliCesitSayisi = 9;
    struct tatlilarBilgi tatli[tatliCesitSayisi], *pTatli;
    pTatli = tatli;

    strcpy(tatli[0].adi, "Kunefe");
    tatli[0].malzemeAdedi = 100;
    tatli[0].fiyati = 13.0;

    strcpy(tatli[1].adi, "Sutlac");
    tatli[1].malzemeAdedi = 100;
    tatli[1].fiyati = 9.0;

    strcpy(tatli[2].adi, "Kadayif");
    tatli[2].malzemeAdedi = 100;
    tatli[2].fiyati = 12.0;

    strcpy(tatli[3].adi, "Baklava");
    tatli[3].malzemeAdedi = 100;
    tatli[3].fiyati = 30.0;

    strcpy(tatli[4].adi, "Trilece");
    tatli[4].malzemeAdedi = 100;
    tatli[4].fiyati = 10.0;

    strcpy(tatli[5].adi, "Hosmerim");
    tatli[5].malzemeAdedi = 100;
    tatli[5].fiyati = 10.0;

    strcpy(tatli[6].adi, "Supangle");
    tatli[6].malzemeAdedi = 100;
    tatli[6].fiyati = 8.0;

    strcpy(tatli[7].adi, "Profiterol");
    tatli[7].malzemeAdedi = 100;
    tatli[7].fiyati = 8.0;

    strcpy(tatli[8].adi, "Cheesecake");
    tatli[8].malzemeAdedi = 100;
    tatli[8].fiyati = 12.0;

    menuRenk();
    cerceve();
    satir_bas(3);

    for (i = 1; i <= tatliCesitSayisi; i++)
    {
        bosluk_bas(3);
        tab_bas(6);

        printf("=====================>    [%d].%10s:%5.2f%25s", i, tatli[i - 1].adi, tatli[i - 1].fiyati, "<=====================\n\n");
        Sleep(100);
    }

    cerceve();

    if (n)
    {
        echo("\n\nadmin yemek guncelleme fonksiyonu");
        //admin yemek guncelleme fonksiyonu
    }
    else
    {
        tatliSecimVeFiyatlandirma(pTatli, n);
    }
}

void tatliSecimVeFiyatlandirma(struct tatlilarBilgi *pTatli, int n)
{
hataliTuslama:
    echo("\n\n");

    int tatli_secim = secimFonksiyonu();
    switch (tatli_secim)
    {
    case 0:
        echo("Tatli tercih etmediniz\n");
        echo("Icecek sayfasina yonlendiriliyorsunuz...");
        Sleep(800);
        icecekler(n);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, pTatli[0].fiyati);
        icecekler(n);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, pTatli[1].fiyati);
        icecekler(n);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, pTatli[2].fiyati);
        icecekler(n);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, pTatli[3].fiyati);
        icecekler(n);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, pTatli[4].fiyati);
        icecekler(n);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, pTatli[5].fiyati);
        icecekler(n);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, pTatli[6].fiyati);
        icecekler(n);
        break;

    case 8:
        siparisDetaylari(&toplamTutar, pTatli[7].fiyati);
        icecekler(n);
        break;

    case 9:
        siparisDetaylari(&toplamTutar, pTatli[8].fiyati);
        icecekler(n);
        break;

    default:
        cls();
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }
}

void siparis_menu(int siparis, int miktar, int sip_kodu)
{
    system("color 3E");

    test *gecici;

    gecici = liste;

    while (gecici->veri != siparis)
    {
        gecici = gecici->sonraki;
    }

    if (gecici->veri == siparis)
    {
        system("color 3E");

        printf("\n\t\t");
        system("color 0A");
        printf("\xdb     %d      \xdb    %s  \xdb     %d     \xdb     %d     \xdb", sip_kodu, gecici->yemekAdi, miktar, gecici->miktar);
        system("color 3E");
        printf("\n\t\t");
        int i;

        for (i = 0; i < 65; i++)
        {
            putchar('=');
        }
        Sleep(50);
    }
    system("color 3E");
}

void cerceve()
{
    // Alt Ã§erÃ§evenin yazdÄ±rÄ±lmasÄ±
    printf("\n\t\t\t\t\t\t");
    int i;
    for (i = 0; i < 80; i++)
    {
        putchar('=');
    }
}

void karsilama()
{
    system("color 2E");
    int i;
    char hosgeldin[50] = "MARMARA KEBAP SALONUNA HOS GELDINIZ";
    satir_bas(16);
    tab_bas(6);

    for (i = 0; i < strlen(hosgeldin); i++)
    {
        system("color 2E");

        printf(" %c", hosgeldin[i]);
        Sleep(25);
    }

    system("color 2E");
    printf("\n\n\t\t\t\t ");

    Sleep(250);
}

void ilerleme(void)
{
    int i;
    for (i = 15; i <= 100; i += 20)
    {
        cls();
        system("color 3E");
        satir_bas(15);
        tab_bas(9);
        bosluk_bas(4);

        printf("%d Yukleniyor... %%", i);

        satir_bas(2);
        tab_bas(7);
        bosluk_bas(4);

        printf("");
        int j;
        for (j = 0; j < i; j += 2)
        {
            printf("\xdb");
            system("color 3E");
        }
        Sleep(10);

        if (i == 90 || i == 50 || i == 96 || i == 35)
        {
            Sleep(25);
        }
    }
}

void musteriEkleme()
{
    system("color 3E");
    printf("\n\t\t");
    system("color 3E");
    bosluk_bas(1);
    tab_bas(4);
    cls();

    int i = 0;

    FILE *musteriKayitlari = fopen("musteriKayitlari.txt", "a"); //dosya acildi.

    struct musteriBilgileri musteriEkleme[musteriSayisi];
    struct krediKartiBilgileri kredikart[musteriSayisi];
    struct musteriAdresi adres[musteriSayisi];

    if (musteriKayitlari == NULL)
    {
        fprintf(stderr, "Dosyalama isleminde bir sorun olustu...");
    }

    echo("\t\t==> [0].Ana Menu\n");
    echo("\t\t==>Kayit olmak icin herhangi bir sayiya basmaniz yeterlidir:\n");

    int musteriEklemeSecim = secimFonksiyonu();

    if (musteriEklemeSecim == 0)
    {
        ana_menu();
    }

    //!asagidaki degiskenler alinan bilgilerin gecici olarak tutulmasi icin olusturuldu..
    char musteriIsmi[30];
    char musteriSoyismi[30];
    //   char musteriSifre[15];
    char kartNumarasi[16];
    char kartSahibiAdi[50]; //bitisikYazilmali...
    char gecerlilikTarihi[40];
    char guvenlikKodu[10];
    char sehir[25];
    char ilce[25];
    char semt[25];
    char sokak[25];
    char daireNo[25];

    do //2 ornek olsun diye.
    {

        echo("\n\t\t--Uyelik olusturmak icin lutfen bilgilerinizi giriniz.--\n");
        echo("\n- Adiniz:");
        scanf("%s", &musteriIsmi);
        echo("- Soyadiniz:");
        scanf("%s", &musteriSoyismi);
        echo("- Hesabiniz icin sifre(sayisal) olusturunuz:");
        scanf("%d", &musteriEkleme[i].musteriSifre);
        echo("- Hesabiniz icin ID(sayisal) olusturunuz:");
        scanf("%d", &musteriEkleme[i].musteriId);
        echo("- Kredi karti numaraniz:");
        scanf("%s", &kartNumarasi);
        echo("- Kredi karti sahibi adi ve soyadi (bitisik yazilmalidir!!): ");
        scanf("%s", &kartSahibiAdi);
        echo("- Kredi karti son gecerlilik tarihi (ay ve yil bitisik yazilmalidir!!): ");
        scanf("%s", &gecerlilikTarihi);
        echo("- Kredi karti guvenlik numaraniz: ");
        scanf("%s", &guvenlikKodu);
        echo("- Evinizin bulundugu sehir:");
        scanf("%s", &sehir);
        echo("- Ilce: ");
        scanf("%s", &ilce);
        echo("- Mahalle: ");
        scanf("%s", &semt);
        echo("- Sokak: ");
        scanf("%s", &sokak);
        echo("- Ev NO: ");
        scanf("%s", &daireNo);

        //!Burada girilen bilgilerin uzunlugu kadar bellekte alan acildi..
        musteriEkleme[i].musteriIsmi = (char *)malloc(sizeof(char) * strlen(musteriIsmi));
        musteriEkleme[i].musteriSoyismi = (char *)malloc(sizeof(char) * strlen(musteriSoyismi));
        //    musteriEkleme[i].musteriSifre = (char *)malloc(sizeof(char) * strlen(musteriSifre));
        kredikart[i].kartNumarasi = (char *)malloc(sizeof(char) * strlen(kartNumarasi));
        kredikart[i].kartSahibiAdi = (char *)malloc(sizeof(char) * strlen(kartSahibiAdi));
        kredikart[i].gecerlilikTarihi = (char *)malloc(sizeof(char) * strlen(gecerlilikTarihi));
        kredikart[i].guvenlikKodu = (char *)malloc(sizeof(char) * strlen(guvenlikKodu));
        adres[i].sehir = (char *)malloc(sizeof(char) * strlen(sehir));
        adres[i].ilce = (char *)malloc(sizeof(char) * strlen(ilce));
        adres[i].semt = (char *)malloc(sizeof(char) * strlen(semt));
        adres[i].sokak = (char *)malloc(sizeof(char) * strlen(sokak));
        adres[i].daireNo = (char *)malloc(sizeof(char) * strlen(daireNo));

        //!burada alinan bilgiler structlara kopyalandi...
        strcpy(musteriEkleme[i].musteriIsmi, musteriIsmi);
        strcpy(musteriEkleme[i].musteriSoyismi, musteriSoyismi);
        //   strcpy(musteriEkleme[i].musteriSifre, musteriSifre);
        strcpy(kredikart[i].kartNumarasi, kartNumarasi);
        strcpy(kredikart[i].kartSahibiAdi, kartSahibiAdi);
        strcpy(kredikart[i].gecerlilikTarihi, gecerlilikTarihi);
        strcpy(kredikart[i].guvenlikKodu, guvenlikKodu);
        strcpy(adres[i].sehir, sehir);
        strcpy(adres[i].ilce, ilce);
        strcpy(adres[i].semt, semt);
        strcpy(adres[i].sokak, sokak);
        strcpy(adres[i].daireNo, daireNo);

        //!Dosyaya yazdirma islemleri yapildi.
        fprintf(musteriKayitlari, "-Ad: %s\t-Soyad: %s\t-Sifre: %d\n", musteriEkleme[i].musteriIsmi, musteriEkleme[i].musteriSoyismi,
                musteriEkleme[i].musteriSifre);
        fprintf(musteriKayitlari, "-ID kodunuz: %d\n", musteriEkleme[i].musteriId);
        fprintf(musteriKayitlari, "-Kart Numarasi: %s\t-Kart Uzerindeki Isim: %s\n", kredikart[i].kartNumarasi, kredikart[i].kartSahibiAdi);
        fprintf(musteriKayitlari, "-Gecerlilik Tarihi: %s\t-Guvenlik Kodu: %s\n", kredikart[i].gecerlilikTarihi, kredikart[i].guvenlikKodu);
        fprintf(musteriKayitlari, "-Sehir: %s\t%-Ilce: %s\t-Mahalle: %s\n", adres[i].sehir, adres[i].ilce, adres[i].semt);
        fprintf(musteriKayitlari, "-Sokak: %s\t-Ev No: %s\n", adres[i].sokak, adres[i].daireNo);

        fprintf(musteriKayitlari, "============================================================================\n");
    } while (i == -1);
    i++;
    echo("Basariyla yeni musteri kaydi olusturulmustur...\n\n");
    Sleep(250);
    fclose(musteriKayitlari);
    echo("Anasayfaya yonlendiriliyorsunuz...\n\n");
    Sleep(1000);
    ana_menu();
}

void musteriKayitlariniGoruntule()
{
    system("color 3E");
    printf("\n\t\t");
    system("color 2E");
    bosluk_bas(1);
    tab_bas(5);
    cls();

    int i;

    FILE *musteriEkranaYazdirma = fopen("musteriKayitlari.txt", "r");

    char *karakter, satir[200]; //! dosyadan okunan karakterler satirda tutuldu sonra karakter ile ekrana yazdirildi...

    printf("\t\t==> [0].Ana Menu\n");
    printf("\t\t==>[1].Kullanici Bilgileri Goruntule\n");

    int musteriEklemeSecim = secimFonksiyonu();
    if (musteriEklemeSecim == 0)
    {
        ana_menu();
    }

    if (musteriEkranaYazdirma == NULL)
    {
        fprintf(stderr, "Dosyalari okurken bir hata meydana geldi...");
    }

    do
    {
        tab_bas(2);
        karakter = fgets(satir, 200, musteriEkranaYazdirma); //!satir satir bilgi okundu...
        if (karakter != NULL)
        {
            printf("%s", satir);
        }
    } while (karakter != NULL);

    printf("\t\t Kayit olan tum kullanicilar goruntulenmektedir..\n");
    printf("\t\t Ana Menuye yonlendiriliyorsunuz..");
    Sleep(10000);
    ana_menu();
}

void uygulamayiKapat()
{
    cls();
    satir_bas(10);
    cerceve();
    satir_bas(2);
    tab_bas(7);
    puts("Yine bekleriz!!\n\n");
    Sleep(200);
    tab_bas(7);
    puts("Program kapatiliyor...\n");
    cerceve();
    Sleep(800);
    exit(1);
}

void gecersizGiris()
{
    cls();
    puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
    Sleep(1000);
    ana_menu();
}

//Gerekli if yerlerinde kullanÄ±lmak uzere secim icin fonksiyon
int secimFonksiyonu()
{
    int secim;
    echo("==> ");
    scanf("%d", &secim);
    return secim;
}

float siparisDetaylari(float *fiyatToplam, float tekFiyat)
{
    float istenenSayi = 0;
    float toplamFiyat = 0;
    echo("Kac tane/porsiyon istersiniz?\n");
    echo("==> ");
    scanf("%f", &istenenSayi);
    *fiyatToplam += istenenSayi * tekFiyat;
    printf("Aldiklariniz %.2f TL tutmustur.\n", *fiyatToplam);
    Sleep(1000);
    echo("Siparisiniz hazirlaniyor. Diger sayfaya yonlendiriliyorsunuz...");
    Sleep(800);
}

// Console tam ekran yapÄ±lÄ±yor
void tamEkran(void)
{
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_SHOWMAXIMIZED);
}
