#include<stdio.h>

int days[40000];

int main()
{
	int no_days, no_party, i, j, hartal, h, t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &no_days);
		scanf("%d", &no_party);
		for(i=1; i<=no_party; i++)
		{
			scanf("%d", &h);
			for(j=h; j<=no_days; j+=h)
			{
				if(j%7 == 6)
					days[j] = 0;
				else if(j%7 == 0)
					days[j] = 0;
				else
					days[j] = 1;
			}
		}
		hartal = 0;
		for(i=1; i<=no_days; i++)
		{
			if(days[i] == 1)
			{
				days[i] = 0;
				hartal++;
			}
		}
		printf("%d\n", hartal);
	}
	return 0;
}