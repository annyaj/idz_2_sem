#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <ctime>
#include <vector>
#include <stdlib.h>
using namespace std;

/* Подпрограмма Func определяет среднюю длину подпоследовательностей, состоящих из четных
цифр в последовательности символов. Входное параметр - имя файла, выходной - средняя длина подпоследовательностей. Функция должна возвращать код завершения
1 - если возникла ошибка чтения, -1 - файл не открыт, 0 - все хорошо.*/

bool even(int);

int Func(fstream& f, float& answ)
{
	char sym;
	int count = 0, sum = 0, k = 0;
	int flag=0;
	if (!f.is_open())flag=-1;
	else
	{
		while (!f.eof() || flag==1)
		{
			f.get(sym);
			if (f.fail())flag = 1;		
			if ((sym == '0') || (sym == '2') || (sym == '4') || (sym == '6') || (sym == '8'))count++;
			else
			{
				if (count > 0)
				{
					sum += count;
					count = 0;
					k++;
				}
			}
			flag = 0;
		}
		if (k == 0)answ = 0;
		else answ = sum / k;
	}
	return flag;
}

char get_random_ch(bool(*func)(int))//получаем рандомный четный символ
{
	int ch;
	do {
		ch = rand() % 10;
	} while (!func(ch));
	return (char)ch;
}
int sum_dl_str(vector<string>& g)//сумма длинн строк
{
	int s = g.size();
	int count = 0;
	for (int i = 0; i < s; i++)
	{
		count += g.at(i).length();
	}
	return count;
}
string get_trash() //получаем строку мусора
{
	string s = "";
	int a = rand() % 3 + 3;
	char w;
	for (int i = 0; i < a; i++)
	{
		w=(char)(rand() % (90 - 65) + 65);
		s += w;
	}
	return s;
}
/* Подпрограмма Generator создает файл по заданным параметрам: средней длине подследовательностей, состоящих из четных
цифр, и их колличеству. Входные параметры - имя файла, средняя длина подпоследовательностей четных цифр, их количество. Функция возвращает код завершения
0 - файл успешно создан, -1 - файл не существует(некуда записывать), -2 - некорректные параметры.*/
int Generator(fstream& f, float length, int quantity)
{
	int flag;
	float a = length * quantity;
	if (!f.is_open())flag= -1;
	else if ((int)a != a || length < 0 || quantity < 0)flag = -2; 
	else {

		string* st = new string[quantity];

		vector<string> str;
		char p;
		for (int i = 0; i < quantity; i++)
		{
			p = get_random_ch(even);
			string d = "";
			d += to_string(p);
			str.push_back(d);
		}
		//cout << (sum_dl_str(str) / quantity) << " " << length << endl;
		while ((sum_dl_str(str) / quantity) < length)
		{
			int d = rand() % str.size();
			str.at(d) += to_string(get_random_ch(even));
			//cout << (sum_dl_str(str) / quantity) << " " << length<<endl;
		}
		string result = "";
		for (int i = 0; i < quantity; i++)
		{
			result += get_trash();
			result += str.at(i);
		}result += get_trash();
		f << result;
		flag = 0;
	}
	return flag;
}

bool even(int x)
{
	return x == 0 || x == 2 || x == 4 || x == 6 || x==8;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "RUS");
	char name[20];
	float length = 0;
	int flag = 0;
	int choice;
	do
	{
		system("cls");
		cout << "1. Сгенерировать файл" << endl;
		cout << "2. Посчитать среднюю длину подпоследовательностей четных цифр" << endl;
		cout << "3. Выход" << endl;
		cout << "Выберите 1-3: "; cin >> choice;

		if (choice == 1)
		{
			float av_length;
			int quantity;
			cout << "Введите имя файла: ";
			cin >> name;
			cout << "Введите среднюю длину: ";
			cin >> av_length;
			cout << "Введите количество подпоследовательностей: ";
			cin >> quantity;
			fstream f(name,ios::out);
			int res=Generator(f, av_length, quantity);
			if (res == 0)cout << "Файл создан успешно.";
			if (res == -1)cout << "Создайте пустой файл.";
			if (res == -2)cout << "Некоректные параметры.";
			f.close();
		}
		if (choice == 2)
		{
			cout << "Введите имя файла:\n\n";
			cin >> name;
			fstream file(name, ios::in);
			flag = Func(file, length);
			if (flag == 0)
			{
				cout << "\nСредняя длина подпоследовательностей из четных цифр равна " <<length;
			}
			else
			{
				cout << "\nВсе не очень хорошо:(\n";
				if (flag == 1)
					cout << "\nОшибка чтения";
				else
					cout << "\nНе удается открыть файл";
			}
			_getch();

		}
		if (choice == 3)
			system("pause");
		_getch();
	} while (choice != 3);
	return 0;
}
