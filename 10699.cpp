#include<stdio.h>
#include<math.h>

int a[1000010];

int count_factors(int n)
{
	int i, cnt=0, s=int(sqrt(n));
	if(n%2==0)
	{
		cnt++;
		while(n%2==0)
			n /= 2;
	}
	for(i=3; i<=s; i+=2)
	{
		if(n%i==0)
		{
			cnt++;
			while(n%i==0)
				n /= i;
		}
	}
	if(n>1)cnt++;
	return cnt;
}

int main()
{
	int n;
	while(scanf("%d", &n))
	{
		if(!n)break;
		printf("%d : %d\n", n, count_factors(n));
	}
	return 0;
}