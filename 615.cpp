#pragma warning(disable : 4786)
#include<stdio.h>
#include<string.h>
#include<map>
#include<queue>
using namespace std;
#define SZ 100

int pos, cs=1, root;
int seen[SZ];
map<int, int> M;
int parent[SZ];
queue<int> q, EQ;
vector<int> edge[SZ];


void init(){
	M.clear();
	q = EQ;
	for(int i=0; i<pos; i++){
		edge[i].clear();
		parent[i] = 0;
	}
}

int input(){
	int ret=1, u, v;
	pos = 1;
	while(scanf("%d%d", &u, &v)){
		if( u<0 && v<0 )return -1;
		if( !u && !v)break;
		if( M.find(u) == M.end() )
			M[u] = pos++;
		if( M.find(v) == M.end() )
			M[v] = pos++;
		if( parent[M[v]] != 0 )ret=0;
		parent[M[v]] = M[u];
		edge[M[u]].push_back(M[v]);
	}
	return ret;
}

int chk_root(){
	int i, cnt=0;
	for(i=1; i<pos; i++){
		if(parent[i]==0){
			cnt++;
			root = i;
		}
	}
	return cnt==1;
}

int travel(){
	int u, v, i;
	q.push(root);
	seen[root] = cs;
	while( !q.empty() ){
		u = q.front(); q.pop();
		for(i=0; i<edge[u].size(); i++){
			v = edge[u][i];
			if( seen[v] != cs ){
				seen[v] = cs;
				q.push(v);
			}
		}
	}
	for(i=1; i<pos; i++)
		if( seen[i] != cs )return 0;
	return 1;
}


int main(){
	freopen("615.txt", "r", stdin);
	int con;
	while(1){
		con = input();
		if( con < 0 )break;
		if( pos==1 ){
			printf("Case %d is a tree.\n", cs++);
		}else if( con==0 ){
			printf("Case %d is not a tree.\n", cs++);
		}else if( !chk_root() ){
			printf("Case %d is not a tree.\n", cs++);
		}else if( !travel() ){
			printf("Case %d is not a tree.\n", cs++);
		}else{
			printf("Case %d is a tree.\n", cs++);
		}
		init();
	}
	return 0;
}