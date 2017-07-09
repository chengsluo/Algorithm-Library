#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

long long f[31];
int main()
{
    f[1]=1;
    f[2]=3;
    f[3]=5;
    for(int i=4;i<=30;i++){
       f[i]=f[i-1]+f[i-2]*2;///两个分支一定不要有重合部分，用乘法还是加法要分清
    }
    int t,n;
    scanf("%d",&t);
    while(t--){
       scanf("%d",&n);
       printf("%lld\n",f[n]);
    }
    return 0;
}
