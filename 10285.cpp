#include<stdio.h>
#define SZ 105

int R, C;
int res;
char str[SZ];
int grid[SZ][SZ];
int seen[SZ][SZ], cs=1;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void input(){
	int i, j;
	for(i=1; i<=R; i++)
		for(j=1; j<=C; j++)
			scanf("%d", &grid[i][j]);
}

void BtKt(int r, int c, int step){
	int i, tr, tc;
	for(i=0; i<4; i++){
		tr = r + dr[i];
		tc = c + dc[i];
		if( tr<1 || tr>R || tc<1 || tc>C )continue;
		if( grid[tr][tc] >= grid[r][c] ) continue;
		if( seen[tr][tc] == cs ) continue;
		seen[tr][tc] = cs;
		if( step+1>res )
			res = step+1;
		BtKt(tr, tc, step+1);
		seen[tr][tc] = 0;
	}
}

int solution(){
	int i, j, ret=-1;
	for(i=1; i<=R; i++){
		for(j=1; j<=C; j++){
			res = 0;
			BtKt(i, j, 1);
			if( res>ret )
				ret = res;
		}
	}
	return ret;
}

int main(){
	freopen("10285.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%s%d%d", str, &R, &C);
		input();
		printf("%s: %d\n", str, solution());
	}
	return 0;
}