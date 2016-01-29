/*
 * hybryda.cpp
 *
 *  Created on: 21 sty 2016
 *      Author: Weronika
 */

#include <iostream>
#include "sort.h"
#include <cstdlib>
#include <time.h>
#include "functions.h"
#include <algorithm>

using namespace std;


// exchanges values
inline void exch(int a[], int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void mix(int a[], int size)  // mieszanie tablicy
{

	for (int i = 0; i < size; i++) {
		int j = nextrand(0, size - 1);
		int t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
}

int mediana(int a[], int size)
{
	int b[3] = {a[0], a[size / 2], a[size - 1]};
	if (b[0] <= b[1])
	{
		if (b[0] >= b[2]) return b[0];
		else return (b[1] <= b[2] ? b[1] : b[2]);
	}
	else
	{
		if (b[0] <= b[2]) return b[0];
		else return (b[1] >= b[2] ? b[1] : b[2]);
	}
	return b[1];
}

int mediana_losowe(int a[], int lo, int hi)
{
	int i = nextrand(lo, hi);
	int j = nextrand(lo, hi);
	int k = nextrand(lo, hi);
//	cout << endl << a[i] << ' ' << a[j] << ' ' << a[k] << endl;
	int b[3] = {a[i], a[j], a[k]};
	return mediana(b, 3);
}

int Tukey(int a[], int lo, int hi)
{
	int eighth = (hi - lo + 1) / 8;
	int b[9];
	for (int i = 0; i < 9; i++)
		b[i] = a[lo + (i * eighth)];

	int j[3] = {b[0], b[1], b[2]};
	int k[3] = {b[3], b[4], b[5]};
	int l[3] = {b[6], b[7], b[8]};
	int j_med = mediana(j, 3);
	int k_med = mediana(k, 3);
	int l_med = mediana(l, 3);
	int med[3] = {j_med, k_med, l_med};
	return mediana(med, 3);
}

// insertion sort
void insertion_sort(int a[], int lo, int hi)
{
	for (int i = lo; i < hi + 1; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (a[j] < a[j - 1])
			{
				exch(a, j, j - 1);
			}
			else
			{
				break;
			}
		}
	}
}

// quick sort
/*void quick_sort_hybryda(int a[], int lo, int hi, int tryb)
{
	if (hi <= lo) return;         // stop when nothing to sort

	int wybrano;

	if(tryb == 0)
	{}
	else if(tryb == 1)
	{
		wybrano = mediana_losowe(a, hi + 1);
		*find(a, a + hi + 1, wybrano) = a[0];
		a[0] = wybrano;
		//exch(a, *find(a, a + hi, wylosowano),0);
	}
	else if(tryb == 2)
	{
		wybrano = Tukey(a, hi + 1);
		*find(a, a + hi + 1, wybrano) = a[0];
		a[0] = wybrano;
	}

	int j = partition(a, lo, hi); // partition
	quick_sort_hybryda(a, lo, j - 1, tryb);     // sort left half
	quick_sort_hybryda(a, j + 1, hi, tryb);     // sort right half
}*/
//
//// sort the whole array (translate arguments)
//void quick_sort_hybryda(int a[], int size)
//{
//	quick_sort(a, 0, size -1);
//}


// quick sort z wyborem trybu partycjonowania
void hybrid_sort(int a[], int lo, int hi, int CUTOFF, int tryb)
{
	if (hi <= lo + CUTOFF - 1) { // insertion_sort when tables are small
		insertion_sort(a, lo, hi);
		return;
	}

	//Tryb partycjonowania
	int wybrano;

	if(tryb == 0)
	{}
	else if(tryb == 1)
	{
		wybrano = mediana_losowe(a, lo, hi);
		*find(a + lo, a + hi, wybrano) = a[0];
		a[lo] = wybrano;
	}
	else if(tryb == 2)
	{
		wybrano = Tukey(a, lo, hi);
		*find(a + lo, a + hi, wybrano) = a[0];
		a[lo] = wybrano;
	}

	int j = partition(a, lo, hi); // partition
	hybrid_sort(a, lo, j - 1, CUTOFF, tryb);     // sort left half
	hybrid_sort(a, j + 1, hi, CUTOFF, tryb);     // sort right half
}

// sort the whole array (translate arguments)
void hybrid_sort(int a[], int size, int cutoff, int tryb)
{
	hybrid_sort(a, 0, size -1, cutoff, tryb);
}


/*
// test sorting
int main(int argc, char* argv[])
{
	srand((int)time(NULL));
	// read a size of data
	int size = 0;
	cin >> size;

	// read an array
	int* a = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}

	//find mediana_losowe
	cout << endl << mediana_losowe(a, size) << endl;

	// sort the array
	hybrid_sort(a, size, 3);

	// print the sorted array
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}




	// clean up
	delete[] a;

	return 0;
}*/



