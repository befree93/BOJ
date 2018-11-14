#include<iostream>//reference kks227.blog
#include<algorithm>
#include<vector>
using namespace std;
#define MAXN 1000001
vector<vector<int>> adj, child;
bool visited[MAXN];
int n, dp[MAXN][2];
void dfs(int cur)
{
	visited[cur] = true;
	for (int next : adj[cur])
	{
		if (visited[next])continue;
		child[cur].push_back(next);
		dfs(next);
	}
}
int f(int cur, int e)
{
	int &ret = dp[cur][e];
	if (ret != -1)return ret;
	int r1 = 1, r2 = 0;
	for (int next : child[cur])//cur==ea
	{
		r1 += f(next, 1);
	}
	if (e)//pa==ea
	{
		for (int next : child[cur])
		{
			r2 += f(next, 0);
		}
		return ret=min(r1, r2);
	}
	return ret=r1;
}
void tracking(int cur, int e)
{
	int r1 = 1, r2 = 1e9;
	for (int next : child[cur])r1 += f(next, 1);
	if (e)
	{
		r2 = 0;
		for (int next : child[cur])r2 += f(next, 0);
	}
	if (r1 < r2)
	{
		printf("%d is EA\n", cur+1);
		for (int next : child[cur])
			tracking(next, 1);
	}
	else
	{
		for (int next : child[cur])
			tracking(next, 0);
	}
}
int main()
{
	scanf("%d", &n);
	adj.resize(n), child.resize(n);
	for (int i = 1; i <n; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i <n; i++)dp[i][0] = dp[i][1] = -1;
	dfs(0);
	printf("%d\n", f(0, 1));
	tracking(0, 1);
	return 0;
}