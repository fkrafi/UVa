#include<stdio.h>
#include<string.h>

char s[10000000];

int isChar(char ch)
{
	if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') )
		return 1;
	return 0;
}

int main()
{
	int l, i, cnt;
	while(gets(s))
	{
		l = strlen(s);
		cnt = 0;
		for(i=0; i<l; i++)
		{
			if(isChar(s[i]))
			{
				cnt++;
				while(isChar(s[i+1]) && i<l)
					i++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}