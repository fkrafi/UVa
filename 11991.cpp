#pragma warning(disable : 4786)
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;

map<int, int> M;
vector<int> occ[100005];


void CLEAR(int n){
	M.clear();
	int i;
	for(i=0; i<=n; i++)occ[i].clear();
}

int main(){
	freopen("11991.txt", "r", stdin);
	int n, m, pos, i, k, v;
	while(scanf("%d%d", &n, &m) != EOF){
		pos = 0;
		for(i=1; i<=n; i++){
			scanf("%d", &v);
			if( M.find(v) == M.end() )
				M[v] = pos++;
			occ[M[v]].push_back(i);
		}
		for(i=0; i<m; i++){
			scanf("%d%d", &k, &v);
			if( occ[M[v]].size() < k )
				printf("0\n");
			else
				printf("%d\n", occ[M[v]][k-1]);
		}
		CLEAR(n);
	}
	return 0;
}