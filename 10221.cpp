#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	double s, a, thita, R, angle,p,q, pi = acos(-1);
	char str[5];

	while(scanf("%lf%lf%s",&s,&a,str)!=EOF)
	{
		if(!strcmp(str,"min"))
			a=a/60.0;
		
		if(a>360.0)
			a=0.0;
		else if(a>180.0)
			a=360.0-a;

		thita = a*(pi/180.0);

		R = 6440.0+s;
	
		printf("%lf %lf\n",R*thita,(2*R*cos((pi-thita)/2.0)));		
	}

	return 0;
}