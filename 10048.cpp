#include<stdio.h>
#include<algorithm>
using namespace std;
#define SZ 105
#define INF 2147483647

int wght[SZ][SZ];
int nV, nC, Q, cs=1;

int max(int a, int b)
{
	return (a>b)?a:b;
}

int min(int a, int b)
{
	return (a<b)?a:b;
}

void floyd()
{
	int i, j, k;
	for(k=1; k<=nV; k++)
		for(i=1; i<=nV; i++)
			for(j=1; j<=nV; j++)
				wght[i][j] = min(wght[i][j], max(wght[i][k], wght[k][j]));
}

int main()
{
	freopen("audio.txt", "r", stdin);
	int i, j, u, v, cost;
	while( scanf("%d%d%d", &nV, &nC, &Q) )
	{
		if( !nV && !nC && !Q )break;
		if(cs>1)printf("\n");
		for(i=1; i<=nV; i++)
			for(j=1; j<=nV; j++)
				wght[i][j] = INF;

		for(i=0; i<nC; i++)
		{
			scanf("%d%d%d", &u, &v, &cost);
			wght[u][v] = wght[v][u] = cost;
		}

		floyd();
		
		printf("Case #%d\n", cs++);
		
		for(i=0; i<Q; i++)
		{
			scanf("%d%d", &u, &v);
			if(wght[u][v] == INF)
				printf("no path\n");
			else
				printf("%d\n", wght[u][v]);
		}
	}
	return 0;
}