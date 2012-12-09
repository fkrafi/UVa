#include<stdio.h>
#define MIN -2147483647

int main()
{
	freopen("11799.txt", "r", stdin);
	int t, n, i, j, a, res;
	scanf("%d", &t);
	for(i=1; i<=t; i++)
	{
		scanf("%d", &n);
		res = MIN;
		for(j=0; j<n; j++)
		{
			scanf("%d", &a);
			if(res < a)res = a;
		}
		printf("Case %d: %d\n", i, res);
	}
	return 0;
}