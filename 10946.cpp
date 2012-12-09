#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
#define SZ 100
typedef pair<int, int> pii;
typedef pair<char, int> pci;

int r, c;
int cnt;
//int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
//int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

char grid[SZ][SZ], cur;

queue<pii> q, EQ;
pci res[SZ*SZ];

int isAlpha(char ch)
{
	return (ch>='A' && ch<='Z');
}

void input()
{
	int i, j;
	char ch;
	pii u;
	for(i=1; i<=r; i++)
	{
		for(j=1; j<=c; j++)
		{
			while(scanf("%c", &ch))
			{
				if( isAlpha(ch) )
				{
					grid[i][j] = ch;
					u.first = i;
					u.second = j;
					q.push(u);
					break;
				}
				else if(ch == '.')
				{
					grid[i][j] = '.';
					break;
				}
			}
		}
	}
}

void dfs(pii S)
{
	grid[S.first][S.second] = '.';
	cnt++;
	int i;
	pii v;
	for(i=0; i<4; i++)
	{
		v.first = S.first + dr[i];
		v.second = S.second + dc[i];
		if(v.first<1 || v.second<1 || v.first>r || v.second>c)continue;
		if(grid[v.first][v.second] != '.' && grid[v.first][v.second]==cur)
			dfs(v);
	}
}

bool comp(pci a, pci b)
{
	if(a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

int main()
{
	freopen("10946.txt", "r", stdin);
	pii S;
	int sz, i, cs=1;
	while(scanf("%d%d", &r, &c))
	{
		if(!r && !c)break;
		input();
		sz = 1;
		while( !q.empty() )
		{
			S = q.front();
			q.pop();
			if( grid[S.first][S.second] != '.' )
			{
				cnt = 0;
				cur = grid[S.first][S.second];
				dfs(S);
				res[sz].first = cur;
				res[sz++].second = cnt;
			}
		}
		sort(res+1, res+sz, comp);
		printf("Problem %d:\n", cs++);
		for(i=1; i<sz; i++)
			printf("%c %d\n", res[i].first, res[i].second);
	}
	return 0;
}