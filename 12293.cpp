#include<stdio.h>
typedef long long int lld;

int main(){
	lld n, t;
	while( scanf("%lld", &n) ){
		if( !n )break;
		t = 1;
		while( t<n ){
			t *= 2;
			t++;
		}
		if( t == n )puts("Bob");
		else puts("Alice");
	}
	return 0;
}