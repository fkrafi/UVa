#include<stdio.h>
#include<math.h>

int main()
{
	double m1, m2, m3, o, a;
	while(scanf("%lf%lf%lf", &m1, &m2, &m3) != EOF)
	{
		o = (m1+m2+m3)/2;
		a = o*(o-m1)*(o-m2)*(o-m3);
		if(a <= 0)
		{
			printf("-1.000\n");
		}else{
			a = sqrt(a);
			a *= 4;
			a /= 3;
			printf("%.3lf\n", a);
		}
	}
	return 0;
}