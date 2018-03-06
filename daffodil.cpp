#include<cstdio>
#include<cmath>
#include<ctime>
using namespace std;
#define INF 100000000
int main()
{
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int sum;
    for(int i=1;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                sum=i*i*i+j*j*j+k*k*k;
                if(sum>=100&&sum<=999&&sum==i*100+j*10+k){
                    printf("%d\n",sum);
                }
            }
        }
    }

    #ifdef LOCAL
    printf("Time used=%.2f\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
    return 0;
}