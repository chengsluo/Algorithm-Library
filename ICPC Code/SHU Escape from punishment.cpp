#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
const int MAX=10010;
typedef long long ll;
using namespace std;
const double pi=3.1415926;

int main()
{
    double r,v1,v2;
    while(scanf("%lf%lf%lf",&r,&v1,&v2)==3){
        if(r/v1<pi*r/v2){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
