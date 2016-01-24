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
	for (int i = 0; i < size; i++) {
		int j = int(rand() / RAND_MAX * size);
		if (j == size)
			j -= 1;
		int t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
}

/*
int mediana(int a[], int size)
{
	int middle;
	if (size % 2 == 0)
		middle = a[size / 2];
	else
		middle = a[(size - 1) / 2];
	int b[3] = {a[0], middle, a[size - 1]};
	insertion_sort(b, size);
	return b[1];
}

int mediana_losowe(int a[], int size)
{
	int i = int(rand() / RAND_MAX * size);
	if (i == size)
		i = 0;
	int j = int(rand() / RAND_MAX * size);
	if (j == size)
		j = 0;
	int k = int(rand() / RAND_MAX * size);
	if (j == size)
		k = 0;
	int b[3] = {i, j, k};
	insertion_sort(b, size);
	return b[1];
}

int Tukey(int a[], int size)
{
	int ninth = size / 9;
	int b[9];
	for (int i = 0; i < size; i * ninth)
		b[i] = a[i * ninth];
	int j[3] = {b[0], b[1], b[2]};
	int k[3] = {b[3], b[4], b[5]};
	int l[3] = {b[6], b[7], b[8]};
	return mediana(mediana(j, 2), mediana(k, 2), mediana(l, 2));
}
*/


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



