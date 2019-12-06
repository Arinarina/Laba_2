#include "func.h"

string my_erase(string s, int end)
{
	string s1;
	int size = s.size(), k = 0;
	s1.resize(s.length() - end);
	s.resize(s.length() + 1);
	size = s.size();
	for (int i = end; i < size; ++i, ++k)
	{
		s1[k] = s[i];
	}
	return s1;
}
int find_first_of(string s)
{
	int num = 0;
	int size = s.size();
	int k;
	bool flag = false;
	for (k = 0; k <= size - 1; k++)
	{
		if (size == 1 && k == 0)
		{
			exception ex("\nОшибка: Не верное предложение\n");
			throw ex;
		}
		if (s[k] == '.' || s[k] == '!' || s[k] == '?' || (s[k] == ' ' && k == 0))
		{
			int kk = k, j = 0;
			flag = false;
			if (s[kk] == ' ' && kk == 0) flag = true;
			if (s[kk + 1] == ' ')
			{
				j = kk + 1;
				while (s[j] == ' ' && j <= (size - 1)) j++;
				if (j == size)
				{
					exception ex("\nОшибка: Не верное предложение\n");
					throw ex;
				}
				kk = j - 1;
			}
			if (s[kk + 1] == '.' || s[kk + 1] == '!' || s[kk + 1] == '?')
			{
				exception ex("\nОшибка: Не верное предложение\n");
				throw ex;
			}
			if (!flag)
			{
				num = k;
				break;
			}
		}
	}
	if (k == size) num = -1;
	return num;
}
string copy(string s, int end)
{
	string s1;
	s1.resize(end);
	int size = s.size();
	int k = 0;
	for (; k < end; ++k)
	{
		s1[k] = s[k];
	}
	return s1;
}