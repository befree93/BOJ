#include<iostream>
#include<algorithm>
using namespace std;

int n, cost[1001], dp[1001];

int solve(int s)
{
	if (s == 0)return 0;
	int &ret = dp[s];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = 0; i < s; i++)
		ret = max(ret, cost[i] + solve(s - i - 1));
	return ret;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i <n; i++)cin >> cost[i],dp[i]=-1;
	dp[n] = -1;
	cout << solve(n);
	return 0;
}