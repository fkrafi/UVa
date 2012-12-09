#pragma warning(disable : 4786)
#include<map>
#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

map<string, int> M;
string store[1000], str;
char s1[1000], temp[1000];

int isValid( char ch )
{
	return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z');
}

string convert(string str)
{
	int l=str.length()-1, i;
	while( !isValid(str[l]) )
		l--;
	for(i=0; i<=l; i++)
		str[i] = tolower(str[i]);
	str[i] = '\0';
	return str;
}

int main()
{
	freopen("11062.txt", "r", stdin);
	int sz=0, l;
	while(scanf("%s", temp) != EOF)
	{
		l = strlen(temp);
		if(temp[l-1] == '-')
		{
			temp[l-1] = '\0';
			strcpy(s1, temp);
			while(scanf("%s", temp))
			{
				l = strlen(temp);
				if(temp[l-1] != '-')break;
				temp[l-1] = '\0';
				strcat(s1, temp);
			}
			strcat(s1, temp);
			strcpy(temp, s1);
		}
		str = string(temp);
		str = convert(str);
		if(M.find(str) == M.end())
		{
			store[sz++] = str;
			M[str] = sz;
		}
	}
	sort(store, store+sz);
	for(l=1; l<sz; l++)
		cout << store[l] << "\n";
	return 0;
}