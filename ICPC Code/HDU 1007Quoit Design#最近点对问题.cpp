#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXN=100010;
struct point{
    double x,y;
    bool index;
};
point num[MAXN],temp[MAXN];

bool cmpx(point a,point b)
{
    return a.x < b.x;
}
double getDistance(const point&t1,const point&t2)
{
    return sqrt((t1.x-t2.x)*(t1.x-t2.x)+(t1.y-t2.y)*(t1.y-t2.y));
}

bool cmpy(point a,point b)
{
    return a.y<b.y;
}

double divide(int left,int right)
{
    double dis;
    if(right-left==1){
        dis=getDistance(num[left],num[right]);
    }
    else if(right-left==2){
        dis=min(
                getDistance(num[left],num[right-1]),
                min(getDistance(num[left],num[right]),getDistance(num[left+1],num[right]))
                );
    }
    else{
        int mid=(left+right)/2;
        dis=min(divide(left,mid),divide(mid+1,right));
        int k=0;
        for(int i=left;i<=mid;i++){
            double leftdis=num[mid].x-dis;
            if(num[i].x>leftdis){
                temp[k].index=1;
                temp[k].x=num[i].x;
                temp[k].y=num[i].y;
                k++;
            }
        }
        for(int i=mid+1;i<=right;i++){
            double rightdis=num[mid].x+dis;
            if(num[i].x<rightdis){
                temp[k].index=0;
                temp[k].x=num[i].x;
                temp[k].y=num[i].y;
                k++;
            }
        }
        sort(temp,temp+k,cmpy);
        for(int i=0;i<k;i++){///这种方式跟下面注释的异曲同工，但是不知道为什么下面的错了
                                                        ///编程时应该尽量选择简单的,逻辑系统相互之间具有容错性、
            int p=7;
            for(int j=1;j<p&&i+j<k;j++){
                if(temp[i].index!=temp[i+j].index)
                    dis=min(dis,getDistance(temp[i],temp[i+j]));
//                else{
//                    p++;
//                }
            }

//                if(temp[i].index==1){
//                    for(int j=i+1,ct=0;j<k&&ct<4;j++){
//                            if(temp[j].index==0){
//                                ct++;
//                                dis=min(dis,getDistance(temp[i],temp[j]));
//                            }
//                    }
//                    for(int j=i-1,ct=0;j>=0&&ct<4;j--){
//                            if(temp[j].index==0){
//                                ct++;
//                                dis=min(dis,getDistance(temp[i],temp[j]));
//                            }
//                    }
//                }

        }
    }
    return dis;
}
int main()
{
    int t;
    while(scanf("%d",&t)==1&&t){
        for(int i=0;i<t;i++){
            scanf("%lf%lf",&num[i].x,&num[i].y);
        }
        sort(num,num+t,cmpx);
        printf("%.2lf\n",divide(0,t-1)/2);
    }
    return 0;
}
