#include<stdio.h>
#include<math.h>
#define SZ 10000005

double d[SZ];

void gen(){
	int i;
	for(i=1; i<SZ-4; i++){
		d[i] = d[i-1] + log10(i);
	}
}

int main(){
	int t, N;
	gen();
	scanf("%d", &t);
	while(t--){
		scanf("%d", &N);
		printf("%.0lf\n", floor(d[N])+1);
	}
	return 0;
}