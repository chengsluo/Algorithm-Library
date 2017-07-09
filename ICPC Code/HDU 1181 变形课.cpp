#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool G[26][26];
bool vis[26];

bool dfs(int i){
       //cout<<i<<endl;
       vis[i]=1;
       for(int j=0;j<26;j++){
              if(!vis[j]&&G[i][j]){
                     if(j=='m'-'a') return 1;
                     if(dfs(j)) return 1;
              }
       }
       vis[i]=0;
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
                     if(dfs(1)){
                            cout<<"Yes.\n";
                     }
                     else cout<<"No.\n";
                     memset(G,0,sizeof(G));
                     memset(vis,0,sizeof(vis));
              }
       }
       return 0;
}
