#include <iostream>
#include <conio.h>
#include "Dequeue.h"
#include <fstream>

using namespace std;

bool Invert(Dequeue& a)
{
	char l, r;
	Dequeue copy = Dequeue(a);
	bool flag = true;
	while (!a.isEmpty() && !copy.isEmpty())
	{
		a.pop_front(l);
		copy.pop_back(r);
		if (l != r)flag=false;
	}
	return flag;
}
void ReadFile(fstream& f, Dequeue& a)
{
	char sym;
	if (!f.is_open())return;
	do
	{
		f.get(sym);
		a.push_front(sym);
	} while (!f.eof());
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int choice, error = 0;
	char elem;
	char name[20];
	Dequeue cur;
	do
	{
		system("cls");
		cout << "1. �������� ������� � ������ ����." << endl;
		cout << "2. �������� ������� � ����� ����." << endl;
		cout << "3. ������� ������ ������� ����." << endl;
		cout << "4. ������� ��������� ������� ����." << endl;
		cout << "5. ������� ������� ���." << endl;
		cout << "6. ���������, �������� �� ����� ������������." << endl;
		cout << "7.File" << endl;
		cout << "8.�����" << endl;
		cout << "������� �����: ";
		cin >> choice;
		cout << endl;
		if (choice == 1)
		{
			cout << "������� �������: ";
			cin >> elem;
			cur.push_front(elem);
		}
		if (choice == 2)
		{
			cout << "������� �������: ";
			cin >> elem;
			cur.push_back(elem);

		}
		if (choice == 3)
		{
			cur.pop_front(elem);
			cout << "��������� �������:" << elem;
		}
		if (choice == 4)
		{
			cur.pop_back(elem);
			cout << "��������� �������:" << elem;
		}
		if (choice == 7)
		{
			cout <<"Input name of file";
			cin >> name;
			fstream file(name, ios::in);
			ReadFile(file, cur);
		}
		if (choice == 5)
		{
			for (auto i = cur.begin(); i != cur.end(); ++i)
			{
				cout << *i <<" ";
			}
			system("pause");
		}
		if (choice == 6)
		{
			bool a=Invert(cur);
			if (a == true)cout << "Yeeeees";
			else cout << "Not invert";
			system("pause");
		}
		
		if (choice == 8)system("pause");
		else cout << "������." << endl;
	} while (choice != 8);

	//cur.push_back('1');
	//cur.push_back('2');
	//cur.push_back('h');
	//cur.push_back('1');
	//cur.push_back('h');
	//cur.push_back('2');
	//cur.push_back('1');
	
	/*for (auto i = cur.begin(); i != cur.end(); ++i)
	{
		cout << *i<<" ";
	}

	bool a = Invert(cur);
	if (a == true)cout <<"Wwwww";
	else cout << ":(";
	*/
	

	_getch();
	return 0;
}