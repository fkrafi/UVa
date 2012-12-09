#include<stdio.h>
#include<string.h>

int N;
int a[105], sum[105], mem[105][105];

int MAX(int a, int b){
	return (a>b)?a:b;
}

int Sum(int i, int j){
	return (sum[j]-sum[i-1]);
}

int dp(){
	int i, j, k, t;
	memset(mem, 0, sizeof(mem));
	for(i=N; i>=1; i--){
		for(j=1; j<=N; j++){
			if(i<=j){
				mem[i][j] = Sum(i, j);
				for(k=i; k<=j; k++){
					t = MAX(Sum(i, k)-mem[k+1][j], Sum(k, j)-mem[i][k-1]);
					mem[i][j] = MAX(t, mem[i][j]);
				}
			}
		}
	}
	return mem[1][N];
}

int main(){
	freopen("10891.txt", "r", stdin);
	int i;
	while( scanf("%d", &N) && N ){
		for(i=1; i<=N; i++){
			scanf("%d", &a[i]);
			sum[i] = sum[i-1] + a[i];
		}printf("%d\n", dp());
	}
	return 0;
}