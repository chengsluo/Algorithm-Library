#include <iostream>
#include <cstdio>

using namespace std;
const int M=100;
double x[M],y[M];

int main()
{
    int n;
    while(scanf("%d",&n)==1,n){

        for(int i=0;i<n;i++){
            scanf("%lf%lf",x+i,y+i);
        }
        double area=0;
        for(int i=2;i<n;i++){
            area+=(x[i]-x[i-1])*(y[i-1]-y[0])-(y[i]-y[i-1])*(x[i-1]-x[0]);
        }
        if(area<0){
            area=-area;
        }
        printf("%.1lf\n",area/2);
    }
    return 0;
}