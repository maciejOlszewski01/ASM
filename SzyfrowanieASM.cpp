// SzyfrowanieASK.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

int main()
{
	//ograniczenie do 64 i bez 0
	char klucz[4];
	klucz[0] = '(';
	klucz[1] = '+';
	klucz[2] = '(';
	klucz[3] = '-';

	char wejscie[10];
	wejscie[0] = 'A';
	wejscie[1] = 'A';
	wejscie[2] = 'A';
	wejscie[3] = 'D';
	wejscie[4] = 'E';
	wejscie[5] = 'F';
	wejscie[6] = 'G';
	wejscie[7] = 'H';
	wejscie[8] = 'I';
	wejscie[9] = 'J';
	char wynik[40];
	char wyjscie[10];
	//Pętla sztfrująca
	for (int i = 0; i < 10; i++) {

		int k = 4;

		char a = wejscie[i];

		//chary klucz/wyjsciowe
		char b = klucz[0];
		char c = klucz[1];
		char d = klucz[2];
		char e = klucz[3];
		__asm {
			mov al, a


			//ustawianie po 2 bity w każdym rejestrze po kolei od najniższego
			shl al, 6
			shr al, 6

			//Wczytanie klucza

			mov cl, b
			mov ch, c
			mov dl, d
			mov dh, e

			mul cl
			mov b, al;

			//Kolejny
			mov al, a;

			shl al, 4
				shr al, 6

				mul ch
				mov c, al;

			mov al, a;

			shl al, 2
				shr al, 6

				mul dl
				mov d, al;


			mov al, a;
			shr al, 6;
			mul dh;
			mov e, al;
		}

		wynik[i * k] = b;
		wynik[i * k + 1] = c;
		wynik[i * k + 2] = d;
		wynik[i * k + 3] = e;

	}

	for (int i = 0; i < 40; i++) {
		printf("%c", wynik[i]);
	}
	printf("\n");

	for (int i = 0; i < 10; i++) {
		int k = 4;
		char a;
		char b = wynik[i * k];
		char c = wynik[i * k + 1];
		char d = wynik[i * k + 2];
		char e = wynik[i * k + 3];


		char f = klucz[0];
		char g = klucz[1];
		char h = klucz[2];
		char j = klucz[3];

		__asm {
			//odczytywanie po kolejnych pozycjach

			mov cl, 0;
			mov al, b;
			mov bl, f;
			div bl;
			or cl, al;


			mov al, c;
			mov bl, g;
			div bl;
			shl al, 2;
			or cl, al;

			mov al, d;
			mov bl, h;
			div bl;
			shl al, 4;
			or cl, al;

			mov al, e;
			mov bl, j;
			div bl;
			shl al, 6;
			or cl, al;

			mov a, cl;
		}
		wyjscie[i] = a;

	}
	for (int i = 0; i < 10; i++) {
		printf("%c", wyjscie[i]);
	}
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
