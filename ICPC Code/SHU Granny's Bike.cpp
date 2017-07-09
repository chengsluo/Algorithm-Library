#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef  long long int  ll ;

bool g[11][11];
bool tag[11];
int key,n;
void BFS(int t){
       int i;
       for(i=1;i<=n;i++){
              if(tag[i]==0) break;
       }
       if(i>n){
              if(g[t][0]==1){
                     key=1;
                     return;
              }
       }
       for(int i=1;i<=n;i++)
              if(g[t][i]==1&&tag[i]==0){
                     tag[i]=1;
                     BFS(i);
                     if(key==1)return;
                     tag[i]=0;
              }
}
int main()
{
       int temp;char ch;int k=1;
       while(scanf("%d%c",&n,&ch)==2&&n){
              memset(g,0,sizeof(g));
              memset(tag,0,sizeof(tag));
              for(int i=1;i<=n;i++){
                     while(1){
                            scanf("%d%c",&temp,&ch);
                            g[i][temp]=g[temp][i]=1;
                            if(ch=='\n') break;
                     }
              }
              key=0;
              BFS(0);
              if(key){
                     cout<<"Case "<<k++<<": Granny can make the circuit."<<endl;
              }
              else{
                      cout<<"Case "<<k++<<": Granny can not make the circuit."<<endl;
              }
       }
       return 0;
}

