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
		stringstream sstreambuf; //��������� ����� 
		fin.open("input.txt", ios::in);
		if (!fin)
		{
			exception ex("\n��� �����\n");
			throw ex;
		}
		if (fin.peek() == -1)
		{
			exception ex("\n��� ������\n");
			throw ex;
		}
		while (!fin.eof()) {//��������� �� ����������� 
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
					cout << "� " << c << " ������\n";
					exception ex("\n������: ��� ������ ����� �����������");
					throw ex;
				}
				s = copy(input, j + 1);
				string temp, tmp = sstreambuf.str(); //������������ ����� ������, ������� ������ ��������� ������ 
				sstreambuf.str(""); //�������� ����� ������������ � ��������� ������ 
				sstreambuf << s << tmp;
				input = my_erase(input, j + 1);//������� ������������ ����������� 
			}
		}
		getline(sstreambuf, l);
		cout << l;
		fin.close();//��������� ���� 
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl << endl;
	}
	system("pause");
	return 0;
}