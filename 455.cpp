#include<stdio.h>
#include<string.h>

char s[100], s1[100];

int min_size(int l)
{
	int stp = l/2, i, j, con, k, m;
	for(i=0; i<stp; i++)
	{
		s1[i] = s[i];s1[i+1]='\0';
		con = 1;
		for(j=i+1; j<l; j+=i+1)
		{
			for(k=0, m=j; k<=i; k++, m++)
			{
				if(s1[k] != s[m])
				{
					con = 0;
					break;
				}
			}
			if(!con)break;
		}
		if(con)return strlen(s1);
	}
	return l;
}

int main()
{
	freopen("455.txt", "r", stdin);
	int t, l, res;
	scanf("%d", &t);getchar();	
	while(t--)
	{
		gets(s);gets(s);
		l = strlen(s);
		res = min_size(l);
		printf("%d\n", res);
		if(t)printf("\n");
	}
	return 0;
}