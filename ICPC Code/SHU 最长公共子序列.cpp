#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char str1[55], str2[55];//����������ַ���
char str3[55];//�ڻ��ݹ��������ڼ�¼��ǰ���ݳɹ����ַ���
char str4[55][55];//���ڼ�¼���������������
int c[55][55];//c[i][j]��¼str1��ǰi���ַ���ɵ��Ӵ�����str2��ǰj���ַ���ɵ��Ӵ��������������
int p;//��¼��Ѱ�ҵ����ٸ������������

int LenOfLCS(int m, int n)
{
	for (int i = 0;i <=m;i++)
		c[i][0] = 0;
	for (int i = 0;i <= n;i++)
		c[0][i] = 0;
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j <=n;j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else if (c[i - 1][j]>c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
			}
			else
			{
				c[i][j] = c[i][j - 1];
			}
		}
	}
	return c[m][n];
}
void traceBack(int i, int j,int k)//k�����ĩβ��ʼ���Ѿ��ҵ�k�����������У�
{
	while (i>0 && j>0)
	{
		if (str1[i - 1] == str2[j - 1])
		{
			str3[k++] = str1[i - 1];
			--i;
			--j;
		}
		else
		{
			if (c[i - 1][j] > c[i][j - 1])
				--i;
			else if (c[i - 1][j] < c[i][j - 1])
				--j;
			else   // ��ȵ����
			{
				traceBack(i - 1, j,k);
				traceBack(i, j - 1,k);
				return;
			}
		}
	}
	int t = 0;
	for (int i = k - 1;i >= 0;i--)
		str4[p][t++] = str3[i];
	str4[p][t] = '\0';
	p++;
}
int main()
{
	int t,ct=0;
	cin >> t;
	getchar();
	while (t--)
	{
		int m, n;
		cin >> m >> n;
		getchar();
		for (int i = 0;i < m;i++)
		{
			cin >> str1[i];
		}
		getchar();
		for (int i = 0;i < n;i++)
		{
			cin >> str2[i];
		}
		getchar();
		cout << "Case " << ++ct << endl << LenOfLCS(m, n) <<"    LCS(X,Y):"<< endl;
		p = 0;
		traceBack(m, n, 0);
		for (int i = 0;i < p;i++)//������������������;
			puts(str4[i]);
		for (int i = 0;i <= m;i++)//�����C��
		{
			for (int j = 0;j <= n;j++)
			{
				cout << c[i][j] << " ";
			}
			cout << endl;
		}
	} 
	return 0;
}

