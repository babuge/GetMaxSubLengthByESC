#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int getMaxSubListLength(const vector<int>& ls, int pos, int last, int max)
{
	if (pos > ls.size())
	{
		return max;
	}
	int maxLast = max;
	for (int i = pos; i < ls.size(); ++i)
	{
		if (ls[i] > last)
		{
			++maxLast;
			int len = getMaxSubListLength(ls, i + 1, ls[i], maxLast);
			if (len > max)
			{
				max = len;
			}
			--maxLast;
		}
	}
	return max;
}

int getSubMaxLen(const vector<int>& ls)
{
	int max = 1;
	for (int i = 0; i < ls.size(); ++i)
	{
		int len = getMaxSubListLength(ls, i + 1,ls[i], 1);
		if (max < len)
		{
			max = len;
		}
	}
	return max;
}

int main(void)
{
	int m;
	cout << "�������鳤�ȣ�";
	while (cin >> m)
	{
		if (m > 0)
		{
			int len = m;
			vector<int> vct(m, 0);
			cout << "��������(" << m << ")ֵ��" << endl;
			while (m--)
			{
				cin >> vct[len - m - 1];
			}
			cout << "vector<int>:" << endl;
			for (int i = 0; i < len; ++i)
			{
				cout << vct[i] << " ";
			}
			cout << endl;

			cout << "������������������г����Ƕ��٣�" << endl;
			cout << getSubMaxLen(vct) << endl;
			cout << "�������鳤�ȣ�";
		}
		else
		{
			break;
		}
	}

	return 0;
}