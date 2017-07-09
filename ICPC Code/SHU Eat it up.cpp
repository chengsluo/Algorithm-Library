#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
const int MAX=1010;
typedef long long ll;
using namespace std;

int main()
{
    int n,a,b;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        if(a%2==0||b%2==0){//理清思路，从小数慢慢推理，往往具有奇偶性质
            printf("yaoge\n");
        }
        else{
            printf("xyiyy\n");
        }
    }
    return 0;
}
