#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>

typedef long long ll;
using namespace std;

int comb[33][5];
ll ans[33];
int main()
{
//    for(int i=1;i<=31;i++){
//        ans[i]=i;
//        if(i>=2) ans[i]+=(2*i*(i-1));
//        if(i>=3) ans[i]+=(i*(i-1)*(i-2));
//        if(i>=4){
//            ans[i]+=(i*(i-1)*(i-2)*(i-3)/4/2);
//        }
//    }
    for(int i=1;i<5;i++) comb[0][i]=0;
    for(int i=0;i<32;i++) comb[i][0]=1;
    for(int i=1;i<32;i++){
        for(int j=1;j<5;j++){
            comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
        }
    }
    //求组合数的方法！
    for(int i=0;i<32;i++){
        ans[i]=comb[i][1]+4*comb[i][2]+6*comb[i][3]+3*comb[i][4];
    }
    int n;
    while(scanf("%d",&n)==1){
        cout<<ans[n]<<endl;
    }
    return 0;
}
