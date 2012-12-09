#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s1[1010], s2[1010];
int lcs[1010][1010];

int max(int a, int b)
{
	if(a>b)return a;
	return b;
}

int main()
{
	int i, j, l, t;
	scanf("%d", &t);getchar();
	while(t--)
	{
		gets(s1);
		strcpy(s2, s1);
		l = strlen(s1);
		reverse(s2, s2+l);
		for(i=0; i<=l; i++)
		{
			for(j=0; j<=l; j++)
			{
				if(!i || !j)
					lcs[i][j] = 0;
				else if(s1[i-1] == s2[j-1])
					lcs[i][j] = lcs[i-1][j-1] + 1;
				else
					lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
		printf("%d\n", lcs[l][l]);
	}
	return 0;
}