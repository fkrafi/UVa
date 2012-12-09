#include<stdio.h>
#define INF 2147483647
#define SZ 20005

int nV, nE;
int d[SZ];

struct EdgePtr{
	int u, v, w;
}edges[SZ];

void init(){
	int i;
	for(i=1; i<nV; i++)
		d[i] = INF;
	d[0] = 0;
}

bool bellman_ford(){
	int i, j, u, v, w;
	for(i=1; i<nV; i++){
		for(j=0; j<nE; j++){
			u = edges[j].u;
			v = edges[j].v;
			w = edges[j].w;
			if( d[v] > d[u]+w ){
				d[v] = d[u] + w;
			}
		}
	}
	for(j=0; j<nE; j++){
		u = edges[j].u;
		v = edges[j].v;
		w = edges[j].w;
		if( d[v] > d[u]+w ){
			return false;
		}
	}
	return true;
}

int main(){
	freopen("Q.txt", "r", stdin);
	int i, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &nV, &nE);
		init();
		for(i=0; i<nE; i++){
			scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
		}
		if( !bellman_ford() )puts("possible");
		else puts("not possible");
	}
	return 0;
}