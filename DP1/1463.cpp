#include<iostream>
#include<algorithm>
using namespace std;
int dp[1000001];
int solve(int num)//top->down
{
	if (num <= 1)return 0;
	int &ret = dp[num];
	if (ret !=-1)return ret;
	ret = 1e9;
	if (num % 3 == 0)ret = min(ret, solve(num / 3)+1);
	if (num % 2 == 0)ret = min(ret, solve(num / 2)+1);
	ret = min(ret, solve(num - 1)+1);
	return ret;
}
int solve2(int n)//bottom->up
{
	dp[1] = dp[0] = 0;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0)dp[i] = min(dp[i], dp[i / 2] + 1);
	}
	return dp[n];
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	//for (int i = n; i >= 0; i--)dp[i] = -1; //topdown
	cout << solve(n);
	return 0;
}