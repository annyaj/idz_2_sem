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



int Integral(double(*f)(double), double a, double b, int quant, double accuracy, double& I1)
{
	int flag = 0;
	double I = 0, step = 0, x;
	if (quant <= 0 || accuracy>1)flag = -1;
	else
	{
		while (flag == 0)
		{
			step = (b - a) / quant;
			for (x = a; x <= b; x += step)
			{
				I = I + 2 * (*f)(x);
			}
			I = step * 0.5 *(I + (*f)(a) + (*f)(b));
			quant=quant*2;
			step = (b - a) / quant;
			for (x = a; x <= b; x += step)
			{
				I1 = I1 + 2 * (*f)(x);
			}
			I1 = step * 0.5 *(I1 + (*f)(a) + (*f)(b));
			if (abs(I1 - I) <= accuracy)
			{
				flag = 1;
				break;
			}
		}
		
	}
	return flag;
}
int main()
{
	setlocale(LC_ALL, "RUS");
	double(*f)(double) = NULL;
	char namefile[30];
	char code[100];
	int choice = 0;
	int quant,result=0;
	double step, a, b, res, accuracy,I;
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
		

		if (choice == 1)
		{
			system("cls");
			cout << endl << endl << "	Введите нижний и верхний пределы интегригования:" << endl;
			cin >> a >> b;
			cout << endl << endl << "	Введите число разбиений:" << endl;
			cin >> quant;
			cout << endl << endl << "	Введите точность разбиений:" << endl;
			cin >> accuracy;
			f = &func1;
			result=Integral(f, a, b, quant, accuracy,I);
			if (result == -1)cout << "Uncorrect parameters!";
			else cout << "Values of integral = " << I;
			system("pause");
		}


		if (choice == 2)
		{

			system("cls");
			cout << endl << endl << "	Введите нижний и верхний пределы интегригования:" << endl;
			cin >> a >> b;
			cout << endl << endl << "	Введите число разбиений:" << endl;
			cin >> quant;
			cout << endl << endl << "	Введите точность разбиений:" << endl;
			cin >> accuracy;
			f = &func2;
			result = Integral(f, a, b, quant, accuracy, I);
			if (result == -1)cout << "Uncorrect parameters!";
			else cout << "Values of integral = " << I;
			system("pause");
		}


		if (choice == 3)
		{

			system("cls");
			cout << endl << endl << "	Введите нижний и верхний пределы интегригования:" << endl;
			cin >> a >> b;
			cout << endl << endl << "	Введите число разбиений:" << endl;
			cin >> quant;
			cout << endl << endl << "	Введите точность разбиений:" << endl;
			cin >> accuracy;
			f = &test_f1;
			result = Integral(f, a, b, quant, accuracy, I);
			if (result == -1)cout << "Uncorrect parameters!";
			else cout << "Values of integral = " << I<<endl;
			double F_N_L = pow(b, 4) / 4 + 5 * b - pow(a, 4) / 4 - 5 * a;
			cout << "По формуле Н-Л = " << F_N_L << endl;
			system("pause");
		}

		if (choice == 4)
		{
			system("cls");
			cout << endl << endl << "	Введите нижний и верхний пределы интегригования:" << endl;
			cin >> a >> b;
			cout << endl << endl << "	Введите число разбиений:" << endl;
			cin >> quant;
			cout << endl << endl << "	Введите точность разбиений:" << endl;
			cin >> accuracy;
			f = &test_f2;
			result = Integral(f, a, b, quant, accuracy, I);
			if (result == -1)cout << "Uncorrect parameters!";
			else cout << "Values of integral = " << I << endl;
			double F_N_L = 2 * (b + 1)* pow(b + 1, 0.5) / 3 - 2 * (a + 1)* pow(a + 1, 0.5) / 3;
			cout << "По формуле Н-Л=" << F_N_L << endl;
			system("pause");
		}
		system("cls");
		cout << "1. Первый интеграл " << endl;
		cout << "2. Второй интеграл" << endl;
		cout << "3. Тестовый интеграл (1)" << endl;
		cout << "4. Тестовый интеграл (2)" << endl;
		cout << "5. Выход" << endl;
		cout << "Выберите 1-5:" << endl;
		cin >> choice;
		system("cls");
		if (choice == 5)
		{
			system("cls");
			break;
		}

	}

	return 0;
}