#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char s[10000][10000];
int sz;

int isSpace(char ch)
{
	return (ch==' ' || ch=='\t');
}

void lead_space(char str[], int &l)
{
	if( !isSpace(str[0]))return;
	int i=0, j=0;
	char temp[1000];
	while(i<l && isSpace(str[i]))i++;
	for(; i<l; i++)
		temp[j++] =str[i];
	temp[j] = '\0';
	strcpy(str, temp);
	l = j;
}

int main()
{
	freopen("724.txt", "r", stdin);
	sz = 0;
	int i, l;
	while(gets(s[sz++]));
	for(i=0; i<sz-1; i++)
	{
		puts(s[i]);
		l = strlen(s[i]);
		reverse(s[i], s[i]+l);
	}
	for(i=sz-2; i>=0; i--)puts(s[i]);
	return 0;
}
