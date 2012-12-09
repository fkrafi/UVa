#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define SZ 105
typedef pair<int, int> pii;


int nR, nC, len;
char grid[SZ][SZ];
char ins[50005], face;
pii S;

void input(){
	char ch;
	int i, j;
	for(i=1; i<=nR; i++){
		for(j=1; j<=nC; j++){
			scanf("%c", &ch);
			if( ch=='N' || ch=='S' || ch=='L' || ch=='O' ){
				grid[i][j] = ch;
				S = pii(i, j);
				face = ch;
			}else if( ch=='.' || ch=='*' || ch=='#' ){
				grid[i][j] = ch;
			}else j--;
		}
	}getchar();
	gets(ins);
}

char face_rotate(char ch){
	if(  ch=='D' ){
		if( face=='N' )return 'L';
		if( face=='L' )return 'S';
		if( face=='S' )return 'O';
		if( face=='O' )return 'N';
	}
	if( face=='N' )return 'O';
	if( face=='L' )return 'N';
	if( face=='S' )return 'L';
	return 'S';
}

pii change_cell(){
	pii ret;
	if( face=='N' ){
		ret.first = S.first - 1;
		ret.second = S.second;
	}else if( face=='L' ){
		ret.first = S.first;
		ret.second = S.second + 1;
	}else if( face=='S' ){
		ret.first = S.first + 1;
		ret.second = S.second;
	}else if( face=='O' ){
		ret.first = S.first;
		ret.second = S.second - 1;
	}
	return ret;
}

void travel(){
	int i, cnt=0;
	pii temp;
	grid[S.first][S.second] = '.';
	for(i=0; i<len; i++){
		if( ins[i]=='D' || ins[i]=='E' ){
			face = face_rotate(ins[i]);
		}else if(ins[i]=='F'){
			temp = change_cell();
			if( temp.first<1 || temp.first>nR || temp.second<1 || temp.second>nC )continue;
			if( grid[temp.first][temp.second] == '#' )continue;
			if( grid[temp.first][temp.second] == '*' )cnt++;
			grid[temp.first][temp.second] = '.';
			S = temp;
		}
	}
	printf("%d\n", cnt);
}

int main(){
	freopen("11831.txt", "r", stdin);
	while( scanf("%d%d%d", &nR, &nC, &len) ){
		if( !nR && !nC && !len)break;
		input();
		travel();
	}
	return 0;
}