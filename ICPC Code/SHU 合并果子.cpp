#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define maxn 1111
#define INF 0x3FFFFFFF
priority_queue<long long,vector<long long>,greater<long long> >qu;
int main()
{
    long long  t,len,cost;
    while(cin>>t){
        cost=0;
        for(long long i=0;i<t;i++){
            cin>>len;
            qu.push(len);
        }
        while(qu.size()!=1){
            long long a=qu.top();qu.pop();
            long long  b=qu.top();qu.pop();
            cost+=(a+b);
            qu.push(a+b);
        }
        cout<<cost<<endl;
        qu.pop();
    }
    return 0;
}
