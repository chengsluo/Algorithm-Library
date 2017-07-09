#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
const int MAX=1010;
typedef long long ll;
using namespace std;

struct A {
    int c,b,a;
}s[MAX];

int ct,x,y,z;

bool cmp(A b1,A b2){//注意结构体的写法
    return b1.c<b2.c;
}
bool judge(int a,int b,int c){
    for(int i=0;i<ct;i++){
        if(s[i].a==a&&s[i].b==b&&s[i].c==c){
            return 0;
        }
    }
    return 1;
}
void imitation(int a,int b,int c){
    int t1,t2;
    //cout<<a<<" "<<b<<" "<<c<<endl;
    if(a!=0){
        t1=(b+a>y?y:b+a);//注意变量更新时的变化
        t2=(b+a>y?b+a-y:0);
        if(judge(t2,t1,c)){
            s[ct].a=t2;s[ct].b=t1;s[ct].c=c;
            ct++;
            imitation(t2,t1,c);
        }
        t1=(c+a>z?z:c+a);
        t2=(c+a>z?c+a-z:0);
        if(judge(t2,b,t1)){
            s[ct].a=t2;s[ct].b=b;s[ct].c=t1;
            ct++;
            imitation(t2,b,t1);
        }
    }
    if(b!=0){
        t1=(b+a>x?x:b+a);
        t2=(b+a>x?b+a-x:0);
        if(judge(t1,t2,c)){
            s[ct].a=t1;s[ct].b=t2;s[ct].c=c;
            ct++;
            imitation(t1,t2,c);
        }
        t1=(c+b>z?z:c+b);
        t2=(c+b>z?c+b-z:0);
        if(judge(a,t2,t1)){
            s[ct].a=a;s[ct].b=t2;s[ct].c=t1;
            ct++;
            imitation(a,t2,t1);
        }
    }
    if(c!=0){
        t1=(c+a>x?x:c+a);
        t2=(c+a>x?c+a-x:0);
        if(judge(t1,b,t2)){
            s[ct].a=t1;s[ct].b=b;s[ct].c=t2;
            ct++;
            imitation(t1,b,t2);
        }
        t1=(c+b>y?y:c+b);
       t2=(c+b>y?c+b-y:0);
        if(judge(a,t1,t2)){
            s[ct].a=a;s[ct].b=t1;s[ct].c=t2;
            ct++;
            imitation(a,t1,t2);
        }
    }
}
int main()
{
    while(scanf("%d%d%d",&x,&y,&z)==3){
            ct=0;
            imitation(0,0,z);
            sort(s,s+ct,cmp);
            int temp=-1,ans=0;
            for(int i=0;i<ct;i++){
                    if(s[i].a==0){//注意题目要求
                        if(ans) printf(" ");
                        printf("%d",s[i].c);
                        ans++;
                    }
            }
            printf("\n");
    }
    return 0;
}

