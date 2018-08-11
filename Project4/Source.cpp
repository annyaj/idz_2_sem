#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;


double func(double x)
{
	return log(x) / (x * log(x + 1));
}

int kol = 500;

double integral(double(*f)(double), double a, double b)
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
	double a, b;
	cin >> a;
	cin >> b;
	cout << integral(func,a,b);
	_getch();
	return 0;
}