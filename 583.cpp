#include<stdio.h>
#include<math.h>

void factors(int n)
{
	int i, flag=1;
	if(n<0)
	{
		printf(" -1");
		n *= -1;
		flag = 0;
	}
	int s = int(sqrt(n));
	while(n%2==0)
	{
		if(flag)
			printf(" 2");
		else
			printf(" x 2");
		n /= 2;
		flag = 0;
	}
	if(n==1)return;
	for(i=3; i<=s; i+=2)
	{
		while(n%i==0)
		{
			if(flag)
				printf(" %d", i);
			else
				printf(" x %d", i);
			n /= i;
			flag = 0;
		}
		if(n==1)return;
	}
	if(n>1)
	{
		if(flag)
			printf(" %d", n);
		else
			printf(" x %d", n);
	}
}

int main()
{
	int n;
	while(scanf("%d", &n))
	{
		if(!n)break;
		printf("%d =", n);
		factors(n);
		printf("\n");
	}
	return 0;
}