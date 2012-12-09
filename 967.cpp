#include<stdio.h>
#include<math.h>

int prime[1000010], circular[1000010], j, p;

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

void no_digit(int n)
{
	if(n>=1000000)
	{
		j = 7; p = 1000000;
	}else if(n>=100000){
		j = 6; p = 100000;
	}else if(n>=10000){
		j = 5; p = 10000;
	}else if(n>=1000){
		j = 4; p = 1000;
	}else if(n>=100){
		j = 3; p = 100;
	}
}

int check_circular(int n)
{
	int t=n, i;
	no_digit(n);
	for(i=0; i<j; i++)
	{
		t = ((n%10)*p) + (n/10);
		if(prime[t])return 0;
		n = t;
	}
	return 1;
}

void cal_circular()
{
	int i;
	circular[100] = 0;
	for(i=101; i<=1000000; i++)
	{
		if(prime[i] == 0)
			circular[i] = circular[i-1] + check_circular(i);
		else
			circular[i] = circular[i-1];
	}
}

int main()
{
	sieve(1000000);
	cal_circular();
	int no, a, b;
	while(scanf("%d", &a))
	{
		if(a<0)break;
		scanf("%d", &b);
		no = circular[b] - circular[a-1];
		if(!no)
			printf("No Circular Primes.\n");
		else if(no==1)
			printf("1 Circular Prime.\n");
		else
			printf("%d Circular Primes.\n", no);
	}
	return 0;
}