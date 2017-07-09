#include<iostream>
#include<cstdio>
using namespace std;

int n,m,t;
int G[10][10];
int v[4][2]={1,0,0,1,-1,0,0,-1};
int c,d;

bool dfs(int i,int j,int ct)
{
       //cout<<i<<j<<ct<<endl;
       if(ct>t) return 0;
       if(i<0||j<0||i>n-1||j>m-1) return 0;
       if(ct==t){
              //cout<<"s"<<i<<j<<G[i][j]<<endl;
              if(G[i][j]==2) return 1;
              else return 0;
       }
       if(G[i][j]==3||G[i][j]==1||G[i][j]==2) return 0;

       int len=c-i;
       if(len<0) len=-len;
       if(d-j<0) len+=(j-d);
       else len+=(d-j);
       if(t-ct-len>0&&((t-ct-len)%2==1)) return 0;///奇偶减枝！！

       for(int k=0;k<4;k++){
              G[i][j]=3;
              if(dfs(i+v[k][0],j+v[k][1],ct+1)) return 1;
              G[i][j]=0;
       }
       return 0;///这个条件不能忘，不然默认返回true！
}
int main()
{
       char ch;
       int a,b;
       while(scanf("%d%d%d",&n,&m,&t)==3){
              if(!(n||m||t)) break;
              getchar();
              for(int i=0;i<n;i++){
                     for(int j=0;j<m;j++){
                            ch=getchar();
                            if(ch=='.'){
                                   G[i][j]=0;
                            }
                            else if(ch=='X'){
                                   G[i][j]=1;
                            }
                            else if(ch=='S'){
                                   G[i][j]=0;
                                   a=i;b=j;
                            }
                            else if(ch=='D'){
                                   c=i;d=j;
                                   G[i][j]=2;
                            }
                     }
                     getchar();
              }
//            for(int i=0;i<n;i++){
//                     for(int j=0;j<m;j++){
//                            cout<<G[i][j];
//                     }
//                     cout<<endl;
//              }
//              cout<<endl;
              if(dfs(a,b,0)) cout<<"YES\n";
              else cout<<"NO\n";
       }
       return 0;
}
