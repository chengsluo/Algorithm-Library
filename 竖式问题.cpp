#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>
using namespace std;
#define INF 100000000
int main()
{
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    char s[20];
    char tmp_str[100];
    while(scanf("%s",s)==1){
        int kase=1;
        for(int i=100;i<=999;i++){
            for(int j=10;j<=99;j++){
                int tmp1=i*(j%10),tmp2=i*(j/10),tmp3=i*j;
                sprintf(tmp_str,"%d%d%d%d%d",i,j,tmp1,tmp2,tmp3);
                int d;
                for(d=0;d<strlen(tmp_str);d++){
                    if(strchr(s,tmp_str[d])==NULL) break;
                }
                if(d==strlen(tmp_str)){
                    printf("<%d>\n",kase++);
                    printf("  %d\nX  %d\n-----\n%5d\n%4d \n-----\n%5d\n",i,j,tmp1,tmp2,tmp3);   
                }
            }
        }
        if(kase==1){
            printf("<%d>\n",kase++);
            printf("No answer\n");
        }   
    }


    #ifdef LOCAL
    printf("Time used=%.2f\n",(double)clock()/CLOCKS_PER_SEC);
    #endif
    return 0;
}