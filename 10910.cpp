#include<stdio.h>

int H, P;
int mem[75][75];

void CLEAR(int N, int T){
	int i, j;
	for(i=0; i<=N; i++)
		for(j=0; j<=T; j++)
			mem[i][j] = -1;
}

int dp( int N, int T ){
	if( T < 0 )return 0;
	if( !N ){
		if( !T )return 1;
		return 0;
	}
	if( mem[N][T] != -1 )return mem[N][T];
	int i, ret=0;
	for( i=P; i<=H; i++ ){
		ret += dp(N-1, T-i);
	}
	mem[N][T] = ret;
	return ret;
}

int main(){
	int N, T, t;
	scanf("%d", &t);
	while( t-- ){
		scanf("%d%d%d", &N, &T, &P);
		CLEAR(N, T);
		H = P + (T- (N*P) ) + 5;
		printf("%d\n", dp(N, T));
	}
	return 0;
}