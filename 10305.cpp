#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

vector<int> edge[110];
int seen[110], in[110];
queue<int> Q, EQ;

void topo(int n){
	int i, u, v, flag = 0;
	for(i=1; i<=n; i++){
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
		if(!flag){
			printf("%d", u);
			flag = 1;
		}else
			printf(" %d", u);
	}
	printf("\n");
}

void init(int n){
	for(int i=0; i<=n; i++){
		in[i] = 0;
		seen[i] = 0;
		edge[i].clear();
	}
}

int main(){
	freopen("10305.txt", "r", stdin);
	int n, m, i, u, v;
	while(scanf("%d%d", &n, &m)){
		if(!n && !m)break;
		init(n);
		for(i=0; i<m; i++){
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
			in[v]++;
		}
		topo(n);
		Q = EQ;
	}
	return 0;
}