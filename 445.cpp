#include<stdio.h>
#include<string.h>

char s[150], c;

int isDigit(char c)
{
	return (c>='0' && c<='9');
}


int main()
{
	//freopen("445.txt", "r", stdin);
	int n, l, i, j;
	while(gets(s))
	{
		l = strlen(s);
		for(i=0; i<l; i++)
		{
			if(s[i] == '!')printf("\n");
			else if(isDigit(s[i])){
				n = 0;
				while(isDigit(s[i]))
					n += s[i++]-48;
				c = (s[i]=='b') ? ' ' : s[i];
				for(j=1; j<=n; j++)printf("%c", c);
			}else{
				c = (s[i]=='b') ? ' ' : s[i];
				printf("%c", c);
			}
		}
		printf("\n");
	}
	return 0;
}