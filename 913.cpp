#include<stdio.h>

int main()
{
	long long int n, term, line, sum, num;
	while(scanf("%lld", &n) != EOF)
	{
		line = (n+1)/2;
		num = 2*(line*(line+1) - line) - 1;
		sum = 3*num-6;
		printf("%lld\n", sum);
	}
	return 0;
}