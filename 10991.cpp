#include<stdio.h>
#include<math.h>

int main()
{
	double r1, r2, r3;
	double a, b, c, s, area, area1, area2, area3, ang;
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lf%lf%lf", &r1, &r2, &r3);
		a = r1+r2;
		b = r2+r3;
		c = r3+r1;

		ang = (a*a)+(b*b)-(c*c);
		ang /= (2*a*b);
		ang = acos(ang);
		area1 = .5*ang*r2*r2;

		ang = (a*a)+(c*c)-(b*b);
		ang /= (2*a*c);
		ang = acos(ang);
		area2 = .5*ang*r1*r1;

		ang = (c*c)+(b*b)-(a*a);
		ang /= (2*c*b);
		ang = acos(ang);
		area3 = .5*ang*r3*r3;

		s = (a+b+c)/2;
		area = sqrt(s*(s-a)*(s-b)*(s-c)) - (area1+area2+area3);
		printf("%.6lf\n", area);
	}
	return 0;
}