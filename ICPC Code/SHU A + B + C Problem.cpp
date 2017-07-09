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

int num[1010];

int main()
{
    int n,s;
    while(scanf("%d%d",&n,&s)==2){
        bool f=0;
        for(int i=0;i<n;i++){
            scanf("%d",num+i);
        }
        sort(num,num+n);
        int k;
        for(k=n-1;num[k]>s;k--);
        for(int i=0;i<=k-2;i++){
                int l=i+1,r=k;
                while(l<r){
                    if(num[i]+num[l]+num[r]==s) {f=1;break;}
                    else if(num[i]+num[l]+num[r]>s) r--;
                    else l++;
                }
                if(f) break;
        }
        if(f) cout<<"YES"<<endl;
        else  cout<<"NO"<<endl;
    }
    return 0;
}
//int main()
//{
//    int n,s;
//    while(scanf("%d%d",&n,&s)==2){
//        bool f=0;
//        for(int i=0;i<n;i++){
//            scanf("%d",num+i);
//        }
//        sort(num,num+n);
//        int k;
//        for(k=n-1;num[k]>s;k--);
//
//        for(int i=0;i<k-1;i++){
//            for(int j=i+1;j<k;j++){
//                int p;
//                for(p=k;num[j]+num[i]+num[p]>s&&p>j+1;p--);
//                if(num[j]+num[i]+num[p]==s){
//                    f=1;
//                    break;
//                }
//            }
//        }
//        if(f) cout<<"YES"<<endl;
//        else  cout<<"NO"<<endl;
//    }
//    return 0;
//}
