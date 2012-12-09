#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s[5010][210], temp[210];
struct dictionary{
	char str[210];
}d[5010];

int isChar(char ch)
{
	if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') )
		return 1;
	return 0;
}

bool comp(dictionary a, dictionary b)
{
	if(strcmp(a.str, b.str) > 0)
		return false;
	return true;
}

char tolower(char ch)
{
	if(ch>='A' && ch<='Z')
		return ch+32;
	return ch;
}

int main()
{
	int l, i, j, k, z;
	i = 0;
	z = 0;
	while(gets(s[i]) != NULL)
	{
		l = strlen(s[i]);
		for(j=0; j<l; j++)
		{
			if(isChar(s[i][j]))
			{
				k = 0;
				do{
					temp[k++] = tolower(s[i][j++]);
				}while(isChar(s[i][j]));
				if(k)
				{
					temp[k] = '\0';
					for(k=0; k<z; k++)
					{
						if(!strcmp(d[k].str, temp))
							break;
					}
					if(k==z)
						strcpy(d[z++].str, temp);
				}
			}
		}
	}
	sort(d, d+z, comp);
	for(i=0; i<z; i++)
		puts(d[i].str);
	return 0;
}