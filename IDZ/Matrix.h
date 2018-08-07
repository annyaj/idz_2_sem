#pragma once
using namespace std;
class Matrix
{
	double** mass;
	int cols, rows;
public:
	Matrix(int cols,int rows)
	{
		mass = new double*[cols];
		for (int i = 0; i < cols; i++)
		{
			mass[i] = new double[rows];
		}
		this->cols = cols;
		this->rows = rows;
	}
	int get_rows();
	int get_cols();
	void change_cols(int c1, int c2);
	void change_rows(int r1, int r2);
	void set_elem(int i, int j, double elem);
	void get_elem(int i, int j, double& elem);
	~Matrix();
	void do_empty();
};

