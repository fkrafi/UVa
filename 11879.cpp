#include<stdio.h>
#include<string.h>

char num[10110];

double mod(char s[], int d){
	int i, l, n;
	int c=0;
	l = strlen(s);
	for(i=0; i<l; i++){
		n = ((s[i]-48)+(c*10));
		c = (n>=d)?(n%d):n;
	}
	return c;
}

int main()
{
	while(gets(num))
	{
		if(num[0]=='0')break;
		if(!mod(num, 17))
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}