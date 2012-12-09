#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define SZ 105


int nV;
int seen[SZ], cs=1;
queue<int> Q;
vector<int> res;
vector<int> edge[SZ];

void bfs(int S){
	int i;
	int u, v;
	Q.push(S);
	while( !Q.empty() ){
		u = Q.front(); Q.pop();
		for(i=0; i<edge[u].size(); i++){
			v = edge[u][i];
			if( seen[v] != cs ){
				Q.push(v);
				seen[v] = cs;
			}
		}
	}
}

void output(){
	int i, cnt=0;
	res.clear();
	for(i=1; i<=nV; i++){
		if( seen[i] != cs ){
			res.push_back(i);
			cnt++;
		}
	}
	printf("%d", cnt);
	for(i=0; i<res.size(); i++)
		printf(" %d", res[i]);
	printf("\n");
}

void init(){
	int i;
	for(i=0; i<=nV; i++)
		edge[i].clear();
}

void input(){
	int u, v;
	init();
	while( scanf("%d", &u) ){
		if( !u )break;
		while( scanf("%d", &v) ){
			if( !v )break;
			edge[u].push_back(v);
		}
	}
	scanf("%d", &u);
	while(u--){
		scanf("%d", &v);
		bfs(v);
		output();
		cs++;
	}
}

int main(){
	freopen("280.txt", "r", stdin);
	while( scanf("%d", &nV) ){
		if( !nV )break;
		input();
	}
	return 0;
}