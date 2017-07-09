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
ll  num[50];
int main()
{
    num[0]=0;num[1]=1;
    for(int i=2;num[i-1]<=2147483647;i++){
            num[i]=num[i-1]+num[i-2];
            //cout<<num[i]<<endl;
    }
    ll n;
    int i;

    while(scanf("%lld",&n)==1&&n!=-1){
            for(i=0;num[i]<n;i++);
            if(num[i]==n){
                printf("%d\n",i);
            }
            if(num[i]>n){
                printf("Not a Fibonacci number.\n");
            }
    }
    return 0;
}
