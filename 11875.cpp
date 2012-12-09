#include<stdio.h>

int a[15];

int main()
{
	int t, i, j, n;
	scanf("%d", &t);
	for(i=1; i<=t; i++)
	{
		scanf("%d", &n);
		for(j=1; j<=n; j++)
			scanf("%d", &a[j]);
		n = (n+1)/2;
		printf("Case %d: %d\n", i, a[n]);
	}
	return 0;
}