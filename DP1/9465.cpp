#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 100001
int T,n,arr[2][MAXN], dp[MAXN][3];//1:up, 2: down, 0: nothing
int solve(int cur, int s)//top down
{
	if (cur == n)return 0;
	int &ret = dp[cur][s];
	if (ret != -1)return ret;
	ret = solve(cur + 1, 0);
	if (s != 1)ret = max(ret, solve(cur + 1, 1) + arr[0][cur]);
	if (s != 2)ret = max(ret, solve(cur + 1, 2) + arr[1][cur]);
	return ret;
}
int solve()//bottom up
{
	for (int i = 0; i <=n; i++)for (int j = 0; j < 3; j++)dp[i][j] = 0;
	for (int i = 1; i <=n; i++)
	{
		dp[i][0] = max(dp[i][0], max(dp[i - 1][0], max(dp[i-1][1],dp[i - 1][2])));
		dp[i][1] = max(dp[i][1], max(dp[i - 1][0], dp[i - 1][2]) + arr[0][i-1]);
		dp[i][2] = max(dp[i][2], max(dp[i - 1][0], dp[i - 1][1]) + arr[1][i - 1]);
	}
	return max(dp[n][0], max(dp[n][1], dp[n][2]));
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)cin >> arr[i][j];
		for (int i = 0; i < n; i++)dp[i][0] = dp[i][1] = dp[i][2] = -1;
		cout << solve(0, 0) << "\n";
	}
	return 0;
}