#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define SZ 1010
typedef pair<int, int> pi;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int nR, nC, d;
int seen[SZ][SZ], cst[SZ][SZ];
pi s, e, u, v;
queue<pi> q, eQ;

void bfs()
{
	int i;
	q.push(s);
	seen[s.first][s.second] = 0;
	cst[s.first][s.second] = 0;
	while(!q.empty())
	{
		u = q.front();
		for(i=0; i<4; i++)
		{
			v.first = u.first + dr[i];
			v.second = u.second + dc[i];
			if( v.first<0 || v.second<0 || v.first>=nR || v.second>=nC )continue;
			if(seen[v.first][v.second] == d)continue;
			seen[v.first][v.second] = d;
			cst[v.first][v.second] = cst[u.first][u.second] + 1;
			q.push(v);
			if(v == e)return;
		}
		q.pop();
	}
}

int main()
{
//	freopen("10653.txt", "r", stdin);
	int i, j, nB, n, r, c;
	d = 1;
	while(scanf("%d%d", &nR, &nC))
	{
		if(!nR && !nC)break;
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &r, &nB);
			for(j=0; j<nB; j++)
			{
				scanf("%d", &c);
				seen[r][c] = d;
			}
		}
		scanf("%d%d", &s.first, &s.second);
		scanf("%d%d", &e.first, &e.second);
		cst[e.first][e.second] = 0;
		bfs();
		printf("%d\n", cst[e.first][e.second]);
		d++;
		q = eQ;
	}
	return 0;
}