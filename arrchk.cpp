/*************************************************************************
*
*  A tiny tool for checking if an array is sorted
*  Counts a number of elements and checks if they are sorted
*  in ascending or descending order or all equal
*
*  Author: Jacek Marciniak
*
*************************************************************************/

#include <iostream>

using namespace std;


int arrchk(int* arr, int size)
{
	int a, b;
	int type = 0;

	a = arr[0];

	for(int i = 0; i < size; i++)
	{
		b = arr[i];
			if (type == 0 && a < b) type = 1;
			else if (type == 0 && a > b) type = 2;
			else if (type == 1 && a > b) type = 3;
			else if (type == 2 && a < b) {type = 3;  break;}

		a = b;
	}
	
	const char* stype[] = { "equal", "ascending", "descending", "none" };
	cout << stype[type];
	return 0;
}
