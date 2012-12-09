#include<stdio.h>

int s1[110], s2[110], lcs[110][110];

int max(int a, int b)
{
	if(a>b)return a;
	return b;
}

void dp(int l1, int l2)
{
	int i, j;
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
}

int main()
{
	int l1, l2, C=1, i;
	while(scanf("%d%d", &l1, &l2) != EOF)
	{
		if(!l1 && !l2)break;
		for(i=0; i<l1; i++)scanf("%d", &s1[i]);
		for(i=0; i<l2; i++)scanf("%d", &s2[i]);
		dp(l1, l2);
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", C++, lcs[l1][l2]);
	}
	return 0;
}