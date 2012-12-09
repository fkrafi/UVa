#include<stdio.h>

int main(){
	int N, a, res;
	while( scanf("%d", &N) && N ){
		res = 0;
		while(N--){
			scanf("%d", &a);
			res ^= a;
		}
		if( res )puts("Yes");
		else puts("No");
	}
	return 0;
}