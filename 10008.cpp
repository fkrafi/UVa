#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

char str[1000][10000], ch;
struct counter
{
	int c, cnt;
}ct[200];

bool comp(counter a, counter b)
{
	if(a.cnt > b.cnt)
		return true;
	if(a.cnt == b.cnt)
		return a.c < b.c;
	return false;
}

int main()
{
	int n, i, j, l;
	scanf("%d%c", &n, &ch);
	for(i=0; i<n; i++)
		gets(str[i]);
	for(i=0; i<200; i++)
		ct[i].cnt = 0;
	for(i=0; i<n; i++)
	{
		l = strlen(str[i]);
		for(j=0; j<l; j++)
		{
			if(isalpha(str[i][j]))
			{
				ct[toupper(str[i][j])].cnt++;
				ct[toupper(str[i][j])].c = toupper(str[i][j]);
			}
		}
	}
	sort(ct, ct+200, comp);
	
	for(i=0; i<200; i++)
		if(ct[i].cnt != 0)
			printf("%c %d\n", toupper(ct[i].c), ct[i].cnt);
	return 0;
}