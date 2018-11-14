#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MAXN 10001
bool visited[MAXN];
int  n, W[MAXN], dp[MAXN][2],parent[MAXN];
vector <vector<int>> adj;
vector<int> res;
void dfs(int cur)
{
	visited[cur] = true;
	for (int next : adj[cur])
	{
		if (visited[next])continue;
		parent[next] = cur;
		dfs(next);
	}
}

int f(int cur,int p)
{
	int &ret = dp[cur][p];
	if (ret != -1)return ret;
	int r1 = W[cur], r2 = 0;
	for (int next : adj[cur])
	{
		if (parent[next] != cur)continue;
		r1 += f(next, 1);
		r2 += f(next, 0);
	}
	if (!p&&r1 > r2)return ret = r1;
	return ret = r2;
}
void tracking(int cur, int p)
{
	int r1 = W[cur], r2 = 0;
	for (int next : adj[cur])
	{
		if (parent[next] != cur)continue;
		r1 += f(next, 1);
		r2 += f(next, 0);
	}
	if (!p&&r1 > r2)
	{
		res.push_back(cur);
		for (int next : adj[cur])
			if (parent[next] == cur)tracking(next, 1);
	}
	else
		for (int next : adj[cur])
			if (parent[next] == cur)tracking(next, 0);
}
int main()
{
	scanf("%d", &n);
	adj.resize(n+1);
	for (int i = 1; i <=n; i++)scanf("%d", W + i), dp[i][0] = dp[i][1] = -1;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	int ans = f(1, 0);
	printf("%d\n", ans);
	tracking(1, 0);
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++)printf("%d ", res[i]);
	return 0;
}