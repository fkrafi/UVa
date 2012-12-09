#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>
using namespace std;

char str[10000];

struct counter
{
	int ch, cnt;
}ct[10000];

bool comp(counter a, counter b)
{
	if(a.cnt == b.cnt)
		return a.ch > b.ch;
	return a.cnt < b.cnt;
}

int main()
{
	int i, l, flag=0;
	while(gets(str))
	{
		if(flag)printf("\n");
		flag = 1;
		l = strlen(str);
		for(i=0; i<1000; i++)
			ct[i].cnt=0;
		for(i=0; i<l; i++)
		{
			ct[ str[i] ].cnt++;
			ct[ str[i] ].ch = str[i];
		}
		sort(ct, ct+200, comp);
		for(i=0; i<200; i++)
			if(ct[i].cnt > 0 && ct[i].ch>=32 && ct[i].ch<129)
				printf("%d %d\n", ct[i].ch, ct[i].cnt);
	}
	return 0;
}