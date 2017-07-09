#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int num[100010];
bool mark[100010];
int find (int x)
{
    int r=x;
    while(r!=num[r]) r=num[r];
    int t1=x,t2;
    while(r!=num[t1]){
        t2=num[t1];
        num[t1]=r;
        t1=t2;
    }
    return r;
}
int main()
{
    int t1,t2;
    while(scanf("%d%d",&t1,&t2)==2&&t1!=-1&&t2!=-1){
        if(t1==0&&t2==0){
            printf("Yes\n");
            continue;
        }
         memset(mark,0,sizeof(mark));
         num[t2]=t1;
         num[t1]=t1;
         mark[t1]=1;
         mark[t2]=1;
         while(scanf("%d%d",&t1,&t2)==2&&t1&&t2){
            if(mark[t2]&&mark[t1]){
                int a=find(t1);
                int b=find(t2);
                if(a!=b)   num[b]=a;
                else   break;
            }
            else if(mark[t2]) {
                mark[t1]=1;
                num[t1]=t2;
            }
            else if(mark[t1]){
                mark[t2]=1;
                num[t2]=t1;
            }
            else{
                mark[t2]=1;
                mark[t1]=1;
                num[t2]=t1;
                num[t1]=t1;
            }
        }
        if(t1==0&&t2==0){
            int temp,j,k;
            for(j=1;j<=100000;j++){
                if(mark[j]==1){
                    temp=find(j);
                    break;
                }
            }
            for(k=j;k<=100000;k++){
                if(mark[k]==1){
                    if(temp!=find(k)) {printf("No\n");break;}
                }
            }
            if(k>100000) printf("Yes\n");
        }
        else{
            while(scanf("%d%d",&t1,&t2)==2&&t1&&t2);
            printf("No\n");
        }
    }
    return 0;
}
