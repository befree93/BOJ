#include<iostream>
using namespace std;
int n, dp[1001][10];
const int mod = 10007;
int solve(int cur, int num)
{
	if (cur == n)return 1;
	int &ret = dp[cur][num];
	if (ret)return ret;
	ret = solve(cur + 1, num),ret%=mod;
	if (num < 9)ret += solve(cur, num + 1), ret %= mod;
	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	cout << solve(0,0) << endl;
	return 0;
}