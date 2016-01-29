/*************************************************************************
*
*  Array generator for testing sorting algorithms
*
*  Author: Jacek Marciniak
*
*************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;


//////////////////////////////////////////////////////////////////////////
// Helpers
//////////////////////////////////////////////////////////////////////////

// generate a next random integer
int nextrand()
{
	return ((rand() & 0x7F) << 24) | 
	       ((rand() & 0xFF) << 16) | 
		   ((rand() & 0xFF) << 8) | 
		    (rand() & 0xFF);
}

// generate a next random integer in the range of [minv,maxv]
int nextrand(int minv, int maxv)
{
	return nextrand() % (maxv - minv + 1) + minv;
}

// swaps two values
inline void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

// inverts two numbers:
// if values are in order swaps them and returns 1, otherwise returns 0
inline int invert(int& a, int& b)
{
	if (a < b)
	{
		swap(a, b);
		return 1;
	}
	else
	{
		return 0;
	}
}

//////////////////////////////////////////////////////////////////////////
// Array generators
//////////////////////////////////////////////////////////////////////////

// print error message
void error_message()
{
	// error message
	cerr << "How to use the program:" << endl;
	cerr << "arrgen R 100 0 1000  - 100 random numbers from range [0,1000]" << endl;
	cerr << "arrgen P 100 20      - 100 partially sorted numbers with 20 inversions" << endl;
	cerr << "arrgen A 100         - 100 sorted numbers: 0, 1, 2, ..., 99" << endl;
	cerr << "arrgen D 100         - 100 numbers sorted in descending order: 99, 98, ..., 0" << endl;
}

// generate an array of specified size
// containing random numbers in range [minv, maxv]
int* array_random(int size, int minv, int maxv, int target[])
{
	//cout << size << endl;
	for (int i = 0; i < size; i++)
	{
		//cout << nextrand(minv, maxv) << " ";
		target[i] = nextrand(minv, maxv);
	}
	return target;
}

// generate a partially sorted array
// with specified number of inversions
int* array_partially_sorted(int size, int inv, int target[])
{
	// check correctness
	if (inv > ((long long)size * (size - 1)) / 2)
	{
		cerr << "Too many inversions..." << endl;
		return 0;
	}

	// generate a sorted array
	int *a = new int[size];
	for (int i = 0; i < size; i++)
	{
		a[i] = i;
	}
	
	// make inversions
	while (inv > 0)
	{
		int i = nextrand(1, size - 1);
		inv -= invert(a[i - 1], a[i]);
	}
	
	// print an array
	cout << size << endl;
	for (int i = 0; i < size; i++)
	{
		target[i] = a[i];
		//cout << a[i] << " ";
	}

	return target;
	// clean up
	delete [] a;
}

// generate an array sorted in the ascending order
int* array_ascending(int size, int* target)
{
	//cout << size << endl;
	for (int i = 0; i < size; i++)
	{
		target[i] = i;
	}
	return target;
}

// generate an array sorted in the descending order
int* array_descending(int size, int* target)
{
	cout << size << "Kupa" << endl;
	for (int i = size - 1; i >=0; i--)
	{
		target[i] = size-i;
	}
	return target;
}

//////////////////////////////////////////////////////////////////////////
// main entry to the program
//////////////////////////////////////////////////////////////////////////

int* arrgen(int argc, char* argv[])
{
	// check if there are at least 2 arguments
	if (argc <= 2)
	{
		error_message();
		return 0;
	}

	// initialize the random number generator
	srand((int)time(NULL));

	// parse an array size
	int size = atoi(argv[2]);
	if (size <= 0) size = 1;

	int* target = new int[size];

	// parse options
	if (argc > 4 && !strcmp(argv[1], "R"))
	{
		int minv = atoi(argv[3]); // parse random values range
		int maxv = atoi(argv[4]);
		if (maxv < minv) maxv = minv;

		return array_random(size, minv, maxv, target);
	}
	else if (argc > 3 && !strcmp(argv[1], "P"))
	{
		int inv = atoi(argv[3]); // parse number of inversions
		if (inv < 0) inv = 0;

		return array_partially_sorted(size, inv, target);
	}
	else if (!strcmp(argv[1], "A"))
	{
		return array_ascending(size, target);
	}
	else if (!strcmp(argv[1], "D"))
	{
		return array_descending(size, target);
	}
	else
	{
		error_message();
	}
		
	return 0;
}
