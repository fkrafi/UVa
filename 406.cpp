#include<stdio.h>
#include<math.h>

int n, c, prime[1000005], cnt[1000005], all_primes[1000000];

void sieve(int n)
{
   prime[0]=1;
   int m = int(sqrt(n)), i=2, k;
   for(k=i*i; k<=n; k+=i)
      prime[k]=1;
   for (i=3; i<=m; i+=2)
      if(!prime[i])
         for (k=i*i; k<=n; k+=i)
            prime[k]=1;
}

int cnt_primes(int n)
{
	int i, j=1;
	for(i=1; i<=n; i++)
	{
		if(prime[i])
			cnt[i] = cnt[i-1];
		else{
			cnt[i] = cnt[i-1] + 1;
			all_primes[j++] = i;
		}
	}
	return j;
}

int main(){
	freopen("406.txt", "r", stdin);
	sieve(1000000);
	
	int no_primes = cnt_primes(1000000), i, max, j;

	while(scanf("%d%d", &n, &c) != EOF){
		printf("%d %d:", n, c);
		max = (cnt[n]%2)?((c*2)-1):(c*2);
		i = (cnt[n] - max)/2 + 1;
		if(i<=0)i=1;
		for(j=0; j<max && all_primes[i+j]<=n; j++)
			printf(" %d", all_primes[i+j]);
		printf("\n\n");
	}
	return 0;
}