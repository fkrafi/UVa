#include<stdio.h>
#include<string.h>

char s[100];
int dic[1010][30];
int temp[30];

int main()
{
//	freopen("895.txt", "r", stdin);
	int i, j, sz=0, l, con, cnt, t;
	while(gets(s))
	{
		if(s[0] == '#')break;
		l = strlen(s);
		for(i=0; i<l; i++)
			dic[sz][s[i]-'a']++;
		sz++;
	}
	while(gets(s))
	{
		if(s[0] == '#')break;
		memset(temp, 0, sizeof(temp));
		cnt = 0;
		l = strlen(s);
		for(i=0; i<l; i++)
			if(s[i]>='a' && s[i]<='z')
				temp[s[i]-'a']++;
		t = 'z' - 'a';
		for(i=0; i<sz; i++)
		{
			con = 1;
			for(j=0; j<=t; j++)
			{
				if( dic[i][j] > temp[j] )
				{
					con = 0;
					break;
				}
			}
			if(con)cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}