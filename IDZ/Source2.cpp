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

void Rand_filling(Matrix& a)
{
	srand(time(0));
	int cols = a.get_cols();
	int rows = a.get_rows();
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			double elem = rand() % 100;
			a.set_elem(i, j, elem);
			cout << elem << " ";
		}
		cout << endl;
	}
}

void Keyboard_filling(Matrix& a)
{
	int cols = a.get_cols();
	int rows = a.get_rows();
	double elem;
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << "Введите элемент."<<endl;
			cin >> elem;
			a.set_elem(i,j,elem);
		}
	}
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			a.get_elem(i,j,elem);
			cout << elem <<" ";
		}
		cout << endl;
	}
}

void Filling_from_file(fstream& f, Matrix& a)
{
	int cols = a.get_cols();
	int rows = a.get_rows();
	double elem;
	if (!f.is_open())return;
	else
	{
		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				f >> elem;
				a.set_elem(i, j, elem);
			}
		}
		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				a.get_elem(i, j, elem);
				cout << elem << " ";
			}
			cout << endl;
		}
	}
}

void Save_to_file(fstream& f, Matrix& a)
{
	int cols = a.get_cols();
	int rows = a.get_rows();
	double elem;
	if (!f.is_open())return;
	else
	{
		f << "Матрица" << endl << endl;
		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				a.get_elem(i, j, elem);
				f << elem << " ";
			}
			f << endl;
		}
	}
}


int main()
{
	setlocale(LC_ALL,"Rus");
	char name[30];
	int cols, rows;
	cout << "Введите размеры матрицы." << endl;
	cin >> cols >> rows;
	Matrix a(cols, rows);
	cols = a.get_cols();
	rows = a.get_rows();
	int choice=1;
	while (choice != 7)
	{
		system("cls");

		cout << "1. Заполнение матрицы случайными числами." << endl;
		cout << "2. Заполнение матрицы с клавиатуры." << endl;
		cout << "3. Заполнение матрицы с файла." << endl;
		cout << "4. Редактор." << endl;
		cout << "5. Сортировка вставками." << endl;
		cout << "6. Сохранение матрицы в файл. " << endl;
		cout << "7. Выход." << endl;
		cout << "Введите пункт:" << endl << endl;
		cin >> choice;

		if (choice == 1)
		{
			Rand_filling(a);
			system("pause");
		}
		if (choice == 2)
		{
			Keyboard_filling(a);
			system("payse");

		}
		if (choice == 3)
		{
			system("payse");
			cout << endl << "Введите имя файла" << endl;
			cin >> name;
			fstream file(name, ios::in);
			Filling_from_file(file,a);

		}
		if (choice == 4)
		{

			//Element(lines, cols, A);
		}
		if (choice == 5)
		{

			insertion_sort(cols,rows,a);
			system("pause");
		}
		if (choice == 6)
		{
			cout << "Введите имя файла";
			cin >> name;
			fstream file(name, ios::out);
			Save_to_file(file,a);
			file.close();
		}
		if (choice == 7)
		{
			break;
		}
	}

	_getch();
	return 0;
}
