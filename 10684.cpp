#include<stdio.h>
#define SZ 10005

int N;
int arr[SZ], res[SZ];


int dp(){
	int sum=0, i, ret=0;
	for(i=1; i<=N; i++){
		scanf("%d", &arr[i]);
		sum += arr[i];
		if( sum<0 )
			sum = 0;
		res[i] = sum;
	}
	for(i=1; i<=N; i++)
		if(res[i]>ret)
			ret = res[i];
	return ret;
}

int main(){
	int a;
	while( scanf("%d", &N) ){
		if( !N )break;
		a = dp();
		if( a>0 )
			printf("The maximum winning streak is %d.\n", a);
		else
			puts("Losing streak.");
	}
	return 0;
}
