#include<stdio.h>

int a[10000];

int main(){
	int n, i, sum, c=1, move;
	while(scanf("%d", &n)){
		if(n==0)break;
		sum = 0;
		for(i=0; i<n; i++){
			scanf("%d", &a[i]);
			sum += a[i];
		}
		sum /= n;
		move = 0;
		for(i=0; i<n; i++){
			if(sum<a[i]){
				move += (a[i]-sum);
			}
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", c, move);
		c++;
	}
	return 0;
}