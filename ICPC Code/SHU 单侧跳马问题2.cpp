#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
const int MAX=10010;
typedef long long ll;
using namespace std;

bool a[22][22];
int n,m,e,f,c,d,flag,ans,ct;
int dir[4][2]={2,-1,2,1,1,2,1,-2};

void jump(int aa,int bb)
{

    if(flag) return ;
     cout<<aa<<":"<<bb<<endl;
    if(aa==c&&bb==d){
        flag=1;
        ans=ct;
        return;
    }
    ct++;
    a[aa][bb]=1;
    for(int i=0;i<4;i++){
        if(aa+dir[i][0]<=n&&aa+dir[i][0]>=1&&bb+dir[i][1]<=m){
            jump(aa+dir[i][0],bb+dir[i][1]);
        }
        a[aa+dir[i][0]][bb+dir[i][1]]=0;
        ct--;
    }
}
int main()
{

    while(scanf("%d%d",&n,&m)==2){
        flag=0;
        ct=0;
        scanf("%d%d%d%d",&e,&f,&c,&d);
        memset(a,0,sizeof(a));
        jump(e,f);
        if(flag) cout<<ans<<endl;
        else cout<<""<<endl;
    }
    return 0;
}
