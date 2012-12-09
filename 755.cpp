#pragma warning(disable : 4786)
#include<map>
#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string temp, str;
map<string, int> M;

struct store{
	string s;
	int cnt;
};
typedef struct store phone;
phone book[100005];

char maping(char ch)
{
	if(ch>='A' && ch<='C')return '2';
	if(ch>='D' && ch<='F')return '3';
	if(ch>='G' && ch<='I')return '4';
	if(ch>='J' && ch<='L')return '5';
	if(ch>='M' && ch<='O')return '6';
	if(ch>='P' && ch<='S')return '7';
	if(ch>='T' && ch<='V')return '8';
	if(ch>='W' && ch<='Y')return '9';
	return ch;
}

int isValid(char ch)
{
	return ((ch>='A' && ch<='P') || (ch>='R' && ch<='Y') || (ch>='0' && ch<='9'));
}

string convert(string s)
{
	int i, len=s.length(), sz=0;
	char s1[100];
	for(i=0; i<len; i++)
	{
		if(isValid(s[i]))
		{
			s1[sz] = maping(s[i]);
			sz++;
		}
		if(sz==3)s1[sz++]='-';
	}
	s1[sz] = '\0';
	return string(s1);
}

bool comp(phone a, phone b)
{
	return a.s<b.s;
}

int main()
{
	freopen("755.txt", "r", stdin);
	int t, n, j, sz, i;
	char ch;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%c", &n, &ch);
		sz = 0;
		for(i=0; i<n; i++)
		{
			getline(cin, str);
			temp = convert(str);
			if(M.find(temp) == M.end())
			{
				book[sz].s = temp;
				book[sz].cnt = 0;
				M[temp] = sz++;
			}
			book[M[temp]].cnt++;
		}
		sort(book, book+sz, comp);
		j = 1;
		for(i=0; i<sz; i++)
		{
			if(book[i].cnt>1)
			{
				cout << book[i].s << " " << book[i].cnt << "\n"; 
				j = 0;
			}
		}
		if(j)printf("No duplicates.\n");
		if(t)
			printf("\n");
		M.clear();
	}
	return 0;
}