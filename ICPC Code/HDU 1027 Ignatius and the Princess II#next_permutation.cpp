#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int data[1010];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i = 0; i < n; i ++)
            data[i] = i+1;
        sort(data,data+n);
        m --;
        while(m--)
            next_permutation(data,data+n);
        for( int i = 0;i<n;i++)
            printf(i ==0 ?"%d":" %d",data[i]);
        printf("\n");
    }
    return 0;
}

//首先，关于什么是全排列不做解释。如果一个排列为A，下一个排列为A_NEXT，那么A_NEXT一定与A有尽可能长的公共前缀。
//看具体例子，一个排列为124653，如何找到它的下一个排列，因为下一个排列一定与124653有尽可能长的前缀，所以，脑洞大开一下，从后面往前看这个序列，如果后面的若干个数字有下一个排列，问题就得到了解决。
//第一步：找最后面1个数字的下一个全排列。
//124653，显然最后1个数字3不具有下一个全排列。
//第二步：找最后面2个数字的下一个全排列。
//124653，显然最后2个数字53不具有下一个全排列。
//第三步：找最后面3个数字的下一个全排列。
//124653，显然最后3个数字653不具有下一个全排列。
//
//------插曲：到这里相信大家已经看出来，如果一个序列是递减的，那么它不具有下一个排列。
//
//第四步：找最后面4个数字的下一个全排列。
//124653，我们发现显然最后4个数字4653具有下一个全排列。因为它不是递减的，例如6453，5643这些排列都在4653的后面。
//
//我们总结上面的操作，并总结出重复上面操作的两种终止情况：
//1：从后向前比较相邻的两个元素，直到前一个元素小于后一个元素，停止
//2：如果已经没有了前一个元素，则说明这个排列是递减的，所以这个排列是没有下一个排列的。
//
//124653这个排列终止情况是上面介绍的第一种，从后向前比较相邻的2个元素，遇到4<6的情况停止。
//并且我们可以知道：
//1：124653和它的下一个排列的公共前缀为12(因为4653存在下一个排列，所以前面的数字12保持不变)
//2：4后面的元素是递减的(上面介绍的终止条件是前一个元素小于后一个元素，这里是4<6)
