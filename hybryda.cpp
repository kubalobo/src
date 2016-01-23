/*
 * hybryda.cpp
 *
 *  Created on: 21 sty 2016
 *      Author: Weronika
 */

#include <iostream>
#include "sort.h"

using namespace std;


// exchanges values
inline void exch(int a[], int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
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



