#include<stdio.h>
#include<math.h>

int main(){
	double n, k, p;
	while(scanf("%lf%lf", &n, &p) != EOF){
		k = exp((1/n)*log(p));
		printf("%.0lf\n", k);
	}
	return 0;
}