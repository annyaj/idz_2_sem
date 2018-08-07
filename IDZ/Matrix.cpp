#include "Matrix.h"
#include <iostream>
using namespace std;





int Matrix::get_rows()
{
	return rows;
}

int Matrix::get_cols()
{
	return cols;
}

void Matrix::change_cols(int c1, int c2)
{
	for (int i = 0; i < cols; i++)
	{
		swap(mass[i][c1], mass[i][c2]);
	}
}

void Matrix::change_rows(int r1, int r2)
{
	for (int i = 0; i < rows; i++)
	{
		swap(mass[r1][i], mass[r2][i]);
	}
}

void Matrix::set_elem(int i, int j, double elem)
{
	mass[i][j] = elem;
}

void Matrix::get_elem(int i, int j, double & elem)
{
	elem = mass[i][j];
}

Matrix::~Matrix()
{
}

void Matrix::do_empty()
{
	for (int i = 0; i < rows; i++)
		delete[] mass[i];
	delete[] mass;
}
