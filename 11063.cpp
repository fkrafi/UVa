#include<stdio.h>

int num[105], sum[20005];

int main()
{
	freopen("11063.txt", "r", stdin);
	freopen("11063_out.txt", "w", stdout);
	int n, cs=1, con, i, j, s;
	while(scanf("%d", &n) != EOF)
	{
		con = 1;
		for(i=0; i<n; i++)
		{
			scanf("%d", &num[i]);
			if(con)
			{
				if(num[i]<=0)
					con = 0;
				if(i && num[i-1]>num[i])
					con = 0;
				for(j=0; j<=i; j++)
				{
					s = num[i] + num[j];
					if(sum[s] != cs)
						sum[s] = cs;
					else
						con = 0;

				}
			}
		}
		if(con)
			printf("Case #%d: It is a B2-Sequence.\n\n", cs++);
		else
			printf("Case #%d: It is not a B2-Sequence.\n\n", cs++);
	}
	return 0;
}