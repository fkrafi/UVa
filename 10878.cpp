#include<stdio.h>
#include<string.h>

char s[1000000], s1[100000], str[100000];

int convert(char s[])
{
	int i, j, n=0, p, l=strlen(s);
	for(i=0; i<l; i++)
	{
		p = 1;
		for(j=i; j<l-1; j++)
			p *= 2;
		n += p*(s[i]-48);
	}
	return n;
}

char tolower(char ch)
{
	if(ch>='A' && ch<='Z')
		return (ch+'a'-1);
	return ch;
}

int main()
{
	int i, j, k=0, l, halt=2;
	while(gets(s))
	{
		if(strcmp(s, "___________")==0)halt--;
		if(!halt)break;
		l = strlen(s);
		j = 0;
		for(i=2; i<l; i++)
		{
			if(s[i] == ' ')
				str[j++] = '0';
			else if(tolower(s[i]) == 'o')
				str[j++] = '1';
		}
		str[j] = '\0';
		if(strlen(str))s1[k++] = convert(str);
	}
	s1[k] = '\0';
	l = strlen(s1);
	for(i=0; i<l; i++)
		printf("%c", s1[i]);
	return 0;
}