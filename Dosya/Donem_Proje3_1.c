#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

//KUllANILAN STRUCTLAR
struct kebaplar
{
	char ad[30];
	int adet;
	float fiyat;
};

struct pideler
{
	char ad[30];
	int adet;
	float fiyat;
};

struct pizzalar
{
	char ad[30];
	int adet;
	float fiyat;
};

struct hamburgerler
{
	char ad[30];
	int adet;
	float fiyat;
};

struct corbalar
{
	char ad[30];
	int adet;
	float fiyat;
};

struct salatalar
{
	char ad[30];
	int adet;
	float fiyat;
};

struct donerler
{
	char ad[30];
	int adet;
	float fiyat;
};

struct baliklar
{
	char ad[30];
	int adet;
	float fiyat;
};

struct tatlilar
{
	char ad[30];
	int adet;
	float fiyat;
};

struct icecekler
{
	char ad[30];
	int adet;
	float fiyat;
};

struct evYemekleri
{
	char ad[30];
	int adet;
	float fiyat;
};

typedef struct yemekler
{
	struct kebaplar kebap;
	struct donerler doner;
	struct baliklar balik;
	struct tatlilar tatli;
	struct icecekler icecek;
	struct evYemekleri evyemek;
	struct hamburgerler hamburger;
	struct corbalar corba;
	struct pizzalar pizza;
	struct pideler pide;
	struct salatalar salata;
} yemek;

//MENU FONKS�YONLARI
void admin_menu();
void siparis_menu();
void ana_menu();

// TASARIM FONKSIYONLARI
void cls();
void echo(char print[]);
void satir_bas(int line);
void tab_bas(int tab);
void bosluk_bas(int space);
void cerceve();
void karsilama();
void ilerleme();

//YEMEK FONKSIYONLARI
void yemekleriCek(yemek *x);
void kebapCek(yemek *x);
void donerCek(yemek *x);
void balikCek(yemek *x);
void tatliCek(yemek *x);
void icecekCek(yemek *x);
void evYemekCek(yemek *x);
void pideCek(yemek *x);
void pizzaCek(yemek *x);
void hamburgerCek(yemek *x);
void corbaCek(yemek *x);
void salataCek(yemek *x);
void kebapListele(yemek *x);
void donerListele(yemek *x);
void balikListele(yemek *x);
void tatliListele(yemek *x);
void icecekListele(yemek *x);
void evYemekleriListele(yemek *x);
void salataListele(yemek *x);
void pideListele(yemek *x);
void pizzaListele(yemek *x);
void corbaListele(yemek *x);
void hamburgerListele(yemek *x);
void yemekMenu();

int main()
{

	struct yemekler *yptr;
	yptr = (struct yemekler *)malloc(100 * sizeof(struct yemekler));

	yemekleriCek(yptr);

	system("title Marmara Kebap House");

	system("mode con: cols=80 lines=30");

	ilerleme();
	cls();

	karsilama();
	cls();

	ana_menu(yptr);
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

void ana_menu(yemek *x)
{
	int anaSecim;

	cls();

	satir_bas(5);
	tab_bas(3);
	echo("===> [1]. Yemek Listesi");

	Sleep(250);

	satir_bas(2);
	tab_bas(3);
	echo("===> [2]. Admin Paneli");

	Sleep(250);
	satir_bas(2);
	tab_bas(3);
	echo("===> [3]. Cikis");

	Sleep(150);
	satir_bas(1);

	echo("==> ");
	scanf("%d", &anaSecim);

	switch (anaSecim)
	{
	case 1:
		corbaListele(x);
		break;

	case 2:
		admin_menu(x);
		break;

	case 3:
		cls();
		puts("Yine bekleriz!!");
		Sleep(250);
		exit(1);

	default:
		cls();
		puts("Gecersiz giris yaptiniz. Lutfen tekrar deneyiniz. ");
		Sleep(250);
		ana_menu(x);
		break;
	}
}

void admin_menu(yemek *x)
{
	int adminSecim;

	cls();

	bosluk_bas(1);
	tab_bas(4);

	printf("==>  [0]. Ana Menu");
	printf("\n\nSifrenizi girin: ");
	scanf("%d", &adminSecim);

	if (adminSecim == 0)
	{
		ana_menu(x);
	}

	else if (adminSecim == 12345)
	{

		cls();

		bosluk_bas(5);
		tab_bas(4);
		echo("Basariyla giris yaptiniz...\n\n");
		Sleep(1000);

	admin:
		cls();

		bosluk_bas(5);

		tab_bas(4);
		echo("[0]. Ana Menuye Don\n\n");

		tab_bas(4);
		echo("[1]. Gunluk Butce\n\n");

		tab_bas(4);
		echo("[2]. Yemek Ekle\n\n");

		tab_bas(4);
		echo("[3]. Yemek Sil\n\n");

		tab_bas(4);
		echo("[4]. Yemekleri Listele\n\n");

		printf("==> ");
		scanf("%d", &adminSecim);

		switch (adminSecim)
		{
		case 0:
			ana_menu(x);
			break;

		case 1:
			cls();
			tab_bas(4);

			getchar();
			Sleep(3000);
			goto admin;
			break;

		case 2:
			cls();

			bosluk_bas(2);
			tab_bas(4);

			goto admin;
			break;

		case 3:
			cls();
			printf(" Yemek silmek için kodunu girin: ");
			getchar();
			goto admin;
			break;

		case 4:
			cls();

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

void cerceve()
{
	// Alt çerçevenin yazdırılması
	printf("\n\t\t\t\t");
	int i;
	for (i = 0; i < 63; i++)
	{
		putchar('=');
	}
}

void karsilama()
{
	system("color 2E");

	char hosgeldin[50] = "MARMARA KEBAP SALONUNA HOS GELDINIZ";
	printf("\n\n\n\n\n\t\t\t");

	int i;

	for (i = 0; i < strlen(hosgeldin); i++)
	{
		system("color 2E");

		printf(" %c", hosgeldin[i]);
		Sleep(25);
	}

	system("color 2E");
	printf("\n\n\t\t\t\t ");

	Sleep(500);
}

void ilerleme(void)
{

	int i;

	for (i = 15; i <= 100; i += 10)
	{
		cls();
		system("color 3E");

		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d Yukleniyor... %% \n\n\t\t", i);

		printf("");

		int j;

		for (j = 0; j < i; j += 2)
		{
			printf("\xdb");
			system("color 3E");
		}
		Sleep(10);

		if (i == 90 || i == 50 || i == 96 || i == 83)
		{
			Sleep(25);
		}
	}
}

void kebapCek(yemek *x)
{
	int i = 0;

	FILE *fpp;
	if ((fpp = fopen("kebaplar.txt", "r")) != NULL)
	{

		while (!feof(fpp))
		{

			fscanf(fpp, "%s %d %f", &(x + i)->kebap.ad, &(x + i)->kebap.adet, &(x + i)->kebap.fiyat);

			i++;
		}
	}
	else
	{
		printf("dosya bulunamadi");
	}

	fclose(fpp);
}

void kebapListele(yemek *x)
{
	int i, satirSayac = 0;
	char c;

	FILE *fpp;
	fpp = fopen("kebaplar.txt", "r");

	for (c = getc(fpp); c != EOF; c = getc(fpp))
		if (c == '\n')
			satirSayac = satirSayac + 1;

	fclose(fpp);

	for (i = 0; i <= satirSayac; ++i)
	{
		printf("%s %d %f \n", (x + i)->kebap.ad, (x + i)->kebap.adet, (x + i)->kebap.fiyat);
	}
}

void yemekMenu()
{

	char menu[6][20] = {

		"1 Kebaplar",
		"2 Donerler",
		"3 Baliklar",
		"4 Tatlilar",
		"5 Icecekler",
		"6 Ev Yemekleri"

	};

	int i;

	for (i = 0; i < 6; i++)
		printf("%s \n", menu[i]);
}

void donerCek(yemek *x)
{
	int i = 0;

	FILE *fpp;
	if ((fpp = fopen("donerler.txt", "r")) != NULL)
	{

		while (!feof(fpp))
		{

			fscanf(fpp, "%s %d %f", &(x + i)->doner.ad, &(x + i)->doner.adet, &(x + i)->doner.fiyat);

			i++;
		}
	}
	else
	{
		printf("dosya bulunamadi");
	}

	fclose(fpp);
}

void balikCek(yemek *x)
{
	int i = 0;

	FILE *fpp;
	if ((fpp = fopen("baliklar.txt", "r")) != NULL)
	{

		while (!feof(fpp))
		{

			fscanf(fpp, "%s %d %f", &(x + i)->balik.ad, &(x + i)->balik.adet, &(x + i)->balik.fiyat);

			i++;
		}
	}
	else
	{
		printf("dosya bulunamadi");
	}

	fclose(fpp);
}

void tatliCek(yemek *x)
{
	int i = 0;

	FILE *fpp;
	if ((fpp = fopen("tatlilar.txt", "r")) != NULL)
	{

		while (!feof(fpp))
		{

			fscanf(fpp, "%s %d %f", &(x + i)->tatli.ad, &(x + i)->tatli.adet, &(x + i)->tatli.fiyat);

			i++;
		}
	}
	else
	{
		printf("dosya bulunamadi");
	}

	fclose(fpp);
}

void icecekCek(yemek *x)
{
	int i = 0;

	FILE *fpp;
	if ((fpp = fopen("icecekler.txt", "r")) != NULL)
	{

		while (!feof(fpp))
		{

			fscanf(fpp, "%s %d %f", &(x + i)->icecek.ad, &(x + i)->icecek.adet, &(x + i)->icecek.fiyat);

			i++;
		}
	}
	else
	{
		printf("dosya bulunamadi");
	}

	fclose(fpp);
}

void evYemekCek(yemek *x)
{
	int i = 0;

	FILE *fpp;
	if ((fpp = fopen("evyemekleri.txt", "r")) != NULL)
	{

		while (!feof(fpp))
		{

			fscanf(fpp, "%s %d %f", &(x + i)->evyemek.ad, &(x + i)->evyemek.adet, &(x + i)->evyemek.fiyat);

			i++;
		}
	}
	else
	{
		printf("dosya bulunamadi");
	}

	fclose(fpp);
}

void salataCek(yemek *x)
{
	int i = 0;

	FILE *fpp;
	if ((fpp = fopen("salatalar.txt", "r")) != NULL)
	{

		while (!feof(fpp))
		{

			fscanf(fpp, "%s %d %f", &(x + i)->salata.ad, &(x + i)->salata.adet, &(x + i)->salata.fiyat);

			i++;
		}
	}
	else
	{
		printf("dosya bulunamadi");
	}

	fclose(fpp);
}

void pideCek(yemek *x)
{
	int i = 0;

	FILE *fpp;
	if ((fpp = fopen("pideler.txt", "r")) != NULL)
	{

		while (!feof(fpp))
		{

			fscanf(fpp, "%s %d %f", &(x + i)->pide.ad, &(x + i)->pide.adet, &(x + i)->pide.fiyat);

			i++;
		}
	}
	else
	{
		printf("dosya bulunamadi");
	}

	fclose(fpp);
}

void pizzaCek(yemek *x)
{
	int i = 0;

	FILE *fpp;
	if ((fpp = fopen("pizzalar.txt", "r")) != NULL)
	{

		while (!feof(fpp))
		{

			fscanf(fpp, "%s %d %f", &(x + i)->pizza.ad, &(x + i)->pizza.adet, &(x + i)->pizza.fiyat);

			i++;
		}
	}
	else
	{
		printf("dosya bulunamadi");
	}

	fclose(fpp);
}

void corbaCek(yemek *x)
{
	int i = 0;

	FILE *fpp;
	if ((fpp = fopen("corbalar.txt", "r")) != NULL)
	{

		while (!feof(fpp))
		{

			fscanf(fpp, "%s %d %f", &(x + i)->corba.ad, &(x + i)->corba.adet, &(x + i)->corba.fiyat);

			i++;
		}
	}
	else
	{
		printf("dosya bulunamadi");
	}

	fclose(fpp);
}

void hamburgerCek(yemek *x)
{
	int i = 0;

	FILE *fpp;
	if ((fpp = fopen("hamburgerler.txt", "r")) != NULL)
	{

		while (!feof(fpp))
		{

			fscanf(fpp, "%s %d %f", &(x + i)->hamburger.ad, &(x + i)->hamburger.adet, &(x + i)->hamburger.fiyat);

			i++;
		}
	}
	else
	{
		printf("dosya bulunamadi");
	}

	fclose(fpp);
}

void yemekleriCek(yemek *x)
{
	kebapCek(x);
	donerCek(x);
	balikCek(x);
	tatliCek(x);
	icecekCek(x);
	evYemekCek(x);
	salataCek(x);
	pideCek(x);
	pizzaCek(x);
	corbaCek(x);
	hamburgerCek(x);
}

void donerListele(yemek *x)
{
	int i, satirSayac = 0;
	char c;

	FILE *fpp;
	fpp = fopen("donerler.txt", "r");

	for (c = getc(fpp); c != EOF; c = getc(fpp))
		if (c == '\n')
			satirSayac = satirSayac + 1;

	fclose(fpp);

	for (i = 0; i <= satirSayac; ++i)
		printf("%s %d %f \n", (x + i)->doner.ad, (x + i)->doner.adet, (x + i)->doner.fiyat);
}

void balikListele(yemek *x)
{
	int i, satirSayac = 0;
	char c;

	FILE *fpp;
	fpp = fopen("baliklar.txt", "r");

	for (c = getc(fpp); c != EOF; c = getc(fpp))
		if (c == '\n')
			satirSayac = satirSayac + 1;

	fclose(fpp);

	for (i = 0; i <= satirSayac; ++i)
		printf("%s %d %f \n", (x + i)->balik.ad, (x + i)->balik.adet, (x + i)->balik.fiyat);
}

void tatliListele(yemek *x)
{
	int i, satirSayac = 0;
	char c;

	FILE *fpp;
	fpp = fopen("tatlilar.txt", "r");

	for (c = getc(fpp); c != EOF; c = getc(fpp))
		if (c == '\n')
			satirSayac = satirSayac + 1;

	fclose(fpp);

	for (i = 0; i <= satirSayac; ++i)
		printf("%s %d %f \n", (x + i)->tatli.ad, (x + i)->tatli.adet, (x + i)->tatli.fiyat);
}

void icecekListele(yemek *x)
{
	int i, satirSayac = 0;
	char c;

	FILE *fpp;
	fpp = fopen("icecekler.txt", "r");

	for (c = getc(fpp); c != EOF; c = getc(fpp))
		if (c == '\n')
			satirSayac = satirSayac + 1;

	fclose(fpp);

	for (i = 0; i <= satirSayac; ++i)
		printf("%s %d %f \n", (x + i)->icecek.ad, (x + i)->icecek.adet, (x + i)->icecek.fiyat);
}

void evYemekleriListele(yemek *x)
{
	int i, satirSayac = 0;
	char c;

	FILE *fpp;
	fpp = fopen("evyemekleri.txt", "r");

	for (c = getc(fpp); c != EOF; c = getc(fpp))
		if (c == '\n')
			satirSayac = satirSayac + 1;

	fclose(fpp);

	for (i = 0; i <= satirSayac; ++i)
		printf("%s %d %f \n", (x + i)->evyemek.ad, (x + i)->evyemek.adet, (x + i)->evyemek.fiyat);
}

void salataListele(yemek *x)
{
	int i, satirSayac = 0;
	char c;

	FILE *fpp;
	fpp = fopen("salatalar.txt", "r");

	for (c = getc(fpp); c != EOF; c = getc(fpp))
		if (c == '\n')
			satirSayac = satirSayac + 1;

	fclose(fpp);

	for (i = 0; i <= satirSayac; ++i)
		printf("%s %d %f \n", (x + i)->salata.ad, (x + i)->salata.adet, (x + i)->salata.fiyat);
}

void pideListele(yemek *x)
{
	int i, satirSayac = 0;
	char c;

	FILE *fpp;
	fpp = fopen("pideler.txt", "r");

	for (c = getc(fpp); c != EOF; c = getc(fpp))
		if (c == '\n')
			satirSayac = satirSayac + 1;

	fclose(fpp);

	for (i = 0; i <= satirSayac; ++i)
		printf("%s %d %f \n", (x + i)->pide.ad, (x + i)->pide.adet, (x + i)->pide.fiyat);
}

void pizzaListele(yemek *x)
{
	int i, satirSayac = 0;
	char c;

	FILE *fpp;
	fpp = fopen("pizzalar.txt", "r");

	for (c = getc(fpp); c != EOF; c = getc(fpp))
		if (c == '\n')
			satirSayac = satirSayac + 1;

	fclose(fpp);

	for (i = 0; i <= satirSayac; ++i)
		printf("%s %d %f \n", (x + i)->pizza.ad, (x + i)->pizza.adet, (x + i)->pizza.fiyat);
}

void corbaListele(yemek *x)
{
	int i, satirSayac = 0;
	char c;

	FILE *fpp;
	fpp = fopen("corbalar.txt", "r");

	for (c = getc(fpp); c != EOF; c = getc(fpp))
		if (c == '\n')
			satirSayac = satirSayac + 1;

	fclose(fpp);

	for (i = 0; i <= satirSayac; ++i)
		printf("%s %d %f \n", (x + i)->corba.ad, (x + i)->corba.adet, (x + i)->corba.fiyat);
}

void hamburgerListele(yemek *x)
{
	int i, satirSayac = 0;
	char c;

	FILE *fpp;
	fpp = fopen("hamburgerler.txt", "r");

	for (c = getc(fpp); c != EOF; c = getc(fpp))
		if (c == '\n')
			satirSayac = satirSayac + 1;

	fclose(fpp);

	for (i = 0; i <= satirSayac; ++i)
		printf("%s %d %f \n", (x + i)->hamburger.ad, (x + i)->hamburger.adet, (x + i)->hamburger.fiyat);
}
