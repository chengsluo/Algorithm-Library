#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
const int MAX=110;
typedef long long ll;
using namespace std;

struct ttt{//不要用一些很常见的极易与判题系统冲突的关键字，eg：time
    double s,e;
}t[110];

bool cmp(ttt t1,ttt t2)
{
    return t1.e<t2.e;
}

int main()
{
    int n;
    while(scanf("%d",&n)==1&&n){
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&t[i].s,&t[i].e);
        }
        sort(t,t+n,cmp);
        int ans=0;
        double temp=-100;
        for(int i=0;i<n;i++){
            if(t[i].s>temp) {ans++;temp=t[i].e;}
        }
        cout<<ans<<endl;
    }
    return 0;
}
