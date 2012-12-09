#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
#define SZ 2005

int nV, nC;
int seen[SZ];
stack<int> S, ES;
vector<int> edge[SZ], rEdge[SZ];

void init(){
	int i;
	S = ES;
	for(i=0; i<=nV; i++){
		seen[i] = 0;
		edge[i].clear();
		rEdge[i].clear();
	}
}

void dfs(int u){
	int i, v;
	seen[u] = 1;
	for(i=0; i<edge[u].size(); i++){
		v = edge[u][i];
		if( seen[v] != 1 )
			dfs(v);
	}
	S.push(u);
}

void scc(int u){
	int i, v;
	seen[u] = 2;
	for(i=0; i<rEdge[u].size(); i++){
		v = rEdge[u][i];
		if( seen[v] != 2 )
			scc(v);
	}
	S.push(u);
}

void input(){
	int i, u, v, P;
	for(i=0; i<nC; i++){
		scanf("%d%d%d", &u, &v, &P);
		edge[u].push_back(v);
		rEdge[v].push_back(u);
		if( P==2 ){
			edge[v].push_back(u);
			rEdge[u].push_back(v);
		}
	}
}

int main(){
	freopen("11838.txt", "r", stdin);
	int i, cnt;
	while( scanf("%d%d", &nV, &nC) ){
		if( !nV && !nC )break;
		init();
		input();
		for(i=1; i<=nV; i++){
			if(seen[i] != 1 )
				dfs(i);
		}
		cnt = 0;
		while( !S.empty() ){
			i = S.top(); S.pop();
			if( seen[i] != 2 ){
				scc(i);
				cnt++;
			}
		}
		printf("%d\n", (cnt==1)?1:0);
	}
	return 0;
}