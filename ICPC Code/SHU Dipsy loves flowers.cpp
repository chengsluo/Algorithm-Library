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
char ch[1010][1010];
int a[1010][1010];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int m,n;
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        getchar();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%c",&ch[i][j]);
            }
            getchar();
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ch[i][j]=='.'){
                    int ct=1;
                    int k;
                    for(k=j+1;k<m&&ch[i][k]=='.';k++){
                        ct++;
                    }
                    for(int p=j;p<k;p++){
                        a[i][p]=ct;
                    }
                    j=k-1;
                }
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(ch[i][j]=='.'){
                    int ct=1;
                    int k;
                    for(k=i+1;k<n&&ch[k][j]=='.';k++){
                        ct++;
                    }
                    for(int p=i;p<k;p++){
                        a[p][j]+=ct;
                    }
                    i=k-1;
                }
            }
        }
        int ans=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //cout<<a[i][j]<<endl;
                if(a[i][j]>ans) ans=a[i][j];
            }
        }
        cout<<ans-2<<endl;
    }
    return 0;
}
