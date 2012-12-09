#include<stdio.h>
#include<math.h>

int main(){
	double area, r, n, pi=acos(-1.0);
	while(scanf("%lf%lf", &r, &n) != EOF){
		area = (n*r*r*(sin(2.0*pi/n)))/2;
		printf("%.3lf\n", area);
	}
	return 0;
}