#include<stdio.h>

double a[1000];

int main(){
	int c, i, j;
	double sum, avg, r, n, count;
	char d='%';
	scanf("%d", &c);
	for(i=0; i<c; i++){
		sum = 0; count = 0;
		scanf("%lf", &n);
		for(j=0; j<n; j++){
			scanf("%lf", &a[j]);
			sum += a[j];
		}
		avg = sum/n;
		for(j=0; j<n; j++){
			if(a[j]>avg)count++;
		}
		r = (count/n)*100;
		printf("%.3lf%c\n", r, d);
	}
	return 0;
}