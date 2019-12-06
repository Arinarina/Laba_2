#include "func.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{

	setlocale(LC_ALL, "Rus");
	try
	{
		ifstream fin;
		long file_size;
		int j = 0, c = 0;
		string s = " ", input, l;
		stringstream sstreambuf; //строковый поток 
		fin.open("input.txt", ios::in);
		if (!fin)
		{
			exception ex("\nНет файла\n");
			throw ex;
		}
		if (fin.peek() == -1)
		{
			exception ex("\nНет данных\n");
			throw ex;
		}
		while (!fin.eof()) {//считываем по предложению 
			s = "";
			c++;
			getline(fin, input);
			if (input.length() == 0)
				continue;
			while (input.length() != 0)
			{
				j = find_first_of(input);
				if (j == -1)
				{
					cout << "В " << c << " строке\n";
					exception ex("\nОшибка: нет знаков конца предложения");
					throw ex;
				}
				s = copy(input, j + 1);
				string temp, tmp = sstreambuf.str(); //возвращается копия строки, которую хранит потоковый объект 
				sstreambuf.str(""); //аргумент будет копироваться в потоковый объект 
				sstreambuf << s << tmp;
				input = my_erase(input, j + 1);//удаляем обработанное предложение 
			}
		}
		getline(sstreambuf, l);
		cout << l;
		fin.close();//закрываем файл 
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
	system("pause");
	return 0;
}