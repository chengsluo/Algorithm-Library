#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;

char str[20000];
char ans[20000];
int len;
void Zip()
{
	int k = 0;
	for (int i = 0;i < len;)
	{
		if (str[i] - '0' + (str[i + 1] - '0') * 10 < 25 && str[i + 2] == '1')
		{
			ans[k++] = str[i] - '0' + (str[i + 1] - '0') * 10 + 100;//ע�⣬�ڲ��������ַ�ʱ���Ƿ���Ҫ-'0';
			i += 3;
		}
		else 
		{
			ans[k++] = str[i] - '0' + (str[i + 1] - '0') * 10;
			i += 2;
		}
	}
	for (int i = k - 1;i >= 0;i--)
		cout << ans[i];
	cout << endl;
}
void Code()
{
	int k = 0;
	for (int i = len - 1;i >= 0;i--)
	{
		while (str[i]!=0)
		{
			ans[k++] = str[i] % 10+'0';
			str[i] /=10;
		}
	}
	ans[k] = '\0';
	puts(ans);
}
int main()
{
	int t;
	cin >> t;
	getchar();
	while (t--)
	{
		//fgets(str, 20000, stdin);//����strĩβ�ӡ�\n';
		gets_s(str);//gets�İ�ȫ�汾��������gets���죻//SHU-OJ����Ҫ��gets(),��Ȼ��ң�233��
		len = strlen(str);
		int i;
		for (i = 0;i < len;i++)
		{
			if (str[i]<'0' || str[i]>'9') break;
		}
		if (i >= len) Zip();
		else Code();
	}
	return 0;
}