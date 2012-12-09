#include<stdio.h>

int main()
{
	//freopen("386.txt", "w", stdout);
	int a, b, c, d;
	for(a=6; a<=200; a++)
		for(b=2; b<=200; b++)
			for(c=b+1; c<=200; c++)
				for(d=c+1; d<=200; d++)
					if( (a*a*a) == ( (b*b*b) + (c*c*c) + (d*d*d) ))
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
	return 0;
}