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
int num[MAX];

bool cmp(int a,int b)//从大到小排序,int为数组元素类型
{
    return a>b;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",num+i);
    }
    sort(num,num+n,cmp);//增加cmp函数
    int x=0,y=0;
    for(int i=0;i<n&&i<k;i++){
        if(num[i]*(i+1)>y){
            y=num[i]*(i+1);
            x=num[i];
        }
    }
    printf("%d %d\n",x,y);
  /*  int x=0,y=0;
    for(int i=n-1;i>=0&&i>=n-k;i--){
        if(num[i]*(n-i)>y){
            y=num[i]*(n-i);
            x=num[i];
        }
    }
    printf("%d %d\n",x,y);*/
    return 0;
}
