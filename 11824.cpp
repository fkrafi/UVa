#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 5000000

bool comp(long long int a, long long int b)
{
	return a>b;
}

long long int cost[41];

long long int calculate(long long int sz)
{
	long long int i, p, j, sum=0;
	for(i=0; i<=sz; i++)
	{
		p = 1;
		for(j=0; j<=i; j++)
		{
			p *= cost[i];
			if(p > MAX)
				return -1;
		}
		if( sum+2*p > MAX)return -1;
		sum += 2*p;
	}
	return sum;
}

int main()
{
	freopen("11824.txt", "r", stdin);
	long long int sz, t, cst;
	scanf("%lld", &t);
	while(t--)
	{
		for(sz=0; ; sz++)
		{
			scanf("%lld", &cost[sz]);
			if(cost[sz] == 0)break;
		}
		sort(cost, cost+sz, comp);
		cst = calculate(sz);
		if(cst == -1)
			printf("Too expensive\n");
		else
			printf("%lld\n", cst);
	}
	return 0;
}