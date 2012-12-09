#include<stdio.h>

int S[] = {0, 1, 5, 10, 25, 50};
double mem[30005][7];

void dp()
{
	int m, n;
	for(n=0; n<=30000; n++)
	{
		for(m=0; m<=5; m++)
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
	int n;
	dp();
	while(scanf("%d", &n) != EOF)
	{
		if(mem[n][5] == 1)
			printf("There is only 1 way to produce %d cents change.\n", n);
		else
		printf("There are %.0lf ways to produce %d cents change.\n", mem[n][5], n);
	}
	return 0;
}