#include<stdio.h>

int a[100], b[100];

void perfection(int n){
	int i , sum=0, m=n/2;
	for(i=1; i<=m; i++){
		if(n%i==0)sum += i;
	}
	if(n>sum){
		printf("DEFICIENT\n");
	}else if(n<sum){
		printf("ABUNDANT\n");
	}else if(n == sum){
		printf("PERFECT\n");
	}
}

int main(){
	int i, j, k, max=0, g;
	for(i=0; ; i++){
		scanf("%d", &a[i]);
		if(a[i] == 0)break;
		b[i]=a[i]; g=0;
		while(b[i]){
			b[i] /= 10;
			g++;
		}
		b[i]=g;
	}
	printf("PERFECTION OUTPUT\n");

	for(j=0; j<i; j++){
		for(k=5-b[j]; k>=1; k--)printf(" ");
		printf("%d  ", a[j]);
		perfection(a[j]);
	}
	printf("END OF OUTPUT\n");
	return 0;
}