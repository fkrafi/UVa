#include<stdio.h>

int main()
{
	freopen("11150.txt", "r", stdin);
	int n, res;
	while(scanf("%d", &n) != EOF)
	{
		res = n;
		while(n > 2)
		{
			res += n/3;
			n = n%3 + n/3;
		}
		if(n==2)res++;
		printf("%d\n", res);
	}
	return 0;
}