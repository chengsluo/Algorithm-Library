#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
       int n,k;
       while(scanf("%d%d",&n,&k)==2){
              int ans=0;
              while(k/2>n){
                     if(k%2) ans+=2;
                     else ans++;
                     k=k/2;
              }
              ans+=(k-n);
              printf("%d\n",ans);
       }
}
