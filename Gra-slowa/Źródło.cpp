#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdlib.h>


using namespace std;
void menu();
void gra();
void powrot();
bool isRight(string);


int main()
{

	menu();

}


void gra()
{
	system("cls");

	cout << "Podaj swoje Imie:" << endl;

	string imie;
	cin >> imie;

	system("cls");

	cout << "Gra dla uzytkownika " << imie << " rozpocznie sie za:" << endl;
	Sleep(1000);

	for (int i = 3; i > 0; i--)
	{
		cout << i << "." << endl;
		Sleep(1000);
		system("cls");


	}

	fstream plik;
	plik.open("test.txt", ios::in);
	if (plik.good() == false)
	{
		cout << " Plik nie istnieje";
		exit(0);

	}

	clock_t start, stop;
	double czas;
	start = clock();


	string slowo[50];

	for (int i = 1; i < 50; i++)

	{
		plik >> slowo[i];

	}

	for (int i = 1; i <= 3; i++)
	{
		system("cls");
		cout << "***RUNDA***" << i << endl;

		cout << endl;
		cout << endl;
		cout << endl;

		srand(time(NULL));
		string losowe[3];
		string odpowiedz[3];



		for (int i = 0; i < 3; i++)

		{
			int pierwsza_losowa;
			pierwsza_losowa = rand() % 50;
			cout << slowo[pierwsza_losowa] << " " << endl;
			losowe[i] = slowo[pierwsza_losowa];


		}

		cout << endl;
		cout << endl;
		cout << endl;

		for (int i = 0; i < 3; i++)
		{
			cin >> odpowiedz[i];
		}


		if (odpowiedz[0] != losowe[0] || odpowiedz[1] != losowe[1] || odpowiedz[2] != losowe[2])
		{

			cout << endl;

			cout << "***PRZEGRALES***" << endl;

			cout << endl;
			cout << endl;
			cout << endl;

			if (odpowiedz[0] != losowe[0])
			{
				cout << "DWA PIERWSZE SLOWA SIE ROZNIA (" << odpowiedz[0] << " i " << losowe[0] << ")" << endl;


			}

			if (odpowiedz[1] != losowe[1])
			{
				cout << "DRUGIE SLOWA SIE ROZNIA (" << odpowiedz[1] << " i " << losowe[1] << ")" << endl;

			}

			if (odpowiedz[2] != losowe[2])
			{
				cout << "TRZECIE PIERWSZE SLOWA SIE ROZNIA (" << odpowiedz[2] << " i " << losowe[2] << ")" << endl;


			}

			exit(1);
		}



		if (i == 3)

		{
			plik.close();
			stop = clock();
			czas = (double)(stop - start) / CLOCKS_PER_SEC;
			system("cls");
			cout << "***GRATULACJE WYGRALES !!!***" << endl;
			cout << "OTO TWOJ CZAS: " << czas << endl;

			powrot();

		}



	}




}

void menu()
{
	cout << " *** WITAJ W MOJEJ GRZE *** " << endl;

	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;

	cout << "Wybierz co chcesz zrobic :" << endl;

	cout << " " << endl;
	cout << "1.GRAJ" << endl;
	cout << "2.ZASADY" << endl;
	cout << "3.INFORMACJE" << endl;
	cout << "4.Wyjscie z gry" << endl;
	

	
	int wybor;
	char wyjscie;

	do { cin >> wybor; } while (!isRight("Musisz wybrac jedna z podanych opcji \n"));


	if (wybor == 1)
	{
		gra();
	}

	else if (wybor == 2)
	{
		cout << "Na ekranie wyœwietlac sie beda 3 losowe wyrazy. Przepis je bezblednie aby przejsc na nastepny level!" << endl;
		cout << endl;
		cout << endl;
		cout << endl;

		powrot();
	}

	else if (wybor == 3)
	{
		cout << " Rafal to koks i siema" << endl;
		powrot();
	}

	else if (wybor == 4)
	{
		cout << " Czy napewno chcesz wyjsc z gry ? (T/N)" << endl;
		cin >> wyjscie;
		if (wyjscie == 'T' || wyjscie == 't')
		{
			exit(1);
		}
		
		else if (wyjscie == 'N' || wyjscie == 'n')
		{
			system("cls");
			menu();
		}
	}

	//else
	{
		
		system("cls");
		menu();
		cout << "MUSISZ WYBRAC '1' , '2', LUB '3' " << endl;
	}

	



	
}


void powrot()
{
	
	
	

		int koniec;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "Powrot do menu - wybierz - 1  / Wyjscie z gry - wybierz - 2" << endl;
		do { cin >> koniec; } while (!isRight("Musisz wybrac jedna z podanych opcji \n"));
		if (koniec == 1)
		{
			system("cls");
			menu();
		}
		else if (koniec == 2)
		{
			exit(1);
		}
		
	 

}
//WALIDACJA DANYCH 
bool isRight(string error_msg)
{
	if (cin.rdstate())
	{
		cin.clear();
		cin.ignore(1024, '\n');

		system("cls");
		menu();
		cout << error_msg;

		return false;


	}

	return true;
}