#include<stdio.h>

int main(){
	int i, j, a, b, n, k, c, max;
	while(scanf("%d%d", &i, &j)!=EOF){
		if(i<j){
			a=i; b=j;
		}else{
			a=j; b=i;
		}
		max=0;
		for(k=a; k<=b; k++){
			n=k;
			c=1;
			while(n!=1){
				if(n%2){
					n=3*n+1;
				}else{
					n=n/2;
				}
				c++;
			}
			if(max<c)max=c;
		}
		printf("%d %d %d\n", i, j, max);
	}
	return 0;
}