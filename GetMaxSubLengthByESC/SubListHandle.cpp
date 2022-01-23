#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class SubListHandle {
public:
	explicit SubListHandle(const vector<int>& list = {}) :m_list(list) {};

	~SubListHandle() { m_list.clear(); };

	void print()
	{
		for (int i = 0; i < m_list.size(); ++i)
		{
			cout << m_list.at(i) << " ";
		}
		cout << endl;
	}

	int getMaxSubLenByESC()
	{
		int max = 1;
		for (int i = 0; i < m_list.size(); ++i)
		{
			int len = getMaxSubLenByESC(i + 1, m_list.at(i), 1);
			if (max < len)
			{
				max = len;
			}
		}
		return max;
	};
private:
	int getMaxSubLenByESC(int pos, int last, int max)
	{
		if (pos > m_list.size())
		{
			return max;
		}
		int maxLast = max;
		for (int i = pos; i < m_list.size(); ++i)
		{
			if (m_list.at(i) > last)
			{
				++maxLast;
				int len = getMaxSubLenByESC(i + 1, m_list.at(i), maxLast);
				if (len > max)
				{
					max = len;
				}
				--maxLast;
			}
		}
		return max;
	};
private:
	vector<int> m_list;
};

int main(void)
{
	int m;
	cout << "输入数组长度：";
	while (cin >> m)
	{
		if (m > 0)
		{
			vector<int> vct(m, 0);
			cout << "输入数组(" << m << ")值：" << endl;
			while (m--)
			{
				cin >> vct[vct.size() - m - 1];
			}

			SubListHandle lsHd(vct);
			cout << "vector<int>:" << endl;
			lsHd.print();

			cout << "数组中最大升序子序列长度是多少？" << endl;
			cout << lsHd.getMaxSubLenByESC() << endl;
			cout << "输入数组长度：";
		}
		else
		{
			break;
		}
	}

	return 0;
}