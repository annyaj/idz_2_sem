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
			if (f.fail())flag = 1;
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

char get_random_ch(bool(*func)(int))//�������� ��������� ������ ������
{
	int ch;
	do {
		ch = rand() % 10;
	} while (!func(ch));
	return (char)ch;
}
int sum_dl_str(vector<string>& g)//����� ����� �����
{
	int s = g.size();
	int count = 0;
	for (int i = 0; i < s; i++)
	{
		count += g.at(i).length();
	}
	return count;
}
string get_trash() //�������� ������ ������
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
/* ������������ Generator ������� ���� �� �������� ����������: ������� ����� ��������������������, ��������� �� ������
����, � �� �����������. ������� ��������� - ��� �����, ������� ����� ���������������������� ������ ����, �� ����������. ������� ���������� ��� ����������
0 - ���� ������� ������, -1 - ���� �� ����������(������ ����������), -2 - ������������ ���������.*/
int Generator(fstream& f, float length, int quantity)
{
	int flag;
	if (!f.is_open())flag= -1;
	float a = length * quantity;
	if ((int)a != a) flag=-2;

	string* st = new string[quantity];
	
	vector<string> str;
	char p;
	for (int i = 0; i < quantity; i++)
	{
		p = get_random_ch(even);
		string d = "";
		d+=to_string(p);
		str.push_back(d);
	}
	//cout << (sum_dl_str(str) / quantity) << " " << length << endl;
	while ((sum_dl_str(str) / quantity) < length)
	{
		int d = rand() % str.size();
		str.at(d)+=to_string(get_random_ch(even));
		//cout << (sum_dl_str(str) / quantity) << " " << length<<endl;
	}
	string result = "";
	for (int i = 0; i < quantity; i++)
	{
		result += get_trash();
		result += str.at(i);
	}result += get_trash();
	f << result;
	flag= 0;
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
			int res=Generator(f, av_length, quantity);
			if (res == 0)cout << "���� ������ �������.";
			if (res == -1)cout << "�������� ������ ����.";
			if (res == -2)cout << "����������� ���������.";
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
