#include<stdio.h>
#include<math.h>
#define EPS 1e-7
double p, q, r, s, t, u;

double func(double x)
{
	double y = ((p*exp(-x)) + (q*sin(x)) + (r*cos(x)) + (s*tan(x)) + (t*x*x) + u);
	return y;
}

int main()
{
//	freopen("10341.txt", "r", stdin);
	double x1, x2, x0, f1, f2, f0, ea, prevX;
	while(scanf("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u) != EOF)
	{
		x1 = 0;
		x2 = 1;
		f1 = func(x1);
		f2 = func(x2);
		if(f1 == 0){
			printf("%.4lf\n", x1);
			continue;
		}else if(f2 == 0){
			printf("%.4lf\n", x2);
			continue;
		}else if(f1*f2>0){
			printf("No solution\n");
			continue;
		}
		x0 = (x1+x2)/2;
		f0 = func(x0);
		if(f0 == 0){
			printf("%.4lf\n", x0);
			continue;
		}
		prevX = 0;
		ea = 1;
		if(f1*f0<0)
			x2 = x0;
		else
			x1 = x0;
		while(ea > EPS)
		{
			f1 = func(x1);
			f2 = func(x2);
			x0 = (x1+x2)/2;
			x0 = (x1+x2)/2;
			f0 = func(x0);
			if(f1 == 0){
				x0 = x1;
				break;
			}else if(f2 == 0){
				x0 = x2;
				break;
			}else if(f0 == 0)
				break;
			if(f1*f0<0)
				x2 = x0;
			else
				x1 = x0;
			ea = fabs((x0-prevX)/x0);
			prevX = x0;
		}
		if(x0>=0 && x0<=1)
			printf("%.4lf\n", x0);
		else
			printf("No solution\n");
	}
	return 0;
}