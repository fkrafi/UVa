#include<stdio.h>
#include<queue>
using namespace std;

int dr[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[] = {2, 1, -1 ,-2, -2, -1 ,1, 2};
int seen[10][10];

struct grid{
	int r, c, d;
};

typedef grid cell;

int bfs(cell s, cell t)
{
	cell u, v;
	memset(seen, 0, sizeof(seen));
	queue<cell> q;
	seen[s.r][s.c] = 1;
	s.d = 0;
	q.push(s);
	while(!q.empty())
	{
		u = q.front();
		if(t.c==u.c && t.r==u.r)return u.d;
		for(int i=0; i<8; i++)
		{
			v.r = u.r + dr[i];
			v.c = u.c + dc[i];
			if(v.r<1 || v.r>8 || v.c>8 || v.c<1)continue;
			if(!seen[v.r][v.c])
			{
				seen[v.r][v.c] = 1;
				v.d = u.d + 1;
				q.push(v);
			}
		}
		q.pop();
	}
	return t.d;
}

int main()
{
	char s1[10], s2[10];
	cell s, t;
	int res;
	while(scanf("%s%s", s1, s2) != EOF)
	{
		s.r = s1[0] - 'a' + 1;
		s.c = s1[1] - 48;
		t.r = s2[0] - 'a' + 1;
		t.c = s2[1] - 48;
		res = bfs(s, t);
		printf("To get from %s to %s takes %d knight moves.\n", s1, s2, res);
	}
	return 0;
}