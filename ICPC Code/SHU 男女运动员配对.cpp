#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int str1[40], str2[40];//

int comp(const void * p, const void * q)//�ȽϺ��������������������ͳ���ָ�룻�Ƚ�Ԫ��ǿ��ת����int��ָ�룬�ٽ������;
{
	return (*(int *)p - *(int *)q);//ǿת��ȡ����;
}

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0;i < n;i++)
			cin >> str1[i];
		for (int i = 0;i < n;i++)
			cin >> str2[i];
		qsort(str1,n,sizeof(int),comp);//algorithmͷ�ļ����ĸ�����(�׵�ַ�����ȣ�Ԫ�ؿ�ȣ��ȽϺ���);
		qsort(str2, n, sizeof(int), comp);
		long long ans = 0;
		for (int i = 0;i < n;i++)
			ans += str1[i] * str2[i];
		cout <<ans<< endl;
	}
	return 0;
}