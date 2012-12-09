#pragma warning(disable : 4786)
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

char str[85], s[85], r[85];
map<string, int> m;
string temp;

int main()
{
	freopen("353.txt", "r", stdin);
	int i, j, k, l=0, cnt;
	while(gets(str))
	{
		l = strlen(str);
		cnt = 0;
		for(i=0; i<l; i++)
		{
			k = 0;
			for(j=i; j<l; j++)
			{
				s[k++] = str[j];
				s[k] = '\0';
				strcpy(r, s);
				reverse(r, r+k);
				temp = string(s);
				if(strcmp(s, r)==0 && m.find(s)==m.end())
				{
					m[temp] = cnt;
					cnt++;
				}
			}
		}
		printf("The string \'%s\' contains %d palindromes.\n", str, cnt);
		m.clear();
	}
	return 0;
}