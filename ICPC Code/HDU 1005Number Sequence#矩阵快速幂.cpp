#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
///矩阵快速幂
struct matrix{
    int a[2][2];
};

matrix inline multi(matrix mx1,matrix mx2){
    matrix mx3;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            mx3.a[i][j]=0;
            for(int k=0;k<2;k++){
                mx3.a[i][j]+=mx1.a[i][k]*mx2.a[k][j]%7;
            }
            //mx3.a[i][j]%=7;
        }
    }
    return mx3;
}
int MatrixPower(matrix mx1,int n){
    matrix mx2;
    mx2.a[0][0]=mx2.a[1][1]=1;
    mx2.a[0][1]=mx2.a[1][0]=0;
    while(n){
        if(n%2)  mx2=multi(mx2,mx1);
        mx1=multi(mx1,mx1);
        n>>=1;
    }
    return (mx2.a[1][0]*1+mx2.a[1][1]*1)%7;///注意最后一步不要忘啦！
}
int main()
{
    int a,b,n;
    matrix mx;
    while(scanf("%d%d%d",&a,&b,&n)==3&&!(a==0&&b==0&&n==0)){
        mx.a[0][0]=a;mx.a[0][1]=b;mx.a[1][0]=1;mx.a[1][1]=0;
        printf("%d\n",MatrixPower(mx,n-1));
    }
    return 0;
}
