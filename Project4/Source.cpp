#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <math.h>
using namespace std;


double func1(double x)
{
	double f = log(x) / (x * log(x + 1));
	return f;
}

double func2(double x)
{
	double f = pow(x, (sin(x)));
	return f;
}

double test_f1(double x)
{
	double f = pow(x, 3) + 5;
	return f;
}

double test_f2(double x)
{
	double f = pow(x+1, 0.5);
	return f;
}

int kol = 500;

double Integral(double(*f)(double), double a, double b)
{
	double sum = 0.0, x0 = a, x1;
	double step = (b - a) / kol;
	for (int i = 0; i < kol - 1; i++)
	{
		x1 = x0 + step;
		sum += step * 0.5*(f(x0)+f(x1));
		x0 = x1;
	}
	return sum;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	double(*f)(double) = NULL;
	char namefile[30];
	char code[100];
	int choice, number_of_iteration;
	double step, a,b,res;

	cout << "1. Первый интеграл " << endl;
	cout << "2. Второй интеграл" << endl;
	cout << "3. Тестовый интеграл (1)" << endl;
	cout << "4. Тестовый интеграл (2)" << endl;
	cout << "5. Выход" << endl;
	cout << "Выберите 1-5:" << endl;
	cin >> choice;
	system("cls");
	while (choice != 5)
	{

		// 1 ИНТЕГРАЛ

		if (choice == 1)
		{
			system("pause");
			system("cls");
			cout << endl << endl << "	Введите нижний и верхний пределы интегригования:" << endl;
			cin >> a >> b;
			cout << endl << endl << "	Введите число разбиений:" << endl;
			/*cin >> number_of_segments;
			cout << endl << endl << "	Введите точность вычислений:" << endl;
			cin >> accuracy_of_calculation;
			cout << endl << endl << "	Введите число итераций:" << endl;
			cin >> number_of_iteration;
			*/
			f = &func1;
			res=Integral(f,a,b);
			cout << "Result = " << res<<endl;
			system("pause");
		}

		// 2 ИНТЕГРАЛ

		if (choice == 2)
		{
			/*I = 0;
			double x(0);
			int flag(0), k(2), i;
			*/
			system("pause");
			system("cls");
			cout << endl << endl << "	Введите нижний и верхний пределы интегригования:" << endl;
			cin >> a >> b;
			cout << endl << endl << "	Введите число разбиений:" << endl;
			/*cin >> number_of_segments;
			cout << endl << endl << "	Введите точность вычислений:" << endl;
			cin >> accuracy_of_calculation;
			cout << endl << endl << "	Введите число итераций:" << endl;
			cin >> number_of_iteration;
			*/
			f = &func2;
			res = Integral(f, a, b);
			cout << "Result = " << res << endl;
			system("pause");
		}

		// 1 ТЕСТ

		if (choice == 3)
		{
			/*I = 0;
			double x, eps, NL;
			int flag(0), k(2), i;
			*/
			system("pause");
			system("cls");
			cout << endl << endl << "	Введите нижний и верхний пределы интегригования:" << endl;
			cin >> a >> b;
			cout << endl << endl << "	Введите число разбиений:" << endl;
			/*cin >> number_of_segments;
			cout << endl << endl << "	Введите точность вычислений:" << endl;
			cin >> accuracy_of_calculation;
			cout << endl << endl << "	Введите число итераций:" << endl;
			cin >> number_of_iteration;
			*/
			f = &test_f1;
			res = Integral(f, a, b);
			cout << "Result = " << res << endl;
			double F_N_L=pow(b,4)/4+5*b - pow(a, 4) / 4 - 5 * a;
			cout << "По формуле Н-Л=" << F_N_L << endl;
			system("pause");
		}

		// 2 ТЕСТ

		if (choice == 4)
		{
			/*I = 0;
			double x, eps, NL;
			int flag(0), k(2), i;
			*/
			system("pause");
			system("cls");
			cout << endl << endl << "	Введите нижний и верхний пределы интегригования:" << endl;
			cin >> a >> b;
			cout << endl << endl << "	Введите число разбиений:" << endl;
			/*cin >> number_of_segments;
			cout << endl << endl << "	Введите точность вычислений:" << endl;
			cin >> accuracy_of_calculation;
			cout << endl << endl << "	Введите число итераций:" << endl;
			cin >> number_of_iteration;
			*/
			f = &test_f2;
			res = Integral(f, a, b);
			cout << "Result = " << res << endl;
			double F_N_L = 2 * (b + 1)* pow(b + 1, 0.5)/3 - 2 * (a + 1)* pow(a + 1, 0.5)/3;
			cout << "По формуле Н-Л=" << F_N_L << endl;
			system("pause");
		}
		system("cls");
		cout << "1. Интеграл 1." << endl;
		cout << "2. Интеграл 2." << endl;
		cout << "3. Тестовый интеграл 1." << endl;
		cout << "4. Тестовый интеграл 2." << endl;
		cout << "5. Выход." << endl;
		cout << "Введите пункт:" << endl;
		cout << endl;
		cin >> choice;
		system("cls");
	}
	if (choice== 5)
	{
		system("cls");
		cout << endl << "Всем пока:)!" << endl << endl;
		system("pause");
	}
	return 0;
}