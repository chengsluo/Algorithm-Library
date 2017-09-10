#include<cstdio>
#include<cstring>
using namespace std;
int prime[7],pn;
//总的来说，这还是属于容斥原理的一道模板题


//小于m的数中，与i的互斥的数的个数
int getCnt(int n,int m){
    pn=0;
    //i×i质因数的平方小于本身
    for(int i=2; i*i<=m; ++i){
        if(m%i) continue;
        while(m%i==0) m/=i;//这里的while循环保证了这里的因式被除尽了
        prime[pn++]=i;
    }
    if(m!=1) prime[pn++]=m;
    //上面是一种获取素数的方法,但只适用与因式分解。

    //容斥原理，与m不互斥的数(与ijkl中的某一个不互斥)总的个数=sigma(与质因子i不互斥)-sigma(与质因子ij不互斥)+sigma(与质因子ijk不互斥)...
    int res=0;
    //遍历所有与m不互斥的数,所有质因子最多1次方。
        //i必须从1开始，只有这时规则才开始生效
    for(int i=1; i<(1<<pn); ++i){
        int tmp=1,cnt=0;
        //cnt统计这个数包含的不同质因子的个数
        //所有质因子的乘积
        for(int j=0; j<pn; ++j){
            if(((i>>j)&1)==0) continue;
            tmp*=prime[j];
            ++cnt;
        }
        //包含质因子偶数个，按照容斥公式需要+；奇数个，按照容斥公式需要-
        if(cnt&1) res+=n/tmp;
        else res-=n/tmp;
    }
    return n-res;
    
}
int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        long long res=0;
        for(int i=1; i<=n; ++i){
            res+=getCnt(m,i);
        }
        printf("%lld\n",res);
    }
    return 0;
}