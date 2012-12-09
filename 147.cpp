#include<stdio.h>

int S[] = {0, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
double mem[30005][15];

void dp()
{
	int m, n;
	for(n=0; n<=30000; n++)
	{
		for(m=0; m<=11; m++)
		{
			if(!n)
				mem[n][m] = 1;
			else if(m-1<0 && (n-S[m])>=0)
				mem[n][m] = mem[n-S[m]][m];
			else if(n-S[m]<0 && (m-1)>=0)
				mem[n][m] = mem[n][m-1];
			else
				mem[n][m] = mem[n][m-1] + mem[n-S[m]][m];
		}
	}
}

int main()
{
	double n;
	int a;
	dp();
	while(scanf("%lf", &n))
	{
		if(!n)break;
		a = int(n * 100 + .5);
		printf("%6.2lf%17.0lf\n", n, mem[a][11]);
	}
	return 0;
}