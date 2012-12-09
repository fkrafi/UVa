#pragma warning(disable : 4786)
#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

struct store{
	string s;
	double cnt;
}ans[10010];

map<string, int> m;
char str[100];
string temp;

bool comp(struct store a, struct store b)
{
	return a.s<b.s;
}

int main()
{
	freopen("10226.txt", "r", stdin);
	int t, in, i;
	double res, n;
	scanf("%d", &t);
	getchar(); gets(str);
	while(t--)
	{
		in = 0;
		n = 0;
		while(gets(str))
		{
			if(!strlen(str))break;
			temp = string(str);
			if(m.find(temp) == m.end())
			{
				m[temp] = in;
				ans[in].s = temp;
				ans[in++].cnt = 0;
			}
			ans[m[temp]].cnt++;
			n++;
		}
		sort(ans, ans+in, comp);
		for(i=0; i<in; i++)
		{
			cout << ans[i].s;
			res = (ans[i].cnt*100.0)/(n);
			printf(" %.4lf\n", res);
		}
		m.clear();
		if(t)printf("\n");
	}
	return 0;
}