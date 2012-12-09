#include<stdio.h>
#include<string.h>

char str[1000000], s[1000000];

int main()
{
	int len, d, i, j, flag;
	while(scanf("%d%s", &d, str))
	{
		len = strlen(str);
		if(!d && len==1 && str[0]=='0')break;
		flag = 0;
		j = 0;
		for(i=0; i<len; i++)
		{
			if(str[i] != d+48)
				s[j++] = str[i];
			if(str[i]!='0' && str[i]!=d+48)
				flag = 1;
		}
		s[j] = '\0';
		if(!flag || !j)
			printf("0\n");
		else
			printf("%s\n", s);
	}
	return 0;
}