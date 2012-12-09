#include<stdio.h>
#include<string.h>

int a[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
char s[10000];

int b1(int n)
{
	int b=0;
	while(n)
	{
		b += (n%2);
		n /= 2;
	}
	return b;
}

int b2(int n)
{
	int b=0;
	while(n)
	{
		b += a[n%10];
		n /= 10;
	}
	return b;
}

int not_num(char ch)
{
	if(ch>='0' && ch<='9')return 0;
	return 1;
}

int convert(char s[])
{
	int p, i, j, l=strlen(s), n=0;
	for(j=0; j<l; j++)
	{
		if(not_num(s[j]))return -1;
		p = 1;
		for(i=l; i>j+1; i--)p*=10;
		n += (s[j]-48)*p;
	}
	return n;
}

int main()
{
	int m, n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", s);
		m = convert(s);
		if(m>0)
			printf("%d %d\n", b1(m), b2(m));
		else
			printf("0 0\n");
	}
	return 0;
}