#include <cstdio>
using namespace std;

int n, ans;
int limit;

void dfs( int h, int r, int l ) {
    //h为每一纵列现在的状态,二进制码串
    //r为主对角线上每一个元素所在斜线上现在的状态,二进制码串//r为主对角线上每一个元素所在斜线上现在的状态,二进制码串
    //l为副对角线上每一个元素所在斜线上现在的状态,二进制码串//r为主对角线上每一个元素所在斜线上现在的状态,二进制码串
    if ( h == limit ) {  //说明n列都站满了
        ans++;
        return;
    }
    int pos = limit & (~(h|r|l)), p; //pos的二进制位0的，并且这个limit不能省，limit保证了pos高于n的位为0
    //pos表示还缺少的位置,二进制码串
    while ( pos ) {
        p = pos & (-pos); //这个运算，即原码和补码取与的运算，可以得出最右边的1；
        ///p为最右边的一个空位置
        pos -= p;
        ///去掉这个空位置
        dfs( h+p, (r+p)<<1, (l+p)>>1 );
        //r+p<<1代表p对副对角线的影响,会随着递归推移
        //l+p>>1代表p对主对角线的影响,会随着递归推移
    }
}
int main()
{
    while ( scanf("%d", &n) != EOF && n ) {
        ans = 0;
        limit = ( 1<<n ) - 1; //limit的二进制是n个1；
        dfs( 0, 0, 0 );
        printf("%d\n", ans);
    }
}