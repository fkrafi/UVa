#include<stdio.h>
#include<string.h>

char s[1000], op;
int a[5];

int isDigit(char c)
{
	return (c>='0' && c<='9');
}

int isOper(char c)
{
	return (c=='-' || c=='+');
}

int check()
{
	if(op == '+'){
		if(a[0] + a[1] == a[2])return 1;
		return 0;
	}
	if(a[0] - a[1] == a[2])return 1;
	return 0;
}

int main()
{
//	freopen("11878.txt", "r", stdin);
	int i, j, l, cor=0;
	while(gets(s))
	{
		l = strlen(s);
		a[0] = a[1] = a[2] = 0;
		j = 0;
		for(i=0; i<l; i++)
		{
			if(s[i] == '?')a[2] = -1;
			if(isDigit(s[i])){
				while(isDigit(s[i]) && i<l)
					a[j] = a[j]*10 + s[i++] - 48;
				j++;
				i--;
			}else if(isOper(s[i]))
				op = s[i];
		}
		if(a[2]>-1 && check())
			cor++;
	}
	printf("%d\n", cor);
	return 0;
}