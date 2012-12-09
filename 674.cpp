#include<stdio.h>

int S[] = {0, 1, 5, 10, 25, 50};
int mem[7520][150];

void dp()
{
	int m, n;
	for(n=0; n<=7500; n++)
	{
		for(m=0; m<=6; m++)
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
		printf("%d\n", mem[n][6]);
	return 0;
}