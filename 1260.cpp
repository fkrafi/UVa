#include<stdio.h>

int a[1005];

int main(){
	int n, i, t, j;
	long long int sum;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		sum = 0;
		for(i=0; i<n; i++){
			scanf("%d", &a[i]);
			for(j=0; j<i; j++){
				if( a[j]<=a[i] )sum++;
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}
