#include<stdio.h>
#include<queue>
using namespace std;
#define SZ 101
typedef pair<int, int> pi;

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int m, n, cnt;
char s[SZ][SZ];
queue<pi> q, EQ;

void input(int m, int n)
{
	pi u;
	char ch;
	int i, j;
	for(i=1; i<=m; i++)
	{
		for(j=1; j<=n; j++)
		{
			while(scanf("%c", &ch))
			{
				if(ch == '*')
				{
					u.first = i;
					u.second = j;
					q.push(u);
					s[i][j] = ch;
					break;
				}else if(ch=='.')
				{
					s[i][j] = ch;
					break;
				}
			}
		}
	}
}

void dfs(pi S)
{
	s[S.first][S.second] = '.';
	cnt++;
	pi v;
	int i;
	for(i=0; i<8; i++)
	{
		v.first = S.first + dr[i];
		v.second = S.second + dc[i];
		if(v.first<1 || v.second<1 || v.first>m || v.second>n)continue;
		if(s[v.first][v.second] == '.')continue;
		dfs(v);
	}
}

int main()
{
	freopen("11244.txt", "r", stdin);
	pi S;
	int ans;
	while(scanf("%d%d", &m, &n))
	{
		if(!m && !n)break;
		input(m, n);
		ans = 0;
		while(!q.empty())
		{
			S = q.front();
			q.pop();
			if(s[S.first][S.second] == '*'){
				cnt = 0;
				dfs(S);
				if(cnt == 1)ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}