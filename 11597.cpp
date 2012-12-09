#include<stdio.h>

int main(){
	int n, cs=1;
	while( scanf("%d", &n) && n ){
		printf("Case %d: %d\n", cs++, n/2);
	}
	return 0;
}