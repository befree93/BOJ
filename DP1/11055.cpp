#include<iostream>
#include<algorithm>
using namespace std;

int n, a[1001], dp[1001];
int solve(int cur)
{
	if (cur == n)return 0;
	int &ret = dp[cur];
	if (ret)return ret;
	ret = a[cur];
	int tmp = 0;
	for (int i = cur + 1; i < n; i++)
		if (a[cur] < a[i])tmp = max(tmp,solve(i));
	return ret+=tmp;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	int ans = 0;
	for (int i = 0; i < n; i++)ans = max(ans, solve(i));
	cout << ans;
	return 0;
}