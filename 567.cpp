#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define SZ 21

int seen[SZ], d, cst[SZ];
queue<int> q, eQ;
vector<int> edge[SZ];

void input(int u, int n)
{
	int i, v;
	for(i=0; i<n; i++)
	{
		scanf("%d", &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
}

void bfs(int s, int e)
{
	int u, v, i;
	q.push(s);
	seen[s] = d;
	cst[s] = 0;
	while(!q.empty())
	{
		u = q.front();
		for(i=0; i<edge[u].size(); i++)
		{
			v = edge[u][i];
			if(seen[v] != d)
			{
				seen[v] = d;
				q.push(v);
				cst[v] = cst[u] + 1;
				if(v == e)return;
			}
		}
		q.pop();
	}
}

int main()
{
	freopen("567.txt", "r", stdin);
	int T=1, u, n, i, v;
	d = 1;
	while(scanf("%d", &n) != EOF)
	{
		u = 1;
		input(u, n);
		for(u=u+1; u<20; u++)
		{
			scanf("%d", &n);
			input(u, n);
		}
		printf("Test Set #%d\n", T++);
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &u, &v);
			bfs(u, v);
			printf("%2d to %2d: %d\n", u, v, cst[v]);
			d++;
			q = eQ;
		}
		printf("\n");
		for(i=0; i<=20; i++)
			edge[i].clear();
	}
	return 0;
}