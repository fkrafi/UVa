#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 999999

typedef pair<int, int> pii;

int R, C, vst, nT;
char grid[55][55];

pii S;
vector<pii> Tre, Angry;
int mem[1<<15][15];
int seen[15][55][55], cst[15][55][55];

queue<pii> Q;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int dr1[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc1[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void input(){
	pii v;
	int i, j;
	Tre.clear();
	Angry.clear();
	for(i=1; i<=R; i++){
		for(j=1; j<=C; j++){
			scanf("%c", &grid[i][j]);
			if( grid[i][j]=='@' ){
				S = pii(i, j);
			}else if( grid[i][j]=='!' ){
				Tre.push_back(pii(i, j));
			}else if( grid[i][j]=='*' ){
				Angry.push_back(pii(i, j));
			}else if(grid[i][j]=='.' || grid[i][j]=='~' || grid[i][j]=='#' ){
				continue;
			}else{
				j--;
			}
		}
	}
	for(i=0; i<Angry.size(); i++){
		for(j=0; j<8; j++){
			v = pii(Angry[i].first+dr1[j], Angry[i].second+dc1[j]);
			if( v.first<1 || v.first>R || v.second<1 || v.second>C )continue;
			grid[v.first][v.second] = '*';
		}
	}
}


void bfs(pii S, int in){
	int i;
	pii u, v;
	Q.push(S);
	cst[in][S.first][S.second] = 0;
	seen[in][S.first][S.second] = vst;
	while( !Q.empty() ){
		u = Q.front(); Q.pop();
		for(i=0; i<4; i++){
			v = pii(u.first+dr[i], u.second+dc[i]);
			if( v.first<1 || v.first>R || v.second<1 || v.second>C )continue;
			if( seen[in][v.first][v.second]==vst )continue;
			if( grid[v.first][v.second]=='#' )continue;
			if( grid[v.first][v.second]=='~' )continue;
			if( grid[v.first][v.second]=='*' )continue;
			Q.push(v);
			seen[in][v.first][v.second] = vst;
			cst[in][v.first][v.second] = cst[in][u.first][u.second] + 1;
		}
	}
}


void init(){
	int i;
	nT = Tre.size();
	memset(mem, -1, sizeof(mem));
	memset(cst, INF, sizeof(cst));
	vst++;
	bfs(S, 0);
	for(i=0; i<nT; i++){
		vst++;
		bfs(Tre[i], i+1);
	}
}

int MIN(int a, int b){
	return (a<b)?a:b;
}

int dp(int mask, int in){
	if( mask==(1<<nT)-1 ){
		return cst[in][S.first][S.second];
	}
	if( mem[mask][in]>=0 )return mem[mask][in];
	int i, ret=INF;
	for(i=0; i<nT; i++){
		if( mask&(1<<i) )continue;
		ret = MIN(ret, dp(mask|(1<<i), i+1)+cst[in][Tre[i].first][Tre[i].second]);
	}
	return mem[mask][in] = ret;
}


int main(){
	freopen("10937.txt", "r", stdin);
	int res;
	while( scanf("%d%d", &R, &C) && R && C ){
		input();
		init();
		res = dp(0, 0);
		printf("%d\n", (res>=INF)?-1:res);
	}
	return 0;
}
