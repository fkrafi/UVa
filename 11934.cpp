#include<stdio.h>

long long int func(long long int n, long long int a, long long int b, long long int c)
{
	return a*n*n+b*n+c;
}

int main()
{
	freopen("11934.txt", "r", stdin);
	long long int a, b, c, d, cnt, i, l;
	while(scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &l))
	{
		if( !a && !b && !c && !d && !l)break;
		cnt = 0;
		for(i=0; i<=l; i++)
		{
			if( func(i, a, b, c)%d == 0 )
				cnt++;
		}
		printf("%lld\n", cnt);
	}
	return 0;
}