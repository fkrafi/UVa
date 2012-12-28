#include<stdio.h>

int main(){
	int T, x, y, z, A;
	scanf("%d", &T);
	while( T-- ){
		scanf("%d%d%d", &x, &y, &z);
		A = z*(2*x-y)/(x+y);
		printf("%d\n", A);
	}
	return 0;
}