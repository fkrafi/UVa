#include<stdio.h>

void happy(int n, int s){
	int sum=0, a, t, i=0, j, k=1, h[100];
	t = n;
	while(sum!=1){
		sum = 0;
		while(t){
			a = t%10;
			sum += (a*a);
			t = t/10;
		}
		for(j=0; j<i; j++){
			if(h[j] == sum){
				sum = 1;
				k = 0;
				break;
			}
		}
		if(sum==1)break;
		h[i++] = sum;
		t = sum;
	}
	if(k==1){
		printf("Case #%d: %d is a Happy number.\n", s, n);
	}else{
		printf("Case #%d: %d is an Unhappy number.\n", s, n);
	}
}

int main(){
	int t, i, n;
	scanf("%d", &t);
	for(i=1; i<=t; i++){
		scanf("%d", &n);
		happy(n, i);
	}
	return 0;
}