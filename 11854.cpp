#include<stdio.h>

int main()
{
	double a, b, c;
	while(scanf("%lf%lf%lf", &a, &b, &c))
	{
		if(!a && !b && !c)break;
		a *= a;
		b *= b;
		c *= c;
		if(a+b==c || a+c==b || b+c==a)
			printf("right\n");
		else
			printf("wrong\n");
	}
	return 0;
}