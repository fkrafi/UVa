#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char str[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
char str1[] = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg\'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";
char s[10000];

int search(char ch)
{
	for(int i=0; i<98; i++)
		if(str[i]==ch)return i;
	return -1;
}

int main()
{
	int i, l, pos;
	while(gets(s))
	{
		l = strlen(s);
		for(i=0; i<l; i++)
		{
			pos = search(s[i]);
			if(pos == -1)
				printf("%c", s[i]);
			else
				printf("%c", str1[pos]);
		}
		printf("\n");
	}
	return 0;
}