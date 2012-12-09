#pragma warning(disable : 4786)
#include<stdio.h>
#include<string.h>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pi;
struct store{
	char c;
	int cnt;
};

map<char, int> M;
int H, W, sz;
char s[1000][1000];
char str[10000], ch;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
struct store ans[25];

int isValid(char c)
{
	return (c>='a' && c<='z');
}

void input(int m, int n)
{
	sz = 0;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			while(scanf("%c", &ch))
			{
				if(isValid(ch))
				{
					s[i][j] = ch;
					if(M.find(ch) == M.end())
					{
						M[ch] = sz++;
						ans[M[ch]].c = ch;
					}
					break;
				}
			}
		}
	}
}

bool comp(struct store a, struct store b)
{
	if(a.cnt == b.cnt)
		return a.c<b.c;
	return a.cnt>b.cnt;
}

void setzero()
{
	for(int i=0; i<25; i++)
		ans[i].cnt = 0;
}

void dfs(pi S, char ch)
{
	pi u;
	s[S.first][S.second] = '1';
	for(int i=0; i<4; i++)
	{
		u.first = S.first + dr[i];
		u.second = S.second + dc[i];
		if(u.first<0 || u.second<0 || u.first>=H || u.second>=W)continue;
		if(s[u.first][u.second] != '1' && s[u.first][u.second]==ans[M[ch]].c)
			dfs(u, s[u.first][u.second]);
	}
}


int main()
{
//	freopen("10336.txt", "r", stdin);
	int t, i, j;
	pi S;
	scanf("%d", &t);getchar();
	for(i=1; i<=t; i++)
	{
		scanf("%d%d", &H, &W);getchar();
		input(H, W);
		setzero();
		for(j=0; j<H; j++)
		{
			for(int k=0; k<W; k++)
			{
				if(s[j][k] != '1')
				{
					ans[M[s[j][k]]].cnt++;
					S.first = j;
					S.second = k;
					dfs(S, s[j][k]);
				}
			}
		}
		sort(ans, ans+sz, comp);
		printf("World #%d\n", i);
		for(j=0; j<sz; j++)
			printf("%c: %d\n", ans[j].c, ans[j].cnt);
		M.clear();
	}
	return 0;
}