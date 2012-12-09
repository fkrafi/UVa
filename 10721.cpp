#include<stdio.h>
#include<string.h>
typedef long long int lli;


lli n, k, m;
lli mem[55][55][55][5];

lli dp(lli N, lli K, lli M, lli L){
	if( K<0 )return 0;
	if( M>m )return 0;
	if( !N ){
		if( !K )return 1;
		return 0;
	}
	if( mem[N][K][M][L] != -1 )return mem[N][K][M][L];
	lli ret = 0, i;
	for(i=0; i<=1; i++){
		if( L==i ){
			ret += dp(N-1, K, M+1, i);
		}else{
			ret += dp(N-1, K-1, 1, i);
		}
	}
	return mem[N][K][M][L] = ret;
}



int main(){
	freopen("10721.txt", "r", stdin);
	while( scanf("%lld%lld%lld", &n, &k, &m) != EOF ){
		memset(mem, -1, sizeof(mem));
		printf("%lld\n", dp(n-1, k-1, 1, 1));
	}
	return 0;
}