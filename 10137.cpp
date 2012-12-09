#include<stdio.h>
#define SZ 10005

double a[SZ];

double MIN(double a, double b){
	return (a<b)?a:b;
}

double convert(double n){
	char str[105];
	sprintf(str,"%.2lf", n);
	sscanf(str,"%lf",&n);
	return n;
}

int main(){
	int N, i;
	double sum, res, nRes;
	while( scanf("%d", &N) ){
		if( !N )break;
		sum = res = nRes = 0;
		for(i=0; i<N; i++){
			scanf("%lf", &a[i]);
			sum += a[i];
		}
		sum = convert(sum/N);
		for(i=0; i<N; i++){
			if( a[i]>sum ){
				res += a[i]-sum;
			}else{
				nRes += sum-a[i];
			}
		}
		printf("$%.2lf\n", MIN(res, nRes));
	}
	return 0;
}