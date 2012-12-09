#include<stdio.h>

int main()
{
	freopen("11900.txt", "r", stdin);
	int cs, t, n, p, q, a, i, cnt, sum;
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++)
	{
		scanf("%d%d%d", &n, &p, &q);
		cnt = 0;
		sum = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d", &a);
			if(cnt<p)
			{
				if(sum+a <= q)
				{
					sum += a;
					cnt++;
				}
			}
		}
		printf("Case %d: %d\n", cs, cnt);
	}
	return 0;
}