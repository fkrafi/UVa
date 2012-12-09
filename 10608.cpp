#include<stdio.h>
#include<vector>
using namespace std;
#define SZ 30005


vector<int> edge[SZ];
int seen[SZ], cs;
int n, m;
int temp;

void dfs(int s)
{
	seen[s] = cs;
	temp++;
	int i, v;
	for(i=0; i<edge[s].size(); i++)
	{
		v = edge[s][i];
		if(seen[v] != cs)
			dfs(v);
	}
}

int main()
{
	freopen("10608.txt", "r", stdin);
	int t, i, u, v, max;
	scanf("%d", &t);
	cs = 1;
	while(t--)
	{
		scanf("%d%d", &n, &m);
		for(i=1; i<=n; i++)
			edge[i].clear();
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		max = -1;
		for(i=1; i<=n; i++)
		{
			temp = 0;
			dfs(i);
			if(max<temp)max = temp;
		}
		printf("%d\n", max);
		cs++;
	}
	return 0;
}