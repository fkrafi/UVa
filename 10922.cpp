#include<stdio.h>
#include<string.h>

char s[1010];

int degree(int sum)
{
	int t = sum, cnt=1;
	while(sum>9)
	{
		t = 0;
		while(sum)
		{
			t += sum%10;
			sum /= 10;
		}
		sum = t;
		cnt++;
	}
	return cnt;
}

int main()
{
	int i, l, sum;
	while(gets(s))
	{
		l = strlen(s);
		if(l==1 && s[0]=='0')break;
		sum = 0;
		for(i=0; i<l; i++)
			sum += s[i]-48;
		if(sum%9)
			printf("%s is not a multiple of 9.\n", s);
		else
			printf("%s is a multiple of 9 and has 9-degree %d.\n", s, degree(sum));
	}
	return 0;
}