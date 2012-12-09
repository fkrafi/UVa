#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

string in[10000], out[10000];
char temp[10000];

int main()
{
	freopen("272.txt", "r", stdin);
	int l, sz=-1, i, j, cnt = 0, len=0;
	char ch;
	while(getline(cin, in[++sz]))
	{
		l = in[sz].length();
		j = 0;
		for(i=0; i<l; i++)
		{
			ch = in[sz][i];
			if(cnt%2==0 && in[sz][i]=='\"')
			{
				cnt++;
				temp[j++] = '`';
				temp[j++] = '`';
			}
			else if(in[sz][i]=='\"')
			{
				cnt++;
				temp[j++] = '\'';
				temp[j++] = '\'';
			}
			else
				temp[j++] = in[sz][i];
		}
		temp[j++] = '\0';
		out[len++] = string(temp);
	}
	for(i=0; i<sz; i++)
		cout << out[i] << "\n";
	return 0;
}