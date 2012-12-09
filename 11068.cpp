#include<stdio.h>
#include<math.h>

double a1, b1, c1, a2, b2, c2, det, x, y;

int main()
{
	while(scanf("%lf%lf%lf%lf%lf%lf", &a1, &b1, &c1, &a2, &b2, &c2))
	{
		if(!a1 && !b1 && !c1 && !a2 && !b2 && !c2)break;
		det = a1*b2 - a2*b1;
		if(det==0)
			printf("No fixed point exists.\n");
		else{
			x = (b2*c1 - b1*c2)/det;
			y = (a1*c2 - a2*c1)/det;
			printf("The fixed point is at %.2lf %.2lf.\n", x, y);
		}
	}
	return 0;
}