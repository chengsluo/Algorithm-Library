#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int k,m;

struct mt{
    int a[10][10];
};

mt multi(mt m1,mt m2) {
    mt m3;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            m3.a[i][j]=0;
            for(int kk=0;kk<10;kk++){
                m3.a[i][j]+=m1.a[i][kk]*m2.a[kk][j]%m;
                m3.a[i][j]%=m;
            }
        }
    }
    return m3;
}

int power(mt m1) {
//    for(int i=0;i<10;i++){
//        for(int j=0;j<10;j++){
//            cout<<m1.a[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    mt m2;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i==j) m2.a[i][j]=1;
            else m2.a[i][j]=0;
        }
    }
    k=k-9;
    while(k){
        if(k%2) m2=multi(m2,m1);
        k>>=1;
         m1=multi(m1,m1);
    }
    int ans=0;
    for(int i=0;i<10;i++){
        ans+=m2.a[0][i]*(9-i)%m;
        ans%=m;
    }
    return ans;
}

int main()
{
    mt m1;
    for(int i=1;i<10;i++){
        for(int j=0;j<10;j++){
            if(i-1==j) m1.a[i][j]=1;///一定要注意行标和列标的关系
            else m1.a[i][j]=0;
        }
    }
    while(scanf("%d%d",&k,&m)==2){
        for(int i=0;i<10;i++){
            scanf("%d",&(m1.a[0][i]));
        }
        if(k<10) {printf("%d\n",k);continue;}
        printf("%d\n",power(m1));
    }
    return 0;
}
