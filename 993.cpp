#include<stdio.h>
#include<algorithm>
using namespace std;

int res[1000];

int main(){
	int n, t, T, i, j;
	scanf("%d", &t);
	while( t-- ){
		scanf("%d", &n);
		if( n <= 9){
			printf("%d\n", n);
			continue;
		}
		j = 0;
		res[0] = 1;
		T = n;
		for(i=9; i>=2; i--){
			while( T%i == 0 ){
				res[j++] = i;
				T /= i;
			}
		}
		T = res[0];
		for(i=1; i<j; i++)T *= res[i];
		if( T == n ){
			for( i=j-1; i>=0; i-- )printf("%d", res[i]);
			printf("\n");
		}else{
			puts("-1");
		}
	}
	return 0;
}