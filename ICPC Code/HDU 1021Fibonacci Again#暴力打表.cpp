#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
const int MAX=1000001;
typedef long long ll;
using namespace std;

bool num[MAX];
int main()
{
    ll t0=7,t1=11,t2;
    memset(num,0,sizeof(bool));
    num[0]=1;num[1]=1;
    for(int i=2;i<MAX;i++){
            t2=(t0+t1);
            if(t2%3) num[i]=1;
            t0=t1;
            t1=t2;
    }
    int n;
    while(scanf("%d",&n)==1){
        if(num[n]) printf("no\n");
        else printf("yes\n");
    }
    return 0;
}
