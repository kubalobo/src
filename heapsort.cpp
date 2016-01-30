/*************************************************************************
*
*  Heapsort algorithm
*  Author: Krzysztof Soka³a
*
*************************************************************************/

inline void exch(int a[], int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
} 

void heap_control (int a[], int size, int i)
{
	int max;
	int lo = 2*i;  
	int ro = (2*i) + 1; 
	if ( (lo <= size) && (a[lo] > a[i]) )
		max=lo;
	else 
		max=i;
	if ( (ro <= size) && (a[ro] > a[max]) )
		max=ro;
	
	if (max!=i)
	{
		exch(a,i,max);
		heap_control(a,size,max);
	}
}

void heap_create(int a[], int size)
{
	for (int i = size/2;  i > 0;  i--)
		heap_control(a,size, i);
}
 
void heap_sort(int a[], int size)
{     
	heap_create(a, size);
	for (int i = size;  i > 1;  i--)
	{
		exch(a,i,1);
		size--;
		heap_control(a, size, 1);
	}
}
 


