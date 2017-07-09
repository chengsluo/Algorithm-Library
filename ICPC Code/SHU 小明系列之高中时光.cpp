#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
const int MAX=410;
const int MOD=1000007;
typedef long long ll;
using namespace std;

int com[MAX][MAX];//组合数打表

int main()
{
    int t,m,n,k;
    scanf("%d",&t);
    //
    com[0][0]=1;
    for(int i=1;i<MAX;i++){
        for(int j=0;j<=i/2;j++){
            if(j==0) com[i][j]=com[i][i-j]=1;
            com[i][j]=com[i][i-j]=(com[i-1][j-1]+com[i-1][j])%MOD;
        }
    }
    //这一段可以当作模板记下来！！！
    while(t--){
        scanf("%d%d%d",&m,&n,&k);
        if(k<2||k>m*n) printf("0\n");
        else{
//
//本题主要运用了容斥原理和求组合数（组合数链接，点击打开链接）。
//
//现在具体分析这道题。
//
//四个边上都有点的组合  =  总组合数  -  四个边中至少有一个边没有点的组合数。
//
//将问题转化成 求：四个边中至少有一个边没有点的组合数
//
//用数组 dp[ i ][ j ]来保存组合数C（i  ,  j）。
//
//由容斥原理：
//
//设A=  上边没点
//    B = 下边没点
//    C = 左边没点
//    D = 右边没点
//四个边中至少有一个边没有点  =  A + B +  C  + D -AB - AC - AD  - BC - BD  -CD + ABC + ABD + ACD + BCD - ABCD
//
//分别求出上述独立事件的组合数即为最终结果。

            int  ans=com[m*n][k];
            if((m-1)*n>=k) ans-=2*com[(m-1)*n][k];
            ans%=MOD;
            if((n-1)*m>=k) ans-=2*com[(n-1)*m][k];
            ans%=MOD;
            if((m-2)*n>=k) ans+=com[(m-2)*n][k];
            ans%=MOD;
            if((n-2)*m>=k) ans+=com[(n-2)*m][k];
            ans%=MOD;
            if((n-1)*(m-1)>=k) ans+=4*com[(n-1)*(m-1)][k];
            ans%=MOD;
            if((n-2)*(m-1)>=k) ans-=2*com[(n-2)*(m-1)][k];
            ans%=MOD;
            if((m-2)*(n-1)>=k) ans-=2*com[(m-2)*(n-1)][k];
            ans%=MOD;
            if((m-2)*(n-2)>=k) ans+=com[(m-2)*(n-2)][k];
            ans%=MOD;
            if(ans<0) ans+=MOD;
            printf("%d\n",ans);
        }
    }
    return 0;
}
