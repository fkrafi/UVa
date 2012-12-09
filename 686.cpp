#include<stdio.h>
#include<math.h>
#define SZ 32770

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
	int i, j=0, cnt, n;
	sieve(SZ);
	for(i=0; i<=SZ; i++)
		if(!prime[i])p[j++] = i;
	while(scanf("%d", &n) && n)
	{
		cnt = 0;
		for(i=0; ; i++)
		{
			j = n - p[i];
			if(j<p[i])break;
			if(!prime[p[i]] && !prime[j])cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}