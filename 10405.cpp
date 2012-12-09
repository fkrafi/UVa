#include<stdio.h>
#include<string.h>

int lcs[1010][1010];
char s1[1001], s2[1001];

int max(int a, int b)
{
	if(a>b)
		return a;
	return b;
}

int main()
{
	int l1, l2, i, j;
	while(gets(s1))
	{
		gets(s2);
		l1 = strlen(s1);
		l2 = strlen(s2);
		for(i=0; i<=l1; i++)
		{
			for(j=0; j<=l2; j++)
			{
				if(i>0 && j>0)
				{
					if(s1[i-1] == s2[j-1])
						lcs[i][j] = lcs[i-1][j-1] + 1;
					else
						lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
				}else{lcs[i][j] = 0;}
			}
		}
		printf("%d\n", lcs[l1][l2]);
	}
	return 0;
}