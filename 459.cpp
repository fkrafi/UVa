#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
#define SZ 250

int seen[SZ], cs;
vector<char> edge[SZ];
char temp[10000];

int isChar(char ch)
{
	return (ch>='A' && ch<='Z');
}

void dfs(char s)
{
	seen[s] = cs;
	int i;
	char v;
	for(i=0; i<edge[s].size(); i++)
	{
		v = edge[s][i];
		if(seen[v] != cs)
			dfs(v);
	}
}

int main()
{
	freopen("459.txt", "r", stdin);
	int t, i, cnt, len;
	char s[10], ch;
	cs = 1;
	scanf("%d%c", &t, &ch);getchar();
	while(t--)
	{
		while(gets(temp))
		{
			len = strlen(temp);
			ch = 1;
			for(i=0; i<len; i++)
			{
				if(isChar(temp[i]))
				{
					ch = temp[i];
					break;
				}
			}
			if(ch != 1)break;
		}
		for(i='A'; i<=ch; i++)
			edge[i].clear();
		while(gets(temp))
		{
			len = strlen(temp);
			if(len == 0 || temp[0] == '\0' || temp[0] == '\n')break;
			cnt = 0;
			for(i=0; i<len; i++)
			{
				if(isChar(temp[i]))
					s[cnt++] = temp[i];
				if(cnt==2)break;
			}
			if(cnt==2)
			{
				edge[s[0]].push_back(s[1]);
				edge[s[1]].push_back(s[0]);
			}
		}
		cnt = 0;
		for(i='A'; i<=ch; i++)
		{
			if(seen[i] != cs)
			{
				dfs(i);
				cnt++;
			}
		}
		printf("%d\n", cnt);
		if(t)printf("\n");
		cs++;
	}
	return 0;
}