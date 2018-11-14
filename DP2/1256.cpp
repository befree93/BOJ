#include<iostream>
#include<algorithm>
using namespace std;

char res[201];
int dp[101][101],top;
const int INF = 1e9+1;
int f(int n, int m)
{
	int &ret = dp[n][m];
	if (ret)return ret;
	if (!n || !m)return ret = 1;
	return ret = min(f(n - 1, m) + f(n, m - 1), INF);

}
bool skip(int n, int m, int k)
{
	if (n == 0)
	{
		for (int i = 0; i < m; i++)res[top++] = 'z';
		return true;
	}
	if (m == 0)
	{
		for (int i = 0; i < n; i++)res[top++] = 'a';
		return true;
	}
	int p = f(n - 1, m);
	if (k < p)
	{
		res[top++] = 'a';
		return skip(n - 1, m, k);
	}
	else if (p < INF)
	{
		res[top++] = 'z';
		return skip(n, m - 1, k-p);
	}
	return false;
}
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	if (k > f(n, m)||!skip(n,m,k-1))puts("-1");
	else printf("%s\n", res);
	return 0;
}