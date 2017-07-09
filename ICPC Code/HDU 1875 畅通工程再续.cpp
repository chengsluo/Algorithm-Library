#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int p[101][2];

struct node
{
    int u,v;
    double dist;
}edge[1000000];

bool cmd(struct node a,struct node b)
{
    if(a.dist<b.dist) return 1;
    else return 0;
}

int num[101];///num[i]的值为i的双亲结点
void init()
{
    for(int i=0;i<101;i++)
        num[i]=i;
}
int find(int i)
{
    int temp=i;
    while(num[temp]!=temp){
        temp=num[temp];
    }
    return temp;
}

void uniion(int i,int j)
{
    num[find(j)]=find(i);
}
int main()
{
    int t,c;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&c);
        for(int i=0;i<c;i++)
        {
            scanf("%d%d",&p[i][0],&p[i][1]);
        }
        int k=0;
        for(int i=0;i<c;i++){
            for(int j=i+1;j<c;j++){
                double xl=p[i][0]-p[j][0];
                double yl=p[i][1]-p[j][1];
                double dist=sqrt(xl*xl+yl*yl);
//                cout<<"dist"<<dist<<endl;
                if(dist>=10&&dist<=1000){
                    edge[k].u=i;
                    edge[k].v=j;
                    edge[k].dist=dist;
                    k++;
                }
            }
        }
        if(c == 1 || c == 0){printf("oh!\n"); continue;}
        if(k<c-1){
            cout<<"oh!\n"<<endl;
            continue;
        }
        sort(edge,edge+k,cmd);
//        for(int i=0;i<k;i++){
//            cout<<"debug"<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].dist<<endl;
//        }
        int ct=0;
        double sum=0;
        init();
        for(int i=0;i<k;i++){
            int u=edge[i].u;
            int v=edge[i].v;
            int j;
            if(find(u)!=find(v)){
                    uniion(u,v);
                    sum+=edge[i].dist;
                    ct++;
            }
        }
//        printf("sum%0.1lf\n",sum*100);
        if(ct==c-1){
            printf("%0.1lf\n",sum*100);
        }else{
            cout<<"oh!\n"<<endl;
        }
    }
    return 0;
}
