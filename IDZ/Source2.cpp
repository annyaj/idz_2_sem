#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctime>
#include "Matrix.h"

using namespace std;

void insertion_sort(int cols, int rows, Matrix& a)
{
	double* sum_array = new double[rows];
	double sum;
	double el;
	for (int i = 0; i < rows; i++)
	{
		sum = 0;
		for (int j = 0; j < cols; j++)
		{
			a.get_elem(i,j,el);
			sum += el;
		}
		sum_array[i] = sum;
	}

	int x = 0;
	for (int i = 0; i < rows; i++)
	{
		x = sum_array[i];
		int j = i;
		for (; j > 0 && sum_array[j - 1] > x; j--)
		{
			sum_array[j] = sum_array[j - 1];
		}
		sum_array[j] = x;
	}
	for (int i = 0; i < rows; i++)cout << sum_array[i] << " ";
}

int main()
{
	srand(time(0));
	Matrix a(3, 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int elem = rand() % 10;
			a.set_elem(i, j, elem);
			cout << elem << " ";
		}
		cout << endl;
	}
	insertion_sort(3, 3, a);
	_getch();
	return 0;
}
