#include <iostream>
#include <stdio.h>
#include <Windows.h>

#include "functions.h"
#include "sort.h"

using namespace std;



int main()
{
	int size = 10000;

	char str[10];
	sprintf(str, "%d", size);		//zamiana size na string ( 10 na "10" bo w takiej formie lyknie to arrgen )

	int* zbiorTestowy = new int[size];
	int* tablica = new int[size];


//	tablica = arrgen(5, arg);
//	arrchk(tablica, size);		//check czy posortowana, chyba dzialal dopoki arrgen sie nie popsul



//	//testowe wypisanie
//		for (int i = 0; i < size; i++)
//		{
//			cout << tablica[i] << " ";
//		}

	double start;
	double end;

//----------------------------------------------------
// Test 1 - random
	char* arg[] = 	{"", "R", str, "0", "10"}; 	//argumenty: {pusty, typ R P A D, ilosc(size), zakresMin, zakresMax}

	cout << "Losowanie tablicy - ";
	zbiorTestowy = arrgen(5, arg);
	arrchk(zbiorTestowy, size);					//jaka jest tablica
	cout << endl << endl;


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





}
