#include<stdio.h>
#define MAX(a, b) ((a)>(b))?(a):(b)

int x[100005];
int res[250];

int main(){
	freopen("12571.txt", "r", stdin);
	int T, N, Q, i, a;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d", &N, &Q);
		for(i=0; i<N; i++){
			scanf("%d", &x[i]);
		}
		for(a=0, res[a]=0; a<230; a++){
			for(i=0; i<N; i++){
				res[a] = MAX(res[a], a&x[i]);
			}
		}
		while( Q-- ){
			scanf("%d", &a);
			printf("%d\n", res[a]);
		}
	}
	return 0;
}