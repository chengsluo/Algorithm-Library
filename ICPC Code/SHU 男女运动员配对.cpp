#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int str1[40], str2[40];//

int comp(const void * p, const void * q)//比较函数，参数是两个空类型常量指针；先将元素强制转化成int型指针，再进行相减;
{
	return (*(int *)p - *(int *)q);//强转，取内容;
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
		qsort(str1,n,sizeof(int),comp);//algorithm头文件，四个参数(首地址，长度，元素宽度，比较函数);
		qsort(str2, n, sizeof(int), comp);
		long long ans = 0;
		for (int i = 0;i < n;i++)
			ans += str1[i] * str2[i];
		cout <<ans<< endl;
	}
	return 0;
}