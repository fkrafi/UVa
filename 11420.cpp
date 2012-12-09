#include<stdio.h>

typedef long long int lli;

lli mem[70][70][5];

void CLEAR(int n, int s){
	for(int i=0; i<=n; i++)
		for(int j=0; j<=s; j++)
			for(int k=0; k<2; k++)
				mem[i][j][k] = -1;
}


lli dp( int n, int s, int l ){
	if( !n ){
		if( !s )return 1;
		return 0;
	}
	if( mem[n][s][l] != -1 )return mem[n][s][l];
	int i;
	lli ret = 0;
	for(i=0; i<2; i++){
		if( l==1 && i==1 ){
			ret += dp(n-1, s-1, i);
		}else{
			ret += dp(n-1, s, i);
		}
	}
	mem[n][s][l] = ret;
	return ret;
}


int main(){
	int n, s;
	while( scanf("%d%d", &n, &s) ){
		if( n<0 || s<0 )break;
		CLEAR(n, s);
		printf("%lld\n", dp(n, s, 1));
	}
	return 0;
}