#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

struct team
{
	char name[1000];
	int atk, def;
}play[500];

string stkTeam[100], defTeam[100];

bool comp(team a, team b)
{
	if(a.atk == b.atk)
	{
		if(a.def == b.def)
		{
			if(strcmp(a.name, b.name)< 0)
				return false;
			return true;
		}
		return a.def > b.def;
	}
	return a.atk<b.atk;
}

int main()
{
	int i, j, c, t;
	char ch;
	scanf("%d%c", &t, &ch);
	for(i=1; i<=t; i++)
	{
		for(j=0; j<10; j++)
		{
			scanf("%s", play[j].name);
			scanf("%d%d", &play[j].atk, &play[j].def);
		}
		sort(play, play+10, comp);
		printf("Case %d:\n", i);
		c = -1;
		for(j=9; j>=5; j--)
			stkTeam[++c] = play[j].name;
		sort(stkTeam, stkTeam+c+1);
		printf("(");
		for(j=0; j<=c; j++)
		{
			if(j==c)
				cout << stkTeam[j] << ")\n";
			else
				cout << stkTeam[j] << ", ";
		}

		c = -1;
		for(j=4; j>=0; j--)
			defTeam[++c] = play[j].name;
		sort(defTeam, defTeam+c+1);
		printf("(");
		for(j=0; j<=4; j++)
		{
			if(j==4)
				cout << defTeam[j] << ")\n";
			else
				cout << defTeam[j] << ", ";
		}
	}
	return 0;
}