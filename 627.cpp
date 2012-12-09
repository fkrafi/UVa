#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define SZ 305

int seen[SZ], cs, nV, pi[SZ];
vector<int> edge[SZ];
char s[1000];
queue<int> q, EQ;

int isNum(char ch)
{
	return (ch>='0' && ch<='9');
}

void separate(char s[])
{
	int i, len=strlen(s), n, flag=1, nd;
	for(i=0; i<len; i++)
	{
		if( isNum(s[i]) )
		{
			n = 0;
			while(i<len && isNum(s[i]))
			{
				n = n*10 + s[i]-48;
				i++;
			}
			if(flag)
			{
				nd = n;
				flag = 0;
			}
			else
				edge[nd].push_back(n);
		}
	}
}

void set()
{
	int i;
	for(i=1; i<=nV; i++)
		pi[i] = 0;
}

void bfs(int S, int T)
{
	seen[S] = cs;
	pi[S] = -1;
	q.push(S);
	int u, v, i, len;
	while(!q.empty())
	{
		u = q.front();
		len = edge[u].size();
		for(i=0; i<len; i++)
		{
			v = edge[u][i];
			if(seen[v] != cs)
			{
				seen[v] = cs;
				pi[v] = u;
				q.push(v);
				if(v==T)return;
			}
		}
		q.pop();
	}
}

void print_path(int i)
{
	if(pi[i] == -1)
		printf("%d", i);
	else{
		print_path(pi[i]);
		printf(" %d", i);
	}
}

int main()
{
	freopen("627.txt", "r", stdin);
	int i, t, u, v;
	cs = 1;
	while(scanf("%d", &nV) != EOF)
	{
		getchar();
		for(i=1; i<=nV; i++)
		{
			edge[i].clear();
			gets(s);
			separate(s);
		}
		scanf("%d", &t);
		printf("-----\n");
		while(t--)
		{
			scanf("%d%d", &u, &v);
			set();
			bfs(u, v);
			if(pi[v])
				print_path(v);
			else
				printf("connection impossible");
			printf("\n");
			cs++;
			q = EQ;
		}
	}
	return 0;
}