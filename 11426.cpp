#include<stdio.h>
#define SZ 4000015

typedef long long lld;

int N=4000000;
lld R[SZ], pi[SZ];


void solve(){
	int i, j;
	for(i=1; i<=N; i++){
		pi[i] = i;
	}
	for(i=2; i<=N; i++){
		if( pi[i]==i ){
			for(j=i; j<=N; j+=i){
				pi[j] = pi[j]/i*(i-1);
			}
		}
		for(j=1; (j*i)<=N; j++){
			R[j*i] += j*pi[i];
		}
	}
	for(i=1; i<=N; i++){
		R[i] += R[i-1];
	}
}

int main(){
	freopen("11426.txt", "r", stdin);
	solve();
	while( scanf("%d", &N) && N ){
		printf("%lld\n", R[N]);
	}
	return 0;
}