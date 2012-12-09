#pragma warning(disable : 4786)
#include<stdio.h>
#include<string>
#include<iostream>
#include<map>
using namespace std;
#define SZ 1000
#define INF 2147483647

string s1, s2;
int nV, nC, wght[SZ][SZ];
map<string, int> M;

int min(int a, int b)
{
	return (a<b)?a:b;
}

int max(int a, int b)
{
	return (a>b)?a:b;
}

void init()
{
	int i, j;
	for(i=1; i<=nV; i++)
		for(j=1; j<=nV; j++)
			wght[i][j] = -INF;
}

void floyd_warshall()
{
	int i, j, k;
	for(k=1; k<=nV; k++)
		for(i=1; i<=nV; i++)
			for(j=1; j<=nV; j++)
				wght[i][j] = max(wght[i][j], min(wght[i][k], wght[k][j]));
}

int main()
{
	freopen("544.txt", "r", stdin);
	int i, cst, cs=1, cnt;
	char u[35], v[35];
	while(scanf("%d%d", &nV, &nC))
	{
		if( !nV && !nC)break;
		init();
		cnt = 1;
		for(i=0; i<nC; i++)
		{
			scanf("%s%s%d", u, v, &cst);
			s1 = string(u);
			s2 = string(v);
			if(M.find(s1) == M.end())
				M[s1] = cnt++;
			if(M.find(s2) == M.end())
				M[s2] = cnt++;
			wght[M[s1]][M[s2]] = wght[M[s2]][M[s1]] = cst;
		}
		scanf("%s%s", u, v);
		floyd_warshall();
		s1 = string(u);
		s2 = string(v);
		printf("Scenario #%d\n%d tons\n\n", cs++, wght[M[s1]][M[s2]]);
		M.clear();
	}
	return 0;
}