#include<stdio.h>
#include<vector>
using namespace std;
#define SZ 30

int N, M, res;
int seen[SZ][SZ], cs=1;
vector<int> edge[SZ];


int no_path(int n){
	int i, v;
	for(i=0; i<edge[n].size(); i++){
		v = edge[n][i];
		if( seen[n][v]!=cs && seen[v][n]!=cs )return 0;
	}
	return 1;
}

void BtKt(int n, int s){
	if( no_path(n) )return;
	int i, v;
	for(i=0; i<edge[n].size(); i++){
		v = edge[n][i];
		if( seen[n][v] == cs || seen[v][n] == cs)continue;
		seen[n][v] = seen[v][n] = cs;
		if( s+1>res )res = s+1;
		BtKt(v, s+1);
		seen[n][v] = seen[v][n] = 0;
	}
}

void CLEAR(){
	int i;
	for(i=0; i<=N; i++){
		edge[i].clear();
	}
}

int main(){
	freopen("539.txt", "r", stdin);
	int i, u, v;
	while( scanf("%d%d", &N, &M) ){
		if( !N && !M )break;
		CLEAR();
		for(i=0; i<M; i++){
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		res = 0;
		for(i=0; i<N; i++){
			BtKt(i, 0);
			cs++;
		}
		printf("%d\n", res);
	}
	return 0;
}