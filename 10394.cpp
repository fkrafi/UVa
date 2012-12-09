#include<stdio.h>
#include<string.h>
#include<math.h>
#include<time.h>

int prime[20000000], twin[100000];

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

void twin_gen()
{
	int i = 0, j = 0;
	for(i=3; ; i+=2)
	{
	    if(prime[i]==0 && prime[i+2]==0)
            twin[j++] = i;
        if(j==100000)break;
    }
}
int main()
{
	int s;
	sieve(20000000);
	twin_gen();
	while(scanf("%d", &s) != EOF)
	{
		printf("(%d, %d)\n", twin[s-1], (twin[s-1]+2));
	}
	return 0;
}
