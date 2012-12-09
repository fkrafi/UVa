#include<stdio.h>
#include<math.h>

int main()
{
	double d, n, c;
	int cs=1;
	while(scanf("%lf", &d) && d)
	{
		c = -2*d;
		n = ceil((3 + sqrt(9 - 4*c)) / 2);
		printf("Case %d: %.0lf\n", cs++, n);
	}
	return 0;
}