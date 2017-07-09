#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

long long f[21][2];
int main()
{
       f[0][0]=0;
       f[0][1]=0;
       f[1][0]=1;
       f[1][1]=2;
       for(int i=2;i<=20;i++){
              f[i][0]=f[i-1][0]+f[i-1][1];
              f[i][1]=f[i-1][0]*2+f[i-1][1];
       }
       int n;
       scanf("%d",&n);
       while(scanf("%d",&n)==1){
              printf("%lld\n",f[n][0]+f[n][1]);
       }
       return 0;
}

