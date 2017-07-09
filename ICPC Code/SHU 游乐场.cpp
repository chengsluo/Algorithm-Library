#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const long long INF = 1000000010;
long long c[10010];
int b[10010];

int main()
{
	long long k, a;
	int n, m, ans;
	int t;
	cin>>t;
	while (t--) {
		scanf("%d%d%dd",&n,&m,&k);
		a = 0;
		for (int i = 0;i<n;i++) scanf("%dd",&c[i]);
		for (int i = 0;i<m;i++) { scanf("%dd",&b[i]);int temp=b[i] - 1;a += c[temp];c[temp] = INF; }
		if (a>k) { printf("-1\n");continue; }
		sort(c,c+n);
		ans = m;
		for (int i = 0;i<n - m;i++) {
			a += c[i];
			if (a <= k) ans++;
			else break;
		}
		printf("%d\n",ans);
	}
	return 0;
}