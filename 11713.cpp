#include<stdio.h>
#include<string.h>

char s1[100], s2[100], ch;

int isVowel(char ch)
{
	if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
		return 1;
	return 0;
}

int abstract_names(char s1[], char s2[])
{
	if(strcmp(s1, s2)==0)
		return 1;
	int l1 = strlen(s1), l2=strlen(s2), i;
	if(l1 != l2)
		return 0;
	for(i=0; i<l1; i++)
	{
		if(s1[i] != s2[i])
			if( !isVowel(s1[i]) || !isVowel(s2[i]) )
				return 0;
	}
	return 1;
}

int main()
{
	int t;
	scanf("%d%c", &t, &ch);
	while(t--)
	{
		gets(s1);
		gets(s2);
		if(abstract_names(s1, s2))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}