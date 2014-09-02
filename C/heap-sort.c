#include <stdio.h>


void max_heapify(int a[], int i)
{
	int largest;
	int temp;

	int l = 2*i;
	int r = 2*i + 1;

	if(l <= heapsize && a[l]  > a[i])
	{
		largest = l;

	}
	else
	{
		largest = i;
	}

	if(r <= heapsize && a[r] > largest)
	{
		largest = r;
	}
	if(largest != i)
	{
		temp = a[i];
		a[i] = largest;
		largest = temp;
		max_heapify(a, largest);
	}

}

void build_max_heap(int a[])
{
	int heapsize;
	int i;
	heapsize = a[].length;
	for(i=(a[].length)/2 - 1; i >= 1; i--)
	{
		max_heapify(a, 0);
	}
}

void heapsort(int a[])
{
	int temp;
	int i;
	build_max_heap(a);
	for(i = a.length; i > 0; i--)
	{
		temp = a[1];
		a[1] = a[i];
		a[i] = temp;

		heapsize = heapsize - 1;
		max_heapify(a,1);
	}
}

void main()
{
	int i,j;
	int a[5];
	printf("enter the 5 elements");
	for(i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
	}

	heapsort(a);

	printf("Sorted array is:");

	for(j = 0; j < 5; j++)
	{
		printf("%d", a[j]);
	}
}