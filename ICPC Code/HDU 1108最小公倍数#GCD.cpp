#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;


int gcd(int a,int b)
{
    int t;
    if(a<b){
        t=a;a=b;b=t;
    }
    while(b!=0){
        t=b;b=a%b;a=t;
    }
    return a;
}
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)==2){
        cout<<m*n/gcd(m,n)<<endl;
    }
    return 0;
}
