#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int num[2000];
int main()
{
       int n,max_ct,ct,ans;
       char str;
       while(scanf("%d",&n)==1&&n){
              getchar();
              max_ct=0;ans=0;
              for(int i=0;i<n;i++){
                     ct=0;
                     do{
                            scanf("%c",&str);
                            if(str=='X') ct++;
                     }while(str!='\n');
                     num[i]=ct;
                     max_ct=max(max_ct,ct);
              }
              for(int i=0;i<n;i++){
                     ans+=(max_ct-num[i]);
              }
              printf("%d\n",ans);
       }
       return 0;
}
