#include<stdio.h>

int main()
{
	int t, i, cs, n, con;
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++)
	{
		scanf("%d", &n);
		printf("Case #%d: %d", cs, n);
		con = 2;
		for(i=2; i<=n; i++)
		{
			if(n%i==0){
				printf(" = %d * %d", i, n/i);
				con--;
			}
			if(!con)break;
		}
		printf("\n");
	}
	return 0;
}