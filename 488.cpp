#include<stdio.h>

int wave[] = {0, 1, 22, 333, 4444, 55555, 666666, 7777777, 88888888, 999999999};

int main()
{
	int t, a, f, i, j=0, k, flag = 0;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &a, &f);
		for(k=1; k<=f; k++)
		{
			for(i=1; i<=a; i++)
				printf("%d\n", wave[i]);
			
			for(i=a-1; i>=1; i--)
				printf("%d\n", wave[i]);
			
			if(k != f)
				printf("\n");
		}
		if(t != 0)
			printf("\n");
	}
	return 0;
}