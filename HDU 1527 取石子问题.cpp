#include<bits/stdc++.h>
using namespace std;
//HDU 1527取石子游戏
//威佐夫博弈(Wythoff Game)

//我们用表示两堆物品的数量并称其为局势，如果甲面对，那么甲已经输了，这种局势我们称为奇异局势。
//前几个奇异局势是(0,0),(1,2),(3,5),(4,7),(6,10)。
//可以看出a0=b0=0.其中ak是未在前面出现过的最小自然数,而bk=ak+k。

int main()
{
    int a , b ;
    while ( cin >> a >> b ) {
        if ( a < b ) swap( a, b ) ;
        if(a==0||b==0){
            cout<<1<<endl;
            continue;
        }
        int k = a - b ;
        int n = (int)( k * ( sqrt(5.0) + 1.0 ) / 2 ) ;
        bool win = ( n != b ) ;
        cout << win << endl ;
    }
    return 0;
}

