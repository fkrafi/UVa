#include<stdio.h>
#include<math.h>
#define SZ 1000005

int prime[SZ], p[SZ];

void sieve(int n)
{
   prime[0]=1;
   prime[1]=1;
   int m = int(sqrt(n)), i=2, k;
   for(k=i*i; k<=n; k+=i)
      prime[k]=1;
   for (i=3; i<=m; i+=2)
      if(!prime[i])
         for (k=i*i; k<=n; k+=i)
            prime[k]=1;
}

int main()
{
	freopen("10948.txt", "r", stdin);
	int i, j=0, n, a, b;
	sieve(SZ-1);
	for(i=0; i<SZ; i++)
		if(!prime[i])p[j++] = i;
	while(scanf("%d", &n))
	{
		if(!n)break;
		a = b = -1;
		for(i=0; ; i++)
		{
			j = n - p[i];
			if(j<p[i])break;
			if(!prime[p[i]] && !prime[j])
			{
				a = p[i];
				b = j;
				break;
			}
		}
		printf("%d:\n", n);
		if(a>0)
			printf("%d+%d\n", a, b);
		else
			printf("NO WAY!\n");
	}
	return 0;
}