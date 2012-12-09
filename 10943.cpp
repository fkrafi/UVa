#include<stdio.h>
#define M 1000000

int N, K;
int mem[105][105];


void CLEAR(int n, int k){
	for(int i=0; i<=n; i++)
		for(int j=0; j<=k; j++)
			mem[i][j] = -1;
}


int dp(int n, int k){
	if( n<0 )return 0;
	if( !k ){
		if( !n )return 1;
		return 0;
	}
	if( mem[n][k] != -1 )return mem[n][k];
	int i, ret=0;
	for(i=0; i<=N; i++){
		ret = (ret%M + dp(n-i, k-1)%M)%M;
	}
	mem[n][k] = ret;
	return ret;
}


int main(){
	while( scanf("%d%d", &N, &K) ){
		if( !N && !K )break;
		CLEAR(N, K);
		printf("%d\n", dp(N, K));
	}
	return 0;
}