#include<stdio.h>
#include<math.h>

int prime[110], prm[110];

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

void only_prime()
{
	int i, sz=0;
	for(i=0; i<110; i++)
	{
		if(!prime[i])
			prm[sz++] = i;
	}
}

int main()
{
	sieve(110);
	only_prime();
	int n, i, row, ans, t;
	while(scanf("%d", &n))
	{
		if(!n)break;
		row = 0;
		printf("%3d! =", n);
		for(i=0; prm[i]<=n; i++)
		{
			t = n;
			ans = 0;
			while(t)
			{
				t /= prm[i];
				ans += t;
			}
			row++;
			if(row%16==0){
				printf("\n      ");
				printf("%3d", ans);
				row = 0;
			}else
				printf("%3d", ans);
		}
		printf("\n");
	}
	return 0;
}