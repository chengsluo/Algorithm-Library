#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

long long f[55];
int main()
{
    int t;
    f[1]=1;
    f[2]=2;
    f[3]=3;
    f[4]=4;
    for(int i=5;i<55;i++){
        f[i]=f[i-1]+f[i-1]-f[i-2]+f[i-3]-f[i-4];
    }
    while(scanf("%d",&t)==1&&t){
       printf("%lld\n",f[t]);
    }
    return 0;
}
