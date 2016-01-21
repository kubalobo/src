#include <iostream>
#include <stdio.h>

#include "functions.h"
#include "sort.h"

using namespace std;

int main()
{
	int size = 10;

	char str[10];
	sprintf(str, "%d", size);

	int* tablica = new int[size];
					//argumenty: {pusty, typ R P A D, ilosc, zakresMin, zakresMax}
	char* arg[] = 	{"", "A", str, "0", "10"};

	tablica = arrgen(5, arg);

	//arrchk(tablica, size);

	for (int i = 0; i < size; i++)
			{
				cout << tablica[i] << " ";
			}

	bubble_sort(tablica, size);

	arrchk(tablica, size);

	for (int i = 0; i < size; i++)
		{
			cout << tablica[i] << " ";
		}

}
