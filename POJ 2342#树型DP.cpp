#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define clr( a , x ) memset ( a , x , sizeof (a) );
#define RE freopen("1.in","r",stdin);
#define WE freopen("1.out","w",stdout);
#define SpeedUp std::cout.sync_with_stdio(false);

const int maxn = 6005;
const int inf = 0x3f3f3f3f;
int father[maxn];
int dp[maxn][2];
int vis[maxn];
int n;

void tree(int rt){
    vis[rt] = 1;
    for (int i = 1; i <= n; ++i){
        if(!vis[i] && father[i] == rt){    //下属
            tree(i);
            dp[rt][1] += dp[i][0];              //上司来，则下属不能来
            dp[rt][0] += max(dp[i][0],dp[i][1]);    //上司不来，下属可来可不来
        }
    }
}

int main(){
    int p,q;

    while(cin>>n){
        clr(vis,0);
        clr(dp,0);
        clr(father,0);
        for (int i = 1; i <= n; ++i){
            cin>>dp[i][1];
        }
        while(cin>>p>>q,p||q){
            father[p] = q;
        }

        int rt = 1;         //1号人肯定在
        while(father[rt]){  //从任意一点开始找根节点
            rt = father[rt];
        }
        tree(rt);
        cout<<max(dp[rt][0],dp[rt][1])<<endl;
    }
    return 0;
}