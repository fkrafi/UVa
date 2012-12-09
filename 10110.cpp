#include<stdio.h>
#include<math.h>

typedef long long int lld;

int main(){
	lld n, a;
	while( scanf("%lld", &n) ){
		if( !n )break;
		a = int(sqrt(n));
		if( n == a*a )puts("yes");
		else puts("no");
	}
	return 0;
}