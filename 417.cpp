#pragma warning(disable : 4786)
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
#define SZ 83690

char s[SZ][10], str[10], temp[10], t[10];
map<string, int> m;
string ans;

void generate()
{
	int pos=1, i, l, j;
	for(i='a'; i<='z'; i++)
	{
		str[0] = i; str[1] = '\0';
		strcpy(s[pos], str);
		ans = string(s[pos]);
		if(m.find(ans) == m.end())
			m[ans] = pos++;
	}
	for(i=1; pos<=83681; i++)
	{
		strcpy(temp, s[i]);
		l = strlen(temp);
		for(j=temp[l-1]+1; j<='z'; j++)
		{
			strcpy(t, temp);
			str[0] = j; str[1] = '\0';
			strcat(t, str);
			strcpy(s[pos], t);
			ans = string(t);
			if(m.find(ans) == m.end())
				m[ans] = pos++;
			if(pos>83681)break;
		}
	}
}

int main()
{
//	freopen("417.txt", "r", stdin);
	generate();
	while(gets(str)){
		ans = string(str);
		if(m.find(ans) == m.end())
			printf("0\n");
		else
			printf("%d\n", m[ans]);
	}
	return 0;
}
