#include<stdio.h>

int sz, cs=1;
int x[35];
int mem[1000][10];
int pl[10];
int a[10];

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

void BtKt(int r){
	if( r>8 ){
		for(int i=1; i<=8; i++){
			mem[sz][i] = x[i];
		}
		sz++;
		return;
	}
	for(int c=1; c<=8; c++){
		if( Place(r, c) ){
			x[r] = c;
			BtKt(r+1);
		}
	}
}


int solution(){
	int ret=10, cnt, i, j;
	for(i=0; i<sz; i++){
		cnt = 0;
		for(j=1; j<=8; j++){
			if( a[j] != mem[i][j] )
				cnt++;
		}
		if( cnt<ret )ret = cnt;
	}
	return ret;
}


int main(){
	freopen("11085.txt", "r", stdin);
	BtKt(1);
	while(scanf("%d%d%d%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8]) != EOF){
		printf("Case %d: %d\n", cs++, solution());
	}
	return 0;
}
