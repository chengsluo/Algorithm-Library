#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

bool G[26][26];
int main()
{
       char str[50];
       while(gets(str)){
              if(str[0]!='0'){
                     int len=strlen(str);
                     G[str[0]-'a'][str[len-1]-'a']=1;
              }
              else{
                     for(int k=0;k<26;k++){
                            for(int i=0;i<26;i++){
                                   for(int j=0;j<26;j++){
                                          G[i][j]=max(G[i][j],G[i][k]&&G[k][j]);
                                   }
                            }
                     }
                     if(G[1]['m'-'a']) cout<<"Yes.\n";
                     else cout<<"No.\n";
                     memset(G,0,sizeof(G));
              }
       }
       return 0;
}
