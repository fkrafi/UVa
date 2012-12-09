#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
#define inf 2147483640
#define SIZE 20005

vector<int> edge[SIZE],w[SIZE];
int n,m,seen[SIZE],dis[SIZE],cas = 1;

class Compare
{
	public:
		bool operator()(int &u, int &v)
		{
			return dis[u]>dis[v];
		}
};

priority_queue<int, vector<int>, Compare> pq;

int dijkstra(int source, int target)
{
	int i, v;

	for(i=0; i<=n; i++)
		dis[i] = inf;

	dis[source] = 0;
	pq.push(source);

	while(!pq.empty())
	{
		int u = pq.top();
		pq.pop();

		for(i=0; i<edge[u].size(); i++)
		{
			v = edge[u][i];
			
			if(seen[v]==cas)
				continue;

			if(dis[v] > (dis[u]+w[u][i]))
			{
				dis[v] = dis[u]+w[u][i] ;
				pq.push(v);
			}
		}
		
		seen[u] = cas;
	}

	return dis[target];
}

int main()
{
	int i, t, u, v, S, T, cost;

	freopen("input.txt", "r", stdin);

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&S,&T);

		for(i=0; i<=n; i++)
		{
			edge[i].clear();
			w[i].clear();
		}

		for(i=0; i<m; i++)
		{
			scanf("%d%d%d",&u,&v,&cost);

			edge[u].push_back(v);
			edge[v].push_back(u);

			w[u].push_back(cost);
			w[v].push_back(cost);
		}

		cost = dijkstra(S,T);

		if(cost == inf)
			printf("Case #%d: unreachable\n", cas++);
		else
			printf("Case #%d: %d\n",cas++, cost);
	}
	return 0;
}