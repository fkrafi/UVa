#include<stdio.h>

int n, res;
int p[5][5];
char board[5][5];

void CLEAR(){
	for(int i=0; i<=4; i++)
		for(int j=0; j<=4; j++)
			p[i][j] = 0;
}

int Place(int r, int c){
	if(board[r][c] == 'X')return 0;
	int i, safe=1;
	for(i=1; i<c; i++){
		if(board[r][i] == 'X')
			safe = 1;
		else if(p[r][i] == 1)
			safe = 0;
	}
	if(!safe)return 0;
	for(i=1; i<r; i++){
		if(board[i][c] == 'X')
			safe = 1;
		else if(p[i][c] == 1)
			safe = 0;
	}
	return safe;
}

void count(){
	int cnt=0, i, j;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if( p[i][j] == 1 )
				cnt++;
		}
	}
	if(cnt>res)
		res = cnt;
}

int isCorrect(){
	int i, j;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			if( !Place(i, j) )return 0;
	return 1;
}

void BtKt(int r, int c){
	if( c>n ){
		r++;
		c = 1;
	}
	if( r>n){
		count();
		return;
	}
	if( Place(r, c) ){
		p[r][c] = 1;
		BtKt(r, c+1);
	}
	p[r][c] = 0;
	BtKt(r, c+1);
}

void input(){
	int i, j;
	char ch;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			scanf("%c", &ch);
			if(ch=='.' || ch=='X')
				board[i][j] = ch;
			else j--;
		}
	}
}

int main(){
	freopen("639.txt", "r", stdin);
	while(scanf("%d", &n)){
		if( !n )break;
		CLEAR();
		input();
		res = -1;
		BtKt(1, 1);
		printf("%d\n", res);
	}
	return 0;
}