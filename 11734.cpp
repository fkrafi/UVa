#include<stdio.h>
#include<string.h>

char ch, s1[100], s2[100], s3[100], s4[100];

int main()
{
	int i, t, l1, l2, j, k;
	scanf("%d%c", &t, &ch);
	for(i=1; i<=t; i++)
	{
		gets(s1);
		gets(s2);
		if(!strcmp(s1, s2))
			printf("Case %d: Yes\n", i);
		else{
			l1 = strlen(s1);
			k = 0;
			for(j=0; j<l1; j++)
			{
				if(s1[j] != ' ')
					s3[k++] = s1[j];
			}
			s3[k] = '\0';
			l1 = strlen(s3);
			l2 = strlen(s2);
			k = 0;
			for(j=0; j<l2; j++)
			{
				if(s2[j] != ' ')
					s4[k++] = s2[j];
			}
			s4[k] = '\0';
			l2 = strlen(s4);
			if(!strcmp(s3, s4))
				printf("Case %d: Output Format Error\n", i);
			else
				printf("Case %d: Wrong Answer\n", i);
		}
	}
	return 0;
}