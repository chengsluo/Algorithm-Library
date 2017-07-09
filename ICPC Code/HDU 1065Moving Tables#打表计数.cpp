#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t,i,j,N,P[200];
    int s,d,temp,k,max;
    cin>>t;
    for(i=0;i<t;i++){
           memset(P,0,sizeof(P));///必须要sizeof(P)
            cin>>N;
            for(j=0;j<N;j++){
               cin>>s>>d;
               s=(s-1)/2;
               d=(d-1)/2;///由于1-2实际上只占用一个路口，
               ///所以可以采用/2的方式来进行表达，但是由于1/2!=2/2,所以先各自减一更好
               if(s>d) {
                    temp=s;
                    s=d;
                    d=temp;
                }
               for(k=s;k<=d;k++)
                  P[k]++;
            }
            max=-1;
            for(j=0;j<200;j++)
                if(P[j]>max) max=P[j];///最后的时间取决于占用最多次数的那一个通道，用打表的方式解决
            cout<<max*10<<endl;
    }
    return 0;
}
