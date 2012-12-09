#include<stdio.h>

int f[50], g[50];

void dp(int n)
{
	int i;
	f[0] = 1;
	f[1] = 0;
	g[0] = 0;
	g[1] = 1;
	for(i=2; i<=n; i++)
	{
		f[i] = f[i-2] + 2*g[i-1];
		g[i] = f[i-1] + g[i-2];
	}
}

int main()
{
	int n;
	dp(30);
	while(scanf("%d", &n))
	{
		if(n<0)break;
		printf("%d\n", f[n]);
	}
	return 0;
}