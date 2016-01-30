/*************************************************************************
*
*  Shell sort algorithm
*  original Shell sequence
*
*  Author: Krzysztof Soka³a
*
*************************************************************************/


// exchanges values
inline void exch(int a[], int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}


//shell sort
void shell_sort(int a[], int size)
{ 
	int i,j, gap;
	for (gap = size/2; gap > 0; gap /= 2)
		for (i = gap; i < size; i++) 
			for (j = i-gap; (j>=0 && a[j]>a[j+gap]); j-=gap) 
				exch(a, j, j+gap);
}

