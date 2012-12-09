#pragma warning(disable : 4786)
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
#define SZ 10000

map<char, char> M;
char s[SZ], rev[SZ];
int len;

void init()
{
	M['A'] = 'A'; M['E'] = '3'; M['H'] = 'H';
	M['I'] = 'I'; M['J'] = 'L'; M['L'] = 'J';
	M['M'] = 'M'; M['O'] = 'O'; M['S'] = '2';
	M['T'] = 'T'; M['U'] = 'U'; M['V'] = 'V';
	M['W'] = 'W'; M['X'] = 'X'; M['Y'] = 'Y';
	M['Z'] = '5'; M['1'] = '2'; M['2'] = 'S';
	M['3'] = 'E'; M['5'] = 'Z'; M['8'] = '8';
}

int palindrom()
{
	strcpy(rev, s);
	reverse(rev, rev+len);
	return strcmp(rev, s);
}

int mirror()
{
	int i;
	for(i=0; i<len; i++)
		rev[i] = M[rev[i]];
	return strcmp(rev, s);
}

int main()
{
	freopen("401.txt", "r", stdin);
	init();
	int p, m;
	while(gets(s))
	{
		printf("%s", s);
		len = strlen(s);
		p = palindrom();
		m = mirror();
		if( !p && !m )
			printf(" -- is a mirrored palindrome.\n");
		else if( !p )
			printf(" -- is a regular palindrome.\n");
		else if( !m )
			printf(" -- is a mirrored string.\n");
		else
			printf(" -- is not a palindrome.\n");
		printf("\n");
	}
	return 0;
}