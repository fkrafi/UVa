#include<stdio.h>

double mem[15][15][15];

void dp(){
	int N, P, R;
	mem[1][1][1] = 1;
	for(N=2; N<=13; N++){
		for(P=1; P<=N; P++){
			for(R=1; R<=N; R++){
				mem[N][P][R] = mem[N-1][P][R]*(N-2) + mem[N-1][P-1][R] + mem[N-1][P][R-1];
			}
		}
	}
}

int main(){
	int N, P, R, T;
	dp();
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d%d", &N, &P, &R);
		printf("%.0lf\n", mem[N][P][R]);
	}
	return 0;
}