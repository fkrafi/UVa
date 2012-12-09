#include<stdio.h>
typedef long long int lld;

lld solve(lld n){
	if( n<2 )return 0;
	lld res=0, temp = 1;
	while(temp<n){
		res++;
		temp *= 2;
	}
	return res;
}

int main(){
	lld cs, T, n;
	scanf("%lld", &T);
	for(cs=1; cs<=T; cs++){
		scanf("%lld", &n);
		printf("Case %lld: %lld\n", cs, solve(n+1));
	}
	return 0;
}