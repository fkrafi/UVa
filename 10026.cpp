#include<stdio.h>
#include<algorithm>
using namespace std;


struct works{
	double T, S;
	int pos;
}w[1005];


bool comp(works a, works b){
	if( a.S/a.T == b.S/b.T )
		return a.pos<b.pos;
	return a.S/a.T > b.S/b.T;
}

int main(){
	freopen("10026.txt", "r", stdin);
	int i, t, N;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &N);
		for(i=0; i<N; i++){
			scanf("%lf%lf", &w[i].T, &w[i].S);
			w[i].pos = i+1;
		}
		sort(w, w+N, comp);
		for(i=0; i<N; i++){
			if( !i )printf("%d", w[i].pos);
			else printf(" %d", w[i].pos);
		}
		printf("\n");
		if( t )printf("\n");
	}
	return 0;
}