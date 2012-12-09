#include<stdio.h>
#include<math.h>

long int prm[100000], cnt[100000];

long int prime_factors(long int n)
{
	long int s=int(sqrt(n)), i, sz=0;
	if(n%2==0)
	{
		prm[sz] = 2;
		cnt[sz] = 0;
		while(n%2==0)
		{
			cnt[sz]++;
			n /= 2;
		}
		sz++;
	}
	for(i=3; i<=s; i+=2)
	{
		if(n%i==0)
		{
			prm[sz] = i;
			cnt[sz] = 0;
			while(n%i==0)
			{
				cnt[sz]++;
				n /= i;
			}
			sz++;
		}
	}
	if(n!=1)
	{
		prm[sz] = n;
		cnt[sz++] = 1;
	}
	return sz;
}

int chk(int n, int sz)
{
	long int i, d, t;
	for(i=0; i<sz; i++)
	{
		t = n;
		d = 0;
		while(t)
		{
			d += (t/prm[i]);
			t /= prm[i];
		}
		if(d < cnt[i])return 0;
	}
	return 1;
}

int main()
{
	long int n, k, sz;
	while(scanf("%ld%ld", &n, &k) != EOF)
	{
		if(!k)
			printf("%ld does not divide %ld!\n", k, n);
		else{
			sz = prime_factors(k);
			if(chk(n, sz))
				printf("%ld divides %ld!\n", k, n);
			else
				printf("%ld does not divide %ld!\n", k, n);
		}
	}
	return 0;
}