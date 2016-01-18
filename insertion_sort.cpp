/*************************************************************************
*
*  Insertion sort algorithm
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

// insertion sort
void insertion_sort(int a[], int size)
{
	for (int i = 1; i < size; i++)
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
	insertion_sort(a, size);

	// print the sorted array
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}

	// clean up
	delete[] a;

	return 0;
}*/
