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
    ll a,b,n;
    ll t1,t2,t3;
    while(scanf("%lld%lld%lld",&a,&b,&n)==3&&n!=0){
        //����ѭ�����ʵ�,һ��Ҫ�ǵ��ҹ���
        t1=t2=1;int temp=0;
        /*while(++temp){
            t3=(a*t2+b*t1)%7;//ע�⿴��Ŀ�ı�ʾ�������뵱Ȼ����Ϊ
            t1=t2;
            t2=t3;
            if(t1==t2&&t1==1) break;
            //cout<<t1<<endl;
        }*/
        n=n%49;n--;//temp<=49?���ԭ��ܼ�
        // ��Ϊ����һ���ݹ飬���%7֮������ֻ��0,1,2,3,4,5,6���������
        //���ں�һ������ǰ�����Ƴ������������յĽ�����ֻ��7*7=49�п���
        //�þ��������Ҳ�����������ģ����һ�����
        while(n--){
            t3=(a*t2+b*t1)%7;
            t1=t2;
            t2=t3;
        }
        cout<<t1<<endl;
    }
    return 0;
}
