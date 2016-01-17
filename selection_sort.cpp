/*************************************************************************
*
*  Selection sort algorithm
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

// selection sort
void selection_sort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int k = i;
		for (int j = i + 1; j < size; j++)
		{
			if (a[j] < a[k])
			{
				k = j;
			}
		}
		exch(a, k, i);
	}
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
	selection_sort(a, size);

	// print the sorted array
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}

	// clean up
	delete[] a;

	return 0;
}
