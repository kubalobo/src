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
// 3-way quick sort algorithm
// 3-way quick sort algorithm
void hybrid_3way_sort(int a[], int lo, int hi, int CUTOFF)
{

	if (hi <= lo + CUTOFF - 1) { // insertion_sort when tables are small

		int size = hi - lo;
		insertion_sort(a, size);
		return;
	}

	int lt = lo;
	int gt = hi;

	int i = lo;
	while (i <= gt)
	{
		if (a[i] < a[lt])
		{
			exch(a, lt++, i++);
		}
		else if (a[i] > a[lt])
		{
			exch(a, i, gt--);
		}
		else
		{
			i++;
		}
	}

	quick_sort_3way(a, lo, lt - 1);
	quick_sort_3way(a, gt + 1, hi);
}

// sort the whole array (translate arguments)
void hybrid_3way_sort(int a[], int size, int cutoff)
{
	hybrid_3way_sort(a, 0, size -1, cutoff);
}


/*

// test sorting
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
	hybrid_3way_sort(a, size, 3);

	// print the sorted array
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}

	// clean up
	delete[] a;

	return 0;
}
*/





