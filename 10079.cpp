#include<stdio.h>

int main()
{
	long long int sum, n;
	while(scanf("%lld", &n))
	{
		if(n<0)break;
		sum = (n*(n+1)/2)+1;
		printf("%lld\n", sum);
	}
	return 0;
}