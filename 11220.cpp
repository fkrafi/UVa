#include<stdio.h>
#include<string.h>

char s1[100000], ch, str[10000];;

int isChar(char ch)
{
	return ( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z'));
}

int main()
{
	freopen("11220.txt", "r", stdin);
	int t, i, j, a, now, k, l;
	scanf("%d%c", &t, &ch);
	getchar();
	for(i=1; i<=t; i++)
	{
		printf("Case #%d:\n", i);
		while(gets(s1))
		{
			now = 0;
			l = strlen(s1);
			if(!l)break;
			for(k=0; k<l; k++)
			{
				a = 0;
				if(isChar(s1[k]))
				{
					while(isChar(s1[k]))
						str[a++] = s1[k++];
					k--;
					str[a] = '\0';
					if(now<a)
						printf("%c", str[now++]);
				}
			}
			printf("\n");
		}
		if(i<t)
			printf("\n");
	}
	return 0;
}