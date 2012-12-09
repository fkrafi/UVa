#include<stdio.h>

int main(){
	int i, j, n;
	while(scanf("%d", &n)){
		if(!n)break;
		if(n<=3 || n%2){
			printf("Impossible\n");
			continue;
		}
		printf("%d\n", 3*n/2);
		for(i=1; i<n; i++){
			printf("%d %d\n", i, i+1);
		}
		printf("%d 1\n", n);
		for(i=1, j=n/2+1; j<=n; i++, j++){
			printf("%d %d\n", i, j);
		}
	}
	return 0;
}