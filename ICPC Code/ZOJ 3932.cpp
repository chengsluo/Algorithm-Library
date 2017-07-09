#include<iostream>
#include<cstdio>
using namespace std;
typedef long long  ll;

int main()
{
       int t1;
       int t,n;
       scanf("%d",&t);
       while(t--){
              int ans=0;
              scanf("%d",&n);
              for(int i=0;i<n;i++){
                     scanf("%d",&t1);
                     if(t1>0){
                            ans++;
                            if(t1>ans) ans=t1;///зЂвт
                     }
              }
              printf("%d\n",ans);
       }
       return 0;
}

