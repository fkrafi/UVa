#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define SZ 1000005

int nV, nC;
vector<int> edge[SZ];
int seen[SZ], in[SZ];
queue<int> Q, EQ;
vector<int> t;

void topo(){
	int i, u, v, flag = 0;
	for(i=1; i<=nV; i++){
		if( !in[i] ){
			Q.push(i);
			seen[i] = 1;
		}
	}
	while( !Q.empty() ){
		u = Q.front();Q.pop();
		for(i=0; i<edge[u].size(); i++){
			v = edge[u][i];
			in[v]--;
			if( !in[v] && !seen[v] ){
				Q.push(v);
				seen[v] = 1;
			}
		}
		t.push_back(u);
	}
}

void init(int n){
	for(int i=0; i<=n; i++){
		in[i] = 0;
		seen[i] = 0;
		edge[i].clear();
	}
	t.clear();
}

int main(){
	freopen("11686.txt", "r", stdin);
	int i, u, v;
	while( scanf("%d%d", &nV, &nC) ){
		if( !nV && !nC )break;
		init(nV);
		for(i=0; i<nC; i++){
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
			in[v]++;
		}
		topo();
		if( t.size() != nV ){
			puts("IMPOSSIBLE");
		}else{
			for(i=0; i<t.size(); i++){
				printf("%d\n", t[i]);
			}
		}
	}
	return 0;
}