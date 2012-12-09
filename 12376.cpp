#include<stdio.h>
#include<vector>
using namespace std;
#define SZ 105

int res, endAt;
int nV, nE;
int cst[SZ];
vector<int> edge[SZ];


void CLEAR(){
	int i;
	res = -1;
	for(i=0; i<nV; i++)
		edge[i].clear();
}


void input(){
	int i, u, v;
	scanf("%d%d", &nV, &nE);
	for(i=0; i<nV; i++)scanf("%d", &cst[i]);
	for(i=0; i<nE; i++){
		scanf("%d%d", &u, &v);
		edge[u].push_back(v);
	}
}


void BtKt(int n, int curMax){
	if( edge[n].size() == 0 ){
		if( curMax > res ){
			res = curMax;
			endAt = n;
		}
		return;
	}
	int i, m=-1, u, tn;
	for(i=0; i<edge[n].size(); i++){
		u = edge[n][i];
		if( cst[u] > m ){
			tn = u;
			m = cst[u];
		}
	}
	BtKt(tn, curMax+m);
}


int main(){
	freopen("12376.txt", "r", stdin);
	int t, cs;
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++){
		CLEAR();
		input();
		BtKt(0, 0);
		printf("Case %d: %d %d\n", cs, res, endAt);
	}
	return 0;
}