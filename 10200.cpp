#include<stdio.h>
#include<math.h>

#define eps 1e-9
double ans[10010];

int isPrime(int n)
{
	int i, s=int(sqrt(n));
	if(n%2==0)return 0;
	for(i=3; i<=s; i+=2)
	{
		if(n%i==0)return 0;
	}
	return 1;
}

void generate(int t)
{
	int i, p;
	ans[0] = 1;
	for(i=1; i<=t; i++)
	{
		p = (i*i)+i+41;
		ans[i] = isPrime(p);
	}
}

int main()
{
	generate(10000);
	int a, b, i;
	double euler, real;
	double res;
	while(scanf("%d%d", &a, &b) != EOF)
	{
		real = 0;
		for(i=a; i<=b; i++)
		{
			if(ans[i])
				real++;
		}
		euler = (b-a+1);
		if(real){
			res = (real/euler)*100.0;
			printf("%.2lf\n", res+eps);
		}else
			printf("0.00\n");
	}
	return 0;
}