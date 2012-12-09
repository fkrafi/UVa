#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define SZ 30

typedef pair<int, int> PII;

int vst[SZ][SZ], cnt;
int cs, sz, len[SZ];
char grid[SZ][SZ], s[SZ];


int dr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dc[] = {-1, -1, -1, 0, 0, 1, 1, 1};

void dfs(PII S){
	PII u;
	int i;
	if( grid[S.first][S.second] == '1' )cnt++;
	vst[S.first][S.second] = cs;
	for(i=0; i<8; i++){
		u.first = S.first + dr[i];
		u.second = S.second + dc[i];
		if( u.first<0 || u.first>=sz || u.second<0 || u.second>=len[u.first] )continue;
		if( grid[u.first][u.second]=='0' || vst[u.first][u.second] == cs )continue;
		dfs(u);
	}
}

int main(){
	freopen("871.txt", "r", stdin);
	int t, i, j, res;
	scanf("%d", &t);
	getchar();getchar();
	for(cs=1; cs<=t; cs++){
		if( cs>1 )printf("\n");
		sz = res = 0;
		while(gets(s)){
			len[sz] = strlen(s);
			if( !len[sz] )break;
			strcpy(grid[sz++], s);
		}
		for(i=0; i<sz; i++){
			for(j=0; j<len[i]; j++){
				if( grid[i][j]=='1' && vst[i][j]!=cs ){
					cnt = 0;
					dfs(PII(i, j));
					if( cnt>res )res=cnt;
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}