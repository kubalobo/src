#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <algorithm>


#include "functions.h"
#include "sort.h"

using namespace std;

int main()
{
	int size = 10000;

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

/*
	//testowe wypisanie
			for (int i = 0; i < 100; i++)
			{
				cout << zbiorTestowy[i] << " ";
			}
		cout << endl;
*/

// Sort 1 - bubble_sort
	copy(zbiorTestowy, zbiorTestowy + size, tablica);//zaladowanie zbioru testowego do tablicy roboczej
	cout << "	bubble_sort" << endl;
	cout << "Sortuje... " << endl;
	start = GetTickCount(); 					// odczytaj liczbê milisekund przed
		bubble_sort(tablica, size);
	end = GetTickCount(); 						// odczytaj liczbê milisekund po
	cout << "Posortowano w: " << (end - start) * 0.001 << "s " << endl;
	cout << "Otrzymano tablice - ";
		arrchk(tablica, size);
	cout << endl << endl;


// Sort 2 - insertion_sort
	copy(zbiorTestowy, zbiorTestowy + size, tablica);//zaladowanie zbioru testowego do tablicy roboczej
	cout << "	insertion_sort" << endl;
	cout << "Sortuje... " << endl;
	start = GetTickCount(); 					// odczytaj liczbê milisekund przed
		insertion_sort(tablica, size);
	end = GetTickCount(); 						// odczytaj liczbê milisekund po
	cout << "Posortowano w: " << (end - start) * 0.001 << "s " << endl;
	cout << "Otrzymano tablice - ";
		arrchk(tablica, size);
	cout << endl << endl;


// Sort 3 - merge_sort_bottom_up
	copy(zbiorTestowy, zbiorTestowy + size, tablica);//zaladowanie zbioru testowego do tablicy roboczej
	cout << "	merge_sort_bottom_up" << endl;
	cout << "Sortuje... " << endl;
	start = GetTickCount(); 					// odczytaj liczbê milisekund przed
		merge_sort_bottom_up(tablica, size);
	end = GetTickCount(); 						// odczytaj liczbê milisekund po
	cout << "Posortowano w: " << (end - start) * 0.001 << "s " << endl;
	cout << "Otrzymano tablice - ";
		arrchk(tablica, size);
	cout << endl << endl;


// Sort 4 - merge_sort
	copy(zbiorTestowy, zbiorTestowy + size, tablica);//zaladowanie zbioru testowego do tablicy roboczej
	cout << "	merge_sort" << endl;
	cout << "Sortuje... " << endl;
	start = GetTickCount(); 					// odczytaj liczbê milisekund przed
		merge_sort(tablica, size);
	end = GetTickCount(); 						// odczytaj liczbê milisekund po
	cout << "Posortowano w: " << (end - start) * 0.001 << "s " << endl;
	cout << "Otrzymano tablice - ";
		arrchk(tablica, size);
	cout << endl << endl;


// Sort 5 - quick_sort_3way
	copy(zbiorTestowy, zbiorTestowy + size, tablica);//zaladowanie zbioru testowego do tablicy roboczej
	cout << "	quick_sort_3way" << endl;
	cout << "Sortuje... " << endl;
	start = GetTickCount(); 					// odczytaj liczbê milisekund przed
		quick_sort_3way(tablica, size);
	end = GetTickCount(); 						// odczytaj liczbê milisekund po
	cout << "Posortowano w: " << (end - start) * 0.001 << "s " << endl;
	cout << "Otrzymano tablice - ";
		arrchk(tablica, size);
	cout << endl << endl;


// Sort 6 - quick_sort
	copy(zbiorTestowy, zbiorTestowy + size, tablica);//zaladowanie zbioru testowego do tablicy roboczej
	cout << "	quick_sort" << endl;
	cout << "Sortuje... " << endl;
	start = GetTickCount(); 					// odczytaj liczbê milisekund przed
		quick_sort(tablica, size);
	end = GetTickCount(); 						// odczytaj liczbê milisekund po
	cout << "Posortowano w: " << (end - start) * 0.001 << "s " << endl;
	cout << "Otrzymano tablice - ";
		arrchk(tablica, size);
	cout << endl << endl;


// Sort 7 - selection_sort
	copy(zbiorTestowy, zbiorTestowy + size, tablica);//zaladowanie zbioru testowego do tablicy roboczej
	cout << "	selection_sort" << endl;
	cout << "Sortuje... " << endl;
	start = GetTickCount(); 					// odczytaj liczbê milisekund przed
		selection_sort(tablica, size);
	end = GetTickCount(); 						// odczytaj liczbê milisekund po
	cout << "Posortowano w: " << (end - start) * 0.001 << "s " << endl;
	cout << "Otrzymano tablice - ";
		arrchk(tablica, size);
	cout << endl << endl;

// Sort 8 - std::sort
	copy(zbiorTestowy, zbiorTestowy + size, tablica);//zaladowanie zbioru testowego do tablicy roboczej
	cout << "	std::sort" << endl;
	cout << "Sortuje... " << endl;
	start = GetTickCount(); 					// odczytaj liczbê milisekund przed
		sort(tablica, tablica + size);
	end = GetTickCount(); 						// odczytaj liczbê milisekund po
	cout << "Posortowano w: " << (end - start) * 0.001 << "s " << endl;
	cout << "Otrzymano tablice - ";
		arrchk(tablica, size);
	cout << endl << endl;

	delete [] zbiorTestowy;
	delete [] tablica;
}
