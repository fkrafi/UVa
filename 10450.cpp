#include<stdio.h>

double fibb[100];

void generate_fibb(int n)
{
	fibb[0] = 1;
	fibb[1] = 2;
	for(int i=2; i<=n; i++)
		fibb[i] = fibb[i-1] + fibb[i-2];
}

int main()
{
	int n, t, i;
	generate_fibb(51);
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		scanf("%d", &t);
		printf("Scenario #%d:\n%.0lf\n\n", i, fibb[t]);
	}
	return 0;
}