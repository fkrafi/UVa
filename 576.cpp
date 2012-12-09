#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
#define SZ 205

char line[SZ];
char *pch;

int isSyllable(char ch)
{
	return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='y');
}

int chk(int pos, int cnt)
{
	if(pos==1 && cnt!=5)return 0;
	if(pos==2 && cnt!=7)return 0;
	if(pos==3 && cnt!=5)return 0;
	return 1;
}

int main()
{
	freopen("576.txt", "r", stdin);
	int i, l, cnt, pos, flag;
	while(gets(line))
	{
		if(!strcmp(line, "e/o/i"))break;
		pch = strtok(line,"/");
		pos = 1;
		flag = 1;
		while(pch != NULL)
		{
			l = strlen(pch);
			cnt = 0;
			for(i=0; i<l; i++)
			{
				if( !isSyllable(pch[i]) )continue;
				if( !i && isSyllable(pch[i]) )cnt++;
				else if(i>0 && !isSyllable(pch[i-1]) && isSyllable(pch[i]) )cnt++;
			}
			if(!chk(pos, cnt))
			{
				printf("%d\n", pos);
				flag = 0;
				break;
			}
			pch = strtok(NULL, "/");
			pos++;
		}
		if(flag)printf("Y\n");
	}
	return 0;
}