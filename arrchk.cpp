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


int main(int argc, char* argv[])
{
	int a, b, count = 0;
	int type = 0;
	while (cin >> b)
	{
		if (count++)
		{
			if (type == 0 && a < b) type = 1;
			else if (type == 0 && a > b) type = 2;
			else if (type == 1 && a > b) type = 3;
			else if (type == 2 && a < b) type = 3;
		}
		a = b;
	}
	
	const char* stype[] = { "equal", "ascending", "descending", "none" };
	cout << count << "," << stype[type];
	return 0;
}
