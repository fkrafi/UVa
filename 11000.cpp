#include<stdio.h>
#define SZ 105
typedef long long int lld;

lld F[SZ];
lld M[SZ], T[SZ];

int main(){
	int i;
	F[0] = F[1] = 1;
	M[0] = 0; T[0] = 1;
	M[1] = 1; T[1] = 2;
	for(i=2; i<SZ; i++){
		F[i] = F[i-1] + F[i-2];
		M[i] = T[i-1];
		T[i] = M[i] + F[i];
	}
	int N;
	while( scanf("%d", &N) ){
		if( N<0 )break;
		printf("%lld %lld\n", M[N], T[N]);
	}
	return 0;
}