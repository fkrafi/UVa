#include<stdio.h>
#include<math.h>

double pi = acos(-1);

int main(){
	freopen("10286.txt", "r", stdin);
	double x;
	double a = sin((108.0 * pi)/180.0) / sin((63.0 * pi)/180.0);
	while(scanf("%lf", &x) != EOF){
		printf("%.10lf\n", a*x);
	}
	return 0;
}