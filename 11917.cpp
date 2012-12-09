#pragma warning(disable : 4786)
#include<stdio.h>
#include<string>
#include<map>
#include<string.h>
using namespace std;

map<string, int> M;

struct store{
	string val;
	int tm;
}sub[10000];

char s[100];

int main(){
	freopen("11917.txt", "r", stdin);
	int t, cs, n, i, d;
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++){
		scanf("%d", &n);
		for(i=0; i<n; i++){
			scanf("%s%d", s, &d);
			M[string(s)] = i;
			sub[i].val = string(s);
			sub[i].tm = d;

		}
		scanf("%d%s", &d, s);
		if( M.find(string(s)) == M.end() )
			printf("Case %d: Do your own homework!\n", cs);
		else if( sub[M[string(s)]].tm <= d )
			printf("Case %d: Yesss\n", cs);
		else if( sub[M[string(s)]].tm <= d+5 )
			printf("Case %d: Late\n", cs);
		else
			printf("Case %d: Do your own homework!\n", cs);
		M.clear();
	}
	return 0;
}