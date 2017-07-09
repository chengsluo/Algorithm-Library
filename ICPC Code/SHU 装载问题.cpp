#include<iostream>
using namespace std;

int w[25], bestx[25];
int MaxLoading(int n,int c)
{
	int i = 1;
	int *x = new int[n +1];
	int bestw = 0,cw = 0,r = 0;
	for (int j = 1;j <= n;j++)
		r += w[j];
	int temp = r;//刚开始时，r为所有物品重量
	while (true) {
		while (i <= n&&cw + w[i] <= c) {//约束条件
			//进入左子树
			r -= w[i];
			cw += w[i];
			x[i] = 1;
			i++;
		}
		if (i > n) {		//到达叶节点

			//for (int j = 1;j <= n;j++) //<未优化时>在遍历的过程中也在记录最优解，会使复杂度增加n倍
			//	bestx[j] = x[j];
			bestw = cw;
		}
		else {//进入右子树
			r -= w[i];
			x[i] = 0;
			i++;
		}
		while (cw + r <= bestw) {//限界条件
			//剪枝回溯
			i--;
			while (i > 0 && !x[i]) {
				//从右子树返回
				r += w[i];
				i--;
			}
			if (i == 0) { delete[] x;
				goto breakloop;//<优化>已找到最优装载量，退出循环
			}
			//进入右子树
			x[i] = 0;
			cw -= w[i];
			i++;
		}
	}
	breakloop://开始根据最优装载量构造最优解
	cw = 0;r = temp;//将cw和r置为初始值
	while (true) {
		while (i <= n&&cw + w[i] <= bestw) {
			r -= w[i];
			cw += w[i];
			bestx[i] = 1;
			i++;
		}
		if (i > n) {//遍历到叶节点，即找到最优解bestw[];
			return bestw;
		}
		else {
			r -= w[i];
			bestx[i] = 0;
			i++;
		}
	}
}
int main()
{
	int n,ct=0;
	while (cin >> n)
	{
		int sum = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> w[i];sum += w[i];
		}
		int c1, c2;//两艘船的容量
		cin >> c1 >> c2;
		cout << "Case " << ++ct << endl;
		int bestw1 = MaxLoading(n, c1);
		if (sum - bestw1 <= c2)//全部能装上船的条件
		{
			cout << bestw1<<" ";
			for (int i = 1;i <= n;i++)
				cout <<bestx[i];
			cout << endl<<endl;
		}
		else cout << "No"<<endl<<endl;
	}
	return 0;
}