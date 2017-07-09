#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[MAXN];
int b[MAXN];
 
int LISdyna(int n)
{
	int i,j,k;
	for(i=1,b[0]=1;i<n;i++){//找出以a[i]结尾的最长递增子序列的长度b[i] 
		for(j=0,k=0;j<i;j++)
			if(a[j]<=a[i]&&k<b[j]) k=b[j];//由于之前的b[j] (j<i)都已经算出了，所以可以直接对比调用出其中符合条件的最大值 
		b[i]=k+1;
	}
	return maxL(n);
}
int maxL(int n){//分辨出哪个结尾的序列最长 
	for(int i=0,temp=0;i<n;i++)
		if(b[i]>temp) temp=b[i];
	return temp;
}
int main(){
	
	return 0;
}

/*

*/

