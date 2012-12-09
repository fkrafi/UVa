#pragma warning(disable : 4786)
#include<stdio.h>
#include<vector>
#include<stack>
#include<string.h>
#include<string>
#include<map>
#include<iostream>
using namespace std;
#define SZ 105


int nV, nC;
int cs=1, Map;
int nCluster;
int seen[SZ], vst;
stack<int> S, ES;
vector<int> edge[SZ], rEdge[SZ];
vector<int> clusters[SZ];
map<string, int> M;
map<int, string> rM;

void init(){
	int i;
	vst++;
	S = ES;
	M.clear();
	rM.clear();
	nCluster = Map = 0;
	for(i=0; i<SZ; i++){
		edge[i].clear();
		rEdge[i].clear();
		clusters[i].clear();
	}
}

void dfs(int u){
	int i, v;
	seen[u] = vst;
	for(i=0; i<edge[u].size(); i++){
		v = edge[u][i];
		if( seen[v] != vst )
			dfs(v);
	}
	S.push(u);
}

void scc(int u, int flag){
	int i, v;
	seen[u] = vst;
	if( flag ){
		cout << rM[u];
	}else{
		cout << ", " << rM[u];
	}
	clusters[nCluster].push_back(u);
	for(i=0; i<rEdge[u].size(); i++){
		v = rEdge[u][i];
		if( seen[v] != vst )
			scc(v, 0);
	}
}

void input_graph(){
	int i;
	char u[SZ], v[SZ];
	for(i=0; i<nC; i++){
		scanf("%s%s", u, v);
		if( M.find(string(u)) == M.end() ){
			M[string(u)] = ++Map;
			rM[Map] = string(u);
		}
		if( M.find(string(v)) == M.end() ){
			M[string(v)] = ++Map;
			rM[Map] = string(v);
		}
		edge[M[string(u)]].push_back(M[string(v)]);
		rEdge[M[string(v)]].push_back(M[string(u)]);
	}
}


int main(){
	freopen("247.txt", "r", stdin);
	int i, flag=0;
	while( scanf("%d%d", &nV, &nC) ){
		if( !nV && !nC )break;
		if( flag )printf("\n"); flag=1;
		init();
		input_graph();
		for(i=1; i<=nV; i++){
			if( seen[i] != vst )
				dfs(i);
		}
		vst++;
		printf("Calling circles for data set %d:\n", cs++);
		while( !S.empty() ){
			i = S.top(); S.pop();
			if( seen[i] != vst ){
				scc(i, 1);
				cout << endl;
			}
		}
	}
	return 0;
}