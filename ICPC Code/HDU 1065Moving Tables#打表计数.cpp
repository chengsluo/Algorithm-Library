#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t,i,j,N,P[200];
    int s,d,temp,k,max;
    cin>>t;
    for(i=0;i<t;i++){
           memset(P,0,sizeof(P));///����Ҫsizeof(P)
            cin>>N;
            for(j=0;j<N;j++){
               cin>>s>>d;
               s=(s-1)/2;
               d=(d-1)/2;///����1-2ʵ����ֻռ��һ��·�ڣ�
               ///���Կ��Բ���/2�ķ�ʽ�����б���������1/2!=2/2,�����ȸ��Լ�һ����
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
                if(P[j]>max) max=P[j];///����ʱ��ȡ����ռ������������һ��ͨ�����ô��ķ�ʽ���
            cout<<max*10<<endl;
    }
    return 0;
}
