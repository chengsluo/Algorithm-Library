#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

struct inf{
    double a,b,bit;
}num[1010];

bool cmp(inf f1,inf f2)
{
    return f1.bit >f2.bit;
}
int main()
{
    int m,n;
    double t1,t2;
    while(scanf("%d%d",&m,&n)==2){
        if(m==-1&&n==-1) break;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&t1,&t2);///�������Ͳ�Ҫ�������
            num[i].a=t2;
            num[i].b=t1;
            num[i].bit=t1/t2;
        }
        sort(num,num+n,cmp);
        double ans=0,ct=0;
        int i=0;
        for(;i<n&&ct+num[i].a<=m;i++){
            ans+=num[i].b;///��num[i].a*num[i].bit�ķ�ʽ���ܱ�����,������ȡԭ����������������پ�����ʧ
            ct+=num[i].a;
        }
        if(i<n&&ct<m){
            ans+=num[i].bit*(m-ct);
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}

