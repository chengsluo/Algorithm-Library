#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef  long long int  ll ;
///£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨///
///£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨ ‹Ω œ¸NÖ»¥Ï£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨///
///£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨£¨///



ll gcd(ll n,ll m)
{
       if(n<m){
              ll temp=n;
              n=m;
              m=temp;
       }
       while(n%m){
              ll temp=m;
              m=n%m;
              n=temp;
       }
       return m;
}
int main()
{
       int t;
       ll n,m;
       scanf("%d",&t);
       while(t--){
              scanf("%lld%lld",&n,&m);
              cout<<n/gcd(n,m)<<endl;
       }
       return 0;
}

