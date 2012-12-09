#include<stdio.h>
#include<string>
using namespace std;

struct store{
	char s[101];
	int len;
}str[101];

char s[101];

int main()
{
	freopen("490.txt", "r", stdin);
	int sz=0, l, max=-1, i, j;
	while(gets(s))
	{
		strcpy(str[sz].s, s);
		l = strlen(s);
		str[sz++].len = l;
		if(max < l)max = l;
	}

	for(i=0; i<max; i++)
	{
		for(j=sz-1; j>=0; j--)
		{
			if(i < str[j].len)
				printf("%c", str[j].s[i]);
			else
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}