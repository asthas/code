#include <stdio.h>
#include <stdlib.h>

countingsort(int a[], int b[], int n, int k)
{
	int i, j;
	int c[50];
	for(i = 0; i <= k; i++)
	{
		c[i] = 0;
	}
	for(j = 0; j < n; j++)
	{
		c[a[j]] = c[a[j]] + 1;

	}
	for(i = 1; i <= k; i++)
	{
		c[i] = c[i] + c[i-1];
	}
	for(j = n-1; j >= 0; j--)
	{
		b[c[a[j]] - 1] = a[j];
		c[a[j]] = c[a[j]] - 1;
	}
}

void main()
{
	int a[100];
	int b[100];
	int i, j;
	int n, k;
	int max = 0;

	printf("Enter the size of array");
	scanf("%d", &n);

	printf("Enter the elements of the array\n");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for(i = 0;i < n; i++)
	{
		if(a[i] > max)
		{
			max = a[i];
		}
	}

	k=max;

	countingsort(a, b, n, k);

	printf("Sorted array:\n");
	for(j = 0;j < n; j++)
	{
		printf("%d\n", b[j]);
	}

}