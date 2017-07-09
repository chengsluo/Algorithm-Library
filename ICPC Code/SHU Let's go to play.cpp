#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int n1[400];
int n2[400];
int main()
{
    int t,t1,t2;
    char ch;
    while(scanf("%d",&t)==1){
            getchar();
            memset(n1,0,sizeof(n1));
            memset(n2,0,sizeof(n2));
            for(int i=0;i<t;i++){
                scanf("%c %d %d",&ch,&t1,&t2);
                getchar();
                if(ch=='M'){
                    for(int j=t1;j<=t2;j++){
                        n1[j]++;
                    }
                }
                else if(ch=='F'){
                    for(int j=t1;j<=t2;j++){
                        n2[j]++;
                    }
                }
            }
            int ans=0;
            for(int i=0;i<400;i++){
                if(min(n1[i],n2[i])>ans){
                    ans=min(n1[i],n2[i]);
                }
            }
            printf("%d\n",ans*2);
    }
    return 0;
}
