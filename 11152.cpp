#include<stdio.h>
#include<math.h>

int main()
{
	double a, b, c, sArea, vArea, rArea, r, s, pi=acos(-1);
	while(scanf("%lf%lf%lf", &a, &b, &c) != EOF)
	{
		s = (a+b+c)/2;
		vArea = sqrt( s*(s-a)*(s-b)*(s-c) );
		r = vArea/s;
		rArea = pi*r*r;
		r = (a*b*c)/(4*vArea);
		sArea = (pi*r*r)-vArea;
		vArea -= rArea;
		printf("%.4lf %.4lf %.4lf\n", sArea, vArea, rArea);
	}
	return 0;
}