#include<stdio.h>
#include<math.h>

int main()
{
	int h, m;
	double ang;
	while(scanf("%d:%d", &h, &m))
	{
		if(!h && !m)return 0;
		ang = (double(h)*60.0*0.5)+(double(m)*0.5)-(double(m)*6);
		if(ang<0)ang *= -1;
		if(ang>=180)ang = 360-ang;
		printf("%.3lf\n", ang);
	}
	return 0;
}