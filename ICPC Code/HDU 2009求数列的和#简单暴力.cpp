#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;


int main()
{
    int m;
    double n;
    double ans;
    while(scanf("%lf%d",&n,&m)==2){
        ans=0;
        while(m){
            ans+=n;
            n=sqrt(n);
            m--;
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
//{
//    int m;
//    double n;
//    double ans;
//    while(scanf("%lf%d",&n,&m)==2){
//        if(n==0){
//            printf("0.00\n");continue;
//        }
//        ans=0;
//        while(n-1>=0.0000001&&m){///这种方法失败，始终达不到精度要求！！！！
//            ans+=n;
//            n=sqrt(n);
//            m--;
//        }
//        if(!m){
//            ans+=m;
//        }
//        printf("%.2lf\n",ans);
//    }
//    return 0;
//}
