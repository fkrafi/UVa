#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

typedef pair<int, int> pi;

char s[105][105], ch;
queue<pi> q;
int m, n;
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, 1, -1, -1, 0, 1};


void input(int m, int n)
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			while(scanf("%c", &ch))
			{
				if(ch == '@'){
					s[i][j] = ch;
					pi u;
					u.first = i;
					u.second = j;
					q.push(u);
					break;
				}else if(ch == '*'){
					s[i][j] = ch;
					break;
				}
			}
		}
	}
}

void dfs(pi S)
{
	pi v;
	s[S.first][S.second] = '1';
	for(int i=0; i<8; i++)
	{
		v.first = S.first + dr[i];
		v.second = S.second + dc[i];
		if(v.first<0 || v.second<0 || v.first>=m || v.second>=n)continue;
		if(s[v.first][v.second] == '@')
			dfs(v);
	}
}

int main()
{
//	freopen("572.txt", "r", stdin);
	while(scanf("%d%d", &m, &n))
	{
		if(!m && !n)break;
		input(m, n);
		int cnt = 0;
		while(!q.empty())
		{
			pi u = q.front();
			if(s[u.first][u.second] == '@')
			{
				dfs(u);
				cnt++;
			}
			q.pop();
		}
		printf("%d\n", cnt);
	}
	return 0;
}