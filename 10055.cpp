#include<stdio.h>

int main(){
	double h, w, d;
	while(scanf("%lf%lf", &h, &w)== 2){
		d = (w>h)?(w-h):(h-w);
		printf("%.0lf\n", d);
	}
	return 0;
}
