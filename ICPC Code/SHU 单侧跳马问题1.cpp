#include<iostream>
#include<queue>
using namespace std;

const int N = 8;
queue<pair<pair<int,int>,int> > qu;
int num[4][2] = { {1,2},{2,1},{1,-2},{2,-1} };

int  JumpSingle(int a, int b)
{
	int bests = -1;
	if (a == N&&b == N) return 0;
	for (int i = 0;i < 4;i++)
	{
		if (a + num[i][0] == N&&b + num[i][1] == N)
		{
			return 1;
		}
		if (a+num[i][0]<=N &&b+num[i][1]>=1&&b + num[i][1] <= N)
			qu.push(make_pair(make_pair(a + num[i][0],b + num[i][1]),2));
	}
	while (!qu.empty())
	{
		int x = qu.front().first.first, y=qu.front().first.second, s=qu.front().second;
		//cout << x <<" "<< y << endl;
		qu.pop();
		for (int i = 0;i < 4;i++)
		{
			if (x + num[i][0] == N&&y + num[i][1] == N)
			{
				if (s > bests) bests = s;
				continue;
			}
			else if(x + num[i][0] <= N && y+ num[i][1] >= 1 && y + num[i][1] <= N)
				qu.push(make_pair(make_pair(x + num[i][0], y + num[i][1]), s+1));
		}
	}
	return bests;
}
int main()
{
	int a, b;
	while (cin >> b >> a)//a,bµÄË³Ğò´íÎó£¬bibi!
	{
		int step = JumpSingle(a, b);
		if (step >= 0) cout << step << endl;
		else cout << "Impossible" << endl;
	}
	return 0;
}