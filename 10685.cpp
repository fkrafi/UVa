#pragma warning(disable : 4786)
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
using namespace std;
#define SZ 5005

int C, R;
int id[SZ], cnt[SZ];
char u[SZ], v[SZ];
map<string, int> Map;


void init(int n) {
	for(int i=0; i<=n; i++) {
		id[i] = i;
		cnt[i] = 0;
	}
}

void Union(int p, int q) {
	int pid = id[p];
	int qid = id[q];
	for (int i=1; i<=C; i++) {
		if (id[i] == pid)
			id[i] = qid;
	}
}

int main(){
	freopen("10685.txt", "r", stdin);
	int i, res;
	while( scanf("%d%d", &C, &R) ){
		if( !C && !R )break;
		Map.clear();
		for(i=1; i<=C; i++){
			scanf("%s", u);
			Map[string(u)] = i;
		}
		init(C);
		for(i=0; i<R; i++){
			scanf("%s%s", u, v);
			Union(Map[string(u)], Map[string(v)]);
		}
		res = -1;
		for(i=1; i<=C; i++){
			cnt[id[i]]++;
			if( res < cnt[id[i]] )
				res = cnt[id[i]];
		}
		printf("%d\n", res);
	}
	return 0;
}