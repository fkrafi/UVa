#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
#define SZ 65
#define N 0
#define S 1
#define E 2
#define W 3

typedef pair<int, int> pii;

int nR, nC;
char grid[SZ][SZ];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};

char face_rotate(char dir, char face){
	if( dir=='R' ){
		if( face=='N' )return 'E';
		if( face=='E' )return 'S';
		if( face=='S' )return 'W';
		if( face=='W' )return 'N';
	}
	if( face=='N' )return 'W';
	if( face=='E' )return 'N';
	if( face=='S' )return 'E';
	return 'S';
}

pii change_dir(pii cur, char ch){
	pii ret;
	if( ch == 'N' ){
		ret.first = cur.first + dr[0];
		ret.second = cur.second + dc[0];
	}else if( ch == 'S' ){
		ret.first = cur.first + dr[1];
		ret.second = cur.second + dc[1];
	}else if( ch == 'E' ){
		ret.first = cur.first + dr[2];
		ret.second = cur.second + dc[2];
	}else if( ch == 'W' ){
		ret.first = cur.first + dr[3];
		ret.second = cur.second + dc[3];
	}
	if( ret.first<1 || ret.first>nR || ret.second<1 || ret.second>nC )return cur;
	if( grid[ret.first][ret.second] == '*' )return cur;
	return ret;
}


void input(){
	int i, j;
	char ch, face='N';
	pii s, cur;
	scanf("%d%d", &nR, &nC);
	for(i=1; i<=nR; i++){
		for(j=1; j<=nC; j++){
			scanf("%c", &ch);
			if( ch=='*' || ch==' ' )grid[i][j] = ch;
			else j--;
		}
	}
	scanf("%d%d", &s.first, &s.second);
	cur = s;
	while( scanf("%c", &ch) ){
		if( ch=='Q' ){
			printf("%d %d %c\n", cur.first, cur.second, face);
			break;
		}
		if( ch=='R' || ch=='L' ){
			face = face_rotate(ch, face);
		}else if(ch=='F'){
			cur = change_dir(cur, face);
		}
	}
}

int main(){
	freopen("10377.txt", "r", stdin);
	int flag=0, t;
	scanf("%d", &t);
	while( t-- ){
		if( flag )printf("\n"); flag=1;
		input();
	}
	return 0;
}