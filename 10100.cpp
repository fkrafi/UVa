#include<stdio.h>
#include<string.h>

int lcs[10100][10100];
char str1[1010], str2[10100];
char s1[10100][10100], s2[10100][10100];
int sz1, sz2, l1, l2;
int isChar(char ch)
{
	return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'));
}
char to_lower(char ch)
{
	if(ch>='A' && ch<='Z')
		return ch+32;
	return ch;
}
void cvnt();

int max(int a, int b)
{
	if(a<b)
		return b;
	return a;
}

int main()
{
	int i, j, C=1;
	while(gets(str1))
	{
		gets(str2);
		cvnt();
		for(i=0; i<sz1; i++)
		{
			for(j=0; j<sz2; j++)
			{
				if(i>0 && j>0)
				{
					if( !strcmp(s1[i],s2[j]) )
						lcs[i][j] = lcs[i-1][j-1] + 1;
					else
						lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
				}else{lcs[i][j] = 0;}
			}
		}
		if(!l1 || !l2)
			printf("%2d. Blank!\n", C++);
		else
			printf("%2d. Length of longest match: %d\n", C++, lcs[sz1-1][sz2-1]);
	}
	return 0;
}

void cvnt()
{
	int i, j;
	l1 = strlen(str1);
	sz1 = 1;
	for(i=0; i<l1; i++)
	{
		j = 0;
		if(isChar(str1[i]))
		{
			do{
				s1[sz1][j++] = str1[i++];
			}while(isChar(str1[i]));
			s1[sz1++][j] = '\0';
		}
	}
	l2 = strlen(str2);
	sz2 = 1;
	for(i=0; i<l2; i++)
	{
		j = 0;
		if(isChar(str2[i]))
		{
			do{
				s2[sz2][j++] = str2[i++];
			}while(isChar(str2[i]));
			s2[sz2++][j] = '\0';
		}
	}
}