#include<stdio.h>
#include<string.h>
#define MIN -999999999

int cnt[256], max, flag;
char ch;

void print_answer()
{
	int i;
	if(max == MIN)
		max = 0;
	for(i='A'; i<='Z'; i++)
	{
		if(cnt[i] == max)
			printf("%c", i);
		cnt[i] = 0;
	}

	for(i='a'; i<='z'; i++)
	{
		if(cnt[i] == max)
			printf("%c", i);
		cnt[i] = 0;
	}
	printf(" %d\n", max);
	max = MIN;
	flag = 0;
}

int isValid(char ch)
{
	return ((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'));
}

int main()
{
	freopen("499.txt", "r", stdin);
	max = MIN;
	while(scanf("%c", &ch) != EOF)
	{
		flag = 1;
		if(ch=='\0' || ch=='\n')
			print_answer();
		else if(isValid(ch))
		{
			cnt[ch]++;
			if(max<cnt[ch])max = cnt[ch];
		}
	}
	if(flag){
		if(max == MIN)
			max = 0;
		print_answer();
	}
	return 0;
}