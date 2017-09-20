#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int M=1001;
int n,t,len,top;
const double PI=3.14159265358979323846; 

struct Point{
    int x,y;
}p[M],stack[M];

int multi(Point p1,Point p2,Point p3)//p1p2×p1p3
{
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}

// void swap(Point * a,Point * b)
// {
//     Point temp=a;
//     a=b;
//     b=temp;
// }

int  dis(Point a,Point b)//距离的平方
{
    return   (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool cmp(Point a,Point b){
    //两点间的极角排序
    int t=multi(p[0],a,b);
    if(t>0) return true;//角度小于180,一般表示a在b的下方。右手法则判断
    if(t==0&&(dis(p[0],a)<dis(p[0],b))){
        return true;//相同偏角，但a在前方，则不用交换
    }else{
        return false;
    }
}
void graham()
{  
    //最下方(左边)的点放在数组最前面
    for(int i=1;i<n;i++){
        if(p[i].y<p[0].y) swap(p[i],p[0]);
        else if(p[i].y==p[0].y&&p[i].x<p[0].x) swap(p[i],p[0]);
    }

    sort(p+1,p+n,cmp);

    for(int i=0;i<3;i++){
        stack[i]=p[i];
    }
    top=2;
    for(int i=3;i<n;i++){
        while(top&&multi(stack[top-1],stack[top],p[i])<=0){
            top--;//上一个点被废弃
        }
        stack[++top]=p[i];
    }
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&len);
        for(int i=0;i<n;i++){
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        graham();
        double ans =0;
        for(int i=0;i<=top;i++){
            double length=(double)sqrt((double)dis(stack[i],stack[(i+1)%(top+1)]));
            //最后一条边需要%(top+1)
            ans+=length;
        }
        ans+=(double)2*PI*len;
        //可以由观察直观得到，拼接后刚好有360度的弧形区域。
        printf("%.0lf\n",ans);
        if(t>0) printf("\n");
    }
    return 0;
}