#include<stdio.h>

int main()
{
	int n, a, res;
	while(scanf("%d", &n) != EOF)
	{
		if(n%2==0 || n%5==0){printf("0\n"); continue;}
		a = 1;
		res = 1;
		while(a)
		{
			if(a<n){
				res++;
				a = a*10 + 1;
			}
			a %= n;
		}
		printf("%d\n", res);
	}
	return 0;
}