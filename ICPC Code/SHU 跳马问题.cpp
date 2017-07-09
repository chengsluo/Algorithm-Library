#include<iostream>
#include<cstring>
using namespace std;

int h, t, r;
int g[70][70];
void eq(int q[], int d)
{
	q[h++] = d;
	if (h>200) h = 1;
}
int dq(int q[])
{
	r = q[++t];
	q[t] = 0;
	return r;
}
int BFS(int s1, int s2)
{
	int k = 1,  i, color[70], d[70], q[1800], u;
	for (i = 1;i <= 64;++i)
	{
		color[i] = 0;
		d[i] = 50;
	}
	color[s1] = 1;
	d[s1] = 0;
	h = 1;
	t = 0;
	memset(q, 0, sizeof(q));
	eq(q, s1);
	while (h - t != 1)
	{
		u = dq(q);
		for (i = 1;i <= 64;++i)
			if (g[u][i] == 1)
			{
				if (color[i] == 0)
				{
					color[i] = 1;
					d[i] = d[u] + 1;
					if (i == s2) return d[i];
					eq(q, i);
				}
			}
		color[u] = 2;
	}
}
int main()
{
	 int i, j, x1, x2, y1, y2, s1, s2;char a[6];
	for (j = 1;j <= 8;++j)
		for (i = 1;i <= 8;++i){
			if ((i + 1 <= 8) && (j + 2 <= 8)) g[8 * (i - 1) + j][8 * i + j + 2] = 1;
			if ((i + 2 <= 8) && (j + 1 <= 8)) g[8 * (i - 1) + j][8 * (i + 1) + j + 1] = 1;
			if ((i + 2 <= 8) && (j - 1>0)) g[8 * (i - 1) + j][8 * (i + 1) + j - 1] = 1;
			if ((i + 1 <= 8) && (j - 2>0)) g[8 * (i - 1) + j][8 * i + j - 2] = 1;
			if ((i - 1>0) && (j - 2>0)) g[8 * (i - 1) + j][8 * (i - 2) + j - 2] = 1;
			if ((i - 2>0) && (j - 1>0)) g[8 * (i - 1) + j][8 * (i - 3) + j - 1] = 1;
			if ((i - 2>0) && (j + 1 <= 8)) g[8 * (i - 1) + j][8 * (i - 3) + j + 1] = 1;
			if ((i - 1>0) && (j + 2 <= 8)) g[8 * (i - 1) + j][8 * (i - 2) + j + 2] = 1;
		}
	while (gets(a) != NULL)
	{
		x1 = a[0] - 'a' + 1;
		y1 = a[1] - '0';
		x2 = a[3] - 'a' + 1;
		y2 = a[4] - '0';
		s1 = 8 * (x1 - 1) + y1;
		s2 = 8 * (x2 - 1) + y2;
		if (s1 == s2)  cout <<a[0]<<a[1]<<"==>"<<a[3]<<a[4]<<": " <<0 <<" moves" <<endl;
		else
			cout << a[0] << a[1] << "==>" << a[3] << a[4] << ": " << BFS(s1, s2) << " moves" << endl;
	}
	return 0;
}
