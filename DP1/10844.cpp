#include<iostream>
using namespace std;
int n, dp[101][10];
const int mod = 1e9;
int solve(int cur, int num)
{
	if (cur == n)return 1;
	int &ret = dp[cur][num];
	if (ret)return ret;
	if (num > 0)ret += solve(cur + 1, num - 1),ret%=mod;
	if (num < 9)ret += solve(cur + 1, num + 1), ret %= mod;
	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int ans = 0;
	for (int i = 1; i < 10; i++)
	{
		ans += solve(1, i);
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}