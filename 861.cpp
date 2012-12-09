#include<stdio.h>

int N, K, cnt;
int grid[10][10];
int res[100][100];

int isPlace(int r, int c){
	int tr=r, tc=c;
	for(tr=r-1, tc=c-1; (tr>=1 && tc>=1); tr--, tc--){
		if( tc<=0 || tr<=0 )break;
		if( grid[tr][tc] )return 0;
	}
	for(tr=r-1, tc=c+1; (tr>=1 && tc<=N); tr--, tc++){
		if( tc>N || tr<=0 )break;
		if( grid[tr][tc] )return 0;
	}
	return 1;
}


void BtKt(int r, int c, int k){
	if( !k ){
		cnt++;
		return;
	}
	if( c>N ){
		c = 1;
		r++;
	}
	if( r>N )return;
	if( isPlace(r, c) ){
		grid[r][c] = 1;
		BtKt(r, c+1, k-1);
	}
	grid[r][c] = 0;
	BtKt(r, c+1, k);
}

void init(){
	for(N=1; N<=8; N++)
		for(K=1; K<=8; K++)
			res[N][K] = -1;
}

int main(){
	N = 8;
	K = 0;
	BtKt(0, 0, K);
	printf("%d\n", cnt);
	return 0;
}