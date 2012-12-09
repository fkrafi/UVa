#pragma warning(disable : 4786)
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
using namespace std;
#define SZ 100005


char u[25], v[25];
int id[SZ], sz[SZ];
map<string, int> Map;

void init(int N) {
	for (int i=0; i<N; i++) {
		id[i] = i;
		sz[i] = 1;
	}
}

int root(int p) {
	while (p != id[p])
		p = id[p];
	return p;
}

int Union(int p, int q) {
	int i = root(p);
	int j = root(q);
	if (i == j){
		return sz[i];
	}
	if (sz[i] < sz[j]) {
		id[i] = j;
		sz[j] += sz[i];
		return sz[j];
	} else {
		id[j] = i;
		sz[i] += sz[j];
		return sz[i];
	}
}

int main(){
	freopen("11503.txt", "r", stdin);
	int T, pos, N;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		init(SZ);
		pos = 0;
		Map.clear();
		while(N--){
			scanf("%s%s", u, v);
			if( Map.find(string(u)) == Map.end() ){
				Map[string(u)] = ++pos;
			}
			if( Map.find(string(v)) == Map.end() ){
				Map[string(v)] = ++pos;
			}
			printf("%d\n", Union(Map[string(u)], Map[string(v)]));
		}
	}
	return 0;
}