#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <ctime>
#include <vector>
#include <stdlib.h>
using namespace std;

/* ������������ Func ���������� ������� ����� ����������������������, ��������� �� ������
���� � ������������������ ��������. ������� �������� - ��� �����, �������� - ������� ����� ����������������������. ������� ������ ���������� ��� ����������
1 - ���� �������� ������ ������??, -1 - ���� �� ������, 0 - ��� ������.*/


bool even(int);
bool five(int);
bool prime(int);

int Func(fstream& f, float& answ)
{
	char sym;
	int count = 0, sum = 0, k = 0;
	int flag=0;
	if (!f.is_open())flag=-1;
	else
	{
		while (!f.eof())
		{
			
			f.get(sym);		
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
		answ = sum / k;
	}
	return flag;
}

char get_random_ch(bool(*func)(int))
{
	int ch;
	do {
		ch = rand() % 10;
	} while (!func(ch));
	return (char)ch;
}
int sum_dl_str(vector<string>& g)
{
	int s = g.size();
	int count = 0;
	for (int i = 0; i < s; i++)
	{
		count += g.at(i).length();
	}
	return count;
}
string get_tr()
{
	string s = "";
	int a = rand() % 3 + 3;
	char w;
	for (int i = 0; i < a; i++)
	{
		w=(char)(rand() % (90 - 65) + 65);
		//cout << "sym=" << w;
		s += w;
		//cout <<"str="<< s<<endl;
	}
	return s;
}
/* ������������ Generator ������� ���� �� �������� ����������: ������� ����� ��������������������, ��������� �� ������
����, � �� �����������. ������� ��������� - ��� �����, ������� ����� ���������������������� ������ ����, �� ����������. ������� ���������� ��� ����������
0 - ���� ������� ������, -1 - ������������ ������� ���������, -2 - ���������� ������� ���� � ��������� �����������.*/
int Generator(fstream& f, float length, int quantity)
{
	if (!f.is_open())return -1;
	int flag = 0;
	float a = length * quantity;
	if ((int)a != a) return 0;

	string* st = new string[quantity];
	
	vector<string> str;
	char p;
	for (int i = 0; i < quantity; i++)
	{
		p = get_random_ch(prime);
		string d = "";
		d+=to_string(p);
		str.push_back(d);
	}
	//cout << (sum_dl_str(str) / quantity) << " " << length << endl;
	while ((sum_dl_str(str) / quantity) < length)
	{
		int d = rand() % str.size();
		str.at(d)+=to_string(get_random_ch(prime));
		//cout << (sum_dl_str(str) / quantity) << " " << length<<endl;
	}
	string result = "";
	for (int i = 0; i < quantity; i++)
	{
		result += get_tr();
		result += str.at(i);
	}result += get_tr();
	f << result;
	return 0;
}

bool even(int x)
{
	return x % 2 == 0;
}
bool five(int x)
{
	return x == 5;
}
bool prime(int x)
{
	return x == 1 || x == 2 || x == 3 || x == 7;
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
		cout << "1. ������������� ����" << endl;
		cout << "2. ��������� ������� ����� ���������������������� ������ ����" << endl;
		cout << "3. �����" << endl;
		cout << "�������� 1-3: "; cin >> choice;

		if (choice == 1)
		{
			float av_length;
			int quantity;
			cout << "������� ��� �����: ";
			cin >> name;
			cout << "������� ������� �����: ";
			cin >> av_length;
			cout << "������� ���������� ����������������������: ";
			cin >> quantity;
			fstream f(name,ios::out);
			Generator(f, av_length, quantity);
			f.close();

		}
		if (choice == 2)
		{
			cout << "������� ��� �����:\n\n";
			cin >> name;
			fstream file(name, ios::in);
			flag = Func(file, length);
			if (flag == 0)
			{
				cout << "\n������� ����� ���������������������� �� ������ ���� ����� " <<length;
			}
			else
			{
				cout << "\n��� �� ����� ������:(\n";
				if (flag == 1)
					cout << "\n������ ������";
				else
					cout << "\n�� ������� ������� ����";
			}
			_getch();

		}
		if (choice == 3)
			system("pause");
		_getch();
	} while (choice != 3);
	return 0;
}
