#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
#define SZ 35


struct cell{
	int x, y, z;
};

cell S, T;
int X, Y, Z;
char grid[SZ][SZ][SZ];
int tm[SZ][SZ][SZ];
int seen[SZ][SZ][SZ], cs=1;
queue<cell> Q, EQ;
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};


int check(cell v){
	return (v.x>X || v.x<1) || (v.y>Y || v.y<1) || (v.z>Z || v.z<1);
}

int isEqual(cell a, cell b){
	return (a.x==b.x && a.y==b.y && a.z==b.z);
}


int bfs(){
	int i;
	cell u, v;
	seen[S.x][S.y][S.z] = cs;
	Q.push(S);
	tm[S.x][S.y][S.z] = 0;
	while( !Q.empty() ){
		u = Q.front();Q.pop();
		for(i=0; i<6; i++){
			v.x = u.x + dx[i];
			v.y = u.y + dy[i];
			v.z = u.z + dz[i];
			if( check(v) )continue;
			if( grid[v.x][v.y][v.z] == '#')continue;
			if( seen[v.x][v.y][v.z] == cs )continue;
			Q.push(v);
			seen[v.x][v.y][v.z] = cs;
			tm[v.x][v.y][v.z] = tm[u.x][u.y][u.z] + 1;
			if( isEqual(v, T) )
				return tm[v.x][v.y][v.z];
		}
	}
	return -1;
}


void input(){
	char ch;
	int i, j, k;
	for(i=1; i<=X; i++){
		for(j=1; j<=Y; j++){
			for(k=1; k<=Z; k++){
				scanf("%c", &ch);
				if( ch=='S' ){
					S.x = i;
					S.y = j;
					S.z = k;
					grid[i][j][k] = ch;
				}else if( ch=='E' ){
					T.x = i;
					T.y = j;
					T.z = k;
					grid[i][j][k] = ch;
				}else if( ch=='.' || ch=='#' ){
					grid[i][j][k] = ch;
				}else{ k--; }
			}
		}
	}
}

int main(){
	freopen("532.txt", "r", stdin);
	int res;
	while( scanf("%d%d%d", &X, &Y, &Z) ){
		if( !X && !Y && !Z )break;
		input();
		res = bfs();
		if( res<0 )
			puts("Trapped!");
		else
			printf("Escaped in %d minute(s).\n", res);
		Q = EQ;
		cs++;
	}
	return 0;
}