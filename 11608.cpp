#include<stdio.h>

int prob[15], need[15], curr, C, i;

int main()
{
	while(scanf("%d", &curr))
	{
		if(curr < 0)break;
		for(i=0; i<12; i++)scanf("%d", &prob[i]);
		for(i=0; i<12; i++)scanf("%d", &need[i]);
		printf("Case %d:\n", ++C);
		for(i=0; i<12; i++)
		{
			if(curr >= need[i]){
				printf("No problem! :D\n");
				curr += prob[i]-need[i];
			}else{
				printf("No problem. :(\n");
				curr += prob[i];
			}
		}
	}
	return 0;
}