#include "pch.h"
#include "stdio.h"
#include "math.h"
#define n 5
void bubble_sort(int matrix[n][n]);
void calculate_geom_average_of_each_line(int b[n][n], double r[n]);
//my comment

void main(void)
{
	int matrix[n][n], line, column;
	double dobutok = 1, geom_average_of_each_line[n];
	for (line = 0; line < n; line++)
	{
		for (column = 0; column < n; column++)
		{
			printf("a[%d][%d]=", line + 1, column + 1);
			scanf_s("%d", &matrix[line][column]);
		}
	}
	bubble_sort(matrix);
	calculate_geom_average_of_each_line(matrix, geom_average_of_each_line);
	for (line = 0; line < n; line++)
	{
		dobutok *= geom_average_of_each_line[line];
	}
	for (line = 0; line < n; line++)
	{
		printf("\n");
		for (column = 0; column < n; column++)
		{
			printf("%5d", matrix[line][column]);
		}
	}
	printf("\n");
	for (line = 0; line < n; line++)
	{
		printf("f(a%d)=%lf", line, geom_average_of_each_line[line]);
	}
	printf("Fij=%lf", dobutok);
}
void calculate_geom_average_of_each_line(int matrix[n][n], double geom_average_each_line[n])
{
	int line, column;
	double dobutok;
	for (line = 0; line < n; line++)
	{
		dobutok = 1;
		for (column = 0; column < n; column++)
		{
			dobutok = dobutok * matrix[line][column];
		}
		dobutok = pow(fabs(dobutok), 0.2);
		geom_average_each_line[line] = dobutok;
	}
}


void bubble_sort(int matrix[n][n])
{
	for (int line = 0; line < n; line++)
	{
		for (int count = 0; count < n; count++)
		{
			for (int column = 0; column < n - 1; column++)
			{
				swap_if_decrement(matrix[line][column], matrix[line][column + 1]);

			}
		}
	}

}

void swap_if_decrement(int &a, int &b)
{
	if (a > b) 
	{
		int temp = a;
		a = b;
		b = temp;
	}
}