#include "pch.h"
#include "stdio.h"
#include "math.h"
#include <iostream>
#define n 5
void matrix(int a[n][n]);
double func(int b[n][n],double r[n]);

void main(void)
{
	int a[n][n], i, j;
	double F,r[n];
	for (i = 0; i < n; i++)
	{ 
		for (j = 0; j < n; j++)
		{
			printf("a[%d][%d]=", i + 1, j + 1);
			scanf_s("%d", &a[i][j]);
		}
	}
	matrix(a);
	func(a,r);
	for (i = 0; i < n; i++)
	F = 1;
	for (i = 0; i < n; i++) 
	{		
		F *=r[i];
	}
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
		{
			printf("%5d", a[i][j]);
		}
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("f(a%d)=%lf", i, r[i]);
	}
	printf("Fij=%lf", F);
}
double func(int a[n][n], double r[n])
{
	int i, j;
	double d;
	for (i = 0; i < n; i++)
	{  
		d = 1;
		for (j = 0; j < n; j++)
		{
			d = d * a[i][j];
		}
		d = pow(fabs(d),0.2);
		r[i] = d;
	}
	return 0;
}

 
void matrix(int a[n][n])
{
	int i,k, j,c;
	for (i = 0; i < n; i++)
	{
		for (k = 0; k < n; k++)
		{
			for (j = 0; j < n-1; j++)
			{
				if (a[i][j] > a[i][j+1])
				{
					c = a[i][j];
					a[i][j] = a[i][j+1];
					a[i][j+1] = c;
				}
			}
		}
	}

}