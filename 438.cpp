#include <stdio.h>
#include <math.h>

const double pi=acos(-1);
int main(){
	double x1, y1, x2, y2, x3, y3;
	double h, k, r, ans;
	double m1, m2;
	while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3)!=EOF)
	{
		m1= (y2-y1)/(x2-x1);
		m2= (y3-y1)/(x3-x1);
		if (m2==0)
		{
			k=(x2-x3)/m1/2+(y1+y2)/2;
			h=(x1+x3)/2;
		}
		if (m1==0){
			k=(x3-x2)/m2/2+(y1+y3)/2;
			h=(x1+x2)/2;
		}else if (m1!=0&&m2!=0){
			h=((x1+x2)/m1-(x1+x3)/m2+y2-y3)/2/(1/m1 - 1/m2);
			k=( h-(x1+x2)/2)/(-m1)+(y1+y2)/2;
		}
		r= sqrt((h-x1)*(h-x1) + (k-y1)*(k-y1));
		ans=2*pi*r;
		printf("%.2lf\n", ans);
	}
	return 0;
}

