#include<stdio.h>
#include<string.h>
#define MAXP 1005
#define MAXW 35


int mem[MAXP][MAXW], W;
int N, p[MAXP], w[MAXP];


int MAX(int a, int b){
	return (a>b)?a:b;
}

int dp(){
	int i, j;
	for(i=1; i<=N; i++){
		for(j=1; j<=W; j++){
			if( j<w[i] ){
				mem[i][j] = mem[i-1][j];
			}else if( j>=w[i] ){
				mem[i][j] = MAX(mem[i-1][j], mem[i-1][j-w[i]]+p[i]);
			}
		}
	}
	return mem[N][W];
}


int main(){
	freopen("10130.txt", "r", stdin);
	int t, i, res, g;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &N);
		for(i=1; i<=N; i++)
			scanf("%d%d", &p[i], &w[i]);
		res = 0;
		scanf("%d", &g);
		for(i=0; i<g; i++){
			scanf("%d", &W);
			res += dp();
		}
		printf("%d\n", res);
	}
	return 0;
}