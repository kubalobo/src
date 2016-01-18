/*************************************************************************
*
*  Bottom-up merge sort algorithm
*  A reference implementation
*
*  Author: Jacek Marciniak
*
*************************************************************************/

#include <iostream>

using namespace std;

// returns minimum of 2 values
inline int min(int a, int b)
{
	return a < b ? a : b;
}

//Zdefiniowano w merge_sort.cpp
void merge(int a[], int aux[], int lo, int mid, int hi);

// merge operation
/*void merge(int a[], int aux[], int lo, int mid, int hi)
{
	// copy
	for (int k = lo; k <= hi; k++)
	{
		aux[k] = a[k];
	}

	// merge
	int i = lo, j = mid + 1;
	for (int k = lo; k <= hi; k++)
	{
		if (i > mid)              a[k] = aux[j++]; // left array empty
		else if (j > hi)          a[k] = aux[i++]; // right array empty
		else if (aux[j] < aux[i]) a[k] = aux[j++]; // right value lower
		else                      a[k] = aux[i++]; // left value lower
	}
}*/

// merge sort - bottom-up version
void merge_sort_bottom_up(int a[], int aux[], int size)
{
	for (int sz = 1; sz < size; sz += sz)
	{
		for (int lo = 0; lo < size - sz; lo += sz + sz)
		{
			int hi = min(lo + sz + sz - 1, size - 1);
			merge(a, aux, lo, lo + sz - 1, hi);
		}
	}
}

// merge sort - bottom-up version
void merge_sort_bottom_up(int a[], int size)
{
	int* aux = new int[size];
	merge_sort_bottom_up(a, aux, size);
	delete[] aux;
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
	merge_sort_bottom_up(a, size);

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
