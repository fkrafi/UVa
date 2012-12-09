#include<stdio.h>
#include<vector>
using namespace std;
#define SZ 50005

int seen[SZ], cs;
int m, n;
vector<int> edge[SZ];

void dfs(int s)
{
	seen[s] = cs;
	int i, v, l=edge[s].size();
	for(i=0; i<l; i++)
	{
		v = edge[s][i];
		if(seen[v] != cs)
			dfs(v);
	}
}

int main()
{
	int u, v, i, cnt;
	cs = 1;
	while(scanf("%d%d", &n, &m))
	{
		if(!n && !m)break;
		for(i=1; i<=n; i++)edge[i].clear();
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		cnt = 0;
		for(i=1; i<=n; i++)
		{
			if(seen[i] != cs)
			{
				dfs(i);
				cnt++;
			}
		}
		printf("Case %d: %d\n", cs++, cnt);
	}
	return 0;
}