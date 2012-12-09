#pragma warning(disable:4786)
#include<stdio.h>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<iostream>
using namespace std;
#define SZ 10000
struct country
{
	string name;
}ctr[SZ];
typedef struct country ctry;

string u, v, s, d;
map<string, int> M;
vector<int> edge[SZ];
queue<int> q, EQ;
int cs;
int seen[SZ], pi[SZ];

void bfs()
{
	int iu, iv, i;
	seen[M[s]] = cs;
	q.push(M[s]);
	pi[M[s]] = -1;
	while(!q.empty())
	{
		iu = q.front();
		for(i=0; i<edge[iu].size(); i++)
		{
			iv = edge[iu][i];
			if(seen[iv] != cs)
			{
				seen[iv] = cs;
				pi[iv] = iu;
				q.push(iv);
			}
			if(iv == M[d])return;
		}
		q.pop();
	}
}

void print_route(int i)
{
	if(pi[i] == -1)
		return;
	else{
		print_route(pi[i]);
		cout << ctr[pi[i]].name << " " << ctr[i].name << "\n";
	}
}

int main()
{
	freopen("762.txt", "r", stdin);
	int n, i, sz;
	cs = 1;
	while(scanf("%d", &n)!=EOF)
	{
		if(cs>1)printf("\n");
		getchar();
		sz = 1;
		for(i=0; i<n; i++)
		{
			cin >> u >> v;
			if(M.find(u) == M.end())
			{
				edge[sz].clear();
				ctr[sz].name = u;
				M[u] = sz++;
			}
			if(M.find(v) == M.end())
			{
				edge[sz].clear();
				ctr[sz].name = v;
				M[v] = sz++;
			}
			edge[M[u]].push_back(M[v]);
			edge[M[v]].push_back(M[u]);
		}
		cin >> s >> d;
		pi[M[s]] = pi[M[d]] = -1;
		bfs();
		if(pi[M[d]] == -1)
			printf("No route\n");
		else
			print_route(M[d]);
		q = EQ;
		cs++;
		M.clear();
	}
	return 0;
}