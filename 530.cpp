#include<stdio.h>

int main(){
	int n, r, i;
	double res1, res2;
	while( scanf("%d%d", &n, &r) ){
		if( !n && !r )break;
		i = n - r + 1;
		if( r+1 > i ){
			i = r+1;
			r = n-r;
		}
		res1 = res2 = 1;
		for(; i<=n; i++)res1 *= i;
		for(i=1; i<=r; i++)res2 *= i;
		printf("%.0lf\n", res1/res2);
	}
	return 0;
}