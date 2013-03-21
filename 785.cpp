#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

queue<PII> q;
int sz, len[82];
char s[82][82], c;

void chk_mark(char str[], int r){
	PII p;
	int i;
	len[r] = strlen(str);
	for(i=0; i<len[r]; i++){
		if( str[i]!='X' && str[i]!=' ' ){
			p.first = r;
			p.second = i;
			q.push(p);
		}
	}
}

void dfs(PII u){
	PII v;
	s[u.first][u.second] = c;
	for(int i=0; i<4; i++){
		v.first = u.first + dr[i];
		v.second = u.second + dc[i];
		if(u.first<0 || u.second<0 || u.first>sz || u.second>=len[u.first])continue;
		if( s[v.first][v.second] == ' ' )
			dfs(v);
	}
}

int main(){
	freopen("785.txt", "r", stdin);
	int i;
	PII u;
	while(gets(s[sz])){
		while(gets(s[++sz])){
			if(s[sz][0] == '_')break;
			chk_mark(s[sz], sz);
		}
		while(!q.empty()){
			u = q.front();
			c = s[u.first][u.second];
			dfs(u);
			q.pop();
		}
		for(i=0; i<=sz; i++)
			puts(s[i]);
		sz = 0;
	}
	return 0;
}