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
    f[1]=3;
    f[2]=6;
    f[3]=6;
    for(int i=4;i<=50;i++){
        f[i]=f[i-1]+2*f[i-2];
     ///   cout<<f[i]<<endl;//不要忘了交题时去掉注释
    }
    while(scanf("%d",&t)==1){
        printf("%lld\n",f[t]);
    }
    return 0;
}
