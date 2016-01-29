#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <algorithm>
#include <time.h>

#include "functions.h"
#include "sort.h"

using namespace std;

int main()
{
	int size = 20;

	srand((int)time(NULL));

//	cout << "Ilosc elementow: ";
//	cin >> size;
//	cout << endl;

//	cout << "Tablica poczatkowa (R P A D): ";
//	cin >> tryb;
//	cout << endl << endl;

	char str[10];
	sprintf(str, "%d", size);		//zamiana size na string ( 10 na "10" bo w takiej formie przyjmie to arrgen )

	int* zbiorTestowy;				//wskaznik na tablice, ktora zostanie utworzona w arrgen
	int* tablica = new int[size];

	double start;
	double end;

//----------------------------------------------------
// Losowanie tablicy ze zbiorem testowym
	char* arg[] = {(char*)"", (char*)"R", (char*)str, (char*)"0", (char*)str}; cout << "Arg R" << endl; 	//argumenty: {pusty, typ R P A D, ilosc(size), zakresMin, zakresMax}
	//char* arg[] = {(char*)"", (char*)"P", (char*)str, (char*)"20000"}; cout << "Arg P" << endl;			//partialy sorted - str==size -> ilosc, ilosc inwersji
	//char* arg[] = {(char*)"", (char*)"A", (char*)str};	cout << "Arg A" << endl;						//rosnaca (posortowana)
	//char* arg[] = {(char*)"", (char*)"D", (char*)str};	cout << "Arg D" << endl;						//malejaca


	cout << "Losowanie tablicy - ";
	zbiorTestowy = arrgen(5, arg);
	cout << "arrchk - ";
		arrchk(zbiorTestowy, size);					//jaka tablice otrzymano
	cout << endl << endl;


	//testowe wypisanie
			for (int i = 0; i < 100; i++)
			{
				cout << zbiorTestowy[i] << " ";
			}
		cout << endl;


//----------------------------------------------------


//Petla dla roznych wartosci CUTOFF
	//for(int i = 0; i <= 20; i++)
	{
		// hybrid_sort
		copy(zbiorTestowy, zbiorTestowy + size, tablica);//zaladowanie zbioru testowego do tablicy roboczej
		cout << "	hybrid_sort CUTOFF == " << 10 << endl;
		cout << "Sortuje... " << endl;
		start = GetTickCount(); 					// odczytaj liczbê milisekund przed
			hybrid_sort(tablica, size, 5, 0);
		end = GetTickCount(); 						// odczytaj liczbê milisekund po
		cout << "Posortowano w: " << (end - start) * 0.001 << "s " << endl;
		cout << "Otrzymano tablice - ";
			arrchk(tablica, size);
		cout << endl << endl;
		//testowe wypisanie
					for (int i = 0; i < 20; i++)
					{
						cout << tablica[i] << " ";
					}
				cout << endl;
	}

	delete [] zbiorTestowy;
	delete [] tablica;
}
