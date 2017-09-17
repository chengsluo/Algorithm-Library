#include <iostream>
#include <cstdio>
using namespace std;
const int M=1000;
int x0,y0,xt,yt;
bool judge(int x3,int y3,int x4 ,int y4)
{
    //线段跨立试验
    return (((x3-x0)*(yt-y0)-(xt-x0)*(y3-y0))*((x4-x0)*(yt-y0)-(xt-x0)*(y4-y0)))<0&&(((x0-x3)*(y4-y3)-(x4-x3)*(y0-y3))*((xt-x3)*(y4-y3)-(x4-x3)*(yt-y3)))<0;
}
int main()
{
    int n,k=1;
    int x[M],y[M];
    while(scanf("%d",&n)==1){
        for(int i=0;i<n;i++){
            scanf("%d%d",x+i,y+i);
        }
        scanf("%d%d%d%d",&x0,&y0,&xt,&yt);
        int flag=false;
        for(int i=1;i<n;i++){
            if(judge(x[i-1],y[i-1],x[i],y[i])){
                flag=true;
                break;
            }
        }
        if(judge(x[n-1],y[n-1],x[0],y[0])){
            flag=true;            
        }
        printf("Case %d:\n",k++);
        if(flag){
            printf("YES\n");
        }else{
            printf("No\n");            
        }
    }
    return 0;
}