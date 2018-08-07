#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string.h>

using namespace std;

/* Подпрограмма Func определяет среднюю длину подпоследовательностей, состоящих из четных
цифр в последовательности символов. Входное параметр - имя файла, выходной - средняя длина подпоследовательностей. Функция должна возвращать код завершения
1 - если возникла ошибка чтения??, -1 - файл не открыт, 0 - все хорошо.*/

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

/* Подпрограмма Generator создает файл по заданным параметрам: средней длине подследовательностей, состоящих из четных
цифр, и их колличеству. Входные параметры - имя файла, средняя длина подпоследовательностей четных цифр, их количество. Функция возвращает код завершения
0 - файл успешно создан, -1 - некорректные входные параметры, -2 - невозможно создать файл с заданными параметрами.
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
	} while (choice != 3);
	return 0;
}
