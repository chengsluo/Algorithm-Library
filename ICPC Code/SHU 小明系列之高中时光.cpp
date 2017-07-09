#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
const int MAX=410;
const int MOD=1000007;
typedef long long ll;
using namespace std;

int com[MAX][MAX];//��������

int main()
{
    int t,m,n,k;
    scanf("%d",&t);
    //
    com[0][0]=1;
    for(int i=1;i<MAX;i++){
        for(int j=0;j<=i/2;j++){
            if(j==0) com[i][j]=com[i][i-j]=1;
            com[i][j]=com[i][i-j]=(com[i-1][j-1]+com[i-1][j])%MOD;
        }
    }
    //��һ�ο��Ե���ģ�������������
    while(t--){
        scanf("%d%d%d",&m,&n,&k);
        if(k<2||k>m*n) printf("0\n");
        else{
//
//������Ҫ�������ݳ�ԭ��������������������ӣ���������ӣ���
//
//���ھ����������⡣
//
//�ĸ����϶��е�����  =  �������  -  �ĸ�����������һ����û�е���������
//
//������ת���� ���ĸ�����������һ����û�е�������
//
//������ dp[ i ][ j ]�����������C��i  ,  j����
//
//���ݳ�ԭ��
//
//��A=  �ϱ�û��
//    B = �±�û��
//    C = ���û��
//    D = �ұ�û��
//�ĸ�����������һ����û�е�  =  A + B +  C  + D -AB - AC - AD  - BC - BD  -CD + ABC + ABD + ACD + BCD - ABCD
//
//�ֱ�������������¼����������Ϊ���ս����

            int  ans=com[m*n][k];
            if((m-1)*n>=k) ans-=2*com[(m-1)*n][k];
            ans%=MOD;
            if((n-1)*m>=k) ans-=2*com[(n-1)*m][k];
            ans%=MOD;
            if((m-2)*n>=k) ans+=com[(m-2)*n][k];
            ans%=MOD;
            if((n-2)*m>=k) ans+=com[(n-2)*m][k];
            ans%=MOD;
            if((n-1)*(m-1)>=k) ans+=4*com[(n-1)*(m-1)][k];
            ans%=MOD;
            if((n-2)*(m-1)>=k) ans-=2*com[(n-2)*(m-1)][k];
            ans%=MOD;
            if((m-2)*(n-1)>=k) ans-=2*com[(m-2)*(n-1)][k];
            ans%=MOD;
            if((m-2)*(n-2)>=k) ans+=com[(m-2)*(n-2)][k];
            ans%=MOD;
            if(ans<0) ans+=MOD;
            printf("%d\n",ans);
        }
    }
    return 0;
}
