#pragma warning(disable : 4786)
#include<stdio.h>
#include<map>
using namespace std;
#define SZ 1000000

int cs=1;
int has[SZ];
map<int, int> Map;

int main(){
	freopen("11849.txt", "r", stdin);
	int M, N, i, a, cnt, pos;
	while( scanf("%d%d", &M, &N) ){
		if( !M && !N )break;
		pos = 1;
		Map.clear();
		for(i=0; i<M; i++){
			scanf("%d", &a);
			has[pos] = cs;
			Map[a] = pos;
		}
		cnt = 0;
		for(i=0; i<N; i++){
			scanf("%d", &a);
			if( has[Map[a]] == cs )
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}