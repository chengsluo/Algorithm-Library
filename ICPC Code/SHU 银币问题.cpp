#include <iostream>
using namespace std;
int m[100001];
void cal(int k, int n)
{
	m[1] = 0;m[2] = 1;m[3] = 1;m[4] = 2;
	int temp;
	for (int i = k + 1;i <= n;i++) {//���仯��������n֮ǰ��,k֮�������m[i]����������о������бף�;
		m[i] = 1000000;m[1] = 0;
		for (int j = 1;j <= i / 2;j++)
		{
			temp = j > i - 2 * j ? m[j] + 1 : m[i - 2 * j] + 1;
			if (temp < m[i])
				m[i] = temp;
		}
	}
}
int main()
{
	int n, k = 0;
	while (cin >> n && n > 0)
	{
		if (k < n)
		{
			cal(k, n);//��k-n֮���m[i];
			k = n;
		}
		cout << n << endl << "Times:" << m[n]<< endl;
	}
	return 0;
}