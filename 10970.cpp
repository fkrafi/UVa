#include<stdio.h>

int main()
{
	int m, n;
	while(scanf("%d%d", &m, &n) != EOF)
	{
		int cut = m*n - 1;
		printf("%d\n", cut);
	}
	return 0;
}