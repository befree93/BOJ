#include<iostream>
#include<algorithm>
using namespace std;
int n,cost[1001][3], dp[1001][3];

int f(int now, int col)
{
	if (now == n)return 0;
	int &ret = dp[now][col];
	if (ret)return ret;
	ret = 1e9;
	for (int i = 0; i < 3; i++)
		if (col != i)ret = min(ret, f(now + 1, i) + cost[now][i]);
	return ret;
}
void tracking(int now, int col)//dp[n][c]==cost[n][!c]+dp[n+1][!c]?
{
	if (now == n)return;
	for (int i = 0; i < 3; i++)
	{
		if (col != i && f(now, col) == cost[now][i] + f(now + 1, i))
		{
			cout << now << "¹øÂ° »ö±ò: " << i << "\n";
			tracking(now + 1, i);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)cin >> cost[i][j];
	int ans = 1e9,idx;
	for (int i = 0; i < 3; i++)
	{
		if (ans > f(0, i))
		{
			ans = f(0, i);
			idx = i;
		}
	}
	tracking(0, idx);
	cout << ans;
	return 0;
}