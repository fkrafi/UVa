#include<stdio.h>
#include<math.h>

int main()
{
	double a, b, c, area, r, s;
	while(scanf("%lf%lf%lf", &a, &b, &c) != EOF)
	{
		if(a>b+c || b>c+a || c>b+a || a+b+c==0){
			printf("The radius of the round table is: 0.000\n");
		}else{
			s = (a+b+c)/2;
			area = sqrt( s*(s-a)*(s-b)*(s-c) );
			r = (2*area)/(a+b+c);
			printf("The radius of the round table is: %.3lf\n", r);
		}
	}
	return 0;
}