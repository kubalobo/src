/*************************************************************************
*
*  Quick sort algorithm
*  A reference implementation
*
*  Author: Jacek Marciniak
*
*************************************************************************/

#include <iostream>

using namespace std;


// exchanges values
inline void exch(int a[], int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

// partitioning
int partition(int a[], int lo, int hi)
{
	int i = lo;
	int j = hi + 1;

	while (true)
	{
		while (a[++i] < a[lo]) // find item on left to swap
		{
			if (i == hi)
			{
				break;
			}
		}

		while (a[--j] > a[lo]) // find item on right to swap
		{
			if (j == lo)
			{
				break;
			}
		}

		if (i >= j) // check if pointers cross
		{
			break;
		}

		exch(a, i, j); // swap
	}

	// swap with partitioning item
	exch(a, lo, j);

	// return index of partitioning item
	return j;
}

// quick sort
void quick_sort(int a[], int lo, int hi)
{
	if (hi <= lo) return;         // stop when nothing to sort

	int j = partition(a, lo, hi); // partition
	quick_sort(a, lo, j - 1);     // sort left half
	quick_sort(a, j + 1, hi);     // sort right half
}

// sort the whole array (translate arguments)
void quick_sort(int a[], int size)
{
	quick_sort(a, 0, size -1);
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
	quick_sort(a, size);

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
