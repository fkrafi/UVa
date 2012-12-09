#pragma warning(disable : 4786)
#include<stdio.h>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
using namespace std;
#define SZ 35

int nV, nC, nQ;
queue<int> Q, EQ;
map<string, int> M;
vector<int> edges[SZ];
int seen[SZ], dis[SZ], vst=1;


void input(){
	int i;
	char u[5], v[5];
	scanf("%d%d%d", &nV, &nC, &nQ);
	for(i=1; i<=nV; i++){
		edges[i].clear();
		scanf("%s", u);
		M[string(u)] = i;
	}
	for(i=1; i<=nC; i++){
		scanf("%s%s", u, v);
		edges[ M[string(u)] ].push_back( M[string(v)] );
		edges[ M[string(v)] ].push_back( M[string(u)] );
	}
}


int bfs(int S, int E){
	int u, v, i;
	Q.push(S);
	dis[S] = 0;
	seen[S] = vst;
	while( !Q.empty() ){
		u = Q.front(); Q.pop();
		for(i=0; i<edges[u].size(); i++){
			v = edges[u][i];
			if( seen[v] != vst ){
				Q.push(v);
				seen[v] = vst;
				dis[v] = dis[u] + 1;
			}
			if( v==E )return dis[v];
		}
	}
	return -1;
}


int main(){
	freopen("383.txt", "r", stdin);
	int cs, t, p, i, res;
	char u[5], v[5];
	scanf("%d", &t);
	printf("SHIPPING ROUTES OUTPUT\n\n");

	for(cs=1; cs<=t; cs++){
		input();
		printf("DATA SET  %d\n\n", cs);
		for(i=0; i<nQ; i++){
			scanf("%d%s%s", &p, u, v);
			res = bfs( M[string(u)], M[string(v)] );
			if( res<0 )
				puts("NO SHIPMENT POSSIBLE");
			else{
				printf("$%d\n", res*100*p);
			}
			vst++;
			Q = EQ;
		}
		printf("\n");
	}

	printf("END OF OUTPUT\n");
	return 0;
}