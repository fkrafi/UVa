#include<stdio.h>

double f[100];

void fact(int n)
{
	f[1] = 1;
	for(int i=2; i<=n; i++)
		f[i] = f[i-1]*i;
}

int main()
{
	long long int n;
	int sign;
	fact(13);
	while(scanf("%lld", &n) != EOF)
	{
		sign = 0;
		if(n<0)
		{
			sign = 1;
			n *= -1;
		}
		if(sign)
		{
			if(n%2)
				printf("Overflow!\n");
			else
				printf("Underflow!\n");
		}else{
			if(n<8)
				printf("Underflow!\n");
			else if(n>13)
				printf("Overflow!\n");
			else
				printf("%.0lf\n", f[n]);
		}
	}
	return 0;
}