#include<stdio.h>
#include<math.h>

int maxN, max;

int factors(int n)
{
	int ret=1, cnt=0, i, s=int(sqrt(n))+1, t=n;
	if(n==1)return 1;
	if(n==3)return 2;
	while(n%2==0)
	{
		n/=2;
		cnt++;
	}
	if(cnt)
		ret *= (cnt+1);
	for(i=3; i<=s; i+=2)
	{
		cnt = 0;
		while(n%i==0)
		{
			cnt++;
			n /= i;
		}
		ret *= (cnt+1);
	}
	if(t==n)return 2;
	return ret;
}


void chk(int L, int H)
{
	int i, t;
	max = maxN = 0;
	for(i=L; i<=H; i++)
	{
		t = factors(i);
		if(max<t)
		{
			max = t;
			maxN = i;
		}
	}
}

int main()
{
	freopen("294.txt", "r", stdin);
	long int L, U, t;
	scanf("%ld", &t);
	while(t--)
	{
		scanf("%ld%ld", &L, &U);
		chk(L, U);
		printf("Between %ld and %ld, %ld has a maximum of %ld divisors.\n", L, U, maxN, max);
	}
	return 0;
}