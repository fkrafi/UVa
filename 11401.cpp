#include<stdio.h>

long long int cnt[1000005];

void cal(){
	long long int i, add=0;
	for(i=4; i<=1000000; i++){
		add += (i-2)/2;
		cnt[i] = cnt[i-1] + add;
	}
}

int main(){
	int n;
	cal();
	while( scanf("%d", &n) ){
		if(n<3)break;
		printf("%lld\n", cnt[n]);
	}
	return 0;
}