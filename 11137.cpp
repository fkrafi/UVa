#include<stdio.h>

int S[25];
double mem[10005][25];

void dp()
{
	int m, n;
	for(n=0; n<=10000; n++)
	{
		for(m=0; m<=21; m++)
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
	int n, i;
	for(i=1; i<=21; i++)
		S[i] = i*i*i;
	dp();
	while(scanf("%d", &n) != EOF)
		printf("%.0lf\n", mem[n][21]);
	return 0;
}