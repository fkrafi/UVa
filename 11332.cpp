#include<stdio.h>

int main(){
	int n, sum, t;
	while(scanf("%d", &n)){
		if(n==0)break;
		while(n/10){
			t = n;
			sum = 0;
			while(t){
				sum += t%10;
				t /= 10;
			}
			n = sum;
		}
		printf("%d\n", n);
	}
	return 0;
}