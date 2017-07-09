#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

bool G[26][26];
bool vis[26];

bool bfs(int i){
       queue<int>qu;
       qu.push('b'-'a');
       vis['b'-'a']=1;
       while(!qu.empty()){
              int t=qu.front();
              if(t=='m'-'a') return 1;
              vis[t]=1;
              qu.pop();
              for(int i=0;i<26;i++){
                     if(G[t][i]&&!vis[i]){
                            qu.push(i);
                     }
              }
       }
       return 0;
}
int main()
{
       char str[50];
       while(gets(str)){
              if(str[0]!='0'){
                     int len=strlen(str);
                     G[str[0]-'a'][str[len-1]-'a']=1;
              }
              else{
                     if(bfs(1)){
                            cout<<"Yes.\n";
                     }
                     else cout<<"No.\n";
                     memset(G,0,sizeof(G));
                     memset(vis,0,sizeof(vis));
              }
       }
       return 0;
}
