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

    int n3,n5,n7,kase=1;
    while(scanf("%d%d%d",&n3,&n5,&n7)==3){
        int ans_count=0;
        int ans;
        for(int i=10;i<=100;i++){
            if(i%3==n3&&i%5==n5&&i%7==n7){
                ans=i;
                ans_count++;
            }
        }
        if(ans_count==1){
            printf("Case %d: %d\n",kase++,ans);
        }else{
            printf("Case %d: No answer\n",kase++);            
        }
    }

    #ifdef LOCAL
    printf("Time used=%.2f\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
    return 0;
}