#include<stdio.h>
#include<math.h>

int prime(int n){
	int i, c=1, j=int(sqrt(n));
	for(i=2; i<=j; i++){
		if(n%i==0){
			c = 0;
			break;
		}
	}
	return c;
}

int main(){
	int n, i, j;

	while(scanf("%d", &n)){
		if(n==0)break;
		if(n%2){
			for(i=3, j=n-2; ; i+=2, j-=2){
				if(prime(i)+prime(j)==2){
					if(n == i+j){
						printf("%d = %d + %d\n", n, i, j);
						break;
					}
				}
			}
		}else{
			for(i=3, j=n-3; ; i+=2, j-=2){
				if(prime(i)+prime(j)==2){
					if(n == i+j){
						printf("%d = %d + %d\n", n, i, j);
						break;
					}
				}
			}
		}
	}
	return 0;
}