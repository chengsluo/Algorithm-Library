#include<iostream>
#include<queue>
using namespace std;

queue<pair<pair<int, int>, int> > qu;
int num[8][2] = { { 1,2 },{ 2,1 },{ 1,-2 },{ 2,-1 },{ -1,2 },{ -2,1 },{ -1,-2 },{ -2,-1 } };
int m = 8, n = 8, e1, e2, s1, s2;

int  Jump(int a, int b)
{
	int bests = -1;
	if (a == e1&&b == e2) return 0;
	if (a <= 0 || a >= m || b <= 0 || b >= n) return -1;
	for (int i = 0;i < 8;i++)
	{
		if (a + num[i][0] == e1&&b + num[i][1] == e2)
		{
			return 1;
		}
		if (a + num[i][0] <= m &&a + num[i][0] >= 1 && b + num[i][1] >= 1 && b + num[i][1] <= n)
			qu.push(make_pair(make_pair(a + num[i][0], b + num[i][1]), 2));
	}
	while (!qu.empty())
	{
		int x = qu.front().first.first, y = qu.front().first.second, s = qu.front().second;
		cout << x <<" "<< y << endl;
		qu.pop();
		for (int i = 0;i < 8;i++)
		{
			if (x + num[i][0] == e1&&y + num[i][1] == e2)
			{
				if (s > bests) bests = s;
				continue;
			}
			else if (x + num[i][0] <= m &&x + num[i][0] >= 1 && y + num[i][1] >= 1 && y + num[i][1] <= n)
				qu.push(make_pair(make_pair(x + num[i][0], y + num[i][1]), s + 1));
		}
	}
	return bests;
}
int main()
{
	char str[6];
	while (gets_s(str))
	{
		s1 = str[0] - 'a' + 1;
		s2 = str[1] - '0';
		e1 = str[3] - 'a' + 1;
		e2 = str[4] - '0';
		cout << str[0]<<str[1]<< "==>" <<str[3]<<str[4]<< ": " << Jump(s1, s2) << " moves" << endl;
	}
	return 0;
}