#include<stdio.h>
typedef long long int lld;


lld fib[100];


void gen(){
	fib[1] = 1;
	fib[2] = 2;
	for(int i=3; i<=80; i++)
		fib[i] = fib[i-1] + fib[i-2];
}

int main(){
	gen();
	int n;
	while( scanf("%d", &n) ){
		if( !n )break;
		printf("%lld\n", fib[n]);
	}
	return 0;
}
