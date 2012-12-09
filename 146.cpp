#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s[10000];
int pos, l;

int chk(char s[])
{
	int i, j;
	for(i=l-2; i>=0; i--)
	{
		for(j=l-1; j>i; j--)
		{
			if(s[i] < s[j])
				return i;
		}
	}
	return -1;
}


void output(char s[])
{
	/*int i;
	for(i=0; i<pos; i++)
		printf("%c", s[i]);
	for(i=l-1; i>=pos; i--)
		printf("%c", s[i]);
	printf("\n");*/
	char s1[1000];
	strcpy(s1, s);
	do{
		if(strcmp(s1, s) > 0)
		{
			puts(s1);
			break;
		}
	}while(next_permutation(s1, s1+l));
}

int main()
{
	while(gets(s))
	{
		l = strlen(s);
		if(s[0]=='#' && l==1)break;
		pos = chk(s);
		if(pos<0)
			printf("No Successor\n");
		else
			output(s);
	}
	return 0;
}