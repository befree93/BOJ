#include<iostream>
#include<algorithm>
using namespace std;
#define INF 0x3c3c3c3c
int n, k, cost[101];
int dp[101][10001];
int solve(int now, int s)
{
	if (now == n)return (s == 0 ? 0 : INF);
	int &ret = dp[now][s];
	if (ret!=-1)return ret;
	ret = solve(now + 1, s);
	if (s >= cost[now])ret = min(ret, solve(now, s - cost[now]) + 1);
	return ret;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> cost[i];
	for (int i = 0; i <= n; i++)for (int j = 0; j <= k; j++)dp[i][j] = -1;
	int ans = solve(0, k);
	if (ans==INF)cout<<"-1";
	else cout <<ans;
	return 0;
}