#include<stdio.h>
#include<queue>
#include<vector>
#include<map>
using namespace std;

int NC, C;
map<int, int> m;

void bfs();

int main()
{
	C = 1;
	while(scanf("%d", &NC))
	{
		if(!NC)break;
		bfs();
	}
	return 0;
}

void bfs()
{
	int s, ttl, i, u, v;
	vector<int> edge[50];
	queue<int> q;
	int seen[32], cst[32], cnt=0, vst;
	m.clear();
	for(i=0; i<NC; i++)
	{
		scanf("%d%d", &u, &v);
		if(m.find(u) == m.end())
			m[u] = cnt++;
		if(m.find(v) == m.end())
			m[v] = cnt++;
		u = m[u];
		v = m[v];
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	while(scanf("%d%d", &s, &ttl))
	{
		if(!s && !ttl)break;
		memset(seen, 0, sizeof(seen));
		q.push(m[s]);
		seen[m[s]] = 1;
		cst[m[s]] = 0;
		vst = 1;
		while(!q.empty())
		{
			u = q.front();
			for(i=0; i<edge[u].size(); i++)
			{
				v = edge[u][i];
				if(!seen[v] && u!=v)
				{
					seen[v] = 1;
					cst[v] = cst[u] + 1;
					if(cst[v]<=ttl)vst++;
					q.push(v);
				}
			}
			q.pop();
		}
		vst = cnt - vst;
		printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", C++, vst, s, ttl);
	}
}