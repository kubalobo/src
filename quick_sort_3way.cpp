/*************************************************************************
*
*  3-way quick sort algorithm
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

// 3-way quick sort algorithm
void quick_sort_3way(int a[], int lo, int hi)
{
	if (hi <= lo) return; // stop when nothing to sort

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
void quick_sort_3way(int a[], int size)
{
	quick_sort_3way(a, 0, size - 1);
}

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
	quick_sort_3way(a, size);

	// print the sorted array
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}

	// clean up
	delete[] a;

	return 0;
}
