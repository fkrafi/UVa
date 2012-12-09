#include<stdio.h>
#include<string.h>

char s[100][100], ch;
int max, cnt[100];

int main()
{
	int t, i, j, sum, l;
	while(scanf("%d", &t))
	{
		ch = getchar();
		if(!t)break;
		max = -1;
		for(i=0; i<t; i++)
		{
			gets(s[i]);
			l = strlen(s[i]);
			cnt[i] = 0;
			for(j=0; j<l; j++)
				if(s[i][j]=='X' || s[i][j]=='x')cnt[i]++;
			if(cnt[i]>max)max=cnt[i];
		}
		sum = 0;
		for(i=0; i<t; i++)
			sum += (max - cnt[i]);
		printf("%d\n", sum);
	}
	return 0;
}