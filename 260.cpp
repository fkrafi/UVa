#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
#define SZ 205
typedef pair<int, int> pii;

int dr[] = {-1, 0, 1, -1, 0, 1};
int dc[] = {-1, -1, 0, 0, 1, 1};
int n, seen[SZ][SZ];
char grid[SZ][SZ];
queue<pii> wq, bq, q;

void input()
{
	int i, j;
	char ch;
	pii u;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			while( scanf("%c", &ch) )
			{
				if(ch=='b' || ch=='w')
				{
					grid[i][j] = ch;
					if(i==1 && ch=='b')
					{
						u.first = i;
						u.second = j;
						bq.push(u);
					}
					if(j==1 && ch=='w')
					{
						u.first = i;
						u.second = j;
						wq.push(u);
					}
					break;
				}
			}
		}
	}
}

void init()
{
	int i, j;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			seen[i][j] = 0;
}

void dfs(pii S, char c, int clr)
{
	seen[S.first][S.second] = clr;
	pii u;
	int i;
	for(i=0; i<6; i++)
	{
		u.first = S.first + dr[i];
		u.second = S.second + dc[i];
		if( u.first<1 || u.first>n || u.second<1 || u.second>n)continue;
		if( grid[u.first][u.second] == c && seen[u.first][u.second] != clr )
			dfs(u, c, clr);
	}
}

int main()
{
	freopen("260.txt", "r", stdin);
	pii u;
	int i, cs=1;
	while( scanf("%d", &n) )
	{
		if(!n)break;
		init();
		input();
		while( !wq.empty() )
		{
			u = wq.front();
			if( grid[u.first][u.second] == 'w' && seen[u.first][u.second] != 1 )
				dfs(u, 'w', 1);
			wq.pop();
		}
		while( !bq.empty() )
		{
			u = bq.front();
			if( grid[u.first][u.second] == 'b' && seen[u.first][u.second] != 2 )
				dfs(u, 'b', 2);
			bq.pop();
		}
		for(i=1; i<=n; i++)
		{
			if(seen[n][i] == 2)
			{
				printf("%d B\n", cs++);
				i = -1;
				break;
			}
		}
		if(i!=-1)
			printf("%d W\n", cs++);
		wq = bq = q;
	}
	return 0;
}