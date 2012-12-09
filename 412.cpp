#include<stdio.h>
#include<math.h>

int a[1000];
double fact[60];
int gcd(int a, int b)
{
	if(!b)return a;
	return gcd(b, a%b);
}

void factorial(int n)
{
	int i;
	fact[0] = 1;
	fact[1] = 1;
	for(i=2; i<=n; i++)
		fact[i] = fact[i-1]*i;
}

double ncr(int n)
{
	double ans;
	ans = fact[n]/(2.0*fact[n-2]);
	return ans;
}

int main()
{
	int n, i, j;
	double pi, b, cnt;
	factorial(50);
	while(scanf("%d", &n))
	{
		if(!n)break;
		for(i=0; i<n; i++)
			scanf("%d", &a[i]);
		cnt = 0;
		for(i=0; i<n; i++)
		{
			for(j=i+1; j<n; j++)
			{
				if(gcd(a[i], a[j]) == 1)
					cnt++;
			}
		}
		b = ncr(n);
		pi = sqrt((6.0*b)/cnt);
		if(!cnt)
			printf("No estimate for this data set.\n");
		else
			printf("%.6lf\n", pi);
	}
	return 0;
}