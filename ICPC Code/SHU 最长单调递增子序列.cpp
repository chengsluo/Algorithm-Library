#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[MAXN];
int b[MAXN];
 
int LISdyna(int n)
{
	int i,j,k;
	for(i=1,b[0]=1;i<n;i++){//�ҳ���a[i]��β������������еĳ���b[i] 
		for(j=0,k=0;j<i;j++)
			if(a[j]<=a[i]&&k<b[j]) k=b[j];//����֮ǰ��b[j] (j<i)���Ѿ�����ˣ����Կ���ֱ�ӶԱȵ��ó����з������������ֵ 
		b[i]=k+1;
	}
	return maxL(n);
}
int maxL(int n){//�ֱ���ĸ���β������� 
	for(int i=0,temp=0;i<n;i++)
		if(b[i]>temp) temp=b[i];
	return temp;
}
int main(){
	
	return 0;
}

/*

*/

