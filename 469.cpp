#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
typedef pair<int, int> pii;
#define SZ 105

int pos, M;
int cell[3];
int seen[SZ][SZ], cs=1;
char str[SZ];
char grid[SZ][SZ];
queue<pii> Q, EQ;
int dr[] = {-1, -1, 1, 1, -1, 0, 1, 0};
int dc[] = {-1, 1, 1, -1, 0, 1, 0, -1};

int str2int(char s[]){
	int n=0, l=strlen(s), i;
	for(i=0; i<l; i++){
		if( s[i]>='0' && s[i]<='9' )
			n = n*10 + s[i]-48;
	}
	return n;
}


int bfs(pii S){
	int ret=1, i;
	M=strlen(grid[0]);
	pii u, v;
	Q.push(S);
	seen[S.first][S.second] = cs;
	while( !Q.empty() ){
		u = Q.front(); Q.pop();
		for(i=0; i<8; i++){
			v.first = u.first + dr[i];
			v.second = u.second + dc[i];
			if( v.first>=pos || v.first<0 || v.second>=M || v.second<0 )continue;
			if( seen[v.first][v.second] == cs || grid[v.first][v.second] == 'L' )continue;
			Q.push(v);
			seen[v.first][v.second] = cs;
			ret++;
		}
	}
	cs++;
	return ret;
}

void input(){
	int i;
	pos = 0;
	while(gets(str)){
		if( str[0]>='0' && str[0]<='9' )break;
		if( str[0]=='L' || str[0]=='W' )
			strcpy(grid[pos++], str);
	}
	do{
		if( strlen(str)==0 || str[0]=='\n' )break;
 		char *pch = strtok(str, " ");
		i = 0;
		while( pch != NULL ){
			cell[i++] = str2int(pch);
			pch = strtok(NULL, " ");
		}
		i = bfs( pii(cell[0]-1, cell[1]-1) );
		printf("%d\n", i);
	}while(gets(str));
}

int main(){
	freopen("469.txt", "r", stdin);
	int t;
	scanf("%d", &t);getchar();
	while( t-- ){
		input();
		if( t!=0 )printf("\n");
	}
	return 0;
} 