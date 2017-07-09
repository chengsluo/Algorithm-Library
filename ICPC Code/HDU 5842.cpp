#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int a[26];
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int key=1;key<=t;key++){
           char ch;
           for(int i=0;i<26;i++){
              a[i]=0;
           }
           while(1){
                     if(scanf("%c",&ch)==1){
                            if(ch>='a'&&ch<='z') a[ch-'a']=1;
                            else break;
                     }else{
                            break;
                     }
              }
              int ans=0;
              for(int i=0;i<26;i++){
                     if(a[i]==1)ans++;
              }
              printf("Case #%d: %d\n",key,ans);
       }
       return 0;
}
