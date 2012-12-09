#include<stdio.h>

int main()
{
	int t, n, k, p, i, st;
	scanf("%d", &t);
	for(i=1; i<=t; i++)
	{
		scanf("%d%d%d", &n, &k, &p);
		st = k+p-n;
		if(st > n)st %= n;
		if(st < 0)st = k+p;
		if(st == 0)st = n;
		printf("Case %d: %d\n", i, st);
	}
	return 0;
}