#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> pi;
#define SZ 26

char s[SZ][SZ];
queue<pi> q;
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n;
void input()
{
	int i, j;
	char ch;
	pi u;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			while(scanf("%c", &ch))
			{
				if(ch == '0'){
					s[i][j] = ch;
					break;
				}else if(ch == '1'){
					u.first = i;
					u.second = j;
					q.push(u);
					s[i][j] = ch;
					break;
				}
			}
		}
	}
}

void dfs(pi u)
{
	s[u.first][u.second] = '0';
	int i;
	pi v;
	for(i=0; i<8; i++)
	{
		v.first = u.first + dr[i];
		v.second = u.second + dc[i];
		if(v.first<0 || v.second<0 || v.first>=n || v.second>=n)continue;
		if(s[v.first][v.second] == '1')
			dfs(v);
	}
}

int main()
{
	freopen("352.txt", "r", stdin);
	int cnt, image=1;
	pi u;
	while(scanf("%d", &n) != EOF)
	{
		input();
		cnt = 0;
		while(!q.empty())
		{
			u = q.front();
			q.pop();
			if(s[u.first][u.second] == '1'){
				cnt++;
				dfs(u);
			}
		}
		printf("Image number %d contains %d war eagles.\n", image++, cnt);
	}
	return 0;
}