#include<stdio.h>
int n, dp[100001];
int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1e9;
		for (int j = 1; j*j <= i; j++)
			dp[i] = dp[i] < dp[i - j*j] + 1 ? dp[i] : dp[i - j*j] + 1;
	}
	printf("%d\n", dp[n]);
	return 0;
}