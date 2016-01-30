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

inline int middle_elem(int a[], int i, int j, int k)
{
	if (a[i] <= a[j])
	{
		if (a[i] >= a[k]) return i;
		else return (a[j] <= a[k] ? j : k);
	}
	else
	{
		if (a[i] <= a[k]) return i;
		else return (a[j] >= a[k] ? j : k);
	}
}


int mediana_losowe(int a[], int lo, int hi)
{
	int i = nextrand(lo, hi);
	int j = nextrand(lo, hi);
	int k = nextrand(lo, hi);
	//cout << endl << a[i] << ' ' << a[j] << ' ' << a[k] << endl;
	return middle_elem(a, i, j, k);
}

int Tukey(int a[], int lo, int hi)
{
	int eighth = (hi - lo + 1) / 8;
	int mid = lo + (hi - lo) / 2;
	int j_med = middle_elem(a, lo, lo + eighth, lo + eighth + eighth);
	int k_med = middle_elem(a, mid - eighth, mid, mid + eighth);
	int l_med = middle_elem(a, hi - eighth - eighth, hi - eighth, eighth);
	return middle_elem(a, j_med, k_med, l_med);
}

// insertion sort
void insertion_sort(int a[], int lo, int hi)
{
	for (int i = lo; i <= hi + 1; i++)
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
		wybrano = middle_elem(a, lo, (hi+lo) / 2, hi);
		exch(a, wybrano, lo);
	}
	else if(tryb == 2)
		{
			wybrano = mediana_losowe(a, lo, hi);
			exch(a, wybrano, lo);
		}
	else if(tryb == 3)
	{
		wybrano = Tukey(a, lo, hi);
		exch(a, wybrano, lo);
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



