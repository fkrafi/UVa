#include<stdio.h>
#include<math.h>
#define SZ 105
#define INF 2147483647

int nV, nC, wght[SZ][SZ];

int min(int a, int b){
	return (a<b)?a:b;
}

int max(int a, int b){
	return (a>b)?a:b;
}

void init(){
	int i, j;
	for(i=1; i<=nV; i++)
		for(j=1; j<=nV; j++)
			wght[i][j] = -INF;
}

void floyd_warshall(){
	int i, j, k;
	for(k=1; k<=nV; k++)
		for(i=1; i<=nV; i++)
			for(j=1; j<=nV; j++)
				wght[i][j] = max(wght[i][j], min(wght[i][k], wght[k][j]));
}

int main(){
	freopen("10099.txt", "r", stdin);
	int u, v, w, i, cs=1;
	double res;
	while( scanf("%d%d", &nV, &nC) ){
		if( !nV && !nC )break;
		init();
		for(i=0; i<nC; i++){
			scanf("%d%d%d", &u, &v, &w);
			wght[u][v] = wght[v][u] = w;
		}
		floyd_warshall();
		scanf("%d%d%d", &u, &v, &w);
		res = ceil(double(w)/double(wght[u][v]-1));
		printf("Scenario #%d\nMinimum Number of Trips = %.0lf\n\n", cs++, res);
	}
	return 0;
}