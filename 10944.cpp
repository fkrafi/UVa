#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;


int R, C, H;
pii S;
queue<pii> Q;
vector<pii> hash;
char grid[25][25];
int mem[1<<16][21];
int seen[20][25][25], cst[20][25][25], vst=1;

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void bfs(pii S, int in){
	int i;
	pii u, v;
	Q.push(S);
	cst[in][S.first][S.second] = 0;
	seen[in][S.first][S.second] = vst;
	while( !Q.empty() ){
		u = Q.front(); Q.pop();
		for(i=0; i<8; i++){
			v.first = u.first + dr[i];
			v.second = u.second + dc[i];
			if( v.first<1 || v.first>R || v.second<1 || v.second>C )continue;
			if( seen[in][v.first][v.second]==vst )continue;
			Q.push(v);
			seen[in][v.first][v.second] = vst;
			cst[in][v.first][v.second] = cst[in][u.first][u.second] + 1;
		}
	}
}


void input(){
	int i, j;
	hash.clear();
	for(i=1; i<=R; i++){
		for(j=1; j<=C; j++){
			scanf("%c", &grid[i][j]);
			if( grid[i][j]=='L' ){
				S = pii(i, j);
			}else if( grid[i][j]=='#' ){
				hash.push_back(pii(i, j));
			}else if( grid[i][j]!='.' ){
				j--;
			}
		}
	}
}

void init(){
	int i;
	vst++;
	bfs(S, 0);
	for(i=1; i<=hash.size(); i++){
		vst++;
		bfs(hash[i-1], i);
	}
	H = hash.size();
	memset(mem, -1, sizeof(mem));
}

int MIN(int a, int b){
	return (a<b)?a:b;
}

int dp(int mask, int in){
	if( mask==(1<<H)-1 ){
		return cst[in][S.first][S.second];
	}
	if( mem[mask][in]>=0 )return mem[mask][in];
	int i, ret=1<<30;
	for(i=0; i<H; i++){
		if( mask & (1<<i) )continue;
		ret =  MIN(ret, dp(mask|(1<<i), i+1)+cst[in][hash[i].first][hash[i].second]);
	}
	return mem[mask][in] = ret;
}

int main(){
	freopen("10944.txt", "r", stdin);
	while( scanf("%d%d", &R, &C) != EOF ){
		input();
		init();
		printf("%d\n", dp(0, 0));
	}
	return 0;
}