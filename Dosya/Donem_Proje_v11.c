#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
//#include <unistd.h>
#define musteriSayisi 100

// kullanilan degiskenler..
int kartNo[100];
int fisIslemSayaci = 0;
float karttakiPara[100];
float kasadakiPara;
float toplamTutar = 0.0;
int siparisNumarasi = 0;
unsigned int toplamSiparis[100];
unsigned int siparisMiktari[100];
unsigned int siparis = 0;
short satir, kolon;

// Structlarin tanimi
struct musteriBilgileri
{
    char musteriIsmi[25];
    char musteriSoyismi[25];
    char musteriEMail[50];
    char musteriSifre[25];
    int musteriId;

    char sehir[20];
    char ilce[20];
    char semt[20];
    char sokak[45];
    char apartmanIsmi[10];
    char daireNo[10];

    char kartNumarasi[16];
    char gecerlilikTarihi[4]; // tarih ay/yil seklinde
    char kartSahibiAdi[50];
    char guvenlikKodu[3];

    float musteriHesapbakiyesi;
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

struct corbalarBilgi
{
    char adi[20];
    int malzemeAdedi;
    float fiyati;
};

struct evYemekleriBilgi
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

struct baliklarBilgi
{
    char adi[20];
    int malzemeAdedi;
    float fiyati;
};

struct salatalarBilgi
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

struct menuBilgi
{
    struct iceceklerBilgi icecekler;
    struct kebaplarBilgi kebap;
    struct donerlerBilgi doner;
    struct hamburgerlerBilgi hamburger;
    struct corbalarBilgi corba;
    struct evYemekleriBilgi evYemekleri;
    struct pizzalarBilgi pizza;
    struct pidelerBilgi pide;
    struct baliklarBilgi balik;
    struct salatalarBilgi salata;
    struct tatlilarBilgi tatli;
};
struct menuBilgi Yemek_Menu;

//Structlar - fonksiyon // Yemek Secimi
void kebapSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n);
void kebapBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac);

void donerSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n);
void donerBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac);

void hamburgerSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n);
void hamburgerBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac);

void corbaSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n);
void corbaBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac);

void evYemekleriSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n);
void evYemekleriBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac);

void pizzaSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n);
void pizzaBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac);

void pideSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n);
void pideBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac);

void balikSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n);
void balikBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac);

void salataSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n);
void salataBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac);

void tatliSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n);
void tatliBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac);

void icecekSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n);
void icecekBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac);

void icecekBilgisiCek(struct menuBilgi *x);
void kebapBilgisiCek(struct menuBilgi *x);
void donerBilgisiCek(struct menuBilgi *x);
void hamburgerBilgisiCek(struct menuBilgi *x);
void corbaBilgisiCek(struct menuBilgi *x);
void evYemekleriBilgisiCek(struct menuBilgi *x);
void pizzaBilgisiCek(struct menuBilgi *x);
void pideBilgisiCek(struct menuBilgi *x);
void balikBilgisiCek(struct menuBilgi *x);
void salataBilgisiCek(struct menuBilgi *x);
void tatliBilgisiCek(struct menuBilgi *x);
void yemekBilgisiCek(struct menuBilgi *x);

// Ekleme ve guncelleme Fonksiyonlari
void yemek_ekle(int veri, char yemekAdi[25], int miktar, float fiyat);
void fiyat_guncelle();
void musteriBilgileriGoruntule();
void onlineOdeme();
void odemeYontemi();
void kapidaOdeme();
void siparisBilgileriGoruntule();

//!
//Todo:
void yeniMusteriOlustur(struct musteriBilgileri *y, struct menuBilgi *x);
void kayitliMusteriKontrol(struct musteriBilgileri *y, struct menuBilgi *x);
void mBilgiCek(struct musteriBilgileri *y);
void mGirisiBilgisiCek(struct musteriBilgileri *y);
//Todo:
//!

// islev fonksiyonlari
void siparisDetaylari(float *fiyatToplam, float tekFiyat, char isim[], int fisIslemSayaci);
int kasaBilgiOku();
void kasaBilgiYaz(int toplam);
int randomId();

// Menu fonksiyonlari
void yemek_listesi(struct musteriBilgileri *y, int n, struct menuBilgi *x);
void admin_menu(struct musteriBilgileri *y, struct menuBilgi *x);
void kayitliMusteriMenu(struct musteriBilgileri *y, struct menuBilgi *x);
void musteriGirisiMenu(struct musteriBilgileri *y, struct menuBilgi *x);
void siparis_menu(int siparis, int miktar, int sip_kodu, struct menuBilgi *x);
void ana_menu(struct musteriBilgileri *y, struct menuBilgi *x);
void uygulamayiKapat();
void gecersizGiris();
int secimFonksiyonu();
void hakkimizdaGoruntule(struct musteriBilgileri *y, struct menuBilgi *x);

// Alt menu fonksiyonlari
void kebap();
void doner();
void corba();
void evYemekleri();
void balik();
void pizza();
void pide();
void hamburger();
void salata();
void tatli();
void icecekler();

// Tasarim fonksiyonlari
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
void zamanGoster();

int main()
{
    tamEkran(); // Konsol ekranini tam ekran seklinde donusturme
    struct musteriBilgileri musteri[musteriSayisi];
    system("title Marmara Kebap House");

    struct menuBilgi *ptrYemek_Menu;
    ptrYemek_Menu = (struct menuBilgi *)malloc(100 * sizeof(struct menuBilgi));
    yemekBilgisiCek(ptrYemek_Menu);

    //!
    //TODO:
    struct musteriBilgileri *ptrMusteriBilgi;
    ptrMusteriBilgi = (struct musteriBilgileri *)malloc(100 * sizeof(struct musteriBilgileri));
    mGirisiBilgisiCek(ptrMusteriBilgi);
    mBilgiCek(ptrMusteriBilgi);

    //TODO:
    //!
    /*
    ilerleme();
    cls();
    karsilama();
    cls();
*/
    ana_menu(ptrMusteriBilgi, ptrYemek_Menu);
}

void ana_menu(struct musteriBilgileri *y, struct menuBilgi *x)
{
    cls();
    int i, n = 0;
    char anaMenuListesi[4][20] = {"Musteri Girisi", "Admin Girisi", "Hakkimizda", "Cikis"};
    tab_bas(12);
    echo("     MARMARA KEBAP HOUSE");
    zamanGoster();
    cerceve();
    satir_bas(1);
    tab_bas(13);
    echo("  (Anamenu)");
    satir_bas(12);

    for (i = 0; i < 4; i++)
    {
        satir_bas(2);
        tab_bas(12);
        printf("==>  [%d]. %s\n\n", i + 1, anaMenuListesi[i]);
        Sleep(100);
    }
    satir_bas(2);
    int anaSecim = secimFonksiyonu();
    switch (anaSecim)
    {
    case 1:
        musteriGirisiMenu(y, x);
        break;

    case 2:
        admin_menu(y, x);
        break;

    case 3:
        hakkimizdaGoruntule(y, x);
        break;

    case 4:
        uygulamayiKapat();

    default:
        gecersizGiris(y, x);
        break;
    }
}

//!
//TODO

void musteriGirisiMenu(struct musteriBilgileri *y, struct menuBilgi *x)
{
    int i;
    char musteriMenuListesi[2][25] = {"Yeni Musteri", "Kayitli Musteri"};
    menuRenk();
    tab_bas(12);
    echo("     MARMARA KEBAP HOUSE");
    zamanGoster();
    cerceve();
    satir_bas(1);
    tab_bas(12);
    echo("   (Musteri Giris Ekrani)");
    satir_bas(12);

    for (i = 0; i < 2; i++)
    {
        satir_bas(2);
        tab_bas(12);
        printf("==>  [%d]. %s\n\n", i + 1, musteriMenuListesi[i]);
        Sleep(100);
    }
    satir_bas(2);
    int musteriSecim = secimFonksiyonu();
    switch (musteriSecim)
    {
    case 0:
        ana_menu(y, x);
        break;
    case 1:
        yeniMusteriOlustur(y, x);
        break;

    case 2:
        kayitliMusteriKontrol(y, x);
        break;

    default:
        gecersizGiris(y, x);
        break;
    }
}

void yeniMusteriOlustur(struct musteriBilgileri *y, struct menuBilgi *x)
{
    int musteriID = 0, satirSayac = 0; //musteri ID numarası satir sayisi ile esitlenmelidir.
    char c;

    FILE *fpp;
    fpp = fopen("musteriGirisiBilgisi.txt", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    musteriID = satirSayac + 2;

    menuRenk();
    tab_bas(12);
    echo("(Yeni Musteri)\n");
    Sleep(200);
    tab_bas(8);
    cerceve();
    Sleep(200);
    satir_bas(3);
    //musteriGirisiBilgisi.txt dosyasi islemleri yapilacak
    tab_bas(9);
    printf("E-posta:");
    scanf("%s", &(y + (musteriID - 1))->musteriEMail);
    satir_bas(1);
    tab_bas(9);
    printf("Sifre:");
    scanf("%s", &(y + (musteriID - 1))->musteriSifre);
    satir_bas(1);
    tab_bas(9);

    FILE *Fp = fopen("musteriGirisiBilgisi.txt", "a");
    if (Fp == NULL)
    {
        tab_bas(11);
        puts("!!! musteriGirisiBilgisi.txt Dosya olusturulamadi !!!\n");
        Sleep(500);
        exit(1);
    }
    else
    {
        fprintf(Fp, "\n%s %s %d", (y + (musteriID - 1))->musteriEMail, (y + (musteriID - 1))->musteriSifre, musteriID);
    }
    fclose(Fp);

    //echo("musteriBilgileri.txt dosyasi islemleri yapilacak.\n");

    echo("- Adiniz:");
    scanf("%s", &(y + (musteriID - 1))->musteriIsmi);
    satir_bas(1);
    tab_bas(9);
    echo("- Soyadiniz:");
    scanf("%s", &(y + (musteriID - 1))->musteriSoyismi);
    satir_bas(1);
    tab_bas(9);
    echo("- Evinizin bulundugu sehir:");
    scanf("%s", &(y + (musteriID - 1))->sehir);
    satir_bas(1);
    tab_bas(9);
    echo("- Ilce: ");
    scanf("%s", &(y + (musteriID - 1))->ilce);
    satir_bas(1);
    tab_bas(9);
    echo("- Mahalle: ");
    scanf("%s", &(y + (musteriID - 1))->semt);
    satir_bas(1);
    tab_bas(9);
    echo("- Sokak: ");
    scanf("%s", &(y + (musteriID - 1))->sokak);
    satir_bas(1);
    tab_bas(9);
    echo("- Apartman ismi:");
    scanf("%s", &(y + (musteriID - 1))->apartmanIsmi);
    satir_bas(1);
    tab_bas(9);
    echo("- Daire NO: ");
    scanf("%s", &(y + (musteriID - 1))->daireNo);
    satir_bas(1);
    tab_bas(10);

    FILE *Fpk = fopen("musteriBilgileri.txt", "a");
    if (Fpk == NULL)
    {
        tab_bas(11);
        puts("!!! musteriBilgileri.txt Dosya olusturulamadi !!!\n");
        Sleep(500);
        exit(1);
    }
    else
    {
        fprintf(Fpk, "\n%s %s %s %s %s %s %s %s", (y + (musteriID - 1))->musteriIsmi,
                (y + (musteriID - 1))->musteriSoyismi, (y + (musteriID - 1))->sehir,
                (y + (musteriID - 1))->ilce, (y + (musteriID - 1))->semt, (y + (musteriID - 1))->sokak,
                (y + (musteriID - 1))->apartmanIsmi, (y + (musteriID - 1))->daireNo);
    }
    fclose(Fpk);

    Sleep(300);
    echo("Basariyla kayit olusturulmustur.\n");
    tab_bas(10);
    echo("Tekrar giris yaparak siparis verebilirsiniz.\n");
    satir_bas(1);
    cerceve();
    getch();
    ana_menu(y, x);
}

void kayitliMusteriKontrol(struct musteriBilgileri *y, struct menuBilgi *x)
{
    menuRenk();
    echo("Kayitli musteri kontrol isleme gerceklesti\n");
    Sleep(1000);
    echo("Esleme islemi gerceklestigi icin: kayitliMusteriMenu aktariliyor.\n");
    Sleep(1000);
    getch();
    if (1) //Esleme gerceklesirse
    {
        kayitliMusteriMenu(y, x);
    }
    else
    {
        gecersizGiris(y, x);
    }
}

void kayitliMusteriMenu(struct musteriBilgileri *y, struct menuBilgi *x)
{
    int i, n = 0;
    char kayitliMusteriMenuListesi[2][30] = {"Siparis Ver", "Bilgilerimi Goruntule"};
hataliTuslama:
geriDon:

    menuRenk();

    tab_bas(12);
    echo("     MARMARA KEBAP HOUSE");
    zamanGoster();
    cerceve();
    satir_bas(1);
    tab_bas(12);
    echo("  (Kayitli Musteri Menusu)");
    satir_bas(12);

    for (i = 0; i < 2; i++)
    {
        satir_bas(2);
        tab_bas(12);
        printf("==>  [%d]. %s\n\n", i + 1, kayitliMusteriMenuListesi[i]);
        Sleep(100);
    }
    satir_bas(2);
    int kayitliMusteriSecim = secimFonksiyonu();
    switch (kayitliMusteriSecim)
    {
    case 0:
        ana_menu(y, x);
        break;
    case 1:
        yemek_listesi(y, n, x);
        break;
    case 2:
        echo("kullaniciye ait olan bireysel bilgi gozukecek.\n");
        echo("tusa basarak kendi sayfaniza donebilirsiniz.\n");
        getch();
        goto geriDon;
        break;
    default:
        cls();
        satir_bas(10);
        tab_bas(11);
        echo("   Gecersiz giris yaptiniz !!");
        Sleep(900);
        goto hataliTuslama;
        break;
    }
}

void mGirisiBilgisiCek(struct musteriBilgileri *y)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("musteriGirisiBilgisi.txt", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s %s %d", &(y + i)->musteriEMail, &(y + i)->musteriSifre, &(y + i)->musteriId);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!!  musteriGirisiBilgisi.txt Bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void mBilgiCek(struct musteriBilgileri *y)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("musteriBilgileri.txt", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s %s %s %s", &(y + i)->musteriIsmi, &(y + i)->musteriSoyismi, &(y + i)->sehir, &(y + i)->ilce, &(y + i)->semt, &(y + i)->sokak, &(y + i)->apartmanIsmi, &(y + i)->daireNo);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! musteriBilgileri.txt Bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

//!
//Todo:

void admin_menu(struct musteriBilgileri *y, struct menuBilgi *x)
{
    menuRenk();
    echo("\n\nSifrenizi girin: ");
    int adminSecim = secimFonksiyonu();

    if (adminSecim == 0)
    {
        ana_menu(y, x);
    }

    else if (adminSecim != 12345)
    {
        cls();
        bosluk_bas(5);
        tab_bas(9);
        echo("Giris yaparken hatali tuslama yaptiniz...\n\n");
        Sleep(1000);
        ana_menu(y, x);
    }

    else if (adminSecim == 12345)
    {
        cls();
        satir_bas(10);
        tab_bas(12);
        echo("Basariyla Giris Yaptiniz...");
        Sleep(1000);

    admin:
        cls();

        int i;
        char adminMenuListesi[5][40] = {"Ana Menuye Don", "Gunluk Butce", "Musteri Bilgileri", "Siparis Bilgileri", "Yemekleri Guncelle"};
        satir_bas(2);
        tab_bas(12);
        echo("      (Admin Menu)");
        cerceve();
        satir_bas(7);
        for (i = 0; i < 5; i++)
        {
            satir_bas(2);
            tab_bas(12);
            printf("==>  [%d]. %s\n\n", i, adminMenuListesi[i]);
            Sleep(100);
        }

        int adminSecim = secimFonksiyonu();
        switch (adminSecim)
        {
        case 0:
            ana_menu(y, x);
            break;

        case 1:
            kasadakiPara = kasaBilgiOku();
            cls();
            satir_bas(10);
            cerceve();
            satir_bas(2);
            tab_bas(11);
            printf("Kasaya giren toplam para : %.2f ", kasadakiPara);
            satir_bas(3);
            cerceve();
            getchar();
            Sleep(3000);
            goto admin;
            break;

        case 2:
            cls();
            musteriBilgileriGoruntule(y, x);
            goto admin;
            break;

        case 3:
            cls();
            //!bu fonksiyon yazilip ,siparis verilen yemekler admin->siparisler kisminda fiyatla birlikte goruntulenmesi gerekmektedir.
            siparisBilgileriGoruntule(y, x);
            goto admin;
            break;

        case 4:
            cls();
            int n;
            yemek_listesi(y, n, x);
            getchar();
            Sleep(3000);
            goto admin;
            break;

        default:
            cls();
            satir_bas(1);
            tab_bas(11);
            puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
            goto admin;
            break;
        }
    }
}

void yemek_listesi(struct musteriBilgileri *y, int n, struct menuBilgi *x)
{
    int i;
    char yemekListesi[11][15] = {"Kebaplar", "Donerler", "Hamburgerler", "Corbalar", "Ev Yemekleri",
                                 "Pizzalar", "Pideler", "Baliklar", "Salatalar", "Tatlilar", "Icecekler"};
    menuRenk();

    tab_bas(12);
    echo("   (Yemek Listesi)");
    cerceve();
    satir_bas(8);
    for (i = 0; i < 11; i++)
    {
        bosluk_bas(1);
        tab_bas(12);
        Sleep(100);
        printf("==>  [%d]. %s\n\n", i + 1, yemekListesi[i]);
    }
    Sleep(100);

    int listeSecim = secimFonksiyonu();

    switch (listeSecim)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        kebap(y, n, x);
        break;

    case 2:
        doner(y, n, x);
        break;

    case 3:
        hamburger(y, n, x);
        break;

    case 4:
        corba(y, n, x);
        break;

    case 5:
        evYemekleri(y, n, x);
        break;

    case 6:
        pizza(y, n, x);
        break;

    case 7:
        pide(y, n, x);
        break;

    case 8:
        balik(y, n, x);
        break;

    case 9:
        salata(y, n, x);
        break;

    case 10:
        tatli(y, n, x);
        break;

    case 11:
        icecekler(y, n, x);
        break;

    default:
        gecersizGiris(y, x);
        break;
    }
}

void icecekler(struct musteriBilgileri *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("icecekler.txt", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(13);
    echo("Icecek Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i < satirSayac; ++i) //!   '<=' kismindaki  '=' silindi sikinti olmasi halinde buraya bakilmali
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("===========================>   [%d].%14s: %7.2f%25s   ", i + 1, (x + i)->icecekler.adi, (x + i)->icecekler.fiyati, "    <==========================\n\n");
        Sleep(100);
    }
    cerceve();

    if (n)
    {
        icecekBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        icecekSecimVeFiyatlandirma(y, x, n);
    }
}

void icecekSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n)
{
    FILE *Fp = fopen("kasadakiPara.txt", "a");
    if (Fp == NULL)
    {
        tab_bas(8);
        puts(" kasadakiPara.txt Dosya olusturulamadi.\n");
        Sleep(300);
        exit(1);
    }
    fclose(Fp);
    echo("\n");
    fisIslemSayaci = 3;
    int icecek_secim = secimFonksiyonu();
    switch (icecek_secim)
    {
    case 0:
        tab_bas(8);
        echo("Icecek istemediginizden emin misiniz? Evet 1 / Hayir 0 \n");
        int tercih = secimFonksiyonu();
        if (tercih)
        {
            tab_bas(8);
            printf("Aldiklariniz %.2f TL tutmustur.\n", toplamTutar);
            tab_bas(8);
            echo("Siparisiniz hazirlaniyor. Odeme Ekranina yonlendiriliyorsunuz...");
            Sleep(1100);
            kasadakiPara = kasaBilgiOku(); //kasadakiPara dosyadan okunuyor son yazan bakiye kasadakiPara degiskenine atiliyor
            kasadakiPara += toplamTutar;   //islem gerceklesti
            kasaBilgiYaz(kasadakiPara);    //kasadakiPara degiskenindeki deger dosyaya yaziliyor
            toplamTutar = 0;
            odemeYontemi(y, x);
        }
        else
        {
            icecekler(y, n, x);
        }
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->icecekler.fiyati, (x + 0)->icecekler.adi, fisIslemSayaci);
        kasadakiPara = kasaBilgiOku(); //kasadakiPara dosyadan okunuyor son yazan bakiye kasadakiPara degiskenine atiliyor
        kasadakiPara += toplamTutar;   //islem gerceklesti
        kasaBilgiYaz(kasadakiPara);    //kasadakiPara degiskenindeki deger dosyaya yaziliyor
        toplamTutar = 0;
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->icecekler.fiyati, (x + 1)->icecekler.adi, fisIslemSayaci);
        kasadakiPara = kasaBilgiOku();
        kasadakiPara += toplamTutar;
        kasaBilgiYaz(kasadakiPara);
        toplamTutar = 0;
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->icecekler.fiyati, (x + 2)->icecekler.adi, fisIslemSayaci);
        kasadakiPara = kasaBilgiOku();
        kasadakiPara += toplamTutar;
        kasaBilgiYaz(kasadakiPara);
        toplamTutar = 0;
        break;

    case 4:
        siparisDetaylari(&toplamTutar, (x + 3)->icecekler.fiyati, (x + 3)->icecekler.adi, fisIslemSayaci);
        kasadakiPara = kasaBilgiOku();
        kasadakiPara += toplamTutar;
        kasaBilgiYaz(kasadakiPara);
        toplamTutar = 0;
        break;

    case 5:
        siparisDetaylari(&toplamTutar, (x + 4)->icecekler.fiyati, (x + 4)->icecekler.adi, fisIslemSayaci);
        kasadakiPara = kasaBilgiOku();
        kasadakiPara += toplamTutar;
        kasaBilgiYaz(kasadakiPara);
        toplamTutar = 0;
        break;

    case 6:
        siparisDetaylari(&toplamTutar, (x + 5)->icecekler.fiyati, (x + 5)->icecekler.adi, fisIslemSayaci);
        kasadakiPara = kasaBilgiOku();
        kasadakiPara += toplamTutar;
        kasaBilgiYaz(kasadakiPara);
        toplamTutar = 0;
        break;

    case 7:
        siparisDetaylari(&toplamTutar, (x + 6)->icecekler.fiyati, (x + 6)->icecekler.adi, fisIslemSayaci);
        kasadakiPara = kasaBilgiOku();
        kasadakiPara += toplamTutar;
        kasaBilgiYaz(kasadakiPara);
        toplamTutar = 0;
        break;
    default:
        cls();
        icecekler(y, n, x);
        break;
    }
    Sleep(1000);
    fisIslemSayaci = 0;
    odemeYontemi(y, x);
}

void icecekBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac)
{
    int icecekGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    icecekGuncelleme = secimFonksiyonu();
    satir_bas(3);
    switch (icecekGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        tab_bas(8);
        printf("%s iceceginin yeni fiyatini giriniz: ", x[0].icecekler.adi);
        scanf("%f", &x[0].icecekler.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Icecek yeni fiyati: %.2f", x[0].icecekler.fiyati);
        break;
    case 2:
        tab_bas(8);
        printf("%s iceceginin yeni fiyatini giriniz: ", x[1].icecekler.adi);
        scanf("%f", &x[1].icecekler.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Icecek yeni fiyati: %.2f", x[1].icecekler.fiyati);
        break;
    case 3:
        tab_bas(8);
        printf("%s iceceginin yeni fiyatini giriniz: ", x[2].icecekler.adi);
        scanf("%f", &x[2].icecekler.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Icecek yeni fiyati: %.2f", x[2].icecekler.fiyati);
        break;
    case 4:
        tab_bas(8);
        printf("%s iceceginin yeni fiyatini giriniz: ", x[3].icecekler.adi);
        scanf("%f", &x[3].icecekler.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Icecek yeni fiyati: %.2f", x[3].icecekler.fiyati);
        break;
    case 5:
        tab_bas(8);
        printf("%s iceceginin yeni fiyatini giriniz: ", x[4].icecekler.adi);
        scanf("%f", &x[4].icecekler.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Icecek yeni fiyati: %.2f", x[4].icecekler.fiyati);
        break;
    case 6:
        tab_bas(8);
        printf("%s iceceginin yeni fiyatini giriniz: ", x[5].icecekler.adi);
        scanf("%f", &x[5].icecekler.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Icecek yeni fiyati: %.2f", x[5].icecekler.fiyati);
        break;
    case 7:
        tab_bas(8);
        printf("%s iceceginin yeni fiyatini giriniz: ", x[6].icecekler.adi);
        scanf("%f", &x[6].icecekler.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Icecek yeni fiyati: %.2f", x[6].icecekler.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    //!? Degistirilen bilgilerin tekrar yeni bir dosya acilarak yazdirilmasi

    int i;
    FILE *fpp;
    fpp = fopen("icecekler.txt", "w");
    for (i = 0; i < satirSayac; i++)
    {
        fprintf(fpp, "\n%s %d %f", (x + i)->icecekler.adi, (x + i)->icecekler.stokAdedi, (x + i)->icecekler.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void kebap(struct musteriBilgileri *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("kebaplar.txt", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(13);
    echo("Kebap Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i <= satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=========================>     [%d].%14s: %7.2f%25s  ", i + 1, (x + i)->kebap.adi, (x + i)->kebap.fiyati, "     <=========================\n\n");
        Sleep(100);
    }
    cerceve();

    if (n)
    {
        kebapBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        kebapSecimVeFiyatlandirma(y, x, n);
    }
}

void kebapBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac)
{
    int kebapGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    kebapGuncelleme = secimFonksiyonu();

    switch (kebapGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[0].kebap.adi);
        scanf("%f", &x[0].kebap.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[0].kebap.fiyati);
        break;

    case 2:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[1].kebap.adi);
        scanf("%f", &x[1].kebap.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[1].kebap.fiyati);
        break;
    case 3:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[2].kebap.adi);
        scanf("%f", &x[2].kebap.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[2].kebap.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("kebaplar.txt", "w");

    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s %d %f", (x + i)->kebap.adi, (x + i)->kebap.malzemeAdedi, (x + i)->kebap.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void kebapSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n)
{
    echo("\n");
    int kebap_secim = secimFonksiyonu();

    switch (kebap_secim)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->kebap.fiyati, (x + 0)->kebap.adi, fisIslemSayaci); // 0
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->kebap.fiyati, (x + 1)->kebap.adi, fisIslemSayaci); // 0
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->kebap.fiyati, (x + 2)->kebap.adi, fisIslemSayaci); // 0
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    default:
        cls();
        gecersizGiris(y, x);
        break;
    }
}

void doner(struct musteriBilgileri *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("donerler.txt", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(13);
    echo("Doner Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i <= satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=========================>     [%d].%14s: %7.2f%25s  ", i + 1, (x + i)->doner.adi, (x + i)->doner.fiyati, "     <=========================\n\n");
        Sleep(100);
    }

    cerceve();

    if (n)
    {
        donerBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        donerSecimVeFiyatlandirma(y, x, n);
    }
}

void donerSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n)
{
    echo("\n");
    int doner_secim = secimFonksiyonu();

    switch (doner_secim)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->doner.fiyati, (x + 0)->doner.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->doner.fiyati, (x + 1)->doner.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->doner.fiyati, (x + 2)->doner.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;
    default:
        gecersizGiris(y, x);
        break;
    }
}

void donerBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac)
{
    int donerGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    donerGuncelleme = secimFonksiyonu();

    switch (donerGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[0].doner.adi);
        scanf("%f", &x[0].doner.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[0].doner.fiyati);
        break;

    case 2:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[1].doner.adi);
        scanf("%f", &x[1].doner.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[1].doner.fiyati);
        break;
    case 3:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[2].doner.adi);
        scanf("%f", &x[2].doner.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[2].doner.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("donerler.txt", "w");
    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s %d %f", (x + i)->doner.adi, (x + i)->doner.malzemeAdedi, (x + i)->doner.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void hamburger(struct musteriBilgileri *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("hamburgerler.txt", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(12);
    echo("    Hamburger Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i <= satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=========================>   [%d].%18s: %7.2f%25s  ", i + 1, (x + i)->hamburger.adi, (x + i)->hamburger.fiyati, "   <========================\n\n");
        Sleep(100);
    }
    cerceve();

    if (n)
    {
        hamburgerBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        hamburgerSecimVeFiyatlandirma(y, x, n);
    }
}

void hamburgerSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n)
{
    echo("\n");
    int hamburger_secim = secimFonksiyonu();

    switch (hamburger_secim)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->hamburger.fiyati, (x + 0)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->hamburger.fiyati, (x + 1)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->hamburger.fiyati, (x + 2)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, (x + 3)->hamburger.fiyati, (x + 3)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, (x + 4)->hamburger.fiyati, (x + 4)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, (x + 5)->hamburger.fiyati, (x + 5)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, (x + 6)->hamburger.fiyati, (x + 6)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 8:
        siparisDetaylari(&toplamTutar, (x + 7)->hamburger.fiyati, (x + 7)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 9:
        siparisDetaylari(&toplamTutar, (x + 8)->hamburger.fiyati, (x + 8)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 10:
        siparisDetaylari(&toplamTutar, (x + 9)->hamburger.fiyati, (x + 9)->hamburger.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;
    default:
        gecersizGiris(y, x);
        break;
    }
}

void hamburgerBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac)
{
    int hamburgerGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    hamburgerGuncelleme = secimFonksiyonu();

    switch (hamburgerGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[0].hamburger.adi);
        scanf("%f", &x[0].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[0].hamburger.fiyati);
        break;

    case 2:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[1].hamburger.adi);
        scanf("%f", &x[1].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[1].hamburger.fiyati);
        break;
    case 3:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[2].hamburger.adi);
        scanf("%f", &x[2].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[2].hamburger.fiyati);
        break;
    case 4:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[3].hamburger.adi);
        scanf("%f", &x[3].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[3].hamburger.fiyati);
        break;
    case 5:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[4].hamburger.adi);
        scanf("%f", &x[4].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[4].hamburger.fiyati);
        break;
    case 6:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[5].hamburger.adi);
        scanf("%f", &x[5].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[5].hamburger.fiyati);
        break;
    case 7:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[6].hamburger.adi);
        scanf("%f", &x[6].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[6].hamburger.fiyati);
        break;
    case 8:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[7].hamburger.adi);
        scanf("%f", &x[7].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[7].hamburger.fiyati);
        break;
    case 9:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[8].hamburger.adi);
        scanf("%f", &x[8].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[8].hamburger.fiyati);
        break;
    case 10:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[9].hamburger.adi);
        scanf("%f", &x[9].hamburger.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[9].hamburger.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("hamburgerler.txt", "w");
    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s %d %f", (x + i)->hamburger.adi, (x + i)->hamburger.malzemeAdedi, (x + i)->hamburger.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void corba(struct musteriBilgileri *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("corbalar.txt", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(13);
    echo("Corba Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i <= satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=========================>    [%d].%14s: %7.2f%25s  ", i + 1, (x + i)->corba.adi, (x + i)->corba.fiyati, "    <=========================\n\n");
        Sleep(100);
    }
    cerceve();

    if (n)
    {
        corbaBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        corbaSecimVeFiyatlandirma(y, x, n);
    }
}

void corbaSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n)
{
    echo("\n");
    int corba_secim = secimFonksiyonu();

    switch (corba_secim)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->corba.fiyati, (x + 0)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->corba.fiyati, (x + 1)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->corba.fiyati, (x + 2)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, (x + 3)->corba.fiyati, (x + 3)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, (x + 4)->corba.fiyati, (x + 4)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, (x + 5)->corba.fiyati, (x + 5)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, (x + 6)->corba.fiyati, (x + 6)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 8:
        siparisDetaylari(&toplamTutar, (x + 7)->corba.fiyati, (x + 7)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 9:
        siparisDetaylari(&toplamTutar, (x + 8)->corba.fiyati, (x + 8)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 10:
        siparisDetaylari(&toplamTutar, (x + 9)->corba.fiyati, (x + 9)->corba.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;
    default:
        gecersizGiris(y, x);
        break;
    }
}

void corbaBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac)
{
    int corbaGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    corbaGuncelleme = secimFonksiyonu();

    switch (corbaGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[0].corba.adi);
        scanf("%f", &x[0].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[0].corba.fiyati);
        break;

    case 2:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[1].corba.adi);
        scanf("%f", &x[1].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[1].corba.fiyati);
        break;
    case 3:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[2].corba.adi);
        scanf("%f", &x[2].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[2].corba.fiyati);
        break;
    case 4:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[3].corba.adi);
        scanf("%f", &x[3].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[3].corba.fiyati);
        break;
    case 5:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[4].corba.adi);
        scanf("%f", &x[4].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[4].corba.fiyati);
        break;
    case 6:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[5].corba.adi);
        scanf("%f", &x[5].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[5].corba.fiyati);
        break;
    case 7:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[6].corba.adi);
        scanf("%f", &x[6].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[6].corba.fiyati);
        break;
    case 8:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[7].corba.adi);
        scanf("%f", &x[7].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[7].corba.fiyati);
        break;
    case 9:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[8].corba.adi);
        scanf("%f", &x[8].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[8].corba.fiyati);
        break;
    case 10:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[9].corba.adi);
        scanf("%f", &x[9].corba.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[9].corba.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("corbalar.txt", "w");
    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s %d %f", (x + i)->corba.adi, (x + i)->corba.malzemeAdedi, (x + i)->corba.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void evYemekleri(struct musteriBilgileri *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("evyemekleri.txt", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(12);
    echo("   Ev Yemekleri Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i <= satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=========================> [%d].%20s: %7.2f%25s  ", i + 1, (x + i)->evYemekleri.adi, (x + i)->evYemekleri.fiyati, "  <=========================\n\n");
        Sleep(100);
    }
    cerceve();

    if (n)
    {
        evYemekleriBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        evYemekleriSecimVeFiyatlandirma(y, x, n);
    }
}

void evYemekleriSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n)
{
    echo("\n");
    int evYemekleri_secim = secimFonksiyonu();

    switch (evYemekleri_secim)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->evYemekleri.fiyati, (x + 0)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->evYemekleri.fiyati, (x + 1)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->evYemekleri.fiyati, (x + 2)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, (x + 3)->evYemekleri.fiyati, (x + 3)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, (x + 4)->evYemekleri.fiyati, (x + 4)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, (x + 5)->evYemekleri.fiyati, (x + 5)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, (x + 6)->evYemekleri.fiyati, (x + 6)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 8:
        siparisDetaylari(&toplamTutar, (x + 7)->evYemekleri.fiyati, (x + 7)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 9:
        siparisDetaylari(&toplamTutar, (x + 8)->evYemekleri.fiyati, (x + 8)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 10:
        siparisDetaylari(&toplamTutar, (x + 9)->evYemekleri.fiyati, (x + 9)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 11:
        siparisDetaylari(&toplamTutar, (x + 10)->evYemekleri.fiyati, (x + 10)->evYemekleri.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;
    default:
        gecersizGiris(y, x);
        break;
    }
}

void evYemekleriBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac)
{

    int evYemekleriGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    evYemekleriGuncelleme = secimFonksiyonu();

    switch (evYemekleriGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[0].evYemekleri.adi);
        scanf("%f", &x[0].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[0].evYemekleri.fiyati);
        break;
    case 2:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[1].evYemekleri.adi);
        scanf("%f", &x[1].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[1].evYemekleri.fiyati);
        break;
    case 3:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[2].evYemekleri.adi);
        scanf("%f", &x[2].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[2].evYemekleri.fiyati);
        break;
    case 4:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[3].evYemekleri.adi);
        scanf("%f", &x[3].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[3].evYemekleri.fiyati);
        break;
    case 5:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[4].evYemekleri.adi);
        scanf("%f", &x[4].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[4].evYemekleri.fiyati);
        break;
    case 6:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[5].evYemekleri.adi);
        scanf("%f", &x[5].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[5].evYemekleri.fiyati);
        break;
    case 7:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[6].evYemekleri.adi);
        scanf("%f", &x[6].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[6].evYemekleri.fiyati);
        break;
    case 8:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[7].evYemekleri.adi);
        scanf("%f", &x[7].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[7].evYemekleri.fiyati);
        break;
    case 9:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[8].evYemekleri.adi);
        scanf("%f", &x[8].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[8].evYemekleri.fiyati);
        break;
    case 10:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[9].evYemekleri.adi);
        scanf("%f", &x[9].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[9].evYemekleri.fiyati);
        break;
    case 11:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[10].evYemekleri.adi);
        scanf("%f", &x[10].evYemekleri.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[10].evYemekleri.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("evYemekleri.txt", "w");
    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s %d %f", (x + i)->evYemekleri.adi, (x + i)->evYemekleri.malzemeAdedi, (x + i)->evYemekleri.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void pizza(struct musteriBilgileri *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("pizzalar.txt", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(13);
    echo("Pizza Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i <= satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=========================>   [%d].%18s: %7.2f%25s  ", i + 1, (x + i)->pizza.adi, (x + i)->pizza.fiyati, "   <=========================\n\n");
        Sleep(100);
    }
    cerceve();

    if (n)
    {
        pizzaBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        pizzaSecimVeFiyatlandirma(y, x, n);
    }
}

void pizzaSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n)
{
    echo("\n");
    int pizza_secim = secimFonksiyonu();

    switch (pizza_secim)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->pizza.fiyati, (x + 0)->pizza.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->pizza.fiyati, (x + 1)->pizza.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->pizza.fiyati, (x + 2)->pizza.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, (x + 3)->pizza.fiyati, (x + 3)->pizza.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, (x + 4)->pizza.fiyati, (x + 4)->pizza.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, (x + 5)->pizza.fiyati, (x + 5)->pizza.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, (x + 6)->pizza.fiyati, (x + 6)->pizza.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;
    default:
        gecersizGiris(y, x);
        break;
    }
}

void pizzaBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac)
{

    int pizzaGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    pizzaGuncelleme = secimFonksiyonu();

    switch (pizzaGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[0].pizza.adi);
        scanf("%f", &x[0].pizza.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[0].pizza.fiyati);
        break;
    case 2:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[1].pizza.adi);
        scanf("%f", &x[1].pizza.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[1].pizza.fiyati);
        break;
    case 3:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[2].pizza.adi);
        scanf("%f", &x[2].pizza.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[2].pizza.fiyati);
        break;
    case 4:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[3].pizza.adi);
        scanf("%f", &x[3].pizza.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[3].pizza.fiyati);
        break;
    case 5:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[4].pizza.adi);
        scanf("%f", &x[4].pizza.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[4].pizza.fiyati);
        break;
    case 6:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[5].pizza.adi);
        scanf("%f", &x[5].pizza.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[5].pizza.fiyati);
        break;
    case 7:
        tab_bas(8);
        printf("%s yemeginin yeni fiyatini giriniz: ", x[6].pizza.adi);
        scanf("%f", &x[6].pizza.fiyati);
        satir_bas(1);
        tab_bas(8);
        printf("Yemeginin yeni fiyati: %.2f", x[6].pizza.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("pizzalar.txt", "w");
    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s %d %f", (x + i)->pizza.adi, (x + i)->pizza.malzemeAdedi, (x + i)->pizza.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}
//! Buradan guncelleme kisminin tasarimina devam et
void pide(struct musteriBilgileri *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("pideler.txt", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(13);
    echo("Pide Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i <= satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=======================>   [%d].%22s: %6.2f%25s  ", i + 1, (x + i)->pide.adi, (x + i)->pide.fiyati, "   <=======================\n\n");
        Sleep(100);
    }

    cerceve();

    if (n)
    {
        pideBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        pideSecimVeFiyatlandirma(y, x, n);
    }
}

void pideSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n)
{
    echo("\n");
    int pide_secim = secimFonksiyonu();

    switch (pide_secim)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->pide.fiyati, (x + 0)->pide.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->pide.fiyati, (x + 1)->pide.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->pide.fiyati, (x + 2)->pide.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, (x + 3)->pide.fiyati, (x + 3)->pide.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, (x + 4)->pide.fiyati, (x + 4)->pide.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, (x + 5)->pide.fiyati, (x + 5)->pide.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, (x + 6)->pide.fiyati, (x + 6)->pide.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;
    default:
        gecersizGiris(y, x);
        break;
    }
}

void pideBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac)
{

    int pideGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    pideGuncelleme = secimFonksiyonu();

    switch (pideGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[0].pide.adi);
        scanf("%f", &x[0].pide.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[0].pide.fiyati);
        break;
    case 2:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[1].pide.adi);
        scanf("%f", &x[1].pide.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[1].pide.fiyati);
        break;
    case 3:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[2].pide.adi);
        scanf("%f", &x[2].pide.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[2].pide.fiyati);
        break;
    case 4:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[3].pide.adi);
        scanf("%f", &x[3].pide.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[3].pide.fiyati);
        break;
    case 5:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[4].pide.adi);
        scanf("%f", &x[4].pide.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[4].pide.fiyati);
        break;
    case 6:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[5].pide.adi);
        scanf("%f", &x[5].pide.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[5].pide.fiyati);
        break;
    case 7:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[6].pide.adi);
        scanf("%f", &x[6].pide.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[6].pide.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("pideler.txt", "w");
    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s %d %f", (x + i)->pide.adi, (x + i)->pide.malzemeAdedi, (x + i)->pide.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void balik(struct musteriBilgileri *y, int n, struct menuBilgi *x)
{

    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("baliklar.txt", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(13);
    echo("Balik Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i <= satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=========================>    [%d].%14s: %8.2f%25s  ", i + 1, (x + i)->balik.adi, (x + i)->balik.fiyati, "     <=========================\n\n");
        Sleep(100);
    }

    cerceve();

    if (n)
    {
        balikBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        balikSecimVeFiyatlandirma(y, x, n);
    }
}

void balikSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n)
{
    echo("\n");

    int balik_secim = secimFonksiyonu();
    switch (balik_secim)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->balik.fiyati, (x + 0)->balik.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->balik.fiyati, (x + 1)->balik.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->balik.fiyati, (x + 2)->balik.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, (x + 3)->balik.fiyati, (x + 3)->balik.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, (x + 4)->balik.fiyati, (x + 4)->balik.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, (x + 5)->balik.fiyati, (x + 5)->balik.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, (x + 6)->balik.fiyati, (x + 6)->balik.adi, fisIslemSayaci);
        fisIslemSayaci++;
        salata(y, n, x);
        break;
    default:
        gecersizGiris(y, x);
        break;
    }
}

void balikBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac)
{
    int balikGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    balikGuncelleme = secimFonksiyonu();

    switch (balikGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[0].balik.adi);
        scanf("%f", &x[0].balik.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[0].balik.fiyati);
        break;
    case 2:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[1].balik.adi);
        scanf("%f", &x[1].balik.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[1].balik.fiyati);
        break;
    case 3:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[2].balik.adi);
        scanf("%f", &x[2].balik.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[2].balik.fiyati);
        break;
    case 4:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[3].balik.adi);
        scanf("%f", &x[3].balik.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[3].balik.fiyati);
        break;
    case 5:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[4].balik.adi);
        scanf("%f", &x[4].balik.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[4].balik.fiyati);
        break;
    case 6:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[5].balik.adi);
        scanf("%f", &x[5].balik.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[5].balik.fiyati);
        break;
    case 7:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[6].balik.adi);
        scanf("%f", &x[6].balik.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[6].balik.fiyati);
        break;
    default:
        cls();
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("baliklar.txt", "w");
    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s %d %f", (x + i)->balik.adi, (x + i)->balik.malzemeAdedi, (x + i)->balik.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void salata(struct musteriBilgileri *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("salatalar.txt", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(13);
    echo("Salata Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i <= satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=========================>     [%d].%12s: %7.2f%25s  ", i + 1, (x + i)->salata.adi, (x + i)->salata.fiyati, "       <=========================\n\n");
        Sleep(100);
    }

    cerceve();

    if (n)
    {
        salataBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        salataSecimVeFiyatlandirma(y, x, n);
    }
}

void salataSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n)
{
hataliTuslama:
    echo("\n");

    int salata_secim = secimFonksiyonu();
    switch (salata_secim)
    {
    case 0:
        tab_bas(8);
        echo("Salata tercih etmediniz\n");
        tab_bas(8);
        echo("Tatli sayfasina yonlendiriliyorsunuz...");
        Sleep(800);
        tatli(y, n, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->salata.fiyati, (x + 0)->salata.adi, fisIslemSayaci);
        fisIslemSayaci++; //2
        tatli(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->salata.fiyati, (x + 1)->salata.adi, fisIslemSayaci);
        fisIslemSayaci++;
        tatli(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->salata.fiyati, (x + 2)->salata.adi, fisIslemSayaci);
        fisIslemSayaci++;
        tatli(y, n, x);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, (x + 3)->salata.fiyati, (x + 3)->salata.adi, fisIslemSayaci);
        fisIslemSayaci++;
        tatli(y, n, x);
        break;
    default:
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }
}

void salataBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac)
{
    int salataGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    salataGuncelleme = secimFonksiyonu();

    switch (salataGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[0].salata.adi);
        scanf("%f", &x[0].salata.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[0].salata.fiyati);
        break;
    case 2:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[1].salata.adi);
        scanf("%f", &x[1].salata.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[1].salata.fiyati);
        break;
    case 3:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[2].salata.adi);
        scanf("%f", &x[2].salata.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[2].salata.fiyati);
        break;
    case 4:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[3].salata.adi);
        scanf("%f", &x[3].salata.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[3].salata.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        tab_bas(8);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz.");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("salatalar.txt", "w");
    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s %d %f", (x + i)->salata.adi, (x + i)->salata.malzemeAdedi, (x + i)->salata.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void tatli(struct musteriBilgileri *y, int n, struct menuBilgi *x)
{
    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("tatlilar.txt", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    menuRenk();
    tab_bas(13);
    echo("Tatli Menusu\n");
    cerceve();
    satir_bas(3);

    for (i = 0; i <= satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(8);

        printf("=========================>    [%d].%16s: %7.2f%25s  ", i + 1, (x + i)->tatli.adi, (x + i)->tatli.fiyati, "    <=========================\n\n");
        Sleep(100);
    }

    cerceve();

    if (n)
    {
        tatliBilgisiGuncelleme(y, x, satirSayac);
    }
    else
    {
        tatliSecimVeFiyatlandirma(y, x, n);
    }
}

void tatliSecimVeFiyatlandirma(struct musteriBilgileri *y, struct menuBilgi *x, int n)
{
hataliTuslama:
    echo("\n\n");

    int tatli_secim = secimFonksiyonu();
    switch (tatli_secim)
    {
    case 0:
        tab_bas(8);
        echo("Tatli tercih etmediniz\n");
        tab_bas(8);
        echo("Icecek sayfasina yonlendiriliyorsunuz...");
        Sleep(800);
        icecekler(y, n, x);
        break;

    case 1:
        siparisDetaylari(&toplamTutar, (x + 0)->tatli.fiyati, (x + 0)->tatli.adi, fisIslemSayaci);
        fisIslemSayaci++; //3
        icecekler(y, n, x);
        break;

    case 2:
        siparisDetaylari(&toplamTutar, (x + 1)->tatli.fiyati, (x + 1)->tatli.adi, fisIslemSayaci);
        fisIslemSayaci++;
        icecekler(y, n, x);
        break;

    case 3:
        siparisDetaylari(&toplamTutar, (x + 2)->tatli.fiyati, (x + 2)->tatli.adi, fisIslemSayaci);
        fisIslemSayaci++;
        icecekler(y, n, x);
        break;

    case 4:
        siparisDetaylari(&toplamTutar, (x + 3)->tatli.fiyati, (x + 3)->tatli.adi, fisIslemSayaci);
        fisIslemSayaci++;
        icecekler(y, n, x);
        break;

    case 5:
        siparisDetaylari(&toplamTutar, (x + 4)->tatli.fiyati, (x + 4)->tatli.adi, fisIslemSayaci);
        fisIslemSayaci++;
        icecekler(y, n, x);
        break;

    case 6:
        siparisDetaylari(&toplamTutar, (x + 5)->tatli.fiyati, (x + 5)->tatli.adi, fisIslemSayaci);
        fisIslemSayaci++;
        icecekler(y, n, x);
        break;

    case 7:
        siparisDetaylari(&toplamTutar, (x + 6)->tatli.fiyati, (x + 6)->tatli.adi, fisIslemSayaci);
        fisIslemSayaci++;
        icecekler(y, n, x);
        break;

    case 8:
        siparisDetaylari(&toplamTutar, (x + 7)->tatli.fiyati, (x + 7)->tatli.adi, fisIslemSayaci);
        fisIslemSayaci++;
        icecekler(y, n, x);
        break;

    case 9:
        siparisDetaylari(&toplamTutar, (x + 8)->tatli.fiyati, (x + 8)->tatli.adi, fisIslemSayaci);
        fisIslemSayaci++;
        icecekler(y, n, x);
        break;

    default:
        cls();
        satir_bas(1);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }
}

void tatliBilgisiGuncelleme(struct musteriBilgileri *y, struct menuBilgi *x, int satirSayac)
{

    int tatliGuncelleme;
    satir_bas(2);
    tab_bas(8);
    echo("Guncellemek istediginiz yemegin numarasini giriniz.\n");

hataliTuslama:

    tatliGuncelleme = secimFonksiyonu();

    switch (tatliGuncelleme)
    {
    case 0:
        ana_menu(y, x);
        break;

    case 1:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[0].tatli.adi);
        scanf("%f", &x[0].tatli.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[0].tatli.fiyati);
        break;
    case 2:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[1].tatli.adi);
        scanf("%f", &x[1].tatli.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[1].tatli.fiyati);
        break;
    case 3:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[2].tatli.adi);
        scanf("%f", &x[2].tatli.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[2].tatli.fiyati);
        break;
    case 4:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[3].tatli.adi);
        scanf("%f", &x[3].tatli.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[3].tatli.fiyati);
        break;
    case 5:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[4].tatli.adi);
        scanf("%f", &x[4].tatli.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[4].tatli.fiyati);
        break;
    case 6:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[5].tatli.adi);
        scanf("%f", &x[5].tatli.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[5].tatli.fiyati);
        break;
    case 7:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[6].tatli.adi);
        scanf("%f", &x[6].tatli.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[6].tatli.fiyati);
        break;
    case 8:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[7].tatli.adi);
        scanf("%f", &x[7].tatli.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[7].tatli.fiyati);
        break;
    case 9:
        printf("\n%s yemeginin yeni fiyatini giriniz: ", x[8].tatli.adi);
        scanf("%f", &x[8].tatli.fiyati);
        printf("\n Yemeginin yeni fiyati: %.2f", x[8].tatli.fiyati);
        break;

    default:
        cls();
        satir_bas(1);
        puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
        goto hataliTuslama;
        break;
    }

    int i;
    FILE *fpp;
    fpp = fopen("tatlilar.txt", "w");
    for (i = 0; i <= satirSayac; i++)
    {
        fprintf(fpp, "%s %d %f", (x + i)->tatli.adi, (x + i)->tatli.malzemeAdedi, (x + i)->tatli.fiyati);
        if (i != satirSayac)
            fprintf(fpp, "\n");
    }
    fclose(fpp);
    satir_bas(1);
    tab_bas(8);
    echo("Basariyla kaydedilmistir.");
    getch();
    ana_menu(y, x);
}

void siparisDetaylari(float *fiyatToplam, float tekFiyat, char isim[], int fisIslemSayaci)
{
    int i, ID = 0;
    char cizgiBastir[67] = "----------------------------------------------------------------\n";
    int siparis_id = randomId(ID);
    siparisNumarasi = siparis_id;

    tab_bas(8);
    printf("%s sectiniz. \n", isim);
    float istenenSayi = 0;
    float toplamFiyat = 0;
    tab_bas(8);
    echo("Kac tane/porsiyon istersiniz?\n");
    tab_bas(8);
    echo("==> ");
    scanf("%f", &istenenSayi);
    *fiyatToplam += istenenSayi * tekFiyat;

    if (fisIslemSayaci == 0) // 0 bilgisi yani ilk siparis verilince yeni dosya acilacak fis tasarimi baslayacak //cerceve vs
    {
        FILE *fSiparisFis = fopen("siparisFis.txt", "a");
        if (fSiparisFis == NULL)
        {
            puts("Dosya olusturulamadi.\n");
            Sleep(300);
            exit(1);
        }
        else
        {
            for (i = 0; i < 65; i++)
            {
                fputc(cizgiBastir[i], fSiparisFis);
            }

            fprintf(fSiparisFis, "\t\t\tMarmara Kebap Salonu\n");
            //fprintf(fSiparisFis, "\n\n\t\t\t\t\t\t\t %d \n", siparisNumarasi);
        }
        fclose(fSiparisFis);
    }

    if (fisIslemSayaci <= 3)
    {
        //Dosyaya yazilacak bilgiler kismi
        satir_bas(2);
        tab_bas(8);
        printf(" %s : \t\t %.2f * %.2f \n", isim, tekFiyat, istenenSayi);

        FILE *fSiparisFis = fopen("siparisFis.txt", "a");
        if (fSiparisFis == NULL)
        {
            puts("Dosya olusturulamadi.\n");
            Sleep(300);
            exit(1);
        }
        else
        {

            fprintf(fSiparisFis, " \n%s: \t \t %.2f * %.2f\n", isim, tekFiyat, istenenSayi);
        }
        fclose(fSiparisFis);

        Sleep(1000);
        satir_bas(1);
        tab_bas(8);
        printf("Aldiklariniz %.2f TL tutmustur.\n", *fiyatToplam);
        satir_bas(3);
        tab_bas(8);
        echo("Siparisiniz hazirlaniyor. Diger sayfaya yonlendiriliyorsunuz...\n");
        Sleep(800);
    }
    if (fisIslemSayaci == 3) //3 bilgisi yani son siparis verildigi an ve mevcut dosyanin kapatilmasi islemi
    {
        FILE *fSiparisFis = fopen("siparisFis.txt", "a");
        if (fSiparisFis == NULL)
        {
            puts("Dosya olusturulamadi.\n");
            Sleep(300);
            exit(1);
        }
        else
        {
            fprintf(fSiparisFis, "\nToplam tutar:\t \t %.2f\n", toplamTutar);

            //!buraya siparis veren kullanicinin adres bilgisi yazdirilabilir.

            for (i = 0; i < 65; i++)
            {
                fputc(cizgiBastir[i], fSiparisFis);
            }
        }
        fclose(fSiparisFis);
    }
    Sleep(2000);
}

void odemeYontemi(struct musteriBilgileri *y, struct menuBilgi *x)
{
    int i;
    char odeme[2][30] = {"Online Odeme", "Kapida Odeme"};

hataliTuslama:

    system("color 3E");
    printf("\n\t\t");
    system("color 3E");
    bosluk_bas(1);
    tab_bas(4);
    cls();

    satir_bas(10);
    for (i = 0; i < 2; i++)
    {
        satir_bas(2);
        tab_bas(12);
        printf("==>  [%d]. %s\n\n", i + 1, odeme[i]);
        Sleep(100);
    }
    satir_bas(1);

    int anaSecim = secimFonksiyonu();
    switch (anaSecim)
    {
    case 1:
        onlineOdeme(y, x);
        break;

    case 2:
        kapidaOdeme(y, x);
        break;

    default:
        cls();
        satir_bas(10);
        tab_bas(11);
        echo("   Gecersiz giris yaptiniz !!");
        Sleep(900);
        goto hataliTuslama;
        break;
    }
}

void kapidaOdeme(struct musteriBilgileri *y, struct menuBilgi *x)
{
    cls();
    system("color 2E");
    printf("\n\t\t");
    system("color 2E");
    bosluk_bas(1);
    tab_bas(4);

    bosluk_bas(1);
    tab_bas(10);

    echo("Ucret Siparis Tesliminde Alinacak..\n");

    //o kisiye ait isim soy isim ve adres bilgileri gosterilecek
    //Altına "yukarıda belirtmis oldugunuz adres bilgisine siparisiniz gonderilmek uzere hazirlaniyor."
    //Todo:Fise bu kisinin adresi yazilacak.

    tab_bas(8);
    echo("Siparis Bilgileri basariyla alinmis ve Siparisiniz hazirlanmaya baslanmistir.\n\n");
    Sleep(250);

    tab_bas(8);
    echo("Anasayfaya yonlendiriliyorsunuz...");
    Sleep(1000);
    ana_menu(y, x);
}

void onlineOdeme(struct musteriBilgileri *y, struct menuBilgi *x)
{

    int musteriID; //Hangi kullanici ID bulmak gerekecek
    //kredi karı bilgileri ile esleme veya direk kredi kartının dogtu kabul edilmesi
    //o kisiye ait isim soy isim ve adres bilgileri gosterilecek
    //Altına "yukarıda belirtmis oldugunuz adres bilgisine siparisiniz gonderilmek uzere hazirlaniyor."

    system("color 2E");
    printf("\n\t\t");
    system("color 2E");
    bosluk_bas(1);
    tab_bas(4);
    cls();

    bosluk_bas(1);
    tab_bas(10);

    echo("Ucret Online Olarak tahsil edilecek..\n");
    echo("- Kredi karti numaraniz:");
    scanf("%s", &(y + (musteriID - 1))->kartNumarasi);
    echo("- Kredi karti sahibi adi ve soyadi (bitisik yazilmalidir!!): ");
    scanf("%s", &(y + (musteriID - 1))->kartSahibiAdi);
    echo("- Kredi karti son gecerlilik tarihi (ay ve yil bitisik yazilmalidir!!): ");
    scanf("%s", &(y + (musteriID - 1))->gecerlilikTarihi);
    echo("- Kredi karti guvenlik numaraniz: ");
    scanf("%s", &(y + (musteriID - 1))->guvenlikKodu);

    //TODO: Kredi karti Esleme olayi yapilacak mi?
    //Todo:Fise bu kisinin adresi yazilacak.

    tab_bas(8);
    echo("Siparis Bilgileri basariyla alinmis ve Siparisiniz hazirlanmaya baslanmistir.\n\n");
    Sleep(250);

    tab_bas(8);
    echo("Anasayfaya yonlendiriliyorsunuz...\n\n");
    Sleep(1000);
    ana_menu(y, x);
}

int randomId(int ID) //Her kullaniciya random ID olusturuluyor..
{
    srand(time(0));
    int siparisNo = 0;
    siparisNo = rand() % 10000 + 1;
    return siparisNo;
}

void musteriBilgileriGoruntule(struct musteriBilgileri *y, struct menuBilgi *x) //!Yazdirma kisimlari yanlis yazdiriyor.
{
    menuRenk();

    int i, satirSayac = 0;
    char c;

    FILE *fpp;
    fpp = fopen("musteriBilgileri.txt", "r");

    for (c = getc(fpp); c != EOF; c = getc(fpp))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpp);

    tab_bas(10);
    printf("    * * * * * * MUSTERI VERILERI * * * * *\n\n");
    for (i = 0; i <= satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(9);

        printf("[%d]. %s %s\n", i + 1, (y + i)->musteriIsmi, (y + i)->musteriSoyismi);
        tab_bas(9);
        printf("Adres Bilgisi:\n");
        tab_bas(9);
        printf("%s %s %s\n", (y + i)->sehir, (y + i)->ilce, (y + i)->semt);
        tab_bas(9);
        printf("%s %s %s\n", (y + i)->sokak, (y + i)->apartmanIsmi, (y + i)->daireNo);
        Sleep(100);
    }

    satirSayac = 0;
    FILE *fpk;
    fpk = fopen("musteriGirisiBilgisi.txt", "r");

    for (c = getc(fpk); c != EOF; c = getc(fpk))
        if (c == '\n')
            satirSayac = satirSayac + 1;

    fclose(fpk);

    tab_bas(10);
    printf("    * * * * * * MUSTERI GIRIS VERILERI * * * * *\n\n");
    for (i = 0; i <= satirSayac; ++i)
    {
        bosluk_bas(3);
        tab_bas(9);

        printf("[%d]. %s %s %d\n", i + 1, (y + i)->musteriEMail, (y + i)->musteriSifre, (y + i)->musteriId);
        Sleep(100);
    }

    satir_bas(1);
    tab_bas(10);
    printf("Kayit olan tum kullanicilar goruntulenmektedir..\n\n\n");
    tab_bas(10);
    printf("Admin menuye donmek icin herhangi bir tusa basiniz...\n\n");
    getch();
}

void siparisBilgileriGoruntule(struct musteriBilgileri *y, struct menuBilgi *x)
{
    system("color 3E");
    printf("\n\t\t");
    system("color 1E");
    bosluk_bas(1);
    tab_bas(5);
    cls();

    int i = 0;
    char *karakter, satir[300];

    FILE *siparisBilgileri = fopen("siparisFis.txt", "r");

    tab_bas(11);
    printf("==> [0].Ana Menu\n");
    tab_bas(11);
    printf("==>[1].Fis Bilgilerini Goruntule\n");

    int musteriEklemeSecim = secimFonksiyonu();
    if (musteriEklemeSecim == 0)
    {
        ana_menu(y, x);
    }

    if (siparisBilgileri == NULL)
    {
        fprintf(stderr, "Dosyalari okurken bir hata meydana geldi...");
    }

    tab_bas(10);
    printf("      * * * * * *   SIPARISLER   * * * * *\n\n");

    do
    {
        tab_bas(10);
        karakter = fgets(satir, 300, siparisBilgileri); //!satir satir bilgi okundu...

        if (karakter != NULL)
        {
            printf("%s", satir);
        }

    } while (karakter != NULL);
    i++;

    satir_bas(1);
    tab_bas(10);
    printf("Verilen tum siparisler goruntulenmektedir..\n\n\n");
    fclose(siparisBilgileri);
    tab_bas(10);
    printf("Admin menuye donmek icin herhangi bir tusa basiniz...");
    getch();
}

void uygulamayiKapat()
{
    cls();
    satir_bas(10);
    cerceve();
    satir_bas(2);
    tab_bas(12);
    puts("Yine bekleriz!!\n\n");
    Sleep(200);
    tab_bas(12);
    puts("Program kapatiliyor...");
    cerceve();
    Sleep(800);
    exit(1);
}
void gecersizGiris(struct musteriBilgileri *y, struct menuBilgi *x)
{
    cls();
    satir_bas(8);
    tab_bas(10);
    puts("Gecersiz Giris Yaptiniz. Lutfen Tekrar Deneyiniz !!! ");
    Sleep(1300);
    ana_menu(y, x);
}

//Gerekli if yerlerinde kullanilmak uzere secim icin fonksiyon
int secimFonksiyonu()
{
    int secim;
    echo("===> ");
    scanf("%d", &secim);
    return secim;
}

//Anlik zaman bilgisi yazdirir.
void zamanGoster()
{
    time_t t;
    time(&t);
    struct tm *zaman;
    zaman = localtime(&t);
    tab_bas(6);
    printf("             %d/%d/%d  %d:%d", zaman->tm_mday, zaman->tm_mon + 1, zaman->tm_year + 1900, zaman->tm_hour, zaman->tm_min);
}

// Console tam ekran yapiliyor.
void tamEkran()
{
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_SHOWMAXIMIZED);
}

int kasaBilgiOku()
{
    int top;
    FILE *Fp = fopen("kasadakiPara.txt", "r");
    if (Fp == NULL)
    {
        tab_bas(11);
        puts("!!! kasadakiPara.txt Dosya okunamadi !!!\n");
        Sleep(500);
        exit(1);
    }
    else
    {
        while (fscanf(Fp, "%d", &top) != EOF)
        {
        }
        printf("%d\n", top);
    }
    fclose(Fp);
    return top;
}

void kasaBilgiYaz(int toplam)
{
    FILE *Fp = fopen("kasadakiPara.txt", "a");
    if (Fp == NULL)
    {
        tab_bas(11);
        puts("!!! kasadakiPara.txt Dosya olusturulamadi !!!\n");
        Sleep(500);
        exit(1);
    }
    else
    {
        fprintf(Fp, "%d\n", toplam);
    }
    fclose(Fp);
}

void icecekBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("icecekler.txt", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s %d %f", &(x + i)->icecekler.adi, &(x + i)->icecekler.stokAdedi, &(x + i)->icecekler.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! icecekler.txt Dosya Bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void kebapBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("kebaplar.txt", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s %d %f", &(x + i)->kebap.adi, &(x + i)->kebap.malzemeAdedi, &(x + i)->kebap.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! kebaplar.txt Dosya Bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void donerBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("donerler.txt", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s %d %f", &(x + i)->doner.adi, &(x + i)->doner.malzemeAdedi, &(x + i)->doner.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! donerler.txt Dosya Bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void hamburgerBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("hamburgerler.txt", "r")) != NULL)
    {

        while (!feof(fpp))
        {

            fscanf(fpp, "%s %d %f", &(x + i)->hamburger.adi, &(x + i)->hamburger.malzemeAdedi, &(x + i)->hamburger.fiyati);

            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! hamburgerler.txt Dosya Bulunamadi !!!");
        Sleep(1000);
    }

    fclose(fpp);
}

void corbaBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("corbalar.txt", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s %d %f", &(x + i)->corba.adi, &(x + i)->corba.malzemeAdedi, &(x + i)->corba.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! corbalar.txt Dosya Bulunamadi !!!");
        Sleep(1000);
    }

    fclose(fpp);
}

void evYemekleriBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("evyemekleri.txt", "r")) != NULL)
    {
        while (!feof(fpp))
        {
            fscanf(fpp, "%s %d %f", &(x + i)->evYemekleri.adi, &(x + i)->evYemekleri.malzemeAdedi, &(x + i)->evYemekleri.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! evyemekleri.txt Dosya bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void pizzaBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("pizzalar.txt", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s %d %f", &(x + i)->pizza.adi, &(x + i)->pizza.malzemeAdedi, &(x + i)->pizza.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! pizzalar.txt Dosya bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void pideBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("pideler.txt", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s %d %f", &(x + i)->pide.adi, &(x + i)->pide.malzemeAdedi, &(x + i)->pide.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! pideler.txt Dosya bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void balikBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("baliklar.txt", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s %d %f", &(x + i)->balik.adi, &(x + i)->balik.malzemeAdedi, &(x + i)->balik.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! baliklar.txt Dosya bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void salataBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("salatalar.txt", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s %d %f", &(x + i)->salata.adi, &(x + i)->salata.malzemeAdedi, &(x + i)->salata.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! salatalar.txt Dosya bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void tatliBilgisiCek(struct menuBilgi *x)
{
    int i = 0;

    FILE *fpp;
    if ((fpp = fopen("tatlilar.txt", "r")) != NULL)
    {

        while (!feof(fpp))
        {
            fscanf(fpp, "%s %d %f", &(x + i)->tatli.adi, &(x + i)->tatli.malzemeAdedi, &(x + i)->tatli.fiyati);
            i++;
        }
    }
    else
    {
        tab_bas(11);
        printf("!!! tatlilar.txt Dosya bulunamadi !!!");
        Sleep(1000);
    }
    fclose(fpp);
}

void yemekBilgisiCek(struct menuBilgi *x)
{
    icecekBilgisiCek(x);
    kebapBilgisiCek(x);
    donerBilgisiCek(x);
    hamburgerBilgisiCek(x);
    corbaBilgisiCek(x);
    evYemekleriBilgisiCek(x);
    pizzaBilgisiCek(x);
    pideBilgisiCek(x);
    balikBilgisiCek(x);
    salataBilgisiCek(x);
    tatliBilgisiCek(x);
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

void cerceve()
{
    // Alt cercevenin yazdirilmasi
    satir_bas(1);
    tab_bas(8);
    int i;
    for (i = 0; i < 89; i++)
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
    Sleep(2000);
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

void hakkimizdaGoruntule(struct musteriBilgileri *y, struct menuBilgi *x)
{
    int k;
    char yazilimcilar[4][50] = {"Melih Afsar", "Kenan Baylan", "Aziz Eren Saganda", "Serif Yilmaz"};
    menuRenk();
    satir_bas(10);
    tab_bas(12);
    echo("   Maramara Kebap Hause");
    cerceve();
    satir_bas(1);
    tab_bas(13);
    echo("since 1883");
    satir_bas(1);
    tab_bas(12);
    echo("Basibuyuk/Maltepe/Istanbul\n");
    satir_bas(5);
    tab_bas(12);
    echo("Yazilimda Emegi Gecenler\n");
    for (k = 0; k < 4; ++k)
    {
        tab_bas(12);
        printf("    %s", yazilimcilar[k]);
        satir_bas(1);
    }
    cerceve();
    getch();
    ana_menu(y, x);
}