#include<iostream>
#include<cmath>
using namespace std;

double a[110][4];
int main()
{
	int t;
	while (cin >> t&&t) {
		for (int i = 0;i<t;i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
		}
		int ans = 0;
		for (int i = 0;i<t - 1;i++) {
			for (int j = i + 1;j<t;j++) {//对于计算集合，还是用struct比较好
				if (((a[j][2] - a[i][0])*(a[i][3] - a[i][1]) - (a[j][3] - a[i][1])*(a[i][2] - a[i][0]))
					*((a[i][2] - a[i][0])*(a[j][1] - a[i][1]) - (a[i][3] - a[i][1])*(a[j][0] - a[i][0])) >= 0) {
					// a[j][2]-a[i][0],a[j][3]-a[i][1];a[i][2]-a[i][0],a[i][3]-a[i][1]
					// a[i][2]-a[i][0],a[i][3]-a[i][1];a[j][0]-a[i][0],a[j][1]-a[i][1];
					int temp = i;i = j;j = temp;//代码重复度很高，在节约时间的情况下可以直接替换，不改代码
					if (((a[j][2] - a[i][0])*(a[i][3] - a[i][1]) - (a[j][3] - a[i][1])*(a[i][2] - a[i][0]))
						*((a[i][2] - a[i][0])*(a[j][1] - a[i][1]) - (a[i][3] - a[i][1])*(a[j][0] - a[i][0])) >= 0)
						//
						//
						ans++;
					temp = i;i = j;j = temp;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
