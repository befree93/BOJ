#include<iostream>
#include<algorithm>
using namespace std;
char res[32];
int dp[32][32],top;

int f(int n, int m)
{
	int &ret = dp[n][m];
	if (ret)return ret;
	if (n == 0 || m == 0)return ret = 1;
	ret = f(n - 1, m);
	if (m > 0)ret += f(n - 1, m - 1);//possible using '1'
	return ret;
}
void skip(int n, int m, int k)
{
	if (n == 0)return;
	if (m == 0)
	{
		for (int i = 0; i < n; i++)res[top++] = '0';
		return;
	}
	int p = f(n - 1, m);
	if (k < p)
	{
		res[top++] = '0';
		skip(n - 1, m, k);
	}
	else
	{
		res[top++] = '1';
		skip(n - 1, m - 1, k - p);
	}
}
int main()
{
	long long n, m, k; //k over the range of integer;
	cin >> n >> m >> k;
	f(n, m);
	skip(n, m, k-1);
	printf("%s\n", res);
	return 0;
}
