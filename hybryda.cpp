/*
 * hybryda.cpp
 *
 *  Created on: 21 sty 2016
 *      Author: Weronika
 */

#include <iostream>
#include "sort.h"
#include <cstdlib>

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
	for (int i = 0; i < a; i++) {
		int j = int(rand() * size / RAND_MAX);
		if (j == size)
			j -= 1;
		int t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
}

int mediana(int a[], int size)
{
	int middle;
	if (size % 2 == 0)
		middle = a[size / 2];
	else
		middle = a[(size - 1) / 2];
	int b[3] = {a[0], middle, a[size - 1]};
	insertion_sort(b, size);
	return 0;
}

// quick sort
void hybrid_sort(int a[], int lo, int hi, int CUTOFF)
{
	if (hi <= lo + CUTOFF - 1) { // insertion_sort when tables are small

		int size = hi - lo;
		insertion_sort(a, size);
		return;
	}

	int j = partition(a, lo, hi); // partition
	quick_sort(a, lo, j - 1);     // sort left half
	quick_sort(a, j + 1, hi);     // sort right half
}

// sort the whole array (translate arguments)
void hybrid_sort(int a[], int size, int cutoff)
{
	hybrid_sort(a, 0, size -1, cutoff);
}



/*// test sorting
int main(int argc, char* argv[])
{
	// read a size of data
	int size = 0;
	cin >> size;

	// read an array
	int* a = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}

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



