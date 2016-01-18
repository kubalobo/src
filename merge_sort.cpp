/*************************************************************************
*
*  Merge sort algorithm
*  A reference implementation
*
*  Author: Jacek Marciniak
*
*************************************************************************/

#include <iostream>

using namespace std;


// merge operation
void merge(int a[], int aux[], int lo, int mid, int hi)
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
}

// merge sort
void merge_sort(int a[], int aux[], int lo, int hi)
{
	if (hi <= lo) return;       // stop when nothing to sort
	int mid = (lo + hi) / 2;    // find middle

	merge_sort(a, aux, lo, mid);      // sort left half  
	merge_sort(a, aux, mid + 1, hi);  // sort right half
	merge(a, aux, lo, mid, hi);       // merge arrays
}

// merge sort
void merge_sort(int a[], int size)
{
	int* aux = new int[size];
	merge_sort(a, aux, 0, size - 1);
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
	merge_sort(a, size);

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
