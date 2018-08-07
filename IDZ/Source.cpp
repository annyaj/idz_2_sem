#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string.h>

using namespace std;

/* ������������ Func ���������� ������� ����� ����������������������, ��������� �� ������
���� � ������������������ ��������. ������� �������� - ��� �����, �������� - ������� ����� ����������������������. ������� ������ ���������� ��� ����������
1 - ���� �������� ������ ������??, -1 - ���� �� ������, 0 - ��� ������.*/

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

/* ������������ Generator ������� ���� �� �������� ����������: ������� ����� ��������������������, ��������� �� ������
����, � �� �����������. ������� ��������� - ��� �����, ������� ����� ���������������������� ������ ����, �� ����������. ������� ���������� ��� ����������
0 - ���� ������� ������, -1 - ������������ ������� ���������, -2 - ���������� ������� ���� � ��������� �����������.
int Generator(fstream& f, float length, int quantity)
{
	
}
*/

int main()
{
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
	} while (choice != 3);
	return 0;
}
