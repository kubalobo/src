#include <iostream>
#include <stdio.h>

#include "functions.h"
#include "sort.h"

using namespace std;

int main()
{
	int size = 10;

	char str[10];
	sprintf(str, "%d", size);		//zamiana size na string ( 10 na "10" bo w takiej formie lyknie to arrgen )

	int* tablica = new int[size];	// tutaj moze byc problem ???

					//argumenty: {pusty, typ R P A D, ilosc(size), zakresMin, zakresMax}
	char* arg[] = 	{"", "A", str, "0", "10"};

	tablica = arrgen(5, arg);

	//arrchk(tablica, size);		//check czy posortowana, chyba dzialal dopoki arrgen sie nie popsul


	//testowe wypisanie
	for (int i = 0; i < size; i++)
	{
		cout << tablica[i] << " ";
	}

/*
	//bubble_sort(tablica, size);

	arrchk(tablica, size);

	for (int i = 0; i < size; i++)
	{
		cout << tablica[i] << " ";
	}
*/

}
