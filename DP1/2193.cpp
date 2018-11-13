#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long dp[100][2];

long long solve(int cur, int s)//top down
{
	if (cur == 1)return s == 1;
	if (dp[cur][s])return dp[cur][s];
	if (s == 0)dp[cur][s]= solve(cur - 1, 0) + solve(cur - 1, 1);
	else if (s == 1)dp[cur][s] = solve(cur - 1, 0);
	return dp[cur][s];
}
long long solve()//bottom up
{
	dp[1][0] = 0; dp[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
		dp[i][1] = dp[i - 1][0];
	}
	return dp[n][0] + dp[n][1];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cout << solve(n,0)+solve(n,1);
	return 0;
}