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

void Element(int rows, int cols, Matrix& a)
{
	//double** array = 0;
	int i = 0, j = 0, c = 0, s = 0, chop = 0, kod = -1, l, f;
	double chislo = 0;
	system("cls");
	//if (cols <= 10) {
	while (chop != 3) {
		cout << "Таблица" << endl;
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
			cout << "Для изменения элемента:\n";
			cout << "1) Таблица с навигацией\n";
			cout << "2) Ввести местоположение элемента\n";
			cout << "3) Вернуться в меню\n";
			cin >> chop;
			system("cls");
		} while (chop != 1 && chop != 2 && chop != 3);
		if (chop == 2) {//через местоположение элемента

			do {
				system("cls");
				cout << "Введите номер строки, в которой находится элемент\n";
				kod = (scanf_s("%d", &i));
				if (cin.fail()) {
					system("cls");
					cout << "Ошибка ввода\n";
					cout << "\n";
				}
			} while (cin.fail() || i <= 0 || kod == 0 || i > rows);
			kod = -1;
			do {
				system("cls");
				cout << "Введите номер столбца, в котором находится элемент\n";
				kod = (scanf_s("%d", &j));
				if (cin.fail()) {
					system("cls");
					cout << "Ошибка ввода\n";
					cout << "\n";
				}
			} while (cin.fail() || j <= 0 || kod == 0 || j > cols);
			kod = -1;
			system("cls");
			a.get_elem(i - 1, j - 1, chislo);
			cout << "Элемент " << i << " строки, " << j << " столбца :" << chislo << endl;

			do {

				cout << "На какой элемент хотите поменять?\n";
				//kod = (scanf_s("%d", &chislo));
				cin >> chislo;
				if (cin.fail()) {
					system("cls");
					cout << "Ошибка ввода\n";
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
			cout << "Таблица : \n";
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
				cout << "Место элемента [" << s << "][" << c << "]" << endl;
				cout << "1)Изменить элемент\n";
				cout << "Навигация: 2-вниз,4-влево,6-вправо,8-вверх.\n";
				cout << "3)Выйти обратно в меню.\n";
				cin >> kod;

				switch (kod) {

				case(8): {
					system("cls");
					s--;
					if (s < 0) s = rows - 1;
					if (s >= rows) s = 0;
					cout << "Таблица : \n";
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
					cout << "Таблица : \n";
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
					cout << "Таблица : \n";
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
					cout << "Таблица : \n";
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
						cout << "Вы действительно хотите изменить этот элемент?\n";
						cout << "1)Да\n";
						cout << "2)Нет\n";
						cin >> kod;
					} while (kod != 1 && kod != 2);
					if (kod == 1) {
						/*do {
							cout << "Введите число на которое хотите заменить\n";
							//l = scanf_s("%d", &chislo);
							cin >> chislo;
							system("cls");
						} while (l == 0);
						l = 0;
						*/
						cout << "Введите число на которое хотите заменить\n";
						cin >> chislo;
						a.set_elem(s, c, chislo);
					}
					system("cls");
					cout << "Элемент был успешно изменён\n";
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
				cout << "Для изменения элемента:\n";
				cout << "1) Открыть таблицу\n";
				cout << "2) Ввести местоположение элемента\n";
				cout << "3) Вернуться в меню\n";
				cin >> chop;
				system("cls");
			} while (chop != 1 && chop != 2 && chop != 3);
			if (chop == 2) {//через местаположение элемента

				do {
					system("cls");
					cout << "Введите номер строки, в которой находится элемент\n";
					kod = (scanf_s("%d", &i));
					if (cin.fail()) {
						system("cls");
						cout << "Ошибка ввода\n";
						cout << "\n";
					}
				} while (cin.fail() || i <= 0 || kod == 0 || i > rows);
				kod = -1;
				do {
					system("cls");
					cout << "Введите номер столбца, в котором находится элемент\n";
					kod = (scanf_s("%d", &j));
					if (cin.fail()) {
						system("cls");
						cout << "Ошибка ввода\n";
						cout << "\n";
					}
				} while (cin.fail() || j <= 0 || kod == 0 || j > cols);
				kod = -1;
				system("cls");
				a.get_elem(i - 1, j - 1, chislo);
				printf("Элемент %d строчки,%d столбца: %d \n", i, j, chislo);

				do {
					system("cls");
					cout << "На какой элемент хотите поменять?\n";
					kod = (scanf_s("%d", &chislo));
					if (cin.fail()) {
						system("cls");
						cout << "Ошибка ввода\n";
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
				cout << "Таблица : \n";
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
					cout << "Место элемента [" << s << "][" << c << "]" << endl;
					cout << "1)Изменить элемент\n";
					cout << "3)Выйти обратно в меню.\n";
					cin >> kod;

					switch (kod) {

					case(8): {
						system("cls");
						s--;
						if (s < 0) s = rows - 1;
						if (s >= rows) s = 0;
						cout << "Таблица : \n";
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
						cout << "Таблица : \n";
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
						cout << "Таблица : \n";
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
						cout << "Таблица : \n";
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
							cout << "Вы действительно хотите изменить этот элемент?\n";
							cout << "1)Да\n";
							cout << "2)Нет\n";
							cin >> kod;
						} while (kod != 1 && kod != 2);
						if (kod == 1) {
							do {
								cout << "Введите число на которое хотите заменить\n";
								l = scanf_s("%d", &chislo);
								system("cls");
							} while (l == 0);
							l = 0;
							a.set_elem(s, c, chislo);
						}
						system("cls");
						cout << "Элемент был успешно изменён\n";
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
			system("pause");

		}
		if (choice == 3)
		{

			cout << endl << "Введите имя файла" << endl;
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
	return 0;
}
