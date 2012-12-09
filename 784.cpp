#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pi;

string s[85];
char str[100];
int len[85], sz;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};



void dfs(pi S)
{
	s[S.first][S.second] = '#';
	for(int i=0; i<4; i++)
	{
		pi u;
		u.first = S.first + dr[i];
		u.second = S.second + dc[i];
		if(u.first<0 || u.second<0 || u.first>=sz || u.second>=len[u.first])continue;
		if(s[u.first][u.second] == ' ' || s[u.first][u.second] == '*')
			dfs(u);
	}
}

int main()
{
	pi S;	
	int i, t, j;
	scanf("%d", &t);getchar();
	while(t--)
	{
		i = 0;
		S.first = -1;
		while(gets(str))
		{
			s[i] = string(str);
			if(s[i][0] == '_')break;
			len[i] = s[i].length();
			if(S.first != -1){i++; continue;}
			for(j=0; j<len[i]; j++)
			{
				if(s[i][j] == '*')
				{
					S.first = i;
					S.second = j;
					break;
				}
			}
			i++;
		}
		sz = i;
		if(S.first == -1)s[0][0] = '*';
		else dfs(S);
		for(j=0; j<=i; j++)
			cout << s[j] << "\n";
	}
	return 0;
}