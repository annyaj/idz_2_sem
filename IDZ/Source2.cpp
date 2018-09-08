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
			cout << elem << "\t";
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
			cout << "������� �������."<<endl;
			cin >> elem;
			a.set_elem(i,j,elem);
		}
	}
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			a.get_elem(i,j,elem);
			cout << elem <<"\t";
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
				cout << elem << "\t";
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
		f << "�������" << endl << endl;
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

void Element(int rows, int cols, Matrix& a)
{
	//double** array = 0;
	int i = 0, j = 0, c = 0, s = 0, chop = 0, kod = -1, l, f;
	double chislo = 0;
	system("cls");
	//if (cols <= 10) {
	while (chop != 3) {
		cout << "�������" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{

				a.get_elem(i, j, chislo);
				cout << chislo << "\t";
			}
			cout << endl;
		}
		do {
			cout << "��� ��������� ��������:\n";
			cout << "1) ������� � ����������\n";
			cout << "2) ������ �������������� ��������\n";
			cout << "3) ��������� � ����\n";
			cin >> chop;
			system("cls");
		} while (chop != 1 && chop != 2 && chop != 3);
		if (chop == 2) {//����� �������������� ��������

			do {
				system("cls");
				cout << "������� ����� ������, � ������� ��������� �������\n";
				kod = (scanf_s("%d", &i));
				if (cin.fail()) {
					system("cls");
					cout << "������ �����\n";
					cout << "\n";
				}
			} while (cin.fail() || i <= 0 || kod == 0 || i > rows);
			kod = -1;
			do {
				system("cls");
				cout << "������� ����� �������, � ������� ��������� �������\n";
				kod = (scanf_s("%d", &j));
				if (cin.fail()) {
					system("cls");
					cout << "������ �����\n";
					cout << "\n";
				}
			} while (cin.fail() || j <= 0 || kod == 0 || j > cols);
			kod = -1;
			system("cls");
			a.get_elem(i - 1, j - 1, chislo);
			cout << "������� " << i << " ������, " << j << " ������� :" << chislo << endl;

			do {

				cout << "�� ����� ������� ������ ��������?\n";
				//kod = (scanf_s("%d", &chislo));
				cin >> chislo;
				if (cin.fail()) {
					system("cls");
					cout << "������ �����\n";
					cout << "\n";
				}
			} while (cin.fail() || kod == 0);
			kod = -1;
			a.set_elem(i - 1, j - 1, chislo);
		}

		if (chop == 1) {
			kod = -1;
			s = 0, c = 0;
			system("cls");
			cout << "������� : \n";
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					if ((i == s) && (j == c)) {
						a.get_elem(s, c, chislo);
						cout << "<" << chislo << ">" << "\t";
					}
					else {
						a.get_elem(i, j, chislo);
						cout << chislo;
						cout << "\t";
					}
				}
				cout << "\n";
			}
			while (kod != 3) {
				cout << "����� �������� [" << s << "][" << c << "]" << endl;
				cout << "1)�������� �������\n";
				cout << "���������: 2-����,4-�����,6-������,8-�����.\n";
				cout << "3)����� ������� � ����.\n";
				cin >> kod;

				switch (kod) {

				case(8): {
					system("cls");
					s--;
					if (s < 0) s = rows - 1;
					if (s >= rows) s = 0;
					cout << "������� : \n";
					for (int i = 0; i < rows; i++) {
						for (int j = 0; j < cols; j++) {
							if ((i == s) && (j == c)) {
								a.get_elem(s, c, chislo);
								cout << "<" << chislo << ">" << "\t";
							}
							else {
								a.get_elem(i, j, chislo);
								cout << chislo;
								cout << "\t";
							}
						}
						cout << "\n";
					}
					break;
				}


				case(2): {
					system("cls");
					s++;
					if (s < 0) s = rows - 1;
					if (s >= rows) s = 0;
					cout << "������� : \n";
					for (int i = 0; i < rows; i++) {
						for (int j = 0; j < cols; j++) {
							if ((i == s) && (j == c)) {
								a.get_elem(s, c, chislo);
								cout << "<" << chislo << ">" << "\t";
							}
							else {
								a.get_elem(i, j, chislo);
								cout << chislo;
								cout << "\t";
							}
						}
						cout << "\n";
					}
					break;
				}

				case(4): {
					system("cls");
					c--;
					if (c < 0) c = cols - 1;
					if (c > cols) c = 0;
					cout << "������� : \n";
					for (int i = 0; i < rows; i++) {
						for (int j = 0; j < cols; j++) {
							if ((i == s) && (j == c)) {
								a.get_elem(s, c, chislo);
								cout << "<" << chislo << ">" << "\t";
							}
							else {
								a.get_elem(i, j, chislo);
								cout << chislo;
								cout << "\t";
							}
						}
						cout << "\n";
					}
					break;
				}

				case(6): {
					system("cls");
					c++;
					if (c < 0) c = cols - 1;
					if (c >= cols) c = 0;
					cout << "������� : \n";
					for (int i = 0; i < rows; i++) {
						for (int j = 0; j < cols; j++) {
							if ((i == s) && (j == c)) {
								a.get_elem(s, c, chislo);
								cout << "<" << chislo << ">" << "\t";
							}
							else {
								a.get_elem(i, j, chislo);
								cout << chislo;
								cout << "\t";
							}
						}
						cout << "\n";
					}
					break;
				}

				case(1): {
					system("cls");
					do {
						cout << "�� ������������� ������ �������� ���� �������?\n";
						cout << "1)��\n";
						cout << "2)���\n";
						cin >> kod;
					} while (kod != 1 && kod != 2);
					if (kod == 1) {
						/*do {
							cout << "������� ����� �� ������� ������ ��������\n";
							//l = scanf_s("%d", &chislo);
							cin >> chislo;
							system("cls");
						} while (l == 0);
						l = 0;
						*/
						cout << "������� ����� �� ������� ������ ��������\n";
						cin >> chislo;
						a.set_elem(s, c, chislo);
					}
					system("cls");
					cout << "������� ��� ������� ������\n";
					for (int i = 0; i < rows; i++) {
						for (int j = 0; j < cols; j++) {
							if ((i == s) && (j == c)) {
								a.get_elem(s, c, chislo);
								cout << "<" << chislo << ">" << "\t";
							}
							else {
								a.get_elem(i, j, chislo);
								cout << chislo;
								cout << "\t";
							}
						}
						cout << "\n";
					}
					system("pause");
					break;
				}


				}
			}system("cls");
		}
	}
}

	/*
	else {
		while (chop != 3) {
			do {
				cout << "��� ��������� ��������:\n";
				cout << "1) ������� �������\n";
				cout << "2) ������ �������������� ��������\n";
				cout << "3) ��������� � ����\n";
				cin >> chop;
				system("cls");
			} while (chop != 1 && chop != 2 && chop != 3);
			if (chop == 2) {//����� �������������� ��������

				do {
					system("cls");
					cout << "������� ����� ������, � ������� ��������� �������\n";
					kod = (scanf_s("%d", &i));
					if (cin.fail()) {
						system("cls");
						cout << "������ �����\n";
						cout << "\n";
					}
				} while (cin.fail() || i <= 0 || kod == 0 || i > rows);
				kod = -1;
				do {
					system("cls");
					cout << "������� ����� �������, � ������� ��������� �������\n";
					kod = (scanf_s("%d", &j));
					if (cin.fail()) {
						system("cls");
						cout << "������ �����\n";
						cout << "\n";
					}
				} while (cin.fail() || j <= 0 || kod == 0 || j > cols);
				kod = -1;
				system("cls");
				a.get_elem(i - 1, j - 1, chislo);
				printf("������� %d �������,%d �������: %d \n", i, j, chislo);

				do {
					system("cls");
					cout << "�� ����� ������� ������ ��������?\n";
					kod = (scanf_s("%d", &chislo));
					if (cin.fail()) {
						system("cls");
						cout << "������ �����\n";
						cout << "\n";
					}
				} while (cin.fail() || kod == 0);
				kod = -1;
				a.set_elem(i - 1, j - 1, chislo);
			}

			if (chop == 1) {
				kod = -1;
				s = 0, c = 0;
				f = 10;
				l = 0;
				system("cls");
				cout << "������� : \n";
				for (int i = 0; i < rows; i++) {
					for (int j = 0; j < f; j++) {
						if ((i == s) && (j == c)) {
							a.get_elem(s, c, chislo);
							cout << "<" << chislo << ">" << "\t";
						}
						else {
							a.get_elem(i, j, chislo);
							cout << chislo;
							cout << "\t";
						}
					}
					cout << "\n";
				}
				while (kod != 3) {
					cout << "����� �������� [" << s << "][" << c << "]" << endl;
					cout << "1)�������� �������\n";
					cout << "3)����� ������� � ����.\n";
					cin >> kod;

					switch (kod) {

					case(8): {
						system("cls");
						s--;
						if (s < 0) s = rows - 1;
						if (s >= rows) s = 0;
						cout << "������� : \n";
						for (int i = 0; i < rows; i++) {
							for (int j = l; j < f; j++) {
								if ((i == s) && (j == c)) {
									a.get_elem(s, c, chislo);
									cout << "<" << chislo << ">" << "\t";
								}
								else {
									a.get_elem(i, j, chislo);
									cout << chislo;
									cout << "\t";
								}
							}
							cout << "\n";
						}
						break;
					}


					case(2): {
						system("cls");
						s++;
						if (s < 0) s = rows - 1;
						if (s >= rows) s = 0;
						cout << "������� : \n";
						for (int i = 0; i < rows; i++) {
							for (int j = l; j < f; j++) {
								if ((i == s) && (j == c)) {
									a.get_elem(s, c, chislo);
									cout << "<" << chislo << ">" << "\t";
								}
								else {
									a.get_elem(i, j, chislo);
									cout << chislo;
									cout << "\t";
								}
							}
							cout << "\n";
						}
						break;
					}

					case(4): {
						system("cls");
						c--;
						if (c == l - 1) {
							f = l;
							l = f - 10;
						}
						if (c < 0) {
							c = cols - 1;
							f = cols;
							l = cols - 10;
						}
						if (c > cols) c = 0;
						cout << "������� : \n";
						for (int i = 0; i < rows; i++) {
							for (int j = l; j < f; j++) {
								if ((i == s) && (j == c)) {
									a.get_elem(s, c, chislo);
									cout << "<" << chislo << ">" << "\t";
								}
								else {
									a.get_elem(i, j, chislo);
									cout << chislo;
									cout << "\t";
								}
							}
							cout << "\n";
						}
						break;
					}

					case(6): {
						system("cls");
						c++;
						if (c == f)
						{
							f = f + 10;
							l = f;
						}
						if (c < 0) c = cols - 1;
						if (c >= cols) {
							f = 10;
							l = 0;
							c = 0;
						}
						cout << "������� : \n";
						for (int i = 0; i < rows; i++) {
							for (int j = l; j < f; j++) {
								if ((i == s) && (j == c)) {
									a.get_elem(s, c, chislo);
									cout << "<" << chislo << ">" << "\t";
								}
								else {
									a.get_elem(i, j, chislo);
									cout << chislo;
									cout << "\t";
								}
							}
							cout << "\n";
						}
						break;
					}

					case(1): {
						system("cls");
						do {
							cout << "�� ������������� ������ �������� ���� �������?\n";
							cout << "1)��\n";
							cout << "2)���\n";
							cin >> kod;
						} while (kod != 1 && kod != 2);
						if (kod == 1) {
							do {
								cout << "������� ����� �� ������� ������ ��������\n";
								l = scanf_s("%d", &chislo);
								system("cls");
							} while (l == 0);
							l = 0;
							a.set_elem(s, c, chislo);
						}
						system("cls");
						cout << "������� ��� ������� ������\n";
						system("pause");
						break;
					}


					}
				}
			}
		}
	}
}
*/

int main()
{
	setlocale(LC_ALL,"Rus");
	char name[30];
	int cols, rows;
	cout << "������� ������� �������." << endl;
	cin >> cols >> rows;
	Matrix a(cols, rows);
	cols = a.get_cols();
	rows = a.get_rows();
	int choice=1;
	while (choice != 7)
	{
		system("cls");

		cout << "1. ���������� ������� ���������� �������." << endl;
		cout << "2. ���������� ������� � ����������." << endl;
		cout << "3. ���������� ������� � �����." << endl;
		cout << "4. ��������." << endl;
		cout << "5. ���������� ���������." << endl;
		cout << "6. ���������� ������� � ����. " << endl;
		cout << "7. �����." << endl;
		cout << "������� �����:" << endl << endl;
		cin >> choice;

		if (choice == 1)
		{
			Rand_filling(a);
			system("pause");
		}
		if (choice == 2)
		{
			Keyboard_filling(a);
			system("pause");

		}
		if (choice == 3)
		{

			cout << endl << "������� ��� �����" << endl;
			cin >> name;
			fstream file(name, ios::in);
			Filling_from_file(file,a);
			system("pause");

		}
		if (choice == 4)
		{

			Element(rows, cols, a);
		}
		if (choice == 5)
		{

			insertion_sort(cols,rows,a);
			system("pause");
		}
		if (choice == 6)
		{
			cout << "������� ��� �����";
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
	return 0;
}
