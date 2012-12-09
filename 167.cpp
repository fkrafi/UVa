#include<stdio.h>


int board[10][10];
int res[300][10], x[10], sz;

int ABS(int n){
	return (n<0)?-n:n;
}

int Place(int k, int i){
	int j;
	for(j=1; j<=k-1; j++){
		if((x[j]==i) || (ABS(x[j]-i) == ABS(j-k)))
			return 0;
	}
	return 1;
}


void NQueen(int k, int n){
	for(int i=1; i<=n; i++){
		if( Place(k, i) ){
			x[k] = i;
			if(k==n){
				for(int j=1; j<=n; j++)
					res[sz][j] = x[j];
				sz++;
			}else {
				NQueen(k+1, n);
			}
		}
	}
}


void input(){
	for(int i=1; i<=8; i++)
		for(int j=1; j<=8; j++)
			scanf("%d", &board[i][j]);
}


int chk(){
	int ret=-1, sum, i, j;
	for(i=0; i<sz; i++){
		sum = 0;
		for(j=1; j<=8; j++)
			sum += board[j][res[i][j]];
		if( ret<sum )ret = sum;
	}
	return ret;
}


int main(){
	freopen("167.txt", "r", stdin);
	NQueen(1, 8);
	int t;
	scanf("%d", &t);
	while(t--){
		input();
		printf("%5d\n", chk());
	}
	return 0;
}