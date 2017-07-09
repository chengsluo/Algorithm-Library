#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
const int MAX=10010;
typedef long long ll;
using namespace std;

ll num[60];
int main()
{
    ll num2=2;
    num[0]=0;num[1]=1,num[2]=2;
    for(int i=3;i<60;i++){
        num2*=2;
        num[i]=num2-num[i-1];
    }
    int n;
    while(scanf("%d",&n)==1){
        printf("%lld\n",num[n]*3);
    }
    return 0;
}
