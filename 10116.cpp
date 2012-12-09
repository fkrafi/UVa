#pragma warning(disable : 4786)
#include<stdio.h>
#include<string.h>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
#define SZ 15
#define N 0
#define S 1
#define E 2
#define W 3

typedef pair<int, int> pii;


int nR, nC, SC;
char grid[SZ][SZ];
int tm[SZ][SZ];
int seen[SZ][SZ], pi[SZ][SZ], cs=1;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};
queue<pii> Q, EQ;

int isValid(char ch){
	return (ch=='N' || ch=='S' || ch=='E' || ch=='W');
}

void init(){
	memset(seen, 0, sizeof(seen));
	memset(tm, 0, sizeof(tm));
}

void input(){
	int i, j;
	char ch;
	for(i=1; i<=nR; i++){
		for(j=1; j<=nC; j++){
			scanf("%c", &ch);
			if( isValid(ch) )grid[i][j]=ch;
			else j--;
		}
	}
	cs++;
}

pii change_dir(pii u){
	pii v;
	if( grid[u.first][u.second] == 'N' ){
		v.first = u.first + dr[0];
		v.second = u.second + dc[0];
	}else if( grid[u.first][u.second] == 'S' ){
		v.first = u.first + dr[1];
		v.second = u.second + dc[1];
	}else if( grid[u.first][u.second] == 'E' ){
		v.first = u.first + dr[2];
		v.second = u.second + dc[2];
	}else if( grid[u.first][u.second] == 'W' ){
		v.first = u.first + dr[3];
		v.second = u.second + dc[3];
	}
	return v;
}

void bfs(){
	pii u, v, ret;
	tm[1][SZ] = 0;
	seen[1][SC] = cs;
	Q.push(pii(1, SC));
	while( !Q.empty() ){
		u = Q.front(); Q.pop();
		v = change_dir(u);
		if( v.first<1 || v.first>nR || v.second<1 || v.second>nC ){
			printf("%d step(s) to exit\n", tm[u.first][u.second]+1);
			return;
		}
		if( seen[v.first][v.second] == cs ){
			ret.first = tm[u.first][u.second]+1 - tm[v.first][v.second];
			printf("%d step(s) before a loop of %d step(s)\n", tm[v.first][v.second], ret.first);
			return;
		}else{
			Q.push(v);
			seen[v.first][v.second] = cs;
			tm[v.first][v.second] = tm[u.first][u.second] + 1;
		}
	}
}


int main(){
	freopen("10116.txt", "r", stdin);
	while(scanf("%d%d%d", &nR, &nC, &SC) ){
		if( !nR && !nC && !SC )break;
		input();
		init();
		bfs();
	}
	return 0;
}