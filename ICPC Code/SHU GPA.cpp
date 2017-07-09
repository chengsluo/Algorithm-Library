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

int main()
{
    int n;
    while(cin>>n){
        float sumd=0,sumx=0;
        float d,x;
        for(int i=0;i<n;i++){
            cin>>x>>d;
            sumx+=x;
            if(d==-1){
                sumx-=x;
            }
            else if(d<60){
                sumd+=0;
            }
            else if(d<70){
                sumd+=x*1;
            }
            else if(d<80){
                sumd+=x*2;
            }
            else if(d<90){
                sumd+=x*3;
            }
            else{
                sumd+=x*4;
            }
        }
        if(sumx!=0)printf("%.2lf\n",sumd/sumx);
        else cout<<0<<endl;
    }
    return 0;
}
