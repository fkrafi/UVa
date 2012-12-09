#include<stdio.h>

int main()
{
	freopen("10300.txt", "r", stdin);
	int t, n, a, b, c, i;
	double sum;
	while(scanf("%d", &t) != EOF)
	{
		while(t--)
		{
			scanf("%d", &n);
			sum = 0;
			for(i=0; i<n; i++)
			{
				scanf("%d%d%d", &a, &b, &c);
				sum += (a*c);
			}
			printf("%.0lf\n", sum);
		}
	}
	return 0;
}