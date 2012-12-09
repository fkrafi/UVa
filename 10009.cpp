#pragma warning(disable : 4786)
#include<stdio.h>
#include<vector>
#include<map>
#include<queue>
#include<string>
using namespace std;
#define SZ 256

char u[SZ], v[SZ], s[SZ], e[SZ], pi[SZ];
vector<char> edge[SZ];
int seen[SZ], d;
map<string, char> M;
queue<char> Q, EQ;
string U, V;

void bfs(char S, char E)
{
	int i;
	seen[S] = d;
	pi[S] = '0';
	Q.push(S);
	while(!Q.empty())
	{
		u[0] = Q.front();
		for(i=0; i<edge[u[0]].size(); i++)
		{
			v[0] = edge[u[0]][i];
			if(seen[v[0]] == d)continue;
			Q.push(v[0]);
			seen[v[0]] = d;
			pi[v[0]] = u[0];
			if(v[0] == E)return;
		}
		Q.pop();
	}
}

void out(char ch)
{
	if(ch == '0')return;
	out(pi[ch]);
	printf("%c", ch);
}

int main()
{
//	freopen("10009.txt", "r", stdin);
	int t, c, q, i;
	d = 1;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &c, &q);getchar();
		for(i=0; i<c; i++)
		{
			scanf("%s%s", u, v);
			U = string(u);
			V = string(v);
			if(M.find(U) == M.end()){
				M[U] = u[0];
				edge[M[U]].clear();
			}
			if(M.find(V) == M.end()){
				M[V] = v[0];
				edge[M[V]].clear();
			}
			edge[M[U]].push_back(M[V]);
			edge[M[V]].push_back(M[U]);
		}
		for(i=0; i<q; i++)
		{
			scanf("%s%s", u, v);
			bfs(u[0], v[0]);
			out(v[0]);
			Q = EQ;
			d++;
			printf("\n");
		}
		M.clear();
		if(t)printf("\n");
	}
	return 0;
}