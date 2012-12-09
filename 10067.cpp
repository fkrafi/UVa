#pragma warning(disable : 4786)
#include<stdio.h>
#include<queue>
#include<map>
using namespace std;


int S[5], _S, E[5], _E;
map<int, int> Map;
queue<int> Q, EQ;

int seen[10005], cst[10005], vst;

int d[][10] = {
		{0, 0, 0, 1},
		{0, 0, 0, -1},
		{0, 0, 1, 0},
		{0, 0, -1, 0},
		{0, 1, 0, 0},
		{0, -1, 0, 0},
		{1, 0, 0, 0},
		{-1, 0, 0, 0}
	};

int val(int A[]){
	int i, ret=0;
	for(i=0; i<4; i++){
		ret = ret*10 + A[i];
	}
	return ret;
}

void split(int _A, int A[]){
	for(int i=3; i>=0; i--){
		A[i] = _A%10;
		_A /= 10;
	}
}

int bfs(){
	int i, j, u[5], v[5], _u, _v;
	Q = EQ;
	Q.push(_S);
	seen[_S] = vst;
	cst[_S] = 0;
	if( _S==_E && Map[_S]!=5 )return 0;
	if( _S==_E && Map[_S]==5 )return -1;
	while( !Q.empty() ){
		_u = Q.front(); Q.pop();
		split(_u, u);
		for(i=0; i<8; i++){
			for(j=0; j<4; j++){
				v[j] = u[j] + d[i][j];
				if( v[j]>9 )v[j] = 0;
				if( v[j]<0 )v[j] = 9;
			}
			_v = val(v);
			if( Map[_v] )continue;
			if( seen[_v] == vst )continue;
			Q.push(_v);
			seen[_v] = vst;
			cst[_v] = cst[_u] + 1;
			if( _v==_E )
				return cst[_v];
		}
	}
	return -1;
}

int main(){
	freopen("10067.txt", "r", stdin);
	int T, i, N, F[5], _F;
	scanf("%d", &T);
	while( T-- ){
		for(i=0; i<4; i++){
			scanf("%d", &S[i]);
		}
		_S = val(S);
		for(i=0; i<4; i++){
			scanf("%d", &E[i]);
		}
		_E = val(E);
		scanf("%d", &N);
		Map.clear();
		while( N-- ){
			for(i=0; i<4; i++){
				scanf("%d", &F[i]);
			}
			_F = val(F);
			Map[_F] = 5;
		}
		++vst;
		printf("%d\n", bfs());
	}
	return 0;
}