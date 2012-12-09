#include<stdio.h>

int ld[10010];

void generate()
{
	int i, n=1;
	ld[0] = 1;
	ld[1] = 1;
	for(i=2; i<=10000; i++)
	{
		n *= i;
		while(!(n%10))
			n /= 10;
		ld[i] = n%10;
		n %= 100000;
	}
}

int main()
{
	generate();
	int n;
	while(scanf("%d", &n) != EOF)
		printf("%5d -> %d\n", n, ld[n]);
	return 0;
}