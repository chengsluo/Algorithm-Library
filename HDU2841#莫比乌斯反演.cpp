#include<iostream>  
#include<cstdio>  
#include<algorithm>
#include<cstdlib>
#include<cstring>

using namespace std;  
typedef long long  ll;  
const ll p =1000000007;  
const int  N=100000;  
bool not_prime[N+500];  
int prime[N+50];  
int mu[N+50];  
ll sum[N+50];  
ll tot;  

//线性筛选求莫比乌斯反演函数代码
void Moblus()  
{  
    //总的素数的个数
    tot = 0;  
    memset(not_prime,0,sizeof(not_prime));      
    //mu数组，代表了f(n)=sigma(mu[d]*F(n/d))中的系数数组.F(n)=sigma(f(d)).其中d|n.
    //mu(d)为莫比乌斯函数，
    mu[1] = 1;  
    for(ll i = 2; i < N; i++){  
        if(!not_prime[i]){
            prime[tot++] = i;  
            mu[i] = -1;
        }
        //mu(d)为积性函数，
        for(ll j = 0; j < tot && i*prime[j] < N; j++){  
            not_prime[i*prime[j]] = 1;
            if(i % prime[j]!=0){
                mu[i*prime[j]] = -mu[i];//因为所有质数的mu为-1
            }else{
                mu[i*prime[j]] = 0;//i是prime[j]的倍数,也就是至少某个质因子出现了两次及以上
                break;//去掉break;也能AC。
                //在直接可以break掉的原因是:当i的某个质因子出现两次之后，更大的质因子进行判断时并不影响...其实我也不知道。以8为例：not_prime[16]=1;8%2==0;mu[16]=1;not_prime[24]=1;mu[24]=-mu[8]
            }
        }
    }
}  
//找[1,n],[1,m]内互质的数的对数.
ll solve(ll n,ll m )  
{  
    if (n>m)swap(n,m);  
    ll ret=0;  
    for (int i=1;i<=n;i++)  
        ret+=mu[i]*(n/i)*(m/i); 
        //根据莫比乌斯反演的变形公式推导而出
    return ret;
}  
int main()  
{  
    Moblus();  
    int t;cin>>t;  
    while(t--)  
    {  
        ll k,a,b,c,d;  
        scanf("%lld",&a);  
        scanf("%lld",&b);  
        ll ans1=solve(a,b);  
        printf("%lld\n",ans1);  
    }
    return 0;  
}  