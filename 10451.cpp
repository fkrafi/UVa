#include<stdio.h>
#include<math.h>

int main()
{
	double ang, n, area[4], r, c, s;
	int i=1;
	while(scanf("%lf%lf", &n, &area[0]))
	{
		if(n < 3)break;
		area[1] = area[0]/n;
		ang = (2.0*acos(-1))/n;
		r = sqrt((2*area[1])/sin(ang));
		area[2] = n*((.5*r*r*ang) - area[1]);
		
		c = sqrt(2*r*r*(1-cos(ang)));
		s = (2*area[1])/c;
		s = acos(-1)*s*s;
		area[3] = area[0] - s;
		printf("Case %d: %.5lf %.5lf\n", i++, area[2], area[3]);
	}
	return 0;
}