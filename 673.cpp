#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

char str[150];

int chk(char ch)
{
	return (ch=='(' || ch=='[');
}

int compare(char c1, char c2)
{
	return ( (c1=='(' && c2==')') || (c1=='[' && c2==']') );
}

int check_parentheses(char str[])
{
	stack<char> s;
	int l=strlen(str);
	for(int i=0; i<l; i++)
	{
		if(chk(str[i]))
			s.push(str[i]);
		else{
			if(s.empty())return 0;
			if(!compare(s.top(), str[i]))
				return 0;
			s.pop();
		}
	}
	if(s.empty())
		return 1;
	return 0;
}

int main()
{
	int t;
	char ch;
	scanf("%d%c", &t, &ch);
	while(t--)
	{
		gets(str);
		if(check_parentheses(str))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}