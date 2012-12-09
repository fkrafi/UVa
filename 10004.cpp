#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;


int color[210];

int bfs(vector<int> edge[])
{
	queue<int> q;
	int i, u, v;
	q.push(0);
	color[0] = 1;
	while(!q.empty())
	{
		u = q.front();
		for(i=0; i<edge[u].size(); i++)
		{
			v = edge[u][i];
			if(!color[v])
			{
				q.push(v);
				color[v] = (color[u]==1)?2:1;
			}else if(color[u]==color[v])return 0;
		}
		q.pop();
	}
	return 1;
}

void take_input(int l)
{
	vector<int> edge[210];
	int i, u, v, res;
	for(i=0; i<l; i++)
	{
		scanf("%d%d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	memset(color, 0, sizeof(color));
	res = bfs(edge);
	if(res)
		printf("BICOLORABLE.\n");
	else
		printf("NOT BICOLORABLE.\n");
}

int main()
{
	int n, l;
	while(scanf("%d", &n))
	{
		if(!n)break;
		scanf("%d", &l);
		take_input(l);
	}
	return 0;
}