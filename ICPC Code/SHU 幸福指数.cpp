#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int r[110],l[110];
int com[110][110];

int main()
{
    memset(com,0,sizeof(com));
    com[0][0]=1;
    for(int i=1;i<110;i++){
        for(int j=0;j<=i/2;j++){
            if(j==0) com[i][j]=com[i][i-j]=1;
            com[i][j]=com[i][i-j]=(com[i-1][j-1]+com[i-1][j]);
        }
    }
    int t;
    char ch;
    while(scanf("%d",&t)==1){
        memset(r,0,sizeof(r));
        memset(l,0,sizeof(l));
        getchar();
        for(int i=0;i<t;i++){
            for(int j=0;j<t;j++){
                ch=getchar();
                if(ch=='C'){
                    r[i]++;l[j]++;
                }
            }
            getchar();
        }
        int ans=0;
        for(int i=0;i<t;i++){
            ans+=com[r[i]][2];
            ans+=com[l[i]][2];
        }
        printf("%d\n",ans);
    }
    return 0;
}
