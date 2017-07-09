#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
const int MAX=66000;
typedef long long ll;
using namespace std;

int num[MAX];
int main()
{
    int temp;
    int ct=0;
    char ch;
    while(scanf("%d",&temp)==1){//
        ch=getchar();//处理空格与换行的方法
        if(ch==' '){
            int i;
            for(i=0;i<ct;i++){
                if(temp==num[i]) break;
            }
            if(i>=ct) {
                    num[ct]=temp;
                    ct++;
            }
        }
        else{
            int i;
            for(i=0;i<ct;i++){
                if(temp==num[i]) break;
            }
            if(i>=ct) {
                    num[ct]=temp;
                    ct++;
            }
            for(int i=0;i<ct;i++){
               if(i) printf(" ");
               printf("%d",num[i]);
            }
            printf("\n");
            ct=0;
        }
    }
    return 0;
}
