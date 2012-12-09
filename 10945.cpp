#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s1[1000000], s2[1000000], s3[1000000];

int isChar(char ch)
{
	if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') )
		return 1;
	return 0;
}

int tolower(char ch)
{
	if(ch>='A' && ch<='Z')
		return ch+32;
	return ch;
}

int main()
{
	int i, k, l;
	while(gets(s1))
	{
		if(!strcmp(s1, "DONE"))break;
		l = strlen(s1);
		k = 0;
		for(i=0; i<l; i++)
		{
			if(isChar(s1[i]))
				s2[k++] = tolower( s1[i] );
		}
		s2[k] = '\0';
		strcpy(s3, s2);
		reverse(s3, s3+k);
		if(strcmp(s2, s3))
			printf("Uh oh..\n");
		else
			printf("You won't be eaten!\n");
	}
	return 0;
}