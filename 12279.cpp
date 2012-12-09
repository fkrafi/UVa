#include<stdio.h>

int main(){
	freopen("12279.txt", "r", stdin);
	int nZero, zero, i, n, t, cs=1;
	while(scanf("%d", &n)){
		if( !n )break;
		nZero = zero = 0;
		for(i=0; i<n; i++){
			scanf("%d", &t);
			if( t )nZero++;
			else zero++;
		}
		printf("Case %d: %d\n", cs++, (nZero-zero));
	}
	return 0;
}